#include "StdAfx.h"
#include ".\installercommandlineinfo.h"
#include "InstallerLog.h"

CInstallerCommandLineInfo::CInstallerCommandLineInfo(void)
{
}

CInstallerCommandLineInfo::~CInstallerCommandLineInfo(void)
{
}

void CInstallerCommandLineInfo::ParseParam(const TCHAR* pszParam, 
											BOOL bFlag,
											BOOL bLast)
{
	if (bFlag &&
		_tcsicmp(pszParam, TEXT("log")) == 0 )
	{
		ApplicationLog.EnableLog();
	}
}