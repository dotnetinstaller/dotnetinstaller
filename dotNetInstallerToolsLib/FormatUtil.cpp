#include "StdAfx.h"
#include "FormatUtil.h"
#include "StringUtil.h"
#include "ExceptionMacros.h"
#include "ErrorUtil.h"

std::string DVLib::FormatMessageFromHRA(HRESULT hr, LPCSTR dllname)
{
    std::string result;
	DWORD rc = 0;

	auto_library dllhandle(dllname != NULL ? ::LoadLibraryA(dllname) : NULL);
	auto_hlocal lpMsgBuf;

    rc = ::FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		((get(dllhandle) != NULL) ? FORMAT_MESSAGE_FROM_HMODULE : FORMAT_MESSAGE_FROM_SYSTEM),
		get(dllhandle),
		hr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		reinterpret_cast<LPSTR>(address(lpMsgBuf)),
		0,
		NULL );

	if (rc != 0)
	{
		result = DVLib::trim(reinterpret_cast<LPCSTR>(get(lpMsgBuf)));
	}
	else
	{
        std::stringstream result_s;
        result_s << "0x" << std::hex << hr;
		result = result_s.str();
	}

    return result;
}

std::wstring DVLib::FormatMessageFromHRW(HRESULT hr, LPCWSTR dllname)
{
    std::wstring result;
	DWORD rc = 0;

	auto_library dllhandle(dllname != NULL ? ::LoadLibraryW(dllname) : NULL);
	auto_hlocal lpMsgBuf;

    rc = ::FormatMessageW(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		((get(dllhandle) != NULL) ? FORMAT_MESSAGE_FROM_HMODULE : FORMAT_MESSAGE_FROM_SYSTEM),
		get(dllhandle),
		hr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		reinterpret_cast<LPWSTR>(address(lpMsgBuf)),
		0,
		NULL );

	if (rc != 0)
	{
		result = DVLib::trim(reinterpret_cast<LPCWSTR>(get(lpMsgBuf)));
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

std::string DVLib::FormatCurrentDateTimeA(LPCSTR fmt)
{
	__time64_t tt;
	CHECK_BOOL(-1 != _time64(& tt), L"_time64");
	return FormatDateTimeA(tt, fmt);
}

std::wstring DVLib::FormatCurrentDateTimeW(LPCWSTR fmt)
{
	__time64_t tt;
	CHECK_BOOL(-1 != _time64(& tt), L"_time64");
	return FormatDateTimeW(tt, fmt);
}

std::string DVLib::FormatDateTimeA(__time64_t tt, LPCSTR fmt)
{
	struct tm tm = { 0 };
	CHECK_WIN32_DWORD(_localtime64_s(& tm, & tt), L"_localtime64_s");
	char buffer[128];
	CHECK_BOOL(0 != strftime(buffer, ARRAYSIZE(buffer), fmt, & tm), L"strftime");
	return buffer;
}

std::wstring DVLib::FormatDateTimeW(__time64_t tt, LPCWSTR fmt)
{
	struct tm tm = { 0 };
	CHECK_WIN32_DWORD(_localtime64_s(& tm, & tt), L"_localtime64_s");
	wchar_t buffer[128];
	CHECK_BOOL(0 != wcsftime(buffer, ARRAYSIZE(buffer), fmt, & tm), L"wcsftime");
	return buffer;
}

// same as StrFormatByteSize (which is not supported on Windows 95)
std::string DVLib::FormatBytesA(ULONG bytes)
{
	if (bytes == 1) // bytes
		return DVLib::FormatMessage("%lu byte", bytes);
	else if (bytes < 1024) // bytes
		return DVLib::FormatMessage("%lu bytes", bytes);
	else if (bytes < 1048576 && bytes % 1024 == 0) // Kb
		return DVLib::FormatMessage("%.0fKB", (double) bytes / 1024);
	else if (bytes < 1048576) // Kb
		return DVLib::FormatMessage("%.2fKB", (double) bytes / 1024);
	else if (bytes % 1048576 == 0 && bytes < 1073741824) // Mb
		return DVLib::FormatMessage("%.0fMB", (double) bytes / 1048576);
	else if (bytes < 1073741824) // Mb
		return DVLib::FormatMessage("%.2fMB", (double) bytes / 1048576);
	else if (bytes % 1073741824 == 0 && bytes < 1099511627776 ) // GB
		return DVLib::FormatMessage("%.0fGB", (double) bytes / 1073741824);
	else if (bytes < 1099511627776 ) // GB
		return DVLib::FormatMessage("%.2fGB", (double) bytes / 1073741824);
	else
		return DVLib::FormatMessage("%lu bytes", bytes);
}

std::wstring DVLib::FormatBytesW(ULONG bytes)
{
	if (bytes == 1) // bytes
		return DVLib::FormatMessage(L"%lu byte", bytes);
	else if (bytes < 1024) // bytes
		return DVLib::FormatMessage(L"%lu bytes", bytes);
	else if (bytes < 1048576 && bytes % 1024 == 0) // Kb
		return DVLib::FormatMessage(L"%.0fKB", (double) bytes / 1024);
	else if (bytes < 1048576) // Kb
		return DVLib::FormatMessage(L"%.2fKB", (double) bytes / 1024);
	else if (bytes % 1048576 == 0 && bytes < 1073741824) // Mb
		return DVLib::FormatMessage(L"%.0fMB", (double) bytes / 1048576);
	else if (bytes < 1073741824) // Mb
		return DVLib::FormatMessage(L"%.2fMB", (double) bytes / 1048576);
	else if (bytes % 1073741824 == 0 && bytes < 1099511627776 ) // GB
		return DVLib::FormatMessage(L"%.0fGB", (double) bytes / 1073741824);
	else if (bytes < 1099511627776 ) // GB
		return DVLib::FormatMessage(L"%.2fGB", (double) bytes / 1073741824);
	else
		return DVLib::FormatMessage(L"%lu bytes", bytes);
}
