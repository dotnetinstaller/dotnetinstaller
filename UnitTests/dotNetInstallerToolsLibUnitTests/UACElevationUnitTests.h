#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(UACElevationUnitTests)
		{
			TEST_METHOD( testIsUserInAdminGroup );
			TEST_METHOD( testIsRunAsAdmin );
			TEST_METHOD( testIsProcessElevated );
			TEST_METHOD( testShellElevated );
			TEST_METHOD( testRestartElevated );
			TEST_METHOD( testIsElevationSupported );
		};
	}
}
