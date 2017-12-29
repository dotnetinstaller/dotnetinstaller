#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(InstalledCheckRegistryUnitTests), public dotNetInstallerLibUnitTestFixture
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
			// \todo: WOW options tests
			// TEST_METHOD( testWOW64_64 );
			// TEST_METHOD( testWOW64_32 );

            void setUp();
            void tearDown();
		};
	}
}
