#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ThreadComponentUnitTests : public dotNetInstallerLibUnitTestFixture
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
