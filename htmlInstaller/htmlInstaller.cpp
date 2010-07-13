#include "StdAfx.h"
#include "htmlInstaller.h"
#include "HtmlWindow.h"
#include "ConfigFileManager.h"
#include <Version/Version.h>

#define MAX_LOADSTRING 100

HINSTANCE hInst; // current instance
TCHAR szWindowClass[MAX_LOADSTRING]; // the main window class name

BOOL InitInstance(HINSTANCE, int);
void ExitInstance();
void ParseCommandLine(CCommandLineInfo& rCmdInfo);
void DisplayHelp();
void DisplayCab();
void ExtractAllCabs();
void DisplayConfig();
void ExtractCab(const std::wstring& id);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	try
	{
		UNREFERENCED_PARAMETER(hPrevInstance);
		UNREFERENCED_PARAMETER(lpCmdLine);

		HtmlWindow::RegisterClass(hInstance);

 		// TODO: Place code here.
		MSG msg;
		HACCEL hAccelTable;

		// Initialize global strings
		LoadString(hInstance, IDC_HTMLINSTALLER, szWindowClass, MAX_LOADSTRING);

		// Perform application initialization:
		if (! InitInstance(hInstance, nCmdShow))
			return 0;

		hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HTMLINSTALLER));

		ConfigFileManagerPtr config(new ConfigFileManager());
		config->Load();
		int rc = config->Run();

		// Main message loop:
		while (GetMessage(&msg, NULL, 0, 0))
		{
			// execute asynchronous tasks in GUI thread.
			htmlayout::queue::execute();

			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		TRYLOG(L"htmlInstaller finished, return code=" << rc);
		ExitInstance();
		return rc;
	}
	catch(std::exception& ex)
	{
        DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK|MB_ICONSTOP);
		TRYLOG(L"Error: " << DVLib::string2wstring(ex.what()));
		return -1;
	}
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	InstallerCommandLineInfo::Instance = shared_any<InstallerCommandLineInfo *, close_delete>(new InstallerCommandLineInfo());
	InstallerLauncher::Instance = shared_any<InstallerLauncher *, close_delete>(new InstallerLauncher());
	InstallerLog::Instance = shared_any<InstallerLog *, close_delete>(new InstallerLog());
	InstallerSession::Instance = shared_any<InstallerSession *, close_delete>(new InstallerSession());
	InstallUILevelSetting::Instance = shared_any<InstallUILevelSetting *, close_delete>(new InstallUILevelSetting());

	ParseCommandLine(* get(InstallerCommandLineInfo::Instance));
		
	CSplashWnd::EnableSplashScreen(InstallerCommandLineInfo::Instance->DisplaySplash());

	LOG(L"-------------------------------------------------------------------");
	LOG(L"htmlNetInstaller (DNI) started, version " << TEXT(VERSION_VALUE));
	LOG(VERSION_LEGALCOPYRIGHT_VALUE);
	LOG(L"Operating system: " << DVLib::GetOperatingSystemVersionString());
	LOG(L"-------------------------------------------------------------------");
	LOG(L"Sequence: " << InstallSequenceUtil::towstring(InstallerSession::Instance->sequence));

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

	return TRUE;
}

void ExitInstance()
{
	reset(InstallerCommandLineInfo::Instance);
	reset(InstallerLauncher::Instance);
	reset(InstallerLog::Instance);
	reset(InstallerSession::Instance);
	reset(InstallUILevelSetting::Instance);
}

void ParseCommandLine(CCommandLineInfo& rCmdInfo)
{
	for (int i = 1; i < __argc; i++)
	{
		LPCTSTR pszParam = __targv[i];
		BOOL bFlag = FALSE;
		BOOL bLast = ((i + 1) == __argc);
		if (pszParam[0] == '-' || pszParam[0] == '/')
		{
			// remove flag specifier
			bFlag = TRUE;
			++pszParam;
		}
		rCmdInfo.ParseParam(pszParam, bFlag, bLast);
	}
}

void DisplayHelp()
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

void DisplayCab()
{
	// TODO
}

void ExtractAllCabs()
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

void ExtractCab(const std::wstring& id)
{
	// TODO
}

void DisplayConfig()
{
	ConfigFileManagerPtr config(new ConfigFileManager());
	config->Load();
	DniMessageBox::Show(config->GetString(), MB_OK|MB_ICONINFORMATION);
}
