#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class InstallerLauncherUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( InstallerLauncherUnitTests );
			CPPUNIT_TEST( testGetCmd );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testGetCmd();
		};
	}
}
