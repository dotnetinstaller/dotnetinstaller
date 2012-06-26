
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0279 */
/* at Thu Dec 14 06:28:44 2000
 */
/* Compiler settings for P:\INSTMSG\src\msimcli\msimcntl\msimcntl.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __msimcntl_h__
#define __msimcntl_h__

/* Forward Declarations */ 

#ifndef ___IUseIMBase_FWD_DEFINED__
#define ___IUseIMBase_FWD_DEFINED__
typedef interface _IUseIMBase _IUseIMBase;
#endif 	/* ___IUseIMBase_FWD_DEFINED__ */


#ifndef __IMSIMContactView_FWD_DEFINED__
#define __IMSIMContactView_FWD_DEFINED__
typedef interface IMSIMContactView IMSIMContactView;
#endif 	/* __IMSIMContactView_FWD_DEFINED__ */


#ifndef __DMSIMContactViewEvents_FWD_DEFINED__
#define __DMSIMContactViewEvents_FWD_DEFINED__
typedef interface DMSIMContactViewEvents DMSIMContactViewEvents;
#endif 	/* __DMSIMContactViewEvents_FWD_DEFINED__ */


#ifndef __IMSIMMessageView_FWD_DEFINED__
#define __IMSIMMessageView_FWD_DEFINED__
typedef interface IMSIMMessageView IMSIMMessageView;
#endif 	/* __IMSIMMessageView_FWD_DEFINED__ */


#ifndef __DMSIMMessageViewEvents_FWD_DEFINED__
#define __DMSIMMessageViewEvents_FWD_DEFINED__
typedef interface DMSIMMessageViewEvents DMSIMMessageViewEvents;
#endif 	/* __DMSIMMessageViewEvents_FWD_DEFINED__ */


#ifndef __MSIMContactView_FWD_DEFINED__
#define __MSIMContactView_FWD_DEFINED__

#ifdef __cplusplus
typedef class MSIMContactView MSIMContactView;
#else
typedef struct MSIMContactView MSIMContactView;
#endif /* __cplusplus */

#endif 	/* __MSIMContactView_FWD_DEFINED__ */


#ifndef __MSIMMessageView_FWD_DEFINED__
#define __MSIMMessageView_FWD_DEFINED__

#ifdef __cplusplus
typedef class MSIMMessageView MSIMMessageView;
#else
typedef struct MSIMMessageView MSIMMessageView;
#endif /* __cplusplus */

#endif 	/* __MSIMMessageView_FWD_DEFINED__ */


#ifndef __IIMSafeContact_FWD_DEFINED__
#define __IIMSafeContact_FWD_DEFINED__
typedef interface IIMSafeContact IIMSafeContact;
#endif 	/* __IIMSafeContact_FWD_DEFINED__ */


#ifndef __IMSIMContactList_FWD_DEFINED__
#define __IMSIMContactList_FWD_DEFINED__
typedef interface IMSIMContactList IMSIMContactList;
#endif 	/* __IMSIMContactList_FWD_DEFINED__ */


#ifndef __DIMContactListEvents_FWD_DEFINED__
#define __DIMContactListEvents_FWD_DEFINED__
typedef interface DIMContactListEvents DIMContactListEvents;
#endif 	/* __DIMContactListEvents_FWD_DEFINED__ */


#ifndef __MSIMContactList_FWD_DEFINED__
#define __MSIMContactList_FWD_DEFINED__

#ifdef __cplusplus
typedef class MSIMContactList MSIMContactList;
#else
typedef struct MSIMContactList MSIMContactList;
#endif /* __cplusplus */

#endif 	/* __MSIMContactList_FWD_DEFINED__ */


#ifndef __IMSafeContact_FWD_DEFINED__
#define __IMSafeContact_FWD_DEFINED__

#ifdef __cplusplus
typedef class IMSafeContact IMSafeContact;
#else
typedef struct IMSafeContact IMSafeContact;
#endif /* __cplusplus */

#endif 	/* __IMSafeContact_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "SIMPDATA.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_msimcntl_0000 */
/* [local] */ 

#define DMSIMCONTACTVIEWEVENTS_OnReady              0xD0
#define DMSIMCONTACTVIEWEVENTS_OnLogon              0xD1
#define DMSIMCONTACTVIEWEVENTS_OnLogoff             0xD2
#define DMSIMCONTACTVIEWEVENTS_OnLaunchMessageUI    0xD3
#define DMSIMCONTACTVIEWEVENTS_OnMenuRequest        0xD6
#define DMSIMCONTACTVIEWEVENTS_OnMenuSelect         0xD7
#define DMSIMCONTACTVIEWEVENTS_OnAddResult          0xD8
#define DMSIMCONTACTVIEWEVENTS_OnRemoveResult       0xD9
#define DMSIMCONTACTVIEWEVENTS_OnSelect             0xDA
#define DMSIMCONTACTVIEWEVENTS_OnShutdown           0xDB
#define DMSIMCONTACTVIEWEVENTS_OnEMailContact       0xDC
#define DMSIMCONTACTVIEWEVENTS_OnAddContactUI       0xDD
#define DMSIMCONTACTVIEWEVENTS_OnLocalStateChange   0xDE
#define DMSIMCONTACTVIEWEVENTS_OnExtentsChange      0xDF
#define DMSIMMESSAGEVIEWEVENTS_OnReady              0xD0
#define DMSIMMESSAGEVIEWEVENTS_OnLogon              0xD1
#define DMSIMMESSAGEVIEWEVENTS_OnLogoff             0xD2
#define DMSIMMESSAGEVIEWEVENTS_OnLaunchMessageUI    0xD3
#define DMSIMMESSAGEVIEWEVENTS_OnNewMessage         0xD6
#define DMSIMMESSAGEVIEWEVENTS_OnAddResult          0xD7
#define DMSIMMESSAGEVIEWEVENTS_OnRemoveResult       0xD8
#define DMSIMMESSAGEVIEWEVENTS_OnNewSession         0xD9
#define DMSIMMESSAGEVIEWEVENTS_OnSessionEnd         0xDA
#define DMSIMMESSAGEVIEWEVENTS_OnShutdown           0xDB
#define DMSIMMESSAGEVIEWEVENTS_OnLocalStateChange   0xDC
#define DMSIMCONTACTLISTEVENTS_OnReady              0xD0
#define DMSIMCONTACTLISTEVENTS_OnLogon              0xD1
#define DMSIMCONTACTLISTEVENTS_OnLogoff             0xD2
#define DMSIMCONTACTLISTEVENTS_OnAddResult          0xD3
#define DMSIMCONTACTLISTEVENTS_OnRemoveResult       0xD4
#define DMSIMCONTACTLISTEVENTS_OnShutdown           0xD5
#define DMSIMCONTACTLISTEVENTS_OnChangeContact      0xD6
#define DMSIMCONTACTLISTEVENTS_OnLocalStateChange   0xD7


extern RPC_IF_HANDLE __MIDL_itf_msimcntl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_msimcntl_0000_v0_0_s_ifspec;


#ifndef __MSIMCNTLLib_LIBRARY_DEFINED__
#define __MSIMCNTLLib_LIBRARY_DEFINED__

/* library MSIMCNTLLib */
/* [helpstring][version][uuid] */ 

typedef /* [public] */ 
enum __MIDL___MIDL_itf_msimcntl_0000_0001
    {	MSIM_PROVIDER_FIRST	= 0,
	MSIM_PROVIDER_ANY	= 0,
	MSIM_PROVIDER_EXCHANGE_HOST	= 1,
	MSIM_PROVIDER_LAST	= 1,
	MSIM_PROVIDER_NONE	= 0xffff
    }	MSIM_PROVIDER;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_msimcntl_0000_0002
    {	MSIM_MSG_UI_SESSION	= 0,
	MSIM_MSG_UI_NETMEETING	= 1
    }	MSIM_MSG_UI;


EXTERN_C const IID LIBID_MSIMCNTLLib;

#ifndef ___IUseIMBase_INTERFACE_DEFINED__
#define ___IUseIMBase_INTERFACE_DEFINED__

/* interface _IUseIMBase */
/* [object][hidden][helpstring][uuid][dual] */ 


EXTERN_C const IID IID__IUseIMBase;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9D921DA0-DFE1-45AE-9EB6-E50A2770A57E")
    _IUseIMBase : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetService( 
            /* [in] */ IDispatch __RPC_FAR *pService,
            /* [defaultvalue][in] */ IDispatch __RPC_FAR *pApp = 0) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Service( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Service( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasService( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoLogon( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoLogon( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LoggedOn( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Logon( 
            /* [defaultvalue][full][in] */ BSTR bstrAddress = L"",
            /* [defaultvalue][full][in] */ BSTR bstrName = L"",
            /* [defaultvalue][full][in] */ BSTR bstrPassword = L"",
            /* [defaultvalue][full][in] */ BSTR bstrDomain = L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Logoff( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLocalState( 
            /* [out] */ VARIANT __RPC_FAR *pvarState,
            /* [optional][out] */ VARIANT __RPC_FAR *pvarDescription,
            /* [optional][out] */ VARIANT __RPC_FAR *pvarData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLocalState( 
            /* [in] */ long lState,
            /* [optional][in] */ VARIANT varDescription,
            /* [optional][in] */ VARIANT varData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _IUseIMBaseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IUseIMBase __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IUseIMBase __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IUseIMBase __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IUseIMBase __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IUseIMBase __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IUseIMBase __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IUseIMBase __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetService )( 
            _IUseIMBase __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pService,
            /* [defaultvalue][in] */ IDispatch __RPC_FAR *pApp);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Service )( 
            _IUseIMBase __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Service )( 
            _IUseIMBase __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HasService )( 
            _IUseIMBase __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AutoLogon )( 
            _IUseIMBase __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AutoLogon )( 
            _IUseIMBase __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LoggedOn )( 
            _IUseIMBase __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Logon )( 
            _IUseIMBase __RPC_FAR * This,
            /* [defaultvalue][full][in] */ BSTR bstrAddress,
            /* [defaultvalue][full][in] */ BSTR bstrName,
            /* [defaultvalue][full][in] */ BSTR bstrPassword,
            /* [defaultvalue][full][in] */ BSTR bstrDomain);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Logoff )( 
            _IUseIMBase __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLocalState )( 
            _IUseIMBase __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *pvarState,
            /* [optional][out] */ VARIANT __RPC_FAR *pvarDescription,
            /* [optional][out] */ VARIANT __RPC_FAR *pvarData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLocalState )( 
            _IUseIMBase __RPC_FAR * This,
            /* [in] */ long lState,
            /* [optional][in] */ VARIANT varDescription,
            /* [optional][in] */ VARIANT varData);
        
        END_INTERFACE
    } _IUseIMBaseVtbl;

    interface _IUseIMBase
    {
        CONST_VTBL struct _IUseIMBaseVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IUseIMBase_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IUseIMBase_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IUseIMBase_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IUseIMBase_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IUseIMBase_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IUseIMBase_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IUseIMBase_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _IUseIMBase_SetService(This,pService,pApp)	\
    (This)->lpVtbl -> SetService(This,pService,pApp)

#define _IUseIMBase_get_Service(This,pVal)	\
    (This)->lpVtbl -> get_Service(This,pVal)

#define _IUseIMBase_put_Service(This,newVal)	\
    (This)->lpVtbl -> put_Service(This,newVal)

#define _IUseIMBase_get_HasService(This,pVal)	\
    (This)->lpVtbl -> get_HasService(This,pVal)

#define _IUseIMBase_get_AutoLogon(This,pVal)	\
    (This)->lpVtbl -> get_AutoLogon(This,pVal)

#define _IUseIMBase_put_AutoLogon(This,newVal)	\
    (This)->lpVtbl -> put_AutoLogon(This,newVal)

#define _IUseIMBase_get_LoggedOn(This,pVal)	\
    (This)->lpVtbl -> get_LoggedOn(This,pVal)

#define _IUseIMBase_Logon(This,bstrAddress,bstrName,bstrPassword,bstrDomain)	\
    (This)->lpVtbl -> Logon(This,bstrAddress,bstrName,bstrPassword,bstrDomain)

#define _IUseIMBase_Logoff(This)	\
    (This)->lpVtbl -> Logoff(This)

#define _IUseIMBase_GetLocalState(This,pvarState,pvarDescription,pvarData)	\
    (This)->lpVtbl -> GetLocalState(This,pvarState,pvarDescription,pvarData)

#define _IUseIMBase_SetLocalState(This,lState,varDescription,varData)	\
    (This)->lpVtbl -> SetLocalState(This,lState,varDescription,varData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _IUseIMBase_SetService_Proxy( 
    _IUseIMBase __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pService,
    /* [defaultvalue][in] */ IDispatch __RPC_FAR *pApp);


void __RPC_STUB _IUseIMBase_SetService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE _IUseIMBase_get_Service_Proxy( 
    _IUseIMBase __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB _IUseIMBase_get_Service_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE _IUseIMBase_put_Service_Proxy( 
    _IUseIMBase __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB _IUseIMBase_put_Service_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE _IUseIMBase_get_HasService_Proxy( 
    _IUseIMBase __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB _IUseIMBase_get_HasService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE _IUseIMBase_get_AutoLogon_Proxy( 
    _IUseIMBase __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB _IUseIMBase_get_AutoLogon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE _IUseIMBase_put_AutoLogon_Proxy( 
    _IUseIMBase __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB _IUseIMBase_put_AutoLogon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE _IUseIMBase_get_LoggedOn_Proxy( 
    _IUseIMBase __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB _IUseIMBase_get_LoggedOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _IUseIMBase_Logon_Proxy( 
    _IUseIMBase __RPC_FAR * This,
    /* [defaultvalue][full][in] */ BSTR bstrAddress,
    /* [defaultvalue][full][in] */ BSTR bstrName,
    /* [defaultvalue][full][in] */ BSTR bstrPassword,
    /* [defaultvalue][full][in] */ BSTR bstrDomain);


void __RPC_STUB _IUseIMBase_Logon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _IUseIMBase_Logoff_Proxy( 
    _IUseIMBase __RPC_FAR * This);


void __RPC_STUB _IUseIMBase_Logoff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _IUseIMBase_GetLocalState_Proxy( 
    _IUseIMBase __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *pvarState,
    /* [optional][out] */ VARIANT __RPC_FAR *pvarDescription,
    /* [optional][out] */ VARIANT __RPC_FAR *pvarData);


void __RPC_STUB _IUseIMBase_GetLocalState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _IUseIMBase_SetLocalState_Proxy( 
    _IUseIMBase __RPC_FAR * This,
    /* [in] */ long lState,
    /* [optional][in] */ VARIANT varDescription,
    /* [optional][in] */ VARIANT varData);


void __RPC_STUB _IUseIMBase_SetLocalState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___IUseIMBase_INTERFACE_DEFINED__ */


#ifndef __IMSIMContactView_INTERFACE_DEFINED__
#define __IMSIMContactView_INTERFACE_DEFINED__

/* interface IMSIMContactView */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMSIMContactView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("415ADE21-A15F-4C06-8F5D-DD5E0A9EA230")
    IMSIMContactView : public _IUseIMBase
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ VARIANT vUser) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT vUser) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_List( 
            /* [retval][out] */ VARIANT __RPC_FAR *pvarList) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_List( 
            /* [in] */ VARIANT varList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddMenuItem( 
            /* [in] */ BSTR bstrItem,
            /* [defaultvalue][in] */ long lPosition,
            /* [retval][out] */ long __RPC_FAR *plCommand) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SelectedMenuOptions( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSelected( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EMailSelected( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InviteSelected( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BlockSelected( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnblockSelected( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExtentWidth( 
            /* [retval][out] */ long __RPC_FAR *pX) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExtentHeight( 
            /* [retval][out] */ long __RPC_FAR *pY) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HotTracking( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HotTracking( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowCollapse( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowCollapse( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowSelectAlways( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowSelectAlways( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnlineRootLabel( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrLabel) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnlineRootLabel( 
            /* [in] */ BSTR bstrLabel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OfflineRootLabel( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrLabel) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OfflineRootLabel( 
            /* [in] */ BSTR bstrLabel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Window( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowLogonButton( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowLogonButton( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnlineCollapsed( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnlineCollapsed( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OfflineCollapsed( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OfflineCollapsed( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Group( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Group( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FilterOffline( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FilterOffline( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowIcons( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowIcons( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AcceptMessages( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AcceptMessages( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSIMContactViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMSIMContactView __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMSIMContactView __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IMSIMContactView __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetService )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pService,
            /* [defaultvalue][in] */ IDispatch __RPC_FAR *pApp);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Service )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Service )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HasService )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AutoLogon )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AutoLogon )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LoggedOn )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Logon )( 
            IMSIMContactView __RPC_FAR * This,
            /* [defaultvalue][full][in] */ BSTR bstrAddress,
            /* [defaultvalue][full][in] */ BSTR bstrName,
            /* [defaultvalue][full][in] */ BSTR bstrPassword,
            /* [defaultvalue][full][in] */ BSTR bstrDomain);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Logoff )( 
            IMSIMContactView __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLocalState )( 
            IMSIMContactView __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *pvarState,
            /* [optional][out] */ VARIANT __RPC_FAR *pvarDescription,
            /* [optional][out] */ VARIANT __RPC_FAR *pvarData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLocalState )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ long lState,
            /* [optional][in] */ VARIANT varDescription,
            /* [optional][in] */ VARIANT varData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT vUser);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT vUser);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_List )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarList);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_List )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT varList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddMenuItem )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ BSTR bstrItem,
            /* [defaultvalue][in] */ long lPosition,
            /* [retval][out] */ long __RPC_FAR *plCommand);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SelectedMenuOptions )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IMSelected )( 
            IMSIMContactView __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EMailSelected )( 
            IMSIMContactView __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InviteSelected )( 
            IMSIMContactView __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BlockSelected )( 
            IMSIMContactView __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnblockSelected )( 
            IMSIMContactView __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ExtentWidth )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pX);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ExtentHeight )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pY);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HotTracking )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HotTracking )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AllowCollapse )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AllowCollapse )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowSelectAlways )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowSelectAlways )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnlineRootLabel )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrLabel);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnlineRootLabel )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ BSTR bstrLabel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OfflineRootLabel )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrLabel);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OfflineRootLabel )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ BSTR bstrLabel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Window )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowLogonButton )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowLogonButton )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnlineCollapsed )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnlineCollapsed )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OfflineCollapsed )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OfflineCollapsed )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Group )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Group )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FilterOffline )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FilterOffline )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowIcons )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowIcons )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AcceptMessages )( 
            IMSIMContactView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AcceptMessages )( 
            IMSIMContactView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IMSIMContactViewVtbl;

    interface IMSIMContactView
    {
        CONST_VTBL struct IMSIMContactViewVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSIMContactView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMSIMContactView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMSIMContactView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMSIMContactView_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMSIMContactView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMSIMContactView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMSIMContactView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMSIMContactView_SetService(This,pService,pApp)	\
    (This)->lpVtbl -> SetService(This,pService,pApp)

#define IMSIMContactView_get_Service(This,pVal)	\
    (This)->lpVtbl -> get_Service(This,pVal)

#define IMSIMContactView_put_Service(This,newVal)	\
    (This)->lpVtbl -> put_Service(This,newVal)

#define IMSIMContactView_get_HasService(This,pVal)	\
    (This)->lpVtbl -> get_HasService(This,pVal)

#define IMSIMContactView_get_AutoLogon(This,pVal)	\
    (This)->lpVtbl -> get_AutoLogon(This,pVal)

#define IMSIMContactView_put_AutoLogon(This,newVal)	\
    (This)->lpVtbl -> put_AutoLogon(This,newVal)

#define IMSIMContactView_get_LoggedOn(This,pVal)	\
    (This)->lpVtbl -> get_LoggedOn(This,pVal)

#define IMSIMContactView_Logon(This,bstrAddress,bstrName,bstrPassword,bstrDomain)	\
    (This)->lpVtbl -> Logon(This,bstrAddress,bstrName,bstrPassword,bstrDomain)

#define IMSIMContactView_Logoff(This)	\
    (This)->lpVtbl -> Logoff(This)

#define IMSIMContactView_GetLocalState(This,pvarState,pvarDescription,pvarData)	\
    (This)->lpVtbl -> GetLocalState(This,pvarState,pvarDescription,pvarData)

#define IMSIMContactView_SetLocalState(This,lState,varDescription,varData)	\
    (This)->lpVtbl -> SetLocalState(This,lState,varDescription,varData)


#define IMSIMContactView_Add(This,vUser)	\
    (This)->lpVtbl -> Add(This,vUser)

#define IMSIMContactView_Remove(This,vUser)	\
    (This)->lpVtbl -> Remove(This,vUser)

#define IMSIMContactView_get_List(This,pvarList)	\
    (This)->lpVtbl -> get_List(This,pvarList)

#define IMSIMContactView_put_List(This,varList)	\
    (This)->lpVtbl -> put_List(This,varList)

#define IMSIMContactView_AddMenuItem(This,bstrItem,lPosition,plCommand)	\
    (This)->lpVtbl -> AddMenuItem(This,bstrItem,lPosition,plCommand)

#define IMSIMContactView_get_SelectedMenuOptions(This,pVal)	\
    (This)->lpVtbl -> get_SelectedMenuOptions(This,pVal)

#define IMSIMContactView_IMSelected(This)	\
    (This)->lpVtbl -> IMSelected(This)

#define IMSIMContactView_EMailSelected(This)	\
    (This)->lpVtbl -> EMailSelected(This)

#define IMSIMContactView_InviteSelected(This)	\
    (This)->lpVtbl -> InviteSelected(This)

#define IMSIMContactView_BlockSelected(This)	\
    (This)->lpVtbl -> BlockSelected(This)

#define IMSIMContactView_UnblockSelected(This)	\
    (This)->lpVtbl -> UnblockSelected(This)

#define IMSIMContactView_get_ExtentWidth(This,pX)	\
    (This)->lpVtbl -> get_ExtentWidth(This,pX)

#define IMSIMContactView_get_ExtentHeight(This,pY)	\
    (This)->lpVtbl -> get_ExtentHeight(This,pY)

#define IMSIMContactView_get_HotTracking(This,pVal)	\
    (This)->lpVtbl -> get_HotTracking(This,pVal)

#define IMSIMContactView_put_HotTracking(This,newVal)	\
    (This)->lpVtbl -> put_HotTracking(This,newVal)

#define IMSIMContactView_get_AllowCollapse(This,pVal)	\
    (This)->lpVtbl -> get_AllowCollapse(This,pVal)

#define IMSIMContactView_put_AllowCollapse(This,newVal)	\
    (This)->lpVtbl -> put_AllowCollapse(This,newVal)

#define IMSIMContactView_get_ShowSelectAlways(This,pVal)	\
    (This)->lpVtbl -> get_ShowSelectAlways(This,pVal)

#define IMSIMContactView_put_ShowSelectAlways(This,newVal)	\
    (This)->lpVtbl -> put_ShowSelectAlways(This,newVal)

#define IMSIMContactView_get_OnlineRootLabel(This,pbstrLabel)	\
    (This)->lpVtbl -> get_OnlineRootLabel(This,pbstrLabel)

#define IMSIMContactView_put_OnlineRootLabel(This,bstrLabel)	\
    (This)->lpVtbl -> put_OnlineRootLabel(This,bstrLabel)

#define IMSIMContactView_get_OfflineRootLabel(This,pbstrLabel)	\
    (This)->lpVtbl -> get_OfflineRootLabel(This,pbstrLabel)

#define IMSIMContactView_put_OfflineRootLabel(This,bstrLabel)	\
    (This)->lpVtbl -> put_OfflineRootLabel(This,bstrLabel)

#define IMSIMContactView_get_Window(This,pVal)	\
    (This)->lpVtbl -> get_Window(This,pVal)

#define IMSIMContactView_get_ShowLogonButton(This,pVal)	\
    (This)->lpVtbl -> get_ShowLogonButton(This,pVal)

#define IMSIMContactView_put_ShowLogonButton(This,newVal)	\
    (This)->lpVtbl -> put_ShowLogonButton(This,newVal)

#define IMSIMContactView_get_OnlineCollapsed(This,pVal)	\
    (This)->lpVtbl -> get_OnlineCollapsed(This,pVal)

#define IMSIMContactView_put_OnlineCollapsed(This,newVal)	\
    (This)->lpVtbl -> put_OnlineCollapsed(This,newVal)

#define IMSIMContactView_get_OfflineCollapsed(This,pVal)	\
    (This)->lpVtbl -> get_OfflineCollapsed(This,pVal)

#define IMSIMContactView_put_OfflineCollapsed(This,newVal)	\
    (This)->lpVtbl -> put_OfflineCollapsed(This,newVal)

#define IMSIMContactView_get_Group(This,pVal)	\
    (This)->lpVtbl -> get_Group(This,pVal)

#define IMSIMContactView_put_Group(This,newVal)	\
    (This)->lpVtbl -> put_Group(This,newVal)

#define IMSIMContactView_get_FilterOffline(This,pVal)	\
    (This)->lpVtbl -> get_FilterOffline(This,pVal)

#define IMSIMContactView_put_FilterOffline(This,newVal)	\
    (This)->lpVtbl -> put_FilterOffline(This,newVal)

#define IMSIMContactView_get_ShowIcons(This,pVal)	\
    (This)->lpVtbl -> get_ShowIcons(This,pVal)

#define IMSIMContactView_put_ShowIcons(This,newVal)	\
    (This)->lpVtbl -> put_ShowIcons(This,newVal)

#define IMSIMContactView_get_AcceptMessages(This,pVal)	\
    (This)->lpVtbl -> get_AcceptMessages(This,pVal)

#define IMSIMContactView_put_AcceptMessages(This,newVal)	\
    (This)->lpVtbl -> put_AcceptMessages(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_Add_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT vUser);


void __RPC_STUB IMSIMContactView_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_Remove_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT vUser);


void __RPC_STUB IMSIMContactView_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_List_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pvarList);


void __RPC_STUB IMSIMContactView_get_List_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_List_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT varList);


void __RPC_STUB IMSIMContactView_put_List_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_AddMenuItem_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ BSTR bstrItem,
    /* [defaultvalue][in] */ long lPosition,
    /* [retval][out] */ long __RPC_FAR *plCommand);


void __RPC_STUB IMSIMContactView_AddMenuItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_SelectedMenuOptions_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_SelectedMenuOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_IMSelected_Proxy( 
    IMSIMContactView __RPC_FAR * This);


void __RPC_STUB IMSIMContactView_IMSelected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_EMailSelected_Proxy( 
    IMSIMContactView __RPC_FAR * This);


void __RPC_STUB IMSIMContactView_EMailSelected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_InviteSelected_Proxy( 
    IMSIMContactView __RPC_FAR * This);


void __RPC_STUB IMSIMContactView_InviteSelected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_BlockSelected_Proxy( 
    IMSIMContactView __RPC_FAR * This);


void __RPC_STUB IMSIMContactView_BlockSelected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_UnblockSelected_Proxy( 
    IMSIMContactView __RPC_FAR * This);


void __RPC_STUB IMSIMContactView_UnblockSelected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_ExtentWidth_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pX);


void __RPC_STUB IMSIMContactView_get_ExtentWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_ExtentHeight_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pY);


void __RPC_STUB IMSIMContactView_get_ExtentHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_HotTracking_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_HotTracking_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_HotTracking_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMContactView_put_HotTracking_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_AllowCollapse_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_AllowCollapse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_AllowCollapse_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMContactView_put_AllowCollapse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_ShowSelectAlways_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_ShowSelectAlways_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_ShowSelectAlways_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMContactView_put_ShowSelectAlways_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_OnlineRootLabel_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrLabel);


void __RPC_STUB IMSIMContactView_get_OnlineRootLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_OnlineRootLabel_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ BSTR bstrLabel);


void __RPC_STUB IMSIMContactView_put_OnlineRootLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_OfflineRootLabel_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrLabel);


void __RPC_STUB IMSIMContactView_get_OfflineRootLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_OfflineRootLabel_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ BSTR bstrLabel);


void __RPC_STUB IMSIMContactView_put_OfflineRootLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_Window_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_Window_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_ShowLogonButton_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_ShowLogonButton_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_ShowLogonButton_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMContactView_put_ShowLogonButton_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_OnlineCollapsed_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_OnlineCollapsed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_OnlineCollapsed_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMContactView_put_OnlineCollapsed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_OfflineCollapsed_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_OfflineCollapsed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_OfflineCollapsed_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMContactView_put_OfflineCollapsed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_Group_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_Group_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_Group_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMContactView_put_Group_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_FilterOffline_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_FilterOffline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_FilterOffline_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMContactView_put_FilterOffline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_ShowIcons_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_ShowIcons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_ShowIcons_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMContactView_put_ShowIcons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_get_AcceptMessages_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactView_get_AcceptMessages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactView_put_AcceptMessages_Proxy( 
    IMSIMContactView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMContactView_put_AcceptMessages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMSIMContactView_INTERFACE_DEFINED__ */


#ifndef __DMSIMContactViewEvents_DISPINTERFACE_DEFINED__
#define __DMSIMContactViewEvents_DISPINTERFACE_DEFINED__

/* dispinterface DMSIMContactViewEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_DMSIMContactViewEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5D39E512-1068-4F85-8173-357CA1892EE2")
    DMSIMContactViewEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct DMSIMContactViewEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            DMSIMContactViewEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            DMSIMContactViewEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            DMSIMContactViewEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            DMSIMContactViewEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            DMSIMContactViewEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            DMSIMContactViewEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            DMSIMContactViewEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } DMSIMContactViewEventsVtbl;

    interface DMSIMContactViewEvents
    {
        CONST_VTBL struct DMSIMContactViewEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define DMSIMContactViewEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define DMSIMContactViewEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define DMSIMContactViewEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define DMSIMContactViewEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define DMSIMContactViewEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define DMSIMContactViewEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define DMSIMContactViewEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __DMSIMContactViewEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IMSIMMessageView_INTERFACE_DEFINED__
#define __IMSIMMessageView_INTERFACE_DEFINED__

/* interface IMSIMMessageView */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMSIMMessageView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("053A4F4E-B931-4602-8C73-ABD3040558F2")
    IMSIMMessageView : public _IUseIMBase
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Window( 
            /* [retval][out] */ long __RPC_FAR *phwnd) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Appearance( 
            /* [in] */ short appearance) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Appearance( 
            /* [retval][out] */ short __RPC_FAR *pappearance) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowParticipants( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowParticipants( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowMembers( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowMembers( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowAvailable( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowAvailable( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AvailableList( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AvailableList( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowMessageHistory( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowMessageHistory( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowEdit( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowEdit( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HideStatus( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HideStatus( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MessageHistory( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StatusText( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MessageText( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MessageText( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Invite( 
            /* [in] */ VARIANT varContact) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndSession( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddToAvailable( 
            /* [in] */ VARIANT varContact) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveFromAvailable( 
            /* [in] */ VARIANT varContact) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InviteNetMeeting( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NetMeetingInvite( 
            /* [in] */ IDispatch __RPC_FAR *pIMSession,
            /* [in] */ IDispatch __RPC_FAR *pContact,
            /* [in] */ long lInviteCookie) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceURL( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SourceURL( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InSession( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSIMMessageViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMSIMMessageView __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMSIMMessageView __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetService )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pService,
            /* [defaultvalue][in] */ IDispatch __RPC_FAR *pApp);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Service )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Service )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HasService )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AutoLogon )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AutoLogon )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LoggedOn )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Logon )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [defaultvalue][full][in] */ BSTR bstrAddress,
            /* [defaultvalue][full][in] */ BSTR bstrName,
            /* [defaultvalue][full][in] */ BSTR bstrPassword,
            /* [defaultvalue][full][in] */ BSTR bstrDomain);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Logoff )( 
            IMSIMMessageView __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLocalState )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *pvarState,
            /* [optional][out] */ VARIANT __RPC_FAR *pvarDescription,
            /* [optional][out] */ VARIANT __RPC_FAR *pvarData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLocalState )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ long lState,
            /* [optional][in] */ VARIANT varDescription,
            /* [optional][in] */ VARIANT varData);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Window )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *phwnd);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Appearance )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ short appearance);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Appearance )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pappearance);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowParticipants )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowParticipants )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowMembers )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowMembers )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowAvailable )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowAvailable )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AvailableList )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AvailableList )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowMessageHistory )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowMessageHistory )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowEdit )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowEdit )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HideStatus )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HideStatus )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MessageHistory )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StatusText )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StatusText )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MessageText )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MessageText )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invite )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ VARIANT varContact);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndSession )( 
            IMSIMMessageView __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddToAvailable )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ VARIANT varContact);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveFromAvailable )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ VARIANT varContact);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InviteNetMeeting )( 
            IMSIMMessageView __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NetMeetingInvite )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pIMSession,
            /* [in] */ IDispatch __RPC_FAR *pContact,
            /* [in] */ long lInviteCookie);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SourceURL )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SourceURL )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_InSession )( 
            IMSIMMessageView __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        END_INTERFACE
    } IMSIMMessageViewVtbl;

    interface IMSIMMessageView
    {
        CONST_VTBL struct IMSIMMessageViewVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSIMMessageView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMSIMMessageView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMSIMMessageView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMSIMMessageView_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMSIMMessageView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMSIMMessageView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMSIMMessageView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMSIMMessageView_SetService(This,pService,pApp)	\
    (This)->lpVtbl -> SetService(This,pService,pApp)

#define IMSIMMessageView_get_Service(This,pVal)	\
    (This)->lpVtbl -> get_Service(This,pVal)

#define IMSIMMessageView_put_Service(This,newVal)	\
    (This)->lpVtbl -> put_Service(This,newVal)

#define IMSIMMessageView_get_HasService(This,pVal)	\
    (This)->lpVtbl -> get_HasService(This,pVal)

#define IMSIMMessageView_get_AutoLogon(This,pVal)	\
    (This)->lpVtbl -> get_AutoLogon(This,pVal)

#define IMSIMMessageView_put_AutoLogon(This,newVal)	\
    (This)->lpVtbl -> put_AutoLogon(This,newVal)

#define IMSIMMessageView_get_LoggedOn(This,pVal)	\
    (This)->lpVtbl -> get_LoggedOn(This,pVal)

#define IMSIMMessageView_Logon(This,bstrAddress,bstrName,bstrPassword,bstrDomain)	\
    (This)->lpVtbl -> Logon(This,bstrAddress,bstrName,bstrPassword,bstrDomain)

#define IMSIMMessageView_Logoff(This)	\
    (This)->lpVtbl -> Logoff(This)

#define IMSIMMessageView_GetLocalState(This,pvarState,pvarDescription,pvarData)	\
    (This)->lpVtbl -> GetLocalState(This,pvarState,pvarDescription,pvarData)

#define IMSIMMessageView_SetLocalState(This,lState,varDescription,varData)	\
    (This)->lpVtbl -> SetLocalState(This,lState,varDescription,varData)


#define IMSIMMessageView_get_Window(This,phwnd)	\
    (This)->lpVtbl -> get_Window(This,phwnd)

#define IMSIMMessageView_put_Appearance(This,appearance)	\
    (This)->lpVtbl -> put_Appearance(This,appearance)

#define IMSIMMessageView_get_Appearance(This,pappearance)	\
    (This)->lpVtbl -> get_Appearance(This,pappearance)

#define IMSIMMessageView_get_ShowParticipants(This,pVal)	\
    (This)->lpVtbl -> get_ShowParticipants(This,pVal)

#define IMSIMMessageView_put_ShowParticipants(This,newVal)	\
    (This)->lpVtbl -> put_ShowParticipants(This,newVal)

#define IMSIMMessageView_get_ShowMembers(This,pVal)	\
    (This)->lpVtbl -> get_ShowMembers(This,pVal)

#define IMSIMMessageView_put_ShowMembers(This,newVal)	\
    (This)->lpVtbl -> put_ShowMembers(This,newVal)

#define IMSIMMessageView_get_ShowAvailable(This,pVal)	\
    (This)->lpVtbl -> get_ShowAvailable(This,pVal)

#define IMSIMMessageView_put_ShowAvailable(This,newVal)	\
    (This)->lpVtbl -> put_ShowAvailable(This,newVal)

#define IMSIMMessageView_get_AvailableList(This,pVal)	\
    (This)->lpVtbl -> get_AvailableList(This,pVal)

#define IMSIMMessageView_put_AvailableList(This,newVal)	\
    (This)->lpVtbl -> put_AvailableList(This,newVal)

#define IMSIMMessageView_get_ShowMessageHistory(This,pVal)	\
    (This)->lpVtbl -> get_ShowMessageHistory(This,pVal)

#define IMSIMMessageView_put_ShowMessageHistory(This,newVal)	\
    (This)->lpVtbl -> put_ShowMessageHistory(This,newVal)

#define IMSIMMessageView_get_ShowEdit(This,pVal)	\
    (This)->lpVtbl -> get_ShowEdit(This,pVal)

#define IMSIMMessageView_put_ShowEdit(This,newVal)	\
    (This)->lpVtbl -> put_ShowEdit(This,newVal)

#define IMSIMMessageView_get_HideStatus(This,pVal)	\
    (This)->lpVtbl -> get_HideStatus(This,pVal)

#define IMSIMMessageView_put_HideStatus(This,newVal)	\
    (This)->lpVtbl -> put_HideStatus(This,newVal)

#define IMSIMMessageView_get_MessageHistory(This,pVal)	\
    (This)->lpVtbl -> get_MessageHistory(This,pVal)

#define IMSIMMessageView_get_StatusText(This,pVal)	\
    (This)->lpVtbl -> get_StatusText(This,pVal)

#define IMSIMMessageView_put_StatusText(This,newVal)	\
    (This)->lpVtbl -> put_StatusText(This,newVal)

#define IMSIMMessageView_get_MessageText(This,pVal)	\
    (This)->lpVtbl -> get_MessageText(This,pVal)

#define IMSIMMessageView_put_MessageText(This,newVal)	\
    (This)->lpVtbl -> put_MessageText(This,newVal)

#define IMSIMMessageView_Invite(This,varContact)	\
    (This)->lpVtbl -> Invite(This,varContact)

#define IMSIMMessageView_EndSession(This)	\
    (This)->lpVtbl -> EndSession(This)

#define IMSIMMessageView_AddToAvailable(This,varContact)	\
    (This)->lpVtbl -> AddToAvailable(This,varContact)

#define IMSIMMessageView_RemoveFromAvailable(This,varContact)	\
    (This)->lpVtbl -> RemoveFromAvailable(This,varContact)

#define IMSIMMessageView_InviteNetMeeting(This)	\
    (This)->lpVtbl -> InviteNetMeeting(This)

#define IMSIMMessageView_NetMeetingInvite(This,pIMSession,pContact,lInviteCookie)	\
    (This)->lpVtbl -> NetMeetingInvite(This,pIMSession,pContact,lInviteCookie)

#define IMSIMMessageView_get_SourceURL(This,pVal)	\
    (This)->lpVtbl -> get_SourceURL(This,pVal)

#define IMSIMMessageView_put_SourceURL(This,newVal)	\
    (This)->lpVtbl -> put_SourceURL(This,newVal)

#define IMSIMMessageView_get_InSession(This,pVal)	\
    (This)->lpVtbl -> get_InSession(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_Window_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *phwnd);


void __RPC_STUB IMSIMMessageView_get_Window_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_put_Appearance_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ short appearance);


void __RPC_STUB IMSIMMessageView_put_Appearance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_Appearance_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pappearance);


void __RPC_STUB IMSIMMessageView_get_Appearance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_ShowParticipants_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_ShowParticipants_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_put_ShowParticipants_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMMessageView_put_ShowParticipants_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_ShowMembers_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_ShowMembers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_put_ShowMembers_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMMessageView_put_ShowMembers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_ShowAvailable_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_ShowAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_put_ShowAvailable_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMMessageView_put_ShowAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_AvailableList_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_AvailableList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_put_AvailableList_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IMSIMMessageView_put_AvailableList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_ShowMessageHistory_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_ShowMessageHistory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_put_ShowMessageHistory_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMMessageView_put_ShowMessageHistory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_ShowEdit_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_ShowEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_put_ShowEdit_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMMessageView_put_ShowEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_HideStatus_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_HideStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_put_HideStatus_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IMSIMMessageView_put_HideStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_MessageHistory_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_MessageHistory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_StatusText_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_StatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_put_StatusText_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IMSIMMessageView_put_StatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_MessageText_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_MessageText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_put_MessageText_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IMSIMMessageView_put_MessageText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_Invite_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ VARIANT varContact);


void __RPC_STUB IMSIMMessageView_Invite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_EndSession_Proxy( 
    IMSIMMessageView __RPC_FAR * This);


void __RPC_STUB IMSIMMessageView_EndSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_AddToAvailable_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ VARIANT varContact);


void __RPC_STUB IMSIMMessageView_AddToAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_RemoveFromAvailable_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ VARIANT varContact);


void __RPC_STUB IMSIMMessageView_RemoveFromAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_InviteNetMeeting_Proxy( 
    IMSIMMessageView __RPC_FAR * This);


void __RPC_STUB IMSIMMessageView_InviteNetMeeting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_NetMeetingInvite_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pIMSession,
    /* [in] */ IDispatch __RPC_FAR *pContact,
    /* [in] */ long lInviteCookie);


void __RPC_STUB IMSIMMessageView_NetMeetingInvite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_SourceURL_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_SourceURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_put_SourceURL_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IMSIMMessageView_put_SourceURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMMessageView_get_InSession_Proxy( 
    IMSIMMessageView __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IMSIMMessageView_get_InSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMSIMMessageView_INTERFACE_DEFINED__ */


#ifndef __DMSIMMessageViewEvents_DISPINTERFACE_DEFINED__
#define __DMSIMMessageViewEvents_DISPINTERFACE_DEFINED__

/* dispinterface DMSIMMessageViewEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_DMSIMMessageViewEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EFFE4FAB-E75C-46EC-AB15-582CD469EB08")
    DMSIMMessageViewEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct DMSIMMessageViewEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            DMSIMMessageViewEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            DMSIMMessageViewEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            DMSIMMessageViewEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            DMSIMMessageViewEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            DMSIMMessageViewEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            DMSIMMessageViewEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            DMSIMMessageViewEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } DMSIMMessageViewEventsVtbl;

    interface DMSIMMessageViewEvents
    {
        CONST_VTBL struct DMSIMMessageViewEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define DMSIMMessageViewEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define DMSIMMessageViewEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define DMSIMMessageViewEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define DMSIMMessageViewEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define DMSIMMessageViewEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define DMSIMMessageViewEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define DMSIMMessageViewEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __DMSIMMessageViewEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MSIMContactView;

#ifdef __cplusplus

class DECLSPEC_UUID("B06EDBC7-287D-405C-A899-9C7F8358EF26")
MSIMContactView;
#endif

EXTERN_C const CLSID CLSID_MSIMMessageView;

#ifdef __cplusplus

class DECLSPEC_UUID("528B6917-4DED-43F1-B56C-35A1519129CA")
MSIMMessageView;
#endif

#ifndef __IIMSafeContact_INTERFACE_DEFINED__
#define __IIMSafeContact_INTERFACE_DEFINED__

/* interface IIMSafeContact */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIMSafeContact;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C7B1AD00-4099-4E41-A566-4C49DD3FA19E")
    IIMSafeContact : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogonName( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrLogonName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FriendlyName( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrFriendlyName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EmailAddress( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrEmailAddress) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ long __RPC_FAR *plState) = 0;
        
        virtual /* [restricted][helpstring][id] */ HRESULT STDMETHODCALLTYPE _SetBaseContact( 
            IDispatch __RPC_FAR *pUnk) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LaunchInstantMessage( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LaunchEmail( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LaunchNetMeeting( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIMSafeContactVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIMSafeContact __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIMSafeContact __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIMSafeContact __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIMSafeContact __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIMSafeContact __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIMSafeContact __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIMSafeContact __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LogonName )( 
            IIMSafeContact __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrLogonName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FriendlyName )( 
            IIMSafeContact __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrFriendlyName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EmailAddress )( 
            IIMSafeContact __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrEmailAddress);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_State )( 
            IIMSafeContact __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *plState);
        
        /* [restricted][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_SetBaseContact )( 
            IIMSafeContact __RPC_FAR * This,
            IDispatch __RPC_FAR *pUnk);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LaunchInstantMessage )( 
            IIMSafeContact __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LaunchEmail )( 
            IIMSafeContact __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LaunchNetMeeting )( 
            IIMSafeContact __RPC_FAR * This);
        
        END_INTERFACE
    } IIMSafeContactVtbl;

    interface IIMSafeContact
    {
        CONST_VTBL struct IIMSafeContactVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMSafeContact_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIMSafeContact_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIMSafeContact_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIMSafeContact_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIMSafeContact_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIMSafeContact_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIMSafeContact_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIMSafeContact_get_LogonName(This,pbstrLogonName)	\
    (This)->lpVtbl -> get_LogonName(This,pbstrLogonName)

#define IIMSafeContact_get_FriendlyName(This,pbstrFriendlyName)	\
    (This)->lpVtbl -> get_FriendlyName(This,pbstrFriendlyName)

#define IIMSafeContact_get_EmailAddress(This,pbstrEmailAddress)	\
    (This)->lpVtbl -> get_EmailAddress(This,pbstrEmailAddress)

#define IIMSafeContact_get_State(This,plState)	\
    (This)->lpVtbl -> get_State(This,plState)

#define IIMSafeContact__SetBaseContact(This,pUnk)	\
    (This)->lpVtbl -> _SetBaseContact(This,pUnk)

#define IIMSafeContact_LaunchInstantMessage(This)	\
    (This)->lpVtbl -> LaunchInstantMessage(This)

#define IIMSafeContact_LaunchEmail(This)	\
    (This)->lpVtbl -> LaunchEmail(This)

#define IIMSafeContact_LaunchNetMeeting(This)	\
    (This)->lpVtbl -> LaunchNetMeeting(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIMSafeContact_get_LogonName_Proxy( 
    IIMSafeContact __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrLogonName);


void __RPC_STUB IIMSafeContact_get_LogonName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIMSafeContact_get_FriendlyName_Proxy( 
    IIMSafeContact __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrFriendlyName);


void __RPC_STUB IIMSafeContact_get_FriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIMSafeContact_get_EmailAddress_Proxy( 
    IIMSafeContact __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrEmailAddress);


void __RPC_STUB IIMSafeContact_get_EmailAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIMSafeContact_get_State_Proxy( 
    IIMSafeContact __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *plState);


void __RPC_STUB IIMSafeContact_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [restricted][helpstring][id] */ HRESULT STDMETHODCALLTYPE IIMSafeContact__SetBaseContact_Proxy( 
    IIMSafeContact __RPC_FAR * This,
    IDispatch __RPC_FAR *pUnk);


void __RPC_STUB IIMSafeContact__SetBaseContact_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIMSafeContact_LaunchInstantMessage_Proxy( 
    IIMSafeContact __RPC_FAR * This);


void __RPC_STUB IIMSafeContact_LaunchInstantMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIMSafeContact_LaunchEmail_Proxy( 
    IIMSafeContact __RPC_FAR * This);


void __RPC_STUB IIMSafeContact_LaunchEmail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIMSafeContact_LaunchNetMeeting_Proxy( 
    IIMSafeContact __RPC_FAR * This);


void __RPC_STUB IIMSafeContact_LaunchNetMeeting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIMSafeContact_INTERFACE_DEFINED__ */


#ifndef __IMSIMContactList_INTERFACE_DEFINED__
#define __IMSIMContactList_INTERFACE_DEFINED__

/* interface IMSIMContactList */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMSIMContactList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("31AE52BA-BCED-4D92-9582-8C4560D6C258")
    IMSIMContactList : public _IUseIMBase
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_List( 
            /* [retval][out] */ VARIANT __RPC_FAR *pvarList) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_List( 
            /* [in] */ VARIANT varList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ VARIANT vUser) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT vUser) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SelectedMenuOptions( 
            /* [in] */ long lRow,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InstantMessage( 
            /* [in] */ long lRow) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EMail( 
            /* [in] */ long lRow) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Invite( 
            /* [in] */ long lRow) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Block( 
            /* [in] */ long lRow) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Unblock( 
            /* [in] */ long lRow) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pnCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Var,
            /* [retval][out] */ VARIANT __RPC_FAR *pSafeContact) = 0;
        
        virtual /* [restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LocalState( 
            /* [retval][out] */ long __RPC_FAR *pnState) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_LocalState( 
            /* [in] */ long nState) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LocalLogonName( 
            /* [retval][out] */ BSTR __RPC_FAR *pval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSIMContactListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMSIMContactList __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMSIMContactList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IMSIMContactList __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetService )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pService,
            /* [defaultvalue][in] */ IDispatch __RPC_FAR *pApp);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Service )( 
            IMSIMContactList __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Service )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HasService )( 
            IMSIMContactList __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AutoLogon )( 
            IMSIMContactList __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AutoLogon )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LoggedOn )( 
            IMSIMContactList __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Logon )( 
            IMSIMContactList __RPC_FAR * This,
            /* [defaultvalue][full][in] */ BSTR bstrAddress,
            /* [defaultvalue][full][in] */ BSTR bstrName,
            /* [defaultvalue][full][in] */ BSTR bstrPassword,
            /* [defaultvalue][full][in] */ BSTR bstrDomain);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Logoff )( 
            IMSIMContactList __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLocalState )( 
            IMSIMContactList __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *pvarState,
            /* [optional][out] */ VARIANT __RPC_FAR *pvarDescription,
            /* [optional][out] */ VARIANT __RPC_FAR *pvarData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLocalState )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ long lState,
            /* [optional][in] */ VARIANT varDescription,
            /* [optional][in] */ VARIANT varData);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_List )( 
            IMSIMContactList __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pvarList);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_List )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ VARIANT varList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ VARIANT vUser);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ VARIANT vUser);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SelectedMenuOptions )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ long lRow,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InstantMessage )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ long lRow);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EMail )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ long lRow);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invite )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ long lRow);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Block )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ long lRow);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unblock )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ long lRow);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IMSIMContactList __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pnCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ VARIANT Var,
            /* [retval][out] */ VARIANT __RPC_FAR *pSafeContact);
        
        /* [restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            IMSIMContactList __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LocalState )( 
            IMSIMContactList __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pnState);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LocalState )( 
            IMSIMContactList __RPC_FAR * This,
            /* [in] */ long nState);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LocalLogonName )( 
            IMSIMContactList __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pval);
        
        END_INTERFACE
    } IMSIMContactListVtbl;

    interface IMSIMContactList
    {
        CONST_VTBL struct IMSIMContactListVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSIMContactList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMSIMContactList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMSIMContactList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMSIMContactList_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMSIMContactList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMSIMContactList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMSIMContactList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMSIMContactList_SetService(This,pService,pApp)	\
    (This)->lpVtbl -> SetService(This,pService,pApp)

#define IMSIMContactList_get_Service(This,pVal)	\
    (This)->lpVtbl -> get_Service(This,pVal)

#define IMSIMContactList_put_Service(This,newVal)	\
    (This)->lpVtbl -> put_Service(This,newVal)

#define IMSIMContactList_get_HasService(This,pVal)	\
    (This)->lpVtbl -> get_HasService(This,pVal)

#define IMSIMContactList_get_AutoLogon(This,pVal)	\
    (This)->lpVtbl -> get_AutoLogon(This,pVal)

#define IMSIMContactList_put_AutoLogon(This,newVal)	\
    (This)->lpVtbl -> put_AutoLogon(This,newVal)

#define IMSIMContactList_get_LoggedOn(This,pVal)	\
    (This)->lpVtbl -> get_LoggedOn(This,pVal)

#define IMSIMContactList_Logon(This,bstrAddress,bstrName,bstrPassword,bstrDomain)	\
    (This)->lpVtbl -> Logon(This,bstrAddress,bstrName,bstrPassword,bstrDomain)

#define IMSIMContactList_Logoff(This)	\
    (This)->lpVtbl -> Logoff(This)

#define IMSIMContactList_GetLocalState(This,pvarState,pvarDescription,pvarData)	\
    (This)->lpVtbl -> GetLocalState(This,pvarState,pvarDescription,pvarData)

#define IMSIMContactList_SetLocalState(This,lState,varDescription,varData)	\
    (This)->lpVtbl -> SetLocalState(This,lState,varDescription,varData)


#define IMSIMContactList_get_List(This,pvarList)	\
    (This)->lpVtbl -> get_List(This,pvarList)

#define IMSIMContactList_put_List(This,varList)	\
    (This)->lpVtbl -> put_List(This,varList)

#define IMSIMContactList_Add(This,vUser)	\
    (This)->lpVtbl -> Add(This,vUser)

#define IMSIMContactList_Remove(This,vUser)	\
    (This)->lpVtbl -> Remove(This,vUser)

#define IMSIMContactList_get_SelectedMenuOptions(This,lRow,pVal)	\
    (This)->lpVtbl -> get_SelectedMenuOptions(This,lRow,pVal)

#define IMSIMContactList_InstantMessage(This,lRow)	\
    (This)->lpVtbl -> InstantMessage(This,lRow)

#define IMSIMContactList_EMail(This,lRow)	\
    (This)->lpVtbl -> EMail(This,lRow)

#define IMSIMContactList_Invite(This,lRow)	\
    (This)->lpVtbl -> Invite(This,lRow)

#define IMSIMContactList_Block(This,lRow)	\
    (This)->lpVtbl -> Block(This,lRow)

#define IMSIMContactList_Unblock(This,lRow)	\
    (This)->lpVtbl -> Unblock(This,lRow)

#define IMSIMContactList_get_Count(This,pnCount)	\
    (This)->lpVtbl -> get_Count(This,pnCount)

#define IMSIMContactList_get_Item(This,Var,pSafeContact)	\
    (This)->lpVtbl -> get_Item(This,Var,pSafeContact)

#define IMSIMContactList_get__NewEnum(This,ppunkEnum)	\
    (This)->lpVtbl -> get__NewEnum(This,ppunkEnum)

#define IMSIMContactList_get_LocalState(This,pnState)	\
    (This)->lpVtbl -> get_LocalState(This,pnState)

#define IMSIMContactList_put_LocalState(This,nState)	\
    (This)->lpVtbl -> put_LocalState(This,nState)

#define IMSIMContactList_get_LocalLogonName(This,pval)	\
    (This)->lpVtbl -> get_LocalLogonName(This,pval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_get_List_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pvarList);


void __RPC_STUB IMSIMContactList_get_List_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_put_List_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [in] */ VARIANT varList);


void __RPC_STUB IMSIMContactList_put_List_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_Add_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [in] */ VARIANT vUser);


void __RPC_STUB IMSIMContactList_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_Remove_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [in] */ VARIANT vUser);


void __RPC_STUB IMSIMContactList_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_get_SelectedMenuOptions_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [in] */ long lRow,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IMSIMContactList_get_SelectedMenuOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_InstantMessage_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [in] */ long lRow);


void __RPC_STUB IMSIMContactList_InstantMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_EMail_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [in] */ long lRow);


void __RPC_STUB IMSIMContactList_EMail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_Invite_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [in] */ long lRow);


void __RPC_STUB IMSIMContactList_Invite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_Block_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [in] */ long lRow);


void __RPC_STUB IMSIMContactList_Block_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_Unblock_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [in] */ long lRow);


void __RPC_STUB IMSIMContactList_Unblock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_get_Count_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pnCount);


void __RPC_STUB IMSIMContactList_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_get_Item_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [in] */ VARIANT Var,
    /* [retval][out] */ VARIANT __RPC_FAR *pSafeContact);


void __RPC_STUB IMSIMContactList_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [restricted][id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_get__NewEnum_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);


void __RPC_STUB IMSIMContactList_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_get_LocalState_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pnState);


void __RPC_STUB IMSIMContactList_get_LocalState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_put_LocalState_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [in] */ long nState);


void __RPC_STUB IMSIMContactList_put_LocalState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IMSIMContactList_get_LocalLogonName_Proxy( 
    IMSIMContactList __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pval);


void __RPC_STUB IMSIMContactList_get_LocalLogonName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMSIMContactList_INTERFACE_DEFINED__ */


#ifndef __DIMContactListEvents_DISPINTERFACE_DEFINED__
#define __DIMContactListEvents_DISPINTERFACE_DEFINED__

/* dispinterface DIMContactListEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_DIMContactListEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8D99BC3C-1F60-4f2e-9D8B-5881604A2E51")
    DIMContactListEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct DIMContactListEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            DIMContactListEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            DIMContactListEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            DIMContactListEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            DIMContactListEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            DIMContactListEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            DIMContactListEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            DIMContactListEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } DIMContactListEventsVtbl;

    interface DIMContactListEvents
    {
        CONST_VTBL struct DIMContactListEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define DIMContactListEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define DIMContactListEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define DIMContactListEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define DIMContactListEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define DIMContactListEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define DIMContactListEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define DIMContactListEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __DIMContactListEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MSIMContactList;

#ifdef __cplusplus

class DECLSPEC_UUID("0711F6B0-B4FA-4DDB-893E-CC197A8F9DC7")
MSIMContactList;
#endif

EXTERN_C const CLSID CLSID_IMSafeContact;

#ifdef __cplusplus

class DECLSPEC_UUID("EFF88E1B-4A46-4B09-9D2A-8191C42A1661")
IMSafeContact;
#endif
#endif /* __MSIMCNTLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


