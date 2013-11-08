#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class MsuComponentUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( MsuComponentUnitTests );
			CPPUNIT_TEST( testExecInstall );
			CPPUNIT_TEST( testExecInstallSilent );
			CPPUNIT_TEST( testExecUninstall );
			CPPUNIT_TEST( testExecUninstallSilent );
			CPPUNIT_TEST( testExecShell );
			CPPUNIT_TEST( testMustReboot );
			CPPUNIT_TEST( testLoad );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExecInstall();
			void testExecInstallSilent();
			void testExecUninstall();
			void testExecUninstallSilent();
			void testExecShell();
			void testMustReboot();
			void testLoad();
		};
	}
}
