#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class FunctionUtilUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( FunctionUtilUnitTests );
			CPPUNIT_TEST( testDllFunctionExists );
			CPPUNIT_TEST( testDllFunctionDoesntExist );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testDllFunctionExists();
			void testDllFunctionDoesntExist();
		};
	}
}
