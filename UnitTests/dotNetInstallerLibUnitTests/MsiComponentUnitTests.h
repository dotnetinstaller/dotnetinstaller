#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class MsiComponentUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( MsiComponentUnitTests );
			CPPUNIT_TEST( testExecInstall );
			CPPUNIT_TEST( testExecInstallSilent );
			CPPUNIT_TEST( testExecUninstall );
			CPPUNIT_TEST( testExecUninstallSilent );
			CPPUNIT_TEST( testGetCommandLine );
			CPPUNIT_TEST( testMustReboot );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExecInstall();
			void testExecInstallSilent();
			void testExecUninstall();
			void testExecUninstallSilent();
			void testGetCommandLine();
			void testMustReboot();
		};
	}
}
