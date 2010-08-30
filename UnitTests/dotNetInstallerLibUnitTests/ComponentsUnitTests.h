#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ComponentsUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( ComponentsUnitTests );
			CPPUNIT_TEST( testAdd );
			CPPUNIT_TEST( testOsFilters );
			CPPUNIT_TEST( testLcidFilters );
			CPPUNIT_TEST( testPAFilters );
			CPPUNIT_TEST( testExecNoCallback );
			CPPUNIT_TEST( testExecWithCallback );
			CPPUNIT_TEST( testExecWithError );
			CPPUNIT_TEST( testLoadUninstallSequence );
			CPPUNIT_TEST( testSequenceInstalled );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testAdd();
			void testOsFilters();
			void testOsFiltersGreaterSmaller();
			void testLcidFilters();
			void testPAFilters();
			void testExecNoCallback();
			void testExecWithCallback();
			void testExecWithError();
			void testLoadUninstallSequence();
			void testSequenceInstalled();
		};
	}
}
