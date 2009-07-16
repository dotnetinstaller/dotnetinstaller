#pragma once

namespace DVLib
{
	// converts a globally unique identifier (GUID) into a string of printable characters
    std::string guid2string(REFGUID rguid);
    std::wstring guid2wstring(REFGUID rguid);
	// converts a string into a GUID
	IID string2guid(const std::wstring& guid);
	IID string2guid(const std::string& guid);
	// generate and converts a globally unique identifier (GUID) into a string of printable characters
    std::string GenerateGUIDStringA();
    std::wstring GenerateGUIDStringW();
}