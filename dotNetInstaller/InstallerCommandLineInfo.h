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

// Matthew Sheets - 2007-11-26: Support more advanced command line argument processing
private:
	enum m_argFlags { unknown, log, silent, noSilent, launcher, launcherArgs };
	m_argFlags m_lastArgFlag;
};
