#pragma once

// these macros wrap Win32 calls and produce std::exceptions on failure

#define CHECK_WIN32_DWORD( func, message ) \
{ \
	DWORD macro_dw_err_ = ( func ); \
	if ( macro_dw_err_ != 0 ) \
	{ \
		std::wstringstream ss_message; ss_message << message; \
		throw std::exception(DVLib::wstring2string(DVLib::GetErrorStringW(macro_dw_err_, \
            ss_message.str().c_str())).c_str()); \
	} \
}

#define CHECK_WIN32_BOOL( func, message ) \
{ \
	if ( FALSE == ( func ) ) \
	{ \
		std::wstringstream ss_message; ss_message << message; \
		throw std::exception(DVLib::wstring2string(DVLib::GetLastErrorStringW( \
            ss_message.str().c_str())).c_str()); \
	} \
}

#define CHECK_BOOL( func, message ) \
{ \
	if ( FALSE == ( func ) ) \
	{ \
		std::wstringstream ss_message; ss_message << message; \
		throw std::exception(DVLib::wstring2string(ss_message.str()).c_str()); \
	} \
}

#define THROW_EX( message ) \
{ \
	std::wstringstream ss_message; ss_message << message; \
	throw std::exception(DVLib::wstring2string(ss_message.str()).c_str()); \
}

#define CHECK_HR( func, message ) \
{ \
	HRESULT macro_hr_ = ( func ); \
	if (FAILED(macro_hr_)) \
	{ \
		std::wstringstream ss_message; ss_message << message; \
		throw std::exception(DVLib::wstring2string(DVLib::GetErrorStringW(macro_hr_, \
            ss_message.str().c_str())).c_str()); \
	} \
}
