#pragma once

class CComponentsList :
	public CCheckListBox
{
	DECLARE_DYNAMIC(CComponentsList);
private:
	IExecuteCallback * m_pExecuteCallback;
	InstallConfiguration * m_pConfiguration;
protected:
	void Exec(const ComponentPtr& component);
	void PreDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct); 
	void OnCheckChange();
	void OnLButtonDblClk(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP();
public:
	void SetExecuteCallback(IExecuteCallback *);
	bool Load(DVLib::LcidType lcidtype, const ConfigurationPtr& configuration);
	CComponentsList();
};
