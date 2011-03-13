#include "StdAfx.h"
#include <Version/Version.h>
#include "InstallerCommandLineInfo.h"
#include "InstallerLog.h"
#include "InstallUILevel.h"
#include "InstallerLauncher.h"
#include "InstallerSession.h"

shared_any<InstallerCommandLineInfo *, close_delete> InstallerCommandLineInfo::Instance;

InstallerCommandLineInfo::InstallerCommandLineInfo()
	: m_displayCab(false)
	, m_extractCab(false)
	, m_displayHelp(false)
	, m_lastArgFlag(unknown)
	, m_reboot(false)
	, m_autostart(false)
	, m_noreboot(false)
	, m_enableRunOnReboot(true)
	, m_displayConfig(false)
	, m_displaySplash(true)
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
		else if (_wcsicmp(pszParam, TEXT("log")) == 0)
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
		// install (default)
		else if (_wcsicmp(pszParam, TEXT("i")) == 0)
		{
			InstallerSession::Instance->sequence = SequenceInstall;
		}
		// uninstall
		else if (_wcsicmp(pszParam, TEXT("x")) == 0)
		{
			InstallerSession::Instance->sequence = SequenceUninstall;
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
		else if (_wcsicmp(pszParam, TEXT("extractCab")) == 0)
		{
            m_extractCab = true;
		}
		else if (_wcsicmp(pszParam, TEXT("displayCab")) == 0)
		{
            m_displayCab = true;
		}
		else if (_wcsicmp(pszParam, TEXT("displayConfig")) == 0)
		{
            m_displayConfig = true;
		}
        else if (_wcsicmp(pszParam, TEXT("componentArgs")) == 0)
        {
            m_lastArgFlag = componentArgs;
        }
        else if (_wcsicmp(pszParam, TEXT("controlArgs")) == 0)
        {
            m_lastArgFlag = controlArgs;
        }
		else if (_wcsicmp(pszParam, TEXT("reboot")) == 0)
		{
            m_reboot = true;
		}
		else if (_wcsicmp(pszParam, TEXT("autostart")) == 0)
		{
            m_autostart = true;
		}
		else if (_wcsicmp(pszParam, TEXT("noreboot")) == 0)
		{
            m_noreboot = true;
		}
		else if (_wcsicmp(pszParam, TEXT("noRunOnReboot")) == 0)
		{
            m_enableRunOnReboot = false;
		}
		else if (_wcsicmp(pszParam, TEXT("nosplash")) == 0)
		{
			m_displaySplash = false;
		}
		else
		{
			THROW_EX(L"Invalid command-line parameter: /" << pszParam);
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
				logFile = pszParam;
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
				{
					std::vector<std::wstring> l_componentArgsArray = DVLib::split(pszParam, L":", 2);
					if (l_componentArgsArray.size() != 2)
					{
						std::string error = "Invalid component argument: ";
						error.append(DVLib::wstring2string(pszParam));
						throw std::exception(error.c_str());
					}
					componentCmdArgs[l_componentArgsArray[0]] = l_componentArgsArray[1];
				}
                break;
            case controlArgs:
				{
					std::vector<std::wstring> l_controlArgsArray = DVLib::split(pszParam, L":", 2);
					if (l_controlArgsArray.size() != 2)
					{
						std::string error = "Invalid control argument: ";
						error.append(DVLib::wstring2string(pszParam));
						throw std::exception(error.c_str());
					}
					controlCmdArgs[l_controlArgsArray[0]] = l_controlArgsArray[1];
				}
                break;
			default:
				THROW_EX(L"Unexpected command-line argument: " << pszParam);
				break;
		}

        m_lastArgFlag = unknown;
	}
}

std::wstring InstallerCommandLineInfo::GetUsage() const
{
	std::wstringstream hs;
	hs << L"Usage: " << DVLib::GetFileNameW(DVLib::GetModuleFileNameW()) << L" [args]" << std::endl;
	hs << std::endl;
	hs << L" /? or /help : this help screen" << std::endl;
	hs << L" /i : install (default)" << std::endl;
	hs << L" /x : uninstall" << std::endl;
	hs << L" /q : force silent (no UI) mode" << std::endl;
	hs << L" /qb : force basic UI mode" << std::endl;
	hs << L" /nq : force full UI mode" << std::endl;
	hs << L" /nosplash : do not display splash screen" << std::endl;
	hs << L" /Log : enable logging" << std::endl;
	hs << L" /LogFile [path] : specify log file" << std::endl;
	hs << L" /ConfigFile [path] : specify configuration file" << std::endl;
	hs << L" /ExtractCab: extract embedded components" << std::endl;
	hs << L" /DisplayCab: display a list of embedded components" << std::endl;
	hs << L" /DisplayConfig: display a list of configurations" << std::endl;
	hs << L" /ComponentArgs [\"id|display_name\":\"value\" ...] : additional component args" << std::endl;
	hs << L" /ControlArgs [\"id\":\"value\" ...] : additional control values" << std::endl;
	hs << L" /CompleteCommandArgs [args] : additional complete command" << std::endl;
	hs << std::endl;
	hs << L"Built by dotNetInstaller (DNI), version " << TEXT(VERSION_VALUE);		
	return hs.str();
}