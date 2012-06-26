/* Microsoft Corporation Copyright 1999 */
/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.03.0110 */
/* at Thu Aug 06 10:08:26 1998
 */
/* Compiler settings for dhtmled.idl:
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

#ifndef __dhtmled_h__
#define __dhtmled_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IDEGetBlockFmtNamesParam_FWD_DEFINED__
#define __IDEGetBlockFmtNamesParam_FWD_DEFINED__
typedef interface IDEGetBlockFmtNamesParam IDEGetBlockFmtNamesParam;
#endif 	/* __IDEGetBlockFmtNamesParam_FWD_DEFINED__ */


#ifndef __IDHTMLSafe_FWD_DEFINED__
#define __IDHTMLSafe_FWD_DEFINED__
typedef interface IDHTMLSafe IDHTMLSafe;
#endif 	/* __IDHTMLSafe_FWD_DEFINED__ */


#ifndef __IDHTMLEdit_FWD_DEFINED__
#define __IDHTMLEdit_FWD_DEFINED__
typedef interface IDHTMLEdit IDHTMLEdit;
#endif 	/* __IDHTMLEdit_FWD_DEFINED__ */


#ifndef __IDEInsertTableParam_FWD_DEFINED__
#define __IDEInsertTableParam_FWD_DEFINED__
typedef interface IDEInsertTableParam IDEInsertTableParam;
#endif 	/* __IDEInsertTableParam_FWD_DEFINED__ */


#ifndef ___DHTMLSafeEvents_FWD_DEFINED__
#define ___DHTMLSafeEvents_FWD_DEFINED__
typedef interface _DHTMLSafeEvents _DHTMLSafeEvents;
#endif 	/* ___DHTMLSafeEvents_FWD_DEFINED__ */


#ifndef ___DHTMLEditEvents_FWD_DEFINED__
#define ___DHTMLEditEvents_FWD_DEFINED__
typedef interface _DHTMLEditEvents _DHTMLEditEvents;
#endif 	/* ___DHTMLEditEvents_FWD_DEFINED__ */


#ifndef __DHTMLEdit_FWD_DEFINED__
#define __DHTMLEdit_FWD_DEFINED__

#ifdef __cplusplus
typedef class DHTMLEdit DHTMLEdit;
#else
typedef struct DHTMLEdit DHTMLEdit;
#endif /* __cplusplus */

#endif 	/* __DHTMLEdit_FWD_DEFINED__ */


#ifndef __DHTMLSafe_FWD_DEFINED__
#define __DHTMLSafe_FWD_DEFINED__

#ifdef __cplusplus
typedef class DHTMLSafe DHTMLSafe;
#else
typedef struct DHTMLSafe DHTMLSafe;
#endif /* __cplusplus */

#endif 	/* __DHTMLSafe_FWD_DEFINED__ */


#ifndef __DEInsertTableParam_FWD_DEFINED__
#define __DEInsertTableParam_FWD_DEFINED__

#ifdef __cplusplus
typedef class DEInsertTableParam DEInsertTableParam;
#else
typedef struct DEInsertTableParam DEInsertTableParam;
#endif /* __cplusplus */

#endif 	/* __DEInsertTableParam_FWD_DEFINED__ */


#ifndef __DEGetBlockFmtNamesParam_FWD_DEFINED__
#define __DEGetBlockFmtNamesParam_FWD_DEFINED__

#ifdef __cplusplus
typedef class DEGetBlockFmtNamesParam DEGetBlockFmtNamesParam;
#else
typedef struct DEGetBlockFmtNamesParam DEGetBlockFmtNamesParam;
#endif /* __cplusplus */

#endif 	/* __DEGetBlockFmtNamesParam_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "docobj.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_dhtmled_0000
 * at Thu Aug 06 10:08:26 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [local] */ 



#define DE_E_INVALIDARG                E_INVALIDARG
#define DE_E_PATH_NOT_FOUND            HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND)
#define DE_E_FILE_NOT_FOUND            HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)
#define DE_E_UNEXPECTED                E_UNEXPECTED
#define DE_E_DISK_FULL                 HRESULT_FROM_WIN32(ERROR_HANDLE_DISK_FULL)
#define DE_E_NOTSUPPORTED              OLECMDERR_E_NOTSUPPORTED
#define DE_E_ACCESS_DENIED             HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED)

#define DE_E_URL_SYNTAX                MK_E_SYNTAX
#define DE_E_INVALID_URL               0x800C0002
#define DE_E_NO_SESSION                0x800C0003
#define DE_E_CANNOT_CONNECT            0x800C0004
#define DE_E_RESOURCE_NOT_FOUND        0x800C0005
#define DE_E_OBJECT_NOT_FOUND          0x800C0006
#define DE_E_DATA_NOT_AVAILABLE        0x800C0007
#define DE_E_DOWNLOAD_FAILURE          0x800C0008
#define DE_E_AUTHENTICATION_REQUIRED   0x800C0009
#define DE_E_NO_VALID_MEDIA            0x800C000A
#define DE_E_CONNECTION_TIMEOUT        0x800C000B
#define DE_E_INVALID_REQUEST           0x800C000C
#define DE_E_UNKNOWN_PROTOCOL          0x800C000D
#define DE_E_SECURITY_PROBLEM          0x800C000E
#define DE_E_CANNOT_LOAD_DATA          0x800C000F
#define DE_E_CANNOT_INSTANTIATE_OBJECT 0x800C0010
#define DE_E_REDIRECT_FAILED           0x800C0014
#define DE_E_REDIRECT_TO_DIR           0x800C0015
#define DE_E_CANNOT_LOCK_REQUEST       0x800C0016

#define DE_E_FILTER_FRAMESET           0x80100001
#define DE_E_FILTER_SERVERSCRIPT       0x80100002
#define DE_E_FILTER_MULTIPLETAGS       0x80100004
#define DE_E_FILTER_SCRIPTLISTING      0x80100008
#define DE_E_FILTER_SCRIPTLABEL        0x80100010
#define DE_E_FILTER_SCRIPTTEXTAREA     0x80100020
#define DE_E_FILTER_SCRIPTSELECT       0x80100040


extern RPC_IF_HANDLE __MIDL_itf_dhtmled_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dhtmled_0000_v0_0_s_ifspec;


#ifndef __DHTMLEDLib_LIBRARY_DEFINED__
#define __DHTMLEDLib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: DHTMLEDLib
 * at Thu Aug 06 10:08:26 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [helpstring][version][uuid] */ 


typedef /* [helpstring][uuid] */ 
enum DHTMLEDITCMDID
    {	DECMD_BOLD	= 5000,
	DECMD_COPY	= 5002,
	DECMD_CUT	= DECMD_COPY + 1,
	DECMD_DELETE	= DECMD_CUT + 1,
	DECMD_DELETECELLS	= DECMD_DELETE + 1,
	DECMD_DELETECOLS	= DECMD_DELETECELLS + 1,
	DECMD_DELETEROWS	= DECMD_DELETECOLS + 1,
	DECMD_FINDTEXT	= DECMD_DELETEROWS + 1,
	DECMD_FONT	= DECMD_FINDTEXT + 1,
	DECMD_GETBACKCOLOR	= DECMD_FONT + 1,
	DECMD_GETBLOCKFMT	= DECMD_GETBACKCOLOR + 1,
	DECMD_GETBLOCKFMTNAMES	= DECMD_GETBLOCKFMT + 1,
	DECMD_GETFONTNAME	= DECMD_GETBLOCKFMTNAMES + 1,
	DECMD_GETFONTSIZE	= DECMD_GETFONTNAME + 1,
	DECMD_GETFORECOLOR	= DECMD_GETFONTSIZE + 1,
	DECMD_HYPERLINK	= DECMD_GETFORECOLOR + 1,
	DECMD_IMAGE	= DECMD_HYPERLINK + 1,
	DECMD_INDENT	= DECMD_IMAGE + 1,
	DECMD_INSERTCELL	= DECMD_INDENT + 1,
	DECMD_INSERTCOL	= DECMD_INSERTCELL + 1,
	DECMD_INSERTROW	= DECMD_INSERTCOL + 1,
	DECMD_INSERTTABLE	= DECMD_INSERTROW + 1,
	DECMD_ITALIC	= DECMD_INSERTTABLE + 1,
	DECMD_JUSTIFYCENTER	= DECMD_ITALIC + 1,
	DECMD_JUSTIFYLEFT	= DECMD_JUSTIFYCENTER + 1,
	DECMD_JUSTIFYRIGHT	= DECMD_JUSTIFYLEFT + 1,
	DECMD_LOCK_ELEMENT	= DECMD_JUSTIFYRIGHT + 1,
	DECMD_MAKE_ABSOLUTE	= DECMD_LOCK_ELEMENT + 1,
	DECMD_MERGECELLS	= DECMD_MAKE_ABSOLUTE + 1,
	DECMD_ORDERLIST	= DECMD_MERGECELLS + 1,
	DECMD_OUTDENT	= DECMD_ORDERLIST + 1,
	DECMD_PASTE	= DECMD_OUTDENT + 1,
	DECMD_REDO	= DECMD_PASTE + 1,
	DECMD_REMOVEFORMAT	= DECMD_REDO + 1,
	DECMD_SELECTALL	= DECMD_REMOVEFORMAT + 1,
	DECMD_SEND_BACKWARD	= DECMD_SELECTALL + 1,
	DECMD_BRING_FORWARD	= DECMD_SEND_BACKWARD + 1,
	DECMD_SEND_BELOW_TEXT	= DECMD_BRING_FORWARD + 1,
	DECMD_BRING_ABOVE_TEXT	= DECMD_SEND_BELOW_TEXT + 1,
	DECMD_SEND_TO_BACK	= DECMD_BRING_ABOVE_TEXT + 1,
	DECMD_BRING_TO_FRONT	= DECMD_SEND_TO_BACK + 1,
	DECMD_SETBACKCOLOR	= DECMD_BRING_TO_FRONT + 1,
	DECMD_SETBLOCKFMT	= DECMD_SETBACKCOLOR + 1,
	DECMD_SETFONTNAME	= DECMD_SETBLOCKFMT + 1,
	DECMD_SETFONTSIZE	= DECMD_SETFONTNAME + 1,
	DECMD_SETFORECOLOR	= DECMD_SETFONTSIZE + 1,
	DECMD_SPLITCELL	= DECMD_SETFORECOLOR + 1,
	DECMD_UNDERLINE	= DECMD_SPLITCELL + 1,
	DECMD_UNDO	= DECMD_UNDERLINE + 1,
	DECMD_UNLINK	= DECMD_UNDO + 1,
	DECMD_UNORDERLIST	= DECMD_UNLINK + 1,
	DECMD_PROPERTIES	= DECMD_UNORDERLIST + 1
    }	DHTMLEDITCMDID;

typedef /* [helpstring][uuid] */ 
enum DHTMLEDITCMDF
    {	DECMDF_NOTSUPPORTED	= 0,
	DECMDF_DISABLED	= 0x1,
	DECMDF_ENABLED	= 0x3,
	DECMDF_LATCHED	= 0x7,
	DECMDF_NINCHED	= 0xb
    }	DHTMLEDITCMDF;

typedef /* [helpstring][uuid] */ 
enum DHTMLEDITAPPEARANCE
    {	DEAPPEARANCE_FLAT	= 0,
	DEAPPEARANCE_3D	= 0x1
    }	DHTMLEDITAPPEARANCE;


EXTERN_C const IID LIBID_DHTMLEDLib;

#ifndef __IDEGetBlockFmtNamesParam_INTERFACE_DEFINED__
#define __IDEGetBlockFmtNamesParam_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDEGetBlockFmtNamesParam
 * at Thu Aug 06 10:08:26 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IDEGetBlockFmtNamesParam;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8D91090D-B955-11D1-ADC5-006008A5848C")
    IDEGetBlockFmtNamesParam : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Names( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Names( 
            /* [in] */ VARIANT __RPC_FAR *newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDEGetBlockFmtNamesParamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDEGetBlockFmtNamesParam __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDEGetBlockFmtNamesParam __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDEGetBlockFmtNamesParam __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDEGetBlockFmtNamesParam __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDEGetBlockFmtNamesParam __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDEGetBlockFmtNamesParam __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDEGetBlockFmtNamesParam __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Names )( 
            IDEGetBlockFmtNamesParam __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Names )( 
            IDEGetBlockFmtNamesParam __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *newVal);
        
        END_INTERFACE
    } IDEGetBlockFmtNamesParamVtbl;

    interface IDEGetBlockFmtNamesParam
    {
        CONST_VTBL struct IDEGetBlockFmtNamesParamVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDEGetBlockFmtNamesParam_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDEGetBlockFmtNamesParam_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDEGetBlockFmtNamesParam_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDEGetBlockFmtNamesParam_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDEGetBlockFmtNamesParam_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDEGetBlockFmtNamesParam_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDEGetBlockFmtNamesParam_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDEGetBlockFmtNamesParam_get_Names(This,pVal)	\
    (This)->lpVtbl -> get_Names(This,pVal)

#define IDEGetBlockFmtNamesParam_put_Names(This,newVal)	\
    (This)->lpVtbl -> put_Names(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDEGetBlockFmtNamesParam_get_Names_Proxy( 
    IDEGetBlockFmtNamesParam __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IDEGetBlockFmtNamesParam_get_Names_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDEGetBlockFmtNamesParam_put_Names_Proxy( 
    IDEGetBlockFmtNamesParam __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *newVal);


void __RPC_STUB IDEGetBlockFmtNamesParam_put_Names_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDEGetBlockFmtNamesParam_INTERFACE_DEFINED__ */


#ifndef __IDHTMLSafe_INTERFACE_DEFINED__
#define __IDHTMLSafe_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDHTMLSafe
 * at Thu Aug 06 10:08:26 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IDHTMLSafe;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CE04B590-2B1F-11d2-8D1E-00A0C959BC0A")
    IDHTMLSafe : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExecCommand( 
            /* [in] */ DHTMLEDITCMDID cmdID,
            /* [defaultvalue][in] */ OLECMDEXECOPT cmdexecopt,
            /* [optional][in] */ VARIANT __RPC_FAR *pInVar,
            /* [retval][out] */ VARIANT __RPC_FAR *pOutVar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryStatus( 
            /* [in] */ DHTMLEDITCMDID cmdID,
            /* [retval][out] */ DHTMLEDITCMDF __RPC_FAR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetContextMenu( 
            /* [in] */ VARIANT __RPC_FAR *menuStrings,
            /* [in] */ VARIANT __RPC_FAR *menuStates) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewDocument( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadURL( 
            /* [in] */ BSTR url) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FilterSourceCode( 
            /* [in] */ BSTR sourceCodeIn,
            /* [retval][out] */ BSTR __RPC_FAR *sourceCodeOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DOM( 
            /* [retval][out] */ /* external definition not present */ IHTMLDocument2 __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DocumentHTML( 
            /* [retval][out] */ BSTR __RPC_FAR *docHTML) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DocumentHTML( 
            /* [in] */ BSTR docHTML) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActivateApplets( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActivateApplets( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActivateActiveXControls( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActivateActiveXControls( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActivateDTCs( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActivateDTCs( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowDetails( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowDetails( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowBorders( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowBorders( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Appearance( 
            /* [retval][out] */ DHTMLEDITAPPEARANCE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Appearance( 
            /* [in] */ DHTMLEDITAPPEARANCE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Scrollbars( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Scrollbars( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScrollbarAppearance( 
            /* [retval][out] */ DHTMLEDITAPPEARANCE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ScrollbarAppearance( 
            /* [in] */ DHTMLEDITAPPEARANCE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceCodePreservation( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SourceCodePreservation( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AbsoluteDropMode( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AbsoluteDropMode( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SnapToGridX( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SnapToGridX( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SnapToGridY( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SnapToGridY( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SnapToGrid( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SnapToGrid( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsDirty( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentDocumentPath( 
            /* [retval][out] */ BSTR __RPC_FAR *docPath) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BaseURL( 
            /* [retval][out] */ BSTR __RPC_FAR *baseURL) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BaseURL( 
            /* [in] */ BSTR baseURL) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DocumentTitle( 
            /* [retval][out] */ BSTR __RPC_FAR *docTitle) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseDivOnCarriageReturn( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseDivOnCarriageReturn( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Busy( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDHTMLSafeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDHTMLSafe __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDHTMLSafe __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExecCommand )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ DHTMLEDITCMDID cmdID,
            /* [defaultvalue][in] */ OLECMDEXECOPT cmdexecopt,
            /* [optional][in] */ VARIANT __RPC_FAR *pInVar,
            /* [retval][out] */ VARIANT __RPC_FAR *pOutVar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryStatus )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ DHTMLEDITCMDID cmdID,
            /* [retval][out] */ DHTMLEDITCMDF __RPC_FAR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetContextMenu )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *menuStrings,
            /* [in] */ VARIANT __RPC_FAR *menuStates);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NewDocument )( 
            IDHTMLSafe __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadURL )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ BSTR url);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FilterSourceCode )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ BSTR sourceCodeIn,
            /* [retval][out] */ BSTR __RPC_FAR *sourceCodeOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IDHTMLSafe __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DOM )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ IHTMLDocument2 __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DocumentHTML )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *docHTML);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DocumentHTML )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ BSTR docHTML);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActivateApplets )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActivateApplets )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActivateActiveXControls )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActivateActiveXControls )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActivateDTCs )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActivateDTCs )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowDetails )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowDetails )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowBorders )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowBorders )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Appearance )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ DHTMLEDITAPPEARANCE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Appearance )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ DHTMLEDITAPPEARANCE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Scrollbars )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Scrollbars )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ScrollbarAppearance )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ DHTMLEDITAPPEARANCE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ScrollbarAppearance )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ DHTMLEDITAPPEARANCE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SourceCodePreservation )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SourceCodePreservation )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AbsoluteDropMode )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AbsoluteDropMode )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SnapToGridX )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SnapToGridX )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SnapToGridY )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SnapToGridY )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SnapToGrid )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SnapToGrid )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsDirty )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CurrentDocumentPath )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *docPath);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BaseURL )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *baseURL);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BaseURL )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ BSTR baseURL);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DocumentTitle )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *docTitle);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UseDivOnCarriageReturn )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UseDivOnCarriageReturn )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Busy )( 
            IDHTMLSafe __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        END_INTERFACE
    } IDHTMLSafeVtbl;

    interface IDHTMLSafe
    {
        CONST_VTBL struct IDHTMLSafeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDHTMLSafe_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDHTMLSafe_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDHTMLSafe_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDHTMLSafe_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDHTMLSafe_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDHTMLSafe_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDHTMLSafe_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDHTMLSafe_ExecCommand(This,cmdID,cmdexecopt,pInVar,pOutVar)	\
    (This)->lpVtbl -> ExecCommand(This,cmdID,cmdexecopt,pInVar,pOutVar)

#define IDHTMLSafe_QueryStatus(This,cmdID,retval)	\
    (This)->lpVtbl -> QueryStatus(This,cmdID,retval)

#define IDHTMLSafe_SetContextMenu(This,menuStrings,menuStates)	\
    (This)->lpVtbl -> SetContextMenu(This,menuStrings,menuStates)

#define IDHTMLSafe_NewDocument(This)	\
    (This)->lpVtbl -> NewDocument(This)

#define IDHTMLSafe_LoadURL(This,url)	\
    (This)->lpVtbl -> LoadURL(This,url)

#define IDHTMLSafe_FilterSourceCode(This,sourceCodeIn,sourceCodeOut)	\
    (This)->lpVtbl -> FilterSourceCode(This,sourceCodeIn,sourceCodeOut)

#define IDHTMLSafe_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)

#define IDHTMLSafe_get_DOM(This,pVal)	\
    (This)->lpVtbl -> get_DOM(This,pVal)

#define IDHTMLSafe_get_DocumentHTML(This,docHTML)	\
    (This)->lpVtbl -> get_DocumentHTML(This,docHTML)

#define IDHTMLSafe_put_DocumentHTML(This,docHTML)	\
    (This)->lpVtbl -> put_DocumentHTML(This,docHTML)

#define IDHTMLSafe_get_ActivateApplets(This,pVal)	\
    (This)->lpVtbl -> get_ActivateApplets(This,pVal)

#define IDHTMLSafe_put_ActivateApplets(This,newVal)	\
    (This)->lpVtbl -> put_ActivateApplets(This,newVal)

#define IDHTMLSafe_get_ActivateActiveXControls(This,pVal)	\
    (This)->lpVtbl -> get_ActivateActiveXControls(This,pVal)

#define IDHTMLSafe_put_ActivateActiveXControls(This,newVal)	\
    (This)->lpVtbl -> put_ActivateActiveXControls(This,newVal)

#define IDHTMLSafe_get_ActivateDTCs(This,pVal)	\
    (This)->lpVtbl -> get_ActivateDTCs(This,pVal)

#define IDHTMLSafe_put_ActivateDTCs(This,newVal)	\
    (This)->lpVtbl -> put_ActivateDTCs(This,newVal)

#define IDHTMLSafe_get_ShowDetails(This,pVal)	\
    (This)->lpVtbl -> get_ShowDetails(This,pVal)

#define IDHTMLSafe_put_ShowDetails(This,newVal)	\
    (This)->lpVtbl -> put_ShowDetails(This,newVal)

#define IDHTMLSafe_get_ShowBorders(This,pVal)	\
    (This)->lpVtbl -> get_ShowBorders(This,pVal)

#define IDHTMLSafe_put_ShowBorders(This,newVal)	\
    (This)->lpVtbl -> put_ShowBorders(This,newVal)

#define IDHTMLSafe_get_Appearance(This,pVal)	\
    (This)->lpVtbl -> get_Appearance(This,pVal)

#define IDHTMLSafe_put_Appearance(This,newVal)	\
    (This)->lpVtbl -> put_Appearance(This,newVal)

#define IDHTMLSafe_get_Scrollbars(This,pVal)	\
    (This)->lpVtbl -> get_Scrollbars(This,pVal)

#define IDHTMLSafe_put_Scrollbars(This,newVal)	\
    (This)->lpVtbl -> put_Scrollbars(This,newVal)

#define IDHTMLSafe_get_ScrollbarAppearance(This,pVal)	\
    (This)->lpVtbl -> get_ScrollbarAppearance(This,pVal)

#define IDHTMLSafe_put_ScrollbarAppearance(This,newVal)	\
    (This)->lpVtbl -> put_ScrollbarAppearance(This,newVal)

#define IDHTMLSafe_get_SourceCodePreservation(This,pVal)	\
    (This)->lpVtbl -> get_SourceCodePreservation(This,pVal)

#define IDHTMLSafe_put_SourceCodePreservation(This,newVal)	\
    (This)->lpVtbl -> put_SourceCodePreservation(This,newVal)

#define IDHTMLSafe_get_AbsoluteDropMode(This,pVal)	\
    (This)->lpVtbl -> get_AbsoluteDropMode(This,pVal)

#define IDHTMLSafe_put_AbsoluteDropMode(This,newVal)	\
    (This)->lpVtbl -> put_AbsoluteDropMode(This,newVal)

#define IDHTMLSafe_get_SnapToGridX(This,pVal)	\
    (This)->lpVtbl -> get_SnapToGridX(This,pVal)

#define IDHTMLSafe_put_SnapToGridX(This,newVal)	\
    (This)->lpVtbl -> put_SnapToGridX(This,newVal)

#define IDHTMLSafe_get_SnapToGridY(This,pVal)	\
    (This)->lpVtbl -> get_SnapToGridY(This,pVal)

#define IDHTMLSafe_put_SnapToGridY(This,newVal)	\
    (This)->lpVtbl -> put_SnapToGridY(This,newVal)

#define IDHTMLSafe_get_SnapToGrid(This,pVal)	\
    (This)->lpVtbl -> get_SnapToGrid(This,pVal)

#define IDHTMLSafe_put_SnapToGrid(This,newVal)	\
    (This)->lpVtbl -> put_SnapToGrid(This,newVal)

#define IDHTMLSafe_get_IsDirty(This,pVal)	\
    (This)->lpVtbl -> get_IsDirty(This,pVal)

#define IDHTMLSafe_get_CurrentDocumentPath(This,docPath)	\
    (This)->lpVtbl -> get_CurrentDocumentPath(This,docPath)

#define IDHTMLSafe_get_BaseURL(This,baseURL)	\
    (This)->lpVtbl -> get_BaseURL(This,baseURL)

#define IDHTMLSafe_put_BaseURL(This,baseURL)	\
    (This)->lpVtbl -> put_BaseURL(This,baseURL)

#define IDHTMLSafe_get_DocumentTitle(This,docTitle)	\
    (This)->lpVtbl -> get_DocumentTitle(This,docTitle)

#define IDHTMLSafe_get_UseDivOnCarriageReturn(This,pVal)	\
    (This)->lpVtbl -> get_UseDivOnCarriageReturn(This,pVal)

#define IDHTMLSafe_put_UseDivOnCarriageReturn(This,newVal)	\
    (This)->lpVtbl -> put_UseDivOnCarriageReturn(This,newVal)

#define IDHTMLSafe_get_Busy(This,pVal)	\
    (This)->lpVtbl -> get_Busy(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_ExecCommand_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ DHTMLEDITCMDID cmdID,
    /* [defaultvalue][in] */ OLECMDEXECOPT cmdexecopt,
    /* [optional][in] */ VARIANT __RPC_FAR *pInVar,
    /* [retval][out] */ VARIANT __RPC_FAR *pOutVar);


void __RPC_STUB IDHTMLSafe_ExecCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_QueryStatus_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ DHTMLEDITCMDID cmdID,
    /* [retval][out] */ DHTMLEDITCMDF __RPC_FAR *retval);


void __RPC_STUB IDHTMLSafe_QueryStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_SetContextMenu_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *menuStrings,
    /* [in] */ VARIANT __RPC_FAR *menuStates);


void __RPC_STUB IDHTMLSafe_SetContextMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_NewDocument_Proxy( 
    IDHTMLSafe __RPC_FAR * This);


void __RPC_STUB IDHTMLSafe_NewDocument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_LoadURL_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ BSTR url);


void __RPC_STUB IDHTMLSafe_LoadURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_FilterSourceCode_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ BSTR sourceCodeIn,
    /* [retval][out] */ BSTR __RPC_FAR *sourceCodeOut);


void __RPC_STUB IDHTMLSafe_FilterSourceCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_Refresh_Proxy( 
    IDHTMLSafe __RPC_FAR * This);


void __RPC_STUB IDHTMLSafe_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_DOM_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ IHTMLDocument2 __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_DOM_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_DocumentHTML_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *docHTML);


void __RPC_STUB IDHTMLSafe_get_DocumentHTML_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_DocumentHTML_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ BSTR docHTML);


void __RPC_STUB IDHTMLSafe_put_DocumentHTML_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_ActivateApplets_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_ActivateApplets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_ActivateApplets_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IDHTMLSafe_put_ActivateApplets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_ActivateActiveXControls_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_ActivateActiveXControls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_ActivateActiveXControls_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IDHTMLSafe_put_ActivateActiveXControls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_ActivateDTCs_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_ActivateDTCs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_ActivateDTCs_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IDHTMLSafe_put_ActivateDTCs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_ShowDetails_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_ShowDetails_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_ShowDetails_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IDHTMLSafe_put_ShowDetails_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_ShowBorders_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_ShowBorders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_ShowBorders_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IDHTMLSafe_put_ShowBorders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_Appearance_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ DHTMLEDITAPPEARANCE __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_Appearance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_Appearance_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ DHTMLEDITAPPEARANCE newVal);


void __RPC_STUB IDHTMLSafe_put_Appearance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_Scrollbars_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_Scrollbars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_Scrollbars_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IDHTMLSafe_put_Scrollbars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_ScrollbarAppearance_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ DHTMLEDITAPPEARANCE __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_ScrollbarAppearance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_ScrollbarAppearance_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ DHTMLEDITAPPEARANCE newVal);


void __RPC_STUB IDHTMLSafe_put_ScrollbarAppearance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_SourceCodePreservation_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_SourceCodePreservation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_SourceCodePreservation_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IDHTMLSafe_put_SourceCodePreservation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_AbsoluteDropMode_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_AbsoluteDropMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_AbsoluteDropMode_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IDHTMLSafe_put_AbsoluteDropMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_SnapToGridX_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_SnapToGridX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_SnapToGridX_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDHTMLSafe_put_SnapToGridX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_SnapToGridY_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_SnapToGridY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_SnapToGridY_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDHTMLSafe_put_SnapToGridY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_SnapToGrid_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_SnapToGrid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_SnapToGrid_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IDHTMLSafe_put_SnapToGrid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_IsDirty_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_IsDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_CurrentDocumentPath_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *docPath);


void __RPC_STUB IDHTMLSafe_get_CurrentDocumentPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_BaseURL_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *baseURL);


void __RPC_STUB IDHTMLSafe_get_BaseURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_BaseURL_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ BSTR baseURL);


void __RPC_STUB IDHTMLSafe_put_BaseURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_DocumentTitle_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *docTitle);


void __RPC_STUB IDHTMLSafe_get_DocumentTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_UseDivOnCarriageReturn_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_UseDivOnCarriageReturn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_put_UseDivOnCarriageReturn_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IDHTMLSafe_put_UseDivOnCarriageReturn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLSafe_get_Busy_Proxy( 
    IDHTMLSafe __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLSafe_get_Busy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDHTMLSafe_INTERFACE_DEFINED__ */


#ifndef __IDHTMLEdit_INTERFACE_DEFINED__
#define __IDHTMLEdit_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDHTMLEdit
 * at Thu Aug 06 10:08:26 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [object][unique][helpstring][dual][uuid] */ 



EXTERN_C const IID IID_IDHTMLEdit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CE04B591-2B1F-11d2-8D1E-00A0C959BC0A")
    IDHTMLEdit : public IDHTMLSafe
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadDocument( 
            /* [in] */ VARIANT __RPC_FAR *pathIn,
            /* [optional][in] */ VARIANT __RPC_FAR *promptUser) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveDocument( 
            /* [in] */ VARIANT __RPC_FAR *pathIn,
            /* [optional][in] */ VARIANT __RPC_FAR *promptUser) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintDocument( 
            /* [optional][in] */ VARIANT __RPC_FAR *withUI) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BrowseMode( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BrowseMode( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDHTMLEditVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDHTMLEdit __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDHTMLEdit __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExecCommand )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ DHTMLEDITCMDID cmdID,
            /* [defaultvalue][in] */ OLECMDEXECOPT cmdexecopt,
            /* [optional][in] */ VARIANT __RPC_FAR *pInVar,
            /* [retval][out] */ VARIANT __RPC_FAR *pOutVar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryStatus )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ DHTMLEDITCMDID cmdID,
            /* [retval][out] */ DHTMLEDITCMDF __RPC_FAR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetContextMenu )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *menuStrings,
            /* [in] */ VARIANT __RPC_FAR *menuStates);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NewDocument )( 
            IDHTMLEdit __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadURL )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ BSTR url);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FilterSourceCode )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ BSTR sourceCodeIn,
            /* [retval][out] */ BSTR __RPC_FAR *sourceCodeOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IDHTMLEdit __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DOM )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ IHTMLDocument2 __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DocumentHTML )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *docHTML);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DocumentHTML )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ BSTR docHTML);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActivateApplets )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActivateApplets )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActivateActiveXControls )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActivateActiveXControls )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActivateDTCs )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActivateDTCs )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowDetails )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowDetails )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowBorders )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowBorders )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Appearance )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ DHTMLEDITAPPEARANCE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Appearance )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ DHTMLEDITAPPEARANCE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Scrollbars )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Scrollbars )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ScrollbarAppearance )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ DHTMLEDITAPPEARANCE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ScrollbarAppearance )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ DHTMLEDITAPPEARANCE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SourceCodePreservation )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SourceCodePreservation )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AbsoluteDropMode )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AbsoluteDropMode )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SnapToGridX )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SnapToGridX )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SnapToGridY )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SnapToGridY )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SnapToGrid )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SnapToGrid )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsDirty )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CurrentDocumentPath )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *docPath);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BaseURL )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *baseURL);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BaseURL )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ BSTR baseURL);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DocumentTitle )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *docTitle);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UseDivOnCarriageReturn )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UseDivOnCarriageReturn )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Busy )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadDocument )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *pathIn,
            /* [optional][in] */ VARIANT __RPC_FAR *promptUser);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveDocument )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT __RPC_FAR *pathIn,
            /* [optional][in] */ VARIANT __RPC_FAR *promptUser);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintDocument )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [optional][in] */ VARIANT __RPC_FAR *withUI);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BrowseMode )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BrowseMode )( 
            IDHTMLEdit __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IDHTMLEditVtbl;

    interface IDHTMLEdit
    {
        CONST_VTBL struct IDHTMLEditVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDHTMLEdit_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDHTMLEdit_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDHTMLEdit_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDHTMLEdit_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDHTMLEdit_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDHTMLEdit_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDHTMLEdit_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDHTMLEdit_ExecCommand(This,cmdID,cmdexecopt,pInVar,pOutVar)	\
    (This)->lpVtbl -> ExecCommand(This,cmdID,cmdexecopt,pInVar,pOutVar)

#define IDHTMLEdit_QueryStatus(This,cmdID,retval)	\
    (This)->lpVtbl -> QueryStatus(This,cmdID,retval)

#define IDHTMLEdit_SetContextMenu(This,menuStrings,menuStates)	\
    (This)->lpVtbl -> SetContextMenu(This,menuStrings,menuStates)

#define IDHTMLEdit_NewDocument(This)	\
    (This)->lpVtbl -> NewDocument(This)

#define IDHTMLEdit_LoadURL(This,url)	\
    (This)->lpVtbl -> LoadURL(This,url)

#define IDHTMLEdit_FilterSourceCode(This,sourceCodeIn,sourceCodeOut)	\
    (This)->lpVtbl -> FilterSourceCode(This,sourceCodeIn,sourceCodeOut)

#define IDHTMLEdit_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)

#define IDHTMLEdit_get_DOM(This,pVal)	\
    (This)->lpVtbl -> get_DOM(This,pVal)

#define IDHTMLEdit_get_DocumentHTML(This,docHTML)	\
    (This)->lpVtbl -> get_DocumentHTML(This,docHTML)

#define IDHTMLEdit_put_DocumentHTML(This,docHTML)	\
    (This)->lpVtbl -> put_DocumentHTML(This,docHTML)

#define IDHTMLEdit_get_ActivateApplets(This,pVal)	\
    (This)->lpVtbl -> get_ActivateApplets(This,pVal)

#define IDHTMLEdit_put_ActivateApplets(This,newVal)	\
    (This)->lpVtbl -> put_ActivateApplets(This,newVal)

#define IDHTMLEdit_get_ActivateActiveXControls(This,pVal)	\
    (This)->lpVtbl -> get_ActivateActiveXControls(This,pVal)

#define IDHTMLEdit_put_ActivateActiveXControls(This,newVal)	\
    (This)->lpVtbl -> put_ActivateActiveXControls(This,newVal)

#define IDHTMLEdit_get_ActivateDTCs(This,pVal)	\
    (This)->lpVtbl -> get_ActivateDTCs(This,pVal)

#define IDHTMLEdit_put_ActivateDTCs(This,newVal)	\
    (This)->lpVtbl -> put_ActivateDTCs(This,newVal)

#define IDHTMLEdit_get_ShowDetails(This,pVal)	\
    (This)->lpVtbl -> get_ShowDetails(This,pVal)

#define IDHTMLEdit_put_ShowDetails(This,newVal)	\
    (This)->lpVtbl -> put_ShowDetails(This,newVal)

#define IDHTMLEdit_get_ShowBorders(This,pVal)	\
    (This)->lpVtbl -> get_ShowBorders(This,pVal)

#define IDHTMLEdit_put_ShowBorders(This,newVal)	\
    (This)->lpVtbl -> put_ShowBorders(This,newVal)

#define IDHTMLEdit_get_Appearance(This,pVal)	\
    (This)->lpVtbl -> get_Appearance(This,pVal)

#define IDHTMLEdit_put_Appearance(This,newVal)	\
    (This)->lpVtbl -> put_Appearance(This,newVal)

#define IDHTMLEdit_get_Scrollbars(This,pVal)	\
    (This)->lpVtbl -> get_Scrollbars(This,pVal)

#define IDHTMLEdit_put_Scrollbars(This,newVal)	\
    (This)->lpVtbl -> put_Scrollbars(This,newVal)

#define IDHTMLEdit_get_ScrollbarAppearance(This,pVal)	\
    (This)->lpVtbl -> get_ScrollbarAppearance(This,pVal)

#define IDHTMLEdit_put_ScrollbarAppearance(This,newVal)	\
    (This)->lpVtbl -> put_ScrollbarAppearance(This,newVal)

#define IDHTMLEdit_get_SourceCodePreservation(This,pVal)	\
    (This)->lpVtbl -> get_SourceCodePreservation(This,pVal)

#define IDHTMLEdit_put_SourceCodePreservation(This,newVal)	\
    (This)->lpVtbl -> put_SourceCodePreservation(This,newVal)

#define IDHTMLEdit_get_AbsoluteDropMode(This,pVal)	\
    (This)->lpVtbl -> get_AbsoluteDropMode(This,pVal)

#define IDHTMLEdit_put_AbsoluteDropMode(This,newVal)	\
    (This)->lpVtbl -> put_AbsoluteDropMode(This,newVal)

#define IDHTMLEdit_get_SnapToGridX(This,pVal)	\
    (This)->lpVtbl -> get_SnapToGridX(This,pVal)

#define IDHTMLEdit_put_SnapToGridX(This,newVal)	\
    (This)->lpVtbl -> put_SnapToGridX(This,newVal)

#define IDHTMLEdit_get_SnapToGridY(This,pVal)	\
    (This)->lpVtbl -> get_SnapToGridY(This,pVal)

#define IDHTMLEdit_put_SnapToGridY(This,newVal)	\
    (This)->lpVtbl -> put_SnapToGridY(This,newVal)

#define IDHTMLEdit_get_SnapToGrid(This,pVal)	\
    (This)->lpVtbl -> get_SnapToGrid(This,pVal)

#define IDHTMLEdit_put_SnapToGrid(This,newVal)	\
    (This)->lpVtbl -> put_SnapToGrid(This,newVal)

#define IDHTMLEdit_get_IsDirty(This,pVal)	\
    (This)->lpVtbl -> get_IsDirty(This,pVal)

#define IDHTMLEdit_get_CurrentDocumentPath(This,docPath)	\
    (This)->lpVtbl -> get_CurrentDocumentPath(This,docPath)

#define IDHTMLEdit_get_BaseURL(This,baseURL)	\
    (This)->lpVtbl -> get_BaseURL(This,baseURL)

#define IDHTMLEdit_put_BaseURL(This,baseURL)	\
    (This)->lpVtbl -> put_BaseURL(This,baseURL)

#define IDHTMLEdit_get_DocumentTitle(This,docTitle)	\
    (This)->lpVtbl -> get_DocumentTitle(This,docTitle)

#define IDHTMLEdit_get_UseDivOnCarriageReturn(This,pVal)	\
    (This)->lpVtbl -> get_UseDivOnCarriageReturn(This,pVal)

#define IDHTMLEdit_put_UseDivOnCarriageReturn(This,newVal)	\
    (This)->lpVtbl -> put_UseDivOnCarriageReturn(This,newVal)

#define IDHTMLEdit_get_Busy(This,pVal)	\
    (This)->lpVtbl -> get_Busy(This,pVal)


#define IDHTMLEdit_LoadDocument(This,pathIn,promptUser)	\
    (This)->lpVtbl -> LoadDocument(This,pathIn,promptUser)

#define IDHTMLEdit_SaveDocument(This,pathIn,promptUser)	\
    (This)->lpVtbl -> SaveDocument(This,pathIn,promptUser)

#define IDHTMLEdit_PrintDocument(This,withUI)	\
    (This)->lpVtbl -> PrintDocument(This,withUI)

#define IDHTMLEdit_get_BrowseMode(This,pVal)	\
    (This)->lpVtbl -> get_BrowseMode(This,pVal)

#define IDHTMLEdit_put_BrowseMode(This,newVal)	\
    (This)->lpVtbl -> put_BrowseMode(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLEdit_LoadDocument_Proxy( 
    IDHTMLEdit __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *pathIn,
    /* [optional][in] */ VARIANT __RPC_FAR *promptUser);


void __RPC_STUB IDHTMLEdit_LoadDocument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLEdit_SaveDocument_Proxy( 
    IDHTMLEdit __RPC_FAR * This,
    /* [in] */ VARIANT __RPC_FAR *pathIn,
    /* [optional][in] */ VARIANT __RPC_FAR *promptUser);


void __RPC_STUB IDHTMLEdit_SaveDocument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLEdit_PrintDocument_Proxy( 
    IDHTMLEdit __RPC_FAR * This,
    /* [optional][in] */ VARIANT __RPC_FAR *withUI);


void __RPC_STUB IDHTMLEdit_PrintDocument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLEdit_get_BrowseMode_Proxy( 
    IDHTMLEdit __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IDHTMLEdit_get_BrowseMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLEdit_put_BrowseMode_Proxy( 
    IDHTMLEdit __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IDHTMLEdit_put_BrowseMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDHTMLEdit_INTERFACE_DEFINED__ */


#ifndef __IDEInsertTableParam_INTERFACE_DEFINED__
#define __IDEInsertTableParam_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDEInsertTableParam
 * at Thu Aug 06 10:08:26 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IDEInsertTableParam;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("47B0DFC6-B7A3-11D1-ADC5-006008A5848C")
    IDEInsertTableParam : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NumRows( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NumRows( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NumCols( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NumCols( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TableAttrs( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TableAttrs( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CellAttrs( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CellAttrs( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Caption( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDEInsertTableParamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDEInsertTableParam __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDEInsertTableParam __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NumRows )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NumRows )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NumCols )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NumCols )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TableAttrs )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TableAttrs )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CellAttrs )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CellAttrs )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            IDEInsertTableParam __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IDEInsertTableParamVtbl;

    interface IDEInsertTableParam
    {
        CONST_VTBL struct IDEInsertTableParamVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDEInsertTableParam_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDEInsertTableParam_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDEInsertTableParam_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDEInsertTableParam_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDEInsertTableParam_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDEInsertTableParam_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDEInsertTableParam_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDEInsertTableParam_get_NumRows(This,pVal)	\
    (This)->lpVtbl -> get_NumRows(This,pVal)

#define IDEInsertTableParam_put_NumRows(This,newVal)	\
    (This)->lpVtbl -> put_NumRows(This,newVal)

#define IDEInsertTableParam_get_NumCols(This,pVal)	\
    (This)->lpVtbl -> get_NumCols(This,pVal)

#define IDEInsertTableParam_put_NumCols(This,newVal)	\
    (This)->lpVtbl -> put_NumCols(This,newVal)

#define IDEInsertTableParam_get_TableAttrs(This,pVal)	\
    (This)->lpVtbl -> get_TableAttrs(This,pVal)

#define IDEInsertTableParam_put_TableAttrs(This,newVal)	\
    (This)->lpVtbl -> put_TableAttrs(This,newVal)

#define IDEInsertTableParam_get_CellAttrs(This,pVal)	\
    (This)->lpVtbl -> get_CellAttrs(This,pVal)

#define IDEInsertTableParam_put_CellAttrs(This,newVal)	\
    (This)->lpVtbl -> put_CellAttrs(This,newVal)

#define IDEInsertTableParam_get_Caption(This,pVal)	\
    (This)->lpVtbl -> get_Caption(This,pVal)

#define IDEInsertTableParam_put_Caption(This,newVal)	\
    (This)->lpVtbl -> put_Caption(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDEInsertTableParam_get_NumRows_Proxy( 
    IDEInsertTableParam __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDEInsertTableParam_get_NumRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDEInsertTableParam_put_NumRows_Proxy( 
    IDEInsertTableParam __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDEInsertTableParam_put_NumRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDEInsertTableParam_get_NumCols_Proxy( 
    IDEInsertTableParam __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDEInsertTableParam_get_NumCols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDEInsertTableParam_put_NumCols_Proxy( 
    IDEInsertTableParam __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDEInsertTableParam_put_NumCols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDEInsertTableParam_get_TableAttrs_Proxy( 
    IDEInsertTableParam __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IDEInsertTableParam_get_TableAttrs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDEInsertTableParam_put_TableAttrs_Proxy( 
    IDEInsertTableParam __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IDEInsertTableParam_put_TableAttrs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDEInsertTableParam_get_CellAttrs_Proxy( 
    IDEInsertTableParam __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IDEInsertTableParam_get_CellAttrs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDEInsertTableParam_put_CellAttrs_Proxy( 
    IDEInsertTableParam __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IDEInsertTableParam_put_CellAttrs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDEInsertTableParam_get_Caption_Proxy( 
    IDEInsertTableParam __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IDEInsertTableParam_get_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDEInsertTableParam_put_Caption_Proxy( 
    IDEInsertTableParam __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IDEInsertTableParam_put_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDEInsertTableParam_INTERFACE_DEFINED__ */


#ifndef ___DHTMLSafeEvents_DISPINTERFACE_DEFINED__
#define ___DHTMLSafeEvents_DISPINTERFACE_DEFINED__

/****************************************
 * Generated header for dispinterface: _DHTMLSafeEvents
 * at Thu Aug 06 10:08:26 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [helpstring][uuid] */ 



EXTERN_C const IID DIID__DHTMLSafeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D1FC78E8-B380-11d1-ADC5-006008A5848C")
    _DHTMLSafeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DHTMLSafeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _DHTMLSafeEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _DHTMLSafeEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _DHTMLSafeEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _DHTMLSafeEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _DHTMLSafeEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _DHTMLSafeEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _DHTMLSafeEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _DHTMLSafeEventsVtbl;

    interface _DHTMLSafeEvents
    {
        CONST_VTBL struct _DHTMLSafeEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DHTMLSafeEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DHTMLSafeEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DHTMLSafeEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DHTMLSafeEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DHTMLSafeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DHTMLSafeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DHTMLSafeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DHTMLSafeEvents_DISPINTERFACE_DEFINED__ */


#ifndef ___DHTMLEditEvents_DISPINTERFACE_DEFINED__
#define ___DHTMLEditEvents_DISPINTERFACE_DEFINED__

/****************************************
 * Generated header for dispinterface: _DHTMLEditEvents
 * at Thu Aug 06 10:08:26 1998
 * using MIDL 3.03.0110
 ****************************************/
/* [helpstring][uuid] */ 



EXTERN_C const IID DIID__DHTMLEditEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("588D5040-CF28-11d1-8CD3-00A0C959BC0A")
    _DHTMLEditEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DHTMLEditEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _DHTMLEditEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _DHTMLEditEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _DHTMLEditEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _DHTMLEditEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _DHTMLEditEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _DHTMLEditEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _DHTMLEditEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _DHTMLEditEventsVtbl;

    interface _DHTMLEditEvents
    {
        CONST_VTBL struct _DHTMLEditEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DHTMLEditEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DHTMLEditEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DHTMLEditEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DHTMLEditEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DHTMLEditEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DHTMLEditEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DHTMLEditEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DHTMLEditEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DHTMLEdit;

#ifdef __cplusplus

class DECLSPEC_UUID("2D360200-FFF5-11d1-8D03-00A0C959BC0A")
DHTMLEdit;
#endif

EXTERN_C const CLSID CLSID_DHTMLSafe;

#ifdef __cplusplus

class DECLSPEC_UUID("2D360201-FFF5-11d1-8D03-00A0C959BC0A")
DHTMLSafe;
#endif

EXTERN_C const CLSID CLSID_DEInsertTableParam;

#ifdef __cplusplus

class DECLSPEC_UUID("47B0DFC7-B7A3-11D1-ADC5-006008A5848C")
DEInsertTableParam;
#endif

EXTERN_C const CLSID CLSID_DEGetBlockFmtNamesParam;

#ifdef __cplusplus

class DECLSPEC_UUID("8D91090E-B955-11D1-ADC5-006008A5848C")
DEGetBlockFmtNamesParam;
#endif
#endif /* __DHTMLEDLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
