#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(ExceptionMacrosUnitTests)
		{
			TEST_METHOD( testCHECK_WIN32_DWORD );
			TEST_METHOD( testCHECK_WIN32_BOOL );
			TEST_METHOD( testCHECK_BOOL );
			TEST_METHOD( testTHROW_EX );
			TEST_METHOD( testCHECK_HR );
			TEST_METHOD( testCHECK_HR_DLL );
		};
	}
}
