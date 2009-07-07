#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class PathUtilUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( PathUtilUnitTests );
			CPPUNIT_TEST( testGetFileDirectory );
			CPPUNIT_TEST( testGetFileName );
			CPPUNIT_TEST( testGetModuleDirectory );
			CPPUNIT_TEST( testGetModuleFileName );
			CPPUNIT_TEST( testDirectoryCombine );
			CPPUNIT_TEST( testGetTemporaryDirectory );
			CPPUNIT_TEST( testGetCurrentDirectory );
			CPPUNIT_TEST( testGetSystemDirectory );
			CPPUNIT_TEST( testGetWindowsDirectory );
			CPPUNIT_TEST( testGetSystemWindowsDirectory );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testGetFileDirectory();
			void testGetFileName();
			void testGetModuleDirectory();
			void testGetModuleFileName();
			void testDirectoryCombine();
			void testGetTemporaryDirectory();
			void testGetCurrentDirectory();
			void testGetSystemDirectory();
			void testGetWindowsDirectory();
			void testGetSystemWindowsDirectory();
		};
	}
}
