// MFCMDIPrintPreviewView.cpp : implementation of the CMFCMDIPrintPreviewView class
//

#include "stdafx.h"
#include "MFCMDIPrintPreview.h"

#include "MFCMDIPrintPreviewDoc.h"
#include "MFCMDIPrintPreviewView.h"

#include "SimplePageSetup.h"

#include <atlconv.h> //for USES_CONVERSION

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewView

IMPLEMENT_DYNCREATE(CMFCMDIPrintPreviewView, CView)

BEGIN_MESSAGE_MAP(CMFCMDIPrintPreviewView, CView)
  //{{AFX_MSG_MAP(CMFCMDIPrintPreviewView)
  ON_WM_SIZE()
  //}}AFX_MSG_MAP
  // Standard printing commands
  ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
  ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
  ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewView construction/destruction

CMFCMDIPrintPreviewView::CMFCMDIPrintPreviewView()
{
  // TODO: add construction code here

  m_pPrinter = NULL;
  m_margin_top = 1.0;
  m_margin_left = 1.0;
  m_margin_right = 1.0;
  m_margin_bottom = 1.0;
}

CMFCMDIPrintPreviewView::~CMFCMDIPrintPreviewView()
{
}

BOOL CMFCMDIPrintPreviewView::PreCreateWindow(CREATESTRUCT& cs)
{
  // TODO: Modify the Window class or styles here by modifying
  //  the CREATESTRUCT cs

  return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewView diagnostics

#ifdef _DEBUG
void CMFCMDIPrintPreviewView::AssertValid() const
{
  CView::AssertValid();
}

void CMFCMDIPrintPreviewView::Dump(CDumpContext& dc) const
{
  CView::Dump(dc);
}

CMFCMDIPrintPreviewDoc* CMFCMDIPrintPreviewView::GetDocument() // non-debug version is inline
{
  ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMDIPrintPreviewDoc)));
  return (CMFCMDIPrintPreviewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewView drawing

void CMFCMDIPrintPreviewView::OnDraw(CDC* /*pDC*/)
{
  CMFCMDIPrintPreviewDoc* pDoc = GetDocument();
  ASSERT_VALID(pDoc);
  // TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewView message handlers

LRESULT CMFCMDIPrintPreviewView::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
  // HTMLayout +
  // HTMLayout could be created as separate window 
  // using CreateWindow API.
  // But in this case we are attaching HTMLayout functionality
  // to the existing window delegating windows message handling to 
  // HTMLayoutProcND function.
  BOOL    bHandled = FALSE;
  LRESULT lResult = HTMLayoutProcND(m_hWnd,message,wParam,lParam, &bHandled);
  if(bHandled)
    return lResult;
  
  return CView::WindowProc(message, wParam, lParam);
}

bool CMFCMDIPrintPreviewView::LoadUrl(LPCTSTR url)
{
  USES_CONVERSION;
  ASSERT(::IsWindow(m_hWnd));
  return (::HTMLayoutLoadFile(m_hWnd, T2W(url)) != 0);
}

void CMFCMDIPrintPreviewView::OnInitialUpdate() 
{
  CView::OnInitialUpdate();
  if (!GetDocument()->GetPathName().IsEmpty()){
    GetDocument()->m_bLoadedDocument = LoadUrl(GetDocument()->GetPathName());
  }
}

/////////////////////////////////////////////////////////////////////////////
// CMFCMDIPrintPreviewView printing

BOOL CMFCMDIPrintPreviewView::OnPreparePrinting(CPrintInfo* pInfo)
{
  // Create printer instance
  if (m_pPrinter != NULL){
    delete m_pPrinter;
  }
  m_pPrinter = new PrintEx;
  if (!m_pPrinter->load(GetDocument()->GetPathName())){
    delete m_pPrinter;
    m_pPrinter = NULL;
    return FALSE;
  }

  // default preparation
  return DoPreparePrinting(pInfo);
}

void CMFCMDIPrintPreviewView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
  pInfo->SetMinPage(1);

  // get some printer metrics
  double dpix = (double)pDC->GetDeviceCaps(LOGPIXELSX);
  double dpiy = (double)pDC->GetDeviceCaps(LOGPIXELSY);
  int unprintable_x = pDC->GetDeviceCaps(PHYSICALOFFSETX);
  int unprintable_y = pDC->GetDeviceCaps(PHYSICALOFFSETY);
  int total_page_cx = pDC->GetDeviceCaps(PHYSICALWIDTH);
  int total_page_cy = pDC->GetDeviceCaps(PHYSICALHEIGHT);
  int printable_area_cx = pDC->GetDeviceCaps (HORZRES);
  int printable_area_cy = pDC->GetDeviceCaps (VERTRES);

  // calculate maximum printable area
  CRect rcMaxPrintArea;
  rcMaxPrintArea.left   = unprintable_x;
  rcMaxPrintArea.right  = printable_area_cx + unprintable_x;
  rcMaxPrintArea.top    = unprintable_y;
  rcMaxPrintArea.bottom = printable_area_cy + unprintable_y;

  // Ask user for new margins
  CSimplePageSetup dlg;
  dlg.m_margin_left = m_margin_left;
  dlg.m_margin_top = m_margin_top;
  dlg.m_margin_right = m_margin_right;
  dlg.m_margin_bottom = m_margin_bottom;
  dlg.m_height = total_page_cy / dpiy;
  dlg.m_width  = total_page_cx / dpix;
  if (IDOK==dlg.DoModal()){
    m_margin_left = dlg.m_margin_left;
    m_margin_top = dlg.m_margin_top;
    m_margin_right = dlg.m_margin_right;
    m_margin_bottom = dlg.m_margin_bottom;
  }

  // calculate printable area adjusted for margins
  m_rcPrintArea.left = (int)(m_margin_left * dpix) - unprintable_x;
  m_rcPrintArea.top  = (int)(m_margin_top  * dpiy) - unprintable_y;
  m_rcPrintArea.right  = total_page_cx - (int)(m_margin_right  * dpix) - unprintable_x;
  m_rcPrintArea.bottom = total_page_cy - (int)(m_margin_bottom * dpiy) - unprintable_y;

  // validate adjusted printable area
  m_rcPrintArea.left   = min (rcMaxPrintArea.right,   max (rcMaxPrintArea.left,   m_rcPrintArea.left) );
  m_rcPrintArea.top    = min (rcMaxPrintArea.bottom,  max (rcMaxPrintArea.top,    m_rcPrintArea.top) );
  m_rcPrintArea.right  = max (rcMaxPrintArea.left,    min (rcMaxPrintArea.right,  m_rcPrintArea.right) );
  m_rcPrintArea.bottom = max (rcMaxPrintArea.top,     min (rcMaxPrintArea.bottom, m_rcPrintArea.bottom) );

  pInfo->m_rectDraw = m_rcPrintArea;

  // Calculate scale factor for true 1:1 scale (e.g. 12 point font on screen should be 12 point font on printer) 
  CClientDC dc_screen(this);
  double fx = (double)dc_screen.GetDeviceCaps(LOGPIXELSX) / (double)::GetDeviceCaps(pDC->m_hAttribDC, LOGPIXELSX);
  m_scaled_width = (int)(fx * m_rcPrintArea.Width());
  
  // Scale for printing and calculate number of pages
  int num_pages = m_pPrinter->measure(*pDC, m_scaled_width, m_rcPrintArea.Width(), m_rcPrintArea.Height());
  if (num_pages > 0){

    pInfo->SetMaxPage((UINT)num_pages);
  }
  else{
    pInfo->SetMaxPage (1);
  }
  m_measured = CSize(0,0);
}

void CMFCMDIPrintPreviewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
  if (m_pPrinter!=NULL){
    delete m_pPrinter;
    m_pPrinter = NULL;
  }
}

void CMFCMDIPrintPreviewView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
  // TODO: Add your specialized code here and/or call the base class
  
  CView::OnPrepareDC(pDC, pInfo);
}

void CMFCMDIPrintPreviewView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
  if (m_pPrinter!=NULL)
  {
    // Draw HTMLayout
    if (pInfo->m_bPreview)
    {
      CPoint ptTopLeft (m_rcPrintArea.TopLeft());
      CPoint ptBotRigh (m_rcPrintArea.BottomRight());
      ::LPtoDP(pDC->m_hDC, &ptTopLeft, 1);
      ::LPtoDP(pDC->m_hDC, &ptBotRigh, 1);

      CSize measured = CSize(ptBotRigh.x-ptTopLeft.x, ptBotRigh.y-ptTopLeft.y);
      if(m_measured != measured)
      {
        m_pPrinter->measure(pDC->GetSafeHdc(), m_scaled_width, ptBotRigh.x-ptTopLeft.x, ptBotRigh.y-ptTopLeft.y);
        m_measured = measured;
      }
      m_pPrinter->render(pDC->GetSafeHdc(), ptTopLeft.x, ptTopLeft.y, pInfo->m_nCurPage-1);
    }
    else{
      m_pPrinter->render(pDC->GetSafeHdc(), m_rcPrintArea.left, m_rcPrintArea.top, pInfo->m_nCurPage-1);
    }

    // Draw borders
    pDC->MoveTo(m_rcPrintArea.left, m_rcPrintArea.top);
    pDC->LineTo(m_rcPrintArea.right, m_rcPrintArea.top);
    pDC->LineTo(m_rcPrintArea.right, m_rcPrintArea.bottom);
    pDC->LineTo(m_rcPrintArea.left, m_rcPrintArea.bottom);
    pDC->LineTo(m_rcPrintArea.left, m_rcPrintArea.top);
  }
}

void CMFCMDIPrintPreviewView::OnSize(UINT nType, int cx, int cy) 
{
  CView::OnSize(nType, cx, cy);
}
