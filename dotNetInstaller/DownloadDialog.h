#pragma once

#include "Resource.h"

// DownloadDialog dialog

class DownloadDialog : public CDialog, public IDownloadCallback
{
	DECLARE_DYNAMIC(DownloadDialog)

public:
	DownloadDialog(const DownloadGroupConfiguration & p_Configuration, CWnd* pParent = NULL);
	virtual ~DownloadDialog();

// Dialog Data
	enum { IDD = IDD_DOWNLOAD_DIALOG };

private:
	std::wstring m_Caption;
	std::wstring m_HelpMessage;
	std::wstring m_HelpMessageDownloading;
	std::wstring m_ButtonStartCaption;
	std::wstring m_ButtonCancelCaption;
	std::vector<DownloadComponentInfoPtr> m_Components;
	bool m_bAutoStartDownload;
	bool m_bCancelOrErrorDownload;
	bool m_bDownloadCompleted;
	HICON m_hIcon;
	CWinThread * m_pDownloadThread;
	static void DownloadComponents(IDownloadCallback *, const std::vector<DownloadComponentInfoPtr>& components);
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
	inline bool IsDownloadCompleted() const { return m_bDownloadCompleted; };
	inline bool IsDownloadStarted() const { return m_pDownloadThread != NULL; }
	bool IsDownloadRequired() const;
	bool IsCopyRequired() const;
	// copy local SourcePath files
	void CopyFromSourcePath();
	// IDownloadCallback
	void Status(ULONG progress_current, ULONG progress_max, const std::wstring& description);
	void DownloadComplete();
	void DownloadError(const std::wstring& error);
	bool IsDownloadCancelled() const;
	void DownloadCancel();
	inline const std::vector<DownloadComponentInfoPtr>& GetComponents() const { return m_Components; }
};


enum StatusType
{
	StatusType_Error,
	StatusType_Downloading,
	StatusType_Completed,
	StatusType_Canceled
};

struct DownloadStatusParam
{
	StatusType Type;
	ULONG CurrentProgress;
	ULONG ProgressMax;
	std::wstring Status;
	std::wstring Error;

	static DownloadStatusParam * CreateProgress(const std::wstring& p_Status, ULONG p_CurrentProgress, ULONG p_ProgressMax)
	{
		DownloadStatusParam * param = new DownloadStatusParam();
		param->Type = StatusType_Downloading;
		param->CurrentProgress = p_CurrentProgress;
		param->ProgressMax = p_ProgressMax;
		param->Status = p_Status;
		return param;
	}
	static DownloadStatusParam * CreateComplete()
	{
		DownloadStatusParam * param = new DownloadStatusParam();
		param->Type = StatusType_Completed;
		return param;
	}
	static DownloadStatusParam * CreateError(const std::wstring& p_Error)
	{
		DownloadStatusParam * param = new DownloadStatusParam();
		param->Type = StatusType_Error;
		param->Error = p_Error;
		return param;
	}
	static DownloadStatusParam * CreateCanceled()
	{
		DownloadStatusParam * param = new DownloadStatusParam();
		param->Type = StatusType_Canceled;
		return param;
	}

	static void Free(DownloadStatusParam * param)
	{
		delete param;
	}
};
