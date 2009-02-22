#include "StdAfx.h"
#include "DownloadDialogSupport.h"

namespace DVLib
{
	// Custom method
	//Download the specified component.
    void DownloadComponent::StartDownload()
	{
		CString l_destinationFullFileName;
		if (m_Component->DestinationFileName.GetLength() <= 0)
			l_destinationFullFileName = DVLib::PathCombineCustom(m_Component->DestinationPath, 
																 DVLib::GetFileNameFromFullFilePath(m_Component->SourceURL));
		else
			l_destinationFullFileName = DVLib::PathCombineCustom(m_Component->DestinationPath, 
																 m_Component->DestinationFileName);


		CreateDirectory(m_Component->DestinationPath,NULL); //cerco comunque di creare la directory

		//
		// Charles McDonald: 2008-06-19: Added some descriptive logging and made sure the underlying
		// call to FileExistsCustom deals with quoted paths correctly.  If the download dialog does
		// get displayed when it shouldn't the log messages provide enough information so you can debug
		// your process.
		ApplicationLog.Write( TEXT("DestinationPath: "), m_Component->DestinationPath);

		//
		// We need to make sure the destination path works with CABing.
		ApplicationLog.Write( TEXT("DestinationFullFileName: "), l_destinationFullFileName);
		CString alwaysDownloadToString = (m_Component->AlwaysDownload ? _T("True") : _T("False"));
		ApplicationLog.Write( TEXT("AlwaysDownload: "), alwaysDownloadToString);

		BOOL fileExists = FileExistsCustom(l_destinationFullFileName);
		CString fileExistsToString = (fileExists ? _T("True") : _T("False"));
		ApplicationLog.Write( TEXT("FileExists: "), fileExistsToString);

		// Matthew Sheets - 2007-08-10: Determine if the download dialog should be displayed
		if (m_Component->AlwaysDownload || !fileExists)
		{
			HRESULT l_hrRet = URLDownloadToFile(NULL, m_Component->SourceURL, l_destinationFullFileName, 0, this);
			if (! SUCCEEDED(l_hrRet))
            {
                std::string error = "Error downloading ";
                error.append(DVLib::Tstring2string(m_Component->SourceURL));
                throw std::exception(error.c_str());
            }
		}
	}

	UINT DownloadComponents(IDownloadCallback * p_Callback)
	{
		CString l_tmpLastComponent = TEXT("-");
		try
		{
			DownloadComponentInfoVector * l_List = p_Callback->GetComponents();
			for (int i = 0; i < l_List->GetCount(); i++)
			{
				//verifico se l'utente ha premuto cancel
				if (p_Callback->WantToStop())
				{
					p_Callback->CanceledByTheUser();
					return 0;
				}

				l_tmpLastComponent = l_List->GetAt(i).ComponentName;

				//Download del componente
				DownloadComponent l_Component(p_Callback, &(l_List->GetAt(i)), i+1, (int)l_List->GetCount() );
				l_Component.StartDownload();


				//verifico se l'utente ha premuto cancel
				if (l_Component.IsCanceledByTheUser())
				{
					p_Callback->CanceledByTheUser();
					return 0;
				}
			}

			p_Callback->DownloadComplete();
		}
		catch(std::exception&)
		{
		    p_Callback->DownloadError(TEXT("Failed to download component: ") + l_tmpLastComponent);
		}

		return 0;
	}

	UINT DownloadComponentsThread( LPVOID pParam )
	{
		return DownloadComponents((IDownloadCallback*)pParam);
	}
}
