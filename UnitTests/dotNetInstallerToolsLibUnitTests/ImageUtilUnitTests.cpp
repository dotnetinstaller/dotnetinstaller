#include "StdAfx.h"
#include "ImageUtilUnitTests.h"

using namespace DVLib::UnitTests;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ImageUtilUnitTests::testLoadBitmapFromFile()
{
    std::wstring filename = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), L"..\\test.bmp");
    std::wcout << std::endl << "Loading \"" << filename << L"\"";
    auto_hbitmap bmp(DVLib::LoadBitmapFromFile(filename));
    Assert::IsTrue(get(bmp) != NULL);
}

void ImageUtilUnitTests::testLoadBitmapFromBuffer()
{
    std::wstring filename = DVLib::DirectoryCombine(DVLib::GetCurrentModuleDirectoryW(), L"..\\test.bmp");
    std::wcout << std::endl << "Loading \"" << filename << L"\"";
    std::vector<char> data = DVLib::FileReadToEnd(filename);
    auto_hbitmap bmp(DVLib::LoadBitmapFromBuffer(data));
    Assert::IsTrue(get(bmp) != NULL);
}

void ImageUtilUnitTests::testLoadBitmapFromResource()
{
    auto_hbitmap bmp(DVLib::LoadBitmapFromResource(GetCurrentModuleHandle(), L"RES_TEST", L"CUSTOM"));
    Assert::IsTrue(get(bmp) != NULL);
}
