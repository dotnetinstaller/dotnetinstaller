// Element.cpp : Implementation of CElement
#include "stdafx.h"
#include "AxHTMLayout.h"
#include "Element.h"
#include "Elements.h"

#include "htmlayout_behavior.h"

/////////////////////////////////////////////////////////////////////////////
// CElement

STDMETHODIMP CElement::get_Tag(BSTR *pVal)
{
  const char* tag = self.get_element_type();
  if( tag )
  {
    *pVal = SysAllocString(aux::a2w(tag));
    return S_OK;
  }
  return S_FALSE;
}

STDMETHODIMP CElement::get_Value(VARIANT *pVal)
{
  json::value jsv = self.get_value();
  *pVal = cvt_json_value_to_VARIANT(jsv);
  return S_OK;
}

STDMETHODIMP CElement::put_Value(VARIANT newVal)
{
  json::value jsv = cvt_VARIANT_to_json_value(newVal);
  self.set_value(jsv);
  return S_OK;
}

STDMETHODIMP CElement::Select(BSTR cssSelector, IElement **elm)
{
  dom::element::find_first_callback find_first;
  self.select_elements( &find_first, aux::w2a(cssSelector)); 
  if( find_first.hfound )
    return CElement::create(find_first.hfound,elm);
  return S_FALSE;
}

STDMETHODIMP CElement::SelectAll(BSTR cssSelector, IElements **ppEls)
{
  return CElements::create(self, cssSelector, ppEls);
}

/*STDMETHODIMP CElement::get_attribute(BSTR name, BSTR *pVal)
{
  const wchar_t* att = self.get_attribute(aux::w2a(name));
  if( att )
    *pVal = SysAllocString(att);
	else
    *pVal = SysAllocString(att);

	return S_OK;
}

STDMETHODIMP CElement::put_attribute(BSTR name, BSTR newVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}*/

STDMETHODIMP CElement::get_attribute(BSTR name, VARIANT *pVal)
{
  const wchar_t* att = self.get_attribute(aux::w2a(name));
  if( att )
  {
    pVal->vt = VT_BSTR;
    pVal->bstrVal = SysAllocString(att);
  }
	else
  {
    VariantClear(pVal);
  }
	return S_OK;
}

STDMETHODIMP CElement::put_attribute(BSTR name, VARIANT newVal)
{
	if(newVal.vt == VT_BSTR)
    self.set_attribute(aux::w2a(name),newVal.bstrVal);
  else
    self.set_attribute(aux::w2a(name),0);
	return S_OK;
}

STDMETHODIMP CElement::get_styleAttribute(BSTR name, VARIANT *pVal)
{
  const wchar_t* att = self.get_style_attribute(aux::w2a(name));
  if( att )
  {
    pVal->vt = VT_BSTR;
    pVal->bstrVal = SysAllocString(att);
  }
	else
  {
    VariantClear(pVal);
  }
	return S_OK;
}

STDMETHODIMP CElement::put_styleAttribute(BSTR name, VARIANT newVal)
{
	if(newVal.vt == VT_BSTR)
    self.set_style_attribute(aux::w2a(name),newVal.bstrVal);
  else
    self.clear_style_attribute(aux::w2a(name));
	return S_OK;
}

STDMETHODIMP CElement::ShowPopup(long x, long y)
{
  POINT pt; pt.x = x; pt.y = y;
	self.show_popup(pt,true);
	return S_OK;
}

STDMETHODIMP CElement::HidePopup()
{
	self.hide_popup();
	return S_OK;
}

STDMETHODIMP CElement::StartTimer(long milliseconds, long timerId)
{
	self.start_timer(milliseconds,timerId);
	return S_OK;
}

STDMETHODIMP CElement::StopTimer(long timerId)
{
  self.stop_timer(timerId);
	return S_OK;
}

STDMETHODIMP CElement::PostControlEvent(long eventType, long reason)
{
	self.post_event(eventType,reason);
	return S_OK;
}

STDMETHODIMP CElement::SendControlEvent(long eventType, long reason, VARIANT_BOOL *handled)
{
	*handled = self.send_event(eventType,reason);
	return S_OK;
}

STDMETHODIMP CElement::Position(long *x, long *y, ElementBoxType ofWhat, RelativeToType relTo)
{
	RECT r = self.get_location( unsigned(ofWhat) | unsigned(relTo));
  *x = r.left;
  *y = r.top;
	return S_OK;
}

STDMETHODIMP CElement::Dimension(long *w, long *h, ElementBoxType ofWhat)
{
	RECT r = self.get_location( unsigned(ofWhat) | SELF_RELATIVE);
  *w = r.right - r.left;
  *h = r.bottom - r.top;
	return S_OK;
}

STDMETHODIMP CElement::Call(BSTR name, SAFEARRAY * params, /*[out,retval]*/ VARIANT *rv)
{
  HRESULT hr; 
  long lbound = 0, ubound = -1;
  bool r = false;

	hr = SafeArrayGetLBound(params, 0, &lbound); 
  hr = SafeArrayGetUBound(params, 0, &ubound); 
  
  aux::w2a aname(name);
  XCALL_PARAMS prm(aname);

  if( lbound <= ubound )
  {
    json::value *argv = new json::value[ubound - lbound + 1];
    int argc = 0;
    for(long n = lbound; n <= ubound; ++n)
    {
      CComVariant var;
      hr = SafeArrayGetElement(params,&n, &var); 
      if(FAILED(hr))
        break;
      argv[argc++] = cvt_VARIANT_to_json_value(var);
    }
    prm.argv = argv;
    prm.argc = argc;
    r = self.call_behavior_method(&prm);
    *rv = cvt_json_value_to_VARIANT(prm.retval);
    delete [] argv;
  }  
  else
  {
    prm.argv = 0;
    prm.argc = 0;
    r = self.call_behavior_method(&prm);
    *rv = cvt_json_value_to_VARIANT(prm.retval);
  }
  return r? S_OK : S_FALSE;
}
