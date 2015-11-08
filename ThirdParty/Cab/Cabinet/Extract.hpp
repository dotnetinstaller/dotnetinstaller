///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://netcult.ch/elmue)
// Date: 23-08-2008
//
// Filename: Extract.hpp
//
// Classes:
// - CExtract
//
// Purpose: This class extracts files from a cabinet file (CAB) on disk
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

######################################################################################

Extraction of splitted CAB files is quite tricky:
When showing the content of a splitted CAB file (index) you see only those files that START in this CAB
A compressed file may span over multiple CABs but its name appears only in the CAB where the file starts.
Example:
******************************
Part_1.cab: (the index of Part_1.cab shows only Manager.exe)
Manager.exe (first part)
Part_2.cab: (the index of Part_2.cab is empty !!)
Manager.exe (second part)
Part_3.cab: (the index of Part_3.cab shows only Utils.dll and Config.xml !!)
Manager.exe (last part)
Utils.dll
Config.xml
Part_4.cab: (the index of Part_4.cab shows only Data.bin !!)
Data.bin
******************************
In this example we must call mf_FdiCopy("Part_1.cab") and Cabinet.dll will automatically
load Part_2.cab and Part_3.cab to extract the entire file Manager.exe
But if we do not call mf_FdiCopy("Part_3.cab") afterwards, the files Utils.dll and Config.xml will 
NOT be extracted although Part_3.cab has already been processed!!
******************************
mf_FdiCopy("Part_1.cab")
Reading Part_1.cab
Callback fdintCABINET_INFO with NextCAB = "Part_2.cab"
Extracting first part of Manager.exe
Callback fdintNEXT_CABINET with NextCAB = "Part_2.cab" because Manager.exe continues in the Part_2.cab
Reading Part_2.cab
Callback fdintCABINET_INFO with NextCAB = "Part_3.cab"
Extracting second part of Manager.exe
Callback fdintNEXT_CABINET with NextCAB = "Part_3.cab" because Manager.exe continues in the Part_3.cab
Reading Part_3.cab
Callback fdintCABINET_INFO with NextCAB = "Part_4.cab"
Extracting last part of Manager.exe
mf_FdiCopy("Part_3.cab") !!! IMPORTANT to extract the remaining files in Part_3.cab !!!!
Reading Part_3.cab  (### AGAIN ###)
Callback fdintCABINET_INFO with NextCAB = "Part_4.cab" (### AGAIN ###)
Extracting Utils.dll
Extracting Config.xml
mf_FdiCopy("Part_4.cab")
Reading Part_4.cab
Callback fdintCABINET_INFO with NextCAB = ""
Extracting Data.bin
******************************
ATTENTION: 
The callback fdintNEXT_CABINET is ONLY called if a compressed file continues in the next CAB!!
See also the comments in FDI.h

######################################################################################
*/

#pragma once

// turn off useless Visual Studio 6 warning: 
// "Identifier was truncated to '255' characters in the debug information"
#pragma warning (disable: 4786)


#include <io.h>     // _open
#include <stdio.h>  // sprintf
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <wininet.h>
#include "FDI.h"

#include "Defines.h"
#include "Static.hpp"
#include "Map.hpp"
#include "File.hpp"
#include "Trace.hpp"
#include "Error.hpp"
#include "Blowfish.hpp"

#pragma warning(disable: 4996)

namespace Cabinet
{

    class CExtract
    {
    public:

        // Structures used as parameters for the notification functions.
        struct kCabinetInfo
        {
            char*   s8_NextCabinet;  // Name of the next cabinet excluding path info
            char*   s8_NextDisk;     // Name of the next disk
            WCHAR* u16_Path;         // Unicode path
            USHORT u16_SetID;        // The set ID of this cabinet
            USHORT u16_Cabinet;      // The cabinet number within the cabinet set (starting at 0)
        };

        struct kCabinetFileInfo
        {
            WCHAR* u16_File;      // Only the filename of the file
            WCHAR* u16_SubFolder; // The subfolder in the CAB file
            WCHAR* u16_RelPath;   // The relative path in the CAB file
            WCHAR* u16_Path;      // The full path to the file on disk
            WCHAR* u16_FullPath;  // The full path to the file plus the filename
            LONG   s32_Size;      // Uncompressed file size
            FILETIME k_Time;      // Time and date of the file
            USHORT u16_Attribs;   // Attributes of the file
        };

        struct kProgressInfo
        {
            WCHAR* u16_RelPath;   // The relative path in the CAB file
            WCHAR* u16_FullPath;  // The full path to the file on disk
            ULONG  u32_TotSize;   // Uncompressed file size
            ULONG  u32_Written;   // Bytes written to disk
            float   fl_Percent;   // Percent written
        };

        struct kCallbacks
        {
            typedef BOOL (*t_BeforeCopyFile)(kCabinetFileInfo* pk_Info, void* p_Param);
            typedef void (*t_AfterCopyFile) (WCHAR* u16_File, CMemory* pi_ExtractMem, void* p_Param);
            typedef void (*t_ProgressInfo)  (kProgressInfo* pk_Progress, void* p_Param);
            typedef void (*t_CabinetInfo)   (kCabinetInfo* pk_Info, void* p_Param);
            typedef void (*t_NextCabinet)   (kCabinetInfo* pk_Info, int s32_Error, void* p_Param);
            // only used in .NET project:
            typedef int  (*t_StreamGetLen)  (void* p_Param);
            typedef int  (*t_StreamRead)    (void* p_Buffer, int Pos, UINT u32_Count, void* p_Param);

            t_BeforeCopyFile f_OnBeforeCopyFile;
            t_AfterCopyFile  f_OnAfterCopyFile;
            t_ProgressInfo   f_OnProgressInfo;
            t_CabinetInfo    f_OnCabinetInfo;
            t_NextCabinet    f_OnNextCabinet;
            t_StreamGetLen   f_StreamGetLen;
            t_StreamRead     f_StreamRead;
            int            s32_ProgressInterval; // Interval in ms or 0 --> call always

            kCallbacks()
            {
                f_OnBeforeCopyFile   = 0;
                f_OnAfterCopyFile    = 0;
                f_OnProgressInfo     = 0;
                f_OnCabinetInfo      = 0;
                f_OnNextCabinet      = 0;
                f_StreamGetLen       = 0;
                f_StreamRead         = 0;
                s32_ProgressInterval = 200; // Call Progress Callback every 200 ms
            }
        };


        // Constructor
        CExtract() : mi_Error(TRUE)
        { 
#if _TraceExtract
            CTrace::TraceW(L"Constructor CExtract()");
#endif

            mh_FDIContext = 0;
            mh_CabinetDll = 0;
            mu8_CryptBuf  = 0;
            mu32_Codepage = 1252; // Default = ANSI (this can be overridden in SetCodepage())
            mu32_ThreadID = GetCurrentThreadId();
        }

        ~CExtract()
        { 
#if _TraceExtract
            CTrace::TraceW(L"Destructor ~CExtract()");
#endif

            CleanUp();
            // Decrement the reference count for the DLL.
            // If another instance is still using the DLL the DLL will not be unloaded!
            if (mh_CabinetDll) FreeLibrary(mh_CabinetDll);

            if (mu8_CryptBuf) delete mu8_CryptBuf;
        }

        BOOL CleanUp()
        {
            if (!DestroyFDIContext())
                return FALSE;

            // Remove "this" pointer from TLS memory
            This(TRUE, NULL);
            return TRUE;
        }

        // This function aborts the currently active operation.
        virtual void AbortOperation()
        {
            mb_Abort = TRUE;
#if _TraceExtract
            CTrace::TraceW(L"*** AbortOperation()");
#endif
        }

        // ATTENTION: Normally you will NOT need this function!!
        // If you don't know what is the purpose of this function, don't use it! Read the documentation!
        // CAB files created with this library are UTF-8 encoded and do NOT need any Codepage setting!
        // !ONLY! if you extract CAB files that have been created with any strange codepage other than ANSI or UTF-8, 
        // define the codepage here, otherwise you will get corrupted filenames!!
        void SetCodepage(DWORD u32_Codepage)
        {
            mu32_Codepage = u32_Codepage;
        }

        // Sets the key for decryption of the CAB file
        // You can pass ANY binary data here, an ANSII string or an Unicode string
        // If the password is longer  than 72 Byte, the remaining bytes will be ignored
        // If the password is shorter than 72 Byte, its bytes will be reused multiple times
        // u32_KeyLen is always the count in Bytes (for Unicode strings = characters * 2)
        // Passing u32_KeyLen = 0 turns off decryption
        // ATTENTION:
        // It is recommended not to pass the password directly to this function!
        // You should derive for example a HASH from the password and use this instead.
        // See http://en.wikipedia.org/wiki/Key_derivation_function
        void SetDecryptionKey(void* p_Key, DWORD u32_KeyLen)
        {
            mi_Blowfish.SetPassword(p_Key, u32_KeyLen);

            if (!mu8_CryptBuf)
            {
                mu8_CryptBuf = new BYTE[CRYPT_BUFFER_SIZE];
                if (!mu8_CryptBuf) throw "Fatal error: Out of memory!"; // Required for older Visual Studio versions
            }
        }

        // Sets up to 4 static callbacks which are called from Cabinet.dll during the extraction process
        void SetCallbacks(kCallbacks* pk_Callbacks)
        {
            mk_Callbacks = *pk_Callbacks;
        }

        WCHAR* LastErrorW()
        {
            return mi_Error.LastErrorW();
        }

        // Creates a new FDI context and returns TRUE if succesful or FALSE otherwise.
        BOOL CreateFDIContext()
        {
#if _TraceExtract
            CTrace::TraceW(L"*** FDICreate() ***");
#endif

            // Every class must only be accessed by one and the same thread. See "Microsoft Cabinet.dll Doku.doc"
            if (mu32_ThreadID != GetCurrentThreadId())
            {
                mi_Error.Set(FDIERROR_INVAL_THREAD,0,0);
                return FALSE;
            }

            CExtract* p_Stored = This();
            if (p_Stored)
            {
                // There is only one instance per thread allowed
                mi_Error.Set(FDIERROR_INST_PER_THREAD,0,0);
                return FALSE;
            }

            // Store "this" pointer per thread into TLS memory
            if (!This(TRUE, this))
            {
                mi_Error.Set(0,ERROR_OUTOFMEMORY,0);
                return FALSE;
            }

            mi_Error.Reset();

            if (mh_FDIContext)
                return FALSE;

#if STATIC_LINK_CABINET_DLL // Use precompiled functions in FDI.LIB

            mf_FdiCreate    = FDICreate;
            mf_FdiCopy      = FDICopy;
            mf_FdiIsCabinet = FDIIsCabinet;
            mf_FdiDestroy   = FDIDestroy;

#else // Dynamic Link (execute functions in Cabinet.dll in Windows directory)

            if (!mh_CabinetDll)
            {
                // If the DLL is already attached to this process it will not be loaded a second time!
                mh_CabinetDll   = LoadLibraryW(L"Cabinet.dll");
                mf_FdiCreate    = (fFdiCreate)    GetProcAddress(mh_CabinetDll, "FDICreate");
                mf_FdiCopy      = (fFdiCopy)      GetProcAddress(mh_CabinetDll, "FDICopy");
                mf_FdiIsCabinet = (fFdiIsCabinet) GetProcAddress(mh_CabinetDll, "FDIIsCabinet");
                mf_FdiDestroy   = (fFdiDestroy)   GetProcAddress(mh_CabinetDll, "FDIDestroy");

                if (!mf_FdiCreate || !mf_FdiCopy || !mf_FdiIsCabinet || !mf_FdiDestroy)
                {
                    mh_CabinetDll = 0;
                    mi_Error.Set(FDIERROR_LOAD_CABINET_DLL,0,0);
                    return FALSE;
                }
            }

#endif

            mh_FDIContext = mf_FdiCreate((PFNALLOC)(FDIAlloc),
                (PFNFREE) (FDIFree),
                (PFNOPEN) (FDIOpen),
                (PFNREAD) (FDIRead),
                (PFNWRITE)(FDIWrite),
                (PFNCLOSE)(FDIClose),
                (PFNSEEK) (FDISeek),
                cpu80386,
                &mi_Error.k_ERF);

            return (mh_FDIContext != NULL);
        }

        // Destroys the FDI context used by this instance and returns TRUE if succesful or FALSE otherwise.
        BOOL DestroyFDIContext()
        {
            // Every class must only be accessed by one and the same thread. See "Microsoft Cabinet.dll Doku.doc"
            if (mu32_ThreadID != GetCurrentThreadId())
            {
                mi_Error.Set(FDIERROR_INVAL_THREAD,0,0);
                return FALSE;
            }

            if (!mh_FDIContext)
                return TRUE;

#if _TraceExtract
            CTrace::TraceW(L"*** FDIDestroy() ***");
#endif

            BOOL b_Ret = mf_FdiDestroy(mh_FDIContext);
            mh_FDIContext = 0;

            mi_ExtractMem.Free(); // There may be some MB allocated
            return b_Ret;
        }


        // This function extracts one or more files from the specified cabinet.
        // sw_CabPath   = Full path to the cabinet file.
        // sw_TargetDir = Target directory.
        // sw_TargetDir = "MEMORY" --> extract to memory
        // pParam        = User defined value which will be passed to the callback function.
        BOOL ExtractFileW(const CStrW& sw_CabPath, const CStrW& sw_TargetDir, void* pParam = NULL)
        {
            // Every class must only be accessed by one and the same thread. See "Microsoft Cabinet.dll Doku.doc"
            if (mu32_ThreadID != GetCurrentThreadId())
            {
                mi_Error.Set(FDIERROR_INVAL_THREAD,0,0);
                return FALSE;
            }

            if (!mh_FDIContext)
                return FALSE;

            mp_Param = pParam;
            mb_Abort = FALSE;
            mk_CurrentFile.Reset();
            mi_Error.Reset();
            mi_Files.Clear();

            msw_TargetDir = sw_TargetDir;
            CFile::TerminatePathW(msw_TargetDir);

            mb_ExtractToMemory = (msw_TargetDir == L"MEMORY\\");

            CStrW sw_CabFolder, sw_CabFile;
            CFile::SplitPathW(sw_CabPath, &sw_CabFolder, &sw_CabFile);

            if (msw_TargetDir.Len() < 3 || sw_CabFolder.Len() < 2 || sw_CabFile.Len() < 2)
            {
                mi_Error.Set(FDIERROR_INVAL_PARAM,0,0);
                return FALSE;
            }

            while (TRUE)
            {
                msw_NextCab.Clean();

#if _TraceExtract
                CTrace::TraceW(L"++++++++++++");
                CTrace::TraceW(L"FDICopy ('%s') -> starting extraction", (WCHAR*)sw_CabFile);
#endif

                // Extract all files which start in the splitted CAB
                // When mf_FdiCopy returns FALSE the error code has already been written into mi_Error in FdiCallback.
                // If you want to debug with a Debugger to trap an error you MUST set a breakpoint in FdiCallback!
                // But it is much easier to enable _TraceExtract and observe in DebugView what's happening.
                CStrA sa_File, sa_Folder;
                if (!mf_FdiCopy(mh_FDIContext, sa_File.EncodeUtf8(sw_CabFile), sa_Folder.EncodeUtf8(sw_CabFolder), 
                    0, (PFNFDINOTIFY)(FDICallback), 0, pParam))
                    break;

                // Check if there are more splitted CAB parts to be extracted
                if (!msw_NextCab.Len())
                    break; 

                // Now extract the next file if the CAB is splitted.
                // IMPORTANT: Please read the detailed comment at the top of this file!!
                sw_CabFile = msw_NextCab;
            }

            // Close the extraction file (sometimes Cabinet.dll closes it on aborting, sometimes not)
            FdiClose(mk_CurrentFile.h_File); // FIRST!

            if (mb_Abort && mk_CurrentFile.h_File)
            {
#if _TraceExtract
                CTrace::TraceW(L"*** Extraction of '%s' has been aborted. Now deleting incomplete file.", (WCHAR*)mk_CurrentFile.sw_FullPath);
#endif

                DeleteFileW(mk_CurrentFile.sw_FullPath); // AFTER!
            }
            return (!mi_Error.HasError());
        }


        // Determines whether the cabinet with the specified handle is a valid cabinet. If it is, the structure
        // which is pointed to by pfdici will be filled with information about the cabinet file. 
        // pfdici can be NULL in which case no information about the cabinet file will be returned.
        BOOL IsCabinetW(const CStrW& sw_CabPath, PFDICABINETINFO pfdici = NULL)
        {
            // Every class must only be accessed by one and the same thread. See "Microsoft Cabinet.dll Doku.doc"
            if (mu32_ThreadID != GetCurrentThreadId())
            {
                mi_Error.Set(FDIERROR_INVAL_THREAD,0,0);
                return FALSE;
            }

            if (!mh_FDIContext)
                return FALSE;

#if _TraceExtract
            CStrW sw_FileName;
            CFile::SplitPathW(sw_CabPath, 0, &sw_FileName);
            CTrace::TraceW(L"++++++++++++");
            CTrace::TraceW(L"FDIIsCabinet('%s')", (WCHAR*)sw_FileName);
#endif

            mi_Error.Reset();
            mi_Files.Clear();
            mb_ExtractToMemory = FALSE;

            INT_PTR fd = FdiOpenW(sw_CabPath, _O_BINARY | _O_RDONLY | _O_SEQUENTIAL, _S_IREAD);
            if (fd <= 0)
                return FALSE;

            BOOL bRet;
            if (!pfdici)
            {
                FDICABINETINFO fdici;
                bRet = mf_FdiIsCabinet(mh_FDIContext, fd, &fdici);
            }
            else bRet = mf_FdiIsCabinet(mh_FDIContext, fd, pfdici);

            FDIClose(fd);
            return bRet;
        }


    protected:

        struct kCurrentFile
        {
            INT_PTR h_File;      // The handle to the file
            CStrW  sw_RelPath;   // The relative path in the CAB file
            CStrW  sw_FullPath;  // The full path to the file on disk
            ULONG u32_TotSize;   // Uncompressed file size
            ULONG u32_Written;   // Bytes written to disk
            int   s32_LastTick;  // The tickcount time of the last callback

            void Reset()
            {
                h_File = 0;
                sw_RelPath. Clean();
                sw_FullPath.Clean();
                u32_TotSize  = 0;
                u32_Written  = 0;
                s32_LastTick = 0;
            }
        };

        kCurrentFile mk_CurrentFile; // the file that is currently written to disk
        kCallbacks   mk_Callbacks;
        CFilePtr     mi_Files;
        CStrW       msw_TargetDir; // extract into this directory
        CStrW       msw_NextCab;   // Stores the next CAB file of a spanned cabinet
        CBlowfish    mi_Blowfish;
        CMemory      mi_ExtractMem;
        CError       mi_Error;

        // Handle to the FDI context.
        HFDI mh_FDIContext;

        // Flag that can be set to abort the current operation.
        BOOL    mb_Abort;
        BOOL    mb_ExtractToMemory;
        BYTE*  mu8_CryptBuf;

        // For example for extracting old CAB files that have been created on Windows 9x
        DWORD mu32_Codepage;

        // User defined value which will be passed to the callback functions.
        void* mp_Param;

        // Every class instance must only be accessed from one thread
        DWORD mu32_ThreadID;

        typedef HFDI (DIAMONDAPI* fFdiCreate)   (PFNALLOC, PFNFREE, PFNOPEN, PFNREAD, PFNWRITE, PFNCLOSE, PFNSEEK, int, PERF);
        typedef BOOL (DIAMONDAPI* fFdiCopy)     (HFDI hfdi, char*, char*, int, PFNFDINOTIFY, PFNFDIDECRYPT, void*);
        typedef BOOL (DIAMONDAPI* fFdiIsCabinet)(HFDI, INT_PTR, PFDICABINETINFO);
        typedef BOOL (DIAMONDAPI* fFdiDestroy)  (HFDI);

        HINSTANCE      mh_CabinetDll;
        fFdiCreate     mf_FdiCreate;
        fFdiCopy       mf_FdiCopy;
        fFdiIsCabinet  mf_FdiIsCabinet;
        fFdiDestroy    mf_FdiDestroy;

        // For every thread a "this" pointer is stored
        static CExtract* This(BOOL b_Set=FALSE, CExtract* p_This=NULL)
        {
            if (CStatic::mu32_ExtractTlsIndex == TLS_OUT_OF_INDEXES)
                return NULL;

            if (b_Set)
            {
                if (!TlsSetValue(CStatic::mu32_ExtractTlsIndex, p_This))
                    return NULL;
            }
            return (CExtract*)TlsGetValue(CStatic::mu32_ExtractTlsIndex);
        }

    private:

        // #################### STATIC FDI CALLBACKS ########################

        // Unlike Compression the Extraction callbacks don´t have a pThis pointer
        // So for every thread a "this" pointer must be stored

        static void* FDIAlloc(UINT size)
        { return operator new(size); }

        static void FDIFree(void* memblock)
        { operator delete(memblock); }

        static INT_PTR FDIOpen(char* s8_File, int oflag, int pmode) // Open CAB file only for reading
        { return This()->FdiOpenA(s8_File, oflag, _S_IREAD); }

        static int FDIRead(INT_PTR fd, void* memory, UINT count)
        { return This()->FdiRead(fd, memory, count); }

        static int FDIWrite(INT_PTR fd, void* memory, UINT count)
        { return This()->FdiWrite(fd, memory, count); }

        static int FDIClose(INT_PTR fd)
        { return This()->FdiClose(fd); }

        static long FDISeek(INT_PTR fd, long offset, int seektype)
        { return This()->FdiSeek(fd, offset, seektype); }

        static INT_PTR FDICallback(FDINOTIFICATIONTYPE fdint, PFDINOTIFICATION pfdin)
        { return This()->FdiCallback(fdint, pfdin); }

        // #################### MEMBER FDI CALLBACKS ########################

        INT_PTR FdiOpenA(const char* s8_File, int oflag, int pmode)
        { 
            CStrW sw_File;
            return FdiOpenW(sw_File.ToUnicode(CP_UTF8, s8_File), oflag, pmode);
        }
        INT_PTR FdiOpenW(const WCHAR* u16_File, int oflag, int pmode)
        {
            INT_PTR fd = Open(u16_File, oflag, pmode);

            // This function opens only the CAB file for reading
            // This function opens any other file for writing
            BOOL b_Write = (pmode & _S_IWRITE);
            if (!b_Write) 
            {
                mi_Files.SetPtr(fd, 0); // It is a CAB file
            }

#if _TraceExtract
            CTrace::TraceW(L"FDIOpen (%s, '%s') --> Handle= 0x%08X", (b_Write ? L"for WRITE" : L"for READ"), u16_File, fd);
#endif
            return fd;
        }

        // Called to read the CAB file
        int FdiRead(INT_PTR fd, void* memory, UINT count)
        { 
#if _TraceExtract
            CTrace::TraceW(L"FDIRead (Handle= 0x%08X, Count= %05d)", fd, count);
#endif

            int s32_Read   = -1;
            int s32_CabPtr = mi_Files.GetPtr(fd);

            if (mi_Blowfish.IsPasswordSet()) // encrypted
            {
                // Convert byte range from Start till End into 8-Byte boundaries:
                // s32_CabPtr = 0x91, count = 7 Bytes --> read only ONE block = 8 Bytes: 0x90...0x97 !!
                int s32_Start  = (s32_CabPtr)            & (~7); // Kill the last 3 bits
                int s32_End    = (s32_CabPtr + count -1) & (~7); // Kill the last 3 bits
                int s32_Count  = (s32_End -s32_Start +8) & (~7); // Kill the last 3 bits
                int s32_Offset = (s32_CabPtr %8);

                // Move filepointer to the begin of previous 8-Byte boundary
                if (s32_Offset) Seek(fd, s32_Start, SEEK_SET);

                s32_Read = Read(fd, mu8_CryptBuf, s32_Count);
                if (s32_Read < s32_Count)
                {
#if _TraceExtract
                    CTrace::TraceW(L"FDIRead (Handle= 0x%08X) ERROR: %d instead of %d Bytes read. (position 0x%X - 0x%X)", fd, s32_Read, s32_Count, s32_CabPtr, s32_CabPtr+s32_Count);
#endif
                    return -1;
                }

                // The first ENCRYPTION_START Bytes (file header) are not encrypted
                int s32_UnEncrypted = max(0, min(s32_Count, ENCRYPTION_START - s32_Start));

                // Decrypt data blocks of 8 Bytes
                mi_Blowfish.CryptBlocks(FALSE, mu8_CryptBuf+s32_UnEncrypted, (s32_Count-s32_UnEncrypted)/8);

                memmove(memory, mu8_CryptBuf+s32_Offset, count);

                // move filepointer to where Cabinet.dll expects it to be
                Seek(fd, s32_CabPtr + count, SEEK_SET);

#if _TraceExtract
                CTrace::TraceW(L"FDIRead --> %05d Bytes read, %05d Bytes decrypted, %05d Bytes copied to buffer at position 0x%05X", s32_Read, s32_Count-s32_UnEncrypted, count, s32_CabPtr);
#endif

                // Return the count of bytes that were copied to the buffer, not the bytes that were read from CAB file!
                s32_Read = count;
            }		
            else // not encrypted
            {
                s32_Read = Read(fd, memory, count); 

#if _TraceExtract
                CTrace::TraceW(L"FDIRead --> %05d Bytes read", s32_Read);
#endif
            }

            // remember the current file pointer position
            mi_Files.SetPtr(fd, s32_CabPtr + s32_Read);

            // Check the file identification (the first 4 Bytes)
            if (s32_CabPtr == 0 && s32_Read >= 4) // memory contains the first bytes of a CAB file
            {
                if (strncmp((char*)memory, "MSCF", 4) == 0)
                {
                    if (mi_Blowfish.IsPasswordSet())
                    {
                        mi_Error.Set(FDIERROR_NOT_ENCRYPTED,0,0);
                        return -1;	
                    }
                }
                else if (strncmp((char*)memory, "CRYP", 4) == 0)
                {
                    if (!mi_Blowfish.IsPasswordSet())
                    {
                        mi_Error.Set(FDIERROR_IS_ENCRYPTED,0,0);
                        return -1;	
                    }
                    else // restore File Identification for encrypted files
                    {
                        strncpy((char*)memory, "MSCF", 4);
                    }
                }
                else
                {
                    mi_Error.Set(FDIERROR_NOT_A_CABINET,0,0);
                    return -1;	
                }
            }
            return s32_Read;
        }

        // Called to write all extracted files
        int FdiWrite(INT_PTR fd, void* memory, UINT count)
        { 
#if _TraceExtract
            CTrace::TraceW(L"FDIWrite(Handle= 0x%08X, Count= %05d)", fd, count);
#endif

            int s32_Written;

            // Extract to memory -> write into CMemory
            if (mb_ExtractToMemory)
            {
                if (mi_ExtractMem.Append((BYTE*)memory, count))
                {
                    s32_Written = count;
                }
                else
                {
                    // Cabinet.dll wants to write more data than specified in fdintCOPY_FILE callback
                    mi_Error.Set(FDIERROR_INVAL_FILE_LEN,0,0);
                    s32_Written = -1;
                }
            }
            else s32_Written = Write(fd, memory, count);

            // Call the ProgressInfo callback every 200 ms
            if (s32_Written > 0 && mk_CurrentFile.h_File == fd && mk_Callbacks.f_OnProgressInfo)
            {
                mk_CurrentFile.u32_Written += s32_Written;

                int s32_Now = GetTickCount();
                if (mk_Callbacks.s32_ProgressInterval == 0 ||
                    abs(s32_Now - mk_CurrentFile.s32_LastTick) > mk_Callbacks.s32_ProgressInterval ||
                    mk_CurrentFile.u32_Written == mk_CurrentFile.u32_TotSize) // always show 100%
                {
                    mk_CurrentFile.s32_LastTick = s32_Now;

                    kProgressInfo k_Progress;
                    k_Progress.u16_FullPath = mk_CurrentFile.sw_FullPath;
                    k_Progress.u16_RelPath  = mk_CurrentFile.sw_RelPath;
                    k_Progress.u32_TotSize  = mk_CurrentFile.u32_TotSize;
                    k_Progress.u32_Written  = mk_CurrentFile.u32_Written;
                    k_Progress.fl_Percent   = (float)100 * mk_CurrentFile.u32_Written / mk_CurrentFile.u32_TotSize;

                    mk_Callbacks.f_OnProgressInfo(&k_Progress, mp_Param);
                }
            }

#if _TraceExtract
            CTrace::TraceW(L"FDIWrite --> %05d Bytes written", s32_Written);
#endif

            // Writing to CAB file does not happen while extracting
            // So we don't have to call mi_Files.SetPtr() here
            return s32_Written;
        }

        int FdiClose(INT_PTR fd)
        { 
            if (fd <= 0)
                return 0;

#if _TraceExtract
            CTrace::TraceW(L"FDIClose(Handle= 0x%08X)", fd);
#endif

            int Err = Close(fd); // FIRST !!! (Close may be overridden)

            if (fd == mk_CurrentFile.h_File)
                mk_CurrentFile.Reset();

            mi_Files.Delete(fd); // AFTERWARDS !!!
            return Err;
        }

        long FdiSeek(INT_PTR fd, long offset, int seektype)
        { 
            int Pos = Seek(fd, offset, seektype); 

#if _TraceExtract
            switch (seektype)
            {
            case SEEK_SET: CTrace::TraceW(L"FDISeek (Handle= 0x%08X, SEEK_SET, Offset= %08d) --> Position= %08d", fd, offset, Pos); break;
            case SEEK_CUR: CTrace::TraceW(L"FDISeek (Handle= 0x%08X, SEEK_CUR, Offset= %08d) --> Position= %08d", fd, offset, Pos); break;
            case SEEK_END: CTrace::TraceW(L"FDISeek (Handle= 0x%08X, SEEK_END, Offset= %08d) --> Position= %08d", fd, offset, Pos); break;
            }
#endif

            // remember the current position in the CAB file
            if (mi_Files.IsCabFile(fd))
                mi_Files.SetPtr(fd, Pos);
            return Pos;
        }

        // Callback function for the FDI context. This will get used when the Copy function is called. This
        // function will call the appropriate handlers which can be overridden to change the default behaviour.
        INT_PTR FdiCallback(FDINOTIFICATIONTYPE fdint, PFDINOTIFICATION pfdin)
        {
            // Abort if user requested
            if (mb_Abort)
                return -1;

#if _TraceExtract
            CTrace::TraceW(L"-----------------------");
#endif

            INT_PTR nRet = 0; // Allow unsupported notifications to continue

            // Relay the notifications
            switch (fdint)
            {
            case fdintCABINET_INFO:
                {
#if _TraceExtract
                    CTrace::TraceW(L"FDICallback(CABINET_INFO)");
#endif

                    // This is required when skipping large files in splitted CABs -> fdintNEXT_CABINET is never called
                    // IMPORTANT: Please read the detailed comment at the top of this file!!
                    if (msw_NextCab.Len() == 0)
                        msw_NextCab.ToUnicode(CP_UTF8, pfdin->psz1);

                    if (mk_Callbacks.f_OnCabinetInfo)
                    {
                        CStrW sw_Path;
                        kCabinetInfo k_Info; 

                        k_Info.s8_NextCabinet = pfdin->psz1;
                        k_Info.s8_NextDisk    = pfdin->psz2;
                        k_Info.u16_Path       = sw_Path.ToUnicode(CP_UTF8, pfdin->psz3);
                        k_Info.u16_SetID      = pfdin->setID;
                        k_Info.u16_Cabinet    = pfdin->iCabinet;

                        mk_Callbacks.f_OnCabinetInfo(&k_Info, mp_Param);	
                    }
                }
                break;

            case fdintNEXT_CABINET:
                {
#if _TraceExtract
                    CTrace::TraceW(L"FDICallback(NEXT_CABINET)");
#endif

                    // This is just for optimization:
                    // It avoids re-reading CABs if a compressed file spans over multiple CABs.
                    // IMPORTANT: Please read the detailed comment at the top of this file!!
                    msw_NextCab.ToUnicode(CP_UTF8, pfdin->psz1);

                    if (pfdin->fdie) // error occurred
                    {
                        // avoid error message "User Aborted"
                        mi_Error.Set(pfdin->fdie,0,0);
                        nRet = -1;
                        break;
                    }

                    if (mk_Callbacks.f_OnNextCabinet)
                    {
                        CStrW sw_Path;
                        kCabinetInfo k_Info; 

                        k_Info.s8_NextCabinet = pfdin->psz1;
                        k_Info.s8_NextDisk    = pfdin->psz2;
                        k_Info.u16_Path       = sw_Path.ToUnicode(CP_UTF8, pfdin->psz3);
                        k_Info.u16_SetID      = pfdin->setID;
                        k_Info.u16_Cabinet    = pfdin->iCabinet;

                        mk_Callbacks.f_OnNextCabinet(&k_Info, pfdin->fdie, mp_Param);
                    }
                }
                break;

                // return  0 -> skip this file
                // return -1 -> abort extraction
            case fdintCOPY_FILE:
                {
                    CStrW sw_File;      // only the filename
                    CStrW sw_SubFolder; // the relative path inside the CAB file without filename
                    CStrW sw_RelPath;   // the relative path inside the CAB file with    filename
                    CStrW sw_Path;      // the full path on disk without filename
                    CStrW sw_FullPath;  // the full path on disk with    filename

                    // If the UTF Flag is set, the filename must ALWAYS be converted using UTF-8 encoding
                    // Otherwise the default is ANSI which can be overridden in SetCodepage()
                    DWORD u32_CP = (pfdin->attribs & _A_NAME_IS_UTF) ? CP_UTF8 : mu32_Codepage;
                    sw_RelPath.ToUnicode(u32_CP, pfdin->psz1);

                    // Some strange programs like PowerArchiver store paths with slashes rather than backslashes
                    sw_RelPath.Replace('/', '\\');

                    CFile::SplitPathW(sw_RelPath, &sw_SubFolder, &sw_File);

                    sw_Path      = msw_TargetDir;
                    sw_Path     += sw_SubFolder;
                    sw_FullPath  = sw_Path;
                    sw_FullPath += sw_File;

#if _TraceExtract
                    CTrace::TraceW(L"FDICallback(COPY_FILE, '%s', Size= %d)", (WCHAR*)sw_File, pfdin->cb);
#endif

                    // Call notification function
                    if (mk_Callbacks.f_OnBeforeCopyFile)
                    {
                        kCabinetFileInfo k_FI;
                        k_FI.u16_File      = sw_File;
                        k_FI.u16_SubFolder = sw_SubFolder;
                        k_FI.u16_RelPath   = sw_RelPath;
                        k_FI.u16_Path      = sw_Path;
                        k_FI.u16_FullPath  = sw_FullPath;
                        k_FI.s32_Size      = pfdin->cb;
                        k_FI.u16_Attribs   = pfdin->attribs;
                        DosDateTimeToFileTime(pfdin->date, pfdin->time, &k_FI.k_Time);

                        if (!mk_Callbacks.f_OnBeforeCopyFile(&k_FI, mp_Param))
                        {
#if _TraceExtract
                            CTrace::TraceW(L"*** OnBeforeCopyFile() callback has canceled extraction.");
#endif
                            break;
                        }
                    }

                    if (mb_ExtractToMemory)
                    {
                        // Allocate memory to store the entire content of the file
                        mi_ExtractMem.Allocate(pfdin->cb);

                        // We must return ANY dummy handle here which is not zero.
                        // But it must be a handle which is not yet in use as a real file handle
                        UINT u32_DummyHandle = 0xFF000000;
                        while (mi_Files.IsCabFile(u32_DummyHandle))
                        {
                            u32_DummyHandle++;
                        }

#if _TraceExtract
                        CTrace::TraceW(L"Extracting to MEMORY --> Dummy Handle= 0x%08X", u32_DummyHandle);
#endif
                        nRet = u32_DummyHandle;
                    }
                    else // Extract to file
                    {
                        DWORD u32_Error = CFile::CreateFolderTreeW(sw_Path);
                        if (u32_Error)
                        {
                            mi_Error.Set(FDIERROR_TARGET_FILE,u32_Error,0);
                            nRet = -1;
                            break;
                        }

                        // IMPORTANT:
                        // If _O_TRUNC is not set, Open() will create corrupt files on disk
                        // if the file to be written already exists and is bigger than the one in the CAB
                        nRet = FdiOpenW(sw_FullPath, _O_TRUNC | _O_BINARY | _O_CREAT | _O_WRONLY | _O_SEQUENTIAL, _S_IREAD | _S_IWRITE);

                        if (nRet <= 0) 
                        {
                            mi_Error.Set(FDIERROR_TARGET_FILE,0,0); // avoid error "User Aborted" if output file could not be written
                            break;
                        }

                        mk_CurrentFile.Reset();
                        mk_CurrentFile.h_File       = nRet;
                        mk_CurrentFile.u32_TotSize  = pfdin->cb;
                        mk_CurrentFile.sw_FullPath  = sw_FullPath;
                        mk_CurrentFile.sw_RelPath   = sw_RelPath;
                        mk_CurrentFile.s32_LastTick = GetTickCount();

                        if (mk_Callbacks.f_OnProgressInfo) // Show Progress = 0 %
                        {
                            kProgressInfo k_Progress;
                            k_Progress.u16_FullPath = mk_CurrentFile.sw_FullPath;
                            k_Progress.u16_RelPath  = mk_CurrentFile.sw_RelPath;
                            k_Progress.u32_TotSize  = mk_CurrentFile.u32_TotSize;
                            k_Progress.u32_Written  = mk_CurrentFile.u32_Written;
                            k_Progress.fl_Percent   = 0.0;

                            mk_Callbacks.f_OnProgressInfo(&k_Progress, mp_Param);
                        }
                    }
                }
                break;

            case fdintCLOSE_FILE_INFO:
                {
                    CStrW sw_Path, sw_RelPath;

                    // If the UTF Flag is set, the filename must ALWAYS be converted using UTF-8 encoding
                    // Otherwise the default is ANSI which can be overridden in SetCodepage()
                    DWORD u32_CP = (pfdin->attribs & _A_NAME_IS_UTF) ? CP_UTF8 : mu32_Codepage;
                    sw_RelPath.ToUnicode(u32_CP, pfdin->psz1);

                    // Some strange programs like PowerArchiver store paths with slashes rather than backslashes
                    sw_RelPath.Replace('/', '\\');

                    sw_Path  = msw_TargetDir;
                    sw_Path += sw_RelPath;

#if _TraceExtract
                    CStrW sw_FileName;
                    CFile::SplitPathW(sw_RelPath, 0, &sw_FileName);
                    CTrace::TraceW(L"FDICallback(CLOSE_FILE_INFO, '%s', Handle= 0x%X)", (WCHAR*)sw_FileName, pfdin->hf);
#endif

                    if (!mb_ExtractToMemory) // don't call FdiClose(dummy handle) !!
                    {
                        FdiClose(pfdin->hf); // FIRST !!
                        SetAttribsAndDateW(sw_Path, pfdin->date, pfdin->time, pfdin->attribs); // AFTER!!
                    }

                    if (mk_Callbacks.f_OnAfterCopyFile)
                    {
                        CMemory* pi_Memory = (mb_ExtractToMemory) ? &mi_ExtractMem : 0;
                        mk_Callbacks.f_OnAfterCopyFile(sw_Path, pi_Memory, mp_Param);
                    }
                    nRet = TRUE;
                }
                break;

#if _TraceExtract
            case fdintPARTIAL_FILE: CTrace::TraceW(L"FDICallback(PARTIAL_FILE)");   break;
            case fdintENUMERATE:    CTrace::TraceW(L"FDICallback(ENUMERATE)");      break;
            default:                CTrace::TraceW(L"FDICallback(unknown action)"); break;
#endif
            }

#if _TraceExtract
            CTrace::TraceW(L"FdiCallback() --> 0x%08X", nRet);
            CTrace::TraceW(L"-----------------------");
#endif
            return nRet;
        }

    protected:

        // #################### OVERRIDABLES ###########################

        // Reads a file. (CAB file and extracted files)
        // This function is overridden in ExtractMemory
        virtual int Read(INT_PTR fp, void* memory, UINT count)
        { return _read((int)fp, memory, count); }

        // Writes a file. (CAB file is not written in the extraction process)
        // This function is overridden in ExtractMemory
        virtual int Write(INT_PTR fp, void* memory, UINT count)
        { return _write((int)fp, memory, count); }

        // Closes a file. (CAB file and extracted files)
        // This function is overridden in ExtractMemory
        virtual int Close(INT_PTR fp)
        { return _close((int)fp); }

        // Moves the file pointer. (CAB file and extracted files)
        // This function is overridden in ExtractMemory
        virtual long Seek(INT_PTR fp, long offset, int seektype)
        { return _lseek((int)fp, offset, seektype); }

        // Opens a file. (CAB file and extracted files)
        // This function is overridden in ExtractMemory
        virtual INT_PTR Open(const WCHAR* u16_File, int oflag, int pmode)
        { 
            // remove write protection (if file already exists)
            if (oflag & _O_CREAT) SetFileAttributesW(u16_File, FILE_ATTRIBUTE_NORMAL);
            return _wopen(u16_File, oflag, pmode); 
        }

        // #################### FDI FUNCTIONS ########################

        // Sets the date and attributes for the specified file.
        void SetAttribsAndDateW(WCHAR* u16_File, USHORT uDate, USHORT uTime, USHORT uAttribs)
        {
            BOOL b_Utc = (uAttribs & FILE_ATTR_UTC_TIME) > 0;

#if _TraceExtract
            BOOL b_Utf = (uAttribs & _A_NAME_IS_UTF) > 0;
            CStrW sw_FileName;
            CFile::SplitPathW(u16_File, 0, &sw_FileName);
            CTrace::TraceW(L"SetAttribsAndDateW('%s'), UTC=%d, UTF=%d", (WCHAR*)sw_FileName, b_Utc, b_Utf);
#endif

            HANDLE h_File = CreateFileW(u16_File, GENERIC_READ | GENERIC_WRITE,
                FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

            if (h_File == INVALID_HANDLE_VALUE)
            {
#if _TraceExtract
                CTrace::TraceW(L"SetAttribsAndDateW('%s') ***** Error %d opening file!", u16_File, GetLastError());
#endif
                return;
            }

            ::FILETIME k_CabTime;
            if (DosDateTimeToFileTime(uDate, uTime, &k_CabTime))
            {
                // The Windows filesystem stores UTC times
                ::FILETIME k_FileTime = k_CabTime;

                if (!b_Utc) LocalFileTimeToFileTime(&k_CabTime, &k_FileTime); // Local time --> UTC

                SetFileTime(h_File, &k_FileTime, 0, &k_FileTime);
            }

            CloseHandle(h_File);

            UINT u32_Attribs = uAttribs & (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_ARCHIVE);
            SetFileAttributesW(u16_File, u32_Attribs);
        }
    };

} // Namespace Cabinet
