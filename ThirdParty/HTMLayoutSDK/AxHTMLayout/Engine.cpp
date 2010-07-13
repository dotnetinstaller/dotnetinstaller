// Engine.cpp : Implementation of CEngine

#include "stdafx.h"
#include "AxHTMLayout.h"
#include "Engine.h"
#include "Element.h"

/////////////////////////////////////////////////////////////////////////////
// CEngine


STDMETHODIMP CEngine::Load(BSTR url)
{
  return HTMLayoutLoadFile(m_hWnd,url)? S_OK: S_FALSE;
}

STDMETHODIMP CEngine::LoadHtml(BSTR html, BSTR baseUrl)
{
  return HTMLayoutLoadHtmlEx(m_hWnd,LPCBYTE(html),SysStringByteLen(html),baseUrl)? S_OK: S_FALSE;
}

STDMETHODIMP CEngine::get_Root(IElement **pVal)
{
  HELEMENT he = 0;
  HTMLayoutGetRootElement(m_hWnd,&he);
  return CElement::create(he,pVal);
}
