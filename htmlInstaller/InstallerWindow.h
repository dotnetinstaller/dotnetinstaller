#pragma once

#include "HtmlWindow.h"

class InstallerWindow : public HtmlWindow, public ThreadComponent, 
	public InstallerUI, public IExecuteCallback, public IDownloadCallback
{
private:
	bool m_download_started;
	bool m_download_cancelled;
	DownloadDialogPtr m_downloaddialog;
	htmlayout::dom::element components;
	htmlayout::dom::element button_install;
	htmlayout::dom::element button_uninstall;
	htmlayout::dom::element button_skip;
	htmlayout::dom::element button_cancel;
	htmlayout::dom::element status;
	htmlayout::dom::element error;
	htmlayout::dom::element progress;
	void SetControlValues();
	void ExtractCab(const std::wstring& id, bool display_dialog);
	// IExecuteCallback
	int ExecOnThread();
	void OnExecBegin();
	bool OnComponentExecBegin(const ComponentPtr& component);
	bool OnComponentExecWait(const ComponentPtr& component);
	bool OnComponentExecSuccess(const ComponentPtr& component);
	bool OnComponentExecError(const ComponentPtr& component, std::exception& ex);
	// IDownloadCallback
	void DownloadingFile(const std::wstring& filename);
	void CopyingFile(const std::wstring& filename);
	void Connecting(const std::wstring& host);
	void SendingRequest(const std::wstring& host);
	void Status(ULONG progress_current, ULONG progress_max, const std::wstring& description);
	void DownloadComplete();
	void DownloadError(const std::wstring& message);
	bool IsDownloadCancelled() const;
	void OnShow();
	Component * m_running_component;
	void SetElevationRequired(bool required = true);
protected:
	void AddComponent(const ComponentPtr& component);
	bool Run();
	HINSTANCE GetInstance() const;
	HWND GetHwnd() const;
	void StartInstall();
	void Stop();
	void Hide();
	void OnDocumentComplete();
	// user-defined controls
	void AddControl(const ControlLabel&);
	void AddControl(const ControlCheckBox&);
	void AddControl(const ControlEdit&);
	void AddControl(const ControlBrowse&);
	void AddControl(const ControlLicense&);
	void AddControl(const ControlHyperlink&);
	void AddControl(const ControlImage&);
	static std::wstring GetPositionStyle(const WidgetPosition& position);
	static std::wstring GetControlStyle(const ControlText& control);
	void RunComponent(const ComponentPtr& component);
	static UINT RunComponentOnThread(LPVOID pParam);
public:
	bool RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration);
	void Create(int x, int y, int width, int height, const wchar_t * caption = 0);
	void ResetContent();
	BOOL on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason);
	BOOL on_mouse(HELEMENT he, HELEMENT target, UINT event_type, POINT pt, UINT mouseButtons, UINT keyboardStates);
	BOOL on_mouse_click(HELEMENT he, HELEMENT target, POINT pt, UINT mouseButtons, UINT keyboardStates);
	BOOL on_mouse_dclick(HELEMENT he, HELEMENT target, POINT pt, UINT mouseButtons, UINT keyboardStates);
	int OnMessage(UINT message, WPARAM wParam, LPARAM lParam);
public:
	void OnInstall();
	void OnOK();
	void OnCancel();
	void ShowError(const std::wstring&);
	void ClearError();
	// progress
	void SetProgress(int pc);
	void SetProgressTotal(int pc);
	void ClearProgress();
	void SetStatus(const std::wstring& msg);
public:
	InstallerWindow();
};
