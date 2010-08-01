#include "StdAfx.h"
#include "InstallerWindow.h"
#include "ConfigFileManager.h"
#include "ExtractCabProcessor.h"
#include "HtmlWidgets.h"
#include "Resource.h"

InstallerWindow::InstallerWindow()
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

bool InstallerWindow::Run()
{
	DoModal();
	// return(IDOK == DoModal());
	return true;
}

void InstallerWindow::DoModal()
{
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

	// progress
	progress = r.get_element_by_id("progress");
	ClearProgress();

	// load components
	LoadComponents();

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

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

	Start();
}

bool InstallerWindow::RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration)
{
	if (! p_Configuration->IsRequired())
	{
		LOG(L"*** Component '" << p_Configuration->component_id << L"': SKIPPING DOWNLOAD/COPY");
		return true;
	}

	m_downloaddialog = p_Configuration;
	p_Configuration->callback = this;

	html_save_progress progress_saved(& progress, m_recorded_progress, m_total_progress);
	SetProgress(0);
	return 0 == p_Configuration->ExecOnThread();
}

void InstallerWindow::AddComponent(const ComponentPtr& component, const std::wstring& description, bool checked, bool disabled)
{
	htmlayout::dom::element opt = htmlayout::dom::element::create("widget", description.c_str());
	opt["type"] = L"checkbox";
	opt["id"] = component->id.GetValue().c_str();
	opt["component_ptr"] = DVLib::towstring(get(component)).c_str();
	if (checked) opt["checked"] = L"true";
	if (disabled) opt["disabled"] = L"true";
	htmlayout::queue::push(new html_insert_task(& components, opt, components.children_count() + 1), HtmlWindow::s_hwnd);
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
	Stop();
}

void InstallerWindow::OnInstall()
{
	BeginExec();
}

void InstallerWindow::ShowError(const std::wstring& message)
{
	htmlayout::queue::push(new html_clear_style_attribute_task(& error, "display"), HtmlWindow::s_hwnd);
	htmlayout::queue::push(new html_set_text_task(& error, message), HtmlWindow::s_hwnd);
}

void InstallerWindow::ClearError() 
{ 
	InstallerUI::ClearError();
	htmlayout::queue::push(new html_set_style_attribute_task(& error, "display", L"none"), HtmlWindow::s_hwnd);
	htmlayout::queue::push(new html_set_text_task(& error, L""), HtmlWindow::s_hwnd);
}

void InstallerWindow::SetProgressTotal(int pc)
{
	m_total_progress = pc;
	htmlayout::queue::push(new html_set_attribute_task(& progress, "maxvalue", DVLib::towstring(pc)), HtmlWindow::s_hwnd);
}

void InstallerWindow::ClearProgress() 
{
	m_recorded_progress = 0;
	htmlayout::queue::push(new html_set_style_attribute_task(& progress, "display", L"none"), HtmlWindow::s_hwnd);
}

void InstallerWindow::SetStatus(const std::wstring& msg)
{
	htmlayout::queue::push(new html_set_text_task(& status, msg), HtmlWindow::s_hwnd);
}

void InstallerWindow::SetProgress(int pc) 
{
	m_recorded_progress = pc;
	htmlayout::queue::push(new html_clear_style_attribute_task(& progress, "display"), HtmlWindow::s_hwnd);
	htmlayout::queue::push(new html_set_attribute_task(& progress, "value", DVLib::towstring(pc)), HtmlWindow::s_hwnd);
}

void InstallerWindow::ResetContent()
{
	htmlayout::queue::push(new html_clear_task(& components), HtmlWindow::s_hwnd);
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
	SetProgress(m_recorded_progress + 1);

	SetControlValues();

	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

    ExtractCab(L"", p_configuration->show_cab_dialog);		
}

bool InstallerWindow::OnComponentExecBegin(const ComponentPtr& component)
{
	return InstallerUI::ComponentExecBegin(component);
}

bool InstallerWindow::OnComponentExecWait(const ComponentPtr& component)
{
	LOG(L"--- Component '" << component->id << L" (" << component->GetDisplayName() << L"): FINISHED");
	return true;
}

bool InstallerWindow::OnComponentExecSuccess(const ComponentPtr& component)
{
	SetProgress(m_recorded_progress + 1);
	return InstallerUI::ComponentExecSuccess(component);
}

bool InstallerWindow::OnComponentExecError(const ComponentPtr& component, std::exception& ex)
{
	SetProgress(m_recorded_progress + 1);
	return InstallerUI::ComponentExecError(component, ex);
}

void InstallerWindow::ExtractCab(const std::wstring& id, bool display_progress)
{
	ExtractCabProcessorPtr p_extractcab(new ExtractCabProcessor(s_hinstance, id, & status));	
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

int InstallerWindow::OnMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_CLOSE:
		if (IsExecuting()) 
		{
			return -1;
		}
		EndExec();
		InstallerUI::Terminate();
		break;
	}

	return HtmlWindow::OnMessage(message, wParam, lParam);
}

int InstallerWindow::ExecOnThread()
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
		ClearProgress();

		InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
		CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

		Components components = p_configuration->GetSupportedComponents(
			m_lcidtype, InstallerSession::Instance->sequence);

		SetProgressTotal(components.size() * 2);

		int rc = components.Exec(this);

		InstallerUI::AfterInstall(rc);
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

	return 0;
}

void InstallerWindow::Connecting(const std::wstring& host)
{
	CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
	std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->connecting_message.GetValue().c_str()), host.c_str());
	SetStatus(message);
}

void InstallerWindow::SendingRequest(const std::wstring& host)
{
	CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
	std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->sendingrequest_message.GetValue().c_str()), host.c_str());
	SetStatus(message);
}

void InstallerWindow::Status(ULONG progress_current, ULONG progress_max, const std::wstring& description)
{
	SetStatus(description);
	SetProgressTotal(progress_max);
	SetProgress(progress_current);
}

void InstallerWindow::DownloadComplete()
{

}

void InstallerWindow::DownloadError(const std::wstring& error)
{
	ShowError(error);
	RecordError();
}

bool InstallerWindow::IsDownloadCancelled() const
{
	return false;
}

void InstallerWindow::DownloadingFile(const std::wstring& filename)
{
	CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
	std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->downloading_message.GetValue().c_str()), filename.c_str());
	SetStatus(message);
}

void InstallerWindow::CopyingFile(const std::wstring& filename)
{
	CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
	std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->copying_message.GetValue().c_str()), filename.c_str());
	SetStatus(message);
}

HINSTANCE InstallerWindow::GetInstance() const
{
	return HtmlWindow::s_hinstance;
}

HWND InstallerWindow::GetHwnd() const
{
	return HtmlWindow::s_hwnd;
}

void InstallerWindow::StartInstall()
{
	OnInstall();
}

void InstallerWindow::Stop()
{
	::PostMessage(hwnd, WM_CLOSE, 0,0);
}