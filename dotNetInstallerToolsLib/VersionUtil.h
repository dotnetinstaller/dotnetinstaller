#pragma once
namespace DVLib
{
	// 4-part version
	struct Version
	{
		int major;
		int minor;
		int build;
		int rev;
	};

	Version wstring2version(std::wstring version);
	std::wstring version2wstring(const Version& version);
	// compare a Windows-specific 4-part version
	int CompareVersion(const std::wstring& l, const std::wstring& r);
	int CompareSemanticVersion(const std::wstring& l, const std::wstring& r);
	bool CompareVersion(const std::wstring& comparison, const std::list<std::wstring>& valuesToCompare, const std::wstring& checkValue);
}