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

#if !defined(AFX_BUSYPROGRESSCTRL_H__BEE47141_AAF5_44A5_8408_2C4452BD764A__INCLUDED_)
#define AFX_BUSYPROGRESSCTRL_H__BEE47141_AAF5_44A5_8408_2C4452BD764A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BusyProgressCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKCBusyProgressCtrl window

//
// defines for the control's mode
#define	BPC_MODE_BUSY		0x00000001
#define	BPC_MODE_PROGRESS	0x00000002

//
// defines for the type of BUSY mode
#define BPC_BUSY_PINGPONG	0x00000001
#define	BPC_BUSY_LTR		0x00000002
#define	BPC_BUSY_RTL		0x00000004

//
// defines for the fill type of BUSY mode
#define	BPC_BUSYFILL_BLOCK	0x00000001
#define	BPC_BUSYFILL_SMOOTH	0x00000002

//
// custom message defines
#define BPM_SETNUMSTEPS		(WM_USER+1)
#define	BPM_SETCURPOS		(WM_USER+2)
#define	BPM_SETIBPAD		(WM_USER+3)
#define	BPM_SETSPEED		(WM_USER+4)
#define	BPM_SETRANGE		(WM_USER+5)
#define	BPM_SETMODE			(WM_USER+6)
#define BPM_STARTBUSY		(WM_USER+7)
#define BPM_ENDBUSY			(WM_USER+8)
#define	BPM_STEPIT			(WM_USER+9)
// new in version 0.3
#define	BPM_SETBUSYTYPE		(WM_USER+10)
#define	BPM_SETBUSYFILL		(WM_USER+11)
#define	BPM_SETGRANULARITY	(WM_USER+12)
#define	BPM_SETCOLBKG		(WM_USER+13)
#define	BPM_SETCOLBFACE		(WM_USER+14)
#define	BPM_SETCOLBEDGE		(WM_USER+15)
#define	BPM_SETCOLBFACEHI	(WM_USER+16)
#define	BPM_SETCOLBEDGEHI	(WM_USER+17)
#define	BPM_RECALC			(WM_USER+18)
#define	BPM_RESET			(WM_USER+19)
#define	BPM_USESYSCOL		(WM_USER+20)

class CKCBusyProgressCtrl : public CStatic
{
// Construction
public:
	CKCBusyProgressCtrl(int nNumSteps = 10, int nCurPos = 0);
	virtual ~CKCBusyProgressCtrl();

	//
	// Methods
	
	// since version 0.1
	void				Recalc();
	void				Reset();
	void				Start();
	void				End();
	void				StepIt();

	void				SetNumSteps(int nNumSteps)					{ m_nNumSteps = nNumSteps; Recalc(); }
	int					GetNumSteps()								{ return m_nNumSteps; }
	void				SetCurPos(int nCurPos)						{ m_nCurPos = nCurPos; Invalidate(); }
	int					GetCurPos()									{ return m_nCurPos; }
	void				SetInterBlockPadding(int nPadding)			{ m_nIBPadding = nPadding; Recalc(); }
	int					GetInterBlockPadding()						{ return m_nIBPadding; }
	void				SetSpeed(int nSpeed)						{ m_nSpeed = nSpeed; }
	int					GetSpeed()									{ return m_nSpeed; }
	bool				IsRunning()									{ return (m_pThrd != NULL); }
	void				SetMode(int nMode = BPC_MODE_BUSY);
	int					GetMode()									{ return m_nMode; }
	void				SetRange(int nLower, int nUpper)			{ m_nLower = nLower; m_nUpper = nUpper; }
	void				GetRange(int& nLower, int& nUpper)			{ nLower = m_nLower; nUpper = m_nUpper; }
	// new in version 0.2
	void				UseSysColBkg(bool bUse = true);
	void				SetBusyType(int nType = BPC_BUSY_PINGPONG);
	int					GetBusyType()								{ return m_nBusyType; }
	void				SetBusyFill(int nFill = BPC_BUSYFILL_BLOCK);
	int					GetBusyFill()								{ return m_nBusyFill; }
	void				SetGranularity(int nGranularity = 5)		{ m_nGranularity = nGranularity; SetBusyFill(m_nBusyFill); }
	int					GetGranularity()							{ return m_nGranularity; }
	
	// since version 0.1
	COLORREF			GetColBkg()									{ return m_colBkg; }
	void				SetColBkg(COLORREF col)						{ m_colBkg = col; }
	COLORREF			GetColBlockFace()							{ return m_colBlockFace; }
	void				SetColBlockFace(COLORREF col)				{ m_colBlockFace = col; }
	COLORREF			GetColBlockEdge()							{ return m_colBlockEdge; }
	void				SetColBlockEdge(COLORREF col)				{ m_colBlockEdge = col; }
	COLORREF			GetColBlockFaceHi()							{ return m_colBlockFaceHi; }
	void				SetColBlockFaceHi(COLORREF col)				{ m_colBlockFaceHi = col; }
	COLORREF			GetColBlockEdgeHi()							{ return m_colBlockEdgeHi; }
	void				SetColBlockEdgeHi(COLORREF col)				{ m_colBlockEdgeHi = col; }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKCBusyProgressCtrl)
	public:
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

protected:

	//
	// Methods
	virtual void		DrawBackground(CDC& dc, CRect& rect);
	void				DrawBlocks(CDC& dc, CRect& rect);
	virtual void		DrawBlock(CDC& dc, CRect& rect);
	virtual void		DrawHiliteBlock(CDC& dc, CRect& rect);
	virtual void		DrawPartialBlock(CDC& dc, CRect& rect, int nPartial);

	// thread
	static UINT			thrdBusy(LPVOID pParam);

	//
	// Attributes
	int					m_nNumSteps;
	int					m_nStep;
	int					m_nCurPos;
	CRect				m_rect;
	int					m_nIBPadding;
	double				m_dBlockHeight;
	double				m_dBlockWidth;
	CWinThread*			m_pThrd;
	bool				m_bBusyThrd;
	int					m_nSpeed;
	int					m_nMode;
	int					m_nLower;
	int					m_nUpper;
	bool				m_bUseSysColBkg;
	int					m_nBusyType;
	int					m_nBusyFill;
	int					m_nGranularity;
	int					m_nNumStepsSmooth;

	// colours
	COLORREF			m_colBkg;
	COLORREF			m_colBlockFace;
	COLORREF			m_colBlockEdge;
	COLORREF			m_colBlockFaceHi;
	COLORREF			m_colBlockEdgeHi;

	// drawing stuff
	CDC					m_memDC;
	CBitmap				m_memBmp;
	CBitmap*			m_pOldBmp;

	// Generated message map functions
	//{{AFX_MSG(CKCBusyProgressCtrl)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSysColorChange();
	//}}AFX_MSG
	afx_msg LRESULT OnSetNumSteps(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetCurPos(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetIBPad(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetSpeed(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetRange(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetMode(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnStartBusy(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEndBusy(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnStepIt(WPARAM wParam, LPARAM lParam);
	// new in version 0.3
	afx_msg LRESULT OnSetBusyType(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetBusyFill(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetGranularity(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetColBkg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetColBFace(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetColBEdge(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetColBFaceHi(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetColBEdgeHi(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRecalc(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnReset(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUseSysCol(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUSYPROGRESSCTRL_H__BEE47141_AAF5_44A5_8408_2C4452BD764A__INCLUDED_)
