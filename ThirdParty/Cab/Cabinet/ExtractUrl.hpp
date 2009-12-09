///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (www.netcult.ch/elmue)
// Date: 16-03-2008
//
// Filename: ExtractUrl.hpp
//
// - CExtractUrl
//
// Purpose: This class extracts files from cabinet file located on a HTTP server
// that must run a little PHP script which allows partial download of the CAB file.
// You can also specify a FTP server which permits to resume broken downloads. 
// You can put a 100 Megabyte CAB file (encrypted) on a HTTP / FTP server and with this library you can extract
// only 1 little file from the huge archive without downloading the whole CAB file !!!
// The internet access runs through a little cache in memory which optimizes the performance.
// The internet transfer is compressed and optionally encrypted (if the CAB file is encrypted)
// Further details see folder Doku in the ZIP file of this sourcecode.
//

#pragma once

#include "ExtractMemory.hpp"
#include "Cache.hpp"
#include "Internet.hpp"

#pragma warning(disable: 4996)

namespace Cabinet
{

class CExtractUrl : public CExtractMemory
{
protected:

	DWORD     mu32_BlockSize;  // The size of the blocks which are loaded from the server
	DWORD     mu32_Cache;      // Counter for the handles that have been opened in OpenMem()
	CCache    mi_Cache[2];     // Cache for the sequentially read CAB data for the 2 Cabinet.Dll file handles
	CMemBlock mi_FirstBlock;   // The very first block of memory which is read multiple times by Cabinet.dll
	CInternet mi_Internet;     // Uses Wininet.dll to load data from a FTP or HTTP(S) server

public:
	CExtractUrl()
	{
		#if _TraceExtract
			CTrace::TraceW(L"Constructor CExtractUrl()");
		#endif
	}
	~CExtractUrl()
	{
		#if _TraceExtract
			CTrace::TraceW(L"Destructor ~CExtractUrl()");
		#endif
	}

	// CleanUp() must only be called if this class is not destroyed with its destructor
	// It must be called to close the connection to the server and close the download file which is still open
	// This is NOT done automatically to allow re-using this class (e.g. multiple extraction of single files)
	BOOL CleanUp()
	{
		mi_Internet.CleanUp();       // close handles
		mi_FirstBlock.Init(0,0,0,0); // free memory
		mi_Cache[0].Init  (0,0,0);
		mi_Cache[1].Init  (0,0,0);
		
		// Clean up base class
		return CExtract::CleanUp();
	}

	// -----------------------------------------------------------------------------------------
	// There are the following possible formats for the URL:
	// http://www.server.com/folder/Downloads/Setup_1.35.cab
	// or
	// https://www.server.com:8000/folder/Downloads/Setup_1.35.cab
	// or
	// ftp://ftp.server.com/folder/Setup_1.35.cab
	// or
	// ftp://user:password@ftp.server.com:1022/folder/Setup_1.35.cab
	//
	// The smaller the blocksize, the slower the download (see Trace)
	// The bigger  the blocksize, the slower extraction of only specific files from a huge cabinet
	// Test results with a connection to the other end of the world on a DSL 2000:
	// Blocksize  50 kB:  40 kB/s
	// Blocksize 200 kB:  95 kB/s
	// Blocksize 500 kB: 150 kB/s
	// Blocksize   1 MB: 190 kB/s
	// Blocksize   5 MB: 245 kB/s (maximum DSL speed)
	//
	// Blocksize = 0:
	// This results in downloading the entire file in one block to disk and then extracting it.
	// (Highest speed download, but slow if only extracting a few files from the CAB)
	// ------------------------------------------------------------------------------------------

	// Extract the CAB file at the given URL into the given target directory
	// If u16_LocalFile = ""  -> a temporary file will be created
	// A Cabfile will be written to disk ONLY if u32_Blocksize = 0 !!
	// u16_TargetDir = L"" AND Blocksize = 0 --> only download any file from internet to disk
	BOOL ExtractUrlW(const CStrW& sw_URL, DWORD u32_Blocksize, const CStrW& sw_LocalFile, const CStrW& sw_TargetDir, void* pParam = NULL)
	{
		if (!Initialize(sw_URL, sw_LocalFile, u32_Blocksize))
			return FALSE;

		// Just a download without CAB extraction
		if (!u32_Blocksize && sw_LocalFile.Len() && !sw_TargetDir.Len())
		{
			// The caller may want to access the file immediately -> close all
			mi_Internet.CleanUp();
			return TRUE;
		}

		// Pass it on to the base class
		return ExtractFileW(L"*CABINET\\*URL", sw_TargetDir, pParam);
	}

	// Extract additional files from the CAB file which has been used in a previous call to ExtractUrlW()
	BOOL ExtractMoreUrlW(const CStrW& sw_TargetDir, void* pParam = NULL)
	{
		mu32_Cache = 0;
		// re-open the same connection, re-using the cache's contents or the already downloaded file
		BOOL  b_Offline;
		DWORD u32_ApiErr = mi_Internet.ConnectServer(&b_Offline);
		if (u32_ApiErr)
		{
			if (b_Offline) mi_Error.Set(FDIERROR_MSIE_OFFLINE, u32_ApiErr, 0);
			else           mi_Error.Set(FDIERROR_INTERNET,     u32_ApiErr, 0);
			return FALSE;
		}
		return ExtractFileW(L"*CABINET\\*URL", sw_TargetDir, pParam);
	}

	// Check if the file at the given URL is a valid CAB file
	// If u16_LocalFile = ""  -> a temporary file will be created
	// A Cabfile will be written to disk ONLY if u32_Blocksize = 0 !!
	BOOL IsUrlCabinetW(const CStrW& sw_URL, DWORD u32_Blocksize, const CStrW& sw_LocalFile, PFDICABINETINFO pfdici = NULL)
	{
		if (!Initialize(sw_URL, sw_LocalFile, u32_Blocksize))
			return FALSE;

		// Pass it on to the base class
		return IsCabinetW(L"*CABINET\\*URL", pfdici);
	}

	// Set a proxy or multiple proxies:
	// String Format= "http=http://Proxy1.com:8000 https=https://Proxy2.com:443"
	// You can specify separate proxies for HTTP, HTTPS, FTP
	// u16_Proxy = "" --> Use Internet Explorer default settings
	void SetProxyW(const CStrW& sw_Proxy)
	{
		mi_Internet.SetProxy(sw_Proxy);
	}

	// Modifies the HTTP headers which are sent to the server. (separated by pipe)
	// e.g. "Referer: http://www.test.com|Accept-Language:en"  (no space before or after pipe!!)
	// If the value of a header is empty, the header is removed.
	void SetHttpHeadersW(const CStrW& sw_Headers)
	{
		mi_Internet.HttpSetHeaders(sw_Headers);
	}

	// Set FTP mode passive / active
	void SetPassiveFtpMode(BOOL b_Passive)
	{
		mi_Internet.FtpSetPassiveMode(b_Passive);
	}

	// Download only the first u32_MaxDownload Bytes of the file
	// Ignored for partial downloads!
	void SetMaxDownload(DWORD u32_MaxDownload)
	{
		mi_Internet.SetMaxDownload(u32_MaxDownload);
	}

	// This function aborts the currently active operation.
	void AbortOperation()
	{
		CExtract::AbortOperation();
		mi_Internet.AbortOperation();
	}

	// See comment in Internet.hpp !!!
	void GetProgress(ULONGLONG* pu64_Size, ULONGLONG* pu64_Read)
	{
		mi_Internet.GetProgress(pu64_Size, pu64_Read);
	}


protected:

	BOOL Initialize(WCHAR* u16_Url, WCHAR* u16_LocalFile, DWORD u32_Blocksize)
	{
		mu32_BlockSize = u32_Blocksize;
		mu32_Cache     = 0;

		if (!mi_Internet.LoadWininet())
		{
			mi_Error.Set(FDIERROR_LOAD_WININET_DLL,0,0);
			return FALSE;
		}

		// Sets Username, Password, Server, UrlPath, Port, ServiceType
		DWORD u32_ApiErr;
		if (u32_ApiErr = mi_Internet.SetUrl(u16_Url))
		{
			mi_Error.Set(FDIERROR_INTERNET, u32_ApiErr,0);
			return FALSE;
		}

		BOOL b_Offline;
		if (u32_ApiErr = mi_Internet.ConnectServer(&b_Offline))
		{
			if (b_Offline) mi_Error.Set(FDIERROR_MSIE_OFFLINE, u32_ApiErr, 0);
			else           mi_Error.Set(FDIERROR_INTERNET,     u32_ApiErr, 0);
			return FALSE;
		}

		if (u32_Blocksize > 0) // Extract via memory blocks
		{
			#if _TraceInternet
				CTrace::TraceW(L"*** Starting URL extraction. Loading blocks of %d Bytes to memory", u32_Blocksize);
			#endif

			// Minimum 50 kB
			// WARNING: Blocks smaller than 250 kB result in a very bad performance (see above)
			mu32_BlockSize = max(mu32_BlockSize, 50000);

			mi_FirstBlock.Init(mu32_BlockSize, CacheCallback, 'F','i'); // Block "Fi"
			mi_Cache[0].  Init(mu32_BlockSize, CacheCallback, '1');     // Block "1A" and "1B"
			mi_Cache[1].  Init(mu32_BlockSize, CacheCallback, '2');     // Block "2A" and "2B"
		}
		else // Extract via a file which is entirely saved to disk, then extracted
		{
			u32_ApiErr = mi_Internet.CreateDownloadFileW(u16_LocalFile);
			if (u32_ApiErr)
			{
				mi_Error.Set(FDIERROR_TARGET_FILE, u32_ApiErr,0);
				return FALSE;
			}

			DWORD u32_Status;
			if (u32_ApiErr = mi_Internet.DownloadEntireFileToDisk(&u32_Status))
			{
				mi_Error.Set(FDIERROR_INTERNET, u32_ApiErr, u32_Status);
				return FALSE;
			}
		}
		return TRUE;
	}

	// return a memory pointer
	kMemory* OpenMem(const WCHAR* u16_File, int oflag, int pmode)
	{
		// The correct value for s32_Size (size of the CAB file) does not matter.
		// !IF! Cabinet.dll !SHOULD! try to read behind the end of the file, the server will return only the existing data
		// Do NOT use CInternet.u64_ProgressSize here, as this is not reliable!
		kMemory* pk_Mem  = new kMemory();
		if (!pk_Mem) throw "Fatal error: Out of memory!"; // Required for older Visual Studio versions

		pk_Mem->s32_Pos  = 0;
		pk_Mem->s32_Size = 0x7FFFFFFF;
		pk_Mem->p_Addr   = (void*)(INT_PTR)mu32_Cache++;

		return pk_Mem;
	}

	int ReadMem(kMemory* pk_Mem, void* buffer, UINT count)
	{
		if (mu32_BlockSize > 0) // read from the blocks in memory (Cache)
		{
			// Cabinet.dll opens two handles to the CAB file
			// The data in the first block of the CAB file is read multiple times by BOTH handles
			if (pk_Mem->s32_Pos + count < mu32_BlockSize)
				return mi_FirstBlock.ReadData(buffer, pk_Mem->s32_Pos, count);

			// One CAB file handle reads the CAB index (filenames)
			// The other handle reads the compressed data
			// To avoid unneccessary downloads each CAB file handle has its own cache
			DWORD u32_Cache = (DWORD)(INT_PTR) pk_Mem->p_Addr;
			return mi_Cache[u32_Cache].ReadData(buffer, pk_Mem->s32_Pos, count);
		}
		else // read from the downloaded file on disk
		{
			SetFilePointer(mi_Internet.GetDownloadFile(), pk_Mem->s32_Pos, 0, FILE_BEGIN);

			DWORD u32_Read;
			if (!ReadFile(mi_Internet.GetDownloadFile(), buffer, count, &u32_Read, 0))
			{
				mi_Error.Set(FDIERROR_READ_CABFILE, GetLastError(),0);
				return -1;
			}
			return u32_Read;
		}
	}

	// This function is called from the cache to read the next data block from the server into memory
	static int CacheCallback(void* p_Buffer, DWORD u32_Offset, DWORD u32_Count)
	{
		CExtractUrl* p_This = (CExtractUrl*)This();
		
		DWORD u32_Read, u32_ApiErr, u32_Status;
		if (u32_ApiErr = p_This->mi_Internet.DownloadFilePartToMemory(p_Buffer, 
			             u32_Offset, u32_Count, &u32_Read, &u32_Status))
		{
			p_This->mi_Error.Set(FDIERROR_INTERNET, u32_ApiErr, u32_Status);
			return -1; // Error
		}
		return u32_Read;
	}

	int CloseMem(kMemory* pk_Mem)
	{
		// The download file must be kept open! (Maybe the user wants to extract more files later)
		mi_Internet.CloseInternet();
		delete pk_Mem;
		return 0;
	}

	// Declare this class as a friend so it can access the protected members.
	friend class CExtractMemory;
};

} // Namespace Cabinet

