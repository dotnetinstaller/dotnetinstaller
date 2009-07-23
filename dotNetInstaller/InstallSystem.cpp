#include "StdAfx.h"
#include "InstallSystem.h"
#include "InstallerLauncher.h"

// HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce
#define c_dotNetInstaller TEXT("dotNetInstallerBoot")
//#define c_RunOnce "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce"
#define c_Reg_Run TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run")

void InsertRegistryRun()
{
	// get the installer launcher command (if specified)
	std::wstring l_Cmd = InstallerLauncher::Instance->GetLauncherCmd();

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

	DVLib::RegistrySetStringValue(HKEY_LOCAL_MACHINE, c_Reg_Run, c_dotNetInstaller, l_Cmd);
};

 void RemoveRegistryRun()
{
	if (DVLib::RegistryKeyExists(HKEY_LOCAL_MACHINE, c_Reg_Run, c_dotNetInstaller))
	{
		DVLib::RegistryDeleteValue(HKEY_LOCAL_MACHINE, c_Reg_Run, c_dotNetInstaller);
	}
};

