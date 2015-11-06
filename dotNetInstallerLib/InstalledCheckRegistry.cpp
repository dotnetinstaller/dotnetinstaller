#include "StdAfx.h"
#include "InstallerSession.h"
#include "XmlAttribute.h"
#include "InstalledCheckRegistry.h"
#include "InstallerLog.h"

InstalledCheckRegistry::InstalledCheckRegistry()
{

}

void InstalledCheckRegistry::Load(TiXmlElement * node)
{
    fieldname = node->Attribute("fieldname");
    fieldtype = DVLib::UTF8string2wstring(node->Attribute("fieldtype"));
    fieldvalue = node->Attribute("fieldvalue");
    path = node->Attribute("path");
    comparison = DVLib::UTF8string2wstring(node->Attribute("comparison"));
    rootkey = DVLib::UTF8string2wstring(node->Attribute("rootkey"));
    wowoption = DVLib::UTF8string2wstring(node->Attribute("wowoption"));
    defaultvalue = node->Attribute("defaultvalue");
    LOG(L"Loaded 'registry' installed check '" << rootkey << L"\\" << path << L"\\" << fieldname << L"'");
}

bool InstalledCheckRegistry::IsInstalledValue() const
{
    std::wstring keypath = GetKeyPath();
    DWORD dwKeyOption = GetKeyOption();

    if (! DVLib::RegistryKeyExists(DVLib::wstring2HKEY(rootkey), path, dwKeyOption))
    {
        bool default_result = defaultvalue.GetBoolValue(false);
        LOG(L"*** No registry key found: " << keypath << L", default value: " << (default_result ? L"true" : L"false"));
        return default_result;
    }
    else if (! DVLib::RegistryValueExists(DVLib::wstring2HKEY(rootkey), path, fieldname, dwKeyOption))
    {
        bool default_result = defaultvalue.GetBoolValue(false);
        LOG(L"*** No registry value found: " << keypath << L", default value: " << (default_result ? L"true" : L"false"));
        return default_result;
    }

    if (fieldtype.empty())
    {
        THROW_EX("Missing registry type for " << keypath);
    }

    if (fieldtype == L"REG_DWORD")
    {
        if (fieldvalue.empty())
        {
            THROW_EX("Missing fieldvalue number for " << keypath);
        }

        DWORD regfieldvalue = DVLib::RegistryGetDWORDValue(
            DVLib::wstring2HKEY(rootkey), path, fieldname, dwKeyOption);
        LOG(L"Registry value: " << regfieldvalue);

        DWORD checkvalue = static_cast<DWORD>(DVLib::wstring2long(fieldvalue));
        LOG(L"Check value: " << checkvalue);

        if (comparison == L"match")
            return (regfieldvalue == checkvalue);
        else if (comparison == L"version")
            return (regfieldvalue >= checkvalue);
        // EXPERIMENTAL
        else if (comparison == L"version_patch")
            return (regfieldvalue >= checkvalue);
        // EXPERIMENTAL
        else if (comparison == L"version_eq")
            return (regfieldvalue == checkvalue);
        else if (comparison == L"version_lt")
            return (regfieldvalue < checkvalue);
        else if (comparison == L"version_le")
            return (regfieldvalue <= checkvalue);
        else if (comparison == L"version_gt")
            return (regfieldvalue > checkvalue);
        else if (comparison == L"version_ge")
            return (regfieldvalue >= checkvalue);
        else
        {
            THROW_EX("Invalid comparison type: " << comparison);
        }
    }
    else if (fieldtype == TEXT("REG_SZ"))
    {
        std::wstring regfieldvalue = DVLib::RegistryGetStringValue(
            DVLib::wstring2HKEY(rootkey), path, fieldname, dwKeyOption);
        LOG(L"Registry value: " << regfieldvalue);

        if (comparison == TEXT("match"))
            return (fieldvalue == regfieldvalue);
        else if (comparison == TEXT("version"))
            return (DVLib::CompareVersion(regfieldvalue, fieldvalue) >= 0);
        // EXPERIMENTAL
        else if (comparison == TEXT("version_patch"))
            return (DVLib::CompareVersion(regfieldvalue, fieldvalue) >= 0);
        // EXPERIMENTAL
        else if (comparison == TEXT("version_eq"))
            return (DVLib::CompareVersion(regfieldvalue, fieldvalue) == 0);
        else if (comparison == TEXT("version_lt"))
            return (DVLib::CompareVersion(regfieldvalue, fieldvalue) < 0);
        else if (comparison == TEXT("version_le"))
            return (DVLib::CompareVersion(regfieldvalue, fieldvalue) <= 0);
        else if (comparison == TEXT("version_gt"))
            return (DVLib::CompareVersion(regfieldvalue, fieldvalue) > 0);
        else if (comparison == TEXT("version_ge"))
            return (DVLib::CompareVersion(regfieldvalue, fieldvalue) >= 0);
        else if (comparison == TEXT("contains"))
            return (regfieldvalue.find(fieldvalue.GetValue()) != regfieldvalue.npos);
        else
        {
            THROW_EX("Invalid comparison type: " << comparison);
        }
    }
    else if (fieldtype == TEXT("REG_MULTI_SZ"))
    {
        std::vector<std::wstring> regfieldvalues = DVLib::RegistryGetMultiStringValue(
            DVLib::wstring2HKEY(rootkey), path, fieldname, dwKeyOption);
        LOG(L"Registry value: " << regfieldvalues.size() << L" string(s)");
        std::vector<std::wstring> fieldvalues = DVLib::split(fieldvalue, L",");

        if (comparison == TEXT("match"))
        {
            return (fieldvalues == regfieldvalues);
        }
        else if (comparison == TEXT("contains"))
        {
            for each (const std::wstring& currentfieldvalue in fieldvalues)
            {
                bool found = false;
                for each (const std::wstring& regfieldvalue in regfieldvalues)
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
            THROW_EX("Invalid comparison type for REG_MULTI_SZ: " << comparison);
        }
    }
    else
    {
        THROW_EX("Unsupported registry type: " << fieldtype);
    }
}

bool InstalledCheckRegistry::IsInstalledKeyExists() const 
{
    std::wstring keypath = GetKeyPath();
    DWORD dwKeyOption = GetKeyOption();
    bool exists = DVLib::RegistryKeyExists(DVLib::wstring2HKEY(rootkey), path, dwKeyOption);
    LOG(L"Registry key '" << keypath << L"' " << (exists ? L"found" : L"not found"));
    return exists;
}

bool InstalledCheckRegistry::IsInstalledValueExists() const 
{
    std::wstring keypath = GetKeyPath();
    DWORD dwKeyOption = GetKeyOption();
    bool exists = DVLib::RegistryValueExists(DVLib::wstring2HKEY(rootkey), path, fieldname, dwKeyOption);
    LOG(L"Registry value '" << keypath << L"' " << (exists ? L"found" : L"not found"));
    return exists;
}

bool InstalledCheckRegistry::IsInstalledExists() const 
{
    return fieldname.empty()
        ? IsInstalledKeyExists()
        : IsInstalledValueExists();
}

std::wstring InstalledCheckRegistry::GetKeyPath() const
{
    std::wstring keypath = path.GetValue();
    if (! fieldname.GetValue().empty())
    {
        keypath += L"\\";
        keypath += fieldname.GetValue();
        LOG(L"Checking whether registry value '" << keypath << L"' exists");
    }
    else
    {
        LOG(L"Checking whether registry key '" << keypath << L"' exists");
    }
    return keypath;
}

DWORD InstalledCheckRegistry::GetKeyOption() const
{
    DVLib::OperatingSystem type = DVLib::GetOperatingSystemVersion();
    DWORD dwKeyOption = KEY_READ;

    // alternate registry view is available from Windows XP onwards for 64 bit systems
    if (type >= DVLib::winXP && ! wowoption.empty())
    {
        // indicates that an application on 64-bit Windows should operate on the 64-bit registry view
        if (_wcsicmp(wowoption.GetValue().c_str(), L"WOW64_64") == 0)
        {	
            LOG(L"Opening 64-bit registry view (KEY_WOW64_64KEY)");
            dwKeyOption |= KEY_WOW64_64KEY;
        }
        //Indicates that an application on 64-bit Windows should operate on the 32-bit registry view.
        else if (_wcsicmp(wowoption.GetValue().c_str(), L"WOW64_32") == 0)
        {
            LOG(L"Opening 32-bit registry view (KEY_WOW64_32KEY)");
            dwKeyOption |= KEY_WOW64_32KEY;
        }
        else if (_wcsicmp(wowoption.GetValue().c_str(), L"NONE") == 0)
        {
            // ignore
        }
        else
        {
            THROW_EX(L"Invalid WOW option '" << wowoption << L"'");
        }
    }

    return dwKeyOption;
}

bool InstalledCheckRegistry::IsInstalled() const
{
    if (comparison == L"exists")
        return IsInstalledExists();
    else if (comparison == L"key_exists")
        return IsInstalledKeyExists();
    else if (comparison == L"value_exists")
        return IsInstalledValueExists();
    else 
        return IsInstalledValue();
}
