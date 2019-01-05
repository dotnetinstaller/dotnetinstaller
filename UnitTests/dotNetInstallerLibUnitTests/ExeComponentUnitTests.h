#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(ExeComponentUnitTests), public dotNetInstallerLibUnitTestFixture
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
			TEST_METHOD( testExecInstallResponseFile );
			TEST_METHOD( testExecInstallDir );
			TEST_METHOD( testExecShell );
			TEST_METHOD( testMustReboot );
			TEST_METHOD( testReturnCodeRebootRequired );
			TEST_METHOD( testReturnCodeSuccess );
			TEST_METHOD( testLoad );
		};
	}
}
