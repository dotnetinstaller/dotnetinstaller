#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class UACElevationUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( UACElevationUnitTests );
			CPPUNIT_TEST( testIsUserInAdminGroup );
			CPPUNIT_TEST( testIsRunAsAdmin );
			CPPUNIT_TEST( testIsProcessElevated );
			CPPUNIT_TEST( testShellElevated );
			CPPUNIT_TEST( testRestartElevated );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testIsUserInAdminGroup();
			void testIsRunAsAdmin();
			void testIsProcessElevated();
			void testShellElevated();
			void testRestartElevated();
		};
	}
}
