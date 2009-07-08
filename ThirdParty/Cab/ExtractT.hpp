///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Luuk Weltevreden
// Date: 23-07-2004
//
// Modified a lot by Elmü (http://kickme.to/elmue)
// Date: 01-08-2006
//
// Filename: ExtractT.hpp
//
// Classes:
// - CExtractT<T>
// - CExtract
//
// Purpose: This template extracts files from a cabinet file (CAB) on disk
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

// #################### START Visual Studio 6 ####################

#if _MSC_VER == 1200 // for Visual Studio 6.0 only

  // turn off MS Visual Studio 6 warning: 
  // "Identifier was truncated to '255' characters in the debug information"
  #pragma warning (disable: 4786)

  #define  IS_INTRESOURCE(_r) (((unsigned long)(_r) >> 16) == 0)
  __inline int   PtrToInt(void* p) { return((int)  (INT_PTR) p); }
  __inline void* IntToPtr(int   i) { return((void*)(INT_PTR) i); }

#endif

// #################### END Visual Studio 6 ####################

#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#include "FDI.h"
#include "Map.hpp"
#include "File.hpp"

#pragma warning(disable: 4996)

// Output of open, close, read, write and seek operations onto a debug viewer
// To view the output set 1 here and use the tool "DebugView" from www.sysinternals.com
// This application MUST be started with STRG + F5 from VisualStudio otherwise you will see nothing
#define _TraceExtract   0

// Extension for enum FDIERROR defined in Microsoft file FDI.H
#define FDIERROR_LOAD_DLL      1000
#define FDIERR_INVAL_PARAM     1001
#define FDIERR_CABFILE_UNICODE 1002
#define FDIERR_NT_PLATFORM     1003
#define FDIERR_INVAL_RESOURCE  1004
#define FDIERR_PATH_TOO_LONG   1005

namespace Cabinet
{

template <class T> class CExtractT
{
public:

	CExtractT()
	{ 
		mh_FDIContext   = 0;
		mh_CabinetDll   = 0;
		mu32_OrgError   = 0;
		memset(&mk_Error, 0, sizeof(ERF));
	}

	~CExtractT()
	{ 
		DestroyFDIContext(); 
		// Decrement the reference count for the DLL.
		// If another instance is still using the DLL the DLL will not be unloaded!
		if (mh_CabinetDll) FreeLibrary(mh_CabinetDll);
	}

	// This function aborts the currently active operation.
	void AbortOperation()
	{
		mb_Abort = TRUE; 
	}

	// The same as SetDecryptionKeyA for Unicode
	BOOL SetDecryptionKeyW(WCHAR* u16_DecryptKey)
	{
		CUtf7 i_Utf;
		return SetDecryptionKeyA(i_Utf.Encode(u16_DecryptKey));
	}

	// Sets the key for decryption of the CAB file
	// You can also pass binary data here which must be zero terminated
	BOOL SetDecryptionKeyA(char* s8_DecryptKey)
	{
		int s32_KeyLen = (int) strlen(s8_DecryptKey);

		if (s32_KeyLen >= sizeof(Store().s8_Key))
			return FALSE;

		Store().s32_KeyLen = s32_KeyLen;
		memcpy(Store().s8_Key, s8_DecryptKey, s32_KeyLen);
		return TRUE;
	}

	// Creates a new FDI context and returns TRUE if succesful or FALSE otherwise.
	BOOL CreateFDIContext()
	{
		memset(&mk_Error, 0, sizeof(ERF));
		mu32_OrgError = 0;

		if (mh_FDIContext)
			return FALSE;

		if (!mh_CabinetDll)
		{
			// If the DLL is already attached to this process it will not be loaded a second time!
			mh_CabinetDll   = LoadLibraryA("Cabinet.dll");
			mf_FdiCreate    = (fFdiCreate)    GetProcAddress(mh_CabinetDll, "FDICreate");
			mf_FdiCopy      = (fFdiCopy)      GetProcAddress(mh_CabinetDll, "FDICopy");
			mf_FdiIsCabinet = (fFdiIsCabinet) GetProcAddress(mh_CabinetDll, "FDIIsCabinet");
			mf_FdiDestroy   = (fFdiDestroy)   GetProcAddress(mh_CabinetDll, "FDIDestroy");

			if (!mf_FdiCreate || !mf_FdiCopy || !mf_FdiIsCabinet || !mf_FdiDestroy)
			{
				mh_CabinetDll  = 0;
				mk_Error.fError  = TRUE;
				mk_Error.erfOper = FDIERROR_LOAD_DLL;
				return FALSE;
			}
		}

		mh_FDIContext = mf_FdiCreate((PFNALLOC)(FDIAlloc),
		                             (PFNFREE) (FDIFree),
		                             (PFNOPEN) (FDIOpen),
		                             (PFNREAD) (FDIRead),
		                             (PFNWRITE)(FDIWrite),
		                             (PFNCLOSE)(FDIClose),
		                             (PFNSEEK) (FDISeek),
		                             cpu80386,
		                             &mk_Error);

		return (mh_FDIContext != NULL);
	}

	// Destroys the FDI context used by this instance and returns TRUE if succesful or FALSE otherwise.
	BOOL DestroyFDIContext()
	{
		if (!mh_FDIContext)
			return TRUE;

		BOOL b_Ret = mf_FdiDestroy(mh_FDIContext);
		mh_FDIContext = NULL;
		return b_Ret;
	}

	// The same as ExtractFileA for Unicode
	BOOL ExtractFileW(WCHAR* u16_CabFile, WCHAR* u16_TargetDir, void* pParam = NULL)
	{
		CUtf7 i_File, i_Dir;
		return ExtractFileA(i_File.Encode(u16_CabFile), i_Dir.Encode(u16_TargetDir), pParam);
	}

	// This function extracts one or more files from the specified cabinet.
	// s8_CabFile   = Full path to the cabinet file.
	// s8_TargetDir = Target directory.
	// pParam       = User defined value which will be passed to the callback function.
	BOOL ExtractFileA(char* s8_CabFile, char* s8_TargetDir, void* pParam = NULL)
	{
		if (!mh_FDIContext)
			return FALSE;

		mu32_OrgError = 0;
		mp_Param = pParam;
		mb_Abort = FALSE;

		if (!SafeCopyPathA(ms8_TargetDir, sizeof(ms8_TargetDir), s8_TargetDir, FALSE))
			return FALSE;

		cFile::TerminatePathA(ms8_TargetDir);

		Store().Clear();
		if (!SafeCopyPathA(Store().s8_CabFile, sizeof(Store().s8_CabFile), s8_CabFile, FALSE))
			return FALSE;

		char s8_File[CB_MAX_CAB_PATH] = "";
		char s8_Path[CB_MAX_CAB_PATH] = "";

		char* s8_Slash = strrchr((char*)s8_CabFile, '\\');
		if (s8_Slash)
		{
			int Len = static_cast<int>(s8_Slash - s8_CabFile);
			if (!SafeCopyPathA(s8_File, sizeof(s8_File), s8_Slash+1, FALSE)) return FALSE;
			if (!SafeCopyPathA(s8_Path, sizeof(s8_Path), s8_CabFile, FALSE)) return FALSE;
			s8_Path[Len+1] = 0;
		}

		if (!strlen(ms8_TargetDir) || !strlen(s8_File) || !strlen(s8_Path))
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FDIERR_INVAL_PARAM;
			return FALSE;
		}

		if (CUtf7::IsUtf(s8_File))
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FDIERR_CABFILE_UNICODE;
			return FALSE;
		}

		if (!CUtf7::IsNtPlatform() && (CUtf7::IsUtf(ms8_TargetDir) || CUtf7::IsUtf(s8_Path)))
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FDIERR_NT_PLATFORM;
			return FALSE;
		}
		
		// The information, which files are contained in a CAB file, is not only in the first part
		// of a splitted archive. It is spread over multiple parts of the CAB file.
		// Example:
		// Part_1.cab --> start        of compressed File_1.exe
		// Part_2.cab --> continuation of compressed File_1.exe
		// Part_3.cab --> start        of compressed File_2.dll
		// Part_4.cab --> continuation of compressed File_2.dll
		// We have to extract every CAB file of a splitted archive which starts a new file 
		// (in this example we must call FdiCopy(Part_1.cab) and FdiCopy(Part_3.cab))
		// otherwise not all compressed files will be extracted.
		if (!SafeCopyPathA(ms8_LastCab, sizeof(ms8_LastCab), s8_File, FALSE))
			return FALSE;

		while (TRUE)
		{
			TraceA("FDICopy (%s) -> starting extraction", s8_File);

			// Extract all files which start in the splitted CAB with the name in s8_File
			if (!mf_FdiCopy(mh_FDIContext, s8_File, s8_Path, 0, (PFNFDINOTIFY)(FDICallback), NULL, this))
				return FALSE;

			if (stricmp(s8_File, ms8_LastCab) == 0)
				break; // no more splitted parts following
			
			if (!SafeCopyPathA(s8_File, sizeof(s8_File), ms8_LastCab, FALSE))
				return FALSE;
		}
		return !mk_Error.fError;
	}

	// The same as IsCabinetA for Unicode
	BOOL IsCabinetW(WCHAR* u16_CabFile, PFDICABINETINFO pfdici = NULL)
	{
		CUtf7  i_Utf;
		return IsCabinetA(i_Utf.Encode(u16_CabFile), PFDICABINETINFO pfdici = NULL)
	}

	// Determines whether the cabinet with the specified handle is a valid cabinet. If it is, the structure
	// which is pointed to by pfdici will be filled with information about the cabinet file. 
	// pfdici can be NULL in which case no information about the cabinet file will be returned.
	BOOL IsCabinetA(char* s8_CabFile, PFDICABINETINFO pfdici = NULL)
	{
		if (!mh_FDIContext)
			return FALSE;

		if (!CUtf7::IsNtPlatform() && CUtf7::IsUtf(s8_CabFile))
		{
			mk_Error.fError  = TRUE;
			mk_Error.erfOper = FDIERR_NT_PLATFORM;
			return FALSE;
		}

		memset(&mk_Error, 0, sizeof(ERF));
		mu32_OrgError = 0;

		Store().Clear();
		if (!SafeCopyPathA(Store().s8_CabFile, sizeof(Store().s8_CabFile), s8_CabFile, FALSE))
			return FALSE;

		int  handle = FDIOpen(s8_CabFile, _O_BINARY | _O_RDONLY | _O_SEQUENTIAL, 0);
		if (!handle)
			return FALSE;

		BOOL bRet;
		if (!pfdici)
		{
			 FDICABINETINFO fdici;
			 bRet = mf_FdiIsCabinet(mh_FDIContext, handle, &fdici);
		}
		else bRet = mf_FdiIsCabinet(mh_FDIContext, handle, pfdici);

		FDIClose(handle);
		return bRet;
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

		i_Utf.Decode(GetFdiErrorA()); // convert Ansii --> Unicode

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

		char* s8_FdiErr = GetFdiErrorA();

		if (!mk_Error.erfType)
			return s8_FdiErr;
		
		char s8_Msg[5000];
		if (!FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, 0, mk_Error.erfType, 0, s8_Msg, sizeof(s8_Msg), 0))
		{
			strcpy(s8_Msg, "Windows has no explanation for this error code.");
		}

		sprintf(ms8_Error, "%s\nError %d: %s", s8_FdiErr, mk_Error.erfType, s8_Msg);
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
			mk_Error.erfOper = FDIERR_PATH_TOO_LONG;
			mu32_OrgError    = FDIERR_PATH_TOO_LONG;
			return FALSE;
		}

		strcat(s8_Buffer, s8_Path);
		return TRUE;		
	}

	// Structures used as parameters for the notification functions.
	typedef struct kCabinetInfo
	{
		char*   s8_NextCabinet;  // Name of the next cabinet excluding path info
		char*   s8_NextDisk;     // Name of the next disk
		char*   s8_Path;         // Path to the cabinet
		WCHAR* u16_Path;         // Unicode path
		USHORT u16_SetID;        // The set ID of this cabinet
		USHORT u16_Cabinet;      // The cabinet number within the cabinet set (starting at 0)
	};

	typedef struct kCabinetFileInfo
	{
		char*   s8_File;      // Only the filename of the file
		char*   s8_SubFolder; // The subfolder in the CAB file
		char*   s8_RelPath;   // The relative path in the CAB file
		char*   s8_Path;      // The full path to the file on disk
		char*   s8_FullPath;  // The full path to the file plus the filename
		WCHAR* u16_File;      // Unicode (see above)
		WCHAR* u16_SubFolder; // Unicode (see above)
		WCHAR* u16_RelPath;   // Unicode (see above)
		WCHAR* u16_Path;      // Unicode (see above)
		WCHAR* u16_FullPath;  // Unicode (see above)
		LONG   s32_Size;      // Uncompressed file size
		FILETIME k_Time;      // Time and date of the file
		USHORT u16_Attribs;   // Attributes of the file
	};

protected:

	// Print Debug Output 
	static void TraceA(char* s8_Format, ...)
	{
		#if _TraceExtract
			char s8_Buf[5001];
			va_list  args;
			va_start(args, s8_Format);
			_vsnprintf(s8_Buf, 5000, s8_Format, args);
			OutputDebugStringA(s8_Buf);
		#endif
	}

	char* GetFdiErrorA()
	{
		// avoid error "User Aborted" if output file could not be written
		if (mu32_OrgError)
			mk_Error.erfOper = mu32_OrgError;

		switch (mk_Error.erfOper)
		{
		case FDIERROR_NONE:                    return "Success";
		case FDIERROR_CABINET_NOT_FOUND:       return "Cabinet file (or part of splitted CAB) not found";
		case FDIERROR_NOT_A_CABINET:           return "Not a cabinet";
		case FDIERROR_UNKNOWN_CABINET_VERSION: return "Unknown cabinet version";
		case FDIERROR_CORRUPT_CABINET:         return "Corrupt cabinet";
		case FDIERROR_ALLOC_FAIL:              return "Memory allocation failed";
		case FDIERROR_BAD_COMPR_TYPE:          return "Unknown compression type";
		case FDIERROR_MDI_FAIL:                return "Failure decompressing data";
		case FDIERROR_TARGET_FILE:             return "Failure writing to target file";
		case FDIERROR_RESERVE_MISMATCH:        return "Cabinets in set have different RESERVE sizes";
		case FDIERROR_WRONG_CABINET:           return "Cabinet returned on fdintNEXT_CABINET is incorrect";
		case FDIERROR_USER_ABORT:              return "User aborted";
		case FDIERROR_LOAD_DLL:                return "Could not load Cabinet.dll";
		case FDIERR_INVAL_PARAM:               return "Invalid parameters";
		case FDIERR_CABFILE_UNICODE:           return "The filename of the CAB file must NEVER contain Unicode characters!";
		case FDIERR_NT_PLATFORM:               return "Extracting Unicode paths requires Windows NT, 2000, XP or higher.";
		case FDIERR_INVAL_RESOURCE:            return "The specified resource could not be opened.";
		case FDIERR_PATH_TOO_LONG:             return "The path is too long. (Max 250 Ansii characters or approx 100 Unicode characters).";
		default:                               return "Unknown error";
		}
	}

	// Allocates a new block of memory and returns the pointer to the newly allocated memory. 
	// This function can be overridden.
	static void* Alloc(UINT size)
		{ return operator new(size); }

	// Frees a block of memory allocated by Alloc. 
	// This function can be overridden.
	static void Free(void* memblock)
		{ operator delete(memblock); }

	// Opens a file. (CAB file and extracted files)
	// This function is overridden in ExtractMemoryT
	static int Open(char* s8_File, int oflag, int pmode)
	{ 
		if (CUtf7::IsUtf(s8_File))
		{
			CUtf7 i_File;
			i_File.Decode(s8_File);

			// remove write protection (if file already exists)
			if (oflag & _O_CREAT) SetFileAttributesW(i_File.Decoded(), FILE_ATTRIBUTE_NORMAL);

			return _wopen(i_File.Decoded(), oflag, pmode); 
		}
		else
		{
			// remove write protection (if file already exists)
			if (oflag & _O_CREAT) SetFileAttributesA(s8_File, FILE_ATTRIBUTE_NORMAL);

			return _open(s8_File, oflag, pmode); 
		}
	}

	// Reads a file. (CAB file and extracted files)
	// This function is overridden in ExtractMemoryT
	static int Read(int fp, void* memory, UINT count)
		{ return _read(fp, memory, count); }

	// Writes a file. (CAB file is not written in the extraction process)
	// This function is overridden in ExtractMemoryT
	static int Write(int fp, void* memory, UINT count)
		{ return _write(fp, memory, count); }

	// Closes a file. (CAB file and extracted files)
	// This function is overridden in ExtractMemoryT
	static int Close(int fp)
		{ return _close(fp); }

	// Moves the file pointer. (CAB file and extracted files)
	// This function is overridden in ExtractMemoryT
	static long Seek(int fp, long offset, int seektype)
		{ return _lseek(fp, offset, seektype); }

	// The static instance of the kStore structure
	static kStore& Store()
	{
		static kStore k_Store;
		return k_Store;
	}

	// Handle to the FDI context.
	HFDI mh_FDIContext;

	// Struct that is used for storing error information.
	ERF  mk_Error;

	// Used for LastError()
	WCHAR mu16_Error[5000];
	char   ms8_Error[5000];

	// The origional error which caused an abortion of the extraction process
	UINT mu32_OrgError;

	// User defined parameter to pass to the callback function.
	void* mp_Param;

	// Flag that can be set to abort the current operation.
	BOOL mb_Abort;

	// Holds a pointer to the name of the target directory.
	char ms8_TargetDir[CB_MAX_CAB_PATH];

	// Stores the last CAB file of a spanned cabinet which has been read
	char  ms8_LastCab[CB_MAX_CAB_PATH];

	typedef HFDI (DIAMONDAPI* fFdiCreate)   (PFNALLOC, PFNFREE, PFNOPEN, PFNREAD, PFNWRITE, PFNCLOSE, PFNSEEK, int, PERF);
	typedef BOOL (DIAMONDAPI* fFdiCopy)     (HFDI hfdi, char*, char*, int, PFNFDINOTIFY, PFNFDIDECRYPT, void*);
	typedef BOOL (DIAMONDAPI* fFdiIsCabinet)(HFDI, int, PFDICABINETINFO);
	typedef BOOL (DIAMONDAPI* fFdiDestroy)  (HFDI);

	HINSTANCE      mh_CabinetDll;
	fFdiCreate     mf_FdiCreate;
	fFdiCopy       mf_FdiCopy;
	fFdiIsCabinet  mf_FdiIsCabinet;
	fFdiDestroy    mf_FdiDestroy;

private:
	static int FDIOpen(char* s8_File, int oflag, int pmode)
	{ 
		int fd = T::Open(s8_File, oflag, pmode);

		TraceA("+++++++");
		TraceA("FDIOpen (%s) --> Handle= 0x%08X", s8_File, fd);

		// The output CAB file has just been opened -> remember its handle
		if (stricmp(s8_File, Store().s8_CabFile) == 0)
			Store().SetPtr(fd, 0);

		return fd;
	}

	static int FDIRead(int fd, void* memory, UINT count)
	{ 
		int Read = T::Read(fd, memory, count); 

		TraceA("FDIRead (Handle= 0x%08X, Count= %05d) --> %05d Bytes read", fd, count, Read);

		// Decrypt the data block if SetDecryptionKey() has been called before
		int s32_CabPtr = Store().GetPtr(fd);
		if (s32_CabPtr >= 0)
		{
			if (Store().s32_KeyLen)
			{
				DecryptDataBlock(memory, Read, Store().s8_Key, Store().s32_KeyLen, s32_CabPtr);
			}

			// remember the current file pointer in the CAB file
			Store().SetPtr(fd, s32_CabPtr + Read);
		}
		return Read;
	}

	static int FDIWrite(int fd, void* memory, UINT count)
	{ 
		int Written = T::Write(fd, memory, count); 

		TraceA("FDIWrite(Handle= 0x%08X, Count= %05d) --> %05d Bytes written", fd, count, Written);

		// Writing to CAB file does not happen while extracting
		// So we don't have to call Store().SetPtr() here

		return Written;
	}

	static int FDIClose(int fd)
	{ 
		TraceA("FDIClose(Handle= 0x%08X)", fd);
		TraceA("-------");

		int Err = T::Close(fd); // ORDER FIRST !!!

		// The output CAB file has just been closed -> reset its handle
		Store().Erase(fd); // ORDER AFTERWARDS !!!
		return Err;		
	}

	static long FDISeek(int fd, long offset, int seektype)
	{ 
		int Pos = T::Seek(fd, offset, seektype); 

		switch (seektype)
		{
			case SEEK_SET: TraceA("FDISeek (Handle= 0x%08X, SEEK_SET, Offset= %04d) --> Position= %04d", fd, offset, Pos); break;
			case SEEK_CUR: TraceA("FDISeek (Handle= 0x%08X, SEEK_CUR, Offset= %04d) --> Position= %04d", fd, offset, Pos); break;
			case SEEK_END: TraceA("FDISeek (Handle= 0x%08X, SEEK_END, Offset= %04d) --> Position= %04d", fd, offset, Pos); break;
		}

		// remember the current position in the CAB file
		if (Store().IsCabFile(fd))
			Store().SetPtr(fd, Pos);

		return Pos;
	}

	static void* FDIAlloc(UINT size)
	{ 
		return T::Alloc(size); 
	}

	static void FDIFree(void* memblock)
	{ 
		T::Free(memblock); 
	}

	// Callback function for the FDI context. This will get used when the Copy function is called. This
	// function will call the appropriate handlers which can be overridden to change the default behaviour.
	static int FDICallback(FDINOTIFICATIONTYPE fdint, PFDINOTIFICATION pfdin)
	{
		switch (fdint)
		{
			case fdintCABINET_INFO:    TraceA("FDICallback(CABINET_INFO)");    break;
			case fdintNEXT_CABINET:    TraceA("FDICallback(NEXT_CABINET)");    break;
			case fdintCOPY_FILE:       TraceA("FDICallback(COPY_FILE)");       break;
			case fdintCLOSE_FILE_INFO: TraceA("FDICallback(CLOSE_FILE_INFO)"); break;
			case fdintPARTIAL_FILE:    TraceA("FDICallback(PARTIAL_FILE)");    break;
			case fdintENUMERATE:       TraceA("FDICallback(ENUMERATE)");       break;
			default:                   TraceA("FDICallback(unknown action)");  break;
		}

		int nRet = 0; // Allow unsupported notifications to continue

		// Get pointer to the instance
		CExtractT<T>* pThis = (CExtractT<T>*)(pfdin->pv);

		// Abort if necessary
		if (pThis->mb_Abort)
			return -1;

		// Relay the notifications
		switch (fdint)
		{
		case fdintCABINET_INFO:
			{
				CUtf7 i_Utf;
				kCabinetInfo k_Info; 

				k_Info.s8_NextCabinet = pfdin->psz1;
				k_Info.s8_NextDisk    = pfdin->psz2;
				k_Info.s8_Path        = pfdin->psz3;
				k_Info.u16_Path       = i_Utf.Decode(pfdin->psz3);
				k_Info.u16_SetID      = pfdin->setID;
				k_Info.u16_Cabinet    = pfdin->iCabinet;

				static_cast<T *>(pThis)->OnCabinetInfo(k_Info, pThis->mp_Param);	
			}
			break;

		case fdintNEXT_CABINET :
			{
				if (pfdin->fdie) // error occurred
				{
					// avoid error "User Aborted" if next cabinet file could not be found
					pThis->mu32_OrgError = pfdin->fdie;
					return -1;
				}

				// this is required to unpack all files from a spanned archive
				if (!pThis->SafeCopyPathA(pThis->ms8_LastCab, sizeof(pThis->ms8_LastCab), pfdin->psz1, FALSE))
					return -1;

				CUtf7 i_Utf;
				kCabinetInfo k_Info; 

				k_Info.s8_NextCabinet = pfdin->psz1;
				k_Info.s8_NextDisk    = pfdin->psz2;
				k_Info.s8_Path        = pfdin->psz3;
				k_Info.u16_Path       = i_Utf.Decode(pfdin->psz3);
				k_Info.u16_SetID      = pfdin->setID;
				k_Info.u16_Cabinet    = pfdin->iCabinet;

				static_cast<T *>(pThis)->OnNextCabinet(k_Info, pfdin->fdie, pThis->mp_Param);
			}
			break;

			// return  0 -> skip this file
			// return -1 -> abort extraction
		case fdintCOPY_FILE:
			{
				char s8_File     [CB_MAX_CAB_PATH];
				char s8_SubFolder[CB_MAX_CAB_PATH];
				char s8_Path     [CB_MAX_CAB_PATH];
				char s8_FullPath [CB_MAX_CAB_PATH];

				// Split the path to a filename and path
				if (!pThis->SafeCopyPathA(s8_File,      sizeof(s8_File),      pfdin->psz1, FALSE)) return 0;
				if (!pThis->SafeCopyPathA(s8_SubFolder, sizeof(s8_SubFolder), pfdin->psz1, FALSE)) return 0;

				char* s8_Slash = strrchr(s8_SubFolder, '\\');
				if   (s8_Slash)
				{
					if (!pThis->SafeCopyPathA(s8_File, sizeof(s8_File), s8_Slash + 1, FALSE)) return 0;
					s8_Slash[1] = 0;
				}
				else s8_SubFolder[0] = 0;

				if(!pThis->SafeCopyPathA(s8_Path,     sizeof(s8_Path),     pThis->ms8_TargetDir, FALSE)) return 0; // strcpy
				if(!pThis->SafeCopyPathA(s8_Path,     sizeof(s8_Path),     s8_SubFolder,         TRUE )) return 0; // strcat
				if(!pThis->SafeCopyPathA(s8_FullPath, sizeof(s8_FullPath), s8_Path,              FALSE)) return 0; // strcpy
				if(!pThis->SafeCopyPathA(s8_FullPath, sizeof(s8_FullPath), s8_File,              TRUE )) return 0; // strcat

				if (!CUtf7::IsNtPlatform() && CUtf7::IsUtf(s8_FullPath))
				{
					pThis->mu32_OrgError   = FDIERR_NT_PLATFORM;
					pThis->mk_Error.fError = TRUE;
					return 0; // skip all Unicode files on Windows 95,98,ME
				}

				CUtf7 i_File, i_Sub, i_Rel, i_Path, i_Full;

				kCabinetFileInfo k_FI;
				k_FI.s8_File       = s8_File;
				k_FI.s8_SubFolder  = s8_SubFolder;
				k_FI.s8_RelPath    = pfdin->psz1;
				k_FI.s8_Path       = s8_Path;
				k_FI.s8_FullPath   = s8_FullPath;
				k_FI.u16_File      = i_File.Decode(s8_File);
				k_FI.u16_SubFolder = i_Sub. Decode(s8_SubFolder);
				k_FI.u16_RelPath   = i_Rel. Decode(pfdin->psz1);
				k_FI.u16_Path      = i_Path.Decode(s8_Path);
				k_FI.u16_FullPath  = i_Full.Decode(s8_FullPath);
				k_FI.s32_Size      = pfdin->cb;
				k_FI.u16_Attribs   = pfdin->attribs;
				DosDateTimeToFileTime(pfdin->date, pfdin->time, &k_FI.k_Time);

				// Call notification function
				if (!static_cast<T *>(pThis)->OnBeforeCopyFile(k_FI, pThis->mp_Param))
				{
					nRet = 0;
				}
				else
				{
					cFile::CreateFolderTreeA(s8_Path);

					// IMPORTANT:
					// If _O_TRUNC is not set, this class will create corrupt files on disk
					// if the file to be written already exists and is bigger than the one in the CAB
					nRet = FDIOpen(s8_FullPath, _O_TRUNC | _O_BINARY | _O_CREAT | _O_WRONLY | _O_SEQUENTIAL, _S_IREAD | _S_IWRITE);

					// avoid error "User Aborted" if output file could not be written
					if (nRet <= 0) pThis->mu32_OrgError = FDIERROR_TARGET_FILE;
				}
			}
			break;

		case fdintCLOSE_FILE_INFO:
			{
				char s8_Path[CB_MAX_CAB_PATH] = "";

				// Close the file
				FDIClose((int)pfdin->hf);

				if (!pThis->SafeCopyPathA(s8_Path, sizeof(s8_Path), pThis->ms8_TargetDir, FALSE)) return 0; // strcpy
				if (!pThis->SafeCopyPathA(s8_Path, sizeof(s8_Path), pfdin->psz1,          TRUE )) return 0; // strcat

				CUtf7 i_Path;
				i_Path.Decode(s8_Path);

				pThis->SetAttribsAndDate(s8_Path, i_Path.Decoded(), pfdin->date, pfdin->time, pfdin->attribs);

				// Call notification function
				static_cast<T *>(pThis)->OnAfterCopyFile(s8_Path, i_Path.Decoded(), pThis->mp_Param);
				nRet = TRUE;
			}
			break;
		}

		return nRet;
	}

protected:
	// Sets the date and attributes for the specified file.
	void SetAttribsAndDate(char* s8_File, WCHAR* u16_File, USHORT uDate, USHORT uTime, USHORT uAttribs)
	{
		BOOL   b_Utf = CUtf7::IsUtf(s8_File);
		HANDLE h_File;

		if (b_Utf)
		{
			h_File = CreateFileW(u16_File, GENERIC_READ | GENERIC_WRITE,
			                     FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		}
		else
		{
			h_File = CreateFileA(s8_File, GENERIC_READ | GENERIC_WRITE,
			                     FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		}

		if (h_File == INVALID_HANDLE_VALUE)
			return;
		
		::FILETIME k_CabTime;
		if (DosDateTimeToFileTime(uDate, uTime, &k_CabTime))
		{
			// The Windows filesystem stores UTC times
			::FILETIME k_FileTime = k_CabTime;
			
			if ((uAttribs & FILE_ATTR_UTC_TIME) == 0) 
				LocalFileTimeToFileTime(&k_CabTime, &k_FileTime); // Local time --> UTC

			SetFileTime(h_File, &k_FileTime, NULL, &k_FileTime);
		}

		CloseHandle(h_File);

		UINT u32_Attribs = uAttribs & (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_ARCHIVE);

		if (b_Utf) SetFileAttributesW(u16_File, u32_Attribs);
		else       SetFileAttributesA( s8_File, u32_Attribs);
	}

	// Decrypt the data block
	// You can override this function to use your own decryption algorithm
	static void DecryptDataBlock(void*   p_Memory,  // data in memory to be decrypted
	                             UINT  u32_Count,   // size of memory block in Bytes
						         char*  s8_Key,     // the decryption key
						         int   s32_KeyLen,  // the legth of s8_Key
						         int   s32_CabPtr)  // a pointer indicating the absolute position in the CAB file where this block starts
	{
		// Restore the first 4 bytes which identify the CAB file
		if (s32_CabPtr == 0)
		{
			((char*)p_Memory)[0] = 'M';
			((char*)p_Memory)[1] = 'S';
			((char*)p_Memory)[2] = 'C';
			((char*)p_Memory)[3] = 'F';
		}

		int k = s32_CabPtr;

		// for each byte of the memory block we subtract the corresponding byte of the encryption key
		// and a value which depends on the position in the file
		for (UINT m=0; m<u32_Count; m++, k++)
		{
			k %= s32_KeyLen;

			// We let the first 0x3C Bytes of the file unencrypted (file header)
			if (s32_CabPtr + m < 0x3C)
				continue;

			((unsigned char*)p_Memory)[m] -= ((unsigned char*)s8_Key)[k];         // SUBTRACT
			((unsigned char*)p_Memory)[m] ^= ((s32_CabPtr + m + s8_Key[0]) %101); // EXOR
		}
	}

	// ########################### CALLBACKS #######################


	// This function will be called for each file in a cabinet at the moment it is about to be extracted. This
	// function can be overridden.
	// Return TRUE to extract the file to the path specified by the second parameter or FALSE to skip.
	BOOL OnBeforeCopyFile(kCabinetFileInfo &k_FI, void* p_Param)
	{
		return TRUE;
	}

	// This function will be called when a file is succesfully extracted.
	void OnAfterCopyFile(char* s8_File, WCHAR* u16_File, void* p_Param)
	{ 
	}

	// This function will be called exactly once for each cabinet opened by Copy, including continuation
	// cabinets opened due to files spanning cabinet boundaries. This function can be overridden.
	void OnCabinetInfo(kCabinetInfo &ci, void* p_Param)
	{ 
	}

	// This function will be called when the next cabinet file in the sequence needs to be opened. The path
	// has to be verified and can be changed if necessary. If the cabinet file cannot be opened this function
	// will be called again with the second parameter set to an error that describes the problem.
	void OnNextCabinet(kCabinetInfo &ci, FDIERROR s32_Error, void* p_Param)
	{ 
	}
};

class CExtract : public CExtractT<CExtract> { };

} // Namespace Cabinet