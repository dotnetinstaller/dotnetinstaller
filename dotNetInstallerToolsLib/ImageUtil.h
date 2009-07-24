#pragma once

namespace DVLib
{	
	HBITMAP LoadBitmapFromFile(const std::wstring& filename);
	HBITMAP LoadBitmapFromBuffer(const std::vector<char>& data);
	HBITMAP LoadBitmapFromResource(HMODULE h, const std::wstring& resource, const std::wstring& type);
}
