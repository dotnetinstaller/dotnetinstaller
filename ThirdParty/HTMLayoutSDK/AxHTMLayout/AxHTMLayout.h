

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Jul 05 19:04:02 2010
 */
/* Compiler settings for .\AxHTMLayout.idl:
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

#ifndef __AxHTMLayout_h__
#define __AxHTMLayout_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IElement_FWD_DEFINED__
#define __IElement_FWD_DEFINED__
typedef interface IElement IElement;
#endif 	/* __IElement_FWD_DEFINED__ */


#ifndef __IEngine_FWD_DEFINED__
#define __IEngine_FWD_DEFINED__
typedef interface IEngine IEngine;
#endif 	/* __IEngine_FWD_DEFINED__ */


#ifndef ___IEngineEvents_FWD_DEFINED__
#define ___IEngineEvents_FWD_DEFINED__
typedef interface _IEngineEvents _IEngineEvents;
#endif 	/* ___IEngineEvents_FWD_DEFINED__ */


#ifndef __Engine_FWD_DEFINED__
#define __Engine_FWD_DEFINED__

#ifdef __cplusplus
typedef class Engine Engine;
#else
typedef struct Engine Engine;
#endif /* __cplusplus */

#endif 	/* __Engine_FWD_DEFINED__ */


#ifndef ___IElementEvents_FWD_DEFINED__
#define ___IElementEvents_FWD_DEFINED__
typedef interface _IElementEvents _IElementEvents;
#endif 	/* ___IElementEvents_FWD_DEFINED__ */


#ifndef __Element_FWD_DEFINED__
#define __Element_FWD_DEFINED__

#ifdef __cplusplus
typedef class Element Element;
#else
typedef struct Element Element;
#endif /* __cplusplus */

#endif 	/* __Element_FWD_DEFINED__ */


#ifndef __IElements_FWD_DEFINED__
#define __IElements_FWD_DEFINED__
typedef interface IElements IElements;
#endif 	/* __IElements_FWD_DEFINED__ */


#ifndef __Elements_FWD_DEFINED__
#define __Elements_FWD_DEFINED__

#ifdef __cplusplus
typedef class Elements Elements;
#else
typedef struct Elements Elements;
#endif /* __cplusplus */

#endif 	/* __Elements_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_AxHTMLayout_0000 */
/* [local] */ 

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_AxHTMLayout_0000_0001
    {	ContentBox	= 0,
	PaddingBox	= 0x10,
	BorderBox	= 0x20,
	MarginBox	= 0x30,
	BackImageArea	= 0x40,
	ForeImageArea	= 0x50,
	ScrollableArea	= 0x60
    } 	ElementBoxType;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_AxHTMLayout_0000_0002
    {	RootRelative	= 0x1,
	SelfRelative	= 0x2,
	ContainerRelative	= 0x3,
	ViewRelative	= 0x4
    } 	RelativeToType;




extern RPC_IF_HANDLE __MIDL_itf_AxHTMLayout_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AxHTMLayout_0000_v0_0_s_ifspec;

#ifndef __IElement_INTERFACE_DEFINED__
#define __IElement_INTERFACE_DEFINED__

/* interface IElement */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IElement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F144258B-4129-42E1-9A07-9F04845C6290")
    IElement : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Select( 
            /* [in] */ BSTR cssSelector,
            /* [retval][out] */ IElement **elm) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectAll( 
            /* [in] */ BSTR cssSelector,
            /* [retval][out] */ IElements **ppEls) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_attribute( 
            BSTR name,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_attribute( 
            BSTR name,
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_styleAttribute( 
            BSTR name,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_styleAttribute( 
            BSTR name,
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowPopup( 
            long x,
            long y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HidePopup( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartTimer( 
            long milliseconds,
            long timerId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopTimer( 
            long timerId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PostControlEvent( 
            long eventType,
            /* [defaultvalue] */ long reason = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendControlEvent( 
            long eventType,
            /* [defaultvalue] */ long reason,
            /* [retval][out] */ VARIANT_BOOL *handled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Position( 
            /* [out] */ long *x,
            /* [out] */ long *y,
            ElementBoxType ofWhat,
            RelativeToType relTo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Dimension( 
            /* [out] */ long *w,
            /* [out] */ long *h,
            ElementBoxType ofWhat) = 0;
        
        virtual /* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE Call( 
            BSTR name,
            SAFEARRAY * params,
            /* [retval][out] */ VARIANT *rv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IElementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IElement * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IElement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IElement * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IElement * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IElement * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IElement * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IElement * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IElement * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IElement * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IElement * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Select )( 
            IElement * This,
            /* [in] */ BSTR cssSelector,
            /* [retval][out] */ IElement **elm);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectAll )( 
            IElement * This,
            /* [in] */ BSTR cssSelector,
            /* [retval][out] */ IElements **ppEls);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_attribute )( 
            IElement * This,
            BSTR name,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_attribute )( 
            IElement * This,
            BSTR name,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_styleAttribute )( 
            IElement * This,
            BSTR name,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_styleAttribute )( 
            IElement * This,
            BSTR name,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowPopup )( 
            IElement * This,
            long x,
            long y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HidePopup )( 
            IElement * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartTimer )( 
            IElement * This,
            long milliseconds,
            long timerId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopTimer )( 
            IElement * This,
            long timerId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PostControlEvent )( 
            IElement * This,
            long eventType,
            /* [defaultvalue] */ long reason);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendControlEvent )( 
            IElement * This,
            long eventType,
            /* [defaultvalue] */ long reason,
            /* [retval][out] */ VARIANT_BOOL *handled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Position )( 
            IElement * This,
            /* [out] */ long *x,
            /* [out] */ long *y,
            ElementBoxType ofWhat,
            RelativeToType relTo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Dimension )( 
            IElement * This,
            /* [out] */ long *w,
            /* [out] */ long *h,
            ElementBoxType ofWhat);
        
        /* [vararg][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Call )( 
            IElement * This,
            BSTR name,
            SAFEARRAY * params,
            /* [retval][out] */ VARIANT *rv);
        
        END_INTERFACE
    } IElementVtbl;

    interface IElement
    {
        CONST_VTBL struct IElementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IElement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IElement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IElement_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IElement_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IElement_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IElement_get_Tag(This,pVal)	\
    (This)->lpVtbl -> get_Tag(This,pVal)

#define IElement_get_Value(This,pVal)	\
    (This)->lpVtbl -> get_Value(This,pVal)

#define IElement_put_Value(This,newVal)	\
    (This)->lpVtbl -> put_Value(This,newVal)

#define IElement_Select(This,cssSelector,elm)	\
    (This)->lpVtbl -> Select(This,cssSelector,elm)

#define IElement_SelectAll(This,cssSelector,ppEls)	\
    (This)->lpVtbl -> SelectAll(This,cssSelector,ppEls)

#define IElement_get_attribute(This,name,pVal)	\
    (This)->lpVtbl -> get_attribute(This,name,pVal)

#define IElement_put_attribute(This,name,newVal)	\
    (This)->lpVtbl -> put_attribute(This,name,newVal)

#define IElement_get_styleAttribute(This,name,pVal)	\
    (This)->lpVtbl -> get_styleAttribute(This,name,pVal)

#define IElement_put_styleAttribute(This,name,newVal)	\
    (This)->lpVtbl -> put_styleAttribute(This,name,newVal)

#define IElement_ShowPopup(This,x,y)	\
    (This)->lpVtbl -> ShowPopup(This,x,y)

#define IElement_HidePopup(This)	\
    (This)->lpVtbl -> HidePopup(This)

#define IElement_StartTimer(This,milliseconds,timerId)	\
    (This)->lpVtbl -> StartTimer(This,milliseconds,timerId)

#define IElement_StopTimer(This,timerId)	\
    (This)->lpVtbl -> StopTimer(This,timerId)

#define IElement_PostControlEvent(This,eventType,reason)	\
    (This)->lpVtbl -> PostControlEvent(This,eventType,reason)

#define IElement_SendControlEvent(This,eventType,reason,handled)	\
    (This)->lpVtbl -> SendControlEvent(This,eventType,reason,handled)

#define IElement_Position(This,x,y,ofWhat,relTo)	\
    (This)->lpVtbl -> Position(This,x,y,ofWhat,relTo)

#define IElement_Dimension(This,w,h,ofWhat)	\
    (This)->lpVtbl -> Dimension(This,w,h,ofWhat)

#define IElement_Call(This,name,params,rv)	\
    (This)->lpVtbl -> Call(This,name,params,rv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IElement_get_Tag_Proxy( 
    IElement * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IElement_get_Tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IElement_get_Value_Proxy( 
    IElement * This,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IElement_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IElement_put_Value_Proxy( 
    IElement * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IElement_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IElement_Select_Proxy( 
    IElement * This,
    /* [in] */ BSTR cssSelector,
    /* [retval][out] */ IElement **elm);


void __RPC_STUB IElement_Select_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IElement_SelectAll_Proxy( 
    IElement * This,
    /* [in] */ BSTR cssSelector,
    /* [retval][out] */ IElements **ppEls);


void __RPC_STUB IElement_SelectAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IElement_get_attribute_Proxy( 
    IElement * This,
    BSTR name,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IElement_get_attribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IElement_put_attribute_Proxy( 
    IElement * This,
    BSTR name,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IElement_put_attribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IElement_get_styleAttribute_Proxy( 
    IElement * This,
    BSTR name,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IElement_get_styleAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IElement_put_styleAttribute_Proxy( 
    IElement * This,
    BSTR name,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IElement_put_styleAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IElement_ShowPopup_Proxy( 
    IElement * This,
    long x,
    long y);


void __RPC_STUB IElement_ShowPopup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IElement_HidePopup_Proxy( 
    IElement * This);


void __RPC_STUB IElement_HidePopup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IElement_StartTimer_Proxy( 
    IElement * This,
    long milliseconds,
    long timerId);


void __RPC_STUB IElement_StartTimer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IElement_StopTimer_Proxy( 
    IElement * This,
    long timerId);


void __RPC_STUB IElement_StopTimer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IElement_PostControlEvent_Proxy( 
    IElement * This,
    long eventType,
    /* [defaultvalue] */ long reason);


void __RPC_STUB IElement_PostControlEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IElement_SendControlEvent_Proxy( 
    IElement * This,
    long eventType,
    /* [defaultvalue] */ long reason,
    /* [retval][out] */ VARIANT_BOOL *handled);


void __RPC_STUB IElement_SendControlEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IElement_Position_Proxy( 
    IElement * This,
    /* [out] */ long *x,
    /* [out] */ long *y,
    ElementBoxType ofWhat,
    RelativeToType relTo);


void __RPC_STUB IElement_Position_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IElement_Dimension_Proxy( 
    IElement * This,
    /* [out] */ long *w,
    /* [out] */ long *h,
    ElementBoxType ofWhat);


void __RPC_STUB IElement_Dimension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [vararg][helpstring][id] */ HRESULT STDMETHODCALLTYPE IElement_Call_Proxy( 
    IElement * This,
    BSTR name,
    SAFEARRAY * params,
    /* [retval][out] */ VARIANT *rv);


void __RPC_STUB IElement_Call_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IElement_INTERFACE_DEFINED__ */


#ifndef __IEngine_INTERFACE_DEFINED__
#define __IEngine_INTERFACE_DEFINED__

/* interface IEngine */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F4032083-0553-4AC1-B08A-6A854DFD1153")
    IEngine : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoSize( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoSize( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Window( 
            /* [retval][out] */ long *phwnd) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TabStop( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TabStop( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderVisible( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderVisible( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR url) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadHtml( 
            /* [in] */ BSTR html,
            /* [defaultvalue][in] */ BSTR baseUrl = L"") = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Root( 
            /* [retval][out] */ IElement **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEngine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEngine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEngine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEngine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSize )( 
            IEngine * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSize )( 
            IEngine * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IEngine * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IEngine * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Window )( 
            IEngine * This,
            /* [retval][out] */ long *phwnd);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabStop )( 
            IEngine * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabStop )( 
            IEngine * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderVisible )( 
            IEngine * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderVisible )( 
            IEngine * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IEngine * This,
            /* [in] */ BSTR url);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadHtml )( 
            IEngine * This,
            /* [in] */ BSTR html,
            /* [defaultvalue][in] */ BSTR baseUrl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Root )( 
            IEngine * This,
            /* [retval][out] */ IElement **pVal);
        
        END_INTERFACE
    } IEngineVtbl;

    interface IEngine
    {
        CONST_VTBL struct IEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEngine_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEngine_put_AutoSize(This,vbool)	\
    (This)->lpVtbl -> put_AutoSize(This,vbool)

#define IEngine_get_AutoSize(This,pbool)	\
    (This)->lpVtbl -> get_AutoSize(This,pbool)

#define IEngine_put_Enabled(This,vbool)	\
    (This)->lpVtbl -> put_Enabled(This,vbool)

#define IEngine_get_Enabled(This,pbool)	\
    (This)->lpVtbl -> get_Enabled(This,pbool)

#define IEngine_get_Window(This,phwnd)	\
    (This)->lpVtbl -> get_Window(This,phwnd)

#define IEngine_put_TabStop(This,vbool)	\
    (This)->lpVtbl -> put_TabStop(This,vbool)

#define IEngine_get_TabStop(This,pbool)	\
    (This)->lpVtbl -> get_TabStop(This,pbool)

#define IEngine_put_BorderVisible(This,vbool)	\
    (This)->lpVtbl -> put_BorderVisible(This,vbool)

#define IEngine_get_BorderVisible(This,pbool)	\
    (This)->lpVtbl -> get_BorderVisible(This,pbool)

#define IEngine_Load(This,url)	\
    (This)->lpVtbl -> Load(This,url)

#define IEngine_LoadHtml(This,html,baseUrl)	\
    (This)->lpVtbl -> LoadHtml(This,html,baseUrl)

#define IEngine_get_Root(This,pVal)	\
    (This)->lpVtbl -> get_Root(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propput] */ HRESULT STDMETHODCALLTYPE IEngine_put_AutoSize_Proxy( 
    IEngine * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB IEngine_put_AutoSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IEngine_get_AutoSize_Proxy( 
    IEngine * This,
    /* [retval][out] */ VARIANT_BOOL *pbool);


void __RPC_STUB IEngine_get_AutoSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IEngine_put_Enabled_Proxy( 
    IEngine * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB IEngine_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IEngine_get_Enabled_Proxy( 
    IEngine * This,
    /* [retval][out] */ VARIANT_BOOL *pbool);


void __RPC_STUB IEngine_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IEngine_get_Window_Proxy( 
    IEngine * This,
    /* [retval][out] */ long *phwnd);


void __RPC_STUB IEngine_get_Window_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IEngine_put_TabStop_Proxy( 
    IEngine * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB IEngine_put_TabStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IEngine_get_TabStop_Proxy( 
    IEngine * This,
    /* [retval][out] */ VARIANT_BOOL *pbool);


void __RPC_STUB IEngine_get_TabStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IEngine_put_BorderVisible_Proxy( 
    IEngine * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB IEngine_put_BorderVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IEngine_get_BorderVisible_Proxy( 
    IEngine * This,
    /* [retval][out] */ VARIANT_BOOL *pbool);


void __RPC_STUB IEngine_get_BorderVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEngine_Load_Proxy( 
    IEngine * This,
    /* [in] */ BSTR url);


void __RPC_STUB IEngine_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEngine_LoadHtml_Proxy( 
    IEngine * This,
    /* [in] */ BSTR html,
    /* [defaultvalue][in] */ BSTR baseUrl);


void __RPC_STUB IEngine_LoadHtml_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IEngine_get_Root_Proxy( 
    IEngine * This,
    /* [retval][out] */ IElement **pVal);


void __RPC_STUB IEngine_get_Root_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEngine_INTERFACE_DEFINED__ */



#ifndef __HTMLayout_LIBRARY_DEFINED__
#define __HTMLayout_LIBRARY_DEFINED__

/* library HTMLayout */
/* [helpstring][version][uuid] */ 



enum PhaseMask
    {	MASK_BUBBLING	= 0,
	MASK_SINKING	= 0x8000,
	MASK_HANDLED	= 0x10000
    } ;

enum MouseEvents
    {	ME_MOUSE_ENTER	= 0,
	ME_MOUSE_LEAVE	= 1,
	ME_MOUSE_MOVE	= 2,
	ME_MOUSE_UP	= 3,
	ME_MOUSE_DOWN	= 4,
	ME_MOUSE_DCLICK	= 5,
	ME_MOUSE_WHEEL	= 6,
	ME_MOUSE_TICK	= 7,
	ME_MOUSE_IDLE	= 8,
	ME_DROP	= 9,
	ME_DRAG_ENTER	= 0xa,
	ME_DRAG_LEAVE	= 0xb,
	ME_DRAGGING	= 0x100
    } ;

enum BehaviorEvents
    {	BE_BUTTON_CLICK	= 0,
	BE_BUTTON_PRESS	= 1,
	BE_BUTTON_STATE_CHANGED	= 2,
	BE_EDIT_VALUE_CHANGING	= 3,
	BE_EDIT_VALUE_CHANGED	= 4,
	BE_SELECT_SELECTION_CHANGED	= 5,
	BE_SELECT_STATE_CHANGED	= 6,
	BE_POPUP_REQUEST	= 7,
	BE_POPUP_READY	= 8,
	BE_POPUP_DISMISSED	= 9,
	BE_MENU_ITEM_ACTIVE	= 0xa,
	BE_MENU_ITEM_CLICK	= 0xb,
	BE_CONTEXT_MENU_SETUP	= 0xf,
	BE_CONTEXT_MENU_REQUEST	= 0x10,
	BE_VISIUAL_STATUS_CHANGED	= 0x11,
	BE_HYPERLINK_CLICK	= 0x80,
	BE_TABLE_HEADER_CLICK	= BE_HYPERLINK_CLICK + 1,
	BE_TABLE_ROW_CLICK	= BE_TABLE_HEADER_CLICK + 1,
	BE_TABLE_ROW_DBL_CLICK	= BE_TABLE_ROW_CLICK + 1,
	BE_ELEMENT_COLLAPSED	= 0x90,
	BE_ELEMENT_EXPANDED	= BE_ELEMENT_COLLAPSED + 1,
	BE_ACTIVATE_CHILD	= BE_ELEMENT_EXPANDED + 1,
	BE_DO_SWITCH_TAB	= BE_ACTIVATE_CHILD,
	BE_INIT_DATA_VIEW	= BE_DO_SWITCH_TAB + 1,
	BE_ROWS_DATA_REQUEST	= BE_INIT_DATA_VIEW + 1,
	BE_UI_STATE_CHANGED	= BE_ROWS_DATA_REQUEST + 1,
	BE_FORM_SUBMIT	= BE_UI_STATE_CHANGED + 1,
	BE_FORM_RESET	= BE_FORM_SUBMIT + 1,
	BE_DOCUMENT_COMPLETE	= BE_FORM_RESET + 1,
	BE_HISTORY_PUSH	= BE_DOCUMENT_COMPLETE + 1,
	BE_HISTORY_DROP	= BE_HISTORY_PUSH + 1,
	BE_HISTORY_PRIOR	= BE_HISTORY_DROP + 1,
	BE_HISTORY_NEXT	= BE_HISTORY_PRIOR + 1,
	BE_HISTORY_STATE_CHANGED	= BE_HISTORY_NEXT + 1,
	BE_FIRST_APPLICATION_EVENT_CODE	= 0x100
    } ;

EXTERN_C const IID LIBID_HTMLayout;

#ifndef ___IEngineEvents_DISPINTERFACE_DEFINED__
#define ___IEngineEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IEngineEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IEngineEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A9CCCA1B-4E1B-4AE0-8004-DD8184BA8FDA")
    _IEngineEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IEngineEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IEngineEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IEngineEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IEngineEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IEngineEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IEngineEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IEngineEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IEngineEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IEngineEventsVtbl;

    interface _IEngineEvents
    {
        CONST_VTBL struct _IEngineEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IEngineEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IEngineEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IEngineEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IEngineEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IEngineEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IEngineEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IEngineEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IEngineEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Engine;

#ifdef __cplusplus

class DECLSPEC_UUID("58BD87DF-8687-4CEC-9710-A4CEEE7D0F7D")
Engine;
#endif

#ifndef ___IElementEvents_DISPINTERFACE_DEFINED__
#define ___IElementEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IElementEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IElementEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A6F09FE1-EB03-4679-B972-2C4EF9596751")
    _IElementEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IElementEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IElementEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IElementEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IElementEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IElementEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IElementEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IElementEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IElementEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IElementEventsVtbl;

    interface _IElementEvents
    {
        CONST_VTBL struct _IElementEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IElementEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IElementEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IElementEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IElementEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IElementEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IElementEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IElementEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IElementEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Element;

#ifdef __cplusplus

class DECLSPEC_UUID("DE1EBB05-E806-4434-A7C3-494D28CFFE24")
Element;
#endif

#ifndef __IElements_INTERFACE_DEFINED__
#define __IElements_INTERFACE_DEFINED__

/* interface IElements */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IElements;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F8745FCD-98FE-4B6F-96CA-F0B969BBFD31")
    IElements : public IDispatch
    {
    public:
        virtual /* [restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppEnum) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [defaultcollelem][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long index,
            /* [retval][out] */ IElement **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IElementsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IElements * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IElements * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IElements * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IElements * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IElements * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IElements * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IElements * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IElements * This,
            /* [retval][out] */ IUnknown **ppEnum);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IElements * This,
            /* [retval][out] */ long *pVal);
        
        /* [defaultcollelem][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IElements * This,
            /* [in] */ long index,
            /* [retval][out] */ IElement **pVal);
        
        END_INTERFACE
    } IElementsVtbl;

    interface IElements
    {
        CONST_VTBL struct IElementsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IElements_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IElements_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IElements_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IElements_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IElements_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IElements_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IElements_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IElements_get__NewEnum(This,ppEnum)	\
    (This)->lpVtbl -> get__NewEnum(This,ppEnum)

#define IElements_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IElements_get_Item(This,index,pVal)	\
    (This)->lpVtbl -> get_Item(This,index,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [restricted][id][propget] */ HRESULT STDMETHODCALLTYPE IElements_get__NewEnum_Proxy( 
    IElements * This,
    /* [retval][out] */ IUnknown **ppEnum);


void __RPC_STUB IElements_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IElements_get_Count_Proxy( 
    IElements * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IElements_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [defaultcollelem][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IElements_get_Item_Proxy( 
    IElements * This,
    /* [in] */ long index,
    /* [retval][out] */ IElement **pVal);


void __RPC_STUB IElements_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IElements_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Elements;

#ifdef __cplusplus

class DECLSPEC_UUID("BB9B507A-1F92-4C43-A2ED-A0B0570200BC")
Elements;
#endif
#endif /* __HTMLayout_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


