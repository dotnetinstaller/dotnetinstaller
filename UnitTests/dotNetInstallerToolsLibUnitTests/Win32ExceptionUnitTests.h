#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		namespace Exceptions
		{
			class Win32ExceptionUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( Win32ExceptionUnitTests );
				CPPUNIT_TEST( testDWORD );
				CPPUNIT_TEST( testGetLastError );
				CPPUNIT_TEST( testHRESULT );
				CPPUNIT_TEST( testGetLastErrorComposite );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testDWORD();
				void testGetLastError();
				void testHRESULT();
				void testGetLastErrorComposite();
			};
		}
	}
}
