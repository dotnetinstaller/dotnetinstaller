#pragma once

class InstallerSession
{
private:
	std::wstring m_tempDirectory;
public:
	InstallerSession();
	// unique session ID
	std::wstring guid;
	// session locale
	DWORD languageid;
	// CAB path
	std::wstring SessionCABPath;
	// additional cmdline arguments
	std::map<std::wstring, std::wstring> AdditionalCmdLineArgs;
	// additional user-defined variables
	std::map<std::wstring, std::wstring> AdditionalControlArgs;
    // get a unique temporary directory for this session
    std::wstring GetSessionTempPath(bool returnonly = false);
	// expand variables
	std::wstring ExpandVariables(const std::wstring& value);
	std::wstring ExpandRegistryVariables(const std::wstring& value);
	std::wstring ExpandPathVariables(const std::wstring& path);
	std::wstring ExpandUserVariables(const std::wstring& value);
	// global instance
	static shared_any<InstallerSession *, close_delete> Instance;
	// save session for subsequent reboot
	void EnableRunOnReboot(const std::wstring& cmd = L"");
	// remove session from subsequent reboot
	void DisableRunOnReboot();
	// returns the reboot command
	std::wstring GetRebootCmd(const std::wstring& additional) const;

};


