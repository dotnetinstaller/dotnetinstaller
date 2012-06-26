// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// Inlines for AFXISAPI.H

#ifdef _AFXISAPI_INLINE

_AFXISAPI_INLINE CHttpServerContext::CHttpServerContext(EXTENSION_CONTROL_BLOCK* pECB)
#ifdef _DEBUG
	: m_dwStatusCode(DWORD(-1)), m_bSendHeaders(TRUE), m_pECB(pECB), 
	  m_pStream(NULL), m_dwEndOfHeaders(0), m_dwOldEndOfHeaders(0),
	  m_dwChunkSize(0), m_pArgList(NULL)
#else
	: m_dwStatusCode(DWORD(-1)), m_bSendHeaders(TRUE), m_pECB(pECB),
	  m_pStream(NULL), m_dwEndOfHeaders(0), m_dwChunkSize(0), m_pArgList(NULL)
#endif
	{
		ISAPIENSURE(NULL != pECB);
	}

_AFXISAPI_INLINE CHttpServerContext::~CHttpServerContext()
	{ delete m_pStream; delete m_pArgList; }

_AFXISAPI_INLINE CHttpServerContext& CHttpServerContext::operator<<(double d)
	{	ISAPIENSURE(m_pStream != NULL);
		*m_pStream << d;
		return *this; }

_AFXISAPI_INLINE CHttpServerContext& CHttpServerContext::operator<<(float f)
	{	ISAPIENSURE(m_pStream != NULL);
		*m_pStream << f;
		return *this; }

_AFXISAPI_INLINE CHttpServerContext& CHttpServerContext::operator<<(long int dw)
	{	ISAPIENSURE(m_pStream != NULL);
		*m_pStream << dw;
		return *this; }

_AFXISAPI_INLINE CHttpServerContext& CHttpServerContext::operator<<(short int w)
	{	ISAPIENSURE(m_pStream != NULL);
		*m_pStream << w;
		return *this; }

_AFXISAPI_INLINE CHttpServerContext& CHttpServerContext::operator<<(const CHtmlStream& stream)
	{	ISAPIENSURE(m_pStream != NULL);
		*m_pStream << stream;
		return *this; }

_AFXISAPI_INLINE CHttpServerContext& CHttpServerContext::operator<<(LPCTSTR psz)
	{	ISAPIENSURE(m_pStream != NULL && psz != NULL);
		*m_pStream << psz;
		return *this; }

_AFXISAPI_INLINE BOOL CHttpServerContext::GetServerVariable(__in_z LPTSTR lpszVariableName,
		__out_ecount_part(*lpdwSize, *lpdwSize) LPVOID lpvBuffer, __inout LPDWORD lpdwSize)
	{
		ISAPIENSURE(m_pECB != NULL);
		return m_pECB->GetServerVariable(m_pECB->ConnID,
			lpszVariableName, lpvBuffer, lpdwSize);
	}

_AFXISAPI_INLINE BOOL CHttpServerContext::WriteClient(LPVOID pBuffer, LPDWORD lpdwBytes,
	DWORD dwReserved /* = 0 */)
	{
		ISAPIENSURE(m_pECB != NULL);
		return m_pECB->WriteClient(m_pECB->ConnID, pBuffer,
			lpdwBytes, dwReserved);
	}

_AFXISAPI_INLINE BOOL CHttpServerContext::ReadClient(LPVOID lpvBuffer, LPDWORD lpdwSize)
	{
		ISAPIENSURE(m_pECB != NULL);
		return m_pECB->ReadClient(m_pECB->ConnID, lpvBuffer, lpdwSize);
	}

_AFXISAPI_INLINE BOOL CHttpServerContext::ServerSupportFunction(DWORD dwHSERRequest,
		LPVOID lpvBuffer, LPDWORD lpdwSize, LPDWORD lpdwDataType)
	{
		ISAPIENSURE(m_pECB != NULL);
		return m_pECB->ServerSupportFunction(m_pECB->ConnID, dwHSERRequest,
			lpvBuffer, lpdwSize, lpdwDataType);
	}

_AFXISAPI_INLINE CHttpArgList::CHttpArgList()
	: m_pFirstArg(NULL)
	{ }

_AFXISAPI_INLINE CHttpArg::~CHttpArg()
	{ free((void*) m_pstrRaw); free((void*) m_pstrParam); }


_AFXISAPI_INLINE POSITION CHttpArgList::GetFirstArgPosition() const
	{ return (POSITION) m_pFirstArg; }

_AFXISAPI_INLINE CHttpArg* CHttpArgList::GetNextArg(POSITION& pos) const
	{
		ISAPIENSURE(pos != NULL);
		CHttpArg* pArg = (CHttpArg*) pos;
		pos = (POSITION) pArg->m_pNext;
		return pArg;
	}


_AFXISAPI_INLINE DWORD CHtmlStream::GetStreamSize() const
	{ return m_nStreamSize; }

_AFXISAPI_INLINE CHttpFilterContext::CHttpFilterContext(PHTTP_FILTER_CONTEXT pCtx)
	: m_pFC(pCtx)
	{
		ISAPIENSURE(NULL != pCtx);
	}

_AFXISAPI_INLINE BOOL CHttpFilterContext::GetServerVariable(__in_z LPTSTR lpszVariableName,
		__out_ecount_part(*lpdwSize, *lpdwSize) LPVOID lpvBuffer, __inout LPDWORD lpdwSize)
	{
		ISAPIENSURE(m_pFC != NULL);
		return m_pFC->GetServerVariable(m_pFC, lpszVariableName, lpvBuffer, lpdwSize);
	}
_AFXISAPI_INLINE BOOL CHttpFilterContext::AddResponseHeaders(__in_z LPTSTR lpszHeaders,
		__in DWORD dwReserved /* = 0 */)
	{
		ISAPIENSURE(m_pFC != NULL);
		return m_pFC->AddResponseHeaders(m_pFC, lpszHeaders, dwReserved);
	}
_AFXISAPI_INLINE BOOL CHttpFilterContext::WriteClient(LPVOID lpvBuffer,
		LPDWORD lpdwBytes, DWORD dwReserved /* = 0 */)
	{
		ISAPIENSURE(m_pFC != NULL);
		return m_pFC->WriteClient(m_pFC, lpvBuffer, lpdwBytes, dwReserved);
	}
_AFXISAPI_INLINE LPVOID CHttpFilterContext::AllocMem(DWORD cbSize,
		DWORD dwReserved /* = 0 */)
	{
		ISAPIENSURE(m_pFC != NULL);
		return m_pFC->AllocMem(m_pFC, cbSize, dwReserved);
	}
_AFXISAPI_INLINE BOOL CHttpFilterContext::ServerSupportFunction(enum SF_REQ_TYPE sfReq,
		LPVOID lpvBuffer, LPDWORD lpdwSize, LPDWORD lpdwDataType)
	{
		ISAPIENSURE(m_pFC != NULL);
		return m_pFC->ServerSupportFunction(m_pFC, sfReq, lpvBuffer,
			(DWORD_PTR) lpdwSize, (DWORD_PTR) lpdwDataType);
	}


#endif // _AFXISAPI_INLINE
