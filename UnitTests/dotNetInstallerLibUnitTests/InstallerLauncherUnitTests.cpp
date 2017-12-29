#include "StdAfx.h"
#include "InstallerLauncherUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void InstallerLauncherUnitTests::testGetCmd()
{
    struct TestData
    {
        LPCWSTR path;
        LPCWSTR args;
        std::wstring cmd;
    };

    std::wstring module = L"\"" + DVLib::GetModuleFileNameW() + L"\"";
    std::wstring args = InstallerLauncher::Instance->GetCommandLine();

    TestData testdata[] = 
    {
        { L"", L"", module + args },
        { L"path", L"", L"\"path\"" + args },
        { L"", L"args", module + args + L" args" },
        { L"path", L"args", L"\"path\"" + args + L" args" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        InstallerLauncher::Instance->SetLauncherPath(testdata[i].path);
        InstallerLauncher::Instance->SetLauncherArgs(testdata[i].args);
        std::wstring cmd = InstallerLauncher::Instance->GetCmd();
        std::wcout << std::endl << i << ": " << cmd;
        Assert::IsTrue(cmd == testdata[i].cmd);
    }
}
