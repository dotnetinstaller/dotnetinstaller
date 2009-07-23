#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ExtractComponentUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( ExtractComponentUnitTests );
			CPPUNIT_TEST( testExtract );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testExtract();
		};
	}
}
