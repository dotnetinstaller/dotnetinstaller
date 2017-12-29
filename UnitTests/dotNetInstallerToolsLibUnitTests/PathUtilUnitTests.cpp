#include "StdAfx.h"
#include "PathUtilUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void PathUtilUnitTests::testGetFileDirectory()
{
    struct TestData
    {
        LPCWSTR path;
        LPCWSTR dir;
    };

    TestData testdata[] = 
    {
        { L"", L"" },
        { L"x", L"" },
        { L"C:\\", L"C:\\" },
        { L"file://", L"file://" },
        { L"file://x", L"file://" },
        { L"file://x/", L"file://x/" },
        { L"file://x/y", L"file://x/" },
        { L"C:\\temp", L"C:\\" },
        { L"C:\\temp\\", L"C:\\temp\\" },
        { L"C:\\temp\\file", L"C:\\temp\\" },
        { L"C:\\temp\\path\\file", L"C:\\temp\\path\\" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wstring dir = DVLib::GetFileDirectoryW(testdata[i].path);
        std::wcout << std::endl << testdata[i].path << L" => " << dir;
        Assert::IsTrue(dir == testdata[i].dir);
    }
}

void PathUtilUnitTests::testGetFileName()
{
    struct TestData
    {
        LPCWSTR path;
        LPCWSTR filename;
    };

    TestData testdata[] = 
    {
        { L"", L"" },
        { L"x", L"x" },
        { L"filename.txt", L"filename.txt" },
        { L"C:\\", L"" },
        { L"file://", L"" },
        { L"file://x", L"x" },
        { L"file://x/", L"" },
        { L"file://x/y", L"y" },
        { L"C:\\temp", L"temp" },
        { L"C:\\temp\\", L"" },
        { L"C:\\temp\\file", L"file" },
        { L"C:\\temp\\path\\file", L"file" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wstring filename = DVLib::GetFileNameW(testdata[i].path);
        std::wcout << std::endl << testdata[i].path << L" => " << filename;
        Assert::IsTrue(filename == testdata[i].filename);
    }
}

void PathUtilUnitTests::testGetModuleDirectory()
{
    std::string path = DVLib::GetModuleDirectoryA();
    std::cout << std::endl << "Module: " << path;
    Assert::IsTrue(path.length() > 0);
    char moduleFileName[MAX_PATH];
    Assert::IsTrue(::GetModuleFileNameA(NULL, moduleFileName, MAX_PATH));
    std::cout << std::endl << "Compare: " << moduleFileName;
    // Assert::IsTrue(DVLib::startsWith(moduleFileName, path));
}

void PathUtilUnitTests::testGetModuleFileName()
{
    std::string path = DVLib::GetModuleFileNameA();
    std::cout << std::endl << "Module: " << path;
    Assert::IsTrue(path.length() > 0);
    char moduleFileName[MAX_PATH];
    Assert::IsTrue(::GetModuleFileNameA(NULL, moduleFileName, MAX_PATH));
    std::cout << std::endl << "Compare: " << moduleFileName;
    Assert::IsTrue(moduleFileName == path);
}

void PathUtilUnitTests::testDirectoryCombine()
{
    struct TestData
    {
        LPCWSTR dir;
        LPCWSTR file;
        LPCWSTR expected_result;
    };

    TestData testdata[] = 
    {
        { L"C:", L"One\\Two\\Three", L"C:\\One\\Two\\Three" },
        { L"C:\\One", L"Two", L"C:\\One\\Two" },
        { L"C:\\One\\", L"Two", L"C:\\One\\Two" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wcout << std::endl << testdata[i].dir << L" + " << testdata[i].file;
        std::wstring result = DVLib::DirectoryCombine(testdata[i].dir, testdata[i].file);
        std::wcout << L" => " << result;
        Assert::IsTrue(result == testdata[i].expected_result);
    }
}

void PathUtilUnitTests::testGetTemporaryDirectory()
{
    std::wstring directory = DVLib::GetTemporaryDirectoryW();
    std::wcout << std::endl << L"Temporary directory: " << directory;
    Assert::IsTrue(directory.length() > 0);
    Assert::IsTrue(DVLib::DirectoryExists(directory));
}

void PathUtilUnitTests::testGetCurrentDirectory()
{
    char expected_result[MAX_PATH];
    Assert::IsTrue(0 < ::GetCurrentDirectoryA(MAX_PATH, expected_result));
    std::string curdir_a = DVLib::GetCurrentDirectoryA();
    std::wstring curdir_w = DVLib::GetCurrentDirectoryW();
    std::wcout << std::endl << "Unicode: " << curdir_w;
    std::cout << std::endl << "ANSI: " << curdir_a;
    Assert::IsTrue(curdir_w.length() > 0);
    Assert::IsTrue(curdir_w.length() == strlen(expected_result));
    Assert::IsTrue(curdir_w.length() == curdir_a.length());
    Assert::IsTrue(strcmp(curdir_a.c_str(), expected_result) == 0);
    Assert::IsTrue(DVLib::DirectoryExists(curdir_w));
}

void PathUtilUnitTests::testGetSystemDirectory()
{
    std::wstring directory = DVLib::GetSystemDirectoryW();
    std::wcout << std::endl << L"System directory: " << directory;
    Assert::IsTrue(directory.length() > 0);
    Assert::IsTrue(DVLib::DirectoryExists(directory));
}

void PathUtilUnitTests::testGetWindowsDirectory()
{
    std::wstring directory = DVLib::GetWindowsDirectoryW();
    std::wcout << std::endl << L"Windows directory: " << directory;
    Assert::IsTrue(directory.length() > 0);
    Assert::IsTrue(DVLib::DirectoryExists(directory));
}

void PathUtilUnitTests::testGetSystemWindowsDirectory()
{
    std::wstring directory = DVLib::GetSystemWindowsDirectoryW();
    std::wcout << std::endl << L"Windows system directory: " << directory;
    Assert::IsTrue(directory.length() > 0);
    Assert::IsTrue(DVLib::DirectoryExists(directory));
}

void PathUtilUnitTests::testStripPathTerminator()
{
    struct TestData
    {
        LPCWSTR path;
        LPCWSTR stripped_path;
    };

    TestData testdata[] = 
    {
        { L"", L"" },
        { L"x", L"x" },
        { L"C:", L"C:\\" },
        { L"C:\\", L"C:\\" },
        { L"C:\\temp", L"C:\\temp" },
        { L"C:\\temp\\", L"C:\\temp" },
        { L"C:\\temp\\file", L"C:\\temp\\file" },
        { L"C:\\temp\\file\\", L"C:\\temp\\file" },
        { L"C:\\temp\\path\\file", L"C:\\temp\\path\\file" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wstring stripped_path = DVLib::StripPathTerminator(testdata[i].path);
        std::wcout << std::endl << testdata[i].path << L" => " << stripped_path;
        Assert::IsTrue(stripped_path == testdata[i].stripped_path);
    }
}