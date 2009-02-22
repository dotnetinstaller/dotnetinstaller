#pragma once

#include <afxtempl.h>

#include <Urlmon.h> //IBindStatusCallback
#include "File.h"
#include "Format.h"

namespace DVLib
{
	struct DownloadComponentInfo
	{
		//URL del file da scaricare
		CString SourceURL;

		//Directory di destinazione (senza il nome del file)
		CString DestinationPath;

		//File di destinazione (se vuoto il nome del file viene reperito dal campo SourceURL)
		CString DestinationFileName;

		////Indica se scaricare sempre il componente anche se si trova già nella directory di destinazione
		//bool ForceDownload;

		//Nome visivo del componente
		CString ComponentName;

        // Matthew Sheets - 2007-08-28: added flag to enable bypassing download if the file already exists locally
		bool AlwaysDownload;
	};

	typedef CArray<DownloadComponentInfo> DownloadComponentInfoVector;


	struct DownloadGroupConfiguration
	{
		//caption della finestra di download
		CString Caption;
		
		//messaggio visualizzato nella finestra di download prima che il download cominci (o perchè l'utente preme il tasto Start o perchè è impostato autodownload)
		CString HelpMessage;

		//messaggio visualizzato nella finestra di download quando il download è in corso
		CString HelpMessageDownloading;

		//Testo del bottone di start
		CString ButtonStartCaption;

		//Testo del bottone di Cancel
		CString ButtonCancelCaption;

		//Elenco componenti da scaricare
		DownloadComponentInfoVector Components;

		//Indica se iniziare automaticamente il download appena la finestra viene aperta
		bool AutoStartDownload;
	};

	class IDownloadCallback
	{
	public:
		virtual void Status(ULONG p_CurrentProgress, ULONG p_MaxProgress, LPCTSTR p_Description) = 0;
		virtual void DownloadComplete() = 0;
		virtual void DownloadError(LPCTSTR p_Message) = 0;
		virtual bool WantToStop() = 0;
		virtual void CanceledByTheUser() = 0;
		virtual DownloadComponentInfoVector * GetComponents() = 0;
	};



	//////////////////////////////////////////////////////////////////////
	// Original class based on:
	// Written by Michael Dunn (mdunn at inreach dot com).  Copyright and all
	// that stuff.  Use however you like but give me credit where it's due.  I'll
	// know if you don't. bwa ha ha ha ha!
	// 
	// Release history:
	//   December 24, 1999: Version 1.0.  First release.
	//
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
		
		DownloadComponent(IDownloadCallback * p_Callback, 
						DownloadComponentInfo * p_Component, 
						int p_CurrentComponent, 
						int p_TotalComponents):
							m_bCanceledByTheUser(false)
		{
			m_Callback = p_Callback;
			m_Component = p_Component;

			m_CurrentComponent = p_CurrentComponent;
			m_TotalComponents = p_TotalComponents;
		}

		inline bool IsCanceledByTheUser()
		{
			return m_bCanceledByTheUser;
		}

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


		// Custom method
		//Download the specified component. Throw an HRESULT for errors.
		inline void StartDownload()
		{
			CString l_destinationFullFileName;
			if (m_Component->DestinationFileName.GetLength() <= 0)
				l_destinationFullFileName = DVLib::PathCombineCustom(m_Component->DestinationPath, 
																		DVLib::GetFileNameFromFullFilePath(m_Component->SourceURL));
			else
				l_destinationFullFileName = DVLib::PathCombineCustom(m_Component->DestinationPath, 
																		m_Component->DestinationFileName);
			
			CreateDirectory(m_Component->DestinationPath,NULL); //cerco comunque di creare la directory

			// Matthew Sheets - 2007-08-10: Determine if the download dialog should be displayed
			if (m_Component->AlwaysDownload || (!FileExistsCustom(l_destinationFullFileName)))
			{
				HRESULT l_hrRet = URLDownloadToFile(NULL, m_Component->SourceURL, l_destinationFullFileName, 0, this);
				if (!SUCCEEDED(l_hrRet))
					throw l_hrRet;
			}
		}
	};

	UINT DownloadComponents(IDownloadCallback * p_Callback);
	UINT DownloadComponentsThread( LPVOID pParam );
}