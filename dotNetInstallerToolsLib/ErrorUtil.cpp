#include "StdAfx.h"
#include "ErrorUtil.h"
#include "StringUtil.h"
#include "FormatUtil.h"

std::string DVLib::GetErrorStringA(HRESULT hr, LPCSTR error)
{
    std::stringstream ss;
    ss << "0x" << std::hex << hr;
    if (NULL != error)
    {
        ss << " - " << error;
    }
    ss << ": " << DVLib::FormatMessageFromHRA(hr);
    return ss.str();
}

std::string DVLib::GetErrorStringA(DWORD dwErr, LPCSTR error)
{
    return GetErrorStringA(HRESULT_FROM_WIN32(dwErr), error);
}

std::string DVLib::GetLastErrorStringA(LPCSTR error)
{
    return GetErrorStringA(GetLastError(), error);
}

std::wstring DVLib::GetErrorStringW(HRESULT hr, LPCTSTR error, LPCTSTR dllname)
{
    std::wstringstream ss;
    ss << L"0x" << std::hex << hr;
    if (NULL != error)
    {
        ss << L" - " << error;
    }
    ss << L": " << DVLib::FormatMessageFromHRW(hr, dllname);
    return ss.str();
}

std::wstring DVLib::GetErrorStringW(DWORD dwErr, LPCTSTR error, LPCTSTR dllname)
{
    return GetErrorStringW(HRESULT_FROM_WIN32(dwErr), error, dllname);
}

std::wstring DVLib::GetLastErrorStringW(LPCTSTR error)
{
    return GetErrorStringW(GetLastError(), error);
}
