#include "StdAfx.h"
#include "htmlInstaller.h"
#include "HtmlWindow.h"
#include "ConfigFileManager.h"
#include "HtmlayoutDll.h"
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

		reset(config);

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

	reset(InstallerCommandLineInfo::Instance, new InstallerCommandLineInfo());
	reset(InstallerLauncher::Instance, new InstallerLauncher());
	reset(InstallerLog::Instance, new InstallerLog());
	reset(InstallerSession::Instance, new InstallerSession());
	reset(InstallUILevelSetting::Instance, new InstallUILevelSetting());
	reset(HtmLayoutDll::Instance, new HtmLayoutDll());

	HtmlWindow::RegisterClass(hInstance);

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
	reset(HtmLayoutDll::Instance);
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
	DniMessageBox::Show(InstallerCommandLineInfo::Instance->GetUsage(), MB_OK|MB_ICONINFORMATION);
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
