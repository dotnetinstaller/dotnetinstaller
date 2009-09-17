#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class InstallerSessionUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( InstallerSessionUnitTests );
			CPPUNIT_TEST( testExpandPathVariables );
			CPPUNIT_TEST( testExpandEnvironmentVariables );
			CPPUNIT_TEST( testExpandRegistryVariables );
			CPPUNIT_TEST( testEnableRunOnReboot );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExpandPathVariables();
			void testExpandEnvironmentVariables();
			void testExpandRegistryVariables();
			void testEnableRunOnReboot();
		};
	}
}
