#pragma once

namespace DVLib
{
	CString GetAppFullName();
	//restituisce il path dell'applicazione corrente senza il backslash finale
	CString GetAppPath();
	CString GetSystemPath();
	CString GetWindowsPath();
	CString GetTempPathCustom();
    // get a unique temporary directory for this run of dni
    CString GetSessionTempPath(bool returnonly = false);
	CString GetTempFullFileName();
	void DeleteDirectoryDeep(const CString& path);
}
