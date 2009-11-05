
/****************************************************************************
 *	class		:	CHyperlinkStatic
 *	author		:	Franz Wong / Simple Hyperlink Static Control / http://www.codeguru.com/Cpp/controls/staticctrl/article.php/c5801/
 */

// HyperlinkStatic.cpp : implementation file
//

#include "stdafx.h"
#include "HyperlinkStatic.h"
#include "DniMessageBox.h"
#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CHyperlinkStatic

CHyperlinkStatic::CHyperlinkStatic()
	: _rect(0, 0, 0, 0)
{
	_strCaption = _strHyperlink = _T("");	 
	_bMouseInControl = _bCreateFont = _bGetCaptionSize = false;

//	_hHandCursor = ::LoadCursor(NULL, IDC_HAND); //non supportato in WIN 95
	_hHandCursor = ::LoadCursor(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDC_CUSTOM_HAND));
	_hArrowCursor = ::LoadCursor(NULL, IDC_ARROW);
}

CHyperlinkStatic::~CHyperlinkStatic()
{
}

BEGIN_MESSAGE_MAP(CHyperlinkStatic, CStatic)
	//{{AFX_MSG_MAP(CHyperlinkStatic)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHyperlinkStatic message handlers

void CHyperlinkStatic::SetHyperlink(std::wstring strHyperlink)
{
	_strHyperlink = strHyperlink.c_str();
}

void CHyperlinkStatic::SetCaption(std::wstring strCaption)
{
	_strCaption = strCaption.c_str();
	_bGetCaptionSize = false;
}

void CHyperlinkStatic::OnLButtonDown(UINT nFlags, CPoint point) 
{
	try
	{
		if ( _bGetCaptionSize == false )
			GetCaptionSize();
		if (InCaptionRange(point))
			DVLib::ShellCmd(_strHyperlink.GetBuffer());
		CStatic::OnLButtonDown(nFlags, point);
	}
	catch(std::exception& ex)
	{
		DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK | MB_ICONSTOP);
	}
}

BOOL CHyperlinkStatic::Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	_rect.SetRect(rect.left, rect.top, rect.right, rect.bottom);
	BOOL rc = CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);
	SetCaption(lpszText);
	return rc;
}

void CHyperlinkStatic::OnPaint() 
{	
	if ( _bCreateFont == false )
		CreateFont();
	CPaintDC dc(this);
	CFont *pOldFont = (CFont*) dc.SelectObject(&_fontCaption);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0, 0, 255));
	GetCaptionSize();
	dc.TextOut(_captionRect.left, _captionRect.top, _strCaption);
	dc.SelectObject(pOldFont);
}

void CHyperlinkStatic::OnDestroy() 
{
	CStatic::OnDestroy();
	_fontCaption.DeleteObject();
}

void CHyperlinkStatic::PreSubclassWindow() 
{
	ModifyStyle(0, SS_NOTIFY, TRUE);
	GetWindowText(_strCaption);
	_bGetCaptionSize = false;
	CStatic::PreSubclassWindow();
}

LRESULT CHyperlinkStatic::OnMouseLeave(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	_bMouseInControl = false;
	::SetCursor(_hArrowCursor);	
	return 0;
}

void CHyperlinkStatic::OnMouseMove(UINT nFlags, CPoint point) 
{
	if ( _bMouseInControl == false ) {
		//Track the mouse leave event
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
        tme.hwndTrack = GetSafeHwnd();
        tme.dwFlags = TME_LEAVE;        
		_TrackMouseEvent(&tme);
		_bMouseInControl = true;
	}
	else {
		if ( _bGetCaptionSize == false )
			GetCaptionSize();
		::SetCursor((InCaptionRange(point))?_hHandCursor:_hArrowCursor);		
	}
	CStatic::OnMouseMove(nFlags, point);
}

void CHyperlinkStatic::CreateFont()
{
	CFont* pFontParent = GetParent()->GetFont();	
	if ( pFontParent ) {
		LOGFONT lf;
		pFontParent->GetObject(sizeof(lf), &lf);
		lf.lfUnderline = TRUE;		
		_fontCaption.CreateFontIndirect(&lf);
		_bCreateFont = true;
	}
}

void CHyperlinkStatic::GetCaptionSize()
{
	if (( _bGetCaptionSize == false ) && ( _bCreateFont )) {
		CClientDC dc(this);
		CFont *pOldFont = dc.SelectObject(&_fontCaption);
		_sizeCaption = dc.GetTextExtent(_strCaption);
		dc.SelectObject(pOldFont);

		GetWindowRect(& _rect);

		_captionRect.SetRect(0, 
			(_rect.bottom - _rect.top - _sizeCaption.cy - 1) / 2,
			_rect.right - _rect.left,
			(_rect.bottom - _rect.top - _sizeCaption.cy - 1) / 2 + _sizeCaption.cy);

		_bGetCaptionSize = true;
	}
}

bool CHyperlinkStatic::InCaptionRange(CPoint &point)
{
	return _captionRect.PtInRect(point) ? true : false;
}
