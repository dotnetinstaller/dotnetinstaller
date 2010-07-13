#include "StdAfx.h"
#include "InstallerWindow.h"
#include "ConfigFileManager.h"

InstallerWindow::InstallerWindow(void)
{

}

void InstallerWindow::Create(int x, int y, int width, int height, const wchar_t * caption)
{
	HtmlWindow::Create(x, y, width, height, caption);
	htmlayout::dom::element r = GetRoot();

	components = r.get_element_by_id("components");
	CHECK_BOOL(components.is_valid(),
		L"Missing widget with id='components' in HTML");
}

bool InstallerWindow::RunInstallConfiguration(DVLib::LcidType lcidtype, const ConfigurationPtr& configuration, bool additional_config)
{
	m_configuration = configuration;
	m_lcidtype = lcidtype;
	m_additional_config = additional_config;
	DoModal();
	// return(IDOK == this->DoModal());
	return true;
}

void InstallerWindow::DoModal()
{
	// remove the Run key if exist
	InstallerSession::Instance->DisableRunOnReboot();

	// os label
	htmlayout::dom::element r = GetRoot();
	htmlayout::dom::element os = r.get_element_by_id("os");
	if (os.is_valid())
	{
		os.set_text((DVLib::GetOperatingSystemVersionString() + L" (" + 
			DVLib::pa2wstring(DVLib::GetProcessorArchitecture()) + L")").c_str());
	}

	// load xml file
	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

	// load components

	bool all = LoadComponentsList();

	if (InstallerSession::Instance->sequence == SequenceInstall && all && p_configuration->supports_uninstall)
	{
		LOG("All components installed, switching to uninstall.");
		InstallerSession::Instance->sequence = SequenceUninstall;
		all = LoadComponentsList();
		if (all)
		{
			LOG("All components uninstalled, nothing to do.");
			InstallerSession::Instance->sequence = SequenceInstall;
		}
	}

	// labels and info
	htmlayout::dom::element dialog_message = r.get_element_by_id("dialog_message");
	switch(InstallerSession::Instance->sequence)
	{
	case SequenceInstall:
		// m_btnInstall.SetWindowText(p_configuration->install_caption.GetValue().c_str());
		if (dialog_message.is_valid()) dialog_message.set_text(p_configuration->dialog_message.GetValue().c_str());
		break;
	case SequenceUninstall:
		// m_btnInstall.SetWindowText(p_configuration->uninstall_caption.GetValue().c_str());
		if (dialog_message.is_valid()) dialog_message.set_text(p_configuration->dialog_message_uninstall.GetValue().c_str());
		break;
	}

	ShowWindow(hwnd, 1);

	CHECK_WIN32_BOOL(UpdateWindow(hwnd),
		L"UpdateWindow");
}

bool InstallerWindow::RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration)
{
	return false;
}

// returns true if all components have been installed
bool InstallerWindow::LoadComponentsList()
{
	InstallConfiguration * pConfiguration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(pConfiguration != NULL, L"Invalid configuration");	

	bool all = true;

	// ResetContent();

	Components components_list = pConfiguration->GetSupportedComponents(
		m_lcidtype, InstallerSession::Instance->sequence);

	for (size_t i = 0; i < components_list.size(); i++)
	{
		ComponentPtr component(components_list[i]);
		component->checked = true;
        bool component_installed = component->IsInstalled();
        
        LOG(L"-- " << component->id << L" (" << component->GetDisplayName() << L"): " 
			<< (component_installed ? L"INSTALLED" : L"NOT INSTALLED"));		

		// component selection
		if (component_installed && InstallerSession::Instance->sequence == SequenceInstall)
			component->checked = false;
		if (! component_installed && InstallerSession::Instance->sequence == SequenceUninstall)
			component->checked = false;

		if (InstallerSession::Instance->sequence == SequenceInstall)
			all &= component_installed;
		else if (InstallerSession::Instance->sequence == SequenceUninstall)
			all &= (! component_installed);

		std::wstring l_descr = component->GetDisplayName();
	    l_descr += L" ";
        l_descr += component_installed
			? (component->status_installed.empty() ? pConfiguration->status_installed : component->status_installed)
			: (component->status_notinstalled.empty() ? pConfiguration->status_notinstalled : component->status_notinstalled);

		// show installed
        if (InstallerSession::Instance->sequence == SequenceInstall 
			&& ! pConfiguration->dialog_show_installed 
			&& component_installed)
            continue;

		// show uninstalled
        if (InstallerSession::Instance->sequence == SequenceUninstall 
			&& ! pConfiguration->dialog_show_uninstalled
			&& ! component_installed)
            continue;

        if (! pConfiguration->dialog_show_required)
		{
			if (component->required_install && InstallerSession::Instance->sequence == SequenceInstall)
				continue;
			else if (component->required_uninstall && InstallerSession::Instance->sequence == SequenceUninstall)
				continue;
		}

		htmlayout::dom::element opt = htmlayout::dom::element::create("widget", l_descr.c_str());
		opt["type"] = L"checkbox";
		opt["id"] = component->id.GetValue().c_str();

        if (component->checked)
        {
			if (component->selected_install && InstallerSession::Instance->sequence == SequenceInstall)
				opt["checked"] = L"true";
			else if (component->selected_uninstall && InstallerSession::Instance->sequence == SequenceUninstall)
				opt["checked"] = L"true";
        }

        // a component is considered installed when it has an install check which results
        // in a clear positive; if a component doesn't have any install checks, it cannot
        // be required (there's no way to check whether the component was installed)
        if (InstallerSession::Instance->sequence == SequenceInstall 
			&& (component->required_install || component_installed))
            opt["disabled"] = L"true";
        else if (InstallerSession::Instance->sequence == SequenceUninstall 
			&& (component->required_uninstall || ! component_installed))
            opt["disabled"] = L"true";

		components.insert(opt, i + 1);
    }

	return all;
}
