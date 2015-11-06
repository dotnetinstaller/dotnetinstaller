#include "StdAfx.h"
#include "InstallUILevelUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstallUILevelUnitTests);

using namespace DVLib::UnitTests;

void InstallUILevelUnitTests::testGetCommand()
{
    InstallUILevelState state;

    struct TestData
    {
        InstallUILevel configLevel;
        InstallUILevel runtimeLevel;
        LPCWSTR full;
        LPCWSTR basic;
        LPCWSTR silent;
        LPCWSTR command;
    };

    TestData testdata[] = 
    {
        { InstallUILevelNotSet, InstallUILevelNotSet, L"full", L"basic", L"silent", L"full" },
        { InstallUILevelFull, InstallUILevelNotSet, L"full", L"basic", L"silent", L"full" },
        { InstallUILevelNotSet, InstallUILevelFull, L"full", L"basic", L"silent", L"full" },
        { InstallUILevelFull, InstallUILevelNotSet, L"full", L"", L"", L"full" },
        { InstallUILevelBasic, InstallUILevelNotSet, L"full", L"", L"", L"full" },
        { InstallUILevelSilent, InstallUILevelNotSet, L"full", L"", L"", L"full" },
        { InstallUILevelFull, InstallUILevelNotSet, L"full", L"", L"", L"full" },
        { InstallUILevelBasic, InstallUILevelNotSet, L"full", L"basic", L"", L"basic" },
        { InstallUILevelSilent, InstallUILevelNotSet, L"full", L"basic", L"", L"basic" },
        { InstallUILevelBasic, InstallUILevelNotSet, L"full", L"", L"silent", L"silent" },
        { InstallUILevelSilent, InstallUILevelNotSet, L"full", L"basic", L"silent", L"silent" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        InstallUILevelSetting::Instance->SetConfigLevel(testdata[i].configLevel);
        InstallUILevelSetting::Instance->SetRuntimeLevel(testdata[i].runtimeLevel);
        std::wstring command = InstallUILevelSetting::Instance->GetCommand(
            testdata[i].full, testdata[i].basic, testdata[i].silent);
        std::wcout << std::endl << i << ": " << command;
        CPPUNIT_ASSERT(command == testdata[i].command);
    }
}

void InstallUILevelUnitTests::testIsAnything()
{
    InstallUILevelState state;

    struct TestData
    {
        InstallUILevel configLevel;
        InstallUILevel runtimeLevel;
        InstallUILevel level;
        bool isAnyUI;
        bool isSilent;
    };

    TestData testdata[] = 
    {
        // not set
        { InstallUILevelNotSet, InstallUILevelNotSet, InstallUILevelFull, true, false },
        { InstallUILevelNotSet, InstallUILevelFull, InstallUILevelFull, true, false },
        { InstallUILevelNotSet, InstallUILevelBasic, InstallUILevelBasic, true, true },
        { InstallUILevelNotSet, InstallUILevelSilent, InstallUILevelSilent, false, true },
        // full, runtime overwrites config
        { InstallUILevelFull, InstallUILevelNotSet, InstallUILevelFull, true, false },
        { InstallUILevelFull, InstallUILevelFull, InstallUILevelFull, true, false },
        { InstallUILevelFull, InstallUILevelBasic, InstallUILevelBasic, true, true },
        { InstallUILevelFull, InstallUILevelSilent, InstallUILevelSilent, false, true },
        // basic
        { InstallUILevelBasic, InstallUILevelNotSet, InstallUILevelBasic, true, true },
        { InstallUILevelBasic, InstallUILevelFull, InstallUILevelFull, true, false },
        { InstallUILevelBasic, InstallUILevelBasic, InstallUILevelBasic, true, true },
        { InstallUILevelBasic, InstallUILevelSilent, InstallUILevelSilent, false, true },
        // basic
        { InstallUILevelSilent, InstallUILevelNotSet, InstallUILevelSilent, false, true },
        { InstallUILevelSilent, InstallUILevelFull, InstallUILevelFull, true, false },
        { InstallUILevelSilent, InstallUILevelBasic, InstallUILevelBasic, true, true },
        { InstallUILevelSilent, InstallUILevelSilent, InstallUILevelSilent, false, true },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        InstallUILevelSetting::Instance->SetConfigLevel(testdata[i].configLevel);
        InstallUILevelSetting::Instance->SetRuntimeLevel(testdata[i].runtimeLevel);
        std::wcout << std::endl << i << ": " << testdata[i].configLevel << L" + " << testdata[i].runtimeLevel;
        CPPUNIT_ASSERT(testdata[i].level == InstallUILevelSetting::Instance->GetUILevel());
        CPPUNIT_ASSERT(testdata[i].isAnyUI == InstallUILevelSetting::Instance->IsAnyUI());
        CPPUNIT_ASSERT(testdata[i].isSilent == InstallUILevelSetting::Instance->IsSilent());
    }
}

void InstallUILevelUnitTests::testToFromString()
{
    struct TestData
    {
        InstallUILevel level;
        std::wstring expected_value;
    };

    TestData testdata[] = 
    {
        // not set
        { InstallUILevelNotSet, L"" },
        { InstallUILevelSilent, L"silent" },
        { InstallUILevelBasic, L"basic" },
        { InstallUILevelFull, L"full" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wstring label = InstallUILevelSetting::ToString(testdata[i].level);
        std::wcout << std::endl << testdata[i].level << L": " << testdata[i].expected_value << L" => " << label;
        CPPUNIT_ASSERT(testdata[i].expected_value == label);
    }
}