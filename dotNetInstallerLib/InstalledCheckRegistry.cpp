#include "StdAfx.h"
#include "InstalledCheckRegistry.h"
#include "InstallerLog.h"

InstalledCheckRegistry::InstalledCheckRegistry(void)
{

}

HKEY InstalledCheckRegistry::GetRootKey() const
{
    if (rootkey == L"HKEY_CLASSES_ROOT")
		return HKEY_CLASSES_ROOT;
    if (rootkey == L"HKEY_CURRENT_USER")
		return HKEY_CURRENT_USER;
    if (rootkey == L"HKEY_USERS")
		return HKEY_USERS;
    if (rootkey == L"HKEY_CURRENT_CONFIG")
		return HKEY_CURRENT_CONFIG;
    
	return HKEY_LOCAL_MACHINE;
}

void InstalledCheckRegistry::Load(TiXmlElement * node, InstallerSetting& setting)
{
    LOG(L"----Reading REGISTRY installed check: " << node->AttributeW("path"));
    fieldname = node->AttributeW("fieldname");
    fieldtype = node->AttributeW("fieldtype");
    fieldvalue = node->AttributeW("fieldvalue");
    path = node->AttributeW("path");
    comparison = node->AttributeW("comparison");
    rootkey = node->AttributeW("rootkey");
    wowoption = node->AttributeW("wowoption");
}

// \todo: rewrite with a registry class
bool InstalledCheckRegistry::IsInstalled() const
{
	try
	{
		// http://msdn.microsoft.com/en-us/library/aa384129(VS.85).aspx
		
		std::wstring keypath(path);
		keypath.append(L"\\");
		keypath.append(fieldname);

        LOG(L"Reading Registry: " << keypath);

		DVLib::OperatingSystem type = DVLib::GetOperatingSystemVersion();
		DWORD dwKeyOption = KEY_READ;

		// alternate registry view is available from Windows XP onwards for 64 bit systems
		if (type >= DVLib::winXP)
		{
			// indicates that an application on 64-bit Windows should operate on the 64-bit registry view
			if (_wcsicmp(wowoption.c_str(), L"WOW64_64") == 0)
			{	
				LOG(L"Opening 64-bit registry view (KEY_WOW64_64KEY)");
				dwKeyOption |= KEY_WOW64_64KEY;
			}
			//Indicates that an application on 64-bit Windows should operate on the 32-bit registry view.
			else if (_wcsicmp(wowoption.c_str(), L"WOW64_32") == 0)
			{
				LOG(L"Opening 32-bit registry view (KEY_WOW64_32KEY)");
				dwKeyOption |= KEY_WOW64_32KEY;
			}
		}

		HKEY l_hkey = NULL;
		LONG l_result = RegOpenKeyEx(GetRootKey(), path.c_str(), 0, dwKeyOption, &l_hkey);
		auto_hkey l_hkey_ptr(l_hkey);

		if (l_result != ERROR_SUCCESS)
		{
			LOG(L"***No Registry Entry Found: " << keypath);
			return false;
		}

		LOG(L"Registry Entry Found: " << keypath);
		if (fieldtype == TEXT("REG_DWORD"))
		{
			DWORD wordValue;
			DWORD l_dwordLen = sizeof(DWORD);
			DWORD l_type = REG_DWORD;
			l_result = RegQueryValueEx(l_hkey, fieldname.c_str(), NULL, &l_type, (LPBYTE)&wordValue, &l_dwordLen);
			if (l_result != ERROR_SUCCESS)
				return false;

			DWORD l_checkValue;
			if (_stscanf_s(fieldvalue.c_str(), TEXT("%d"), & l_checkValue) != 1)
			{
				throw std::exception("Invalid registry value to check expected DWORD.");
			}

            LOG(L"Value: " << DVLib::towstring(wordValue));

			if (comparison == TEXT("match"))
			{
				if (l_checkValue == wordValue)
					return true;
				else
					return false;
			}
			else if (comparison == TEXT("version"))
			{
				if (l_checkValue <= wordValue)
					return true;
				else
					return false;
			}
			else if (comparison == TEXT("exists"))
			{
				return true;  
			}
			else
			{
				throw std::exception("Invalid comparison type; expected match, version, or exists.");
			}
		}
		else if (fieldtype == TEXT("REG_SZ"))
		{
			DWORD l_dwordLen = 0;//number of bytes
			DWORD l_type = REG_SZ;
			l_result = RegQueryValueEx(l_hkey,fieldname.c_str(), NULL, &l_type, NULL, &l_dwordLen);
			if (l_result != ERROR_SUCCESS)
				return false;

			size_t numberOfChars = l_dwordLen / sizeof(TCHAR);
			TCHAR * charsRegValue = new TCHAR[ numberOfChars + 1 ];
			ZeroMemory(charsRegValue, numberOfChars+1);

			l_result = RegQueryValueEx(l_hkey,fieldname.c_str(), NULL, &l_type, (LPBYTE)charsRegValue, &l_dwordLen);
			if (l_result != ERROR_SUCCESS)
				return false;

			std::wstring registryValue = charsRegValue;
			delete [] charsRegValue;

            LOG(L"Value: " << registryValue);

			if (comparison == TEXT("match"))
			{
				if (fieldvalue == registryValue)
					return true;
				else
					return false;
			}
			else if (comparison == TEXT("version"))
			{
				if ( DVLib::CompareVersion(fieldvalue, registryValue) <= 0 )
					return true;
				else
					return false;
			}
			else if (comparison == TEXT("exists"))
			{
				return true;
			}
			else if (comparison == TEXT("contains"))
			{
				if (registryValue.find(fieldvalue) != registryValue.npos)
					return true;
				else
					return false;
			}
			else
			{
				throw std::exception("Invalid comparison type; expected match, version, exists, or contains.");
			}
		}
		else if (fieldtype == TEXT("REG_MULTI_SZ"))
		{
			DWORD l_dwordLen = 0;//number of bytes
			DWORD l_type = REG_MULTI_SZ;
			l_result = RegQueryValueEx(l_hkey,fieldname.c_str(), NULL, &l_type, NULL, &l_dwordLen);
			if (l_result != ERROR_SUCCESS)
				return false;

			size_t numberOfChars = l_dwordLen / sizeof(TCHAR);
			TCHAR * charsRegValue = new TCHAR[ numberOfChars + 1 ];
			ZeroMemory(charsRegValue, numberOfChars+1);

			l_result = RegQueryValueEx(l_hkey,fieldname.c_str(), NULL, &l_type, (LPBYTE)charsRegValue, &l_dwordLen);
			if (l_result != ERROR_SUCCESS)
				return false;

			// Check for null values and replace them with spaces.  Because the return value from the 
			// registry can be a series of null terminated strings, it's easiest to replace the null values 
			// at the end of each string with a space in order to make it easier to deal with.
			// There's probably a better way to do this, but this gets the job done.
			for (int ii = 0; ii < (int)numberOfChars; ii++)
			{
				if (charsRegValue[ii] == 0)
				{
					charsRegValue[ii] = ' ';
				}
			}
			std::wstring registryValue = charsRegValue;
			delete [] charsRegValue;

			if (comparison == TEXT("match"))
			{
				if (fieldvalue == registryValue)
					return true;
				else
					return false;
			}
			else if (comparison == TEXT("version"))
			{
				if ( DVLib::CompareVersion(fieldvalue, registryValue) <= 0 )
					return true;
				else
					return false;
			}
			else if (comparison == TEXT("exists"))
			{
				return true;
			}
			else if (comparison == TEXT("contains"))
			{
				if (registryValue.find(fieldvalue) != registryValue.npos)
					return true;
				else
					return false;
			}
			else
			{
				throw std::exception("Invalid comparison type; expected match, version, exists, or contains.");
			}
		}
		else
		{
			throw std::exception("Invalid registry type");
		}
	}
	catch(...)
	{
		return false;
	}
}
