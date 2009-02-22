#pragma once
#include "afxwin.h"

class CInstallerCommandLineInfo :
	public CCommandLineInfo
{
public:
	CInstallerCommandLineInfo(void);
	virtual ~CInstallerCommandLineInfo(void);

	virtual void ParseParam(
					const TCHAR* pszParam, 
					BOOL bFlag,
					BOOL bLast);
};
