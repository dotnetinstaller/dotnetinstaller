#pragma once

namespace DVLib
{
	// does a file exist?
	bool FileExists(const std::string& filename);
	bool FileExists(const std::wstring& filename);
	// create a temporary file and return its name
	std::string GetTemporaryFileNameA();
	std::wstring GetTemporaryFileNameW();
	// copy a file
	void FileCopy(const std::string& from, const std::string& to, bool overwrite = true);
	void FileCopy(const std::wstring& from, const std::wstring& to, bool overwrite = true);
	// move a file
	void FileMove(const std::string& from, const std::string& to);
	void FileMove(const std::wstring& from, const std::wstring& to);
	// delete a file
	void FileDelete(const std::string& filename);
	void FileDelete(const std::wstring& filename);
	// get file size (< 2GB)
	long GetFileSize(const std::wstring& filename);
	long GetFileSize(const std::string& filename);
    // write data to a file
	void FileWrite(
		const std::wstring& filename, 
        const std::vector<char>& data,
        DWORD dwShareMode = GENERIC_READ | GENERIC_WRITE,
        DWORD dwCreationDisposition = CREATE_ALWAYS,
        DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL);
	// create an empty file
	void FileCreate(
		const std::wstring& filename, 
		DWORD dwDesiredAccess = GENERIC_READ | GENERIC_WRITE,
		DWORD dwShareMode = 0,
        DWORD dwCreationDisposition = CREATE_ALWAYS,
        DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL);
	// read contents of a file
	std::vector<char> FileReadToEnd(const std::wstring& filename);
	
	struct TranslationInfo 
	{
		WORD wLanguage;
		WORD wCodePage;
	};
	
	struct FileVersionInfo
	{
		VS_FIXEDFILEINFO fixed_info;
		TranslationInfo translation_info;
	};

	// get executable file version information
	FileVersionInfo GetFileVersionInfo(const std::wstring& filename);
	// get executable file version string
	std::wstring GetFileVersion(const std::wstring& filename);

	// returns true if the resource exists
	bool ResourceExists(HMODULE h, const std::wstring& resource, const std::wstring& type);
	// load resource data from a module
	template<class T>
	std::vector<T> LoadResourceData(HMODULE h, const std::wstring& resource, const std::wstring& type);

	// 4-part file version
	struct FileVersion
	{
		int major;
		int minor;
		int build;
		int rev;
	};

	FileVersion wstring2fileversion(std::wstring version);
	std::wstring fileversion2wstring(const FileVersion& version);
	// compare a Windows-specific 4-part version
	int CompareVersion(const std::wstring& l, const std::wstring& r);
}
