#include "StdAfx.h"
#include "ComponentsList.h"
#include "dotNetInstallerDlg.h"

CComponentsList::CComponentsList()
: m_pConfiguration(NULL)
, m_pExecuteCallback(NULL)
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

void CComponentsList::AddComponent(const ComponentPtr& component)
{
    int id = AddString(component->description.c_str());
    SetItemDataPtr(id, get(component));
    if (component->checked) SetCheck(id, 1);
    if (component->disabled) Enable(id, 0);

    CDC * pDC = GetDC();
    ASSERT(pDC);
    CSize size = pDC->GetTextExtent(component->GetDisplayName().c_str());
    if ((size.cx > 0) && (GetHorizontalExtent() < size.cx))
    {
        SetHorizontalExtent(size.cx);
    }
    ReleaseDC(pDC);
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
            if (m_pExecuteCallback)
            {
                m_pExecuteCallback->LoadComponentsList(false);
            }
        }
    }
    else if (nFlags & MK_SHIFT && nFlags && MK_LBUTTON)
    {
        BOOL bOutside = false;
        UINT uiItem = ItemFromPoint(point, bOutside);
        if (! bOutside)
        {
            ComponentPtr component = m_pConfiguration->GetComponentPtr((Component *) GetItemDataPtr(uiItem));			
            SetCheck(uiItem, ! GetCheck(uiItem));
        }
    }
}

void CComponentsList::Exec(const ComponentPtr& component)
{
    try
    {
        if (m_pExecuteCallback)
        {
            m_pExecuteCallback->OnExecBegin();
        }

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

        DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK | MB_ICONSTOP);
    }
}

void CComponentsList::SetExecuteCallback(CdotNetInstallerDlg * pExec)
{
    m_pExecuteCallback = pExec;
}

void CComponentsList::Load(InstallConfiguration * pConfiguration)
{
    m_pConfiguration = pConfiguration;
}
