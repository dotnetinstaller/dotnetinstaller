#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
		TEST_CLASS(ExtractComponentUnitTests), public dotNetInstallerLibUnitTestFixture
		{
            TEST_METHOD_INITIALIZE( initialize )
            {
                setUp();
            }

            TEST_METHOD_CLEANUP( cleanup )
            {
                tearDown();
            }

			TEST_METHOD( testExtractWithoutComponentId );
			TEST_METHOD( testExtractWithComponentId );
			TEST_METHOD( testExtractWithStatus );
		};
	}
}
