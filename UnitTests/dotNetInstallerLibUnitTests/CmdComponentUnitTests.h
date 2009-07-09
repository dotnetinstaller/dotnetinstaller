#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class CmdComponentUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( CmdComponentUnitTests );
			CPPUNIT_TEST( testExec );
			CPPUNIT_TEST( testExecUISilent );
			CPPUNIT_TEST( testExecUIBasic );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExec();
			void testExecUISilent();
			void testExecUIBasic();
		};
	}
}
