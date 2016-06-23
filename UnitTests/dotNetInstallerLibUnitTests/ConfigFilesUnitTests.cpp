#include "StdAfx.h"
#include "ConfigFilesUnitTests.h"
#include "ConfigFilesImpl.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ConfigFilesUnitTests);

using namespace DVLib::UnitTests;

void ConfigFilesUnitTests::testSaveRestoreAppState()
{
    InstallUILevelState state;
    ConfigFilesImpl cf;
    InstallUILevelSetting::Instance->SetConfigLevel(InstallUILevelNotSet);
    // from not set to set
    cf.SaveAppState();
    InstallUILevelSetting::Instance->SetConfigLevel(InstallUILevelBasic);
    CPPUNIT_ASSERT(InstallUILevelBasic == InstallUILevelSetting::Instance->GetUILevel());
    cf.RestoreAppState();
    // default is full ui mode
    CPPUNIT_ASSERT(InstallUILevelFull == InstallUILevelSetting::Instance->GetUILevel());
    // from set to set
    InstallUILevelSetting::Instance->SetConfigLevel(InstallUILevelBasic);
    cf.SaveAppState();
    InstallUILevelSetting::Instance->SetConfigLevel(InstallUILevelSilent);
    cf.RestoreAppState();
    CPPUNIT_ASSERT(InstallUILevelBasic == InstallUILevelSetting::Instance->GetUILevel());
}

void ConfigFilesUnitTests::testLoad()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\PackagedSetup\\Configuration.xml");
    CPPUNIT_ASSERT(DVLib::FileExists(configxml));
    ConfigFilesImpl cf(configxml);
    cf.Load();
    CPPUNIT_ASSERT(cf.IsLoaded());
}

void ConfigFilesUnitTests::testDownload()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\ReferenceSetup\\Configuration.xml");
    ConfigFilesImpl cf(configxml);
    // reference setup will fail a download
    try
    {
        cf.Load();
        throw "expected std::exception";
    }
    catch(std::exception&)
    {

    }

    CPPUNIT_ASSERT(cf.GetDownloads() == 1);
    CPPUNIT_ASSERT(cf.GetRuns() == 0);
}

void ConfigFilesUnitTests::testRun()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\PackagedSetup\\Configuration.xml");
    CPPUNIT_ASSERT(DVLib::FileExists(configxml));
    ConfigFilesImpl cf(configxml);
    cf.Load();
    CPPUNIT_ASSERT(cf.IsLoaded());
    cf.Run();
    CPPUNIT_ASSERT(cf.GetDownloads() == 0);
    CPPUNIT_ASSERT(cf.GetRuns() == 1);
}

void ConfigFilesUnitTests::testSelectLanguageNoSelection()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
    CPPUNIT_ASSERT(DVLib::FileExists(configxml));
    ConfigFilesImpl cf(configxml);
    cf.Load();
    CPPUNIT_ASSERT(cf.IsLoaded());
    // only one configuration out of the two opposite locales is loaded
    CPPUNIT_ASSERT(cf.size() == 1);
    CPPUNIT_ASSERT(cf[0]->lcid_filter == L"!1040");
}

void ConfigFilesUnitTests::testSelectLanguage1040()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
    CPPUNIT_ASSERT(DVLib::FileExists(configxml));
    InstallerSession::Instance->languageid = 1040;
    ConfigFilesImpl cf(configxml);
    cf.Load();
    CPPUNIT_ASSERT(cf.IsLoaded());
    // only one configuration out of the two opposite locales is loaded
    CPPUNIT_ASSERT(cf.size() == 1);
    CPPUNIT_ASSERT(cf[0]->lcid_filter == L"1040");
}

void ConfigFilesUnitTests::testSelectLanguageNot1040()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
    CPPUNIT_ASSERT(DVLib::FileExists(configxml));
    InstallerSession::Instance->languageid = 1041;
    ConfigFilesImpl cf(configxml);
    cf.Load();
    CPPUNIT_ASSERT(cf.IsLoaded());
    // only one configuration out of the two opposite locales is loaded
    CPPUNIT_ASSERT(cf.size() == 1);
    CPPUNIT_ASSERT(cf[0]->lcid_filter == L"!1040");
}

void ConfigFilesUnitTests::testSelectLanguageCancelled()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
    CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFilesImpl cf(configxml);
	cf.SetLanguageSelectionCancelled();
    cf.Load();
    CPPUNIT_ASSERT(cf.IsLoaded());
	// no one configuration is loaded because language selection was cancelled
	CPPUNIT_ASSERT(cf.size() == 0);
}

void ConfigFilesUnitTests::testGetLanguages()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
    CPPUNIT_ASSERT(DVLib::FileExists(configxml));
    ConfigFilesImpl cf(configxml);
    cf.Load();
    CPPUNIT_ASSERT(cf.IsLoaded());
    // only one configuration out of the two opposite locales is loaded
    std::vector<std::wstring> config_languages = cf.GetConfigLanguages();
    CPPUNIT_ASSERT(config_languages.size() == 2);
    std::wcout << std::endl << L"Language: " << config_languages[0];
    CPPUNIT_ASSERT(config_languages[0] == L"English");
    std::vector<std::wstring> supported_languages = cf.GetLanguages();
    CPPUNIT_ASSERT(supported_languages.size() == 1);
}

void ConfigFilesUnitTests::testNoMatchingConfiguration()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\Invalid\\NoMatchingOSFilter.xml");
    CPPUNIT_ASSERT(DVLib::FileExists(configxml));
    ConfigFilesImpl cf(configxml);
    try
    {
        cf.Load();
        throw "expected std::exception";
    }
    catch(std::exception& ex)
    {
        std::cout << std::endl << "Expected exception: [" << ex.what() << "]";
        CPPUNIT_ASSERT(0 == strcmp(ex.what(), "Expected error: no match in 1 setup configuration(s)."));
    }
}
