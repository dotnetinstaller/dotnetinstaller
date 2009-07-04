#include "StdAfx.h"
#include "ExceptionMacrosUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(ExceptionMacrosUnitTests);

void ExceptionMacrosUnitTests::testCHECK_WIN32_DWORD()
{
	try
	{
		CHECK_WIN32_DWORD(ERROR_NOT_FOUND, "ERROR_NOT_FOUND");
		throw "expected std::exception";
	}
	catch(std::exception& ex)
	{
		std::cout << std::endl << ex.what();
		CPPUNIT_ASSERT(0 == strcmp(ex.what(), "0x80070490 - ERROR_NOT_FOUND: Element not found."));
	}
}

void ExceptionMacrosUnitTests::testCHECK_WIN32_BOOL()
{
	try
	{
		::SetLastError(ERROR_NOT_FOUND);
		CHECK_WIN32_BOOL(false, "ERROR_NOT_FOUND");
		throw "expected std::exception";
	}
	catch(std::exception& ex)
	{
		std::cout << std::endl << ex.what();
		CPPUNIT_ASSERT(0 == strcmp(ex.what(), "0x80070490 - ERROR_NOT_FOUND: Element not found."));
	}
}

void ExceptionMacrosUnitTests::testCHECK_BOOL()
{
	try
	{
		CHECK_BOOL(false, "ERROR_NOT_FOUND");
		throw "expected std::exception";
	}
	catch(std::exception& ex)
	{
		std::cout << std::endl << ex.what();
		CPPUNIT_ASSERT(0 == strcmp(ex.what(), "ERROR_NOT_FOUND"));
	}
}

void ExceptionMacrosUnitTests::testTHROW_EX()
{
	try
	{
		THROW_EX("expected exception: " << "test");
		throw "expected std::exception";
	}
	catch(std::exception& ex)
	{
		std::cout << std::endl << ex.what();
		CPPUNIT_ASSERT(0 == strcmp(ex.what(), "expected exception: test"));
	}
}

void ExceptionMacrosUnitTests::testCHECK_HR()
{
	try
	{
		CHECK_HR(HRESULT_FROM_WIN32(ERROR_NOT_FOUND), "ERROR_NOT_FOUND");
		throw "expected std::exception";
	}
	catch(std::exception& ex)
	{
		std::cout << std::endl << ex.what();
		CPPUNIT_ASSERT(0 == strcmp(ex.what(), "0x80070490 - ERROR_NOT_FOUND: Element not found."));
	}
}
