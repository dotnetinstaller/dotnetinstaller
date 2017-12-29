#include "StdAfx.h"
#include "FunctionUtilUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void FunctionUtilUnitTests::testDllFunctionExists()
{
    typedef HGLOBAL (WINAPI * pGlobalAlloc) (UINT flags, SIZE_T bytes);
    DllFunction<pGlobalAlloc> myGlobalAlloc(L"kernel32.dll", "GlobalAlloc");
    Assert::IsTrue(NULL != myGlobalAlloc);
    HGLOBAL h = myGlobalAlloc(GMEM_FIXED, 123);
    Assert::IsTrue(NULL != h);
    Assert::IsTrue(GMEM_FIXED == ::GlobalFlags(h));
    ::GlobalFree(h);
}

void FunctionUtilUnitTests::testDllFunctionDoesntExist()
{
    typedef HGLOBAL (WINAPI * pGlobalAlloc) (UINT flags, SIZE_T bytes);
    DllFunction<pGlobalAlloc> invalidFunction(L"kernel32.dll", "GlobalAllocDoesntExist");
    Assert::IsTrue(NULL == invalidFunction);
    DllFunction<pGlobalAlloc> invalidDll(L"kernel32doesntexist.dll", "GlobalAlloc");
    Assert::IsTrue(NULL == invalidDll);
}
