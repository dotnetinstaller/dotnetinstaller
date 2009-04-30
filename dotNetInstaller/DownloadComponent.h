#pragma once

#include "DownloadCallback.h"
#include "Tools\Format.h"

//////////////////////////////////////////////////////////////////////
// Original class based on:
// Written by Michael Dunn (mdunn at inreach dot com).  Copyright and all
// that stuff.  Use however you like but give me credit where it's due.  I'll
// know if you don't. bwa ha ha ha ha!
// 
// Release history:
//   December 24, 1999: Version 1.0.  First release.
//////////////////////////////////////////////////////////////////////
class DownloadComponent : public IBindStatusCallback
{
private:
	IDownloadCallback * m_Callback;
	DownloadComponentInfo * m_Component;

	//solo per messaggi
	int m_CurrentComponent; 
	int m_TotalComponents;

	bool m_bCanceledByTheUser;
public:
	
	DownloadComponent(
		IDownloadCallback * p_Callback, 
		DownloadComponentInfo * p_Component, 
		int p_CurrentComponent, 
		int p_TotalComponents);

	inline bool IsCanceledByTheUser() { return m_bCanceledByTheUser; }

	// returns true if a download is required (local file doesn't exist, etc.)
	bool IsDownloadRequired() const;
	// returns true if a local copy from source path is required (or possible)
	bool IsCopyRequired() const;
	// destination filename
	CString GetDestinationFileName() const;

	// IBindStatusCallback methods.  Note that the only method called by IE
	// is OnProgress(), so the others just return E_NOTIMPL.
	STDMETHOD(OnStartBinding)(
		/* [in] */ DWORD dwReserved,
		/* [in] */ IBinding __RPC_FAR *pib)
		{ return E_NOTIMPL; }

	STDMETHOD(GetPriority)(
		/* [out] */ LONG __RPC_FAR *pnPriority)
		{ return E_NOTIMPL; }

	STDMETHOD(OnLowResource)(
		/* [in] */ DWORD reserved)
		{ return E_NOTIMPL; }

	STDMETHOD(OnProgress)(
		/* [in] */ ULONG ulProgress,
		/* [in] */ ULONG ulProgressMax,
		/* [in] */ ULONG ulStatusCode,
		/* [in] */ LPCWSTR wszStatusText)
	{
		// Did the user hit the Stop button?
		if ( m_Callback->WantToStop() )
		{
			m_bCanceledByTheUser = true;
			return E_ABORT;
		}

		CString tmp;
		tmp.Format(TEXT("%s (%s of %s) - %d/%d"), m_Component->ComponentName, FormatNumberToBytes(ulProgress), FormatNumberToBytes(ulProgressMax), m_CurrentComponent, m_TotalComponents );

		m_Callback->Status(ulProgress, ulProgressMax, tmp);

		return S_OK;
	}

	STDMETHOD(OnStopBinding)(
		/* [in] */ HRESULT hresult,
		/* [unique][in] */ LPCWSTR szError)
		{ return E_NOTIMPL; }

	STDMETHOD(GetBindInfo)(
		/* [out] */ DWORD __RPC_FAR *grfBINDF,
		/* [unique][out][in] */ BINDINFO __RPC_FAR *pbindinfo)
		{ return E_NOTIMPL; }

	STDMETHOD(OnDataAvailable)(
		/* [in] */ DWORD grfBSCF,
		/* [in] */ DWORD dwSize,
		/* [in] */ FORMATETC __RPC_FAR *pformatetc,
		/* [in] */ STGMEDIUM __RPC_FAR *pstgmed)
		{ return E_NOTIMPL; }

	STDMETHOD(OnObjectAvailable)(
		/* [in] */ REFIID riid,
		/* [iid_is][in] */ IUnknown __RPC_FAR *punk)
		{ return E_NOTIMPL; }

	// IUnknown methods.  Note that IE never calls any of these methods, since
	// the caller owns the IBindStatusCallback interface, so the methods all
	// return zero/E_NOTIMPL.
	STDMETHOD_(ULONG,AddRef)()
		{ return 0; }

	STDMETHOD_(ULONG,Release)()
		{ return 0; }

	STDMETHOD(QueryInterface)(
	/* [in] */ REFIID riid,
	/* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject)
		{ return E_NOTIMPL; }

	// Download the specified component.
	void StartDownload();
	// Copy the component from SourcePath.
	void CopyFromSourcePath();
};

UINT DownloadComponents(IDownloadCallback * p_Callback);
UINT DownloadComponentsThread( LPVOID pParam );
