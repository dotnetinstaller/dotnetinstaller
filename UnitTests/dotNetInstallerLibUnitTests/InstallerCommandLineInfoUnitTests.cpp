#include "StdAfx.h"
#include "InstallerCommandLineInfoUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstallerCommandLineInfoUnitTests);

using namespace DVLib::UnitTests;

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
    CPPUNIT_ASSERT_MESSAGE("DisplayConfig", cmdinfo.DisplayConfig());
    CPPUNIT_ASSERT_MESSAGE("ConfigFile", cmdinfo.configFile == L"test.config");
    CPPUNIT_ASSERT_MESSAGE("componentArgs: a1", cmdinfo.componentCmdArgs[L"a1"] == L"a1");
    CPPUNIT_ASSERT_MESSAGE("componentArgs: a2", cmdinfo.componentCmdArgs[L"a2"] == L"a2 a2");
}
