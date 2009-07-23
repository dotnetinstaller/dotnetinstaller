#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class InstalledCheckDirectoryUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( InstalledCheckDirectoryUnitTests );
			CPPUNIT_TEST( testIsInstalled );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testIsInstalled();
		};
	}
}
