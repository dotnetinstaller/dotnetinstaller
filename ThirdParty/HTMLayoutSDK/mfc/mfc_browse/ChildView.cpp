// ChildView.cpp : implementation of the CLayoutView class
//

#include "stdafx.h"
#include "mfc_browse.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLayoutView

CLayoutView::CLayoutView(): event_handler(HANDLE_ALL)
{
}

CLayoutView::~CLayoutView()
{
}


BEGIN_MESSAGE_MAP(CLayoutView,CWnd )
  //{{AFX_MSG_MAP(CLayoutView)
  ON_WM_CREATE()
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CLayoutView message handlers

BOOL CLayoutView::PreCreateWindow(CREATESTRUCT& cs) 
{
  if (!CWnd::PreCreateWindow(cs))
    return FALSE;

  cs.dwExStyle |= WS_EX_CLIENTEDGE;
  cs.style &= ~WS_BORDER;
  cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
    ::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);
  
  return TRUE;
}



LRESULT CLayoutView::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
  LRESULT lResult;
  BOOL    bHandled = FALSE;
  // HTMLayout +
  // HTMLayout could be created as sepearate window 
  // using CreateWindow API.
  // But in this case we are attaching HTMLayout functionality
  // to the existing window delegating windows message handling to 
  // HTMLayoutProcND function.
  lResult = HTMLayoutProcND(m_hWnd,message,wParam,lParam, &bHandled);
  if(bHandled)
    return lResult;
  // HTMLayout -  
  
  return CWnd ::WindowProc(message, wParam, lParam);
}


// HTMLayout specific notification handler.
static LRESULT CALLBACK HTMLayoutNotifyHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, LPVOID vParam)
{
  // all HTMLayout notification are comming here.
  NMHDR*  phdr = (NMHDR*)lParam;

  CLayoutView* pView = static_cast<CLayoutView*>(vParam);

  switch(phdr->code)
  {
      case HLN_CREATE_CONTROL:    return pView->OnCreateControl((LPNMHL_CREATE_CONTROL) lParam);
      case HLN_CONTROL_CREATED:   return pView->OnControlCreated((LPNMHL_CREATE_CONTROL) lParam);
      case HLN_DESTROY_CONTROL:   return pView->OnDestroyControl((LPNMHL_DESTROY_CONTROL) lParam);
      case HLN_LOAD_DATA:         return pView->OnLoadData((LPNMHL_LOAD_DATA) lParam);
      case HLN_DATA_LOADED:       return pView->OnDataLoaded((LPNMHL_DATA_LOADED)lParam);
      case HLN_DOCUMENT_COMPLETE: return pView->OnDocumentComplete();
      case HLN_ATTACH_BEHAVIOR:   return pView->OnAttachBehavior((LPNMHL_ATTACH_BEHAVIOR)lParam );
  }
  return 0;
}

BOOL GetHtmlResource(LPCTSTR pszName, /*out*/PBYTE& pb, /*out*/DWORD& cb);

int CLayoutView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
  if (CWnd::OnCreate(lpCreateStruct) == -1)
    return -1;
  
  HTMLayoutSetCallback(m_hWnd,&HTMLayoutNotifyHandler,this); // attach handler of htmlayout events

  htmlayout::attach_event_handler(m_hWnd,this); // attach handler of DOM events
  
  PBYTE pb; DWORD cb;
  if(GetHtmlResource(TEXT("DEFAULT"),pb,cb))
      LoadHtml(pb,cb);
  
  return 0;
}

LRESULT CLayoutView::OnAttachBehavior(LPNMHL_ATTACH_BEHAVIOR lpab )
{
    // attach custom behaviors
    htmlayout::event_handler *pb = htmlayout::behavior::find(lpab->behaviorName, lpab->element);
    if(pb)
    {
      lpab->elementTag  = pb;
      lpab->elementProc = htmlayout::behavior::element_proc;
      lpab->elementEvents = pb->subscribed_to;
    }
    
    // this project includes two behavior implementationsL
    // behavior_hyperlink.cpp
    // behavior_command.cpp
    // to connect them into the chain of available 
    // behaviors - just include them into the project.
    return 0;
}



BOOL GetHtmlResource(LPCTSTR pszName, /*out*/PBYTE& pb, /*out*/DWORD& cb)
{
  // Find specified resource and check if ok

  HRSRC hrsrc = ::FindResource( theApp.m_hInstance, pszName, MAKEINTRESOURCE(RT_HTML));

  if(!hrsrc) 
    return false;

  // Load specified resource and check if ok
  
  HGLOBAL hgres = ::LoadResource(theApp.m_hInstance, hrsrc);
  if(!hgres) return FALSE;

  // Retrieve resource data and check if ok

  pb = (PBYTE)::LockResource(hgres); if (!pb) return FALSE;
  cb = ::SizeofResource(theApp.m_hInstance, hrsrc); if (!cb) return FALSE;

  return TRUE;
}

bool CLayoutView::LoadHtmlResource(LPCTSTR name)
{
  ASSERT(::IsWindow(m_hWnd));
  PBYTE pb; DWORD cb;
  if(GetHtmlResource(name,pb,cb))
    return LoadHtml(pb,cb);
  return false;
}
