#pragma once

#include "DownloadCallback.h"

class DownloadFile : public IBindStatusCallback
{
public:
	IDownloadCallback * callback;
	// download url
	std::wstring sourceurl;
	// optional local location for the file
	std::wstring sourcepath;
	// destination path
	std::wstring destinationpath;
	// destination filename
	std::wstring destinationfilename;
	// component name
	std::wstring componentname;
    // enable bypassing download if the file already exists locally
	bool alwaysdownload;
public:
	// returns true if a download is required (local file doesn't exist, etc.)
	bool IsDownloadRequired() const;
	// returns true if a local copy from source path is required (or possible)
	bool IsCopyRequired() const;
	std::wstring GetDestinationFileName() const;
	DownloadFile();
	virtual ~DownloadFile();
	void Load(TiXmlElement * node);
	void Exec(IDownloadCallback * callback);
public:
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
private:
	void CopyFromSourcePath();
	void DownloadFromSourceUrl();
};

typedef shared_any<DownloadFile *, close_delete> DownloadFilePtr;
