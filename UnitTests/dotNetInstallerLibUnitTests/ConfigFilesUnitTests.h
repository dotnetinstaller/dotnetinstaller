#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class ConfigFilesUnitTests : public dotNetInstallerLibUnitTestFixture
		{
			CPPUNIT_TEST_SUITE( ConfigFilesUnitTests );
			CPPUNIT_TEST( testSaveRestoreAppState );
			CPPUNIT_TEST( testLoad );
			CPPUNIT_TEST( testDownload );
			CPPUNIT_TEST( testRun );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testSaveRestoreAppState();
			void testLoad();
			void testDownload();
			void testRun();
		};
	}
}
