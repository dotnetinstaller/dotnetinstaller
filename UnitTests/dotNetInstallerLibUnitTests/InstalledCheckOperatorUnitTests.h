#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class InstalledCheckOperatorUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( InstalledCheckOperatorUnitTests );
			CPPUNIT_TEST( testAnd );
			CPPUNIT_TEST( testOr );
			CPPUNIT_TEST( testNot );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testAnd();
			void testOr();
			void testNot();
		};
	}
}
