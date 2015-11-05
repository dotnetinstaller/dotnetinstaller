#include "StdAfx.h"
#include "DownloadDialogUnitTests.h"
#include "DownloadCallbackImpl.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::DownloadDialogUnitTests);

using namespace DVLib::UnitTests;

void DownloadDialogUnitTests::testIsCopyDownloadRequiredEmpty()
{
    DownloadDialog dd;
    // empty dd, no copy required, but download is
    CPPUNIT_ASSERT(! dd.IsCopyRequired());
    CPPUNIT_ASSERT(! dd.IsDownloadRequired());	
}

void DownloadDialogUnitTests::testIsCopyDownloadRequired()
{
    DownloadFilePtr c(new DownloadFile());
    c->alwaysdownload = false;
    c->sourceurl = L"http://download.microsoft.com/download/5/6/7/567758a3-759e-473e-bf8f-52154438565a/dotnetfx.exe";
    DownloadDialog dd;
    dd.downloadfiles.push_back(c);
    // component with no source path
    CPPUNIT_ASSERT(! dd.IsCopyRequired());	
    CPPUNIT_ASSERT(dd.IsDownloadRequired());
    // component with both source and destination path, source path must exist
    c->sourcepath = DVLib::GetModuleFileNameW();
    CPPUNIT_ASSERT(dd.IsCopyRequired());
    CPPUNIT_ASSERT(! dd.IsDownloadRequired());
    DownloadFilePtr c2(new DownloadFile());	
    dd.downloadfiles.push_back(c2);
    c2->alwaysdownload = true;
    c2->sourceurl = L"http://download.microsoft.com/download/5/6/7/567758a3-759e-473e-bf8f-52154438565a/dotnetfx.exe";
    CPPUNIT_ASSERT(dd.IsCopyRequired());
    CPPUNIT_ASSERT(dd.IsDownloadRequired());
}

void DownloadDialogUnitTests::testDownload()
{
    // download via URL
    DownloadFilePtr info(new DownloadFile());
    info->alwaysdownload = false;
    info->componentname = L"test download";
    info->sourcepath = L"";
    info->sourceurl = L"file://" + DVLib::GetModuleFileNameW();
    info->destinationpath = DVLib::GetTemporaryDirectoryW();
    info->destinationfilename = DVLib::GenerateGUIDStringW();
    DownloadCallbackImpl callback;
    DownloadDialog dd;
    dd.callback = & callback;
    dd.downloadfiles.push_back(info);
    dd.Exec();
    std::wstring fullpath = DVLib::DirectoryCombine(info->destinationpath, info->destinationfilename);
    CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
    DVLib::FileDelete(fullpath);
}

void DownloadDialogUnitTests::testCopyFromSource()
{
    // download via URL
    DownloadFilePtr info(new DownloadFile());
    info->alwaysdownload = false;
    info->componentname = L"test download";
    info->sourceurl = L"file://this is a bogus url";
    info->sourcepath = DVLib::GetModuleFileNameW();
    info->destinationpath = DVLib::GetTemporaryDirectoryW();
    info->destinationfilename = DVLib::GenerateGUIDStringW();
    DownloadCallbackImpl callback;
    DownloadDialog dd;
    dd.callback = & callback;
    dd.downloadfiles.push_back(info);
    dd.Exec();
    std::wstring fullpath = DVLib::DirectoryCombine(info->destinationpath, info->destinationfilename);
    CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
    DVLib::FileDelete(fullpath);
}

void DownloadDialogUnitTests::testDownloadMultiple()
{
    // component 1
    DownloadFilePtr info1(new DownloadFile());
    info1->alwaysdownload = false;
    info1->componentname = L"test download (1)";
    info1->sourcepath = L"";
    info1->sourceurl = L"file://" + DVLib::GetModuleFileNameW();
    info1->destinationpath = DVLib::GetTemporaryDirectoryW();
    info1->destinationfilename = DVLib::GenerateGUIDStringW();
    // component 2
    DownloadFilePtr info2(new DownloadFile());
    info2->alwaysdownload = false;
    info2->componentname = L"test download (2)";
    info2->sourcepath = L"";
    info2->sourceurl = L"file://" + DVLib::GetModuleFileNameW();
    info2->destinationpath = DVLib::GetTemporaryDirectoryW();
    info2->destinationfilename = DVLib::GenerateGUIDStringW();
    // download
    DownloadCallbackImpl callback;
    DownloadDialog dd;
    dd.callback = & callback;
    dd.downloadfiles.push_back(info1);
    dd.downloadfiles.push_back(info2);
    dd.Exec();
    std::wcout << std::endl << L"Complete count: " << callback.GetCompleteCount();
    CPPUNIT_ASSERT(1 == callback.GetCompleteCount());
    std::wstring fullpath1 = DVLib::DirectoryCombine(info1->destinationpath, info1->destinationfilename);
    CPPUNIT_ASSERT(DVLib::FileExists(fullpath1));
    DVLib::FileDelete(fullpath1);
    std::wstring fullpath2 = DVLib::DirectoryCombine(info2->destinationpath, info2->destinationfilename);
    CPPUNIT_ASSERT(DVLib::FileExists(fullpath2));
    DVLib::FileDelete(fullpath2);
}

void DownloadDialogUnitTests::testDownloadMultipleError()
{
    // component 1
    DownloadFilePtr info1(new DownloadFile());
    info1->alwaysdownload = false;
    info1->componentname = L"test download (1)";
    info1->sourcepath = L"";
    info1->sourceurl = L"file://" + DVLib::GenerateGUIDStringW();
    info1->destinationpath = DVLib::GetTemporaryDirectoryW();
    info1->destinationfilename = DVLib::GenerateGUIDStringW();
    // component 2
    DownloadFilePtr info2(new DownloadFile());
    info2->alwaysdownload = false;
    info2->componentname = L"test download (2)";
    info2->sourcepath = L"";
    info2->sourceurl = L"file://" + DVLib::GenerateGUIDStringW();
    info2->destinationpath = DVLib::GetTemporaryDirectoryW();
    info2->destinationfilename = DVLib::GenerateGUIDStringW();
    // download
    DownloadCallbackImpl callback;
    DownloadDialog dd;
    dd.callback = & callback;
    dd.downloadfiles.push_back(info1);
    dd.downloadfiles.push_back(info2);

    try
    {
        dd.Exec();
        throw "expected std::exception";
    }
    catch(std::exception&)
    {

    }

    CPPUNIT_ASSERT(1 == callback.GetErrorCount());
}

void DownloadDialogUnitTests::testShowDialogOnDownloadFile()
{
    // download via URL
    DownloadFilePtr info(new DownloadFile());
    info->alwaysdownload = false;
    info->componentname = L"test download";
    info->sourcepath = L"";
    info->sourceurl = L"file://" + DVLib::GetModuleFileNameW();
    info->destinationpath = DVLib::GetTemporaryDirectoryW();
    info->destinationfilename = DVLib::GenerateGUIDStringW();
    DownloadCallbackImpl callback;
    DownloadDialog dd;
    dd.callback = & callback;
    dd.downloadfiles.push_back(info);
    dd.Exec();
    std::wstring fullpath = DVLib::DirectoryCombine(info->destinationpath, info->destinationfilename);
    CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
    DVLib::FileDelete(fullpath);
    CPPUNIT_ASSERT(callback.IsDownloading());
    CPPUNIT_ASSERT(! callback.IsCopying());
}

void DownloadDialogUnitTests::testShowDialogOnCopyFile()
{
    // download via URL
    DownloadFilePtr info(new DownloadFile());
    info->alwaysdownload = false;
    info->componentname = L"test download";
    info->sourcepath = DVLib::GetModuleFileNameW();
    info->sourceurl = L"file://" + DVLib::GetModuleFileNameW();
    info->destinationpath = DVLib::GetTemporaryDirectoryW();
    info->destinationfilename = DVLib::GenerateGUIDStringW();
    DownloadCallbackImpl callback;
    DownloadDialog dd;
    dd.callback = & callback;
    dd.downloadfiles.push_back(info);
    dd.Exec();
    std::wstring fullpath = DVLib::DirectoryCombine(info->destinationpath, info->destinationfilename);
    CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
    DVLib::FileDelete(fullpath);
    CPPUNIT_ASSERT(! callback.IsDownloading());
    CPPUNIT_ASSERT(callback.IsCopying());
}

void DownloadDialogUnitTests::testNoDialogOnNoDownloadOrCopy()
{
    // download via URL
    DownloadFilePtr info(new DownloadFile());
    info->alwaysdownload = false;
    info->componentname = L"test download";
    info->sourcepath = DVLib::GetModuleFileNameW();
    info->sourceurl = L"file://" + DVLib::GetModuleFileNameW();
    info->destinationpath = DVLib::GetModuleDirectoryW();
    info->destinationfilename = DVLib::GetFileNameW(DVLib::GetModuleFileNameW());
    CPPUNIT_ASSERT(! info->IsDownloadRequired());
    CPPUNIT_ASSERT(! info->IsCopyRequired());
    DownloadCallbackImpl callback;
    DownloadDialog dd;
    dd.callback = & callback;
    dd.downloadfiles.push_back(info);
    dd.Exec();
    std::wstring fullpath = DVLib::DirectoryCombine(info->destinationpath, info->destinationfilename);
    CPPUNIT_ASSERT(! callback.IsDownloading());
    CPPUNIT_ASSERT(! callback.IsCopying());
}

