#pragma once

#include "DownloadCallback.h"

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
	DownloadComponentInfo m_Component;
	int m_CurrentComponent; 
	int m_TotalComponents;
	bool m_bCancel;
public:	
	DownloadComponent(
		IDownloadCallback * callback, 
		const DownloadComponentInfo& component, 
		int p_CurrentComponent = 0, 
		int p_TotalComponents = 1);
	inline bool IsCancelled() { return m_bCancel; }
	// returns true if a download is required (local file doesn't exist, etc.)
	bool IsDownloadRequired() const;
	// returns true if a local copy from source path is required (or possible)
	bool IsCopyRequired() const;
	// destination filename
	std::wstring GetDestinationFileName() const;
	// IBindStatusCallback
	STDMETHOD(OnStartBinding)(DWORD dwReserved, IBinding __RPC_FAR *pib);
	STDMETHOD(GetPriority)(LONG __RPC_FAR *pnPriority);
	STDMETHOD(OnLowResource)(DWORD reserved);
	STDMETHOD(OnProgress)(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR wszStatusText);
	STDMETHOD(OnStopBinding)(HRESULT hresult, LPCWSTR szError);
	STDMETHOD(GetBindInfo)(DWORD __RPC_FAR *grfBINDF, BINDINFO __RPC_FAR *pbindinfo);
	STDMETHOD(OnDataAvailable)(DWORD grfBSCF, DWORD dwSize, FORMATETC __RPC_FAR *pformatetc, STGMEDIUM __RPC_FAR *pstgmed);
	STDMETHOD(OnObjectAvailable)(REFIID riid, IUnknown __RPC_FAR *punk);
	// IUnknown
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();
	STDMETHOD(QueryInterface)(REFIID riid, void __RPC_FAR *__RPC_FAR *ppvObject);
	// Download the specified component.
	void StartDownload();
	// Copy the component from SourcePath.
	void CopyFromSourcePath();
};
