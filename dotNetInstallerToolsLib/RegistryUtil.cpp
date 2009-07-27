#include "StdAfx.h"
#include "RegistryUtil.h"
#include "ExceptionMacros.h"
#include "StringUtil.h"
#include "ErrorUtil.h"

bool DVLib::RegistryKeyExists(HKEY root, const std::wstring& key, const std::wstring& name, DWORD ulFlags)
{
    HKEY reg = NULL;
    DWORD dwErr = ::RegOpenKeyEx(root, key.c_str(), 0, ulFlags | KEY_READ, & reg);
    auto_hkey reg_ptr(reg);

    bool result = true;
    switch(dwErr)
    {
    case ERROR_SUCCESS:
        break;
    case ERROR_FILE_NOT_FOUND:
        result = false;
        break;
    default:
        CHECK_WIN32_DWORD(dwErr,
            L"Error checking whether '" << HKEY2wstring(root) << L"\\" << key << L"' exists");
        break;
    }

    if (result && ! name.empty())
    {
        DWORD dwSize = 0;
        DWORD dwType = 0;
        dwErr = ::RegQueryValueEx(reg, name.c_str(), 0, & dwType, NULL, & dwSize);
        switch(dwErr)
        {
        case ERROR_SUCCESS:
        case ERROR_INSUFFICIENT_BUFFER:
            break;
        case ERROR_FILE_NOT_FOUND:
            result = false;
            break;
        default:
            CHECK_WIN32_DWORD(dwErr,
                L"Error checking whether '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"' exists");
            break;        
        }
    }

    return result;
}

std::wstring DVLib::RegistryGetStringValue(HKEY root, const std::wstring& key, const std::wstring& name, DWORD ulFlags)
{
    HKEY reg = NULL;

    CHECK_WIN32_DWORD(::RegOpenKeyEx(root, key.c_str(), 0, ulFlags | KEY_READ, & reg),
        L"Error opening " << HKEY2wstring(root) << L"\\" << key);

    auto_hkey reg_ptr(reg);

    DWORD dwSize = 0;
    DWORD dwType = 0;

    CHECK_WIN32_DWORD(::RegQueryValueEx(reg, name.c_str(), 0, & dwType, NULL, & dwSize),
        L"Error quering '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"' value size");

	CHECK_BOOL(dwType == REG_SZ || dwType == REG_EXPAND_SZ,
        L"Error quering '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"' value, unexpected type " << dwType);

    std::wstring value;
    if (dwSize > 0)
    {
        value.resize(dwSize / sizeof(WCHAR));

        CHECK_WIN32_DWORD(::RegQueryValueEx(reg, name.c_str(), 0, & dwType, reinterpret_cast<LPBYTE>(& * value.begin()), & dwSize),
			L"Error quering '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"' value data");

        value.resize((dwSize - 1) / sizeof(WCHAR));
    }

    return value;
}

DWORD DVLib::RegistryGetValueType(HKEY root, const std::wstring& key, const std::wstring& name, DWORD ulFlags)
{
    HKEY reg = NULL;

    CHECK_WIN32_DWORD(::RegOpenKeyEx(root, key.c_str(), 0, ulFlags | KEY_READ, & reg),
        L"Error opening " << HKEY2wstring(root) << L"\\" << key);

    auto_hkey reg_ptr(reg);

    DWORD dwSize = 0;
    DWORD dwType = 0;

    CHECK_WIN32_DWORD(::RegQueryValueEx(reg, name.c_str(), 0, & dwType, NULL, & dwSize),
        L"Error quering '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"'");

	return dwType;
}

void DVLib::RegistryCreateKey(HKEY root, const std::wstring& key, DWORD ulFlags)
{
	HKEY hkey = NULL;

	CHECK_WIN32_DWORD(::RegCreateKeyEx(root, key.c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, ulFlags | KEY_WRITE, NULL, & hkey, NULL),
        L"Error creating '" << HKEY2wstring(root) << L"\\" << key << L"'");

	::RegCloseKey(hkey);
}

void DVLib::RegistryDeleteValue(HKEY root, const std::wstring& key, const std::wstring& name, DWORD ulFlags)
{
	HKEY reg = NULL;
	CHECK_WIN32_DWORD(::RegOpenKeyEx(root, key.c_str(), 0, ulFlags | KEY_WRITE, & reg), 
		L"Error opening '" << HKEY2wstring(root) << L"\\" << key << L"'");
    auto_hkey reg_ptr(reg);
	CHECK_WIN32_DWORD(::RegDeleteValue(reg, name.c_str()),
		L"Error deleting '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"'");
}

void DVLib::RegistryDeleteKey(HKEY root, const std::wstring& key, DWORD ulFlags)
{
	DWORD namesize, subkeys, maxkeyname;
	if (ERROR_SUCCESS != ::RegDeleteKey(root, key.c_str()))
	{
		HKEY reg = NULL;

		CHECK_WIN32_DWORD(::RegOpenKeyEx(root, key.c_str(), 0, ulFlags | KEY_READ, & reg), 
			L"Error opening '" << HKEY2wstring(root) << L"\\" << key << L"'");

        auto_hkey reg_ptr(reg); 

		// query subkey information
		CHECK_WIN32_DWORD(::RegQueryInfoKey(reg, NULL, NULL, NULL, & subkeys, & maxkeyname, NULL, NULL, NULL, NULL, NULL, NULL), 
			L"Error quering '" << HKEY2wstring(root) << L"\\" << key << L"' for subkeys");

		// walk through all subkeys, and recursively delete
		wchar_t name[MAX_PATH] = {0};
		namesize = MAX_PATH;

		while (ERROR_SUCCESS == ::RegEnumKeyEx(reg, 0, name, & namesize, NULL, NULL, NULL, NULL))
		{
			RegistryDeleteKey(root, key + L"\\" + name, ulFlags);
			namesize = MAX_PATH;
		}

		CHECK_WIN32_DWORD(::RegDeleteKey(root, key.c_str()), 
			L"Error deleting '" << HKEY2wstring(root) << L"\\" << key << L"'");
	}
}

void DVLib::RegistrySetStringValue(HKEY root, const std::wstring& key, const std::wstring &name, const std::wstring& value, DWORD ulFlags)
{
	HKEY hkey = NULL;

	CHECK_WIN32_DWORD(::RegCreateKeyEx(root, key.c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, 
		ulFlags | KEY_SET_VALUE, NULL, & hkey, NULL),
		L"Error creating '" << HKEY2wstring(root) << L"\\" << key << L"'");

    auto_hkey hkey_ptr(hkey);

	CHECK_WIN32_DWORD(::RegSetValueEx(hkey, name.c_str(), 0L, REG_SZ, 
		reinterpret_cast<const byte *>(value.c_str()), (value.length() + 1) * sizeof(WCHAR)),
		L"Error setting '" << HKEY2wstring(root) << L"\\" << key << L"'" << name << L"' value");
}

DWORD DVLib::RegistryGetDWORDValue(HKEY root, const std::wstring& key, const std::wstring& name, DWORD ulFlags)
{
    HKEY reg = NULL;

    CHECK_WIN32_DWORD(::RegOpenKeyEx(root, key.c_str(), 0, ulFlags | KEY_READ, & reg),
		L"Error opening '" << HKEY2wstring(root) << L"\\" << key << L"'");

    auto_hkey reg_ptr(reg);

    DWORD dwSize = 0;
    DWORD dwType = 0;

    CHECK_WIN32_DWORD(::RegQueryValueEx(reg, name.c_str(), 0, & dwType, NULL, & dwSize),
        L"Error quering '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"' size");

	CHECK_BOOL(dwType == REG_DWORD && dwSize == sizeof(DWORD),
        L"Error quering '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"', unexpected type");

    DWORD value = 0;
    CHECK_WIN32_DWORD(::RegQueryValueEx(reg, name.c_str(), 0, & dwType, reinterpret_cast<LPBYTE>(& value), & dwSize),
        L"Error quering '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"' value");
    return value;
}

void DVLib::RegistrySetDWORDValue(HKEY root, const std::wstring& key, const std::wstring &name, DWORD value, DWORD ulFlags)
{
	HKEY hkey = NULL;

	CHECK_WIN32_DWORD(::RegCreateKeyEx(root, key.c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, 
		ulFlags | KEY_SET_VALUE, NULL, & hkey, NULL),
		L"Error creating '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"'");

    auto_hkey hkey_ptr(hkey);

	CHECK_WIN32_DWORD(::RegSetValueEx(hkey, name.c_str(), 0L, REG_DWORD, 
		reinterpret_cast<const byte *>(& value), sizeof(DWORD)),
		L"Error setting '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"' value");
}

std::wstring DVLib::HKEY2wstring(HKEY root)
{
	for(int i = 0; i < ARRAYSIZE(HKEY2wstringMap); i++)
	{
		if (HKEY2wstringMap[i].value == root)
			return HKEY2wstringMap[i].name;
	}

	THROW_EX("Unknown HKEY: " << root);
}

HKEY DVLib::wstring2HKEY(const std::wstring& key)
{
	for(int i = 0; i < ARRAYSIZE(HKEY2wstringMap); i++)
	{
		if (HKEY2wstringMap[i].name == key)
			return HKEY2wstringMap[i].value;
	}

	THROW_EX("Unknown HKEY: " << key);
}

std::vector<std::wstring> DVLib::RegistryGetMultiStringValue(HKEY root, const std::wstring& key, const std::wstring& name, DWORD ulFlags)
{
    HKEY reg = NULL;

    CHECK_WIN32_DWORD(::RegOpenKeyEx(root, key.c_str(), 0, ulFlags | KEY_READ, & reg),
        L"Error opening " << HKEY2wstring(root) << L"\\" << key);

    auto_hkey reg_ptr(reg);

    DWORD dwSize = 0;
    DWORD dwType = 0;

    CHECK_WIN32_DWORD(::RegQueryValueEx(reg, name.c_str(), 0, & dwType, NULL, & dwSize),
        L"Error quering '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"' value size");

	CHECK_BOOL(dwType == REG_MULTI_SZ,
        L"Error quering '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"' value, unexpected type " << dwType);

	std::vector<std::wstring> result;
    std::vector<wchar_t> value;
    if (dwSize > 0)
    {
        value.resize(dwSize / sizeof(WCHAR));

        CHECK_WIN32_DWORD(::RegQueryValueEx(reg, name.c_str(), 0, & dwType, reinterpret_cast<LPBYTE>(& * value.begin()), & dwSize),
			L"Error quering '" << HKEY2wstring(root) << L"\\" << key << L"\\" << name << L"' value data");

        value.resize((dwSize - 1) / sizeof(WCHAR));

		std::vector<wchar_t>::iterator l = value.begin();
		std::vector<wchar_t>::iterator r = value.begin();
		while(r != value.end())
		{
			if (* r == 0)
			{
				if (l == r) 
					result.push_back(L"");
				else 
					result.push_back(std::wstring(l, r));
				l = r + 1;
			}
			r++;
		}
    }

	return result;
}

void DVLib::RegistrySetMultiStringValue(HKEY root, const std::wstring& key, const std::wstring &name, const std::vector<std::wstring>& value, DWORD ulFlags)
{
	HKEY hkey = NULL;

	CHECK_WIN32_DWORD(::RegCreateKeyEx(root, key.c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, 
		ulFlags | KEY_SET_VALUE, NULL, & hkey, NULL),
		L"Error creating '" << HKEY2wstring(root) << L"\\" << key << L"'");

    auto_hkey hkey_ptr(hkey);

	std::vector<wchar_t> data;
	for (size_t i = 0; i < value.size(); i++)
	{
		data.insert(data.end(), value[i].begin(), value[i].end());
		data.push_back(0);
	}
	data.push_back(0);

	CHECK_WIN32_DWORD(::RegSetValueEx(hkey, name.c_str(), 0L, REG_MULTI_SZ, 
		reinterpret_cast<const byte *>(& * data.begin()), data.size() * sizeof(WCHAR)),
		L"Error setting '" << HKEY2wstring(root) << L"\\" << key << L"'" << name << L"' value");
}
