#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ThreadComponentUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( ThreadComponentUnitTests );
			CPPUNIT_TEST( testExec );
			CPPUNIT_TEST( testExecWithError );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExec();
			void testExecWithError();
		};
	}
}
