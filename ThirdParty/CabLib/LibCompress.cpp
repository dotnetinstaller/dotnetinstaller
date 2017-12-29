// -------------------------------------------------------
// CabLib by ElmüSoft
// www.netcult.ch/elmue
// -------------------------------------------------------


#include "stdafx.h"

#include <windows.h>
#include <stdio.h>
#include "LibCompress.h" // LAST IN ORDER !!

#pragma warning(disable: 4996)

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Reflection;
using namespace System::Security::Cryptography;
using namespace System::Runtime::InteropServices;  // Marshal

namespace CabLib
{

// Constructor
CabLib::Compress::Compress()
{
    mi_Compress = 0;
    ms_TempDir  = "";
    me_Compress = eCompress::LZX; // Default
    mu8_Key     = gcnew array<Byte>(0);
}

// This must be called from another thread!
void CabLib::Compress::AbortOperation()
{
    if (mi_Compress) mi_Compress->AbortOperation();
}

// s_TempDir may specify a TEMP directory where to store the temporary files.
// This makes sense for the compression of huge files.
// s_TempDir = null --> the Windows default Temp directoy will be used
void CabLib::Compress::SetTempDirectory(String^ s_TempDir)
{ 
    ms_TempDir = s_TempDir;
}

// Creates a SHA512 hash from the given Unicode string 
// and uses this 64 Byte hash as key for the Blowfish algorithm which encrypts CAB data.
// This makes encryption more secure: See http://en.wikipedia.org/wiki/Key_derivation_function
void CabLib::Compress::SetEncryptionKey(String^ s_Password)
{
    if (s_Password->Length == 0)
    {
        mu8_Key = gcnew array<Byte>(0);
    }
    else
    {
        array<Byte>^ u8_Pass = gcnew array<Byte>(s_Password->Length * 2);

        // Copy the unicode string into the Byte array
        for (int i=0; i<s_Password->Length; i++)
        {
            u8_Pass[i*2]   = s_Password[i] % 256;
            u8_Pass[i*2+1] = s_Password[i] / 256;
        }

        SHA512^ i_Hash = gcnew SHA512Managed(); 
        mu8_Key = i_Hash->ComputeHash(u8_Pass);
    }
}

// The key passed to this function will be passed directly to the Blowfish encryption
// If the key is longer  than 72 Byte, the remaining bytes will be ignored.
// If the key is shorter than 72 Byte, its bytes will be reused multiple times.
// You should use this function only for setting binary keys.
// For plain text passwords use SetEncryptionKey(String^)
void CabLib::Compress::SetEncryptionKey(array<Byte>^ u8_Key)
{ 
    mu8_Key = u8_Key;
}

// Set Compression algorithm: see declaration of eCompress
void CabLib::Compress::SwitchCompression(eCompress e_Compress)
{
    me_Compress = e_Compress;
}

// Packs a folder s_Folder and all files in all its subfolders into a CAB file s_CabFile
//    preserving the relative paths, file attributes and dates of the files
// s_Filter = "*.*" to pack all files
// b_UtcTime = TRUE -> store the files with UTC time in the CAB file (recommended)
//    Windows stores files with UTC time. If you compress with local time you will have
//    a discrepancy of one hour or more after daylight saving or timezone changes
//    When extracting you must set the same value for this flag!!
// b_EncodeUTF=TRUE  -> If a filename has characters > 0x7F, encode it using UTF8
// b_EncodeUTF=FALSE -> Store ANSI filenames unchanged, read documentation!
// The CAB file will be split into peaces of s32_SplitSize
//    If s32_SplitSize == 0 --> no splitting
// Throws an exception on error
void CabLib::Compress::CompressFolder(String^ s_Folder, 
                                      String^ s_CabFile, 
                                      String^ s_Filter,    // may be null to compress ALL file types
                                      bool    b_UtcTime,
                                      bool    b_EncodeUtf,
                                      Int32 s32_SplitSize) // may be 0
{
    int s32_BaseFolderLen = s_Folder->Length;
    if (!s_Folder->EndsWith("\\")) s32_BaseFolderLen ++;

    ArrayList^ i_FileList = gcnew ArrayList();
    EnumFiles (i_FileList, s_Folder, s_Filter, true);

    // Now replace the entries in i_FileList with String[2] where the first string is the path
    // to the file and the second string is the relative path in the CAB file
    for (int i=0; i<i_FileList->Count; i++)
    {
        array<String^>^ s_Items = gcnew array<String^>(2);

        s_Items[0] = static_cast<String^>(i_FileList[i]); // File name
        s_Items[1] = s_Items[0]->Substring(s32_BaseFolderLen);  // Cut base path -> rel path in CAB

        i_FileList[i] = s_Items;
    }

    CompressFileList(i_FileList, s_CabFile, b_UtcTime, b_EncodeUtf, s32_SplitSize);
}


// Creates a CAB file s_CabFile
// i_FileList must contain String[2] items where the first string is the full path on disk
//    to the file to be packed into the CAB archive and the second string is the path inside the 
//    CAB archive
//    Example: i_FileList[0] = { "C:\Windows\Explorer.exe", "FileManager\Explorer.exe" }
//    This would create a subfolder "FileManager" in the CAB file with the file "Explorer.exe" in it
// b_UtcTime = TRUE -> store the files with UTC time in the CAB file (recommended)
//    Windows stores files with UTC time. If you compress with local time you will have
//    a discrepancy of one hour or more after daylight saving or timezone changes
//    When extracting you must set the same value for this flag!!
// b_EncodeUTF=TRUE  -> If a filename has characters > 0x7F, encode it using UTF8
// b_EncodeUTF=FALSE -> Store ANSI filenames unchanged, read documentation!
// The CAB file will be split into peaces of s32_SplitSize
//    If s32_SplitSize == 0 --> no splitting
// Throws an exception on error
void CabLib::Compress::CompressFileList(ArrayList^ i_FileList, 
                                        String^    s_CabFile, 
                                        bool       b_UtcTime,
                                        bool       b_EncodeUtf,
                                        Int32    s32_SplitSize) // may be 0
{
    if (mi_Compress) throw gcnew Exception(gcnew String(L"You cannot call CompressFileList() from two different threads. Please create a new instance for each thread!"));

    Exception^ i_Ex = nullptr;

    if (s32_SplitSize <= 0) s32_SplitSize = 0x7FFFFFFF; // Maximum = 2 GB

    WCHAR* u16_CabFile = (WCHAR*)Marshal::StringToHGlobalUni( s_CabFile).ToPointer();
    WCHAR* u16_TempDir = (WCHAR*)Marshal::StringToHGlobalUni(ms_TempDir).ToPointer();
    
    cCompressBridge i_Bridge(this);

    Cabinet::CCompress i_Compress;
    i_Compress.SetCallbacks(i_Bridge.GetCallbacks());
    mi_Compress = &i_Compress;

    BYTE  u8_Key[72];
    UINT u32_Len = min(72, mu8_Key->Length);
    for (UINT i=0; i<u32_Len; i++)
    {
        u8_Key[i] = mu8_Key[i]; // copy managed --> unmanged
    }
    i_Compress.SetEncryptionKey(u8_Key, u32_Len);

    // If u16_TempDir == "" set Windows default Temp directory
    // returns FALSE on error creating the Temp folder
    if (!i_Compress.SetTempDirectoryW(u16_TempDir))
    {
        i_Ex = gcnew Exception(String::Format("CabLib Compress ERROR: Error setting temp directory: {0}",
                               gcnew String(i_Compress.LastErrorW())));
        goto _Exit;
    }

    // The CabID is a user defined value which is stored in the Cabinet on compression
    // and can be retrieved later with Extract.IsFileCabinet()
    UInt16 u16_SetID = 0;
    if (!i_Compress.CreateFCIContextW(u16_CabFile, (b_UtcTime!=false), (b_EncodeUtf!=false), s32_SplitSize, u16_SetID, &i_Bridge)) // bool --> BOOL
    {
        i_Ex = gcnew Exception(String::Format("CabLib Compress ERROR: Could not create FCI context: {0}", 
                               gcnew String(i_Compress.LastErrorW())));
        goto _Exit;
    }

    for (int i=0; i<i_FileList->Count; i++)
    {
        array<String^>^ s_Item = static_cast<array<String^>^>(i_FileList[i]);
        if (s_Item->Length != 2)
        {
            i_Ex = gcnew Exception("Invalid Parameter: CompressFileList() requires an ArrayList with string pairs. Read the documentation!");
            goto _Exit;
        }

        WCHAR* u16_File      = (WCHAR*)Marshal::StringToHGlobalUni(s_Item[0]).ToPointer();
        WCHAR* u16_PathInCab = (WCHAR*)Marshal::StringToHGlobalUni(s_Item[1]).ToPointer();

        BOOL b_OK = i_Compress.AddFileW(u16_File, u16_PathInCab, (Cabinet::CCompress::eCompress)me_Compress);

        Marshal::FreeHGlobal((IntPtr)u16_File);
        Marshal::FreeHGlobal((IntPtr)u16_PathInCab);

        if (!b_OK)
        {
            i_Ex = gcnew Exception(String::Format("CabLib Compress ERROR: Could not add file \"{0}\" to cabinet: {1}", 
                                   s_Item[0], gcnew String(i_Compress.LastErrorW())));
            goto _Exit;
        }
    }

    if (!i_Compress.DestroyFCIContext())
    {
        i_Ex = gcnew Exception(String::Format("CabLib Compress ERROR: Could not flush cabinet: {0}", 
                               gcnew String(i_Compress.LastErrorW())));
        goto _Exit;
    }

    _Exit:
    Marshal::FreeHGlobal((IntPtr)u16_CabFile);
    Marshal::FreeHGlobal((IntPtr)u16_TempDir);

    mi_Compress = 0;
    if (i_Ex) throw i_Ex;
}

// ###############################################################################################
// ###############################################################################################
//                                       HELPER FUNCTIONS
// ###############################################################################################
// ###############################################################################################

// This function lists all files in the given folder s_Path and optionally its subfolders 
// into an ArrayList
// s_Filter = "*.Dll|*.Exe|*.Dat" (file extensions delimited by a pipe character)
// s_Path   = The folder to scan
void CabLib::Compress::EnumFiles(ArrayList^ i_FileList, 
                                 String^    s_Path, 
                                 String^    s_Filter,     // if null -> list ALL file types
                                 bool       b_Subfolders)
{
    if (!s_Filter || !s_Filter->Length) s_Filter = "*.*";

    array<Char>^ c_Pipe = gcnew array<Char>('|');
    array<String^>^ s_ExtList = s_Filter->Split(c_Pipe);
    for (int i=0; i<s_ExtList->Length; i++)
    {
        String^ s_Ext = static_cast<String^>(s_ExtList[i]);
        RecursiveEnumFiles(i_FileList, s_Path, s_Ext, b_Subfolders);
    }
}

// private function
void CabLib::Compress::RecursiveEnumFiles(ArrayList^ i_FileList, String^ s_Path, String^ s_Filter, bool b_Subfolders)
{
    int Len = s_Path->Length;
    if (!s_Path || Len == 0)
        return;

    // Path must terminate with "\"
    s_Path = TerminatePath(s_Path);

    array<String^>^ s_Files = Directory::GetFiles(s_Path, s_Filter->Trim());
    for (int i=0; i<s_Files->Length; i++)
    {
        i_FileList->Add(s_Files[i]);
    }

    if (b_Subfolders)
    {
        array<String^>^ s_Dirs = Directory::GetDirectories(s_Path);
        for (int i=0; i<s_Dirs->Length; i++)
        {
            String^ s_Dir = static_cast<String^>(s_Dirs[i]);
            RecursiveEnumFiles(i_FileList, s_Dir, s_Filter, true);
        }
    }
}

String^ CabLib::Compress::TerminatePath(String^ s_Path)
{
    if (s_Path->Length && !s_Path->EndsWith("\\")) s_Path = String::Concat(s_Path, "\\");
    return s_Path;
}

// If you need to use the good old sprintf/swprintf in your C# code you can do that with this function:
// s_Format =  "File_%04X.%s" and o_Values[0] = 10 and o_Values[1] = "cab"
// will return "File_000A.cab"
String^ CabLib::Compress::Sprintf(String^ s_Format, array<Object^>^ o_Values)
{
    WCHAR*  u16_Format = (WCHAR*)Marshal::StringToHGlobalUni(s_Format).ToPointer();
    VARIANT* pk_Args   = new VARIANT[o_Values->Length];

    for (int i=0; i<o_Values->Length; i++)
    {
        Marshal::GetNativeVariantForObject(o_Values[i], (IntPtr)(pk_Args + i));
    }

    Cabinet::CStrW s_String;
    s_String.Format(u16_Format, o_Values->Length, pk_Args);

    for (int i=0; i<o_Values->Length; i++)
    {
        VariantClear(pk_Args + i); // free BSTR if required
    }

    delete pk_Args;
    Marshal::FreeHGlobal((IntPtr)u16_Format);

    return gcnew String(s_String);
}

// ###############################################################################################
// ###############################################################################################
//                                  COMPRESS EVENT HANDLER
// ###############################################################################################
// ###############################################################################################


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
// - s8_CabNameFormatter:
//      is the filename which the caller has specified in CreateFCIContext
// - p_Param:
//      your user defined parameter which you have passed to AddFile(..)
// return TRUE for success, or FALSE to abort cabinet creation.
BOOL CabLib::cCompressBridge::OnGetNextCabinet(PCCAB pccab, ULONG cbPrevCab, char* s8_CabNameFormatter, void* p_Param)
{ 
    // Modify if required:
    // pccab->iCab = xyz
    // pccab->iDisk = xyz
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
int CabLib::cCompressBridge::OnUpdateStatus(UINT typeStatus, Cabinet::CCompress::kCurStatus *pk_CurStatus, void* p_Param)
{
    if (!p_Param) // May happen if destructor of CCompress calls DestroyFciContext()
        return 0;

    // copy to managed structure
    Compress::kCurStatus^ k_Status = gcnew Compress::kCurStatus();
    k_Status->cb1                     = pk_CurStatus->cb1;
    k_Status->cb2                     = pk_CurStatus->cb2;
    k_Status->u32_TypeStatus          = typeStatus;
    k_Status->u32_FolderPercent       = pk_CurStatus->FolderPercent;
    k_Status->u32_TotCompressedSize   = pk_CurStatus->u32_TotCompressedSize;
    k_Status->u32_TotUncompressedSize = pk_CurStatus->u32_TotUncompressedSize;

    cCompressBridge* p_Bridge = (cCompressBridge*)p_Param;
    return p_Bridge->mi_Instance->FireUpdateStatus(k_Status);
}

// Called whenever the location of a file or file segment on a particular cabinet has been finalized.
// This information is useful only when files are being stored across multiple cabinets
// fContinuation is a bool which signifies whether the file is a later segment 
// of a file which has been split across cabinets.  
int CabLib::cCompressBridge::OnFilePlaced(CCAB *pccab, WCHAR* u16_File, int s32_FileSize, BOOL fContinuation, void* p_Param)
{
    if (!p_Param) // May happen if destructor of CCompress calls DestroyFciContext()
        return 0; 

    cCompressBridge* p_Bridge = (cCompressBridge*)p_Param;
    return p_Bridge->mi_Instance->FireFilePlaced(gcnew String(u16_File), s32_FileSize, (fContinuation != FALSE)); // BOOL --> bool
}

} // Namespace CabLib