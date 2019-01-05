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

    int argCount;
    LPWSTR *szArgList = CommandLineToArgvW(::GetCommandLineW(), &argCount);
    if (szArgList != NULL)
    {
        if (argCount > 1)
        {
            cmd_s << L" " << DVLib::trim( ( ::GetCommandLineW() + wcslen(szArgList[0]) +
                ( ::GetCommandLineW()[0] == '\"' ? 2 : 0 ) ) );
        }
    }

    LocalFree(szArgList);

    if (! launcherArgs.empty())
    {
        cmd_s << L" " << launcherArgs;
    }

    return cmd_s.str();
}

std::wstring InstallerLauncher::GetCommandLine() const
{
    std::wstringstream cmd_s;

    int argCount;
    LPWSTR *szArgList = CommandLineToArgvW(::GetCommandLineW(), &argCount);
    if (szArgList != NULL)
    {
        if (argCount > 1)
        {
            cmd_s << L" " << DVLib::trim( ( ::GetCommandLineW() + wcslen(szArgList[0]) +
                ( ::GetCommandLineW()[0] == '\"' ? 2 : 0 ) ) );
        }
    }

    LocalFree(szArgList);

    if (! launcherArgs.empty())
    {
        cmd_s << L" " << launcherArgs;
    }

    return cmd_s.str();
}
