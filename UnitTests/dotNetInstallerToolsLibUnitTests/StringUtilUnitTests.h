#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		namespace String
		{
			TEST_CLASS(StringUtilUnitTests)
			{
				TEST_METHOD( teststring2long );
				TEST_METHOD( teststring2ulong );
				TEST_METHOD( testsplitjoin );				
                TEST_METHOD( testtrim );
				TEST_METHOD( testreplace );
				TEST_METHOD( teststring2wstring );
				TEST_METHOD( testwstring2string );
				TEST_METHOD( testlong2string );
				TEST_METHOD( testlong2wstring );
				TEST_METHOD( testtostring );
				TEST_METHOD( testtowstring );
				TEST_METHOD( teststartswith );
				TEST_METHOD( testendswith );
				TEST_METHOD( testUTF82wstring );
			};
		}
	}
}
