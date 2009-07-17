#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class MsuComponentUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( MsuComponentUnitTests );
			CPPUNIT_TEST( testExec );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExec();
		};
	}
}
