#include "stdafx.h"
#include "InstallerLauncher.h"

// support alternate installer launchers
shared_any<InstallerLauncher *, close_delete> InstallerLauncher::Instance;

InstallerLauncher::InstallerLauncher()
{

}

std::wstring InstallerLauncher::GetLauncherCmd() const
{
	std::wstringstream cmd_s;
	if (! launcherPath.empty())
	{
		cmd_s << L"\"" << launcherPath << L"\"";
		if (! launcherArgs.empty())
		{
			cmd_s << L" " << launcherArgs;
		}
	}

	return cmd_s.str();
}


