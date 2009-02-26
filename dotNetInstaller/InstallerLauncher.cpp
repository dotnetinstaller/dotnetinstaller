#include "stdafx.h"
#include "InstallerLauncher.h"

// support alternate installer launchers
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
