// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__268F5AF1_8043_4B0F_AE2E_A60E6EB22EF7__INCLUDED_)
#define AFX_STDAFX_H__268F5AF1_8043_4B0F_AE2E_A60E6EB22EF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
#include <atlctl.h>

#include "htmlayout.h"
#include "htmlayout_notifications.hpp"
using namespace htmlayout;

inline bool LoadHtmlResource(UINT resId, LPCBYTE& pb, DWORD& cb )
{
  HRSRC hrsrc = ::FindResource(_Module.GetResourceInstance(), MAKEINTRESOURCE(resId), MAKEINTRESOURCE(23));
  if (!hrsrc) return FALSE; // resource not found here - proceed with default loader
  // Load specified resource and check if ok
  HGLOBAL hgres = ::LoadResource(_Module.GetResourceInstance(), hrsrc);
  if (!hgres) return FALSE;
  // Retrieve resource data and check if ok
  pb = (PBYTE)::LockResource(hgres); if (!pb) return FALSE;
  cb = ::SizeofResource(_Module.GetResourceInstance(), hrsrc); if (!cb) return FALSE;
  return TRUE;
}

extern json::value cvt_VARIANT_to_json_value(const VARIANT& tv);
extern VARIANT cvt_json_value_to_VARIANT(const json::value& tv);


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__268F5AF1_8043_4B0F_AE2E_A60E6EB22EF7__INCLUDED)
