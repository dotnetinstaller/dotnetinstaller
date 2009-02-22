#include "DownloadDialogSupport.h"

namespace DVLib
{
	UINT DownloadComponents(IDownloadCallback * p_Callback)
	{
		CString l_tmpLastComponent = "-";
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
		catch(...)
		{
			try
			{
				CString tmp = "Failed to download component: ";
				tmp += l_tmpLastComponent;
				p_Callback->DownloadError(tmp);
			}
			catch(...)
			{
				_ASSERT(false);
			}
		}

		return 0;
	}

	UINT DownloadComponentsThread( LPVOID pParam )
	{
		return DownloadComponents((IDownloadCallback*)pParam);
	}
}