#include "StdAfx.h"
#include "ImageUtil.h"
#include "StringUtil.h"
#include "ExceptionMacros.h"
#include "ErrorUtil.h"
#include "PathUtil.h"
#include "FileUtil.h"

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
	HRSRC res = ::FindResource(h, resource.c_str(), type.c_str());
	CHECK_WIN32_BOOL(res != NULL, L"Invalid " << type << " resource: " << resource);
	HGLOBAL hgl = ::LoadResource(h, res);
	CHECK_WIN32_BOOL(hgl != NULL, L"Missing " << type << " resource: " << resource);
	DWORD size = SizeofResource(h, res);
	LPVOID buffer = LockResource(hgl);
	CHECK_WIN32_BOOL(buffer != NULL, L"Cannot lock " << type << " resource: " << resource);
	std::vector<char> data;
	data.resize(size);
	memcpy(& * data.begin(), buffer, size);
	return LoadBitmapFromBuffer(data);
}
