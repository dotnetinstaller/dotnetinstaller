#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class XmlAttributeUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( XmlAttributeUnitTests );
			CPPUNIT_TEST( testEmpty );
			CPPUNIT_TEST( testGetValue );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testEmpty();
			void testGetValue();
		};
	}
}
