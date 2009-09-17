#include "StdAfx.h"
#include "InstallUILevelUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstallUILevelUnitTests);

using namespace DVLib::UnitTests;

void InstallUILevelUnitTests::testGetCommand()
{
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