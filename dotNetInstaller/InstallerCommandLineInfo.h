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

    const std::wstring& GetCompleteCommandArgs() const { return m_completeCommandArgs; }
    bool ExtractCab() const { return m_extractCab; }
public:
    std::map<std::wstring, std::wstring> m_componentCmdArgs;
private:
	enum m_argFlags 
	{ 
		unknown, 
		log, 
		logfile, 
		silent, 
		noSilent, 
		basic, 
		launcher, 
		launcherArgs, 
		completeCommandArgs, 
		extractCab, 
		componentArgs 
	};
	m_argFlags m_lastArgFlag;
    std::wstring m_completeCommandArgs;
    bool m_extractCab;
};

extern CInstallerCommandLineInfo commandLineInfo;