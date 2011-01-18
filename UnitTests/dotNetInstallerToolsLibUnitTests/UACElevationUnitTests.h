#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class UACElevationUnitTests : public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( UACElevationUnitTests );
			CPPUNIT_TEST( testIsUserInAdminGroup );
			CPPUNIT_TEST( testIsRunAsAdmin );
			CPPUNIT_TEST( testIsProcessElevated );
			CPPUNIT_TEST( testShellElevated );
			CPPUNIT_TEST( testRestartElevated );
			CPPUNIT_TEST( testIsElevationSupported );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testIsUserInAdminGroup();
			void testIsRunAsAdmin();
			void testIsProcessElevated();
			void testShellElevated();
			void testRestartElevated();
			void testIsElevationSupported();
		};
	}
}
