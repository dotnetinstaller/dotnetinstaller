#include "stdafx.h"

#include "StringUtil.h"
#include "StringUtilImpl.h"
#include "ExceptionMacros.h"
#include "Win32Exception.h"

std::wstring DVLib::UTF8string2wstring(const std::string& s)
{
	int req = ::MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, NULL, 0);
	CHECK_WIN32_BOOL(0 != req, "MultiByteToWideChar");
	std::vector<wchar_t> result;
	result.resize(req);
	req = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, & * result.begin(), result.size());
	CHECK_WIN32_BOOL(0 != req, "MultiByteToWideChar");
	std::wstring to;
	to.assign(& * result.begin(), req - 1);
	return to;
}

std::wstring DVLib::string2wstring(const std::string& s)
{
	return UTF8string2wstring(s);
}

std::string DVLib::wstring2string(const std::wstring& s)
{
	int req = ::WideCharToMultiByte(CP_ACP, 0, s.c_str(), -1, NULL, 0, NULL, NULL);
	CHECK_WIN32_BOOL(0 != req, "WideCharToMultiByte");
	std::vector<char> result;
	result.resize(req);
	req = WideCharToMultiByte(CP_ACP, 0, s.c_str(), -1, & * result.begin(), result.size(), NULL, NULL);
	CHECK_WIN32_BOOL(0 != req, "WideCharToMultiByte");
	std::string to;
	to.assign(& * result.begin(), req - 1);
	return to;
}

std::string DVLib::UTF8string2string(const std::string& s)
{
	return wstring2string(UTF8string2wstring(s));
}

bool DVLib::string2bool(const std::string& s, bool defaultValue)
{
    if (s.length() == 0) return defaultValue;
    else if (0 == _stricmp(s.c_str(), "true")) return true;
    else if (0 == _stricmp(s.c_str(), "false")) return false;
    else return defaultValue;
}

bool DVLib::wstring2bool(const std::wstring& s, bool defaultValue)
{
    if (s.length() == 0) return defaultValue;
    else if (0 == _wcsicmp(s.c_str(), L"true")) return true;
    else if (0 == _wcsicmp(s.c_str(), L"false")) return false;
    else return defaultValue;
}

std::string DVLib::trim(const std::string& s, const std::string& whitespaces)
{
	return StringUtilsImpl<char>::trim(s, whitespaces);
}

std::wstring DVLib::trim(const std::wstring& s, const std::wstring& whitespaces)
{
	return StringUtilsImpl<wchar_t>::trim(s, whitespaces);
}

std::string DVLib::trimleft(const std::string& s, const std::string& whitespaces)
{
	return StringUtilsImpl<char>::trimleft(s, whitespaces);
}

std::wstring DVLib::trimleft(const std::wstring& s, const std::wstring& whitespaces)
{
	return StringUtilsImpl<wchar_t>::trimleft(s, whitespaces);
}

std::string DVLib::trimright(const std::string& s, const std::string& whitespaces)
{
	return StringUtilsImpl<char>::trimright(s, whitespaces);
}

std::wstring DVLib::trimright(const std::wstring& s, const std::wstring& whitespaces)
{
	return StringUtilsImpl<wchar_t>::trimright(s, whitespaces);
}

long DVLib::string2long(const std::string& s, long default_on_error, int base)
{
	const char * psz = s.c_str();
    char *endPtr = NULL;
    int result = 0; 

    if ( psz != NULL && *psz != '\0' )
    {
	    // errrange
	    result = strtol(psz, &endPtr, base);
		
	    if ( *endPtr != '\0' || (errno == ERANGE && (result == LONG_MAX || result == LONG_MIN)) )
	    {
		    result = default_on_error;
	    }
    }
    else
    {
	    result = default_on_error;
    }

    return result;
}

long DVLib::wstring2long(const std::wstring& s, long default_on_error, int base)
{
	const wchar_t * psz = s.c_str();
    wchar_t *endPtr = NULL;
    int result = 0; 
	
    result = wcstol(psz, &endPtr, base);
    if ( psz != NULL && *psz != L'\0' )
    {
	    if ( *endPtr != L'\0' || (errno == ERANGE && (result == LONG_MAX || result == LONG_MIN)) )
	    {
		    result = default_on_error;
	    }
    }
    else
    {
	    result = default_on_error;
    }
	
    return result;
}

std::string DVLib::replace(const std::string& s, const std::string& from, const std::string& to)
{
    return StringUtilsImpl<char>::replace(s, from, to);
}

std::wstring DVLib::replace(const std::wstring& s, const std::wstring& from, const std::wstring& to)
{
    return StringUtilsImpl<wchar_t>::replace(s, from, to);
}

std::vector<std::string> DVLib::split(const std::string& s, const std::string& delims, int max)
{
    return StringUtilsImpl<char>::split(s, delims, max);
}

std::vector<std::wstring> DVLib::split(const std::wstring& s, const std::wstring& delims, int max)
{
    return StringUtilsImpl<wchar_t>::split(s, delims, max);
}

std::string DVLib::join(const std::vector<std::string>& tokens, const std::string& delims)
{
    return StringUtilsImpl<char>::join(tokens, delims);
}

std::wstring DVLib::join(const std::vector<std::wstring>& tokens, const std::wstring& delims)
{
    return StringUtilsImpl<wchar_t>::join(tokens, delims);
}

std::string DVLib::join(const std::list<std::string>& tokens, const std::string& delims)
{
    return StringUtilsImpl<char>::join(tokens, delims);
}

std::wstring DVLib::join(const std::list<std::wstring>& tokens, const std::wstring& delims)
{
    return StringUtilsImpl<wchar_t>::join(tokens, delims);
}
