#include "stdafx.h"
#include "InstallerLauncher.h"

// Matthew Sheets - 2007-11-27: Support alternate installer launchers

InstallerLauncher DNILauncher;

InstallerLauncher::InstallerLauncher(void)
{
	_tcscpy_s(m_LauncherPath, TEXT(""));
	_tcscpy_s(m_LauncherArgs, TEXT(""));
	_tcscpy_s(m_LauncherCmd, TEXT(""));
}

InstallerLauncher::~InstallerLauncher(void)
{
}
