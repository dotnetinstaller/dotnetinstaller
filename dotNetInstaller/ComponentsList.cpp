#include "StdAfx.h"
#include "ComponentsList.h"

CComponentsList::CComponentsList(void)
{
}

CComponentsList::~CComponentsList(void)
{
}

IMPLEMENT_DYNAMIC(CComponentsList, CCheckListBox)

BEGIN_MESSAGE_MAP(CComponentsList, CCheckListBox) 
END_MESSAGE_MAP()

void CComponentsList::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{ 
	if (lpDrawItemStruct->rcItem.left == 0)
		return;

	CDC dc; 
	dc.Attach(lpDrawItemStruct->hDC);
	
	COLORREF crOldTextColor = dc.GetTextColor();
	COLORREF crOldBkColor = dc.GetBkColor();
	if ((lpDrawItemStruct->itemAction | ODA_SELECT) && (lpDrawItemStruct->itemState & ODS_SELECTED))
	{
		dc.SetTextColor(::GetSysColor(COLOR_HIGHLIGHTTEXT));
		dc.SetBkColor(::GetSysColor(COLOR_HIGHLIGHT));		
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, ::GetSysColor(COLOR_HIGHLIGHT));
	}
	else
	{
		dc.FillSolidRect(& lpDrawItemStruct->rcItem, crOldBkColor);
	}

	CString text;
	GetText(lpDrawItemStruct->itemID, text); 
	lpDrawItemStruct->rcItem.left += 2;
	dc.DrawText(text, & lpDrawItemStruct->rcItem, DT_SINGLELINE);

	dc.SetTextColor(crOldTextColor);
	dc.SetBkColor(crOldBkColor);

	dc.Detach();
}
