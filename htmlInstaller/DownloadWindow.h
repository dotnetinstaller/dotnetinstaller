#pragma once

#include "HtmlWindow.h"

class DownloadWindow : public HtmlWindow, public IDownloadCallback
{
	DownloadDialogPtr m_downloaddialog;
	int m_recorded_error;
	int m_recorded_progress;
	int m_total_progress;
	bool download_started;
	bool download_cancelled;
	htmlayout::dom::element status;
	htmlayout::dom::element error;
	htmlayout::dom::element progress;
	htmlayout::dom::element button_cancel;
	htmlayout::dom::element button_start;
	// ThreadComponent
	int ExecOnThread();
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
	void OnStart();
	void OnCancel();
protected:
	HINSTANCE GetInstance() const;
	HWND GetHwnd() const;
	void Stop();
	void OnDocumentComplete();
	void RecordError(int error = -1);
	void ClearError();
	void Start();
public:
	void Create(int x, int y, int width, int height, const wchar_t * caption = 0);
	BOOL on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason);
	int OnMessage(UINT message, WPARAM wParam, LPARAM lParam);
public:
	void ShowError(const std::wstring&);
	// progress
	void SetProgress(int pc);
	void SetProgressTotal(int pc);
	void ClearProgress();
	void SetStatus(const std::wstring& msg);
	bool Run();
public:
	DownloadWindow(const DownloadDialogPtr& p_Configuration);
};
