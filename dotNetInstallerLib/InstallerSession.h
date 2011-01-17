#pragma once

#include "InstallSequence.h"

class InstallerSession
{
public:
	InstallerSession();
	// unique session ID
	std::wstring guid;
	// session locale
	DWORD languageid;
	// language string
	std::wstring language;
	// CAB path
	std::wstring cabpath;
	// additional cmdline arguments
	std::map<std::wstring, std::wstring> AdditionalCmdLineArgs;
	// additional user-defined variables
	std::map<std::wstring, std::wstring> AdditionalControlArgs;
    // get a unique temporary directory for CAB files in this session
    std::wstring GetSessionCabPath(bool returnonly = false);
	// expand variables
	std::wstring ExpandVariables(const std::wstring& value);
	std::wstring ExpandRegistryVariables(const std::wstring& value);
	bool ExpandRegistryVariable(const std::wstring& variable, std::wstring& value);
	std::wstring ExpandPathVariables(const std::wstring& path);
	std::wstring ExpandUserVariables(const std::wstring& value);
	// sequence
	InstallSequence sequence;
	// lcid type
	DVLib::LcidType lcidtype;
	// global instance
	static shared_any<InstallerSession *, close_delete> Instance;
	// save session for subsequent reboot
	void EnableRunOnReboot(const std::wstring& cmd = L"");
	// remove session from subsequent reboot
	void DisableRunOnReboot();
	// returns the reboot command
	std::wstring GetRebootCmd(const std::wstring& additional) const;
	// returns the restart command line
	std::wstring GetRestartCommandLine(const std::wstring& additional) const;
};


