#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class OpenFileComponentUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( OpenFileComponentUnitTests );
			CPPUNIT_TEST( testExec );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExec();
		};
	}
}
