#include "StdAfx.h"
#include "PathUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(PathUtilUnitTests);

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
		CPPUNIT_ASSERT(dir == testdata[i].dir);
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
		CPPUNIT_ASSERT(filename == testdata[i].filename);
	}
}

void PathUtilUnitTests::testGetModuleDirectory()
{
	std::string path = DVLib::GetModuleDirectoryA();
	std::cout << std::endl << "Module: " << path;
	CPPUNIT_ASSERT(path.length() > 0);
	char moduleFileName[MAX_PATH];
	CPPUNIT_ASSERT(::GetModuleFileNameA(NULL, moduleFileName, MAX_PATH));
	std::cout << std::endl << "Compare: " << moduleFileName;
	// CPPUNIT_ASSERT(DVLib::startsWith(moduleFileName, path));
}

void PathUtilUnitTests::testGetModuleFileName()
{
	std::string path = DVLib::GetModuleFileNameA();
	std::cout << std::endl << "Module: " << path;
	CPPUNIT_ASSERT(path.length() > 0);
	char moduleFileName[MAX_PATH];
	CPPUNIT_ASSERT(::GetModuleFileNameA(NULL, moduleFileName, MAX_PATH));
	std::cout << std::endl << "Compare: " << moduleFileName;
	CPPUNIT_ASSERT(moduleFileName == path);
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
        CPPUNIT_ASSERT(result == testdata[i].expected_result);
    }
}

void PathUtilUnitTests::testGetTemporaryDirectory()
{
	std::wstring directory = DVLib::GetTemporaryDirectoryW();
	std::wcout << std::endl << L"Temporary directory: " << directory;
	CPPUNIT_ASSERT(directory.length() > 0);
	CPPUNIT_ASSERT(DVLib::DirectoryExists(directory));
}

void PathUtilUnitTests::testGetCurrentDirectory()
{
    char expected_result[MAX_PATH];
    CPPUNIT_ASSERT(0 < ::GetCurrentDirectoryA(MAX_PATH, expected_result));
    std::string curdir_a = DVLib::GetCurrentDirectoryA();
    std::wstring curdir_w = DVLib::GetCurrentDirectoryW();
    std::wcout << std::endl << "Unicode: " << curdir_w;
    std::cout << std::endl << "ANSI: " << curdir_a;
    CPPUNIT_ASSERT(curdir_w.length() > 0);
    CPPUNIT_ASSERT(curdir_w.length() == strlen(expected_result));
    CPPUNIT_ASSERT(curdir_w.length() == curdir_a.length());
    CPPUNIT_ASSERT(strcmp(curdir_a.c_str(), expected_result) == 0);
    CPPUNIT_ASSERT(DVLib::DirectoryExists(curdir_w));
}

void PathUtilUnitTests::testGetSystemDirectory()
{
	std::wstring directory = DVLib::GetSystemDirectoryW();
	std::wcout << std::endl << L"System directory: " << directory;
	CPPUNIT_ASSERT(directory.length() > 0);
	CPPUNIT_ASSERT(DVLib::DirectoryExists(directory));
}

void PathUtilUnitTests::testGetWindowsDirectory()
{
	std::wstring directory = DVLib::GetWindowsDirectoryW();
	std::wcout << std::endl << L"Windows directory: " << directory;
	CPPUNIT_ASSERT(directory.length() > 0);
	CPPUNIT_ASSERT(DVLib::DirectoryExists(directory));
}

void PathUtilUnitTests::testGetSystemWindowsDirectory()
{
	std::wstring directory = DVLib::GetSystemWindowsDirectoryW();
	std::wcout << std::endl << L"Windows system directory: " << directory;
	CPPUNIT_ASSERT(directory.length() > 0);
	CPPUNIT_ASSERT(DVLib::DirectoryExists(directory));
}
