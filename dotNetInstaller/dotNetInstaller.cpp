#include "stdafx.h"
#include "dotNetInstaller.h"
#include "dotNetInstallerDlg.h"
#include "ConfigFileManager.h"
#include <Version/Version.h>
#include "ExtractCabProcessor.h"
#include "ExtractCabDlg.h"

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
        reset(InstallerCommandLineInfo::Instance, new InstallerCommandLineInfo());
        reset(InstallerLauncher::Instance, new InstallerLauncher());
        reset(InstallerLog::Instance, new InstallerLog());
        reset(InstallerSession::Instance, new InstallerSession());
        reset(InstallUILevelSetting::Instance, new InstallUILevelSetting());

        DVLib::LoggerManager::Register(* get(InstallerLog::Instance));

        ParseCommandLine(* get(InstallerCommandLineInfo::Instance));

        CSplashWnd::EnableSplashScreen(InstallerCommandLineInfo::Instance->DisplaySplash());

        LOG(L"-------------------------------------------------------------------");
        LOG(L"dotNetInstaller (DNI) started, version " << TEXT(VERSION_VALUE));
        LOG(VERSION_LEGALCOPYRIGHT_VALUE);
        LOG(L"Operating system: " << DVLib::GetOperatingSystemVersionString() << 
            L" (" << DVLib::pa2wstring(DVLib::GetProcessorArchitecture()) << L")");
        LOG(L"-------------------------------------------------------------------");
        LOG(L"Sequence: " << InstallSequenceUtil::towstring(InstallerSession::Instance->sequence));

        std::map<std::wstring, std::wstring>::iterator arg = InstallerCommandLineInfo::Instance->componentCmdArgs.begin();
        while(arg != InstallerCommandLineInfo::Instance->componentCmdArgs.end())
        {
            LOG(L"Component arguments: \"" + arg->first + L"\": " << arg->second);
            arg++;
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
            ExtractAllCabs();
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
        DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK|MB_ICONSTOP);
        TRYLOG(L"Error: " << DVLib::string2wstring(ex.what()));
        m_rc = -1;
    }

    // Poiché la finestra di dialogo è stata chiusa, restituisce FALSE in modo che l'applicazione
    //  venga terminata, anziché avviare la message pump dell'applicazione.
    return FALSE;
}

int CdotNetInstallerApp::ExitInstance() 
{
    TRYLOG(L"dotNetInstaller finished, return code: " << m_rc << DVLib::FormatMessage(L" (0x%x)", m_rc));
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
    DniMessageBox::Show(InstallerCommandLineInfo::Instance->GetUsage(), MB_OK|MB_ICONINFORMATION);
}

void CdotNetInstallerApp::DisplayCab()
{
    InstallComponentDlg dlg;
    ExtractCabProcessorPtr extractcab(new ExtractCabProcessor(AfxGetApp()->m_hInstance, L"", & dlg));
    DniMessageBox::Show(DVLib::join(extractcab->GetCabFiles(), L"\r\n"), MB_OK|MB_ICONINFORMATION);
}

void CdotNetInstallerApp::ExtractAllCabs()
{
    ExtractCab(L"");
    ConfigFileManagerPtr config(new ConfigFileManager());
    config->Load();
    for each(const ConfigurationPtr& configuration in * config)
    {
        if (configuration->type != configuration_install)
            continue;

        InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(configuration));
        for each (const ComponentPtr& component in p_configuration->components)
        {
            ExtractCab(component->id);
        }
    }
}

void CdotNetInstallerApp::ExtractCab(const std::wstring& id)
{
    ExtractCabDlg dlg;

    ExtractCabProcessorPtr p_extractcab(new ExtractCabProcessor(AfxGetApp()->m_hInstance, id, & dlg));	
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
