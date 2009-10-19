#include "StdAfx.h"
#include "InstallerSession.h"
#include "InstallerLog.h"
#include "InstallerLauncher.h"

#define REGISTRY_CURRENTVERSION_RUN L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"

shared_any<InstallerSession *, close_delete> InstallerSession::Instance;

InstallerSession::InstallerSession()
	: languageid(0)
	, guid(DVLib::GenerateGUIDStringW())
{

}

std::wstring InstallerSession::GetSessionTempPath(bool returnonly)
{
	if (m_tempDirectory.empty() && ! returnonly)
    {
		m_tempDirectory = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), guid);
		DVLib::DirectoryCreate(m_tempDirectory);
    }

    return m_tempDirectory;
}

std::wstring InstallerSession::ExpandVariables(const std::wstring& value)
{
	std::wstring result = DVLib::ExpandEnvironmentVariables(value);
	result = ExpandPathVariables(result);
	result = ExpandRegistryVariables(result);
	return result;	
}

std::wstring InstallerSession::ExpandUserVariables(const std::wstring& s_in)
{
	std::wstring s(s_in);
	std::wstring::size_type i = 0, j = 0;	
	while (((i = s.find(L"[", i)) != s.npos) && ((j = s.find(L"]", i + 1)) != s.npos))
	{
		if (i + 1 != j)
		{
			std::wstring name = s.substr(i + 1, j - i - 1);
			std::wstring value = AdditionalControlArgs[name];			
			s.replace(i, j - i + 1, value);
			i += value.length();
		}
		else
		{
			i = j + 1;
		}
	}
	return s;
}

std::wstring InstallerSession::ExpandPathVariables(const std::wstring& path)
{
	std::wstring s(path);
	std::wstring::size_type i = 0, j = 0;	
	while ((i = s.find(L"#", i)) != s.npos && j != s.npos)
	{
		j = i + 1;
		while(j != s.npos && isalpha(s[j]))
			j++;

		if (i + 1 != j)
		{
			std::wstring name = s.substr(i + 1, j - i - 1);
			std::wstring value;
			if (name == L"CABPATH")
				value = SessionCABPath.empty() ? GetSessionTempPath() : SessionCABPath;
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
			else
			{
				THROW_EX(L"Invalid variable #" << name << L" in '" << path << L"'");
			}

			// don't introduce double-backslashes for paths, bug 4378
			if (j != s.npos)
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
			std::vector<std::wstring> parts = DVLib::split(value_parts[0], L"\\");
			if (parts.size() < 2) THROW_EX(L"Invalid registry path '" << name << L"' in '" << s_in << L"'");
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
					else THROW_EX(L"Invalid WOW option '" << hkey_parts[1] << L"' in '" << s_in << L"'");
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
			std::wstring value;

			if (value_parts.size() > 1 && ! DVLib::RegistryKeyExists(hkey, key_path, key_name, ulFlags))
			{
				value = value_parts[1];
			}
			else
			{
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
					THROW_EX(L"Registry value '" << name << L"' is of unsupported type " << dwType);
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
	if (DVLib::RegistryKeyExists(HKEY_LOCAL_MACHINE, REGISTRY_CURRENTVERSION_RUN, name))
	{
		DVLib::RegistryDeleteValue(HKEY_LOCAL_MACHINE, REGISTRY_CURRENTVERSION_RUN, name);
	}
}

