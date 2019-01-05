#include "StdAfx.h"
#include "FormatUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void FormatUnitTests::testFormatMessageA()
{
    std::string result = DVLib::FormatMessage(
        "Error executing: %s. Error Code: %d", "MessageFormatter", 100);	

    Assert::IsTrue(result.compare("Error executing: MessageFormatter. Error Code: 100") == 0);
}

void FormatUnitTests::testFormatMessageW()
{
    std::wstring result = DVLib::FormatMessage(
        L"Error executing: %s. Error Code: %d", L"MessageFormatter", 100);	

    Assert::IsTrue(result.compare(L"Error executing: MessageFormatter. Error Code: 100") == 0);
}

void FormatUnitTests::testFormatMessageFromLastErrorCodeA()
{
    std::string expected = "The remote server has been paused or is in the process of being started.";
    DWORD errorCode = ERROR_SHARING_PAUSED; // The remote server has been paused or is in the process of being started.
    std::string result = DVLib::FormatMessageFromLastErrorCodeA(errorCode);
    std::wstring assertMessage = DVLib::FormatMessageFromLastErrorCodeW(errorCode);
    Assert::IsTrue(result.compare(expected) == 0, assertMessage.c_str());
}

void FormatUnitTests::testFormatMessageFromLastErrorCodeW()
{
    std::wstring expected = L"The remote server has been paused or is in the process of being started.";
    DWORD errorCode = ERROR_SHARING_PAUSED; // The remote server has been paused or is in the process of being started.
    std::wstring result = DVLib::FormatMessageFromLastErrorCodeW(errorCode);	
    Assert::IsTrue(result.compare(expected) == 0 );
}

void FormatUnitTests::testFormatMessageFromHRA()
{
    Assert::IsTrue(DVLib::FormatMessageFromHRA(S_OK) == "The operation completed successfully.");
    Assert::IsTrue(DVLib::FormatMessageFromHRA(INET_E_SECURITY_PROBLEM, "urlmon.dll") == "A security problem occurred.");
}

void FormatUnitTests::testFormatMessageFromHRW()
{
    Assert::IsTrue(DVLib::FormatMessageFromHRW(S_OK) == L"The operation completed successfully.");
    Assert::IsTrue(DVLib::FormatMessageFromHRW(INET_E_SECURITY_PROBLEM, L"urlmon.dll") == L"A security problem occurred.");
}

void FormatUnitTests::testFormatBytes()
{
    struct TestData
    {
        ULONG bytes;
        LPCWSTR expected_result;
    };

    TestData testData[] = 
    {
        { 0, L"0 bytes" },
        { 1, L"1 byte" },
        { 532, L"532 bytes" },
        { 1024, L"1KB" },
        { 1340, L"1.3KB" },
        { 1024 * 1024, L"1MB" },
        { 2400016, L"2.3MB" },
        { 1024 * 1024 * 1024, L"1GB" },
        { 2400000000, L"2.2GB" },
    };

    for (int i = 0; i < ARRAYSIZE(testData); i++)
    {
        {
            std::wstring result = DVLib::FormatBytesW(testData[i].bytes);
            std::wcout << std::endl << testData[i].bytes << L" => " << result;
            Assert::IsTrue(testData[i].expected_result == result);
        }
        {
            std::string result = DVLib::FormatBytesA(testData[i].bytes);
            std::cout << std::endl << testData[i].bytes << " => " << result;
            Assert::IsTrue(testData[i].expected_result == DVLib::string2wstring(result));
        }
    }
}

void FormatUnitTests::testFormatDateTime()
{
    // set the current time-zone to UTC to make FormatDateTime predictable
    Assert::IsTrue(ERROR_SUCCESS == _putenv_s( "TZ", "UTC" ));
    _tzset();
    // formatting of 0 time is the number of seconds since 1970-01-01, hence 0
    Assert::IsTrue(DVLib::FormatDateTimeA(0) == "1970-01-01 00:00:00");
    Assert::IsTrue("1970" == DVLib::FormatDateTimeA(0, "%Y"));
    Assert::IsTrue(DVLib::FormatDateTimeW(0) == L"1970-01-01 00:00:00");
    Assert::IsTrue(L"1970" == DVLib::FormatDateTimeW(0, L"%Y"));
}

void FormatUnitTests::testFormatCurrentDateTime()
{
    {
        std::wstring current_time = DVLib::FormatCurrentDateTimeW();
        std::wcout << std::endl << current_time;
        Assert::IsTrue(! current_time.empty());
    }

    {
        std::string current_time = DVLib::FormatCurrentDateTimeA();
        std::cout << std::endl << current_time;
        Assert::IsTrue(! current_time.empty());
    }

    time_t t = 0;
    time(& t);
    struct tm tt = { 0 };
    localtime_s(& tt, &t);
    Assert::IsTrue(DVLib::towstring(tt.tm_year + 1900) == DVLib::FormatCurrentDateTimeW(L"%Y"));
    Assert::IsTrue(DVLib::tostring(tt.tm_year + 1900) == DVLib::FormatCurrentDateTimeA("%Y"));
}

