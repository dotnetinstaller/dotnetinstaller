#include "StdAfx.h"
#include "UACElevationUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void UACElevationUnitTests::testIsUserInAdminGroup()
{
    // As build is run as an admin this should return true
    Assert::IsTrue(DVLib::IsUserInAdminGroup());
}

void UACElevationUnitTests::testIsRunAsAdmin()
{
    // As build is run as an admin this should return true
    Assert::IsTrue(DVLib::IsRunAsAdmin());
}

void UACElevationUnitTests::testIsElevationSupported()
{
    OSVERSIONINFO osver = { sizeof(osver) };
    Assert::IsTrue(DVLib::IsElevationSupported() == (GetVersionEx(&osver) && osver.dwMajorVersion >= 6));
}

void UACElevationUnitTests::testIsProcessElevated()
{
    if (DVLib::IsElevationSupported())
    {
        // As build is run as an admin this should return true
        Assert::IsTrue(DVLib::IsProcessElevated());
    }
}

void UACElevationUnitTests::testShellElevated()
{
    if (DVLib::IsElevationSupported())
    {
        Assert::IsTrue(DVLib::ShellElevated(NULL, L"cmd.exe", L"C:\\", L"/c exit 0"));
    }
}

void UACElevationUnitTests::testRestartElevated()
{
    if (DVLib::IsElevationSupported())
    {
        // This will restart this test elevated and run one test.
        Assert::IsTrue(DVLib::RestartElevated(NULL, L"DVLib::UnitTests::UACElevationUnitTests::testIsProcessElevated"));
    }
}
