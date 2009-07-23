#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class InstalledCheckFileUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( InstalledCheckFileUnitTests );
			CPPUNIT_TEST( testIsInstalled );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testIsInstalled();
		};
	}
}
