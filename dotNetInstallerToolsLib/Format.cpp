#include "StdAfx.h"
#include "Format.h"
#include "StringUtil.h"

std::string DVLib::FormatMessageFromHRA(HRESULT hr)
{
    std::string result;
	LPSTR lpMsgBuf = NULL;
	DWORD rc = 0;

    rc = ::FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		hr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		reinterpret_cast<LPSTR>(& lpMsgBuf),
		0,
		NULL );

	if (rc != 0)
	{
		result = DVLib::trim(lpMsgBuf);
	}
	else
	{
        std::stringstream result_s;
        result_s << "0x" << std::hex << hr;
		result = result_s.str();
	}

	::LocalFree(lpMsgBuf);
    return result;
}

std::wstring DVLib::FormatMessageFromHRW(HRESULT hr)
{
    std::wstring result;
	LPWSTR lpMsgBuf = NULL;
	DWORD rc = 0;

    rc = ::FormatMessageW(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		hr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		reinterpret_cast<LPWSTR>(& lpMsgBuf),
		0,
		NULL );

	if (rc != 0)
	{
		result = DVLib::trim(lpMsgBuf);
	}
	else
	{
        std::wstringstream result_s;
        result_s << L"0x" << std::hex << hr;
		result = result_s.str();
	}
    return result;
}

std::wstring DVLib::FormatMessageFromLastErrorCodeW(const DWORD errorCode)
{
	return FormatMessageFromHRW(HRESULT_FROM_WIN32(errorCode));
}

std::string DVLib::FormatMessageFromLastErrorCodeA(const DWORD errorCode)
{
	return FormatMessageFromHRA(HRESULT_FROM_WIN32(errorCode));
}

std::string DVLib::FormatMessageFromVArgs(char * fmt, va_list& args)
{
    std::string result;
	int len = 0;
	result.resize(24);
	while( (len = vsnprintf_s(& * result.begin(), result.size(), result.size() - 1, fmt, args)) < 0 )
	{
		result.resize(result.size() * 2);
	}
	result.resize(len);
    return result;
}

std::wstring DVLib::FormatMessageFromVArgs(wchar_t * fmt, va_list& args)
{
    std::wstring result;
	int len = 0;
	result.resize(24);
	while( (len = _vsnwprintf_s(& * result.begin(), result.size(), result.size() - 1, fmt, args)) < 0 )
	{
		result.resize(result.size() * 2);
	}
	result.resize(len);
    return result;
}

std::string DVLib::FormatMessage(char * fmt, ...)
{
	va_list args;

	va_start(args, fmt);
    std::string result = FormatMessageFromVArgs(fmt, args);
	va_end(args);
	return result;		
}

std::wstring DVLib::FormatMessage(wchar_t * fmt, ...)
{
	va_list args;

	va_start(args, fmt);
    std::wstring result = FormatMessageFromVArgs(fmt, args);
	va_end(args);
	return result;		
}
