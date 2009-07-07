#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ExceptionMacrosUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( ExceptionMacrosUnitTests );
			CPPUNIT_TEST( testCHECK_WIN32_DWORD );
			CPPUNIT_TEST( testCHECK_WIN32_BOOL );
			CPPUNIT_TEST( testCHECK_BOOL );
			CPPUNIT_TEST( testTHROW_EX );
			CPPUNIT_TEST( testCHECK_HR );
			CPPUNIT_TEST( testCHECK_HR_DLL );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testCHECK_WIN32_DWORD();
			void testCHECK_WIN32_BOOL();
			void testCHECK_BOOL();
			void testTHROW_EX();
			void testCHECK_HR();
			void testCHECK_HR_DLL();
		};
	}
}
