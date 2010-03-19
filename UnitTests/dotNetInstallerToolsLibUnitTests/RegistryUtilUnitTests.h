#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class RegistryUtilUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( RegistryUtilUnitTests );
			CPPUNIT_TEST( testHKEY2wstring );
			CPPUNIT_TEST( testwstring2HKEY );
			CPPUNIT_TEST( testKeyExists );
			CPPUNIT_TEST( testValueExists );
			CPPUNIT_TEST( testCreateDeleteKey );
			CPPUNIT_TEST( testGetStringValue );
			CPPUNIT_TEST( testSetStringValue );
			CPPUNIT_TEST( testGetDWORDValue );
			CPPUNIT_TEST( testSetDWORDValue );
			CPPUNIT_TEST( testGetSetMultiStringValue );
			CPPUNIT_TEST( testDeleteValue );
			CPPUNIT_TEST( testGetValueType );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testKeyExists();
			void testValueExists();
			void testSetStringValue();
			void testGetStringValue();
			void testSetDWORDValue();
			void testGetDWORDValue();
			void testGetSetMultiStringValue();
			void testCreateDeleteKey();
			void testDeleteValue();
			void testHKEY2wstring();
			void testwstring2HKEY();
			void testGetValueType();
		};
	}
}
