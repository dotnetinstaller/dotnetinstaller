#include "StdAfx.h"
#include "FunctionUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(FunctionUtilUnitTests);

void FunctionUtilUnitTests::testDllFunctionExists()
{
	typedef HGLOBAL (WINAPI * pGlobalAlloc) (UINT flags, SIZE_T bytes);
	DllFunction<pGlobalAlloc> myGlobalAlloc(L"kernel32.dll", "GlobalAlloc");
	CPPUNIT_ASSERT(NULL != myGlobalAlloc);
	HGLOBAL h = myGlobalAlloc(GMEM_FIXED, 123);
	CPPUNIT_ASSERT(NULL != h);
	CPPUNIT_ASSERT(GMEM_FIXED == ::GlobalFlags(h));
	::GlobalFree(h);
}

void FunctionUtilUnitTests::testDllFunctionDoesntExist()
{
	typedef HGLOBAL (WINAPI * pGlobalAlloc) (UINT flags, SIZE_T bytes);
	DllFunction<pGlobalAlloc> invalidFunction(L"kernel32.dll", "GlobalAllocDoesntExist");
	CPPUNIT_ASSERT(NULL == invalidFunction);
	DllFunction<pGlobalAlloc> invalidDll(L"kernel32doesntexist.dll", "GlobalAlloc");
	CPPUNIT_ASSERT(NULL == invalidDll);
}
