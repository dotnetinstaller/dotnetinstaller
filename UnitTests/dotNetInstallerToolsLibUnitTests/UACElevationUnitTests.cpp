#include "StdAfx.h"
#include "UACElevationUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(UACElevationUnitTests);

void UACElevationUnitTests::testIsUserInAdminGroup()
{
	// As build is run as an admin this should return true
	CPPUNIT_ASSERT(DVLib::IsUserInAdminGroup());
}

void UACElevationUnitTests::testIsRunAsAdmin()
{
	// As build is run as an admin this should return true
	CPPUNIT_ASSERT(DVLib::IsRunAsAdmin());
}

void UACElevationUnitTests::testIsElevationSupported()
{
	OSVERSIONINFO osver = { sizeof(osver) };
	CPPUNIT_ASSERT(DVLib::IsElevationSupported() == (GetVersionEx(&osver) && osver.dwMajorVersion >= 6));
}

void UACElevationUnitTests::testIsProcessElevated()
{
	if (DVLib::IsElevationSupported())
	{
		// As build is run as an admin this should return true
		CPPUNIT_ASSERT(DVLib::IsProcessElevated());
	}
}

void UACElevationUnitTests::testShellElevated()
{
	if (DVLib::IsElevationSupported())
	{
		CPPUNIT_ASSERT(DVLib::ShellElevated(NULL, L"cmd.exe", L"C:\\", L"/c exit 0"));
	}
}

void UACElevationUnitTests::testRestartElevated()
{
	if (DVLib::IsElevationSupported())
	{
		// This will restart this test elevated and run one test.
		CPPUNIT_ASSERT(DVLib::RestartElevated(NULL, L"DVLib::UnitTests::UACElevationUnitTests::testIsProcessElevated"));
	}
}
