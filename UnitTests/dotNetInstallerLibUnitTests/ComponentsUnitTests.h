#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(ComponentsUnitTests), public dotNetInstallerLibUnitTestFixture
		{
            TEST_METHOD_INITIALIZE( initialize )
            {
                setUp();
            }

            TEST_METHOD_CLEANUP( cleanup )
            {
                tearDown();
            }

			TEST_METHOD( testAdd );
			TEST_METHOD( testOsFilters );
            TEST_METHOD( testOsFiltersGreaterSmaller );
			TEST_METHOD( testLcidFilters );
			TEST_METHOD( testPAFilters );
			TEST_METHOD( testOsTypeFilters );
			TEST_METHOD( testExecNoCallback );
			TEST_METHOD( testExecWithCallback );
			TEST_METHOD( testExecWithError );
			TEST_METHOD( testLoadUninstallSequence );
			TEST_METHOD( testSequenceInstalled );
		};
	}
}
