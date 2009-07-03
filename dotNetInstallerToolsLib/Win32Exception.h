#pragma once

namespace DVLib
{
	//! Exception from GetLastError
    std::string GetLastErrorString(LPCTSTR error = NULL);
	//! Exception from an error code
	std::string GetErrorString(DWORD dwErr, LPCTSTR error = NULL);
	//! Exception from an HRESULT
	std::string GetErrorString(HRESULT hr, LPCTSTR error = NULL);
}