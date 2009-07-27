#include "StdAfx.h"
#include "DownloadComponentUnitTests.h"
#include "DownloadComponentCallbackImpl.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::DownloadComponentUnitTests);

using namespace DVLib::UnitTests;

void DownloadComponentUnitTests::testDownload()
{
	// download via URL
	DownloadComponentInfoPtr info(new DownloadComponentInfo());
	info->alwaysdownload = false;
	info->componentname = L"test download";
	info->sourcepath = L"";
	info->sourceurl = L"file://" + DVLib::GetModuleFileNameW();
	info->destinationpath = DVLib::GetTemporaryDirectoryW();
	info->destinationfilename = DVLib::GenerateGUIDStringW();
	DownloadComponentCallbackImpl callback;
	DownloadComponent component(& callback, info);
	CPPUNIT_ASSERT(! component.IsCopyRequired());
	CPPUNIT_ASSERT(component.IsDownloadRequired());
	component.Exec();
	callback.DownloadComplete();
	std::wstring fullpath = DVLib::DirectoryCombine(info->destinationpath, info->destinationfilename);
	CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
	DVLib::FileDelete(fullpath);
}

void DownloadComponentUnitTests::testCopyFromSource()
{
	// download via URL
	DownloadComponentInfoPtr info(new DownloadComponentInfo());
	info->alwaysdownload = false;
	info->componentname = L"test download";
	info->sourceurl = L"file://this is a bogus url";
	info->sourcepath = DVLib::GetModuleFileNameW();
	info->destinationpath = DVLib::GetTemporaryDirectoryW();
	info->destinationfilename = DVLib::GenerateGUIDStringW();
	DownloadComponentCallbackImpl callback;
	DownloadComponent component(& callback, info);
	CPPUNIT_ASSERT(component.IsCopyRequired());
	CPPUNIT_ASSERT(! component.IsDownloadRequired());
	component.Exec();
	callback.DownloadComplete();
	std::wstring fullpath = DVLib::DirectoryCombine(info->destinationpath, info->destinationfilename);
	CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
	DVLib::FileDelete(fullpath);
}
