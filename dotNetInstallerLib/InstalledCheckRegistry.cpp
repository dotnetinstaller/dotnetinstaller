#include "StdAfx.h"
#include "InstalledCheckRegistry.h"
#include "InstallerLog.h"

InstalledCheckRegistry::InstalledCheckRegistry(void)
{

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

bool InstalledCheckRegistry::IsInstalled() const
{
	std::wstring keypath(path + L"\\" + fieldname);
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

	if (! DVLib::RegistryKeyExists(DVLib::wstring2HKEY(rootkey), path, fieldname, dwKeyOption))
	{
		LOG(L"***No registry key found: " << keypath);
		return false;
	}

	LOG(L"Registry key found: " << keypath);
	if (fieldtype == L"REG_DWORD")
	{
		DWORD regfieldvalue = DVLib::RegistryGetDWORDValue(DVLib::wstring2HKEY(rootkey), path, fieldname, dwKeyOption);
        LOG(L"Registry value: " << regfieldvalue);

		DWORD checkvalue = static_cast<DWORD>(DVLib::wstring2long(fieldvalue));
        LOG(L"Check value: " << checkvalue);

		if (comparison == L"match")
		{
			return (checkvalue == regfieldvalue);
		}
		else if (comparison == L"version")
		{
			return (checkvalue <= regfieldvalue);
		}
		else if (comparison == L"exists")
		{
			return true;  
		}
		else
		{
			THROW_EX("Invalid comparison type: " << comparison);
		}
	}
	else if (fieldtype == TEXT("REG_SZ"))
	{
		std::wstring regfieldvalue = DVLib::RegistryGetStringValue(DVLib::wstring2HKEY(rootkey), path, fieldname, dwKeyOption);
        LOG(L"Registry value: " << regfieldvalue);

		if (comparison == TEXT("match"))
		{
			return (fieldvalue == regfieldvalue);
		}
		else if (comparison == TEXT("version"))
		{
			return (DVLib::CompareVersion(fieldvalue, regfieldvalue) <= 0);
		}
		else if (comparison == TEXT("exists"))
		{
			return true;
		}
		else if (comparison == TEXT("contains"))
		{
			return (regfieldvalue.find(fieldvalue) != regfieldvalue.npos);
		}
		else
		{
			THROW_EX("Invalid comparison type: " << comparison);
		}
	}
	else if (fieldtype == TEXT("REG_MULTI_SZ"))
	{
		std::vector<std::wstring> regfieldvalues = DVLib::RegistryGetMultiStringValue(DVLib::wstring2HKEY(rootkey), path, fieldname, dwKeyOption);
		LOG(L"Registry value: " << regfieldvalues.size() << L" string(s)");
		std::vector<std::wstring> fieldvalues = DVLib::split(fieldvalue, L",");

		if (comparison == TEXT("match"))
		{
			return (fieldvalues == regfieldvalues);
		}
		else if (comparison == TEXT("exists"))
		{
			return true;
		}
		else if (comparison == TEXT("contains"))
		{
			for each (const std::wstring& regfieldvalue in regfieldvalues)
			{
				bool found = false;
				for each (const std::wstring currentfieldvalue in fieldvalues)
				{
					if (regfieldvalue == currentfieldvalue)
					{
						found = true;
						break;
					}
				}
				
				if (! found) 
					return false;
			}

			return true;
		}
		else
		{
			THROW_EX("Invalid comparison type: " << comparison);
		}
	}
	else
	{
		THROW_EX("Unsupported registry type: " << fieldtype);
	}
}
