#include "StdAfx.h"
#include "InstalledCheckRegistryUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstalledCheckRegistryUnitTests);

using namespace DVLib::UnitTests;

void InstalledCheckRegistryUnitTests::setUp()
{
	DVLib::RegistryCreateKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
	DVLib::RegistrySetDWORDValue(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib", L"DWORD", 1);
	DVLib::RegistrySetStringValue(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib", L"String", L"1.2.3.4");
	std::vector<std::wstring> data;
	data.push_back(L"abc");
	data.push_back(L"defg");
	DVLib::RegistrySetMultiStringValue(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib", L"MultiString", data);
}

void InstalledCheckRegistryUnitTests::tearDown()
{
	DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
}

void InstalledCheckRegistryUnitTests::testIsInstalled()
{
	struct TestData
	{
		LPCWSTR rootkey;
		LPCWSTR path;
		LPCWSTR fieldname;
		LPCWSTR fieldtype;
		LPCWSTR fieldvalue;
		LPCWSTR comparison;
		bool expected_isinstalled;
	};

	TestData testdata[] = 
	{
		// DWORD
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"1", L"match", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"match", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"exists", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD-doesntexist", L"REG_DWORD", L"2", L"exists", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib-doesntexist", L"DWORD", L"REG_DWORD", L"", L"exists", false },
		{ L"HKEY_LOCAL_MACHINE", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"1", L"match", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"1", L"version", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"0", L"version", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"version", false },
		// string
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.4", L"match", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"Hello world", L"match", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"bla bla", L"exists", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String-doesntexist", L"REG_SZ", L"1.2.3.4", L"exists", false },
		{ L"HKEY_LOCAL_MACHINE", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.4", L"match", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.4", L"version", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.0", L"version", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.5", L"version", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.3", L"version", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.4", L"contains", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"2.3", L"contains", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"3.2", L"contains", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"", L"contains", true },
		// multi-string
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"", L"match", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"", L"exists", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"", L"contains", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"abc,defg", L"match", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"defg,abc", L"match", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"abc, defg", L"match", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"abc", L"contains", true },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"abc,def", L"contains", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"def", L"contains", false },
		{ L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"defg", L"contains", true },
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		InstalledCheckRegistry check;
		check.rootkey = testdata[i].rootkey;
		check.path = testdata[i].path;
		check.fieldname = testdata[i].fieldname;
		check.fieldtype = testdata[i].fieldtype;
		check.fieldvalue = testdata[i].fieldvalue;
		check.comparison = testdata[i].comparison;
		bool isinstalled = check.IsInstalled();
		std::wcout << std::endl 
			<< check.rootkey << L"\\" << check.path << L"\\" << check.fieldname << L"\\" << check.fieldvalue 
			<< L" (" << check.fieldtype << L") - " << check.comparison
			<< L": " << (isinstalled ? L"yes" : L"no");
		CPPUNIT_ASSERT(isinstalled == testdata[i].expected_isinstalled);
	}
}
