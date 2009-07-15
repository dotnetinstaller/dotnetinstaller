#pragma once

template<class T>
std::vector<T> DVLib::LoadResourceData(HMODULE h, const std::wstring& resource, const std::wstring& type)
{
	HRSRC res = ::FindResource(h, resource.c_str(), type.c_str());
	CHECK_WIN32_BOOL(res != NULL, L"Invalid " << type << " resource: " << resource);
	HGLOBAL hgl = ::LoadResource(h, res);
	CHECK_WIN32_BOOL(hgl != NULL, L"Missing " << type << " resource: " << resource);
	DWORD size = SizeofResource(h, res);
	LPVOID buffer = LockResource(hgl);
	CHECK_WIN32_BOOL(buffer != NULL, L"Cannot lock " << type << " resource: " << resource);
	std::vector<T> data;
	data.resize(size / sizeof(T));
	memcpy(& * data.begin(), buffer, data.size() * sizeof(T));
	return data;
}
