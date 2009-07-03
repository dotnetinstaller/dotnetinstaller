#include "StdAfx.h"
#include "Win32Exception.h"
#include "StringUtil.h"
#include "Format.h"

std::string DVLib::GetErrorString(HRESULT hr, LPCTSTR error)
{
    std::stringstream ss;
    ss << "0x" << std::hex << hr;
	if (NULL != error)
	{
		ss << " - " << DVLib::wstring2string(error);
	}
    ss << ": " << DVLib::FormatMessageFromHRA(hr);
    return ss.str();
}

std::string DVLib::GetErrorString(DWORD dwErr, LPCTSTR error)
{
    return GetErrorString(HRESULT_FROM_WIN32(dwErr));
}

std::string DVLib::GetLastErrorString(LPCTSTR error)
{
    return GetErrorString(GetLastError(), error);
}
