// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __ATLSIFACE_H__
#define __ATLSIFACE_H__

#pragma once
#include <atlcoll.h>
#include <httpext.h>
#include <atlserr.h>

#pragma pack(push,_ATL_PACKING)
namespace ATL{

// Forward declarations of custom data types used in 
// interfaces declared in this file.
struct AtlServerRequest;
class CIsapiWorker;
__interface IAtlMemMgr;
class CCookie;

// Forward declarations of all interfaces declared in this file.
__interface IWriteStream;
__interface IHttpFile;
__interface IHttpServerContext;
__interface IHttpRequestLookup;
__interface IRequestHandler;
__interface ITagReplacer;
__interface IIsapiExtension;
__interface IPageCacheControl;
__interface IRequestStats;
__interface IBrowserCaps;
__interface IBrowserCapsSvc;


// ATLS Interface declarations.

// IWriteStream
// Interface for writing to a stream.
__interface IWriteStream
{
	HRESULT WriteStream(LPCSTR szOut, int nLen, DWORD *pdwWritten);
	HRESULT FlushStream();
};

// IHttpFile
// This is an interface that provides for basic accessor
// functionality for files (see CHttpRequestFile).
__interface IHttpFile
{
	LPCSTR GetParamName();
	LPCSTR GetFileName();
	LPCSTR GetFullFileName();
	LPCSTR GetContentType();
	LPCSTR GetTempFileName();
	ULONGLONG GetFileSize();
	void Free();
};

// IHttpServerContext
// This interface encapsulates the capabilities of the web server and provides information about
// the current request being handled. See CServerContext for implementation.
__interface ATL_NO_VTABLE __declspec(uuid("813F3F00-3881-11d3-977B-00C04F8EE25E")) 
	IHttpServerContext : public IUnknown
{
	HRESULT  STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	LPCSTR GetRequestMethod();
	LPCSTR GetQueryString();
	LPCSTR GetPathInfo();
	LPCSTR GetPathTranslated();
	LPCSTR GetScriptPathTranslated();
	DWORD GetTotalBytes();
	DWORD GetAvailableBytes();
	BYTE *GetAvailableData();
	LPCSTR GetContentType();
	BOOL GetServerVariable(__in_z LPCSTR pszVariableName,
									__out_ecount_part_opt(*pdwSize, *pdwSize) LPSTR pvBuffer, __inout DWORD *pdwSize);
	BOOL GetImpersonationToken(HANDLE * pToken);
	BOOL WriteClient(void *pvBuffer, DWORD *pdwBytes);
	BOOL AsyncWriteClient(void *pvBuffer, DWORD *pdwBytes);
	BOOL ReadClient(void *pvBuffer, DWORD *pdwSize);
	BOOL AsyncReadClient(void *pvBuffer, DWORD *pdwSize);
	BOOL SendRedirectResponse(LPCSTR pszRedirectUrl);
	BOOL SendResponseHeader(LPCSTR pszHeader, LPCSTR pszStatusCode,
							BOOL fKeepConn);
	BOOL DoneWithSession(DWORD dwHttpStatusCode);
	BOOL RequestIOCompletion(PFN_HSE_IO_COMPLETION pfn, DWORD *pdwContext);
	BOOL TransmitFile(HANDLE hFile, PFN_HSE_IO_COMPLETION pfn, void *pContext, 
		LPCSTR szStatusCode, DWORD dwBytesToWrite, DWORD dwOffset,
		void *pvHead, DWORD dwHeadLen, void *pvTail,
		DWORD dwTailLen, DWORD dwFlags);
	BOOL AppendToLog(LPCSTR szMessage, DWORD* pdwLen);
	BOOL MapUrlToPathEx(LPCSTR szLogicalPath, DWORD dwLen, HSE_URL_MAPEX_INFO *pumInfo);
};

// IHttpRequestLookup
// This interface is designed to allow one map to chain to another map.
// The interface is implemented by the CHttpThunkMap and CHttpRequest classes.
// Pointers to this interface are passed around by CRequestHandlerT and CHtmlTagReplacer.
// dwType - the type of item being requested
__interface ATL_NO_VTABLE __declspec(uuid("A5990B44-FF74-4bfe-B66D-F9E7E9F42D42")) 
	IHttpRequestLookup : public IUnknown
{
	POSITION GetFirstQueryParam(LPCSTR *ppszName, LPCSTR *ppszValue);
	POSITION GetNextQueryParam(POSITION pos, LPCSTR *ppszName, LPCSTR *ppszValue);

	POSITION GetFirstFormVar(LPCSTR *ppszName, LPCSTR *ppszValue);
	POSITION GetNextFormVar(POSITION pos, LPCSTR *ppszName, LPCSTR *ppszValue);

	POSITION GetFirstFile(LPCSTR *ppszName, IHttpFile **ppFile);
	POSITION GetNextFile(POSITION pos, LPCSTR *ppszName, IHttpFile **ppFile);

	HRESULT GetServerContext(IHttpServerContext **ppOut);
};


// IRequestHandler
// This interface is impelemented by clients who want to be request handlers in an
// atl server application. Server default implementations are provided in ATL, including
// IRequestHandlerImpl (atlisapi.h) and CRequestHandlerT (atlstencil.h)
__interface ATL_NO_VTABLE __declspec(uuid("D57F8D0C-751A-4223-92BC-0B29F65D2453")) 
IRequestHandler : public IUnknown
{
	HTTP_CODE GetFlags(DWORD *pdwStatus);
	HTTP_CODE InitializeHandler(AtlServerRequest *pRequestInfo, IServiceProvider *pProvider);
	HTTP_CODE InitializeChild(AtlServerRequest *pRequestInfo, IServiceProvider *pProvider, IHttpRequestLookup *pLookup);
	HTTP_CODE HandleRequest(AtlServerRequest *pRequestInfo, IServiceProvider *pProvider);
	void UninitializeHandler();
};

// ITagReplacer
// This interface defines the methods necessary for server response file processing.
__interface ATL_NO_VTABLE __declspec(uuid("8FF5E90C-8CE0-43aa-96C4-3BF930837512")) 
	ITagReplacer : public IUnknown
{
	HTTP_CODE FindReplacementOffset(LPCSTR szMethodName, DWORD *pdwMethodOffset, 
						LPCSTR szObjectName, DWORD *pdwObjOffset, DWORD *pdwMap, void **ppvParam, IAtlMemMgr *pMemMgr);
	HTTP_CODE RenderReplacement(DWORD dwFnOffset, DWORD dwObjOffset, DWORD dwMap, void *pvParam);
	HRESULT GetContext(REFIID riid, void** ppv);
	IWriteStream *SetStream(IWriteStream *pStream);
};


struct CStencilState;

// IIsapiExtension
// Tnis is the interface to the ISAPI extension of a running ATL Server web
// application. Provides request handler clients with access to functions of the
// ISAPI server.
__interface __declspec(uuid("79DD4A27-D820-4fa6-954D-E1DFC2C05978"))
	IIsapiExtension : public IUnknown
{
	BOOL DispatchStencilCall(AtlServerRequest *pRequestInfo);
	void RequestComplete(AtlServerRequest *pRequestInfo, DWORD hStatus, DWORD dwSubStatus);
	BOOL OnThreadAttach();
	void OnThreadTerminate();
	BOOL QueueRequest(AtlServerRequest *pRequestInfo);
	CIsapiWorker *GetThreadWorker();
	BOOL SetThreadWorker(CIsapiWorker *pWorker);
	HTTP_CODE LoadRequestHandler(LPCSTR szDllPath, LPCSTR szHandlerName, IHttpServerContext *pServerContext,
		HINSTANCE *phInstance, IRequestHandler **ppHandler);
	HRESULT AddService(REFGUID guidService, REFIID riid, IUnknown *punk, HINSTANCE hInstance);
	HRESULT RemoveService(REFGUID guidService, REFIID riid);
	HTTP_CODE LoadDispatchFile(LPCSTR szFileName, AtlServerRequest *pRequestInfo);

	AtlServerRequest* CreateRequest();
	void FreeRequest(AtlServerRequest* pRequest);
	HTTP_CODE TransferRequest(
		AtlServerRequest *pRequest, 
		IServiceProvider *pServiceProvider,
		IWriteStream *pWriteStream,
		IHttpRequestLookup *pLookup,
		LPCSTR szNewUrl,
		WORD nCodePage,
		bool bContinueAfterProcess,
		CStencilState *pState);
};

// IPageCacheControl
// This interface controls the cacheability of the current page
__interface ATL_NO_VTABLE __declspec(uuid("9868BFC0-D44D-4154-931C-D186EC0C45D5")) 
	IPageCacheControl : public IUnknown
{
	HRESULT GetExpiration(FILETIME *pftExpiration);
	HRESULT SetExpiration(FILETIME ftExpiration);
	BOOL IsCached();
	BOOL Cache(BOOL bCache);
};

// IRequestStats
// Used to query request statistics from a running ATL server ISAPI application.
__interface ATL_NO_VTABLE __declspec(uuid("2B75C68D-0DDF-48d6-B58A-CC7C2387A6F2"))
	IRequestStats : public IUnknown
{
	long GetTotalRequests();
	long GetFailedRequests();
	long GetAvgResponseTime();
	long GetCurrWaiting();
	long GetMaxWaiting();
	long GetActiveThreads();
};

// IBrowserCaps
// Interface that provides information about a particular web brorwser.
// See atlutil.h and the ATL Browser Capabilities service for information
// about this interface's implementation
__interface __declspec(uuid("3339FCE2-99BC-4985-A702-4ABC8304A995"))
	IBrowserCaps : public IUnknown
{
	HRESULT GetPropertyString(BSTR bstrProperty, BSTR * pbstrOut);
	HRESULT GetBooleanPropertyValue(BSTR bstrProperty, BOOL* pbOut);
	HRESULT GetBrowserName(BSTR * pbstrName);
	HRESULT GetPlatform(BSTR * pbstrPlatform);
	HRESULT GetVersion(BSTR * pbstrVersion);
	HRESULT GetMajorVer(BSTR * pbstrMajorVer);
	HRESULT GetMinorVer(BSTR * pbstrMinorVer);
	HRESULT SupportsFrames(BOOL* pbFrames);
	HRESULT SupportsTables(BOOL* pbTables);
	HRESULT SupportsCookies(BOOL* pbCookies);
	HRESULT SupportsBackgroundSounds(BOOL* pbBackgroundSounds);
	HRESULT SupportsVBScript(BOOL* pbVBScript);
	HRESULT SupportsJavaScript(BOOL* pbJavaScript);
	HRESULT SupportsJavaApplets(BOOL* pbJavaApplets);
	HRESULT SupportsActiveXControls(BOOL* pbActiveXControls);
	HRESULT SupportsCDF(BOOL* pbCDF);
	HRESULT SupportsAuthenticodeUpdate(BOOL* pbAuthenticodeUpdate);
	HRESULT IsBeta(BOOL* pbIsBeta);
	HRESULT IsCrawler(BOOL* pbIsCrawler);
	HRESULT IsAOL(BOOL* pbIsAOL);
	HRESULT IsWin16(BOOL* pbIsWin16);
	HRESULT IsAK(BOOL* pbIsAK);
	HRESULT IsSK(BOOL* pbIsSK);
	HRESULT IsUpdate(BOOL* pbIsUpdate);
};

// IBrowserCapsSvc.
// Interface on the browser caps service. Used by clients to query a running
// instance of the browser capabilities service for information about a user's web
// browser. See atlutil.h for implementation of the browser capabilities services.
__interface __declspec(uuid("391E7418-863B-430e-81BB-1312ED2FF3E9"))
	IBrowserCapsSvc : public IUnknown
{
	HRESULT GetCaps(IHttpServerContext * pContext, IBrowserCaps ** ppOut);
	HRESULT GetCapsUserAgent(BSTR bstrAgent, IBrowserCaps ** ppOut);
};

// IThreadPoolConfig
// Used to configure the worker thread pool. This can be used by any
// client of the CThreadPool class. See atlutil.h for implemenetation
// of CThreadPool.
__interface __declspec(uuid("B1F64757-6E88-4fa2-8886-7848B0D7E660")) 
	IThreadPoolConfig : public IUnknown
{
	STDMETHOD(SetSize)(int nNumThreads);
	STDMETHOD(GetSize)(int *pnNumThreads);
	STDMETHOD(SetTimeout)(DWORD dwMaxWait);
	STDMETHOD(GetTimeout)(DWORD *pdwMaxWait);
};

typedef DWORD_PTR HSESSIONENUM;

// ISession
// Interface on a single client session. Used to access variables in the client 
// session in the session state services. See atlsession.h for implementation of
// this interface.
__interface __declspec(uuid("DEB69BE3-7AC9-4a13-9519-266C1EA3AB39")) 
	ISession : public IUnknown
{
	STDMETHOD(SetVariable)(LPCSTR szName, VARIANT NewVal);
	STDMETHOD(GetVariable)(LPCSTR szName, VARIANT *pVal);
	STDMETHOD(GetCount)(long *pnCount);
	STDMETHOD(RemoveVariable)(LPCSTR szName);
	STDMETHOD(RemoveAllVariables)();
	STDMETHOD(BeginVariableEnum)(POSITION *pPOS, HSESSIONENUM *phEnumHandle);
	STDMETHOD(GetNextVariable)(POSITION *pPOS, VARIANT *pVal, HSESSIONENUM hEnum, LPSTR szName, DWORD dwLen);
	STDMETHOD(CloseEnum)(HSESSIONENUM hEnumHandle);
	STDMETHOD(IsExpired)();
	STDMETHOD(SetTimeout)(unsigned __int64 dwNewTimeout);
}; //ISession


// ISessionStateService
// Interface on the session state service for an ISAPI application. Request
// handler objects will use this interface to access user sessions. See
// atlsession.h for implementation of this interface.
__interface __declspec(uuid("C5740C4F-0C6D-4b43-92C4-2AF778F35DDE"))
	ISessionStateService : public IUnknown
{
	STDMETHOD(CreateNewSession)(LPSTR szNewID, DWORD *pdwSize, ISession** ppSession);
	STDMETHOD(CreateNewSessionByName)(LPSTR szNewID, ISession** ppSession);
	STDMETHOD(GetSession)(LPCSTR szID, ISession **ppSession);
	STDMETHOD(CloseSession)(LPCSTR szID);
};

// ISessionStateControl
// Interface used by session state service to get information about the service.
// Currently you can get the count of active sessions and the current default
// timeout for a session.
__interface __declspec(uuid("6C7F5F56-6CBD-49ee-9797-4C837D4C527A"))
	ISessionStateControl : public IUnknown
{
	STDMETHOD(SetSessionTimeout)(unsigned __int64 nTimeout);
	STDMETHOD(GetSessionTimeout)(unsigned __int64 *pnTimeout);
	STDMETHOD(GetSessionCount)(DWORD *pnSessionCount);
}; 

//
// IWorkerThreadClient
// Interface to be used with CWorkerThread
__interface IWorkerThreadClient
{
	HRESULT Execute(DWORD_PTR dwParam, HANDLE hObject);
	HRESULT CloseHandle(HANDLE hHandle);
};

}; // namespace ATL
#pragma pack(pop)

#endif // __ATLSIFACE_H__
