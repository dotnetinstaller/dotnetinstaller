#include "StdAfx.h"
#include "DownloadFileUnitTests.h"
#include "DownloadCallbackImpl.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::DownloadFileUnitTests);

using namespace DVLib::UnitTests;

void DownloadFileUnitTests::testDownload()
{
	// download via URL
	DownloadFilePtr file(new DownloadFile());
	file->alwaysdownload = false;
	file->componentname = L"test download";
	file->sourcepath = L"";
	file->sourceurl = L"file://" + DVLib::GetModuleFileNameW();
	file->destinationpath = DVLib::GetTemporaryDirectoryW();
	file->destinationfilename = DVLib::GenerateGUIDStringW();
	DownloadCallbackImpl callback;
	CPPUNIT_ASSERT(! file->IsCopyRequired());
	CPPUNIT_ASSERT(file->IsDownloadRequired());
	file->Exec(& callback);
	callback.DownloadComplete();
	std::wstring fullpath = DVLib::DirectoryCombine(file->destinationpath, file->destinationfilename);
	CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
	DVLib::FileDelete(fullpath);
}

void DownloadFileUnitTests::testCopyFromSource()
{
	// download via URL
	DownloadFilePtr file(new DownloadFile());
	file->alwaysdownload = false;
	file->componentname = L"test download";
	file->sourceurl = L"file://this is a bogus url";
	file->sourcepath = DVLib::GetModuleFileNameW();
	file->destinationpath = DVLib::GetTemporaryDirectoryW();
	file->destinationfilename = DVLib::GenerateGUIDStringW();
	DownloadCallbackImpl callback;
	CPPUNIT_ASSERT(file->IsCopyRequired());
	CPPUNIT_ASSERT(! file->IsDownloadRequired());
	file->Exec(& callback);
	callback.DownloadComplete();
	std::wstring fullpath = DVLib::DirectoryCombine(file->destinationpath, file->destinationfilename);
	CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
	DVLib::FileDelete(fullpath);
}

void DownloadFileUnitTests::testClearCache()
{
	DownloadFilePtr file(new DownloadFile());
	// by default clear_cache = false
	CPPUNIT_ASSERT(! file->ClearCache());
	file->alwaysdownload = false;
	file->clear_cache = true;
	file->componentname = L"test download";
	file->sourceurl = L"file://this is a bogus url";
	file->sourcepath = DVLib::GetModuleFileNameW();
	file->destinationpath = DVLib::GetTemporaryDirectoryW();
	file->destinationfilename = DVLib::GenerateGUIDStringW();
	// file doesn't exist in cache
	CPPUNIT_ASSERT(! file->ClearCache());
}

void DownloadFileUnitTests::testDownloadCache()
{
	DownloadFilePtr file(new DownloadFile());
	file->alwaysdownload = false;
	file->clear_cache = true;
	file->componentname = L"test download";
	file->sourcepath = L"";
	file->sourceurl = L"http://ardownload.adobe.com/pub/adobe/reader/win/9.x/9.1/enu/AdbeRdr910_en_US_Std.exe";
	file->destinationpath = DVLib::GetTemporaryDirectoryW();
	file->destinationfilename = DVLib::GenerateGUIDStringW();
	DownloadCallbackImpl callback;
	CPPUNIT_ASSERT(! file->IsCopyRequired());
	CPPUNIT_ASSERT(file->IsDownloadRequired());
	file->Exec(& callback);
	callback.DownloadComplete();
	std::wstring fullpath = DVLib::DirectoryCombine(file->destinationpath, file->destinationfilename);
	CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
	DVLib::FileDelete(fullpath);
	CPPUNIT_ASSERT(file->ClearCache());
}
