#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class GuidUtilUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( GuidUtilUnitTests );
			CPPUNIT_TEST( testguid2wstring );
			CPPUNIT_TEST( testisguid );
			CPPUNIT_TEST( testmakeguid );
			CPPUNIT_TEST( testGenerateGUIDString );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testguid2wstring();
			void testisguid();
			void testGenerateGUIDString();
			void testmakeguid();
		};
	}
}
