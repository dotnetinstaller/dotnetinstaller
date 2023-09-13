#include "stdafx.h"
#include "InstalledCheckWmiUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void InstalledCheckWmiUnitTests::setUp()
{
    dotNetInstallerLibUnitTestFixture::setUp();
}

void InstalledCheckWmiUnitTests::tearDown()
{
    dotNetInstallerLibUnitTestFixture::tearDown();
}

void InstalledCheckWmiUnitTests::testIsInstalled()
{
    struct TestData
    {
        LPCWSTR query;
        bool expected_isinstalled;
    };

    TestData testdata[] =
    {
        { L"SELECT * FROM Win32_Process WHERE ProcessId < 0", false }, // returns no results
        { L"SELECT Name FROM Win32_ComputerSystem", true }, // returns one result
        { L"SELECT * FROM Win32_OperatingSystem", true }, // returns one result
        { L"SELECT * FROM Win32_Service", true }, // returns more than one result
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        InstalledCheckWmi check;
        check.query = testdata[i].query;

        try
        {
            bool isinstalled = check.IsInstalled();

            std::wcout << std::endl
                << check.query
                << L": " << (isinstalled ? L"yes" : L"no");
            Assert::IsTrue(isinstalled == testdata[i].expected_isinstalled);
        }
        catch (std::exception& ex)
        {
            Assert::Fail(DVLib::string2wstring(ex.what()).c_str());
        }
    }
}
