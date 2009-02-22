
#include "stdafx.h"

#include "StringUtil.h"

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
	std::wstring UTF8string2wstring(const char * strValue)
	{
		//check if the UTF-8 string is empty
		if (strValue == NULL || strlen(strValue) <= 0)
		{
			return std::wstring();
		}

		//First convert the UTF-8 string to UNICODE
		int reqWideChars = MultiByteToWideChar(CP_UTF8,
									0,
									strValue,
									-1,
									NULL,
									0);
		if (reqWideChars == 0)
			throw std::exception("Error converting to unicode");

		reqWideChars++; //add one null terminated char (to ensure enough space)
		wchar_t * strUNICODE = new wchar_t[reqWideChars];
		memset(strUNICODE, 0, reqWideChars);

		reqWideChars = MultiByteToWideChar(CP_UTF8,
									0,
									strValue,
									-1,
									strUNICODE,
									reqWideChars);
		if (reqWideChars == 0)
			throw std::exception("Error converting to unicode");

		std::wstring out = std::wstring(strUNICODE);
		delete [] strUNICODE;
		return out;
	}

	std::wstring string2wstring(const char * strValue)
	{
		return UTF8string2wstring(strValue);
	}

	//Unicode to ASCII using CP_ACP
	std::string wstring2string(const wchar_t * strUnicode)
	{
		//check if the UTF-8 string is empty
		if (strUnicode == NULL || wcslen(strUnicode) <= 0)
		{
			return std::string();
		}

		int reqByte = WideCharToMultiByte(CP_ACP,
									0,
									strUnicode,
									-1,
									NULL,
									0,
									NULL,
									NULL);
		if (reqByte == 0)
			throw std::exception("Error converting to specified codepage");

		reqByte++; //add one null terminated char (to ensure enough space)
		char * strAnsi = new char[reqByte]; //usually a ASCII string (with the specified codepage)
		memset(strAnsi, 0, reqByte);

		reqByte = WideCharToMultiByte(CP_ACP,
									0,
									strUnicode,
									-1,
									strAnsi,
									reqByte,
									NULL,
									NULL);
		if (reqByte == 0)
			throw std::exception("Error converting to specified codepage");

		std::string out = std::string(strAnsi);
		delete [] strAnsi;
		return out;
	}

	//UTF8 string to ASCII
	std::string UTF8string2string(const char * strValue)
	{
		return wstring2string( UTF8string2wstring(strValue).data() );
	}

	stlstring UTF8string2Tstring(const char * utf8String)
	{
		#ifdef UNICODE
			return UTF8string2wstring(utf8String);
		#else
			return UTF8string2string(utf8String);
		#endif
	}

	stlstring string2Tstring(const char * strAscii)
	{
		return UTF8string2Tstring(strAscii);
	}

	std::string Tstring2string(const TCHAR * TString)
	{
		#ifdef UNICODE
			return wstring2string(TString);
		#else
			return std::string(TString);
		#endif
	}
}