#include "StdAfx.h"
#include "InstalledCheckFileUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
        bool defaultvalue;
        bool expected_isinstalled;
    };

    TestData testdata[] = 
    {
        { userexepath.c_str(), L"", L"exists", false, true },
        { L"C:\\file-doesnt-exist", L"", L"exists", false, false },
        { L"C:\\file-doesnt-exist", L"", L"exists", true, false },
        { L"C:\\file-doesnt-exist", L"", L"match", true, true },
        { L"C:\\file-doesnt-exist", L"", L"version", true, true },
        { userexepath.c_str(), version.c_str(), L"match", false, true },
        { userexepath.c_str(), L"1.0", L"match", false, false },
        { userexepath.c_str(), version.c_str(), L"version", false, true },
        { userexepath.c_str(), version.c_str(), L"version_gt", false, false },
        { userexepath.c_str(), version.c_str(), L"version_lt", false, false },
        { userexepath.c_str(), version.c_str(), L"version_eq", false, true },
        { userexepath.c_str(), version.c_str(), L"version_le", false, true },
        { userexepath.c_str(), version.c_str(), L"version_ge", false, true },
        { userexepath.c_str(), L"1.0", L"version", false, true },
        { userexepath.c_str(), L"1.0", L"version_lt", false, false },
        { userexepath.c_str(), L"1.0", L"version_le", false, false },
        { userexepath.c_str(), L"1.0", L"version_gt", false, true },
        { userexepath.c_str(), L"1.0", L"version_ge", false, true },
        { userexepath.c_str(), L"1.0", L"version_eq", false, false },
        { userexepath.c_str(), L"999.0.0.0", L"version", false, false },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        InstalledCheckFile check;
        check.filename = testdata[i].filename;
        check.fileversion = testdata[i].fileversion;
        check.comparison = testdata[i].comparison;
        check.defaultvalue = testdata[i].defaultvalue ? L"True" : L"False";
        bool isinstalled = check.IsInstalled();
        std::wcout << std::endl 
            << check.filename << L" (" << check.fileversion << L") - " << check.comparison
            << L": " << (isinstalled ? L"yes" : L"no");
        Assert::IsTrue(isinstalled == testdata[i].expected_isinstalled);
    }
}