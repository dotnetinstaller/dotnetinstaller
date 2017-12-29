#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(InstalledCheckOperatorUnitTests), public dotNetInstallerLibUnitTestFixture
		{
            TEST_METHOD_INITIALIZE( initialize )
            {
                setUp();
            }

            TEST_METHOD_CLEANUP( cleanup )
            {
                tearDown();
            }

			TEST_METHOD( testAnd );
			TEST_METHOD( testOr );
			TEST_METHOD( testNot );
		};
	}
}
