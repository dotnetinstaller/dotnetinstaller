#include "StdAfx.h"
#include "InstalledCheckRegistryUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void InstalledCheckRegistryUnitTests::setUp()
{
    dotNetInstallerLibUnitTestFixture::setUp();
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
    DVLib::RegistrySetDWORDValue(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib", L"DWORD", 1);
    DVLib::RegistrySetStringValue(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib", L"String", L"1.2.3.4");
    DVLib::RegistryCreateKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib\\SubWithDefaultValue");
    DVLib::RegistrySetStringValue(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib\\SubWithDefaultValue", L"", L"default value");
    std::vector<std::wstring> data;
    data.push_back(L"abc");
    data.push_back(L"defg");
    DVLib::RegistrySetMultiStringValue(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib", L"MultiString", data);
}

void InstalledCheckRegistryUnitTests::tearDown()
{
    DVLib::RegistryDeleteKey(HKEY_CURRENT_USER, L"SOFTWARE\\DVLib");
    dotNetInstallerLibUnitTestFixture::tearDown();
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
        bool defaultvalue;
        bool expected_isinstalled;
    };

    TestData testdata[] = 
    {
        // DWORD
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"1", L"match", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"match", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"exists", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"key_exists", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"value_exists", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"", L"", L"", L"value_exists", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib\\SubWithDefaultValue", L"", L"", L"", L"value_exists", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD-doesntexist", L"REG_DWORD", L"2", L"value_exists", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD-doesntexist", L"REG_DWORD", L"2", L"exists", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib-doesntexist", L"DWORD", L"REG_DWORD", L"", L"exists", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib-doesntexist", L"", L"REG_SZ", L"", L"exists", false, false },
        { L"HKEY_LOCAL_MACHINE", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"1", L"match", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"1", L"version", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"0", L"version", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"version", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"1", L"version_eq", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"1", L"version_gt", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"1", L"version_ge", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"1", L"version_lt", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"1", L"version_le", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"version_eq", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"version_gt", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"version_ge", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"version_lt", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"DWORD", L"REG_DWORD", L"2", L"version_le", false, true },
        // string
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.4", L"match", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"Hello world", L"match", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"bla bla", L"exists", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String-doesntexist", L"REG_SZ", L"1.2.3.4", L"exists", false, false },
        { L"HKEY_LOCAL_MACHINE", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.4", L"match", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.4", L"version", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.0", L"version", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.5", L"version", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.3", L"version", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.4", L"version_eq", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.5", L"version_eq", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.4", L"version_lt", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.0", L"version_lt", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.4", L"version_le", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.0", L"version_le", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.0", L"version_gt", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.5", L"version_gt", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.0", L"version_ge", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.5", L"version_ge", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"1.2.3.4", L"contains", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"2.3", L"contains", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"3.2", L"contains", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"String", L"REG_SZ", L"", L"contains", false, true },
        // multi-string
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"", L"match", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"", L"exists", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"", L"contains", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"abc,defg", L"match", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"defg,abc", L"match", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"abc, defg", L"match", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"abc", L"contains", false, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"abc,def", L"contains", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"def", L"contains", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLib", L"MultiString", L"REG_MULTI_SZ", L"defg", L"contains", false, true },
        // default value
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLibDoesntExist", L"String", L"REG_SZ", L"2.3", L"contains", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLibDoesntExist", L"String", L"REG_SZ", L"2.3", L"contains", true, true },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLibDoesntExist", L"String", L"REG_SZ", L"2.3", L"version", false, false },
        { L"HKEY_CURRENT_USER", L"SOFTWARE\\DVLibDoesntExist", L"String", L"REG_SZ", L"2.3", L"version", true, true },
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
        check.defaultvalue = testdata[i].defaultvalue ? L"True" : L"False";
        bool isinstalled = check.IsInstalled();
        std::wcout << std::endl 
            << check.rootkey << L"\\" << check.path << L"\\" << check.fieldname << L"\\" << check.fieldvalue 
            << L" (" << check.fieldtype << L") - " << check.comparison
            << L": " << (isinstalled ? L"yes" : L"no");
        Assert::IsTrue(isinstalled == testdata[i].expected_isinstalled);
    }
}
