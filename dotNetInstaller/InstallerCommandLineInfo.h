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

    const CString& GetCompleteCommandArgs() const { return m_completeCommandArgs; }
    bool ExtractCab() const { return m_extractCab; }
public:
    std::map<std::wstring, std::wstring> m_componentCmdArgs;
// Matthew Sheets - 2007-11-26: Support more advanced command line argument processing
private:
	enum m_argFlags { unknown, log, logfile, silent, noSilent, launcher, launcherArgs, completeCommandArgs, extractCab, componentArgs };
	m_argFlags m_lastArgFlag;
    CString m_completeCommandArgs;
    bool m_extractCab;
};

extern CInstallerCommandLineInfo commandLineInfo;