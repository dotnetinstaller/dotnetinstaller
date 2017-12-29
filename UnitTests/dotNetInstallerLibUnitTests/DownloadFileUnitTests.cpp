#include "StdAfx.h"
#include "DownloadFileUnitTests.h"
#include "DownloadCallbackImpl.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
    Assert::IsTrue(! file->IsCopyRequired());
    Assert::IsTrue(file->IsDownloadRequired());
    file->Exec(& callback);
    callback.DownloadComplete();
    std::wstring fullpath = DVLib::DirectoryCombine(file->destinationpath, file->destinationfilename);
    Assert::IsTrue(DVLib::FileExists(fullpath));
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
    Assert::IsTrue(file->IsCopyRequired());
    Assert::IsTrue(! file->IsDownloadRequired());
    file->Exec(& callback);
    callback.DownloadComplete();
    std::wstring fullpath = DVLib::DirectoryCombine(file->destinationpath, file->destinationfilename);
    Assert::IsTrue(DVLib::FileExists(fullpath));
    DVLib::FileDelete(fullpath);
}

void DownloadFileUnitTests::testClearCache()
{
    DownloadFilePtr file(new DownloadFile());
    // by default clear_cache = false
    Assert::IsTrue(! file->ClearCache());
    file->alwaysdownload = false;
    file->clear_cache = true;
    file->componentname = L"test download";
    file->sourceurl = L"file://this is a bogus url";
    file->sourcepath = DVLib::GetModuleFileNameW();
    file->destinationpath = DVLib::GetTemporaryDirectoryW();
    file->destinationfilename = DVLib::GenerateGUIDStringW();
    // file doesn't exist in cache
    Assert::IsTrue(! file->ClearCache());
}

void DownloadFileUnitTests::testDownloadCache()
{
    // test can only run online, \todo: need a local web server
    DownloadFilePtr file(new DownloadFile());
    file->alwaysdownload = false;
    file->clear_cache = true;
    file->componentname = L"test download";
    file->sourcepath = L"";
    file->sourceurl = L"http://ardownload.adobe.com/pub/adobe/reader/win/9.x/9.1/enu/AdbeRdr910_en_US_Std.exe";
    file->destinationpath = DVLib::GetTemporaryDirectoryW();
    file->destinationfilename = DVLib::GenerateGUIDStringW();
    DownloadCallbackImpl callback;
    Assert::IsTrue(! file->IsCopyRequired());
    Assert::IsTrue(file->IsDownloadRequired());
    file->Exec(& callback);
    callback.DownloadComplete();
    std::wstring fullpath = DVLib::DirectoryCombine(file->destinationpath, file->destinationfilename);
    Assert::IsTrue(DVLib::FileExists(fullpath));
    DVLib::FileDelete(fullpath);
    Assert::IsTrue(file->ClearCache());
}
