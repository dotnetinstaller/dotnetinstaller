#pragma once

namespace DVLib
{
	bool ShellExecuteDefault(LPCTSTR file);

    // Can be used to check if a file or directory exists
	bool FileExists(LPCTSTR filename);

	//Return the file name of a specified file path.
	// es. GetFileNameFromFullFilePath("c:\temp\pippo.txt") == "pippo.txt"
	// es. GetFileNameFromFullFilePath("http:\\temp\pippo.txt") == "pippo.txt"
	// Path Separators: \ or /
	CString GetFileNameFromFullFilePath(LPCTSTR p_FileFullPath);

	// Return the path of a specified file path (without the last path separator).
	//  es. GetPathFromFullFilePath("c:\temp\pippo.txt") == "c:\temp"
	//  es. GetPathFromFullFilePath("http:\\temp\pippo.txt") == "http:\\temp"
	//  Path Separators: \ or /
	CString GetPathFromFullFilePath(LPCTSTR p_FileFullPath);

	//Concatenates two strings that represent properly formed paths into one path
	// Non uso PathCombine perchè non è presente in Win95
	CString PathCombine(LPCTSTR p_Path1, LPCTSTR p_Path2, char p_separator = '\\');
}