#include "StdAfx.h"
#include "InstallerCommandLineInfoUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void InstallerCommandLineInfoUnitTests::ParseCommandLineInfo(int argc, wchar_t ** argv, CCommandLineInfo& rCmdInfo)
{
    for (int i = 1; i < argc; i++)
    {
        LPCTSTR pszParam = argv[i];
        BOOL bFlag = FALSE;
        BOOL bLast = ((i + 1) == argc);
        if (pszParam[0] == '-' || pszParam[0] == '/')
        {
            // remove flag specifier
            bFlag = TRUE;
            ++pszParam;
        }

        rCmdInfo.ParseParam(pszParam, bFlag, bLast);
    }
}

void InstallerCommandLineInfoUnitTests::testGetCmd()
{
    wchar_t * cmd[] = 
    {
        L"setup.exe",
        L"/DisplayConfig",
        L"/configFile", L"test.config",
        L"/componentArgs", L"a1:a1",
        L"/componentArgs", L"a2:a2 a2",
    };

    InstallerCommandLineInfo cmdinfo;
    ParseCommandLineInfo(ARRAYSIZE(cmd), cmd, cmdinfo);
    Assert::IsTrue(cmdinfo.DisplayConfig(), L"DisplayConfig");
    Assert::IsTrue(cmdinfo.configFile == L"test.config", L"ConfigFile");
    Assert::IsTrue(cmdinfo.componentCmdArgs[L"a1"] == L"a1", L"componentArgs: a1");
    Assert::IsTrue(cmdinfo.componentCmdArgs[L"a2"] == L"a2 a2", L"componentArgs: a2");
}
