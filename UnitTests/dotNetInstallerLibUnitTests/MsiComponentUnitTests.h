#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class MsiComponentUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( MsiComponentUnitTests );
			CPPUNIT_TEST( testExec );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExec();
		};
	}
}
