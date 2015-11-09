///////////////////////////////////////////////////////////////////////////
//				BrowseCtrl.cpp
//
// CBrowseCtrl is a CButton derived control used to let the user browse for
// files or folders on their systems.
//
// CBrowseCtrl integrates an edit-box and a browse-button together so the
// develops only need to maintain one control in their projects instead of two.

// Moreover, CBrowseCtrl draws its own "build-in" images on the browse-button
// without requiring the developers to include any extra icon, bitmap or other
// image resources.
//
// Written by Abin (abinn32@yahoo.com)
//
// History:
// 
// Jan 08, 2004 - Initial public release.
// Jan 09, 2004 - 1, Improved drawing functions to properly handle the case in
//                   which the control client area is too small to be drawn.
//                   In debug mode it will provide a message box to inform the
//                   developer about that issue.
//                2, Improved the edit box so it acts better upon receiving and
//                   losing the input focus. 
// Jan 10, 2004 - 1, Fixed a problem where the edit bix is not properly redrawn
//                   in some mouse events. Thanks to JOHN11.
//                2, Added method "GetSelectedCount" which returns the number of
//                   items the user has selected in the most recent file/folder
//                   dialog that was terminated by IDOK.
//                3, Improved the mouse/focus events monitoring functions.
//                4, Fixed a drawing glitch when the user clicks on the edges of
//                   the edit box.
//                5, Changed the drawing rects calculating methods for performance
//                   improvement.
// Jan 14, 2004 - 1, Updated "SetPathName" and "GetPathName" member functions.
//                2, Altered the message sending method so the lparam is now a
//                   pointer to this CBrowseCtrl object.
// Jan 22, 2004 - 1, Added methods to monitor whether the user has manually changed
//                   the contents of the edit box when BC_CTL_ALLOWEDIT is set. The
//                   return value of "GetPathName" will also be properly affected.
//                2, The window titles of file/folder dialogs can now be accessed
//                   by calling "SetDialogTitle" and "GetDialogTitle".
//                3, The banner text of folder dialogs can now be accessed by calling
//                   "SetDialogBanner" and "GetDialogBanner".
//                4, Added method "ModifyButtonStyle" to allow convenient style changing.
// Feb 07, 2004 - 1, Improved drawing functions so that images/text are partially drawn
//                   if there is not enough space.
//
/////////////////////////////////////////////////////////////////////////// 

#include "stdafx.h"
#include "BrowseCtrl.h"
#include <afxdlgs.h>
#include <string.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define ICON_WIDTH	16
#define ICON_HEIGHT	16
#define BTN_EDGE	2
#define WIDTH_SPACE	(BTN_EDGE * 2 + 7)

#define EDITCTRL_ID				12345
#define TOOLTIPCTRL_ID			12346
#define ID_TMR_MOUSEMONITOR		12347
#define ID_TMR_FOCUSMONITOR		12348

// color defines
#define BC_COLOR_WHITE	RGB(255, 255, 255)
#define BC_COLOR_BLACK	RGB(0, 0, 0)
#define BC_COLOR_DARK	RGB(128, 128, 128)
#define BC_COLOR_GRAY	RGB(192, 192, 192)
#define BC_COLOR_YELLOW	RGB(255, 255, 0)
#define BC_COLOR_BLUE	RGB(0, 0, 255)
#define BC_COLOR_OLIVE	RGB(128, 128, 0)
#define BC_COLOR_CYAN	RGB(0, 255, 255)
#define BC_COLOR_NAVY	RGB(0, 0, 128)

// maximum buffer length for retrieving pathname
#define MAX_SUM_PATHNAME	65535

// "CLineDraw" class is used for helping on drawing lines, the default behavior of
// CDC::LineTo on not drawing the last pixel could be extremely inconvenient in
// certain cases.
class CLineDraw
{
public:

    // Constructor
    CLineDraw(CDC* pDC, long lInitX = 0, long lInitY = 0)
    {
        ASSERT(pDC != NULL);
        m_pDC = pDC;
        m_ptCur.x = lInitX;
        m_ptCur.y = lInitY;
        m_ptInit.x = lInitX;
        m_ptInit.y = lInitY;
    }

    // Set the point the top-lect corner of the rect, offset the point,
    // then move dc to that point
    void InitOffsetMoveTo(long x, long y)
    {
        m_ptCur = m_ptInit;
        m_ptCur.Offset(x, y);
        m_pDC->MoveTo(m_ptCur);
    }

    // Offset the point and move dc to the point
    void OffsetMoveTo(long x, long y)
    {
        m_ptCur.Offset(x, y);
        m_pDC->MoveTo(m_ptCur);
    }

    // Offset the point and draw a line to the point, then set pixel at the point
    // using the color of current pen stored in the dc
    void OffsetLineTo(long x, long y)
    {
        m_ptCur.Offset(x, y);
        m_pDC->LineTo(m_ptCur);
        m_pDC->GetCurrentPen()->GetLogPen(&m_lgp);
        m_pDC->SetPixel(m_ptCur, m_lgp.lopnColor);
    }

private:
    CDC* m_pDC;
    CPoint m_ptCur;
    LOGPEN m_lgp;
    CPoint m_ptInit;
};

/////////////////////////////////////////////////////////////////////////////
// CBrowseCtrl Implementations
/////////////////////////////////////////////////////////////////////////////

CBrowseCtrl::CBrowseCtrl()
{
    m_dwStyle = BC_BTN_ICON | BC_ICO_ARROWFOLDER; // By default, the "arrow folder" icon is drawn on the browse button
    m_nSelCount = 0;
    m_bEditFocused = FALSE;
    m_nPathNamesLen = 0;
    m_bDlgPopped = FALSE;
    m_nNotifyMsg = 0;
    m_bOwnCreate = FALSE;
    m_bBtnPushed = FALSE;
    m_bMouseIn = FALSE;
    m_sTootipText = _T("Browse");
    m_sDlgBanner = _T("Please select a folder from the list:");
    m_bReadOnlyRef = FALSE;
    m_bOpenFileDialog = TRUE;
    m_dwFileFlags = OFN_ALLOWMULTISELECT | OFN_OVERWRITEPROMPT | OFN_CREATEPROMPT | OFN_ENABLESIZING | OFN_EXPLORER;
    m_nFolderFlags = BIF_RETURNONLYFSDIRS;
    m_sFilter = _T("All Files (*.*)|*.*||");
    m_lpszPathNames = NULL;
    m_bEditChanged = FALSE;
}

CBrowseCtrl::~CBrowseCtrl()
{
    if (m_lpszPathNames != NULL)
        delete [] m_lpszPathNames;
}

BEGIN_MESSAGE_MAP(CBrowseCtrl, CButton)
    //{{AFX_MSG_MAP(CBrowseCtrl)
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_TIMER()
    ON_WM_DESTROY()
    ON_WM_MOUSEMOVE()
    ON_WM_SETFOCUS()
    ON_WM_MOVE()
    ON_WM_SIZE()
    ON_WM_ENABLE()
    ON_WM_KEYDOWN()
    ON_WM_KEYUP()
    //}}AFX_MSG_MAP
    ON_EN_CHANGE(EDITCTRL_ID, OnChangeEdit)
END_MESSAGE_MAP()

void CBrowseCtrl::OnChangeEdit()
{
    if (!m_bDlgPopped && (m_dwStyle & BC_CTL_ALLOWEDIT))
    {
        // The user has changed the edit box contents manually
        m_wndEdit.GetWindowText(m_sEditText);
        m_bEditChanged = TRUE;
    }
}

void CBrowseCtrl::PreSubclassWindow() 
{
    // TODO: Add your specialized code here and/or call the base class
    CButton::PreSubclassWindow();
    if (!m_bOwnCreate)
        CreateCtrl(); // only create the edit/tooltip control once!
}

void CBrowseCtrl::SetButtonStyle(DWORD dwStyles)
{
    // Change the control style
    if (m_dwStyle != dwStyles)
    {
        m_dwStyle = dwStyles;
        if (::IsWindow(m_hWnd))
        {
            RecalculateRects();
            CreateEdit();
            RedrawWindow();
        }	
    }
}

DWORD CBrowseCtrl::GetButtonStyle() const
{
    return m_dwStyle;
}

BOOL CBrowseCtrl::CreateCtrl()
{
    if (!::IsWindow(m_hWnd))
        return FALSE;

    RecalculateRects();

    // Move window text from actual window to the fake button
    if (m_sButtonText.IsEmpty())
        CButton::GetWindowText(m_sButtonText);
    CButton::SetWindowText(_T(""));

    if (!CreateEdit())
    {
        ASSERT(FALSE);
        return FALSE;
    }

    // Create tooltip control
    if (!m_wndTooltip.Create(this))
    {
        ASSERT(FALSE);
        return FALSE;
    }

    m_wndTooltip.AddTool(this, m_sTootipText, m_rcButton, TOOLTIPCTRL_ID);
    SetTimer(ID_TMR_FOCUSMONITOR, 1, NULL);
    return TRUE;
}

void CBrowseCtrl::OnPaint() 
{
    CPaintDC dc(this); // device context for painting
    COLORREF bkColor = ::GetSysColor(COLOR_BTNFACE);

    // TODO: Add your message handler code here
    DrawButtonFrame(&dc, bkColor);

    // Draw text or different images on the browse button
    CRect rect = m_rcContent;

    // If the button is pushed down, make it look sunken.
    if (m_bBtnPushed)
        rect.OffsetRect(1, 1);

    if (m_dwStyle & BC_BTN_ICON)
    {
        if (m_dwStyle & BC_ICO_ARROWFOLDER)
        {
            DrawButtonArrowFolder(&dc, bkColor, rect);
        }
        else if (m_dwStyle & BC_ICO_FOLDER)
        {
            DrawButtonFolder(&dc, bkColor, rect);
        }
        else if (m_dwStyle & BC_ICO_EXPLORER)
        {
            DrawButtonExplorer(&dc, bkColor, rect);
        }
        else 
        {
            // Do we have any other stuff to draw?
        }
    }
    else
    {
        DrawButtonText(&dc, bkColor, rect);
    }
}

void CBrowseCtrl::OnSetFocus(CWnd* pOldWnd) 
{
    KillTimer(ID_TMR_FOCUSMONITOR);
    if (!m_bEditFocused && pOldWnd != &m_wndEdit)
    {
        CButton::OnSetFocus(pOldWnd);
        m_wndEdit.SetFocus();
        m_wndEdit.SetSel(0, -1);
        m_bEditFocused = TRUE;
    }
    SetTimer(ID_TMR_FOCUSMONITOR, 1, NULL);
}

void CBrowseCtrl::OnSetEditFocus()
{
    m_wndEdit.SetSel(0, -1);
}

void CBrowseCtrl::OnKillEditFocus()
{
    m_wndEdit.SetSel(-1, -1);
}

int CBrowseCtrl::DoModal()
{
    // Popup the file/folder dialog
    if (m_bDlgPopped)
        return IDCANCEL;

    m_bDlgPopped = TRUE;

    // Either popup a file dialog, or a folder dialog
    int nRes = (m_dwStyle & BC_CTL_FOLDERSONLY) ? FolderDoModal() : FileDoModal();

    if (m_nNotifyMsg > 0)
        GetParent()->SendMessage(m_nNotifyMsg, (WPARAM)nRes, (LPARAM)this);

    m_bDlgPopped = FALSE;
    return nRes;
}

int CBrowseCtrl::GetSelectedCount() const
{
    return m_nSelCount;
}

void CBrowseCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default
    CButton::OnLButtonDown(nFlags, point);
    if (m_rcButton.PtInRect(point))
    {
        OnKillEditFocus();
        SetCapture();
        m_bBtnPushed = TRUE;
    }
    RedrawWindow();
}

void CBrowseCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default
    CButton::OnLButtonUp(nFlags, point);
    if (GetCapture() == this)	
    {
        ReleaseCapture();
        m_bBtnPushed = FALSE;
        RedrawWindow(&m_rcButton);

        if (m_rcButton.PtInRect(point))
            OnButtonClicked();
    }
}

void CBrowseCtrl::DrawButtonFrame(CDC *pDC, COLORREF bkColor) const
{
    CRect rect = m_rcButton;
    pDC->FillSolidRect(&rect, bkColor);

    if (m_dwStyle & BC_BTN_FLAT)
    {
        if (m_bBtnPushed)
        {
            pDC->Draw3dRect(rect, ::GetSysColor(COLOR_3DDKSHADOW), ::GetSysColor(COLOR_3DHIGHLIGHT));
        }
        else
        {
            if (m_bMouseIn)
                pDC->Draw3dRect(rect, ::GetSysColor(COLOR_3DHIGHLIGHT), ::GetSysColor(COLOR_3DSHADOW));
        }
    }
    else
    {
        if (!m_bBtnPushed)
        {
            pDC->Draw3dRect(rect, ::GetSysColor(COLOR_3DHIGHLIGHT), ::GetSysColor(COLOR_3DDKSHADOW));
            rect.DeflateRect(1, 1);
            pDC->Draw3dRect(rect, ::GetSysColor(COLOR_3DLIGHT), ::GetSysColor(COLOR_3DSHADOW));
        }
        else
        {
            pDC->Draw3dRect(rect, ::GetSysColor(COLOR_3DDKSHADOW), ::GetSysColor(COLOR_3DDKSHADOW));
            rect.DeflateRect(1, 1);
            pDC->Draw3dRect(rect, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
        }
    }	
}

BOOL CBrowseCtrl::PreTranslateMessage(MSG* pMsg) 
{
    // TODO: Add your specialized code here and/or call the base class
    m_wndTooltip.RelayEvent(pMsg);

    // Popup the file/folder dialog when user hits "Enter" key when the
    // control window is active
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
    {
        OnButtonClicked();
        return TRUE;
    }

    return CButton::PreTranslateMessage(pMsg);
}

void CBrowseCtrl::OnTimer(UINT nIDEvent) 
{
    // TODO: Add your message handler code here and/or call default
    if (nIDEvent == ID_TMR_MOUSEMONITOR)
    {
        // monitors mouse enter/leave events
        if (m_bMouseIn)
        {
            POINT pt;
            ::GetCursorPos(&pt);
            CRect rect = m_rcButton;
            ClientToScreen(&rect);
            if (!rect.PtInRect(pt))
            {
                KillTimer(ID_TMR_MOUSEMONITOR);
                m_bMouseIn = FALSE;
                OnMouseLeave();
            }
        }
    }
    else if (nIDEvent == ID_TMR_FOCUSMONITOR)
    {
        // monitors control focus events
        if (GetFocus() != &m_wndEdit)
        {
            if (m_bEditFocused)
            {
                m_bEditFocused = FALSE;
                OnKillEditFocus();
            }
        }
        else
        {
            if (!m_bEditFocused)
            {
                m_bEditFocused = TRUE;
                OnSetEditFocus();
            }
        }
    }

    CButton::OnTimer(nIDEvent);
}

void CBrowseCtrl::OnDestroy() 
{
    KillTimer(ID_TMR_MOUSEMONITOR);
    KillTimer(ID_TMR_FOCUSMONITOR);
    m_wndEdit.DestroyWindow();
    m_wndTooltip.DestroyWindow();
    CButton::OnDestroy();
}

void CBrowseCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default	
    CButton::OnMouseMove(nFlags, point);
    if (!m_bMouseIn && m_rcButton.PtInRect(point))
    {
        m_bMouseIn = TRUE;
        if (GetCapture() == this)
            m_bBtnPushed = TRUE;
        SetTimer(ID_TMR_MOUSEMONITOR, 1, NULL);
        OnMouseEnter();
    }
}

void CBrowseCtrl::OnMouseEnter()
{
    RedrawWindow(&m_rcButton);
}

void CBrowseCtrl::OnMouseLeave()
{
    m_bBtnPushed = FALSE;
    RedrawWindow();
}

void CBrowseCtrl::SetTooltipText(LPCTSTR lpszText)
{
    m_sTootipText = lpszText;
    if (::IsWindow(m_hWnd))
        m_wndTooltip.UpdateTipText(lpszText, this, TOOLTIPCTRL_ID);
}

void CBrowseCtrl::SetWindowText(LPCTSTR lpszString)
{
    SetButtonText(lpszString);
}

int CBrowseCtrl::GetWindowText(LPTSTR lpszStringBuf, int nMaxCount) const
{
    if (lpszStringBuf == NULL)
        return 0;
    _tcsncpy_s(lpszStringBuf, nMaxCount, m_sButtonText, nMaxCount);
    return _tcslen(lpszStringBuf);
}

void CBrowseCtrl::GetWindowText(CString &rString) const
{
    rString = GetButtonText();
}

BOOL CBrowseCtrl::CreateEdit()
{
    if (!::IsWindow(m_hWnd))
    {
        ASSERT(FALSE);
        return FALSE;
    }

    CString str;
    if (::IsWindow(m_wndEdit.m_hWnd))
    {
        m_wndEdit.GetWindowText(str);
        m_wndEdit.DestroyWindow();
    }

    DWORD dwStyle = ES_AUTOHSCROLL | ES_NOHIDESEL | WS_CHILD | WS_VISIBLE;
    if ((m_dwStyle & BC_CTL_ALLOWEDIT) == 0)
        dwStyle |= ES_READONLY;

    if (GetStyle() & WS_DISABLED)
        dwStyle |= WS_DISABLED;

    m_wndEdit.m_hWnd = NULL;
    if (!m_wndEdit.CreateEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL, dwStyle, m_rcEdit, this, EDITCTRL_ID, NULL))
    {
        ASSERT(FALSE);
        return FALSE;
    }
    m_wndEdit.SetMargins(1, 1);
    m_wndEdit.SetFont(GetFont());
    m_wndEdit.SetWindowText(str);
    m_wndEdit.ShowWindow(SW_SHOW);
    return TRUE;
}

void CBrowseCtrl::SetNotifyMessageID(UINT nNotifyMsgID)
{
    m_nNotifyMsg = nNotifyMsgID;
}

UINT CBrowseCtrl::GetNotifyMessageID() const
{
    return m_nNotifyMsg;
}

void CBrowseCtrl::SetOpenSave(BOOL bOpen)
{
    m_bOpenFileDialog = bOpen;
}

BOOL CBrowseCtrl::GetOpenSave() const
{
    return m_bOpenFileDialog;
}

void CBrowseCtrl::SetDefExt(LPCTSTR lpszDefExt)
{
    m_sDefExt = lpszDefExt;
}

CString CBrowseCtrl::GetDefExt() const
{
    return m_sDefExt;
}

void CBrowseCtrl::SetFileFlags(DWORD dwFlags)
{
    m_dwFileFlags = dwFlags | OFN_EXPLORER;
}

DWORD CBrowseCtrl::GetFileFlags() const
{
    return m_dwFileFlags;
}

void CBrowseCtrl::SetFilter(LPCTSTR lpszFilter)
{
    m_sFilter = lpszFilter;
}

CString CBrowseCtrl::GetFilter() const
{
    return m_sFilter;
}

CString CBrowseCtrl::GetTooltipText() const
{	
    return m_sTootipText;
}

CString CBrowseCtrl::GetPathName() const
{
    return IsEditManuallyChanged() ? m_sEditText : CString(m_lpszPathNames);
}

CString CBrowseCtrl::GetFileName() const
{
    if (m_dwStyle & BC_CTL_FOLDERSONLY)
        return _T("");

    CString str;
    SplitPath(GetPathName(), NULL, NULL, &str, NULL, NULL);
    return str;
}

CString CBrowseCtrl::GetFileExt() const
{
    if (m_dwStyle & BC_CTL_FOLDERSONLY)
        return _T("");

    CString str;
    SplitPath(GetPathName(), NULL, NULL, NULL, NULL, &str);
    return str;
}

CString CBrowseCtrl::GetFileTitle() const
{
    if (m_dwStyle & BC_CTL_FOLDERSONLY)
        return _T("");

    CString str;
    SplitPath(GetPathName(), NULL, NULL, NULL, &str, NULL);
    return str;
}

POSITION CBrowseCtrl::GetStartPosition() const
{
    if (IsEditManuallyChanged())
        return m_sEditText.IsEmpty() ? NULL : (POSITION)(LPCTSTR)m_sEditText;
    else
        return (m_lpszPathNames == NULL || m_lpszPathNames[0] == _T('\0')) ? NULL : (POSITION)(LPCTSTR)m_lpszPathNames;
}

CString CBrowseCtrl::GetNextPathName(POSITION &pos) const
{
    // Make sure pos is a valid position
    if (pos == NULL)
        return _T("");

    if (IsEditManuallyChanged())
    {
        // contents of the edit box has been changed by direct user input
        POSITION posOrig = pos;
        pos = NULL;
        return (DWORD)posOrig == (DWORD)(LPCTSTR)m_sEditText ? m_sEditText : _T("");
    }

    if (m_lpszPathNames == NULL
        || m_nPathNamesLen == 0
        || m_nSelCount == 0
        || (DWORD)pos < (DWORD)m_lpszPathNames
        || (DWORD)pos >= (DWORD)m_lpszPathNames + (DWORD)m_nPathNamesLen)
    {
        pos = NULL;
        return _T("");
    }

    LPCTSTR p = (LPCTSTR)pos;
    const int LEN = _tcslen(p);
    if (LEN == 0)
    {
        pos = NULL;
        return _T("");
    }
    else
    {
        pos = (POSITION)(&p[LEN + 1]); // Advance the pointer to next file name
        return p;
    }
}

BOOL CBrowseCtrl::GetReadOnlyPref() const
{
    return m_bReadOnlyRef;
}

BOOL CBrowseCtrl::Create(const RECT& rect, CWnd* pParentWnd, UINT nID, DWORD dwBtnStyles, UINT nNotifyMessageID) 
{
    // TODO: Add your specialized code here and/or call the base class
    if (pParentWnd == NULL)
    {
        pParentWnd = AfxGetMainWnd();
        if (pParentWnd == NULL)
        {
            ASSERT(FALSE);
            return FALSE;
        }
    }

    m_bOwnCreate = TRUE;
    m_nNotifyMsg = nNotifyMessageID;

    if (!CButton::Create(_T(""), WS_CHILD|WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, rect, pParentWnd, nID))
    {
        ASSERT(FALSE);
        return FALSE;
    }

    m_dwStyle = dwBtnStyles;
    return CreateCtrl();
}

void CBrowseCtrl::SetPathName(LPCTSTR lpszPathName)
{
    if (::IsWindow(m_wndEdit.m_hWnd))
        m_wndEdit.SetWindowText(lpszPathName);

    if (m_lpszPathNames != NULL)
    {
        delete [] m_lpszPathNames;
        m_lpszPathNames = NULL;
    }

    if (lpszPathName != NULL)
        m_lpszPathNames = _tcsdup(lpszPathName);
}

int CBrowseCtrl::BrowseCallbackProc(HWND hwnd, UINT nMsg, LPARAM lParam, LPARAM lpData)
{	
    lParam = 0; // Appeases VC6 warning level 4.
    CBrowseCtrl* pCtrl = reinterpret_cast<CBrowseCtrl*>(lpData);
    if (pCtrl == NULL)
        return 0;

    if (nMsg == BFFM_INITIALIZED)
    {
        if (!pCtrl->m_sDlgTitle.IsEmpty())
            ::SetWindowText(hwnd, pCtrl->m_sDlgTitle);

        CString sPathName = pCtrl->GetPathName();
        if (!sPathName.IsEmpty())
            ::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM)(LPCTSTR)sPathName);
    }

    return 0;
}

void CBrowseCtrl::SetFolderFlags(UINT nFlags)
{
    m_nFolderFlags = nFlags;
}

UINT CBrowseCtrl::GetFolderFlags() const
{
    return m_nFolderFlags;
}

int CBrowseCtrl::FolderDoModal()
{
    // Popup the folder dialog
    TCHAR szPathName[MAX_PATH + 1] = _T("");
    BROWSEINFO bi;
    memset(&bi, 0, sizeof(BROWSEINFO)); 

    bi.hwndOwner = ::GetParent(m_hWnd);
    bi.pszDisplayName = szPathName;
    bi.lpszTitle = m_sDlgBanner;
    bi.ulFlags = m_nFolderFlags;
    bi.lpfn = BrowseCallbackProc;
    bi.lParam = (LPARAM)this;
    LPITEMIDLIST pItemIDList = ::SHBrowseForFolder(&bi);
    if (pItemIDList == NULL)
        return IDCANCEL;

    m_nSelCount = 1;
    if (m_lpszPathNames != NULL)
    {
        delete [] m_lpszPathNames;
        m_lpszPathNames = NULL;
    }
    m_lpszPathNames = new TCHAR[MAX_PATH + 2];
    memset(m_lpszPathNames, 0, (MAX_PATH + 2) * sizeof(TCHAR));
    ::SHGetPathFromIDList(pItemIDList, m_lpszPathNames);

    IMalloc* pMalloc = NULL;
    if(SUCCEEDED(::SHGetMalloc(&pMalloc)))
    {
        pMalloc->Free(pItemIDList);
        pMalloc->Release();
    }

    m_nPathNamesLen = _tcslen(m_lpszPathNames);
    m_bReadOnlyRef = FALSE;

    if (::IsWindow(m_wndEdit.m_hWnd))
    {
        m_wndEdit.SetWindowText(m_lpszPathNames);
        m_wndEdit.SetSel(0, -1);
    }

    m_bEditChanged = FALSE; // Discard previously changes made to the edit control
    m_sEditText = m_lpszPathNames;
    return IDOK;
}	

int CBrowseCtrl::FileDoModal()
{
    CFileDialog dlg(m_bOpenFileDialog, m_sDefExt, GetPathName(), m_dwFileFlags, m_sFilter, ::IsWindow(m_hWnd) ? GetParent() : NULL);
    dlg.m_ofn.lpstrTitle = m_sDlgTitle; // display dialog title

    // ***** To make the buffer less likely to be too small *****
    // The buffer allocates 64KB heap memory and frees it before this function ends.
    // Of course 64KB is a serious overkill in most cases, but the memory usage is
    // just temporary. As soon as the actual usage is determined, the wasted memory
    // will be redeemed immediately.
    LPTSTR pszLargeBuffer = new TCHAR[MAX_SUM_PATHNAME + 1];
    ASSERT(pszLargeBuffer != NULL);
    pszLargeBuffer[0] = _T('\0');

    // Make the struct use our buffer instead of its own(which was allocated in the
    // stack so no need to be taken care of)
    dlg.m_ofn.lpstrFile = pszLargeBuffer;
    dlg.m_ofn.nMaxFile = MAX_SUM_PATHNAME;

    if (dlg.DoModal() != IDOK)
    {
        delete [] pszLargeBuffer;
        return IDCANCEL;
    }

    if (m_lpszPathNames != NULL)
    {
        delete [] m_lpszPathNames;
        m_lpszPathNames = NULL;
    }

    POSITION pos = dlg.GetStartPosition();

    // determine the string length
    m_nSelCount = 0;
    m_nPathNamesLen = 0;
    while (pos != NULL)
    {
        m_nSelCount++;
        m_nPathNamesLen += dlg.GetNextPathName(pos).GetLength() + 1;
    }

    m_nPathNamesLen++;
    m_lpszPathNames = new TCHAR[m_nPathNamesLen];

    // copy the string
    LPTSTR lpDes = m_lpszPathNames;
    pos = dlg.GetStartPosition();
    while (pos != NULL)
    {
        CString str = dlg.GetNextPathName(pos);
        _tcscpy_s(lpDes, m_nPathNamesLen, str);			
        lpDes = &lpDes[str.GetLength() + 1];
    }
    m_lpszPathNames[m_nPathNamesLen - 1] = _T('\0');

    // Now the "ugly large buffer" is no longer useful, free it.
    delete [] pszLargeBuffer;

    m_bReadOnlyRef = dlg.GetReadOnlyPref();

    if (::IsWindow(m_wndEdit.m_hWnd))
    {
        m_wndEdit.SetWindowText(m_lpszPathNames);
        m_wndEdit.SetSel(0, -1);
    }

    m_bEditChanged = FALSE; // Discard previously changes made to the edit control
    m_sEditText = m_lpszPathNames;

    return IDOK;
}

void CBrowseCtrl::SetDialogTitle(LPCTSTR lpszTitle)
{
    m_sDlgTitle = lpszTitle;
}

CString CBrowseCtrl::GetDialogTitle() const
{
    return m_sDlgTitle;
}

void CBrowseCtrl::SetButtonText(LPCTSTR lpszText)
{
    m_sButtonText = lpszText;
    if ((m_dwStyle & BC_BTN_ICON) == 0 && ::IsWindow(m_hWnd))
    {
        RecalculateRects();
        CreateEdit();
        RedrawWindow();
    }
}

CString CBrowseCtrl::GetButtonText() const
{
    return m_sButtonText;
}

void CBrowseCtrl::DrawButtonText(CDC *pDC, COLORREF bkColor, const CRect& rect) const
{	
    if (m_sButtonText.IsEmpty() || rect.IsRectEmpty())
        return;

    CDC memDC;
    CBitmap bmp;
    PrepareMemDC(&memDC, &bmp, pDC, rect, bkColor);

    memDC.SelectObject(GetFont());
    memDC.SetBkMode(TRANSPARENT);

    if (GetStyle() & WS_DISABLED)
    {
        memDC.SetTextColor(::GetSysColor(COLOR_3DHIGHLIGHT));
        memDC.TextOut(1, 1, m_sButtonText);
        memDC.SetTextColor(::GetSysColor(COLOR_3DSHADOW));
        memDC.TextOut(0, 0, m_sButtonText);
    }
    else
    {
        memDC.SetTextColor(::GetSysColor(COLOR_BTNTEXT));
        memDC.TextOut(0, 0, m_sButtonText);
    }	

    // bitblt to screen
    pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

    // cleanup
    bmp.DeleteObject();
}

void CBrowseCtrl::DrawButtonArrowFolder(CDC *pDC, COLORREF bkColor, const CRect& rect) const
{
    CDC memDC;
    CBitmap bmp;
    PrepareMemDC(&memDC, &bmp, pDC, rect, bkColor);

    CLineDraw ld(&memDC);
    const BOOL DISABLED = (GetStyle() & WS_DISABLED) != 0;
    int i = 0;

    CPen blackPen, whitePen, yellowPen, olivePen;
    blackPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_DARK : BC_COLOR_BLACK);
    whitePen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_WHITE : BC_COLOR_WHITE);
    yellowPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_GRAY : BC_COLOR_YELLOW);
    olivePen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_DARK : BC_COLOR_OLIVE);

    // black frame
    memDC.SelectObject(&blackPen);
    ld.InitOffsetMoveTo(1, 13);
    ld.OffsetLineTo(10, 0);
    ld.OffsetLineTo(4, -4);
    ld.OffsetLineTo(0, -1);
    ld.OffsetLineTo(-9, 0);
    ld.OffsetLineTo(-5, 5);
    ld.OffsetLineTo(0, -8);
    ld.OffsetLineTo(1, -1);
    ld.OffsetLineTo(2, 0);
    ld.OffsetLineTo(1, 1);
    ld.OffsetLineTo(6, 0);
    ld.OffsetLineTo(0, 2);

    // top bending arrow
    ld.InitOffsetMoveTo(9, 2);
    ld.OffsetLineTo(1, -1);
    ld.OffsetLineTo(2, 0);
    ld.OffsetLineTo(2, 2);
    ld.OffsetMoveTo(1, -1);
    ld.OffsetLineTo(0, 2);
    ld.OffsetLineTo(-2, 0);

    // Olive patterns
    memDC.SelectObject(&olivePen);
    ld.InitOffsetMoveTo(6, 9);

    for (i = 0; i < 4; i++)
    {
        ld.OffsetLineTo(8, 0);
        ld.OffsetMoveTo(-9, 1);
    }

    // yellow patterns
    memDC.SelectObject(&yellowPen);
    ld.InitOffsetMoveTo(2, 6);
    ld.OffsetLineTo(1, -1);
    ld.InitOffsetMoveTo(2, 8);
    ld.OffsetLineTo(2, -2);
    ld.InitOffsetMoveTo(2, 10);
    ld.OffsetLineTo(4, -4);
    ld.OffsetLineTo(1, 1);
    ld.OffsetLineTo(1, -1);
    ld.OffsetLineTo(1, 1);
    ld.OffsetLineTo(1, -1);

    // white patterns
    memDC.SelectObject(&whitePen);
    ld.InitOffsetMoveTo(2, 5);
    ld.OffsetLineTo(0, 0);
    ld.OffsetMoveTo(0, 2);
    ld.OffsetLineTo(2, -2);
    ld.InitOffsetMoveTo(2, 9);
    ld.OffsetLineTo(3, -3);
    ld.InitOffsetMoveTo(2, 11);
    ld.OffsetLineTo(5, -5);
    ld.OffsetLineTo(1, 1);
    ld.OffsetLineTo(1, -1);
    ld.OffsetLineTo(1, 1);

    // Bitblt to screen
    pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

    // Cleanup
    blackPen.DeleteObject();
    whitePen.DeleteObject();
    yellowPen.DeleteObject();
    olivePen.DeleteObject();
    bmp.DeleteObject();
}

void CBrowseCtrl::DrawButtonFolder(CDC *pDC, COLORREF bkColor, const CRect& rect) const
{
    CDC memDC;
    CBitmap bmp;
    PrepareMemDC(&memDC, &bmp, pDC, rect, bkColor);

    CLineDraw ld(&memDC);
    const BOOL DISABLED = (GetStyle() & WS_DISABLED) != 0;
    int i = 0;

    CPen blackPen, whitePen, yellowPen, darkPen, grayPen;
    blackPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_DARK : BC_COLOR_BLACK);
    whitePen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_WHITE : BC_COLOR_WHITE);
    yellowPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_GRAY : BC_COLOR_YELLOW);
    darkPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_DARK : BC_COLOR_DARK);
    grayPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_GRAY : BC_COLOR_GRAY);

    // right side black part
    memDC.SelectObject(&blackPen);
    ld.InitOffsetMoveTo(15, 4);
    ld.OffsetLineTo(0, 9);
    ld.OffsetLineTo(-12, 0);
    ld.OffsetMoveTo(11, -1);
    ld.OffsetLineTo(-2, -5);

    // front white part
    memDC.SelectObject(&whitePen);
    ld.InitOffsetMoveTo(3, 12);
    ld.OffsetLineTo(-2, -5);
    ld.OffsetLineTo(9, 0);

    // front dark frame
    memDC.SelectObject(&darkPen);
    ld.InitOffsetMoveTo(13, 11);
    ld.OffsetLineTo(0, 1);
    ld.OffsetLineTo(-11, 0);
    ld.OffsetLineTo(-2, -5);
    ld.OffsetLineTo(0, -1);
    ld.OffsetLineTo(12, 0);
    ld.OffsetLineTo(-1, 1);
    ld.OffsetMoveTo(2, 1);
    ld.OffsetLineTo(-1, 1);

    // front gray patterns
    memDC.SelectObject(&grayPen);
    ld.InitOffsetMoveTo(2, 8);
    ld.OffsetLineTo(3, 3);

    for (i = 0; i < 5; i++)
    {
        ld.InitOffsetMoveTo(i * 2 + 2, 8);
        if (i == 4)
            ld.OffsetLineTo(2, 2);
        else
            ld.OffsetLineTo(3, 3);
    }

    // front yellow patterns
    memDC.SelectObject(&yellowPen);
    ld.InitOffsetMoveTo(3, 10);
    ld.OffsetLineTo(1, 1);

    for (i = 0; i < 5; i++)
    {
        ld.InitOffsetMoveTo(3 + i * 2, 8);
        if (i == 4)
            ld.OffsetLineTo(0, 0);
        else
            ld.OffsetLineTo(3, 3);
    }

    // rear dark frame
    memDC.SelectObject(&darkPen);
    ld.InitOffsetMoveTo(1, 5);
    ld.OffsetLineTo(0, -2);
    ld.OffsetLineTo(2, -2);
    ld.OffsetLineTo(4, 0);
    ld.OffsetLineTo(2, 2);
    ld.OffsetLineTo(5, 0);
    ld.OffsetLineTo(0, 7);

    // rear white part
    memDC.SelectObject(&whitePen);
    ld.InitOffsetMoveTo(2, 5);
    ld.OffsetLineTo(0, -2);
    ld.OffsetLineTo(1, -1);
    ld.OffsetLineTo(4, 0);
    ld.OffsetLineTo(2, 2);
    ld.OffsetLineTo(4, 0);

    // rear gray patterns
    memDC.SelectObject(&grayPen);
    ld.InitOffsetMoveTo(3, 5);
    ld.OffsetLineTo(0, 0);

    for (i = 0; i < 3; i++)
    {
        ld.InitOffsetMoveTo(3 + i * 2, 3);
        ld.OffsetLineTo(2, 2);
    }

    ld.InitOffsetMoveTo(11, 5);
    ld.OffsetLineTo(0, 0);
    ld.OffsetMoveTo(2, 0);
    ld.OffsetLineTo(0, 0);
    ld.OffsetMoveTo(0, 2);
    ld.OffsetLineTo(0, 0);

    // rear yellow patterns
    memDC.SelectObject(&yellowPen);
    for (i = 0; i < 5; i++)
    {
        ld.InitOffsetMoveTo(4 + i * 2, 5);
        if (i == 0)
            ld.OffsetLineTo(-1, -1);		
        else if (i == 3)
            ld.OffsetLineTo(0, 0);
        else if (i == 4)
            ld.OffsetLineTo(1, 1);
        else
            ld.OffsetLineTo(-2, -2);
    }

    // bitblt to screen
    pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

    // clean up
    blackPen.DeleteObject();
    whitePen.DeleteObject();
    yellowPen.DeleteObject();
    darkPen.DeleteObject();
    grayPen.DeleteObject();
    bmp.DeleteObject();
}

void CBrowseCtrl::DrawButtonExplorer(CDC *pDC, COLORREF bkColor, const CRect& rect) const
{
    CDC memDC;
    CBitmap bmp;
    PrepareMemDC(&memDC, &bmp, pDC, rect, bkColor);

    CLineDraw ld(&memDC);
    const BOOL DISABLED = (GetStyle() & WS_DISABLED) != 0;
    int i = 0;

    CPen blackPen, whitePen, yellowPen, darkPen, grayPen, olivePen, cyanPen, bluePen, navyPen;
    blackPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_DARK : BC_COLOR_BLACK);
    whitePen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_WHITE : BC_COLOR_WHITE);
    yellowPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_GRAY : BC_COLOR_YELLOW);
    darkPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_DARK : BC_COLOR_DARK);
    grayPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_GRAY : BC_COLOR_GRAY);
    olivePen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_GRAY : BC_COLOR_OLIVE);
    cyanPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_WHITE : BC_COLOR_CYAN);
    bluePen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_DARK : BC_COLOR_BLUE);
    navyPen.CreatePen(PS_SOLID, 1, DISABLED ? BC_COLOR_DARK : BC_COLOR_NAVY);

    // top-left dark frame
    memDC.SelectObject(&darkPen);
    ld.InitOffsetMoveTo(0, 11);
    ld.OffsetLineTo(0, -9);
    ld.OffsetLineTo(2, -2);
    ld.OffsetLineTo(4, 0);
    ld.OffsetLineTo(2, 2);
    ld.OffsetLineTo(5, 0);

    // scope dark border
    ld.InitOffsetMoveTo(8, 9);
    ld.OffsetLineTo(-1, 1);
    ld.OffsetLineTo(-3, 0);
    ld.OffsetLineTo(-2, -2);
    ld.OffsetLineTo(0, -2);
    ld.OffsetLineTo(2, -2);
    ld.OffsetLineTo(3, 0);
    ld.OffsetLineTo(2, 2);

    // black lines
    memDC.SelectObject(&blackPen);
    ld.InitOffsetMoveTo(14, 3);
    ld.OffsetLineTo(0, 8);
    ld.OffsetLineTo(-1, 1);
    ld.OffsetLineTo(1, 1);
    ld.OffsetLineTo(0, 1);
    ld.OffsetLineTo(-1, 1);
    ld.OffsetLineTo(-1, 0);
    ld.OffsetMoveTo(-4, -3);
    ld.OffsetLineTo(-7, 0);
    ld.OffsetMoveTo(4, -2);
    ld.OffsetLineTo(1, 0);
    ld.OffsetLineTo(2, -2);
    ld.OffsetLineTo(0, -2);
    ld.OffsetLineTo(-2, -2);

    // yellow lines
    memDC.SelectObject(&yellowPen);
    ld.InitOffsetMoveTo(2, 10);
    ld.OffsetLineTo(0, 0);
    ld.InitOffsetMoveTo(2, 4);
    ld.OffsetLineTo(0, -2);
    ld.OffsetLineTo(1, -1);
    ld.OffsetLineTo(1, 1);
    ld.OffsetLineTo(1, -1);
    ld.OffsetLineTo(7, 7);
    ld.OffsetMoveTo(-2, 0);
    ld.OffsetLineTo(2, 2);
    ld.OffsetMoveTo(0, -4);
    ld.OffsetLineTo(-2, -2);
    ld.OffsetMoveTo(2, 0);
    ld.OffsetLineTo(0, 0);

    // gray parts
    memDC.SelectObject(&grayPen);
    ld.InitOffsetMoveTo(1, 2);

    int q = -1;
    for (i = 0; i < 5; i++, q = -q)
        ld.OffsetLineTo(1, q);

    ld.OffsetLineTo(7, 7);
    ld.OffsetMoveTo(0, -2);
    ld.OffsetLineTo(-1, -1);
    ld.OffsetMoveTo(-1, 3);
    ld.OffsetLineTo(2, 2);
    ld.OffsetMoveTo(-4, 1);
    ld.OffsetLineTo(0, 0);
    ld.OffsetMoveTo(-2, -1);
    ld.OffsetLineTo(1, -1);
    ld.OffsetMoveTo(0, -2);
    ld.OffsetLineTo(-4, 4);
    ld.OffsetLineTo(-1, -1);
    ld.OffsetMoveTo(0, -4);
    ld.OffsetLineTo(1, -1);

    // white parts
    memDC.SelectObject(&whitePen);
    ld.InitOffsetMoveTo(1, 10);
    ld.OffsetLineTo(0, -7);
    ld.OffsetLineTo(11, 0);
    ld.InitOffsetMoveTo(3, 6);
    ld.OffsetLineTo(1, -1);
    ld.OffsetMoveTo(2, 0);
    ld.OffsetLineTo(-3, 3);

    // Olive parts
    memDC.SelectObject(&olivePen);
    ld.InitOffsetMoveTo(13, 3);
    ld.OffsetLineTo(0, 8);
    ld.OffsetLineTo(-1, 0);
    ld.OffsetLineTo(-2, -2);
    ld.OffsetLineTo(-1, 0);
    ld.OffsetLineTo(0, -2);
    ld.OffsetMoveTo(-1, 4);
    ld.OffsetLineTo(-6, 0);

    // Cyan parts
    memDC.SelectObject(&cyanPen);
    ld.InitOffsetMoveTo(5, 5);
    ld.OffsetLineTo(-2, 2);
    ld.OffsetLineTo(2, 2);
    ld.OffsetLineTo(2, -2);
    ld.OffsetLineTo(-1, -1);
    ld.OffsetLineTo(-1, 1);
    ld.InitOffsetMoveTo(9, 11);
    ld.OffsetLineTo(3, 3);

    // Navy parts
    memDC.SelectObject(&navyPen);
    ld.InitOffsetMoveTo(8, 11);
    ld.OffsetLineTo(3, 3);

    // Blue parts
    memDC.SelectObject(&bluePen);
    ld.InitOffsetMoveTo(9, 10);
    ld.OffsetLineTo(4, 4);
    ld.OffsetLineTo(0, -1);
    ld.OffsetLineTo(-3, -3);	

    // bitblt to screen
    pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

    // clean up
    blackPen.DeleteObject();
    whitePen.DeleteObject();
    yellowPen.DeleteObject();
    darkPen.DeleteObject();
    grayPen.DeleteObject();
    olivePen.DeleteObject();
    cyanPen.DeleteObject();
    bluePen.DeleteObject();
    navyPen.DeleteObject();
    bmp.DeleteObject();
}

void CBrowseCtrl::OnMove(int x, int y) 
{
    CButton::OnMove(x, y);
    RecalculateRects(TRUE);
}

void CBrowseCtrl::OnSize(UINT nType, int cx, int cy) 
{
    CButton::OnSize(nType, cx, cy);
    RecalculateRects(TRUE);
}

void CBrowseCtrl::RecalculateRects(BOOL bMoveEdit)
{
    ASSERT(::IsWindow(m_hWnd));
    CRect rcClient;
    GetClientRect(&rcClient);	

    // get the button rect
    m_rcButton = rcClient;
    CSize netSize(ICON_WIDTH, ICON_HEIGHT);
    int nReqWidth = ICON_WIDTH;

    if ((m_dwStyle & BC_BTN_ICON) == 0)
    {
        // Unlike icons, text size could vary
        CClientDC dc(this);
        dc.SelectObject(GetFont());
        netSize = dc.GetTextExtent(m_sButtonText);
        nReqWidth = netSize.cx;
    }

    if (nReqWidth < ICON_WIDTH)
        nReqWidth = ICON_WIDTH;
    nReqWidth += WIDTH_SPACE;

    if (m_rcButton.Width() > nReqWidth)
    {
        if (m_dwStyle & BC_BTN_LEFT)
            m_rcButton.right = m_rcButton.left + nReqWidth; // Left side
        else
            m_rcButton.left = m_rcButton.right - nReqWidth; // Right side
    }

    // get the content rect(areat for drawing icons and text on the browse button)
    CRect rcBtn = m_rcButton;
    rcBtn.DeflateRect(BTN_EDGE, BTN_EDGE);

    m_rcContent = CRect(rcBtn.TopLeft(), netSize);

    if (rcBtn.Height() > netSize.cy)
        m_rcContent.OffsetRect(0, (rcBtn.Height() - netSize.cy) / 2);
    else
        m_rcContent.bottom = rcBtn.bottom;

    if (rcBtn.Width() > netSize.cx)
        m_rcContent.OffsetRect((rcBtn.Width() - netSize.cx) / 2, 0);
    else
        m_rcContent.right = rcBtn.right;

    // Get the edit box area
    m_rcEdit = rcClient;
    if (m_dwStyle & BC_BTN_LEFT)
        m_rcEdit.left = m_rcButton.right;
    else
        m_rcEdit.right = m_rcButton.left;

    if (bMoveEdit && ::IsWindow(m_wndEdit.m_hWnd))
        m_wndEdit.MoveWindow(&m_rcEdit, TRUE);
}

BOOL CBrowseCtrl::IsEditManuallyChanged() const
{
    return m_bEditChanged && m_sEditText.CompareNoCase(CString(m_lpszPathNames)) != 0;
}

void CBrowseCtrl::SetDialogBanner(LPCTSTR lpszBanner)
{
    m_sDlgBanner = lpszBanner;
}

CString CBrowseCtrl::GetDialogBanner() const
{
    return m_sDlgBanner;
}

void CBrowseCtrl::ModifyButtonStyle(DWORD dwRemove, DWORD dwAdd)
{
    DWORD dwStyle = m_dwStyle;
    dwStyle &= ~dwRemove;
    dwStyle |= dwAdd;
    SetButtonStyle(dwStyle);
}

void CBrowseCtrl::PrepareMemDC(CDC *pMemDC, CBitmap *pBmp, CDC *pSrcDC, const CRect &srcRect, COLORREF bkColor) const
{
    pMemDC->CreateCompatibleDC(pSrcDC);
    pBmp->CreateCompatibleBitmap(pSrcDC, srcRect.Width(), srcRect.Height());
    pMemDC->SelectObject(pBmp);
    pMemDC->FillSolidRect(CRect(0, 0, srcRect.Width(), srcRect.Height()), bkColor);
}

BOOL CBrowseCtrl::SplitPath(LPCTSTR lpszPathName, CString *pStrDrvLetter, CString *pStrFolder, CString *pStrFileName, CString *pStrFileTitle, CString *pStrFileExt)
{
    const int FULL_LEN = 2048; // should be enough?

    TCHAR szFullPath[FULL_LEN + 1] = _T("");
    if (_tfullpath(szFullPath, lpszPathName, FULL_LEN) == NULL)
        return FALSE;	

    TCHAR szDrv[_MAX_DRIVE + 1] = _T("");
    TCHAR szDir[FULL_LEN + 1] = _T("");
    TCHAR szName[FULL_LEN + 1] = _T("");
    TCHAR szExt[FULL_LEN + 1] = _T("");
    _tsplitpath_s<>(szFullPath, szDrv, szDir, szName, szExt);

    if (pStrDrvLetter != NULL)
        *pStrDrvLetter = szDrv;

    if (pStrFolder != NULL)
    {
        *pStrFolder = CString(szDrv) + szDir;
        pStrFolder->TrimRight(_T('\\'));
        pStrFolder->TrimRight(_T('/'));
    }

    if (pStrFileName != NULL)
        *pStrFileName = CString(szName) + szExt;

    if (pStrFileTitle != NULL)
        *pStrFileTitle = szName;

    if (pStrFileExt != NULL)
    {
        *pStrFileExt = szExt;
        pStrFileExt->TrimLeft(_T('.'));
    }

    return TRUE;
}

CString CBrowseCtrl::GetDriveLetter() const
{
    CString str;
    SplitPath(GetPathName(), &str, NULL, NULL, NULL, NULL);
    return str;
}

CString CBrowseCtrl::GetDirectory() const
{
    if (m_dwStyle & BC_CTL_FOLDERSONLY)
        return GetPathName();

    CString str;
    SplitPath(GetPathName(), NULL, &str, NULL, NULL, NULL);
    return str;
}

void CBrowseCtrl::OnEnable(BOOL bEnable) 
{
    CButton::OnEnable(bEnable);	
    // TODO: Add your message handler code here

    if (::IsWindow(m_wndEdit.m_hWnd))
        m_wndEdit.EnableWindow(bEnable);

    if (::IsWindow(m_hWnd))
        RedrawWindow();
}

void CBrowseCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    // TODO: Add your message handler code here and/or call default	
    CButton::OnKeyDown(nChar, nRepCnt, nFlags);
    if (nChar == VK_SPACE)
    {
        m_bBtnPushed = TRUE;
        RedrawWindow();
    }
}

void CBrowseCtrl::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    // TODO: Add your message handler code here and/or call default
    CButton::OnKeyUp(nChar, nRepCnt, nFlags);
    if (nChar == VK_SPACE)
    {
        m_bBtnPushed = FALSE;
        RedrawWindow();
        OnButtonClicked();
    }	
}

void CBrowseCtrl::OnButtonClicked()
{
    DoModal();
    CWnd* pParent = GetParent();
    if (pParent != NULL && ::IsWindow(pParent->m_hWnd))
        pParent->PostMessage(WM_COMMAND, MAKEWPARAM(GetDlgCtrlID(), 0), (LPARAM)NULL);
}

void CBrowseCtrl::SetFont(CFont* pFont, BOOL bRedraw)
{
    m_wndEdit.SetFont(pFont, bRedraw);	
}

void CBrowseCtrl::EnableWindow(BOOL bEnabled)
{
    m_wndEdit.EnableWindow(bEnabled);
    CButton::EnableWindow(bEnabled);
}
