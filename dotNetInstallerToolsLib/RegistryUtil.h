#pragma once

namespace DVLib
{
	struct HKEY2wstringMapEntry
	{
		LPCWSTR name;
		HKEY value;
	};

	static HKEY2wstringMapEntry HKEY2wstringMap[] = 
	{
		{ L"HKEY_LOCAL_MACHINE", HKEY_LOCAL_MACHINE },
		{ L"HKEY_CURRENT_USER", HKEY_CURRENT_USER },
		{ L"HKEY_CURRENT_CONFIG", HKEY_CURRENT_CONFIG },
		{ L"HKEY_CLASSES_ROOT", HKEY_CLASSES_ROOT },
		{ L"HKEY_USERS", HKEY_USERS }
	};

	// convert a well-known HKEY value to a string
	std::wstring HKEY2wstring(HKEY root);
	// convert a well-known HKEY value to a string
	HKEY wstring2HKEY(const std::wstring& key);
	// checks whether a registry key exists
	bool RegistryKeyExists(HKEY root, const std::wstring& key, DWORD ulFlags = 0);
	// checks whether a registry value exists
	bool RegistryValueExists(HKEY root, const std::wstring& key, const std::wstring& name, DWORD ulFlags = 0);
	// create a registry key
	void RegistryCreateKey(HKEY root, const std::wstring& key, DWORD ulFlags = 0);
	// delete a registry value
	void RegistryDeleteValue(HKEY root, const std::wstring& key, const std::wstring& name = L"", DWORD ulFlags = 0);
	// delete a registry key and all its subkeys
	void RegistryDeleteKey(HKEY root, const std::wstring& key, DWORD ulFlags = 0);
	// get a string value from registry
	std::wstring RegistryGetStringValue(HKEY root, const std::wstring& key, const std::wstring& name = L"", DWORD ulFlags = 0);
	// create a string name / value pair
	void RegistrySetStringValue(HKEY root, const std::wstring& key, const std::wstring& name, const std::wstring& value = L"", DWORD ulFlags = 0);
	// get a DWORD value from registry
	DWORD RegistryGetDWORDValue(HKEY root, const std::wstring& key, const std::wstring& name = L"", DWORD ulFlags = 0);
	// create a string name / value pair
	void RegistrySetDWORDValue(HKEY root, const std::wstring& key, const std::wstring& name, DWORD value, DWORD ulFlags = 0);
	// get a multi-string value from registry
	std::vector<std::wstring> RegistryGetMultiStringValue(HKEY root, const std::wstring& key, const std::wstring& name = L"", DWORD ulFlags = 0);
	// create a multi string name / value pair
	void RegistrySetMultiStringValue(HKEY root, const std::wstring& key, const std::wstring& name, const std::vector<std::wstring>& value, DWORD ulFlags = 0);
	// get registry value type
	DWORD RegistryGetValueType(HKEY root, const std::wstring& key, const std::wstring& name, DWORD ulFlags = 0);
}