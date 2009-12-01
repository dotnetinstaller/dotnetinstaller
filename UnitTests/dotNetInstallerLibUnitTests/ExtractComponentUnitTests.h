#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ExtractComponentUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( ExtractComponentUnitTests );
			CPPUNIT_TEST( testExtractWithoutComponentId );
			CPPUNIT_TEST( testExtractWithComponentId );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExtractWithoutComponentId();
			void testExtractWithComponentId();
		};
	}
}
