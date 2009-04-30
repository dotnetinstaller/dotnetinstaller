#include "StdAfx.h"
#include "File.h"
#include <shellapi.h>

bool DVLib::ShellExecuteDefault(LPCTSTR file)
{
	// if environment variables are in the string for ShellExecute then replace these variables first.
	// Using ShellExecuteEx API function with setting the flag SEE_MASK_DOENVSUBST does not working in this case
	// because environment variables can also be placed in the parameters for the new process.
	CString complete = file;
	CString search;
	CString environment;
	CString replace;
	int startPos = 0;
	int endPos = 0;
	
	while (1)
	{
		// serach first %
		startPos = complete.Find(TEXT("%"), 0);
		if (startPos != -1)
		{
			// search second %
			endPos = complete.Find(TEXT("%"), startPos + 1);
		}
		else
		{
			// break if not found
			break;
		}
		// second % found and minimum one character between the two % chars?
		if (endPos != -1 && endPos - startPos > 1)
		{
			environment = complete.Mid(startPos + 1, endPos - startPos - 1);
			search = complete.Mid(startPos, endPos - startPos + 1);
			replace.GetEnvironmentVariable(environment);
			complete.Replace(search, replace);
		}
		else
		{
			// break if it not so
			break;
		}
	}
	
	// parsing the parameters from the passed file
	complete.Trim();
	startPos = 0;
	// starts the string with "
	if (complete.GetAt(0) == '"')
	{
		// then start searching at position 1
		startPos = 1;
	}
	// search for space or "
	endPos = complete.Find(startPos == 0 ? TEXT(" ") : TEXT("\""), startPos);
	HINSTANCE l_hInstance;
	// when character found and it is not the last character the are parameters available
	if (endPos != -1 && endPos < complete.GetLength() - 1)
	{
		// parameters availabel!
		CString parameters = complete.Mid(endPos + 1 + startPos);
		CString fileOnly = complete.Mid(startPos, endPos - startPos);
		l_hInstance = ShellExecute(NULL,NULL,fileOnly,parameters,NULL,SW_SHOWNORMAL);
	}
	else
	{
		// no parameters available
		l_hInstance = ShellExecute(NULL,NULL,file,NULL,NULL,SW_SHOWNORMAL);
	}

	if ( l_hInstance <= (HINSTANCE)32 )
		return false;
	else
		return true;
}

// check if a file or directory exists
bool DVLib::FileExists(LPCTSTR filename)
{
	// removing double quotes from the path ensures Win32 will validate a good path
	CString fileNameNoDoubleQuotes = CString(filename);
	fileNameNoDoubleQuotes.Trim(_T('"'));

	DWORD ret = GetFileAttributes(fileNameNoDoubleQuotes);
	if (ret == INVALID_FILE_ATTRIBUTES)
		return false;
	else
		return true;
}

//Return the file name of a specified file path.
// es. GetFileNameFromFullFilePath("c:\temp\pippo.txt") == "pippo.txt"
// es. GetFileNameFromFullFilePath("http:\\temp\pippo.txt") == "pippo.txt"
// Path Separators: \ or /
CString DVLib::GetFileNameFromFullFilePath(LPCTSTR p_FileFullPath)
{
	CString l_FullPath = p_FileFullPath;

	//trovo l'ultimo backslash
	int l_PosFind = -1;
	for (int i = l_FullPath.GetLength()-1; i >= 0; i--)
	{
		if (l_FullPath.GetAt(i) == '\\' || l_FullPath.GetAt(i) == '/')
		{
			l_PosFind = i;
			break;
		}
	}

	CString tmp;
	if (l_PosFind == -1) //separatore non trovato
		tmp = l_FullPath;
	else if ((l_PosFind+1) >= l_FullPath.GetLength()) //il separatore è l'ultimo carattere
		tmp = "";
	else
		tmp = l_FullPath.Mid(l_PosFind+1,l_FullPath.GetLength()-l_PosFind);

	return tmp;
}

//Return the path of a specified file path (without the last path separator).
// es. GetPathFromFullFilePath("c:\temp\pippo.txt") == "c:\temp"
// es. GetPathFromFullFilePath("http:\\temp\pippo.txt") == "http:\\temp"
// Path Separators: \ or /
CString DVLib::GetPathFromFullFilePath(LPCTSTR p_FileFullPath)
{
	CString l_FullPath = p_FileFullPath;

	//trovo l'ultimo backslash
	int l_PosFind = -1;
	for (int i = l_FullPath.GetLength()-1; i >= 0; i--)
	{
		if (l_FullPath.GetAt(i) == '\\' || l_FullPath.GetAt(i) == '/')
		{
			l_PosFind = i;
			break;
		}
	}

	CString tmp;
	if (l_PosFind == -1)
		tmp = "";
	else
		tmp = l_FullPath.Mid(0,l_PosFind);

	return tmp;
}

//Concatenates two strings that represent properly formed paths into one path
// Non uso PathCombine perchè non è presente in Win95
CString DVLib::PathCombine(LPCTSTR p_Path1, LPCTSTR p_Path2, char p_separator)
{
	CString l_Path1 = p_Path1;
	CString l_Path2 = p_Path2;

	if (l_Path1.GetLength() > 0)
	{
		int l_End = l_Path1.GetLength()-1;

		//verifico se è giò presente un separatore
		if (l_Path1.GetAt(l_End) == '\\' || l_Path1.GetAt(l_End) == '/')
			return (l_Path1 + l_Path2);
		else //aggiungo il separatore 
		{
			CString tmp = l_Path1;
			tmp += p_separator;
			tmp += l_Path2;
			return tmp;
		}
	}
	else
		return (l_Path1 + l_Path2);
}
