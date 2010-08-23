#pragma once

class CdotNetInstallerDlg;

class CComponentsList :
	public CCheckListBox
{
	DECLARE_DYNAMIC(CComponentsList);
private:
	CdotNetInstallerDlg * m_pExecuteCallback;
	InstallConfiguration * m_pConfiguration;
	void Exec(const ComponentPtr& component);
protected:
	void PreDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct); 
	void OnCheckChange();
	void OnLButtonDblClk(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP();
public:
	void SetExecuteCallback(CdotNetInstallerDlg *);
	void Load(InstallConfiguration * pConfiguration);
	void AddComponent(const ComponentPtr& component);
	CComponentsList();
};
