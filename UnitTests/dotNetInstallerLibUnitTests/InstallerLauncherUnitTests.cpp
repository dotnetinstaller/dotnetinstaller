#include "StdAfx.h"
#include "InstallerLauncherUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstallerLauncherUnitTests);

using namespace DVLib::UnitTests;

void InstallerLauncherUnitTests::setUp()
{
	InstallerLauncher::Instance = shared_any<InstallerLauncher *, close_delete>(new InstallerLauncher());
}

void InstallerLauncherUnitTests::tearDown()
{
	reset(InstallerLauncher::Instance);
}

void InstallerLauncherUnitTests::testGetLauncherCmd()
{
	struct TestData
	{
		LPCWSTR path;
		LPCWSTR args;
		LPCWSTR cmd;
	};

	TestData testdata[] = 
	{
		{ L"", L"", L"" },
		{ L"path", L"", L"\"path\"" },
		{ L"", L"args", L"" },
		{ L"path", L"args", L"\"path\" args" },
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		InstallerLauncher::Instance->SetLauncherPath(testdata[i].path);
		InstallerLauncher::Instance->SetLauncherArgs(testdata[i].args);
		std::wstring cmd = InstallerLauncher::Instance->GetLauncherCmd();
		std::wcout << std::endl << i << ": " << cmd;
		CPPUNIT_ASSERT(cmd == testdata[i].cmd);
	}
}
