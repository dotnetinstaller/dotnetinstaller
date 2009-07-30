#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class MsiComponentUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( MsiComponentUnitTests );
			CPPUNIT_TEST( testExec );
			CPPUNIT_TEST( testGetCommandLine );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExec();
			void testGetCommandLine();
		};
	}
}
