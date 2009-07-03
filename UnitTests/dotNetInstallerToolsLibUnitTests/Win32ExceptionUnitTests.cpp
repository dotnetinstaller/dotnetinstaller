#include "StdAfx.h"
#include "Win32ExceptionUnitTests.h"

using namespace DVLib::UnitTests::Exceptions;

CPPUNIT_TEST_SUITE_REGISTRATION(Win32ExceptionUnitTests);

void Win32ExceptionUnitTests::testDWORD()
{
	try
	{
        throw std::exception(DVLib::GetErrorString(ERROR_NOT_FOUND).c_str());		
	}
    catch(std::exception& ex)
	{
		std::wcout << std::endl << ex.what();
	}
}

void Win32ExceptionUnitTests::testGetLastError()
{
	try
	{
		::SetLastError(ERROR_SUCCESS);
        throw std::exception(DVLib::GetLastErrorString().c_str());		
	}
    catch(std::exception& ex)
	{
		std::wcout << std::endl << ex.what();
	}
}

void Win32ExceptionUnitTests::testHRESULT()
{
	try
	{
        throw std::exception(DVLib::GetErrorString(HRESULT_FROM_WIN32(ERROR_NOT_FOUND)).c_str());		
	}
    catch(std::exception& ex)
	{
		std::wcout << std::endl << ex.what();
	}
}

void Win32ExceptionUnitTests::testGetLastErrorComposite()
{
	try
	{
		::SetLastError(ERROR_SUCCESS);
        throw std::exception(DVLib::GetLastErrorString(_T("UT")).c_str());		
	}
    catch(std::exception& ex)
	{
		std::wcout << std::endl << ex.what();
	}
}