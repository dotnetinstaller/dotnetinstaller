// -------------------------------------------------------
// CabLib by ElmüSoft
// www.netcult.ch/elmue
// -------------------------------------------------------


#include "stdafx.h"

#include "stdio.h"
#include <windows.h>
#include "LibExtract.h" // LAST IN ORDER !!

#pragma warning(disable: 4996)

// Workaround for Compiler Bug: Error C2039 when using Directory::CreateDirectory()
#undef CreateDirectory

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Reflection;
using namespace System::Security::Cryptography;
using namespace System::Runtime::InteropServices;  // Marshal

namespace CabLib
{

// Constructor
CabLib::Extract::Extract()
{
    mi_Extract = 0;
    CleanUp();
}

// Destructor
CabLib::Extract::~Extract()
{
    CleanUp();
}

// Free memory, close handles
// Additionally reset all user settings
void CabLib::Extract::CleanUp()
{
    Reset();

    mu8_Key       = gcnew array<Byte>(0);
    mb_Passive    = true;
    mb_ExtractMem = false;
    ms_Proxy      = "";
    ms_Headers    = "";
    ms_SingleFile = "";
    ms32_ProgressInterval = 200; // call the callback every 200 ms
    mu32_Codepage = 1252; // Default = ANSI (this can be overridden in SetCodepage())
}

// Free memory, close handles
// Do NOT reset user settings
void CabLib::Extract::Reset()
{
    if (mi_Extract) 
    {
        mi_Extract->CleanUp(); // Close handles, free memory
        delete mi_Extract;
        mi_Extract = 0;
    }
    mb_Internet = false;
}

// This must be called from another thread!
void CabLib::Extract::AbortOperation()
{
    if (mi_Extract) mi_Extract->AbortOperation();
}

// ATTENTION: Normally you will NOT need this function!!
// If you don't know what is the purpose of this function, don't use it! Read the documentation!
// CAB files created with this library are UTF-8 encoded and do NOT need any Codepage setting!
// !ONLY! if you extract CAB files that have been created with any strange codepage other than ANSI or UTF-8, 
// define the codepage here, otherwise you will get corrupted filenames!!
void CabLib::Extract::SetCodepage(UInt32 u32_Codepage)
{
    mu32_Codepage = u32_Codepage;
}

// Creates a SHA512 hash from the given Unicode string 
// and uses this 64 Byte hash as key for the Blowfish algorithm which encrypts CAB data.
// This makes encryption more secure: See http://en.wikipedia.org/wiki/Key_derivation_function
void CabLib::Extract::SetDecryptionKey(String^ s_Password)
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

// The key passed to this function will be passed directly to the Blowfish decryption
// If the key is longer  than 72 Byte, the remaining bytes will be ignored.
// If the key is shorter than 72 Byte, its bytes will be reused multiple times.
// You should use this function only for setting binary keys.
// For plain text passwords use SetDecryptionKey(String^)
void CabLib::Extract::SetDecryptionKey(array<Byte>^ u8_Key)
{ 
    mu8_Key = u8_Key;
}

// Extract only one single file from the archive.
// This file MUST be located in the root folder of the CAB archive !!!
// For splitted CAB files the file MUST be in the FIRST archive!
// After setting a single file the event evBeforeCopyFile will NOT be fired !!!
// You must set the single file before calling
// ExtractFile() or ExtractResource() or ExtractStream()
// The single file will only be valid for ONE extraction process !!!
void CabLib::Extract::SetSingleFile(String^ s_File)
{
    ms_SingleFile = s_File;
}

// Set the interval in ms after which the Progress Callback is called
// If the file extracts faster than this interval only 0.0% and 100.0% are reported
// If the interval is set to zero EVERY write process calls the callback
void CabLib::Extract::SetProgressInterval(int s32_CallbackInterval)
{
    ms32_ProgressInterval = s32_CallbackInterval;
}

// ##################################### FILE ####################################################

// This static function checks if the given file ends with ".URL" or ".LNK"
// If so it resolves the shortcut and returns the target in the corresponding OUT string.
// Otherwise it returns false.
bool CabLib::Extract::ResolveShortcut(String^ s_File, [Out]String^% s_Url, [Out]String^% s_Lnk)
{
    s_Url = nullptr;
    s_Lnk = nullptr;
    WCHAR  u16_Target[8000];
    WCHAR* u16_File = (WCHAR*)Marshal::StringToHGlobalUni(s_File).ToPointer();
    bool b_Ret = false;

    if (s_File->ToLower()->EndsWith(".url"))
    {
        if (0 != Cabinet::CFile::ResolveUrlShortcutW(u16_File, u16_Target, sizeof(u16_Target)/2))
            throw gcnew Exception(String::Concat("Could not resolve shortcut: ", s_File));

        s_Url = gcnew String(u16_Target);
        b_Ret = true;
    }

    if (s_File->ToLower()->EndsWith(".lnk"))
    {
        if (0 != Cabinet::CFile::ResolveLnkShortcutW(u16_File, u16_Target, sizeof(u16_Target)/2))
            throw gcnew Exception(String::Concat("Could not resolve shortcut: ", s_File));

        s_Lnk = gcnew String(u16_Target);
        b_Ret = true;
    }

    Marshal::FreeHGlobal((IntPtr)u16_File);
    return b_Ret;
}

// Extracts the content of a CAB file s_CabFile into the given folder s_Folder
// The subfolder structure in the CAB file will be maintained on disk
// Also file attributes and dates of the files are maintained
// Throws an exception on error
void CabLib::Extract::ExtractFile(String^ s_CabFile, String^ s_Folder)
{
    if (mi_Extract) throw gcnew Exception(gcnew String("You cannot call the extraction functions from two different threads. Please create a new instance for each thread! After URL extraction you MUST call CleanUp()"));

    String^ s_Url = nullptr;
    String^ s_Lnk = nullptr;
    if (ResolveShortcut(s_CabFile, s_Url, s_Lnk))
    {
        if (s_Url != nullptr) // Redirect URL shortcuts to ExtractUrl()
        {
            // extract the URL after downloading it to a temp file
            ExtractUrl(s_Url, 0, L"", s_Folder);
            return;
        }
        if (s_Lnk != nullptr) // use LNK target
        {
            s_CabFile = s_Lnk;
        }
    }

    Reset();
    Exception^ i_Ex = nullptr;

    WCHAR* u16_CabFile = (WCHAR*)Marshal::StringToHGlobalUni(s_CabFile).ToPointer();
    WCHAR* u16_Folder  = (WCHAR*)Marshal::StringToHGlobalUni(s_Folder) .ToPointer();

    Cabinet::CExtract* pi_Extract = new Cabinet::CExtract();
    mi_Extract = pi_Extract;

    cExtractBridge i_Bridge(this, ms_SingleFile, 0, ms32_ProgressInterval);

    pi_Extract->SetCallbacks(i_Bridge.GetCallbacks());

    BYTE  u8_Key[72];
    UINT u32_Len = min(72, mu8_Key->Length);
    for (UINT i=0; i<u32_Len; i++)
    {
        u8_Key[i] = mu8_Key[i]; // copy managed --> unmanged
    }
    pi_Extract->SetDecryptionKey(u8_Key, u32_Len);
    pi_Extract->SetCodepage(mu32_Codepage);

    if (!pi_Extract->CreateFDIContext()) 
    {
        i_Ex = gcnew Exception(String::Format("CabLib Extract ERROR: Could not create FDI context: {0}", 
                               gcnew String(pi_Extract->LastErrorW())));
        goto _Exit;
    }

    // The i_Bridge instance must be passed to the static callbacks to access its members
    if (!pi_Extract->ExtractFileW(u16_CabFile, u16_Folder, &i_Bridge))
    {
        i_Ex = gcnew Exception(String::Format("CabLib Extract ERROR while extracting files from cabinet archive: {0}", 
                               gcnew String(pi_Extract->LastErrorW())));
        goto _Exit;
    }

    _Exit:
    Marshal::FreeHGlobal((IntPtr)u16_CabFile);
    Marshal::FreeHGlobal((IntPtr)u16_Folder);

    CleanUp();
    if (i_Ex) throw i_Ex;
}

// returns true if the file is a valid CABINET file
// returns additional information which is read from the header of the CAB file
bool CabLib::Extract::IsFileCabinet(String^ s_CabFile, [Out]kHeaderInfo^% pk_HeaderInfo)
{
    pk_HeaderInfo = gcnew kHeaderInfo();

    Exception^ i_Ex = nullptr;

    WCHAR* u16_CabFile = (WCHAR*)Marshal::StringToHGlobalUni(s_CabFile).ToPointer();

    BOOL              b_Ret = FALSE;
    FDICABINETINFO    k_Info;
    Cabinet::CExtract i_Extract;

    BYTE  u8_Key[72];
    UINT u32_Len = min(72, mu8_Key->Length);
    for (UINT i=0; i<u32_Len; i++)
    {
        u8_Key[i] = mu8_Key[i]; // copy managed --> unmanged
    }
    i_Extract.SetDecryptionKey(u8_Key, u32_Len);
    i_Extract.SetCodepage(mu32_Codepage);

    if (!i_Extract.CreateFDIContext()) 
    {
        i_Ex = gcnew Exception(String::Format("CabLib Extract ERROR: Could not create FDI context: {0}", 
                               gcnew String(i_Extract.LastErrorW())));
    }
    else
    {
        b_Ret = i_Extract.IsCabinetW(u16_CabFile, &k_Info);
    }
    
    if (!b_Ret) memset(&k_Info, 0, sizeof(FDICABINETINFO));
    
    (pk_HeaderInfo)->u32_FileSize  = k_Info.cbCabinet;
    (pk_HeaderInfo)->u16_Folders   = k_Info.cFolders;
    (pk_HeaderInfo)->u16_Files     = k_Info.cFiles;
    (pk_HeaderInfo)->u16_SetID     = k_Info.setID;
    (pk_HeaderInfo)->u16_CabIndex  = k_Info.iCabinet;
    (pk_HeaderInfo)->b_HasReserve  =(k_Info.fReserve != FALSE);
    (pk_HeaderInfo)->b_HasPrevious =(k_Info.hasprev  != FALSE);
    (pk_HeaderInfo)->b_HasNext     =(k_Info.hasnext  != FALSE); // ATTENTION: returns 2 or 0 !!
    
    i_Extract.CleanUp();
    Marshal::FreeHGlobal((IntPtr)u16_CabFile);

    if (i_Ex) throw i_Ex;

    return (b_Ret != FALSE);
}

// ################################### RESOURCE ##################################################

// Extracts the content of a CAB file which is stored in the file s_Module (DLL or EXE)
// into the given folder s_Folder.
// If s_Module == null --> The Cab resource is expected in the file which created the process
// Otherwise s_Module must be the filename (without path) of the DLL which contains the CAB resource
// The subfolder structure in the CAB file will be maintained on disk
// Also file attributes and dates of the files are maintained
// Throws an exception on error
// To test this function with the file Test.cab included in this project
// set s_Module = "CabLib.dll" and o_RscName = ID_CAB_TEST and o_RscType = "CABFILE"
// because the file CabLib.rc contains:
// ID_CAB_TEST        CABFILE         "Res\\Test.cab"
void CabLib::Extract::ExtractResource(String^ s_Module,  // filename of DLL or null 
                                      Object^ o_RscName, // Name of resource (String or integer)
                                      Object^ o_RscType, // Type of resource (String or integer)
                                      String^ s_Folder)  // Where to extract the CAB to
{
    if (mi_Extract) throw gcnew Exception(gcnew String("You cannot call the extraction functions from two different threads. Please create a new instance for each thread! After URL extraction you MUST call CleanUp()"));

    Reset();
    Exception^ i_Ex = nullptr;

    WCHAR* u16_Module = NULL;
    WCHAR  u16_RscName[1000] = L"";
    WCHAR  u16_RscType[1000] = L"";

    if (s_Module) u16_Module  = (WCHAR*)Marshal::StringToHGlobalUni(s_Module).ToPointer();
    WCHAR*        u16_Folder  = (WCHAR*)Marshal::StringToHGlobalUni(s_Folder).ToPointer();
    WCHAR*        u16_ObjName = (WCHAR*)Marshal::StringToHGlobalUni(o_RscName->ToString()).ToPointer();
    WCHAR*        u16_ObjType = (WCHAR*)Marshal::StringToHGlobalUni(o_RscType->ToString()).ToPointer();

         if (o_RscName->GetType() == Int32::typeid)  swprintf(u16_RscName, L"#%s", u16_ObjName);
    else if (o_RscName->GetType() == String::typeid) wcscpy  (u16_RscName, u16_ObjName);

         if (o_RscType->GetType() == Int32::typeid)  swprintf(u16_RscType, L"#%s", u16_ObjType);
    else if (o_RscType->GetType() == String::typeid) wcscpy  (u16_RscType, u16_ObjType);

    Cabinet::CExtractResource* pi_Extract = new Cabinet::CExtractResource();
    mi_Extract = pi_Extract;

    cExtractBridge i_Bridge(this, ms_SingleFile, 0, ms32_ProgressInterval);

    pi_Extract->SetCallbacks(i_Bridge.GetCallbacks());

    BYTE  u8_Key[72];
    UINT u32_Len = min(72, mu8_Key->Length);
    for (UINT i=0; i<u32_Len; i++)
    {
        u8_Key[i] = mu8_Key[i]; // copy managed --> unmanged
    }
    pi_Extract->SetDecryptionKey(u8_Key, u32_Len);
    pi_Extract->SetCodepage(mu32_Codepage);

    if (!pi_Extract->CreateFDIContext()) 
    {
        i_Ex = gcnew Exception(String::Format("CabLib Extract ERROR: Could not create FDI context: {0}", 
                               gcnew String(pi_Extract->LastErrorW())));
        goto _Exit;
    }

    // The i_Bridge instance must be passed to the static callbacks to access its members
    if (!pi_Extract->ExtractResourceW(u16_Module, u16_RscName, u16_RscType, u16_Folder, &i_Bridge))
    {
        i_Ex = gcnew Exception(String::Format("CabLib Extract ERROR while extracting files from cabinet resource: {0}",
                               gcnew String(pi_Extract->LastErrorW())));
        goto _Exit;
    }

    _Exit:
    if (s_Module) Marshal::FreeHGlobal((IntPtr)u16_Module);
    Marshal::FreeHGlobal((IntPtr)u16_Folder);
    Marshal::FreeHGlobal((IntPtr)u16_ObjType);
    Marshal::FreeHGlobal((IntPtr)u16_ObjName);

    CleanUp();
    if (i_Ex) throw i_Ex;
}

// ##################################### STREAM ##################################################

// Extracts the content of a stream, which contains a CAB file, into the given folder s_Folder
// The subfolder structure in the CAB file will be maintained on disk
// Also file attributes and dates of the files are maintained
// Throws an exception on error
void CabLib::Extract::ExtractStream(Stream^ i_Stream, String^ s_Folder)
{
    if (mi_Extract) throw gcnew Exception(gcnew String(L"You cannot call the extraction functions from two different threads. Please create a new instance for each thread! After URL extraction you MUST call CleanUp()"));

    if (!i_Stream->CanSeek || !i_Stream->CanRead)
        throw gcnew Exception(L"The stream specified for CAB extraction is invalid! The stream must be capable of reading and seeking.");

    Reset();
    Exception^ i_Ex = nullptr;

    WCHAR* u16_Folder = (WCHAR*)Marshal::StringToHGlobalUni( s_Folder). ToPointer();

    Cabinet::CExtractStream* pi_Extract = new Cabinet::CExtractStream();
    mi_Extract = pi_Extract;

    cExtractBridge i_Bridge(this, ms_SingleFile, i_Stream, ms32_ProgressInterval);

    pi_Extract->SetCallbacks(i_Bridge.GetCallbacks());

    BYTE  u8_Key[72];
    UINT u32_Len = min(72, mu8_Key->Length);
    for (UINT i=0; i<u32_Len; i++)
    {
        u8_Key[i] = mu8_Key[i]; // copy managed --> unmanged
    }
    pi_Extract->SetDecryptionKey(u8_Key, u32_Len);
    pi_Extract->SetCodepage(mu32_Codepage);

    if (!pi_Extract->CreateFDIContext()) 
    {
        i_Ex = gcnew Exception(String::Format("CabLib Extract ERROR: Could not create FDI context: {0}", 
                               gcnew String(pi_Extract->LastErrorW())));
        goto _Exit;
    }

    // The i_Bridge instance must be passed to the static callbacks to access its members
    if (!pi_Extract->ExtractStreamW(u16_Folder, &i_Bridge))
    {
        i_Ex = gcnew Exception(String::Format("CabLib Extract ERROR while extracting files from cabinet stream: {0}",
                               gcnew String(pi_Extract->LastErrorW())));
        goto _Exit;
    }

    _Exit:
    Marshal::FreeHGlobal((IntPtr)u16_Folder);

    i_Stream->Close();
    CleanUp();

    if (i_Ex) throw i_Ex;
}

// ##################################### INTERNET ################################################

// Sets FTP transfer to passive / active mode
void CabLib::Extract::SetPassiveFtpMode(bool b_Passive)
{
    mb_Passive = b_Passive;
}

// Proxy Types: CERN, TIS or SOCKS
// String Format= "http=http://Proxy1.com:8000 https=https://Proxy2.com:443"
// Possible Proxies for HTTP, HTTPS, FTP
// s_ProxyString = "" --> Use Internet Explorer default settings
void CabLib::Extract::SetProxy(String^ s_ProxyString)
{
    if (s_ProxyString->Length > 0 && s_ProxyString->IndexOf("=") < 0)
        throw gcnew Exception("Read the documentation before using this library!");

    ms_Proxy = s_ProxyString;
}

// Modifies the HTTP headers which are sent to the server. (separated by pipe)
// e.g. "Referer: http://www.test.com|Accept-Language:en"  (no space before or after pipe!!)
// If the value of a header is empty, the header is removed.
void CabLib::Extract::SetHttpHeaders(String^ s_Headers)
{
    if (s_Headers->IndexOf("| ") >= 0 || s_Headers->IndexOf(" |") >= 0 ||
        s_Headers->IndexOf("\r") >= 0 || s_Headers->IndexOf("\n") >= 0)
        throw gcnew Exception("Read the documentation before using this library!");

    ms_Headers = s_Headers;
}

// This must be called from another thread while a download is in progress.
// If this is called during a block download to memory,
// it will return only the progress of the current block
// Really usefull only for downloads of entire files
// Not all HTTP Servers return "CONTENT-LENGTH" (e.g. AOL servers) --> Total = 0
void CabLib::Extract::InternetGetProgress([Out] Int32^% s32_Total, [Out] Int32^% s32_Read)
{
    *s32_Read  = 0;
    *s32_Total = 0;

    if (!mb_Internet || !mi_Extract)
        return;

    Cabinet::CExtractUrl* i_ExtUrl = (Cabinet::CExtractUrl*) mi_Extract;

    ULONGLONG s64_Total, s64_Read;
    i_ExtUrl->GetProgress(&s64_Total, &s64_Read);

    // CAB files can never be bigger than 2 Gigabyte, so we don't need 64 bit here
    *s32_Read  = (int)min(s64_Read, s64_Total);
    *s32_Total = (int)s64_Total;
}

// ---------------------------------------------------------------------------------------------
//           !! READ THE DOCUMENTATION FOR MORE DETAILS ABOUT THIS FUNCTION !!
// ---------------------------------------------------------------------------------------------

void CabLib::Extract::ExtractUrl(String^ s_Url, Int32 s32_BlockSize, String^ s_LocalPath, String^ s_Folder)
{
    if (mi_Extract) throw gcnew Exception(gcnew String("You cannot call the extraction functions from two different threads. Please create a new instance for each thread! After URL extraction you MUST call CleanUp()"));

    // Redirect "file://" URLs to ExtractFile()
    if (s_Url->ToLower()->StartsWith("file:"))
    {
        String^ s_File = s_Url->Substring(5);
        while  (s_File->StartsWith("/"))
        {
            // The URL may be "file://.." or "file:///.."
            s_File = s_File->Substring(1);
        }
        ExtractFile(s_File->Replace("/", "\\"), s_Folder);
        return;
    }

    Reset();
    mb_Internet = true;
    Exception^ i_Ex = nullptr;

    WCHAR* u16_Url     = (WCHAR*)Marshal::StringToHGlobalUni(s_Url).ToPointer();
    WCHAR* u16_Local   = (WCHAR*)Marshal::StringToHGlobalUni(s_LocalPath).ToPointer();
    WCHAR* u16_Folder  = (WCHAR*)Marshal::StringToHGlobalUni(s_Folder).ToPointer();
    WCHAR* u16_Proxy   = (WCHAR*)Marshal::StringToHGlobalUni(ms_Proxy).ToPointer();
    WCHAR* u16_Headers = (WCHAR*)Marshal::StringToHGlobalUni(ms_Headers).ToPointer();

    Cabinet::CExtractUrl* pi_Extract = new Cabinet::CExtractUrl();
    mi_Extract = pi_Extract;

    cExtractBridge i_Bridge(this, ms_SingleFile, 0, ms32_ProgressInterval);

    pi_Extract->SetCallbacks     (i_Bridge.GetCallbacks());
    pi_Extract->SetPassiveFtpMode(mb_Passive != false);
    pi_Extract->SetProxyW        (u16_Proxy);
    pi_Extract->SetHttpHeadersW  (u16_Headers);

    BYTE  u8_Key[72];
    UINT u32_Len = min(72, mu8_Key->Length);
    for (UINT i=0; i<u32_Len; i++)
    {
        u8_Key[i] = mu8_Key[i]; // copy managed --> unmanged
    }
    pi_Extract->SetDecryptionKey(u8_Key, u32_Len);
    pi_Extract->SetCodepage(mu32_Codepage);

    if (!pi_Extract->CreateFDIContext()) 
    {
        i_Ex = gcnew Exception(String::Format("CabLib Extract ERROR: Could not create FDI context: {0}", 
                               gcnew String(pi_Extract->LastErrorW())));
        goto _Exit;
    }

    // The i_Bridge instance must be passed to the static callbacks to access its members
    if (!pi_Extract->ExtractUrlW(u16_Url, s32_BlockSize, u16_Local, u16_Folder, &i_Bridge))
    {
        i_Ex = gcnew Exception(String::Format("CabLib Extract ERROR while extracting files from URL: {0}",
                               gcnew String(pi_Extract->LastErrorW())));
        goto _Exit;
    }

    _Exit:
    Marshal::FreeHGlobal((IntPtr)u16_Url);
    Marshal::FreeHGlobal((IntPtr)u16_Local);
    Marshal::FreeHGlobal((IntPtr)u16_Folder);
    Marshal::FreeHGlobal((IntPtr)u16_Proxy);
    Marshal::FreeHGlobal((IntPtr)u16_Headers);

    // No CleanUp() here! (Maybe there are more files to be extracted later from the same CAB file)
    ms_SingleFile = "";
    pi_Extract->DestroyFDIContext(); 
    if (i_Ex) throw i_Ex;
}

 void CabLib::Extract::ExtractMoreUrl(String^ s_Folder)
 {
    if (!mb_Internet || !mi_Extract) throw gcnew Exception("Read the documentation before using this library!");

    // No Reset() here !!
    Exception^ i_Ex = nullptr;
    WCHAR* u16_Folder = (WCHAR*)Marshal::StringToHGlobalUni(s_Folder).ToPointer();

    cExtractBridge i_Bridge(this, ms_SingleFile, 0, ms32_ProgressInterval);

    Cabinet::CExtractUrl* pi_Extract = (Cabinet::CExtractUrl*)mi_Extract;

    pi_Extract->SetCallbacks(i_Bridge.GetCallbacks());

    if (!pi_Extract->CreateFDIContext()) 
    {
        i_Ex = gcnew Exception(String::Format("CabLib Extract ERROR: Could not create FDI context: {0}", 
                               gcnew String(pi_Extract->LastErrorW())));
        goto _Exit;
    }

    // The i_Bridge instance must be passed to the static callbacks to access the member variables
    if (!pi_Extract->ExtractMoreUrlW(u16_Folder, &i_Bridge))
    {
        i_Ex = gcnew Exception(String::Format("CabLib Extract ERROR while extracting more files from URL: {0}",
                               gcnew String(pi_Extract->LastErrorW())));
        goto _Exit;
    }

    _Exit:
    Marshal::FreeHGlobal((IntPtr)u16_Folder);

    // No CleanUp() here! (Maybe there are more files to be extracted later from the same CAB file)
    ms_SingleFile = "";
    pi_Extract->DestroyFDIContext();

    if (i_Ex) throw i_Ex;
 }

// ###############################################################################################
// ###############################################################################################
//                                  EXTRACT EVENT HANDLER
// ###############################################################################################
// ###############################################################################################


// This function will be called for each file in a cabinet before it is extracted.
// Return TRUE to extract the file or FALSE to skip the file.
BOOL CabLib::cExtractBridge::OnBeforeCopyFile(Cabinet::CExtract::kCabinetFileInfo *pk_Info, void* p_Param)
{ 
    cExtractBridge* p_Bridge = (cExtractBridge*)p_Param;

    // Extract single file specified by user from the root folder in the CAB file
    if (p_Bridge->ms_SingleFile && p_Bridge->ms_SingleFile->Length)
        return String::Compare(p_Bridge->ms_SingleFile, gcnew String(pk_Info->u16_File), true) == 0;

    Extract::kCabinetFileInfo^ k_Info = gcnew Extract::kCabinetFileInfo();

    k_Info->s_File      = gcnew String(pk_Info->u16_File);
    k_Info->s_SubFolder = gcnew String(pk_Info->u16_SubFolder);
    k_Info->s_RelPath   = gcnew String(pk_Info->u16_RelPath);
    k_Info->s_Path      = gcnew String(pk_Info->u16_Path);
    k_Info->s_FullPath  = gcnew String(pk_Info->u16_FullPath);
    k_Info->s32_Size    = pk_Info->s32_Size;
    k_Info->u16_Attribs = pk_Info->u16_Attribs;

    // Because DateTime::FromFileTime() will add the timezone
    // we must subtract the timezone before to get the correct result
    // DateTime::FromFileTimeUtc() is not available on Visual Studio 7.0
    ::FILETIME k_Local;
    LocalFileTimeToFileTime(&pk_Info->k_Time, &k_Local);
    k_Info->k_Time = DateTime::FromFileTime(_FileTimeTo64(k_Local));

    return (p_Bridge->mi_Instance->FireBeforeCopyFile(k_Info) != false); // bool -> BOOL
}

// This function will be called when a file has been succesfully extracted.
// If ExtractToMemory is enabled, no file is written to disk,
// instead the entire content of the file is passed in u8_ExtractMem
// If ExtractToMemory is not enabled, u8_ExtractMem is null
void CabLib::cExtractBridge::OnAfterCopyFile(WCHAR* u16_File, Cabinet::CMemory* pi_ExtractMem, void* p_Param)
{ 
    cExtractBridge* p_Bridge = (cExtractBridge*)p_Param;

    array<Byte>^ u8_ExtractMem = nullptr;
    if (pi_ExtractMem)
    {
        int  s32_Len  = 0;
        IntPtr p_Data = (IntPtr)pi_ExtractMem->GetData(&s32_Len);

        u8_ExtractMem = gcnew array<Byte>(s32_Len);
        Marshal::Copy(p_Data, u8_ExtractMem, 0, s32_Len);
    }
        
    p_Bridge->mi_Instance->FireAfterCopyFile(gcnew String(u16_File), u8_ExtractMem);
}

void CabLib::cExtractBridge::OnProgressInfo(Cabinet::CExtract::kProgressInfo* pk_Info, void* p_Param)
{ 
    cExtractBridge* p_Bridge = (cExtractBridge*)p_Param;

    // copy to managed structure
    Extract::kProgressInfo^ k_Info = gcnew Extract::kProgressInfo();

    k_Info->s_RelPath   = gcnew String(pk_Info->u16_RelPath);
    k_Info->s_FullPath  = gcnew String(pk_Info->u16_FullPath);
    k_Info->u32_TotSize = pk_Info->u32_TotSize;
    k_Info->u32_Written = pk_Info->u32_Written;
    k_Info->fl_Percent  = pk_Info->fl_Percent;

    p_Bridge->mi_Instance->FireProgressInfo(k_Info);
}

// This function will be called exactly once for each cabinet opened by Copy, 
// including continuation cabinets opened due to files which are spanning over cabinet boundaries. 
void CabLib::cExtractBridge::OnCabinetInfo(Cabinet::CExtract::kCabinetInfo* pk_Info, void* p_Param)
{
    cExtractBridge* p_Bridge = (cExtractBridge*)p_Param;

    // copy to managed structure
    Extract::kCabinetInfo^ k_Info = gcnew Extract::kCabinetInfo();

    k_Info->s_NextCabinet = gcnew String(pk_Info->s8_NextCabinet);
    k_Info->s_NextDisk    = gcnew String(pk_Info->s8_NextDisk);
    k_Info->s_Path        = gcnew String(pk_Info->u16_Path);
    k_Info->u16_SetID     = pk_Info->u16_SetID;
    k_Info->u16_Cabinet   = pk_Info->u16_Cabinet;

    p_Bridge->mi_Instance->FireCabinetInfo(k_Info);
}

// This function will be called when the next cabinet file in the sequence needs to be opened. 
// The path has to be verified and can be changed if necessary. 
// If the cabinet file cannot be opened this function will be called again 
// with the second parameter set to an error that describes the problem.
void CabLib::cExtractBridge::OnNextCabinet(Cabinet::CExtract::kCabinetInfo *pk_Info, int s32_FdiError, void* p_Param)
{ 
    cExtractBridge* p_Bridge = (cExtractBridge*)p_Param;

    // copy to managed structure
    Extract::kCabinetInfo^ k_Info = gcnew Extract::kCabinetInfo();

    k_Info->s_NextCabinet = gcnew String(pk_Info->s8_NextCabinet);
    k_Info->s_NextDisk    = gcnew String(pk_Info->s8_NextDisk);
    k_Info->s_Path        = gcnew String(pk_Info->u16_Path);
    k_Info->u16_SetID     = pk_Info->u16_SetID;
    k_Info->u16_Cabinet   = pk_Info->u16_Cabinet;

    p_Bridge->mi_Instance->FireNextCabinet(k_Info, s32_FdiError);
}

// ###############################################################################################
// ###############################################################################################
//                                  STREAM ACCESS FUNCTIONS
// ###############################################################################################
// ###############################################################################################


int CabLib::cExtractBridge::OnStreamGetLen(void* p_Param)
{
    cExtractBridge* p_Bridge = (cExtractBridge*)p_Param;
    return (int)p_Bridge->mi_Stream->Length; 
}

int CabLib::cExtractBridge::OnStreamRead(void* p_Buffer, int Pos, UINT u32_Count, void* p_Param)
{
    cExtractBridge* p_Bridge = (cExtractBridge*)p_Param;
    p_Bridge->mi_Stream->Position = Pos;

    array<Byte>^ u8_ReadBuf = gcnew array<Byte>(u32_Count);
    int s32_Read = p_Bridge->mi_Stream->Read(u8_ReadBuf, 0, u32_Count);

    Marshal::Copy(u8_ReadBuf, 0, (IntPtr)p_Buffer, s32_Read);
    return s32_Read;
}


} // Namespace CabLib