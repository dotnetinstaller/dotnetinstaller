#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class InstallerSessionUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( InstallerSessionUnitTests );
			CPPUNIT_TEST( testExpandVariables );
			CPPUNIT_TEST( testExpandPathVariables );
			CPPUNIT_TEST( testExpandEnvironmentVariables );
			CPPUNIT_TEST( testExpandRegistryVariables );
			CPPUNIT_TEST( testExpandRegistryVariable );
			CPPUNIT_TEST( testExpandUserVariables );
			CPPUNIT_TEST( testGetRebootCmd );
			CPPUNIT_TEST( testEnableRunOnReboot );
			CPPUNIT_TEST( testExpandPathVariablesBackslashes );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExpandVariables();
			void testExpandPathVariablesBackslashes();
			void testExpandPathVariables();
			void testExpandEnvironmentVariables();
			void testExpandRegistryVariables();
			void testExpandRegistryVariable();
			void testEnableRunOnReboot();
			void testGetRebootCmd();
			void testExpandUserVariables();
		};
	}
}
