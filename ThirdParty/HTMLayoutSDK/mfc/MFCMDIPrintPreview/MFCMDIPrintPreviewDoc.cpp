// MFCMDIPrintPreviewDoc.cpp : implementation of the CMFCMDIPrintPreviewDoc class
//

#include "stdafx.h"
#include "MFCMDIPrintPreview.h"

#include "MFCMDIPrintPreviewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewDoc

IMPLEMENT_DYNCREATE(CMFCMDIPrintPreviewDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCMDIPrintPreviewDoc, CDocument)
  //{{AFX_MSG_MAP(CMFCMDIPrintPreviewDoc)
  ON_UPDATE_COMMAND_UI(ID_FILE_PRINT, OnUpdateFilePrint)
  ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, OnUpdateFilePrintPreview)
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewDoc construction/destruction

CMFCMDIPrintPreviewDoc::CMFCMDIPrintPreviewDoc()
{
  // TODO: add one-time construction code here
  m_bLoadedDocument = FALSE;
}

CMFCMDIPrintPreviewDoc::~CMFCMDIPrintPreviewDoc()
{
}

BOOL CMFCMDIPrintPreviewDoc::OnNewDocument()
{
  if (!CDocument::OnNewDocument())
    return FALSE;

  CString strDefaultFile = "..\\html_samples\\HTML32.htm";
  CFileStatus unused_fs;
  if (CFile::GetStatus(strDefaultFile, unused_fs)){
    SetPathName(strDefaultFile);
  }

  return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewDoc serialization

void CMFCMDIPrintPreviewDoc::Serialize(CArchive& ar)
{
  if (ar.IsStoring())
  {
    // TODO: add storing code here
  }
  else
  {
    // TODO: add loading code here
  }
}

/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewDoc diagnostics

#ifdef _DEBUG
void CMFCMDIPrintPreviewDoc::AssertValid() const
{
  CDocument::AssertValid();
}

void CMFCMDIPrintPreviewDoc::Dump(CDumpContext& dc) const
{
  CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewDoc commands

void CMFCMDIPrintPreviewDoc::OnUpdateFilePrint(CCmdUI* pCmdUI){
  pCmdUI->Enable (m_bLoadedDocument);
}

void CMFCMDIPrintPreviewDoc::OnUpdateFilePrintPreview(CCmdUI* pCmdUI){
  pCmdUI->Enable (m_bLoadedDocument);
}
