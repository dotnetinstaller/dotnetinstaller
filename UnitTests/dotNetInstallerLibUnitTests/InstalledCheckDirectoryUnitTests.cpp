#include "StdAfx.h"
#include "InstalledCheckDirectoryUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::InstalledCheckDirectoryUnitTests);

using namespace DVLib::UnitTests;

void InstalledCheckDirectoryUnitTests::testIsInstalled()
{
    std::wcout << std::endl << L"Checking " << DVLib::GetSystemDirectoryW();
    InstalledCheckDirectory check;
    check.path = DVLib::GetSystemDirectoryW();
    CPPUNIT_ASSERT(check.IsInstalled());
    check.path = DVLib::GenerateGUIDStringW();
    CPPUNIT_ASSERT(! check.IsInstalled());
}