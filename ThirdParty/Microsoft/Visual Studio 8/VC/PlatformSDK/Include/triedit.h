/* Microsoft Corporation Copyright 1999 */
/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.03.0110 */
/* at Tue Jun 30 09:29:52 1998
 */
/* Compiler settings for triedit.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
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

#ifndef __triedit_h__
#define __triedit_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITriEditDocument_FWD_DEFINED__
#define __ITriEditDocument_FWD_DEFINED__
typedef interface ITriEditDocument ITriEditDocument;
#endif 	/* __ITriEditDocument_FWD_DEFINED__ */


#ifndef __TriEditDocument_FWD_DEFINED__
#define __TriEditDocument_FWD_DEFINED__

#ifdef __cplusplus
typedef class TriEditDocument TriEditDocument;
#else
typedef struct TriEditDocument TriEditDocument;
#endif /* __cplusplus */

#endif 	/* __TriEditDocument_FWD_DEFINED__ */


#ifndef __IDocHostDragDropHandler_FWD_DEFINED__
#define __IDocHostDragDropHandler_FWD_DEFINED__
typedef interface IDocHostDragDropHandler IDocHostDragDropHandler;
#endif 	/* __IDocHostDragDropHandler_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_triedit_0000
 * at Tue Jun 30 09:29:52 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [local] */ 


// dwFlags to indicate what needs to be filtered
#define dwFilterDefaults		0x00000000
#define dwFilterNone			0x00000001
#define dwFilterDTCs			0x00000002
#define dwFilterDTCsWithoutMetaTags	0x00000004
#define dwFilterServerSideScripts	0x00000008
#define dwPreserveSourceCode		0x00000010 // whitespace & attrib order
#define dwFilterSourceCode		0x00000020 // set by control for FilterSourceCode Method
#define dwFilterMultiByteStream	0x10000000
#define dwFilterUsePstmNew           0x20000000

#define E_FILTER_FRAMESET		0x80100001
#define E_FILTER_SERVERSCRIPT	0x80100002
#define E_FILTER_MULTIPLETAGS	0x80100004
#define E_FILTER_SCRIPTLISTING	0x80100008
#define E_FILTER_SCRIPTLABEL		0x80100010
#define E_FILTER_SCRIPTTEXTAREA	0x80100020
#define E_FILTER_SCRIPTSELECT	0x80100040


extern RPC_IF_HANDLE __MIDL_itf_triedit_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_triedit_0000_v0_0_s_ifspec;

#ifndef __ITriEditDocument_INTERFACE_DEFINED__
#define __ITriEditDocument_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITriEditDocument
 * at Tue Jun 30 09:29:52 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_ITriEditDocument;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("438DA5DF-F171-11D0-984E-0000F80270F8")
    ITriEditDocument : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FilterIn( 
            /* [in] */ IUnknown __RPC_FAR *pStmOld,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppStmNew,
            /* [in] */ DWORD dwFlags,
            /* [in] */ BSTR bstrBaseURL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FilterOut( 
            /* [in] */ IUnknown __RPC_FAR *pStmOld,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppStmNew,
            /* [in] */ DWORD dwFlags,
            /* [in] */ BSTR bstrBaseURL) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITriEditDocumentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITriEditDocument __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITriEditDocument __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITriEditDocument __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ITriEditDocument __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ITriEditDocument __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ITriEditDocument __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ITriEditDocument __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FilterIn )( 
            ITriEditDocument __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pStmOld,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppStmNew,
            /* [in] */ DWORD dwFlags,
            /* [in] */ BSTR bstrBaseURL);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FilterOut )( 
            ITriEditDocument __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pStmOld,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppStmNew,
            /* [in] */ DWORD dwFlags,
            /* [in] */ BSTR bstrBaseURL);
        
        END_INTERFACE
    } ITriEditDocumentVtbl;

    interface ITriEditDocument
    {
        CONST_VTBL struct ITriEditDocumentVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITriEditDocument_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITriEditDocument_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITriEditDocument_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITriEditDocument_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITriEditDocument_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITriEditDocument_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITriEditDocument_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITriEditDocument_FilterIn(This,pStmOld,ppStmNew,dwFlags,bstrBaseURL)	\
    (This)->lpVtbl -> FilterIn(This,pStmOld,ppStmNew,dwFlags,bstrBaseURL)

#define ITriEditDocument_FilterOut(This,pStmOld,ppStmNew,dwFlags,bstrBaseURL)	\
    (This)->lpVtbl -> FilterOut(This,pStmOld,ppStmNew,dwFlags,bstrBaseURL)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITriEditDocument_FilterIn_Proxy( 
    ITriEditDocument __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pStmOld,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppStmNew,
    /* [in] */ DWORD dwFlags,
    /* [in] */ BSTR bstrBaseURL);


void __RPC_STUB ITriEditDocument_FilterIn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITriEditDocument_FilterOut_Proxy( 
    ITriEditDocument __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pStmOld,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppStmNew,
    /* [in] */ DWORD dwFlags,
    /* [in] */ BSTR bstrBaseURL);


void __RPC_STUB ITriEditDocument_FilterOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITriEditDocument_INTERFACE_DEFINED__ */



#ifndef __TRIEDITLib_LIBRARY_DEFINED__
#define __TRIEDITLib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: TRIEDITLib
 * at Tue Jun 30 09:29:52 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_TRIEDITLib;

EXTERN_C const CLSID CLSID_TriEditDocument;

#ifdef __cplusplus

class DECLSPEC_UUID("438DA5E0-F171-11D0-984E-0000F80270F8")
TriEditDocument;
#endif
#endif /* __TRIEDITLib_LIBRARY_DEFINED__ */

#ifndef __IDocHostDragDropHandler_INTERFACE_DEFINED__
#define __IDocHostDragDropHandler_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDocHostDragDropHandler
 * at Tue Jun 30 09:29:52 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [local][unique][helpstring][uuid][object] */ 



EXTERN_C const IID IID_IDocHostDragDropHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25188F40-D959-11d1-989F-0000F80270F8")
    IDocHostDragDropHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DrawDragFeedback( 
            /* [out][in] */ RECT __RPC_FAR *pRect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDocHostDragDropHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDocHostDragDropHandler __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDocHostDragDropHandler __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDocHostDragDropHandler __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawDragFeedback )( 
            IDocHostDragDropHandler __RPC_FAR * This,
            /* [out][in] */ RECT __RPC_FAR *pRect);
        
        END_INTERFACE
    } IDocHostDragDropHandlerVtbl;

    interface IDocHostDragDropHandler
    {
        CONST_VTBL struct IDocHostDragDropHandlerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDocHostDragDropHandler_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDocHostDragDropHandler_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDocHostDragDropHandler_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDocHostDragDropHandler_DrawDragFeedback(This,pRect)	\
    (This)->lpVtbl -> DrawDragFeedback(This,pRect)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDocHostDragDropHandler_DrawDragFeedback_Proxy( 
    IDocHostDragDropHandler __RPC_FAR * This,
    /* [out][in] */ RECT __RPC_FAR *pRect);


void __RPC_STUB IDocHostDragDropHandler_DrawDragFeedback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDocHostDragDropHandler_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
