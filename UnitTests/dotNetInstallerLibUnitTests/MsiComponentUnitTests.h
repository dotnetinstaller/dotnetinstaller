#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(MsiComponentUnitTests), public dotNetInstallerLibUnitTestFixture
		{
            TEST_METHOD_INITIALIZE( initialize )
            {
                setUp();
            }

            TEST_METHOD_CLEANUP( cleanup )
            {
                tearDown();
            }

			TEST_METHOD( testExecInstall );
			TEST_METHOD( testExecInstallSilent );
			TEST_METHOD( testExecUninstall );
			TEST_METHOD( testExecUninstallSilent );
			TEST_METHOD( testGetCommandLine );
			TEST_METHOD( testMustReboot );
		};
	}
}
