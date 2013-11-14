#pragma once

#include "HyperlinkStatic.h"
#include "ComponentsList.h"
#include "InstallComponentDlg.h"
#include "ControlValue.h"
#include "resource.h"

// finestra di dialogo CdotNetInstallerDlg
class CdotNetInstallerDlg : public CDialog, public IExecuteCallback, public InstallerUI
{
public:
	CdotNetInstallerDlg(CWnd* pParent = NULL);	// costruttore standard
	enum { IDD = IDD_DOTNETINSTALLER_DIALOG };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// supporto DDX/DDV
	void AddComponent(const ComponentPtr& component);
	void ResetContent();
protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	auto_any<InstallComponentDlg *, close_delete> m_pComponentDlg;
	void ExtractCab(const std::wstring& id, bool display_dialog);
    void SelectComponents();
    // move a window to the coordinates defined by a rectangle with defaults
    static bool MoveWindow(CWnd& dlg, const WidgetPosition& pos);
	DWORD SetDefaultButton(DWORD id);
public:
	bool RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration);
	CButton m_btnSkip;
	CButton m_btnInstall;
	CButton m_btnCancel;
	CStatic m_lblMessage;
	CComponentsList m_ListBoxComponents;
	CStatic m_PictureBox;
	CStatic m_lblOperatingSystem;
	afx_msg void OnBnClickedInstall();
	ComponentsStatus LoadComponentsList(bool autoSetChecked);
	CHyperlinkStatic m_InfoLink;
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedSkip();
	// IExecuteCallback
	void OnExecBegin();
	bool OnComponentExecBegin(const ComponentPtr& component);
	bool OnComponentExecWait(const ComponentPtr& component);
	bool OnComponentExecSuccess(const ComponentPtr& component);
	bool OnComponentExecError(const ComponentPtr& component, std::exception& ex);
private:
	std::map<std::wstring, ControlValue *> m_custom_control_values; 
	std::list<CFont *> m_custom_fonts;
	std::list<CWnd *> m_custom_controls;
	CFont * CreateFont(const ControlText&);
	void AddControl(const ControlLabel&);
	void AddControl(const ControlCheckBox&);
	void AddControl(const ControlEdit&);
	void AddControl(const ControlBrowse&);
	void AddControl(const ControlLicense&);
	void AddControl(const ControlHyperlink&);
	void AddControl(const ControlImage&);
	void SetControlValues();
	bool Run();
	HWND GetHwnd() const;
	HINSTANCE GetInstance() const;
	void StartInstall();
	void Stop();
	void SetElevationRequired(bool required = true);
};
