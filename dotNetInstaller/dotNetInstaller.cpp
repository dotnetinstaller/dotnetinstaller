#include "stdafx.h"
#include "dotNetInstaller.h"
#include "dotNetInstallerDlg.h"
#include "InstallerCommandLineInfo.h"
#include "DniMessageBox.h"
#include "ConfigFileManager.h"
#include "InstallerLauncher.h"
#include <Version/Version.h>

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

	InstallerCommandLineInfo::Instance = shared_any<InstallerCommandLineInfo *, close_delete>(new InstallerCommandLineInfo());
	InstallerLauncher::Instance = shared_any<InstallerLauncher *, close_delete>(new InstallerLauncher());
	InstallerLog::Instance = shared_any<InstallerLog *, close_delete>(new InstallerLog());
	InstallerSession::Instance = shared_any<InstallerSession *, close_delete>(new InstallerSession());
	InstallUILevelSetting::Instance = shared_any<InstallUILevelSetting *, close_delete>(new InstallUILevelSetting());

	try
	{
		ParseCommandLine(* get(InstallerCommandLineInfo::Instance));

		LOG(L"-------------------------------------------------------------------");
		LOG(L"dotNetInstaller (DNI) started, version " << TEXT(VERSION_VALUE));
		LOG(VERSION_LEGALCOPYRIGHT_VALUE);
		LOG(L"Operating system: " << DVLib::GetOperatingSystemVersionString());
		LOG(L"-------------------------------------------------------------------");

		std::map<std::wstring, std::wstring>::iterator arg = InstallerCommandLineInfo::Instance->componentCmdArgs.begin();
		while(arg != InstallerCommandLineInfo::Instance->componentCmdArgs.end())
		{
			LOG(L"Component arguments: \"" + arg->first + L"\": " << arg->second);
			arg ++;
		}

		// propagate command line arguments during execution
		InstallerSession::Instance->AdditionalCmdLineArgs = InstallerCommandLineInfo::Instance->componentCmdArgs;

		ConfigFileManager config;
		config.Load();
		m_rc = config.Run();
	}
	catch(std::exception& ex)
	{
        DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK|MB_ICONSTOP);
		m_rc = -1;
	}

	// Poiché la finestra di dialogo è stata chiusa, restituisce FALSE in modo che l'applicazione
	//  venga terminata, anziché avviare la message pump dell'applicazione.
	return FALSE;
}

int CdotNetInstallerApp::ExitInstance() 
{
	reset(InstallerCommandLineInfo::Instance);
	reset(InstallerLauncher::Instance);
	reset(InstallerLog::Instance);
	reset(InstallerSession::Instance);
	reset(InstallUILevelSetting::Instance);
	// ignore the MFC return code, which is typically the last key pressed
	CWinApp::ExitInstance();
	return m_rc;
}
