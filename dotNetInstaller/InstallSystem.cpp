#include "StdAfx.h"
#include "InstallSystem.h"
#include "InstallerLauncher.h"

// HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce
#define c_dotNetInstaller TEXT("dotNetInstallerBoot")
//#define c_RunOnce "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce"
#define c_Reg_Run TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run")

void InsertRegistryRun()
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
		std::wstring l_Cmd = DNILauncher.GetLauncherCmd();

		// if no launcher argument was specified, use the DNI command line
		if (l_Cmd.empty())
		{
			l_Cmd = _T("\"") + std::wstring(DVLib::GetModuleFileNameW().c_str()) + _T("\"");
            if (__argc > 1)
            {                
                l_Cmd.append(::GetCommandLineW() + wcslen(__targv[0]) 
                    + (::GetCommandLineW()[0] == '\"' ? 2 : 0));
            }
		}

		RegSetValueEx(l_HKey, c_dotNetInstaller,0,REG_SZ,(LPBYTE)l_Cmd.c_str(), (DWORD)(l_Cmd.length()+1) * sizeof(TCHAR) );

		RegCloseKey(l_HKey);
	}
    catch(std::exception&)
	{
		_ASSERT(false);
	}
};

 void RemoveRegistryRun()
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
bool InitiateReboot()
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

	return ExitWindowsEx( EWX_REBOOT, 0) ? true : false;
}