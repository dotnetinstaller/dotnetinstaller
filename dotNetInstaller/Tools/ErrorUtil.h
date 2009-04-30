#pragma once

namespace DVLib
{
	inline HRESULT LastError () 
	{
	HRESULT hr = HRESULT_FROM_WIN32(GetLastError());
	if (SUCCEEDED(hr)) 
		return E_FAIL;
	return hr;
	}

	// This little function emits an error message based on WIN32 error messages
	inline CString TranslateErrorMsg (HRESULT hr) 
	{
		TCHAR szMsg[1024] = { 0 };
		FormatMessage( 
			FORMAT_MESSAGE_FROM_SYSTEM, 
			NULL,
			hr,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			szMsg,
			1024,
			NULL 
			);
		return szMsg;
	}
}