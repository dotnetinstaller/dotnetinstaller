// Element.h : Declaration of the CElement

#ifndef __ELEMENT_H_
#define __ELEMENT_H_

#include "resource.h"       // main symbols
#include "AxHTMLayoutCP.h"

/////////////////////////////////////////////////////////////////////////////
// CElement
class ATL_NO_VTABLE CElement : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<CElement, &CLSID_Element>,
  public IConnectionPointContainerImpl<CElement>,
  public IDispatchImpl<IElement, &IID_IElement, &LIBID_HTMLayout>,
  public CProxy_IElementEvents< CElement >,
  public htmlayout::event_handler

{
public:
  dom::element self;
  bool         connected;
  CElement(): connected(false),event_handler(HANDLE_ALL)
  {
  }
  ~CElement() 
  { 
    if(connected) detach_event_handler(self, this ); 
  }

  static HRESULT create(HELEMENT he, IElement** iface)  
  {
    CComObject<CElement>* pElement; 
    HRESULT hr = CComObject<CElement>::CreateInstance(&pElement);
    if (SUCCEEDED(hr) && pElement)
    {   
      pElement->AddRef();
      pElement->self = he;
      pElement->QueryInterface(IID_IElement, reinterpret_cast<void**>(iface));
      pElement->Release();
    }
    return hr;
  }

  STDMETHOD(FindConnectionPoint)(REFIID riid, IConnectionPoint** ppCP)
  {
    HRESULT hr = IConnectionPointContainerImpl<CElement>::FindConnectionPoint(riid, ppCP);
    if(SUCCEEDED(hr))
    {
      if(!connected)
      {
        connected = true;
        htmlayout::attach_event_handler(self, this );
      }
    }
    return hr;
  }

DECLARE_REGISTRY_RESOURCEID(IDR_ELEMENT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CElement)
  COM_INTERFACE_ENTRY(IElement)
  COM_INTERFACE_ENTRY(IDispatch)
  COM_INTERFACE_ENTRY(IConnectionPointContainer)
  COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CElement)
CONNECTION_POINT_ENTRY(DIID__IElementEvents)
END_CONNECTION_POINT_MAP()

  // htmlayout::event_handler events
  virtual BOOL on_mouse  (HELEMENT he, HELEMENT target, UINT event_type, POINT pt, UINT mouseButtons, UINT keyboardStates ) 
  { 
    if(!connected)
      return FALSE; 
    IElement* pTarget = 0;
    HRESULT hr = create(target,&pTarget);
    if( FAILED(hr) )
      return false;
    VARIANT_BOOL handled = 0;
    hr = Fire_onMouse(pTarget, event_type, pt.x, pt.y, mouseButtons, keyboardStates, &handled );
    pTarget->Release();
    if( SUCCEEDED(hr) && handled )
      return TRUE;
    return FALSE; 
  }

  virtual BOOL on_key    (HELEMENT he, HELEMENT target, UINT event_type, UINT code, UINT keyboardStates ) 
  { 
    if(!connected)
      return FALSE; 
    IElement* pTarget = 0;
    HRESULT hr = create(target,&pTarget);
    if( FAILED(hr) )
      return false;
    VARIANT_BOOL handled = 0;
    hr = Fire_onKey(pTarget, event_type, code, keyboardStates, &handled );
    pTarget->Release();
    if( SUCCEEDED(hr) && handled )
      return TRUE;
    return FALSE; 
  }

  virtual BOOL on_focus  (HELEMENT he, HELEMENT target, UINT event_type )
  { 
    if(!connected)
      return FALSE; 
    IElement* pTarget = 0;
    HRESULT hr = create(target,&pTarget);
    if( FAILED(hr) )
      return false;
    VARIANT_BOOL handled = 0;
    hr = Fire_onFocus(pTarget, event_type, &handled );
    pTarget->Release();
    if( SUCCEEDED(hr) && handled )
      return TRUE;
    return FALSE; 
  }

  virtual BOOL on_timer  (HELEMENT he, UINT_PTR extTimerId ) 
  {
    if(!connected)
      return FALSE; 
    VARIANT_BOOL handled = 0;
    HRESULT hr = Fire_onTimer(extTimerId, &handled );
    if( SUCCEEDED(hr) && handled )
      return TRUE;
    return FALSE; 
  }

  virtual BOOL on_event (HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason ) 
  {
    if(!connected)
      return FALSE; 
    IElement* pTarget = 0;
    HRESULT hr = create(target,&pTarget);
    if( FAILED(hr) )
      return false;
    VARIANT_BOOL handled = 0;
    hr = Fire_onControlEvent(pTarget, type, reason, &handled );
    pTarget->Release();
    if( SUCCEEDED(hr) && handled )
      return TRUE;
    return FALSE; 
  }

  virtual BOOL on_scroll( HELEMENT he, HELEMENT target, SCROLL_EVENTS cmd, INT pos, BOOL isVertical )
  {
    if(!connected)
      return FALSE; 
    IElement* pTarget = 0;
    HRESULT hr = create(target,&pTarget);
    if( FAILED(hr) )
      return false;
    VARIANT_BOOL handled = 0;
    hr = Fire_onScroll(pTarget, cmd, pos, isVertical, &handled );
    pTarget->Release();
    if( SUCCEEDED(hr) && handled )
      return TRUE;
    return FALSE; 
  }

// IElement
public:
	STDMETHOD(Call)(BSTR name, SAFEARRAY * params, /*[out,retval]*/ VARIANT *rv);
	STDMETHOD(Dimension)(/*[out]*/ long* w, /*[out]*/ long* h,  ElementBoxType ofWhat);
	STDMETHOD(Position)(/*[out]*/ long* x, /*[out]*/ long* y, ElementBoxType ofWhat, RelativeToType relTo);
	STDMETHOD(SendControlEvent)(long eventType, /*[defaultvalue(0)]*/ long reason, /*[out, retval]*/  VARIANT_BOOL* handled);
	STDMETHOD(PostControlEvent)(long eventType, /*[defaultvalue(0)]*/ long reason);
	STDMETHOD(StopTimer)(long timerId);
	STDMETHOD(StartTimer)(long milliseconds, long timerId);
	STDMETHOD(HidePopup)();
	STDMETHOD(ShowPopup)(long x, long y);
	STDMETHOD(get_styleAttribute)(BSTR name, /*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_styleAttribute)(BSTR name, /*[in]*/ VARIANT newVal);
	STDMETHOD(get_attribute)(BSTR name, /*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_attribute)(BSTR name, /*[in]*/ VARIANT newVal);
  STDMETHOD(SelectAll)(/*[in]*/ BSTR cssSelector, /*[out,retval]*/ IElements** ppEls);
  STDMETHOD(Select)(/*[in]*/ BSTR cssSelector, /*[out, retval]*/ IElement** elm);
  STDMETHOD(get_Value)(/*[out, retval]*/ VARIANT *pVal);
  STDMETHOD(put_Value)(/*[in]*/ VARIANT newVal);
  STDMETHOD(get_Tag)(/*[out, retval]*/ BSTR *pVal);
};




#endif //__ELEMENT_H_
