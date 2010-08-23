#include "StdAfx.h"
#include "InstallerUI.h"
#include "InstallUILevel.h"
#include "InstallerSession.h"
#include "InstallerLog.h"
#include "InstallerCommandLineInfo.h"
#include "DniMessageBox.h"
#include "SplashWnd.h"

InstallerUI::InstallerUI()
	: m_reboot(false)
	, m_recorded_error(0)
	, m_total_progress(0)
	, m_recorded_progress(0)
	, m_additional_config(false)
{

}

InstallerUI::~InstallerUI()
{

}

void InstallerUI::RecordError(int error)
{
	if (m_recorded_error == 0) 
	{
		m_recorded_error = error; 
	}
}

void InstallerUI::ClearError()
{
	m_recorded_error = 0;
}

bool InstallerUI::AutoStart(InstallConfiguration * p_configuration)
{
	bool autostart = false;

	if (InstallUILevelSetting::Instance->IsSilent())
	{
		autostart = true;
		LOG(L"Silent mode: automatically starting " 
			<< InstallSequenceUtil::towstring(InstallerSession::Instance->sequence));
	}

	if (InstallerCommandLineInfo::Instance->Reboot())
	{
		if (p_configuration->auto_continue_on_reboot)
		{
			autostart = true;
			LOG(L"Reboot defines auto-start: automatically starting "
				 << InstallSequenceUtil::towstring(InstallerSession::Instance->sequence));
		}
	}
	else if (p_configuration->auto_start)
	{
		autostart = true;
		LOG(L"Configuration defines auto-start: automatically starting "
			 << InstallSequenceUtil::towstring(InstallerSession::Instance->sequence));
	}

	return autostart;
}

void InstallerUI::LoadComponents()
{
	m_all = LoadComponentsList();

	// load xml file
	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

	if (InstallerSession::Instance->sequence == SequenceInstall && m_all && p_configuration->supports_uninstall)
	{
		LOG("All components installed, switching to uninstall.");
		InstallerSession::Instance->sequence = SequenceUninstall;
		m_all = LoadComponentsList();
		if (m_all)
		{
			LOG("All components uninstalled, nothing to do.");
			InstallerSession::Instance->sequence = SequenceInstall;
		}
	}
}

// returns true if all components have been installed
bool InstallerUI::LoadComponentsList()
{
	InstallConfiguration * pConfiguration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(pConfiguration != NULL, L"Invalid configuration");	

	bool all = true;

	ResetContent();

	Components components_list = pConfiguration->GetSupportedComponents(
		InstallerSession::Instance->lcidtype, InstallerSession::Instance->sequence);

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

		std::wstring description = component->GetDisplayName();
	    description += L" ";
        description += component_installed
			? (component->status_installed.empty() ? pConfiguration->status_installed : component->status_installed)
			: (component->status_notinstalled.empty() ? pConfiguration->status_notinstalled : component->status_notinstalled);

		component->description = description;

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

		bool checked = false;
        if (component->checked)
        {
			if (component->selected_install && InstallerSession::Instance->sequence == SequenceInstall)
				checked = true;
			else if (component->selected_uninstall && InstallerSession::Instance->sequence == SequenceUninstall)
				checked = true;
        }

		component->checked = checked;

        // a component is considered installed when it has an install check which results
        // in a clear positive; if a component doesn't have any install checks, it cannot
        // be required (there's no way to check whether the component was installed)
		bool disabled = false;
        if (InstallerSession::Instance->sequence == SequenceInstall 
			&& (component->required_install || component_installed))
            disabled = true;
        else if (InstallerSession::Instance->sequence == SequenceUninstall 
			&& (component->required_uninstall || ! component_installed))
            disabled = true;

		component->disabled = disabled;

		AddComponent(component);
    }

	return all;
}

void InstallerUI::ExecuteCompleteCode(bool components_installed)
{
	LOG(L"--- Complete Command");

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

	std::wstring message;
	switch(InstallerSession::Instance->sequence)
	{
	case SequenceInstall:
		message = p_configuration->installation_completed;
		// installation completed, but no components have been installed
		if (! components_installed && ! p_configuration->installation_none.empty())
		{
			message = p_configuration->installation_none;
		}
		break;
	case SequenceUninstall:
		message = p_configuration->uninstallation_completed;
		// uninstallation completed, but no components have been uninstalled
		if (! components_installed && ! p_configuration->uninstallation_none.empty())
		{
			message = p_configuration->uninstallation_none;
		}
		break;
	}

	if (! message.empty())
    {
		ShowMessage(message, MB_OK|MB_ICONINFORMATION);
    }

	std::wstring l_complete_command = InstallUILevelSetting::Instance->GetCommand(
		p_configuration->complete_command,
		p_configuration->complete_command_basic,
		p_configuration->complete_command_silent);

    if (! InstallerCommandLineInfo::Instance->GetCompleteCommandArgs().empty())
    {
        l_complete_command.append(L" ");
        l_complete_command.append(InstallerCommandLineInfo::Instance->GetCompleteCommandArgs());
    }

	if (! l_complete_command.empty())
	{
		DWORD dwExitCode = 0;
		if (p_configuration->wait_for_complete_command)
		{
			LOG(L"Executing complete command: " << l_complete_command);
			dwExitCode = DVLib::ExecCmd(l_complete_command);
		}
		else
		{
			LOG(L"Detaching complete command: " << l_complete_command);
			DVLib::DetachCmd(l_complete_command);
		}
	}
}

void InstallerUI::ShowMessage(const std::wstring& message, int flags)
{
	DniMessageBox::Show(message, flags);
}

bool InstallerUI::RunInstallConfiguration(const ConfigurationPtr& configuration, bool p_additional_config)
{
	// remove the Run key if exist
	InstallerSession::Instance->DisableRunOnReboot();

	m_configuration = configuration;
	m_additional_config = p_additional_config;

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

	// check sequences
	if (! p_configuration->supports_uninstall && ! p_configuration->supports_install)
	{
		THROW_EX("Configuration supports neither install nor uninstall.");
	}
	else if (InstallerSession::Instance->sequence == SequenceUninstall && ! p_configuration->supports_uninstall)
	{
		THROW_EX("Configuration doesn't support uninstall.");
	}
	else if (InstallerSession::Instance->sequence == SequenceInstall && ! p_configuration->supports_install)
	{
		THROW_EX("Configuration doesn't support install.");
	}

	return Run();
}

bool InstallerUI::RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration)
{
	if (! p_Configuration->IsRequired())
	{
		LOG(L"*** Component '" << p_Configuration->component_id << L"': SKIPPING DOWNLOAD/COPY");
	}

	THROW("RunDownloadConfiguration not implemented");
}

void InstallerUI::DisplaySplash()
{
	// splash screen
	if (! InstallerCommandLineInfo::Instance->DisplaySplash())
		return;
	
	if (! InstallUILevelSetting::Instance->IsAnyUI())
		return;

	HRSRC hsplash = ::FindResourceA(NULL, "RES_SPLASH", "CUSTOM");
	if (NULL == hsplash)
		return;

	HBITMAP hsplash_bitmap = DVLib::LoadBitmapFromResource(GetInstance(), L"RES_SPLASH", L"CUSTOM");
	CHECK_BOOL(CSplashWnd::ShowSplashScreen(3000, hsplash_bitmap, GetHwnd()),
		L"Error loading splash screen.");
}

void InstallerUI::Start()
{
	DisplaySplash();

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

	if (InstallerSession::Instance->sequence == SequenceInstall && m_all && p_configuration->supports_install)
	{
		if (p_configuration->auto_close_if_installed || InstallUILevelSetting::Instance->IsSilent())
		{
            if (! p_configuration->complete_command.empty()
				|| ! p_configuration->complete_command_silent.empty()
				|| ! p_configuration->complete_command_basic.empty())
            {
                ExtractCab(L"", p_configuration->show_cab_dialog); // the command may need to execute a file
            }

			ExecuteCompleteCode(false);
			Stop();
		}
	}
	else if (InstallerSession::Instance->sequence == SequenceUninstall && m_all && p_configuration->supports_uninstall)
	{
		Stop();
	}
	else
	{
		if (AutoStart(p_configuration))
		{
			StartInstall();
		}
	}
}

bool InstallerUI::ComponentExecError(const ComponentPtr& component, std::exception& ex)
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
        DniMessageBox::Show(error_message, MB_OK, 0, MB_ICONEXCLAMATION);
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

bool InstallerUI::ComponentExecSuccess(const ComponentPtr& component)
{
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

bool InstallerUI::ComponentExecBegin(const ComponentPtr& component)
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

	return true;
}

void InstallerUI::Terminate()
{
	try
	{
        // delete temporary directory
        // even if a reboot is required, the temporary folder is gone; next run will re-extract components
		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");
        std::wstring cabpath = (! p_configuration->cab_path.empty()) ? p_configuration->cab_path : InstallerSession::Instance->GetSessionTempPath(true);
		cabpath = InstallerSession::Instance->ExpandVariables(cabpath);
		if (p_configuration->cab_path_autodelete && ! cabpath.empty() && DVLib::DirectoryExists(cabpath))
        {
		    LOG(L"Deleting temporary folder: " << cabpath);
			DVLib::DirectoryDelete(cabpath);
        }
	}
    catch(std::exception& ex)
    {
		LOG("Error terminating dotNetInstaller: " << DVLib::string2wstring(ex.what()));
		DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK | MB_ICONSTOP);
    }
	catch(...)
	{
		_ASSERT(false);
	}
}

void InstallerUI::AfterInstall(int rc)
{
	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

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
		Stop();
		return;
	}

	// failure and auto-close-on-error
	if (rc != 0 && p_configuration->auto_close_on_error)
	{
		LOG(L"*** Failed to install one or more components, closing (auto_close_on_error).");
		Stop();
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
			ExecuteCompleteCode(true);
			Stop();
		}
	}
}

void InstallerUI::AddUserControls()
{
	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

	for each(const ControlPtr& control in p_configuration->controls)
	{
		if (! control->IsVisible())
		{
			LOG(L"-- Skipping " << control->GetString() << L", hidden");
			continue;
		}

		LOG(L"-- Adding " << control->GetString());
		switch(control->type)
		{
		case control_type_label:
			AddControl(* (ControlLabel *) get(control));
			break;
		case control_type_checkbox:
			{
				ControlCheckBox * control_checkbox = (ControlCheckBox *) get(control);
				std::map<std::wstring, std::wstring>::iterator value;
				if ((value = InstallerSession::Instance->AdditionalControlArgs.find(control_checkbox->id)) != 
					InstallerSession::Instance->AdditionalControlArgs.end())
				{
					if (control_checkbox->checked_value == value->second) 
					{
						control_checkbox->checked = true;
					}
					else if (control_checkbox->unchecked_value == value->second) 
					{
						control_checkbox->checked = false;
					}
					else
					{
						THROW_EX(L"Invalid " << control_checkbox->id << L" value '" << value->second << L"', should be one of '"
							<< control_checkbox->checked_value << L"' or '" << control_checkbox->unchecked_value << L"'");
					}
				}
				
				AddControl(* control_checkbox);
			}
			break;
		case control_type_edit:
			{
				ControlEdit * control_edit = (ControlEdit *) get(control);
				std::map<std::wstring, std::wstring>::iterator value;
				if ((value = InstallerSession::Instance->AdditionalControlArgs.find(control_edit->id)) != 
					InstallerSession::Instance->AdditionalControlArgs.end())
				{
					control_edit->text = value->second.c_str();
				}

				AddControl(* control_edit);
			}
			break;
		case control_type_browse:
			{
				ControlBrowse * control_browse = (ControlBrowse *) get(control);
				std::map<std::wstring, std::wstring>::iterator value;
				if ((value = InstallerSession::Instance->AdditionalControlArgs.find(control_browse->id)) != 
					InstallerSession::Instance->AdditionalControlArgs.end())
				{
					control_browse->path = value->second;
				}
				else
				{
					control_browse->path = control_browse->text;
				}

				AddControl(* control_browse);
			}
			break;
		case control_type_license:
			{
				ControlLicense * control_license = (ControlLicense *) get(control);
				// extract license to temporary location
				std::vector<char> license_buffer = DVLib::LoadResourceData<char>(NULL, control_license->resource_id, L"CUSTOM");
				std::wstring license_file = DVLib::DirectoryCombine(InstallerSession::Instance->GetSessionTempPath(), DVLib::GetFileNameW(control_license->license_file));
				LOG(L"Extracting license '" << control_license->resource_id << L"' to " << license_file);
				DVLib::FileWrite(license_file, license_buffer);
				control_license->license_file = license_file;
				AddControl(* control_license);
			}
			break;
		case control_type_hyperlink:
			AddControl(* (ControlHyperlink *) get(control));
			break;
		case control_type_image:
			AddControl(* (ControlImage *) get(control));
			break;
		default:
			THROW_EX(L"Invalid control type: " << control->type);
		}
	}
}
