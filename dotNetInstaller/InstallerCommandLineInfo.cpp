#include "StdAfx.h"
#include "InstallerCommandLineInfo.h"
#include "InstallerLog.h"
#include "SilentInstall.h"
#include "InstallerLauncher.h"

CInstallerCommandLineInfo commandLineInfo;

CInstallerCommandLineInfo::CInstallerCommandLineInfo(void)
{
}

CInstallerCommandLineInfo::~CInstallerCommandLineInfo(void)
{
}

void CInstallerCommandLineInfo::ParseParam(const TCHAR* pszParam, BOOL bFlag, BOOL bLast)
{
	if (bFlag)
    {
		if (_tcsicmp(pszParam, TEXT("log")) == 0 )
		{
			m_lastArgFlag = log;
			ApplicationLog.EnableLog();
		}

		// specify log filename and path
		else if (_tcsicmp(pszParam, TEXT("logfile")) == 0)
		{
			m_lastArgFlag = logfile;
		}
		// enable silent installs from the command line
		else if (_tcsicmp(pszParam, TEXT("q")) == 0)
		{
			m_lastArgFlag = silent;
			QuietInstall.EnableSilentInstall();
		}
        // disable silent installs from the command line
		else if (_tcsicmp(pszParam, TEXT("nq")) == 0)
		{
			m_lastArgFlag = noSilent;
			QuietInstall.OverrideSilentInstall();
		}
		// accept another command to use in RegistryRun
		else if (_tcsicmp(pszParam, TEXT("launcher")) == 0)
		{
			m_lastArgFlag = launcher;
		}
		// accept arguments to use with the launcher RegistryRun command
		else if (_tcsicmp(pszParam, TEXT("launcherArgs")) == 0)
		{
			m_lastArgFlag = launcherArgs;
		}
        // accept arguments to use in complete command args
		else if (_tcsicmp(pszParam, TEXT("completeCommandArgs")) == 0)
		{
			m_lastArgFlag = completeCommandArgs;
		}
		else if (_tcsicmp(pszParam, TEXT("extractCab")) == 0 )
		{
			m_lastArgFlag = extractCab;
            m_extractCab = true;
		}
        else if (_tcsicmp(pszParam, TEXT("componentArgs")) == 0)
        {
            m_lastArgFlag = componentArgs;
        }
		else
		{
			m_lastArgFlag = unknown;
		}
	}
	else
	{
		switch (m_lastArgFlag)
		{
			case log:
				break;
			case silent:
				break;
			case noSilent:
				break;
            case logfile:
                ApplicationLog.SetLogFile(pszParam);
                break;
			case launcher:
				DNILauncher.SetLauncherPath(pszParam);
				break;
			case launcherArgs:
				// NOTE: Actual LauncherArgs must be enclosed in quotes
				// IMPORTANT: If first character after the quote is a flag character (e.g. "-" or "/"),
				//    the argument is (incorrectly?) interpreted as a flag.
				//    To work around this, leave a space between the opening quote and the first
				//       launcherArg charater
				// EXAMPLE: To set LauncherArgs as /q -Z, the format should be as follows (note quotes and spacing):
				//    /launcherArgs " /q -Z"
				DNILauncher.SetLauncherArgs(pszParam);
				break;
			case completeCommandArgs:
				m_completeCommandArgs = pszParam;
                break;
            case extractCab:
				break;
            case componentArgs:
		        stlvectorstring l_componentArgsArray;
                split_string(pszParam, ':', l_componentArgsArray, 2);
                if (l_componentArgsArray.size() != 2) 
                {
                    std::string error = "Invalid component argument parameter: ";
                    error.append(DVLib::wstring2string(pszParam));
                    throw std::exception(error.c_str());
                }
                m_componentCmdArgs[l_componentArgsArray[0]] = l_componentArgsArray[1];
                break;
		}

        m_lastArgFlag = unknown;
	}
}