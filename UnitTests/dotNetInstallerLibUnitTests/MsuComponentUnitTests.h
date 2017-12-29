#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(MsuComponentUnitTests), public dotNetInstallerLibUnitTestFixture
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
			TEST_METHOD( testExecShell );
			TEST_METHOD( testMustReboot );
			TEST_METHOD( testLoad );
		};
	}
}
