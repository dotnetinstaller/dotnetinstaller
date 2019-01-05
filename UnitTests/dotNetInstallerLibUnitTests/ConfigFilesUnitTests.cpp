#include "StdAfx.h"
#include "ConfigFilesUnitTests.h"
#include "ConfigFilesImpl.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ConfigFilesUnitTests::testSaveRestoreAppState()
{
    InstallUILevelState state;
    ConfigFilesImpl cf;
    InstallUILevelSetting::Instance->SetConfigLevel(InstallUILevelNotSet);
    // from not set to set
    cf.SaveAppState();
    InstallUILevelSetting::Instance->SetConfigLevel(InstallUILevelBasic);
    Assert::IsTrue(InstallUILevelBasic == InstallUILevelSetting::Instance->GetUILevel());
    cf.RestoreAppState();
    // default is full ui mode
    Assert::IsTrue(InstallUILevelFull == InstallUILevelSetting::Instance->GetUILevel());
    // from set to set
    InstallUILevelSetting::Instance->SetConfigLevel(InstallUILevelBasic);
    cf.SaveAppState();
    InstallUILevelSetting::Instance->SetConfigLevel(InstallUILevelSilent);
    cf.RestoreAppState();
    Assert::IsTrue(InstallUILevelBasic == InstallUILevelSetting::Instance->GetUILevel());
}

void ConfigFilesUnitTests::testLoad()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(),
        L"..\\..\\..\\Samples\\PackagedSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFilesImpl cf(configxml);
    cf.Load();
    Assert::IsTrue(cf.IsLoaded());
}

void ConfigFilesUnitTests::testDownload()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
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

    Assert::IsTrue(cf.GetDownloads() == 1);
    Assert::IsTrue(cf.GetRuns() == 0);
}

void ConfigFilesUnitTests::testRun()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\PackagedSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFilesImpl cf(configxml);
    cf.Load();
    Assert::IsTrue(cf.IsLoaded());
    cf.Run();
    Assert::IsTrue(cf.GetDownloads() == 0);
    Assert::IsTrue(cf.GetRuns() == 1);
}

void ConfigFilesUnitTests::testSelectLanguageNoSelection()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFilesImpl cf(configxml);
    cf.Load();
    Assert::IsTrue(cf.IsLoaded());
    // only one configuration out of the two opposite locales is loaded
    Assert::IsTrue(cf.size() == 1);
    Assert::IsTrue(cf[0]->lcid_filter == L"!1040");
}

void ConfigFilesUnitTests::testSelectLanguage1040()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    InstallerSession::Instance->languageid = 1040;
    ConfigFilesImpl cf(configxml);
    cf.Load();
    Assert::IsTrue(cf.IsLoaded());
    // only one configuration out of the two opposite locales is loaded
    Assert::IsTrue(cf.size() == 1);
    Assert::IsTrue(cf[0]->lcid_filter == L"1040");
}

void ConfigFilesUnitTests::testSelectLanguageNot1040()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    InstallerSession::Instance->languageid = 1041;
    ConfigFilesImpl cf(configxml);
    cf.Load();
    Assert::IsTrue(cf.IsLoaded());
    // only one configuration out of the two opposite locales is loaded
    Assert::IsTrue(cf.size() == 1);
    Assert::IsTrue(cf[0]->lcid_filter == L"!1040");
}

void ConfigFilesUnitTests::testSelectLanguageCancelled()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFilesImpl cf(configxml);
    cf.SetLanguageSelectionCancelled();
    cf.Load();
    Assert::IsTrue(cf.IsLoaded());
    // no one configuration is loaded because language selection was cancelled
    Assert::IsTrue(cf.size() == 0);
}

void ConfigFilesUnitTests::testGetLanguages()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFilesImpl cf(configxml);
    cf.Load();
    Assert::IsTrue(cf.IsLoaded());
    // only one configuration out of the two opposite locales is loaded
    std::vector<std::wstring> config_languages = cf.GetConfigLanguages();
    Assert::IsTrue(config_languages.size() == 2);
    std::wcout << std::endl << L"Language: " << config_languages[0];
    Assert::IsTrue(config_languages[0] == L"English");
    std::vector<std::wstring> supported_languages = cf.GetLanguages();
    Assert::IsTrue(supported_languages.size() == 1);
}

void ConfigFilesUnitTests::testNoMatchingConfiguration()
{
    std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), 
        L"..\\..\\..\\Samples\\Invalid\\NoMatchingOSFilter.xml");
    Assert::IsTrue(DVLib::FileExists(configxml));
    ConfigFilesImpl cf(configxml);
    try
    {
        cf.Load();
        throw "expected std::exception";
    }
    catch(std::exception& ex)
    {
        Assert::AreEqual("Expected error: no match in 1 setup configuration(s).", ex.what());
    }
}
