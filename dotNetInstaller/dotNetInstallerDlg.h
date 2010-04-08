#pragma once

#include "HyperlinkStatic.h"
#include "ComponentsList.h"
#include "InstallComponentDlg.h"
#include "ControlValue.h"
#include "resource.h"

// finestra di dialogo CdotNetInstallerDlg
class CdotNetInstallerDlg : public CDialog, public IExecuteCallback
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
	bool m_reboot;
	bool m_additional_config;
	DVLib::LcidType m_lcidtype;
	ConfigurationPtr m_configuration;
	InstallComponentDlg m_component_dlg;
	void ExtractCab(const std::wstring& id);
    void SelectComponents();
	void DisplaySplash();
    // move a window to the coordinates defined by a rectangle with defaults
    static bool MoveWindow(CWnd& dlg, const WidgetPosition& pos);
	DWORD SetDefaultButton(DWORD id);
public:
	void ExecuteCompleteCode(bool componentsInstalled);
	bool RunInstallConfiguration(DVLib::LcidType lcidtype, const ConfigurationPtr& configuration, bool additional_config);
	bool RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration);
	bool RunComponentDownload(const ComponentPtr& p_Component);
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
	bool LoadComponentsList();
	CHyperlinkStatic m_InfoLink;
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedSkip();
	// IExecuteCallback
	bool OnComponentExecBegin(const ComponentPtr& component);
	bool OnComponentExecWait(const ComponentPtr& component);
	bool OnComponentExecSuccess(const ComponentPtr& component);
	bool OnComponentExecError(const ComponentPtr& component, std::exception& ex);
	bool AutoStart(InstallConfiguration * p_configuration);
private:
	std::map<std::wstring, ControlValue *> m_custom_control_values; 
	std::list<CObject *> m_custom_controls;
	CFont * CreateFont(const ControlText&);
	void AddControl(const ControlLabel&);
	void AddControl(const ControlCheckBox&);
	void AddControl(const ControlEdit&);
	void AddControl(const ControlBrowse&);
	void AddControl(const ControlLicense&);
	void AddControl(const ControlHyperlink&);
	void SetControlValues();
};
