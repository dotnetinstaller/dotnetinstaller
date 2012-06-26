
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0279 */
/* at Wed Dec 13 23:45:28 2000
 */
/* Compiler settings for P:\admin\src\libs\emolib\CDOEXM.idl:
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

#ifndef __CDOEXM_h__
#define __CDOEXM_h__

/* Forward Declarations */ 

#ifndef __IDistributionList_FWD_DEFINED__
#define __IDistributionList_FWD_DEFINED__
typedef interface IDistributionList IDistributionList;
#endif 	/* __IDistributionList_FWD_DEFINED__ */


#ifndef __IMailRecipient_FWD_DEFINED__
#define __IMailRecipient_FWD_DEFINED__
typedef interface IMailRecipient IMailRecipient;
#endif 	/* __IMailRecipient_FWD_DEFINED__ */


#ifndef __IMailboxStore_FWD_DEFINED__
#define __IMailboxStore_FWD_DEFINED__
typedef interface IMailboxStore IMailboxStore;
#endif 	/* __IMailboxStore_FWD_DEFINED__ */


#ifndef __MailGroup_FWD_DEFINED__
#define __MailGroup_FWD_DEFINED__

#ifdef __cplusplus
typedef class MailGroup MailGroup;
#else
typedef struct MailGroup MailGroup;
#endif /* __cplusplus */

#endif 	/* __MailGroup_FWD_DEFINED__ */


#ifndef __MailRecipient_FWD_DEFINED__
#define __MailRecipient_FWD_DEFINED__

#ifdef __cplusplus
typedef class MailRecipient MailRecipient;
#else
typedef struct MailRecipient MailRecipient;
#endif /* __cplusplus */

#endif 	/* __MailRecipient_FWD_DEFINED__ */


#ifndef __Mailbox_FWD_DEFINED__
#define __Mailbox_FWD_DEFINED__

#ifdef __cplusplus
typedef class Mailbox Mailbox;
#else
typedef struct Mailbox Mailbox;
#endif /* __cplusplus */

#endif 	/* __Mailbox_FWD_DEFINED__ */


#ifndef __FolderAdmin_FWD_DEFINED__
#define __FolderAdmin_FWD_DEFINED__

#ifdef __cplusplus
typedef class FolderAdmin FolderAdmin;
#else
typedef struct FolderAdmin FolderAdmin;
#endif /* __cplusplus */

#endif 	/* __FolderAdmin_FWD_DEFINED__ */


#ifndef __ExchangeServer_FWD_DEFINED__
#define __ExchangeServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class ExchangeServer ExchangeServer;
#else
typedef struct ExchangeServer ExchangeServer;
#endif /* __cplusplus */

#endif 	/* __ExchangeServer_FWD_DEFINED__ */


#ifndef __FolderTree_FWD_DEFINED__
#define __FolderTree_FWD_DEFINED__

#ifdef __cplusplus
typedef class FolderTree FolderTree;
#else
typedef struct FolderTree FolderTree;
#endif /* __cplusplus */

#endif 	/* __FolderTree_FWD_DEFINED__ */


#ifndef __PublicStoreDB_FWD_DEFINED__
#define __PublicStoreDB_FWD_DEFINED__

#ifdef __cplusplus
typedef class PublicStoreDB PublicStoreDB;
#else
typedef struct PublicStoreDB PublicStoreDB;
#endif /* __cplusplus */

#endif 	/* __PublicStoreDB_FWD_DEFINED__ */


#ifndef __MailboxStoreDB_FWD_DEFINED__
#define __MailboxStoreDB_FWD_DEFINED__

#ifdef __cplusplus
typedef class MailboxStoreDB MailboxStoreDB;
#else
typedef struct MailboxStoreDB MailboxStoreDB;
#endif /* __cplusplus */

#endif 	/* __MailboxStoreDB_FWD_DEFINED__ */


#ifndef __StorageGroup_FWD_DEFINED__
#define __StorageGroup_FWD_DEFINED__

#ifdef __cplusplus
typedef class StorageGroup StorageGroup;
#else
typedef struct StorageGroup StorageGroup;
#endif /* __cplusplus */

#endif 	/* __StorageGroup_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_CDOEXM_0000 */
/* [local] */ 

#ifndef NO_CDOEX_H
#define CDO_NO_NAMESPACE
#include "cdoex.h"
#endif
#include "emostore.h"



typedef 
enum CDOEXMRestrictedAddressType
    {	cdoexmAccept	= 0,
	cdoexmReject	= 0x1
    }	CDOEXMRestrictedAddressType;

typedef 
enum CDOEXMDeliverAndRedirect
    {	cdoexmRecipientOrForward	= 0,
	cdoexmDeliverToBoth	= 0x1
    }	CDOEXMDeliverAndRedirect;



extern RPC_IF_HANDLE __MIDL_itf_CDOEXM_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_CDOEXM_0000_v0_0_s_ifspec;


#ifndef __CDOEXM_LIBRARY_DEFINED__
#define __CDOEXM_LIBRARY_DEFINED__

/* library CDOEXM */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_CDOEXM;

#ifndef __IDistributionList_INTERFACE_DEFINED__
#define __IDistributionList_INTERFACE_DEFINED__

/* interface IDistributionList */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDistributionList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25150F3F-5734-11d2-A593-00C04F990D8A")
    IDistributionList : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HideDLMembership( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pHideDLMembership) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HideDLMembership( 
            /* [in] */ VARIANT_BOOL varHideDLMembership) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDistributionListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDistributionList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDistributionList __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDistributionList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDistributionList __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDistributionList __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDistributionList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDistributionList __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HideDLMembership )( 
            IDistributionList __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pHideDLMembership);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HideDLMembership )( 
            IDistributionList __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varHideDLMembership);
        
        END_INTERFACE
    } IDistributionListVtbl;

    interface IDistributionList
    {
        CONST_VTBL struct IDistributionListVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDistributionList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDistributionList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDistributionList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDistributionList_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDistributionList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDistributionList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDistributionList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDistributionList_get_HideDLMembership(This,pHideDLMembership)	\
    (This)->lpVtbl -> get_HideDLMembership(This,pHideDLMembership)

#define IDistributionList_put_HideDLMembership(This,varHideDLMembership)	\
    (This)->lpVtbl -> put_HideDLMembership(This,varHideDLMembership)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IDistributionList_get_HideDLMembership_Proxy( 
    IDistributionList __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pHideDLMembership);


void __RPC_STUB IDistributionList_get_HideDLMembership_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IDistributionList_put_HideDLMembership_Proxy( 
    IDistributionList __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varHideDLMembership);


void __RPC_STUB IDistributionList_put_HideDLMembership_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDistributionList_INTERFACE_DEFINED__ */


#ifndef __IMailRecipient_INTERFACE_DEFINED__
#define __IMailRecipient_INTERFACE_DEFINED__

/* interface IMailRecipient */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMailRecipient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25150F40-5734-11d2-A593-00C04F990D8A")
    IMailRecipient : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IncomingLimit( 
            /* [retval][out] */ long __RPC_FAR *pIncomingLimit) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_IncomingLimit( 
            /* [in] */ long varIncomingLimit) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OutgoingLimit( 
            /* [retval][out] */ long __RPC_FAR *pOutgoingLimit) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_OutgoingLimit( 
            /* [in] */ long varOutgoingLimit) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RestrictedAddressList( 
            /* [retval][out] */ VARIANT __RPC_FAR *pRestrictedAddressList) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_RestrictedAddressList( 
            /* [in] */ VARIANT varRestrictedAddressList) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RestrictedAddresses( 
            /* [retval][out] */ CDOEXMRestrictedAddressType __RPC_FAR *pRestrictedAddresses) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_RestrictedAddresses( 
            /* [in] */ CDOEXMRestrictedAddressType varRestrictedAddresses) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ForwardTo( 
            /* [retval][out] */ BSTR __RPC_FAR *pForwardTo) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ForwardTo( 
            /* [in] */ BSTR varForwardTo) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ForwardingStyle( 
            /* [retval][out] */ CDOEXMDeliverAndRedirect __RPC_FAR *pForwardingStyle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ForwardingStyle( 
            /* [in] */ CDOEXMDeliverAndRedirect varForwardingStyle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HideFromAddressBook( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pHideFromAddressBook) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HideFromAddressBook( 
            /* [in] */ VARIANT_BOOL varHideFromAddressBook) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_X400Email( 
            /* [retval][out] */ BSTR __RPC_FAR *pX400Email) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_X400Email( 
            /* [in] */ BSTR varX400Email) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SMTPEmail( 
            /* [retval][out] */ BSTR __RPC_FAR *pSMTPEmail) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SMTPEmail( 
            /* [in] */ BSTR varSMTPEmail) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ProxyAddresses( 
            /* [retval][out] */ VARIANT __RPC_FAR *pProxyAddresses) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ProxyAddresses( 
            /* [in] */ VARIANT varProxyAddresses) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoGenerateEmailAddresses( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pAutoGenerateEmailAddresses) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoGenerateEmailAddresses( 
            /* [in] */ VARIANT_BOOL varAutoGenerateEmailAddresses) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Alias( 
            /* [retval][out] */ BSTR __RPC_FAR *pAlias) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Alias( 
            /* [in] */ BSTR varAlias) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TargetAddress( 
            /* [retval][out] */ BSTR __RPC_FAR *varTargetAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MailEnable( 
            /* [optional][in] */ BSTR TargetMailAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MailDisable( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMailRecipientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMailRecipient __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMailRecipient __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IMailRecipient __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IncomingLimit )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pIncomingLimit);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IncomingLimit )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ long varIncomingLimit);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OutgoingLimit )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pOutgoingLimit);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OutgoingLimit )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ long varOutgoingLimit);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RestrictedAddressList )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pRestrictedAddressList);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RestrictedAddressList )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ VARIANT varRestrictedAddressList);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RestrictedAddresses )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ CDOEXMRestrictedAddressType __RPC_FAR *pRestrictedAddresses);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RestrictedAddresses )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ CDOEXMRestrictedAddressType varRestrictedAddresses);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForwardTo )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pForwardTo);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ForwardTo )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ BSTR varForwardTo);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForwardingStyle )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ CDOEXMDeliverAndRedirect __RPC_FAR *pForwardingStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ForwardingStyle )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ CDOEXMDeliverAndRedirect varForwardingStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HideFromAddressBook )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pHideFromAddressBook);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HideFromAddressBook )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varHideFromAddressBook);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_X400Email )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pX400Email);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_X400Email )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ BSTR varX400Email);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SMTPEmail )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pSMTPEmail);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SMTPEmail )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ BSTR varSMTPEmail);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProxyAddresses )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pProxyAddresses);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProxyAddresses )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ VARIANT varProxyAddresses);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AutoGenerateEmailAddresses )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pAutoGenerateEmailAddresses);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AutoGenerateEmailAddresses )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varAutoGenerateEmailAddresses);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alias )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pAlias);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Alias )( 
            IMailRecipient __RPC_FAR * This,
            /* [in] */ BSTR varAlias);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TargetAddress )( 
            IMailRecipient __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varTargetAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MailEnable )( 
            IMailRecipient __RPC_FAR * This,
            /* [optional][in] */ BSTR TargetMailAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MailDisable )( 
            IMailRecipient __RPC_FAR * This);
        
        END_INTERFACE
    } IMailRecipientVtbl;

    interface IMailRecipient
    {
        CONST_VTBL struct IMailRecipientVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMailRecipient_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMailRecipient_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMailRecipient_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMailRecipient_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMailRecipient_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMailRecipient_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMailRecipient_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMailRecipient_get_IncomingLimit(This,pIncomingLimit)	\
    (This)->lpVtbl -> get_IncomingLimit(This,pIncomingLimit)

#define IMailRecipient_put_IncomingLimit(This,varIncomingLimit)	\
    (This)->lpVtbl -> put_IncomingLimit(This,varIncomingLimit)

#define IMailRecipient_get_OutgoingLimit(This,pOutgoingLimit)	\
    (This)->lpVtbl -> get_OutgoingLimit(This,pOutgoingLimit)

#define IMailRecipient_put_OutgoingLimit(This,varOutgoingLimit)	\
    (This)->lpVtbl -> put_OutgoingLimit(This,varOutgoingLimit)

#define IMailRecipient_get_RestrictedAddressList(This,pRestrictedAddressList)	\
    (This)->lpVtbl -> get_RestrictedAddressList(This,pRestrictedAddressList)

#define IMailRecipient_put_RestrictedAddressList(This,varRestrictedAddressList)	\
    (This)->lpVtbl -> put_RestrictedAddressList(This,varRestrictedAddressList)

#define IMailRecipient_get_RestrictedAddresses(This,pRestrictedAddresses)	\
    (This)->lpVtbl -> get_RestrictedAddresses(This,pRestrictedAddresses)

#define IMailRecipient_put_RestrictedAddresses(This,varRestrictedAddresses)	\
    (This)->lpVtbl -> put_RestrictedAddresses(This,varRestrictedAddresses)

#define IMailRecipient_get_ForwardTo(This,pForwardTo)	\
    (This)->lpVtbl -> get_ForwardTo(This,pForwardTo)

#define IMailRecipient_put_ForwardTo(This,varForwardTo)	\
    (This)->lpVtbl -> put_ForwardTo(This,varForwardTo)

#define IMailRecipient_get_ForwardingStyle(This,pForwardingStyle)	\
    (This)->lpVtbl -> get_ForwardingStyle(This,pForwardingStyle)

#define IMailRecipient_put_ForwardingStyle(This,varForwardingStyle)	\
    (This)->lpVtbl -> put_ForwardingStyle(This,varForwardingStyle)

#define IMailRecipient_get_HideFromAddressBook(This,pHideFromAddressBook)	\
    (This)->lpVtbl -> get_HideFromAddressBook(This,pHideFromAddressBook)

#define IMailRecipient_put_HideFromAddressBook(This,varHideFromAddressBook)	\
    (This)->lpVtbl -> put_HideFromAddressBook(This,varHideFromAddressBook)

#define IMailRecipient_get_X400Email(This,pX400Email)	\
    (This)->lpVtbl -> get_X400Email(This,pX400Email)

#define IMailRecipient_put_X400Email(This,varX400Email)	\
    (This)->lpVtbl -> put_X400Email(This,varX400Email)

#define IMailRecipient_get_SMTPEmail(This,pSMTPEmail)	\
    (This)->lpVtbl -> get_SMTPEmail(This,pSMTPEmail)

#define IMailRecipient_put_SMTPEmail(This,varSMTPEmail)	\
    (This)->lpVtbl -> put_SMTPEmail(This,varSMTPEmail)

#define IMailRecipient_get_ProxyAddresses(This,pProxyAddresses)	\
    (This)->lpVtbl -> get_ProxyAddresses(This,pProxyAddresses)

#define IMailRecipient_put_ProxyAddresses(This,varProxyAddresses)	\
    (This)->lpVtbl -> put_ProxyAddresses(This,varProxyAddresses)

#define IMailRecipient_get_AutoGenerateEmailAddresses(This,pAutoGenerateEmailAddresses)	\
    (This)->lpVtbl -> get_AutoGenerateEmailAddresses(This,pAutoGenerateEmailAddresses)

#define IMailRecipient_put_AutoGenerateEmailAddresses(This,varAutoGenerateEmailAddresses)	\
    (This)->lpVtbl -> put_AutoGenerateEmailAddresses(This,varAutoGenerateEmailAddresses)

#define IMailRecipient_get_Alias(This,pAlias)	\
    (This)->lpVtbl -> get_Alias(This,pAlias)

#define IMailRecipient_put_Alias(This,varAlias)	\
    (This)->lpVtbl -> put_Alias(This,varAlias)

#define IMailRecipient_get_TargetAddress(This,varTargetAddress)	\
    (This)->lpVtbl -> get_TargetAddress(This,varTargetAddress)

#define IMailRecipient_MailEnable(This,TargetMailAddress)	\
    (This)->lpVtbl -> MailEnable(This,TargetMailAddress)

#define IMailRecipient_MailDisable(This)	\
    (This)->lpVtbl -> MailDisable(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_IncomingLimit_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pIncomingLimit);


void __RPC_STUB IMailRecipient_get_IncomingLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_IncomingLimit_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ long varIncomingLimit);


void __RPC_STUB IMailRecipient_put_IncomingLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_OutgoingLimit_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pOutgoingLimit);


void __RPC_STUB IMailRecipient_get_OutgoingLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_OutgoingLimit_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ long varOutgoingLimit);


void __RPC_STUB IMailRecipient_put_OutgoingLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_RestrictedAddressList_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pRestrictedAddressList);


void __RPC_STUB IMailRecipient_get_RestrictedAddressList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_RestrictedAddressList_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ VARIANT varRestrictedAddressList);


void __RPC_STUB IMailRecipient_put_RestrictedAddressList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_RestrictedAddresses_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ CDOEXMRestrictedAddressType __RPC_FAR *pRestrictedAddresses);


void __RPC_STUB IMailRecipient_get_RestrictedAddresses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_RestrictedAddresses_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ CDOEXMRestrictedAddressType varRestrictedAddresses);


void __RPC_STUB IMailRecipient_put_RestrictedAddresses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_ForwardTo_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pForwardTo);


void __RPC_STUB IMailRecipient_get_ForwardTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_ForwardTo_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ BSTR varForwardTo);


void __RPC_STUB IMailRecipient_put_ForwardTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_ForwardingStyle_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ CDOEXMDeliverAndRedirect __RPC_FAR *pForwardingStyle);


void __RPC_STUB IMailRecipient_get_ForwardingStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_ForwardingStyle_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ CDOEXMDeliverAndRedirect varForwardingStyle);


void __RPC_STUB IMailRecipient_put_ForwardingStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_HideFromAddressBook_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pHideFromAddressBook);


void __RPC_STUB IMailRecipient_get_HideFromAddressBook_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_HideFromAddressBook_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varHideFromAddressBook);


void __RPC_STUB IMailRecipient_put_HideFromAddressBook_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_X400Email_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pX400Email);


void __RPC_STUB IMailRecipient_get_X400Email_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_X400Email_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ BSTR varX400Email);


void __RPC_STUB IMailRecipient_put_X400Email_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_SMTPEmail_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pSMTPEmail);


void __RPC_STUB IMailRecipient_get_SMTPEmail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_SMTPEmail_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ BSTR varSMTPEmail);


void __RPC_STUB IMailRecipient_put_SMTPEmail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_ProxyAddresses_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pProxyAddresses);


void __RPC_STUB IMailRecipient_get_ProxyAddresses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_ProxyAddresses_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ VARIANT varProxyAddresses);


void __RPC_STUB IMailRecipient_put_ProxyAddresses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_AutoGenerateEmailAddresses_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pAutoGenerateEmailAddresses);


void __RPC_STUB IMailRecipient_get_AutoGenerateEmailAddresses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_AutoGenerateEmailAddresses_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varAutoGenerateEmailAddresses);


void __RPC_STUB IMailRecipient_put_AutoGenerateEmailAddresses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_Alias_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pAlias);


void __RPC_STUB IMailRecipient_get_Alias_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_put_Alias_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [in] */ BSTR varAlias);


void __RPC_STUB IMailRecipient_put_Alias_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_get_TargetAddress_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varTargetAddress);


void __RPC_STUB IMailRecipient_get_TargetAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_MailEnable_Proxy( 
    IMailRecipient __RPC_FAR * This,
    /* [optional][in] */ BSTR TargetMailAddress);


void __RPC_STUB IMailRecipient_MailEnable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMailRecipient_MailDisable_Proxy( 
    IMailRecipient __RPC_FAR * This);


void __RPC_STUB IMailRecipient_MailDisable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMailRecipient_INTERFACE_DEFINED__ */


#ifndef __IMailboxStore_INTERFACE_DEFINED__
#define __IMailboxStore_INTERFACE_DEFINED__

/* interface IMailboxStore */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMailboxStore;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25150F41-5734-11d2-A593-00C04F990D8A")
    IMailboxStore : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnableStoreDefaults( 
            /* [retval][out] */ VARIANT __RPC_FAR *pEnableStoreDefaults) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EnableStoreDefaults( 
            /* [in] */ VARIANT varEnableStoreDefaults) = 0;
        
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
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OverrideStoreGarbageCollection( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pOverrideStoreGarbageCollection) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_OverrideStoreGarbageCollection( 
            /* [in] */ VARIANT_BOOL varOverrideStoreGarbageCollection) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DaysBeforeGarbageCollection( 
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeGarbageCollection) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DaysBeforeGarbageCollection( 
            /* [in] */ long varDaysBeforeGarbageCollection) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GarbageCollectOnlyAfterBackup( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pGarbageCollectOnlyAfterBackup) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GarbageCollectOnlyAfterBackup( 
            /* [in] */ VARIANT_BOOL varGarbageCollectOnlyAfterBackup) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Delegates( 
            /* [retval][out] */ VARIANT __RPC_FAR *pDelegates) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Delegates( 
            /* [in] */ VARIANT varDelegates) = 0;
        
        virtual /* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HomeMDB( 
            /* [retval][out] */ BSTR __RPC_FAR *varHomeMDB) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RecipientLimit( 
            /* [retval][out] */ long __RPC_FAR *pRecipientLimit) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_RecipientLimit( 
            /* [in] */ long varRecipientLimit) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateMailbox( 
            /* [in] */ BSTR HomeMDBURL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteMailbox( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveMailbox( 
            /* [in] */ BSTR HomeMDBURL) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMailboxStoreVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMailboxStore __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMailboxStore __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IMailboxStore __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EnableStoreDefaults )( 
            IMailboxStore __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pEnableStoreDefaults);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_EnableStoreDefaults )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ VARIANT varEnableStoreDefaults);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StoreQuota )( 
            IMailboxStore __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pStoreQuota);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StoreQuota )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ long varStoreQuota);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OverQuotaLimit )( 
            IMailboxStore __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pOverQuotaLimit);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OverQuotaLimit )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ long varOverQuotaLimit);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HardLimit )( 
            IMailboxStore __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pHardLimit);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HardLimit )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ long varHardLimit);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OverrideStoreGarbageCollection )( 
            IMailboxStore __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pOverrideStoreGarbageCollection);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OverrideStoreGarbageCollection )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varOverrideStoreGarbageCollection);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DaysBeforeGarbageCollection )( 
            IMailboxStore __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pDaysBeforeGarbageCollection);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DaysBeforeGarbageCollection )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ long varDaysBeforeGarbageCollection);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GarbageCollectOnlyAfterBackup )( 
            IMailboxStore __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pGarbageCollectOnlyAfterBackup);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GarbageCollectOnlyAfterBackup )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL varGarbageCollectOnlyAfterBackup);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Delegates )( 
            IMailboxStore __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pDelegates);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Delegates )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ VARIANT varDelegates);
        
        /* [readonly][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HomeMDB )( 
            IMailboxStore __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *varHomeMDB);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RecipientLimit )( 
            IMailboxStore __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRecipientLimit);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RecipientLimit )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ long varRecipientLimit);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateMailbox )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ BSTR HomeMDBURL);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteMailbox )( 
            IMailboxStore __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveMailbox )( 
            IMailboxStore __RPC_FAR * This,
            /* [in] */ BSTR HomeMDBURL);
        
        END_INTERFACE
    } IMailboxStoreVtbl;

    interface IMailboxStore
    {
        CONST_VTBL struct IMailboxStoreVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMailboxStore_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMailboxStore_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMailboxStore_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMailboxStore_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMailboxStore_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMailboxStore_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMailboxStore_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMailboxStore_get_EnableStoreDefaults(This,pEnableStoreDefaults)	\
    (This)->lpVtbl -> get_EnableStoreDefaults(This,pEnableStoreDefaults)

#define IMailboxStore_put_EnableStoreDefaults(This,varEnableStoreDefaults)	\
    (This)->lpVtbl -> put_EnableStoreDefaults(This,varEnableStoreDefaults)

#define IMailboxStore_get_StoreQuota(This,pStoreQuota)	\
    (This)->lpVtbl -> get_StoreQuota(This,pStoreQuota)

#define IMailboxStore_put_StoreQuota(This,varStoreQuota)	\
    (This)->lpVtbl -> put_StoreQuota(This,varStoreQuota)

#define IMailboxStore_get_OverQuotaLimit(This,pOverQuotaLimit)	\
    (This)->lpVtbl -> get_OverQuotaLimit(This,pOverQuotaLimit)

#define IMailboxStore_put_OverQuotaLimit(This,varOverQuotaLimit)	\
    (This)->lpVtbl -> put_OverQuotaLimit(This,varOverQuotaLimit)

#define IMailboxStore_get_HardLimit(This,pHardLimit)	\
    (This)->lpVtbl -> get_HardLimit(This,pHardLimit)

#define IMailboxStore_put_HardLimit(This,varHardLimit)	\
    (This)->lpVtbl -> put_HardLimit(This,varHardLimit)

#define IMailboxStore_get_OverrideStoreGarbageCollection(This,pOverrideStoreGarbageCollection)	\
    (This)->lpVtbl -> get_OverrideStoreGarbageCollection(This,pOverrideStoreGarbageCollection)

#define IMailboxStore_put_OverrideStoreGarbageCollection(This,varOverrideStoreGarbageCollection)	\
    (This)->lpVtbl -> put_OverrideStoreGarbageCollection(This,varOverrideStoreGarbageCollection)

#define IMailboxStore_get_DaysBeforeGarbageCollection(This,pDaysBeforeGarbageCollection)	\
    (This)->lpVtbl -> get_DaysBeforeGarbageCollection(This,pDaysBeforeGarbageCollection)

#define IMailboxStore_put_DaysBeforeGarbageCollection(This,varDaysBeforeGarbageCollection)	\
    (This)->lpVtbl -> put_DaysBeforeGarbageCollection(This,varDaysBeforeGarbageCollection)

#define IMailboxStore_get_GarbageCollectOnlyAfterBackup(This,pGarbageCollectOnlyAfterBackup)	\
    (This)->lpVtbl -> get_GarbageCollectOnlyAfterBackup(This,pGarbageCollectOnlyAfterBackup)

#define IMailboxStore_put_GarbageCollectOnlyAfterBackup(This,varGarbageCollectOnlyAfterBackup)	\
    (This)->lpVtbl -> put_GarbageCollectOnlyAfterBackup(This,varGarbageCollectOnlyAfterBackup)

#define IMailboxStore_get_Delegates(This,pDelegates)	\
    (This)->lpVtbl -> get_Delegates(This,pDelegates)

#define IMailboxStore_put_Delegates(This,varDelegates)	\
    (This)->lpVtbl -> put_Delegates(This,varDelegates)

#define IMailboxStore_get_HomeMDB(This,varHomeMDB)	\
    (This)->lpVtbl -> get_HomeMDB(This,varHomeMDB)

#define IMailboxStore_get_RecipientLimit(This,pRecipientLimit)	\
    (This)->lpVtbl -> get_RecipientLimit(This,pRecipientLimit)

#define IMailboxStore_put_RecipientLimit(This,varRecipientLimit)	\
    (This)->lpVtbl -> put_RecipientLimit(This,varRecipientLimit)

#define IMailboxStore_CreateMailbox(This,HomeMDBURL)	\
    (This)->lpVtbl -> CreateMailbox(This,HomeMDBURL)

#define IMailboxStore_DeleteMailbox(This)	\
    (This)->lpVtbl -> DeleteMailbox(This)

#define IMailboxStore_MoveMailbox(This,HomeMDBURL)	\
    (This)->lpVtbl -> MoveMailbox(This,HomeMDBURL)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_get_EnableStoreDefaults_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pEnableStoreDefaults);


void __RPC_STUB IMailboxStore_get_EnableStoreDefaults_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_put_EnableStoreDefaults_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [in] */ VARIANT varEnableStoreDefaults);


void __RPC_STUB IMailboxStore_put_EnableStoreDefaults_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_get_StoreQuota_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pStoreQuota);


void __RPC_STUB IMailboxStore_get_StoreQuota_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_put_StoreQuota_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [in] */ long varStoreQuota);


void __RPC_STUB IMailboxStore_put_StoreQuota_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_get_OverQuotaLimit_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pOverQuotaLimit);


void __RPC_STUB IMailboxStore_get_OverQuotaLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_put_OverQuotaLimit_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [in] */ long varOverQuotaLimit);


void __RPC_STUB IMailboxStore_put_OverQuotaLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_get_HardLimit_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pHardLimit);


void __RPC_STUB IMailboxStore_get_HardLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_put_HardLimit_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [in] */ long varHardLimit);


void __RPC_STUB IMailboxStore_put_HardLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_get_OverrideStoreGarbageCollection_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pOverrideStoreGarbageCollection);


void __RPC_STUB IMailboxStore_get_OverrideStoreGarbageCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_put_OverrideStoreGarbageCollection_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varOverrideStoreGarbageCollection);


void __RPC_STUB IMailboxStore_put_OverrideStoreGarbageCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_get_DaysBeforeGarbageCollection_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pDaysBeforeGarbageCollection);


void __RPC_STUB IMailboxStore_get_DaysBeforeGarbageCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_put_DaysBeforeGarbageCollection_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [in] */ long varDaysBeforeGarbageCollection);


void __RPC_STUB IMailboxStore_put_DaysBeforeGarbageCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_get_GarbageCollectOnlyAfterBackup_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pGarbageCollectOnlyAfterBackup);


void __RPC_STUB IMailboxStore_get_GarbageCollectOnlyAfterBackup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_put_GarbageCollectOnlyAfterBackup_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL varGarbageCollectOnlyAfterBackup);


void __RPC_STUB IMailboxStore_put_GarbageCollectOnlyAfterBackup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_get_Delegates_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pDelegates);


void __RPC_STUB IMailboxStore_get_Delegates_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_put_Delegates_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [in] */ VARIANT varDelegates);


void __RPC_STUB IMailboxStore_put_Delegates_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [readonly][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_get_HomeMDB_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *varHomeMDB);


void __RPC_STUB IMailboxStore_get_HomeMDB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_get_RecipientLimit_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRecipientLimit);


void __RPC_STUB IMailboxStore_get_RecipientLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_put_RecipientLimit_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [in] */ long varRecipientLimit);


void __RPC_STUB IMailboxStore_put_RecipientLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_CreateMailbox_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [in] */ BSTR HomeMDBURL);


void __RPC_STUB IMailboxStore_CreateMailbox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_DeleteMailbox_Proxy( 
    IMailboxStore __RPC_FAR * This);


void __RPC_STUB IMailboxStore_DeleteMailbox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMailboxStore_MoveMailbox_Proxy( 
    IMailboxStore __RPC_FAR * This,
    /* [in] */ BSTR HomeMDBURL);


void __RPC_STUB IMailboxStore_MoveMailbox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMailboxStore_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MailGroup;

#ifdef __cplusplus

class DECLSPEC_UUID("25150F1F-5734-11d2-A593-00C04F990D8A")
MailGroup;
#endif

EXTERN_C const CLSID CLSID_MailRecipient;

#ifdef __cplusplus

class DECLSPEC_UUID("25150F20-5734-11d2-A593-00C04F990D8A")
MailRecipient;
#endif

EXTERN_C const CLSID CLSID_Mailbox;

#ifdef __cplusplus

class DECLSPEC_UUID("25150F21-5734-11d2-A593-00C04F990D8A")
Mailbox;
#endif

EXTERN_C const CLSID CLSID_FolderAdmin;

#ifdef __cplusplus

class DECLSPEC_UUID("25150F22-5734-11d2-A593-00C04F990D8A")
FolderAdmin;
#endif

EXTERN_C const CLSID CLSID_ExchangeServer;

#ifdef __cplusplus

class DECLSPEC_UUID("25150F27-5734-11d2-A593-00C04F990D8A")
ExchangeServer;
#endif

EXTERN_C const CLSID CLSID_FolderTree;

#ifdef __cplusplus

class DECLSPEC_UUID("25150F23-5734-11d2-A593-00C04F990D8A")
FolderTree;
#endif

EXTERN_C const CLSID CLSID_PublicStoreDB;

#ifdef __cplusplus

class DECLSPEC_UUID("25150F24-5734-11d2-A593-00C04F990D8A")
PublicStoreDB;
#endif

EXTERN_C const CLSID CLSID_MailboxStoreDB;

#ifdef __cplusplus

class DECLSPEC_UUID("25150F25-5734-11d2-A593-00C04F990D8A")
MailboxStoreDB;
#endif

EXTERN_C const CLSID CLSID_StorageGroup;

#ifdef __cplusplus

class DECLSPEC_UUID("25150F26-5734-11d2-A593-00C04F990D8A")
StorageGroup;
#endif


#ifndef __CDOEXMInterfaces_MODULE_DEFINED__
#define __CDOEXMInterfaces_MODULE_DEFINED__


/* module CDOEXMInterfaces */
/* [helpstring][uuid] */ 

const BSTR cdoexmIMailRecipient	=	L"IMailRecipient";

const BSTR cdoexmIMailboxStore	=	L"IMailboxStore";

const BSTR cdoexmIDistributionList	=	L"IDistributionList";

const BSTR cdoexmIExchangeServer	=	L"IExchangeServer";

const BSTR cdoexmIFolderTree	=	L"IFolderTree";

const BSTR cdoexmIPublicStoreDB	=	L"IPublicStoreDB";

const BSTR cdoexmIMailboxStoreDB	=	L"IMailboxStoreDB";

const BSTR cdoexmIStorageGroup	=	L"IStorageGroup";

const BSTR cdoexmIFolderAdmin	=	L"IFolderAdmin";

const BSTR cdoexmIADs	=	L"IADs";

#endif /* __CDOEXMInterfaces_MODULE_DEFINED__ */
#endif /* __CDOEXM_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


