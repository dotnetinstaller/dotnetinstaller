#include "StdAfx.h"
#include "InstalledCheckDirectoryUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void InstalledCheckDirectoryUnitTests::testIsInstalled()
{
    std::wcout << std::endl << L"Checking " << DVLib::GetSystemDirectoryW();
    InstalledCheckDirectory check;
    check.comparison = L"exists";
    check.path = DVLib::GetSystemDirectoryW();
    Assert::IsTrue(check.IsInstalled());
    check.path = DVLib::GenerateGUIDStringW();
    Assert::IsTrue(! check.IsInstalled());
}

void InstalledCheckDirectoryUnitTests::testIsInstalled_version_with_non_existent_directory()
{
    std::wstring tempDir = DVLib::GetTemporaryDirectoryW() + L"\\" + DVLib::GenerateGUIDStringW();

    InstalledCheckDirectory check;
    check.path = tempDir;

    TestData testdata[] =
    {
        // directoryNames, comparison, version, expected
        { {}, L"version", L"", false },
        { {}, L"version", L"1", false },
        { {}, L"version_eq", L"", false },
        { {}, L"version_eq", L"1", false },
        { {}, L"version_lt", L"", false },
        { {}, L"version_lt", L"1", false },
        { {}, L"version_le", L"", false },
        { {}, L"version_le", L"1", false },
        { {}, L"version_gt", L"", false },
        { {}, L"version_gt", L"1", false },
        { {}, L"version_ge", L"", false },
        { {}, L"version_ge", L"1", false },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        check.comparison = testdata[i].comparison;
        check.version = testdata[i].version;
        Assert::AreEqual(testdata[i].expected, check.IsInstalled());
    }
}

void InstalledCheckDirectoryUnitTests::testIsInstalled_version()
{
    std::wstring tempDir = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), DVLib::GenerateGUIDStringW());
    DVLib::DirectoryCreate(tempDir);

    InstalledCheckDirectory check;
    check.path = tempDir;

    TestData testdata[] =
    {
        // directoryNames, comparison, version, expected
        { {}, L"version", L"", false},
        { {}, L"version", L"1", false },
        { {L"1.0"}, L"version", L"0.1", true },
        { {L"0.1"}, L"version", L"1.0", false },
        { {L"1.0"}, L"version", L"1.0", true },
        { {L"1.0", L"2.0"}, L"version", L"0.1", true },
        { {L"0.1", L"0.2"}, L"version", L"1.0", false },
        { {L"1.0", L"0.1"}, L"version", L"1.0", true },
        { {L"0.1", L"1.0"}, L"version", L"1.0", true },

        { {}, L"version_eq", L"", false },
        { {}, L"version_eq", L"1", false },
        { {L"1.0"}, L"version_eq", L"0.1", false },
        { {L"0.1"}, L"version_eq", L"1.0", false },
        { {L"1.0"}, L"version_eq", L"1.0", true },
        { {L"1.0", L"2.0"}, L"version_eq", L"0.1", false },
        { {L"1.0", L"0.1"}, L"version_eq", L"1.0", true },
        { {L"0.1", L"1.0"}, L"version_eq", L"1.0", true },
        
        { {}, L"version_lt", L"", false },
        { {}, L"version_lt", L"1", false },
        { {L"1.0"}, L"version_lt", L"0.1", false },
        { {L"0.1"}, L"version_lt", L"1.0", true },
        { {L"1.0"}, L"version_lt", L"1.0", false },
        { {L"1.0", L"2.0"}, L"version_lt", L"0.1", false },
        { {L"0.1", L"0.2"}, L"version_lt", L"1.0", true },
        { {L"1.0", L"0.1"}, L"version_lt", L"1.0", true },
        { {L"0.1", L"1.0"}, L"version_lt", L"1.0", true },
        
        { {}, L"version_le", L"", false },
        { {}, L"version_le", L"1", false },
        { {L"1.0"}, L"version_le", L"0.1", false },
        { {L"0.1"}, L"version_le", L"1.0", true },
        { {L"1.0"}, L"version_le", L"1.0", true },
        { {L"1.0", L"2.0"}, L"version_le", L"0.1", false },
        { {L"0.1", L"0.2"}, L"version_le", L"1.0", true },
        { {L"1.0", L"0.1"}, L"version_le", L"1.0", true },
        { {L"0.1", L"1.0"}, L"version_le", L"1.0", true },
        
        { {}, L"version_gt", L"", false },
        { {}, L"version_gt", L"1", false },
        { {L"1.0"}, L"version_gt", L"0.1", true },
        { {L"0.1"}, L"version_gt", L"1.0", false },
        { {L"1.0"}, L"version_gt", L"1.0", false },
        { {L"1.0", L"2.0"}, L"version_gt", L"0.1", true },
        { {L"0.1", L"0.2"}, L"version_gt", L"1.0", false },
        { {L"1.0", L"0.1"}, L"version_gt", L"1.0", false },
        { {L"0.1", L"1.0"}, L"version_gt", L"1.0", false },

        { {}, L"version_ge", L"", false},
        { {}, L"version_ge", L"1", false },
        { {L"1.0"}, L"version_ge", L"0.1", true },
        { {L"0.1"}, L"version_ge", L"1.0", false },
        { {L"1.0"}, L"version_ge", L"1.0", true },
        { {L"1.0", L"2.0"}, L"version_ge", L"0.1", true },
        { {L"0.1", L"0.2"}, L"version_ge", L"1.0", false },
        { {L"1.0", L"0.1"}, L"version_ge", L"1.0", true },
        { {L"0.1", L"1.0"}, L"version_ge", L"1.0", true },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        for each (const std::wstring & directoryName in testdata[i].directoryNames)
        {
            std::wstring subDirectory = DVLib::DirectoryCombine(tempDir, directoryName);
            DVLib::DirectoryCreate(subDirectory);
        }

        check.comparison = testdata[i].comparison;
        check.version = testdata[i].version;
        Assert::AreEqual(testdata[i].expected, check.IsInstalled());

        for each (const std::wstring & directoryName in testdata[i].directoryNames)
        {
            std::wstring subDirectory = DVLib::DirectoryCombine(tempDir, directoryName);
            DVLib::DirectoryDelete(subDirectory, DELETE_DIRECTORY_FLAGS::DELETE_DIRECTORY_EMPTY);
        }
    }

    DVLib::DirectoryDelete(tempDir, DELETE_DIRECTORY_FLAGS::DELETE_DIRECTORY_EMPTY);
}

void InstalledCheckDirectoryUnitTests::testIsInstalled_semver_with_non_existent_directory()
{
    std::wstring tempDir = DVLib::GetTemporaryDirectoryW() + L"\\" + DVLib::GenerateGUIDStringW();

    InstalledCheckDirectory check;
    check.path = tempDir;

    TestData testdata[] =
    {
        // directoryNames, comparison, version, expected
        { {}, L"semver", L"1.0.0", false },
        { {}, L"semver_eq", L"1.0.0", false },
        { {}, L"semver_lt", L"1.0.0", false },
        { {}, L"semver_le", L"1.0.0", false },
        { {}, L"semver_gt", L"1.0.0", false },
        { {}, L"semver_ge", L"1.0.0", false },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        check.comparison = testdata[i].comparison;
        check.version = testdata[i].version;
        Assert::AreEqual(testdata[i].expected, check.IsInstalled());
    }
}

void InstalledCheckDirectoryUnitTests::testIsInstalled_semver()
{
    std::wstring tempDir = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), DVLib::GenerateGUIDStringW());
    DVLib::DirectoryCreate(tempDir);

    InstalledCheckDirectory check;
    check.path = tempDir;

    TestData testdata[] =
    {
        // directoryNames, comparison, version, expected
        { {L"1.2.3"}, L"semver", L"1.2.3", true },
        { {L"1.0.0"}, L"semver", L"1.0.0-alpha", true },
        { {L"1.0.0-alpha"}, L"semver", L"1.0.0", false },
        { {L"6.0.6", L"7.0.0-preview.5.22301.12"}, L"semver", L"6.0.7", true },
        { {L"5.0.17", L"6.0.6"}, L"semver", L"7.0.0-preview.5.22301.12", false },

        { {L"1.2.3"}, L"semver_eq", L"1.2.3", true },
        { {L"1.0.0"}, L"semver_eq", L"1.0.0-alpha", false },
        { {L"1.0.0-alpha"}, L"semver_eq", L"1.0.0", false },
        { {L"6.0.6", L"7.0.0-preview.5.22301.12"}, L"semver_eq", L"6.0.7", false },
        { {L"5.0.17", L"6.0.6"}, L"semver_eq", L"7.0.0-preview.5.22301.12", false },

        { {L"1.2.3"}, L"semver_lt", L"1.2.3", false },
        { {L"1.0.0"}, L"semver_lt", L"1.0.0-alpha", false },
        { {L"1.0.0-alpha"}, L"semver_lt", L"1.0.0", true },
        { {L"6.0.6", L"7.0.0-preview.5.22301.12"}, L"semver_lt", L"6.0.7", true },
        { {L"5.0.17", L"6.0.6"}, L"semver_lt", L"7.0.0-preview.5.22301.12", true },

        { {L"1.2.3"}, L"semver_le", L"1.2.3", true },
        { {L"1.0.0"}, L"semver_le", L"1.0.0-alpha", false },
        { {L"1.0.0-alpha"}, L"semver_le", L"1.0.0", true },
        { {L"6.0.6", L"7.0.0-preview.5.22301.12"}, L"semver_le", L"6.0.7", true },
        { {L"5.0.17", L"6.0.6"}, L"semver_le", L"7.0.0-preview.5.22301.12", true },

        { {L"1.2.3"}, L"semver_gt", L"1.2.3", false },
        { {L"1.0.0"}, L"semver_gt", L"1.0.0-alpha", true },
        { {L"1.0.0-alpha"}, L"semver_gt", L"1.0.0", false },
        { {L"6.0.6", L"7.0.0-preview.5.22301.12"}, L"semver_gt", L"6.0.7", true },
        { {L"5.0.17", L"6.0.6"}, L"semver_gt", L"7.0.0-preview.5.22301.12", false },

        { {L"1.2.3"}, L"semver_ge", L"1.2.3", true },
        { {L"1.0.0"}, L"semver_ge", L"1.0.0-alpha", true },
        { {L"1.0.0-alpha"}, L"semver_ge", L"1.0.0", false },
        { {L"6.0.6", L"7.0.0-preview.5.22301.12"}, L"semver_ge", L"6.0.7", true },
        { {L"5.0.17", L"6.0.6"}, L"semver_ge", L"7.0.0-preview.5.22301.12", false },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        for each (const std::wstring & directoryName in testdata[i].directoryNames)
        {
            std::wstring subDirectory = DVLib::DirectoryCombine(tempDir, directoryName);
            DVLib::DirectoryCreate(subDirectory);
        }

        check.comparison = testdata[i].comparison;
        check.version = testdata[i].version;
        Assert::AreEqual(testdata[i].expected, check.IsInstalled());

        for each (const std::wstring & directoryName in testdata[i].directoryNames)
        {
            std::wstring subDirectory = DVLib::DirectoryCombine(tempDir, directoryName);
            DVLib::DirectoryDelete(subDirectory, DELETE_DIRECTORY_FLAGS::DELETE_DIRECTORY_EMPTY);
        }
    }

    DVLib::DirectoryDelete(tempDir, DELETE_DIRECTORY_FLAGS::DELETE_DIRECTORY_EMPTY);
}

void InstalledCheckDirectoryUnitTests::testIsInstalled_semver_invalid()
{
    std::wstring tempDir = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), DVLib::GenerateGUIDStringW());
    DVLib::DirectoryCreate(tempDir);

    InstalledCheckDirectory check;
    check.path = tempDir;

    TestDataException testdata[] =
    {
        // directoryNames, comparison, version, expectedException
        { {L"invalid"}, L"semver", L"1.2.3", "invalid character encountered: i" },
        { {L"unknown"}, L"semver", L"1.2.3", "invalid character encountered: u" },
        { {L"_"}, L"semver_eq", L"1.2.3", "invalid character encountered: _" },
        { {L"+"}, L"semver_lt", L"1.2.3", "invalid character encountered: +" },
        { {L";"}, L"semver_le", L"1.2.3", "invalid character encountered: ;" },
        { {L"-"}, L"semver_gt", L"1.2.3", "invalid character encountered: -" },
        { {L"="}, L"semver_ge", L"1.2.3", "invalid character encountered: =" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        for each (const std::wstring & directoryName in testdata[i].directoryNames)
        {
            std::wstring subDirectory = DVLib::DirectoryCombine(tempDir, directoryName);
            DVLib::DirectoryCreate(subDirectory);
        }

        check.comparison = testdata[i].comparison;
        check.version = testdata[i].version;

        try
        {
            check.IsInstalled();

            Assert::Fail(L"Expected exception.");
        }
        catch (std::exception& ex)
        {
            Assert::AreEqual(testdata[i].expectedException, ex.what());
        }

        for each (const std::wstring & directoryName in testdata[i].directoryNames)
        {
            std::wstring subDirectory = DVLib::DirectoryCombine(tempDir, directoryName);
            DVLib::DirectoryDelete(subDirectory, DELETE_DIRECTORY_FLAGS::DELETE_DIRECTORY_EMPTY);
        }
    }

    DVLib::DirectoryDelete(tempDir, DELETE_DIRECTORY_FLAGS::DELETE_DIRECTORY_EMPTY);
}