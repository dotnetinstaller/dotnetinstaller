#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ComponentsStatusUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( ComponentsStatusUnitTests );
			CPPUNIT_TEST( testEqual );
			CPPUNIT_TEST( testAll );
			CPPUNIT_TEST( testAllRequired );
			CPPUNIT_TEST( testAllOptional );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testEqual();
			void testAll();
			void testAllRequired();
			void testAllOptional();
		};
	}
}
