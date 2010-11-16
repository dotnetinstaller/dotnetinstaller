#include "StdAfx.h"
#include "FormatUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(FormatUnitTests);

void FormatUnitTests::testFormatMessageA()
{
	std::string result = DVLib::FormatMessage(
		"Error executing: %s. Error Code: %d", "MessageFormatter", 100);	

	CPPUNIT_ASSERT(result.compare("Error executing: MessageFormatter. Error Code: 100") == 0);
}

void FormatUnitTests::testFormatMessageW()
{
	std::wstring result = DVLib::FormatMessage(
		L"Error executing: %s. Error Code: %d", L"MessageFormatter", 100);	

	CPPUNIT_ASSERT(result.compare(L"Error executing: MessageFormatter. Error Code: 100") == 0);
}

void FormatUnitTests::testFormatMessageFromLastErrorCodeA()
{
	std::string expected = "The remote server has been paused or is in the process of being started.";
	DWORD errorCode = ERROR_SHARING_PAUSED; // The remote server has been paused or is in the process of being started.
    std::string result = DVLib::FormatMessageFromLastErrorCodeA(errorCode);	
	CPPUNIT_ASSERT_MESSAGE(result, result.compare(expected) == 0 );
}

void FormatUnitTests::testFormatMessageFromLastErrorCodeW()
{
	std::wstring expected = L"The remote server has been paused or is in the process of being started.";
	DWORD errorCode = ERROR_SHARING_PAUSED; // The remote server has been paused or is in the process of being started.
    std::wstring result = DVLib::FormatMessageFromLastErrorCodeW(errorCode);	
	CPPUNIT_ASSERT(result.compare(expected) == 0 );
}

void FormatUnitTests::testFormatMessageFromHRA()
{
	CPPUNIT_ASSERT(DVLib::FormatMessageFromHRA(S_OK) == "The operation completed successfully.");
	CPPUNIT_ASSERT(DVLib::FormatMessageFromHRA(INET_E_SECURITY_PROBLEM, "urlmon.dll") == "A security problem occurred.");
}

void FormatUnitTests::testFormatMessageFromHRW()
{
	CPPUNIT_ASSERT(DVLib::FormatMessageFromHRW(S_OK) == L"The operation completed successfully.");
	CPPUNIT_ASSERT(DVLib::FormatMessageFromHRW(INET_E_SECURITY_PROBLEM, L"urlmon.dll") == L"A security problem occurred.");
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
			CPPUNIT_ASSERT(testData[i].expected_result == result);
		}
		{
			std::string result = DVLib::FormatBytesA(testData[i].bytes);
			std::cout << std::endl << testData[i].bytes << " => " << result;
			CPPUNIT_ASSERT(testData[i].expected_result == DVLib::string2wstring(result));
		}
	}
}

void FormatUnitTests::testFormatDateTime()
{
	CPPUNIT_ASSERT(DVLib::FormatDateTimeA(0).find_first_of("1969-12-31") == 0);
	CPPUNIT_ASSERT("1969" == DVLib::FormatDateTimeA(0, "%Y"));
	CPPUNIT_ASSERT(DVLib::FormatDateTimeW(0).find_first_of(L"1969-12-31") == 0);
	CPPUNIT_ASSERT(L"1969" == DVLib::FormatDateTimeW(0, L"%Y"));
}

void FormatUnitTests::testFormatCurrentDateTime()
{
	{
		std::wstring current_time = DVLib::FormatCurrentDateTimeW();
		std::wcout << std::endl << current_time;
		CPPUNIT_ASSERT(! current_time.empty());
	}

	{
		std::string current_time = DVLib::FormatCurrentDateTimeA();
		std::cout << std::endl << current_time;
		CPPUNIT_ASSERT(! current_time.empty());
	}

	time_t t = 0;
	time(& t);
	struct tm tt = { 0 };
	localtime_s(& tt, &t);
	CPPUNIT_ASSERT(DVLib::towstring(tt.tm_year + 1900) == DVLib::FormatCurrentDateTimeW(L"%Y"));
	CPPUNIT_ASSERT(DVLib::tostring(tt.tm_year + 1900) == DVLib::FormatCurrentDateTimeA("%Y"));
}

