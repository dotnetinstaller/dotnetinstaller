#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ComponentUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( ComponentUnitTests );
			CPPUNIT_TEST( testGetDisplayName );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testGetDisplayName();
		};
	}
}
