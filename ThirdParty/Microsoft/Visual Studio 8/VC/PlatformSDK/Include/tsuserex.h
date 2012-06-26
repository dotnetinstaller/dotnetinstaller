

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for tsuserex.idl:
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


#ifndef __tsuserex_h__
#define __tsuserex_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __TSUserExInterfaces_FWD_DEFINED__
#define __TSUserExInterfaces_FWD_DEFINED__

#ifdef __cplusplus
typedef class TSUserExInterfaces TSUserExInterfaces;
#else
typedef struct TSUserExInterfaces TSUserExInterfaces;
#endif /* __cplusplus */

#endif 	/* __TSUserExInterfaces_FWD_DEFINED__ */


#ifndef __IADsTSUserEx_FWD_DEFINED__
#define __IADsTSUserEx_FWD_DEFINED__
typedef interface IADsTSUserEx IADsTSUserEx;
#endif 	/* __IADsTSUserEx_FWD_DEFINED__ */


#ifndef __ADsTSUserEx_FWD_DEFINED__
#define __ADsTSUserEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class ADsTSUserEx ADsTSUserEx;
#else
typedef struct ADsTSUserEx ADsTSUserEx;
#endif /* __cplusplus */

#endif 	/* __ADsTSUserEx_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "mmc.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __TSUSEREXLib_LIBRARY_DEFINED__
#define __TSUSEREXLib_LIBRARY_DEFINED__

/* library TSUSEREXLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TSUSEREXLib;

EXTERN_C const CLSID CLSID_TSUserExInterfaces;

#ifdef __cplusplus

class DECLSPEC_UUID("0910dd01-df8c-11d1-ae27-00c04fa35813")
TSUserExInterfaces;
#endif

#ifndef __IADsTSUserEx_INTERFACE_DEFINED__
#define __IADsTSUserEx_INTERFACE_DEFINED__

/* interface IADsTSUserEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IADsTSUserEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4930E79-2989-4462-8A60-2FCF2F2955EF")
    IADsTSUserEx : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TerminalServicesProfilePath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TerminalServicesProfilePath( 
            /* [in] */ BSTR pNewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TerminalServicesHomeDirectory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TerminalServicesHomeDirectory( 
            /* [in] */ BSTR pNewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TerminalServicesHomeDrive( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TerminalServicesHomeDrive( 
            /* [in] */ BSTR pNewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowLogon( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowLogon( 
            /* [in] */ LONG NewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableRemoteControl( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableRemoteControl( 
            /* [in] */ LONG NewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxDisconnectionTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxDisconnectionTime( 
            /* [in] */ LONG NewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxConnectionTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxConnectionTime( 
            /* [in] */ LONG NewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxIdleTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxIdleTime( 
            /* [in] */ LONG NewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ReconnectionAction( 
            /* [retval][out] */ LONG *pNewVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ReconnectionAction( 
            /* [in] */ LONG NewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BrokenConnectionAction( 
            /* [retval][out] */ LONG *pNewVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BrokenConnectionAction( 
            /* [in] */ LONG NewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ConnectClientDrivesAtLogon( 
            /* [retval][out] */ LONG *pNewVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ConnectClientDrivesAtLogon( 
            /* [in] */ LONG NewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ConnectClientPrintersAtLogon( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ConnectClientPrintersAtLogon( 
            /* [in] */ LONG NewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultToMainPrinter( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultToMainPrinter( 
            /* [in] */ LONG NewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TerminalServicesWorkDirectory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TerminalServicesWorkDirectory( 
            /* [in] */ BSTR pNewVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TerminalServicesInitialProgram( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TerminalServicesInitialProgram( 
            /* [in] */ BSTR pNewVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADsTSUserExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IADsTSUserEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IADsTSUserEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IADsTSUserEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IADsTSUserEx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IADsTSUserEx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IADsTSUserEx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IADsTSUserEx * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TerminalServicesProfilePath )( 
            IADsTSUserEx * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TerminalServicesProfilePath )( 
            IADsTSUserEx * This,
            /* [in] */ BSTR pNewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TerminalServicesHomeDirectory )( 
            IADsTSUserEx * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TerminalServicesHomeDirectory )( 
            IADsTSUserEx * This,
            /* [in] */ BSTR pNewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TerminalServicesHomeDrive )( 
            IADsTSUserEx * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TerminalServicesHomeDrive )( 
            IADsTSUserEx * This,
            /* [in] */ BSTR pNewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowLogon )( 
            IADsTSUserEx * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowLogon )( 
            IADsTSUserEx * This,
            /* [in] */ LONG NewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableRemoteControl )( 
            IADsTSUserEx * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableRemoteControl )( 
            IADsTSUserEx * This,
            /* [in] */ LONG NewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxDisconnectionTime )( 
            IADsTSUserEx * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxDisconnectionTime )( 
            IADsTSUserEx * This,
            /* [in] */ LONG NewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxConnectionTime )( 
            IADsTSUserEx * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxConnectionTime )( 
            IADsTSUserEx * This,
            /* [in] */ LONG NewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxIdleTime )( 
            IADsTSUserEx * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxIdleTime )( 
            IADsTSUserEx * This,
            /* [in] */ LONG NewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReconnectionAction )( 
            IADsTSUserEx * This,
            /* [retval][out] */ LONG *pNewVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReconnectionAction )( 
            IADsTSUserEx * This,
            /* [in] */ LONG NewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BrokenConnectionAction )( 
            IADsTSUserEx * This,
            /* [retval][out] */ LONG *pNewVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BrokenConnectionAction )( 
            IADsTSUserEx * This,
            /* [in] */ LONG NewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectClientDrivesAtLogon )( 
            IADsTSUserEx * This,
            /* [retval][out] */ LONG *pNewVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ConnectClientDrivesAtLogon )( 
            IADsTSUserEx * This,
            /* [in] */ LONG NewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectClientPrintersAtLogon )( 
            IADsTSUserEx * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ConnectClientPrintersAtLogon )( 
            IADsTSUserEx * This,
            /* [in] */ LONG NewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultToMainPrinter )( 
            IADsTSUserEx * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultToMainPrinter )( 
            IADsTSUserEx * This,
            /* [in] */ LONG NewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TerminalServicesWorkDirectory )( 
            IADsTSUserEx * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TerminalServicesWorkDirectory )( 
            IADsTSUserEx * This,
            /* [in] */ BSTR pNewVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TerminalServicesInitialProgram )( 
            IADsTSUserEx * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TerminalServicesInitialProgram )( 
            IADsTSUserEx * This,
            /* [in] */ BSTR pNewVal);
        
        END_INTERFACE
    } IADsTSUserExVtbl;

    interface IADsTSUserEx
    {
        CONST_VTBL struct IADsTSUserExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADsTSUserEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADsTSUserEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADsTSUserEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADsTSUserEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADsTSUserEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADsTSUserEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADsTSUserEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADsTSUserEx_get_TerminalServicesProfilePath(This,pVal)	\
    (This)->lpVtbl -> get_TerminalServicesProfilePath(This,pVal)

#define IADsTSUserEx_put_TerminalServicesProfilePath(This,pNewVal)	\
    (This)->lpVtbl -> put_TerminalServicesProfilePath(This,pNewVal)

#define IADsTSUserEx_get_TerminalServicesHomeDirectory(This,pVal)	\
    (This)->lpVtbl -> get_TerminalServicesHomeDirectory(This,pVal)

#define IADsTSUserEx_put_TerminalServicesHomeDirectory(This,pNewVal)	\
    (This)->lpVtbl -> put_TerminalServicesHomeDirectory(This,pNewVal)

#define IADsTSUserEx_get_TerminalServicesHomeDrive(This,pVal)	\
    (This)->lpVtbl -> get_TerminalServicesHomeDrive(This,pVal)

#define IADsTSUserEx_put_TerminalServicesHomeDrive(This,pNewVal)	\
    (This)->lpVtbl -> put_TerminalServicesHomeDrive(This,pNewVal)

#define IADsTSUserEx_get_AllowLogon(This,pVal)	\
    (This)->lpVtbl -> get_AllowLogon(This,pVal)

#define IADsTSUserEx_put_AllowLogon(This,NewVal)	\
    (This)->lpVtbl -> put_AllowLogon(This,NewVal)

#define IADsTSUserEx_get_EnableRemoteControl(This,pVal)	\
    (This)->lpVtbl -> get_EnableRemoteControl(This,pVal)

#define IADsTSUserEx_put_EnableRemoteControl(This,NewVal)	\
    (This)->lpVtbl -> put_EnableRemoteControl(This,NewVal)

#define IADsTSUserEx_get_MaxDisconnectionTime(This,pVal)	\
    (This)->lpVtbl -> get_MaxDisconnectionTime(This,pVal)

#define IADsTSUserEx_put_MaxDisconnectionTime(This,NewVal)	\
    (This)->lpVtbl -> put_MaxDisconnectionTime(This,NewVal)

#define IADsTSUserEx_get_MaxConnectionTime(This,pVal)	\
    (This)->lpVtbl -> get_MaxConnectionTime(This,pVal)

#define IADsTSUserEx_put_MaxConnectionTime(This,NewVal)	\
    (This)->lpVtbl -> put_MaxConnectionTime(This,NewVal)

#define IADsTSUserEx_get_MaxIdleTime(This,pVal)	\
    (This)->lpVtbl -> get_MaxIdleTime(This,pVal)

#define IADsTSUserEx_put_MaxIdleTime(This,NewVal)	\
    (This)->lpVtbl -> put_MaxIdleTime(This,NewVal)

#define IADsTSUserEx_get_ReconnectionAction(This,pNewVal)	\
    (This)->lpVtbl -> get_ReconnectionAction(This,pNewVal)

#define IADsTSUserEx_put_ReconnectionAction(This,NewVal)	\
    (This)->lpVtbl -> put_ReconnectionAction(This,NewVal)

#define IADsTSUserEx_get_BrokenConnectionAction(This,pNewVal)	\
    (This)->lpVtbl -> get_BrokenConnectionAction(This,pNewVal)

#define IADsTSUserEx_put_BrokenConnectionAction(This,NewVal)	\
    (This)->lpVtbl -> put_BrokenConnectionAction(This,NewVal)

#define IADsTSUserEx_get_ConnectClientDrivesAtLogon(This,pNewVal)	\
    (This)->lpVtbl -> get_ConnectClientDrivesAtLogon(This,pNewVal)

#define IADsTSUserEx_put_ConnectClientDrivesAtLogon(This,NewVal)	\
    (This)->lpVtbl -> put_ConnectClientDrivesAtLogon(This,NewVal)

#define IADsTSUserEx_get_ConnectClientPrintersAtLogon(This,pVal)	\
    (This)->lpVtbl -> get_ConnectClientPrintersAtLogon(This,pVal)

#define IADsTSUserEx_put_ConnectClientPrintersAtLogon(This,NewVal)	\
    (This)->lpVtbl -> put_ConnectClientPrintersAtLogon(This,NewVal)

#define IADsTSUserEx_get_DefaultToMainPrinter(This,pVal)	\
    (This)->lpVtbl -> get_DefaultToMainPrinter(This,pVal)

#define IADsTSUserEx_put_DefaultToMainPrinter(This,NewVal)	\
    (This)->lpVtbl -> put_DefaultToMainPrinter(This,NewVal)

#define IADsTSUserEx_get_TerminalServicesWorkDirectory(This,pVal)	\
    (This)->lpVtbl -> get_TerminalServicesWorkDirectory(This,pVal)

#define IADsTSUserEx_put_TerminalServicesWorkDirectory(This,pNewVal)	\
    (This)->lpVtbl -> put_TerminalServicesWorkDirectory(This,pNewVal)

#define IADsTSUserEx_get_TerminalServicesInitialProgram(This,pVal)	\
    (This)->lpVtbl -> get_TerminalServicesInitialProgram(This,pVal)

#define IADsTSUserEx_put_TerminalServicesInitialProgram(This,pNewVal)	\
    (This)->lpVtbl -> put_TerminalServicesInitialProgram(This,pNewVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_TerminalServicesProfilePath_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IADsTSUserEx_get_TerminalServicesProfilePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_TerminalServicesProfilePath_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ BSTR pNewVal);


void __RPC_STUB IADsTSUserEx_put_TerminalServicesProfilePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_TerminalServicesHomeDirectory_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IADsTSUserEx_get_TerminalServicesHomeDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_TerminalServicesHomeDirectory_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ BSTR pNewVal);


void __RPC_STUB IADsTSUserEx_put_TerminalServicesHomeDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_TerminalServicesHomeDrive_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IADsTSUserEx_get_TerminalServicesHomeDrive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_TerminalServicesHomeDrive_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ BSTR pNewVal);


void __RPC_STUB IADsTSUserEx_put_TerminalServicesHomeDrive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_AllowLogon_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IADsTSUserEx_get_AllowLogon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_AllowLogon_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ LONG NewVal);


void __RPC_STUB IADsTSUserEx_put_AllowLogon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_EnableRemoteControl_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IADsTSUserEx_get_EnableRemoteControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_EnableRemoteControl_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ LONG NewVal);


void __RPC_STUB IADsTSUserEx_put_EnableRemoteControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_MaxDisconnectionTime_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IADsTSUserEx_get_MaxDisconnectionTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_MaxDisconnectionTime_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ LONG NewVal);


void __RPC_STUB IADsTSUserEx_put_MaxDisconnectionTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_MaxConnectionTime_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IADsTSUserEx_get_MaxConnectionTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_MaxConnectionTime_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ LONG NewVal);


void __RPC_STUB IADsTSUserEx_put_MaxConnectionTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_MaxIdleTime_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IADsTSUserEx_get_MaxIdleTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_MaxIdleTime_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ LONG NewVal);


void __RPC_STUB IADsTSUserEx_put_MaxIdleTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_ReconnectionAction_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ LONG *pNewVal);


void __RPC_STUB IADsTSUserEx_get_ReconnectionAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_ReconnectionAction_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ LONG NewVal);


void __RPC_STUB IADsTSUserEx_put_ReconnectionAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_BrokenConnectionAction_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ LONG *pNewVal);


void __RPC_STUB IADsTSUserEx_get_BrokenConnectionAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_BrokenConnectionAction_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ LONG NewVal);


void __RPC_STUB IADsTSUserEx_put_BrokenConnectionAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_ConnectClientDrivesAtLogon_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ LONG *pNewVal);


void __RPC_STUB IADsTSUserEx_get_ConnectClientDrivesAtLogon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_ConnectClientDrivesAtLogon_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ LONG NewVal);


void __RPC_STUB IADsTSUserEx_put_ConnectClientDrivesAtLogon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_ConnectClientPrintersAtLogon_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IADsTSUserEx_get_ConnectClientPrintersAtLogon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_ConnectClientPrintersAtLogon_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ LONG NewVal);


void __RPC_STUB IADsTSUserEx_put_ConnectClientPrintersAtLogon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_DefaultToMainPrinter_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IADsTSUserEx_get_DefaultToMainPrinter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_DefaultToMainPrinter_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ LONG NewVal);


void __RPC_STUB IADsTSUserEx_put_DefaultToMainPrinter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_TerminalServicesWorkDirectory_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IADsTSUserEx_get_TerminalServicesWorkDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_TerminalServicesWorkDirectory_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ BSTR pNewVal);


void __RPC_STUB IADsTSUserEx_put_TerminalServicesWorkDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_get_TerminalServicesInitialProgram_Proxy( 
    IADsTSUserEx * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IADsTSUserEx_get_TerminalServicesInitialProgram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IADsTSUserEx_put_TerminalServicesInitialProgram_Proxy( 
    IADsTSUserEx * This,
    /* [in] */ BSTR pNewVal);


void __RPC_STUB IADsTSUserEx_put_TerminalServicesInitialProgram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADsTSUserEx_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ADsTSUserEx;

#ifdef __cplusplus

class DECLSPEC_UUID("E2E9CAE6-1E7B-4B8E-BABD-E9BF6292AC29")
ADsTSUserEx;
#endif
#endif /* __TSUSEREXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


