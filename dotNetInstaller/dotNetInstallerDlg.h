#pragma once

#include "HyperlinkStatic.h"
#include "ComponentsList.h"
#include "resource.h"

// finestra di dialogo CdotNetInstallerDlg
class CdotNetInstallerDlg : public CDialog
{
public:
	CdotNetInstallerDlg(CWnd* pParent = NULL);	// costruttore standard
	enum { IDD = IDD_DOTNETINSTALLER_DIALOG };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// supporto DDX/DDV
protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	int m_recorded_error;
	bool m_additional_config;
	ConfigurationPtr m_configuration;
    void ExtractCab();
	void DisplayCab();
    void SelectComponents();
    // move a window to the coordinates defined by a rectangle with defaults
    static bool MoveWindow(CWnd& dlg, const WidgetPosition& pos);
public:
	void ExecuteCompleteCode(bool componentsInstalled);
	bool RunInstallConfiguration(const ConfigurationPtr& configuration, bool additional_config);
	bool RunDownloadConfiguration(DownloadGroupConfiguration & p_Configuration);
	bool DownloadComponents(Component& p_Component);
	inline int GetRecordedError() const { return m_recorded_error; }
	void RecordError(int error = -1);
	void ClearError();
	CButton m_btnSkip;
	CButton m_btnInstall;
	CButton m_btnCancel;
	CStatic m_lblMessage;
	CComponentsList m_ListBoxComponents;
	CStatic m_PictureBox;
	CStatic m_lblOperatingSystem;
	afx_msg void OnBnClickedInstall();
	bool LoadComponentsList(void);
	CHyperlinkStatic m_InfoLink;
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedSkip();
};
