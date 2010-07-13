// MFCMDIPrintPreviewDoc.h : interface of the CMFCMDIPrintPreviewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCMDIPRINTPREVIEWDOC_H__C0565F11_CF13_4D2F_B9E8_702E053B6AA1__INCLUDED_)
#define AFX_MFCMDIPRINTPREVIEWDOC_H__C0565F11_CF13_4D2F_B9E8_702E053B6AA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCMDIPrintPreviewDoc : public CDocument
{
protected: // create from serialization only
  CMFCMDIPrintPreviewDoc();
  DECLARE_DYNCREATE(CMFCMDIPrintPreviewDoc)

// Attributes
public:
  BOOL m_bLoadedDocument;

// Operations
public:

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CMFCMDIPrintPreviewDoc)
  public:
  virtual BOOL OnNewDocument();
  virtual void Serialize(CArchive& ar);
  //}}AFX_VIRTUAL

// Implementation
public:
  virtual ~CMFCMDIPrintPreviewDoc();
#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
  //{{AFX_MSG(CMFCMDIPrintPreviewDoc)
  afx_msg void OnUpdateFilePrint(CCmdUI* pCmdUI);
  afx_msg void OnUpdateFilePrintPreview(CCmdUI* pCmdUI);
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCMDIPRINTPREVIEWDOC_H__C0565F11_CF13_4D2F_B9E8_702E053B6AA1__INCLUDED_)
