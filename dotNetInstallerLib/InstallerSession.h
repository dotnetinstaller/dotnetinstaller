#pragma once

class InstallerSession
{
private:
	static std::wstring s_GUID;
	static std::wstring s_tempDirectory;
public:
	// session CAB path
	static std::wstring s_sessioncabpath;
	// additional cmdline arguments
	static std::map<std::wstring, std::wstring> s_AdditionalCmdLineArgs;
	// get a unique id for this session
	static std::wstring GetSessionGUID();
    // get a unique temporary directory for this session
    static std::wstring GetSessionTempPath(bool returnonly = false);
	// make a session path
	static std::wstring MakePath(const std::wstring&);
};
