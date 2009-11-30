#pragma once

#include "Resource.h"

class CDownloadDialog : public CDialog, public IDownloadCallback
{
	DECLARE_DYNAMIC(CDownloadDialog)
public:
	CDownloadDialog(const DownloadDialogPtr& p_Configuration, CWnd* pParent = NULL);
	enum { IDD = IDD_DOWNLOAD_DIALOG };
private:
	std::wstring m_LastStatusMessage;
	std::wstring m_Caption;
	std::wstring m_Message;
	std::wstring m_MessageDownloadingFile;
	std::wstring m_MessageCopyingFile;
	std::wstring m_MessageConnecting;
	std::wstring m_MessageSendingRequest;
	std::wstring m_ButtonStartCaption;
	std::wstring m_ButtonCancelCaption;
	HICON m_hIcon;
	// download components and flags
	DownloadDialogPtr m_DownloadDialog;
	bool m_bAutoStartDownload;
	bool m_bDownloadCancelled;
	bool m_bDownloadError;
	bool m_bDownloadCompleted;
	bool m_bDownloadStarted;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	LRESULT OnCloseDialog(WPARAM, LPARAM);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnCancel();
	afx_msg void OnClose();
	static UINT ThreadProc(LPVOID pParam);
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_LabelHelp;
	CStatic m_LabelStatus;
	CButton m_btStart;
	CButton m_btnCancel;
	CProgressCtrl m_ProgressControl;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedStart();
	afx_msg void OnOK();
	afx_msg LRESULT OnSetStatusDownload(WPARAM wParam, LPARAM lParam);
	// IDownloadCallback
	void Connecting(const std::wstring& host);
	void SendingRequest(const std::wstring& host);
	void Status(ULONG progress_current, ULONG progress_max, const std::wstring& description);
	void DownloadComplete();
	void DownloadError(const std::wstring& error);
	bool IsDownloadCancelled() const;
	bool IsDownloadError() const;
	void DownloadCancel();
	bool IsDownloadCompleted() const;
	bool IsDownloadStarted() const;
	void DownloadingFile(const std::wstring& filename);
	void CopyingFile(const std::wstring& filename);
};
