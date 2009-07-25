#pragma once

class CComponentsList :
	public CCheckListBox
{
	DECLARE_DYNAMIC(CComponentsList);
protected: 
	void PreDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct); 
	void OnCheckChange();
	DECLARE_MESSAGE_MAP();
public:
	bool Load(DVLib::LcidType lcidtype, const ConfigurationPtr& configuration);
	CComponentsList();
};
