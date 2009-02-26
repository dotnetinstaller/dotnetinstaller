#pragma once

// support for alternate installer launchers

// Path + Args + quotes for Path + space between Path and Args
#define DNI_LAUNCHER_CMD_LEN (FILENAME_MAX * 2) + 3

class InstallerLauncher
{
public:
	InstallerLauncher(void);
	~InstallerLauncher(void);

	void SetLauncherPath(const TCHAR* path)
	{
		_tcscpy_s(m_LauncherPath, path);
	}

	void SetLauncherArgs(const TCHAR* args)
	{
		_tcscpy_s(m_LauncherArgs, args);
	}

	TCHAR* GetLauncherCmd()
	{
		// Create the Launcher Command if a Launcher Path is specified
		if(_tcslen(m_LauncherPath) > 0)
		{
			_tcscpy_s(m_LauncherCmd, TEXT("\""));
			_tcscat_s(m_LauncherCmd, DNI_LAUNCHER_CMD_LEN, m_LauncherPath);
			_tcscat_s(m_LauncherCmd, DNI_LAUNCHER_CMD_LEN, TEXT("\""));

			// Append arguments (if specified)
			if(_tcslen(m_LauncherArgs) > 0)
			{
				_tcscat_s(m_LauncherCmd, DNI_LAUNCHER_CMD_LEN, TEXT(" "));
				_tcscat_s(m_LauncherCmd, DNI_LAUNCHER_CMD_LEN, m_LauncherArgs);
			}
		}

		return m_LauncherCmd;
	}

private:
	TCHAR m_LauncherPath[FILENAME_MAX];
	TCHAR m_LauncherArgs[FILENAME_MAX];

	TCHAR m_LauncherCmd[DNI_LAUNCHER_CMD_LEN];
};

extern InstallerLauncher DNILauncher;
