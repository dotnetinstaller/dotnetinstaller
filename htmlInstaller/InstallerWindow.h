#pragma once

#include "HtmlWindow.h"

class InstallerWindow : public HtmlWindow, public IExecuteCallback
{
private:
	int m_recorded_error;
	bool m_reboot;
	bool m_additional_config;
	DVLib::LcidType m_lcidtype;
	ConfigurationPtr m_configuration;
	htmlayout::dom::element components;
	htmlayout::dom::element button_install;
	htmlayout::dom::element button_uninstall;
	htmlayout::dom::element button_skip;
	htmlayout::dom::element button_cancel;
	htmlayout::dom::element status;
	htmlayout::dom::element error;
	// IExecuteCallback
	void SetControlValues();
	void ExtractCab(const std::wstring& id, bool display_dialog);
	void OnExecBegin();
	bool OnComponentExecBegin(const ComponentPtr& component);
	bool OnComponentExecWait(const ComponentPtr& component);
	bool OnComponentExecSuccess(const ComponentPtr& component);
	bool OnComponentExecError(const ComponentPtr& component, std::exception& ex);
public:
	bool RunInstallConfiguration(DVLib::LcidType lcidtype, const ConfigurationPtr& configuration, bool additional_config);
	bool RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration);
	void Create(int x, int y, int width, int height, const wchar_t * caption = 0);
	bool LoadComponentsList();
	void ResetContent();
	void DoModal();
	BOOL on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason);
public:
	void OnInstall();
	void OnOK();
	void RecordError(int error = -1);
	void ShowError(const std::wstring&);
	void ClearError();
public:
	InstallerWindow();
};
