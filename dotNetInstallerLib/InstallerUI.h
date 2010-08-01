#pragma once
#include "InstallConfiguration.h"

class InstallerUI
{
protected:
	int m_recorded_error;
	int m_recorded_progress;
	int m_total_progress;
	bool m_reboot;
	bool m_additional_config;
	bool m_all;
	DVLib::LcidType m_lcidtype;
	ConfigurationPtr m_configuration;
public:
	InstallerUI();
	virtual ~InstallerUI();
	virtual inline int GetRecordedError() const { return m_recorded_error; }
	virtual bool RunInstallConfiguration(DVLib::LcidType lcidtype, const ConfigurationPtr& configuration, bool p_additional_config);
	virtual bool RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration);
	void DisplaySplash();
protected:
	virtual bool AutoStart(InstallConfiguration * p_configuration);
	virtual void RecordError(int error = -1);
	virtual void ClearError();
	virtual void ResetContent() = 0;
	virtual void AddComponent(const ComponentPtr& component, 
		const std::wstring& description, bool checked, bool disabled) = 0;
	virtual bool LoadComponentsList();
	virtual void ExecuteCompleteCode(bool components_installed);
	virtual void ShowMessage(const std::wstring& message, int flags = 0);
	virtual bool Run() = 0;
	virtual HINSTANCE GetInstance() const = 0;
	virtual HWND GetHwnd() const = 0;
	void LoadComponents();
	void Start();
	virtual void StartInstall() = 0;
	virtual void Stop() = 0;
	virtual void ExtractCab(const std::wstring& id, bool display_dialog) = 0;
	bool ComponentExecError(const ComponentPtr& component, std::exception& ex);
	bool ComponentExecSuccess(const ComponentPtr& component);
	bool ComponentExecBegin(const ComponentPtr& component);
	void Terminate();
	void AfterInstall(int rc);
};
