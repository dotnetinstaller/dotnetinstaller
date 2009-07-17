#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ComponentsUnitTests :  public CPPUNIT_NS::TestFixture
		{
			CPPUNIT_TEST_SUITE( ComponentsUnitTests );
			CPPUNIT_TEST( testAdd );
			CPPUNIT_TEST( testOsFilters );
			CPPUNIT_TEST( testLcidFilters );
			CPPUNIT_TEST( testPAFilters );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testAdd();
			void testOsFilters();
			void testLcidFilters();
			void testPAFilters();
		};
	}
}
