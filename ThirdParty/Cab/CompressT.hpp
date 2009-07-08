//////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (www.netcult.ch/elmue)
// Date: 01-08-2006
//
// Filename: CompressT.hpp
//
// Classes:
// - CCompressT<T>
// - CCompress
//
// Purpose: This template compresses files into a cabinet file (CAB).
//
/////////////////////////////////////////////////////////////////////////////////
/*
----------------------------------------------------------------------------------
Using these conventions results in better readable code and less coding errors !
----------------------------------------------------------------------------------

     cName  for generic class definitions
     CName  for MFC     class definitions
     tName  for type    definitions
     eName  for enum    definitions
     kName  for struct  definitions

    e_Name  for enum variables
    E_Name  for enum constant values

    i_Name  for instances of classes
    h_Name  for handles

    T_Name  for Templates
    t_Name  for TCHAR or LPTSTR

    s_Name  for strings
   bs_Name  for BSTR
    f_Name  for function pointers
    k_Name  for contructs (struct)

    b_Name  bool,BOOL 1 Bit

   s8_Name    signed  8 Bit (char)
  s16_Name    signed 16 Bit (SHORT, WCHAR)
  s32_Name    signed 32 Bit (LONG, int)
  s64_Name    signed 64 Bit (LONGLONG)

   u8_Name  unsigned  8 Bit (BYTE)
  u16_Name  unsigned 16 bit (WORD)
  u32_Name  unsigned 32 Bit (DWORD, UINT)
  u64_Name  unsigned 64 Bit (ULONGLONG)

    d_Name  for double

  ----------------

    m_Name  for member variables of a class (e.g. ms32_Name for int member variable)
    g_Name  for global variables            (e.g. gu16_Name for global WORD)
    p_Name  for pointer                     (e.g.   ps_Name  *pointer to string)
   pp_Name  for pointer to pointer          (e.g.  ppd_Name **pointer to double)

*************************************************************************************/

#pragma once


// When a folder has this much compressed data inside it, automatically flush the folder.
// Flushing the folder hurts compression a little bit, but helps random access significantly.
#define FOLDER_THRESHOLD	900000

#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#include "FCI.h"
#include "File.hpp"

#pragma warning(disable: 4996)

// Output of open, close, read, write, seek and delete operations onto a debug viewer
// To view the output set 1 here and use the tool "DebugView" from www.sysinternals.com
// This application MUST be started with STRG + F5 from VisualStudio otherwise you will see nothing
#define _TraceCompress   0

// Extension for enum FCIERROR defined in Microsoft file FCI.H
#define FCIERR_LOAD_DLL        1000
#define FCIERR_INVAL_PARAM     1001
#define FCIERR_CABFILE_UNICODE 1002
#define FCIERR_NT_PLATFORM     1003
#define FCIERR_CREATE_DIR      1004
#define FCIERR_PATH_TOO_LONG   1005

namespace Cabinet
{

template <class T> class CCompressT
{
public:

	// Constructor
	CCompressT()
	{ 
		mh_FCIContext   = 0;
		mh_CabinetDll   = 0;
		memset(&mk_Error, 0, sizeof(ERF));

		ms32_TempCounter = 1;
		SetTempDirectoryA(""); // Set Windows default Temp directory
	}

	// Destructor
	// Deletes all created temp files and flushes the cabinet from memory to disk if
	// the user did not yet call FlushCabinet()
	~CCompressT()
	{ 
		DestroyFCIContext();
		// Decrement the reference count for the DLL.
		// If another instance is still using the DLL the DLL will not be unloaded!
		if (mh_CabinetDll) FreeLibrary(mh_CabinetDll);
	}

	// This function aborts the currently active operation.
	void AbortOperation()
	{ 
		mb_Abort = TRUE;
	}

	// The same as SetTempDirectoryA for Unicode
	BOOL SetTempDirectoryW(WCHAR *u16_TempDir)
	{
		CUtf7 i_Utf;
		return SetTempDirectoryA(i_Utf.Encode(u16_TempDir));
	}

	// You can specify where to store the temp files which can become very huge
	// if you compress huge files
	// If this function is never called or called with "", the default Windows Temp directory will be used
	BOOL SetTempDirectoryA(char *s8_TempDir)
	{
		int Len = strlen(s8_TempDir);
		if (Len == 0)
		{
			GetTempPathA(sizeof(ms8_TempDir), ms8_TempDir);
		}
		else
		{
			if (!CUtf7::IsNtPlatform() && CUtf7::IsUtf(s8_TempDir))
			{
				mk_Error.fError  = TRUE;
				mk_Error.erfOper = FCIERR_NT_PLATFORM;
				return FALSE;
			}

			if (!SafeCopyPathA(ms8_TempDir, sizeof(ms8_TempDir), s8_TempDir, FALSE))
				return FALSE;
		}

		cFile::TerminatePathA(ms8_TempDir);

		UINT u32_Error = cFile::CreateFolderTreeA(ms8_TempDir);
		if  (u32_Error)
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FCIERR_CREATE_DIR;
			mk_Error.erfType = u32_Error;
			return FALSE;
		}
		return TRUE;
	}
	
	// The same as SetEncryptionKeyA for Unicode
	BOOL SetEncryptionKeyW(WCHAR* u16_EncryptKey)
	{
		CUtf7 i_Utf;
		return SetEncryptionKeyA(i_Utf.Encode(u16_EncryptKey));
	}

	// Sets the key for encryption of the CAB file
	// You can also pass binary data here which must be zero terminated
	// Setting an empty string turns off encryption
	BOOL SetEncryptionKeyA(char* s8_EncryptKey)
	{
		int s32_KeyLen = (int) strlen(s8_EncryptKey);

		if (s32_KeyLen >= sizeof(mk_Encrypt.s8_Key))
			return FALSE;

		mk_Encrypt.s32_KeyLen = s32_KeyLen;
		memcpy(mk_Encrypt.s8_Key, s8_EncryptKey, s32_KeyLen);
		return TRUE;
	}

	// The same as CreateFCIContextA() for Unicode 
	BOOL CreateFCIContextW(WCHAR* u16_File,
	                       BOOL     b_UtcTime = TRUE,
	                       ULONG  u32_CabSplitSize = 0x7FFFFFFF,
	                       USHORT u16_CabID = 0)
	{
		CUtf7 i_Utf;
		return CreateFCIContextA(i_Utf.Encode(u16_File), b_UtcTime, u32_CabSplitSize, u16_CabID);
	}

	// Creates a new FCI context for a single CAB file 
	// b_UtcTime = TRUE -> store the files with UTC time in the CAB file (recommended)
	// Windows stores files with UTC time. If you compress with local time you will have
	// a discrepancy of one hour or more after daylight saving or timezone changes
	// When extracting you must set the same value for this flag!!
	BOOL CreateFCIContextA(char*   s8_File,                      // "C:\Temp\Packed.cab"
	                       BOOL     b_UtcTime = TRUE,            // Store files with UTC time (recommended)
	                       ULONG  u32_CabSplitSize = 0x7FFFFFFF, // The split filesize where to start a new CAB file
	                       USHORT u16_CabID = 0)                 // an ID to be stored in the CAB file
	{
		char s8_CabPath    [CB_MAX_CAB_PATH];
		char s8_CabFileName[CB_MAX_CAB_PATH];

		char *s8_Pos = strrchr(s8_File, '\\');
		if  (!s8_Pos)
			return FALSE;

		int Pos = (int)(s8_Pos - s8_File + 1);

		if (!SafeCopyPathA(s8_CabFileName, sizeof(s8_CabFileName), s8_File + Pos, FALSE)) return FALSE;
		if (!SafeCopyPathA(s8_CabPath,     sizeof(s8_CabPath),     s8_File      , FALSE)) return FALSE;

		s8_CabPath[Pos] = 0;

		return CreateFCIContextA(s8_CabPath, s8_CabFileName, b_UtcTime, u32_CabSplitSize, u16_CabID);
	}

	// The same as CreateFCIContextA() for Unicode 
	BOOL CreateFCIContextW(WCHAR* u16_CabPath,
	                       WCHAR* u16_CabFileName,
	                       BOOL     b_UtcTime = TRUE,
	                       ULONG  u32_CabSplitSize = 0x7FFFFFFF,
	                       USHORT u16_CabID = 0)
	{
		CUtf7 i_Path, i_File;
		return CreateFCIContextA(i_Path.Encode(u16_CabPath), i_File.Encode(u16_CabFileName), b_UtcTime, u32_CabSplitSize, u16_CabID);
	}

	// Creates a new FCI context for a CAB file which spans over multiple CAB files ("disks")
	// You can modify the specific settings for the sub-CAB files in GetNextCabinet()
	// b_UtcTime = TRUE -> store the files with UTC time in the CAB file (recommended)
	// Windows stores files with UTC time. If you compress with local time you will have
	// a discrepancy of one hour or more after daylight saving or timezone changes
	// When extracting you must set the same value for this flag!!
	BOOL CreateFCIContextA(char*   s8_CabPath,                   // "C:\Temp"
						   char*   s8_CabFileName,               // "Packed_%d.cab"
						   BOOL     b_UtcTime = TRUE,            // Store files with UTC time (recommended)
						   ULONG  u32_CabSplitSize = 0x7FFFFFFF, // The split filesize where to start a new CAB file
						   USHORT u16_CabID = 0)                 // an ID to be stored in the CAB file
	{
		memset(&mk_Error, 0, sizeof(ERF));

		if (mh_FCIContext || !strlen(s8_CabPath) || !strlen(s8_CabFileName))
		{
			mk_Error.erfOper = FCIERR_INVAL_PARAM;
			return FALSE;
		}

		if (!mh_CabinetDll)
		{
			// If the DLL is already attached to this process it will not be loaded a second time!
			mh_CabinetDll = LoadLibraryA("Cabinet.dll");
			mf_FciCreate       = (fFciCreate)       GetProcAddress(mh_CabinetDll, "FCICreate");
			mf_FciAddFile      = (fFciAddFile)      GetProcAddress(mh_CabinetDll, "FCIAddFile");
			mf_FciFlushFolder  = (fFciFlushFolder)  GetProcAddress(mh_CabinetDll, "FCIFlushFolder");
			mf_FciFlushCabinet = (fFciFlushCabinet) GetProcAddress(mh_CabinetDll, "FCIFlushCabinet");
			mf_FciDestroy      = (fFciDestroy)      GetProcAddress(mh_CabinetDll, "FCIDestroy");

			if (!mf_FciCreate || !mf_FciAddFile || !mf_FciFlushFolder || !mf_FciFlushCabinet || !mf_FciDestroy)
			{
				mh_CabinetDll  = 0;
				mk_Error.fError  = TRUE;
				mk_Error.erfOper = FCIERR_LOAD_DLL;
				return FALSE;
			}
		}

		// The CAB filename itself must never be Unicode
		if (CUtf7::IsUtf(s8_CabFileName))
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FCIERR_CABFILE_UNICODE;
			return FALSE;
		}

		// The CAB path may be Unicode but only on NT platforms
		if (!CUtf7::IsNtPlatform() && CUtf7::IsUtf(s8_CabPath))
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FCIERR_NT_PLATFORM;
			return FALSE;
		}

		// Create the tree of folders where to store the CAB file if they do not yet exist
		UINT u32_Error = cFile::CreateFolderTreeA(s8_CabPath);
		if  (u32_Error)
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FCIERR_CREATE_DIR;
			mk_Error.erfType = u32_Error;
			return FALSE;
		}

		mb_UtcTime   = b_UtcTime;
		mb_Abort     = FALSE; 
		mb_AutoFlush = TRUE; // Flushing must still be done
		mk_Encrypt.h_CabHandle = 0;

		if (!SetCabParameters(&mk_CabParams, s8_CabPath, s8_CabFileName, u16_CabID, u32_CabSplitSize))
			return FALSE;

		memset(&mk_CurStatus, 0, sizeof(kCurStatus));

		mh_FCIContext = mf_FciCreate(&mk_Error,
		                            (PFNFCIFILEPLACED) (FCIFilePlaced),
		                            (PFNFCIALLOC)      (FCIAlloc),
		                            (PFNFCIFREE)       (FCIFree),
		                            (PFNFCIOPEN)       (FCIOpen),
		                            (PFNFCIREAD)       (FCIRead),
		                            (PFNFCIWRITE)      (FCIWrite),
		                            (PFNFCICLOSE)      (FCIClose),
		                            (PFNFCISEEK)       (FCISeek),
		                            (PFNFCIDELETE)     (FCIDelete),
   		                            (PFNFCIGETTEMPFILE)(FCIGetTempFile),
		                            &mk_CabParams,
		                            this); // passed to the callbacks as "pv"

		return (mh_FCIContext != NULL);
	}


	// Flushes the cabinet if the user did not yet call FlushCabinet()
	// Destroys the FCI context used by this instance and returns TRUE if succesful or FALSE otherwise.
	// Deletes all temp files
	BOOL DestroyFCIContext()
	{
		BOOL b_Ret = TRUE;

		if (!mh_FCIContext)
			return b_Ret;

		if (mb_AutoFlush) // The user has not yet flushed the cabinet
		{
			if (!FlushCabinet(FALSE))
				b_Ret = FALSE;
		}

		TraceA("*** FCIDESTROY() ***");

		if (!mf_FciDestroy(mh_FCIContext))
			b_Ret = FALSE;
		
		mh_FCIContext = NULL;
		return b_Ret;
	}

	// The same as AddFileA() for Unicode 
	BOOL AddFileW(WCHAR* u16_FileToAdd, WCHAR* u16_NameInCab, void* pParam = NULL)
	{
		CUtf7 i_File, i_Name;
		return AddFileA(i_File.Encode(u16_FileToAdd), i_Name.Encode(u16_NameInCab), pParam);
	}

	// This function adds one ANSII or UTF7 file to the current cabinet.
	// Parameters:
	// s8_FileToAdd = Full path to the file to be added to the cabinet.
	// s8_NameInCab = path and filename under which to store the file in the cabinet
	//                "Install\Setup.exe" will create a subfolder "Install" inside the cabinet
	// pParam       = User defined value which will be passed to the callback function.
	BOOL AddFileA(char* s8_FileToAdd, char* s8_NameInCab, void* pParam = NULL)
	{
		if (!mh_FCIContext)
			return FALSE;

		// Unicode files may be compressed but only on NT platforms
		if (!CUtf7::IsNtPlatform() && CUtf7::IsUtf(s8_FileToAdd))
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FCIERR_NT_PLATFORM;
			return FALSE;
		}

		mb_AutoFlush = TRUE; // Flushing must be done
		mp_Param     = pParam;

		TraceA("*** AddFileA(%s) ***", s8_FileToAdd);

		return mf_FciAddFile(mh_FCIContext, 
		                     s8_FileToAdd, 
    			             s8_NameInCab, 
			    	         FALSE, 
				    	     (PFNFCIGETNEXTCABINET) FCIGetNextCabinet,
		                     (PFNFCISTATUS)         FCIUpdateStatus,
		                     (PFNFCIGETOPENINFO)    FCIGetAttribsAndDate,
						     tcompTYPE_MSZIP);
	}

	// The same as AddFolderA for Unicode
	BOOL AddFolderW(WCHAR* u16_Folder, WCHAR* u16_Filter=L"*.*", void* pParam=NULL, int s32_BaseLen=-1)
	{
		// Unicode files may be compressed but only on NT platforms
		if (!CUtf7::IsNtPlatform())
		{
			CUtf7 i_Folder, i_Filter;
			return AddFolderA(i_Folder.Encode(u16_Folder), i_Filter.Encode(u16_Filter), pParam, -1);
		}

		WCHAR u16_Path[CB_MAX_CAB_PATH];
		if (!SafeCopyPathW(u16_Path, sizeof(u16_Path), u16_Folder, FALSE)) // wcscpy
			return FALSE;

		cFile::TerminatePathW(u16_Path);

		int s32_Len = wcslen (u16_Path);
		if (s32_BaseLen < 0) 
			s32_BaseLen = s32_Len;

		if (!SafeCopyPathW(u16_Path, sizeof(u16_Path), u16_Filter, TRUE)) // wcscat
			return FALSE;

		WIN32_FIND_DATAW k_Find;
		HANDLE h_File = FindFirstFileW(u16_Path, &k_Find);

		if (h_File == INVALID_HANDLE_VALUE)
			return FALSE;

		do
		{
			if (k_Find.cFileName[0] == '.')
				continue;

			WCHAR u16_File[CB_MAX_CAB_PATH];
			if (!SafeCopyPathW(u16_File, sizeof(u16_File), u16_Path, FALSE)) // wcscpy
				return FALSE;

			u16_File[s32_Len] = 0;
			if (!SafeCopyPathW(u16_File, sizeof(u16_File), k_Find.cFileName, TRUE)) // wcscat
				return FALSE;

			if (k_Find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (!AddFolderW(u16_File, u16_Filter, pParam, s32_BaseLen))
				{
					FindClose(h_File);
					return FALSE;
				}
			}
			else
			{
				if (!AddFileW(u16_File, u16_File + s32_BaseLen, pParam))
				{
					FindClose(h_File);
					return FALSE;
				}
			}
		}
		while (FindNextFileW(h_File, &k_Find));

		FindClose(h_File);
		return TRUE;
	}

	// Adds a folder with all its files and all its subfolders to the CAB file
	// s8_Path   = "C:\MyFolder\"
	// s8_Filter = "*.*  or  "*.dll"
	// Do never set or modify s32_BaseLen !!
	BOOL AddFolderA(char* s8_Folder, char* s8_Filter="*.*", void* pParam=NULL, int s32_BaseLen=-1)
	{
		// Unicode files may be compressed but only on NT platforms
		if (!CUtf7::IsNtPlatform() && (CUtf7::IsUtf(s8_Folder) || CUtf7::IsUtf(s8_Filter)))
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FCIERR_NT_PLATFORM;
			return FALSE;
		}

		char s8_Path[CB_MAX_CAB_PATH];
		if (!SafeCopyPathA(s8_Path, sizeof(s8_Path), s8_Folder, FALSE)) // strcpy
			return FALSE;

		cFile::TerminatePathA(s8_Path);
		
		int s32_Len = strlen (s8_Path);
		if (s32_BaseLen < 0) 
			s32_BaseLen = s32_Len;

		if (!SafeCopyPathA(s8_Path, sizeof(s8_Path), s8_Filter, TRUE)) // strcat
			return FALSE;

		WIN32_FIND_DATAA k_Find;
		HANDLE h_File = FindFirstFileA(s8_Path, &k_Find);

		if (h_File == INVALID_HANDLE_VALUE)
			return FALSE;

		do
		{
			if (k_Find.cFileName[0] == '.')
				continue;

			char s8_File[CB_MAX_CAB_PATH];
			if (!SafeCopyPathA(s8_File, sizeof(s8_File), s8_Path, FALSE)) // strcpy
				return FALSE;

			s8_File[s32_Len] = 0;
			if (!SafeCopyPathA(s8_File, sizeof(s8_File), k_Find.cFileName, TRUE)) // strcat
				return FALSE;

			if (k_Find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (!AddFolderA(s8_File, s8_Filter, pParam, s32_BaseLen))
				{
					FindClose(h_File);
					return FALSE;
				}
			}
			else
			{
				if (!AddFileA(s8_File, s8_File + s32_BaseLen, pParam))
				{
					FindClose(h_File);
					return FALSE;
				}
			}
		}
		while (FindNextFileA(h_File, &k_Find));

		FindClose(h_File);
		return TRUE;
	}

	// Forces the current cabinet under construction to be completed immediately and written to disk.
	// Further calls to AddFile will cause files to be added to another cabinet.
	// It is also possible that there exists pending data in FCI’s internal buffers that 
	// will may require spillover into another cabinet, if the current cabinet 
	// has reached the application-specified media size limit.
	// b_CreateNewCabinetFile = TRUE:  Call GetNextCabinet() to obtain continuation information.
	// b_CreateNewCabinetFile = FALSE: Call GetNextCabinet() only if the cabinet overflows
	BOOL FlushCabinet(BOOL b_CreateNewCabinetFile, void* pParam = NULL)
	{
		if (!mh_FCIContext)
			return FALSE;

		mb_AutoFlush = FALSE; // Flushing already done
		mp_Param     = pParam;

		TraceA("*** FlushCabinet() ***");

		return mf_FciFlushCabinet(mh_FCIContext, 
		                          b_CreateNewCabinetFile,
					  	          (PFNFCIGETNEXTCABINET) FCIGetNextCabinet,
		                          (PFNFCISTATUS)         FCIUpdateStatus);
	}

	// Complete the current folder under construction
	// This will force the termination of the current folder, which may or
	// may not cause one or more cabinet files to be completed.
	BOOL FlushFolder(void* pParam = NULL)
	{
		if (!mh_FCIContext)
			return FALSE;

		mb_AutoFlush = TRUE; // Flushing must be done
		mp_Param     = pParam;

		TraceA("*** FlushFolder() ***");

		return mf_FciFlushFolder(mh_FCIContext, 
				 		        (PFNFCIGETNEXTCABINET) FCIGetNextCabinet,
		                        (PFNFCISTATUS)         FCIUpdateStatus);
	}

	// Returns an Unicode message for the last error that has occured.
	WCHAR* LastErrorW()
	{
		if (!mk_Error.fError)
			return L"Success";

		CUtf7 i_Utf;
		if (!CUtf7::IsNtPlatform())
		{
			wcscpy(mu16_Error, i_Utf.Decode(LastErrorA())); // convert Ansii --> Unicode
			return mu16_Error;
		}

		i_Utf.Decode(GetFciErrorA()); // convert Ansii --> Unicode

		if (!mk_Error.erfType)
		{
			wcscpy(mu16_Error, i_Utf.Decoded());
			return mu16_Error;
		}

		WCHAR u16_Msg[5000];		
		if (!FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM, 0, mk_Error.erfType, 0, u16_Msg, sizeof(u16_Msg)/2, 0))
		{
			wcscpy(u16_Msg, L"Windows has no explanation for this error code.");
		}

		swprintf(mu16_Error, L"%s\nError %d: %s", i_Utf.Decoded(), mk_Error.erfType, u16_Msg);
		return   mu16_Error;
	}

	// Returns an ANSII message for the last error that has occured.
	char* LastErrorA()
	{
		if (!mk_Error.fError)
			return "Success";

		char* s8_FciErr = GetFciErrorA();

		if (!mk_Error.erfType)
			return s8_FciErr;
		
		char s8_Msg[5000];
		if (!FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, 0, mk_Error.erfType, 0, s8_Msg, sizeof(s8_Msg), 0))
		{
			strcpy(s8_Msg, "Windows has no explanation for this error code.");
		}

		sprintf(ms8_Error, "%s\nError %d: %s", s8_FciErr, mk_Error.erfType, s8_Msg);
		return  ms8_Error;
	}

	// Assure that the buffer size is sufficient
	// Cabinet.dll limits to CB_MAX_CAB_PATH = 256
	// Use SafeCopyPath() to replace strcpy() and strcat()
	BOOL SafeCopyPathA(char* s8_Buffer, UINT u32_BufSize, char* s8_Path, BOOL b_Append)
	{
		if (!b_Append) s8_Buffer[0] = 0;

		if (strlen(s8_Buffer) + strlen(s8_Path) >= u32_BufSize -1) // + backslash and zero
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FCIERR_PATH_TOO_LONG;
			return FALSE;
		}

		strcat(s8_Buffer, s8_Path);
		return TRUE;		
	}

	BOOL SafeCopyPathW(WCHAR* u16_Buffer, UINT u32_BufSize /* in Bytes! */, WCHAR* u16_Path, BOOL b_Append)
	{
		if (!b_Append) u16_Buffer[0] = 0;

		if (wcslen(u16_Buffer) + wcslen(u16_Path) >= u32_BufSize/2 -1) // + backslash and zero
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FCIERR_PATH_TOO_LONG;
			return FALSE;
		}

		wcscat(u16_Buffer, u16_Path);
		return TRUE;		
	}

	BOOL SafeFormatPathA(char* s8_Buffer, UINT u32_BufSize, char* s8_Format, ...)
	{
		va_list  args;
		va_start(args, s8_Format);
		if (_vsnprintf(s8_Buffer, u32_BufSize, s8_Format, args) < 0)
		{
			s8_Buffer[0] = 0;
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FCIERR_PATH_TOO_LONG;
			return FALSE;
		}
		return TRUE;		
	}

	// Used by UpdateStatus()
	typedef struct kCurStatus
	{
		ULONG u32_TotCompressedSize;
		ULONG u32_TotUncompressedSize;
		ULONG cb1;
		ULONG cb2;
		ULONG FolderPercent;
	};


protected:
	
	// Print Debug Output 
	static void TraceA(char* s8_Format, ...)
	{
		#if _TraceCompress
			char s8_Buf[5001];
			va_list  args;
			va_start(args, s8_Format);
			_vsnprintf(s8_Buf, 5000, s8_Format, args);
			OutputDebugStringA(s8_Buf);
		#endif
	}

	char* GetFciErrorA()
	{
		switch (mk_Error.erfOper)
		{
		case FCIERR_NONE:            return "Success";
		case FCIERR_OPEN_SRC:        return "Failure opening file to be stored in cabinet";
		case FCIERR_READ_SRC:        return "Failure reading file to be stored in cabinet";
		case FCIERR_ALLOC_FAIL:      return "Insufficient memory in FCI";
		case FCIERR_TEMP_FILE:       return "Could not create a temporary file";
		case FCIERR_BAD_COMPR_TYPE:  return "Unknown compression type";
		case FCIERR_CAB_FILE:        return "Could not create cabinet file";
		case FCIERR_USER_ABORT:      return "Client requested abort";
		case FCIERR_MCI_FAIL:        return "Failure compressing data";
		case FCIERR_LOAD_DLL:        return "Could not load Cabinet.dll";
		case FCIERR_INVAL_PARAM:     return "Invalid parameters";
		case FCIERR_CABFILE_UNICODE: return "The filename of the CAB file must NEVER contain Unicode characters!";
		case FCIERR_NT_PLATFORM:     return "Compressing Unicode paths requires Windows NT, 2000, XP or higher.";
		case FCIERR_CREATE_DIR:      return "Could not create the directory where to save the CAB file.";
		case FCIERR_PATH_TOO_LONG:   return "The path is too long. (Max 250 Ansii characters or approx 100 Unicode characters).";
		default:                     return "Unknown error";
		}
	}

	// Allocates a new block of memory and returns the pointer to the newly allocated memory. 
	// This function can be overridden.
	static void* Alloc(UINT size)
	{ 
		return operator new(size); 
	}

	// Frees a block of memory allocated by Alloc.
	// This function can be overridden.
	static void Free(void* memblock)
	{ 
		operator delete(memblock); 
	}

	// Used to encrypt the CAB file
	typedef struct kEncrypt
	{
		char   s8_Key[5000];                // Holds the Encryption string if it has been set by SetEncryptionKey()
		int   s32_KeyLen;                   // The length of the key
		char   s8_CabFile[CB_MAX_CAB_PATH]; // The path to the CAB file file which is currently written
		int     h_CabHandle;                // The handle of the CAB file which is currently written
		int   s32_CabPtr;                   // The current read / write position in the CAB file

		// Constructor
		kEncrypt()
		{
			 s8_Key[0]     = 0;
			 s8_CabFile[0] = 0;
			  h_CabHandle  = 0;
			s32_CabPtr     = 0;
			s32_KeyLen     = 0;
		}
	};

	kEncrypt mk_Encrypt;

	// The count of Bytes which have yet been compressed
	kCurStatus mk_CurStatus;

	// Handle to the FCI context.
	HFCI mh_FCIContext;

	// Struct that is used for storing error information.
	ERF mk_Error;

	// Used for LastError()
	WCHAR mu16_Error[5000];
	char   ms8_Error[5000];

	// User defined parameter to pass to the callback function.
	void* mp_Param;

	// Flag that can be set to abort the current operation.
	BOOL mb_Abort;

	// TRUE when the caller did not yet flush the cabinet
	BOOL mb_AutoFlush;

	// TRUE -> store the files with UTC time in the CAB file (recommended)
	// Windows stores files with UTC time. If you compress with local time you will have
	// a discrepancy of one hour or more after daylight saving or timezone changes
	// When extracting you must set the same value for this flag!!
	BOOL mb_UtcTime;

	// The initialization data for the current cabinet
	CCAB mk_CabParams;

	// The directory where to store the temporary files
	char ms8_TempDir[CB_MAX_CAB_PATH];

	// The current number of the latest temp file
	int ms32_TempCounter;

	// This receives the formatter for the resulting filename for the cabfile
	// For a single cab file -> "MyCabFile.cab"
	// For a spanned cabfile the name must contain "%d" -> "MyCabFile_%d.cab"
	char ms8_CabNameFormatter[CB_MAX_CABINET_NAME];

	typedef HFCI (DIAMONDAPI* fFciCreate)      (PERF, PFNFCIFILEPLACED, PFNFCIALLOC, PFNFCIFREE, PFNFCIOPEN, PFNFCIREAD, PFNFCIWRITE, PFNFCICLOSE, PFNFCISEEK, PFNFCIDELETE, PFNFCIGETTEMPFILE, PCCAB, void*);
	typedef BOOL (DIAMONDAPI* fFciAddFile)     (HFCI, char*, char*, BOOL, PFNFCIGETNEXTCABINET, PFNFCISTATUS, PFNFCIGETOPENINFO, TCOMP);
	typedef BOOL (DIAMONDAPI* fFciFlushFolder) (HFCI,       PFNFCIGETNEXTCABINET, PFNFCISTATUS);
	typedef BOOL (DIAMONDAPI* fFciFlushCabinet)(HFCI, BOOL, PFNFCIGETNEXTCABINET, PFNFCISTATUS);
	typedef BOOL (DIAMONDAPI* fFciDestroy)     (HFCI);

	HINSTANCE        mh_CabinetDll;
	fFciCreate       mf_FciCreate;
	fFciAddFile      mf_FciAddFile;
	fFciFlushFolder  mf_FciFlushFolder;
	fFciFlushCabinet mf_FciFlushCabinet;
	fFciDestroy      mf_FciDestroy;


private:
	//Callback functions called while creating the CAB file
	static int FCIOpen(char* pszFile, int oflag, int pmode, int *err, void *pv)
	{ 
		CCompressT<T>* pThis = (CCompressT<T>*) pv;
		int fd = static_cast<T*>(pThis)->Open(pszFile, oflag, pmode, err, pThis->mp_Param);

		TraceA("> > > > FCIOpen (%s) --> Handle= 0x%08X", pszFile, fd);

		// The output CAB file has just been opened -> remember its handle
		if (stricmp(pszFile, pThis->mk_Encrypt.s8_CabFile) == 0) 
		{
			pThis->mk_Encrypt.h_CabHandle = fd;
			pThis->mk_Encrypt.s32_CabPtr  = 0;
		}

		return fd;
	}

	static UINT FCIRead(int fd, void *memory, UINT count, int *err, void *pv)
	{ 
		CCompressT<T>* pThis = (CCompressT<T>*) pv;
		int Read = static_cast<T*>(pThis)->Read(fd, memory, count, err, pThis->mp_Param); 

		TraceA("FCIRead (Handle= 0x%08X, Count= %04d) --> %04d Bytes read", fd, count, Read);

		// Reading from CAB file does not happen while compressing

		return Read;
	}

	static UINT FCIWrite(int fd, void *memory, UINT count, int *err, void *pv)
	{ 
		CCompressT<T>* pThis = (CCompressT<T>*) pv;

		// Encrypt the data block if SetEncryptionKey() has been called before
		if (pThis->mk_Encrypt.h_CabHandle == fd && pThis->mk_Encrypt.s32_KeyLen)
		{
			pThis->EncryptDataBlock(memory, count, pThis->mk_Encrypt.s8_Key, pThis->mk_Encrypt.s32_KeyLen, pThis->mk_Encrypt.s32_CabPtr, pv);
		}

		// Write data block to disk
		int Written = static_cast<T*>(pThis)->Write(fd, memory, count, err, pThis->mp_Param); 

		TraceA("FCIWrite(Handle= 0x%08X, Count= %04d) --> %04d Bytes written", fd, count, Written);

		// remember the current file pointer in the CAB file
		if (pThis->mk_Encrypt.h_CabHandle == fd)
			pThis->mk_Encrypt.s32_CabPtr += Written;

		return Written;
	}

	static int FCIClose(int fd, int *err, void *pv)
	{ 
		CCompressT<T>* pThis = (CCompressT<T>*) pv;
		
		TraceA("FCIClose(Handle= 0x%08X)", fd);

		// The output CAB file has just been closed -> reset its handle
		if (pThis->mk_Encrypt.h_CabHandle == fd) 
			pThis->mk_Encrypt.h_CabHandle = 0;

		return static_cast<T*>(pThis)->Close(fd, err, pThis->mp_Param); 
	}

	// see comment for Seek!
	static long FCISeek(int fd, long offset, int seektype, int *err, void *pv)
	{ 
		CCompressT<T>* pThis = (CCompressT<T>*) pv;
		int Pos = static_cast<T*>(pThis)->Seek(fd, offset, seektype, err, pThis->mp_Param); 

		switch (seektype)
		{
			case SEEK_SET: TraceA("FCISeek (Handle= 0x%08X, SEEK_SET, Offset= %04d) --> Position= %04d", fd, offset, Pos); break;
			case SEEK_CUR: TraceA("FCISeek (Handle= 0x%08X, SEEK_CUR, Offset= %04d) --> Position= %04d", fd, offset, Pos); break;
			case SEEK_END: TraceA("FCISeek (Handle= 0x%08X, SEEK_END, Offset= %04d) --> Position= %04d", fd, offset, Pos); break;
		}

		// remember the current file pointer in the CAB file
		if (pThis->mk_Encrypt.h_CabHandle == fd) 
			pThis->mk_Encrypt.s32_CabPtr = Pos;

		return Pos;
	}

	static int FCIDelete(char *pszFile, int *err, void *pv)
	{ 
		CCompressT<T>* pThis = (CCompressT<T>*) pv;

		TraceA("FCIDelete(%s)", pszFile);
		TraceA("-------");

		return static_cast<T*>(pThis)->Delete(pszFile, err, pThis->mp_Param); 
	}

	// see comment for GetTempFile!
	static BOOL FCIGetTempFile(char *pszTempName, int cbTempName, void *pv)
	{ 
		CCompressT<T>* pThis = (CCompressT<T>*) pv;
		return static_cast<T*>(pThis)->GetTempFile(pszTempName, cbTempName, pThis->mp_Param); 
	}

	// see comment for GetAttribsAndDate!
	static int FCIGetAttribsAndDate(char *pszName, USHORT *pdate, USHORT *ptime, USHORT *pattribs, int *err, void *pv)
	{
		CCompressT<T>* pThis = (CCompressT<T>*) pv;

		if (pThis->mb_Abort)
			return -1;

		return static_cast<T*>(pThis)->GetAttribsAndDate(pszName, pdate, ptime, pattribs, err, pThis->mp_Param);
	}
	
	// see comment for OnFilePlaced!
	static int FCIFilePlaced(PCCAB pccab, char *s8_File, long cbFile, BOOL fContinuation, void *pv)
	{ 
		CCompressT<T>* pThis = (CCompressT<T>*) pv;
		CUtf7 i_Utf;
		return static_cast<T*>(pThis)->OnFilePlaced(pccab, s8_File, i_Utf.Decode(s8_File), cbFile, fContinuation, pThis->mp_Param); 
	}

	// see comment for OnGetNextCabinet!
	static BOOL FCIGetNextCabinet(PCCAB pccab, ULONG cbPrevCab, void* pv)
	{
		CCompressT<T>* pThis = (CCompressT<T>*) pv;

		if (pThis->mb_Abort)
			return FALSE;

		BOOL b_Continue = static_cast<T*>(pThis)->OnGetNextCabinet(pccab, cbPrevCab, pThis->mp_Param);

		// copy the current cab file path to member variable
		if (!pThis->SafeFormatPathA(pThis->mk_Encrypt.s8_CabFile, sizeof(pThis->mk_Encrypt.s8_CabFile), "%s%s", pccab->szCabPath, pccab->szCab))
			return FALSE;

		return b_Continue;
	}

	// see comment for OnUpdateStatus!
	static long FCIUpdateStatus(UINT typeStatus, ULONG cb1, ULONG cb2, void *pv)
	{
		CCompressT<T>* pThis = (CCompressT<T>*) pv;

		if (pThis->mb_Abort)
			return -1;

		pThis->mk_CurStatus.cb1           = cb1;
		pThis->mk_CurStatus.cb2           = cb2;
		pThis->mk_CurStatus.FolderPercent = 0;

		if (typeStatus == statusFile)
		{
			// Calculate how many bytes have been compressed totally yet
			pThis->mk_CurStatus.u32_TotCompressedSize   += cb1;
			pThis->mk_CurStatus.u32_TotUncompressedSize += cb2;
		}
		else if (typeStatus == statusFolder)
		{
			// Calculate percentage of folder compression
			while (cb1 > 10000000)
			{
				cb1 >>= 3;
				cb2 >>= 3;
			}
			if (cb2 != 0) pThis->mk_CurStatus.FolderPercent = ((cb1*100)/cb2);
		}

		return static_cast<T*>(pThis)->OnUpdateStatus(typeStatus, &pThis->mk_CurStatus, pThis->mp_Param);
	}

	static void* FCIAlloc(UINT size)
	{ 
		return T::Alloc(size); 
	}

	static void FCIFree(void* memblock)
	{ 
		T::Free(memblock); 
	}

protected:
	// Load the initialization structure pk_CabParams
	// May be overridden
	BOOL SetCabParameters(CCAB*   pk_CabParams, 
	                      char*   s8_CabPath,     // "C:\Temp"
						  char*   s8_CabFileName, // "Packed.cab" or "Packed_Part_%d"
						  USHORT u16_CabID,       // an ID to be stored in the CAB file
						  ULONG  u32_CabSplitSize)// The max filesize for splitted CAB files in Bytes
	{
		memset(pk_CabParams, 0, sizeof(CCAB));

		UINT Len = (UINT)strlen(s8_CabPath); 
		if (Len < 3 || strlen(s8_CabFileName) < 3 || u32_CabSplitSize < 20000)
		{
			mk_Error.erfOper = FCIERR_INVAL_PARAM;
			return FALSE;
		}

		if (!SafeCopyPathA(pk_CabParams->szCabPath, sizeof(pk_CabParams->szCabPath), s8_CabPath, FALSE))
			return FALSE;

		cFile::TerminatePathA(pk_CabParams->szCabPath);

		// ATTENTION:
		// Altough Microsoft defined "cb" as ULONG it is treated 
		// internally as if it would be signed !!!
		pk_CabParams->cb                = u32_CabSplitSize & 0x7FFFFFFF; // MediaSize
		pk_CabParams->cbFolderThresh    = FOLDER_THRESHOLD;
		// Don't reserve space for any extensions
		pk_CabParams->cbReserveCFHeader = 0;
		pk_CabParams->cbReserveCFFolder = 0;
		pk_CabParams->cbReserveCFData   = 0;
		// We use this to create the cabinet name
		pk_CabParams->iCab  = 1;
		// If you want to use disk names, use this to count disks
		pk_CabParams->iDisk = 1;
		// Chose your own number (e.g. 12345) or set to zero
		pk_CabParams->setID = u16_CabID;
		
		// copy the formatter of the cabfile ("Packed_%d.cab" or "Packed.cab")
		if (!SafeCopyPathA(ms8_CabNameFormatter, sizeof(ms8_CabNameFormatter), s8_CabFileName, FALSE))
			return FALSE;

		// Create the name of first CAB file and of the first disk
		FCIGetNextCabinet(pk_CabParams, 0, this);
		return TRUE;
	}

	// Open a file
	int Open(char* s8_File, int oflag, int pmode, int *err, void* p_Param)
	{
		int result;
		if (CUtf7::IsUtf(s8_File))
		{
			CUtf7 i_Utf;
			result = _wopen(i_Utf.Decode(s8_File), oflag, pmode);
		}
		else result = _open(s8_File, oflag, pmode);

		if (result == -1) *err = errno;
		return result;
	}

	// Read a file
	UINT Read(int hf, void *memory, UINT cb, int *err, void* p_Param)
	{ 
		UINT result = (UINT) _read(hf, memory, cb);
		if  (result != cb) *err = errno;
		return result;
	}

	// Write a file
	UINT Write(int hf, void *memory, UINT cb, int *err, void* p_Param)
	{ 
		UINT result = (UINT) _write(hf, memory, cb);
		if  (result != cb) *err = errno;
		return result;
	}

	// Close a file
	int Close(int hf, int *err, void* p_Param)
	{ 
		int result = _close(hf);
	    if (result != 0) *err = errno;
	    return result;
	}

	// Delete a (temp) file
	int Delete(char *s8_File, int *err, void* p_Param)
	{     
		int result;
		if (CUtf7::IsUtf(s8_File))
		{
			CUtf7 i_Utf;
			result = _wremove(i_Utf.Decode(s8_File));
		}
		else result = remove(s8_File);

		if (result != 0) *err = errno;
		return result;
	}

	// Seek inside a file (move file pointer)
	long Seek(int hf, long dist, int seektype, int *err, void* p_Param)
	{ 
		long result = _lseek(hf, dist, seektype);
	    if  (result == -1) *err = errno;
		return result; 
	}

	// Encrypt the data block
	// You can override this function to use your own encryption algorithm
	void EncryptDataBlock(void*   p_Memory,  // data in memory to be encrypted
	                      UINT  u32_Count,   // size of memory block in Bytes
						  char*  s8_Key,     // the encryption key
						  int   s32_KeyLen,  // the legth of s8_Key
						  int   s32_CabPtr,  // a pointer indicating the absolute position in the CAB file where this block starts
						  void*   p_Param)   // user defined parameter which has been passed to AddFile()
	{
		// Modify the first 4 bytes which identify the CAB file
		// So tools which try to open the file will spit out an error
		if (s32_CabPtr == 0)
		{
			((char*)p_Memory)[0] = 'C';
			((char*)p_Memory)[1] = 'R';
			((char*)p_Memory)[2] = 'Y';
			((char*)p_Memory)[3] = 'P';
		}

		int k = s32_CabPtr;

		// for each byte of the memory block we add the corresponding byte of the encryption key
		// and EXOR the value with the position in the file % 73
		for (UINT m=0; m<u32_Count; m++, k++)
		{
			k %= s32_KeyLen;

			// We let the first 0x3C Bytes of the file unencrypted (file header)
			if (s32_CabPtr + m < 0x3C)
				continue;

			((unsigned char*)p_Memory)[m] ^= ((s32_CabPtr + m + s8_Key[0]) %101); // EXOR
			((unsigned char*)p_Memory)[m] += ((unsigned char*)s8_Key)[k];         // ADD
		}		
	}

	// A function to obtain temporary file names
	// The filename returned should not occupy more than cbTempName bytes.
	// FCI may open several temporary files at once, so it is important to ensure 
	// that a different filename is returned each time, and that the file does not already exist.
	BOOL GetTempFile(char *s8_TempName, int cbBufSize, void* p_Param)
	{ 
		CUtf7 i_Utf;
		BOOL  b_Utf = CUtf7::IsUtf(ms8_TempDir);

		while (true)
		{
			if (!SafeFormatPathA(s8_TempName, cbBufSize, "%sCabTemp%04u", ms8_TempDir, ms32_TempCounter++))
				return FALSE;

			// Check if the file already exists (-1 = Error reading file attribures)
			if (b_Utf)
			{
				if (-1 == GetFileAttributesW(i_Utf.Decode(s8_TempName)))
					return TRUE;
			}
			else
			{
				if (-1 == GetFileAttributesA(s8_TempName))
					return TRUE;
			}
		}
	}

	// Open source file and return date / time / attributes
	// - pszName:  complete path to filename
	// - pdate:    FAT-style date code
	// - ptime:    FAT-style time code
	// - pattribs: FAT-style attributes
	// - p_Param:  your user defined parameter which you have passed to AddFile(..)
	// Exit-Success: Return file handle of open file to read
	// Exit-Failure: Return -1
	int GetAttribsAndDate(char *s8_File, USHORT *pdate, USHORT *ptime, USHORT *pattribs, int *err, void *p_Param)
	{
		HANDLE h_File;

		if (CUtf7::IsUtf(s8_File))
		{
			CUtf7 i_Utf;
			h_File = CreateFileW(i_Utf.Decode(s8_File), GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
			                     FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
		}
		else
		{
			h_File = CreateFileA(s8_File, GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
			                     FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
		}

		if (h_File == INVALID_HANDLE_VALUE)
		{
			*err = ::GetLastError();
			return -1;
		}

		BY_HANDLE_FILE_INFORMATION k_FileInfo;
		if (!GetFileInformationByHandle(h_File, &k_FileInfo))
		{
			*err = ::GetLastError();
			CloseHandle(h_File);
			return -1;
		}

		CloseHandle(h_File);

		// The Windows filesystem stores UTC times
		::FILETIME k_CabTime = k_FileInfo.ftLastWriteTime;
		
		if (!mb_UtcTime) 
			FileTimeToLocalFileTime(&k_FileInfo.ftLastWriteTime, &k_CabTime); // UTC -> local time

		FileTimeToDosDateTime(&k_CabTime, pdate, ptime);

		// Mask out all other bits except these four, since other bits are used 
		// by the cabinet format to indicate a special meaning.
		*pattribs = (int)(k_FileInfo.dwFileAttributes & (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_ARCHIVE));

		if (mb_UtcTime) *pattribs |= FILE_ATTR_UTC_TIME;

		// Now return a handle using _open()
		return FCIOpen(s8_File, _O_RDONLY | _O_BINARY, _S_IREAD, err, this);
	}

	// ########################### CALLBACKS #######################

	// Called whenever the location of a file or file segment on a particular cabinet has been finalized.
	// This information is useful only when files are being stored across multiple cabinets
	// fContinuation is a BOOL which signifies whether the file is a later segment 
	// of a file which has been split across cabinets.  
	int OnFilePlaced(PCCAB pccab, char *s8_File, WCHAR* u16_File, long cbFile, BOOL fContinuation, void* p_Param)
	{
		return 0; 
	}

	// called whenever FCI wishes to create a new cabinet, which will happen whenever 
	// the size of the cabinet is about to exceed the media size as specified in the cb field 
	// of the CCAB structure passed to FCICreate.  
	// - pccab:
	//      pointer to a copy of the CCAB structure of the cabinet which has just been completed.
	//      However, the iCab field will have been incremented by one.
	//      When this function returns, the next cabinet will be created using the fields 
	//      in this structure, so these fields should be modified as is necessary.
	//      In particular, the szCab field (the cabinet name) should be changed.
	//      If creating multiple cabinets, typically the iCab field is used to create the name;
	//      Similarly, the disk name, media size, folder threshold, etc. parameters may 
	//      also be modified.
	// - cbPrevCab:
	//      is an estimate of the size of the cabinet which has just been completed.
	// - p_Param:
	//      your user defined parameter which you have passed to AddFile(..)
	// return TRUE for success, or FALSE to abort cabinet creation.
	BOOL OnGetNextCabinet(PCCAB pccab, ULONG cbPrevCab, void* p_Param)
	{ 
		// Create a name for CAB files spanning over multiple files
		// This will also be called if only one CAB file is created
		if (!SafeFormatPathA(pccab->szCab,  sizeof(pccab->szCab),  ms8_CabNameFormatter, pccab->iCab))
			return FALSE;

		if (!SafeFormatPathA(pccab->szDisk, sizeof(pccab->szDisk), "Disk %d", pccab->iDisk ++))
			return FALSE;

		// Modify the other elements if required:
		// pccab->cbFolderThresh = xyz;
		// pccab->setID = xyz;
		// pccab->cb    = xyz;

		return TRUE;
	}

	//  typeStatus == statusFile if compressing a block into a folder
	//        - cb1 : Size of compressed block
	//        - cb2 : Size of uncompressed block
	//
	//  typeStatus == statusFolder if adding a folder to a cabinet
	//        - cb1 : Amount of folder copied to cabinet so far
	//        - cb2 : Total size of folder
	//
	//  typeStatus == statusCabinet if writing out a complete cabinet
	//        - cb1 : Estimated cabinet size that was previously passed to GetNextCabinet().
	//        - cb2 : Actual cabinet size
	// - p_Param:
	//        your user defined parameter which you have passed to AddFile(..)
	//
	// The return value is desired client size for cabinet file.
	// FCI updates the maximum cabinet size remaining using this value.
	// This allows a to generate multiple cabinets per disk, and have FCI limit the size correctly.
	// The client can do cluster size rounding on the cabinet size!
	// The client should either return cb2, or round cb2 up to some larger value and return that.
	// Exit-Failure: Return -1 to signal that FCI should abort
	long OnUpdateStatus(UINT typeStatus, kCurStatus *pk_CurStatus, void *p_Param)
	{
		// Display the values in pk_CurStatus in your GUI 
		// or do whatever you like with them or ignore them !
		return 0;
	}
};

class CCompress : public CCompressT<CCompress> { };

} // Namespace Cabinet