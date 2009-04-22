#include "StdAfx.h"
#include "DownloadGroupConfiguration.h"
#include "DownloadDialog.h"

DownloadGroupConfiguration::DownloadGroupConfiguration()
	: AutoStartDownload(true)
{

}

bool DownloadGroupConfiguration::Run(CWnd * p_Parent)
{
	DownloadDialog l_dgDownload(* this, p_Parent);
	
	if (! l_dgDownload.IsDownloadRequired())
		return true;

	l_dgDownload.DoModal();
	return l_dgDownload.IsDownloadCompleted();
}
