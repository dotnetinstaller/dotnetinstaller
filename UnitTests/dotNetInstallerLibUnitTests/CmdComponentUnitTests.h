#pragma once
#include "dotNetInstallerLibUnitTestFixture.h"

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(CmdComponentUnitTests), public dotNetInstallerLibUnitTestFixture
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
			TEST_METHOD( testExecUninstall );
			TEST_METHOD( testExecUISilent );
			TEST_METHOD( testExecUIBasic );
			TEST_METHOD( testExecXCopy );
			TEST_METHOD( testExecShell );
			TEST_METHOD( testReturnCodeZero );
			TEST_METHOD( testReturnCodeNone );
			TEST_METHOD( testReturnCodeAll );
			TEST_METHOD( testReturnCodeNonZero );
			TEST_METHOD( testReturnCodeNonValue );
			TEST_METHOD( testReturnCodeRebootRequired );
			TEST_METHOD( testReturnCodeSuccess );
			TEST_METHOD( testMustReboot );
			TEST_METHOD( testLoad );
			TEST_METHOD( testWithHiddenWindow );
		};
	}
}
