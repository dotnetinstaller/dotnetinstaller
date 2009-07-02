#include "StdAfx.h"
#include "Component.h"
#include "InstalledCheck.h"

Component::Component()
    : m_pDialog(NULL)
    , type(msi)
    , mustreboot(false)
    , must_reboot_required(false)
    , allow_continue_on_error(true)
    , cancelled(false)
    , required(true)
    , download(false)
    , selected(true)
{

}

Component::~Component(void)
{
	for (size_t j = 0; j < installedchecks.size(); j++)
	{
		delete installedchecks[j];
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

