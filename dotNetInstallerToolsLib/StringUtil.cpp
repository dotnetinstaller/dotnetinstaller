#include "StdAfx.h"
#include "StringUtil.h"
#include "StringUtilImpl.h"
#include "ExceptionMacros.h"
#include "ErrorUtil.h"

std::wstring DVLib::UTF8string2wstring(const std::string& s)
{
	return UTF8string2wstring(s.c_str());
}

std::wstring DVLib::UTF8string2wstring(const char * s)
{
	if (s == NULL) return L"";
	int req = ::MultiByteToWideChar(CP_UTF8, 0, s, -1, NULL, 0);
	CHECK_WIN32_BOOL(0 != req, "MultiByteToWideChar");
	std::vector<wchar_t> result;
	result.resize(req);
	req = MultiByteToWideChar(CP_UTF8, 0, s, -1, & * result.begin(), result.size());
	CHECK_WIN32_BOOL(0 != req, "MultiByteToWideChar");
	std::wstring to;
	to.assign(& * result.begin(), req - 1); // length returned includes the null terminator
	return to;
}

std::wstring DVLib::string2wstring(const std::string& s)
{
	return string2wstring(s.c_str());
}

std::wstring DVLib::string2wstring(const char * s)
{
	if (s == NULL) return L"";
	int req = ::MultiByteToWideChar(CP_ACP, 0, s, -1, NULL, 0);
	CHECK_WIN32_BOOL(0 != req, "MultiByteToWideChar");
	std::vector<wchar_t> result;
	result.resize(req);
	req = MultiByteToWideChar(CP_ACP, 0, s, -1, & * result.begin(), result.size());
	CHECK_WIN32_BOOL(0 != req, "MultiByteToWideChar");
	std::wstring to;
	to.assign(& * result.begin(), req - 1);
	return to;
}

std::string DVLib::wstring2string(const std::wstring& s)
{
	return wstring2string(s.c_str());
}

std::string DVLib::wstring2string(const wchar_t * s)
{
	if (s == NULL) return "";
	int req = ::WideCharToMultiByte(CP_ACP, 0, s, -1, NULL, 0, NULL, NULL);
	CHECK_WIN32_BOOL(0 != req, "WideCharToMultiByte");
	std::vector<char> result;
	result.resize(req);
	req = WideCharToMultiByte(CP_ACP, 0, s, -1, & * result.begin(), result.size(), NULL, NULL);
	CHECK_WIN32_BOOL(0 != req, "WideCharToMultiByte");
	std::string to;
	to.assign(& * result.begin(), req - 1);
	return to;
}

std::string DVLib::UTF8string2string(const std::string& s)
{
	return UTF8string2string(s.c_str());
}

std::string DVLib::UTF8string2string(const char * s)
{
	return wstring2string(UTF8string2wstring(s));
}

bool DVLib::string2bool(const std::string& s, bool defaultValue)
{
	return string2bool(s.c_str(), defaultValue);
}

bool DVLib::string2bool(const char * s, bool defaultValue)
{
    if (s == NULL || strlen(s) == 0) return defaultValue;
    else if (0 == _stricmp(s, "true")) return true;
    else if (0 == _stricmp(s, "false")) return false;
	else THROW_EX(L"Invalid boolean value: " << s);
}

bool DVLib::wstring2bool(const std::wstring& s, bool defaultValue)
{
	return wstring2bool(s.c_str(), defaultValue);
}

bool DVLib::wstring2bool(const wchar_t * s, bool defaultValue)
{
	if (s == NULL || wcslen(s) == 0) return defaultValue;
    else if (0 == _wcsicmp(s, L"true")) return true;
    else if (0 == _wcsicmp(s, L"false")) return false;
	else THROW_EX(L"Invalid boolean value: " << s);
}

std::string DVLib::trim(const std::string& s, const std::string& whitespaces)
{
	return StringUtilImpl<char>::trim(s, whitespaces);
}

std::wstring DVLib::trim(const std::wstring& s, const std::wstring& whitespaces)
{
	return StringUtilImpl<wchar_t>::trim(s, whitespaces);
}

std::string DVLib::trimleft(const std::string& s, const std::string& whitespaces)
{
	return StringUtilImpl<char>::trimleft(s, whitespaces);
}

std::wstring DVLib::trimleft(const std::wstring& s, const std::wstring& whitespaces)
{
	return StringUtilImpl<wchar_t>::trimleft(s, whitespaces);
}

std::string DVLib::trimright(const std::string& s, const std::string& whitespaces)
{
	return StringUtilImpl<char>::trimright(s, whitespaces);
}

std::wstring DVLib::trimright(const std::wstring& s, const std::wstring& whitespaces)
{
	return StringUtilImpl<wchar_t>::trimright(s, whitespaces);
}

long DVLib::string2long(const std::string& s, int base)
{
	if (s.empty()) throw std::exception("Missing number");
    char *endPtr = NULL;
	_set_errno(0); // errno is not reset by runtime calls
	long result = strtol(s.c_str(), & endPtr, base);
    if ( *endPtr != '\0' || (errno == ERANGE && (result == LONG_MAX || result == LONG_MIN)) )
    {
		THROW_EX(L"Invalid number: " << string2wstring(s));
    }
    return result;
}

long DVLib::wstring2long(const std::wstring& s, int base)
{
	if (s.empty()) throw std::exception("Missing number");
    wchar_t *endPtr = NULL;
	_set_errno(0); // errno is not reset by runtime calls
	long result = wcstol(s.c_str(), & endPtr, base);
    if ( *endPtr != L'\0' || (errno == ERANGE && (result == LONG_MAX || result == LONG_MIN)) )
    {
		THROW_EX("Invalid number: " << s);
    }
    return result;
}

unsigned long DVLib::string2ulong(const std::string& s, int base)
{
	if (s.empty()) throw std::exception("Missing number");
    char *endPtr = NULL;
	_set_errno(0); // errno is not reset by runtime calls
	unsigned long result = strtoul(s.c_str(), & endPtr, base);
    if ( *endPtr != '\0' || (errno == ERANGE && (result == ULONG_MAX || result == 0)) )
    {
		THROW_EX(L"Invalid number: " << string2wstring(s));
    }
    return result;
}

unsigned long DVLib::wstring2ulong(const std::wstring& s, int base)
{
	if (s.empty()) throw std::exception("Missing number");
    wchar_t *endPtr = NULL;
	_set_errno(0); // errno is not reset by runtime calls
	unsigned long result = wcstoul(s.c_str(), & endPtr, base);
    if ( *endPtr != L'\0' || (errno == ERANGE && (result == ULONG_MAX || result == 0)) )
    {
		THROW_EX("Invalid number: " << s);
    }
    return result;
}

std::string DVLib::replace(const std::string& s, const std::string& from, const std::string& to)
{
    return StringUtilImpl<char>::replace(s, from, to);
}

std::wstring DVLib::replace(const std::wstring& s, const std::wstring& from, const std::wstring& to)
{
    return StringUtilImpl<wchar_t>::replace(s, from, to);
}

std::vector<std::string> DVLib::split(const std::string& s, const std::string& delims, int max)
{
    return StringUtilImpl<char>::split(s, delims, max);
}

std::vector<std::wstring> DVLib::split(const std::wstring& s, const std::wstring& delims, int max)
{
    return StringUtilImpl<wchar_t>::split(s, delims, max);
}

std::string DVLib::join(const std::vector<std::string>& tokens, const std::string& delims)
{
    return StringUtilImpl<char>::join(tokens, delims);
}

std::wstring DVLib::join(const std::vector<std::wstring>& tokens, const std::wstring& delims)
{
    return StringUtilImpl<wchar_t>::join(tokens, delims);
}

std::string DVLib::join(const std::list<std::string>& tokens, const std::string& delims)
{
    return StringUtilImpl<char>::join(tokens, delims);
}

std::wstring DVLib::join(const std::list<std::wstring>& tokens, const std::wstring& delims)
{
    return StringUtilImpl<wchar_t>::join(tokens, delims);
}

bool DVLib::startswith(const std::string& ss, const std::string& what)
{
    return StringUtilImpl<char>::startswith(ss, what);
}

bool DVLib::startswith(const std::wstring& ss, const std::wstring& what)
{
    return StringUtilImpl<wchar_t>::startswith(ss, what);
}

bool DVLib::endswith(const std::string& ss, const std::string& what)
{
    return StringUtilImpl<char>::endswith(ss, what);
}

bool DVLib::endswith(const std::wstring& ss, const std::wstring& what)
{
    return StringUtilImpl<wchar_t>::endswith(ss, what);
}
