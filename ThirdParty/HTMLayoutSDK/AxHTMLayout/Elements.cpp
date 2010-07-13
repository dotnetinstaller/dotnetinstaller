// Elements.cpp : Implementation of CElements
#include "stdafx.h"
#include "AxHTMLayout.h"
#include "Element.h"
#include "Elements.h"

/////////////////////////////////////////////////////////////////////////////
// CElements


STDMETHODIMP CElements::get_Count(long *pVal)
{
  *pVal = elements.size();
  return S_OK;
}

STDMETHODIMP CElements::get__NewEnum(IUnknown **ppEnum)
{
  if (ppEnum == NULL)
    return E_POINTER;
  return QueryInterface(IID_IEnumVARIANT,(void**)ppEnum);
}

STDMETHODIMP CElements::get_Item(long index, IElement **pVal)
{
  if (pVal == NULL)
    return E_POINTER;
  if( index < 1 || index > elements.size() )
    return DISP_E_BADINDEX;
  return CElement::create(elements[index-1],pVal);
}
