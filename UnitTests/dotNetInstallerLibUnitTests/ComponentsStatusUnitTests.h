#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
		TEST_CLASS(ComponentsStatusUnitTests), public dotNetInstallerLibUnitTestFixture
		{
            TEST_METHOD_INITIALIZE( initialize )
            {
                setUp();
            }

            TEST_METHOD_CLEANUP( cleanup )
            {
                tearDown();
            }

			TEST_METHOD( testEqual );
			TEST_METHOD( testAll );
			TEST_METHOD( testAllRequired );
			TEST_METHOD( testAllOptional );
		};
	}
}
