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
			CPPUNIT_TEST( testSelectLanguageNoSelection );
			CPPUNIT_TEST( testSelectLanguage1040 );
			CPPUNIT_TEST( testSelectLanguageNot1040 );
			CPPUNIT_TEST( testSelectLanguageCancelled );
			CPPUNIT_TEST( testGetLanguages );
			CPPUNIT_TEST( testNoMatchingConfiguration );
			CPPUNIT_TEST_SUITE_END();
		public:
			void testSaveRestoreAppState();
			void testLoad();
			void testDownload();
			void testRun();
			void testSelectLanguageNoSelection();
			void testSelectLanguage1040();
			void testSelectLanguageNot1040();
			void testSelectLanguageCancelled();
			void testGetLanguages();
			void testNoMatchingConfiguration();
		};
	}
}
