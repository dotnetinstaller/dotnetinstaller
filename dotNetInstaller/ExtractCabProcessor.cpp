#include "StdAfx.h"
#include "ExtractCabProcessor.h"
#include "InstallComponentDlg.h"
#include "Resource.h"

ExtractCabProcessor::ExtractCabProcessor(HMODULE h, CDialog * pDialog)
    : ExtractComponent(h)
	, m_pDialog(pDialog)
{

}

void ExtractCabProcessor::OnStatus(const std::wstring& status)
{
	if (m_pDialog != NULL && m_pDialog->GetSafeHwnd() != NULL)
	{
        m_pDialog->PostMessage(WM_USER_SETSTATUSINSTALL, 
            (WPARAM) release(InstallStatus::CreateStatus(status)));
	}
}
