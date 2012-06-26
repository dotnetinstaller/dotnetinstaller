
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0268 */
/* at Wed Jul 07 15:53:18 1999
 */
/* Compiler settings for iis.odl:
    Os (OptLev=s), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
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

#ifndef __iiis_h__
#define __iiis_h__

/* Forward Declarations */ 

#ifndef __IISMimeType_FWD_DEFINED__
#define __IISMimeType_FWD_DEFINED__
typedef interface IISMimeType IISMimeType;
#endif 	/* __IISMimeType_FWD_DEFINED__ */


#ifndef __MimeMap_FWD_DEFINED__
#define __MimeMap_FWD_DEFINED__

#ifdef __cplusplus
typedef class MimeMap MimeMap;
#else
typedef struct MimeMap MimeMap;
#endif /* __cplusplus */

#endif 	/* __MimeMap_FWD_DEFINED__ */


#ifndef __IISIPSecurity_FWD_DEFINED__
#define __IISIPSecurity_FWD_DEFINED__
typedef interface IISIPSecurity IISIPSecurity;
#endif 	/* __IISIPSecurity_FWD_DEFINED__ */


#ifndef __IPSecurity_FWD_DEFINED__
#define __IPSecurity_FWD_DEFINED__

#ifdef __cplusplus
typedef class IPSecurity IPSecurity;
#else
typedef struct IPSecurity IPSecurity;
#endif /* __cplusplus */

#endif 	/* __IPSecurity_FWD_DEFINED__ */


#ifndef __IISNamespace_FWD_DEFINED__
#define __IISNamespace_FWD_DEFINED__

#ifdef __cplusplus
typedef class IISNamespace IISNamespace;
#else
typedef struct IISNamespace IISNamespace;
#endif /* __cplusplus */

#endif 	/* __IISNamespace_FWD_DEFINED__ */


#ifndef __IISProvider_FWD_DEFINED__
#define __IISProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class IISProvider IISProvider;
#else
typedef struct IISProvider IISProvider;
#endif /* __cplusplus */

#endif 	/* __IISProvider_FWD_DEFINED__ */


#ifndef __IISBaseObject_FWD_DEFINED__
#define __IISBaseObject_FWD_DEFINED__
typedef interface IISBaseObject IISBaseObject;
#endif 	/* __IISBaseObject_FWD_DEFINED__ */


#ifndef __IISSchemaObject_FWD_DEFINED__
#define __IISSchemaObject_FWD_DEFINED__
typedef interface IISSchemaObject IISSchemaObject;
#endif 	/* __IISSchemaObject_FWD_DEFINED__ */


#ifndef __IISPropertyAttribute_FWD_DEFINED__
#define __IISPropertyAttribute_FWD_DEFINED__
typedef interface IISPropertyAttribute IISPropertyAttribute;
#endif 	/* __IISPropertyAttribute_FWD_DEFINED__ */


#ifndef __PropertyAttribute_FWD_DEFINED__
#define __PropertyAttribute_FWD_DEFINED__

#ifdef __cplusplus
typedef class PropertyAttribute PropertyAttribute;
#else
typedef struct PropertyAttribute PropertyAttribute;
#endif /* __cplusplus */

#endif 	/* __PropertyAttribute_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_iis_0000 */
/* [local] */ 

DEFINE_GUID(LIBID_IISOle,0x49D704A0L,0x89F7,0x11D0,0x85,0x27,0x00,0xC0,0x4F,0xD8,0xD5,0x03);
DEFINE_GUID(IID_IISBaseObject, 0x4b42e390, 0xe96, 0x11d1, 0x9c, 0x3f, 0x0, 0xa0,0xc9, 0x22, 0xe7, 0x3);


extern RPC_IF_HANDLE __MIDL_itf_iis_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_iis_0000_v0_0_s_ifspec;


#ifndef __IISOle_LIBRARY_DEFINED__
#define __IISOle_LIBRARY_DEFINED__

/* library IISOle */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_IISOle;

#ifndef __IISMimeType_INTERFACE_DEFINED__
#define __IISMimeType_INTERFACE_DEFINED__

/* interface IISMimeType */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IISMimeType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9036B027-A780-11d0-9B3D-0080C710EF95")
    IISMimeType : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MimeType( 
            /* [retval][out] */ BSTR __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MimeType( 
            /* [in] */ BSTR bstrMimeType) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Extension( 
            /* [retval][out] */ BSTR __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Extension( 
            /* [in] */ BSTR bstrExtension) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IISMimeTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IISMimeType __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IISMimeType __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IISMimeType __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IISMimeType __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IISMimeType __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IISMimeType __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IISMimeType __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MimeType )( 
            IISMimeType __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MimeType )( 
            IISMimeType __RPC_FAR * This,
            /* [in] */ BSTR bstrMimeType);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Extension )( 
            IISMimeType __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Extension )( 
            IISMimeType __RPC_FAR * This,
            /* [in] */ BSTR bstrExtension);
        
        END_INTERFACE
    } IISMimeTypeVtbl;

    interface IISMimeType
    {
        CONST_VTBL struct IISMimeTypeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IISMimeType_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IISMimeType_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IISMimeType_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IISMimeType_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IISMimeType_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IISMimeType_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IISMimeType_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IISMimeType_get_MimeType(This,retval)	\
    (This)->lpVtbl -> get_MimeType(This,retval)

#define IISMimeType_put_MimeType(This,bstrMimeType)	\
    (This)->lpVtbl -> put_MimeType(This,bstrMimeType)

#define IISMimeType_get_Extension(This,retval)	\
    (This)->lpVtbl -> get_Extension(This,retval)

#define IISMimeType_put_Extension(This,bstrExtension)	\
    (This)->lpVtbl -> put_Extension(This,bstrExtension)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISMimeType_get_MimeType_Proxy( 
    IISMimeType __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *retval);


void __RPC_STUB IISMimeType_get_MimeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISMimeType_put_MimeType_Proxy( 
    IISMimeType __RPC_FAR * This,
    /* [in] */ BSTR bstrMimeType);


void __RPC_STUB IISMimeType_put_MimeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISMimeType_get_Extension_Proxy( 
    IISMimeType __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *retval);


void __RPC_STUB IISMimeType_get_Extension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISMimeType_put_Extension_Proxy( 
    IISMimeType __RPC_FAR * This,
    /* [in] */ BSTR bstrExtension);


void __RPC_STUB IISMimeType_put_Extension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IISMimeType_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MimeMap;

#ifdef __cplusplus

class DECLSPEC_UUID("9036B028-A780-11d0-9B3D-0080C710EF95")
MimeMap;
#endif

#ifndef __IISIPSecurity_INTERFACE_DEFINED__
#define __IISIPSecurity_INTERFACE_DEFINED__

/* interface IISIPSecurity */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IISIPSecurity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3287521-BBA3-11d0-9BDC-00A0C922E703")
    IISIPSecurity : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_IPDeny( 
            /* [retval][out] */ VARIANT __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_IPDeny( 
            /* [in] */ VARIANT vIPDeny) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_IPGrant( 
            /* [retval][out] */ VARIANT __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_IPGrant( 
            /* [in] */ VARIANT vIPGrant) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainDeny( 
            /* [retval][out] */ VARIANT __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DomainDeny( 
            /* [in] */ VARIANT vDomainDeny) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainGrant( 
            /* [retval][out] */ VARIANT __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DomainGrant( 
            /* [in] */ VARIANT vDomainGrant) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_GrantByDefault( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_GrantByDefault( 
            /* [in] */ VARIANT_BOOL fGrantByDefault) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IISIPSecurityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IISIPSecurity __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IISIPSecurity __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IISIPSecurity __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IISIPSecurity __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IISIPSecurity __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IISIPSecurity __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IISIPSecurity __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IPDeny )( 
            IISIPSecurity __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IPDeny )( 
            IISIPSecurity __RPC_FAR * This,
            /* [in] */ VARIANT vIPDeny);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IPGrant )( 
            IISIPSecurity __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IPGrant )( 
            IISIPSecurity __RPC_FAR * This,
            /* [in] */ VARIANT vIPGrant);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainDeny )( 
            IISIPSecurity __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DomainDeny )( 
            IISIPSecurity __RPC_FAR * This,
            /* [in] */ VARIANT vDomainDeny);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainGrant )( 
            IISIPSecurity __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DomainGrant )( 
            IISIPSecurity __RPC_FAR * This,
            /* [in] */ VARIANT vDomainGrant);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GrantByDefault )( 
            IISIPSecurity __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GrantByDefault )( 
            IISIPSecurity __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL fGrantByDefault);
        
        END_INTERFACE
    } IISIPSecurityVtbl;

    interface IISIPSecurity
    {
        CONST_VTBL struct IISIPSecurityVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IISIPSecurity_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IISIPSecurity_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IISIPSecurity_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IISIPSecurity_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IISIPSecurity_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IISIPSecurity_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IISIPSecurity_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IISIPSecurity_get_IPDeny(This,retval)	\
    (This)->lpVtbl -> get_IPDeny(This,retval)

#define IISIPSecurity_put_IPDeny(This,vIPDeny)	\
    (This)->lpVtbl -> put_IPDeny(This,vIPDeny)

#define IISIPSecurity_get_IPGrant(This,retval)	\
    (This)->lpVtbl -> get_IPGrant(This,retval)

#define IISIPSecurity_put_IPGrant(This,vIPGrant)	\
    (This)->lpVtbl -> put_IPGrant(This,vIPGrant)

#define IISIPSecurity_get_DomainDeny(This,retval)	\
    (This)->lpVtbl -> get_DomainDeny(This,retval)

#define IISIPSecurity_put_DomainDeny(This,vDomainDeny)	\
    (This)->lpVtbl -> put_DomainDeny(This,vDomainDeny)

#define IISIPSecurity_get_DomainGrant(This,retval)	\
    (This)->lpVtbl -> get_DomainGrant(This,retval)

#define IISIPSecurity_put_DomainGrant(This,vDomainGrant)	\
    (This)->lpVtbl -> put_DomainGrant(This,vDomainGrant)

#define IISIPSecurity_get_GrantByDefault(This,retval)	\
    (This)->lpVtbl -> get_GrantByDefault(This,retval)

#define IISIPSecurity_put_GrantByDefault(This,fGrantByDefault)	\
    (This)->lpVtbl -> put_GrantByDefault(This,fGrantByDefault)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISIPSecurity_get_IPDeny_Proxy( 
    IISIPSecurity __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *retval);


void __RPC_STUB IISIPSecurity_get_IPDeny_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISIPSecurity_put_IPDeny_Proxy( 
    IISIPSecurity __RPC_FAR * This,
    /* [in] */ VARIANT vIPDeny);


void __RPC_STUB IISIPSecurity_put_IPDeny_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISIPSecurity_get_IPGrant_Proxy( 
    IISIPSecurity __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *retval);


void __RPC_STUB IISIPSecurity_get_IPGrant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISIPSecurity_put_IPGrant_Proxy( 
    IISIPSecurity __RPC_FAR * This,
    /* [in] */ VARIANT vIPGrant);


void __RPC_STUB IISIPSecurity_put_IPGrant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISIPSecurity_get_DomainDeny_Proxy( 
    IISIPSecurity __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *retval);


void __RPC_STUB IISIPSecurity_get_DomainDeny_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISIPSecurity_put_DomainDeny_Proxy( 
    IISIPSecurity __RPC_FAR * This,
    /* [in] */ VARIANT vDomainDeny);


void __RPC_STUB IISIPSecurity_put_DomainDeny_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISIPSecurity_get_DomainGrant_Proxy( 
    IISIPSecurity __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *retval);


void __RPC_STUB IISIPSecurity_get_DomainGrant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISIPSecurity_put_DomainGrant_Proxy( 
    IISIPSecurity __RPC_FAR * This,
    /* [in] */ VARIANT vDomainGrant);


void __RPC_STUB IISIPSecurity_put_DomainGrant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISIPSecurity_get_GrantByDefault_Proxy( 
    IISIPSecurity __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);


void __RPC_STUB IISIPSecurity_get_GrantByDefault_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISIPSecurity_put_GrantByDefault_Proxy( 
    IISIPSecurity __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL fGrantByDefault);


void __RPC_STUB IISIPSecurity_put_GrantByDefault_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IISIPSecurity_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_IPSecurity;

#ifdef __cplusplus

class DECLSPEC_UUID("F3287520-BBA3-11d0-9BDC-00A0C922E703")
IPSecurity;
#endif

EXTERN_C const CLSID CLSID_IISNamespace;

#ifdef __cplusplus

class DECLSPEC_UUID("d6bfa35e-89f2-11d0-8527-00c04fd8d503")
IISNamespace;
#endif

EXTERN_C const CLSID CLSID_IISProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("d88966de-89f2-11d0-8527-00c04fd8d503")
IISProvider;
#endif

#ifndef __IISBaseObject_INTERFACE_DEFINED__
#define __IISBaseObject_INTERFACE_DEFINED__

/* interface IISBaseObject */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IISBaseObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4B42E390-0E96-11d1-9C3F-00A0C922E703")
    IISBaseObject : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetDataPaths( 
            /* [in] */ BSTR bstrName,
            /* [in] */ LONG lnAttribute,
            /* [retval][out] */ VARIANT __RPC_FAR *pvPaths) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetPropertyAttribObj( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IISBaseObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IISBaseObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IISBaseObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IISBaseObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IISBaseObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IISBaseObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IISBaseObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IISBaseObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDataPaths )( 
            IISBaseObject __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ LONG lnAttribute,
            /* [retval][out] */ VARIANT __RPC_FAR *pvPaths);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropertyAttribObj )( 
            IISBaseObject __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppObject);
        
        END_INTERFACE
    } IISBaseObjectVtbl;

    interface IISBaseObject
    {
        CONST_VTBL struct IISBaseObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IISBaseObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IISBaseObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IISBaseObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IISBaseObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IISBaseObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IISBaseObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IISBaseObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IISBaseObject_GetDataPaths(This,bstrName,lnAttribute,pvPaths)	\
    (This)->lpVtbl -> GetDataPaths(This,bstrName,lnAttribute,pvPaths)

#define IISBaseObject_GetPropertyAttribObj(This,bstrName,ppObject)	\
    (This)->lpVtbl -> GetPropertyAttribObj(This,bstrName,ppObject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IISBaseObject_GetDataPaths_Proxy( 
    IISBaseObject __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [in] */ LONG lnAttribute,
    /* [retval][out] */ VARIANT __RPC_FAR *pvPaths);


void __RPC_STUB IISBaseObject_GetDataPaths_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IISBaseObject_GetPropertyAttribObj_Proxy( 
    IISBaseObject __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppObject);


void __RPC_STUB IISBaseObject_GetPropertyAttribObj_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IISBaseObject_INTERFACE_DEFINED__ */


#ifndef __IISSchemaObject_INTERFACE_DEFINED__
#define __IISSchemaObject_INTERFACE_DEFINED__

/* interface IISSchemaObject */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IISSchemaObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B6865A9C-3F64-11D2-A600-00A0C922E703")
    IISSchemaObject : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSchemaPropertyAttributes( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppObject) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PutSchemaPropertyAttributes( 
            /* [in] */ IDispatch __RPC_FAR *pObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IISSchemaObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IISSchemaObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IISSchemaObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IISSchemaObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IISSchemaObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IISSchemaObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IISSchemaObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IISSchemaObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSchemaPropertyAttributes )( 
            IISSchemaObject __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppObject);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PutSchemaPropertyAttributes )( 
            IISSchemaObject __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pObject);
        
        END_INTERFACE
    } IISSchemaObjectVtbl;

    interface IISSchemaObject
    {
        CONST_VTBL struct IISSchemaObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IISSchemaObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IISSchemaObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IISSchemaObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IISSchemaObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IISSchemaObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IISSchemaObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IISSchemaObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IISSchemaObject_GetSchemaPropertyAttributes(This,bstrName,ppObject)	\
    (This)->lpVtbl -> GetSchemaPropertyAttributes(This,bstrName,ppObject)

#define IISSchemaObject_PutSchemaPropertyAttributes(This,pObject)	\
    (This)->lpVtbl -> PutSchemaPropertyAttributes(This,pObject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IISSchemaObject_GetSchemaPropertyAttributes_Proxy( 
    IISSchemaObject __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppObject);


void __RPC_STUB IISSchemaObject_GetSchemaPropertyAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IISSchemaObject_PutSchemaPropertyAttributes_Proxy( 
    IISSchemaObject __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pObject);


void __RPC_STUB IISSchemaObject_PutSchemaPropertyAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IISSchemaObject_INTERFACE_DEFINED__ */


#ifndef __IISPropertyAttribute_INTERFACE_DEFINED__
#define __IISPropertyAttribute_INTERFACE_DEFINED__

/* interface IISPropertyAttribute */
/* [object][dual][oleautomation][uuid] */ 


EXTERN_C const IID IID_IISPropertyAttribute;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("50E21930-A247-11D1-B79C-00A0C922E703")
    IISPropertyAttribute : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PropName( 
            /* [retval][out] */ BSTR __RPC_FAR *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MetaId( 
            /* [retval][out] */ long __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MetaId( 
            /* [in] */ long lnMetaId) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_UserType( 
            /* [retval][out] */ long __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_UserType( 
            /* [in] */ long lnUserType) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AllAttributes( 
            /* [retval][out] */ long __RPC_FAR *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Inherit( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Inherit( 
            /* [in] */ VARIANT_BOOL fInherit) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Secure( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Secure( 
            /* [in] */ VARIANT_BOOL fSecure) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Reference( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Reference( 
            /* [in] */ VARIANT_BOOL fReference) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Volatile( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Volatile( 
            /* [in] */ VARIANT_BOOL fVolatile) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Isinherit( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Default( 
            /* [retval][out] */ VARIANT __RPC_FAR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Default( 
            /* [in] */ VARIANT vDefault) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IISPropertyAttributeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IISPropertyAttribute __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IISPropertyAttribute __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PropName )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MetaId )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MetaId )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [in] */ long lnMetaId);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UserType )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UserType )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [in] */ long lnUserType);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AllAttributes )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Inherit )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Inherit )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL fInherit);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Secure )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Secure )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL fSecure);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Reference )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Reference )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL fReference);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Volatile )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Volatile )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL fVolatile);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Isinherit )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Default )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Default )( 
            IISPropertyAttribute __RPC_FAR * This,
            /* [in] */ VARIANT vDefault);
        
        END_INTERFACE
    } IISPropertyAttributeVtbl;

    interface IISPropertyAttribute
    {
        CONST_VTBL struct IISPropertyAttributeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IISPropertyAttribute_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IISPropertyAttribute_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IISPropertyAttribute_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IISPropertyAttribute_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IISPropertyAttribute_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IISPropertyAttribute_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IISPropertyAttribute_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IISPropertyAttribute_get_PropName(This,retval)	\
    (This)->lpVtbl -> get_PropName(This,retval)

#define IISPropertyAttribute_get_MetaId(This,retval)	\
    (This)->lpVtbl -> get_MetaId(This,retval)

#define IISPropertyAttribute_put_MetaId(This,lnMetaId)	\
    (This)->lpVtbl -> put_MetaId(This,lnMetaId)

#define IISPropertyAttribute_get_UserType(This,retval)	\
    (This)->lpVtbl -> get_UserType(This,retval)

#define IISPropertyAttribute_put_UserType(This,lnUserType)	\
    (This)->lpVtbl -> put_UserType(This,lnUserType)

#define IISPropertyAttribute_get_AllAttributes(This,retval)	\
    (This)->lpVtbl -> get_AllAttributes(This,retval)

#define IISPropertyAttribute_get_Inherit(This,retval)	\
    (This)->lpVtbl -> get_Inherit(This,retval)

#define IISPropertyAttribute_put_Inherit(This,fInherit)	\
    (This)->lpVtbl -> put_Inherit(This,fInherit)

#define IISPropertyAttribute_get_Secure(This,retval)	\
    (This)->lpVtbl -> get_Secure(This,retval)

#define IISPropertyAttribute_put_Secure(This,fSecure)	\
    (This)->lpVtbl -> put_Secure(This,fSecure)

#define IISPropertyAttribute_get_Reference(This,retval)	\
    (This)->lpVtbl -> get_Reference(This,retval)

#define IISPropertyAttribute_put_Reference(This,fReference)	\
    (This)->lpVtbl -> put_Reference(This,fReference)

#define IISPropertyAttribute_get_Volatile(This,retval)	\
    (This)->lpVtbl -> get_Volatile(This,retval)

#define IISPropertyAttribute_put_Volatile(This,fVolatile)	\
    (This)->lpVtbl -> put_Volatile(This,fVolatile)

#define IISPropertyAttribute_get_Isinherit(This,retval)	\
    (This)->lpVtbl -> get_Isinherit(This,retval)

#define IISPropertyAttribute_get_Default(This,retval)	\
    (This)->lpVtbl -> get_Default(This,retval)

#define IISPropertyAttribute_put_Default(This,vDefault)	\
    (This)->lpVtbl -> put_Default(This,vDefault)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_get_PropName_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *retval);


void __RPC_STUB IISPropertyAttribute_get_PropName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_get_MetaId_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *retval);


void __RPC_STUB IISPropertyAttribute_get_MetaId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_put_MetaId_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [in] */ long lnMetaId);


void __RPC_STUB IISPropertyAttribute_put_MetaId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_get_UserType_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *retval);


void __RPC_STUB IISPropertyAttribute_get_UserType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_put_UserType_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [in] */ long lnUserType);


void __RPC_STUB IISPropertyAttribute_put_UserType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_get_AllAttributes_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *retval);


void __RPC_STUB IISPropertyAttribute_get_AllAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_get_Inherit_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);


void __RPC_STUB IISPropertyAttribute_get_Inherit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_put_Inherit_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL fInherit);


void __RPC_STUB IISPropertyAttribute_put_Inherit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_get_Secure_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);


void __RPC_STUB IISPropertyAttribute_get_Secure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_put_Secure_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL fSecure);


void __RPC_STUB IISPropertyAttribute_put_Secure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_get_Reference_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);


void __RPC_STUB IISPropertyAttribute_get_Reference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_put_Reference_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL fReference);


void __RPC_STUB IISPropertyAttribute_put_Reference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_get_Volatile_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);


void __RPC_STUB IISPropertyAttribute_get_Volatile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_put_Volatile_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL fVolatile);


void __RPC_STUB IISPropertyAttribute_put_Volatile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_get_Isinherit_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *retval);


void __RPC_STUB IISPropertyAttribute_get_Isinherit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_get_Default_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *retval);


void __RPC_STUB IISPropertyAttribute_get_Default_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IISPropertyAttribute_put_Default_Proxy( 
    IISPropertyAttribute __RPC_FAR * This,
    /* [in] */ VARIANT vDefault);


void __RPC_STUB IISPropertyAttribute_put_Default_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IISPropertyAttribute_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PropertyAttribute;

#ifdef __cplusplus

class DECLSPEC_UUID("FD2280A8-51A4-11D2-A601-3078302C2030")
PropertyAttribute;
#endif
#endif /* __IISOle_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


