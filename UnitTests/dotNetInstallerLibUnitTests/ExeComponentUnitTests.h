#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ExeComponentUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( ExeComponentUnitTests );
			CPPUNIT_TEST( testExecInstall );
			CPPUNIT_TEST( testExecInstallResponseFile );
			CPPUNIT_TEST( testExecInstallDir );
			CPPUNIT_TEST( testExecShell );
			CPPUNIT_TEST( testMustReboot );
			CPPUNIT_TEST( testReturnCodeRebootRequired );
			CPPUNIT_TEST( testReturnCodeSuccess );
			CPPUNIT_TEST( testLoad );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExecInstall();
			void testExecInstallResponseFile();
			void testExecInstallDir();
			void testExecShell();
			void testMustReboot();
			void testReturnCodeRebootRequired();
			void testReturnCodeSuccess();
			void testLoad();
		};
	}
}
