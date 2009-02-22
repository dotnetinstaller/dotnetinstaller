///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://kickme.to/elmue)
// Date: 5-12-2007
//
// Filename: File.hpp
//
// Classes:
// - CFile
//
// Purpose: Some utilities for file and directoy operations
//

#pragma once

#include "Utf7.hpp"

namespace Cabinet
{

// -------------------------------------------------------------
// The following defines are used for compression AND extraction
// -------------------------------------------------------------

// Stores in the file attributes that the file was compressed using UTC time
#define FILE_ATTR_UTC_TIME     0x100

class cFile
{
public:
	// creates all not yet existing folders in s8_DirTree
	// Example: s8_DirTree = "C:\Temp\Test\Extract\"  or
	//          s8_DirTree = "C:\Temp\Test\Extract"
	// If only the path      "C:\Temp" exists the subfolders "Test" and "Extract" will be created
	// returns 0 if OK, returns a Win32 Error code on error
	static UINT CreateFolderTreeA(char* s8_DirTree)
	{
		CUtf7   i_Utf;
		char   s8_Folder[1000];
		char   s8_Parent[1000];
		strcpy(s8_Folder, s8_DirTree);
		strcpy(s8_Parent, s8_DirTree);

		BOOL b_Utf = CUtf7::IsUtf (s8_Folder);
		if  (b_Utf)
		{
			i_Utf.Decode(s8_Folder);
			if (CheckDirectoryExistsW(i_Utf.Decoded()))
				return 0;
		}
		else
		{
			if (CheckDirectoryExistsA(s8_Folder))
				return 0;
		}

		RemovePathTerminationA(s8_Parent);

		// Cut the last Folder from the tree
		char* s8_Pos = strrchr(s8_Parent, '\\');
		if (s8_Pos > 0) s8_Pos[0] = 0;

		// recursively create all the parent folders (if necessary)
		UINT u32_Error = CreateFolderTreeA(s8_Parent);
		if  (u32_Error)
			return u32_Error;

		// create the folder itself
		if (b_Utf)
		{
			if (!CreateDirectoryW(i_Utf.Decoded(), 0))
				return GetLastError();
		}
		else
		{
			if (!CreateDirectoryA(s8_Folder, 0))
				return GetLastError();
		}
		return 0;
	}

	static BOOL CheckDirectoryExistsA(char* s8_Folder)
	{
		UINT u32_Attr = GetFileAttributesA(s8_Folder);

		if (u32_Attr == 0xFFFFFFFF)
			return FALSE;

		return (u32_Attr & FILE_ATTRIBUTE_DIRECTORY) > 0;
	}

	static BOOL CheckDirectoryExistsW(WCHAR* u16_Folder)
	{
		UINT u32_Attr = GetFileAttributesW(u16_Folder);

		if (u32_Attr == 0xFFFFFFFF)
			return FALSE;

		return (u32_Attr & FILE_ATTRIBUTE_DIRECTORY) > 0;
	}

	// "C:\Temp" --> "C:\Temp\"
	static void TerminatePathA(char* s8_Path)
	{
		int s32_Len = strlen(s8_Path);

		if (s32_Len > 1 && s8_Path[s32_Len-1] != '\\')
		{
			s8_Path[s32_Len]   = '\\';
			s8_Path[s32_Len+1] = 0;
		}
	}

	// "C:\Temp" --> "C:\Temp\"
	static void TerminatePathW(WCHAR* u16_Path)
	{
		int s32_Len = wcslen(u16_Path);

		if (s32_Len > 1 && u16_Path[s32_Len-1] != '\\')
		{
			u16_Path[s32_Len]   = '\\';
			u16_Path[s32_Len+1] = 0;
		}
	}

	// "C:\Temp\" --> "C:\Temp"
	static void RemovePathTerminationA(char* s8_Path)
	{
		int s32_Len = strlen(s8_Path);

		if (s32_Len > 1 && s8_Path[s32_Len-1] == '\\')
		{
			s8_Path[s32_Len-1] = 0;
		}
	}
};

} // Namespace Cabinet
