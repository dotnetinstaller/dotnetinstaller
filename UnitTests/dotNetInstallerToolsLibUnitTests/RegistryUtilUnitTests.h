#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		TEST_CLASS(RegistryUtilUnitTests)
		{
			TEST_METHOD( testHKEY2wstring );
			TEST_METHOD( testwstring2HKEY );
			TEST_METHOD( testKeyExists );
			TEST_METHOD( testValueExists );
			TEST_METHOD( testCreateDeleteKey );
			TEST_METHOD( testGetStringValue );
			TEST_METHOD( testSetStringValue );
			TEST_METHOD( testGetDWORDValue );
			TEST_METHOD( testSetDWORDValue );
			TEST_METHOD( testGetSetMultiStringValue );
			TEST_METHOD( testDeleteValue );
			TEST_METHOD( testGetValueType );
		};
	}
}
