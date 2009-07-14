#include "StdAfx.h"
#include "ExtractCAB.h"
#include "InstallComponentDlg.h"
#include "Resource.h"

ExtractCABProcessor::ExtractCABProcessor(HMODULE h, CDialog * pDialog)
    : ExtractComponent(h)
	, m_pDialog(pDialog)
{

}

void ExtractCABProcessor::OnStatus(const std::wstring& status)
{
	if (m_pDialog != NULL && m_pDialog->GetSafeHwnd() != NULL)
	{
        m_pDialog->PostMessage(WM_USER_SETSTATUSINSTALL, 
            (WPARAM) InstallStatusParam::CreateStatus(status));
	}
}
