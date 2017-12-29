#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		TEST_CLASS(PathUtilUnitTests)
		{
			TEST_METHOD( testGetFileDirectory );
			TEST_METHOD( testGetFileName );
			TEST_METHOD( testGetModuleDirectory );
			TEST_METHOD( testGetModuleFileName );
			TEST_METHOD( testDirectoryCombine );
			TEST_METHOD( testGetTemporaryDirectory );
			TEST_METHOD( testGetCurrentDirectory );
			TEST_METHOD( testGetSystemDirectory );
			TEST_METHOD( testGetWindowsDirectory );
			TEST_METHOD( testGetSystemWindowsDirectory );
			TEST_METHOD( testStripPathTerminator );
		};
	}
}
