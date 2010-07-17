#include "StdAfx.h"
#include "InstallerWindow.h"
#include "ConfigFileManager.h"
#include "ExtractCabProcessor.h"
#include "HtmlWidgets.h"

InstallerWindow::InstallerWindow(void)
	: m_reboot(false)
	, m_recorded_error(0)
	, m_additional_config(false)
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

	// status
	status = r.get_element_by_id("status");

	// error
	error = r.get_element_by_id("error");
	ClearError();

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
	if (dialog_message.is_valid()) 
	{
		dialog_message.set_text(InstallerSession::Instance->sequence == SequenceInstall 
			? p_configuration->dialog_message.GetValue().c_str()
			: p_configuration->dialog_message_uninstall.GetValue().c_str());
	}

	button_install = r.get_element_by_id("button_install");
	if (button_install.is_valid()) 
	{
		button_install.set_attribute("value", p_configuration->install_caption.GetValue().c_str());
		if (InstallerSession::Instance->sequence != SequenceInstall) button_install.destroy();
	}

	button_uninstall = r.get_element_by_id("button_uninstall");
	if (button_uninstall.is_valid()) 
	{
		button_uninstall.set_attribute("value", p_configuration->uninstall_caption.GetValue().c_str());
		if (InstallerSession::Instance->sequence != SequenceUninstall) button_uninstall.destroy();
	}

	button_skip = r.get_element_by_id("button_skip");
	if (button_skip.is_valid()) 
	{
		button_skip.set_attribute("value", p_configuration->skip_caption.GetValue().c_str());
		// todo: show with additional config
		button_skip.destroy();
	}

	button_cancel = r.get_element_by_id("button_cancel");
	if (button_cancel.is_valid()) 
	{
		button_cancel.set_attribute("value", p_configuration->cancel_caption.GetValue().c_str());
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

	ResetContent();

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
		opt["component_ptr"] = DVLib::towstring(get(component)).c_str();

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

BOOL InstallerWindow::on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason)
{
	htmlayout::dom::element target_element = target;
	if (type == BUTTON_CLICK && button_cancel == target_element)
	{
		OnOK();
		return TRUE;
	}
	else if (type == BUTTON_CLICK && button_install == target_element)
	{
		OnInstall();
		return TRUE;
	}
	else 
	{
		const wchar_t * component_ptr = target_element.get_attribute("component_ptr");
		if (component_ptr != NULL)
		{
			Component * p_component = reinterpret_cast<Component *>(DVLib::wstring2long(component_ptr, 16));
			p_component->checked = target_element.get_state(STATE_CHECKED);
		}
	}

	return HtmlWindow::on_event(he, target, type, reason);
}

void InstallerWindow::OnOK()
{
	::PostMessage(hwnd, WM_CLOSE, 0,0);
}

void InstallerWindow::OnInstall()
{
	try
	{
		auto_any<htmlayout::dom::element *, html_disabled> btn_install(& button_install);
		button_install.set_attribute("disabled", L"disabled");
		auto_any<htmlayout::dom::element *, html_disabled> btn_cancel(& button_cancel);
		button_cancel.set_attribute("disabled", L"disabled");
		auto_any<htmlayout::dom::element *, html_disabled> btn_skip(& button_skip);
		button_skip.set_attribute("disabled", L"disabled");
	
		ClearError();

		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

		Components components = p_configuration->GetSupportedComponents(
			m_lcidtype, InstallerSession::Instance->sequence);

		int rc = components.Exec(this);

		if (rc != 0)
		{
			RecordError(rc);
		}

		if (m_reboot)
		{
			InstallerSession::Instance->EnableRunOnReboot(p_configuration->reboot_cmd);
			DVLib::ExitWindowsSystem(EWX_REBOOT);
			PostQuitMessage(ERROR_SUCCESS_REBOOT_REQUIRED);
			return;
		}

		// silent execution, 
		if (InstallUILevelSetting::Instance->IsSilent()) 
		{
			OnOK();
			return;
		}

		// failure and auto-close-on-error
		if (rc != 0 && p_configuration->auto_close_on_error)
		{
			LOG(L"*** Failed to install one or more components, closing (auto_close_on_error).");
			OnOK();
			return;
		}

		// failure and reload-on-error
		if (rc != 0 && p_configuration->reload_on_error)
		{
			LOG(L"*** Failed to install one or more components, reloading components (reload_on_error).");
			LoadComponentsList();
			return;
		}

		// success and possibly auto-close with a complete code if all components have been installed
		if (rc == 0)
		{
			bool all = LoadComponentsList();
			if (all || p_configuration->auto_close_if_installed) 
			{
				// ExecuteCompleteCode(true);
				OnOK();
			}
		}
    }
    catch(std::exception& ex)
    {
		LOG(L"*** Failed to install one or more components: " << DVLib::string2wstring(ex.what()));
		ShowError(DVLib::string2wstring(ex.what()));
		RecordError();
    }
	catch(...)
	{
		LOG(L"*** Failed to install one or more components");
		ShowError(TEXT("Failed to install one or more components"));
		RecordError();
	}
}

void InstallerWindow::ShowError(const std::wstring& message)
{
	if (error.is_valid()) 
	{
		error.clear_style_attribute("display");
		error.set_text(message.c_str());
	} 
	else 
	{
		DniMessageBox::Show(message, MB_OK | MB_ICONSTOP);
	}
}

void InstallerWindow::RecordError(int error) 
{ 
	if (m_recorded_error == 0) 
	{
		m_recorded_error = error; 
	}
}

void InstallerWindow::ClearError() 
{ 
	m_recorded_error = 0; 
	if (error.is_valid()) 
	{
		error.set_style_attribute("display", L"none");
		error.set_text(L"");
	}
}

void InstallerWindow::ResetContent()
{
	components.clear();
}

void InstallerWindow::SetControlValues()
{
	// TODO: iterate through all widgets, set values
	// LOG(L"--- Setting user-defined value '" << iter->first << L"'=" << iter->second->GetValue());
	// InstallerSession::Instance->AdditionalControlArgs[iter->first] = iter->second->GetValue();
}

// IExecuteCallback

void InstallerWindow::OnExecBegin()
{
	SetControlValues();

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

    ExtractCab(L"", p_configuration->show_cab_dialog);		
}

bool InstallerWindow::OnComponentExecBegin(const ComponentPtr& component)
{
	// embedded cab?
	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

	ExtractCab(component->id, p_configuration->show_cab_dialog && component->show_cab_dialog);

	// download?
	if (get(component->downloaddialog))
	{
		if (! RunDownloadConfiguration(component->downloaddialog))
		{
			LOG(L"*** Component '" << component->id << L" (" << component->GetDisplayName() << L"): ERROR ON DOWNLOAD");
			THROW_EX(L"Error downloading '" << component->id << L" (" << component->GetDisplayName() << L")");
		}
	}

	// m_component_dlg.LoadComponent(m_configuration, component);
	return true;
}

bool InstallerWindow::OnComponentExecWait(const ComponentPtr& component)
{
	if (InstallUILevelSetting::Instance->IsAnyUI())
	{
		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

		if (p_configuration->show_progress_dialog && component->show_progress_dialog)
		{
			// m_component_dlg.DoModal();
			LOG(L"--- Component '" << component->id << L" (" << component->GetDisplayName() << L"): DIALOG CLOSED");
		}
	}

	return true;
}

bool InstallerWindow::OnComponentExecSuccess(const ComponentPtr& component)
{
	// se è presente un messaggio di completamento installazione
	if (! component->installcompletemessage.empty())
	{
		DniMessageBox::Show(component->installcompletemessage, MB_OK | MB_ICONINFORMATION);
	}

	// se l'installazione ha chiesto di riavviare non continuo con gli altri componenti ma aggiorno solo la lista e lascio il Run nel registry per fare in modo che al prossimo riavvio venga rilanciato
	if (component->IsRebootRequired())
	{
		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

		LOG(L"--- Component '" << component->id << L" (" << component->GetDisplayName() << L"): REQUESTS REBOOT");

		std::wstring reboot_required = component->reboot_required;
		if (reboot_required.empty()) reboot_required = p_configuration->reboot_required;
		
		if (p_configuration->must_reboot_required || component->must_reboot_required)
		{
			LOG(L"--- Component '" << component->id << L" (" << component->GetDisplayName() << L"): REQUIRES REBOOT");
			DniMessageBox::Show(reboot_required, MB_OK | MB_ICONQUESTION);
			m_reboot = true;
		}
		else if (DniMessageBox::Show(reboot_required, MB_YESNO|MB_ICONQUESTION, IDYES) == IDYES)
		{
			m_reboot = true;
		}

		if (m_reboot)
		{
			LOG(L"--- Component '" << component->id << L" (" << component->GetDisplayName() << L": CAUSED A REBOOT");
			return false;
		}
	}

	return true;
}

bool InstallerWindow::OnComponentExecError(const ComponentPtr& component, std::exception& ex)
{
	LOG(L"--- Component '" << component->id << L" (" << component->GetDisplayName() << L")' FAILED: " << DVLib::string2wstring(ex.what()));
	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");
    // the component failed to install, display an error message and let the user choose to continue or not
    // unless global or component setting decides otherwise
	std::wstring failed_exec_command_continue = component->failed_exec_command_continue;
	if (failed_exec_command_continue.empty()) failed_exec_command_continue = p_configuration->failed_exec_command_continue;
	std::wstring error_message = DVLib::FormatMessage(const_cast<wchar_t *>(failed_exec_command_continue.c_str()), 
		component->GetDisplayName().c_str());

    bool break_sequence = false;
	if (error_message.empty())
	{
		break_sequence = ! component->default_continue_on_error;
	}
    else if (component->allow_continue_on_error)
    {
	    break_sequence = (DniMessageBox::Show(error_message, MB_YESNO, 
			component->default_continue_on_error ? IDYES : IDNO,
			MB_YESNO | MB_ICONEXCLAMATION) == IDNO);
    }
    else
    {
		ShowError(error_message);
        break_sequence = true;
    }

    if (break_sequence)
	{
		LOG(L"--- Component '" << component->id << L" (" << component->GetDisplayName() << L"): FAILED, ABORTING");
		return false;
	} else {
		LOG(L"--- Component '" << component->id << L" (" << component->GetDisplayName() << L"): FAILED, CONTINUE");
	}

	return true;
}

void InstallerWindow::ExtractCab(const std::wstring& id, bool display_progress)
{
	ExtractCabProcessorPtr p_extractcab(new ExtractCabProcessor(hinstance, id, status));	
	int cab_count = p_extractcab->GetCabCount();
	if (cab_count == 0)
	{
		LOG(L"Extracting embedded files for component '" << (id.empty() ? L"*" : id) << L"': NO FILES EMBEDDED");
		return;
	}

	LOG(L"Extracting embedded files for component '" << (id.empty() ? L"*" : id) << L"': " << cab_count << L" CAB(s)");

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	p_extractcab->cab_path = p_configuration->cab_path;
	p_extractcab->cab_cancelled_message = p_configuration->cab_cancelled_message;
	p_extractcab->BeginExec();

	p_extractcab->EndExec();
}
