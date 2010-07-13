// HTMLayoutCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "Wizard.h"
#include "HTMLayoutCtrl.h"


// CHTMLayoutCtrl

IMPLEMENT_DYNAMIC(CHTMLayoutCtrl, CWnd)
CHTMLayoutCtrl::CHTMLayoutCtrl()
{
}

CHTMLayoutCtrl::~CHTMLayoutCtrl()
{
}

BOOL CHTMLayoutCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
  UINT nID)
{
  CWnd* pWnd = this;
  if(pWnd->Create(::HTMLayoutClassNameT(), NULL, dwStyle, rect, pParentWnd, nID))
  {
    SetCallback(); // reroute all HTMLayout notifications directly to this class
    return TRUE;
  }
  return FALSE;
}

BOOL CHTMLayoutCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
  CWnd* pParentWnd, UINT nID)
{
  BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
  if (bRet)
  {
    ModifyStyleEx(0, dwExStyle);
  }
  return bRet;
}

BEGIN_MESSAGE_MAP(CHTMLayoutCtrl, CWnd)
END_MESSAGE_MAP()


// CHTMLayoutCtrl message handlers



bool CHTMLayoutCtrl::LoadHtmlResource(LPCTSTR pszName, HMODULE hModule)
{
  // This code assumes that the host and control windows are the same
  ASSERT(::IsWindow(m_hWnd));

  LPBYTE pb;
  DWORD  cb;

  if(!GetHtmlResource(pszName, pb, cb, hModule))
    return false;

  return LoadHtml(pb, cb);
}

bool CHTMLayoutCtrl::LoadHtmlResource(DWORD resID, HMODULE hModule)
{
  return LoadHtmlResource(MAKEINTRESOURCE(resID), hModule);
}



bool GetHtmlResource(LPCTSTR pszName, /*out*/PBYTE& pb, /*out*/DWORD& cb, HMODULE hModule)
{
  ASSERT(pszName != NULL);

  // Find specified resource and check if ok

  if(!hModule)
    hModule = theApp.m_hInstance;
  
  HRSRC hrsrc = ::FindResource(hModule, pszName, MAKEINTRESOURCE(RT_HTML));

  if(!hrsrc) 
    return false;

  // Load specified resource and check if ok
  
  HGLOBAL hgres = ::LoadResource(hModule, hrsrc);
  if(!hgres) return false;

  // Retrieve resource data and check if ok

  pb = (PBYTE)::LockResource(hgres); if (!pb) return false;
  cb = ::SizeofResource(hModule, hrsrc); if (!cb) return false;

  return true;
}

  LRESULT CHTMLayoutCtrl::OnBehaviorNotify(UINT uMsg, WPARAM wParam, LPARAM lParam)
  {
    ASSERT(uMsg == WM_BEHAVIOR_NOTIFY);

    // Crack and call appropriate method
    
    // here are all notifiactions
    switch(((NMHDR*)lParam)->code) 
    {
      case HLN_HYPERLINK:         
        return OnHyperLink((NMHL_HYPERLINK*) lParam);
      case HLN_COMMAND_CLICK:
        return OnHtmlCommand((NMHL_COMMAND_CLICK*)lParam);
    }
    return 0;
  }

  LRESULT CHTMLayoutCtrl::OnHtmlGenericNotifications(UINT uMsg, WPARAM wParam, LPARAM lParam)
  {
    // all generic notifications 
    // are coming to the parent of HTMLayout
    ASSERT(::IsWindow(m_hWnd));
    // Pass it to the parent window if any
    HWND hWndParent = ::GetParent(m_hWnd);
    if (!hWndParent) return 0;
    return ::SendMessage(hWndParent, uMsg, wParam, lParam);
  }

  LRESULT CHTMLayoutCtrl::OnCreateControl(LPNMHL_CREATE_CONTROL pnmcc)
  {
    TRACE(_T("CHTMLayoutCtrl::OnCreateControl: type='%s' \n"), GetElementType(pnmcc->helement) );

    // Try to create control and if failed, proceed with default processing.
    // Note that this code assumes that the host and control windows are the same. If
    // you are handling HTMLayout control notification in another window, you'll have
    // to override this method and provide proper hWnd.

    ASSERT(::IsWindow(m_hWnd));

    //return CreateControl(pT->m_hWnd, pnmcc);
    return 0;
  }

  LRESULT CHTMLayoutCtrl::OnControlCreated(LPNMHL_CREATE_CONTROL pnmcc)
  {
    TRACE(_T("CHTMLayoutHost::OnControlCreated: type='%s' \n"), GetElementType(pnmcc->helement) );
    return 0;
  }

  LRESULT CHTMLayoutCtrl::OnDestroyControl(LPNMHL_DESTROY_CONTROL pnmhl)
  {
    TRACE(_T("CHTMLayoutHost::OnDestroyControl: HWND=%x\n"), pnmhl->inoutControlHwnd);
    
    //  use this if you don't want this child to be destroyed:
    //  pnmhl->inoutControlHwnd = 0;

    //  If you will not change pnmhl->inoutControlHwnd field then HTMLayout 
    //  will call ::DestroyWindow by itself.

    return 0;
  }


  LRESULT CHTMLayoutCtrl::OnHyperLink(NMHL_HYPERLINK* pnmhl)
  {
    ATLTRACE(_T("CHTMLayoutHost::OnHyperLink: href='%s' target='%s' action=%u\n"), 
      CString(pnmhl->szHREF), CString(pnmhl->szTarget), pnmhl->action);

    switch (pnmhl->action) {
      case NMHL_HYPERLINK::ENTER: return OnHyperLinkEnter(pnmhl);
      case NMHL_HYPERLINK::LEAVE: return OnHyperLinkLeave(pnmhl);
      case NMHL_HYPERLINK::CLICK: return OnHyperLinkClick(pnmhl);
    }

    return 0;
  }

  LRESULT CHTMLayoutCtrl::OnHyperLinkEnter(NMHL_HYPERLINK* pnmhl)
  {
    return 0;
  }

  LRESULT CHTMLayoutCtrl::OnHyperLinkLeave(NMHL_HYPERLINK* pnmhl)
  {
    return 0;
  }

  LRESULT CHTMLayoutCtrl::OnHyperLinkClick(NMHL_HYPERLINK* pnmhl)
  {
    USES_CONVERSION;
    ::ShellExecute(m_hWnd,TEXT("open"),CW2T(pnmhl->szHREF),NULL,NULL,SW_SHOW);
    return 0;
  }

  LRESULT CHTMLayoutCtrl::OnLoadData(LPNMHL_LOAD_DATA pnmld)
  {
    TRACE(_T("CHTMLayoutHost::OnLoadData: uri='%s'\n"), CString(pnmld->uri));

    // Try to load data from resource and if failed, proceed with default processing.
    // Note that this code assumes that the host and control windows are the same. If
    // you are handling HTMLayout control notification in another window, you'll have
    // to override this method and provide proper hWnd.
    return LoadResourceData(pnmld);
  }

  LRESULT CHTMLayoutCtrl::OnDataLoaded(LPNMHL_DATA_LOADED pnmld)
  {
    ATLTRACE(_T("CHTMLayoutHost::OnDataLoaded: uri='%s'\n"), CString(pnmld->uri));
    return 0;
  }

  LRESULT CHTMLayoutCtrl::OnDocumentComplete()
  {
    ATLTRACE(_T("CHTMLayoutHost::OnDocumentComplete\n"));
    return 0;
  }

  LRESULT CHTMLayoutCtrl::OnAttachBehavior( LPNMHL_ATTACH_BEHAVIOR lpab )
  {
    htmlayout::event_handler *pb = htmlayout::behavior::find(lpab->behaviorName, lpab->element);
  if(pb)
  {
    lpab->elementTag  = pb;
    lpab->elementProc = htmlayout::behavior::element_proc;
    lpab->elementEvents = pb->subscribed_to;
  }
    return 0;
  }

  int CHTMLayoutCtrl::GetAttrInt(HELEMENT he, LPCSTR attrName, int defaultValue)
  {
    htmlayout::dom::element el = he;
    const wchar_t* pv = el.get_attribute(attrName);
    if(pv && wcslen(pv) > 0)
      return _wtoi(pv);
    return defaultValue;
  }

  CString CHTMLayoutCtrl::GetElementType(HELEMENT he)
  {
    htmlayout::dom::element el = he;
    USES_CONVERSION;
    CString s = CA2T(el.get_element_type());
    return s;
  }

  CString CHTMLayoutCtrl::GetAttr(HELEMENT he, LPCSTR attrName)
  {
    htmlayout::dom::element el = he;
    USES_CONVERSION;
    CString s = CW2T(el.get_attribute(attrName));
    return s;
  }

  bool CHTMLayoutCtrl::HasAttr(HELEMENT he, LPCSTR attrName)
  {
    htmlayout::dom::element el = he;
    for(unsigned int i = 0; i < el.get_attribute_count(); ++i)
    {
      if(stricmp(el.get_attribute_name(i),attrName) == 0)
        return true;
    }
    return false;
  }

  static LRESULT LoadResourceData(HWND hWnd, LPCWSTR uri )
  {
    USES_CONVERSION;

    ATLASSERT(::IsWindow(hWnd));
    // Check for trivial case

    if (!uri || !uri[0]) return LOAD_DISCARD;

    // Retrieve url specification into a local storage since FindResource() expects 
    // to find its parameters on stack rather then on the heap under Win9x/Me

    TCHAR achURL[MAX_PATH]; lstrcpyn(achURL, W2CT(uri), MAX_PATH);

    
    // Separate name and handle external resource module specification

    LPTSTR pszName = achURL;

    /*
    Module module;
    LPTSTR psz;
    if ((psz = _tcsrchr(pszName, '/')) != NULL) {
      LPTSTR pszModule = pszName; pszName = psz + 1; *psz = '\0';
      DWORD dwAttr = ::GetFileAttributes(pszModule);
      if (dwAttr != INVALID_FILE_ATTRIBUTES && !(dwAttr & FILE_ATTRIBUTE_DIRECTORY)) {
        module.Load(pszModule, LOAD_LIBRARY_AS_DATAFILE);
      }
    }
    */

    // Separate extension if any

    LPTSTR pszExt = _tcsrchr(pszName, '.'); if (pszExt) *pszExt++ = '\0';

    // Find specified resource and leave if failed. Note that we use extension
    // as the custom resource type specification or assume standard HTML resource 
    // if no extension is specified

    HRSRC hrsrc = 0;
    bool  isHtml = false;
    if( pszExt == 0 || _tcsicmp(pszExt,TEXT("HTML")) == 0)
    {
      hrsrc = ::FindResource(theApp.m_hInstance, pszName, RT_HTML);
      isHtml = true;
    }
    else
      hrsrc = ::FindResource(theApp.m_hInstance, pszName, pszExt);

    if (!hrsrc) return LOAD_OK; // resource not found here - proceed with default loader

    // Load specified resource and check if ok

    HGLOBAL hgres = ::LoadResource(theApp.m_hInstance, hrsrc);
    if (!hgres) return LOAD_DISCARD;

    // Retrieve resource data and check if ok

    PBYTE pb = (PBYTE)::LockResource(hgres); if (!pb) return LOAD_DISCARD;
    DWORD cb = ::SizeofResource(theApp.m_hInstance, hrsrc); if (!cb) return LOAD_DISCARD;

    // Report data ready

    ::HTMLayoutDataReady(hWnd, uri, pb,  cb);
    
    return LOAD_OK;
  }

  static LRESULT LoadResourceData(HWND hWnd, LPCSTR uri )
  {
     USES_CONVERSION;
     return LoadResourceData(hWnd,A2CW(uri));
  }


  LRESULT CHTMLayoutCtrl::LoadResourceData(LPNMHL_LOAD_DATA pnmld)
  {
    // This code assumes that the host and control windows are the same
    ASSERT(::IsWindow(m_hWnd));
    return ::LoadResourceData(m_hWnd, pnmld->uri);
  }
