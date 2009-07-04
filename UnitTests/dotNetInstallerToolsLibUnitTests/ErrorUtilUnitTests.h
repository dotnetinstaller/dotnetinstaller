#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ErrorUtilUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( ErrorUtilUnitTests );
			CPPUNIT_TEST( testDWORD );
			CPPUNIT_TEST( testGetLastError );
			CPPUNIT_TEST( testHRESULT );
			CPPUNIT_TEST( testGetLastErrorComposite );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testDWORD();
			void testGetLastError();
			void testHRESULT();
			void testGetLastErrorComposite();
		};
	}
}
