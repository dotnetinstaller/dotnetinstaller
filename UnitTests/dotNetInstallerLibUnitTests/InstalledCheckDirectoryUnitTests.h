#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(InstalledCheckDirectoryUnitTests), public dotNetInstallerLibUnitTestFixture
		{
            TEST_METHOD_INITIALIZE( initialize )
            {
                setUp();
            }

            TEST_METHOD_CLEANUP( cleanup )
            {
                tearDown();
            }

			TEST_METHOD( testIsInstalled );
            TEST_METHOD( testIsInstalled_version_with_non_existent_directory );
            TEST_METHOD( testIsInstalled_version );
            TEST_METHOD( testIsInstalled_semver_with_non_existent_directory );
            TEST_METHOD( testIsInstalled_semver );
            TEST_METHOD( testIsInstalled_semver_invalid );

        private:
            struct TestData
            {
                std::list<std::wstring> directoryNames;
                LPCWSTR comparison;
                LPCWSTR version;
                bool expected;
            };

            struct TestDataException
            {
                std::list<std::wstring> directoryNames;
                LPCWSTR comparison;
                LPCWSTR version;
                LPCSTR expectedException;
            };
		};
	}
}
