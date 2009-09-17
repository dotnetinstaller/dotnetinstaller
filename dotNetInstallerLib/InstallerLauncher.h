#pragma once

// support for alternate installer launchers

class InstallerLauncher
{
public:
	static shared_any<InstallerLauncher *, close_delete> Instance;
	InstallerLauncher();
	void SetLauncherPath(const std::wstring& path) { launcherPath = path; }
	void SetLauncherArgs(const std::wstring args) { launcherArgs = args; }
	std::wstring GetLauncherCmd() const;
private:
	std::wstring launcherPath;
	std::wstring launcherArgs;
};
