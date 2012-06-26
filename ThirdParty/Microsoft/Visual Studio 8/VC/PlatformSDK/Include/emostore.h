
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0279 */
/* at Wed Dec 13 23:45:32 2000
 */
/* Compiler settings for P:\admin\src\libs\emolib\EMOSTORE.idl:
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

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __EMOSTORE_h__
#define __EMOSTORE_h__

/* Forward Declarations */ 

#ifndef __IExchangeServer_FWD_DEFINED__
#define __IExchangeServer_FWD_DEFINED__
typedef interface IExchangeServer IExchangeServer;
#endif 	/* __IExchangeServer_FWD_DEFINED__ */


#ifndef __IStorageGroup_FWD_DEFINED__
#define __IStorageGroup_FWD_DEFINED__
typedef interface IStorageGroup IStorageGroup;
#endif 	/* __IStorageGroup_FWD_DEFINED__ */


#ifndef __IPublicStoreDB_FWD_DEFINED__
#define __IPublicStoreDB_FWD_DEFINED__
typedef interface IPublicStoreDB IPublicStoreDB;
#endif 	/* __IPublicStoreDB_FWD_DEFINED__ */


#ifndef __IMailboxStoreDB_FWD_DEFINED__
#define __IMailboxStoreDB_FWD_DEFINED__
typedef interface IMailboxStoreDB IMailboxStoreDB;
#endif 	/* __IMailboxStoreDB_FWD_DEFINED__ */


#ifndef __IFolderTree_FWD_DEFINED__
#define __IFolderTree_FWD_DEFINED__
typedef interface IFolderTree IFolderTree;
#endif 	/* __IFolderTree_FWD_DEFINED__ */


#ifndef __IDataSource2_FWD_DEFINED__
#define __IDataSource2_FWD_DEFINED__
typedef interface IDataSource2 IDataSource2;
#endif 	/* __IDataSource2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "msado15.h"
#include "cdoex.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_EMOSTORE_0000 */
/* [local] */ 







typedef 
enum CDOEXMStoreDBStatus
    {	cdoexmOnline	= 0,
	cdoexmOffline	= 0x1,
	cdoexmMounting	= 0x2,
	cdoexmDismounting	= 0x3
    }	CDOEXMStoreDBStatus;

typedef 
enum CDOEXMFolderTreeType
    {	cdoexmGeneralPurpose	= 0,
	cdoexmMAPI	= 0x1,
	cdoexmNNTPOnly	= 0x2
    }	CDOEXMFolderTreeType;

typedef 
enum CDOEXMServerType
    {	cdoexmBackEnd	= 0,
	cdoexmFrontEnd	= 0x1
    }	CDOEXMServerType;



extern RPC_IF_HANDLE __MIDL_itf_EMOSTORE_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_EMOSTORE_0000_v0_0_s_ifspec;

#ifndef __IExchangeServer_INTERFACE_DEFINED__
#define __IExchangeServer_INTERFACE_DEFINED__

/* interface IExchangeServer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IExchangeServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25150F47-5734-11d2-A593-00C04F990D8A")
    IExchangeServer : public IDispatch
    {
    public:
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DataSource( 
            /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Fields( 
            /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *varName) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ExchangeVersion( 
            /* [retval][out] */ BSTR __RPC_FAR *varExchangeVersion) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StorageGroups( 
            /* [retval][out] */ VARIANT __RPC_FAR *varStorageGroups) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SubjectLoggingEnabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pSubjectLoggingEnabled) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SubjectLoggingEnabled( 
            /* [in] */ VARIANT_BOOL varSubjectLoggingEnabled) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MessageTrackingEnabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pMessageTrackingEnabled) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MessageTrackingEnabled( 
            /* [in] */ VARIANT_BOOL varMessageTrackingEnabled) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DaysBeforeLogFileRemoval( 
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeLogFileRemoval) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DaysBeforeLogFileRemoval( 
            /* [in] */ long varDaysBeforeLogFileRemoval) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ServerType( 
            /* [retval][out] */ CDOEXMServerType __RPC_FAR *pServerType) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ServerType( 
            /* [in] */ CDOEXMServerType varServerType) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DirectoryServer( 
            /* [retval][out] */ BSTR __RPC_FAR *varDirectoryServer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInterface( 
            /* [in] */ BSTR Interface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExchangeServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExchangeServer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExchangeServer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExchangeServer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IExchangeServer __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IExchangeServer __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IExchangeServer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IExchangeServer __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DataSource )( 
            IExchangeServer __RPC_FAR * This,
            /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Fields )( 
            IExchangeServer __RPC_FAR * This,
            /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IExchangeServer __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varName);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ExchangeVersion )( 
            IExchangeServer __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varExchangeVersion);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StorageGroups )( 
            IExchangeServer __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *varStorageGroups);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubjectLoggingEnabled )( 
            IExchangeServer __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pSubjectLoggingEnabled);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubjectLoggingEnabled )( 
            IExchangeServer __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varSubjectLoggingEnabled);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MessageTrackingEnabled )( 
            IExchangeServer __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pMessageTrackingEnabled);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MessageTrackingEnabled )( 
            IExchangeServer __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varMessageTrackingEnabled);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DaysBeforeLogFileRemoval )( 
            IExchangeServer __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeLogFileRemoval);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DaysBeforeLogFileRemoval )( 
            IExchangeServer __RPC_FAR * This,
            /* [in] */ long varDaysBeforeLogFileRemoval);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServerType )( 
            IExchangeServer __RPC_FAR * This,
            /* [retval][out] */ CDOEXMServerType __RPC_FAR *pServerType);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ServerType )( 
            IExchangeServer __RPC_FAR * This,
            /* [in] */ CDOEXMServerType varServerType);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DirectoryServer )( 
            IExchangeServer __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varDirectoryServer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInterface )( 
            IExchangeServer __RPC_FAR * This,
            /* [in] */ BSTR Interface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown);
        
        END_INTERFACE
    } IExchangeServerVtbl;

    interface IExchangeServer
    {
        CONST_VTBL struct IExchangeServerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExchangeServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExchangeServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExchangeServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExchangeServer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExchangeServer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExchangeServer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExchangeServer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExchangeServer_get_DataSource(This,varDataSource)	\
    (This)->lpVtbl -> get_DataSource(This,varDataSource)

#define IExchangeServer_get_Fields(This,varFields)	\
    (This)->lpVtbl -> get_Fields(This,varFields)

#define IExchangeServer_get_Name(This,varName)	\
    (This)->lpVtbl -> get_Name(This,varName)

#define IExchangeServer_get_ExchangeVersion(This,varExchangeVersion)	\
    (This)->lpVtbl -> get_ExchangeVersion(This,varExchangeVersion)

#define IExchangeServer_get_StorageGroups(This,varStorageGroups)	\
    (This)->lpVtbl -> get_StorageGroups(This,varStorageGroups)

#define IExchangeServer_get_SubjectLoggingEnabled(This,pSubjectLoggingEnabled)	\
    (This)->lpVtbl -> get_SubjectLoggingEnabled(This,pSubjectLoggingEnabled)

#define IExchangeServer_put_SubjectLoggingEnabled(This,varSubjectLoggingEnabled)	\
    (This)->lpVtbl -> put_SubjectLoggingEnabled(This,varSubjectLoggingEnabled)

#define IExchangeServer_get_MessageTrackingEnabled(This,pMessageTrackingEnabled)	\
    (This)->lpVtbl -> get_MessageTrackingEnabled(This,pMessageTrackingEnabled)

#define IExchangeServer_put_MessageTrackingEnabled(This,varMessageTrackingEnabled)	\
    (This)->lpVtbl -> put_MessageTrackingEnabled(This,varMessageTrackingEnabled)

#define IExchangeServer_get_DaysBeforeLogFileRemoval(This,pDaysBeforeLogFileRemoval)	\
    (This)->lpVtbl -> get_DaysBeforeLogFileRemoval(This,pDaysBeforeLogFileRemoval)

#define IExchangeServer_put_DaysBeforeLogFileRemoval(This,varDaysBeforeLogFileRemoval)	\
    (This)->lpVtbl -> put_DaysBeforeLogFileRemoval(This,varDaysBeforeLogFileRemoval)

#define IExchangeServer_get_ServerType(This,pServerType)	\
    (This)->lpVtbl -> get_ServerType(This,pServerType)

#define IExchangeServer_put_ServerType(This,varServerType)	\
    (This)->lpVtbl -> put_ServerType(This,varServerType)

#define IExchangeServer_get_DirectoryServer(This,varDirectoryServer)	\
    (This)->lpVtbl -> get_DirectoryServer(This,varDirectoryServer)

#define IExchangeServer_GetInterface(This,Interface,ppUnknown)	\
    (This)->lpVtbl -> GetInterface(This,Interface,ppUnknown)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_get_DataSource_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource);


void __RPC_STUB IExchangeServer_get_DataSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_get_Fields_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields);


void __RPC_STUB IExchangeServer_get_Fields_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_get_Name_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varName);


void __RPC_STUB IExchangeServer_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_get_ExchangeVersion_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varExchangeVersion);


void __RPC_STUB IExchangeServer_get_ExchangeVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_get_StorageGroups_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *varStorageGroups);


void __RPC_STUB IExchangeServer_get_StorageGroups_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_get_SubjectLoggingEnabled_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pSubjectLoggingEnabled);


void __RPC_STUB IExchangeServer_get_SubjectLoggingEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_put_SubjectLoggingEnabled_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varSubjectLoggingEnabled);


void __RPC_STUB IExchangeServer_put_SubjectLoggingEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_get_MessageTrackingEnabled_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pMessageTrackingEnabled);


void __RPC_STUB IExchangeServer_get_MessageTrackingEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_put_MessageTrackingEnabled_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varMessageTrackingEnabled);


void __RPC_STUB IExchangeServer_put_MessageTrackingEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_get_DaysBeforeLogFileRemoval_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pDaysBeforeLogFileRemoval);


void __RPC_STUB IExchangeServer_get_DaysBeforeLogFileRemoval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_put_DaysBeforeLogFileRemoval_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [in] */ long varDaysBeforeLogFileRemoval);


void __RPC_STUB IExchangeServer_put_DaysBeforeLogFileRemoval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_get_ServerType_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [retval][out] */ CDOEXMServerType __RPC_FAR *pServerType);


void __RPC_STUB IExchangeServer_get_ServerType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_put_ServerType_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [in] */ CDOEXMServerType varServerType);


void __RPC_STUB IExchangeServer_put_ServerType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_get_DirectoryServer_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varDirectoryServer);


void __RPC_STUB IExchangeServer_get_DirectoryServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExchangeServer_GetInterface_Proxy( 
    IExchangeServer __RPC_FAR * This,
    /* [in] */ BSTR Interface,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown);


void __RPC_STUB IExchangeServer_GetInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExchangeServer_INTERFACE_DEFINED__ */


#ifndef __IStorageGroup_INTERFACE_DEFINED__
#define __IStorageGroup_INTERFACE_DEFINED__

/* interface IStorageGroup */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IStorageGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25150F46-5734-11d2-A593-00C04F990D8A")
    IStorageGroup : public IDispatch
    {
    public:
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DataSource( 
            /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Fields( 
            /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR varName) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PublicStoreDBs( 
            /* [retval][out] */ VARIANT __RPC_FAR *varPublicStoreDBs) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MailboxStoreDBs( 
            /* [retval][out] */ VARIANT __RPC_FAR *varMailboxStoreDBs) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LogFilePath( 
            /* [retval][out] */ BSTR __RPC_FAR *varLogFilePath) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SystemFilePath( 
            /* [retval][out] */ BSTR __RPC_FAR *varSystemFilePath) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CircularLogging( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pCircularLogging) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CircularLogging( 
            /* [in] */ VARIANT_BOOL varCircularLogging) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ZeroDatabase( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pZeroDatabase) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ZeroDatabase( 
            /* [in] */ VARIANT_BOOL varZeroDatabase) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInterface( 
            /* [in] */ BSTR Interface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveLogFiles( 
            /* [in] */ BSTR LogFilePath,
            /* [optional][in] */ long Flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveSystemFiles( 
            /* [in] */ BSTR SystemFilePath,
            /* [optional][in] */ long Flags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStorageGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IStorageGroup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IStorageGroup __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IStorageGroup __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IStorageGroup __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IStorageGroup __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IStorageGroup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IStorageGroup __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DataSource )( 
            IStorageGroup __RPC_FAR * This,
            /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Fields )( 
            IStorageGroup __RPC_FAR * This,
            /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IStorageGroup __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IStorageGroup __RPC_FAR * This,
            /* [in] */ BSTR varName);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublicStoreDBs )( 
            IStorageGroup __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *varPublicStoreDBs);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MailboxStoreDBs )( 
            IStorageGroup __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *varMailboxStoreDBs);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LogFilePath )( 
            IStorageGroup __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varLogFilePath);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SystemFilePath )( 
            IStorageGroup __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varSystemFilePath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CircularLogging )( 
            IStorageGroup __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pCircularLogging);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CircularLogging )( 
            IStorageGroup __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varCircularLogging);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ZeroDatabase )( 
            IStorageGroup __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pZeroDatabase);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ZeroDatabase )( 
            IStorageGroup __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varZeroDatabase);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInterface )( 
            IStorageGroup __RPC_FAR * This,
            /* [in] */ BSTR Interface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveLogFiles )( 
            IStorageGroup __RPC_FAR * This,
            /* [in] */ BSTR LogFilePath,
            /* [optional][in] */ long Flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveSystemFiles )( 
            IStorageGroup __RPC_FAR * This,
            /* [in] */ BSTR SystemFilePath,
            /* [optional][in] */ long Flags);
        
        END_INTERFACE
    } IStorageGroupVtbl;

    interface IStorageGroup
    {
        CONST_VTBL struct IStorageGroupVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStorageGroup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStorageGroup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStorageGroup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStorageGroup_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IStorageGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IStorageGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IStorageGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IStorageGroup_get_DataSource(This,varDataSource)	\
    (This)->lpVtbl -> get_DataSource(This,varDataSource)

#define IStorageGroup_get_Fields(This,varFields)	\
    (This)->lpVtbl -> get_Fields(This,varFields)

#define IStorageGroup_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IStorageGroup_put_Name(This,varName)	\
    (This)->lpVtbl -> put_Name(This,varName)

#define IStorageGroup_get_PublicStoreDBs(This,varPublicStoreDBs)	\
    (This)->lpVtbl -> get_PublicStoreDBs(This,varPublicStoreDBs)

#define IStorageGroup_get_MailboxStoreDBs(This,varMailboxStoreDBs)	\
    (This)->lpVtbl -> get_MailboxStoreDBs(This,varMailboxStoreDBs)

#define IStorageGroup_get_LogFilePath(This,varLogFilePath)	\
    (This)->lpVtbl -> get_LogFilePath(This,varLogFilePath)

#define IStorageGroup_get_SystemFilePath(This,varSystemFilePath)	\
    (This)->lpVtbl -> get_SystemFilePath(This,varSystemFilePath)

#define IStorageGroup_get_CircularLogging(This,pCircularLogging)	\
    (This)->lpVtbl -> get_CircularLogging(This,pCircularLogging)

#define IStorageGroup_put_CircularLogging(This,varCircularLogging)	\
    (This)->lpVtbl -> put_CircularLogging(This,varCircularLogging)

#define IStorageGroup_get_ZeroDatabase(This,pZeroDatabase)	\
    (This)->lpVtbl -> get_ZeroDatabase(This,pZeroDatabase)

#define IStorageGroup_put_ZeroDatabase(This,varZeroDatabase)	\
    (This)->lpVtbl -> put_ZeroDatabase(This,varZeroDatabase)

#define IStorageGroup_GetInterface(This,Interface,ppUnknown)	\
    (This)->lpVtbl -> GetInterface(This,Interface,ppUnknown)

#define IStorageGroup_MoveLogFiles(This,LogFilePath,Flags)	\
    (This)->lpVtbl -> MoveLogFiles(This,LogFilePath,Flags)

#define IStorageGroup_MoveSystemFiles(This,SystemFilePath,Flags)	\
    (This)->lpVtbl -> MoveSystemFiles(This,SystemFilePath,Flags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_get_DataSource_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource);


void __RPC_STUB IStorageGroup_get_DataSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_get_Fields_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields);


void __RPC_STUB IStorageGroup_get_Fields_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_get_Name_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pName);


void __RPC_STUB IStorageGroup_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_put_Name_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [in] */ BSTR varName);


void __RPC_STUB IStorageGroup_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_get_PublicStoreDBs_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *varPublicStoreDBs);


void __RPC_STUB IStorageGroup_get_PublicStoreDBs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_get_MailboxStoreDBs_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *varMailboxStoreDBs);


void __RPC_STUB IStorageGroup_get_MailboxStoreDBs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_get_LogFilePath_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varLogFilePath);


void __RPC_STUB IStorageGroup_get_LogFilePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_get_SystemFilePath_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varSystemFilePath);


void __RPC_STUB IStorageGroup_get_SystemFilePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_get_CircularLogging_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pCircularLogging);


void __RPC_STUB IStorageGroup_get_CircularLogging_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_put_CircularLogging_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varCircularLogging);


void __RPC_STUB IStorageGroup_put_CircularLogging_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_get_ZeroDatabase_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pZeroDatabase);


void __RPC_STUB IStorageGroup_get_ZeroDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_put_ZeroDatabase_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varZeroDatabase);


void __RPC_STUB IStorageGroup_put_ZeroDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_GetInterface_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [in] */ BSTR Interface,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown);


void __RPC_STUB IStorageGroup_GetInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_MoveLogFiles_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [in] */ BSTR LogFilePath,
    /* [optional][in] */ long Flags);


void __RPC_STUB IStorageGroup_MoveLogFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IStorageGroup_MoveSystemFiles_Proxy( 
    IStorageGroup __RPC_FAR * This,
    /* [in] */ BSTR SystemFilePath,
    /* [optional][in] */ long Flags);


void __RPC_STUB IStorageGroup_MoveSystemFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStorageGroup_INTERFACE_DEFINED__ */


#ifndef __IPublicStoreDB_INTERFACE_DEFINED__
#define __IPublicStoreDB_INTERFACE_DEFINED__

/* interface IPublicStoreDB */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPublicStoreDB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25150F44-5734-11d2-A593-00C04F990D8A")
    IPublicStoreDB : public IDispatch
    {
    public:
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DataSource( 
            /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Fields( 
            /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR varName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FolderTree( 
            /* [retval][out] */ BSTR __RPC_FAR *pFolderTree) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FolderTree( 
            /* [in] */ BSTR varFolderTree) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DBPath( 
            /* [retval][out] */ BSTR __RPC_FAR *varDBPath) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SLVPath( 
            /* [retval][out] */ BSTR __RPC_FAR *varSLVPath) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ CDOEXMStoreDBStatus __RPC_FAR *varStatus) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pEnabled) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL varEnabled) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StoreQuota( 
            /* [retval][out] */ long __RPC_FAR *pStoreQuota) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_StoreQuota( 
            /* [in] */ long varStoreQuota) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HardLimit( 
            /* [retval][out] */ long __RPC_FAR *pHardLimit) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HardLimit( 
            /* [in] */ long varHardLimit) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ItemSizeLimit( 
            /* [retval][out] */ long __RPC_FAR *pItemSizeLimit) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ItemSizeLimit( 
            /* [in] */ long varItemSizeLimit) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DaysBeforeItemExpiration( 
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeItemExpiration) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DaysBeforeItemExpiration( 
            /* [in] */ long varDaysBeforeItemExpiration) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DaysBeforeGarbageCollection( 
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeGarbageCollection) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DaysBeforeGarbageCollection( 
            /* [in] */ long varDaysBeforeGarbageCollection) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GarbageCollectOnlyAfterBackup( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pGarbageCollectOnlyAfterBackup) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GarbageCollectOnlyAfterBackup( 
            /* [in] */ VARIANT_BOOL varGarbageCollectOnlyAfterBackup) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInterface( 
            /* [in] */ BSTR Interface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveDataFiles( 
            /* [in] */ BSTR DBPath,
            /* [in] */ BSTR SLVPath,
            /* [optional][in] */ long Flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Mount( 
            /* [optional][in] */ long Timeout) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Dismount( 
            /* [optional][in] */ long Timeout) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPublicStoreDBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPublicStoreDB __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPublicStoreDB __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DataSource )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Fields )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ BSTR varName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FolderTree )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pFolderTree);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FolderTree )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ BSTR varFolderTree);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DBPath )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varDBPath);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SLVPath )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varSLVPath);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Status )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ CDOEXMStoreDBStatus __RPC_FAR *varStatus);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pEnabled);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varEnabled);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StoreQuota )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pStoreQuota);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StoreQuota )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ long varStoreQuota);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HardLimit )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pHardLimit);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HardLimit )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ long varHardLimit);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ItemSizeLimit )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pItemSizeLimit);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ItemSizeLimit )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ long varItemSizeLimit);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DaysBeforeItemExpiration )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeItemExpiration);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DaysBeforeItemExpiration )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ long varDaysBeforeItemExpiration);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DaysBeforeGarbageCollection )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeGarbageCollection);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DaysBeforeGarbageCollection )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ long varDaysBeforeGarbageCollection);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GarbageCollectOnlyAfterBackup )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pGarbageCollectOnlyAfterBackup);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GarbageCollectOnlyAfterBackup )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varGarbageCollectOnlyAfterBackup);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInterface )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ BSTR Interface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveDataFiles )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [in] */ BSTR DBPath,
            /* [in] */ BSTR SLVPath,
            /* [optional][in] */ long Flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Mount )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [optional][in] */ long Timeout);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Dismount )( 
            IPublicStoreDB __RPC_FAR * This,
            /* [optional][in] */ long Timeout);
        
        END_INTERFACE
    } IPublicStoreDBVtbl;

    interface IPublicStoreDB
    {
        CONST_VTBL struct IPublicStoreDBVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPublicStoreDB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPublicStoreDB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPublicStoreDB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPublicStoreDB_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPublicStoreDB_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPublicStoreDB_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPublicStoreDB_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPublicStoreDB_get_DataSource(This,varDataSource)	\
    (This)->lpVtbl -> get_DataSource(This,varDataSource)

#define IPublicStoreDB_get_Fields(This,varFields)	\
    (This)->lpVtbl -> get_Fields(This,varFields)

#define IPublicStoreDB_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IPublicStoreDB_put_Name(This,varName)	\
    (This)->lpVtbl -> put_Name(This,varName)

#define IPublicStoreDB_get_FolderTree(This,pFolderTree)	\
    (This)->lpVtbl -> get_FolderTree(This,pFolderTree)

#define IPublicStoreDB_put_FolderTree(This,varFolderTree)	\
    (This)->lpVtbl -> put_FolderTree(This,varFolderTree)

#define IPublicStoreDB_get_DBPath(This,varDBPath)	\
    (This)->lpVtbl -> get_DBPath(This,varDBPath)

#define IPublicStoreDB_get_SLVPath(This,varSLVPath)	\
    (This)->lpVtbl -> get_SLVPath(This,varSLVPath)

#define IPublicStoreDB_get_Status(This,varStatus)	\
    (This)->lpVtbl -> get_Status(This,varStatus)

#define IPublicStoreDB_get_Enabled(This,pEnabled)	\
    (This)->lpVtbl -> get_Enabled(This,pEnabled)

#define IPublicStoreDB_put_Enabled(This,varEnabled)	\
    (This)->lpVtbl -> put_Enabled(This,varEnabled)

#define IPublicStoreDB_get_StoreQuota(This,pStoreQuota)	\
    (This)->lpVtbl -> get_StoreQuota(This,pStoreQuota)

#define IPublicStoreDB_put_StoreQuota(This,varStoreQuota)	\
    (This)->lpVtbl -> put_StoreQuota(This,varStoreQuota)

#define IPublicStoreDB_get_HardLimit(This,pHardLimit)	\
    (This)->lpVtbl -> get_HardLimit(This,pHardLimit)

#define IPublicStoreDB_put_HardLimit(This,varHardLimit)	\
    (This)->lpVtbl -> put_HardLimit(This,varHardLimit)

#define IPublicStoreDB_get_ItemSizeLimit(This,pItemSizeLimit)	\
    (This)->lpVtbl -> get_ItemSizeLimit(This,pItemSizeLimit)

#define IPublicStoreDB_put_ItemSizeLimit(This,varItemSizeLimit)	\
    (This)->lpVtbl -> put_ItemSizeLimit(This,varItemSizeLimit)

#define IPublicStoreDB_get_DaysBeforeItemExpiration(This,pDaysBeforeItemExpiration)	\
    (This)->lpVtbl -> get_DaysBeforeItemExpiration(This,pDaysBeforeItemExpiration)

#define IPublicStoreDB_put_DaysBeforeItemExpiration(This,varDaysBeforeItemExpiration)	\
    (This)->lpVtbl -> put_DaysBeforeItemExpiration(This,varDaysBeforeItemExpiration)

#define IPublicStoreDB_get_DaysBeforeGarbageCollection(This,pDaysBeforeGarbageCollection)	\
    (This)->lpVtbl -> get_DaysBeforeGarbageCollection(This,pDaysBeforeGarbageCollection)

#define IPublicStoreDB_put_DaysBeforeGarbageCollection(This,varDaysBeforeGarbageCollection)	\
    (This)->lpVtbl -> put_DaysBeforeGarbageCollection(This,varDaysBeforeGarbageCollection)

#define IPublicStoreDB_get_GarbageCollectOnlyAfterBackup(This,pGarbageCollectOnlyAfterBackup)	\
    (This)->lpVtbl -> get_GarbageCollectOnlyAfterBackup(This,pGarbageCollectOnlyAfterBackup)

#define IPublicStoreDB_put_GarbageCollectOnlyAfterBackup(This,varGarbageCollectOnlyAfterBackup)	\
    (This)->lpVtbl -> put_GarbageCollectOnlyAfterBackup(This,varGarbageCollectOnlyAfterBackup)

#define IPublicStoreDB_GetInterface(This,Interface,ppUnknown)	\
    (This)->lpVtbl -> GetInterface(This,Interface,ppUnknown)

#define IPublicStoreDB_MoveDataFiles(This,DBPath,SLVPath,Flags)	\
    (This)->lpVtbl -> MoveDataFiles(This,DBPath,SLVPath,Flags)

#define IPublicStoreDB_Mount(This,Timeout)	\
    (This)->lpVtbl -> Mount(This,Timeout)

#define IPublicStoreDB_Dismount(This,Timeout)	\
    (This)->lpVtbl -> Dismount(This,Timeout)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_DataSource_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource);


void __RPC_STUB IPublicStoreDB_get_DataSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_Fields_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields);


void __RPC_STUB IPublicStoreDB_get_Fields_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_Name_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pName);


void __RPC_STUB IPublicStoreDB_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_put_Name_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [in] */ BSTR varName);


void __RPC_STUB IPublicStoreDB_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_FolderTree_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pFolderTree);


void __RPC_STUB IPublicStoreDB_get_FolderTree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_put_FolderTree_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [in] */ BSTR varFolderTree);


void __RPC_STUB IPublicStoreDB_put_FolderTree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_DBPath_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varDBPath);


void __RPC_STUB IPublicStoreDB_get_DBPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_SLVPath_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varSLVPath);


void __RPC_STUB IPublicStoreDB_get_SLVPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_Status_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ CDOEXMStoreDBStatus __RPC_FAR *varStatus);


void __RPC_STUB IPublicStoreDB_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_Enabled_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pEnabled);


void __RPC_STUB IPublicStoreDB_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_put_Enabled_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varEnabled);


void __RPC_STUB IPublicStoreDB_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_StoreQuota_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pStoreQuota);


void __RPC_STUB IPublicStoreDB_get_StoreQuota_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_put_StoreQuota_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [in] */ long varStoreQuota);


void __RPC_STUB IPublicStoreDB_put_StoreQuota_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_HardLimit_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pHardLimit);


void __RPC_STUB IPublicStoreDB_get_HardLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_put_HardLimit_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [in] */ long varHardLimit);


void __RPC_STUB IPublicStoreDB_put_HardLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_ItemSizeLimit_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pItemSizeLimit);


void __RPC_STUB IPublicStoreDB_get_ItemSizeLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_put_ItemSizeLimit_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [in] */ long varItemSizeLimit);


void __RPC_STUB IPublicStoreDB_put_ItemSizeLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_DaysBeforeItemExpiration_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pDaysBeforeItemExpiration);


void __RPC_STUB IPublicStoreDB_get_DaysBeforeItemExpiration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_put_DaysBeforeItemExpiration_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [in] */ long varDaysBeforeItemExpiration);


void __RPC_STUB IPublicStoreDB_put_DaysBeforeItemExpiration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_DaysBeforeGarbageCollection_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pDaysBeforeGarbageCollection);


void __RPC_STUB IPublicStoreDB_get_DaysBeforeGarbageCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_put_DaysBeforeGarbageCollection_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [in] */ long varDaysBeforeGarbageCollection);


void __RPC_STUB IPublicStoreDB_put_DaysBeforeGarbageCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_get_GarbageCollectOnlyAfterBackup_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pGarbageCollectOnlyAfterBackup);


void __RPC_STUB IPublicStoreDB_get_GarbageCollectOnlyAfterBackup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_put_GarbageCollectOnlyAfterBackup_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varGarbageCollectOnlyAfterBackup);


void __RPC_STUB IPublicStoreDB_put_GarbageCollectOnlyAfterBackup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_GetInterface_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [in] */ BSTR Interface,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown);


void __RPC_STUB IPublicStoreDB_GetInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_MoveDataFiles_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [in] */ BSTR DBPath,
    /* [in] */ BSTR SLVPath,
    /* [optional][in] */ long Flags);


void __RPC_STUB IPublicStoreDB_MoveDataFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_Mount_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [optional][in] */ long Timeout);


void __RPC_STUB IPublicStoreDB_Mount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPublicStoreDB_Dismount_Proxy( 
    IPublicStoreDB __RPC_FAR * This,
    /* [optional][in] */ long Timeout);


void __RPC_STUB IPublicStoreDB_Dismount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPublicStoreDB_INTERFACE_DEFINED__ */


#ifndef __IMailboxStoreDB_INTERFACE_DEFINED__
#define __IMailboxStoreDB_INTERFACE_DEFINED__

/* interface IMailboxStoreDB */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMailboxStoreDB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25150F45-5734-11d2-A593-00C04F990D8A")
    IMailboxStoreDB : public IDispatch
    {
    public:
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DataSource( 
            /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Fields( 
            /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR varName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PublicStoreDB( 
            /* [retval][out] */ BSTR __RPC_FAR *pPublicStoreDB) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PublicStoreDB( 
            /* [in] */ BSTR varPublicStoreDB) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OfflineAddressList( 
            /* [retval][out] */ BSTR __RPC_FAR *pOfflineAddressList) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_OfflineAddressList( 
            /* [in] */ BSTR varOfflineAddressList) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DBPath( 
            /* [retval][out] */ BSTR __RPC_FAR *varDBPath) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SLVPath( 
            /* [retval][out] */ BSTR __RPC_FAR *varSLVPath) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ CDOEXMStoreDBStatus __RPC_FAR *varStatus) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pEnabled) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL varEnabled) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StoreQuota( 
            /* [retval][out] */ long __RPC_FAR *pStoreQuota) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_StoreQuota( 
            /* [in] */ long varStoreQuota) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OverQuotaLimit( 
            /* [retval][out] */ long __RPC_FAR *pOverQuotaLimit) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_OverQuotaLimit( 
            /* [in] */ long varOverQuotaLimit) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HardLimit( 
            /* [retval][out] */ long __RPC_FAR *pHardLimit) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HardLimit( 
            /* [in] */ long varHardLimit) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DaysBeforeGarbageCollection( 
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeGarbageCollection) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DaysBeforeGarbageCollection( 
            /* [in] */ long varDaysBeforeGarbageCollection) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DaysBeforeDeletedMailboxCleanup( 
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeDeletedMailboxCleanup) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DaysBeforeDeletedMailboxCleanup( 
            /* [in] */ long varDaysBeforeDeletedMailboxCleanup) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GarbageCollectOnlyAfterBackup( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pGarbageCollectOnlyAfterBackup) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GarbageCollectOnlyAfterBackup( 
            /* [in] */ VARIANT_BOOL varGarbageCollectOnlyAfterBackup) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInterface( 
            /* [in] */ BSTR Interface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveDataFiles( 
            /* [in] */ BSTR DBPath,
            /* [in] */ BSTR SLVPath,
            /* [optional][in] */ long Flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Mount( 
            /* [optional][in] */ long Timeout) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Dismount( 
            /* [optional][in] */ long Timeout) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMailboxStoreDBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMailboxStoreDB __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMailboxStoreDB __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DataSource )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Fields )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ BSTR varName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublicStoreDB )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pPublicStoreDB);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublicStoreDB )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ BSTR varPublicStoreDB);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OfflineAddressList )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pOfflineAddressList);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OfflineAddressList )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ BSTR varOfflineAddressList);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DBPath )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varDBPath);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SLVPath )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varSLVPath);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Status )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ CDOEXMStoreDBStatus __RPC_FAR *varStatus);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pEnabled);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varEnabled);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StoreQuota )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pStoreQuota);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StoreQuota )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ long varStoreQuota);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OverQuotaLimit )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pOverQuotaLimit);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OverQuotaLimit )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ long varOverQuotaLimit);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HardLimit )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pHardLimit);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HardLimit )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ long varHardLimit);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DaysBeforeGarbageCollection )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeGarbageCollection);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DaysBeforeGarbageCollection )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ long varDaysBeforeGarbageCollection);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DaysBeforeDeletedMailboxCleanup )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeDeletedMailboxCleanup);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DaysBeforeDeletedMailboxCleanup )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ long varDaysBeforeDeletedMailboxCleanup);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GarbageCollectOnlyAfterBackup )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pGarbageCollectOnlyAfterBackup);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GarbageCollectOnlyAfterBackup )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varGarbageCollectOnlyAfterBackup);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInterface )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ BSTR Interface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveDataFiles )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [in] */ BSTR DBPath,
            /* [in] */ BSTR SLVPath,
            /* [optional][in] */ long Flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Mount )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [optional][in] */ long Timeout);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Dismount )( 
            IMailboxStoreDB __RPC_FAR * This,
            /* [optional][in] */ long Timeout);
        
        END_INTERFACE
    } IMailboxStoreDBVtbl;

    interface IMailboxStoreDB
    {
        CONST_VTBL struct IMailboxStoreDBVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMailboxStoreDB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMailboxStoreDB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMailboxStoreDB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMailboxStoreDB_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMailboxStoreDB_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMailboxStoreDB_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMailboxStoreDB_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMailboxStoreDB_get_DataSource(This,varDataSource)	\
    (This)->lpVtbl -> get_DataSource(This,varDataSource)

#define IMailboxStoreDB_get_Fields(This,varFields)	\
    (This)->lpVtbl -> get_Fields(This,varFields)

#define IMailboxStoreDB_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IMailboxStoreDB_put_Name(This,varName)	\
    (This)->lpVtbl -> put_Name(This,varName)

#define IMailboxStoreDB_get_PublicStoreDB(This,pPublicStoreDB)	\
    (This)->lpVtbl -> get_PublicStoreDB(This,pPublicStoreDB)

#define IMailboxStoreDB_put_PublicStoreDB(This,varPublicStoreDB)	\
    (This)->lpVtbl -> put_PublicStoreDB(This,varPublicStoreDB)

#define IMailboxStoreDB_get_OfflineAddressList(This,pOfflineAddressList)	\
    (This)->lpVtbl -> get_OfflineAddressList(This,pOfflineAddressList)

#define IMailboxStoreDB_put_OfflineAddressList(This,varOfflineAddressList)	\
    (This)->lpVtbl -> put_OfflineAddressList(This,varOfflineAddressList)

#define IMailboxStoreDB_get_DBPath(This,varDBPath)	\
    (This)->lpVtbl -> get_DBPath(This,varDBPath)

#define IMailboxStoreDB_get_SLVPath(This,varSLVPath)	\
    (This)->lpVtbl -> get_SLVPath(This,varSLVPath)

#define IMailboxStoreDB_get_Status(This,varStatus)	\
    (This)->lpVtbl -> get_Status(This,varStatus)

#define IMailboxStoreDB_get_Enabled(This,pEnabled)	\
    (This)->lpVtbl -> get_Enabled(This,pEnabled)

#define IMailboxStoreDB_put_Enabled(This,varEnabled)	\
    (This)->lpVtbl -> put_Enabled(This,varEnabled)

#define IMailboxStoreDB_get_StoreQuota(This,pStoreQuota)	\
    (This)->lpVtbl -> get_StoreQuota(This,pStoreQuota)

#define IMailboxStoreDB_put_StoreQuota(This,varStoreQuota)	\
    (This)->lpVtbl -> put_StoreQuota(This,varStoreQuota)

#define IMailboxStoreDB_get_OverQuotaLimit(This,pOverQuotaLimit)	\
    (This)->lpVtbl -> get_OverQuotaLimit(This,pOverQuotaLimit)

#define IMailboxStoreDB_put_OverQuotaLimit(This,varOverQuotaLimit)	\
    (This)->lpVtbl -> put_OverQuotaLimit(This,varOverQuotaLimit)

#define IMailboxStoreDB_get_HardLimit(This,pHardLimit)	\
    (This)->lpVtbl -> get_HardLimit(This,pHardLimit)

#define IMailboxStoreDB_put_HardLimit(This,varHardLimit)	\
    (This)->lpVtbl -> put_HardLimit(This,varHardLimit)

#define IMailboxStoreDB_get_DaysBeforeGarbageCollection(This,pDaysBeforeGarbageCollection)	\
    (This)->lpVtbl -> get_DaysBeforeGarbageCollection(This,pDaysBeforeGarbageCollection)

#define IMailboxStoreDB_put_DaysBeforeGarbageCollection(This,varDaysBeforeGarbageCollection)	\
    (This)->lpVtbl -> put_DaysBeforeGarbageCollection(This,varDaysBeforeGarbageCollection)

#define IMailboxStoreDB_get_DaysBeforeDeletedMailboxCleanup(This,pDaysBeforeDeletedMailboxCleanup)	\
    (This)->lpVtbl -> get_DaysBeforeDeletedMailboxCleanup(This,pDaysBeforeDeletedMailboxCleanup)

#define IMailboxStoreDB_put_DaysBeforeDeletedMailboxCleanup(This,varDaysBeforeDeletedMailboxCleanup)	\
    (This)->lpVtbl -> put_DaysBeforeDeletedMailboxCleanup(This,varDaysBeforeDeletedMailboxCleanup)

#define IMailboxStoreDB_get_GarbageCollectOnlyAfterBackup(This,pGarbageCollectOnlyAfterBackup)	\
    (This)->lpVtbl -> get_GarbageCollectOnlyAfterBackup(This,pGarbageCollectOnlyAfterBackup)

#define IMailboxStoreDB_put_GarbageCollectOnlyAfterBackup(This,varGarbageCollectOnlyAfterBackup)	\
    (This)->lpVtbl -> put_GarbageCollectOnlyAfterBackup(This,varGarbageCollectOnlyAfterBackup)

#define IMailboxStoreDB_GetInterface(This,Interface,ppUnknown)	\
    (This)->lpVtbl -> GetInterface(This,Interface,ppUnknown)

#define IMailboxStoreDB_MoveDataFiles(This,DBPath,SLVPath,Flags)	\
    (This)->lpVtbl -> MoveDataFiles(This,DBPath,SLVPath,Flags)

#define IMailboxStoreDB_Mount(This,Timeout)	\
    (This)->lpVtbl -> Mount(This,Timeout)

#define IMailboxStoreDB_Dismount(This,Timeout)	\
    (This)->lpVtbl -> Dismount(This,Timeout)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_DataSource_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource);


void __RPC_STUB IMailboxStoreDB_get_DataSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_Fields_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields);


void __RPC_STUB IMailboxStoreDB_get_Fields_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_Name_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pName);


void __RPC_STUB IMailboxStoreDB_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_put_Name_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ BSTR varName);


void __RPC_STUB IMailboxStoreDB_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_PublicStoreDB_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pPublicStoreDB);


void __RPC_STUB IMailboxStoreDB_get_PublicStoreDB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_put_PublicStoreDB_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ BSTR varPublicStoreDB);


void __RPC_STUB IMailboxStoreDB_put_PublicStoreDB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_OfflineAddressList_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pOfflineAddressList);


void __RPC_STUB IMailboxStoreDB_get_OfflineAddressList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_put_OfflineAddressList_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ BSTR varOfflineAddressList);


void __RPC_STUB IMailboxStoreDB_put_OfflineAddressList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_DBPath_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varDBPath);


void __RPC_STUB IMailboxStoreDB_get_DBPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_SLVPath_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varSLVPath);


void __RPC_STUB IMailboxStoreDB_get_SLVPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_Status_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ CDOEXMStoreDBStatus __RPC_FAR *varStatus);


void __RPC_STUB IMailboxStoreDB_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_Enabled_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pEnabled);


void __RPC_STUB IMailboxStoreDB_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_put_Enabled_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varEnabled);


void __RPC_STUB IMailboxStoreDB_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_StoreQuota_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pStoreQuota);


void __RPC_STUB IMailboxStoreDB_get_StoreQuota_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_put_StoreQuota_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ long varStoreQuota);


void __RPC_STUB IMailboxStoreDB_put_StoreQuota_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_OverQuotaLimit_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pOverQuotaLimit);


void __RPC_STUB IMailboxStoreDB_get_OverQuotaLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_put_OverQuotaLimit_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ long varOverQuotaLimit);


void __RPC_STUB IMailboxStoreDB_put_OverQuotaLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_HardLimit_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pHardLimit);


void __RPC_STUB IMailboxStoreDB_get_HardLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_put_HardLimit_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ long varHardLimit);


void __RPC_STUB IMailboxStoreDB_put_HardLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_DaysBeforeGarbageCollection_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pDaysBeforeGarbageCollection);


void __RPC_STUB IMailboxStoreDB_get_DaysBeforeGarbageCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_put_DaysBeforeGarbageCollection_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ long varDaysBeforeGarbageCollection);


void __RPC_STUB IMailboxStoreDB_put_DaysBeforeGarbageCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_DaysBeforeDeletedMailboxCleanup_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pDaysBeforeDeletedMailboxCleanup);


void __RPC_STUB IMailboxStoreDB_get_DaysBeforeDeletedMailboxCleanup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_put_DaysBeforeDeletedMailboxCleanup_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ long varDaysBeforeDeletedMailboxCleanup);


void __RPC_STUB IMailboxStoreDB_put_DaysBeforeDeletedMailboxCleanup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_get_GarbageCollectOnlyAfterBackup_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pGarbageCollectOnlyAfterBackup);


void __RPC_STUB IMailboxStoreDB_get_GarbageCollectOnlyAfterBackup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_put_GarbageCollectOnlyAfterBackup_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varGarbageCollectOnlyAfterBackup);


void __RPC_STUB IMailboxStoreDB_put_GarbageCollectOnlyAfterBackup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_GetInterface_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ BSTR Interface,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown);


void __RPC_STUB IMailboxStoreDB_GetInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_MoveDataFiles_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [in] */ BSTR DBPath,
    /* [in] */ BSTR SLVPath,
    /* [optional][in] */ long Flags);


void __RPC_STUB IMailboxStoreDB_MoveDataFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_Mount_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [optional][in] */ long Timeout);


void __RPC_STUB IMailboxStoreDB_Mount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMailboxStoreDB_Dismount_Proxy( 
    IMailboxStoreDB __RPC_FAR * This,
    /* [optional][in] */ long Timeout);


void __RPC_STUB IMailboxStoreDB_Dismount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMailboxStoreDB_INTERFACE_DEFINED__ */


#ifndef __IFolderTree_INTERFACE_DEFINED__
#define __IFolderTree_INTERFACE_DEFINED__

/* interface IFolderTree */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFolderTree;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25150F43-5734-11d2-A593-00C04F990D8A")
    IFolderTree : public IDispatch
    {
    public:
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DataSource( 
            /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Fields( 
            /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR varName) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StoreDBs( 
            /* [retval][out] */ VARIANT __RPC_FAR *varStoreDBs) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TreeType( 
            /* [retval][out] */ CDOEXMFolderTreeType __RPC_FAR *varTreeType) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RootFolderURL( 
            /* [retval][out] */ BSTR __RPC_FAR *varRootFolderURL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInterface( 
            /* [in] */ BSTR Interface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFolderTreeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IFolderTree __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IFolderTree __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IFolderTree __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IFolderTree __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IFolderTree __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IFolderTree __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IFolderTree __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DataSource )( 
            IFolderTree __RPC_FAR * This,
            /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Fields )( 
            IFolderTree __RPC_FAR * This,
            /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IFolderTree __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IFolderTree __RPC_FAR * This,
            /* [in] */ BSTR varName);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StoreDBs )( 
            IFolderTree __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *varStoreDBs);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TreeType )( 
            IFolderTree __RPC_FAR * This,
            /* [retval][out] */ CDOEXMFolderTreeType __RPC_FAR *varTreeType);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RootFolderURL )( 
            IFolderTree __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varRootFolderURL);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInterface )( 
            IFolderTree __RPC_FAR * This,
            /* [in] */ BSTR Interface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown);
        
        END_INTERFACE
    } IFolderTreeVtbl;

    interface IFolderTree
    {
        CONST_VTBL struct IFolderTreeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFolderTree_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFolderTree_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFolderTree_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFolderTree_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFolderTree_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFolderTree_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFolderTree_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFolderTree_get_DataSource(This,varDataSource)	\
    (This)->lpVtbl -> get_DataSource(This,varDataSource)

#define IFolderTree_get_Fields(This,varFields)	\
    (This)->lpVtbl -> get_Fields(This,varFields)

#define IFolderTree_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IFolderTree_put_Name(This,varName)	\
    (This)->lpVtbl -> put_Name(This,varName)

#define IFolderTree_get_StoreDBs(This,varStoreDBs)	\
    (This)->lpVtbl -> get_StoreDBs(This,varStoreDBs)

#define IFolderTree_get_TreeType(This,varTreeType)	\
    (This)->lpVtbl -> get_TreeType(This,varTreeType)

#define IFolderTree_get_RootFolderURL(This,varRootFolderURL)	\
    (This)->lpVtbl -> get_RootFolderURL(This,varRootFolderURL)

#define IFolderTree_GetInterface(This,Interface,ppUnknown)	\
    (This)->lpVtbl -> GetInterface(This,Interface,ppUnknown)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IFolderTree_get_DataSource_Proxy( 
    IFolderTree __RPC_FAR * This,
    /* [retval][out] */ IDataSource2 __RPC_FAR *__RPC_FAR *varDataSource);


void __RPC_STUB IFolderTree_get_DataSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IFolderTree_get_Fields_Proxy( 
    IFolderTree __RPC_FAR * This,
    /* [retval][out] */ Fields __RPC_FAR *__RPC_FAR *varFields);


void __RPC_STUB IFolderTree_get_Fields_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IFolderTree_get_Name_Proxy( 
    IFolderTree __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pName);


void __RPC_STUB IFolderTree_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IFolderTree_put_Name_Proxy( 
    IFolderTree __RPC_FAR * This,
    /* [in] */ BSTR varName);


void __RPC_STUB IFolderTree_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IFolderTree_get_StoreDBs_Proxy( 
    IFolderTree __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *varStoreDBs);


void __RPC_STUB IFolderTree_get_StoreDBs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IFolderTree_get_TreeType_Proxy( 
    IFolderTree __RPC_FAR * This,
    /* [retval][out] */ CDOEXMFolderTreeType __RPC_FAR *varTreeType);


void __RPC_STUB IFolderTree_get_TreeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IFolderTree_get_RootFolderURL_Proxy( 
    IFolderTree __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varRootFolderURL);


void __RPC_STUB IFolderTree_get_RootFolderURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFolderTree_GetInterface_Proxy( 
    IFolderTree __RPC_FAR * This,
    /* [in] */ BSTR Interface,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppUnknown);


void __RPC_STUB IFolderTree_GetInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFolderTree_INTERFACE_DEFINED__ */


#ifndef __IDataSource2_INTERFACE_DEFINED__
#define __IDataSource2_INTERFACE_DEFINED__

/* interface IDataSource2 */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDataSource2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25150F48-5734-11d2-A593-00C04F990D8A")
    IDataSource2 : public IDataSource
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveToContainer( 
            /* [in] */ BSTR ContainerURL) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDataSource2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDataSource2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDataSource2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDataSource2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDataSource2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDataSource2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDataSource2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDataSource2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [readonly][helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SourceClass )( 
            IDataSource2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varSourceClass);
        
        /* [readonly][helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Source )( 
            IDataSource2 __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *varSource);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsDirty )( 
            IDataSource2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsDirty);
        
        /* [helpcontext][helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IsDirty )( 
            IDataSource2 __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varIsDirty);
        
        /* [readonly][helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SourceURL )( 
            IDataSource2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varSourceURL);
        
        /* [readonly][helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActiveConnection )( 
            IDataSource2 __RPC_FAR * This,
            /* [retval][out] */ _Connection __RPC_FAR *__RPC_FAR *varActiveConnection);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveToObject )( 
            IDataSource2 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *Source,
            /* [in] */ BSTR InterfaceName);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenObject )( 
            IDataSource2 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *Source,
            /* [in] */ BSTR InterfaceName);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveTo )( 
            IDataSource2 __RPC_FAR * This,
            /* [in] */ BSTR SourceURL,
            /* [defaultvalue][in] */ IDispatch __RPC_FAR *ActiveConnection,
            /* [optional][in] */ ConnectModeEnum Mode,
            /* [optional][in] */ RecordCreateOptionsEnum CreateOptions,
            /* [optional][in] */ RecordOpenOptionsEnum Options,
            /* [optional][in] */ BSTR UserName,
            /* [optional][in] */ BSTR Password);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IDataSource2 __RPC_FAR * This,
            /* [in] */ BSTR SourceURL,
            /* [defaultvalue][in] */ IDispatch __RPC_FAR *ActiveConnection,
            /* [optional][in] */ ConnectModeEnum Mode,
            /* [defaultvalue][in] */ RecordCreateOptionsEnum CreateOptions,
            /* [optional][in] */ RecordOpenOptionsEnum Options,
            /* [optional][in] */ BSTR UserName,
            /* [optional][in] */ BSTR Password);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IDataSource2 __RPC_FAR * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveToContainer )( 
            IDataSource2 __RPC_FAR * This,
            /* [in] */ BSTR ContainerURL,
            /* [defaultvalue][in] */ IDispatch __RPC_FAR *ActiveConnection,
            /* [optional][in] */ ConnectModeEnum Mode,
            /* [optional][in] */ RecordCreateOptionsEnum CreateOptions,
            /* [optional][in] */ RecordOpenOptionsEnum Options,
            /* [optional][in] */ BSTR UserName,
            /* [optional][in] */ BSTR Password);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IDataSource2 __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveToContainer )( 
            IDataSource2 __RPC_FAR * This,
            /* [in] */ BSTR ContainerURL);
        
        END_INTERFACE
    } IDataSource2Vtbl;

    interface IDataSource2
    {
        CONST_VTBL struct IDataSource2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataSource2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDataSource2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDataSource2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDataSource2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDataSource2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDataSource2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDataSource2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDataSource2_get_SourceClass(This,varSourceClass)	\
    (This)->lpVtbl -> get_SourceClass(This,varSourceClass)

#define IDataSource2_get_Source(This,varSource)	\
    (This)->lpVtbl -> get_Source(This,varSource)

#define IDataSource2_get_IsDirty(This,pIsDirty)	\
    (This)->lpVtbl -> get_IsDirty(This,pIsDirty)

#define IDataSource2_put_IsDirty(This,varIsDirty)	\
    (This)->lpVtbl -> put_IsDirty(This,varIsDirty)

#define IDataSource2_get_SourceURL(This,varSourceURL)	\
    (This)->lpVtbl -> get_SourceURL(This,varSourceURL)

#define IDataSource2_get_ActiveConnection(This,varActiveConnection)	\
    (This)->lpVtbl -> get_ActiveConnection(This,varActiveConnection)

#define IDataSource2_SaveToObject(This,Source,InterfaceName)	\
    (This)->lpVtbl -> SaveToObject(This,Source,InterfaceName)

#define IDataSource2_OpenObject(This,Source,InterfaceName)	\
    (This)->lpVtbl -> OpenObject(This,Source,InterfaceName)

#define IDataSource2_SaveTo(This,SourceURL,ActiveConnection,Mode,CreateOptions,Options,UserName,Password)	\
    (This)->lpVtbl -> SaveTo(This,SourceURL,ActiveConnection,Mode,CreateOptions,Options,UserName,Password)

#define IDataSource2_Open(This,SourceURL,ActiveConnection,Mode,CreateOptions,Options,UserName,Password)	\
    (This)->lpVtbl -> Open(This,SourceURL,ActiveConnection,Mode,CreateOptions,Options,UserName,Password)

#define IDataSource2_Save(This)	\
    (This)->lpVtbl -> Save(This)

#define IDataSource2_SaveToContainer(This,ContainerURL,ActiveConnection,Mode,CreateOptions,Options,UserName,Password)	\
    (This)->lpVtbl -> SaveToContainer(This,ContainerURL,ActiveConnection,Mode,CreateOptions,Options,UserName,Password)


#define IDataSource2_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IDataSource2_MoveToContainer(This,ContainerURL)	\
    (This)->lpVtbl -> MoveToContainer(This,ContainerURL)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataSource2_Delete_Proxy( 
    IDataSource2 __RPC_FAR * This);


void __RPC_STUB IDataSource2_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataSource2_MoveToContainer_Proxy( 
    IDataSource2 __RPC_FAR * This,
    /* [in] */ BSTR ContainerURL);


void __RPC_STUB IDataSource2_MoveToContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDataSource2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


