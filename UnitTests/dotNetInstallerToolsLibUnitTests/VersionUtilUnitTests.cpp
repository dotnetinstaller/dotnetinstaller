#include "stdafx.h"
#include "VersionUtilUnitTests.h"
#include "dotNetInstallerToolsLib/Logger.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void VersionUtilUnitTests::testwstring2version()
{
    struct TestData
    {
        LPCWSTR version_s;
        DVLib::Version version;
    };

    TestData testdata[] =
    {
        { L"", { 0, 0, 0, 0 } },
        { L"1", { 1, 0, 0, 0 } },
        { L"0.1", { 0, 1, 0, 0 } },
        { L"0.1.0", { 0, 1, 0, 0 } },
        { L"0.1.2.3", { 0, 1, 2, 3 } },
        { L"1.2.3.4", { 1, 2, 3, 4 } },
        { L"19.456.12345.5", { 19, 456, 12345, 5 } },
        { L"v1", { 1, 0, 0, 0 } },
        { L"v0.1", { 0, 1, 0, 0 } },
        { L"v0.1.0", { 0, 1, 0, 0 } },
        { L"v0.1.2.3", { 0, 1, 2, 3 } },
        { L"v1.2.3.4", { 1, 2, 3, 4 } },
        { L"v19.456.12345.5", { 19, 456, 12345, 5 } },
        { L"V1", { 1, 0, 0, 0 } },
        { L"V0.1", { 0, 1, 0, 0 } },
        { L"V0.1.0", { 0, 1, 0, 0 } },
        { L"V0.1.2.3", { 0, 1, 2, 3 } },
        { L"V1.2.3.4", { 1, 2, 3, 4 } },
        { L"V19.456.12345.5", { 19, 456, 12345, 5 } }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        DVLib::Version version = DVLib::wstring2version(testdata[i].version_s);
        std::wcout << std::endl << testdata[i].version_s << L" => "
            << version.major << L"." << version.minor << L"."
            << version.build << L"." << version.rev;
        Assert::IsTrue(version.major == testdata[i].version.major);
        Assert::IsTrue(version.minor == testdata[i].version.minor);
        Assert::IsTrue(version.build == testdata[i].version.build);
        Assert::IsTrue(version.rev == testdata[i].version.rev);
    }
}

void VersionUtilUnitTests::testversion2wstring()
{
    Version zero = { 0, 0, 0, 0 };
    Assert::IsTrue(DVLib::version2wstring(zero) == L"0.0.0.0");
    Version notzero = { 12, 345, 6789, 100 };
    Assert::IsTrue(DVLib::version2wstring(notzero) == L"12.345.6789.100");
}

void VersionUtilUnitTests::testCompareVersion()
{
    struct TestData
    {
        LPCWSTR l;
        LPCWSTR r;
        int cmp;
    };

    TestData testdata[] =
    {
        { L"", L"", 0 },
        { L"1", L"", 1 },
        { L"", L"1", -1 },
        { L"1.0", L"0.9", 1 },
        { L"0.1", L"0.9", -1 },
        { L"1.1", L"1.0", 1 },
        { L"1.1", L"1.1", 0 },
        { L"1.0", L"1.1", -1 },
        { L"1.0.0", L"1", 0 },
        { L"1.0.0.0", L"1", 0 },
        { L"1.0.0.0", L"1.0.0.1", -1 },

        { L"v1", L"", 1 },
        { L"", L"v1", -1 },
        { L"v1.0", L"0.9", 1 },
        { L"0.1", L"v0.9", -1 },
        { L"1.1", L"v1.0", 1 },
        { L"1.1", L"V1.1", 0 },
        { L"1.0", L"V1.1", -1 },
        { L"V1.0.0", L"1", 0 },
        { L"v1.0.0.0", L"V1", 0 },
        { L"V1.0.0.0", L"v1.0.0.1", -1 },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        int cmp = DVLib::CompareVersion(testdata[i].l, testdata[i].r);
        std::wcout << std::endl << testdata[i].l << L" vs. " << testdata[i].r << L" => " << cmp;
        Assert::IsTrue(cmp == testdata[i].cmp);
    }
}

void VersionUtilUnitTests::testCompareSemanticVersion()
{
    struct TestData
    {
        LPCWSTR l;
        LPCWSTR r;
        int cmp;
    };

    TestData testdata[] =
    {
        // normal precedence
        { L"1.2.3", L"1.2.3", 0 },
        { L"0.0.2", L"0.0.1", 1 },
        { L"0.2.0", L"0.0.3", 1 },
        { L"0.2.0", L"0.1.3", 1 },
        { L"2.0.0", L"0.0.1", 1 },
        { L"2.0.0", L"0.3.1", 1 },
        { L"2.0.0", L"1.3.1", 1 },

        // normal and pre-release precedence
        { L"1.0.0", L"1.0.0-alpha", 1 },
        { L"1.0.0", L"1.0.0-99", 1 },
        { L"1.0.0", L"1.0.0-ZZ", 1 },
        
        // same pre-release
        { L"1.0.0-alpha", L"1.0.0-alpha", 0 },
        { L"1.0.0-alpha.1", L"1.0.0-alpha.1", 0 },
        { L"1.0.0-1", L"1.0.0-1", 0 },

        // pre-release precedence with numeric id
        { L"1.0.0-1", L"1.0.0-0", 1 },
        { L"1.0.0-10", L"1.0.0-1", 1 },
        { L"1.0.0-alpha.3", L"1.0.0-alpha.1", 1 },

        // prerels precedence with alphanum id
        { L"1.0.0-1", L"1.0.0-0", 1 },
        { L"1.0.0-Z", L"1.0.0-A", 1 },
        { L"1.0.0-Z", L"1.0.0-1", 1 },
        { L"1.0.0-alpha-3", L"1.0.0-alpha-1", 1 },
        { L"1.0.0-alpha-3", L"1.0.0-alpha-100", 1 },

        // prerels precedence misc
        { L"1.0.0-alpha", L"1.0.0-alpha.1", -1 },
        { L"1.0.0-alpha.1", L"1.0.0-alpha.beta", -1 },
        { L"1.0.0-alpha.beta", L"1.0.0-beta", -1 },
        { L"1.0.0-beta", L"1.0.0-beta.2", -1 },
        { L"1.0.0-beta.2", L"1.0.0-beta.11", -1 },
        { L"1.0.0-beta.11", L"1.0.0-rc.1", -1 },
        { L"1.0.0-rc.1", L"1.0.0", -1 },

        // equal precedence based on build
        { L"1.0.0", L"1.0.0+build.1.2.3", 0 },
        { L"1.0.0+ZZZ", L"1.0.0+build.1.2.3", 0 },
        { L"1.0.0+100", L"1.0.0+200", 0 },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        int cmp = DVLib::CompareSemanticVersion(testdata[i].l, testdata[i].r);
        std::wcout << std::endl << testdata[i].l << L" vs. " << testdata[i].r << L" => " << cmp;
        Assert::IsTrue(cmp == testdata[i].cmp);
    }
}

void VersionUtilUnitTests::testCompareSemanticVersion_invalid()
{
    try
    {
        DVLib::CompareSemanticVersion(L"unknown", L"invalid");

        Assert::Fail(L"Expected exception.");
    }
    catch (std::exception& ex)
    {
        Assert::AreEqual("invalid character encountered: u", ex.what());
    }
}

void VersionUtilUnitTests::testCompareVersion_unknown()
{
    std::list<std::wstring> valuesToCompare;
    std::wstring checkValue;

    try
    {
        DVLib::CompareVersion(L"unknown", valuesToCompare, checkValue);

        Assert::Fail(L"Expected exception.");
    }
    catch (std::exception& ex)
    {
        Assert::AreEqual("Invalid comparison: unknown", ex.what());
    }
}

void VersionUtilUnitTests::testCompareVersion_version_and_version_ge()
{
    struct TestData
    {
        std::list<std::wstring> l;
        std::wstring r;
        bool expected;
    };

    TestData testdata[] =
    {
        { {}, {}, false },
        { {L""}, L"", true },
        { {L"1"}, L"", true },
        { {L""}, L"1", false },
        { {L"1.0"}, L"0.1", true },
        { {L"0.1"}, L"1.0", false },
        { {L"1.0"}, L"1.0", true },
        { {L"1.0", L"2.0"}, L"0.1", true },
        { {L"0.1", L"0.2"}, L"1.0", false },
        { {L"1.0", L"0.1"}, L"1.0", true },
        { {L"0.1", L"1.0"}, L"1.0", true },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        bool result = DVLib::CompareVersion(L"version", testdata[i].l, testdata[i].r);
        bool result2 = DVLib::CompareVersion(L"version_ge", testdata[i].l, testdata[i].r);
        Assert::AreEqual(result2, result);
        std::wstring index = std::to_wstring(i);
        Assert::AreEqual(testdata[i].expected, result, index.c_str());
    }
}

void VersionUtilUnitTests::testCompareVersion_version_eq()
{
    struct TestData
    {
        std::list<std::wstring> l;
        std::wstring r;
        bool expected;
    };

    TestData testdata[] =
    {
        { {}, {}, false },
        { {L""}, L"", true },
        { {L"1"}, L"", false },
        { {L""}, L"1", false },
        { {L"1.0"}, L"0.1", false },
        { {L"0.1"}, L"1.0", false },
        { {L"1.0"}, L"1.0", true },
        { {L"1.0", L"2.0"}, L"0.1", false },
        { {L"1.0", L"0.1"}, L"1.0", true },
        { {L"0.1", L"1.0"}, L"1.0", true },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        bool result = DVLib::CompareVersion(L"version_eq", testdata[i].l, testdata[i].r);
        std::wstring index = std::to_wstring(i);
        Assert::AreEqual(testdata[i].expected, result, index.c_str());
    }
}

void VersionUtilUnitTests::testCompareVersion_version_lt()
{
    struct TestData
    {
        std::list<std::wstring> l;
        std::wstring r;
        bool expected;
    };

    TestData testdata[] =
    {
        { {}, {}, false },
        { {L""}, L"", false },
        { {L"1"}, L"", false },
        { {L""}, L"1", true },
        { {L"1.0"}, L"0.1", false },
        { {L"0.1"}, L"1.0", true },
        { {L"1.0"}, L"1.0", false },
        { {L"1.0", L"2.0"}, L"0.1", false },
        { {L"0.1", L"0.2"}, L"1.0", true },
        { {L"1.0", L"0.1"}, L"1.0", true },
        { {L"0.1", L"1.0"}, L"1.0", true },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        bool result = DVLib::CompareVersion(L"version_lt", testdata[i].l, testdata[i].r);
        std::wstring index = std::to_wstring(i);
        Assert::AreEqual(testdata[i].expected, result, index.c_str());
    }
}

void VersionUtilUnitTests::testCompareVersion_version_le()
{
    struct TestData
    {
        std::list<std::wstring> l;
        std::wstring r;
        bool expected;
    };

    TestData testdata[] =
    {
        { {}, {}, false },
        { {L""}, L"", true },
        { {L"1"}, L"", false },
        { {L""}, L"1", true },
        { {L"1.0"}, L"0.1", false },
        { {L"0.1"}, L"1.0", true },
        { {L"1.0"}, L"1.0", true },
        { {L"1.0", L"2.0"}, L"0.1", false },
        { {L"0.1", L"0.2"}, L"1.0", true },
        { {L"1.0", L"0.1"}, L"1.0", true },
        { {L"0.1", L"1.0"}, L"1.0", true },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        bool result = DVLib::CompareVersion(L"version_le", testdata[i].l, testdata[i].r);
        std::wstring index = std::to_wstring(i);
        Assert::AreEqual(testdata[i].expected, result, index.c_str());
    }
}

void VersionUtilUnitTests::testCompareVersion_version_gt()
{
    struct TestData
    {
        std::list<std::wstring> l;
        std::wstring r;
        bool expected;
    };

    TestData testdata[] =
    {
        { {}, {}, false },
        { {L""}, L"", false },
        { {L"1"}, L"", true },
        { {L""}, L"1", false },
        { {L"1.0"}, L"0.1", true },
        { {L"0.1"}, L"1.0", false },
        { {L"1.0"}, L"1.0", false },
        { {L"1.0", L"2.0"}, L"0.1", true },
        { {L"0.1", L"0.2"}, L"1.0", false },
        { {L"1.0", L"0.1"}, L"1.0", false },
        { {L"0.1", L"1.0"}, L"1.0", false },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        bool result = DVLib::CompareVersion(L"version_gt", testdata[i].l, testdata[i].r);
        std::wstring index = std::to_wstring(i);
        Assert::AreEqual(testdata[i].expected, result, index.c_str());
    }
}