#include "StdAfx.h"
#include "ComponentsList.h"

CComponentsList::CComponentsList()
{
}

IMPLEMENT_DYNAMIC(CComponentsList, CCheckListBox)

BEGIN_MESSAGE_MAP(CComponentsList, CCheckListBox) 
  ON_CONTROL_REFLECT(CLBN_CHKCHANGE, OnCheckChange)
  ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

void CComponentsList::OnCheckChange()
{
	this->Invalidate();
}

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

bool CComponentsList::Load(DVLib::LcidType lcidtype, const ConfigurationPtr& configuration)
{
	bool all = true;

	ResetContent();

	CDC * pDC = GetDC();
	ASSERT(pDC);

	int hScrollWidth = 0;
	m_pConfiguration = reinterpret_cast<InstallConfiguration *>(get(configuration));
	CHECK_BOOL(m_pConfiguration != NULL, L"Invalid configuration");
    
	Components components = m_pConfiguration->GetSupportedComponents(
		lcidtype, InstallerSession::Instance->sequence);

	for (size_t i = 0; i < components.size(); i++)
	{
		ComponentPtr component(components[i]);
		component->checked = true;
        bool component_installed = component->IsInstalled();
        
        LOG(L"-- " << component->id << L" (" << component->GetDisplayName() << L"): " 
			<< (component_installed ? L"INSTALLED" : L"NOT INSTALLED"));		

		// component selection
		if (component_installed && InstallerSession::Instance->sequence == SequenceInstall)
			component->checked = false;
		if (! component_installed && InstallerSession::Instance->sequence == SequenceUninstall)
			component->checked = false;

		if (InstallerSession::Instance->sequence == SequenceInstall)
			all &= component_installed;
		else if (InstallerSession::Instance->sequence == SequenceUninstall)
			all &= (! component_installed);

		std::wstring l_descr = component->GetDisplayName();
	    l_descr += L" ";
        l_descr += component_installed
			? (component->status_installed.empty() ? m_pConfiguration->status_installed : component->status_installed)
			: (component->status_notinstalled.empty() ? m_pConfiguration->status_notinstalled : component->status_notinstalled);

		// show installed
        if (InstallerSession::Instance->sequence == SequenceInstall 
			&& ! m_pConfiguration->dialog_show_installed 
			&& component_installed)
            continue;

		// show uninstalled
        if (InstallerSession::Instance->sequence == SequenceUninstall 
			&& ! m_pConfiguration->dialog_show_uninstalled
			&& ! component_installed)
            continue;

        if (! m_pConfiguration->dialog_show_required)
		{
			if (component->required_install && InstallerSession::Instance->sequence == SequenceInstall)
				continue;
			else if (component->required_uninstall && InstallerSession::Instance->sequence == SequenceUninstall)
				continue;
		}

		int id = AddString(l_descr.c_str());
		SetItemDataPtr(id, get(component));

        if (component->checked)
        {
			if (component->selected_install && InstallerSession::Instance->sequence == SequenceInstall)
				SetCheck(id, 1);
			else if (component->selected_uninstall && InstallerSession::Instance->sequence == SequenceUninstall)
				SetCheck(id, 1);
        }

        // a component is considered installed when it has an install check which results
        // in a clear positive; if a component doesn't have any install checks, it cannot
        // be required (there's no way to check whether the component was installed)
        if (InstallerSession::Instance->sequence == SequenceInstall 
			&& (component->required_install || component_installed))
            Enable(id, 0);
        else if (InstallerSession::Instance->sequence == SequenceUninstall 
			&& (component->required_uninstall || ! component_installed))
            Enable(id, 0);

		CSize size = pDC->GetTextExtent(component->GetDisplayName().c_str());
		if ((size.cx > 0) && (hScrollWidth < size.cx))
			hScrollWidth = size.cx;
    }

	if (hScrollWidth > 0 )
	{
		SetHorizontalExtent(hScrollWidth);
	}

	ReleaseDC(pDC); 
	return all;
}

void CComponentsList::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	if (nFlags & MK_CONTROL && nFlags && MK_LBUTTON)
	{
		BOOL bOutside = false;
		UINT uiItem = ItemFromPoint(point, bOutside);
		if (! bOutside)
		{
			ComponentPtr component = m_pConfiguration->GetComponentPtr((Component *) GetItemDataPtr(uiItem));
			Exec(component);
		}
	}
}

void CComponentsList::Exec(const ComponentPtr& component)
{
	try
	{
		LOG(L"--- Component '" << component->id << L"' (" << component->GetDisplayName() << L"): EXECUTING");
		
		if (m_pExecuteCallback && ! m_pExecuteCallback->OnComponentExecBegin(component))
			return;

		component->Exec();
		
		if (m_pExecuteCallback && ! m_pExecuteCallback->OnComponentExecWait(component))
			return;

		component->Wait();

		LOG(L"*** Component '" << component->id << L"' (" << component->GetDisplayName() << L"): SUCCESS");

		if (m_pExecuteCallback && ! m_pExecuteCallback->OnComponentExecSuccess(component))
			return;
	}
	catch(std::exception& ex)
	{
		LOG(L"*** Component '" << component->id << L"' (" << component->GetDisplayName() << L"): ERROR - " 
			<< DVLib::string2wstring(ex.what()));
		
		if (m_pExecuteCallback && ! m_pExecuteCallback->OnComponentExecError(component, ex))
			return;
	}
}

void CComponentsList::SetExecuteCallback(IExecuteCallback * pExec)
{
	m_pExecuteCallback = pExec;
}
