///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Author: Elmü (http://netcult.ch/elmue)
// Date: 17-03-2008
//
// Filename: Internet.hpp
//
// Classes:
// - CInternet
//
// Purpose: This class uses WinInet.dll to download files from the internet.
// This class does NOT require MFC.
// All functions return an error code or 0 if no error occurred
//

#pragma once

#include <windows.h>
#include <wininet.h>

#include "Defines.h"
#include "File.hpp"

namespace Cabinet
{

class CInternet
{
protected:
	typedef HINTERNET (WINAPI* tOpenW)           (WCHAR*, DWORD, WCHAR*, WCHAR*, DWORD);
	typedef HINTERNET (WINAPI* tConnectW)        (HINTERNET, WCHAR*, INTERNET_PORT, WCHAR*, WCHAR*, DWORD, DWORD, DWORD*);
	typedef BOOL      (WINAPI* tReadFile)        (HINTERNET, void*, DWORD, DWORD*);
	typedef BOOL      (WINAPI* tCloseHandle)     (HINTERNET);
	typedef BOOL      (WINAPI* tCrackUrlW)       (WCHAR*, DWORD, DWORD, URL_COMPONENTSW*);
	typedef BOOL      (WINAPI* tGetLastResponseW)(DWORD*, WCHAR*, DWORD*);
	typedef BOOL      (WINAPI* tGetConectedState)(DWORD*, DWORD);
	typedef BOOL      (WINAPI* tHttpAddHeadersW) (HINTERNET, WCHAR*, DWORD, DWORD);
	typedef HINTERNET (WINAPI* tHttpOpenRequestW)(HINTERNET, WCHAR*, WCHAR*, WCHAR*, WCHAR*, WCHAR**, DWORD, DWORD*);
	typedef BOOL      (WINAPI* tHttpSendRequestW)(HINTERNET, WCHAR*, DWORD, void*, DWORD);
	typedef BOOL      (WINAPI* tHttpQueryInfoW)  (HINTERNET, DWORD, void*, DWORD*, DWORD*);
	typedef HINTERNET (WINAPI* tFtpOpenFileW)    (HINTERNET, WCHAR*, DWORD, DWORD, DWORD*);
	typedef BOOL      (WINAPI* tFtpCommandW)     (HINTERNET, BOOL, DWORD, LPCWSTR, DWORD*, HINTERNET*);
	typedef DWORD     (WINAPI* tFtpGetFileSize)  (HINTERNET, DWORD*);

	struct kWinInet
	{
		HMODULE           mh_WininetDll;
		tOpenW            mf_OpenW;
		tConnectW         mf_ConnectW;
		tCloseHandle      mf_CloseHandle;
		tReadFile         mf_ReadFile;
		tCrackUrlW        mf_CrackUrlW;
		tGetLastResponseW mf_GetLastResponseW;
		tGetConectedState mf_GetConectedState;
		tHttpAddHeadersW  mf_HttpAddHeadersW;
		tHttpOpenRequestW mf_HttpOpenRequestW;
		tHttpSendRequestW mf_HttpSendRequestW;
		tHttpQueryInfoW   mf_HttpQueryInfoW;
		tFtpOpenFileW     mf_FtpOpenFileW;
		tFtpCommandW      mf_FtpCommandW;
		tFtpGetFileSize   mf_FtpGetFileSize;

		// Constructor
		kWinInet()
		{
			mh_WininetDll = 0;
		}

		BOOL Load()
		{
			if (mh_WininetDll)
				return TRUE;

			mh_WininetDll = LoadLibraryW(L"Wininet.Dll");

			mf_OpenW            = (tOpenW)           GetProcAddress(mh_WininetDll, "InternetOpenW");
			mf_ConnectW         = (tConnectW)        GetProcAddress(mh_WininetDll, "InternetConnectW");
			mf_CloseHandle      = (tCloseHandle)     GetProcAddress(mh_WininetDll, "InternetCloseHandle");
			mf_ReadFile         = (tReadFile)        GetProcAddress(mh_WininetDll, "InternetReadFile");
			mf_CrackUrlW        = (tCrackUrlW)       GetProcAddress(mh_WininetDll, "InternetCrackUrlW");
			mf_GetLastResponseW = (tGetLastResponseW)GetProcAddress(mh_WininetDll, "InternetGetLastResponseInfoW");
			mf_GetConectedState = (tGetConectedState)GetProcAddress(mh_WininetDll, "InternetGetConnectedState");
			mf_HttpAddHeadersW  = (tHttpAddHeadersW) GetProcAddress(mh_WininetDll, "HttpAddRequestHeadersW");
			mf_HttpOpenRequestW = (tHttpOpenRequestW)GetProcAddress(mh_WininetDll, "HttpOpenRequestW");
			mf_HttpSendRequestW = (tHttpSendRequestW)GetProcAddress(mh_WininetDll, "HttpSendRequestW");
			mf_HttpQueryInfoW   = (tHttpQueryInfoW)  GetProcAddress(mh_WininetDll, "HttpQueryInfoW");
			mf_FtpOpenFileW     = (tFtpOpenFileW)    GetProcAddress(mh_WininetDll, "FtpOpenFileW");
			mf_FtpCommandW      = (tFtpCommandW)     GetProcAddress(mh_WininetDll, "FtpCommandW");
			mf_FtpGetFileSize   = (tFtpGetFileSize)  GetProcAddress(mh_WininetDll, "FtpGetFileSize");

			if (!mf_OpenW       || 
				!mf_ConnectW    || 
				!mf_CloseHandle || 
				!mf_ReadFile    || 
				!mf_CrackUrlW   || 
				!mf_GetLastResponseW ||
				!mf_GetConectedState ||	
				!mf_HttpAddHeadersW  ||	
				!mf_HttpOpenRequestW || 
				!mf_HttpSendRequestW ||	
				!mf_HttpQueryInfoW   || 
				!mf_FtpOpenFileW || 
				!mf_FtpCommandW  || 
				!mf_FtpGetFileSize) 
			{
				mh_WininetDll = 0;
				return FALSE;
			}
			return TRUE;
		}
	};

	// This avoids Linker errors
	static kWinInet& WI()
	{
		static kWinInet k_WinInet;
		return k_WinInet;
	}

	// INTERNET_OPEN_TYPE_DIRECT :    direct access to the internet (no Proxy)
	// INTERNET_OPEN_TYPE_PRECONFIG : use InternetExplorer settings (Proxy config in Registry : HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings)
	// INTERNET_OPEN_TYPE_PROXY :     use the proxy specified in mu16_Proxy
	DWORD  mu32_AccessType;
	// Proxy Types: CERN, TIS or SOCKS
	// String Format= "http=http://Proxy1.com:8000 https=https://Proxy2.com:443"
	// Possible Proxies for HTTP, HTTPS, FTP
	CStrW ms_Proxy;

	// Optional additional HTTP headers separated by pipe
	CStrW ms_Headers;

	// Server name or IP address
	WCHAR mu16_Server[INTERNET_MAX_HOST_NAME_LENGTH];
	// "WebFolder1/WebFolder2/File.zip"
	WCHAR mu16_UrlPath[INTERNET_MAX_PATH_LENGTH];
	// Username and Password  (used for FTP and HTTPS) set = NULL if not needed
	WCHAR mu16_Username[INTERNET_MAX_USER_NAME_LENGTH];
	WCHAR mu16_Password[INTERNET_MAX_PASSWORD_LENGTH];

	// Server Port (Defaults HTTP:80, FTP:21, HTTPS:443, SOCKS:1080) 
	WORD  mu16_Port;

	// INTERNET_SERVICE_HTTP or INTERNET_SERVICE_FTP
	DWORD mu32_Service;

	// INTERNET_FLAG_RESYNCHRONIZE, INTERNET_FLAG_NO_CACHE_WRITE, etc... (see MSDN)
	DWORD mu32_ReqFlags;

	// INTERNET_FLAG_PASSIVE for FTP
	DWORD mu32_ConectFlags;

	DWORD mu32_MaxDownload;

	HINTERNET mh_Session;
	HINTERNET mh_Connection;
	HINTERNET mh_InetFile;

	BOOL mb_Abort;

	ULONGLONG u64_ProgressSize;  // The maximum  value for a progressbar (file size)
	ULONGLONG u64_ProgressRead;  // The progress value for a progressbar (Bytes downloaded)

	WCHAR  mu16_TempFile[MAX_PATH]; // The temporary file for download
	HANDLE mh_DownloadFile;         // The file which is beeing downloaded (entire CAB download)

public:

	CInternet()
	{
		// Load defaults
		mb_Abort          = FALSE;
		mu16_Server  [0]  = 0;
		mu16_UrlPath [0]  = 0;
		mu16_Username[0]  = 0;
		mu16_Password[0]  = 0;
		mu16_Port         = 0;
		mu32_Service      = -1;
		mu32_AccessType   = INTERNET_OPEN_TYPE_PRECONFIG;
		mu32_ReqFlags     = INTERNET_FLAG_DONT_CACHE;
		mu32_ConectFlags  = INTERNET_FLAG_PASSIVE;
		mu32_MaxDownload  = 0x7FFFFFFF;
		mu16_TempFile[0]  = 0;
		mh_DownloadFile   = 0;
		u64_ProgressSize  = 0;
		u64_ProgressRead  = 0;
		mh_Session        = 0;
		mh_Connection     = 0;
		mh_InetFile       = 0;
	}

	~CInternet()
	{
		CleanUp();
	}

	// Loads Wininet.dll
	BOOL LoadWininet()
	{
		return WI().Load();
	}

	// Parses the given URL and sets the internal variables of this class
	// Example URL: "ftp://user:password@ftp.company.com:1022/Installer/Setup_1.35.cab"
	// --> mu16_Username = "user"
	// --> mu16_Password = "password"
	// --> mu16_Server   = "ftp.company.com"
	// --> mu16_UrlPath  = "Installer/Setup_1.35.cab"
	// --> mu16_Port     = 1022
	// --> mu32_Service  = INTERNET_SERVICE_FTP
	// If no username and password are specified, FTP uses anonymous login.
	// Must be called before ConnectServer() !
	DWORD SetUrl(WCHAR* u16_Url)
	{
		if (!WI().mh_WininetDll)
			return ERROR_INVALID_HANDLE;

		URL_COMPONENTSW k_Comp;
		memset(&k_Comp, 0,    sizeof(URL_COMPONENTS));
		k_Comp.dwStructSize = sizeof(URL_COMPONENTS);

		k_Comp.lpszHostName = mu16_Server;
		k_Comp.dwHostNameLength = sizeof(mu16_Server)/2;
		
		k_Comp.lpszUrlPath  = mu16_UrlPath;
		k_Comp.dwUrlPathLength  = sizeof(mu16_UrlPath)/2;
		
		k_Comp.lpszUserName = mu16_Username;
		k_Comp.dwUserNameLength = sizeof(mu16_Username)/2;
		
		k_Comp.lpszPassword = mu16_Password;
		k_Comp.dwPasswordLength = sizeof(mu16_Password)/2;

		if (!WI().mf_CrackUrlW(u16_Url, 0, ICU_ESCAPE, &k_Comp))
			return GetInetError();

		mu16_Port = k_Comp.nPort;

		switch (k_Comp.nScheme)
		{
			case INTERNET_SCHEME_FTP:   mu32_Service = INTERNET_SERVICE_FTP;  break;
			case INTERNET_SCHEME_HTTP:  mu32_Service = INTERNET_SERVICE_HTTP; break;
			case INTERNET_SCHEME_HTTPS: mu32_Service = INTERNET_SERVICE_HTTP; break;
			default: 
				mu32_Service = -1;
				return ERROR_INTERNET_UNRECOGNIZED_SCHEME;
		}
		return 0;
	}

	// See description for mu16_Proxy and mu32_AccessType
	// Must be called before ConnectServer() !
	// u16_Proxy = "" --> Use Internet Explorer default settings
	void SetProxy(WCHAR* u16_Proxy)
	{
		ms_Proxy = u16_Proxy;
		mu32_AccessType = (ms_Proxy.Len() > 0) ? INTERNET_OPEN_TYPE_PROXY : INTERNET_OPEN_TYPE_PRECONFIG;
	}

	// Modifies the HTTP headers which are sent to the server. (separated by pipe)
	// e.g. "Referer: http://www.test.com|Accept-Language:en"
	// If the value of a header is empty, the header is removed.
	void HttpSetHeaders(WCHAR* u16_Headers)
	{
		ms_Headers = u16_Headers;
	}

	// switches FTP into passive mode
	// Must be called before ConnectServer() !
	void FtpSetPassiveMode(BOOL b_Passive)
	{
		mu32_ConectFlags = (b_Passive) ? INTERNET_FLAG_PASSIVE : 0;
	}

	// See description for mu32_ReqFlags
	// Must be called before HttpOpenFile() !
	void HttpSetRequestFlags(DWORD u32_ReqFlags)
	{
		mu32_ReqFlags = u32_ReqFlags;
	}
	
	// Download only the first u32_MaxDownload Bytes of the file
	// Only used in DownloadEntireFileToDisk(), not for partial downloads!
	void SetMaxDownload(DWORD u32_MaxDownload)
	{
		mu32_MaxDownload = u32_MaxDownload;
	}

	// This function aborts the currently active operation.
	void AbortOperation()
	{
		mb_Abort = TRUE; 
	
		if (WI().mh_WininetDll)
		{
			// Closing the handles aborts any running operation in Wininet.dll
			WI().mf_CloseHandle(mh_Connection);
			WI().mf_CloseHandle(mh_Session);
			WI().mf_CloseHandle(mh_InetFile);  // LAST !! WinInet.dll BUG !! (may block)
			mh_Connection = 0;
			mh_Session    = 0;
			mh_InetFile   = 0;
		}
	}

	// returns the maximum value and the current value for a progressbar
	// to show the download progress
	// ATTENTION:
	// The progressbar makes only sense  when using DownloadEntireFileToDisk().
	// A progressbar would show nonsense when using DownloadFilePartToMemory().
	// ATTENTION:
	// Not all HTTP Servers return "CONTENT-LENGTH" (e.g. AOL servers)
	// This function may return Size = 0 although the file is not corrupt !!!!!!
	// Do not rely on size value, use only for progressbars  !!!!!!
	void GetProgress(ULONGLONG* pu64_Size, ULONGLONG* pu64_Read)
	{
		*pu64_Size = u64_ProgressSize;
		*pu64_Read = u64_ProgressRead;
	}

	// returns 0 on success or error code
	// This function connects to any server (HTTP, HTTPS, FTP,...)
	// Sets *pb_Offline = TRUE if Internet Explorer is in Offline Mode
	DWORD ConnectServer(BOOL* pb_Offline)
	{
		*pb_Offline = FALSE;

		if (!WI().mh_WininetDll)
			return ERROR_INVALID_HANDLE;

		CloseInternet();

		// Never pass an empty proxy string to InternetOpenW() !!
		WCHAR* u16_Proxy = (ms_Proxy.Len()) ? (WCHAR*)ms_Proxy : 0;

		#if _TraceInternet
			CTrace::TraceW(L"Connecting: %s:%u", mu16_Server, mu16_Port);
		#endif

		ULONG u32_StateFlags;
		WI().mf_GetConectedState(&u32_StateFlags, 0);
		if ((u32_StateFlags & INTERNET_CONNECTION_OFFLINE) > 0)
		{
			*pb_Offline = TRUE;
			return ERROR_INTERNET_CANNOT_CONNECT;
		}

		mh_Session = WI().mf_OpenW(L"ElmueSoft Cabinet Extraction", mu32_AccessType, u16_Proxy, 0, 0);
		if (!mh_Session)
			return GetInetError();

		mh_Connection = WI().mf_ConnectW(mh_Session, mu16_Server, mu16_Port, mu16_Username, mu16_Password, mu32_Service, mu32_ConectFlags, 0);
		if (!mh_Connection)
			return GetInetError();

		return 0;
	}

	
	// Send the request to the server. 
	// u16_Method must be "GET" or "POST"
	// Optional parameters:
	//   p_POST = POST or PUT data (set 0 if not used)
	// u16_GET  = GET data wich is appended to the UrlPath (set L"" if not used)
	// If the server did not return HTTP_STATUS_OK, the status code is written to pu32_Status
	DWORD HttpOpenFile(WCHAR* u16_Method, void* p_POST, DWORD u32_POSTLength, WCHAR* u16_GET, DWORD* pu32_Status)
	{
		*pu32_Status = 0;

		CloseInetFile();

		if (!mh_Connection)
			return ERROR_INVALID_HANDLE;

		if (mu32_Service != INTERNET_SERVICE_HTTP)
			return ERROR_INVALID_PARAMETER;

		CStrW s_Url;
		s_Url.Format(L"%s%s", mu16_UrlPath, u16_GET);

		#if _TraceInternet
			CTrace::TraceW(L"HTTP Open: %s%s", mu16_Server, (WCHAR*)s_Url);
		#endif

		mh_InetFile = WI().mf_HttpOpenRequestW(mh_Connection, u16_Method, s_Url, L"HTTP/1.1", 0, 0, mu32_ReqFlags, 0);
		if (!mh_InetFile)
			return GetInetError();

		BOOL b_PartialContent;
		if (!HttpAddHeaders(ms_Headers, &b_PartialContent))
			return GetInetError();

		if (!WI().mf_HttpSendRequestW(mh_InetFile, 0, 0, p_POST, u32_POSTLength))
			return GetInetError();

		DWORD u32_Err;
		if (u32_Err = HttpQueryInfo(HTTP_QUERY_STATUS_CODE, pu32_Status))
			return u32_Err;

		if (b_PartialContent)
		{
			if (*pu32_Status != HTTP_STATUS_PARTIAL_CONTENT) // 206
				return ERROR_HTTP_INVALID_SERVER_RESPONSE;
		}
		else
		{
			if (*pu32_Status != HTTP_STATUS_OK) // 200
				return ERROR_HTTP_INVALID_SERVER_RESPONSE;
		}

		DWORD u32_FileSize; // Not all HTTP Servers return "CONTENT-LENGTH" (e.g. AOL servers) !!!
		HttpQueryInfo(HTTP_QUERY_CONTENT_LENGTH, &u32_FileSize);
		
		u64_ProgressSize = u32_FileSize;
		return 0;
	}

	// Open the file on the FTP server
	// If u32_FirstByte > 0 --> Send the command "REST" to the FTP server 
	// which starts the file transfer at the given Byte position in the file
	DWORD FtpOpenFile(DWORD u32_FirstByte)
	{
		CloseInetFile();

		if (!mh_Connection)
			return ERROR_INVALID_HANDLE;

		if (mu32_Service != INTERNET_SERVICE_FTP)
			return ERROR_INVALID_PARAMETER;

		if (u32_FirstByte > 0)
		{
			WCHAR u16_Command[100];
			swprintf(u16_Command, L"REST %u", u32_FirstByte);

			if (!WI().mf_FtpCommandW(mh_Connection, FALSE, 0, u16_Command, 0, 0))
				return GetInetError();
		}

		#if _TraceInternet
			CTrace::TraceW(L"FTP Open: %s%s", mu16_Server, mu16_UrlPath);
		#endif

		mh_InetFile = WI().mf_FtpOpenFileW(mh_Connection, mu16_UrlPath, GENERIC_READ, FTP_TRANSFER_TYPE_BINARY|INTERNET_FLAG_DONT_CACHE, 0);
		if (!mh_InetFile)
			return GetInetError();

		DWORD u32_High;
		DWORD u32_Low = WI().mf_FtpGetFileSize(mh_InetFile, &u32_High);

		u64_ProgressSize = (ULONGLONG)u32_High * 0x100000000 + u32_Low;
		return 0;
	}


	// Sets *pu32_Result to the integer value to be retrieved
	// u32_InfoType = HTTP_QUERY_STATUS_CODE    returns the status sent by the serverr (200 = OK)
	// u32_InfoType = HTTP_QUERY_CONTENT_LENGTH returns the length of the file to be downloaded
	DWORD HttpQueryInfo(DWORD u32_InfoType, DWORD *pu32_Result)
	{
		*pu32_Result = 0;

		if (!mh_InetFile)
			return ERROR_INVALID_HANDLE;

		u32_InfoType |= HTTP_QUERY_FLAG_NUMBER;
		DWORD u32_Len = 4;

		if (!WI().mf_HttpQueryInfoW(mh_InetFile, u32_InfoType, pu32_Result, &u32_Len, 0))
			return GetInetError();

		return 0;
	}

	// reads the content of the FTP or HTTP file requested with HttpOpenFile or FtpOpenFile
	DWORD ReadFile(void* p_Buffer, DWORD u32_Count, DWORD* pu32_Read)
	{
		*pu32_Read = 0;
		BYTE* pu8_Buf = (BYTE*)p_Buffer;

		if (!mh_InetFile)
			return ERROR_INVALID_HANDLE;

		int s32_Tick = GetTickCount();

		DWORD u32_Len = 0;
		do 
		{
			if (mb_Abort)
				return ERROR_CANCELLED;

			// Get little chunks from InternetReadFile to allow Aborting the operation quickly
			// and for detailed display in progressbar
			DWORD u32_Chunk = min (20000, u32_Count - *pu32_Read);

			if (!WI().mf_ReadFile(mh_InetFile, pu8_Buf, u32_Chunk, &u32_Len))
				return GetInetError();

			*pu32_Read        += u32_Len;
			 pu8_Buf          += u32_Len;
			 u64_ProgressRead += u32_Len;
		}
		while (u32_Len > 0 && *pu32_Read < u32_Count); // Stop if nothing received (Len=0)

		s32_Tick = max(1, GetTickCount() - s32_Tick);

		#if _TraceInternet
			CTrace::TraceW(L">>>>>>>>>>>>>>>>>>>>>>>>>> Downloaded %d Bytes with %d kB/s <<<<<<<<<<<<<<<<<<<<<<<<<", *pu32_Read, *pu32_Read/s32_Tick);
		#endif
		return 0;
	}

	// Closes the file opened with HttpOpenFile or FtpOpenFile
	void CloseInetFile()
	{
		if (mh_InetFile) 
		{
			WI().mf_CloseHandle(mh_InetFile);
			mh_InetFile = 0;

			#if _TraceInternet
				CTrace::TraceW(L"Internet Close File");
			#endif
		}
		mb_Abort         = FALSE;
		u64_ProgressSize = 0;
		u64_ProgressRead = 0;
		mu32_MaxDownload = 0x7FFFFFFF;
	}

	void CloseDownloadFile()
	{
		CloseHandle(mh_DownloadFile);
		mh_DownloadFile = 0;
	}

	void DeleteTempFile()
	{
		CloseDownloadFile();

		#if _TraceInternet
			if (mu16_TempFile[0]) CTrace::TraceW(L"*** Deleting Temp file: %s", mu16_TempFile);
		#endif

		DeleteFileW(mu16_TempFile);
		mu16_TempFile[0] = 0;
	}

	// Closes all connections to the server
	void CloseInternet()
	{
		CloseInetFile();
		if (mh_Connection)
		{
			WI().mf_CloseHandle(mh_Connection);
			mh_Connection = 0;

			#if _TraceInternet
				CTrace::TraceW(L"Internet Close Connection");
			#endif
		}
		if (mh_Session)    
		{
			WI().mf_CloseHandle(mh_Session);
			mh_Session    = 0;
		}
	}

	// Close ALL
	void CleanUp()
	{
		CloseInternet();
		DeleteTempFile();
	}

	// Explains the API error from WinInet.dll or the HTTP Status code
	// returns TRUE if the error could be explained
	static BOOL ExplainInetErrorW(DWORD u32_Error, CStrW* psw_Msg, DWORD u32_Status)
	{
		DWORD u32_BufLen = 2000;
		psw_Msg->Allocate(u32_BufLen);

		if (u32_Status > 0 && u32_Status != HTTP_STATUS_OK)
		{
			psw_Msg->Format(L"The server returned HTTP status error %d: %s", u32_Status, GetHttpStatusW(u32_Status));
			return TRUE;
		}

		if (!WI().mh_WininetDll || u32_Error < INTERNET_ERROR_BASE || u32_Error > INTERNET_ERROR_LAST)
			return FALSE;

		if (u32_Error == ERROR_INTERNET_EXTENDED_ERROR)
		{
			DWORD u32_ExtError;
			WI().mf_GetLastResponseW(&u32_ExtError, *psw_Msg, &u32_BufLen);

			if (!u32_BufLen)
				*psw_Msg = L"Could not retrieve the server error message for the failed operation.";

			return TRUE;
		}

		if (FormatMessageW(FORMAT_MESSAGE_FROM_HMODULE, WI().mh_WininetDll, u32_Error, 0, *psw_Msg, u32_BufLen, 0))
			return TRUE;

		return FALSE;
	}

	// Explains the HTTP status code
	static WCHAR* GetHttpStatusW(DWORD u32_Status)
	{
		switch (u32_Status)
		{
		case HTTP_STATUS_CONTINUE:            return L"OK to continue with request"; break;
		case HTTP_STATUS_SWITCH_PROTOCOLS:    return L"Server has switched protocols in upgrade header"; break;
	
		case HTTP_STATUS_OK:                  return L"Request completed"; break;
		case HTTP_STATUS_CREATED:             return L"Object created. Reason = new URI"; break;
		case HTTP_STATUS_ACCEPTED:            return L"Async completion (TBS)"; break;
		case HTTP_STATUS_PARTIAL:             return L"Partial completion"; break;
		case HTTP_STATUS_NO_CONTENT:          return L"No info to return"; break;
		case HTTP_STATUS_RESET_CONTENT:       return L"Request completed, but clear form"; break;
		case HTTP_STATUS_PARTIAL_CONTENT:     return L"Partial GET fulfilled"; break;
	
		case HTTP_STATUS_AMBIGUOUS:           return L"Server couldn't decide what to return"; break;
		case HTTP_STATUS_MOVED:               return L"Object permanently moved"; break;
		case HTTP_STATUS_REDIRECT:            return L"Object temporarily moved"; break;
		case HTTP_STATUS_REDIRECT_METHOD:     return L"Redirection w/ new access method"; break;
		case HTTP_STATUS_NOT_MODIFIED:        return L"If-modified-since was not modified"; break;
		case HTTP_STATUS_USE_PROXY:           return L"Redirection to proxy, location header specifies proxy to use"; break;
		case HTTP_STATUS_REDIRECT_KEEP_VERB:  return L"HTTP/1.1: keep same verb"; break;
	
		case HTTP_STATUS_BAD_REQUEST:         return L"Invalid Syntax"; break;
		case HTTP_STATUS_DENIED:              return L"Access denied"; break;
		case HTTP_STATUS_PAYMENT_REQ:         return L"Payment required"; break;
		case HTTP_STATUS_FORBIDDEN:           return L"Request forbidden"; break;
		case HTTP_STATUS_NOT_FOUND:           return L"Object not found"; break;
		case HTTP_STATUS_BAD_METHOD:          return L"Method is not allowed"; break;
		case HTTP_STATUS_NONE_ACCEPTABLE:     return L"No response acceptable to client found"; break;
		case HTTP_STATUS_PROXY_AUTH_REQ:      return L"Proxy authentication required"; break;
		case HTTP_STATUS_REQUEST_TIMEOUT:     return L"Server timed out waiting for request"; break;
		case HTTP_STATUS_CONFLICT:            return L"User should resubmit with more info"; break;
		case HTTP_STATUS_GONE:                return L"The resource is no longer available"; break;
		case HTTP_STATUS_LENGTH_REQUIRED:     return L"The server refused to accept request w/o a length"; break;
		case HTTP_STATUS_PRECOND_FAILED:      return L"Precondition given in request failed"; break;
		case HTTP_STATUS_REQUEST_TOO_LARGE:   return L"Request entity was too large"; break;
		case HTTP_STATUS_URI_TOO_LONG:        return L"Request URI too long"; break;
		case HTTP_STATUS_UNSUPPORTED_MEDIA:   return L"Unsupported media type"; break;
		case HTTP_STATUS_RETRY_WITH:          return L"Retry after doing the appropriate action"; break;
	
		case HTTP_STATUS_SERVER_ERROR:        return L"Internal server error"; break;
		case HTTP_STATUS_NOT_SUPPORTED:       return L"Required not supported"; break;
		case HTTP_STATUS_BAD_GATEWAY:         return L"Error response received from gateway"; break;
		case HTTP_STATUS_SERVICE_UNAVAIL:     return L"Temporarily overloaded"; break;
		case HTTP_STATUS_GATEWAY_TIMEOUT:     return L"Timed out waiting for gateway"; break;
		case HTTP_STATUS_VERSION_NOT_SUP:     return L"HTTP version not supported"; break;
		default:                              return L"Unknown HTTP Status Code"; break;
		};
	}

	// ################################ PRIVATE ########################################

private:

	DWORD GetInetError()
	{
		if (mb_Abort)
			return ERROR_CANCELLED;
		else
			return GetLastError();
	}

	// This function is private because it must be called between OpenRequest() and SendRequest()
	// Calling it from outside the class does not make sense.
	// Modifies the HTTP headers which are sent to the server. (separated by pipe)
	// e.g. "Referer: http://www.test.com|Accept-Language:en"  (no space before or after pipe!!)
	// If the value of a header is empty, the header is removed.
	// Sets *pb_PartialContent = TRUE if a "Range:..." header is specified
	BOOL HttpAddHeaders(WCHAR* u16_Headers, BOOL* pb_PartialContent)
	{
		*pb_PartialContent = FALSE;

		if (!wcslen(u16_Headers))
			return TRUE;

		// Stupid Microsoft does not allow to replace multiple headers at once, so a loop is required
		WCHAR* u16_Start = u16_Headers;
		while (TRUE)
		{
			DWORD  u32_Len = -1; // Pass the rest of the string to HttpAddHeaders()
			WCHAR* u16_End = wcschr(u16_Start, '|');
			if (u16_End)
			{
				u32_Len = (UINT)(u16_End - u16_Start); // Pass only u32_Len characters to HttpAddHeaders()
			}

			if (wcsnicmp(u16_Start, L"Range:", 6) == 0)
				*pb_PartialContent = TRUE;

			if (!WI().mf_HttpAddHeadersW(mh_InetFile, u16_Start, u32_Len, HTTP_ADDREQ_FLAG_REPLACE | HTTP_ADDREQ_FLAG_ADD))
				return FALSE;

			if (!u16_End)
				break;

			u16_Start = u16_End + 1;
		};
		return TRUE;
	}

	// ########################### HIGH LEVEL FUNCTIONS ################################

public:

	// If you pass an empty string, a temporary file will be created, which is deleted after extraction
	DWORD CreateDownloadFileW(WCHAR* u16_File)
	{
		// Create a unique new temporary file to be used for downloads
		if (!u16_File[0])
		{
			DeleteTempFile(); // If there is an older temp file -> delete it.

			WCHAR u16_TempDir[MAX_PATH];
			if (!GetTempPathW(MAX_PATH, u16_TempDir))
				return GetLastError();

			if (!GetTempFileNameW(u16_TempDir, L"Cab", 0, mu16_TempFile))
				return GetLastError();

			u16_File = mu16_TempFile;
		}

		// Create the folder(s) if it/they do not yet exist
		CStrW sw_Folder;
		CFile::SplitPathW(u16_File, &sw_Folder, 0);
		
		DWORD u32_Error = CFile::CreateFolderTreeW(sw_Folder);
		if (u32_Error)
			return u32_Error;

		CloseDownloadFile();

		#if _TraceInternet
			CTrace::TraceW(L"Creating download file: %s", u16_File);
		#endif

		mh_DownloadFile = CreateFileW(u16_File, GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
		if (mh_DownloadFile == INVALID_HANDLE_VALUE)
			return GetLastError();

		#if _TraceInternet
			CTrace::TraceW(L"*** Successfully created Download file: %s", u16_File);
		#endif
		return 0;
	}

	// returns the handle of the file to be written with downloaded data
	HANDLE GetDownloadFile()
	{
		return mh_DownloadFile;
	}

	// Downloads an entire file from HTTP or FTP with maximum possible speed and saves it into the download file
	// The connection and the file must already be open and stay open after the download
	// returns the API error on error and optionally the HTTP Status in pu32_Status
	DWORD DownloadEntireFileToDisk(DWORD *pu32_Status)
	{
		#if _TraceInternet
			CTrace::TraceW(L"--------------------------------------");
			CTrace::TraceW(L"Internet Start downloading entire file to disk.");
		#endif

		*pu32_Status = 0;

		if (!mh_DownloadFile)
			return ERROR_INVALID_PARAMETER;

		DWORD u32_Err;
		if (mu32_Service == INTERNET_SERVICE_HTTP)
		{
			if (u32_Err = HttpOpenFile(L"GET", 0, 0, L"", pu32_Status))
				return u32_Err;
		}
		else if (mu32_Service == INTERNET_SERVICE_FTP)
		{
			if (u32_Err = FtpOpenFile(0))
				return u32_Err;
		}
		else return ERROR_INTERNET_UNRECOGNIZED_SCHEME;

		BYTE  u8_Buffer[100000];
		DWORD u32_Read;
		do
		{
			DWORD u32_Count = min(mu32_MaxDownload, sizeof(u8_Buffer));
			
			if (u32_Err = ReadFile(u8_Buffer, u32_Count, &u32_Read))
				return u32_Err;
				
			mu32_MaxDownload -= u32_Read;

			DWORD u32_Written;
			if (!WriteFile(mh_DownloadFile, u8_Buffer, u32_Read, &u32_Written, 0))
				return GetLastError();
		}
		while (u32_Read > 0 && mu32_MaxDownload > 0);
		
		CloseInetFile();
		return 0;
	}


	// Loads a part of a file into memory (used for direct extraction)
	// The file can be on a FTP server which supports resuming broken downloads
	// or on a HTTP server which runs a script which returns the part of a file
	// passing the HTTP header "Range: bytes=Start-End"
	// The connection must already be open and stays open to download more parts
	// returns the API error on error and optionally the HTTP Status in pu32_Status
	DWORD DownloadFilePartToMemory(void* p_Buffer, DWORD u32_Offset, DWORD u32_Count, DWORD* pu32_Read, DWORD* pu32_Status)
	{
		#if _TraceInternet
			CTrace::TraceW(L"--------------------------------------");
			CTrace::TraceW(L"Internet Start downloading file part to memory. Offset= %u Byte, Count= %u Byte", u32_Offset, u32_Count);
		#endif

		*pu32_Read   = 0;
		*pu32_Status = 0;
		
		DWORD u32_Err;
		if (mu32_Service == INTERNET_SERVICE_HTTP)
		{
			// "Range: bytes=0-9" will download 10 bytes!
			WCHAR u16_Range[100];
			swprintf(u16_Range, L"Range: bytes=%u-%u", u32_Offset, u32_Offset+u32_Count-1);

			if (ms_Headers.Len()) ms_Headers += L"|";
			ms_Headers += u16_Range;
			
			if (u32_Err = HttpOpenFile(L"GET", 0, 0, L"", pu32_Status))
				return u32_Err;
		}
		else if (mu32_Service == INTERNET_SERVICE_FTP)
		{
			if (u32_Err = FtpOpenFile(u32_Offset))
				return u32_Err;
		}
		else return ERROR_INTERNET_UNRECOGNIZED_SCHEME;

		if (u32_Err = ReadFile(p_Buffer, u32_Count, pu32_Read))
			return u32_Err;

		CloseInetFile();
		return 0;
	}
};

} // Namespace Cabinet
