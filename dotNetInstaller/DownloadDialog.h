#pragma once

#include "Resource.h"

class DownloadDialog : public CDialog, public IDownloadCallback
{
	DECLARE_DYNAMIC(DownloadDialog)
public:
	DownloadDialog(const DownloadGroupConfigurationPtr& p_Configuration, CWnd* pParent = NULL);
	enum { IDD = IDD_DOWNLOAD_DIALOG };
private:
	std::wstring m_Caption;
	std::wstring m_HelpMessage;
	std::wstring m_HelpMessageDownloading;
	std::wstring m_HelpMessageConnecting;
	std::wstring m_HelpMessageSendingRequest;
	std::wstring m_ButtonStartCaption;
	std::wstring m_ButtonCancelCaption;
	HICON m_hIcon;
	// download components and flags
	DownloadComponents m_DownloadComponents;
	bool m_bAutoStartDownload;
	bool m_bDownloadCancelled;
	bool m_bDownloadError;
	bool m_bDownloadCompleted;
	bool m_bDownloadStarted;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	LRESULT OnCloseDialog(WPARAM, LPARAM);
	virtual afx_msg void OnClose();
	static UINT ThreadProc(LPVOID pParam);
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_LabelHelpDownload;
	CStatic m_LabelStatus;
	CButton m_btStart;
	CButton m_btnCancel;
	CProgressCtrl m_ProgressControl;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedStart();
	afx_msg void OnOK();
	afx_msg LRESULT OnSetStatusDownload(WPARAM wParam, LPARAM lParam);
	// IDownloadCallback
	void Connecting();
	void SendingRequest();
	void Status(ULONG progress_current, ULONG progress_max, const std::wstring& description);
	void DownloadComplete();
	void DownloadError(const std::wstring& error);
	bool IsDownloadCancelled() const;
	bool IsDownloadError() const;
	void DownloadCancel();
	bool IsDownloadCompleted() const;
	bool IsDownloadStarted() const;
};
