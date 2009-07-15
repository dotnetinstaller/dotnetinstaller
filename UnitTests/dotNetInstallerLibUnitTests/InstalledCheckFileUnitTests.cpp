#include "StdAfx.h"
#include "InstalledCheckFileUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstalledCheckFileUnitTests);

using namespace DVLib::UnitTests;

void InstalledCheckFileUnitTests::testIsInstalled()
{
	std::wstring userexepath = DVLib::DirectoryCombine(DVLib::GetSystemDirectoryW(), L"user.exe");
	std::wstring version = DVLib::GetFileVersion(userexepath);
	std::wcout << std::endl << L"Checking " << userexepath << L" (" << version << L")";

	struct TestData
	{
		LPCWSTR filename;
		LPCWSTR fileversion; // the version of user.exe is being compared to this version
		LPCWSTR comparison;
		bool expected_isinstalled;
	};

	TestData testdata[] = 
	{
		{ userexepath.c_str(), L"", L"exists", true },
		{ L"C:\\file-doesnt-exist", L"", L"exists", false },
		{ userexepath.c_str(), version.c_str(), L"match", true },
		{ userexepath.c_str(), L"1.0", L"match", false },
		{ userexepath.c_str(), version.c_str(), L"version", true },
		{ userexepath.c_str(), version.c_str(), L"version_gt", false },
		{ userexepath.c_str(), version.c_str(), L"version_lt", false },
		{ userexepath.c_str(), version.c_str(), L"version_eq", true },
		{ userexepath.c_str(), L"1.0", L"version", true },
		{ userexepath.c_str(), L"1.0", L"version_lt", false },
		{ userexepath.c_str(), L"1.0", L"version_gt", true },
		{ userexepath.c_str(), L"1.0", L"version_eq", false },
		{ userexepath.c_str(), L"999.0.0.0", L"version", false },
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		InstalledCheckFile check;
		check.filename = testdata[i].filename;
		check.fileversion = testdata[i].fileversion;
		check.comparison = testdata[i].comparison;
		bool isinstalled = check.IsInstalled();
		std::wcout << std::endl 
			<< check.filename << L" (" << check.fileversion << L") - " << check.comparison
			<< L": " << (isinstalled ? L"yes" : L"no");
		CPPUNIT_ASSERT(isinstalled == testdata[i].expected_isinstalled);
	}
}