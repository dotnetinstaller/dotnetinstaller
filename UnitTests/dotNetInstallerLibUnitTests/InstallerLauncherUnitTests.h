#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class InstallerLauncherUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( InstallerLauncherUnitTests );
			CPPUNIT_TEST( testGetLauncherCmd );
			CPPUNIT_TEST_SUITE_END();
		public:
			void setUp();
			void tearDown();
			void testGetLauncherCmd();
		};
	}
}
