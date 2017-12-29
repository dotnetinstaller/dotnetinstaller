#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
        TEST_CLASS(ErrorUtilUnitTests)
		{
			TEST_METHOD( testDWORD );
			TEST_METHOD( testGetLastError );
			TEST_METHOD( testHRESULT );
			TEST_METHOD( testGetLastErrorComposite );
		};
	}
}
