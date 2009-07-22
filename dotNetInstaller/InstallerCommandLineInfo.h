#pragma once
#include "afxwin.h"

class CInstallerCommandLineInfo :
	public CCommandLineInfo
{
public:
	CInstallerCommandLineInfo();
	void ParseParam(const TCHAR* pszParam, BOOL bFlag, BOOL bLast);
    const std::wstring& GetCompleteCommandArgs() const { return m_completeCommandArgs; }
    bool ExtractCab() const { return m_extractCab; }
	bool DisplayCab() const { return m_displayCab; }
public:
	std::wstring configFile;
    std::map<std::wstring, std::wstring> componentCmdArgs;
private:
	enum m_argFlags 
	{ 
		unknown, 
		log, 
		logfile,
		configfile,
		silent, 
		noSilent, 
		basic, 
		launcher, 
		launcherArgs, 
		completeCommandArgs, 
		extractCab, 
		displayCab,
		componentArgs 
	};
	m_argFlags m_lastArgFlag;
    std::wstring m_completeCommandArgs;
    bool m_extractCab;
	bool m_displayCab;
};

extern CInstallerCommandLineInfo commandLineInfo;
