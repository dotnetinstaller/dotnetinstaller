#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class InstallUILevelUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( InstallUILevelUnitTests );
			CPPUNIT_TEST( testGetCommand );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testGetCommand();
		};
	}
}
