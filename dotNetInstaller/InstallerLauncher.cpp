#include "stdafx.h"
#include "InstallerLauncher.h"

// support alternate installer launchers
shared_any<InstallerLauncher *, close_delete> InstallerLauncher::Instance;

InstallerLauncher::InstallerLauncher(void)
{
	_tcscpy_s(m_LauncherPath, TEXT(""));
	_tcscpy_s(m_LauncherArgs, TEXT(""));
	_tcscpy_s(m_LauncherCmd, TEXT(""));
}

