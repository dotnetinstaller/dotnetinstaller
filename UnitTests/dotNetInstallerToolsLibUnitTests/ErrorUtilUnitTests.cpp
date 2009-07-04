#include "StdAfx.h"
#include "ErrorUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(ErrorUtilUnitTests);

void ErrorUtilUnitTests::testDWORD()
{
	CPPUNIT_ASSERT(DVLib::GetErrorStringW(ERROR_NOT_FOUND) == L"0x490: Element not found.");
	CPPUNIT_ASSERT(DVLib::GetErrorStringA(ERROR_NOT_FOUND) == "0x490: Element not found.");
}

void ErrorUtilUnitTests::testGetLastError()
{
	::SetLastError(ERROR_SUCCESS);
	CPPUNIT_ASSERT(DVLib::GetLastErrorStringA() == "0x0: The operation completed successfully.");
	CPPUNIT_ASSERT(DVLib::GetLastErrorStringW() == L"0x0: The operation completed successfully.");
}

void ErrorUtilUnitTests::testHRESULT()
{
	CPPUNIT_ASSERT(DVLib::GetErrorStringA(HRESULT_FROM_WIN32(ERROR_NOT_FOUND)) == "0x80070490: Element not found.");
	CPPUNIT_ASSERT(DVLib::GetErrorStringW(HRESULT_FROM_WIN32(ERROR_NOT_FOUND)) == L"0x80070490: Element not found.");
}

void ErrorUtilUnitTests::testGetLastErrorComposite()
{
	::SetLastError(ERROR_SUCCESS);
	CPPUNIT_ASSERT(DVLib::GetLastErrorStringA("UT") == "0x0 - UT: The operation completed successfully.");
	CPPUNIT_ASSERT(DVLib::GetLastErrorStringW(L"UT") == L"0x0 - UT: The operation completed successfully.");
}

