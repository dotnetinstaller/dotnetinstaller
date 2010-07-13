// Engine.h : Declaration of the CEngine

#ifndef __ENGINE_H_
#define __ENGINE_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "AxHTMLayoutCP.h"


/////////////////////////////////////////////////////////////////////////////
// CEngine
class ATL_NO_VTABLE CEngine : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CStockPropImpl<CEngine, IEngine, &IID_IEngine, &LIBID_HTMLayout>,
  public CComControl<CEngine>,
  public IPersistStreamInitImpl<CEngine>,
  public IOleControlImpl<CEngine>,
  public IOleObjectImpl<CEngine>,
  public IOleInPlaceActiveObjectImpl<CEngine>,
  public IViewObjectExImpl<CEngine>,
  public IOleInPlaceObjectWindowlessImpl<CEngine>,
  public ISupportErrorInfo,
  public IConnectionPointContainerImpl<CEngine>,
  public IPersistStorageImpl<CEngine>,
  public ISpecifyPropertyPagesImpl<CEngine>,
  public IQuickActivateImpl<CEngine>,
  public IDataObjectImpl<CEngine>,
  public IProvideClassInfo2Impl<&CLSID_Engine, &DIID__IEngineEvents, &LIBID_HTMLayout>,
  public IPropertyNotifySinkCP<CEngine>,
  public CComCoClass<CEngine, &CLSID_Engine>,
  public CProxy_IEngineEvents<CEngine>,
  public notification_handler<CEngine>
{
public:
  CEngine()
  {
    m_bWindowOnly = TRUE;
  }

DECLARE_REGISTRY_RESOURCEID(IDR_ENGINE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CEngine)
  COM_INTERFACE_ENTRY(IEngine)
  COM_INTERFACE_ENTRY(IDispatch)
  COM_INTERFACE_ENTRY(IViewObjectEx)
  COM_INTERFACE_ENTRY(IViewObject2)
  COM_INTERFACE_ENTRY(IViewObject)
  COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
  COM_INTERFACE_ENTRY(IOleInPlaceObject)
  COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
  COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
  COM_INTERFACE_ENTRY(IOleControl)
  COM_INTERFACE_ENTRY(IOleObject)
  COM_INTERFACE_ENTRY(IPersistStreamInit)
  COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
  COM_INTERFACE_ENTRY(ISupportErrorInfo)
  COM_INTERFACE_ENTRY(IConnectionPointContainer)
  COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
  COM_INTERFACE_ENTRY(IQuickActivate)
  COM_INTERFACE_ENTRY(IPersistStorage)
  COM_INTERFACE_ENTRY(IDataObject)
  COM_INTERFACE_ENTRY(IProvideClassInfo)
  COM_INTERFACE_ENTRY(IProvideClassInfo2)
  COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_PROP_MAP(CEngine)
  PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
  PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
  PROP_ENTRY("AutoSize", DISPID_AUTOSIZE, CLSID_NULL)
  PROP_ENTRY("BorderVisible", DISPID_BORDERVISIBLE, CLSID_NULL)
  PROP_ENTRY("Enabled", DISPID_ENABLED, CLSID_NULL)
  //PROP_ENTRY("HWND", DISPID_HWND, CLSID_NULL)
  PROP_ENTRY("TabStop", DISPID_TABSTOP, CLSID_NULL)
  // Example entries
  // PROP_ENTRY("Property Description", dispid, clsid)
  // PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CEngine)
  CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
  //CONNECTION_POINT_ENTRY(__uuidof(_IEngineEvents))
  CONNECTION_POINT_ENTRY(DIID__IEngineEvents)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CEngine)
  {
     BOOL    bHandled = FALSE;
     LRESULT lResult = HTMLayoutProcND(hWnd,uMsg,wParam,lParam, &bHandled);
     if(bHandled)
       return lResult;
  }
  CHAIN_MSG_MAP(CComControl<CEngine>)
  DEFAULT_REFLECTION_HANDLER()
  MESSAGE_HANDLER(WM_CREATE, OnCreate)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

// notification_handler<CEngine>
  virtual LRESULT on_document_complete() 
  { 
    Fire_DocumentComplete();
    return 0; 
  }
  virtual LRESULT on_document_loaded()
  {
    Fire_DocumentLoaded();
    return 0; 
  }

  virtual LRESULT on_data_loaded(LPNMHL_DATA_LOADED pnmld)  
  { 
    BSTR st = SysAllocString(pnmld->uri);
    Fire_DataDelivered(st,pnmld->dataType,pnmld->status,const_cast<BYTE*>(pnmld->data), pnmld->dataSize);
    SysFreeString(st);
    return 0; 
  }
  


// ISupportsErrorInfo
  STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
  {
    static const IID* arr[] = 
    {
      &IID_IEngine,
    };
    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
      if (IsEqualGUID(*arr[i], riid))
        return S_OK;
    }
    return S_FALSE;
  }

// IViewObjectEx
  DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IEngine
public:
  STDMETHOD(get_Root)(/*[out, retval]*/ IElement* *pVal);
  STDMETHOD(LoadHtml)(/*[in]*/ BSTR html, /*[in, defaultvalue("")]*/ BSTR baseUrl);
  STDMETHOD(Load)(BSTR url);

  HRESULT OnDraw(ATL_DRAWINFO& di)
  {
    RECT& rc = *(RECT*)di.prcBounds;
    Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

    SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
    LPCTSTR pszText = _T("ATL 3.0 : Engine");
    TextOut(di.hdcDraw, 
      (rc.left + rc.right) / 2, 
      (rc.top + rc.bottom) / 2, 
      pszText, 
      lstrlen(pszText));

    return S_OK;
  }
  BOOL m_bBorderVisible;
  BOOL m_bEnabled;
  BOOL m_bTabStop;

  virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator( LPMSG lpmsg )
  {
    bool is_ctrl = GetKeyState(VK_CONTROL) < 0;

    if( lpmsg->message == WM_KEYDOWN && lpmsg->hwnd == m_hWnd &&
      (lpmsg->wParam == VK_TAB) || ((lpmsg->wParam == VK_LEFT)
                                ||  (lpmsg->wParam == VK_RIGHT)
                                ||  (lpmsg->wParam == VK_UP)
                                ||  (lpmsg->wParam == VK_DOWN)
                                ||  (lpmsg->wParam == VK_HOME)
                                ||  (lpmsg->wParam == VK_END)
                                ||  (lpmsg->wParam == VK_NEXT)
                                ||  (lpmsg->wParam == VK_PRIOR)
                                ||  (lpmsg->wParam == VK_RETURN)
                                ||  (lpmsg->wParam == VK_BACK)
                                ||  is_ctrl))
    {
      BOOL    bHandled = FALSE;
      LRESULT lResult = HTMLayoutProcND(m_hWnd,lpmsg->message,lpmsg->wParam,lpmsg->lParam, &bHandled);
      if(!bHandled)
        return IOleInPlaceActiveObjectImpl<CEngine>::TranslateAccelerator(lpmsg);
      return S_OK;
    }
    return IOleInPlaceActiveObjectImpl<CEngine>::TranslateAccelerator(lpmsg);

  }


  LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {
    setup_callback(m_hWnd);
    LPCBYTE pb; DWORD cb;
    if(LoadHtmlResource(IDR_HTML_DEFAULT, pb, cb ))
      HTMLayoutLoadHtml(m_hWnd,pb,cb);
    return 0;
  }
};

#endif //__ENGINE_H_
