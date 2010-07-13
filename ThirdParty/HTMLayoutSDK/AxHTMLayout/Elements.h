// Elements.h : Declaration of the CElements

#ifndef __ELEMENTS_H_
#define __ELEMENTS_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CElements
class ATL_NO_VTABLE CElements : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<CElements, &CLSID_Elements>,
  public IDispatchImpl<IElements, &IID_IElements, &LIBID_HTMLayout>,
  public IEnumVARIANT,
  public dom::callback 
{

  // dom::callback
  virtual bool on_element(HELEMENT he)
  {
    elements.push_back(he);
    return false;
  }

public:
  std::vector<dom::element> elements;
  int                       next;
  CElements(): next(0)
  {

  }

DECLARE_REGISTRY_RESOURCEID(IDR_ELEMENTS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CElements)
  COM_INTERFACE_ENTRY(IElements)
  COM_INTERFACE_ENTRY(IDispatch)
  COM_INTERFACE_ENTRY(IEnumVARIANT)
END_COM_MAP()

// IElements
public:
  STDMETHOD(get_Item)(/*[in]*/ long index, /*[out, retval]*/ IElement* *pVal);
  STDMETHOD(get__NewEnum)(/*[out, retval]*/ IUnknown** ppEnum);
  STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
// IEnumVARIANT
  STDMETHOD(Next)(ULONG celt, VARIANT * rgvar, ULONG * pceltFetched)
  {
    //if (pceltFetched == NULL)
    //  return E_POINTER;

    int n = 0;
    for(; n < celt && next < elements.size(); ++next )
    {
      IElement* el = 0;
      if(SUCCEEDED(CElement::create(elements[next],&el)))
      {
        rgvar->vt = VT_DISPATCH;
        rgvar->pdispVal = el;
        ++n;
        ++rgvar; 
      }
    }
    if (pceltFetched) *pceltFetched = n;
    return n == celt? S_OK : S_FALSE;
  }
  STDMETHOD(Skip)(ULONG celt)
  {
    next += celt;
    return S_OK;
  }
  STDMETHOD(Reset)()
  {
    next = 0;
    return S_OK;
  }
  STDMETHOD(Clone)(IEnumVARIANT ** ppenum)
  {
    if (ppenum == NULL)
      return E_POINTER;
   
    CComObject<CElements>* pElements; 
    HRESULT hr = CComObject<CElements>::CreateInstance(&pElements);
    if (SUCCEEDED(hr) && pElements)
    {   
      pElements->AddRef();
      pElements->elements = elements;
      pElements->QueryInterface(IID_IEnumVARIANT, reinterpret_cast<void**>(ppenum));
      pElements->Release();
    }
    return S_OK;
  }

  static HRESULT create(dom::element self, const wchar_t* selector, IElements** iface)  
  {
    CComObject<CElements>* pElements; 
    HRESULT hr = CComObject<CElements>::CreateInstance(&pElements);
    if (SUCCEEDED(hr) && pElements)
    {   
      pElements->AddRef();
      self.select_elements(pElements, aux::w2a(selector));
      pElements->QueryInterface(IID_IEnumVARIANT, reinterpret_cast<void**>(iface));
      pElements->Release();
    }
    return hr;
  }


};

#endif //__ELEMENTS_H_
