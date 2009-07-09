#include "StdAfx.h"
#include "DownloadComponentUnitTests.h"
#include "DownloadComponentCallbackImpl.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::DownloadComponentUnitTests);

using namespace DVLib::UnitTests;

void DownloadComponentUnitTests::testDownload()
{
	// download via URL
	DownloadComponentInfo info;
	info.always_download = false;
	info.component_name = L"test download";
	info.source_path = L"";
	info.source_url = L"file://" + DVLib::GetModuleFileNameW();
	info.destination_path = DVLib::GetTemporaryDirectoryW();
	info.destination_filename = DVLib::GenerateGUIDStringW();
	DownloadComponentCallbackImpl callback;
	DownloadComponent component(& callback, info);
	CPPUNIT_ASSERT(! component.IsCopyRequired());
	CPPUNIT_ASSERT(component.IsDownloadRequired());
	component.StartDownload();
	callback.DownloadComplete();
	CPPUNIT_ASSERT(! component.IsCancelled());
	std::wstring fullpath = DVLib::DirectoryCombine(info.destination_path, info.destination_filename);
	CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
	DVLib::FileDelete(fullpath);
}

void DownloadComponentUnitTests::testCopyFromSource()
{
	// download via URL
	DownloadComponentInfo info;
	info.always_download = false;
	info.component_name = L"test download";
	info.source_url = L"file://this is a bogus url";
	info.source_path = DVLib::GetModuleFileNameW();
	info.destination_path = DVLib::GetTemporaryDirectoryW();
	info.destination_filename = DVLib::GenerateGUIDStringW();
	DownloadComponentCallbackImpl callback;
	DownloadComponent component(& callback, info);
	CPPUNIT_ASSERT(component.IsCopyRequired());
	CPPUNIT_ASSERT(! component.IsDownloadRequired());
	component.CopyFromSourcePath();
	callback.DownloadComplete();
	CPPUNIT_ASSERT(! component.IsCancelled());
	std::wstring fullpath = DVLib::DirectoryCombine(info.destination_path, info.destination_filename);
	CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
	DVLib::FileDelete(fullpath);
}
