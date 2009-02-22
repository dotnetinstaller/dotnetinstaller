#include "StdAfx.h"
#include "Component.h"
#include "DownloadDialog.h"
#include "InstalledCheck.h"

Component::Component()
    : m_pDialog(NULL)
    , type(msi)
    , mustreboot(false)
    , cancelled(false)
    , required(true)
    , ContainsDownloadComponent(false)
    , selected(false)
{

}

Component::~Component(void)
{

}

bool Component::DownloadComponents(CWnd * p_Parent)
{
	try
	{
		if (ContainsDownloadComponent)
        {
			return RunDownloadDialog(DownloadDialogConfiguration, p_Parent);
        }
		else
        {
			return true;
        }
	}
	catch(std::exception&)
	{
		return false;
	}
}

void Component::Init(CDialog * pDialog)
{
    m_pDialog = pDialog;
    cancelled = false;
}

bool Component::IsInstalled()
{
	if (installedchecks.size() == 0)
		return false;

	bool l_installed = true;
	
    for (size_t j = 0; j < installedchecks.size(); j++)
	{
		l_installed &= installedchecks[j]->IsInstalled();
	}

	return l_installed;
}
