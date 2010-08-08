// SplashWnd.cpp : implementation file
//
// ©1998-2001 Codejock Software, All Rights Reserved.
// Based on the Visual C++ splash screen component.
//
// support@codejock.com
// http://www.codejock.com
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SplashWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
//   Splash Screen class

BOOL        CSplashWnd::m_bShowSplashWnd;
CSplashWnd* CSplashWnd::m_pSplashWnd;

CSplashWnd::CSplashWnd()
{
}

CSplashWnd::~CSplashWnd()
{
	if (m_pBitmap != NULL)
	{
		m_pBitmap->DeleteObject();
		m_pBitmap = NULL;
	}

	// Clear the static window pointer.
	ASSERT(m_pSplashWnd == this);
	m_pSplashWnd = NULL;
}

BEGIN_MESSAGE_MAP(CSplashWnd, CWnd)
	//{{AFX_MSG_MAP(CSplashWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CSplashWnd::EnableSplashScreen(BOOL bEnable /*= TRUE*/)
{
	m_bShowSplashWnd = bEnable;
}

BOOL CSplashWnd::ShowSplashScreen(UINT uTimeOut, UINT uBitmapID, HWND hParent /*= NULL*/)
{
	ASSERT(uTimeOut && uBitmapID);
	
	if (!m_bShowSplashWnd || m_pSplashWnd != NULL) {
		return FALSE;
	}

	// Allocate a new splash screen, and create the window.
	m_pSplashWnd = new CSplashWnd;

	m_pSplashWnd->m_pBitmap = new CBitmap();
	if (! m_pSplashWnd->m_pBitmap->LoadBitmap(uBitmapID)) {
		delete m_pSplashWnd;
		m_pSplashWnd = NULL;
		return FALSE;
	}

	if (! m_pSplashWnd->ShowSplashScreen(uTimeOut, hParent))
	{
		delete m_pSplashWnd;
		m_pSplashWnd = NULL;
		return FALSE;
	}

	return TRUE;
}

BOOL CSplashWnd::ShowSplashScreen(UINT uTimeOut, LPCTSTR lpszResourceID, HWND hParent /*= NULL*/)
{
	ASSERT(uTimeOut && lpszResourceID);
	
	if (!m_bShowSplashWnd || m_pSplashWnd != NULL) {
		return FALSE;
	}

	// Allocate a new splash screen, and create the window.
	m_pSplashWnd = new CSplashWnd;

	if (! m_pSplashWnd->m_pBitmap->LoadBitmap(lpszResourceID)) {
		delete m_pSplashWnd;
		m_pSplashWnd = NULL;
		return FALSE;
	}

	if (! m_pSplashWnd->ShowSplashScreen(uTimeOut, hParent)) {
		delete m_pSplashWnd;
		m_pSplashWnd = NULL;
		return FALSE;
	}

	return TRUE;
}

BOOL CSplashWnd::ShowSplashScreen(UINT uTimeOut, HBITMAP h, HWND hParent)
{
	ASSERT(uTimeOut && h);
	
	if (!m_bShowSplashWnd || m_pSplashWnd != NULL) {
		return FALSE;
	}

	CBitmap * pBitmap = CBitmap::FromHandle(h);
	if (! pBitmap) {
		return FALSE;
	}

	// Allocate a new splash screen, and create the window.
	m_pSplashWnd = new CSplashWnd;
	m_pSplashWnd->m_pBitmap = pBitmap;

	if (! m_pSplashWnd->ShowSplashScreen(uTimeOut, hParent)) {
		delete m_pSplashWnd;
		m_pSplashWnd = NULL;
		return FALSE;
	}

	return TRUE;
}

BOOL CSplashWnd::ShowSplashScreen(UINT uTimeOut, HWND hParent)
{
	ASSERT(m_pBitmap);

	BITMAP bm;
	m_pBitmap->GetBitmap(&bm);

	CString strWndClass = AfxRegisterWndClass(0,
		AfxGetApp()->LoadStandardCursor(IDC_ARROW));

	if (! CreateEx(0, strWndClass, NULL, WS_POPUP | WS_VISIBLE,
		0, 0, bm.bmWidth, bm.bmHeight, hParent, NULL))
	{
		TRACE0("Failed to create splash screen.\n");
		return FALSE;
	}

	// Center the window.
	CenterWindow();
	UpdateWindow();

	// Set a timer to destroy the splash screen.
	SetTimer(1, uTimeOut, NULL);
	return TRUE;
}

BOOL CSplashWnd::PreTranslateAppMessage(MSG* pMsg)
{
	if (m_pSplashWnd == NULL)
		return FALSE;

	// If we get a keyboard or mouse message, hide the splash screen.
	if (pMsg->message == WM_KEYDOWN ||
	    pMsg->message == WM_SYSKEYDOWN ||
	    pMsg->message == WM_LBUTTONDOWN ||
	    pMsg->message == WM_RBUTTONDOWN ||
	    pMsg->message == WM_MBUTTONDOWN ||
	    pMsg->message == WM_NCLBUTTONDOWN ||
	    pMsg->message == WM_NCRBUTTONDOWN ||
	    pMsg->message == WM_NCMBUTTONDOWN)
	{
		m_pSplashWnd->HideSplashScreen();
		return TRUE;	// message handled here
	}

	return FALSE;	// message not handled
}

void CSplashWnd::CloseSplashScreen()
{
	if (NULL != m_pSplashWnd)
	{
		m_pSplashWnd->HideSplashScreen();
	}
}

void CSplashWnd::HideSplashScreen()
{
	// Destroy the window, and update the mainframe.
	DestroyWindow();
	
	CWnd * pMainWnd = AfxGetMainWnd();
	
	if (pMainWnd != NULL && pMainWnd->GetSafeHwnd() != NULL)
	{
		pMainWnd->UpdateWindow();
	}
}

void CSplashWnd::PostNcDestroy()
{
	// Free the C++ class.
	delete this;
}

void CSplashWnd::OnPaint()
{
	ASSERT(m_pBitmap);

	CPaintDC dc(this);

	CDC dcImage;
	if (dcImage.CreateCompatibleDC(&dc))
	{
		BITMAP bm;
		m_pBitmap->GetBitmap(&bm);

		// Paint the image.
		CBitmap * pOldBitmap = dcImage.SelectObject(m_pBitmap);
		dc.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &dcImage, 0, 0, SRCCOPY);
		dcImage.SelectObject(pOldBitmap);
	}
}

void CSplashWnd::OnTimer(UINT /*nIDEvent*/)
{
	// Destroy the splash screen window.
	HideSplashScreen();
}
