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
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	if (((LONG)(lpDrawItemStruct->itemID) >= 0) &&
		(lpDrawItemStruct->itemAction & (ODA_DRAWENTIRE | ODA_SELECT)))
	{
		int cyItem = GetItemHeight(lpDrawItemStruct->itemID);
		BOOL fDisabled = !IsWindowEnabled() || !IsEnabled(lpDrawItemStruct->itemID);

		COLORREF newTextColor = fDisabled ?
			RGB(0, 0, 0) : GetSysColor(COLOR_WINDOWTEXT);  // light gray
		COLORREF oldTextColor = pDC->SetTextColor(newTextColor);

		COLORREF newBkColor = GetSysColor(COLOR_WINDOW);
		COLORREF oldBkColor = pDC->SetBkColor(newBkColor);

		if (newTextColor == newBkColor)
			newTextColor = RGB(0xC0, 0xC0, 0xC0);   // dark gray

		if (!fDisabled && ((lpDrawItemStruct->itemState & ODS_SELECTED) != 0))
		{
			pDC->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT));
			pDC->SetBkColor(GetSysColor(COLOR_HIGHLIGHT));
		}

		if (m_cyText == 0)
			VERIFY(cyItem >= CalcMinimumItemHeight());

		CString strText;
		GetText(lpDrawItemStruct->itemID, strText);

		pDC->ExtTextOut(lpDrawItemStruct->rcItem.left + 5,
			lpDrawItemStruct->rcItem.top + max(0, (cyItem - m_cyText) / 2),
			ETO_OPAQUE, &(lpDrawItemStruct->rcItem), strText, strText.GetLength(), NULL);

		int nCheck = GetCheck(lpDrawItemStruct->itemID);
		if (fDisabled && nCheck == 0)
		{
			CRect checkbox(0, lpDrawItemStruct->rcItem.top, lpDrawItemStruct->rcItem.left, lpDrawItemStruct->rcItem.bottom);
			COLORREF newBkColor = GetSysColor(COLOR_WINDOW);
			CBrush brush(newBkColor);
			pDC->FillRect(& checkbox, & brush);
		}

		pDC->SetTextColor(oldTextColor);
		pDC->SetBkColor(oldBkColor);
	}

	if ((lpDrawItemStruct->itemAction & ODA_FOCUS) != 0)
		pDC->DrawFocusRect(&(lpDrawItemStruct->rcItem));
}

void CComponentsList::PreDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CCheckListBox::PreDrawItem(lpDrawItemStruct);
}

bool CComponentsList::Load(const ConfigurationPtr& configuration)
{
	bool all_components_installed = true;

	ResetContent();

	CDC * pDC = GetDC();
	ASSERT(pDC);

	int hScrollWidth = 0;
	InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(configuration));
	CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");
    
	for each(const ComponentPtr& component in p_configuration->components)
	{
        bool component_installed = component->IsInstalled();
        
        LOG(L"-- " << component->description << L": " << component_installed ? L"INSTALLED" : L"NOT INSTALLED");

		if (component_installed)
		{
			component->selected = false;
		}

		all_components_installed &= component_installed;

		std::wstring l_descr = component->description;
	    l_descr += L" ";
        l_descr += component_installed
			? (component->status_installed.empty() ? p_configuration->status_installed : component->status_installed)
			: (component->status_notinstalled.empty() ? p_configuration->status_notinstalled : component->status_notinstalled);

        if (! p_configuration->dialog_show_installed && component_installed)
            continue;

        if (! p_configuration->dialog_show_required && component->required)
            continue;

		int id = AddString(l_descr.c_str());
		SetItemDataPtr(id, get(component));

        if (component->selected)
        {
			SetCheck(id, 1);
        }

        // a component is considered installed when it has an install check which results
        // in a clear positive; if a component doesn't have any install checks, it cannot
        // be required (there's no way to check whether the component was installed)
        if (component->required || component_installed)
        {
            Enable(id, 0);
        }

		CSize size = pDC->GetTextExtent(component->description.c_str());
		if ((size.cx > 0) && (hScrollWidth < size.cx))
			hScrollWidth = size.cx;
    }

	if (hScrollWidth > 0 )
	{
		SetHorizontalExtent(hScrollWidth);
	}

	ReleaseDC(pDC); 
	return all_components_installed;
}
