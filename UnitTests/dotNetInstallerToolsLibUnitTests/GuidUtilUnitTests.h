#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class GuidUtilUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( GuidUtilUnitTests );
			CPPUNIT_TEST( testStringFromGUID2 );
			CPPUNIT_TEST( testGenerateGUIDString );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testStringFromGUID2();
			void testGenerateGUIDString();
		};
	}
}
