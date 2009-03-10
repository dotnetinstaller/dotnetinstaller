#pragma once
#include "Component.h"

//in tutti i percorsi viene sostituito #APPPATH con il percorso dell'applicazione corrente, #SYSTEMPATH con la directory System del computer e #WINDOWSPATH con la directory di installazione di Windows, #TEMPPATH con la directory temporanea
//in all the paths we replace the string constant #APPPATH with the current path of the application and #SYSTEMPATH with the system directory of the computer, #TEMPPATH with the temp directory

#define c_APPPATH TEXT("#APPPATH")
#define c_SYSTEMPATH TEXT("#SYSTEMPATH")
#define c_WINDOWSPATH TEXT("#WINDOWSPATH")
#define c_SYSTEMWINDOWSPATH TEXT("#SYSTEMWINDOWSPATH")
#define c_TEMPPATH TEXT("#TEMPPATH")
#define c_CABPATH TEXT("#CABPATH")
#define c_GUID TEXT("#GUID")

#include "InstallerLauncher.h"

// top-level configuration settings
struct configSetting
{
	bool silent_install;
};


// HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce
#define c_dotNetInstaller TEXT("dotNetInstallerBoot")
//#define c_RunOnce "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce"
#define c_Reg_Run TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run")

inline void InsertRegistryRun()
{
	try
	{
		HKEY l_HKey;
		LONG l_result = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
					c_Reg_Run,
					0,
					KEY_WRITE,
					&l_HKey);
		if (l_result != ERROR_SUCCESS)
			return;

		// get the installer launcher command (if specified)
		CString l_Cmd = DNILauncher.GetLauncherCmd();

		// if no launcher argument was specified, use the DNI command line
		if (l_Cmd.GetLength() == 0)
		{
			l_Cmd = _T("\"") + DVLib::GetAppFullName() + _T("\"");
            if (__argc > 1)
            {                
                l_Cmd.Append(::GetCommandLineW() + wcslen(__targv[0]) 
                    + (::GetCommandLineW()[0] == '\"' ? 2 : 0));
            }
		}

		RegSetValueEx(l_HKey, c_dotNetInstaller,0,REG_SZ,(LPBYTE)(LPCTSTR)l_Cmd, (DWORD)(l_Cmd.GetLength()+1) * sizeof(TCHAR) );

		RegCloseKey(l_HKey);
	}
    catch(std::exception&)
	{
		_ASSERT(false);
	}
};

inline void RemoveRegistryRun()
{
	try
	{
		HKEY l_HKey;
		LONG l_result = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
					c_Reg_Run,
					0,
					KEY_WRITE,
					&l_HKey);
		if (l_result != ERROR_SUCCESS)
			return;

		RegDeleteValue(l_HKey, c_dotNetInstaller);

		RegCloseKey(l_HKey);
	}
	catch(std::exception&)
	{
		_ASSERT(false);
	}
};

// ==========================================================================
// InitiateReboot()
//
// Purpose: initiates a system reboot
//
// ==========================================================================
inline BOOL InitiateReboot()
{
    HANDLE hToken;              // handle to process token 
    TOKEN_PRIVILEGES tkp;       // pointer to token structure     
     
    try 
    {
        // Get the current process token handle so we can get shutdown 
        // privilege. 
         
        if (!OpenProcessToken(GetCurrentProcess(), 
                TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
        {
           // return FALSE;
        }
         
        // Get the LUID for shutdown privilege. 
         
        LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, 
                &tkp.Privileges[0].Luid); 
         
        tkp.PrivilegeCount = 1;  // one privilege to set    
        tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 
         
        // Get shutdown privilege for this process. 
         
        AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, 
            (PTOKEN_PRIVILEGES) NULL, 0); 
         
        // Cannot test the return value of AdjustTokenPrivileges. 
         
        if (GetLastError() != ERROR_SUCCESS) 
        {
           // return FALSE;
        }
    }

    catch (...)
    {
    }
    return ExitWindowsEx( EWX_REBOOT, 0);
}
