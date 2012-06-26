/*------------------------------------------------*\
 *
 *	Copyright 1997 - 1999 Microsoft Corporation
 *
 *	Module Name:
 *
 *		wpspihlp.h
 *
 *	Abstract:
 *
 *		Declaration of Microsoft Web Publishing
 *		Service Provider helper functions.
 *
 *	Note:
 *
 *		If you are #including this file in
 *		a Web Publishing Service Provider
 *		implementation, you should first
 *		#define IN_WPPDLL.
 *
\*------------------------------------------------*/


#ifndef __WPSPIHLP_H__
#define __WPSPIHLP_H__


#include <windows.h>
#include "wptypes.h"


#if defined(IN_WPPDLL)
#define WPPFUNC	__declspec( dllexport )
#else
#define WPPFUNC	__declspec( dllimport )
#endif	//	IN_WPPDLL


//
//	Flags
//

#define WPF_FORCE_BIND					0x00000100		//	WppBindToSite


//
//	Helper function declarations and typedefs
//

HRESULT WPPFUNC WINAPI WppBindToSiteA(
	HWND	hwnd,
	LPCSTR	sSiteName,
	LPCSTR	sURL,
    REFIID	riid,
	DWORD	dwFlag,
	DWORD	dwReserved,
    PVOID 	*ppvUnk);

typedef HRESULT (WINAPI *PFN_WPPBINDTOSITEA)(
						HWND	hwnd,
						LPCSTR	sSiteName,
						LPCSTR	sURL,
						REFIID 	riid,
						DWORD	dwFlag,
						DWORD	dwReserved,
						PVOID 	*ppvUnk);


HRESULT WPPFUNC WINAPI WppListSitesA(
	LPDWORD			pdwSitesBufLen,
	LPWPSITEINFOA	pSitesBuffer,
	LPDWORD			pdwNumSites);

typedef HRESULT (WINAPI *PFN_WPPLISTSITESA)(
						LPDWORD			pdwSitesBufLen,
						LPWPSITEINFOA	pSitesBuffer,
						LPDWORD			pdwNumSites);

										
HRESULT WPPFUNC WINAPI WppDeleteSiteA(LPCSTR sSiteName);

typedef HRESULT (WINAPI *PFN_WPPDELETESITEA)(LPCSTR sSiteName);


HRESULT WPPFUNC WINAPI WppBindToSiteW(
	HWND	hwnd,
	LPCWSTR	sSiteName,
	LPCWSTR	sURL,
    REFIID	riid,
	DWORD	dwFlag,
	DWORD	dwReserved,
    PVOID 	*ppvUnk);

typedef HRESULT (WINAPI *PFN_WPPBINDTOSITEW)(
						HWND	hwnd,
						LPCWSTR sSiteName,
						LPCWSTR	sURL,
						REFIID 	riid,
						DWORD	dwFlag,
						DWORD	dwReserved,
						PVOID 	*ppvUnk);

HRESULT WPPFUNC WINAPI WppListSitesW(
	LPDWORD			pdwSitesBufLen,
	LPWPSITEINFOW	pSitesBuffer,
	LPDWORD			pdwNumSites);

typedef HRESULT (WINAPI *PFN_WPPLISTSITESW)(
						LPDWORD			pdwSitesBufLen,
						LPWPSITEINFOW	pSitesBuffer,
						LPDWORD			pdwNumSites);
										
HRESULT WPPFUNC WINAPI WppDeleteSiteW(LPCWSTR sSiteName);

typedef HRESULT (WINAPI *PFN_WPPDELETESITEW)(LPCWSTR sSiteName);


//
//	Entry Points
//

#define	EP_WPPBINDTOSITEW	"WppBindToSiteW"
#define EP_WPPLISTSITESW	"WppListSitesW"
#define EP_WPPDELETESITEW	"WppDeleteSiteW"

#define EP_WPPBINDTOSITEA	"WppBindToSiteA"
#define EP_WPPLISTSITESA	"WppListSitesA"
#define EP_WPPDELETESITEA	"WppDeleteSiteA"



#endif	// __WPSPIHLP_H__

