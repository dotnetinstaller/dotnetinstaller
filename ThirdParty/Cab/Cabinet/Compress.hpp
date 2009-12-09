//////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (www.netcult.ch/elmue)
// Date: 19-04-2008
//
// Filename: Compress.hpp
//
// Classes:
// - CCompress
//
// Purpose: This class compresses files into a cabinet file (CAB).
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
   sa_Name  for Ascii strings
   sw_Name  for Wide (Unicode) strings
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
    g_Name  for global (static) variables   (e.g. gu16_Name for global WORD)
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

#include "Defines.h"
#include "Static.hpp"
#include "File.hpp"
#include "Trace.hpp"
#include "Error.hpp"
#include "Blowfish.hpp"

#pragma warning(disable: 4996)

namespace Cabinet
{

class CCompress
{

public:

	typedef struct kCurStatus
	{
		ULONG u32_TotCompressedSize;
		ULONG u32_TotUncompressedSize;
		ULONG cb1;
		ULONG cb2;
		ULONG FolderPercent;
	};

	struct kCallbacks
	{
		typedef int  (*t_FilePlaced)    (PCCAB, WCHAR*, int, BOOL, void*);
		typedef BOOL (*t_GetNextCabinet)(PCCAB, ULONG, char*, void*);
		typedef int  (*t_UpdateStatus)  (UINT, kCurStatus*, void*);
		
		t_FilePlaced     f_FilePlaced;
		t_GetNextCabinet f_GetNextCabinet;
		t_UpdateStatus   f_UpdateStatus;

		kCallbacks()
		{
			f_FilePlaced     = 0;
			f_GetNextCabinet = 0;
			f_UpdateStatus   = 0;
		}
	};

	// Constructor
	CCompress() : mi_Error(FALSE)
	{ 
		#if _TraceCompress
			CTrace::TraceW(L"Constructor CCompress()");
		#endif

		mh_FCIContext = 0;
		mh_CabinetDll = 0;

		mu32_ThreadID = GetCurrentThreadId(); // FIRST !!

		SetTempDirectoryW(L""); // Set Windows default Temp directory

		// The following two variables are used to generate the filename of the temp files
		// TempCounter is incremented with every new temp file
		mu32_TempCounter = 1;

		// ClassID is incremented with every new class instance.
		// There may be multiple class instances in the same thread, so we don't use the ThreadID here
		mu32_ClassID = InterlockedIncrement(&CStatic::ms32_CompressClassID);
	}

	// Destructor
	// Deletes all created temp files and flushes the cabinet from memory to disk if
	// the user did not yet call FlushCabinet()
	~CCompress()
	{ 
		#if _TraceCompress
			CTrace::TraceW(L"Destructor ~CCompress()");
		#endif

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

	// You can specify where to store the temp files which can become very huge if you compress huge files
	// If this function is never called or called with "" or 0, the default Windows Temp directory will be used
	BOOL SetTempDirectoryW(const CStrW& sw_TempDir)
	{
		// Every class must only be accessed by one and the same thread. See "Microsoft Cabinet.dll Doku.doc"
		if (mu32_ThreadID != GetCurrentThreadId())
		{
			mi_Error.Set(FCIERR_INVAL_THREAD,0,0);
			return FALSE;
		}

		if (sw_TempDir[0])
		{
			msw_TempDir = sw_TempDir;
		}
		else
		{
			msw_TempDir.Allocate(MAX_PATH);
			GetTempPathW(MAX_PATH, msw_TempDir);
		}
		
		CFile::TerminatePathW(msw_TempDir);

		UINT u32_Error = CFile::CreateFolderTreeW(msw_TempDir);
		if  (u32_Error)
		{
			mi_Error.Set(FCIERR_CREATE_DIR, u32_Error,0);
			return FALSE;
		}
		return TRUE;
	}
	
	// Sets the key for encryption of the CAB file
	// You can pass ANY binary data here, an ANSII string or an Unicode string
	// If the password is longer  than 72 Byte, the remaining bytes will be ignored
	// If the password is shorter than 72 Byte, its bytes will be reused multiple times
	// u32_KeyLen is always the count in Bytes (for Unicode strings = characters * 2)
	// Passing u32_KeyLen = 0 turns off encryption
	// ATTENTION:
	// It is recommended not to pass the password directly to this function!
	// You should derive for example a HASH from the password and use this instead.
	// See http://en.wikipedia.org/wiki/Key_derivation_function
	void SetEncryptionKey(void* p_Key, DWORD u32_KeyLen)
	{
		mk_Encrypt.i_Blowfish.SetPassword(p_Key, u32_KeyLen);

		if (!mk_Encrypt.u8_Buf)
		{
			mk_Encrypt.u8_Buf = new BYTE[CRYPT_BUFFER_SIZE];
			if (!mk_Encrypt.u8_Buf) throw "Fatal error: Out of memory!"; // Required for older Visual Studio versions
		}
	}

	// Sets up to 3 static callbacks which are called from Cabinet.dll during the compression process
	void SetCallbacks(kCallbacks* pk_Callbacks)
	{
		mk_Callbacks = *pk_Callbacks;
	}

	// Creates a new FCI context for a single CAB file 
	// You can modify the specific settings for the sub-CAB files in GetNextCabinet()
	// b_UtcTime = TRUE -> store the files with UTC time in the CAB file (recommended)
	// Windows stores files with UTC time. If you compress with local time you will have
	// a discrepancy of one hour or more after daylight saving or timezone changes
	// b_EncodeUTF=TRUE  -> If a filename has characters > 0x7F, encode it using UTF8
	// b_EncodeUTF=FALSE -> Store ANSI filenames unchanged, read documentation!
	BOOL CreateFCIContextW(const CStrW& sw_CabFile,                   // "C:\Temp\Packed.cab"
	                       BOOL          b_UtcTime   = TRUE,          // Store files with UTC time (recommended)
	                       BOOL          b_EncodeUtf = TRUE,          // Store filenames UTF8 encoded (recommended)
	                       ULONG       u32_CabSplitSize = 0x7FFFFFFF, // The split filesize where to start a new CAB file
	                       USHORT      u16_CabID = 0,                 // an ID to be stored in the CAB file
	                       void*       pParam=NULL)                  // optional user parameter passed to all callbacks
	{
		// Every class must only be accessed by one and the same thread. See "Microsoft Cabinet.dll Doku.doc"
		if (mu32_ThreadID != GetCurrentThreadId())
		{
			mi_Error.Set(FCIERR_INVAL_THREAD,0,0);
			return FALSE;
		}

		CStrW sw_Folder, sw_File;
		CFile::SplitPathW(sw_CabFile, &sw_Folder, &sw_File);

		#if _TraceCompress
			CTrace::TraceW(L"*** FCICreate(File='%s', UTC=%d, Split=0x%X, ID=%d) ***", (WCHAR*)sw_File, b_UtcTime, u32_CabSplitSize, u16_CabID);
		#endif

		mi_Error.Reset();

		if (mh_FCIContext || !sw_File.Len() || !sw_Folder.Len())
		{
			mi_Error.Set(FCIERR_INVAL_PARAM,0,0);
			return FALSE;
		}

		#if STATIC_LINK_CABINET_DLL // Use precompiled functions in FCI.LIB

			mf_FciCreate       = FCICreate;
			mf_FciAddFile      = FCIAddFile;
			mf_FciFlushFolder  = FCIFlushFolder;
			mf_FciFlushCabinet = FCIFlushCabinet;
			mf_FciDestroy      = FCIDestroy;

		#else // Dynamic Link (execute functions in Cabinet.dll in Windows directory)

			if (!mh_CabinetDll)
			{
				// If the DLL is already attached to this process it will not be loaded a second time!
				mh_CabinetDll = LoadLibraryW(L"Cabinet.dll");
				mf_FciCreate       = (fFciCreate)       GetProcAddress(mh_CabinetDll, "FCICreate");
				mf_FciAddFile      = (fFciAddFile)      GetProcAddress(mh_CabinetDll, "FCIAddFile");
				mf_FciFlushFolder  = (fFciFlushFolder)  GetProcAddress(mh_CabinetDll, "FCIFlushFolder");
				mf_FciFlushCabinet = (fFciFlushCabinet) GetProcAddress(mh_CabinetDll, "FCIFlushCabinet");
				mf_FciDestroy      = (fFciDestroy)      GetProcAddress(mh_CabinetDll, "FCIDestroy");

				if (!mf_FciCreate || !mf_FciAddFile || !mf_FciFlushFolder || !mf_FciFlushCabinet || !mf_FciDestroy)
				{
					mh_CabinetDll  = 0;
					mi_Error.Set(FCIERR_LOAD_DLL,0,0);
					return FALSE;
				}
			}

		#endif

		// Create the tree of folders where to store the CAB file if they do not yet exist
		UINT u32_Error = CFile::CreateFolderTreeW(sw_Folder);
		if  (u32_Error)
		{
			mi_Error.Set(FCIERR_CREATE_DIR, u32_Error,0);
			return FALSE;
		}

		mp_Param     = pParam;
		mb_UtcTime   = b_UtcTime;
		mb_EncodeUtf = b_EncodeUtf;
		mb_Abort     = FALSE; 
		mb_AutoFlush = TRUE; // Flushing must still be done
		
		mk_Encrypt.h_CabHandle = 0;
		mk_Encrypt.sw_CabFiles = L"|";

		if (!SetCabParametersW(&mk_CabParams, sw_Folder, sw_File, u16_CabID, u32_CabSplitSize))
			return FALSE;

		memset(&mk_CurStatus, 0, sizeof(kCurStatus));

		mh_FCIContext = mf_FciCreate(&mi_Error.k_ERF,
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
		                            this); // passed to the static callbacks as "pThis"

		return (mh_FCIContext != NULL);
	}


	// Flushes the cabinet if the user did not yet call FlushCabinet()
	// Destroys the FCI context used by this instance and returns TRUE if succesful or FALSE otherwise.
	// Deletes all temp files
	BOOL DestroyFCIContext()
	{
		// Every class must only be accessed by one and the same thread. See "Microsoft Cabinet.dll Doku.doc"
		if (mu32_ThreadID != GetCurrentThreadId())
		{
			mi_Error.Set(FCIERR_INVAL_THREAD,0,0);
			return FALSE;
		}

		BOOL b_Ret = TRUE;

		if (!mh_FCIContext)
			return b_Ret;

		if (mb_AutoFlush) // The user has not yet flushed the cabinet
		{
			if (!FlushCabinet(FALSE))
				b_Ret = FALSE;
		}

		#if _TraceCompress
			CTrace::TraceW(L"*** FCIDestroy() ***");
		#endif

		if (!mf_FciDestroy(mh_FCIContext))
			b_Ret = FALSE;
		
		mh_FCIContext = NULL;
		return b_Ret;
	}

	// This function adds one file to the current cabinet.
	// Parameters:
	// sw_FileToAdd = Full path to the file to be added to the cabinet.
	// sw_NameInCab = path and filename under which to store the file in the cabinet
	//                "Install\Setup.exe" will create a subfolder "Install" inside the cabinet
	// b_Compress   = FALSE --> store in CAB file without compression
	BOOL AddFileW(const CStrW& sw_FileToAdd, const CStrW& sw_NameInCab, BOOL b_Compress=TRUE)
	{
		// Every class must only be accessed by one and the same thread. See "Microsoft Cabinet.dll Doku.doc"
		if (mu32_ThreadID != GetCurrentThreadId())
		{
			mi_Error.Set(FCIERR_INVAL_THREAD,0,0);
			return FALSE;
		}

		if (!mh_FCIContext)
			return FALSE;

		mb_AutoFlush = TRUE; // Flushing must be done

		#if _TraceCompress
			CTrace::TraceW(L"*** FCIAddFile('%s') ***", (WCHAR*)sw_FileToAdd);
		#endif

		ULONGLONG u64_Size;
		DWORD u32_Error = CFile::GetFileSizeW(sw_FileToAdd, &u64_Size);
		if (u32_Error)
		{
			mi_Error.Set(FCIERR_OPEN_SRC, u32_Error,0);
			return FALSE;
		}

		if (u64_Size > 0x7FFF0000) // Cabinet.dll supports max 2 GB
		{
			mi_Error.Set(FCIERR_FILE_TOO_BIG,0,0);
			return FALSE;
		}

		CStrA s_File, s_Name;
		if (mb_EncodeUtf) 
		{
			mb_NameInCabIsUtf = !sw_NameInCab.IsAscii();
			s_Name.EncodeUtf8(sw_NameInCab);
		}
		else // UTF8 encoding disabled by the caller
		{
			// Unicode filenames cannot be stored with UTF8 encoding disabled
			if (sw_NameInCab.IsUnicode())
			{
				mi_Error.Set(FCIERR_UNICODE_NEEDS_UTF8, 0,0);
				return FALSE;
			}

			mb_NameInCabIsUtf = FALSE;
			s_Name = sw_NameInCab;
		}

		// When mf_FciAddFile returns FALSE the error code has already been written into mi_Error in one of the 3 callbacks.
		// If you want to debug with a Debugger to trap an error you MUST set a breakpoint in FCIGetNextCabinet, FCIUpdateStatus, FCIGetAttribsAndDate!
		// But it is much easier to enable _TraceCompress and observe in DebugView what's happening.
		return mf_FciAddFile(mh_FCIContext, 
		                     s_File.EncodeUtf8(sw_FileToAdd),
		                     s_Name,
		                     FALSE, 
		                     (PFNFCIGETNEXTCABINET) FCIGetNextCabinet,
		                     (PFNFCISTATUS)         FCIUpdateStatus,
		                     (PFNFCIGETOPENINFO)    FCIGetAttribsAndDate,
		                     b_Compress ? tcompTYPE_MSZIP : tcompTYPE_NONE);
	}

	// Adds a folder with all its files and all its subfolders to the CAB file
	// sw_Path    = "C:\MyFolder\"
	// sw_Filter  = "*.*  or  "*.dll"
	// b_Compress = FALSE --> store in CAB file without compression
	// Do never set or modify s32_BaseLen !!
	BOOL AddFolderW(/*NO const*/ CStrW sw_Path, const CStrW& sw_Filter=L"*.*", BOOL b_Compress=TRUE, int s32_BaseLen=-1)
	{
		CFile::TerminatePathW(sw_Path);

		int s32_Len = sw_Path.Len();
		if (s32_BaseLen < 0) 
			s32_BaseLen = s32_Len;

		sw_Path += sw_Filter;

		WIN32_FIND_DATAW k_Find;
		HANDLE h_File = FindFirstFileW(sw_Path, &k_Find);

		if (h_File == INVALID_HANDLE_VALUE)
			return (GetLastError() == ERROR_FILE_NOT_FOUND);

		do
		{
			if (k_Find.cFileName[0] == '.') // directories "." and ".."
				continue;

			CStrW sw_File = sw_Path;

			sw_File[s32_Len] = 0;
			sw_File += k_Find.cFileName;

			if (k_Find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (!AddFolderW(sw_File, sw_Filter, b_Compress, s32_BaseLen))
				{
					FindClose(h_File);
					return FALSE;
				}
			}
			else
			{
				if (!AddFileW(sw_File, (WCHAR*)sw_File + s32_BaseLen, b_Compress))
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


	// Forces the current cabinet under construction to be completed immediately and written to disk.
	// Further calls to AddFile will cause files to be added to another cabinet.
	// It is also possible that there exists pending data in FCI’s internal buffers that 
	// will may require spillover into another cabinet, if the current cabinet 
	// has reached the application-specified media size limit.
	// b_CreateNewCabinetFile = TRUE:  Call GetNextCabinet() to obtain continuation information.
	// b_CreateNewCabinetFile = FALSE: Call GetNextCabinet() only if the cabinet overflows
	BOOL FlushCabinet(BOOL b_CreateNewCabinetFile)
	{
		// Every class must only be accessed by one and the same thread. See "Microsoft Cabinet.dll Doku.doc"
		if (mu32_ThreadID != GetCurrentThreadId())
		{
			mi_Error.Set(FCIERR_INVAL_THREAD,0,0);
			return FALSE;
		}

		if (!mh_FCIContext)
			return FALSE;

		mb_AutoFlush = FALSE; // Flushing already done

		#if _TraceCompress
			CTrace::TraceW(L"*** FCIFlushCabinet() ***");
		#endif

		// When mf_FciFlushCabinet returns FALSE the error code has already been written into mi_Error in one of the 2 callbacks.
		// If you want to debug with a Debugger to trap an error you MUST set a breakpoint in FCIGetNextCabinet and FCIUpdateStatus!
		// But it is much easier to enable _TraceCompress and observe in DebugView what's happening.
		return mf_FciFlushCabinet(mh_FCIContext, 
		                           b_CreateNewCabinetFile,
					  	          (PFNFCIGETNEXTCABINET) FCIGetNextCabinet,
		                          (PFNFCISTATUS)         FCIUpdateStatus);
	}

	// Complete the current folder under construction
	// This will force the termination of the current folder, which may or
	// may not cause one or more cabinet files to be completed.
	BOOL FlushFolder()
	{
		// Every class must only be accessed by one and the same thread. See "Microsoft Cabinet.dll Doku.doc"
		if (mu32_ThreadID != GetCurrentThreadId())
		{
			mi_Error.Set(FCIERR_INVAL_THREAD,0,0);
			return FALSE;
		}

		if (!mh_FCIContext)
			return FALSE;

		mb_AutoFlush = TRUE; // Flushing must be done

		#if _TraceCompress
			CTrace::TraceW(L"*** FCIFlushFolder() ***");
		#endif

		return mf_FciFlushFolder(mh_FCIContext, 
				 		        (PFNFCIGETNEXTCABINET) FCIGetNextCabinet,
		                        (PFNFCISTATUS)         FCIUpdateStatus);
	}

	// Returns an Unicode message for the last error that has occured.
	WCHAR* LastErrorW()
	{
		return mi_Error.LastErrorW();
	}

protected:

	// Used to encrypt the CAB file
	struct kEncrypt
	{
		CBlowfish i_Blowfish;    // The Blowfish encryption class
		CStrW    sw_CabFiles;    // The path to all CAB files splitted by pipe characters
		INT_PTR   h_CabHandle;   // The handle of the CAB file which is currently written
		UINT    u32_Pointer;     // Filepointer (modified when writing and modfied by Seek)
		BYTE*    u8_Buf;         // A 64 kB buffer for encryption

		kEncrypt() // Constructor
		{
			  h_CabHandle = 0;
			u32_Pointer   = 0;
			 u8_Buf       = 0;
		}
		~kEncrypt() // Destructor
		{
			if (u8_Buf) delete u8_Buf;
		}
	};

	kEncrypt   mk_Encrypt;
	kCallbacks mk_Callbacks;

	// The count of Bytes which have yet been compressed
	kCurStatus mk_CurStatus;

	// Handle to the FCI context.
	HFCI mh_FCIContext;

	// Stores the last error
	CError mi_Error;

	// The directory where to store the temporary files
	CStrW msw_TempDir;

	// This receives the formatter for the resulting filename for the cabfile
	// For a single cab file -> "MyCabFile.cab"
	// For a spanned cabfile the name must contain "%d" -> "MyCabFile_%d.cab"
	CStrA msa_CabNameFormatter;

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

	// TRUE  -> If a filename has characters > 0x7F, encode it using UTF8 and set the flag _A_NAME_IS_UTF
	// FALSE -> Store ANSI filenames unchanged, do not set _A_NAME_IS_UTF, return error if character > 0xFF
	// Read the documentation!
	BOOL mb_EncodeUtf;
	
	// This flag is set when AddFile() adds a file which is to be stored with an Utf name into the cabinet
	BOOL mb_NameInCabIsUtf;

	// The initialization data for the current cabinet
	CCAB mk_CabParams;

	// Every class instance must only be accessed from one thread
	DWORD mu32_ThreadID;

	// A unique identifier for each class instance
	DWORD mu32_ClassID;

	// The current number of the latest temp file
	DWORD mu32_TempCounter;

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

	// #################### STATIC FCI CALLBACKS ########################

	static void* FCIAlloc(UINT size)
		{ return operator new(size); }

	static void FCIFree(void* memblock)
		{ operator delete(memblock); }
	
	static INT_PTR FCIOpen(char* s8_File, int oflag, int pmode, int *err, void *pThis)
		{ return ((CCompress*)pThis)->FciOpenA(s8_File, oflag, pmode, err); }
	
	static UINT FCIRead(INT_PTR fd, void *memory, UINT count, int *err, void *pThis)
		{ return ((CCompress*)pThis)->FciRead(fd, memory, count, err); }
	
	static UINT FCIWrite(INT_PTR fd, void *memory, UINT count, int *err, void *pThis)
		{ return ((CCompress*)pThis)->FciWrite(fd, memory, count, err); }
	
	static int FCIClose(INT_PTR fd, int *err, void *pThis)
		{ return ((CCompress*)pThis)->FciClose(fd, err); }
	
	static long FCISeek(INT_PTR fd, long offset, int seektype, int *err, void *pThis)
		{ return ((CCompress*)pThis)->FciSeek(fd, offset, seektype, err); }
	
	static int FCIDelete(char *s8_File, int *err, void *pThis)
		{ return ((CCompress*)pThis)->FciDelete(s8_File, err); }
	
	static BOOL FCIGetTempFile(char *pszTempName, int cbTempName, void *pThis)
		{ return ((CCompress*)pThis)->FciGetTempFile(pszTempName, cbTempName); }
	
	static INT_PTR FCIGetAttribsAndDate(char *pszName, USHORT *pdate, USHORT *ptime, USHORT *pattribs, int *err, void *pThis)
		{ return ((CCompress*)pThis)->FciGetAttribsAndDate(pszName, pdate, ptime, pattribs, err); }
	
	static int FCIFilePlaced(PCCAB pccab, char *s8_File, int s32_FileSize, BOOL fContinuation, void *pThis)
		{ return ((CCompress*)pThis)->FciFilePlaced(pccab, s8_File, s32_FileSize, fContinuation); }
	
	static BOOL FCIGetNextCabinet(PCCAB pccab, ULONG cbPrevCab, void* pThis)
		{ return ((CCompress*)pThis)->FciGetNextCabinet(pccab, cbPrevCab); }
	
	static long FCIUpdateStatus(UINT typeStatus, ULONG cb1, ULONG cb2, void *pThis)
		{ return ((CCompress*)pThis)->FciUpdateStatus(typeStatus, cb1, cb2); }

	// #################### MEMBER FCI CALLBACKS ########################

	INT_PTR FciOpenA(char* s8_File, int oflag, int pmode, int *err)
	{
		CStrW sw_File;
		return FciOpenW(sw_File.DecodeUtf8(s8_File), oflag, pmode, err);
	}
	INT_PTR FciOpenW(const CStrW& sw_File, int oflag, int pmode, int *err)
	{ 
		INT_PTR fd = Open(sw_File, oflag, pmode, err);

		// Open for writing: The final CAB file(s)      and the temp files
		// Open for reading: The files to be compressed and the temp files
		// BOOL b_Write = (pmode & _S_IWRITE);

		#if _TraceCompress
			CTrace::TraceW(L"> > > > FCIOpen (%s, %s) --> Handle= 0x%08X", (b_Write ? L"Write" : L"Read"), (WCHAR*)sw_File, fd);
		#endif

		// The output CAB file has just been opened -> remember its handle
		if (mk_Encrypt.i_Blowfish.IsPasswordSet() && wcsstr(mk_Encrypt.sw_CabFiles, sw_File) > 0) 
		{
			mk_Encrypt.h_CabHandle = fd;
			mk_Encrypt.u32_Pointer = 0;
			mk_Encrypt.i_Blowfish.EncryptStreamOpen();

			#if _TraceCompress
				CTrace::TraceW(L"**** Blowfish EncryptStreamOpen");
			#endif
		}
		return fd;
	}

	UINT FciRead(INT_PTR fd, void *memory, UINT count, int *err)
	{ 
		int s32_Read = Read(fd, memory, count, err); 

		#if _TraceCompress
			CTrace::TraceW(L"FCIRead (Handle= 0x%08X, Count= %5d) --> %05d Bytes read", fd, count, s32_Read);
		#endif

		// Reading from CAB file does not happen while compressing

		return s32_Read;
	}

	UINT FciWrite(INT_PTR fd, void *memory, UINT count, int *err)
	{ 
		// Write without encryption
		if (mk_Encrypt.h_CabHandle != fd)
		{
			// Write data block to disk
			UINT u32_Written = Write(fd, memory, count, err); 

			#if _TraceCompress
				CTrace::TraceW(L"FCIWrite(Handle= 0x%08X, Count= %5d) --> %05d Bytes written", fd, count, u32_Written);
			#endif

			return u32_Written;
		}

		// Write with Encryption
		BYTE* u8_Buffer = (BYTE*)memory;
		UINT u32_Count  = count;

		// Modify the first 4 bytes which identify the CAB file
		// So programs which try to open the file will spit out an error "Invalid CAB file"
		if (mk_Encrypt.u32_Pointer == 0 && strncmp((char*)u8_Buffer, "MSCF", 4) == 0)
		{
			strncpy((char*)u8_Buffer, "CRYP", 4);
		}

		// The first ENCRYPTION_START Bytes (file header) are written without encryption
		if (mk_Encrypt.u32_Pointer < ENCRYPTION_START)
		{
			UINT u32_UnEncrypted = min(u32_Count, ENCRYPTION_START - mk_Encrypt.u32_Pointer);

			UINT u32_Written = Write(fd, u8_Buffer, u32_UnEncrypted, err);
			if  (u32_Written != u32_UnEncrypted)
				 return -1;

			#if _TraceCompress
				CTrace::TraceW(L"FCIWrite(Handle= 0x%08X) --> %05d unencrypted Bytes written", fd, u32_Written);
			#endif

			u32_Count              -= u32_Written;
			u8_Buffer              += u32_Written;
			mk_Encrypt.u32_Pointer += u32_Written;
		}

		// Write the rest of the bytes (compressed CAB data) encrypted
		if (u32_Count > 0)
		{
			DWORD u32_Encrypted = 0;
			mk_Encrypt.i_Blowfish.EncryptStreamData(u8_Buffer, u32_Count, mk_Encrypt.u8_Buf, CRYPT_BUFFER_SIZE, &u32_Encrypted);

			UINT u32_Written = Write(fd, mk_Encrypt.u8_Buf, u32_Encrypted, err);
			if  (u32_Written != u32_Encrypted)
				 return -1;

			#if _TraceCompress
				CTrace::TraceW(L"FCIWrite(Handle= 0x%08X) --> %05d Bytes encrypted, %05d Bytes written", fd, u32_Count, u32_Written);
			#endif

			mk_Encrypt.u32_Pointer += u32_Written;
		}
		// To avoid an error, return the byte count that Cabinet.dll wanted to write
		// although some of these bytes may still remain in the Blowfish buffer
		return count;
	}

	// Write the last block in the Blowfish buffer to disk before setting the file pointer or closing file
	BOOL FlushBlowfish(INT_PTR fd, int *err)
	{
		DWORD u32_Flushed = 0;
		BYTE   u8_Flush[8];
		mk_Encrypt.i_Blowfish.EncryptStreamClose(u8_Flush, sizeof(u8_Flush), &u32_Flushed);
		if (u32_Flushed > 0)
		{
			#if _TraceCompress
				CTrace::TraceW(L"**** Blowfish EncryptStreamClose (Handle= 0x%08X) --> flushed last block (8 Bytes)", fd);
			#endif

			if (u32_Flushed != Write(fd, u8_Flush, u32_Flushed, err))
				return FALSE;
		}
		return TRUE;
	}

	long FciSeek(INT_PTR fd, long offset, int seektype, int *err)
	{ 
		// Cabinet.dll calls FciSeek after each compression before closing the CAB file.
		if (mk_Encrypt.h_CabHandle == fd)
		{
			if (!FlushBlowfish(fd, err))
				return -1;
		}

		// Move the file pointer to the new position
		int Pos = Seek(fd, offset, seektype, err); 

		#if _TraceCompress
			switch (seektype)
			{
				case SEEK_SET: CTrace::TraceW(L"FCISeek (Handle= 0x%08X, SEEK_SET, Offset= %05d) --> Position= %05d", fd, offset, Pos); break;
				case SEEK_CUR: CTrace::TraceW(L"FCISeek (Handle= 0x%08X, SEEK_CUR, Offset= %05d) --> Position= %05d", fd, offset, Pos); break;
				case SEEK_END: CTrace::TraceW(L"FCISeek (Handle= 0x%08X, SEEK_END, Offset= %05d) --> Position= %05d", fd, offset, Pos); break;
			}
		#endif

		// remember the current file pointer in the CAB file
		if (mk_Encrypt.h_CabHandle == fd) 
		{
			mk_Encrypt.u32_Pointer = Pos;
		}
		return Pos;
	}

	int FciClose(INT_PTR fd, int *err)
	{ 
		#if _TraceCompress
			CTrace::TraceW(L"FCIClose(Handle= 0x%08X)", fd);
		#endif

		// The output CAB file has just been closed -> reset its handle
		if (mk_Encrypt.h_CabHandle == fd) 
		{
			mk_Encrypt.h_CabHandle = 0;

			if (!FlushBlowfish(fd, err))
				return -1;
		}
		return Close(fd, err); 
	}


	int FciDelete(char* s8_File, int* err)
	{ 
		CStrW sw_File;
		sw_File.DecodeUtf8(s8_File);
		
		#if _TraceCompress
			CTrace::TraceW(L"FCIDelete('%s')", (WCHAR*)sw_File);
			CTrace::TraceW(L"-------");
		#endif

		return Delete(sw_File, err); 
	}

	// see comment for GetTempFileW!
	BOOL FciGetTempFile(char *pszTempName, int cbTempName)
	{ 
		return GetTempFileA(pszTempName, cbTempName); 
	}

	// see comment for GetAttribsAndDate!
	INT_PTR FciGetAttribsAndDate(char *s8_File, USHORT *pdate, USHORT *ptime, USHORT *pattribs, int *err)
	{
		if (mb_Abort)
			return -1;

		CStrW sw_File;
		return GetAttribsAndDateW(sw_File.DecodeUtf8(s8_File), pdate, ptime, pattribs, err);
	}
	
	// see comment for OnFilePlaced!
	int FciFilePlaced(PCCAB pccab, char *s8_File, int s32_FileSize, BOOL fContinuation)
	{ 
		if (mk_Callbacks.f_FilePlaced)
		{
			CStrW sw_File;
			return mk_Callbacks.f_FilePlaced(pccab, sw_File.DecodeUtf8(s8_File), s32_FileSize, fContinuation, mp_Param);
		}
		return 0;
	}

	// see comment for OnGetNextCabinet!
	BOOL FciGetNextCabinet(PCCAB pccab, ULONG cbPrevCab)
	{
		if (mb_Abort)
			return FALSE;

		CStrA sa_CabName;
		sa_CabName.Format(msa_CabNameFormatter, pccab->iCab);

		if (!sa_CabName.SafeExport(pccab->szCab, sizeof(pccab->szCab)))
		{
			mi_Error.Set(FCIERR_PATH_TOO_LONG,0,0);
			return FALSE;
		}

		// sizeof(szDisk) = 256 Bytes
		sprintf(pccab->szDisk, "Disk %d", pccab->iDisk++);

		if (mk_Callbacks.f_GetNextCabinet)
		{
			// the callback may modify the values in pccab here!!
			if (!mk_Callbacks.f_GetNextCabinet(pccab, cbPrevCab, msa_CabNameFormatter, mp_Param))
				return FALSE;
		}

		// Append the Cab path to the list of Cab files
		CStrA sa_CabPath;
		sa_CabPath.Format("%s%s", pccab->szCabPath, pccab->szCab);

		CStrW sw_CabPath;
		sw_CabPath.DecodeUtf8(sa_CabPath);

		#if _TraceCompress
			CTrace::TraceW(L"FCIGetNextCabinet formatted filename: '%s'", (WCHAR*)sw_CabPath);
		#endif

		mk_Encrypt.sw_CabFiles += sw_CabPath;
		mk_Encrypt.sw_CabFiles += L"|";
		return TRUE;
	}

	// see comment for OnUpdateStatus!
	int FciUpdateStatus(UINT typeStatus, ULONG cb1, ULONG cb2)
	{
		if (mb_Abort)
			return -1;

		mk_CurStatus.cb1           = cb1;
		mk_CurStatus.cb2           = cb2;
		mk_CurStatus.FolderPercent = 0;

		if (typeStatus == statusFile)
		{
			// Calculate how many bytes have been compressed totally yet
			mk_CurStatus.u32_TotCompressedSize   += cb1;
			mk_CurStatus.u32_TotUncompressedSize += cb2;
		}
		else if (typeStatus == statusFolder)
		{
			// Calculate percentage of folder compression
			while (cb1 > 10000000)
			{
				cb1 >>= 3;
				cb2 >>= 3;
			}
			if (cb2 != 0 && cb1<=cb2) mk_CurStatus.FolderPercent = ((cb1*100)/cb2);
		}

		if (mk_Callbacks.f_UpdateStatus)
			return mk_Callbacks.f_UpdateStatus(typeStatus, &mk_CurStatus, mp_Param);

		return 0;
	}

protected:

	// #################### OVERRIDABLES ###########################

	// Opens a file
	virtual INT_PTR Open(WCHAR* u16_File, int oflag, int pmode, int *err)
	{
		int result = _wopen(u16_File, oflag, pmode);
		if (result == -1) *err = errno;
		return result;
	}

	// Read a file
	virtual UINT Read(INT_PTR hf, void *memory, UINT cb, int *err)
	{ 
		UINT result = (UINT) _read((int)hf, memory, cb);
		if  (result != cb) *err = errno;
		return result;
	}

	// Write a file
	virtual UINT Write(INT_PTR hf, void *memory, UINT cb, int *err)
	{ 
		UINT result = (UINT) _write((int)hf, memory, cb);
		if  (result != cb) *err = errno;
		return result;
	}

	// Close a file
	virtual int Close(INT_PTR hf, int *err)
	{ 
		int result = _close((int)hf);
	    if (result != 0) *err = errno;
	    return result;
	}

	// Delete a (temp) file
	virtual int Delete(WCHAR *u16_File, int *err)
	{     
		int result = _wremove(u16_File);
		if (result != 0) *err = errno;
		return result;
	}

	// Seek inside a file (move file pointer)
	virtual long Seek(INT_PTR hf, long dist, int seektype, int *err)
	{ 
		long result = _lseek((int)hf, dist, seektype);
	    if  (result == -1) *err = errno;
		return result; 
	}


	// #################### FCI FUNCTIONS ########################


	// Load the initialization structure pk_CabParams
	// May be overridden
	BOOL SetCabParametersW(CCAB*   pk_CabParams, 
	                       CStrW   sw_CabFolder,   // "C:\Temp"
						   CStrW   sw_CabFileName, // "Packed.cab" or "Packed_Part_%d"
						   USHORT u16_CabID,       // an ID to be stored in the CAB file
						   ULONG  u32_CabSplitSize)// The max filesize for splitted CAB files in Bytes
	{
		memset(pk_CabParams, 0, sizeof(CCAB));

		if (sw_CabFolder.Len() < 3 || sw_CabFileName.Len() < 3 || u32_CabSplitSize < 20000)
		{
			mi_Error.Set(FCIERR_INVAL_PARAM,0,0);
			return FALSE;
		}

		// The filename must be like "Packed_%d.cab" or "Packed_%03u.cab" if splitting
		if (u32_CabSplitSize < 0x7FFF0000 && !wcsstr(sw_CabFileName, L"%"))
		{
			mi_Error.Set(FCIERR_INVAL_PARAM,0,0);
			return FALSE;
		}

		CFile::TerminatePathW(sw_CabFolder);

		CStrA sa_CabPath;
		sa_CabPath.EncodeUtf8(sw_CabFolder);
		
		if (!sa_CabPath.SafeExport(pk_CabParams->szCabPath, sizeof(pk_CabParams->szCabPath)))
		{
			mi_Error.Set(FCIERR_PATH_TOO_LONG,0,0);
			return FALSE;
		}

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
		msa_CabNameFormatter.EncodeUtf8(sw_CabFileName);

		// Create the name of first CAB file and the first disk
		FCIGetNextCabinet(pk_CabParams, 0, this); // passed to the static callbacks as "pThis"
		return TRUE;
	}


	// A function to obtain temporary file names
	// The filename returned should not occupy more than cbBufSize bytes.
	// FCI may open several temporary files at once, so it is important to ensure 
	// that a different filename is returned each time, and that the file does not already exist.
	BOOL GetTempFileA(char *s8_TempName, int cbBufSize)
	{ 
		CStrW sw_TempFile;
		while (TRUE)
		{
			sw_TempFile.Format(L"%sCabTmp_%02X_%02X", (WCHAR*)msw_TempDir, mu32_ClassID, mu32_TempCounter++);

			// Check if the file already exists (-1 = Error reading file attribures)
			if (-1 == GetFileAttributesW(sw_TempFile))
				break;
		}

		CStrA sa_TempFile;
		sa_TempFile.EncodeUtf8(sw_TempFile);

		if (!sa_TempFile.SafeExport(s8_TempName, cbBufSize))
		{
			mi_Error.Set(FCIERR_PATH_TOO_LONG,0,0);
			return FALSE;
		}
		return TRUE;
	}

	// Open source file and return date / time / attributes
	// - pszName:  complete path to filename
	// - pdate:    FAT-style date code
	// - ptime:    FAT-style time code
	// - pattribs: FAT-style attributes
	// - p_Param:  your user defined parameter which you have passed to AddFile(..)
	// Exit-Success: Return file handle of open file to read
	// Exit-Failure: Return -1
	INT_PTR GetAttribsAndDateW(WCHAR* u16_File, USHORT *pdate, USHORT *ptime, USHORT *pattribs, int *err)
	{
		#if _TraceCompress
			CStrW s_FileName;
			CFile::SplitPathW(u16_File, 0, &s_FileName);
			CTrace::TraceW(L"GetAttribsAndDate('%s'), UTC=%d, UTF=%d", (WCHAR*)s_FileName, mb_UtcTime, mb_NameInCabIsUtf);
		#endif

		HANDLE h_File = CreateFileW(u16_File, GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
		                            FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);

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
		*pattribs = (USHORT)(k_FileInfo.dwFileAttributes & (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_ARCHIVE));

		if (mb_UtcTime)        *pattribs |= FILE_ATTR_UTC_TIME;
		if (mb_NameInCabIsUtf) *pattribs |= _A_NAME_IS_UTF;

		// Now return a handle using _wopen()
		return FciOpenW(u16_File, _O_RDONLY | _O_BINARY, _S_IREAD, err);
	}
};

} // Namespace Cabinet
