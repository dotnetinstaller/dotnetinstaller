#pragma once

class InstallerSession
{
private:
	std::wstring m_tempDirectory;
	std::wstring m_GUID;
public:
	// CAB path
	std::wstring SessionCABPath;
	// additional cmdline arguments
	std::map<std::wstring, std::wstring> AdditionalCmdLineArgs;
	// get a unique id for this session
	std::wstring GetSessionGUID();
    // get a unique temporary directory for this session
    std::wstring GetSessionTempPath(bool returnonly = false);
	// expand variables
	std::wstring ExpandVariables(const std::wstring& value);
	std::wstring ExpandRegistryVariables(const std::wstring& value);
	std::wstring ExpandPathVariables(const std::wstring& path);
	// global instance
	static shared_any<InstallerSession *, close_delete> Instance;
	// save session for subsequent reboot
	void EnableRunOnReboot(const std::wstring& cmd = L"");
	// remove session from subsequent reboot
	void DisableRunOnReboot();
};


