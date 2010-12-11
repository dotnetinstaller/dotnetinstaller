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
			CPPUNIT_TEST( testIsOperatingSystemID );
			CPPUNIT_TEST( testIsInOperatingSystemInRange );
			CPPUNIT_TEST( testGetOperatingSystemLCID );
			CPPUNIT_TEST( testIsOperatingSystemLCID );
			CPPUNIT_TEST( testGetLocale );
			CPPUNIT_TEST( testGetISOLocale );
			CPPUNIT_TEST( testIsOperatingSystemLCIDValue );
			CPPUNIT_TEST( testCompareVersion );
			CPPUNIT_TEST( testGetProcessorArchitecture );
			CPPUNIT_TEST( testProcessorArchitectureToFromString );
			CPPUNIT_TEST( testIsProcessorArchitecture );
			CPPUNIT_TEST( testIsWow64 );
			CPPUNIT_TEST( testWow64DisableWow64FsRedirection );
			// CPPUNIT_TEST( testExistWindowsSystem );
			CPPUNIT_TEST( testwstring2lcidtype );
			CPPUNIT_TEST( testlcidtype2wstring );
			CPPUNIT_TEST( testos2wstring );
			CPPUNIT_TEST( testoscode2os );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testGetOperatingSystemVersion();
			void testGetOperatingSystemVersionString();
			void testIsOperatingSystemID();
			void testIsInOperatingSystemInRange();
			void testGetOperatingSystemLCID();
			void testIsOperatingSystemLCID();
			void testIsOperatingSystemLCIDValue();
			void testGetLocale();
			void testGetISOLocale();
			void testCompareVersion();
			void testGetProcessorArchitecture();
			void testProcessorArchitectureToFromString();
			void testIsProcessorArchitecture();
			void testIsWow64();
			void testWow64DisableWow64FsRedirection();
			void testExistWindowsSystem();
			void testwstring2lcidtype();
			void testlcidtype2wstring();
			void testos2wstring();
			void testoscode2os();
		};
	}
}
