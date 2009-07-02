#pragma once
#include "Format.h"

namespace DVLib
{
	inline HRESULT LastError () 
	{
		HRESULT hr = HRESULT_FROM_WIN32(GetLastError());
		if (SUCCEEDED(hr)) 
			return E_FAIL;
		return hr;
	}

	// Emit an error message based on WIN32 error messages
	inline CString TranslateErrorMsg (HRESULT hr) 
	{
		CString result;
		LPSTR lpMsgBuf = NULL;
		DWORD rc = 0;

		rc = ::FormatMessageA(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			hr,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPSTR) &lpMsgBuf,
			0,
			NULL );

		if (rc != 0)
		{
			result = lpMsgBuf;
			// remove the control line feed characters
			// StringUtils::lrtrimcrlf(result);
			LocalFree( lpMsgBuf );
		}
		else
		{
			result = DVLib::FormatHexNumber(hr);
		}

		return result.Trim();
	}

	// Emit an error message based on WIN32 error messages from a specific system DLL
	inline CString TranslateErrorMsg(HRESULT hr, LPCSTR dllname) 
	{
		CString result;
		LPSTR lpMsgBuf = NULL;
		DWORD rc = 0;

		HMODULE dllhandle = ::LoadLibraryA(dllname);

		rc = ::FormatMessageA(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_HMODULE,
			dllhandle,
			hr,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPSTR) &lpMsgBuf,
			0,
			NULL );

		::CloseHandle(dllhandle);

		if (rc != 0)
		{
			result = lpMsgBuf;
			// remove the control line feed characters
			// StringUtils::lrtrimcrlf(result);
			LocalFree( lpMsgBuf );
		}
		else
		{
			// fallback to system
			result = TranslateErrorMsg(hr);
		}

		return result.Trim();
	}
}