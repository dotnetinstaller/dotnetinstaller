#include "StdAfx.h"
#include "InstalledCheckFileUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void InstalledCheckFileUnitTests::testIsInstalled()
{
    // user.exe exists in C:\Windows\SysWOW64 but not C:\Windows\system32 
    std::wstring userExePath = DVLib::DirectoryCombine(DVLib::GetSystemDirectoryW(), L"user.exe");

    TestData userExeTestData[] = 
    {
        { userExePath.c_str(), L"", L"exists", false, false, true },
        { userExePath.c_str(), L"", L"exists", false, true, false }
    };

    for (int i = 0; i < ARRAYSIZE(userExeTestData); i++)
    {
        testIsInstalled(userExeTestData[i], userExeTestData[i].disableWow64FsRedirection);
    }

    // attrib.exe exists in both C:\Windows\system32 and C:\Windows\SysWOW64
    std::wstring attribExePath = DVLib::DirectoryCombine(DVLib::GetSystemDirectoryW(), L"attrib.exe");
    std::wstring version = DVLib::GetFileVersion(attribExePath);
    std::wcout << std::endl << L"Checking " << attribExePath << L" (" << version << L")";
    TestData testdata[] =
    {
        { attribExePath.c_str(), L"", L"exists", false, true },
        { L"C:\\file-doesnt-exist", L"", L"exists", false, false },
        { L"C:\\file-doesnt-exist", L"", L"exists", true, false },
        { L"C:\\file-doesnt-exist", L"", L"match", true, true },
        { L"C:\\file-doesnt-exist", L"", L"version", true, true },
        { attribExePath.c_str(), version.c_str(), L"match", false, true },
        { attribExePath.c_str(), L"1.0", L"match", false, false },
        { attribExePath.c_str(), version.c_str(), L"version", false, true },
        { attribExePath.c_str(), version.c_str(), L"version_gt", false, false },
        { attribExePath.c_str(), version.c_str(), L"version_lt", false, false },
        { attribExePath.c_str(), version.c_str(), L"version_eq", false, true },
        { attribExePath.c_str(), version.c_str(), L"version_le", false, true },
        { attribExePath.c_str(), version.c_str(), L"version_ge", false, true },
        { attribExePath.c_str(), L"1.0", L"version", false, true },
        { attribExePath.c_str(), L"1.0", L"version_lt", false, false },
        { attribExePath.c_str(), L"1.0", L"version_le", false, false },
        { attribExePath.c_str(), L"1.0", L"version_gt", false, true },
        { attribExePath.c_str(), L"1.0", L"version_ge", false, true },
        { attribExePath.c_str(), L"1.0", L"version_eq", false, false },
        { attribExePath.c_str(), L"999.0.0.0", L"version", false, false }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        testIsInstalled(testdata[i], false);
        testIsInstalled(testdata[i], true);
    }
}

void InstalledCheckFileUnitTests::testIsInstalled(TestData testdata, bool disableWow64FsRedirection)
{
    InstalledCheckFile check;
    check.filename = testdata.filename;
    check.fileversion = testdata.fileversion;
    check.comparison = testdata.comparison;
    check.defaultvalue = testdata.defaultvalue ? L"True" : L"False";
    check.disableWow64FsRedirection = testdata.disableWow64FsRedirection;
    bool isinstalled = check.IsInstalled();
    std::wcout << std::endl
        << check.filename << L" (" << check.fileversion << L") - " << check.comparison
        << L": " << (isinstalled ? L"yes" : L"no");
    Assert::IsTrue(isinstalled == testdata.expected_isinstalled);
}