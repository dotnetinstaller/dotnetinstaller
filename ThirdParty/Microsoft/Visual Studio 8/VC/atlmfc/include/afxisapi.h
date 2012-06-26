// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.

// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __AFXISAPI_H_
#define __AFXISAPI_H_

#ifdef _UNICODE
#error ERROR: ISAPI does not support Unicode.
#endif

#pragma once

#include <afxv_cpu.h>

/////////////////////////////////////////////////////////////////////////////
// Turn off warnings for /W4
// To resume any of these warning: #pragma warning(default: 4xxx)
// which should be placed after the AFX include files

#ifdef _AFX_ALL_WARNINGS
#pragma warning( push )
#endif

// warnings generated with common MFC/Windows code
#pragma warning(disable: 4127)  // constant expression for TRACE/ASSERT
#pragma warning(disable: 4134)  // message map member fxn casts
#pragma warning(disable: 4201)  // nameless unions are part of C++
#pragma warning(disable: 4320)  // structs w/ uuid and single base class
#pragma warning(disable: 4511)  // private copy constructors are good to have
#pragma warning(disable: 4512)  // private operator= are good to have
#pragma warning(disable: 4514)  // unreferenced inlines are common
#pragma warning(disable: 4710)  // function not inlined
#pragma warning(disable: 4705)  // statement has no effect in optimized code
#pragma warning(disable: 4191)  // pointer-to-function casting
// warnings caused by normal optimizations
#ifndef _DEBUG
#pragma warning(disable: 4701)  // local variable *may* be used without init
#pragma warning(disable: 4702)  // unreachable code caused by optimizations
#pragma warning(disable: 4791)  // loss of debugging info in retail version
#pragma warning(disable: 4189)  // initialized but unused variable
#pragma warning(disable: 4390)  // empty controlled statement
#endif
// warnings specific to _AFXDLL version
#ifdef _AFXDLL
#pragma warning(disable: 4204)  // non-constant aggregate initializer
#pragma warning(disable: 4275)  // deriving exported class from non-exported
#pragma warning(disable: 4251)  // using non-exported as public in exported
#endif

#define STRICT 1

#ifndef _AFX_ENABLE_INLINES
#define _AFX_ENABLE_INLINES
#endif

#include <httpext.h>
#include <httpfilt.h>

#ifndef _INC_STDLIB
	#include <stdlib.h>
#endif
#ifndef _INC_TCHAR
	#include <tchar.h>
#endif

#include <atlcore.h>

#ifndef _INC_ERRNO 
	#include <errno.h>
#endif


#ifndef UNUSED
#ifdef _DEBUG
#define UNUSED(x)
#else
#define UNUSED(x) x
#endif
#endif

#define AFXISAPI __stdcall
#define AFXIS_DATADEF
#define AFXISAPI_CDECL __cdecl

#ifndef AFX_INLINE
#define AFX_INLINE __forceinline
#endif

#if !defined(UNALIGNED)
#if defined(_M_IA64) || defined(_M_AMD64)
#define UNALIGNED __unaligned
#else
#define UNALIGNED
#endif
#endif

#if !defined(_countof)
#if !defined(__cplusplus)
#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
#else
extern "C++"
{
template <typename _CountofType, size_t _SizeOfArray>
char (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) sizeof(*__countof_helper(_Array))
}
#endif
#endif

// Catches
// limits.h must not define its constants in terms of hex. [we are ok here]
// Actual limits.h values may cause excessive buffer.

// Users should use INT_MIN, not INT_MAX, to allow space for signs 
// makes a literal into a string

#define AFXISAPI_STRINGIZE(x) (# x)
// expands a macro and then makes that into a string

#define AFXISAPI_STRINGIZE_MACRO(x) AFXISAPI_STRINGIZE(x)

// determines the character count (includeing terminator) required by a numeric macro
#define AFXISAPI_CHARCOUNT_CONSTANT(x) (sizeof(AFXISAPI_STRINGIZE_MACRO(x)))


/////////////////////////////////////////////////////////////////////////////
// Internet Server API Library

#ifndef _AFX_NOFORCE_LIBS

#ifdef _AFXDLL
#ifdef _DEBUG
	#ifdef _UNICODE
		#pragma comment(lib, "MFCISUD.lib")
	#else
		#pragma comment(lib, "EAFXISD.lib")
	#endif
#else
	#ifdef _UNICODE
		#pragma comment(lib, "MFCISU.lib")
	#else
		#pragma comment(lib, "EAFXIS.lib")
	#endif // _UNICODE
#endif // _DEBUG
#else
#ifdef _DEBUG
	#ifdef _UNICODE
		#pragma comment(lib, "UAFXISD.lib")
	#else
		#pragma comment(lib, "NAFXISD.lib")
	#endif
#else
	#ifdef _UNICODE
		#pragma comment(lib, "UAFXIS.lib")
	#else
		#pragma comment(lib, "NAFXIS.lib")
	#endif // _UNICODE
#endif // _DEBUG
#endif // _AFXDLL

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "winspool.lib")
#pragma comment(lib, "advapi32.lib")

#endif // _AFX_NOFORCE_LIBS

extern HINSTANCE AFXISAPI AfxGetResourceHandle();

/////////////////////////////////////////////////////////////////////////////
// AFXIASPI - MFC Internet Server API support

// Classes declared in this file

class CHtmlStream;
class CHttpServerContext;
class CHttpServer;
class CHttpFilterContext;
class CHttpFilter;
class CHttpArgList;
struct CHttpArg;

// Classes this file uses from elsewhere, sometimes

#ifdef _AFX
class CLongBinary;
class CByteArray;
#endif

///////////////////////////////////////////////////////////////////////
// CHtmlStream -- manages in-memory HTML

class CHtmlStream
{
public:
// Constructors
	/* explicit */ CHtmlStream(UINT nGrowBytes = 4096);
	CHtmlStream(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes = 0);

// Operations
	void Attach(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes = 0);
	BYTE* Detach();
	DWORD GetStreamSize() const;

	virtual void Abort();
	virtual void Close();
	virtual void InitStream();
	virtual void Reset();

	virtual void Write(const void* lpBuf, UINT nCount);

	CHtmlStream& operator<<(LPCTSTR psz);
	CHtmlStream& operator<<(short int w);
	CHtmlStream& operator<<(long int dw);
	CHtmlStream& operator<<(const CHtmlStream& stream);
	CHtmlStream& operator<<(double d);
	CHtmlStream& operator<<(float f);

#ifdef _AFX
	// only available if building with core MFC
	CHtmlStream& operator<<(const CByteArray& array);
	CHtmlStream& operator<<(const CLongBinary& blob);
#endif

// Advanced Overridables
protected:
	virtual BYTE* Alloc(DWORD nBytes);
	virtual BYTE* Realloc(BYTE* lpMem, DWORD nBytes);
	virtual BYTE* Memcpy(BYTE* lpMemTarget, const BYTE* lpMemSource, UINT nBytes);
	virtual void GrowStream(DWORD dwNewLen);

	DWORD   m_nStreamSize;

public:
	virtual void Free(BYTE* lpMem);

// Implementation
protected:
	UINT    m_nGrowBytes;
	DWORD   m_nPosition;
	DWORD   m_nBufferSize;
	BYTE*   m_lpBuffer;
	BOOL    m_bAutoDelete;

public:
	virtual ~CHtmlStream();
};


///////////////////////////////////////////////////////////////////////
// Status codes for HTTP transactions

#ifndef _WININET_ // these symbols may come from WININET.H

#define HTTP_STATUS_OK                  200     // OK
#define HTTP_STATUS_CREATED             201     // created
#define HTTP_STATUS_ACCEPTED            202     // accepted
#define HTTP_STATUS_NO_CONTENT          204     // no content
#define HTTP_STATUS_REDIRECT            302     // moved permanently
#define HTTP_STATUS_TEMP_REDIRECT       302     // moved temporarily
#define HTTP_STATUS_NOT_MODIFIED        304     // not modified
#define HTTP_STATUS_BAD_REQUEST         400     // bad request
#define HTTP_STATUS_AUTH_REQUIRED       401     // unauthorized
#define HTTP_STATUS_FORBIDDEN           403     // forbidden
#define HTTP_STATUS_NOT_FOUND           404     // not found
#define HTTP_STATUS_REQUEST_TOO_LARGE   413     // Request entity was too large
#define HTTP_STATUS_SERVER_ERROR        500     // internal server error
#define HTTP_STATUS_NOT_IMPLEMENTED     501     // not implemented
#define HTTP_STATUS_BAD_GATEWAY         502     // bad gateway
#define HTTP_STATUS_SERVICE_NA          503     // service unavailable
#endif

///////////////////////////////////////////////////////////////////////
// Parse Map macros

#ifndef AFX_PARSE_CALL
#define AFX_PARSE_CALL
#endif

typedef void (AFX_PARSE_CALL CHttpServer::*AFX_PISAPICMD)(CHttpServerContext* pCtxt);

struct AFX_PARSEMAP_ENTRY;  // declared after CHttpServer, below

struct AFX_PARSEMAP
{
	UINT (PASCAL* pfnGetNumMapEntries)();
#ifdef _AFXDLL
	const AFX_PARSEMAP* (PASCAL* pfnGetBaseMap)();
#else
	const AFX_PARSEMAP* pBaseMap;
#endif
	const AFX_PARSEMAP_ENTRY* lpEntries;
	~AFX_PARSEMAP();
};

struct AFX_PARSEMAP_ENTRY_PARAMS
{
	int nParams;            // number of parameters
	int nRequired;          // number of parameters without defaults
	// all of these are arrays!
	LPTSTR* ppszInfo;       // pointers to name[2n], pointer to default[2n+1]
	BYTE*   ppszDefaults;   // pointers to coerced default values
	~AFX_PARSEMAP_ENTRY_PARAMS();
};

#ifdef _AFXDLL
#define DECLARE_PARSE_MAP() \
private: \
	static AFX_PARSEMAP_ENTRY _parseEntries[]; \
public: \
	static const AFX_PARSEMAP parseMap; \
	static const AFX_PARSEMAP* PASCAL GetThisParseMap(); \
	static UINT PASCAL GetNumMapEntries(); \
	virtual const AFX_PARSEMAP* GetParseMap() const; \

#else
#define DECLARE_PARSE_MAP() \
private: \
	static AFX_PARSEMAP_ENTRY _parseEntries[]; \
public: \
	static const AFX_PARSEMAP parseMap; \
	static UINT PASCAL GetNumMapEntries(); \
	virtual const AFX_PARSEMAP* GetParseMap() const; \

#endif // _AFXDLL

#ifdef _AFXDLL
#define BEGIN_PARSE_MAP(theClass, baseClass) \
	const AFX_PARSEMAP* PASCAL theClass::GetThisParseMap() \
		{ return &theClass::parseMap; } \
	typedef void (AFX_PARSE_CALL theClass::*theClass##CALL)(CHttpServerContext*); \
	const AFX_PARSEMAP* theClass::GetParseMap() const \
		{ return &theClass::parseMap; } \
	AFXIS_DATADEF const AFX_PARSEMAP theClass::parseMap = \
		{ &theClass::GetNumMapEntries, &baseClass::GetThisParseMap, &theClass::_parseEntries[0] }; \
	AFX_PARSEMAP_ENTRY theClass::_parseEntries[] = \
	{ \

#else
#define BEGIN_PARSE_MAP(theClass, baseClass) \
	typedef void (AFX_PARSE_CALL theClass::*theClass##CALL)(CHttpServerContext*); \
	const AFX_PARSEMAP* theClass::GetParseMap() const \
		{ return &theClass::parseMap; } \
	AFXIS_DATADEF const AFX_PARSEMAP theClass::parseMap = \
		{ &theClass::GetNumMapEntries, &baseClass::parseMap, &theClass::_parseEntries[0] }; \
	AFX_PARSEMAP_ENTRY theClass::_parseEntries[] = \
	{ \

#endif

#define ON_PARSE_COMMAND(FnName, mapClass, Args) \
	{ _T(#FnName), (AFX_PISAPICMD) (mapClass##CALL)&mapClass::FnName,\
		Args, NULL },

#define ON_PARSE_COMMAND_PARAMS(Params) \
	{ NULL, (AFX_PISAPICMD) NULL, Params, NULL },

#define DEFAULT_PARSE_COMMAND(FnName, mapClass) \
	{ _T(#FnName), (AFX_PISAPICMD) (mapClass##CALL)&mapClass::FnName,\
		NULL, NULL },

#define END_PARSE_MAP(theClass) \
	}; \
	UINT PASCAL theClass::GetNumMapEntries() { \
		return sizeof(theClass::_parseEntries) /\
		sizeof(AFX_PARSEMAP_ENTRY); } \

///////////////////////////////////////////////////////////////////////
//

class CHttpServerContext
{
public:
	explicit CHttpServerContext(EXTENSION_CONTROL_BLOCK* pECB);
	virtual ~CHttpServerContext();

// Operations
	BOOL GetServerVariable(__in_z LPTSTR lpszVariableName,
		__out_bcount_part_z(*lpdwSize, *lpdwSize) LPVOID lpvBuffer, __inout LPDWORD lpdwSize);
	BOOL WriteClient(LPVOID lpvBuffer, LPDWORD lpdwBytes, DWORD dwReserved = 0);
	BOOL ReadClient(LPVOID lpvBuffer, LPDWORD lpdwSize);
	BOOL ServerSupportFunction(DWORD dwHSERRequest,
		LPVOID lpvBuffer, LPDWORD lpdwSize, LPDWORD lpdwDataType);
	BOOL TransmitFile(HANDLE hFile,
		DWORD dwFlags = HSE_IO_DISCONNECT_AFTER_SEND,
		LPVOID pstrHeader = NULL, DWORD dwHeaderLen = 0,
		LPVOID pstrTrailer = NULL, DWORD dwTrailerLen = 0);

	CHttpServerContext& operator<<(LPCTSTR psz);
	CHttpServerContext& operator<<(long int dw);
	CHttpServerContext& operator<<(short int w);
	CHttpServerContext& operator<<(const CHtmlStream& stream);
	CHttpServerContext& operator<<(double d);
	CHttpServerContext& operator<<(float f);

#ifdef _AFX
	CHttpServerContext& operator<<(const CLongBinary& blob);
	CHttpServerContext& operator<<(const CByteArray& array);
#endif

	DWORD SetChunkSize(DWORD dwNewSize);
	DWORD GetChunkSize() const;

	void Reset();

// Attributes
public:
	BOOL m_bSendHeaders;
	DWORD m_dwStatusCode;
	EXTENSION_CONTROL_BLOCK* const m_pECB;
	CHtmlStream* m_pStream;
	DWORD m_dwEndOfHeaders;
#ifdef _DEBUG
	DWORD m_dwOldEndOfHeaders;
#endif

// Implementation
	DWORD m_dwBytesReceived;
	DWORD m_dwChunkSize;
	CHttpArgList* m_pArgList;
};


///////////////////////////////////////////////////////////////////////
// Internet Information Server Extension Support

class CHttpServer
{
public:
	/* explicit */ CHttpServer(TCHAR cDelimiter = '&');
	virtual ~CHttpServer();

	enum errors {
		callOK = 0,         // everything is fine
		callParamRequired,  // a required parameter was missing
		callBadParamCount,  // there were too many or too few parameters
		callBadCommand,     // the command name was not found
		callNoStackSpace,   // no stack space was available
		callNoStream,       // no CHtmlStream was available
		callMissingQuote,   // a parameter had a bad format
		callMissingParams,  // no parameters were available
		callBadParam,       // a paremeter had a bad format (ie, only one quote)
		callNoMemory,		// ran out of memory
	};

// overridables
	virtual int CallFunction(__in CHttpServerContext* pCtxt,
		__in_z LPTSTR pszQuery, __in_z_opt LPTSTR pszCommand);
	virtual BOOL OnParseError(CHttpServerContext* pCtxt, int nCause);
	virtual BOOL OnWriteBody(CHttpServerContext* pCtxt, LPBYTE pbContent,
		DWORD dwSize, DWORD dwReserved = 0);

// operations
	virtual void EndContent(CHttpServerContext* pCtxt) const;
	virtual void StartContent(CHttpServerContext* pCtxt) const;
	virtual void WriteTitle(CHttpServerContext* pCtxt) const;
	virtual LPCTSTR GetTitle() const;
	void AddHeader(CHttpServerContext* pCtxt, LPCTSTR pszString) const;

	virtual BOOL TerminateExtension(DWORD dwFlags);
	virtual DWORD HttpExtensionProc(EXTENSION_CONTROL_BLOCK *pECB);
	virtual BOOL GetExtensionVersion(HSE_VERSION_INFO *pVer);
	virtual CHtmlStream* ConstructStream();

	virtual BOOL InitInstance(CHttpServerContext* pCtxt);

// implementation
protected:
	UINT PASCAL GetStackSize(const BYTE* pbParams);
	int CallMemberFunc(__in CHttpServerContext* pCtxt,
		__in const AFX_PARSEMAP_ENTRY* pEntry,
		__in AFX_PARSEMAP_ENTRY* pParams, __in_z_opt LPTSTR szParams);
	LPTSTR GetQuery(CHttpServerContext* pCtxt, __in_z LPTSTR lpszQuery);
	const AFX_PARSEMAP_ENTRY* LookUp(LPCTSTR szMethod,
		const AFX_PARSEMAP*& pMap, AFX_PARSEMAP_ENTRY*& pParams,
		AFX_PISAPICMD pCmdDefault = NULL);
	int CountParams(LPCTSTR pszCommandLine, int& nCount);
	int ParseDefaultParams(AFX_PARSEMAP_ENTRY* pParams,
		int nParams, AFX_PARSEMAP_ENTRY_PARAMS*& pBlock,
		const BYTE* pbTypes);
	LPVOID PreprocessString(__in_z LPTSTR psz);
	void BuildStatusCode(__in_z LPTSTR pszResponse, __in DWORD dwCode);
	ATL::CComCriticalSection m_cs;

#ifdef _SHADOW_DOUBLES
	int PushDefaultStackArgs(BYTE* pStack,
		CHttpServerContext* pCtxt, const BYTE* pbParams,
		__in_z_opt LPTSTR lpszParams, AFX_PARSEMAP_ENTRY_PARAMS* pDefParams,
		int nSizeArgs);
	int PushStackArgs(BYTE* pStack, CHttpServerContext* pCtxt,
		const BYTE* pbParams, __in_z_opt LPTSTR lpszParams, UINT nSizeArgs);
	BYTE* StoreStackParameter(BYTE* pStack, BYTE nType,
		__in_z LPTSTR pszCurParam, UINT nSizeArgs, BOOL bDoShadow);
	BYTE* StoreRawStackParameter(BYTE* pStack, BYTE nType,
		BYTE* pRawParam, int nSizeArgs);
#else
	int PushDefaultStackArgs(BYTE* pStack,
		CHttpServerContext* pCtxt, const BYTE* pbParams,
		__in_z_opt LPTSTR lpszParams, AFX_PARSEMAP_ENTRY_PARAMS* pDefParams);
	int PushStackArgs(BYTE* pStack, CHttpServerContext* pCtxt,
		const BYTE* pbParams, __in_z_opt LPTSTR lpszParams);
	BYTE* StoreStackParameter(BYTE* pStack, BYTE nType, __in_z LPTSTR pszParam);
	BYTE* StoreRawStackParameter(BYTE* pStack, BYTE nType, BYTE* pRawParam);
#endif

	const TCHAR m_cTokenDelimiter;  // can't EVER change

	DECLARE_PARSE_MAP()
};

extern "C" BOOL WINAPI GetExtensionVersion(HSE_VERSION_INFO *pVer);
extern "C" DWORD WINAPI HttpExtensionProc(EXTENSION_CONTROL_BLOCK *pECB);

struct AFX_PARSEMAP_ENTRY
{
	LPTSTR          pszFnName;     // if default param entry, ptr to AFX_PARSEMAP_ENTRY_PARAMS
	AFX_PISAPICMD   pfn;           // NULL if default param entry
	LPCSTR          pszArgs;       // NULL if default function entry
	LPSTR           pszParamInfo;  // copy of pszArgs for parsing
};

///////////////////////////////////////////////////////////////////////
// Constants to describe parameter types

#define ITS_EMPTY           "\x06"      // no parameters
#define ITS_I2              "\x01"      // a 'short'
#define ITS_I4              "\x02"      // a 'long'
#define ITS_R4              "\x03"      // a 'float'
#define ITS_R8              "\x04"      // a 'double'
#define ITS_PSTR            "\x05"      // a 'LPCTSTR'
#define ITS_RAW             "\x07"      // exactly as received
#define ITS_I8              "\x08"      // an '_int64'
#define ITS_ARGLIST         "\x09"      // pointer to CHttpArgList

enum INETVARENUM
{
	IT_I2       = 1,
	IT_I4       = 2,
	IT_R4       = 3,
	IT_R8       = 4,
	IT_PSTR     = 5,
	IT_EMPTY    = 6,
	IT_RAW      = 7,
	IT_I8       = 8,
	IT_ARGLIST  = 9,
};

///////////////////////////////////////////////////////////////////////
// class to describe parameters as received

#ifndef _AFX
struct __POSITION { };
typedef __POSITION* POSITION;
#endif

struct CHttpArg
{
protected:
	// Implementation
	~CHttpArg();
	CHttpArg *m_pNext;
	friend class CHttpArgList;

	// Constructors
public:
	explicit CHttpArg(CHttpArg* pPrevious, LPCTSTR pstrRaw = NULL);

	// Attributes
	LPCTSTR m_pstrRaw;	// unparsed "param=value" string
	LPCTSTR m_pstrParam;	// parsed parameter name
	LPCTSTR m_pstrValue;	// parsed value for parameter
};

class CHttpArgList
{
public:
	static void Unescape(__in_z LPTSTR pstrChunk);

	// Operations

	// Get POSITION of first argument
	POSITION GetFirstArgPosition() const;

	// get pointer to argument and move POSITION to 
	// reference next argument
	CHttpArg* GetNextArg(POSITION& pos) const;

	// Implementation
public:
	~CHttpArgList();
	bool BuildArgList(__in_z LPTSTR psz, TCHAR cDelimiter);
	CHttpArgList();

protected:
	CHttpArg* m_pFirstArg;
};

///////////////////////////////////////////////////////////////////////
// Internet Information Server Entry Points

extern "C" DWORD WINAPI HttpFilterProc(PHTTP_FILTER_CONTEXT pfc,
	DWORD dwNotificationType, LPVOID pvNotification);

extern "C" BOOL WINAPI GetFilterVersion(PHTTP_FILTER_VERSION pVer);


///////////////////////////////////////////////////////////////////////
// Internet Information Server Filter Support

class CHttpFilterContext
{
public:
	CHttpFilterContext(PHTTP_FILTER_CONTEXT pfc);
	~CHttpFilterContext() { }

	BOOL GetServerVariable(__in_z LPTSTR lpszVariableName, __out_ecount_part(*lpdwSize, *lpdwSize) LPVOID lpvBuffer,
		__inout LPDWORD lpdwSize);
	BOOL AddResponseHeaders(__in_z LPTSTR lpszHeaders, DWORD dwReserved = 0);
	BOOL WriteClient(LPVOID lpvBuffer, LPDWORD lpdwBytes,
		DWORD dwReserved = 0);
	LPVOID AllocMem(DWORD cbSize, DWORD dwReserved = 0);
	BOOL ServerSupportFunction(enum SF_REQ_TYPE sfReq,
		LPVOID lpvBuffer, LPDWORD lpdwSize, LPDWORD lpdwDataType);

	PHTTP_FILTER_CONTEXT const m_pFC;
};


///////////////////////////////////////////////////////////////////////
//

class CHttpFilter
{
public:
	CHttpFilter();
	~CHttpFilter();

protected:

public:
	virtual DWORD HttpFilterProc(PHTTP_FILTER_CONTEXT pfc,
		DWORD dwNotificationType, LPVOID pvNotification);
	virtual BOOL GetFilterVersion(PHTTP_FILTER_VERSION pVer);

	virtual DWORD OnReadRawData(CHttpFilterContext* pfc, PHTTP_FILTER_RAW_DATA pRawData);
	virtual DWORD OnPreprocHeaders(CHttpFilterContext* pfc, PHTTP_FILTER_PREPROC_HEADERS pHeaders);
	virtual DWORD OnAuthentication(CHttpFilterContext* pfc, PHTTP_FILTER_AUTHENT pAuthent);
	virtual DWORD OnUrlMap(CHttpFilterContext* pfc, PHTTP_FILTER_URL_MAP pUrlMap);
	virtual DWORD OnSendRawData(CHttpFilterContext* pfc, PHTTP_FILTER_RAW_DATA pRawData);
	virtual DWORD OnLog(CHttpFilterContext* pfc, PHTTP_FILTER_LOG pLog);
	virtual DWORD OnEndOfNetSession(CHttpFilterContext* pfc);
	virtual DWORD OnEndOfRequest(CHttpFilterContext* pfc);
	virtual DWORD OnAuthComplete(CHttpFilterContext* pfc, PHTTP_FILTER_AUTH_COMPLETE_INFO pAuthComplInfo);
	virtual DWORD OnSendResponse(CHttpFilterContext*, PHTTP_FILTER_SEND_RESPONSE);
	virtual DWORD OnAccessDenied(CHttpFilterContext*, PHTTP_FILTER_ACCESS_DENIED);
};


/////////////////////////////////////////////////////////////////////////////
// Alternate debugging suppot

#include <malloc.h>
#include <crtdbg.h>

#ifdef _AFX
#define ISAPIASSERT(expr)                   ASSERT(expr)
#define ISAPITRACE                          TRACE
#define ISAPITRACE0(str)                    TRACE0(str)
#define ISAPITRACE1(str, arg1)              TRACE1(str, arg1)
#define ISAPITRACE2(str, arg1, arg2)        TRACE2(str, arg1, arg2)
#define ISAPITRACE3(str, arg1, arg2, arg3)  TRACE3(str, arg1, arg2, arg3)

#define ISAPIENSURE(expr)					do{ int __afx_condVal=!!(expr); ISAPIASSERT(__afx_condVal); if (!(__afx_condVal)) {AfxThrowInvalidArgException();}}while(false)

#else // !_AFX
#define ISAPIASSERT(expr)                   _ASSERTE(expr)
#define ISAPITRACE0(str)                    _RPT0(_CRT_WARN, str)
#define ISAPITRACE1(str, arg1)              _RPT1(_CRT_WARN, str, arg1)
#define ISAPITRACE2(str, arg1, arg2)        _RPT2(_CRT_WARN, str, arg1, arg2)
#define ISAPITRACE3(str, arg1, arg2, arg3)  _RPT3(_CRT_WARN, arg1, arg2, arg3)

#include <exception>

class CException {};
class CSimpleException : public CException {};
class CMemoryException : public CException {};
class CInvalidArgException : public CSimpleException {};

#define ISAPIENSURE(expr)					do{ int __afx_condVal=!!(expr); ISAPIASSERT(__afx_condVal); if (!(__afx_condVal)) { throw new CInvalidArgException(); }}while(false)

void AFXISAPI_CDECL AfxISAPITrace(LPCTSTR lpszFormat, ...);

#ifdef _DEBUG
#define ISAPITRACE                          AfxISAPITrace
#else
#define ISAPITRACE                          __noop
#endif // _DEBUG
#endif // _AFX

#ifdef _DEBUG
#define ISAPIVERIFY(expr)                   ISAPIASSERT(expr)
#else
#define ISAPIVERIFY(expr)                   ((void)(expr))
#endif

/////////////////////////////////////////////////////////////////////////////
// Inline function declarations

#ifdef _AFX_ENABLE_INLINES
#define _AFXISAPI_INLINE AFX_INLINE
#include <afxisapi.inl>
#endif

#undef AFX_DATA
#define AFX_DATA

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, on)
#endif
#ifndef _AFX_FULLTYPEINFO
#pragma component(mintypeinfo, off)
#endif

#ifdef _AFX_ALL_WARNINGS
#pragma warning( pop )
#endif

#endif // __AFXISAPI_H_
