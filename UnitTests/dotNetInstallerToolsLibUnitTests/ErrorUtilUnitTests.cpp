#include "StdAfx.h"
#include "ErrorUtilUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ErrorUtilUnitTests::testDWORD()
{
    Assert::IsTrue(DVLib::GetErrorStringW(ERROR_NOT_FOUND) == L"0x490: Element not found.");
    Assert::IsTrue(DVLib::GetErrorStringA(ERROR_NOT_FOUND) == "0x490: Element not found.");
}

void ErrorUtilUnitTests::testGetLastError()
{
    ::SetLastError(ERROR_SUCCESS);
    Assert::IsTrue(DVLib::GetLastErrorStringA() == "0x0: The operation completed successfully.");
    Assert::IsTrue(DVLib::GetLastErrorStringW() == L"0x0: The operation completed successfully.");
}

void ErrorUtilUnitTests::testHRESULT()
{
    Assert::IsTrue(DVLib::GetErrorStringA(HRESULT_FROM_WIN32(ERROR_NOT_FOUND)) == "0x80070490: Element not found.");
    Assert::IsTrue(DVLib::GetErrorStringW(HRESULT_FROM_WIN32(ERROR_NOT_FOUND)) == L"0x80070490: Element not found.");
}

void ErrorUtilUnitTests::testGetLastErrorComposite()
{
    ::SetLastError(ERROR_SUCCESS);
    Assert::IsTrue(DVLib::GetLastErrorStringA("UT") == "0x0 - UT: The operation completed successfully.");
    Assert::IsTrue(DVLib::GetLastErrorStringW(L"UT") == L"0x0 - UT: The operation completed successfully.");
}

