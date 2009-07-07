#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class OsUtilUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( OsUtilUnitTests );
			CPPUNIT_TEST( testGetOperatingSystemVersion );
			CPPUNIT_TEST( testGetOperatingSystemVersionString );
			CPPUNIT_TEST( testIsInOperatingSystemInRange );
			CPPUNIT_TEST( testGetOperatingSystemLCID );
			CPPUNIT_TEST( testIsOperatingSystemLCID );
			CPPUNIT_TEST( testCompareVersion );
			CPPUNIT_TEST( testGetProcessorArchitecture );
			CPPUNIT_TEST( testProcessorArchitectureToFromString );
			CPPUNIT_TEST( testIsProcessorArchitecture );
			CPPUNIT_TEST( testIsWow64 );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testGetOperatingSystemVersion();
			void testGetOperatingSystemVersionString();
			void testIsInOperatingSystemInRange();
			void testGetOperatingSystemLCID();
			void testIsOperatingSystemLCID();
			void testCompareVersion();
			void testGetProcessorArchitecture();
			void testProcessorArchitectureToFromString();
			void testIsProcessorArchitecture();
			void testIsWow64();
		};
	}
}
