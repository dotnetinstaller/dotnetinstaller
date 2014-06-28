#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class CmdComponentUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( CmdComponentUnitTests );
			CPPUNIT_TEST( testExecInstall );
			CPPUNIT_TEST( testExecUninstall );
			CPPUNIT_TEST( testExecUISilent );
			CPPUNIT_TEST( testExecUIBasic );
			CPPUNIT_TEST( testExecXCopy );
			CPPUNIT_TEST( testExecShell );
			CPPUNIT_TEST( testReturnCodeZero );
			CPPUNIT_TEST( testReturnCodeNone );
			CPPUNIT_TEST( testReturnCodeAll );
			CPPUNIT_TEST( testReturnCodeNonZero );
			CPPUNIT_TEST( testReturnCodeNonValue );
			CPPUNIT_TEST( testReturnCodeRebootRequired );
			CPPUNIT_TEST( testReturnCodeSuccess );
			CPPUNIT_TEST( testMustReboot );
			CPPUNIT_TEST( testLoad );
			CPPUNIT_TEST( testWithHiddenWindow );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExecInstall();
			void testExecUninstall();
			void testExecUISilent();
			void testExecUIBasic();
			void testExecXCopy();
			void testExecShell();
			void testReturnCodeZero();
			void testReturnCodeNone();
			void testReturnCodeAll();
			void testReturnCodeNonZero();
			void testReturnCodeNonValue();
			void testReturnCodeRebootRequired();
			void testReturnCodeSuccess();
			void testMustReboot();
			void testLoad();
			void testWithHiddenWindow();
		};
	}
}
