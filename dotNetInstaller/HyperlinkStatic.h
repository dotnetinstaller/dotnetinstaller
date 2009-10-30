/****************************************************************************
 *	class		:	CHyperlinkStatic
 *	author		:	Franz Wong / Simple Hyperlink Static Control / http://www.codeguru.com/Cpp/controls/staticctrl/article.php/c5801/
 */

#if !defined(AFX_HYPERLINKSTATIC_H__32A71426_1315_407C_9D90_A484C5589D80__INCLUDED_)
#define AFX_HYPERLINKSTATIC_H__32A71426_1315_407C_9D90_A484C5589D80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HyperlinkStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHyperlinkStatic window

class CHyperlinkStatic : public CStatic
{
// Construction
public:
	CHyperlinkStatic();

// Attributes
public:

// Operations
public:

	BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHyperlinkStatic)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHyperlinkStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CHyperlinkStatic)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	void SetHyperlink(std::wstring strHyperlink);
	void SetCaption(std::wstring strCaption);
private:
	CString _strCaption, _strHyperlink;
	CFont _fontCaption;
	CSize _sizeCaption;
	CRect _rect;
	CRect _captionRect;
	bool _bCreateFont, _bMouseInControl, _bGetCaptionSize;
	HCURSOR	_hHandCursor, _hArrowCursor;

	void CreateFont();
	void GetCaptionSize();
	bool InCaptionRange(CPoint &point);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HYPERLINKSTATIC_H__32A71426_1315_407C_9D90_A484C5589D80__INCLUDED_)
