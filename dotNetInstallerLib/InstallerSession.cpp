#include "StdAfx.h"
#include "InstallerSession.h"
#include "InstallerLog.h"
#include "InstallerLauncher.h"
#include "InstallUILevel.h"

#define REGISTRY_CURRENTVERSION_RUN L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"

shared_any<InstallerSession *, close_delete> InstallerSession::Instance;

InstallerSession::InstallerSession()
: languageid(0)
, guid(DVLib::GenerateGUIDStringW())
, sequence(SequenceInstall)
, lcidtype(DVLib::LcidUserExe)
{

}

std::wstring InstallerSession::GetSessionCabPath(bool returnonly)
{
    if (cabpath.empty() && ! returnonly)
    {
        cabpath = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), guid);
        DVLib::DirectoryCreate(cabpath);
    }

    return ExpandVariables(cabpath);
}

std::wstring InstallerSession::ExpandVariables(const std::wstring& value)
{
    std::wstring result = DVLib::ExpandEnvironmentVariables(value);
    result = ExpandPathVariables(result);
    result = ExpandRegistryVariables(result);
    result = ExpandUserVariables(result);
    return result;
}

std::wstring InstallerSession::ExpandUserVariables(const std::wstring& s_in)
{
    static wchar_t const openBracketEscape[] = L"[\\[]";
    static size_t const openBracketEscapeSize = sizeof(openBracketEscape) / sizeof(openBracketEscape[0])- 1;
    static wchar_t const closeBracketEscape[] = L"[\\]]";
    static size_t const closeBracketEscapeSize = sizeof(closeBracketEscape) / sizeof(closeBracketEscape[0]) - 1;

    std::wstring s(s_in);
    std::wstring::size_type current = 0, open = s.npos;	
    while ((current = s.find_first_of(L"[]", current)) != s.npos) {
        if (s[current] == L'[') {
            if (s.compare(current, openBracketEscapeSize, openBracketEscape, openBracketEscapeSize) == 0) {
                s.erase(++current, openBracketEscapeSize - 1);
            } else if (s.compare(current, closeBracketEscapeSize, closeBracketEscape, closeBracketEscapeSize) == 0) {
                s.erase(current++, closeBracketEscapeSize - 1);
            } else if (open == s.npos) {
                open = current++;
            }
        } else if (open != s.npos) {
            if (open + 1 == current) {
                ++current;
            } else {
                std::wstring value = AdditionalControlArgs[s.substr(open + 1, current - open - 1)];			
                s.replace(open, current - open + 1, value);
                current = open + value.size();
            }
            open = s.npos;
        } else {
            ++current;
        }
    }

    return s;
}

std::wstring InstallerSession::ExpandPathVariables(const std::wstring& path)
{
    std::wstring s(path);
    std::wstring::size_type i = 0, j = 0;	
    while ((i = s.find(L"#", i)) != s.npos && j != s.size())
    {
        j = i + 1;
        while(j != s.size() && isalpha(s[j]))
            j++;

        if (i + 1 != j)
        {
            std::wstring name = s.substr(i + 1, j - i - 1);
            std::wstring value;
            if (name == L"CABPATH")
                value = GetSessionCabPath();
            else if (name == L"APPPATH")
                value = DVLib::GetModuleDirectoryW();
            else if (name == L"SYSTEMPATH")
                value = DVLib::GetSystemDirectoryW();
            else if (name == L"WINDOWSPATH")
                value = DVLib::GetWindowsDirectoryW();
            else if (name == L"SYSTEMWINDOWSPATH")
                value = DVLib::GetSystemWindowsDirectory();
            else if (name == L"TEMPPATH")
                value = DVLib::GetTemporaryDirectoryW();
            else if (name == L"GUID")
                value = guid;
            else if (name == L"PID")
                value = DVLib::towstring(::GetCurrentProcessId());
            else if (name == L"UILEVEL")
                value = InstallUILevelSetting::ToString(InstallUILevelSetting::Instance->GetUILevel());
            else if (name == L"LANGID")
                value = DVLib::towstring(languageid);
            else if (name == L"LANGUAGE")
                value = language;
            else if (name == L"STARTPATH")
                value = DVLib::GetModuleDirectoryW();
            else if (name == L"STARTEXE")
                value = DVLib::GetModuleFileNameW();
            else if (name == L"STARTFILENAME")
                value = DVLib::GetFileNameW(DVLib::GetModuleFileNameW());
            else if (name == L"OSLANGID")
                value = DVLib::towstring(DVLib::GetOperatingSystemLCID(InstallerSession::Instance->lcidtype));
            else if (name == L"OSLOCALE")
                value = DVLib::GetISOLocale(DVLib::GetOperatingSystemLCID(InstallerSession::Instance->lcidtype));
            else
            {
                THROW_EX(L"Invalid variable #" << name << L" in '" << path << L"'");
            }

            // don't introduce double-backslashes for paths, bug 4378
            if (j != s.size())
            {
                switch(s[j])
                {
                case L'\\':
                    value = DVLib::trimright(value, L"\\");
                    break;
                }
            }

            s.replace(i, j - i, value);
            i += value.length();
        }
        else
        {
            i = j;
        }
    }
    return s;
}

bool InstallerSession::ExpandRegistryVariable(const std::wstring& variable, std::wstring& value)
{
    std::vector<std::wstring> parts = DVLib::split(variable, L"\\");
    if (parts.size() < 2) THROW_EX(L"Invalid registry path '" << variable << L"'");
    // hkey
    ULONG ulFlags = 0;
    std::vector<std::wstring> hkey_parts = DVLib::split(parts[0], L":", 2);
    HKEY hkey = DVLib::wstring2HKEY(hkey_parts[0]);
    DVLib::OperatingSystem type = DVLib::GetOperatingSystemVersion();
    if (type >= DVLib::winXP)
    {
        if (hkey_parts.size() > 1)
        {
            if (hkey_parts[1] == L"WOW64_64") ulFlags |= KEY_WOW64_64KEY;
            else if (hkey_parts[1] == L"WOW64_32") ulFlags |= KEY_WOW64_32KEY;
            else THROW_EX(L"Invalid WOW option '" << hkey_parts[1] << L"' in '" << variable << L"'");
        }
    }
    parts.erase(parts.begin());
    // key name
    std::wstring key_name;
    if (parts.size() > 1)
    {
        key_name = parts[parts.size() - 1];
        parts.erase(parts.end() - 1);
    }
    // path
    std::wstring key_path = DVLib::join(parts, L"\\");

    if (! DVLib::RegistryValueExists(hkey, key_path, key_name, ulFlags))
    {
        return false;
    }

    DWORD dwType = DVLib::RegistryGetValueType(hkey, key_path, key_name, ulFlags);
    switch(dwType)
    {
    case REG_SZ:
        value = DVLib::RegistryGetStringValue(hkey, key_path, key_name, ulFlags);
        break;
    case REG_DWORD:
        value = DVLib::towstring(DVLib::RegistryGetDWORDValue(hkey, key_path, key_name, ulFlags));
        break;
    case REG_MULTI_SZ:
        value = DVLib::join(DVLib::RegistryGetMultiStringValue(hkey, key_path, key_name, ulFlags), L",");
        break;
    default:
        THROW_EX(L"Registry value '" << key_path << L"\\" << key_name << L"' is of unsupported type " << dwType);
    }

    return true;
}

std::wstring InstallerSession::ExpandRegistryVariables(const std::wstring& s_in)
{
    std::wstring s(s_in);
    std::wstring::size_type i = 0, j = 0;	
    while (((i = s.find(L"@[", i)) != s.npos) && ((j = s.find(L"]", i + 2)) != s.npos))
    {
        if (i + 2 != j)
        {
            std::wstring name = s.substr(i + 2, j - i - 2);
            std::vector<std::wstring> value_parts = DVLib::split(name, L",", 2);
            std::vector<std::wstring> registry_parts = DVLib::split(value_parts[0], L"|");

            std::wstring value;
            bool resolved = false;

            for (unsigned int r = 0; r < registry_parts.size(); r++)
            {
                if (ExpandRegistryVariable(registry_parts[r], value))
                {
                    resolved = true;
                    break;
                }
            }

            if (! resolved)
            {
                if (value_parts.size() > 1) 
                {
                    // default to the contents of the last value
                    value = value_parts[1];
                }
            }

            s.replace(i, j - i + 1, value);
            i += value.length();
        }
        else
        {
            i = j + 2;
        }
    }
    return s;
}

std::wstring InstallerSession::GetRebootCmd(const std::wstring& add) const
{
    std::wstringstream reboot_cmd;
    // launcher command-line
    reboot_cmd << InstallerLauncher::Instance->GetCmd();
    // additional switches
    if (! add.empty())
    {
        reboot_cmd << L" " << add;
    }
    // additional reboot switch
    if (reboot_cmd.str().find(L"/Reboot") == std::wstring::npos)
    {
        reboot_cmd << L" /Reboot";
    }
    return reboot_cmd.str();
}

// Get the command line that was used to lauch the current
// instance and append the supplied parameters.
std::wstring InstallerSession::GetRestartCommandLine(const std::wstring& add) const
{
    std::wstringstream restart_cmd;

    // launcher command-line
    restart_cmd << InstallerLauncher::Instance->GetCommandLine();

    // Don't duplicate option
    if (restart_cmd.str().find(add) == std::wstring::npos)
    {
        // additional switches
        if (! add.empty())
        {
            restart_cmd << L" " << add;
        }
    }

    return restart_cmd.str();
}

void InstallerSession::EnableRunOnReboot(const std::wstring& add)
{	
    std::wstring reboot_cmd = GetRebootCmd(add);
    std::wstring filename = DVLib::GetFileNameW(DVLib::GetModuleFileNameW());
    LOG(L"Writing HKEY_LOCAL_MACHINE\\" << REGISTRY_CURRENTVERSION_RUN << L"\\" << filename << L": " << reboot_cmd);
    DVLib::RegistrySetStringValue(HKEY_LOCAL_MACHINE, 
        REGISTRY_CURRENTVERSION_RUN, 
        filename,
        reboot_cmd);
};

void InstallerSession::DisableRunOnReboot()
{
    std::wstring name = DVLib::GetFileNameW(DVLib::GetModuleFileNameW());
    if (DVLib::RegistryValueExists(HKEY_LOCAL_MACHINE, REGISTRY_CURRENTVERSION_RUN, name))
    {
        DVLib::RegistryDeleteValue(HKEY_LOCAL_MACHINE, REGISTRY_CURRENTVERSION_RUN, name);
    }
}
