#pragma once

/* 
 CHyperlinkStatic: modified version from Franz Wong / Simple Hyperlink Static Control 
 http://www.codeguru.com/Cpp/controls/staticctrl/article.php/c5801/ 
 */
class CHyperlinkStatic : public CStatic
{
public:
	CHyperlinkStatic();
public:
	BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);
	//{{AFX_VIRTUAL(CHyperlinkStatic)
protected:
	virtual void PreSubclassWindow();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL
public:
	virtual ~CHyperlinkStatic();
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
	CString _strCaption;
	CString _strHyperlink;
	CFont _fontCaption;
	CSize _sizeCaption;
	CRect _rect;
	CRect _captionRect;
	bool _bCreateFont;
	bool _bMouseInControl;
	bool _bGetCaptionSize;
	HCURSOR	_hHandCursor;
	HCURSOR	_hArrowCursor;
	void CreateFont();
	void GetCaptionSize();
	bool InCaptionRange(CPoint &point);
};
