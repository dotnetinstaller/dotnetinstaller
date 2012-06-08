#pragma once
#include "InstallConfiguration.h"
#include "ControlLabel.h"
#include "ControlCheckBox.h"
#include "ControlEdit.h"
#include "ControlBrowse.h"
#include "ControlLicense.h"
#include "ControlHyperlink.h"
#include "ControlImage.h"
#include "ComponentsStatus.h"

class InstallerUI
{
protected:
	int m_recorded_error;
	int m_recorded_progress;
	int m_total_progress;
	bool m_reboot;
	bool m_additional_config;
	ComponentsStatus m_install_status;
	ConfigurationPtr m_configuration;
public:
	InstallerUI();
	virtual ~InstallerUI();
	virtual inline int GetRecordedError() const { return m_recorded_error; }
	virtual bool RunInstallConfiguration(const ConfigurationPtr& configuration, bool p_additional_config);
	virtual bool RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration);
	void DisplaySplash();
protected:
	virtual bool AutoStart(InstallConfiguration * p_configuration);
	virtual void RecordError(int error = -1);
	virtual void ClearError();
	virtual void ResetContent() = 0;
	virtual void AddComponent(const ComponentPtr& component) = 0;
	virtual ComponentsStatus LoadComponentsList();
	virtual void ExecuteCompleteCode(bool components_installed);
	virtual void ShowMessage(const std::wstring& message, int flags = 0);
	virtual bool Run() = 0;
	virtual HINSTANCE GetInstance() const = 0;
	virtual HWND GetHwnd() const = 0;
	void LoadComponents();
	void Start();
	void AddUserControls();
	void AddElevatedControls();
	virtual void StartInstall() = 0;
	virtual void Stop() = 0;
	virtual void ExtractCab(const std::wstring& id, bool display_dialog) = 0;
	bool ComponentExecError(const ComponentPtr& component, std::exception& ex);
	bool ComponentExecSuccess(const ComponentPtr& component);
	bool ComponentExecBegin(const ComponentPtr& component);
	void Terminate();
	void AfterInstall(int rc);
	// user-defined controls
	virtual void AddControl(const ControlLabel&) = 0;
	virtual void AddControl(const ControlCheckBox&) = 0;
	virtual void AddControl(const ControlEdit&) = 0;
	virtual void AddControl(const ControlBrowse&) = 0;
	virtual void AddControl(const ControlLicense&) = 0;
	virtual void AddControl(const ControlHyperlink&) = 0;
	virtual void AddControl(const ControlImage&) = 0;
	virtual void SetElevationRequired(bool required = true) = 0;
	bool RestartElevated();
};
