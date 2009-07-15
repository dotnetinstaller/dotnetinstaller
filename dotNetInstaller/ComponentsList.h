#pragma once

struct ComponentsListStatus
{
	bool all_required_components_installed;
	bool all_components_installed;
};

class CComponentsList :
	public CCheckListBox
{
	DECLARE_DYNAMIC(CComponentsList);
protected: 
	void PreDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct); 
	DECLARE_MESSAGE_MAP();
public:
	ComponentsListStatus Load(const ConfigurationPtr& configuration);
	CComponentsList(void);
	~CComponentsList(void);
};
