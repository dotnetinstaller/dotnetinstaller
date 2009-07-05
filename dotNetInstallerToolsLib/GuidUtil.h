#pragma once

namespace DVLib
{
	// converts a globally unique identifier (GUID) into a string of printable characters
    std::string StringFromGUID2A(REFGUID rguid);
    std::wstring StringFromGUID2W(REFGUID rguid);
	// generate and converts a globally unique identifier (GUID) into a string of printable characters
    std::string GenerateGUIDStringA();
    std::wstring GenerateGUIDStringW();
}