#include "StdAfx.h"
#include "ImageUtil.h"
#include "StringUtil.h"
#include "ExceptionMacros.h"
#include "ErrorUtil.h"
#include "PathUtil.h"
#include "FileUtil.h"
#include "DirectoryUtil.h"

HBITMAP DVLib::LoadBitmapFromFile(const std::wstring& filename)
{
	HBITMAP h = static_cast<HBITMAP>(::LoadImage(
		NULL,
		filename.c_str(),
		IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_VGACOLOR));
	
	CHECK_WIN32_BOOL(h != NULL,
		L"Error loading \"" << filename << L"\"");

	return h;
}

HBITMAP DVLib::LoadBitmapFromBuffer(const std::vector<char>& data)
{
	std::wstring filename = DVLib::GetTemporaryFileNameW();

    // create temporary directory if it doesn't already exist
    std::wstring path = DVLib::GetFileDirectoryW(filename);
	if (path.length())
    {
        DVLib::DirectoryCreate(path);
    }

	try
	{
		DVLib::FileWrite(filename, data);
		HBITMAP h = LoadBitmapFromFile(filename);
		DVLib::FileDelete(filename);
		return h;
	}
	catch(std::exception&)
	{
		DVLib::FileDelete(filename);
		throw;
	}
}


HBITMAP DVLib::LoadBitmapFromResource(HMODULE h, const std::wstring& resource, const std::wstring& type)
{
	return LoadBitmapFromBuffer(DVLib::LoadResourceData<char>(h, resource, type));
}
