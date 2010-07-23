#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class InstallerCommandLineInfoUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( InstallerCommandLineInfoUnitTests );
			CPPUNIT_TEST( testGetCmd );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testGetCmd();
		private:
			void ParseCommandLineInfo(int argc, wchar_t ** argv, CCommandLineInfo& cmdinfo);
		};
	}
}
