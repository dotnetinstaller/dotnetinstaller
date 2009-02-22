#pragma once

#include <string>
#include <vector>

namespace DVLib
{
	#ifdef UNICODE
		#define stlstring std::wstring
		#define stlvectorstring std::vector<std::wstring>
	#else
		#define stlstring std::string
		#define stlvectorstring std::vector<std::string>
	#endif

	//UTF8 string to UNICODE
	//can be used also for converting ASCII to UNICODE
	std::wstring UTF8string2wstring(const char * strValue);

	std::wstring string2wstring(const char * strValue);

	//Unicode to ASCII using CP_ACP
	std::string wstring2string(const wchar_t * strUnicode);

	//UTF8 string to ASCII
	std::string UTF8string2string(const char * strValue);

	stlstring UTF8string2Tstring(const char * utf8String);

	stlstring string2Tstring(const char * strAscii);

	std::string Tstring2string(const TCHAR * TString);
}