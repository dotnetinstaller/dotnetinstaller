#include "stdafx.h"
#include "dotNetInstaller.h"
#include "dotNetInstallerDlg.h"
#include "InstallerCommandLineInfo.h"
#include "DniMessageBox.h"
#include "ConfigFileManager.h"
#include <Version/Version.h>
#include "ExtractCabProcessor.h"
#include "ExtractCabDlg.h"
#include "SplashWnd.h"

BEGIN_MESSAGE_MAP(CdotNetInstallerApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CdotNetInstallerApp::CdotNetInstallerApp()
	: m_rc(0)
{

}

CdotNetInstallerApp theApp;

BOOL CdotNetInstallerApp::InitInstance()
{
	InitCommonControls();
	CWinApp::InitInstance();

	try
	{
		InstallerCommandLineInfo::Instance = shared_any<InstallerCommandLineInfo *, close_delete>(new InstallerCommandLineInfo());
		InstallerLauncher::Instance = shared_any<InstallerLauncher *, close_delete>(new InstallerLauncher());
		InstallerLog::Instance = shared_any<InstallerLog *, close_delete>(new InstallerLog());
		InstallerSession::Instance = shared_any<InstallerSession *, close_delete>(new InstallerSession());
		InstallUILevelSetting::Instance = shared_any<InstallUILevelSetting *, close_delete>(new InstallUILevelSetting());

		ParseCommandLine(* get(InstallerCommandLineInfo::Instance));
		
		CSplashWnd::EnableSplashScreen(InstallerCommandLineInfo::Instance->DisplaySplash());

		LOG(L"-------------------------------------------------------------------");
		LOG(L"dotNetInstaller (DNI) started, version " << TEXT(VERSION_VALUE));
		LOG(VERSION_LEGALCOPYRIGHT_VALUE);
		LOG(L"Operating system: " << DVLib::GetOperatingSystemVersionString());
		LOG(L"Sequence: " << InstallSequenceUtil::towstring(InstallerSession::Instance->sequence));
		LOG(L"-------------------------------------------------------------------");

		std::map<std::wstring, std::wstring>::iterator arg = InstallerCommandLineInfo::Instance->componentCmdArgs.begin();
		while(arg != InstallerCommandLineInfo::Instance->componentCmdArgs.end())
		{
			LOG(L"Component arguments: \"" + arg->first + L"\": " << arg->second);
			arg ++;
		}

		// propagate command line arguments during execution
		InstallerSession::Instance->AdditionalCmdLineArgs = InstallerCommandLineInfo::Instance->componentCmdArgs;
		InstallerSession::Instance->AdditionalControlArgs = InstallerCommandLineInfo::Instance->controlCmdArgs;

		if (InstallerCommandLineInfo::Instance->DisplayHelp())
		{
			DisplayHelp();
			return FALSE;
		}

		ConfigFileManagerPtr config(new ConfigFileManager());
		config->Load();

		// just display CAB contents
		if (InstallerCommandLineInfo::Instance->DisplayCab())
		{
			DisplayCab();
			return FALSE;
		}
		// just extract the CABs
		else if (InstallerCommandLineInfo::Instance->ExtractCab())
		{
			ExtractCab();
			return FALSE;
		}
		// just display the configuration
		else if (InstallerCommandLineInfo::Instance->DisplayConfig())
		{
			DisplayConfig();
			return FALSE;
		}
	
		m_rc = config->Run();
	}
	catch(std::exception& ex)
	{
		LOG(L"Error: " << DVLib::string2wstring(ex.what()));
        DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK|MB_ICONSTOP);
		m_rc = -1;
	}

	// Poiché la finestra di dialogo è stata chiusa, restituisce FALSE in modo che l'applicazione
	//  venga terminata, anziché avviare la message pump dell'applicazione.
	return FALSE;
}

int CdotNetInstallerApp::ExitInstance() 
{
	LOG(L"dotNetInstaller finished, return code=" << m_rc);
	reset(InstallerCommandLineInfo::Instance);
	reset(InstallerLauncher::Instance);
	reset(InstallerLog::Instance);
	reset(InstallerSession::Instance);
	reset(InstallUILevelSetting::Instance);
	// ignore the MFC return code, which is typically the last key pressed
	CWinApp::ExitInstance();
	return m_rc;
}

void CdotNetInstallerApp::DisplayHelp()
{
	std::wstringstream hs;
	hs << L"Usage: " << DVLib::GetFileNameW(DVLib::GetModuleFileNameW()) << L" [args]" << std::endl;
	hs << std::endl;
	hs << L" /? or /help : this help screen" << std::endl;
	hs << L" /i : install (default)" << std::endl;
	hs << L" /x : uninstall" << std::endl;
	hs << L" /q : force silent (no UI) mode" << std::endl;
	hs << L" /qb : force basic UI mode" << std::endl;
	hs << L" /nq : force full UI mode" << std::endl;
	hs << L" /Log : enable logging" << std::endl;
	hs << L" /LogFile [path] : specify log file" << std::endl;
	hs << L" /ConfigFile [path] : specify configuration file" << std::endl;
	hs << L" /ExtractCab: extract embedded components" << std::endl;
	hs << L" /DisplayCab: display a list of embedded components" << std::endl;
	hs << L" /DisplayConfig: display a list of configurations" << std::endl;
	hs << L" /ComponentArgs [\"id|display_name\":\"value\" ...] : additional component args" << std::endl;
	hs << L" /ControlArgs [\"id\":\"value\" ...] : additional control values" << std::endl;
	hs << L" /CompleteCommandArgs [args] : additional complete command" << std::endl;
	hs << L" /Launcher [path] : alternate launcher on reboot" << std::endl;
	hs << L" /LauncherArgs [args] : additional launcher args on reboot" << std::endl;
	hs << std::endl;
	hs << L"Built by dotNetInstaller (DNI), version " << TEXT(VERSION_VALUE);		
	DniMessageBox::Show(hs.str(), MB_OK|MB_ICONINFORMATION);
}

void CdotNetInstallerApp::DisplayCab()
{
    InstallComponentDlg dlg;
	ExtractCabProcessorPtr extractcab(new ExtractCabProcessor(AfxGetApp()->m_hInstance, & dlg));
	DniMessageBox::Show(DVLib::join(extractcab->GetCabFiles(), L"\r\n"), MB_OK|MB_ICONINFORMATION);
}

void CdotNetInstallerApp::ExtractCab()
{
    ExtractCabDlg dlg;

	ExtractCabProcessorPtr p_extractcab(new ExtractCabProcessor(AfxGetApp()->m_hInstance, & dlg));	
	if (p_extractcab->GetCabCount() == 0)
		return;

	ConfigurationPtr configuration(new InstallConfiguration());
	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(configuration));
	p_configuration->cab_dialog_caption = L"ExtractCab";
	p_configuration->cab_dialog_message = L"%s";

	p_extractcab->cab_path = DVLib::GetCurrentDirectoryW();
	p_extractcab->cab_path.append(L"\\SupportFiles");

	if (InstallUILevelSetting::Instance->IsAnyUI())
		dlg.LoadComponent(configuration, p_extractcab);

	p_extractcab->BeginExec();

	if (InstallUILevelSetting::Instance->IsAnyUI())
		dlg.DoModal();

	p_extractcab->EndExec();
}

void CdotNetInstallerApp::DisplayConfig()
{
	ConfigFileManagerPtr config(new ConfigFileManager());
	config->Load();
	DniMessageBox::Show(config->GetString(), MB_OK|MB_ICONINFORMATION);
}

BOOL CdotNetInstallerApp::PreTranslateMessage(MSG * pMsg)
{
	// route messages to the splash screen while it is visible
	if (CSplashWnd::PreTranslateAppMessage(pMsg)) 
	{
		return TRUE;
	}

	return CWinApp::PreTranslateMessage(pMsg);
}
