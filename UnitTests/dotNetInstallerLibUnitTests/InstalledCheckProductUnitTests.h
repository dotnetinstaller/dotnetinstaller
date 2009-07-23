#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class InstalledCheckProductUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( InstalledCheckProductUnitTests );
			CPPUNIT_TEST( testProductCode );
			CPPUNIT_TEST( testUpgradeCode );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testProductCode();
			void testUpgradeCode();
		};
	}
}
