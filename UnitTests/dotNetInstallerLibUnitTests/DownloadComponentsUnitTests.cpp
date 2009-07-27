#include "StdAfx.h"
#include "DownloadComponentsUnitTests.h"
#include "DownloadComponentCallbackImpl.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::DownloadComponentsUnitTests);

using namespace DVLib::UnitTests;

void DownloadComponentsUnitTests::testIsCopyDownloadRequiredEmpty()
{
	std::vector<DownloadComponentInfoPtr> component_info;
	DownloadComponents components;
	components.Load(NULL, component_info);
	// empty components, no copy required, but download is
	CPPUNIT_ASSERT(! components.IsCopyRequired());
	CPPUNIT_ASSERT(! components.IsDownloadRequired());	
}

void DownloadComponentsUnitTests::testIsCopyDownloadRequired()
{
	DownloadComponentInfoPtr c(new DownloadComponentInfo());
	c->alwaysdownload = false;
	c->sourceurl = L"http://download.microsoft.com/download/5/6/7/567758a3-759e-473e-bf8f-52154438565a/dotnetfx.exe";
	std::vector<DownloadComponentInfoPtr> component_info;
	component_info.push_back(c);
	DownloadComponents components;
	components.Load(NULL, component_info);
	// component with no source path
	CPPUNIT_ASSERT(! components.IsCopyRequired());	
	CPPUNIT_ASSERT(components.IsDownloadRequired());
	// component with both source and destination path, source path must exist
	c->sourcepath = DVLib::GetModuleFileNameW();
	CPPUNIT_ASSERT(components.IsCopyRequired());
	CPPUNIT_ASSERT(! components.IsDownloadRequired());
	DownloadComponentInfoPtr c2(new DownloadComponentInfo());
	component_info.push_back(c2);
	c2->alwaysdownload = true;
	c2->sourceurl = L"http://download.microsoft.com/download/5/6/7/567758a3-759e-473e-bf8f-52154438565a/dotnetfx.exe";
	CPPUNIT_ASSERT(components.IsCopyRequired());
	CPPUNIT_ASSERT(! components.IsDownloadRequired());
}

void DownloadComponentsUnitTests::testDownload()
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
	std::vector<DownloadComponentInfoPtr> component_info;
	component_info.push_back(info);
	DownloadComponents components;
	components.Load(& callback, component_info);
	components.Exec();
	components.Wait();
	std::wstring fullpath = DVLib::DirectoryCombine(info->destinationpath, info->destinationfilename);
	CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
	DVLib::FileDelete(fullpath);
}

void DownloadComponentsUnitTests::testCopyFromSource()
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
	std::vector<DownloadComponentInfoPtr> component_info;
	component_info.push_back(info);
	DownloadComponents components;
	components.Load(& callback, component_info);
	components.Exec();
	components.Wait();
	std::wstring fullpath = DVLib::DirectoryCombine(info->destinationpath, info->destinationfilename);
	CPPUNIT_ASSERT(DVLib::FileExists(fullpath));
	DVLib::FileDelete(fullpath);
}

void DownloadComponentsUnitTests::testDownloadMultiple()
{
	// component 1
	DownloadComponentInfoPtr info1(new DownloadComponentInfo());
	info1->alwaysdownload = false;
	info1->componentname = L"test download (1)";
	info1->sourcepath = L"";
	info1->sourceurl = L"file://" + DVLib::GetModuleFileNameW();
	info1->destinationpath = DVLib::GetTemporaryDirectoryW();
	info1->destinationfilename = DVLib::GenerateGUIDStringW();
	// component 2
	DownloadComponentInfoPtr info2(new DownloadComponentInfo());
	info2->alwaysdownload = false;
	info2->componentname = L"test download (2)";
	info2->sourcepath = L"";
	info2->sourceurl = L"file://" + DVLib::GetModuleFileNameW();
	info2->destinationpath = DVLib::GetTemporaryDirectoryW();
	info2->destinationfilename = DVLib::GenerateGUIDStringW();
	// download
	DownloadComponentCallbackImpl callback;
	std::vector<DownloadComponentInfoPtr> component_info;
	component_info.push_back(info1);
	component_info.push_back(info2);
	DownloadComponents components;
	components.Load(& callback, component_info);
	components.Exec();
	components.Wait();
	std::wcout << std::endl << L"Complete count: " << callback.GetCompleteCount();
	CPPUNIT_ASSERT(1 == callback.GetCompleteCount());
	std::wstring fullpath1 = DVLib::DirectoryCombine(info1->destinationpath, info1->destinationfilename);
	CPPUNIT_ASSERT(DVLib::FileExists(fullpath1));
	DVLib::FileDelete(fullpath1);
	std::wstring fullpath2 = DVLib::DirectoryCombine(info2->destinationpath, info2->destinationfilename);
	CPPUNIT_ASSERT(DVLib::FileExists(fullpath2));
	DVLib::FileDelete(fullpath2);
}

void DownloadComponentsUnitTests::testDownloadMultipleError()
{
	// component 1
	DownloadComponentInfoPtr info1(new DownloadComponentInfo());
	info1->alwaysdownload = false;
	info1->componentname = L"test download (1)";
	info1->sourcepath = L"";
	info1->sourceurl = L"file://" + DVLib::GenerateGUIDStringW();
	info1->destinationpath = DVLib::GetTemporaryDirectoryW();
	info1->destinationfilename = DVLib::GenerateGUIDStringW();
	// component 2
	DownloadComponentInfoPtr info2(new DownloadComponentInfo());
	info2->alwaysdownload = false;
	info2->componentname = L"test download (2)";
	info2->sourcepath = L"";
	info2->sourceurl = L"file://" + DVLib::GenerateGUIDStringW();
	info2->destinationpath = DVLib::GetTemporaryDirectoryW();
	info2->destinationfilename = DVLib::GenerateGUIDStringW();
	// download
	DownloadComponentCallbackImpl callback;
	std::vector<DownloadComponentInfoPtr> component_info;
	component_info.push_back(info1);
	component_info.push_back(info2);
	DownloadComponents components;
	components.Load(& callback, component_info);

	try
	{
		components.Exec();
		throw "expected std::exception";
	}
	catch(std::exception&)
	{

	}

	CPPUNIT_ASSERT(1 == callback.GetErrorCount());
}
