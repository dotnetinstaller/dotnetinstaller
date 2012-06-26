/*-------------------------------------------------------*\
 *
 *	Copyright 1997 - 1999 Microsoft Corporation
 *
 *	Module Name:
 *
 *		wp15api.h
 *
 *	Abstract:
 *
 *		Declaration of the Microsoft Web Publishing API
 *
\*-------------------------------------------------------*/


#ifndef __WP15API_H__
#define __WP15API_H__


#include <windows.h>
#include "wptypes.h"

//
// Assume packing on DWORD boundary
//

#include <pshpack4.h>


//
//	Flags
//

#define WPF_NO_RECURSIVE_POST			0x00000001		//	WpPost
#define WPF_NO_WIZARD					0x00000002		//	WpPost
#define WPF_MINIMAL_UI					0x00000004		//	WpPost - OBSOLETE
#define WPF_FIRST_FILE_AS_DEFAULT		0x00000008		//	WpPost/PostFiles
#define WPF_NO_DIRECT_LOOKUP			0x00000010		//	WpBindToSite
#define WPF_NO_URL_LOOKUP				0x00000020		//	WpBindToSite
#define WPF_USE_PROVIDER_PASSED			0x00000040		//	WpCreateSite
#define WPF_NO_VERIFY_POST				0x00000080		//	WpPost
#define WPF_NO_PROGRESS_DLGS			0x00000200		//	WpPost
#define WPF_SHOWPAGE_WELCOME			0x00010000		//	WpPost/Wizard
#define WPF_SHOWPAGE_SRCFILE			0x00020000		//	WpPost/Wizard
#define WPF_SHOWPAGE_DESTSITE			0x00040000		//	WpPost/Wizard
#define WPF_SHOWPAGE_PROVIDER			0x00080000		//	WpPost/Wizard/AddWizardPages
#define WPF_ENABLE_LOCAL_BASE_DIR		0x00100000		//	WpPost/Wizard

#define WPF_NO_UI						WPF_NO_WIZARD | \
										WPF_NO_PROGRESS_DLGS
 
#define WPF_SHOWPAGE_ALL				WPF_SHOWPAGE_WELCOME | \
										WPF_SHOWPAGE_SRCFILE | \
										WPF_SHOWPAGE_DESTSITE | \
										WPF_SHOWPAGE_PROVIDER


//
//	Miscellaneous
//

#define MAX_SITENAME_LEN				128


//
//	Unicode APIs
//

#ifdef __cplusplus
extern "C" {
#endif

DWORD WINAPI WpPostW(	HWND hwnd, 
						DWORD dwNumLocalPaths,
						LPWSTR *pwsLocalPaths, 
						LPDWORD pdwSiteNameBufLen,
						LPWSTR wsSiteName,
						LPDWORD pdwDestURLBufLen,
						LPWSTR wsDestURL, 
						DWORD dwFlag);

DWORD WINAPI WpListSitesW(	LPDWORD pdwSitesBufLen,
							LPWPSITEINFOW pSitesBuffer,
							LPDWORD pdwNumSites);

DWORD WINAPI WpDoesSiteExistW(	LPCWSTR wsSiteName,
								BOOL *pfSiteExists);

DWORD WINAPI WpDeleteSiteW(	LPCWSTR wsSiteName);

DWORD WINAPI WpBindToSiteW(	HWND	hwnd,
							LPCWSTR	wsSiteName,
							LPCWSTR	wsSitePostingURL,
							DWORD	dwFlag,
							DWORD	dwReserved,
							PVOID 	*ppvUnk);

DWORD WINAPI WpCreateSiteW(	LPCWSTR wsSiteName,
							LPCWSTR wsSiteLocalBaseDir,
							LPCWSTR wsSitePostingURL,
							LPCWSTR wsProviderCLSID,
							DWORD dwFlags);

DWORD WINAPI WpEnumProvidersW(	LPDWORD pdwProvidersBufLen,
								LPWPPROVINFOW pProvidersBuffer,
								LPDWORD pdwNumProviders);

DWORD WINAPI WpGetErrorStringW(	UINT uErrCode,
								LPWSTR wsOutputBuf,
								LPDWORD pdwBufLen);

//
//	ANSI APIs
//

DWORD WINAPI WpPostA(	HWND hwnd,
						DWORD dwNumLocalPaths,
						LPSTR *psLocalPaths, 
						LPDWORD pdwSiteNameBufLen,
						LPSTR sSiteName,
						LPDWORD pdwDestURLBufLen,
						LPSTR sDestURLBufLen, 
						DWORD dwFlag);

DWORD WINAPI WpListSitesA(	LPDWORD pdwSitesBufLen,
							LPWPSITEINFOA pSitesBuffer,
							LPDWORD pdwNumSites);

DWORD WINAPI WpDoesSiteExistA(	LPCSTR sSiteName,
								BOOL *pfSiteExists);

DWORD WINAPI WpDeleteSiteA(	LPCSTR sSiteName);

DWORD WINAPI WpBindToSiteA(	HWND	hwnd,
							LPCSTR	sSiteName,
							LPCSTR	sSitePostingURL,
							DWORD	dwFlag,
							DWORD	dwReserved,
						    PVOID 	*ppvUnk);

DWORD WINAPI WpCreateSiteA(	LPCSTR sSiteName,
							LPCSTR sSiteLocalBaseDir,
							LPCSTR sSitePostingURL,
							LPCSTR sProviderCLSID,
							DWORD dwFlags);

DWORD WINAPI WpEnumProvidersA(	LPDWORD pdwProvidersBufLen,
								LPWPPROVINFOA pProvidersBuffer,
								LPDWORD pdwNumProviders);

DWORD WINAPI WpGetErrorStringA(	UINT uErrCode,
								LPSTR sOutputBuf,
								LPDWORD pdwBufLen);


#ifdef __cplusplus
}
#endif


#ifdef UNICODE

#define WpPost					WpPostW
#define WpListSites				WpListSitesW
#define WpDoesSiteExist			WpDoesSiteExistW
#define WpDeleteSite			WpDeleteSiteW
#define WpBindToSite			WpBindToSiteW
#define WpCreateSite			WpCreateSiteW
#define WpEnumProviders			WpEnumProvidersW
#define WpGetErrorString		WpGetErrorStringW

#else

#define WpPost					WpPostA
#define WpListSites				WpListSitesA
#define WpDoesSiteExist			WpDoesSiteExistA
#define WpDeleteSite			WpDeleteSiteA
#define WpBindToSite			WpBindToSiteA
#define WpCreateSite			WpCreateSiteA
#define WpEnumProviders			WpEnumProvidersA
#define WpGetErrorString		WpGetErrorStringA

#endif


#include <poppack.h>


#endif // __WP15API_H__
