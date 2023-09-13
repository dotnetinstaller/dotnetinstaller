#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
    namespace UnitTests
    {
        TEST_CLASS(InstalledCheckWmiUnitTests), public dotNetInstallerLibUnitTestFixture
        {
            TEST_METHOD_INITIALIZE(initialize)
            {
                setUp();
            }

            TEST_METHOD_CLEANUP(cleanup)
            {
                tearDown();
            }

            TEST_METHOD(testIsInstalled);

            void setUp();
            void tearDown();
        };
    }
}
