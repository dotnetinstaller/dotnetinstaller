#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		TEST_CLASS(ShellUtilUnitTests)
		{
			TEST_METHOD( testGetEnvironmentVariable );
			TEST_METHOD( testExpandEnvironmentVariables );
			TEST_METHOD( testDetachCmd );
			TEST_METHOD( testRunCmd );
			TEST_METHOD( testExecCmd );
			TEST_METHOD( testShellCmd );
			TEST_METHOD( testRunCmdWithHiddenWindow );
			TEST_METHOD( testShellCmdWithHiddenWindow );
			TEST_METHOD( testRunCmdWithoutWorkingDirectorySpecified );
			TEST_METHOD( testRunCmdWithWorkingDirectorySpecified );
			TEST_METHOD( testShellCmdWithoutWorkingDirectorySpecified );
			TEST_METHOD( testShellCmdWithWorkingDirectorySpecified );
		};
	}
}
