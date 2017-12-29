#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(InstallerSessionUnitTests), public dotNetInstallerLibUnitTestFixture
		{
            TEST_METHOD_INITIALIZE( initialize )
            {
                setUp();
            }

            TEST_METHOD_CLEANUP( cleanup )
            {
                tearDown();
            }

			TEST_METHOD( testExpandVariables );
			TEST_METHOD( testExpandPathVariables );
			TEST_METHOD( testExpandEnvironmentVariables );
			TEST_METHOD( testExpandRegistryVariables );
			TEST_METHOD( testExpandRegistryVariable );
			TEST_METHOD( testExpandUserVariables );
			TEST_METHOD( testExpandUserVariablesEscapes );
			TEST_METHOD( testGetRebootCmd );
			TEST_METHOD( testGetRestartCommandLine );
			TEST_METHOD( testEnableRunOnReboot );
			TEST_METHOD( testExpandPathVariablesBackslashes );
		};
	}
}
