#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class MsuComponentUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( MsuComponentUnitTests );
			CPPUNIT_TEST( testExecInstall );
			CPPUNIT_TEST( testExecUninstall );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExecInstall();
			void testExecUninstall();
		};
	}
}
