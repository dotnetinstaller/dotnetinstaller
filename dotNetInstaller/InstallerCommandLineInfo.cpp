#include "StdAfx.h"
#include "InstallerCommandLineInfo.h"
#include "InstallerLauncher.h"

shared_any<InstallerCommandLineInfo *, close_delete> InstallerCommandLineInfo::Instance;

InstallerCommandLineInfo::InstallerCommandLineInfo()
	: m_displayCab(false)
	, m_extractCab(false)
	, m_displayHelp(false)
	, m_lastArgFlag(unknown)
{

}

void InstallerCommandLineInfo::ParseParam(const TCHAR* pszParam, BOOL bFlag, BOOL /*bLast*/)
{
	if (bFlag)
    {
		m_lastArgFlag = unknown;
		if ((_wcsicmp(pszParam, TEXT("?")) == 0) || (_wcsicmp(pszParam, TEXT("help")) == 0))
		{
			m_displayHelp = true;
		}
		if (_wcsicmp(pszParam, TEXT("log")) == 0 )
		{
			InstallerLog::Instance->EnableLog();
		}
		// specify log filename and path
		else if (_wcsicmp(pszParam, TEXT("logfile")) == 0)
		{
			m_lastArgFlag = logfile;
		}
		// specify configuration filename and path
		else if (_wcsicmp(pszParam, TEXT("configfile")) == 0)
		{
			m_lastArgFlag = configfile;
		}
		// enable silent installs from the command line
		else if (_wcsicmp(pszParam, TEXT("q")) == 0)
		{
			InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelSilent);
		}
        // disable silent installs from the command line
		else if (_wcsicmp(pszParam, TEXT("nq")) == 0)
		{
			InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelFull);
		}
		// enable silent installs from the command line
		else if (_wcsicmp(pszParam, TEXT("qb")) == 0)
		{
			InstallUILevelSetting::Instance->SetRuntimeLevel(InstallUILevelBasic);
		}
		// accept another command to use in RegistryRun
		else if (_wcsicmp(pszParam, TEXT("launcher")) == 0)
		{
			m_lastArgFlag = launcher;
		}
		// accept arguments to use with the launcher RegistryRun command
		else if (_wcsicmp(pszParam, TEXT("launcherArgs")) == 0)
		{
			m_lastArgFlag = launcherArgs;
		}
        // accept arguments to use in complete command args
		else if (_wcsicmp(pszParam, TEXT("completeCommandArgs")) == 0)
		{
			m_lastArgFlag = completeCommandArgs;
		}
		else if (_wcsicmp(pszParam, TEXT("extractCab")) == 0 )
		{
            m_extractCab = true;
		}
		else if (_wcsicmp(pszParam, TEXT("displayCab")) == 0 )
		{
            m_displayCab = true;
		}
        else if (_wcsicmp(pszParam, TEXT("componentArgs")) == 0)
        {
            m_lastArgFlag = componentArgs;
        }
	}
	else
	{
		switch (m_lastArgFlag)
		{
			case configfile:
				configFile = pszParam;
				break;
            case logfile:
				InstallerLog::Instance->SetLogFile(pszParam);
                break;
			case launcher:
				InstallerLauncher::Instance->SetLauncherPath(pszParam);
				break;
			case launcherArgs:
				// NOTE: Actual LauncherArgs must be enclosed in quotes
				// IMPORTANT: If first character after the quote is a flag character (e.g. "-" or "/"),
				//    the argument is (incorrectly?) interpreted as a flag.
				//    To work around this, leave a space between the opening quote and the first
				//       launcherArg charater
				// EXAMPLE: To set LauncherArgs as /q -Z, the format should be as follows (note quotes and spacing):
				//    /launcherArgs " /q -Z"
				InstallerLauncher::Instance->SetLauncherArgs(pszParam);
				break;
			case completeCommandArgs:
				m_completeCommandArgs = pszParam;
                break;
            case componentArgs:
				std::vector<std::wstring> l_componentArgsArray = DVLib::split(pszParam, L":", 2);
                if (l_componentArgsArray.size() != 2)
                {
                    std::string error = "Invalid component argument parameter: ";
                    error.append(DVLib::wstring2string(pszParam));
                    throw std::exception(error.c_str());
                }
                componentCmdArgs[l_componentArgsArray[0]] = l_componentArgsArray[1];
                break;
		}

        m_lastArgFlag = unknown;
	}
}
