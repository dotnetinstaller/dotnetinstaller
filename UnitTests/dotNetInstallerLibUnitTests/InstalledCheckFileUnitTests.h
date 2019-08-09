#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
    namespace UnitTests 
    {
        TEST_CLASS(InstalledCheckFileUnitTests), public dotNetInstallerLibUnitTestFixture
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

        private:
            struct TestData
            {
                LPCWSTR filename;
                LPCWSTR fileversion; // the version of attrib.exe is being compared to this version
                LPCWSTR comparison;
                bool defaultvalue;
                bool expected_isinstalled;
                bool disableWow64FsRedirection;
            };

            void testIsInstalled(TestData testdata, bool disableWow64FsRedirection);
        };
    }
}
