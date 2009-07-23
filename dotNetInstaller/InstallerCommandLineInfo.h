#pragma once
#include "afxwin.h"

class InstallerCommandLineInfo :
	public CCommandLineInfo
{
public:
	static shared_any<InstallerCommandLineInfo *, close_delete> Instance;
	InstallerCommandLineInfo();
	void ParseParam(const TCHAR* pszParam, BOOL bFlag, BOOL bLast);
    const std::wstring& GetCompleteCommandArgs() const { return m_completeCommandArgs; }
    bool ExtractCab() const { return m_extractCab; }
	bool DisplayCab() const { return m_displayCab; }
	bool DisplayHelp() const { return m_displayHelp; }
public:
	std::wstring configFile;
    std::map<std::wstring, std::wstring> componentCmdArgs;
private:
	
	enum argFlags 
	{ 
		unknown, 		
		logfile,
		configfile,		
		launcher, 
		launcherArgs, 
		completeCommandArgs,		
		componentArgs
	};
	
	argFlags m_lastArgFlag;
    std::wstring m_completeCommandArgs;
    bool m_extractCab;
	bool m_displayCab;
	bool m_displayHelp;
};

