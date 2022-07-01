#include "StdAfx.h"
#include "htmlInstaller.h"
#include "HtmlWindow.h"
#include "ConfigFileManager.h"
#include "HtmlayoutDll.h"
#include "ExtractCabProcessor.h"
#include <Version/Version.h>

BEGIN_MESSAGE_MAP(CHtmlInstallerApp, CWinApp)
    ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CHtmlInstallerApp::CHtmlInstallerApp()
: m_rc(0)
{

}

CHtmlInstallerApp theApp;

BOOL CHtmlInstallerApp::InitInstance()
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
        reset(HtmLayoutDll::Instance, new HtmLayoutDll());

        HtmlWindow::RegisterClass(m_hInstance);

        DVLib::LoggerManager::Register(*get(InstallerLog::Instance));

        ParseCommandLine(*get(InstallerCommandLineInfo::Instance));

        CSplashWnd::EnableSplashScreen(InstallerCommandLineInfo::Instance->DisplaySplash());

        LOG(L"-------------------------------------------------------------------");
        LOG(L"htmlNetInstaller (DNI) started, version " << TEXT(VERSION_VALUE));
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

        ConfigFileManagerPtr config(new ConfigFileManager());
        config->Load();
        config->Run();
        m_rc = config->GetRecordedError();
        reset(config);
    }
    catch(std::exception& ex)
    {
        DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK|MB_ICONSTOP);
        TRYLOG(L"Error: " << DVLib::string2wstring(ex.what()));
        m_rc = -1;
    }

    return FALSE;
}

int CHtmlInstallerApp::ExitInstance() 
{
    TRYLOG(L"htmlInstaller finished, return code: " << m_rc << DVLib::FormatMessage(L" (0x%x)", m_rc));

    reset(HtmLayoutDll::Instance);
    reset(InstallerCommandLineInfo::Instance);
    reset(InstallerLauncher::Instance);
    reset(InstallerLog::Instance);
    reset(InstallerSession::Instance);
    reset(InstallUILevelSetting::Instance);

    CWinApp::ExitInstance();
    return m_rc;
}

void CHtmlInstallerApp::DisplayHelp()
{
    DniMessageBox::Show(InstallerCommandLineInfo::Instance->GetUsage(), MB_OK|MB_ICONINFORMATION);
}

void CHtmlInstallerApp::DisplayCab()
{
    ExtractCabProcessorPtr extractcab(new ExtractCabProcessor(InstallerWindow::s_hinstance, L"", NULL));
    DniMessageBox::Show(DVLib::join(extractcab->GetCabFiles(), L"\r\n"), MB_OK|MB_ICONINFORMATION);
}

void CHtmlInstallerApp::ExtractAllCabs()
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

void CHtmlInstallerApp::ExtractCab(const std::wstring& id)
{
    ExtractCabProcessorPtr p_extractcab(new ExtractCabProcessor(InstallerWindow::s_hinstance, id, NULL));	
    int cab_count = p_extractcab->GetCabCount();
    if (cab_count == 0)
    {
        LOG(L"Extracting embedded files for component '" << (id.empty() ? L"*" : id) << L"': NO FILES EMBEDDED");
        return;
    }

    LOG(L"Extracting embedded files for component '" << (id.empty() ? L"*" : id) << L"': " << cab_count << L" CAB(s)");

    p_extractcab->cab_path = DVLib::GetCurrentDirectoryW();
    p_extractcab->cab_path.append(L"\\SupportFiles");
    p_extractcab->BeginExec();
    p_extractcab->EndExec();
}

void CHtmlInstallerApp::DisplayConfig()
{
    ConfigFileManagerPtr config(new ConfigFileManager());
    config->Load();
    DniMessageBox::Show(config->GetString(), MB_OK|MB_ICONINFORMATION);
}

BOOL CHtmlInstallerApp::PreTranslateMessage(MSG * pMsg)
{
    // route messages to the splash screen while it is visible
    if (CSplashWnd::PreTranslateAppMessage(pMsg)) 
    {
        return TRUE;
    }

    return CWinApp::PreTranslateMessage(pMsg);
}
