#include "StdAfx.h"
#include "ImageUtilUnitTests.h"

using namespace DVLib::UnitTests;

CPPUNIT_TEST_SUITE_REGISTRATION(ImageUtilUnitTests);

void ImageUtilUnitTests::testLoadBitmapFromFile()
{
	std::wstring filename = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), L"..\\test.bmp");
	std::wcout << std::endl << "Loading \"" << filename << L"\"";
	auto_hbitmap bmp(DVLib::LoadBitmapFromFile(filename));
	CPPUNIT_ASSERT(get(bmp) != NULL);
}

void ImageUtilUnitTests::testLoadBitmapFromBuffer()
{
	std::wstring filename = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), L"..\\test.bmp");
	std::wcout << std::endl << "Loading \"" << filename << L"\"";
	std::vector<char> data = DVLib::FileReadToEnd(filename);
	auto_hbitmap bmp(DVLib::LoadBitmapFromBuffer(data));
	CPPUNIT_ASSERT(get(bmp) != NULL);
}

void ImageUtilUnitTests::testLoadBitmapFromResource()
{
	auto_hbitmap bmp(DVLib::LoadBitmapFromResource(NULL, L"RES_TEST", L"CUSTOM"));
	CPPUNIT_ASSERT(get(bmp) != NULL);
}
