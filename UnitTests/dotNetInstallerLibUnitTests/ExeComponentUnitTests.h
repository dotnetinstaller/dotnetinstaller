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
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExecInstall();
			void testExecInstallResponseFile();
		};
	}
}
