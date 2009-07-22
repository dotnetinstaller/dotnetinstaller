/****************************************************************************
 *	class		:	CKCBusyProgressCtrl
 *	author		:	Peter Mares / kinkycode.com (gui@ch.co.za)
 *	base class	:	CStatic (MFC)
 *	notes		:	Control to be used for progress indication when there are
 *					no lower and upper bounds available for a progress bar.
 *					Can also be used as a normal progress bar
 *
 *	Disclaimer	:	Its free, it feels good and its from South Africa :)
 ****************************************************************************
 *	Version History:
 *
 *	v0.1 (2003-04-21)
 *
 *	- First public release
 *
 *	v0.2 (2003-04-22)
 *
 *	- Added support for WM_SYSCOLORCHANGE
 *	- Added flag for whether background colour was a system colour (true by default)
 *	- Modified ON_MESSAGE handlers to return LRESULT instead of void for
 *	  VC++.NET compatibility
 *  - Added "Busy Type" flag to support different motion while in busy mode.
 *	  Current modes supported are :		BPC_BUSY_PINGPONG
 *										BPC_BUSY_LTR		(left to right)
 *										BPC_BUSY_RTL		(right to left)
 *	- Added "Busy Fill" flag to support different filling methods while in
 *	  busy mode. 
 *	  Current modes supported are :		BPC_BUSYFILL_BLOCK	(block filling)
 *										BPC_BUSYFILL_SMOOTH	(smooth filling)
 *  - Fixed bug in percentage fill calculation
 *
 *	v0.21 (2003-04-30)
 *
 *	- Fixed a threading bug (identified by Mark Richards - thanks)
 *
 *	v0.3 (2003-05-02)
 *
 *	- Added the outstanding BPM_XXXXX Messages and handlers to the control
 *
 ****************************************************************************/

#include "stdafx.h"
#include "KCBusyProgressCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CKCBusyProgressCtrl

CKCBusyProgressCtrl::CKCBusyProgressCtrl(int nNumSteps, int nCurPos)
: m_nNumSteps(nNumSteps)
, m_nStep(1)
, m_nCurPos(nCurPos)
, m_colBkg( GetSysColor( COLOR_BTNFACE ) )
, m_colBlockFace( RGB(160, 190, 220) )
, m_colBlockEdge( RGB(50, 90, 135) )
, m_colBlockFaceHi( RGB(190, 220, 255) )
, m_colBlockEdgeHi( RGB(50, 90, 135) )
, m_pOldBmp(NULL)
, m_nIBPadding(1)
, m_rect(0,0,0,0)
, m_dBlockHeight(0.0L)
, m_dBlockWidth(0.0L)
, m_bBusyThrd(false)
, m_pThrd(NULL)
, m_nSpeed(100)
, m_nMode(BPC_MODE_BUSY)
, m_nLower(0)
, m_nUpper(100)
, m_bUseSysColBkg(true)
, m_nBusyType(BPC_BUSY_PINGPONG)
, m_nBusyFill(BPC_BUSYFILL_BLOCK)
, m_nGranularity(5)
, m_nNumStepsSmooth( m_nNumSteps * m_nGranularity )
{
}

/////////////////////////////////////////////////////////////////////////////

CKCBusyProgressCtrl::~CKCBusyProgressCtrl()
{
	if ( m_pOldBmp )
	{
		m_memDC.SelectObject(m_pOldBmp);
		m_memBmp.DeleteObject();
		m_memDC.DeleteDC();
	}
}

/////////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CKCBusyProgressCtrl, CStatic)
	//{{AFX_MSG_MAP(CKCBusyProgressCtrl)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_SYSCOLORCHANGE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(BPM_SETNUMSTEPS, OnSetNumSteps)
	ON_MESSAGE(BPM_SETCURPOS, OnSetCurPos)
	ON_MESSAGE(BPM_SETIBPAD, OnSetIBPad)
	ON_MESSAGE(BPM_SETSPEED, OnSetSpeed)
	ON_MESSAGE(BPM_SETRANGE, OnSetRange)
	ON_MESSAGE(BPM_SETMODE, OnSetMode)
	ON_MESSAGE(BPM_STARTBUSY, OnStartBusy)
	ON_MESSAGE(BPM_ENDBUSY, OnEndBusy)
	ON_MESSAGE(BPM_STEPIT, OnStepIt)
	// new in version 0.3
	ON_MESSAGE(BPM_SETBUSYTYPE, OnSetBusyType)
	ON_MESSAGE(BPM_SETBUSYFILL, OnSetBusyFill)
	ON_MESSAGE(BPM_SETGRANULARITY, OnSetGranularity)
	ON_MESSAGE(BPM_SETCOLBKG, OnSetColBkg)
	ON_MESSAGE(BPM_SETCOLBFACE, OnSetColBFace)
	ON_MESSAGE(BPM_SETCOLBEDGE, OnSetColBEdge)
	ON_MESSAGE(BPM_SETCOLBFACEHI, OnSetColBFaceHi)
	ON_MESSAGE(BPM_SETCOLBEDGEHI, OnSetColBEdgeHi)
	ON_MESSAGE(BPM_RECALC, OnRecalc)
	ON_MESSAGE(BPM_RESET, OnReset)
	ON_MESSAGE(BPM_USESYSCOL, OnUseSysCol)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKCBusyProgressCtrl message handlers

void CKCBusyProgressCtrl::PreSubclassWindow() 
{
	CStatic::PreSubclassWindow();
	Recalc();
}

/////////////////////////////////////////////////////////////////////////////

BOOL CKCBusyProgressCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	BOOL bResult = CWnd::Create(TEXT("STATIC"), TEXT("BusyProgressCtrl"), dwStyle, rect, pParentWnd, nID, pContext);
	
	Recalc();

	return bResult;
}

/////////////////////////////////////////////////////////////////////////////
//	function		:	Recalc()
//	description		:	Function used to recalculate the block sizes and
//						optionally get the current client area
/////////////////////////////////////////////////////////////////////////////
void CKCBusyProgressCtrl::Recalc()
{
	if ( m_rect.IsRectEmpty() )
		GetClientRect(&m_rect);

	CRect			tRect = m_rect;

	tRect.right -= (m_nNumSteps * m_nIBPadding);
	m_dBlockWidth = ((double)tRect.Width() / (double)m_nNumSteps);
	m_dBlockHeight = tRect.Height();
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::OnPaint() 
{
	CPaintDC			dc(this); // device context for painting

	// create a memory dc if needs be
	if ( !m_memDC.m_hDC )
	{
		m_memDC.CreateCompatibleDC(&dc);
		m_memBmp.CreateCompatibleBitmap(&dc, m_rect.Width(), m_rect.Height());
		m_pOldBmp = m_memDC.SelectObject(&m_memBmp);
	}

	DrawBackground(m_memDC, m_rect);
	DrawBlocks(m_memDC, m_rect);

	// render the final image
	dc.BitBlt(0, 0, m_rect.Width(), m_rect.Height(), &m_memDC, 0, 0, SRCCOPY);
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::DrawBackground(CDC& dc, CRect& rect)
{
	dc.FillSolidRect( &rect, m_colBkg );
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::DrawBlocks(CDC& dc, CRect& /* rect */)
{
	CRect				bRect;
	double				dXOffset = 0;
	int					i;
	CPen				nPen, *pOldPen = NULL;
	CBrush				nBrush, *pOldBrush = NULL;

	// create some drawing tools
	nPen.CreatePen( PS_SOLID, 0, m_colBlockEdge );
	nBrush.CreateSolidBrush( m_colBlockFace );
	pOldPen = dc.SelectObject(&nPen);
	pOldBrush = dc.SelectObject(&nBrush);

	// create the initial rectangle
	bRect.top = 0; bRect.bottom = (int) m_dBlockHeight;
	bRect.left = 0; bRect.right = (int) m_dBlockWidth;
	for ( i = 0; i < m_nNumSteps; i++ )
	{
		if ( m_nMode & BPC_MODE_BUSY )
		{
			switch ( m_nBusyFill )
			{
			case	BPC_BUSYFILL_BLOCK:
				{
					if ( i == m_nCurPos )
						DrawHiliteBlock(dc, bRect);
					else
						DrawBlock(dc, bRect);
				}
				break;

			case	BPC_BUSYFILL_SMOOTH:
				{
					double		dDiff = (double)m_nNumStepsSmooth;
					double		dPerc = ((double) m_nCurPos / dDiff);
					int			nFull = (int) (dPerc*(double)m_nNumSteps)-1;
					double		dPerc2 = (((dPerc * (double)m_nNumSteps)-1) - nFull);
					int			nPartial = (int)(m_dBlockWidth * dPerc2);

					if ( i <= nFull )
						DrawHiliteBlock(dc, bRect);
					else
					{
						DrawBlock(dc, bRect);
						if ( i == nFull + 1 && nPartial )
							DrawPartialBlock(dc, bRect, nPartial);
					}
				}
				break;
			}
		}
		else if ( m_nMode & BPC_MODE_PROGRESS )
		{
			double		dDiff = (double)(m_nUpper - m_nLower);
			double		dPerc = ((double) m_nCurPos / dDiff);
			int			nFull = (int) (dPerc*(double)m_nNumSteps)-1;
			double		dPerc2 = (((dPerc * (double)m_nNumSteps)-1) - nFull);
			int			nPartial = (int)(m_dBlockWidth * dPerc2);

			if ( i <= nFull )
				DrawHiliteBlock(dc, bRect);
			else
			{
				DrawBlock(dc, bRect);
				if ( i == nFull + 1 && nPartial )
					DrawPartialBlock(dc, bRect, nPartial);
			}
		}
		// offset the rectangle a bit
		dXOffset += m_dBlockWidth + (double) m_nIBPadding;
		bRect.left = (int) dXOffset;
		bRect.right = (int)(dXOffset + m_dBlockWidth);
	}

	// cleanup after ourselves...
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
	nPen.DeleteObject();
	nBrush.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::DrawBlock(CDC& dc, CRect& rect)
{
	dc.Rectangle(&rect);
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::DrawHiliteBlock(CDC& dc, CRect& rect)
{
	CPen			nPen, *pOldPen = NULL;
	CBrush			nBrush, *pOldBrush = NULL;

	// use the correct tools ;)
	nPen.CreatePen( PS_SOLID, 0, m_colBlockEdgeHi );
	nBrush.CreateSolidBrush( m_colBlockFaceHi );
	pOldPen = dc.SelectObject(&nPen);
	pOldBrush = dc.SelectObject(&nBrush);

	// draw the block
	dc.Rectangle(&rect);

	// cleanup
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
	nPen.DeleteObject();
	nBrush.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::DrawPartialBlock(CDC& dc, CRect& rect, int nPartial)
{
	CRect			pRect = rect;

	pRect.DeflateRect(1, 1);
	pRect.right = pRect.left + nPartial;
	if ( pRect.right >= rect.right )
		pRect.right = rect.right - 1;
	dc.FillSolidRect(&pRect, m_colBlockFaceHi);
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);
	
	GetClientRect(&m_rect);
	if ( m_memDC.m_hDC )
	{
		// delete the dc to allow OnPaint to recreate the DC for the new size
		m_memDC.SelectObject(m_pOldBmp);
		m_memBmp.DeleteObject();
		m_memDC.DeleteDC();
	}
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::StepIt()
{
	int				nNumSteps = 0;

	if ( m_nMode & BPC_MODE_BUSY)
	{
		switch ( m_nBusyFill )
		{
		case	BPC_BUSYFILL_BLOCK:
			nNumSteps = m_nNumSteps;
			break;

		case	BPC_BUSYFILL_SMOOTH:
			nNumSteps = m_nNumStepsSmooth;
			break;
		}

		switch ( m_nBusyType )
		{
		case	BPC_BUSY_PINGPONG:
			{
				// do a check for the left to right movement
				if ( m_nCurPos >= nNumSteps-1 )
					m_nStep = -1;
				// check if we're done moving from right to left..
				if ( m_nCurPos <= 0 )
					m_nStep = 1;
			}
			break;

		case	BPC_BUSY_LTR:
			{
				if ( m_nCurPos == nNumSteps-1 )
					m_nCurPos = -1;
			}
			break;

		case	BPC_BUSY_RTL:
			{
				if ( m_nCurPos == 0 )
					m_nCurPos = nNumSteps;
			}
			break;
		}
	}
	else if ( m_nMode & BPC_MODE_PROGRESS )
	{
	}

	// update the position
	m_nCurPos += m_nStep;

	Invalidate();
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::SetMode(int nMode)
{
	End(); 
	if ( m_nMode >= BPC_MODE_BUSY && m_nMode <= BPC_MODE_PROGRESS )
	{
		m_nMode = nMode;
		if ( m_nMode == BPC_MODE_PROGRESS )
			m_nStep = 1;
	}
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::Start()
{
	if ( m_nMode & BPC_MODE_BUSY)
	{
		while ( m_pThrd || m_bBusyThrd)
			End();
		m_pThrd = AfxBeginThread(thrdBusy, this);
		m_pThrd->m_bAutoDelete = false;
	}
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::End()
{
	if ( m_pThrd )
	{
		if ( m_bBusyThrd )
			m_bBusyThrd = false;
		WaitForSingleObject(m_pThrd->m_hThread, m_nSpeed*2);
		delete m_pThrd;
		m_pThrd = NULL;
	}
	else
		m_bBusyThrd = false;
}

/////////////////////////////////////////////////////////////////////////////

UINT CKCBusyProgressCtrl::thrdBusy(LPVOID pParam)
{
	CKCBusyProgressCtrl*			pThis = (CKCBusyProgressCtrl*) pParam;

	if ( !pThis )
		return 0;

	while ( pThis->m_bBusyThrd )
		Sleep(pThis->m_nSpeed);
	pThis->m_bBusyThrd = true;
	while ( pThis->m_bBusyThrd )
	{
		pThis->StepIt();
		Sleep(pThis->m_nSpeed);
	}
	pThis->m_bBusyThrd = false;

	return 0;
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::Reset()
{
	if ( m_nMode == BPC_MODE_BUSY )
	{
		m_nCurPos = m_nBusyType != BPC_BUSY_RTL ? 0 : 
					m_nBusyFill != BPC_BUSYFILL_SMOOTH ? m_nNumSteps : 
					m_nNumSteps * m_nGranularity;
		m_nStep = m_nBusyType != BPC_BUSY_RTL ? 1 : -1;
	}
	else
	{
		m_nCurPos = 0;
		m_nStep = 1;
	}
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetNumSteps(WPARAM wParam, LPARAM /*lParam*/)
{
	SetNumSteps((int)wParam);
	Invalidate();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetCurPos(WPARAM wParam, LPARAM /*lParam*/)
{
	SetCurPos( (int)wParam );
	Invalidate();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetIBPad(WPARAM wParam, LPARAM /*lParam*/)
{
	SetInterBlockPadding( (int) wParam );
	Invalidate();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetSpeed(WPARAM wParam, LPARAM /*lParam*/)
{
	SetSpeed( (int) wParam );
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetRange(WPARAM wParam, LPARAM lParam)
{
	SetRange( (int) wParam, (int) lParam );
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetMode(WPARAM wParam, LPARAM /*lParam*/)
{
	SetMode( (int) wParam );
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnStartBusy(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	Start();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnEndBusy(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	End();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnStepIt(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	StepIt();
	Invalidate();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetBusyType(WPARAM wParam, LPARAM /*lParam*/)
{
	SetBusyType( (int) wParam );
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetBusyFill(WPARAM wParam, LPARAM /*lParam*/)
{
	SetBusyFill( (int) wParam );
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetGranularity(WPARAM wParam, LPARAM /*lParam*/)
{
	SetGranularity((int) wParam);
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetColBkg(WPARAM wParam, LPARAM /*lParam*/)
{
	SetColBkg( (COLORREF) wParam );
	Invalidate();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetColBFace(WPARAM wParam, LPARAM /*lParam*/)
{
	SetColBlockFace( (COLORREF) wParam );
	Invalidate();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetColBEdge(WPARAM wParam, LPARAM /*lParam*/)
{
	SetColBlockEdge( (COLORREF) wParam );
	Invalidate();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetColBFaceHi(WPARAM wParam, LPARAM /*lParam*/)
{
	SetColBlockFaceHi( (COLORREF) wParam );
	Invalidate();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnSetColBEdgeHi(WPARAM wParam, LPARAM /*lParam*/)
{
	SetColBlockEdgeHi( (COLORREF) wParam );
	Invalidate();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnRecalc(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	Recalc();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnReset(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	Reset();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

LRESULT CKCBusyProgressCtrl::OnUseSysCol(WPARAM wParam, LPARAM /*lParam*/)
{
	UseSysColBkg( wParam ? true : false );
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::UseSysColBkg(bool bUse)
{
	m_bUseSysColBkg = bUse;
	if ( bUse )
		m_colBkg = GetSysColor(COLOR_3DFACE);
	Invalidate();
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::OnSysColorChange() 
{
	CStatic::OnSysColorChange();
	
	if ( m_bUseSysColBkg )
	{
		m_colBkg = GetSysColor(COLOR_3DFACE);
		Invalidate();
	}
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::SetBusyType(int nType)
{
	m_nBusyType = nType;
	if ( m_nMode == BPC_MODE_BUSY )
	{
		switch ( nType )
		{
		case	BPC_BUSY_LTR:
			m_nStep = 1;
			break;

		case	BPC_BUSY_RTL:
			m_nStep = -1;
			break;

		case	BPC_BUSY_PINGPONG:
		default:
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////

void CKCBusyProgressCtrl::SetBusyFill(int nFill)
{
	if ( m_nMode == BPC_MODE_BUSY )
	{
		m_nBusyFill = nFill;
		switch ( nFill )
		{
		case	BPC_BUSYFILL_SMOOTH:
			Reset();
			m_nNumStepsSmooth = m_nNumSteps * m_nGranularity;
			break;

		case	BPC_BUSYFILL_BLOCK:
		default:
			Reset();
			break;

		}
	}
}