#include "stdafx.h"
#include "InstallerLauncher.h"

// support alternate installer launchers
shared_any<InstallerLauncher *, close_delete> InstallerLauncher::Instance;

InstallerLauncher::InstallerLauncher()
{

}

std::wstring InstallerLauncher::GetCmd() const
{
    std::wstringstream cmd_s;
    if (! launcherPath.empty())
    {
        cmd_s << L"\"" << launcherPath << L"\"";
    }
    else
    {
        cmd_s << L"\"" << DVLib::GetModuleFileNameW() << L"\"";
    }

    if (__argc > 1)
    {
        cmd_s << L" " << DVLib::trim((::GetCommandLineW() + wcslen(__targv[0]) + 
            (::GetCommandLineW()[0] == '\"' ? 2 : 0)));
    }

    if (! launcherArgs.empty())
    {
        cmd_s << L" " << launcherArgs;
    }

    return cmd_s.str();
}

std::wstring InstallerLauncher::GetCommandLine() const
{
    std::wstringstream cmd_s;

    if (__argc > 1)
    {
        cmd_s << L" " << DVLib::trim((::GetCommandLineW() + wcslen(__targv[0]) + 
            (::GetCommandLineW()[0] == '\"' ? 2 : 0)));
    }

    if (! launcherArgs.empty())
    {
        cmd_s << L" " << launcherArgs;
    }

    return cmd_s.str();
}
