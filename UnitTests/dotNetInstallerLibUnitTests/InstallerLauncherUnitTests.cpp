#include "StdAfx.h"
#include "InstallerLauncherUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstallerLauncherUnitTests);

using namespace DVLib::UnitTests;

void InstallerLauncherUnitTests::testGetCmd()
{
	struct TestData
	{
		LPCWSTR path;
		LPCWSTR args;
		std::wstring cmd;
	};

	std::wstring module = L"\"" + DVLib::GetModuleFileNameW() + L"\"";
	std::wstring args = DVLib::trim((::GetCommandLineW() + wcslen(__targv[0]) + 
			(::GetCommandLineW()[0] == '\"' ? 2 : 0)));
	if (! args.empty()) args = L" " + args;

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
		CPPUNIT_ASSERT(cmd == testdata[i].cmd);
	}
}
