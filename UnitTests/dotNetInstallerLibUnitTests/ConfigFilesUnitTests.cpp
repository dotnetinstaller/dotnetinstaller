#include "StdAfx.h"
#include "ConfigFilesUnitTests.h"
#include "ConfigFilesImpl.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ConfigFilesUnitTests);

using namespace DVLib::UnitTests;

void ConfigFilesUnitTests::testSaveRestoreAppState()
{
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