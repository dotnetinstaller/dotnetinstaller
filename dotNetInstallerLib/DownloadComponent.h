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
	DownloadComponentInfoPtr m_pComponent;
	int m_CurrentComponent;
	int m_TotalComponents;
	void DownloadFromSourceUrl();
	void CopyFromSourcePath();
public:	
	DownloadComponent(
		IDownloadCallback * callback, 
		DownloadComponentInfoPtr componentinfo, 
		int p_CurrentComponent = 0, 
		int p_TotalComponents = 1);
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
	// execute
	void Exec();
	// properties
	bool IsCopyRequired() const { return m_pComponent->IsCopyRequired(); }
	bool IsDownloadRequired() const { return m_pComponent->IsDownloadRequired(); }
	std::wstring GetDestinationFileName() const { return m_pComponent->GetDestinationFileName(); }
};

typedef shared_any<DownloadComponent *, close_delete> DownloadComponentPtr;
