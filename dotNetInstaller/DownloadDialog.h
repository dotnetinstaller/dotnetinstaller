#pragma once

#include "Resource.h"
#include "DownloadGroupConfiguration.h"

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
	CString m_Caption;
	CString m_HelpMessage;
	CString m_HelpMessageDownloading;
	CString m_ButtonStartCaption;
	CString m_ButtonCancelCaption;
	DownloadComponentInfoVector m_Components;
	bool m_bAutoStartDownload;

	bool m_bCancelOrErrorDownload;
	bool m_bDownloadCompleted;

	HICON m_hIcon;

	CWinThread * m_pDownloadThread;

	//HWND m_HWNDProgressBar;
	//HWND m_HWNDLabelStatus;

	static void DownloadComponents(IDownloadCallback *);

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

	inline bool IsDownloadCompleted() { return m_bDownloadCompleted; };
	inline bool IsDownloadStarted() { return m_pDownloadThread != NULL; }
	bool IsDownloadRequired();
	bool IsCopyRequired();

	// copy local SourcePath files
	void CopyFromSourcePath();

	// IDownloadCallback
	virtual void Status(ULONG p_CurrentProgress, ULONG p_MaxProgress, LPCTSTR p_Description);
	virtual void DownloadComplete();
	virtual void DownloadError(LPCTSTR);
	virtual bool WantToStop();
	virtual void CanceledByTheUser();
	virtual DownloadComponentInfoVector * GetComponents();
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
	CString Status;
	CString Error;

	static DownloadStatusParam * CreateProgress(CString p_Status, ULONG p_CurrentProgress, ULONG p_ProgressMax)
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
	static DownloadStatusParam * CreateError(CString p_Error)
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
