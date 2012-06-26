

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for inputscope.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __inputscope_h__
#define __inputscope_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITfInputScope_FWD_DEFINED__
#define __ITfInputScope_FWD_DEFINED__
typedef interface ITfInputScope ITfInputScope;
#endif 	/* __ITfInputScope_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_inputscope_0000 */
/* [local] */ 

//=--------------------------------------------------------------------------=
// InputScope.h


// InputScope declarations.

//=--------------------------------------------------------------------------=
// (C) Copyright 1995-2003 Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR TFPLIED, INCLUDING BUT NOT LIMITED TO
// THE TFPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#ifndef INPUTSCOPE_DEFINED
#define INPUTSCOPE_DEFINED

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_inputscope_0000_0001
    {	IS_DEFAULT	= 0,
	IS_URL	= 1,
	IS_FILE_FULLFILEPATH	= 2,
	IS_FILE_FILENAME	= 3,
	IS_EMAIL_USERNAME	= 4,
	IS_EMAIL_SMTPEMAILADDRESS	= 5,
	IS_LOGINNAME	= 6,
	IS_PERSONALNAME_FULLNAME	= 7,
	IS_PERSONALNAME_PREFIX	= 8,
	IS_PERSONALNAME_GIVENNAME	= 9,
	IS_PERSONALNAME_MIDDLENAME	= 10,
	IS_PERSONALNAME_SURNAME	= 11,
	IS_PERSONALNAME_SUFFIX	= 12,
	IS_ADDRESS_FULLPOSTALADDRESS	= 13,
	IS_ADDRESS_POSTALCODE	= 14,
	IS_ADDRESS_STREET	= 15,
	IS_ADDRESS_STATEORPROVINCE	= 16,
	IS_ADDRESS_CITY	= 17,
	IS_ADDRESS_COUNTRYNAME	= 18,
	IS_ADDRESS_COUNTRYSHORTNAME	= 19,
	IS_CURRENCY_AMOUNTANDSYMBOL	= 20,
	IS_CURRENCY_AMOUNT	= 21,
	IS_DATE_FULLDATE	= 22,
	IS_DATE_MONTH	= 23,
	IS_DATE_DAY	= 24,
	IS_DATE_YEAR	= 25,
	IS_DATE_MONTHNAME	= 26,
	IS_DATE_DAYNAME	= 27,
	IS_DIGITS	= 28,
	IS_NUMBER	= 29,
	IS_ONECHAR	= 30,
	IS_PASSWORD	= 31,
	IS_TELEPHONE_FULLTELEPHONENUMBER	= 32,
	IS_TELEPHONE_COUNTRYCODE	= 33,
	IS_TELEPHONE_AREACODE	= 34,
	IS_TELEPHONE_LOCALNUMBER	= 35,
	IS_TIME_FULLTIME	= 36,
	IS_TIME_HOUR	= 37,
	IS_TIME_MINORSEC	= 38,
	IS_NUMBER_FULLWIDTH	= 39,
	IS_ALPHANUMERIC_HALFWIDTH	= 40,
	IS_ALPHANUMERIC_FULLWIDTH	= 41,
	IS_CURRENCY_CHINESE	= 42,
	IS_BOPOMOFO	= 43,
	IS_HIRAGANA	= 44,
	IS_KATAKANA_HALFWIDTH	= 45,
	IS_KATAKANA_FULLWIDTH	= 46,
	IS_HANJA	= 47,
	IS_PHRASELIST	= -1,
	IS_REGULAREXPRESSION	= -2,
	IS_SRGS	= -3,
	IS_XML	= -4
    } 	InputScope;

HRESULT WINAPI SetInputScope(HWND hwnd, InputScope inputscope);
HRESULT WINAPI SetInputScopes(HWND hwnd, const InputScope *pInputScopes, UINT cInputScopes, WCHAR **ppszPhraseList, UINT cPhrases, WCHAR *pszRegExp, WCHAR *pszSRGS);
HRESULT WINAPI SetInputScopeXML(HWND hwnd, WCHAR *pszXML);
DEFINE_GUID(IID_ITfInputScope, 0xfde1eaee, 0x6924, 0x4cdf, 0x91, 0xe7, 0xda, 0x38, 0xcf, 0xf5, 0x55, 0x9d);
DEFINE_GUID(GUID_PROP_INPUTSCOPE, 0x1713dd5a, 0x68e7, 0x4a5b, 0x9a, 0xf6, 0x59, 0x2a, 0x59, 0x5c, 0x77, 0x8d);
#ifdef __cplusplus
}
#endif  /* __cplusplus */


extern RPC_IF_HANDLE __MIDL_itf_inputscope_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_inputscope_0000_v0_0_s_ifspec;

#ifndef __ITfInputScope_INTERFACE_DEFINED__
#define __ITfInputScope_INTERFACE_DEFINED__

/* interface ITfInputScope */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfInputScope;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fde1eaee-6924-4cdf-91e7-da38cff5559d")
    ITfInputScope : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInputScopes( 
            /* [out] */ InputScope **pprgInputScopes,
            /* [out] */ UINT *pcCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPhrase( 
            /* [out] */ BSTR **ppbstrPhrases,
            /* [out] */ UINT *pcCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegularExpression( 
            /* [out] */ BSTR *pbstrRegExp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSRGS( 
            /* [out] */ BSTR *pbstrSRGS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetXML( 
            /* [out] */ BSTR *pbstrXML) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITfInputScopeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITfInputScope * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITfInputScope * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITfInputScope * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputScopes )( 
            ITfInputScope * This,
            /* [out] */ InputScope **pprgInputScopes,
            /* [out] */ UINT *pcCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ITfInputScope * This,
            /* [out] */ BSTR **ppbstrPhrases,
            /* [out] */ UINT *pcCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegularExpression )( 
            ITfInputScope * This,
            /* [out] */ BSTR *pbstrRegExp);
        
        HRESULT ( STDMETHODCALLTYPE *GetSRGS )( 
            ITfInputScope * This,
            /* [out] */ BSTR *pbstrSRGS);
        
        HRESULT ( STDMETHODCALLTYPE *GetXML )( 
            ITfInputScope * This,
            /* [out] */ BSTR *pbstrXML);
        
        END_INTERFACE
    } ITfInputScopeVtbl;

    interface ITfInputScope
    {
        CONST_VTBL struct ITfInputScopeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfInputScope_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITfInputScope_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITfInputScope_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITfInputScope_GetInputScopes(This,pprgInputScopes,pcCount)	\
    (This)->lpVtbl -> GetInputScopes(This,pprgInputScopes,pcCount)

#define ITfInputScope_GetPhrase(This,ppbstrPhrases,pcCount)	\
    (This)->lpVtbl -> GetPhrase(This,ppbstrPhrases,pcCount)

#define ITfInputScope_GetRegularExpression(This,pbstrRegExp)	\
    (This)->lpVtbl -> GetRegularExpression(This,pbstrRegExp)

#define ITfInputScope_GetSRGS(This,pbstrSRGS)	\
    (This)->lpVtbl -> GetSRGS(This,pbstrSRGS)

#define ITfInputScope_GetXML(This,pbstrXML)	\
    (This)->lpVtbl -> GetXML(This,pbstrXML)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITfInputScope_GetInputScopes_Proxy( 
    ITfInputScope * This,
    /* [out] */ InputScope **pprgInputScopes,
    /* [out] */ UINT *pcCount);


void __RPC_STUB ITfInputScope_GetInputScopes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITfInputScope_GetPhrase_Proxy( 
    ITfInputScope * This,
    /* [out] */ BSTR **ppbstrPhrases,
    /* [out] */ UINT *pcCount);


void __RPC_STUB ITfInputScope_GetPhrase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITfInputScope_GetRegularExpression_Proxy( 
    ITfInputScope * This,
    /* [out] */ BSTR *pbstrRegExp);


void __RPC_STUB ITfInputScope_GetRegularExpression_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITfInputScope_GetSRGS_Proxy( 
    ITfInputScope * This,
    /* [out] */ BSTR *pbstrSRGS);


void __RPC_STUB ITfInputScope_GetSRGS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITfInputScope_GetXML_Proxy( 
    ITfInputScope * This,
    /* [out] */ BSTR *pbstrXML);


void __RPC_STUB ITfInputScope_GetXML_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITfInputScope_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_inputscope_0262 */
/* [local] */ 

#endif // INPUTSCOPE_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_inputscope_0262_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_inputscope_0262_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


