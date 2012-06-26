/**************************************************************************
*                                                                         *
* AgtCtl.h - Microsoft Agent Control                                      *
*                                                                         *
* Copyright (c) 1996-1999, Microsoft Corp. All rights reserved.           *
*                                                                         *
**************************************************************************/

#if _MSC_VER < 1200

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Sep 01 10:41:00 1998
 */
/* Compiler settings for AgentControl.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __AgtCtlVC5_h__
#define __AgtCtlVC5_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAgentCtlRequest_FWD_DEFINED__
#define __IAgentCtlRequest_FWD_DEFINED__
typedef interface IAgentCtlRequest IAgentCtlRequest;
#endif 	/* __IAgentCtlRequest_FWD_DEFINED__ */


#ifndef __IAgentCtlUserInput_FWD_DEFINED__
#define __IAgentCtlUserInput_FWD_DEFINED__
typedef interface IAgentCtlUserInput IAgentCtlUserInput;
#endif 	/* __IAgentCtlUserInput_FWD_DEFINED__ */


#ifndef __IAgentCtlBalloon_FWD_DEFINED__
#define __IAgentCtlBalloon_FWD_DEFINED__
typedef interface IAgentCtlBalloon IAgentCtlBalloon;
#endif 	/* __IAgentCtlBalloon_FWD_DEFINED__ */


#ifndef __IAgentCtlBalloonEx_FWD_DEFINED__
#define __IAgentCtlBalloonEx_FWD_DEFINED__
typedef interface IAgentCtlBalloonEx IAgentCtlBalloonEx;
#endif 	/* __IAgentCtlBalloonEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCommand_FWD_DEFINED__
#define __IAgentCtlCommand_FWD_DEFINED__
typedef interface IAgentCtlCommand IAgentCtlCommand;
#endif 	/* __IAgentCtlCommand_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandEx_FWD_DEFINED__
#define __IAgentCtlCommandEx_FWD_DEFINED__
typedef interface IAgentCtlCommandEx IAgentCtlCommandEx;
#endif 	/* __IAgentCtlCommandEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCommands_FWD_DEFINED__
#define __IAgentCtlCommands_FWD_DEFINED__
typedef interface IAgentCtlCommands IAgentCtlCommands;
#endif 	/* __IAgentCtlCommands_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandsEx_FWD_DEFINED__
#define __IAgentCtlCommandsEx_FWD_DEFINED__
typedef interface IAgentCtlCommandsEx IAgentCtlCommandsEx;
#endif 	/* __IAgentCtlCommandsEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacter_FWD_DEFINED__
#define __IAgentCtlCharacter_FWD_DEFINED__
typedef interface IAgentCtlCharacter IAgentCtlCharacter;
#endif 	/* __IAgentCtlCharacter_FWD_DEFINED__ */


#ifndef __IAgentCtlAnimationNames_FWD_DEFINED__
#define __IAgentCtlAnimationNames_FWD_DEFINED__
typedef interface IAgentCtlAnimationNames IAgentCtlAnimationNames;
#endif 	/* __IAgentCtlAnimationNames_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacterEx_FWD_DEFINED__
#define __IAgentCtlCharacterEx_FWD_DEFINED__
typedef interface IAgentCtlCharacterEx IAgentCtlCharacterEx;
#endif 	/* __IAgentCtlCharacterEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacters_FWD_DEFINED__
#define __IAgentCtlCharacters_FWD_DEFINED__
typedef interface IAgentCtlCharacters IAgentCtlCharacters;
#endif 	/* __IAgentCtlCharacters_FWD_DEFINED__ */


#ifndef __IAgentCtlAudioObject_FWD_DEFINED__
#define __IAgentCtlAudioObject_FWD_DEFINED__
typedef interface IAgentCtlAudioObject IAgentCtlAudioObject;
#endif 	/* __IAgentCtlAudioObject_FWD_DEFINED__ */


#ifndef __IAgentCtlAudioObjectEx_FWD_DEFINED__
#define __IAgentCtlAudioObjectEx_FWD_DEFINED__
typedef interface IAgentCtlAudioObjectEx IAgentCtlAudioObjectEx;
#endif 	/* __IAgentCtlAudioObjectEx_FWD_DEFINED__ */


#ifndef __IAgentCtlSpeechInput_FWD_DEFINED__
#define __IAgentCtlSpeechInput_FWD_DEFINED__
typedef interface IAgentCtlSpeechInput IAgentCtlSpeechInput;
#endif 	/* __IAgentCtlSpeechInput_FWD_DEFINED__ */


#ifndef __IAgentCtlPropertySheet_FWD_DEFINED__
#define __IAgentCtlPropertySheet_FWD_DEFINED__
typedef interface IAgentCtlPropertySheet IAgentCtlPropertySheet;
#endif 	/* __IAgentCtlPropertySheet_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandsWindow_FWD_DEFINED__
#define __IAgentCtlCommandsWindow_FWD_DEFINED__
typedef interface IAgentCtlCommandsWindow IAgentCtlCommandsWindow;
#endif 	/* __IAgentCtlCommandsWindow_FWD_DEFINED__ */


#ifndef __IAgentCtl_FWD_DEFINED__
#define __IAgentCtl_FWD_DEFINED__
typedef interface IAgentCtl IAgentCtl;
#endif 	/* __IAgentCtl_FWD_DEFINED__ */


#ifndef __IAgentCtlEx_FWD_DEFINED__
#define __IAgentCtlEx_FWD_DEFINED__
typedef interface IAgentCtlEx IAgentCtlEx;
#endif 	/* __IAgentCtlEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacters_FWD_DEFINED__
#define __IAgentCtlCharacters_FWD_DEFINED__
typedef interface IAgentCtlCharacters IAgentCtlCharacters;
#endif 	/* __IAgentCtlCharacters_FWD_DEFINED__ */


#ifndef __IAgentCtlBalloon_FWD_DEFINED__
#define __IAgentCtlBalloon_FWD_DEFINED__
typedef interface IAgentCtlBalloon IAgentCtlBalloon;
#endif 	/* __IAgentCtlBalloon_FWD_DEFINED__ */


#ifndef __IAgentCtlBalloonEx_FWD_DEFINED__
#define __IAgentCtlBalloonEx_FWD_DEFINED__
typedef interface IAgentCtlBalloonEx IAgentCtlBalloonEx;
#endif 	/* __IAgentCtlBalloonEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacter_FWD_DEFINED__
#define __IAgentCtlCharacter_FWD_DEFINED__
typedef interface IAgentCtlCharacter IAgentCtlCharacter;
#endif 	/* __IAgentCtlCharacter_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacterEx_FWD_DEFINED__
#define __IAgentCtlCharacterEx_FWD_DEFINED__
typedef interface IAgentCtlCharacterEx IAgentCtlCharacterEx;
#endif 	/* __IAgentCtlCharacterEx_FWD_DEFINED__ */


#ifndef __IAgentCtlAudioObject_FWD_DEFINED__
#define __IAgentCtlAudioObject_FWD_DEFINED__
typedef interface IAgentCtlAudioObject IAgentCtlAudioObject;
#endif 	/* __IAgentCtlAudioObject_FWD_DEFINED__ */


#ifndef __IAgentCtlAudioObjectEx_FWD_DEFINED__
#define __IAgentCtlAudioObjectEx_FWD_DEFINED__
typedef interface IAgentCtlAudioObjectEx IAgentCtlAudioObjectEx;
#endif 	/* __IAgentCtlAudioObjectEx_FWD_DEFINED__ */


#ifndef __IAgentCtlSpeechInput_FWD_DEFINED__
#define __IAgentCtlSpeechInput_FWD_DEFINED__
typedef interface IAgentCtlSpeechInput IAgentCtlSpeechInput;
#endif 	/* __IAgentCtlSpeechInput_FWD_DEFINED__ */


#ifndef __IAgentCtlPropertySheet_FWD_DEFINED__
#define __IAgentCtlPropertySheet_FWD_DEFINED__
typedef interface IAgentCtlPropertySheet IAgentCtlPropertySheet;
#endif 	/* __IAgentCtlPropertySheet_FWD_DEFINED__ */


#ifndef __IAgentCtlCommands_FWD_DEFINED__
#define __IAgentCtlCommands_FWD_DEFINED__
typedef interface IAgentCtlCommands IAgentCtlCommands;
#endif 	/* __IAgentCtlCommands_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandsEx_FWD_DEFINED__
#define __IAgentCtlCommandsEx_FWD_DEFINED__
typedef interface IAgentCtlCommandsEx IAgentCtlCommandsEx;
#endif 	/* __IAgentCtlCommandsEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCommand_FWD_DEFINED__
#define __IAgentCtlCommand_FWD_DEFINED__
typedef interface IAgentCtlCommand IAgentCtlCommand;
#endif 	/* __IAgentCtlCommand_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandEx_FWD_DEFINED__
#define __IAgentCtlCommandEx_FWD_DEFINED__
typedef interface IAgentCtlCommandEx IAgentCtlCommandEx;
#endif 	/* __IAgentCtlCommandEx_FWD_DEFINED__ */


#ifndef __IAgentCtlRequest_FWD_DEFINED__
#define __IAgentCtlRequest_FWD_DEFINED__
typedef interface IAgentCtlRequest IAgentCtlRequest;
#endif 	/* __IAgentCtlRequest_FWD_DEFINED__ */


#ifndef __IAgentCtlUserInput_FWD_DEFINED__
#define __IAgentCtlUserInput_FWD_DEFINED__
typedef interface IAgentCtlUserInput IAgentCtlUserInput;
#endif 	/* __IAgentCtlUserInput_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandsWindow_FWD_DEFINED__
#define __IAgentCtlCommandsWindow_FWD_DEFINED__
typedef interface IAgentCtlCommandsWindow IAgentCtlCommandsWindow;
#endif 	/* __IAgentCtlCommandsWindow_FWD_DEFINED__ */


#ifndef __IAgentCtl_FWD_DEFINED__
#define __IAgentCtl_FWD_DEFINED__
typedef interface IAgentCtl IAgentCtl;
#endif 	/* __IAgentCtl_FWD_DEFINED__ */


#ifndef __IAgentCtlEx_FWD_DEFINED__
#define __IAgentCtlEx_FWD_DEFINED__
typedef interface IAgentCtlEx IAgentCtlEx;
#endif 	/* __IAgentCtlEx_FWD_DEFINED__ */


#ifndef ___AgentEvents_FWD_DEFINED__
#define ___AgentEvents_FWD_DEFINED__
typedef interface _AgentEvents _AgentEvents;
#endif 	/* ___AgentEvents_FWD_DEFINED__ */


#ifndef __Agent_FWD_DEFINED__
#define __Agent_FWD_DEFINED__

#ifdef __cplusplus
typedef class Agent Agent;
#else
typedef struct Agent Agent;
#endif /* __cplusplus */

#endif 	/* __Agent_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_AgentControl_0000
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define	RequestSuccess	( 0 )

#define	RequestFailed	( 1 )

#define	RequestPending	( 2 )

#define	RequestInterrupted	( 3 )

#define	RequestInProgress	( 4 )



extern RPC_IF_HANDLE __MIDL_itf_AgentControl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AgentControl_0000_v0_0_s_ifspec;

#ifndef __IAgentCtlRequest_INTERFACE_DEFINED__
#define __IAgentCtlRequest_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlRequest
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlRequest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("1DAB85C3-803A-11D0-AC63-00C04FD97575")
    IAgentCtlRequest : public IDispatch
    {
    public:
        virtual /* [hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long __RPC_FAR *ID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ long __RPC_FAR *Status) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR __RPC_FAR *Description) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Number( 
            /* [retval][out] */ long __RPC_FAR *Number) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlRequestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlRequest __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlRequest __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ID )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Status )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Status);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Description )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Number )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Number);
        
        END_INTERFACE
    } IAgentCtlRequestVtbl;

    interface IAgentCtlRequest
    {
        CONST_VTBL struct IAgentCtlRequestVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlRequest_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlRequest_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlRequest_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlRequest_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlRequest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlRequest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlRequest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlRequest_get_ID(This,ID)	\
    (This)->lpVtbl -> get_ID(This,ID)

#define IAgentCtlRequest_get_Status(This,Status)	\
    (This)->lpVtbl -> get_Status(This,Status)

#define IAgentCtlRequest_get_Description(This,Description)	\
    (This)->lpVtbl -> get_Description(This,Description)

#define IAgentCtlRequest_get_Number(This,Number)	\
    (This)->lpVtbl -> get_Number(This,Number)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [hidden][propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlRequest_get_ID_Proxy( 
    IAgentCtlRequest __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ID);


void __RPC_STUB IAgentCtlRequest_get_ID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlRequest_get_Status_Proxy( 
    IAgentCtlRequest __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Status);


void __RPC_STUB IAgentCtlRequest_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlRequest_get_Description_Proxy( 
    IAgentCtlRequest __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Description);


void __RPC_STUB IAgentCtlRequest_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlRequest_get_Number_Proxy( 
    IAgentCtlRequest __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Number);


void __RPC_STUB IAgentCtlRequest_get_Number_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlRequest_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlUserInput_INTERFACE_DEFINED__
#define __IAgentCtlUserInput_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlUserInput
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [object][dual][uuid] */ 



EXTERN_C const IID IID_IAgentCtlUserInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("C4ABF875-8100-11D0-AC63-00C04FD97575")
    IAgentCtlUserInput : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ short __RPC_FAR *pCount) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CharacterID( 
            /* [retval][out] */ BSTR __RPC_FAR *pCharacterID) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Confidence( 
            /* [retval][out] */ long __RPC_FAR *pConfidence) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Voice( 
            /* [retval][out] */ BSTR __RPC_FAR *pVoice) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt1Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pAlt1Name) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt1Confidence( 
            /* [retval][out] */ long __RPC_FAR *pAlt1Confidence) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt1Voice( 
            /* [retval][out] */ BSTR __RPC_FAR *pAlt1Voice) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt2Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pAlt2Name) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt2Confidence( 
            /* [retval][out] */ long __RPC_FAR *pAlt2Confidence) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt2Voice( 
            /* [retval][out] */ BSTR __RPC_FAR *pAlt2Voice) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlUserInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlUserInput __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlUserInput __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pCount);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CharacterID )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pCharacterID);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Confidence )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pConfidence);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Voice )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVoice);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt1Name )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pAlt1Name);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt1Confidence )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pAlt1Confidence);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt1Voice )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pAlt1Voice);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt2Name )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pAlt2Name);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt2Confidence )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pAlt2Confidence);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt2Voice )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pAlt2Voice);
        
        END_INTERFACE
    } IAgentCtlUserInputVtbl;

    interface IAgentCtlUserInput
    {
        CONST_VTBL struct IAgentCtlUserInputVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlUserInput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlUserInput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlUserInput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlUserInput_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlUserInput_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlUserInput_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlUserInput_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlUserInput_get_Count(This,pCount)	\
    (This)->lpVtbl -> get_Count(This,pCount)

#define IAgentCtlUserInput_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IAgentCtlUserInput_get_CharacterID(This,pCharacterID)	\
    (This)->lpVtbl -> get_CharacterID(This,pCharacterID)

#define IAgentCtlUserInput_get_Confidence(This,pConfidence)	\
    (This)->lpVtbl -> get_Confidence(This,pConfidence)

#define IAgentCtlUserInput_get_Voice(This,pVoice)	\
    (This)->lpVtbl -> get_Voice(This,pVoice)

#define IAgentCtlUserInput_get_Alt1Name(This,pAlt1Name)	\
    (This)->lpVtbl -> get_Alt1Name(This,pAlt1Name)

#define IAgentCtlUserInput_get_Alt1Confidence(This,pAlt1Confidence)	\
    (This)->lpVtbl -> get_Alt1Confidence(This,pAlt1Confidence)

#define IAgentCtlUserInput_get_Alt1Voice(This,pAlt1Voice)	\
    (This)->lpVtbl -> get_Alt1Voice(This,pAlt1Voice)

#define IAgentCtlUserInput_get_Alt2Name(This,pAlt2Name)	\
    (This)->lpVtbl -> get_Alt2Name(This,pAlt2Name)

#define IAgentCtlUserInput_get_Alt2Confidence(This,pAlt2Confidence)	\
    (This)->lpVtbl -> get_Alt2Confidence(This,pAlt2Confidence)

#define IAgentCtlUserInput_get_Alt2Voice(This,pAlt2Voice)	\
    (This)->lpVtbl -> get_Alt2Voice(This,pAlt2Voice)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Count_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pCount);


void __RPC_STUB IAgentCtlUserInput_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Name_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pName);


void __RPC_STUB IAgentCtlUserInput_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_CharacterID_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pCharacterID);


void __RPC_STUB IAgentCtlUserInput_get_CharacterID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Confidence_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pConfidence);


void __RPC_STUB IAgentCtlUserInput_get_Confidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Voice_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVoice);


void __RPC_STUB IAgentCtlUserInput_get_Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt1Name_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pAlt1Name);


void __RPC_STUB IAgentCtlUserInput_get_Alt1Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt1Confidence_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pAlt1Confidence);


void __RPC_STUB IAgentCtlUserInput_get_Alt1Confidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt1Voice_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pAlt1Voice);


void __RPC_STUB IAgentCtlUserInput_get_Alt1Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt2Name_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pAlt2Name);


void __RPC_STUB IAgentCtlUserInput_get_Alt2Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt2Confidence_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pAlt2Confidence);


void __RPC_STUB IAgentCtlUserInput_get_Alt2Confidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt2Voice_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pAlt2Voice);


void __RPC_STUB IAgentCtlUserInput_get_Alt2Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlUserInput_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlBalloon_INTERFACE_DEFINED__
#define __IAgentCtlBalloon_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlBalloon
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlBalloon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("F5BE8BD3-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlBalloon : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_NumberOfLines( 
            /* [retval][out] */ long __RPC_FAR *Lines) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CharsPerLine( 
            /* [retval][out] */ long __RPC_FAR *CharsPerLine) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontName( 
            /* [retval][out] */ BSTR __RPC_FAR *FontName) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontSize( 
            /* [retval][out] */ long __RPC_FAR *FontSize) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontBold( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontBold) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontItalic( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontItalic) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontStrikethru( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontStrikethru) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontUnderline( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontUnderline) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ForeColor( 
            /* [retval][out] */ long __RPC_FAR *ForeColor) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ long __RPC_FAR *BackColor) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_BorderColor( 
            /* [retval][out] */ long __RPC_FAR *BorderColor) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_FontName( 
            /* [in] */ BSTR FontName) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_FontSize( 
            /* [in] */ long FontSize) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_FontCharSet( 
            /* [in] */ short FontCharSet) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontCharSet( 
            /* [retval][out] */ short __RPC_FAR *FontCharSet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlBalloonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlBalloon __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlBalloon __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NumberOfLines )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Lines);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CharsPerLine )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *CharsPerLine);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontName )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *FontName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontSize )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *FontSize);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontBold )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontBold);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontItalic )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontItalic);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontStrikethru )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontStrikethru);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontUnderline )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontUnderline);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForeColor )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ForeColor);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColor )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *BackColor);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BorderColor )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *BorderColor);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontName )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ BSTR FontName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontSize )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ long FontSize);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontCharSet )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ short FontCharSet);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontCharSet )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *FontCharSet);
        
        END_INTERFACE
    } IAgentCtlBalloonVtbl;

    interface IAgentCtlBalloon
    {
        CONST_VTBL struct IAgentCtlBalloonVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlBalloon_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlBalloon_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlBalloon_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlBalloon_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlBalloon_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlBalloon_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlBalloon_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlBalloon_get_Enabled(This,Enabled)	\
    (This)->lpVtbl -> get_Enabled(This,Enabled)

#define IAgentCtlBalloon_get_NumberOfLines(This,Lines)	\
    (This)->lpVtbl -> get_NumberOfLines(This,Lines)

#define IAgentCtlBalloon_get_CharsPerLine(This,CharsPerLine)	\
    (This)->lpVtbl -> get_CharsPerLine(This,CharsPerLine)

#define IAgentCtlBalloon_get_FontName(This,FontName)	\
    (This)->lpVtbl -> get_FontName(This,FontName)

#define IAgentCtlBalloon_get_FontSize(This,FontSize)	\
    (This)->lpVtbl -> get_FontSize(This,FontSize)

#define IAgentCtlBalloon_get_FontBold(This,FontBold)	\
    (This)->lpVtbl -> get_FontBold(This,FontBold)

#define IAgentCtlBalloon_get_FontItalic(This,FontItalic)	\
    (This)->lpVtbl -> get_FontItalic(This,FontItalic)

#define IAgentCtlBalloon_get_FontStrikethru(This,FontStrikethru)	\
    (This)->lpVtbl -> get_FontStrikethru(This,FontStrikethru)

#define IAgentCtlBalloon_get_FontUnderline(This,FontUnderline)	\
    (This)->lpVtbl -> get_FontUnderline(This,FontUnderline)

#define IAgentCtlBalloon_get_ForeColor(This,ForeColor)	\
    (This)->lpVtbl -> get_ForeColor(This,ForeColor)

#define IAgentCtlBalloon_get_BackColor(This,BackColor)	\
    (This)->lpVtbl -> get_BackColor(This,BackColor)

#define IAgentCtlBalloon_get_BorderColor(This,BorderColor)	\
    (This)->lpVtbl -> get_BorderColor(This,BorderColor)

#define IAgentCtlBalloon_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlBalloon_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlBalloon_put_FontName(This,FontName)	\
    (This)->lpVtbl -> put_FontName(This,FontName)

#define IAgentCtlBalloon_put_FontSize(This,FontSize)	\
    (This)->lpVtbl -> put_FontSize(This,FontSize)

#define IAgentCtlBalloon_put_FontCharSet(This,FontCharSet)	\
    (This)->lpVtbl -> put_FontCharSet(This,FontCharSet)

#define IAgentCtlBalloon_get_FontCharSet(This,FontCharSet)	\
    (This)->lpVtbl -> get_FontCharSet(This,FontCharSet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_Enabled_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);


void __RPC_STUB IAgentCtlBalloon_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_NumberOfLines_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Lines);


void __RPC_STUB IAgentCtlBalloon_get_NumberOfLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_CharsPerLine_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *CharsPerLine);


void __RPC_STUB IAgentCtlBalloon_get_CharsPerLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontName_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *FontName);


void __RPC_STUB IAgentCtlBalloon_get_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontSize_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *FontSize);


void __RPC_STUB IAgentCtlBalloon_get_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontBold_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontBold);


void __RPC_STUB IAgentCtlBalloon_get_FontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontItalic_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontItalic);


void __RPC_STUB IAgentCtlBalloon_get_FontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontStrikethru_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontStrikethru);


void __RPC_STUB IAgentCtlBalloon_get_FontStrikethru_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontUnderline_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontUnderline);


void __RPC_STUB IAgentCtlBalloon_get_FontUnderline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_ForeColor_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ForeColor);


void __RPC_STUB IAgentCtlBalloon_get_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_BackColor_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *BackColor);


void __RPC_STUB IAgentCtlBalloon_get_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_BorderColor_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *BorderColor);


void __RPC_STUB IAgentCtlBalloon_get_BorderColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_put_Visible_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Visible);


void __RPC_STUB IAgentCtlBalloon_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_Visible_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlBalloon_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_put_FontName_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [in] */ BSTR FontName);


void __RPC_STUB IAgentCtlBalloon_put_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_put_FontSize_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [in] */ long FontSize);


void __RPC_STUB IAgentCtlBalloon_put_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_put_FontCharSet_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [in] */ short FontCharSet);


void __RPC_STUB IAgentCtlBalloon_put_FontCharSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontCharSet_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *FontCharSet);


void __RPC_STUB IAgentCtlBalloon_get_FontCharSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlBalloon_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlBalloonEx_INTERFACE_DEFINED__
#define __IAgentCtlBalloonEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlBalloonEx
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlBalloonEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("822DB1C0-8879-11d1-9EC6-00C04FD7081F")
    IAgentCtlBalloonEx : public IAgentCtlBalloon
    {
    public:
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Style( 
            /* [in] */ long Style) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Style( 
            /* [retval][out] */ long __RPC_FAR *Style) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlBalloonExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlBalloonEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlBalloonEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NumberOfLines )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Lines);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CharsPerLine )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *CharsPerLine);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontName )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *FontName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontSize )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *FontSize);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontBold )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontBold);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontItalic )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontItalic);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontStrikethru )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontStrikethru);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontUnderline )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontUnderline);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForeColor )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ForeColor);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColor )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *BackColor);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BorderColor )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *BorderColor);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontName )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ BSTR FontName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontSize )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ long FontSize);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontCharSet )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ short FontCharSet);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontCharSet )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *FontCharSet);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Style )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ long Style);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Style )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Style);
        
        END_INTERFACE
    } IAgentCtlBalloonExVtbl;

    interface IAgentCtlBalloonEx
    {
        CONST_VTBL struct IAgentCtlBalloonExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlBalloonEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlBalloonEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlBalloonEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlBalloonEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlBalloonEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlBalloonEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlBalloonEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlBalloonEx_get_Enabled(This,Enabled)	\
    (This)->lpVtbl -> get_Enabled(This,Enabled)

#define IAgentCtlBalloonEx_get_NumberOfLines(This,Lines)	\
    (This)->lpVtbl -> get_NumberOfLines(This,Lines)

#define IAgentCtlBalloonEx_get_CharsPerLine(This,CharsPerLine)	\
    (This)->lpVtbl -> get_CharsPerLine(This,CharsPerLine)

#define IAgentCtlBalloonEx_get_FontName(This,FontName)	\
    (This)->lpVtbl -> get_FontName(This,FontName)

#define IAgentCtlBalloonEx_get_FontSize(This,FontSize)	\
    (This)->lpVtbl -> get_FontSize(This,FontSize)

#define IAgentCtlBalloonEx_get_FontBold(This,FontBold)	\
    (This)->lpVtbl -> get_FontBold(This,FontBold)

#define IAgentCtlBalloonEx_get_FontItalic(This,FontItalic)	\
    (This)->lpVtbl -> get_FontItalic(This,FontItalic)

#define IAgentCtlBalloonEx_get_FontStrikethru(This,FontStrikethru)	\
    (This)->lpVtbl -> get_FontStrikethru(This,FontStrikethru)

#define IAgentCtlBalloonEx_get_FontUnderline(This,FontUnderline)	\
    (This)->lpVtbl -> get_FontUnderline(This,FontUnderline)

#define IAgentCtlBalloonEx_get_ForeColor(This,ForeColor)	\
    (This)->lpVtbl -> get_ForeColor(This,ForeColor)

#define IAgentCtlBalloonEx_get_BackColor(This,BackColor)	\
    (This)->lpVtbl -> get_BackColor(This,BackColor)

#define IAgentCtlBalloonEx_get_BorderColor(This,BorderColor)	\
    (This)->lpVtbl -> get_BorderColor(This,BorderColor)

#define IAgentCtlBalloonEx_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlBalloonEx_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlBalloonEx_put_FontName(This,FontName)	\
    (This)->lpVtbl -> put_FontName(This,FontName)

#define IAgentCtlBalloonEx_put_FontSize(This,FontSize)	\
    (This)->lpVtbl -> put_FontSize(This,FontSize)

#define IAgentCtlBalloonEx_put_FontCharSet(This,FontCharSet)	\
    (This)->lpVtbl -> put_FontCharSet(This,FontCharSet)

#define IAgentCtlBalloonEx_get_FontCharSet(This,FontCharSet)	\
    (This)->lpVtbl -> get_FontCharSet(This,FontCharSet)


#define IAgentCtlBalloonEx_put_Style(This,Style)	\
    (This)->lpVtbl -> put_Style(This,Style)

#define IAgentCtlBalloonEx_get_Style(This,Style)	\
    (This)->lpVtbl -> get_Style(This,Style)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloonEx_put_Style_Proxy( 
    IAgentCtlBalloonEx __RPC_FAR * This,
    /* [in] */ long Style);


void __RPC_STUB IAgentCtlBalloonEx_put_Style_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloonEx_get_Style_Proxy( 
    IAgentCtlBalloonEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Style);


void __RPC_STUB IAgentCtlBalloonEx_get_Style_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlBalloonEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCommand_INTERFACE_DEFINED__
#define __IAgentCtlCommand_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlCommand
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlCommand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("F5BE8BE3-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlCommand : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Voice( 
            /* [retval][out] */ BSTR __RPC_FAR *Voice) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Voice( 
            /* [in] */ BSTR Voice) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR __RPC_FAR *Caption) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Caption( 
            /* [in] */ BSTR Caption) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL Enabled) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Confidence( 
            /* [retval][out] */ long __RPC_FAR *Confidence) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Confidence( 
            /* [in] */ long Confidence) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ConfidenceText( 
            /* [retval][out] */ BSTR __RPC_FAR *Text) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ConfidenceText( 
            /* [in] */ BSTR Text) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCommandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCommand __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCommand __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Voice )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Voice);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Voice )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ BSTR Voice);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Caption);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ BSTR Caption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Enabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Confidence )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Confidence);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Confidence )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ long Confidence);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ConfidenceText )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Text);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ConfidenceText )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ BSTR Text);
        
        END_INTERFACE
    } IAgentCtlCommandVtbl;

    interface IAgentCtlCommand
    {
        CONST_VTBL struct IAgentCtlCommandVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCommand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCommand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCommand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCommand_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCommand_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCommand_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCommand_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCommand_get_Voice(This,Voice)	\
    (This)->lpVtbl -> get_Voice(This,Voice)

#define IAgentCtlCommand_put_Voice(This,Voice)	\
    (This)->lpVtbl -> put_Voice(This,Voice)

#define IAgentCtlCommand_get_Caption(This,Caption)	\
    (This)->lpVtbl -> get_Caption(This,Caption)

#define IAgentCtlCommand_put_Caption(This,Caption)	\
    (This)->lpVtbl -> put_Caption(This,Caption)

#define IAgentCtlCommand_get_Enabled(This,Enabled)	\
    (This)->lpVtbl -> get_Enabled(This,Enabled)

#define IAgentCtlCommand_put_Enabled(This,Enabled)	\
    (This)->lpVtbl -> put_Enabled(This,Enabled)

#define IAgentCtlCommand_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCommand_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlCommand_get_Confidence(This,Confidence)	\
    (This)->lpVtbl -> get_Confidence(This,Confidence)

#define IAgentCtlCommand_put_Confidence(This,Confidence)	\
    (This)->lpVtbl -> put_Confidence(This,Confidence)

#define IAgentCtlCommand_get_ConfidenceText(This,Text)	\
    (This)->lpVtbl -> get_ConfidenceText(This,Text)

#define IAgentCtlCommand_put_ConfidenceText(This,Text)	\
    (This)->lpVtbl -> put_ConfidenceText(This,Text)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_Voice_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Voice);


void __RPC_STUB IAgentCtlCommand_get_Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_Voice_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ BSTR Voice);


void __RPC_STUB IAgentCtlCommand_put_Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_Caption_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Caption);


void __RPC_STUB IAgentCtlCommand_get_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_Caption_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ BSTR Caption);


void __RPC_STUB IAgentCtlCommand_put_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_Enabled_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);


void __RPC_STUB IAgentCtlCommand_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_Enabled_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Enabled);


void __RPC_STUB IAgentCtlCommand_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_Visible_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlCommand_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_Visible_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Visible);


void __RPC_STUB IAgentCtlCommand_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_Confidence_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Confidence);


void __RPC_STUB IAgentCtlCommand_get_Confidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_Confidence_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ long Confidence);


void __RPC_STUB IAgentCtlCommand_put_Confidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_ConfidenceText_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Text);


void __RPC_STUB IAgentCtlCommand_get_ConfidenceText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_ConfidenceText_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ BSTR Text);


void __RPC_STUB IAgentCtlCommand_put_ConfidenceText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCommand_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCommandEx_INTERFACE_DEFINED__
#define __IAgentCtlCommandEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlCommandEx
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlCommandEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("B0913410-3B44-11d1-ACBA-00C04FD97575")
    IAgentCtlCommandEx : public IAgentCtlCommand
    {
    public:
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpContextID( 
            /* [in] */ long ID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpContextID( 
            /* [retval][out] */ long __RPC_FAR *ID) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_VoiceCaption( 
            /* [in] */ BSTR VoiceCaption) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_VoiceCaption( 
            /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCommandExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCommandEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCommandEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Voice )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Voice);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Voice )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ BSTR Voice);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Caption);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ BSTR Caption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Enabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Confidence )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Confidence);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Confidence )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ long Confidence);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ConfidenceText )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Text);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ConfidenceText )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ BSTR Text);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpContextID )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ long ID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpContextID )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ID);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_VoiceCaption )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ BSTR VoiceCaption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VoiceCaption )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption);
        
        END_INTERFACE
    } IAgentCtlCommandExVtbl;

    interface IAgentCtlCommandEx
    {
        CONST_VTBL struct IAgentCtlCommandExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCommandEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCommandEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCommandEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCommandEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCommandEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCommandEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCommandEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCommandEx_get_Voice(This,Voice)	\
    (This)->lpVtbl -> get_Voice(This,Voice)

#define IAgentCtlCommandEx_put_Voice(This,Voice)	\
    (This)->lpVtbl -> put_Voice(This,Voice)

#define IAgentCtlCommandEx_get_Caption(This,Caption)	\
    (This)->lpVtbl -> get_Caption(This,Caption)

#define IAgentCtlCommandEx_put_Caption(This,Caption)	\
    (This)->lpVtbl -> put_Caption(This,Caption)

#define IAgentCtlCommandEx_get_Enabled(This,Enabled)	\
    (This)->lpVtbl -> get_Enabled(This,Enabled)

#define IAgentCtlCommandEx_put_Enabled(This,Enabled)	\
    (This)->lpVtbl -> put_Enabled(This,Enabled)

#define IAgentCtlCommandEx_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCommandEx_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlCommandEx_get_Confidence(This,Confidence)	\
    (This)->lpVtbl -> get_Confidence(This,Confidence)

#define IAgentCtlCommandEx_put_Confidence(This,Confidence)	\
    (This)->lpVtbl -> put_Confidence(This,Confidence)

#define IAgentCtlCommandEx_get_ConfidenceText(This,Text)	\
    (This)->lpVtbl -> get_ConfidenceText(This,Text)

#define IAgentCtlCommandEx_put_ConfidenceText(This,Text)	\
    (This)->lpVtbl -> put_ConfidenceText(This,Text)


#define IAgentCtlCommandEx_put_HelpContextID(This,ID)	\
    (This)->lpVtbl -> put_HelpContextID(This,ID)

#define IAgentCtlCommandEx_get_HelpContextID(This,ID)	\
    (This)->lpVtbl -> get_HelpContextID(This,ID)

#define IAgentCtlCommandEx_put_VoiceCaption(This,VoiceCaption)	\
    (This)->lpVtbl -> put_VoiceCaption(This,VoiceCaption)

#define IAgentCtlCommandEx_get_VoiceCaption(This,VoiceCaption)	\
    (This)->lpVtbl -> get_VoiceCaption(This,VoiceCaption)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandEx_put_HelpContextID_Proxy( 
    IAgentCtlCommandEx __RPC_FAR * This,
    /* [in] */ long ID);


void __RPC_STUB IAgentCtlCommandEx_put_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandEx_get_HelpContextID_Proxy( 
    IAgentCtlCommandEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ID);


void __RPC_STUB IAgentCtlCommandEx_get_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandEx_put_VoiceCaption_Proxy( 
    IAgentCtlCommandEx __RPC_FAR * This,
    /* [in] */ BSTR VoiceCaption);


void __RPC_STUB IAgentCtlCommandEx_put_VoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandEx_get_VoiceCaption_Proxy( 
    IAgentCtlCommandEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption);


void __RPC_STUB IAgentCtlCommandEx_get_VoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCommandEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCommands_INTERFACE_DEFINED__
#define __IAgentCtlCommands_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlCommands
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlCommands;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("F5BE8BE1-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlCommands : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Command( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *Count) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR __RPC_FAR *Caption) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Caption( 
            /* [in] */ BSTR Caption) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Voice( 
            /* [retval][out] */ BSTR __RPC_FAR *Voice) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Voice( 
            /* [in] */ BSTR Voice) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ BSTR Name,
            /* [in] */ BSTR RefName,
            /* [optional][in] */ VARIANT Before,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCommandsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCommands __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCommands __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Command )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Count);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Caption);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Caption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Voice )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Voice);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Voice )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Voice);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enum )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [in] */ BSTR RefName,
            /* [optional][in] */ VARIANT Before,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll )( 
            IAgentCtlCommands __RPC_FAR * This);
        
        END_INTERFACE
    } IAgentCtlCommandsVtbl;

    interface IAgentCtlCommands
    {
        CONST_VTBL struct IAgentCtlCommandsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCommands_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCommands_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCommands_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCommands_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCommands_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCommands_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCommands_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCommands_get_Item(This,Name,Item)	\
    (This)->lpVtbl -> get_Item(This,Name,Item)

#define IAgentCtlCommands_Command(This,Name,Item)	\
    (This)->lpVtbl -> Command(This,Name,Item)

#define IAgentCtlCommands_get_Count(This,Count)	\
    (This)->lpVtbl -> get_Count(This,Count)

#define IAgentCtlCommands_get_Caption(This,Caption)	\
    (This)->lpVtbl -> get_Caption(This,Caption)

#define IAgentCtlCommands_put_Caption(This,Caption)	\
    (This)->lpVtbl -> put_Caption(This,Caption)

#define IAgentCtlCommands_get_Voice(This,Voice)	\
    (This)->lpVtbl -> get_Voice(This,Voice)

#define IAgentCtlCommands_put_Voice(This,Voice)	\
    (This)->lpVtbl -> put_Voice(This,Voice)

#define IAgentCtlCommands_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCommands_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlCommands_get_Enum(This,ppunkEnum)	\
    (This)->lpVtbl -> get_Enum(This,ppunkEnum)

#define IAgentCtlCommands_Add(This,Name,Caption,Voice,Enabled,Visible,Command)	\
    (This)->lpVtbl -> Add(This,Name,Caption,Voice,Enabled,Visible,Command)

#define IAgentCtlCommands_Insert(This,Name,RefName,Before,Caption,Voice,Enabled,Visible,Command)	\
    (This)->lpVtbl -> Insert(This,Name,RefName,Before,Caption,Voice,Enabled,Visible,Command)

#define IAgentCtlCommands_Remove(This,Name)	\
    (This)->lpVtbl -> Remove(This,Name)

#define IAgentCtlCommands_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Item_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);


void __RPC_STUB IAgentCtlCommands_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_Command_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);


void __RPC_STUB IAgentCtlCommands_Command_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Count_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Count);


void __RPC_STUB IAgentCtlCommands_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Caption_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Caption);


void __RPC_STUB IAgentCtlCommands_get_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_put_Caption_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Caption);


void __RPC_STUB IAgentCtlCommands_put_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Voice_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Voice);


void __RPC_STUB IAgentCtlCommands_get_Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_put_Voice_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Voice);


void __RPC_STUB IAgentCtlCommands_put_Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Visible_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlCommands_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_put_Visible_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Visible);


void __RPC_STUB IAgentCtlCommands_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Enum_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);


void __RPC_STUB IAgentCtlCommands_get_Enum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_Add_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [optional][in] */ VARIANT Caption,
    /* [optional][in] */ VARIANT Voice,
    /* [optional][in] */ VARIANT Enabled,
    /* [optional][in] */ VARIANT Visible,
    /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);


void __RPC_STUB IAgentCtlCommands_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_Insert_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [in] */ BSTR RefName,
    /* [optional][in] */ VARIANT Before,
    /* [optional][in] */ VARIANT Caption,
    /* [optional][in] */ VARIANT Voice,
    /* [optional][in] */ VARIANT Enabled,
    /* [optional][in] */ VARIANT Visible,
    /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);


void __RPC_STUB IAgentCtlCommands_Insert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_Remove_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB IAgentCtlCommands_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_RemoveAll_Proxy( 
    IAgentCtlCommands __RPC_FAR * This);


void __RPC_STUB IAgentCtlCommands_RemoveAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCommands_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCommandsEx_INTERFACE_DEFINED__
#define __IAgentCtlCommandsEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlCommandsEx
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlCommandsEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("6BA90C01-3910-11d1-ACB3-00C04FD97575")
    IAgentCtlCommandsEx : public IAgentCtlCommands
    {
    public:
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultCommand( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultCommand( 
            /* [retval][out] */ BSTR __RPC_FAR *Name) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpContextID( 
            /* [in] */ long ID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpContextID( 
            /* [retval][out] */ long __RPC_FAR *ID) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_FontName( 
            /* [in] */ BSTR FontName) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontName( 
            /* [retval][out] */ BSTR __RPC_FAR *FontName) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontSize( 
            /* [retval][out] */ long __RPC_FAR *FontSize) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_FontSize( 
            /* [in] */ long FontSize) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_VoiceCaption( 
            /* [in] */ BSTR VoiceCaption) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_VoiceCaption( 
            /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_GlobalVoiceCommandsEnabled( 
            /* [in] */ VARIANT_BOOL Enable) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_GlobalVoiceCommandsEnabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCommandsExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCommandsEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCommandsEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Command )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Count);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Caption);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Caption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Voice )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Voice);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Voice )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Voice);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enum )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [in] */ BSTR RefName,
            /* [optional][in] */ VARIANT Before,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll )( 
            IAgentCtlCommandsEx __RPC_FAR * This);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultCommand )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultCommand )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Name);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpContextID )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ long ID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpContextID )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ID);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontName )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR FontName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontName )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *FontName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontSize )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *FontSize);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontSize )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ long FontSize);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_VoiceCaption )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR VoiceCaption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VoiceCaption )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GlobalVoiceCommandsEnabled )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Enable);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GlobalVoiceCommandsEnabled )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enable);
        
        END_INTERFACE
    } IAgentCtlCommandsExVtbl;

    interface IAgentCtlCommandsEx
    {
        CONST_VTBL struct IAgentCtlCommandsExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCommandsEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCommandsEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCommandsEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCommandsEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCommandsEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCommandsEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCommandsEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCommandsEx_get_Item(This,Name,Item)	\
    (This)->lpVtbl -> get_Item(This,Name,Item)

#define IAgentCtlCommandsEx_Command(This,Name,Item)	\
    (This)->lpVtbl -> Command(This,Name,Item)

#define IAgentCtlCommandsEx_get_Count(This,Count)	\
    (This)->lpVtbl -> get_Count(This,Count)

#define IAgentCtlCommandsEx_get_Caption(This,Caption)	\
    (This)->lpVtbl -> get_Caption(This,Caption)

#define IAgentCtlCommandsEx_put_Caption(This,Caption)	\
    (This)->lpVtbl -> put_Caption(This,Caption)

#define IAgentCtlCommandsEx_get_Voice(This,Voice)	\
    (This)->lpVtbl -> get_Voice(This,Voice)

#define IAgentCtlCommandsEx_put_Voice(This,Voice)	\
    (This)->lpVtbl -> put_Voice(This,Voice)

#define IAgentCtlCommandsEx_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCommandsEx_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlCommandsEx_get_Enum(This,ppunkEnum)	\
    (This)->lpVtbl -> get_Enum(This,ppunkEnum)

#define IAgentCtlCommandsEx_Add(This,Name,Caption,Voice,Enabled,Visible,Command)	\
    (This)->lpVtbl -> Add(This,Name,Caption,Voice,Enabled,Visible,Command)

#define IAgentCtlCommandsEx_Insert(This,Name,RefName,Before,Caption,Voice,Enabled,Visible,Command)	\
    (This)->lpVtbl -> Insert(This,Name,RefName,Before,Caption,Voice,Enabled,Visible,Command)

#define IAgentCtlCommandsEx_Remove(This,Name)	\
    (This)->lpVtbl -> Remove(This,Name)

#define IAgentCtlCommandsEx_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)


#define IAgentCtlCommandsEx_put_DefaultCommand(This,Name)	\
    (This)->lpVtbl -> put_DefaultCommand(This,Name)

#define IAgentCtlCommandsEx_get_DefaultCommand(This,Name)	\
    (This)->lpVtbl -> get_DefaultCommand(This,Name)

#define IAgentCtlCommandsEx_put_HelpContextID(This,ID)	\
    (This)->lpVtbl -> put_HelpContextID(This,ID)

#define IAgentCtlCommandsEx_get_HelpContextID(This,ID)	\
    (This)->lpVtbl -> get_HelpContextID(This,ID)

#define IAgentCtlCommandsEx_put_FontName(This,FontName)	\
    (This)->lpVtbl -> put_FontName(This,FontName)

#define IAgentCtlCommandsEx_get_FontName(This,FontName)	\
    (This)->lpVtbl -> get_FontName(This,FontName)

#define IAgentCtlCommandsEx_get_FontSize(This,FontSize)	\
    (This)->lpVtbl -> get_FontSize(This,FontSize)

#define IAgentCtlCommandsEx_put_FontSize(This,FontSize)	\
    (This)->lpVtbl -> put_FontSize(This,FontSize)

#define IAgentCtlCommandsEx_put_VoiceCaption(This,VoiceCaption)	\
    (This)->lpVtbl -> put_VoiceCaption(This,VoiceCaption)

#define IAgentCtlCommandsEx_get_VoiceCaption(This,VoiceCaption)	\
    (This)->lpVtbl -> get_VoiceCaption(This,VoiceCaption)

#define IAgentCtlCommandsEx_put_GlobalVoiceCommandsEnabled(This,Enable)	\
    (This)->lpVtbl -> put_GlobalVoiceCommandsEnabled(This,Enable)

#define IAgentCtlCommandsEx_get_GlobalVoiceCommandsEnabled(This,Enable)	\
    (This)->lpVtbl -> get_GlobalVoiceCommandsEnabled(This,Enable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_DefaultCommand_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB IAgentCtlCommandsEx_put_DefaultCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_DefaultCommand_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Name);


void __RPC_STUB IAgentCtlCommandsEx_get_DefaultCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_HelpContextID_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ long ID);


void __RPC_STUB IAgentCtlCommandsEx_put_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_HelpContextID_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ID);


void __RPC_STUB IAgentCtlCommandsEx_get_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_FontName_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR FontName);


void __RPC_STUB IAgentCtlCommandsEx_put_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_FontName_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *FontName);


void __RPC_STUB IAgentCtlCommandsEx_get_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_FontSize_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *FontSize);


void __RPC_STUB IAgentCtlCommandsEx_get_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_FontSize_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ long FontSize);


void __RPC_STUB IAgentCtlCommandsEx_put_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_VoiceCaption_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR VoiceCaption);


void __RPC_STUB IAgentCtlCommandsEx_put_VoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_VoiceCaption_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption);


void __RPC_STUB IAgentCtlCommandsEx_get_VoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_GlobalVoiceCommandsEnabled_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Enable);


void __RPC_STUB IAgentCtlCommandsEx_put_GlobalVoiceCommandsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_GlobalVoiceCommandsEnabled_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enable);


void __RPC_STUB IAgentCtlCommandsEx_get_GlobalVoiceCommandsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCommandsEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCharacter_INTERFACE_DEFINED__
#define __IAgentCtlCharacter_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlCharacter
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlCharacter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("F5BE8BD9-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlCharacter : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Balloon( 
            /* [retval][out] */ IAgentCtlBalloonEx __RPC_FAR *__RPC_FAR *ppidBalloon) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Commands( 
            /* [retval][out] */ IAgentCtlCommandsEx __RPC_FAR *__RPC_FAR *ppidCommands) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *Name) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR __RPC_FAR *Description) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Left( 
            short Left) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ short __RPC_FAR *Left) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Top( 
            short Top) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ short __RPC_FAR *Top) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Height( 
            short Height) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ short __RPC_FAR *Height) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Width( 
            short Width) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ short __RPC_FAR *Width) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Speed( 
            /* [retval][out] */ long __RPC_FAR *Speed) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Pitch( 
            /* [retval][out] */ long __RPC_FAR *Pitch) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_IdleOn( 
            VARIANT_BOOL On) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IdleOn( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Activate( 
            /* [optional][in] */ VARIANT State,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Success) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Play( 
            /* [in] */ BSTR Animation,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ BSTR Type,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Queue,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Stop( 
            /* [optional][in] */ VARIANT Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Wait( 
            /* [in] */ IDispatch __RPC_FAR *WaitForRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Interrupt( 
            /* [in] */ IDispatch __RPC_FAR *InterruptRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Speak( 
            /* [optional][in] */ VARIANT Text,
            /* [optional][in] */ VARIANT Url,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GestureAt( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MoveTo( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [optional][in] */ VARIANT Speed,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Hide( 
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Show( 
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StopAll( 
            /* [optional][in] */ VARIANT Types) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MoveCause( 
            /* [retval][out] */ short __RPC_FAR *MoveCause) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_VisibilityCause( 
            /* [retval][out] */ short __RPC_FAR *VisibilityCause) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HasOtherClients( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *HasOtherClients) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_SoundEffectsOn( 
            VARIANT_BOOL On) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SoundEffectsOn( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR Description) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ExtraData( 
            /* [retval][out] */ BSTR __RPC_FAR *ExtraData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCharacterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCharacter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCharacter __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Balloon )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlBalloonEx __RPC_FAR *__RPC_FAR *ppidBalloon);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Commands )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCommandsEx __RPC_FAR *__RPC_FAR *ppidCommands);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Description )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Left )( 
            IAgentCtlCharacter __RPC_FAR * This,
            short Left);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Left )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Left);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Top )( 
            IAgentCtlCharacter __RPC_FAR * This,
            short Top);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Top )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Top);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Height )( 
            IAgentCtlCharacter __RPC_FAR * This,
            short Height);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Height )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Height);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Width )( 
            IAgentCtlCharacter __RPC_FAR * This,
            short Width);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Width);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Speed )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Speed);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Pitch )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Pitch);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IdleOn )( 
            IAgentCtlCharacter __RPC_FAR * This,
            VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IdleOn )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Activate )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT State,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Success);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ BSTR Animation,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Get )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ BSTR Type,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Queue,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Wait )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *WaitForRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Interrupt )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *InterruptRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Speak )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT Text,
            /* [optional][in] */ VARIANT Url,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GestureAt )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [optional][in] */ VARIANT Speed,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hide )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Show )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopAll )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT Types);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MoveCause )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *MoveCause);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VisibilityCause )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *VisibilityCause);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HasOtherClients )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *HasOtherClients);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SoundEffectsOn )( 
            IAgentCtlCharacter __RPC_FAR * This,
            VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SoundEffectsOn )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Description )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ BSTR Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ExtraData )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ExtraData);
        
        END_INTERFACE
    } IAgentCtlCharacterVtbl;

    interface IAgentCtlCharacter
    {
        CONST_VTBL struct IAgentCtlCharacterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCharacter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCharacter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCharacter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCharacter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCharacter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCharacter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCharacter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCharacter_get_Balloon(This,ppidBalloon)	\
    (This)->lpVtbl -> get_Balloon(This,ppidBalloon)

#define IAgentCtlCharacter_get_Commands(This,ppidCommands)	\
    (This)->lpVtbl -> get_Commands(This,ppidCommands)

#define IAgentCtlCharacter_get_Name(This,Name)	\
    (This)->lpVtbl -> get_Name(This,Name)

#define IAgentCtlCharacter_get_Description(This,Description)	\
    (This)->lpVtbl -> get_Description(This,Description)

#define IAgentCtlCharacter_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCharacter_put_Left(This,Left)	\
    (This)->lpVtbl -> put_Left(This,Left)

#define IAgentCtlCharacter_get_Left(This,Left)	\
    (This)->lpVtbl -> get_Left(This,Left)

#define IAgentCtlCharacter_put_Top(This,Top)	\
    (This)->lpVtbl -> put_Top(This,Top)

#define IAgentCtlCharacter_get_Top(This,Top)	\
    (This)->lpVtbl -> get_Top(This,Top)

#define IAgentCtlCharacter_put_Height(This,Height)	\
    (This)->lpVtbl -> put_Height(This,Height)

#define IAgentCtlCharacter_get_Height(This,Height)	\
    (This)->lpVtbl -> get_Height(This,Height)

#define IAgentCtlCharacter_put_Width(This,Width)	\
    (This)->lpVtbl -> put_Width(This,Width)

#define IAgentCtlCharacter_get_Width(This,Width)	\
    (This)->lpVtbl -> get_Width(This,Width)

#define IAgentCtlCharacter_get_Speed(This,Speed)	\
    (This)->lpVtbl -> get_Speed(This,Speed)

#define IAgentCtlCharacter_get_Pitch(This,Pitch)	\
    (This)->lpVtbl -> get_Pitch(This,Pitch)

#define IAgentCtlCharacter_put_IdleOn(This,On)	\
    (This)->lpVtbl -> put_IdleOn(This,On)

#define IAgentCtlCharacter_get_IdleOn(This,On)	\
    (This)->lpVtbl -> get_IdleOn(This,On)

#define IAgentCtlCharacter_Activate(This,State,Success)	\
    (This)->lpVtbl -> Activate(This,State,Success)

#define IAgentCtlCharacter_Play(This,Animation,Request)	\
    (This)->lpVtbl -> Play(This,Animation,Request)

#define IAgentCtlCharacter_Get(This,Type,Name,Queue,Request)	\
    (This)->lpVtbl -> Get(This,Type,Name,Queue,Request)

#define IAgentCtlCharacter_Stop(This,Request)	\
    (This)->lpVtbl -> Stop(This,Request)

#define IAgentCtlCharacter_Wait(This,WaitForRequest,Request)	\
    (This)->lpVtbl -> Wait(This,WaitForRequest,Request)

#define IAgentCtlCharacter_Interrupt(This,InterruptRequest,Request)	\
    (This)->lpVtbl -> Interrupt(This,InterruptRequest,Request)

#define IAgentCtlCharacter_Speak(This,Text,Url,Request)	\
    (This)->lpVtbl -> Speak(This,Text,Url,Request)

#define IAgentCtlCharacter_GestureAt(This,x,y,Request)	\
    (This)->lpVtbl -> GestureAt(This,x,y,Request)

#define IAgentCtlCharacter_MoveTo(This,x,y,Speed,Request)	\
    (This)->lpVtbl -> MoveTo(This,x,y,Speed,Request)

#define IAgentCtlCharacter_Hide(This,Fast,Request)	\
    (This)->lpVtbl -> Hide(This,Fast,Request)

#define IAgentCtlCharacter_Show(This,Fast,Request)	\
    (This)->lpVtbl -> Show(This,Fast,Request)

#define IAgentCtlCharacter_StopAll(This,Types)	\
    (This)->lpVtbl -> StopAll(This,Types)

#define IAgentCtlCharacter_get_MoveCause(This,MoveCause)	\
    (This)->lpVtbl -> get_MoveCause(This,MoveCause)

#define IAgentCtlCharacter_get_VisibilityCause(This,VisibilityCause)	\
    (This)->lpVtbl -> get_VisibilityCause(This,VisibilityCause)

#define IAgentCtlCharacter_get_HasOtherClients(This,HasOtherClients)	\
    (This)->lpVtbl -> get_HasOtherClients(This,HasOtherClients)

#define IAgentCtlCharacter_put_SoundEffectsOn(This,On)	\
    (This)->lpVtbl -> put_SoundEffectsOn(This,On)

#define IAgentCtlCharacter_get_SoundEffectsOn(This,On)	\
    (This)->lpVtbl -> get_SoundEffectsOn(This,On)

#define IAgentCtlCharacter_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IAgentCtlCharacter_put_Description(This,Description)	\
    (This)->lpVtbl -> put_Description(This,Description)

#define IAgentCtlCharacter_get_ExtraData(This,ExtraData)	\
    (This)->lpVtbl -> get_ExtraData(This,ExtraData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Balloon_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlBalloonEx __RPC_FAR *__RPC_FAR *ppidBalloon);


void __RPC_STUB IAgentCtlCharacter_get_Balloon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Commands_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlCommandsEx __RPC_FAR *__RPC_FAR *ppidCommands);


void __RPC_STUB IAgentCtlCharacter_get_Commands_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Name_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Name);


void __RPC_STUB IAgentCtlCharacter_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Description_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Description);


void __RPC_STUB IAgentCtlCharacter_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Visible_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlCharacter_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Left_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    short Left);


void __RPC_STUB IAgentCtlCharacter_put_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Left_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Left);


void __RPC_STUB IAgentCtlCharacter_get_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Top_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    short Top);


void __RPC_STUB IAgentCtlCharacter_put_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Top_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Top);


void __RPC_STUB IAgentCtlCharacter_get_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Height_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    short Height);


void __RPC_STUB IAgentCtlCharacter_put_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Height_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Height);


void __RPC_STUB IAgentCtlCharacter_get_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Width_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    short Width);


void __RPC_STUB IAgentCtlCharacter_put_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Width_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Width);


void __RPC_STUB IAgentCtlCharacter_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Speed_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Speed);


void __RPC_STUB IAgentCtlCharacter_get_Speed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Pitch_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Pitch);


void __RPC_STUB IAgentCtlCharacter_get_Pitch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_IdleOn_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    VARIANT_BOOL On);


void __RPC_STUB IAgentCtlCharacter_put_IdleOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_IdleOn_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);


void __RPC_STUB IAgentCtlCharacter_get_IdleOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Activate_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT State,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Success);


void __RPC_STUB IAgentCtlCharacter_Activate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Play_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ BSTR Animation,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Play_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Get_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ BSTR Type,
    /* [in] */ BSTR Name,
    /* [optional][in] */ VARIANT Queue,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Get_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Stop_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT Request);


void __RPC_STUB IAgentCtlCharacter_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Wait_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *WaitForRequest,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Wait_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Interrupt_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *InterruptRequest,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Interrupt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Speak_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT Text,
    /* [optional][in] */ VARIANT Url,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Speak_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_GestureAt_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_GestureAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_MoveTo_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [optional][in] */ VARIANT Speed,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_MoveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Hide_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT Fast,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Hide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Show_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT Fast,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Show_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_StopAll_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT Types);


void __RPC_STUB IAgentCtlCharacter_StopAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_MoveCause_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *MoveCause);


void __RPC_STUB IAgentCtlCharacter_get_MoveCause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_VisibilityCause_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *VisibilityCause);


void __RPC_STUB IAgentCtlCharacter_get_VisibilityCause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_HasOtherClients_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *HasOtherClients);


void __RPC_STUB IAgentCtlCharacter_get_HasOtherClients_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_SoundEffectsOn_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    VARIANT_BOOL On);


void __RPC_STUB IAgentCtlCharacter_put_SoundEffectsOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_SoundEffectsOn_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);


void __RPC_STUB IAgentCtlCharacter_get_SoundEffectsOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Name_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB IAgentCtlCharacter_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Description_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ BSTR Description);


void __RPC_STUB IAgentCtlCharacter_put_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_ExtraData_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *ExtraData);


void __RPC_STUB IAgentCtlCharacter_get_ExtraData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCharacter_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlAnimationNames_INTERFACE_DEFINED__
#define __IAgentCtlAnimationNames_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlAnimationNames
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlAnimationNames;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8B77181C-D3EF-11d1-8500-00C04FA34A14")
    IAgentCtlAnimationNames : public IDispatch
    {
    public:
        virtual /* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlAnimationNamesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlAnimationNames __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlAnimationNames __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enum )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);
        
        END_INTERFACE
    } IAgentCtlAnimationNamesVtbl;

    interface IAgentCtlAnimationNames
    {
        CONST_VTBL struct IAgentCtlAnimationNamesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlAnimationNames_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlAnimationNames_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlAnimationNames_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlAnimationNames_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlAnimationNames_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlAnimationNames_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlAnimationNames_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlAnimationNames_get_Enum(This,ppunkEnum)	\
    (This)->lpVtbl -> get_Enum(This,ppunkEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlAnimationNames_get_Enum_Proxy( 
    IAgentCtlAnimationNames __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);


void __RPC_STUB IAgentCtlAnimationNames_get_Enum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlAnimationNames_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCharacterEx_INTERFACE_DEFINED__
#define __IAgentCtlCharacterEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlCharacterEx
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlCharacterEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("DE8EF600-2F82-11d1-ACAC-00C04FD97575")
    IAgentCtlCharacterEx : public IAgentCtlCharacter
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowPopupMenu( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Showed) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoPopupMenu( 
            /* [in] */ VARIANT_BOOL On) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoPopupMenu( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpModeOn( 
            /* [in] */ VARIANT_BOOL On) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpModeOn( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpContextID( 
            /* [in] */ long ID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpContextID( 
            /* [retval][out] */ long __RPC_FAR *ID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ short __RPC_FAR *State) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Listen( 
            /* [in] */ VARIANT_BOOL Listen,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *StartedListening) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_LanguageID( 
            /* [in] */ long LanguageID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LanguageID( 
            /* [retval][out] */ long __RPC_FAR *LanguageID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SRModeID( 
            /* [retval][out] */ BSTR __RPC_FAR *EngineModeId) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_SRModeID( 
            /* [in] */ BSTR EngineModeId) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_TTSModeID( 
            /* [retval][out] */ BSTR __RPC_FAR *EngineModeId) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_TTSModeID( 
            /* [in] */ BSTR EngineModeId) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpFile( 
            /* [retval][out] */ BSTR __RPC_FAR *File) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpFile( 
            /* [in] */ BSTR File) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_GUID( 
            /* [retval][out] */ BSTR __RPC_FAR *GUID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_OriginalHeight( 
            /* [retval][out] */ short __RPC_FAR *Height) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_OriginalWidth( 
            /* [retval][out] */ short __RPC_FAR *Width) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Think( 
            /* [in] */ BSTR Text,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ BSTR __RPC_FAR *Version) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_AnimationNames( 
            /* [retval][out] */ IAgentCtlAnimationNames __RPC_FAR *__RPC_FAR *Names) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SRStatus( 
            /* [retval][out] */ long __RPC_FAR *Status) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCharacterExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCharacterEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCharacterEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Balloon )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlBalloonEx __RPC_FAR *__RPC_FAR *ppidBalloon);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Commands )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCommandsEx __RPC_FAR *__RPC_FAR *ppidCommands);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Description )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Left )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            short Left);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Left )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Left);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Top )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            short Top);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Top )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Top);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Height )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            short Height);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Height )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Height);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Width )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            short Width);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Width);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Speed )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Speed);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Pitch )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Pitch);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IdleOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IdleOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Activate )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT State,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Success);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR Animation,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Get )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR Type,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Queue,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Wait )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *WaitForRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Interrupt )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *InterruptRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Speak )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT Text,
            /* [optional][in] */ VARIANT Url,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GestureAt )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [optional][in] */ VARIANT Speed,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hide )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Show )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopAll )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT Types);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MoveCause )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *MoveCause);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VisibilityCause )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *VisibilityCause);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HasOtherClients )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *HasOtherClients);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SoundEffectsOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SoundEffectsOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Description )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ExtraData )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ExtraData);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowPopupMenu )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Showed);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AutoPopupMenu )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AutoPopupMenu )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpModeOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpModeOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpContextID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ long ID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpContextID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Active )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *State);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Listen )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Listen,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *StartedListening);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LanguageID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ long LanguageID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LanguageID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *LanguageID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SRModeID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *EngineModeId);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SRModeID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR EngineModeId);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TTSModeID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *EngineModeId);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TTSModeID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR EngineModeId);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpFile )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *File);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpFile )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR File);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GUID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *GUID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OriginalHeight )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Height);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OriginalWidth )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Width);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Think )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR Text,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Version )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Version);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AnimationNames )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlAnimationNames __RPC_FAR *__RPC_FAR *Names);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SRStatus )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Status);
        
        END_INTERFACE
    } IAgentCtlCharacterExVtbl;

    interface IAgentCtlCharacterEx
    {
        CONST_VTBL struct IAgentCtlCharacterExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCharacterEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCharacterEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCharacterEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCharacterEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCharacterEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCharacterEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCharacterEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCharacterEx_get_Balloon(This,ppidBalloon)	\
    (This)->lpVtbl -> get_Balloon(This,ppidBalloon)

#define IAgentCtlCharacterEx_get_Commands(This,ppidCommands)	\
    (This)->lpVtbl -> get_Commands(This,ppidCommands)

#define IAgentCtlCharacterEx_get_Name(This,Name)	\
    (This)->lpVtbl -> get_Name(This,Name)

#define IAgentCtlCharacterEx_get_Description(This,Description)	\
    (This)->lpVtbl -> get_Description(This,Description)

#define IAgentCtlCharacterEx_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCharacterEx_put_Left(This,Left)	\
    (This)->lpVtbl -> put_Left(This,Left)

#define IAgentCtlCharacterEx_get_Left(This,Left)	\
    (This)->lpVtbl -> get_Left(This,Left)

#define IAgentCtlCharacterEx_put_Top(This,Top)	\
    (This)->lpVtbl -> put_Top(This,Top)

#define IAgentCtlCharacterEx_get_Top(This,Top)	\
    (This)->lpVtbl -> get_Top(This,Top)

#define IAgentCtlCharacterEx_put_Height(This,Height)	\
    (This)->lpVtbl -> put_Height(This,Height)

#define IAgentCtlCharacterEx_get_Height(This,Height)	\
    (This)->lpVtbl -> get_Height(This,Height)

#define IAgentCtlCharacterEx_put_Width(This,Width)	\
    (This)->lpVtbl -> put_Width(This,Width)

#define IAgentCtlCharacterEx_get_Width(This,Width)	\
    (This)->lpVtbl -> get_Width(This,Width)

#define IAgentCtlCharacterEx_get_Speed(This,Speed)	\
    (This)->lpVtbl -> get_Speed(This,Speed)

#define IAgentCtlCharacterEx_get_Pitch(This,Pitch)	\
    (This)->lpVtbl -> get_Pitch(This,Pitch)

#define IAgentCtlCharacterEx_put_IdleOn(This,On)	\
    (This)->lpVtbl -> put_IdleOn(This,On)

#define IAgentCtlCharacterEx_get_IdleOn(This,On)	\
    (This)->lpVtbl -> get_IdleOn(This,On)

#define IAgentCtlCharacterEx_Activate(This,State,Success)	\
    (This)->lpVtbl -> Activate(This,State,Success)

#define IAgentCtlCharacterEx_Play(This,Animation,Request)	\
    (This)->lpVtbl -> Play(This,Animation,Request)

#define IAgentCtlCharacterEx_Get(This,Type,Name,Queue,Request)	\
    (This)->lpVtbl -> Get(This,Type,Name,Queue,Request)

#define IAgentCtlCharacterEx_Stop(This,Request)	\
    (This)->lpVtbl -> Stop(This,Request)

#define IAgentCtlCharacterEx_Wait(This,WaitForRequest,Request)	\
    (This)->lpVtbl -> Wait(This,WaitForRequest,Request)

#define IAgentCtlCharacterEx_Interrupt(This,InterruptRequest,Request)	\
    (This)->lpVtbl -> Interrupt(This,InterruptRequest,Request)

#define IAgentCtlCharacterEx_Speak(This,Text,Url,Request)	\
    (This)->lpVtbl -> Speak(This,Text,Url,Request)

#define IAgentCtlCharacterEx_GestureAt(This,x,y,Request)	\
    (This)->lpVtbl -> GestureAt(This,x,y,Request)

#define IAgentCtlCharacterEx_MoveTo(This,x,y,Speed,Request)	\
    (This)->lpVtbl -> MoveTo(This,x,y,Speed,Request)

#define IAgentCtlCharacterEx_Hide(This,Fast,Request)	\
    (This)->lpVtbl -> Hide(This,Fast,Request)

#define IAgentCtlCharacterEx_Show(This,Fast,Request)	\
    (This)->lpVtbl -> Show(This,Fast,Request)

#define IAgentCtlCharacterEx_StopAll(This,Types)	\
    (This)->lpVtbl -> StopAll(This,Types)

#define IAgentCtlCharacterEx_get_MoveCause(This,MoveCause)	\
    (This)->lpVtbl -> get_MoveCause(This,MoveCause)

#define IAgentCtlCharacterEx_get_VisibilityCause(This,VisibilityCause)	\
    (This)->lpVtbl -> get_VisibilityCause(This,VisibilityCause)

#define IAgentCtlCharacterEx_get_HasOtherClients(This,HasOtherClients)	\
    (This)->lpVtbl -> get_HasOtherClients(This,HasOtherClients)

#define IAgentCtlCharacterEx_put_SoundEffectsOn(This,On)	\
    (This)->lpVtbl -> put_SoundEffectsOn(This,On)

#define IAgentCtlCharacterEx_get_SoundEffectsOn(This,On)	\
    (This)->lpVtbl -> get_SoundEffectsOn(This,On)

#define IAgentCtlCharacterEx_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IAgentCtlCharacterEx_put_Description(This,Description)	\
    (This)->lpVtbl -> put_Description(This,Description)

#define IAgentCtlCharacterEx_get_ExtraData(This,ExtraData)	\
    (This)->lpVtbl -> get_ExtraData(This,ExtraData)


#define IAgentCtlCharacterEx_ShowPopupMenu(This,x,y,Showed)	\
    (This)->lpVtbl -> ShowPopupMenu(This,x,y,Showed)

#define IAgentCtlCharacterEx_put_AutoPopupMenu(This,On)	\
    (This)->lpVtbl -> put_AutoPopupMenu(This,On)

#define IAgentCtlCharacterEx_get_AutoPopupMenu(This,On)	\
    (This)->lpVtbl -> get_AutoPopupMenu(This,On)

#define IAgentCtlCharacterEx_put_HelpModeOn(This,On)	\
    (This)->lpVtbl -> put_HelpModeOn(This,On)

#define IAgentCtlCharacterEx_get_HelpModeOn(This,On)	\
    (This)->lpVtbl -> get_HelpModeOn(This,On)

#define IAgentCtlCharacterEx_put_HelpContextID(This,ID)	\
    (This)->lpVtbl -> put_HelpContextID(This,ID)

#define IAgentCtlCharacterEx_get_HelpContextID(This,ID)	\
    (This)->lpVtbl -> get_HelpContextID(This,ID)

#define IAgentCtlCharacterEx_get_Active(This,State)	\
    (This)->lpVtbl -> get_Active(This,State)

#define IAgentCtlCharacterEx_Listen(This,Listen,StartedListening)	\
    (This)->lpVtbl -> Listen(This,Listen,StartedListening)

#define IAgentCtlCharacterEx_put_LanguageID(This,LanguageID)	\
    (This)->lpVtbl -> put_LanguageID(This,LanguageID)

#define IAgentCtlCharacterEx_get_LanguageID(This,LanguageID)	\
    (This)->lpVtbl -> get_LanguageID(This,LanguageID)

#define IAgentCtlCharacterEx_get_SRModeID(This,EngineModeId)	\
    (This)->lpVtbl -> get_SRModeID(This,EngineModeId)

#define IAgentCtlCharacterEx_put_SRModeID(This,EngineModeId)	\
    (This)->lpVtbl -> put_SRModeID(This,EngineModeId)

#define IAgentCtlCharacterEx_get_TTSModeID(This,EngineModeId)	\
    (This)->lpVtbl -> get_TTSModeID(This,EngineModeId)

#define IAgentCtlCharacterEx_put_TTSModeID(This,EngineModeId)	\
    (This)->lpVtbl -> put_TTSModeID(This,EngineModeId)

#define IAgentCtlCharacterEx_get_HelpFile(This,File)	\
    (This)->lpVtbl -> get_HelpFile(This,File)

#define IAgentCtlCharacterEx_put_HelpFile(This,File)	\
    (This)->lpVtbl -> put_HelpFile(This,File)

#define IAgentCtlCharacterEx_get_GUID(This,GUID)	\
    (This)->lpVtbl -> get_GUID(This,GUID)

#define IAgentCtlCharacterEx_get_OriginalHeight(This,Height)	\
    (This)->lpVtbl -> get_OriginalHeight(This,Height)

#define IAgentCtlCharacterEx_get_OriginalWidth(This,Width)	\
    (This)->lpVtbl -> get_OriginalWidth(This,Width)

#define IAgentCtlCharacterEx_Think(This,Text,Request)	\
    (This)->lpVtbl -> Think(This,Text,Request)

#define IAgentCtlCharacterEx_get_Version(This,Version)	\
    (This)->lpVtbl -> get_Version(This,Version)

#define IAgentCtlCharacterEx_get_AnimationNames(This,Names)	\
    (This)->lpVtbl -> get_AnimationNames(This,Names)

#define IAgentCtlCharacterEx_get_SRStatus(This,Status)	\
    (This)->lpVtbl -> get_SRStatus(This,Status)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_ShowPopupMenu_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Showed);


void __RPC_STUB IAgentCtlCharacterEx_ShowPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_AutoPopupMenu_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL On);


void __RPC_STUB IAgentCtlCharacterEx_put_AutoPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_AutoPopupMenu_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);


void __RPC_STUB IAgentCtlCharacterEx_get_AutoPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_HelpModeOn_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL On);


void __RPC_STUB IAgentCtlCharacterEx_put_HelpModeOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_HelpModeOn_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);


void __RPC_STUB IAgentCtlCharacterEx_get_HelpModeOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_HelpContextID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ long ID);


void __RPC_STUB IAgentCtlCharacterEx_put_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_HelpContextID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ID);


void __RPC_STUB IAgentCtlCharacterEx_get_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_Active_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *State);


void __RPC_STUB IAgentCtlCharacterEx_get_Active_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_Listen_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Listen,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *StartedListening);


void __RPC_STUB IAgentCtlCharacterEx_Listen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_LanguageID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ long LanguageID);


void __RPC_STUB IAgentCtlCharacterEx_put_LanguageID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_LanguageID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *LanguageID);


void __RPC_STUB IAgentCtlCharacterEx_get_LanguageID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_SRModeID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *EngineModeId);


void __RPC_STUB IAgentCtlCharacterEx_get_SRModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_SRModeID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR EngineModeId);


void __RPC_STUB IAgentCtlCharacterEx_put_SRModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_TTSModeID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *EngineModeId);


void __RPC_STUB IAgentCtlCharacterEx_get_TTSModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_TTSModeID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR EngineModeId);


void __RPC_STUB IAgentCtlCharacterEx_put_TTSModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_HelpFile_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *File);


void __RPC_STUB IAgentCtlCharacterEx_get_HelpFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_HelpFile_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR File);


void __RPC_STUB IAgentCtlCharacterEx_put_HelpFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_GUID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *GUID);


void __RPC_STUB IAgentCtlCharacterEx_get_GUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_OriginalHeight_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Height);


void __RPC_STUB IAgentCtlCharacterEx_get_OriginalHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_OriginalWidth_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Width);


void __RPC_STUB IAgentCtlCharacterEx_get_OriginalWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_Think_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR Text,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacterEx_Think_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_Version_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Version);


void __RPC_STUB IAgentCtlCharacterEx_get_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_AnimationNames_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlAnimationNames __RPC_FAR *__RPC_FAR *Names);


void __RPC_STUB IAgentCtlCharacterEx_get_AnimationNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_SRStatus_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Status);


void __RPC_STUB IAgentCtlCharacterEx_get_SRStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCharacterEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCharacters_INTERFACE_DEFINED__
#define __IAgentCtlCharacters_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlCharacters
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlCharacters;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("F5BE8BE8-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlCharacters : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ BSTR CharacterID,
            /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Character( 
            /* [in] */ BSTR CharacterID,
            /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem) = 0;
        
        virtual /* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Unload( 
            /* [in] */ BSTR CharacterID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR CharacterID,
            /* [optional][in] */ VARIANT LoadKey,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *ppidRequest) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCharactersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCharacters __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCharacters __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ BSTR CharacterID,
            /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Character )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ BSTR CharacterID,
            /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem);
        
        /* [restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enum )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unload )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ BSTR CharacterID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ BSTR CharacterID,
            /* [optional][in] */ VARIANT LoadKey,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *ppidRequest);
        
        END_INTERFACE
    } IAgentCtlCharactersVtbl;

    interface IAgentCtlCharacters
    {
        CONST_VTBL struct IAgentCtlCharactersVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCharacters_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCharacters_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCharacters_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCharacters_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCharacters_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCharacters_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCharacters_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCharacters_get_Item(This,CharacterID,ppidItem)	\
    (This)->lpVtbl -> get_Item(This,CharacterID,ppidItem)

#define IAgentCtlCharacters_Character(This,CharacterID,ppidItem)	\
    (This)->lpVtbl -> Character(This,CharacterID,ppidItem)

#define IAgentCtlCharacters_get_Enum(This,ppunkEnum)	\
    (This)->lpVtbl -> get_Enum(This,ppunkEnum)

#define IAgentCtlCharacters_Unload(This,CharacterID)	\
    (This)->lpVtbl -> Unload(This,CharacterID)

#define IAgentCtlCharacters_Load(This,CharacterID,LoadKey,ppidRequest)	\
    (This)->lpVtbl -> Load(This,CharacterID,LoadKey,ppidRequest)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacters_get_Item_Proxy( 
    IAgentCtlCharacters __RPC_FAR * This,
    /* [in] */ BSTR CharacterID,
    /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem);


void __RPC_STUB IAgentCtlCharacters_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacters_Character_Proxy( 
    IAgentCtlCharacters __RPC_FAR * This,
    /* [in] */ BSTR CharacterID,
    /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem);


void __RPC_STUB IAgentCtlCharacters_Character_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacters_get_Enum_Proxy( 
    IAgentCtlCharacters __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);


void __RPC_STUB IAgentCtlCharacters_get_Enum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacters_Unload_Proxy( 
    IAgentCtlCharacters __RPC_FAR * This,
    /* [in] */ BSTR CharacterID);


void __RPC_STUB IAgentCtlCharacters_Unload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacters_Load_Proxy( 
    IAgentCtlCharacters __RPC_FAR * This,
    /* [in] */ BSTR CharacterID,
    /* [optional][in] */ VARIANT LoadKey,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *ppidRequest);


void __RPC_STUB IAgentCtlCharacters_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCharacters_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlAudioObject_INTERFACE_DEFINED__
#define __IAgentCtlAudioObject_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlAudioObject
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlAudioObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("F5BE8BDB-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlAudioObject : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *AudioEnabled) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SoundEffects( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *SoundEffects) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlAudioObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlAudioObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlAudioObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *AudioEnabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SoundEffects )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *SoundEffects);
        
        END_INTERFACE
    } IAgentCtlAudioObjectVtbl;

    interface IAgentCtlAudioObject
    {
        CONST_VTBL struct IAgentCtlAudioObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlAudioObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlAudioObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlAudioObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlAudioObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlAudioObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlAudioObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlAudioObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlAudioObject_get_Enabled(This,AudioEnabled)	\
    (This)->lpVtbl -> get_Enabled(This,AudioEnabled)

#define IAgentCtlAudioObject_get_SoundEffects(This,SoundEffects)	\
    (This)->lpVtbl -> get_SoundEffects(This,SoundEffects)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlAudioObject_get_Enabled_Proxy( 
    IAgentCtlAudioObject __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *AudioEnabled);


void __RPC_STUB IAgentCtlAudioObject_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlAudioObject_get_SoundEffects_Proxy( 
    IAgentCtlAudioObject __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *SoundEffects);


void __RPC_STUB IAgentCtlAudioObject_get_SoundEffects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlAudioObject_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlAudioObjectEx_INTERFACE_DEFINED__
#define __IAgentCtlAudioObjectEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlAudioObjectEx
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlAudioObjectEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("F5BE8BF0-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlAudioObjectEx : public IAgentCtlAudioObject
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ short __RPC_FAR *Available) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlAudioObjectExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *AudioEnabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SoundEffects )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *SoundEffects);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Status )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Available);
        
        END_INTERFACE
    } IAgentCtlAudioObjectExVtbl;

    interface IAgentCtlAudioObjectEx
    {
        CONST_VTBL struct IAgentCtlAudioObjectExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlAudioObjectEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlAudioObjectEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlAudioObjectEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlAudioObjectEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlAudioObjectEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlAudioObjectEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlAudioObjectEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlAudioObjectEx_get_Enabled(This,AudioEnabled)	\
    (This)->lpVtbl -> get_Enabled(This,AudioEnabled)

#define IAgentCtlAudioObjectEx_get_SoundEffects(This,SoundEffects)	\
    (This)->lpVtbl -> get_SoundEffects(This,SoundEffects)


#define IAgentCtlAudioObjectEx_get_Status(This,Available)	\
    (This)->lpVtbl -> get_Status(This,Available)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlAudioObjectEx_get_Status_Proxy( 
    IAgentCtlAudioObjectEx __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Available);


void __RPC_STUB IAgentCtlAudioObjectEx_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlAudioObjectEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlSpeechInput_INTERFACE_DEFINED__
#define __IAgentCtlSpeechInput_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlSpeechInput
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlSpeechInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("F5BE8BDD-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlSpeechInput : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceEnabled) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Language( 
            /* [retval][out] */ BSTR __RPC_FAR *Language) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HotKey( 
            /* [retval][out] */ BSTR __RPC_FAR *HotKey) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Installed( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceInstalled) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Engine( 
            /* [retval][out] */ BSTR __RPC_FAR *Engine) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Engine( 
            /* [in] */ BSTR Engine) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ListeningTip( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ListeningTip) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlSpeechInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlSpeechInput __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlSpeechInput __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceEnabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Language )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Language);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HotKey )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *HotKey);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Installed )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceInstalled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Engine )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Engine);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Engine )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [in] */ BSTR Engine);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListeningTip )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ListeningTip);
        
        END_INTERFACE
    } IAgentCtlSpeechInputVtbl;

    interface IAgentCtlSpeechInput
    {
        CONST_VTBL struct IAgentCtlSpeechInputVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlSpeechInput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlSpeechInput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlSpeechInput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlSpeechInput_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlSpeechInput_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlSpeechInput_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlSpeechInput_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlSpeechInput_get_Enabled(This,VoiceEnabled)	\
    (This)->lpVtbl -> get_Enabled(This,VoiceEnabled)

#define IAgentCtlSpeechInput_get_Language(This,Language)	\
    (This)->lpVtbl -> get_Language(This,Language)

#define IAgentCtlSpeechInput_get_HotKey(This,HotKey)	\
    (This)->lpVtbl -> get_HotKey(This,HotKey)

#define IAgentCtlSpeechInput_get_Installed(This,VoiceInstalled)	\
    (This)->lpVtbl -> get_Installed(This,VoiceInstalled)

#define IAgentCtlSpeechInput_get_Engine(This,Engine)	\
    (This)->lpVtbl -> get_Engine(This,Engine)

#define IAgentCtlSpeechInput_put_Engine(This,Engine)	\
    (This)->lpVtbl -> put_Engine(This,Engine)

#define IAgentCtlSpeechInput_get_ListeningTip(This,ListeningTip)	\
    (This)->lpVtbl -> get_ListeningTip(This,ListeningTip)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_Enabled_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceEnabled);


void __RPC_STUB IAgentCtlSpeechInput_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_Language_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Language);


void __RPC_STUB IAgentCtlSpeechInput_get_Language_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_HotKey_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *HotKey);


void __RPC_STUB IAgentCtlSpeechInput_get_HotKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_Installed_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceInstalled);


void __RPC_STUB IAgentCtlSpeechInput_get_Installed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_Engine_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Engine);


void __RPC_STUB IAgentCtlSpeechInput_get_Engine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_put_Engine_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [in] */ BSTR Engine);


void __RPC_STUB IAgentCtlSpeechInput_put_Engine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_ListeningTip_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ListeningTip);


void __RPC_STUB IAgentCtlSpeechInput_get_ListeningTip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlSpeechInput_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlPropertySheet_INTERFACE_DEFINED__
#define __IAgentCtlPropertySheet_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlPropertySheet
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlPropertySheet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("F5BE8BDF-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlPropertySheet : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ short __RPC_FAR *Left) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ short __RPC_FAR *Top) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ short __RPC_FAR *Height) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ short __RPC_FAR *Width) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Page( 
            /* [in] */ BSTR Page) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Page( 
            /* [retval][out] */ BSTR __RPC_FAR *Page) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlPropertySheetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlPropertySheet __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlPropertySheet __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Left )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Left);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Top )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Top);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Height )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Height);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Width);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Page )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ BSTR Page);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Page )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Page);
        
        END_INTERFACE
    } IAgentCtlPropertySheetVtbl;

    interface IAgentCtlPropertySheet
    {
        CONST_VTBL struct IAgentCtlPropertySheetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlPropertySheet_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlPropertySheet_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlPropertySheet_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlPropertySheet_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlPropertySheet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlPropertySheet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlPropertySheet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlPropertySheet_get_Left(This,Left)	\
    (This)->lpVtbl -> get_Left(This,Left)

#define IAgentCtlPropertySheet_get_Top(This,Top)	\
    (This)->lpVtbl -> get_Top(This,Top)

#define IAgentCtlPropertySheet_get_Height(This,Height)	\
    (This)->lpVtbl -> get_Height(This,Height)

#define IAgentCtlPropertySheet_get_Width(This,Width)	\
    (This)->lpVtbl -> get_Width(This,Width)

#define IAgentCtlPropertySheet_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlPropertySheet_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlPropertySheet_put_Page(This,Page)	\
    (This)->lpVtbl -> put_Page(This,Page)

#define IAgentCtlPropertySheet_get_Page(This,Page)	\
    (This)->lpVtbl -> get_Page(This,Page)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Left_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Left);


void __RPC_STUB IAgentCtlPropertySheet_get_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Top_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Top);


void __RPC_STUB IAgentCtlPropertySheet_get_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Height_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Height);


void __RPC_STUB IAgentCtlPropertySheet_get_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Width_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Width);


void __RPC_STUB IAgentCtlPropertySheet_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_put_Visible_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Visible);


void __RPC_STUB IAgentCtlPropertySheet_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Visible_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlPropertySheet_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_put_Page_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [in] */ BSTR Page);


void __RPC_STUB IAgentCtlPropertySheet_put_Page_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Page_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Page);


void __RPC_STUB IAgentCtlPropertySheet_get_Page_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlPropertySheet_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCommandsWindow_INTERFACE_DEFINED__
#define __IAgentCtlCommandsWindow_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlCommandsWindow
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlCommandsWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("6D0ECB27-9968-11D0-AC6E-00C04FD97575")
    IAgentCtlCommandsWindow : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ short __RPC_FAR *Left) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ short __RPC_FAR *Top) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ short __RPC_FAR *Height) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ short __RPC_FAR *Width) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCommandsWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCommandsWindow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCommandsWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Left )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Left);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Top )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Top);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Height )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Height);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Width);
        
        END_INTERFACE
    } IAgentCtlCommandsWindowVtbl;

    interface IAgentCtlCommandsWindow
    {
        CONST_VTBL struct IAgentCtlCommandsWindowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCommandsWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCommandsWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCommandsWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCommandsWindow_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCommandsWindow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCommandsWindow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCommandsWindow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCommandsWindow_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCommandsWindow_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlCommandsWindow_get_Left(This,Left)	\
    (This)->lpVtbl -> get_Left(This,Left)

#define IAgentCtlCommandsWindow_get_Top(This,Top)	\
    (This)->lpVtbl -> get_Top(This,Top)

#define IAgentCtlCommandsWindow_get_Height(This,Height)	\
    (This)->lpVtbl -> get_Height(This,Height)

#define IAgentCtlCommandsWindow_get_Width(This,Width)	\
    (This)->lpVtbl -> get_Width(This,Width)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_get_Visible_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlCommandsWindow_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_put_Visible_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Visible);


void __RPC_STUB IAgentCtlCommandsWindow_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_get_Left_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Left);


void __RPC_STUB IAgentCtlCommandsWindow_get_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_get_Top_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Top);


void __RPC_STUB IAgentCtlCommandsWindow_get_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_get_Height_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Height);


void __RPC_STUB IAgentCtlCommandsWindow_get_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_get_Width_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Width);


void __RPC_STUB IAgentCtlCommandsWindow_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCommandsWindow_INTERFACE_DEFINED__ */


#ifndef __IAgentCtl_INTERFACE_DEFINED__
#define __IAgentCtl_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtl
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("F5BE8BD1-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtl : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Characters( 
            /* [retval][out] */ IAgentCtlCharacters __RPC_FAR *__RPC_FAR *Characters) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_AudioOutput( 
            /* [retval][out] */ IAgentCtlAudioObjectEx __RPC_FAR *__RPC_FAR *AudioOutput) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SpeechInput( 
            /* [retval][out] */ IAgentCtlSpeechInput __RPC_FAR *__RPC_FAR *SpeechInput) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PropertySheet( 
            /* [retval][out] */ IAgentCtlPropertySheet __RPC_FAR *__RPC_FAR *PropSheet) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CommandsWindow( 
            /* [retval][out] */ IAgentCtlCommandsWindow __RPC_FAR *__RPC_FAR *CommandsWindow) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Connected( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Connected) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Connected( 
            /* [in] */ VARIANT_BOOL Connected) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Suspended( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Suspended) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Characters )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCharacters __RPC_FAR *__RPC_FAR *Characters);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AudioOutput )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlAudioObjectEx __RPC_FAR *__RPC_FAR *AudioOutput);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SpeechInput )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlSpeechInput __RPC_FAR *__RPC_FAR *SpeechInput);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PropertySheet )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlPropertySheet __RPC_FAR *__RPC_FAR *PropSheet);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CommandsWindow )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCommandsWindow __RPC_FAR *__RPC_FAR *CommandsWindow);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Connected )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Connected);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Connected )( 
            IAgentCtl __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Connected);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Suspended )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Suspended);
        
        END_INTERFACE
    } IAgentCtlVtbl;

    interface IAgentCtl
    {
        CONST_VTBL struct IAgentCtlVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtl_get_Characters(This,Characters)	\
    (This)->lpVtbl -> get_Characters(This,Characters)

#define IAgentCtl_get_AudioOutput(This,AudioOutput)	\
    (This)->lpVtbl -> get_AudioOutput(This,AudioOutput)

#define IAgentCtl_get_SpeechInput(This,SpeechInput)	\
    (This)->lpVtbl -> get_SpeechInput(This,SpeechInput)

#define IAgentCtl_get_PropertySheet(This,PropSheet)	\
    (This)->lpVtbl -> get_PropertySheet(This,PropSheet)

#define IAgentCtl_get_CommandsWindow(This,CommandsWindow)	\
    (This)->lpVtbl -> get_CommandsWindow(This,CommandsWindow)

#define IAgentCtl_get_Connected(This,Connected)	\
    (This)->lpVtbl -> get_Connected(This,Connected)

#define IAgentCtl_put_Connected(This,Connected)	\
    (This)->lpVtbl -> put_Connected(This,Connected)

#define IAgentCtl_get_Suspended(This,Suspended)	\
    (This)->lpVtbl -> get_Suspended(This,Suspended)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_Characters_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlCharacters __RPC_FAR *__RPC_FAR *Characters);


void __RPC_STUB IAgentCtl_get_Characters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_AudioOutput_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlAudioObjectEx __RPC_FAR *__RPC_FAR *AudioOutput);


void __RPC_STUB IAgentCtl_get_AudioOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_SpeechInput_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlSpeechInput __RPC_FAR *__RPC_FAR *SpeechInput);


void __RPC_STUB IAgentCtl_get_SpeechInput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_PropertySheet_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlPropertySheet __RPC_FAR *__RPC_FAR *PropSheet);


void __RPC_STUB IAgentCtl_get_PropertySheet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_CommandsWindow_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlCommandsWindow __RPC_FAR *__RPC_FAR *CommandsWindow);


void __RPC_STUB IAgentCtl_get_CommandsWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_Connected_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Connected);


void __RPC_STUB IAgentCtl_get_Connected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_put_Connected_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Connected);


void __RPC_STUB IAgentCtl_put_Connected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_Suspended_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Suspended);


void __RPC_STUB IAgentCtl_get_Suspended_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtl_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlEx_INTERFACE_DEFINED__
#define __IAgentCtlEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCtlEx
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCtlEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8563FF20-8ECC-11d1-B9B4-00C04FD97575")
    IAgentCtlEx : public IAgentCtl
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowDefaultCharacterProperties( 
            /* [optional][in] */ VARIANT x,
            /* [optional][in] */ VARIANT y) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_RaiseRequestErrors( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *RaiseErrors) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_RaiseRequestErrors( 
            /* [in] */ VARIANT_BOOL RaiseErrors) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Characters )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCharacters __RPC_FAR *__RPC_FAR *Characters);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AudioOutput )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlAudioObjectEx __RPC_FAR *__RPC_FAR *AudioOutput);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SpeechInput )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlSpeechInput __RPC_FAR *__RPC_FAR *SpeechInput);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PropertySheet )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlPropertySheet __RPC_FAR *__RPC_FAR *PropSheet);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CommandsWindow )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCommandsWindow __RPC_FAR *__RPC_FAR *CommandsWindow);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Connected )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Connected);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Connected )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Connected);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Suspended )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Suspended);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowDefaultCharacterProperties )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT x,
            /* [optional][in] */ VARIANT y);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RaiseRequestErrors )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *RaiseErrors);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RaiseRequestErrors )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL RaiseErrors);
        
        END_INTERFACE
    } IAgentCtlExVtbl;

    interface IAgentCtlEx
    {
        CONST_VTBL struct IAgentCtlExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlEx_get_Characters(This,Characters)	\
    (This)->lpVtbl -> get_Characters(This,Characters)

#define IAgentCtlEx_get_AudioOutput(This,AudioOutput)	\
    (This)->lpVtbl -> get_AudioOutput(This,AudioOutput)

#define IAgentCtlEx_get_SpeechInput(This,SpeechInput)	\
    (This)->lpVtbl -> get_SpeechInput(This,SpeechInput)

#define IAgentCtlEx_get_PropertySheet(This,PropSheet)	\
    (This)->lpVtbl -> get_PropertySheet(This,PropSheet)

#define IAgentCtlEx_get_CommandsWindow(This,CommandsWindow)	\
    (This)->lpVtbl -> get_CommandsWindow(This,CommandsWindow)

#define IAgentCtlEx_get_Connected(This,Connected)	\
    (This)->lpVtbl -> get_Connected(This,Connected)

#define IAgentCtlEx_put_Connected(This,Connected)	\
    (This)->lpVtbl -> put_Connected(This,Connected)

#define IAgentCtlEx_get_Suspended(This,Suspended)	\
    (This)->lpVtbl -> get_Suspended(This,Suspended)


#define IAgentCtlEx_ShowDefaultCharacterProperties(This,x,y)	\
    (This)->lpVtbl -> ShowDefaultCharacterProperties(This,x,y)

#define IAgentCtlEx_get_RaiseRequestErrors(This,RaiseErrors)	\
    (This)->lpVtbl -> get_RaiseRequestErrors(This,RaiseErrors)

#define IAgentCtlEx_put_RaiseRequestErrors(This,RaiseErrors)	\
    (This)->lpVtbl -> put_RaiseRequestErrors(This,RaiseErrors)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlEx_ShowDefaultCharacterProperties_Proxy( 
    IAgentCtlEx __RPC_FAR * This,
    /* [optional][in] */ VARIANT x,
    /* [optional][in] */ VARIANT y);


void __RPC_STUB IAgentCtlEx_ShowDefaultCharacterProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlEx_get_RaiseRequestErrors_Proxy( 
    IAgentCtlEx __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *RaiseErrors);


void __RPC_STUB IAgentCtlEx_get_RaiseRequestErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlEx_put_RaiseRequestErrors_Proxy( 
    IAgentCtlEx __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL RaiseErrors);


void __RPC_STUB IAgentCtlEx_put_RaiseRequestErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlEx_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_AgentControl_0154
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define	CONTROL_MAJOR_VERSION	( 2 )

#define	CONTROL_MINOR_VERSION	( 0 )



extern RPC_IF_HANDLE __MIDL_itf_AgentControl_0154_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AgentControl_0154_v0_0_s_ifspec;


#ifndef __AgentObjects_LIBRARY_DEFINED__
#define __AgentObjects_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: AgentObjects
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 






















EXTERN_C const IID LIBID_AgentObjects;

#ifndef ___AgentEvents_DISPINTERFACE_DEFINED__
#define ___AgentEvents_DISPINTERFACE_DEFINED__

/****************************************
 * Generated header for dispinterface: _AgentEvents
 * at Tue Sep 01 10:41:00 1998
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][uuid] */ 



EXTERN_C const IID DIID__AgentEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    interface DECLSPEC_UUID("F5BE8BD4-7DE6-11D0-91FE-00C04FD701A5")
    _AgentEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _AgentEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _AgentEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _AgentEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _AgentEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _AgentEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _AgentEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _AgentEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _AgentEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _AgentEventsVtbl;

    interface _AgentEvents
    {
        CONST_VTBL struct _AgentEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _AgentEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _AgentEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _AgentEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _AgentEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _AgentEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _AgentEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _AgentEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___AgentEvents_DISPINTERFACE_DEFINED__ */


#ifdef __cplusplus
EXTERN_C const CLSID CLSID_Agent;

class DECLSPEC_UUID("D45FD31B-5C6E-11D1-9EC1-00C04FD7081F")
Agent;
#endif
#endif /* __AgentObjects_LIBRARY_DEFINED__ */

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

#else // _MSC_VER >= 1200

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Sep 15 16:56:03 1998
 */
/* Compiler settings for AgentControl.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
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

#ifndef __AgentControl_h__
#define __AgentControl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAgentCtlRequest_FWD_DEFINED__
#define __IAgentCtlRequest_FWD_DEFINED__
typedef interface IAgentCtlRequest IAgentCtlRequest;
#endif 	/* __IAgentCtlRequest_FWD_DEFINED__ */


#ifndef __IAgentCtlUserInput_FWD_DEFINED__
#define __IAgentCtlUserInput_FWD_DEFINED__
typedef interface IAgentCtlUserInput IAgentCtlUserInput;
#endif 	/* __IAgentCtlUserInput_FWD_DEFINED__ */


#ifndef __IAgentCtlBalloon_FWD_DEFINED__
#define __IAgentCtlBalloon_FWD_DEFINED__
typedef interface IAgentCtlBalloon IAgentCtlBalloon;
#endif 	/* __IAgentCtlBalloon_FWD_DEFINED__ */


#ifndef __IAgentCtlBalloonEx_FWD_DEFINED__
#define __IAgentCtlBalloonEx_FWD_DEFINED__
typedef interface IAgentCtlBalloonEx IAgentCtlBalloonEx;
#endif 	/* __IAgentCtlBalloonEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCommand_FWD_DEFINED__
#define __IAgentCtlCommand_FWD_DEFINED__
typedef interface IAgentCtlCommand IAgentCtlCommand;
#endif 	/* __IAgentCtlCommand_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandEx_FWD_DEFINED__
#define __IAgentCtlCommandEx_FWD_DEFINED__
typedef interface IAgentCtlCommandEx IAgentCtlCommandEx;
#endif 	/* __IAgentCtlCommandEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCommands_FWD_DEFINED__
#define __IAgentCtlCommands_FWD_DEFINED__
typedef interface IAgentCtlCommands IAgentCtlCommands;
#endif 	/* __IAgentCtlCommands_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandsEx_FWD_DEFINED__
#define __IAgentCtlCommandsEx_FWD_DEFINED__
typedef interface IAgentCtlCommandsEx IAgentCtlCommandsEx;
#endif 	/* __IAgentCtlCommandsEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacter_FWD_DEFINED__
#define __IAgentCtlCharacter_FWD_DEFINED__
typedef interface IAgentCtlCharacter IAgentCtlCharacter;
#endif 	/* __IAgentCtlCharacter_FWD_DEFINED__ */


#ifndef __IAgentCtlAnimationNames_FWD_DEFINED__
#define __IAgentCtlAnimationNames_FWD_DEFINED__
typedef interface IAgentCtlAnimationNames IAgentCtlAnimationNames;
#endif 	/* __IAgentCtlAnimationNames_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacterEx_FWD_DEFINED__
#define __IAgentCtlCharacterEx_FWD_DEFINED__
typedef interface IAgentCtlCharacterEx IAgentCtlCharacterEx;
#endif 	/* __IAgentCtlCharacterEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacters_FWD_DEFINED__
#define __IAgentCtlCharacters_FWD_DEFINED__
typedef interface IAgentCtlCharacters IAgentCtlCharacters;
#endif 	/* __IAgentCtlCharacters_FWD_DEFINED__ */


#ifndef __IAgentCtlAudioObject_FWD_DEFINED__
#define __IAgentCtlAudioObject_FWD_DEFINED__
typedef interface IAgentCtlAudioObject IAgentCtlAudioObject;
#endif 	/* __IAgentCtlAudioObject_FWD_DEFINED__ */


#ifndef __IAgentCtlAudioObjectEx_FWD_DEFINED__
#define __IAgentCtlAudioObjectEx_FWD_DEFINED__
typedef interface IAgentCtlAudioObjectEx IAgentCtlAudioObjectEx;
#endif 	/* __IAgentCtlAudioObjectEx_FWD_DEFINED__ */


#ifndef __IAgentCtlSpeechInput_FWD_DEFINED__
#define __IAgentCtlSpeechInput_FWD_DEFINED__
typedef interface IAgentCtlSpeechInput IAgentCtlSpeechInput;
#endif 	/* __IAgentCtlSpeechInput_FWD_DEFINED__ */


#ifndef __IAgentCtlPropertySheet_FWD_DEFINED__
#define __IAgentCtlPropertySheet_FWD_DEFINED__
typedef interface IAgentCtlPropertySheet IAgentCtlPropertySheet;
#endif 	/* __IAgentCtlPropertySheet_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandsWindow_FWD_DEFINED__
#define __IAgentCtlCommandsWindow_FWD_DEFINED__
typedef interface IAgentCtlCommandsWindow IAgentCtlCommandsWindow;
#endif 	/* __IAgentCtlCommandsWindow_FWD_DEFINED__ */


#ifndef __IAgentCtl_FWD_DEFINED__
#define __IAgentCtl_FWD_DEFINED__
typedef interface IAgentCtl IAgentCtl;
#endif 	/* __IAgentCtl_FWD_DEFINED__ */


#ifndef __IAgentCtlEx_FWD_DEFINED__
#define __IAgentCtlEx_FWD_DEFINED__
typedef interface IAgentCtlEx IAgentCtlEx;
#endif 	/* __IAgentCtlEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacters_FWD_DEFINED__
#define __IAgentCtlCharacters_FWD_DEFINED__
typedef interface IAgentCtlCharacters IAgentCtlCharacters;
#endif 	/* __IAgentCtlCharacters_FWD_DEFINED__ */


#ifndef __IAgentCtlBalloon_FWD_DEFINED__
#define __IAgentCtlBalloon_FWD_DEFINED__
typedef interface IAgentCtlBalloon IAgentCtlBalloon;
#endif 	/* __IAgentCtlBalloon_FWD_DEFINED__ */


#ifndef __IAgentCtlBalloonEx_FWD_DEFINED__
#define __IAgentCtlBalloonEx_FWD_DEFINED__
typedef interface IAgentCtlBalloonEx IAgentCtlBalloonEx;
#endif 	/* __IAgentCtlBalloonEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacter_FWD_DEFINED__
#define __IAgentCtlCharacter_FWD_DEFINED__
typedef interface IAgentCtlCharacter IAgentCtlCharacter;
#endif 	/* __IAgentCtlCharacter_FWD_DEFINED__ */


#ifndef __IAgentCtlCharacterEx_FWD_DEFINED__
#define __IAgentCtlCharacterEx_FWD_DEFINED__
typedef interface IAgentCtlCharacterEx IAgentCtlCharacterEx;
#endif 	/* __IAgentCtlCharacterEx_FWD_DEFINED__ */


#ifndef __IAgentCtlAudioObject_FWD_DEFINED__
#define __IAgentCtlAudioObject_FWD_DEFINED__
typedef interface IAgentCtlAudioObject IAgentCtlAudioObject;
#endif 	/* __IAgentCtlAudioObject_FWD_DEFINED__ */


#ifndef __IAgentCtlAudioObjectEx_FWD_DEFINED__
#define __IAgentCtlAudioObjectEx_FWD_DEFINED__
typedef interface IAgentCtlAudioObjectEx IAgentCtlAudioObjectEx;
#endif 	/* __IAgentCtlAudioObjectEx_FWD_DEFINED__ */


#ifndef __IAgentCtlSpeechInput_FWD_DEFINED__
#define __IAgentCtlSpeechInput_FWD_DEFINED__
typedef interface IAgentCtlSpeechInput IAgentCtlSpeechInput;
#endif 	/* __IAgentCtlSpeechInput_FWD_DEFINED__ */


#ifndef __IAgentCtlPropertySheet_FWD_DEFINED__
#define __IAgentCtlPropertySheet_FWD_DEFINED__
typedef interface IAgentCtlPropertySheet IAgentCtlPropertySheet;
#endif 	/* __IAgentCtlPropertySheet_FWD_DEFINED__ */


#ifndef __IAgentCtlCommands_FWD_DEFINED__
#define __IAgentCtlCommands_FWD_DEFINED__
typedef interface IAgentCtlCommands IAgentCtlCommands;
#endif 	/* __IAgentCtlCommands_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandsEx_FWD_DEFINED__
#define __IAgentCtlCommandsEx_FWD_DEFINED__
typedef interface IAgentCtlCommandsEx IAgentCtlCommandsEx;
#endif 	/* __IAgentCtlCommandsEx_FWD_DEFINED__ */


#ifndef __IAgentCtlCommand_FWD_DEFINED__
#define __IAgentCtlCommand_FWD_DEFINED__
typedef interface IAgentCtlCommand IAgentCtlCommand;
#endif 	/* __IAgentCtlCommand_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandEx_FWD_DEFINED__
#define __IAgentCtlCommandEx_FWD_DEFINED__
typedef interface IAgentCtlCommandEx IAgentCtlCommandEx;
#endif 	/* __IAgentCtlCommandEx_FWD_DEFINED__ */


#ifndef __IAgentCtlRequest_FWD_DEFINED__
#define __IAgentCtlRequest_FWD_DEFINED__
typedef interface IAgentCtlRequest IAgentCtlRequest;
#endif 	/* __IAgentCtlRequest_FWD_DEFINED__ */


#ifndef __IAgentCtlUserInput_FWD_DEFINED__
#define __IAgentCtlUserInput_FWD_DEFINED__
typedef interface IAgentCtlUserInput IAgentCtlUserInput;
#endif 	/* __IAgentCtlUserInput_FWD_DEFINED__ */


#ifndef __IAgentCtlCommandsWindow_FWD_DEFINED__
#define __IAgentCtlCommandsWindow_FWD_DEFINED__
typedef interface IAgentCtlCommandsWindow IAgentCtlCommandsWindow;
#endif 	/* __IAgentCtlCommandsWindow_FWD_DEFINED__ */


#ifndef __IAgentCtl_FWD_DEFINED__
#define __IAgentCtl_FWD_DEFINED__
typedef interface IAgentCtl IAgentCtl;
#endif 	/* __IAgentCtl_FWD_DEFINED__ */


#ifndef __IAgentCtlEx_FWD_DEFINED__
#define __IAgentCtlEx_FWD_DEFINED__
typedef interface IAgentCtlEx IAgentCtlEx;
#endif 	/* __IAgentCtlEx_FWD_DEFINED__ */


#ifndef ___AgentEvents_FWD_DEFINED__
#define ___AgentEvents_FWD_DEFINED__
typedef interface _AgentEvents _AgentEvents;
#endif 	/* ___AgentEvents_FWD_DEFINED__ */


#ifndef __Agent_FWD_DEFINED__
#define __Agent_FWD_DEFINED__

#ifdef __cplusplus
typedef class Agent Agent;
#else
typedef struct Agent Agent;
#endif /* __cplusplus */

#endif 	/* __Agent_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_AgentControl_0000 */
/* [local] */ 

#define	RequestSuccess	( 0 )

#define	RequestFailed	( 1 )

#define	RequestPending	( 2 )

#define	RequestInterrupted	( 3 )

#define	RequestInProgress	( 4 )



extern RPC_IF_HANDLE __MIDL_itf_AgentControl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AgentControl_0000_v0_0_s_ifspec;

#ifndef __IAgentCtlRequest_INTERFACE_DEFINED__
#define __IAgentCtlRequest_INTERFACE_DEFINED__

/* interface IAgentCtlRequest */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlRequest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1DAB85C3-803A-11D0-AC63-00C04FD97575")
    IAgentCtlRequest : public IDispatch
    {
    public:
        virtual /* [hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long __RPC_FAR *ID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ long __RPC_FAR *Status) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR __RPC_FAR *Description) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Number( 
            /* [retval][out] */ long __RPC_FAR *Number) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlRequestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlRequest __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlRequest __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ID )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Status )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Status);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Description )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Number )( 
            IAgentCtlRequest __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Number);
        
        END_INTERFACE
    } IAgentCtlRequestVtbl;

    interface IAgentCtlRequest
    {
        CONST_VTBL struct IAgentCtlRequestVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlRequest_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlRequest_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlRequest_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlRequest_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlRequest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlRequest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlRequest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlRequest_get_ID(This,ID)	\
    (This)->lpVtbl -> get_ID(This,ID)

#define IAgentCtlRequest_get_Status(This,Status)	\
    (This)->lpVtbl -> get_Status(This,Status)

#define IAgentCtlRequest_get_Description(This,Description)	\
    (This)->lpVtbl -> get_Description(This,Description)

#define IAgentCtlRequest_get_Number(This,Number)	\
    (This)->lpVtbl -> get_Number(This,Number)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [hidden][propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlRequest_get_ID_Proxy( 
    IAgentCtlRequest __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ID);


void __RPC_STUB IAgentCtlRequest_get_ID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlRequest_get_Status_Proxy( 
    IAgentCtlRequest __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Status);


void __RPC_STUB IAgentCtlRequest_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlRequest_get_Description_Proxy( 
    IAgentCtlRequest __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Description);


void __RPC_STUB IAgentCtlRequest_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlRequest_get_Number_Proxy( 
    IAgentCtlRequest __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Number);


void __RPC_STUB IAgentCtlRequest_get_Number_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlRequest_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlUserInput_INTERFACE_DEFINED__
#define __IAgentCtlUserInput_INTERFACE_DEFINED__

/* interface IAgentCtlUserInput */
/* [object][dual][uuid] */ 


EXTERN_C const IID IID_IAgentCtlUserInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4ABF875-8100-11D0-AC63-00C04FD97575")
    IAgentCtlUserInput : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ short __RPC_FAR *pCount) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CharacterID( 
            /* [retval][out] */ BSTR __RPC_FAR *pCharacterID) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Confidence( 
            /* [retval][out] */ long __RPC_FAR *pConfidence) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Voice( 
            /* [retval][out] */ BSTR __RPC_FAR *pVoice) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt1Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pAlt1Name) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt1Confidence( 
            /* [retval][out] */ long __RPC_FAR *pAlt1Confidence) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt1Voice( 
            /* [retval][out] */ BSTR __RPC_FAR *pAlt1Voice) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt2Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pAlt2Name) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt2Confidence( 
            /* [retval][out] */ long __RPC_FAR *pAlt2Confidence) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Alt2Voice( 
            /* [retval][out] */ BSTR __RPC_FAR *pAlt2Voice) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlUserInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlUserInput __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlUserInput __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pCount);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CharacterID )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pCharacterID);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Confidence )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pConfidence);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Voice )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVoice);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt1Name )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pAlt1Name);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt1Confidence )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pAlt1Confidence);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt1Voice )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pAlt1Voice);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt2Name )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pAlt2Name);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt2Confidence )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pAlt2Confidence);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Alt2Voice )( 
            IAgentCtlUserInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pAlt2Voice);
        
        END_INTERFACE
    } IAgentCtlUserInputVtbl;

    interface IAgentCtlUserInput
    {
        CONST_VTBL struct IAgentCtlUserInputVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlUserInput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlUserInput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlUserInput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlUserInput_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlUserInput_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlUserInput_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlUserInput_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlUserInput_get_Count(This,pCount)	\
    (This)->lpVtbl -> get_Count(This,pCount)

#define IAgentCtlUserInput_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IAgentCtlUserInput_get_CharacterID(This,pCharacterID)	\
    (This)->lpVtbl -> get_CharacterID(This,pCharacterID)

#define IAgentCtlUserInput_get_Confidence(This,pConfidence)	\
    (This)->lpVtbl -> get_Confidence(This,pConfidence)

#define IAgentCtlUserInput_get_Voice(This,pVoice)	\
    (This)->lpVtbl -> get_Voice(This,pVoice)

#define IAgentCtlUserInput_get_Alt1Name(This,pAlt1Name)	\
    (This)->lpVtbl -> get_Alt1Name(This,pAlt1Name)

#define IAgentCtlUserInput_get_Alt1Confidence(This,pAlt1Confidence)	\
    (This)->lpVtbl -> get_Alt1Confidence(This,pAlt1Confidence)

#define IAgentCtlUserInput_get_Alt1Voice(This,pAlt1Voice)	\
    (This)->lpVtbl -> get_Alt1Voice(This,pAlt1Voice)

#define IAgentCtlUserInput_get_Alt2Name(This,pAlt2Name)	\
    (This)->lpVtbl -> get_Alt2Name(This,pAlt2Name)

#define IAgentCtlUserInput_get_Alt2Confidence(This,pAlt2Confidence)	\
    (This)->lpVtbl -> get_Alt2Confidence(This,pAlt2Confidence)

#define IAgentCtlUserInput_get_Alt2Voice(This,pAlt2Voice)	\
    (This)->lpVtbl -> get_Alt2Voice(This,pAlt2Voice)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Count_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pCount);


void __RPC_STUB IAgentCtlUserInput_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Name_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pName);


void __RPC_STUB IAgentCtlUserInput_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_CharacterID_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pCharacterID);


void __RPC_STUB IAgentCtlUserInput_get_CharacterID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Confidence_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pConfidence);


void __RPC_STUB IAgentCtlUserInput_get_Confidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Voice_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVoice);


void __RPC_STUB IAgentCtlUserInput_get_Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt1Name_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pAlt1Name);


void __RPC_STUB IAgentCtlUserInput_get_Alt1Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt1Confidence_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pAlt1Confidence);


void __RPC_STUB IAgentCtlUserInput_get_Alt1Confidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt1Voice_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pAlt1Voice);


void __RPC_STUB IAgentCtlUserInput_get_Alt1Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt2Name_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pAlt2Name);


void __RPC_STUB IAgentCtlUserInput_get_Alt2Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt2Confidence_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pAlt2Confidence);


void __RPC_STUB IAgentCtlUserInput_get_Alt2Confidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAgentCtlUserInput_get_Alt2Voice_Proxy( 
    IAgentCtlUserInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pAlt2Voice);


void __RPC_STUB IAgentCtlUserInput_get_Alt2Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlUserInput_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlBalloon_INTERFACE_DEFINED__
#define __IAgentCtlBalloon_INTERFACE_DEFINED__

/* interface IAgentCtlBalloon */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlBalloon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5BE8BD3-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlBalloon : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_NumberOfLines( 
            /* [retval][out] */ long __RPC_FAR *Lines) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CharsPerLine( 
            /* [retval][out] */ long __RPC_FAR *CharsPerLine) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontName( 
            /* [retval][out] */ BSTR __RPC_FAR *FontName) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontSize( 
            /* [retval][out] */ long __RPC_FAR *FontSize) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontBold( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontBold) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontItalic( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontItalic) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontStrikethru( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontStrikethru) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontUnderline( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontUnderline) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ForeColor( 
            /* [retval][out] */ long __RPC_FAR *ForeColor) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ long __RPC_FAR *BackColor) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_BorderColor( 
            /* [retval][out] */ long __RPC_FAR *BorderColor) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_FontName( 
            /* [in] */ BSTR FontName) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_FontSize( 
            /* [in] */ long FontSize) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_FontCharSet( 
            /* [in] */ short FontCharSet) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontCharSet( 
            /* [retval][out] */ short __RPC_FAR *FontCharSet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlBalloonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlBalloon __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlBalloon __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NumberOfLines )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Lines);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CharsPerLine )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *CharsPerLine);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontName )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *FontName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontSize )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *FontSize);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontBold )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontBold);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontItalic )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontItalic);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontStrikethru )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontStrikethru);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontUnderline )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontUnderline);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForeColor )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ForeColor);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColor )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *BackColor);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BorderColor )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *BorderColor);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontName )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ BSTR FontName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontSize )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ long FontSize);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontCharSet )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [in] */ short FontCharSet);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontCharSet )( 
            IAgentCtlBalloon __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *FontCharSet);
        
        END_INTERFACE
    } IAgentCtlBalloonVtbl;

    interface IAgentCtlBalloon
    {
        CONST_VTBL struct IAgentCtlBalloonVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlBalloon_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlBalloon_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlBalloon_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlBalloon_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlBalloon_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlBalloon_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlBalloon_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlBalloon_get_Enabled(This,Enabled)	\
    (This)->lpVtbl -> get_Enabled(This,Enabled)

#define IAgentCtlBalloon_get_NumberOfLines(This,Lines)	\
    (This)->lpVtbl -> get_NumberOfLines(This,Lines)

#define IAgentCtlBalloon_get_CharsPerLine(This,CharsPerLine)	\
    (This)->lpVtbl -> get_CharsPerLine(This,CharsPerLine)

#define IAgentCtlBalloon_get_FontName(This,FontName)	\
    (This)->lpVtbl -> get_FontName(This,FontName)

#define IAgentCtlBalloon_get_FontSize(This,FontSize)	\
    (This)->lpVtbl -> get_FontSize(This,FontSize)

#define IAgentCtlBalloon_get_FontBold(This,FontBold)	\
    (This)->lpVtbl -> get_FontBold(This,FontBold)

#define IAgentCtlBalloon_get_FontItalic(This,FontItalic)	\
    (This)->lpVtbl -> get_FontItalic(This,FontItalic)

#define IAgentCtlBalloon_get_FontStrikethru(This,FontStrikethru)	\
    (This)->lpVtbl -> get_FontStrikethru(This,FontStrikethru)

#define IAgentCtlBalloon_get_FontUnderline(This,FontUnderline)	\
    (This)->lpVtbl -> get_FontUnderline(This,FontUnderline)

#define IAgentCtlBalloon_get_ForeColor(This,ForeColor)	\
    (This)->lpVtbl -> get_ForeColor(This,ForeColor)

#define IAgentCtlBalloon_get_BackColor(This,BackColor)	\
    (This)->lpVtbl -> get_BackColor(This,BackColor)

#define IAgentCtlBalloon_get_BorderColor(This,BorderColor)	\
    (This)->lpVtbl -> get_BorderColor(This,BorderColor)

#define IAgentCtlBalloon_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlBalloon_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlBalloon_put_FontName(This,FontName)	\
    (This)->lpVtbl -> put_FontName(This,FontName)

#define IAgentCtlBalloon_put_FontSize(This,FontSize)	\
    (This)->lpVtbl -> put_FontSize(This,FontSize)

#define IAgentCtlBalloon_put_FontCharSet(This,FontCharSet)	\
    (This)->lpVtbl -> put_FontCharSet(This,FontCharSet)

#define IAgentCtlBalloon_get_FontCharSet(This,FontCharSet)	\
    (This)->lpVtbl -> get_FontCharSet(This,FontCharSet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_Enabled_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);


void __RPC_STUB IAgentCtlBalloon_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_NumberOfLines_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Lines);


void __RPC_STUB IAgentCtlBalloon_get_NumberOfLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_CharsPerLine_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *CharsPerLine);


void __RPC_STUB IAgentCtlBalloon_get_CharsPerLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontName_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *FontName);


void __RPC_STUB IAgentCtlBalloon_get_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontSize_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *FontSize);


void __RPC_STUB IAgentCtlBalloon_get_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontBold_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontBold);


void __RPC_STUB IAgentCtlBalloon_get_FontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontItalic_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontItalic);


void __RPC_STUB IAgentCtlBalloon_get_FontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontStrikethru_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontStrikethru);


void __RPC_STUB IAgentCtlBalloon_get_FontStrikethru_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontUnderline_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontUnderline);


void __RPC_STUB IAgentCtlBalloon_get_FontUnderline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_ForeColor_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ForeColor);


void __RPC_STUB IAgentCtlBalloon_get_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_BackColor_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *BackColor);


void __RPC_STUB IAgentCtlBalloon_get_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_BorderColor_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *BorderColor);


void __RPC_STUB IAgentCtlBalloon_get_BorderColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_put_Visible_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Visible);


void __RPC_STUB IAgentCtlBalloon_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_Visible_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlBalloon_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_put_FontName_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [in] */ BSTR FontName);


void __RPC_STUB IAgentCtlBalloon_put_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_put_FontSize_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [in] */ long FontSize);


void __RPC_STUB IAgentCtlBalloon_put_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_put_FontCharSet_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [in] */ short FontCharSet);


void __RPC_STUB IAgentCtlBalloon_put_FontCharSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloon_get_FontCharSet_Proxy( 
    IAgentCtlBalloon __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *FontCharSet);


void __RPC_STUB IAgentCtlBalloon_get_FontCharSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlBalloon_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlBalloonEx_INTERFACE_DEFINED__
#define __IAgentCtlBalloonEx_INTERFACE_DEFINED__

/* interface IAgentCtlBalloonEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlBalloonEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("822DB1C0-8879-11d1-9EC6-00C04FD7081F")
    IAgentCtlBalloonEx : public IAgentCtlBalloon
    {
    public:
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Style( 
            /* [in] */ long Style) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Style( 
            /* [retval][out] */ long __RPC_FAR *Style) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlBalloonExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlBalloonEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlBalloonEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NumberOfLines )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Lines);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CharsPerLine )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *CharsPerLine);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontName )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *FontName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontSize )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *FontSize);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontBold )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontBold);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontItalic )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontItalic);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontStrikethru )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontStrikethru);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontUnderline )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *FontUnderline);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForeColor )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ForeColor);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColor )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *BackColor);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BorderColor )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *BorderColor);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontName )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ BSTR FontName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontSize )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ long FontSize);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontCharSet )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ short FontCharSet);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontCharSet )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *FontCharSet);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Style )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [in] */ long Style);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Style )( 
            IAgentCtlBalloonEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Style);
        
        END_INTERFACE
    } IAgentCtlBalloonExVtbl;

    interface IAgentCtlBalloonEx
    {
        CONST_VTBL struct IAgentCtlBalloonExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlBalloonEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlBalloonEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlBalloonEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlBalloonEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlBalloonEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlBalloonEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlBalloonEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlBalloonEx_get_Enabled(This,Enabled)	\
    (This)->lpVtbl -> get_Enabled(This,Enabled)

#define IAgentCtlBalloonEx_get_NumberOfLines(This,Lines)	\
    (This)->lpVtbl -> get_NumberOfLines(This,Lines)

#define IAgentCtlBalloonEx_get_CharsPerLine(This,CharsPerLine)	\
    (This)->lpVtbl -> get_CharsPerLine(This,CharsPerLine)

#define IAgentCtlBalloonEx_get_FontName(This,FontName)	\
    (This)->lpVtbl -> get_FontName(This,FontName)

#define IAgentCtlBalloonEx_get_FontSize(This,FontSize)	\
    (This)->lpVtbl -> get_FontSize(This,FontSize)

#define IAgentCtlBalloonEx_get_FontBold(This,FontBold)	\
    (This)->lpVtbl -> get_FontBold(This,FontBold)

#define IAgentCtlBalloonEx_get_FontItalic(This,FontItalic)	\
    (This)->lpVtbl -> get_FontItalic(This,FontItalic)

#define IAgentCtlBalloonEx_get_FontStrikethru(This,FontStrikethru)	\
    (This)->lpVtbl -> get_FontStrikethru(This,FontStrikethru)

#define IAgentCtlBalloonEx_get_FontUnderline(This,FontUnderline)	\
    (This)->lpVtbl -> get_FontUnderline(This,FontUnderline)

#define IAgentCtlBalloonEx_get_ForeColor(This,ForeColor)	\
    (This)->lpVtbl -> get_ForeColor(This,ForeColor)

#define IAgentCtlBalloonEx_get_BackColor(This,BackColor)	\
    (This)->lpVtbl -> get_BackColor(This,BackColor)

#define IAgentCtlBalloonEx_get_BorderColor(This,BorderColor)	\
    (This)->lpVtbl -> get_BorderColor(This,BorderColor)

#define IAgentCtlBalloonEx_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlBalloonEx_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlBalloonEx_put_FontName(This,FontName)	\
    (This)->lpVtbl -> put_FontName(This,FontName)

#define IAgentCtlBalloonEx_put_FontSize(This,FontSize)	\
    (This)->lpVtbl -> put_FontSize(This,FontSize)

#define IAgentCtlBalloonEx_put_FontCharSet(This,FontCharSet)	\
    (This)->lpVtbl -> put_FontCharSet(This,FontCharSet)

#define IAgentCtlBalloonEx_get_FontCharSet(This,FontCharSet)	\
    (This)->lpVtbl -> get_FontCharSet(This,FontCharSet)


#define IAgentCtlBalloonEx_put_Style(This,Style)	\
    (This)->lpVtbl -> put_Style(This,Style)

#define IAgentCtlBalloonEx_get_Style(This,Style)	\
    (This)->lpVtbl -> get_Style(This,Style)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloonEx_put_Style_Proxy( 
    IAgentCtlBalloonEx __RPC_FAR * This,
    /* [in] */ long Style);


void __RPC_STUB IAgentCtlBalloonEx_put_Style_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlBalloonEx_get_Style_Proxy( 
    IAgentCtlBalloonEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Style);


void __RPC_STUB IAgentCtlBalloonEx_get_Style_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlBalloonEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCommand_INTERFACE_DEFINED__
#define __IAgentCtlCommand_INTERFACE_DEFINED__

/* interface IAgentCtlCommand */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlCommand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5BE8BE3-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlCommand : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Voice( 
            /* [retval][out] */ BSTR __RPC_FAR *Voice) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Voice( 
            /* [in] */ BSTR Voice) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR __RPC_FAR *Caption) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Caption( 
            /* [in] */ BSTR Caption) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL Enabled) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Confidence( 
            /* [retval][out] */ long __RPC_FAR *Confidence) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Confidence( 
            /* [in] */ long Confidence) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ConfidenceText( 
            /* [retval][out] */ BSTR __RPC_FAR *Text) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ConfidenceText( 
            /* [in] */ BSTR Text) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCommandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCommand __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCommand __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Voice )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Voice);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Voice )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ BSTR Voice);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Caption);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ BSTR Caption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Enabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Confidence )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Confidence);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Confidence )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ long Confidence);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ConfidenceText )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Text);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ConfidenceText )( 
            IAgentCtlCommand __RPC_FAR * This,
            /* [in] */ BSTR Text);
        
        END_INTERFACE
    } IAgentCtlCommandVtbl;

    interface IAgentCtlCommand
    {
        CONST_VTBL struct IAgentCtlCommandVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCommand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCommand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCommand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCommand_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCommand_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCommand_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCommand_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCommand_get_Voice(This,Voice)	\
    (This)->lpVtbl -> get_Voice(This,Voice)

#define IAgentCtlCommand_put_Voice(This,Voice)	\
    (This)->lpVtbl -> put_Voice(This,Voice)

#define IAgentCtlCommand_get_Caption(This,Caption)	\
    (This)->lpVtbl -> get_Caption(This,Caption)

#define IAgentCtlCommand_put_Caption(This,Caption)	\
    (This)->lpVtbl -> put_Caption(This,Caption)

#define IAgentCtlCommand_get_Enabled(This,Enabled)	\
    (This)->lpVtbl -> get_Enabled(This,Enabled)

#define IAgentCtlCommand_put_Enabled(This,Enabled)	\
    (This)->lpVtbl -> put_Enabled(This,Enabled)

#define IAgentCtlCommand_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCommand_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlCommand_get_Confidence(This,Confidence)	\
    (This)->lpVtbl -> get_Confidence(This,Confidence)

#define IAgentCtlCommand_put_Confidence(This,Confidence)	\
    (This)->lpVtbl -> put_Confidence(This,Confidence)

#define IAgentCtlCommand_get_ConfidenceText(This,Text)	\
    (This)->lpVtbl -> get_ConfidenceText(This,Text)

#define IAgentCtlCommand_put_ConfidenceText(This,Text)	\
    (This)->lpVtbl -> put_ConfidenceText(This,Text)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_Voice_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Voice);


void __RPC_STUB IAgentCtlCommand_get_Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_Voice_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ BSTR Voice);


void __RPC_STUB IAgentCtlCommand_put_Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_Caption_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Caption);


void __RPC_STUB IAgentCtlCommand_get_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_Caption_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ BSTR Caption);


void __RPC_STUB IAgentCtlCommand_put_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_Enabled_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);


void __RPC_STUB IAgentCtlCommand_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_Enabled_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Enabled);


void __RPC_STUB IAgentCtlCommand_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_Visible_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlCommand_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_Visible_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Visible);


void __RPC_STUB IAgentCtlCommand_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_Confidence_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Confidence);


void __RPC_STUB IAgentCtlCommand_get_Confidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_Confidence_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ long Confidence);


void __RPC_STUB IAgentCtlCommand_put_Confidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_get_ConfidenceText_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Text);


void __RPC_STUB IAgentCtlCommand_get_ConfidenceText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommand_put_ConfidenceText_Proxy( 
    IAgentCtlCommand __RPC_FAR * This,
    /* [in] */ BSTR Text);


void __RPC_STUB IAgentCtlCommand_put_ConfidenceText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCommand_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCommandEx_INTERFACE_DEFINED__
#define __IAgentCtlCommandEx_INTERFACE_DEFINED__

/* interface IAgentCtlCommandEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlCommandEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B0913410-3B44-11d1-ACBA-00C04FD97575")
    IAgentCtlCommandEx : public IAgentCtlCommand
    {
    public:
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpContextID( 
            /* [in] */ long ID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpContextID( 
            /* [retval][out] */ long __RPC_FAR *ID) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_VoiceCaption( 
            /* [in] */ BSTR VoiceCaption) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_VoiceCaption( 
            /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCommandExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCommandEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCommandEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Voice )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Voice);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Voice )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ BSTR Voice);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Caption);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ BSTR Caption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enabled);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Enabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Confidence )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Confidence);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Confidence )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ long Confidence);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ConfidenceText )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Text);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ConfidenceText )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ BSTR Text);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpContextID )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ long ID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpContextID )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ID);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_VoiceCaption )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [in] */ BSTR VoiceCaption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VoiceCaption )( 
            IAgentCtlCommandEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption);
        
        END_INTERFACE
    } IAgentCtlCommandExVtbl;

    interface IAgentCtlCommandEx
    {
        CONST_VTBL struct IAgentCtlCommandExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCommandEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCommandEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCommandEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCommandEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCommandEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCommandEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCommandEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCommandEx_get_Voice(This,Voice)	\
    (This)->lpVtbl -> get_Voice(This,Voice)

#define IAgentCtlCommandEx_put_Voice(This,Voice)	\
    (This)->lpVtbl -> put_Voice(This,Voice)

#define IAgentCtlCommandEx_get_Caption(This,Caption)	\
    (This)->lpVtbl -> get_Caption(This,Caption)

#define IAgentCtlCommandEx_put_Caption(This,Caption)	\
    (This)->lpVtbl -> put_Caption(This,Caption)

#define IAgentCtlCommandEx_get_Enabled(This,Enabled)	\
    (This)->lpVtbl -> get_Enabled(This,Enabled)

#define IAgentCtlCommandEx_put_Enabled(This,Enabled)	\
    (This)->lpVtbl -> put_Enabled(This,Enabled)

#define IAgentCtlCommandEx_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCommandEx_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlCommandEx_get_Confidence(This,Confidence)	\
    (This)->lpVtbl -> get_Confidence(This,Confidence)

#define IAgentCtlCommandEx_put_Confidence(This,Confidence)	\
    (This)->lpVtbl -> put_Confidence(This,Confidence)

#define IAgentCtlCommandEx_get_ConfidenceText(This,Text)	\
    (This)->lpVtbl -> get_ConfidenceText(This,Text)

#define IAgentCtlCommandEx_put_ConfidenceText(This,Text)	\
    (This)->lpVtbl -> put_ConfidenceText(This,Text)


#define IAgentCtlCommandEx_put_HelpContextID(This,ID)	\
    (This)->lpVtbl -> put_HelpContextID(This,ID)

#define IAgentCtlCommandEx_get_HelpContextID(This,ID)	\
    (This)->lpVtbl -> get_HelpContextID(This,ID)

#define IAgentCtlCommandEx_put_VoiceCaption(This,VoiceCaption)	\
    (This)->lpVtbl -> put_VoiceCaption(This,VoiceCaption)

#define IAgentCtlCommandEx_get_VoiceCaption(This,VoiceCaption)	\
    (This)->lpVtbl -> get_VoiceCaption(This,VoiceCaption)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandEx_put_HelpContextID_Proxy( 
    IAgentCtlCommandEx __RPC_FAR * This,
    /* [in] */ long ID);


void __RPC_STUB IAgentCtlCommandEx_put_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandEx_get_HelpContextID_Proxy( 
    IAgentCtlCommandEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ID);


void __RPC_STUB IAgentCtlCommandEx_get_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandEx_put_VoiceCaption_Proxy( 
    IAgentCtlCommandEx __RPC_FAR * This,
    /* [in] */ BSTR VoiceCaption);


void __RPC_STUB IAgentCtlCommandEx_put_VoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandEx_get_VoiceCaption_Proxy( 
    IAgentCtlCommandEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption);


void __RPC_STUB IAgentCtlCommandEx_get_VoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCommandEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCommands_INTERFACE_DEFINED__
#define __IAgentCtlCommands_INTERFACE_DEFINED__

/* interface IAgentCtlCommands */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlCommands;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5BE8BE1-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlCommands : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Command( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *Count) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR __RPC_FAR *Caption) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Caption( 
            /* [in] */ BSTR Caption) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Voice( 
            /* [retval][out] */ BSTR __RPC_FAR *Voice) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Voice( 
            /* [in] */ BSTR Voice) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ BSTR Name,
            /* [in] */ BSTR RefName,
            /* [optional][in] */ VARIANT Before,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCommandsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCommands __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCommands __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Command )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Count);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Caption);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Caption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Voice )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Voice);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Voice )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Voice);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enum )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [in] */ BSTR RefName,
            /* [optional][in] */ VARIANT Before,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IAgentCtlCommands __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll )( 
            IAgentCtlCommands __RPC_FAR * This);
        
        END_INTERFACE
    } IAgentCtlCommandsVtbl;

    interface IAgentCtlCommands
    {
        CONST_VTBL struct IAgentCtlCommandsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCommands_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCommands_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCommands_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCommands_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCommands_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCommands_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCommands_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCommands_get_Item(This,Name,Item)	\
    (This)->lpVtbl -> get_Item(This,Name,Item)

#define IAgentCtlCommands_Command(This,Name,Item)	\
    (This)->lpVtbl -> Command(This,Name,Item)

#define IAgentCtlCommands_get_Count(This,Count)	\
    (This)->lpVtbl -> get_Count(This,Count)

#define IAgentCtlCommands_get_Caption(This,Caption)	\
    (This)->lpVtbl -> get_Caption(This,Caption)

#define IAgentCtlCommands_put_Caption(This,Caption)	\
    (This)->lpVtbl -> put_Caption(This,Caption)

#define IAgentCtlCommands_get_Voice(This,Voice)	\
    (This)->lpVtbl -> get_Voice(This,Voice)

#define IAgentCtlCommands_put_Voice(This,Voice)	\
    (This)->lpVtbl -> put_Voice(This,Voice)

#define IAgentCtlCommands_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCommands_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlCommands_get_Enum(This,ppunkEnum)	\
    (This)->lpVtbl -> get_Enum(This,ppunkEnum)

#define IAgentCtlCommands_Add(This,Name,Caption,Voice,Enabled,Visible,Command)	\
    (This)->lpVtbl -> Add(This,Name,Caption,Voice,Enabled,Visible,Command)

#define IAgentCtlCommands_Insert(This,Name,RefName,Before,Caption,Voice,Enabled,Visible,Command)	\
    (This)->lpVtbl -> Insert(This,Name,RefName,Before,Caption,Voice,Enabled,Visible,Command)

#define IAgentCtlCommands_Remove(This,Name)	\
    (This)->lpVtbl -> Remove(This,Name)

#define IAgentCtlCommands_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Item_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);


void __RPC_STUB IAgentCtlCommands_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_Command_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);


void __RPC_STUB IAgentCtlCommands_Command_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Count_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Count);


void __RPC_STUB IAgentCtlCommands_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Caption_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Caption);


void __RPC_STUB IAgentCtlCommands_get_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_put_Caption_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Caption);


void __RPC_STUB IAgentCtlCommands_put_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Voice_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Voice);


void __RPC_STUB IAgentCtlCommands_get_Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_put_Voice_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Voice);


void __RPC_STUB IAgentCtlCommands_put_Voice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Visible_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlCommands_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_put_Visible_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Visible);


void __RPC_STUB IAgentCtlCommands_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_get_Enum_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);


void __RPC_STUB IAgentCtlCommands_get_Enum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_Add_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [optional][in] */ VARIANT Caption,
    /* [optional][in] */ VARIANT Voice,
    /* [optional][in] */ VARIANT Enabled,
    /* [optional][in] */ VARIANT Visible,
    /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);


void __RPC_STUB IAgentCtlCommands_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_Insert_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [in] */ BSTR RefName,
    /* [optional][in] */ VARIANT Before,
    /* [optional][in] */ VARIANT Caption,
    /* [optional][in] */ VARIANT Voice,
    /* [optional][in] */ VARIANT Enabled,
    /* [optional][in] */ VARIANT Visible,
    /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);


void __RPC_STUB IAgentCtlCommands_Insert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_Remove_Proxy( 
    IAgentCtlCommands __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB IAgentCtlCommands_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommands_RemoveAll_Proxy( 
    IAgentCtlCommands __RPC_FAR * This);


void __RPC_STUB IAgentCtlCommands_RemoveAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCommands_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCommandsEx_INTERFACE_DEFINED__
#define __IAgentCtlCommandsEx_INTERFACE_DEFINED__

/* interface IAgentCtlCommandsEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlCommandsEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6BA90C01-3910-11d1-ACB3-00C04FD97575")
    IAgentCtlCommandsEx : public IAgentCtlCommands
    {
    public:
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultCommand( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultCommand( 
            /* [retval][out] */ BSTR __RPC_FAR *Name) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpContextID( 
            /* [in] */ long ID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpContextID( 
            /* [retval][out] */ long __RPC_FAR *ID) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_FontName( 
            /* [in] */ BSTR FontName) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontName( 
            /* [retval][out] */ BSTR __RPC_FAR *FontName) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FontSize( 
            /* [retval][out] */ long __RPC_FAR *FontSize) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_FontSize( 
            /* [in] */ long FontSize) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_VoiceCaption( 
            /* [in] */ BSTR VoiceCaption) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_VoiceCaption( 
            /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_GlobalVoiceCommandsEnabled( 
            /* [in] */ VARIANT_BOOL Enable) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_GlobalVoiceCommandsEnabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCommandsExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCommandsEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCommandsEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Command )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IAgentCtlCommandEx __RPC_FAR *__RPC_FAR *Item);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Count);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Caption);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Caption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Voice )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Voice);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Voice )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Voice);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enum )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [in] */ BSTR RefName,
            /* [optional][in] */ VARIANT Before,
            /* [optional][in] */ VARIANT Caption,
            /* [optional][in] */ VARIANT Voice,
            /* [optional][in] */ VARIANT Enabled,
            /* [optional][in] */ VARIANT Visible,
            /* [retval][out] */ IAgentCtlCommand __RPC_FAR *__RPC_FAR *Command);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll )( 
            IAgentCtlCommandsEx __RPC_FAR * This);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DefaultCommand )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DefaultCommand )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Name);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpContextID )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ long ID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpContextID )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ID);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontName )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR FontName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontName )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *FontName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FontSize )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *FontSize);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FontSize )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ long FontSize);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_VoiceCaption )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR VoiceCaption);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VoiceCaption )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GlobalVoiceCommandsEnabled )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Enable);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GlobalVoiceCommandsEnabled )( 
            IAgentCtlCommandsEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enable);
        
        END_INTERFACE
    } IAgentCtlCommandsExVtbl;

    interface IAgentCtlCommandsEx
    {
        CONST_VTBL struct IAgentCtlCommandsExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCommandsEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCommandsEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCommandsEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCommandsEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCommandsEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCommandsEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCommandsEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCommandsEx_get_Item(This,Name,Item)	\
    (This)->lpVtbl -> get_Item(This,Name,Item)

#define IAgentCtlCommandsEx_Command(This,Name,Item)	\
    (This)->lpVtbl -> Command(This,Name,Item)

#define IAgentCtlCommandsEx_get_Count(This,Count)	\
    (This)->lpVtbl -> get_Count(This,Count)

#define IAgentCtlCommandsEx_get_Caption(This,Caption)	\
    (This)->lpVtbl -> get_Caption(This,Caption)

#define IAgentCtlCommandsEx_put_Caption(This,Caption)	\
    (This)->lpVtbl -> put_Caption(This,Caption)

#define IAgentCtlCommandsEx_get_Voice(This,Voice)	\
    (This)->lpVtbl -> get_Voice(This,Voice)

#define IAgentCtlCommandsEx_put_Voice(This,Voice)	\
    (This)->lpVtbl -> put_Voice(This,Voice)

#define IAgentCtlCommandsEx_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCommandsEx_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlCommandsEx_get_Enum(This,ppunkEnum)	\
    (This)->lpVtbl -> get_Enum(This,ppunkEnum)

#define IAgentCtlCommandsEx_Add(This,Name,Caption,Voice,Enabled,Visible,Command)	\
    (This)->lpVtbl -> Add(This,Name,Caption,Voice,Enabled,Visible,Command)

#define IAgentCtlCommandsEx_Insert(This,Name,RefName,Before,Caption,Voice,Enabled,Visible,Command)	\
    (This)->lpVtbl -> Insert(This,Name,RefName,Before,Caption,Voice,Enabled,Visible,Command)

#define IAgentCtlCommandsEx_Remove(This,Name)	\
    (This)->lpVtbl -> Remove(This,Name)

#define IAgentCtlCommandsEx_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)


#define IAgentCtlCommandsEx_put_DefaultCommand(This,Name)	\
    (This)->lpVtbl -> put_DefaultCommand(This,Name)

#define IAgentCtlCommandsEx_get_DefaultCommand(This,Name)	\
    (This)->lpVtbl -> get_DefaultCommand(This,Name)

#define IAgentCtlCommandsEx_put_HelpContextID(This,ID)	\
    (This)->lpVtbl -> put_HelpContextID(This,ID)

#define IAgentCtlCommandsEx_get_HelpContextID(This,ID)	\
    (This)->lpVtbl -> get_HelpContextID(This,ID)

#define IAgentCtlCommandsEx_put_FontName(This,FontName)	\
    (This)->lpVtbl -> put_FontName(This,FontName)

#define IAgentCtlCommandsEx_get_FontName(This,FontName)	\
    (This)->lpVtbl -> get_FontName(This,FontName)

#define IAgentCtlCommandsEx_get_FontSize(This,FontSize)	\
    (This)->lpVtbl -> get_FontSize(This,FontSize)

#define IAgentCtlCommandsEx_put_FontSize(This,FontSize)	\
    (This)->lpVtbl -> put_FontSize(This,FontSize)

#define IAgentCtlCommandsEx_put_VoiceCaption(This,VoiceCaption)	\
    (This)->lpVtbl -> put_VoiceCaption(This,VoiceCaption)

#define IAgentCtlCommandsEx_get_VoiceCaption(This,VoiceCaption)	\
    (This)->lpVtbl -> get_VoiceCaption(This,VoiceCaption)

#define IAgentCtlCommandsEx_put_GlobalVoiceCommandsEnabled(This,Enable)	\
    (This)->lpVtbl -> put_GlobalVoiceCommandsEnabled(This,Enable)

#define IAgentCtlCommandsEx_get_GlobalVoiceCommandsEnabled(This,Enable)	\
    (This)->lpVtbl -> get_GlobalVoiceCommandsEnabled(This,Enable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_DefaultCommand_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB IAgentCtlCommandsEx_put_DefaultCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_DefaultCommand_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Name);


void __RPC_STUB IAgentCtlCommandsEx_get_DefaultCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_HelpContextID_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ long ID);


void __RPC_STUB IAgentCtlCommandsEx_put_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_HelpContextID_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ID);


void __RPC_STUB IAgentCtlCommandsEx_get_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_FontName_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR FontName);


void __RPC_STUB IAgentCtlCommandsEx_put_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_FontName_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *FontName);


void __RPC_STUB IAgentCtlCommandsEx_get_FontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_FontSize_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *FontSize);


void __RPC_STUB IAgentCtlCommandsEx_get_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_FontSize_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ long FontSize);


void __RPC_STUB IAgentCtlCommandsEx_put_FontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_VoiceCaption_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR VoiceCaption);


void __RPC_STUB IAgentCtlCommandsEx_put_VoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_VoiceCaption_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *VoiceCaption);


void __RPC_STUB IAgentCtlCommandsEx_get_VoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_put_GlobalVoiceCommandsEnabled_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Enable);


void __RPC_STUB IAgentCtlCommandsEx_put_GlobalVoiceCommandsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsEx_get_GlobalVoiceCommandsEnabled_Proxy( 
    IAgentCtlCommandsEx __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Enable);


void __RPC_STUB IAgentCtlCommandsEx_get_GlobalVoiceCommandsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCommandsEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCharacter_INTERFACE_DEFINED__
#define __IAgentCtlCharacter_INTERFACE_DEFINED__

/* interface IAgentCtlCharacter */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlCharacter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5BE8BD9-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlCharacter : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Balloon( 
            /* [retval][out] */ IAgentCtlBalloonEx __RPC_FAR *__RPC_FAR *ppidBalloon) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Commands( 
            /* [retval][out] */ IAgentCtlCommandsEx __RPC_FAR *__RPC_FAR *ppidCommands) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *Name) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR __RPC_FAR *Description) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Left( 
            short Left) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ short __RPC_FAR *Left) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Top( 
            short Top) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ short __RPC_FAR *Top) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Height( 
            short Height) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ short __RPC_FAR *Height) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Width( 
            short Width) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ short __RPC_FAR *Width) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Speed( 
            /* [retval][out] */ long __RPC_FAR *Speed) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Pitch( 
            /* [retval][out] */ long __RPC_FAR *Pitch) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_IdleOn( 
            VARIANT_BOOL On) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IdleOn( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Activate( 
            /* [optional][in] */ VARIANT State,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Success) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Play( 
            /* [in] */ BSTR Animation,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ BSTR Type,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Queue,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Stop( 
            /* [optional][in] */ VARIANT Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Wait( 
            /* [in] */ IDispatch __RPC_FAR *WaitForRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Interrupt( 
            /* [in] */ IDispatch __RPC_FAR *InterruptRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Speak( 
            /* [optional][in] */ VARIANT Text,
            /* [optional][in] */ VARIANT Url,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GestureAt( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MoveTo( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [optional][in] */ VARIANT Speed,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Hide( 
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Show( 
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StopAll( 
            /* [optional][in] */ VARIANT Types) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MoveCause( 
            /* [retval][out] */ short __RPC_FAR *MoveCause) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_VisibilityCause( 
            /* [retval][out] */ short __RPC_FAR *VisibilityCause) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HasOtherClients( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *HasOtherClients) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_SoundEffectsOn( 
            VARIANT_BOOL On) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SoundEffectsOn( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR Description) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ExtraData( 
            /* [retval][out] */ BSTR __RPC_FAR *ExtraData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCharacterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCharacter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCharacter __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Balloon )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlBalloonEx __RPC_FAR *__RPC_FAR *ppidBalloon);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Commands )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCommandsEx __RPC_FAR *__RPC_FAR *ppidCommands);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Description )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Left )( 
            IAgentCtlCharacter __RPC_FAR * This,
            short Left);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Left )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Left);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Top )( 
            IAgentCtlCharacter __RPC_FAR * This,
            short Top);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Top )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Top);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Height )( 
            IAgentCtlCharacter __RPC_FAR * This,
            short Height);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Height )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Height);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Width )( 
            IAgentCtlCharacter __RPC_FAR * This,
            short Width);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Width);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Speed )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Speed);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Pitch )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Pitch);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IdleOn )( 
            IAgentCtlCharacter __RPC_FAR * This,
            VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IdleOn )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Activate )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT State,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Success);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ BSTR Animation,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Get )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ BSTR Type,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Queue,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Wait )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *WaitForRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Interrupt )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *InterruptRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Speak )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT Text,
            /* [optional][in] */ VARIANT Url,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GestureAt )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [optional][in] */ VARIANT Speed,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hide )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Show )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopAll )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [optional][in] */ VARIANT Types);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MoveCause )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *MoveCause);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VisibilityCause )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *VisibilityCause);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HasOtherClients )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *HasOtherClients);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SoundEffectsOn )( 
            IAgentCtlCharacter __RPC_FAR * This,
            VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SoundEffectsOn )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Description )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [in] */ BSTR Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ExtraData )( 
            IAgentCtlCharacter __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ExtraData);
        
        END_INTERFACE
    } IAgentCtlCharacterVtbl;

    interface IAgentCtlCharacter
    {
        CONST_VTBL struct IAgentCtlCharacterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCharacter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCharacter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCharacter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCharacter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCharacter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCharacter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCharacter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCharacter_get_Balloon(This,ppidBalloon)	\
    (This)->lpVtbl -> get_Balloon(This,ppidBalloon)

#define IAgentCtlCharacter_get_Commands(This,ppidCommands)	\
    (This)->lpVtbl -> get_Commands(This,ppidCommands)

#define IAgentCtlCharacter_get_Name(This,Name)	\
    (This)->lpVtbl -> get_Name(This,Name)

#define IAgentCtlCharacter_get_Description(This,Description)	\
    (This)->lpVtbl -> get_Description(This,Description)

#define IAgentCtlCharacter_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCharacter_put_Left(This,Left)	\
    (This)->lpVtbl -> put_Left(This,Left)

#define IAgentCtlCharacter_get_Left(This,Left)	\
    (This)->lpVtbl -> get_Left(This,Left)

#define IAgentCtlCharacter_put_Top(This,Top)	\
    (This)->lpVtbl -> put_Top(This,Top)

#define IAgentCtlCharacter_get_Top(This,Top)	\
    (This)->lpVtbl -> get_Top(This,Top)

#define IAgentCtlCharacter_put_Height(This,Height)	\
    (This)->lpVtbl -> put_Height(This,Height)

#define IAgentCtlCharacter_get_Height(This,Height)	\
    (This)->lpVtbl -> get_Height(This,Height)

#define IAgentCtlCharacter_put_Width(This,Width)	\
    (This)->lpVtbl -> put_Width(This,Width)

#define IAgentCtlCharacter_get_Width(This,Width)	\
    (This)->lpVtbl -> get_Width(This,Width)

#define IAgentCtlCharacter_get_Speed(This,Speed)	\
    (This)->lpVtbl -> get_Speed(This,Speed)

#define IAgentCtlCharacter_get_Pitch(This,Pitch)	\
    (This)->lpVtbl -> get_Pitch(This,Pitch)

#define IAgentCtlCharacter_put_IdleOn(This,On)	\
    (This)->lpVtbl -> put_IdleOn(This,On)

#define IAgentCtlCharacter_get_IdleOn(This,On)	\
    (This)->lpVtbl -> get_IdleOn(This,On)

#define IAgentCtlCharacter_Activate(This,State,Success)	\
    (This)->lpVtbl -> Activate(This,State,Success)

#define IAgentCtlCharacter_Play(This,Animation,Request)	\
    (This)->lpVtbl -> Play(This,Animation,Request)

#define IAgentCtlCharacter_Get(This,Type,Name,Queue,Request)	\
    (This)->lpVtbl -> Get(This,Type,Name,Queue,Request)

#define IAgentCtlCharacter_Stop(This,Request)	\
    (This)->lpVtbl -> Stop(This,Request)

#define IAgentCtlCharacter_Wait(This,WaitForRequest,Request)	\
    (This)->lpVtbl -> Wait(This,WaitForRequest,Request)

#define IAgentCtlCharacter_Interrupt(This,InterruptRequest,Request)	\
    (This)->lpVtbl -> Interrupt(This,InterruptRequest,Request)

#define IAgentCtlCharacter_Speak(This,Text,Url,Request)	\
    (This)->lpVtbl -> Speak(This,Text,Url,Request)

#define IAgentCtlCharacter_GestureAt(This,x,y,Request)	\
    (This)->lpVtbl -> GestureAt(This,x,y,Request)

#define IAgentCtlCharacter_MoveTo(This,x,y,Speed,Request)	\
    (This)->lpVtbl -> MoveTo(This,x,y,Speed,Request)

#define IAgentCtlCharacter_Hide(This,Fast,Request)	\
    (This)->lpVtbl -> Hide(This,Fast,Request)

#define IAgentCtlCharacter_Show(This,Fast,Request)	\
    (This)->lpVtbl -> Show(This,Fast,Request)

#define IAgentCtlCharacter_StopAll(This,Types)	\
    (This)->lpVtbl -> StopAll(This,Types)

#define IAgentCtlCharacter_get_MoveCause(This,MoveCause)	\
    (This)->lpVtbl -> get_MoveCause(This,MoveCause)

#define IAgentCtlCharacter_get_VisibilityCause(This,VisibilityCause)	\
    (This)->lpVtbl -> get_VisibilityCause(This,VisibilityCause)

#define IAgentCtlCharacter_get_HasOtherClients(This,HasOtherClients)	\
    (This)->lpVtbl -> get_HasOtherClients(This,HasOtherClients)

#define IAgentCtlCharacter_put_SoundEffectsOn(This,On)	\
    (This)->lpVtbl -> put_SoundEffectsOn(This,On)

#define IAgentCtlCharacter_get_SoundEffectsOn(This,On)	\
    (This)->lpVtbl -> get_SoundEffectsOn(This,On)

#define IAgentCtlCharacter_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IAgentCtlCharacter_put_Description(This,Description)	\
    (This)->lpVtbl -> put_Description(This,Description)

#define IAgentCtlCharacter_get_ExtraData(This,ExtraData)	\
    (This)->lpVtbl -> get_ExtraData(This,ExtraData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Balloon_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlBalloonEx __RPC_FAR *__RPC_FAR *ppidBalloon);


void __RPC_STUB IAgentCtlCharacter_get_Balloon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Commands_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlCommandsEx __RPC_FAR *__RPC_FAR *ppidCommands);


void __RPC_STUB IAgentCtlCharacter_get_Commands_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Name_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Name);


void __RPC_STUB IAgentCtlCharacter_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Description_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Description);


void __RPC_STUB IAgentCtlCharacter_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Visible_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlCharacter_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Left_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    short Left);


void __RPC_STUB IAgentCtlCharacter_put_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Left_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Left);


void __RPC_STUB IAgentCtlCharacter_get_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Top_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    short Top);


void __RPC_STUB IAgentCtlCharacter_put_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Top_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Top);


void __RPC_STUB IAgentCtlCharacter_get_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Height_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    short Height);


void __RPC_STUB IAgentCtlCharacter_put_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Height_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Height);


void __RPC_STUB IAgentCtlCharacter_get_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Width_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    short Width);


void __RPC_STUB IAgentCtlCharacter_put_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Width_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Width);


void __RPC_STUB IAgentCtlCharacter_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Speed_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Speed);


void __RPC_STUB IAgentCtlCharacter_get_Speed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_Pitch_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Pitch);


void __RPC_STUB IAgentCtlCharacter_get_Pitch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_IdleOn_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    VARIANT_BOOL On);


void __RPC_STUB IAgentCtlCharacter_put_IdleOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_IdleOn_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);


void __RPC_STUB IAgentCtlCharacter_get_IdleOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Activate_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT State,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Success);


void __RPC_STUB IAgentCtlCharacter_Activate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Play_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ BSTR Animation,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Play_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Get_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ BSTR Type,
    /* [in] */ BSTR Name,
    /* [optional][in] */ VARIANT Queue,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Get_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Stop_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT Request);


void __RPC_STUB IAgentCtlCharacter_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Wait_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *WaitForRequest,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Wait_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Interrupt_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *InterruptRequest,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Interrupt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Speak_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT Text,
    /* [optional][in] */ VARIANT Url,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Speak_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_GestureAt_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_GestureAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_MoveTo_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [optional][in] */ VARIANT Speed,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_MoveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Hide_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT Fast,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Hide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_Show_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT Fast,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacter_Show_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_StopAll_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [optional][in] */ VARIANT Types);


void __RPC_STUB IAgentCtlCharacter_StopAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_MoveCause_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *MoveCause);


void __RPC_STUB IAgentCtlCharacter_get_MoveCause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_VisibilityCause_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *VisibilityCause);


void __RPC_STUB IAgentCtlCharacter_get_VisibilityCause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_HasOtherClients_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *HasOtherClients);


void __RPC_STUB IAgentCtlCharacter_get_HasOtherClients_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_SoundEffectsOn_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    VARIANT_BOOL On);


void __RPC_STUB IAgentCtlCharacter_put_SoundEffectsOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_SoundEffectsOn_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);


void __RPC_STUB IAgentCtlCharacter_get_SoundEffectsOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Name_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB IAgentCtlCharacter_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_put_Description_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [in] */ BSTR Description);


void __RPC_STUB IAgentCtlCharacter_put_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacter_get_ExtraData_Proxy( 
    IAgentCtlCharacter __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *ExtraData);


void __RPC_STUB IAgentCtlCharacter_get_ExtraData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCharacter_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlAnimationNames_INTERFACE_DEFINED__
#define __IAgentCtlAnimationNames_INTERFACE_DEFINED__

/* interface IAgentCtlAnimationNames */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlAnimationNames;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8B77181C-D3EF-11d1-8500-00C04FA34A14")
    IAgentCtlAnimationNames : public IDispatch
    {
    public:
        virtual /* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlAnimationNamesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlAnimationNames __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlAnimationNames __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enum )( 
            IAgentCtlAnimationNames __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);
        
        END_INTERFACE
    } IAgentCtlAnimationNamesVtbl;

    interface IAgentCtlAnimationNames
    {
        CONST_VTBL struct IAgentCtlAnimationNamesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlAnimationNames_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlAnimationNames_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlAnimationNames_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlAnimationNames_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlAnimationNames_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlAnimationNames_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlAnimationNames_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlAnimationNames_get_Enum(This,ppunkEnum)	\
    (This)->lpVtbl -> get_Enum(This,ppunkEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlAnimationNames_get_Enum_Proxy( 
    IAgentCtlAnimationNames __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);


void __RPC_STUB IAgentCtlAnimationNames_get_Enum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlAnimationNames_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCharacterEx_INTERFACE_DEFINED__
#define __IAgentCtlCharacterEx_INTERFACE_DEFINED__

/* interface IAgentCtlCharacterEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlCharacterEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DE8EF600-2F82-11d1-ACAC-00C04FD97575")
    IAgentCtlCharacterEx : public IAgentCtlCharacter
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowPopupMenu( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Showed) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoPopupMenu( 
            /* [in] */ VARIANT_BOOL On) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoPopupMenu( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpModeOn( 
            /* [in] */ VARIANT_BOOL On) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpModeOn( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpContextID( 
            /* [in] */ long ID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpContextID( 
            /* [retval][out] */ long __RPC_FAR *ID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ short __RPC_FAR *State) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Listen( 
            /* [in] */ VARIANT_BOOL Listen,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *StartedListening) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_LanguageID( 
            /* [in] */ long LanguageID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LanguageID( 
            /* [retval][out] */ long __RPC_FAR *LanguageID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SRModeID( 
            /* [retval][out] */ BSTR __RPC_FAR *EngineModeId) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_SRModeID( 
            /* [in] */ BSTR EngineModeId) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_TTSModeID( 
            /* [retval][out] */ BSTR __RPC_FAR *EngineModeId) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_TTSModeID( 
            /* [in] */ BSTR EngineModeId) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpFile( 
            /* [retval][out] */ BSTR __RPC_FAR *File) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpFile( 
            /* [in] */ BSTR File) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_GUID( 
            /* [retval][out] */ BSTR __RPC_FAR *GUID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_OriginalHeight( 
            /* [retval][out] */ short __RPC_FAR *Height) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_OriginalWidth( 
            /* [retval][out] */ short __RPC_FAR *Width) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Think( 
            /* [in] */ BSTR Text,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ BSTR __RPC_FAR *Version) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_AnimationNames( 
            /* [retval][out] */ IAgentCtlAnimationNames __RPC_FAR *__RPC_FAR *Names) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SRStatus( 
            /* [retval][out] */ long __RPC_FAR *Status) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCharacterExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCharacterEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCharacterEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Balloon )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlBalloonEx __RPC_FAR *__RPC_FAR *ppidBalloon);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Commands )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCommandsEx __RPC_FAR *__RPC_FAR *ppidCommands);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Description )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Left )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            short Left);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Left )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Left);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Top )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            short Top);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Top )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Top);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Height )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            short Height);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Height )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Height);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Width )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            short Width);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Width);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Speed )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Speed);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Pitch )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Pitch);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IdleOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IdleOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Activate )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT State,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Success);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR Animation,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Get )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR Type,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT Queue,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Wait )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *WaitForRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Interrupt )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *InterruptRequest,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Speak )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT Text,
            /* [optional][in] */ VARIANT Url,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GestureAt )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [optional][in] */ VARIANT Speed,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hide )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Show )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT Fast,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopAll )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT Types);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MoveCause )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *MoveCause);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VisibilityCause )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *VisibilityCause);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HasOtherClients )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *HasOtherClients);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SoundEffectsOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SoundEffectsOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Description )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ExtraData )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *ExtraData);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowPopupMenu )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Showed);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AutoPopupMenu )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AutoPopupMenu )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpModeOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL On);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpModeOn )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpContextID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ long ID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpContextID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Active )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *State);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Listen )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Listen,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *StartedListening);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LanguageID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ long LanguageID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LanguageID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *LanguageID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SRModeID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *EngineModeId);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SRModeID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR EngineModeId);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TTSModeID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *EngineModeId);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TTSModeID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR EngineModeId);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HelpFile )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *File);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HelpFile )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR File);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GUID )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *GUID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OriginalHeight )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Height);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OriginalWidth )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Width);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Think )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR Text,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Version )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Version);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AnimationNames )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlAnimationNames __RPC_FAR *__RPC_FAR *Names);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SRStatus )( 
            IAgentCtlCharacterEx __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Status);
        
        END_INTERFACE
    } IAgentCtlCharacterExVtbl;

    interface IAgentCtlCharacterEx
    {
        CONST_VTBL struct IAgentCtlCharacterExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCharacterEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCharacterEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCharacterEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCharacterEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCharacterEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCharacterEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCharacterEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCharacterEx_get_Balloon(This,ppidBalloon)	\
    (This)->lpVtbl -> get_Balloon(This,ppidBalloon)

#define IAgentCtlCharacterEx_get_Commands(This,ppidCommands)	\
    (This)->lpVtbl -> get_Commands(This,ppidCommands)

#define IAgentCtlCharacterEx_get_Name(This,Name)	\
    (This)->lpVtbl -> get_Name(This,Name)

#define IAgentCtlCharacterEx_get_Description(This,Description)	\
    (This)->lpVtbl -> get_Description(This,Description)

#define IAgentCtlCharacterEx_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCharacterEx_put_Left(This,Left)	\
    (This)->lpVtbl -> put_Left(This,Left)

#define IAgentCtlCharacterEx_get_Left(This,Left)	\
    (This)->lpVtbl -> get_Left(This,Left)

#define IAgentCtlCharacterEx_put_Top(This,Top)	\
    (This)->lpVtbl -> put_Top(This,Top)

#define IAgentCtlCharacterEx_get_Top(This,Top)	\
    (This)->lpVtbl -> get_Top(This,Top)

#define IAgentCtlCharacterEx_put_Height(This,Height)	\
    (This)->lpVtbl -> put_Height(This,Height)

#define IAgentCtlCharacterEx_get_Height(This,Height)	\
    (This)->lpVtbl -> get_Height(This,Height)

#define IAgentCtlCharacterEx_put_Width(This,Width)	\
    (This)->lpVtbl -> put_Width(This,Width)

#define IAgentCtlCharacterEx_get_Width(This,Width)	\
    (This)->lpVtbl -> get_Width(This,Width)

#define IAgentCtlCharacterEx_get_Speed(This,Speed)	\
    (This)->lpVtbl -> get_Speed(This,Speed)

#define IAgentCtlCharacterEx_get_Pitch(This,Pitch)	\
    (This)->lpVtbl -> get_Pitch(This,Pitch)

#define IAgentCtlCharacterEx_put_IdleOn(This,On)	\
    (This)->lpVtbl -> put_IdleOn(This,On)

#define IAgentCtlCharacterEx_get_IdleOn(This,On)	\
    (This)->lpVtbl -> get_IdleOn(This,On)

#define IAgentCtlCharacterEx_Activate(This,State,Success)	\
    (This)->lpVtbl -> Activate(This,State,Success)

#define IAgentCtlCharacterEx_Play(This,Animation,Request)	\
    (This)->lpVtbl -> Play(This,Animation,Request)

#define IAgentCtlCharacterEx_Get(This,Type,Name,Queue,Request)	\
    (This)->lpVtbl -> Get(This,Type,Name,Queue,Request)

#define IAgentCtlCharacterEx_Stop(This,Request)	\
    (This)->lpVtbl -> Stop(This,Request)

#define IAgentCtlCharacterEx_Wait(This,WaitForRequest,Request)	\
    (This)->lpVtbl -> Wait(This,WaitForRequest,Request)

#define IAgentCtlCharacterEx_Interrupt(This,InterruptRequest,Request)	\
    (This)->lpVtbl -> Interrupt(This,InterruptRequest,Request)

#define IAgentCtlCharacterEx_Speak(This,Text,Url,Request)	\
    (This)->lpVtbl -> Speak(This,Text,Url,Request)

#define IAgentCtlCharacterEx_GestureAt(This,x,y,Request)	\
    (This)->lpVtbl -> GestureAt(This,x,y,Request)

#define IAgentCtlCharacterEx_MoveTo(This,x,y,Speed,Request)	\
    (This)->lpVtbl -> MoveTo(This,x,y,Speed,Request)

#define IAgentCtlCharacterEx_Hide(This,Fast,Request)	\
    (This)->lpVtbl -> Hide(This,Fast,Request)

#define IAgentCtlCharacterEx_Show(This,Fast,Request)	\
    (This)->lpVtbl -> Show(This,Fast,Request)

#define IAgentCtlCharacterEx_StopAll(This,Types)	\
    (This)->lpVtbl -> StopAll(This,Types)

#define IAgentCtlCharacterEx_get_MoveCause(This,MoveCause)	\
    (This)->lpVtbl -> get_MoveCause(This,MoveCause)

#define IAgentCtlCharacterEx_get_VisibilityCause(This,VisibilityCause)	\
    (This)->lpVtbl -> get_VisibilityCause(This,VisibilityCause)

#define IAgentCtlCharacterEx_get_HasOtherClients(This,HasOtherClients)	\
    (This)->lpVtbl -> get_HasOtherClients(This,HasOtherClients)

#define IAgentCtlCharacterEx_put_SoundEffectsOn(This,On)	\
    (This)->lpVtbl -> put_SoundEffectsOn(This,On)

#define IAgentCtlCharacterEx_get_SoundEffectsOn(This,On)	\
    (This)->lpVtbl -> get_SoundEffectsOn(This,On)

#define IAgentCtlCharacterEx_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IAgentCtlCharacterEx_put_Description(This,Description)	\
    (This)->lpVtbl -> put_Description(This,Description)

#define IAgentCtlCharacterEx_get_ExtraData(This,ExtraData)	\
    (This)->lpVtbl -> get_ExtraData(This,ExtraData)


#define IAgentCtlCharacterEx_ShowPopupMenu(This,x,y,Showed)	\
    (This)->lpVtbl -> ShowPopupMenu(This,x,y,Showed)

#define IAgentCtlCharacterEx_put_AutoPopupMenu(This,On)	\
    (This)->lpVtbl -> put_AutoPopupMenu(This,On)

#define IAgentCtlCharacterEx_get_AutoPopupMenu(This,On)	\
    (This)->lpVtbl -> get_AutoPopupMenu(This,On)

#define IAgentCtlCharacterEx_put_HelpModeOn(This,On)	\
    (This)->lpVtbl -> put_HelpModeOn(This,On)

#define IAgentCtlCharacterEx_get_HelpModeOn(This,On)	\
    (This)->lpVtbl -> get_HelpModeOn(This,On)

#define IAgentCtlCharacterEx_put_HelpContextID(This,ID)	\
    (This)->lpVtbl -> put_HelpContextID(This,ID)

#define IAgentCtlCharacterEx_get_HelpContextID(This,ID)	\
    (This)->lpVtbl -> get_HelpContextID(This,ID)

#define IAgentCtlCharacterEx_get_Active(This,State)	\
    (This)->lpVtbl -> get_Active(This,State)

#define IAgentCtlCharacterEx_Listen(This,Listen,StartedListening)	\
    (This)->lpVtbl -> Listen(This,Listen,StartedListening)

#define IAgentCtlCharacterEx_put_LanguageID(This,LanguageID)	\
    (This)->lpVtbl -> put_LanguageID(This,LanguageID)

#define IAgentCtlCharacterEx_get_LanguageID(This,LanguageID)	\
    (This)->lpVtbl -> get_LanguageID(This,LanguageID)

#define IAgentCtlCharacterEx_get_SRModeID(This,EngineModeId)	\
    (This)->lpVtbl -> get_SRModeID(This,EngineModeId)

#define IAgentCtlCharacterEx_put_SRModeID(This,EngineModeId)	\
    (This)->lpVtbl -> put_SRModeID(This,EngineModeId)

#define IAgentCtlCharacterEx_get_TTSModeID(This,EngineModeId)	\
    (This)->lpVtbl -> get_TTSModeID(This,EngineModeId)

#define IAgentCtlCharacterEx_put_TTSModeID(This,EngineModeId)	\
    (This)->lpVtbl -> put_TTSModeID(This,EngineModeId)

#define IAgentCtlCharacterEx_get_HelpFile(This,File)	\
    (This)->lpVtbl -> get_HelpFile(This,File)

#define IAgentCtlCharacterEx_put_HelpFile(This,File)	\
    (This)->lpVtbl -> put_HelpFile(This,File)

#define IAgentCtlCharacterEx_get_GUID(This,GUID)	\
    (This)->lpVtbl -> get_GUID(This,GUID)

#define IAgentCtlCharacterEx_get_OriginalHeight(This,Height)	\
    (This)->lpVtbl -> get_OriginalHeight(This,Height)

#define IAgentCtlCharacterEx_get_OriginalWidth(This,Width)	\
    (This)->lpVtbl -> get_OriginalWidth(This,Width)

#define IAgentCtlCharacterEx_Think(This,Text,Request)	\
    (This)->lpVtbl -> Think(This,Text,Request)

#define IAgentCtlCharacterEx_get_Version(This,Version)	\
    (This)->lpVtbl -> get_Version(This,Version)

#define IAgentCtlCharacterEx_get_AnimationNames(This,Names)	\
    (This)->lpVtbl -> get_AnimationNames(This,Names)

#define IAgentCtlCharacterEx_get_SRStatus(This,Status)	\
    (This)->lpVtbl -> get_SRStatus(This,Status)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_ShowPopupMenu_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Showed);


void __RPC_STUB IAgentCtlCharacterEx_ShowPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_AutoPopupMenu_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL On);


void __RPC_STUB IAgentCtlCharacterEx_put_AutoPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_AutoPopupMenu_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);


void __RPC_STUB IAgentCtlCharacterEx_get_AutoPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_HelpModeOn_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL On);


void __RPC_STUB IAgentCtlCharacterEx_put_HelpModeOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_HelpModeOn_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *On);


void __RPC_STUB IAgentCtlCharacterEx_get_HelpModeOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_HelpContextID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ long ID);


void __RPC_STUB IAgentCtlCharacterEx_put_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_HelpContextID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ID);


void __RPC_STUB IAgentCtlCharacterEx_get_HelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_Active_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *State);


void __RPC_STUB IAgentCtlCharacterEx_get_Active_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_Listen_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Listen,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *StartedListening);


void __RPC_STUB IAgentCtlCharacterEx_Listen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_LanguageID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ long LanguageID);


void __RPC_STUB IAgentCtlCharacterEx_put_LanguageID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_LanguageID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *LanguageID);


void __RPC_STUB IAgentCtlCharacterEx_get_LanguageID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_SRModeID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *EngineModeId);


void __RPC_STUB IAgentCtlCharacterEx_get_SRModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_SRModeID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR EngineModeId);


void __RPC_STUB IAgentCtlCharacterEx_put_SRModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_TTSModeID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *EngineModeId);


void __RPC_STUB IAgentCtlCharacterEx_get_TTSModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_TTSModeID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR EngineModeId);


void __RPC_STUB IAgentCtlCharacterEx_put_TTSModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_HelpFile_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *File);


void __RPC_STUB IAgentCtlCharacterEx_get_HelpFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_put_HelpFile_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR File);


void __RPC_STUB IAgentCtlCharacterEx_put_HelpFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_GUID_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *GUID);


void __RPC_STUB IAgentCtlCharacterEx_get_GUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_OriginalHeight_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Height);


void __RPC_STUB IAgentCtlCharacterEx_get_OriginalHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_OriginalWidth_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Width);


void __RPC_STUB IAgentCtlCharacterEx_get_OriginalWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_Think_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR Text,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *Request);


void __RPC_STUB IAgentCtlCharacterEx_Think_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_Version_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Version);


void __RPC_STUB IAgentCtlCharacterEx_get_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_AnimationNames_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlAnimationNames __RPC_FAR *__RPC_FAR *Names);


void __RPC_STUB IAgentCtlCharacterEx_get_AnimationNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacterEx_get_SRStatus_Proxy( 
    IAgentCtlCharacterEx __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Status);


void __RPC_STUB IAgentCtlCharacterEx_get_SRStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCharacterEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCharacters_INTERFACE_DEFINED__
#define __IAgentCtlCharacters_INTERFACE_DEFINED__

/* interface IAgentCtlCharacters */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlCharacters;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5BE8BE8-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlCharacters : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ BSTR CharacterID,
            /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Character( 
            /* [in] */ BSTR CharacterID,
            /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem) = 0;
        
        virtual /* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Unload( 
            /* [in] */ BSTR CharacterID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR CharacterID,
            /* [optional][in] */ VARIANT LoadKey,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *ppidRequest) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCharactersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCharacters __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCharacters __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ BSTR CharacterID,
            /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Character )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ BSTR CharacterID,
            /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem);
        
        /* [restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enum )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unload )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ BSTR CharacterID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IAgentCtlCharacters __RPC_FAR * This,
            /* [in] */ BSTR CharacterID,
            /* [optional][in] */ VARIANT LoadKey,
            /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *ppidRequest);
        
        END_INTERFACE
    } IAgentCtlCharactersVtbl;

    interface IAgentCtlCharacters
    {
        CONST_VTBL struct IAgentCtlCharactersVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCharacters_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCharacters_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCharacters_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCharacters_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCharacters_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCharacters_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCharacters_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCharacters_get_Item(This,CharacterID,ppidItem)	\
    (This)->lpVtbl -> get_Item(This,CharacterID,ppidItem)

#define IAgentCtlCharacters_Character(This,CharacterID,ppidItem)	\
    (This)->lpVtbl -> Character(This,CharacterID,ppidItem)

#define IAgentCtlCharacters_get_Enum(This,ppunkEnum)	\
    (This)->lpVtbl -> get_Enum(This,ppunkEnum)

#define IAgentCtlCharacters_Unload(This,CharacterID)	\
    (This)->lpVtbl -> Unload(This,CharacterID)

#define IAgentCtlCharacters_Load(This,CharacterID,LoadKey,ppidRequest)	\
    (This)->lpVtbl -> Load(This,CharacterID,LoadKey,ppidRequest)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacters_get_Item_Proxy( 
    IAgentCtlCharacters __RPC_FAR * This,
    /* [in] */ BSTR CharacterID,
    /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem);


void __RPC_STUB IAgentCtlCharacters_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacters_Character_Proxy( 
    IAgentCtlCharacters __RPC_FAR * This,
    /* [in] */ BSTR CharacterID,
    /* [retval][out] */ IAgentCtlCharacterEx __RPC_FAR *__RPC_FAR *ppidItem);


void __RPC_STUB IAgentCtlCharacters_Character_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [restricted][propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacters_get_Enum_Proxy( 
    IAgentCtlCharacters __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);


void __RPC_STUB IAgentCtlCharacters_get_Enum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacters_Unload_Proxy( 
    IAgentCtlCharacters __RPC_FAR * This,
    /* [in] */ BSTR CharacterID);


void __RPC_STUB IAgentCtlCharacters_Unload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCharacters_Load_Proxy( 
    IAgentCtlCharacters __RPC_FAR * This,
    /* [in] */ BSTR CharacterID,
    /* [optional][in] */ VARIANT LoadKey,
    /* [retval][out] */ IAgentCtlRequest __RPC_FAR *__RPC_FAR *ppidRequest);


void __RPC_STUB IAgentCtlCharacters_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCharacters_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlAudioObject_INTERFACE_DEFINED__
#define __IAgentCtlAudioObject_INTERFACE_DEFINED__

/* interface IAgentCtlAudioObject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlAudioObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5BE8BDB-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlAudioObject : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *AudioEnabled) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SoundEffects( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *SoundEffects) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlAudioObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlAudioObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlAudioObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *AudioEnabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SoundEffects )( 
            IAgentCtlAudioObject __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *SoundEffects);
        
        END_INTERFACE
    } IAgentCtlAudioObjectVtbl;

    interface IAgentCtlAudioObject
    {
        CONST_VTBL struct IAgentCtlAudioObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlAudioObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlAudioObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlAudioObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlAudioObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlAudioObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlAudioObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlAudioObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlAudioObject_get_Enabled(This,AudioEnabled)	\
    (This)->lpVtbl -> get_Enabled(This,AudioEnabled)

#define IAgentCtlAudioObject_get_SoundEffects(This,SoundEffects)	\
    (This)->lpVtbl -> get_SoundEffects(This,SoundEffects)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlAudioObject_get_Enabled_Proxy( 
    IAgentCtlAudioObject __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *AudioEnabled);


void __RPC_STUB IAgentCtlAudioObject_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlAudioObject_get_SoundEffects_Proxy( 
    IAgentCtlAudioObject __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *SoundEffects);


void __RPC_STUB IAgentCtlAudioObject_get_SoundEffects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlAudioObject_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlAudioObjectEx_INTERFACE_DEFINED__
#define __IAgentCtlAudioObjectEx_INTERFACE_DEFINED__

/* interface IAgentCtlAudioObjectEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlAudioObjectEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5BE8BF0-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlAudioObjectEx : public IAgentCtlAudioObject
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ short __RPC_FAR *Available) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlAudioObjectExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *AudioEnabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SoundEffects )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *SoundEffects);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Status )( 
            IAgentCtlAudioObjectEx __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Available);
        
        END_INTERFACE
    } IAgentCtlAudioObjectExVtbl;

    interface IAgentCtlAudioObjectEx
    {
        CONST_VTBL struct IAgentCtlAudioObjectExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlAudioObjectEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlAudioObjectEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlAudioObjectEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlAudioObjectEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlAudioObjectEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlAudioObjectEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlAudioObjectEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlAudioObjectEx_get_Enabled(This,AudioEnabled)	\
    (This)->lpVtbl -> get_Enabled(This,AudioEnabled)

#define IAgentCtlAudioObjectEx_get_SoundEffects(This,SoundEffects)	\
    (This)->lpVtbl -> get_SoundEffects(This,SoundEffects)


#define IAgentCtlAudioObjectEx_get_Status(This,Available)	\
    (This)->lpVtbl -> get_Status(This,Available)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlAudioObjectEx_get_Status_Proxy( 
    IAgentCtlAudioObjectEx __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Available);


void __RPC_STUB IAgentCtlAudioObjectEx_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlAudioObjectEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlSpeechInput_INTERFACE_DEFINED__
#define __IAgentCtlSpeechInput_INTERFACE_DEFINED__

/* interface IAgentCtlSpeechInput */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlSpeechInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5BE8BDD-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlSpeechInput : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceEnabled) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Language( 
            /* [retval][out] */ BSTR __RPC_FAR *Language) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HotKey( 
            /* [retval][out] */ BSTR __RPC_FAR *HotKey) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Installed( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceInstalled) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Engine( 
            /* [retval][out] */ BSTR __RPC_FAR *Engine) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Engine( 
            /* [in] */ BSTR Engine) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ListeningTip( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ListeningTip) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlSpeechInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlSpeechInput __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlSpeechInput __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceEnabled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Language )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Language);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HotKey )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *HotKey);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Installed )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceInstalled);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Engine )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Engine);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Engine )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [in] */ BSTR Engine);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ListeningTip )( 
            IAgentCtlSpeechInput __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ListeningTip);
        
        END_INTERFACE
    } IAgentCtlSpeechInputVtbl;

    interface IAgentCtlSpeechInput
    {
        CONST_VTBL struct IAgentCtlSpeechInputVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlSpeechInput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlSpeechInput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlSpeechInput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlSpeechInput_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlSpeechInput_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlSpeechInput_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlSpeechInput_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlSpeechInput_get_Enabled(This,VoiceEnabled)	\
    (This)->lpVtbl -> get_Enabled(This,VoiceEnabled)

#define IAgentCtlSpeechInput_get_Language(This,Language)	\
    (This)->lpVtbl -> get_Language(This,Language)

#define IAgentCtlSpeechInput_get_HotKey(This,HotKey)	\
    (This)->lpVtbl -> get_HotKey(This,HotKey)

#define IAgentCtlSpeechInput_get_Installed(This,VoiceInstalled)	\
    (This)->lpVtbl -> get_Installed(This,VoiceInstalled)

#define IAgentCtlSpeechInput_get_Engine(This,Engine)	\
    (This)->lpVtbl -> get_Engine(This,Engine)

#define IAgentCtlSpeechInput_put_Engine(This,Engine)	\
    (This)->lpVtbl -> put_Engine(This,Engine)

#define IAgentCtlSpeechInput_get_ListeningTip(This,ListeningTip)	\
    (This)->lpVtbl -> get_ListeningTip(This,ListeningTip)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_Enabled_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceEnabled);


void __RPC_STUB IAgentCtlSpeechInput_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_Language_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Language);


void __RPC_STUB IAgentCtlSpeechInput_get_Language_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_HotKey_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *HotKey);


void __RPC_STUB IAgentCtlSpeechInput_get_HotKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_Installed_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *VoiceInstalled);


void __RPC_STUB IAgentCtlSpeechInput_get_Installed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_Engine_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Engine);


void __RPC_STUB IAgentCtlSpeechInput_get_Engine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_put_Engine_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [in] */ BSTR Engine);


void __RPC_STUB IAgentCtlSpeechInput_put_Engine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlSpeechInput_get_ListeningTip_Proxy( 
    IAgentCtlSpeechInput __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ListeningTip);


void __RPC_STUB IAgentCtlSpeechInput_get_ListeningTip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlSpeechInput_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlPropertySheet_INTERFACE_DEFINED__
#define __IAgentCtlPropertySheet_INTERFACE_DEFINED__

/* interface IAgentCtlPropertySheet */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlPropertySheet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5BE8BDF-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtlPropertySheet : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ short __RPC_FAR *Left) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ short __RPC_FAR *Top) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ short __RPC_FAR *Height) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ short __RPC_FAR *Width) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Page( 
            /* [in] */ BSTR Page) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Page( 
            /* [retval][out] */ BSTR __RPC_FAR *Page) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlPropertySheetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlPropertySheet __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlPropertySheet __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Left )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Left);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Top )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Top);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Height )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Height);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Width);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Page )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [in] */ BSTR Page);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Page )( 
            IAgentCtlPropertySheet __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Page);
        
        END_INTERFACE
    } IAgentCtlPropertySheetVtbl;

    interface IAgentCtlPropertySheet
    {
        CONST_VTBL struct IAgentCtlPropertySheetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlPropertySheet_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlPropertySheet_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlPropertySheet_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlPropertySheet_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlPropertySheet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlPropertySheet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlPropertySheet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlPropertySheet_get_Left(This,Left)	\
    (This)->lpVtbl -> get_Left(This,Left)

#define IAgentCtlPropertySheet_get_Top(This,Top)	\
    (This)->lpVtbl -> get_Top(This,Top)

#define IAgentCtlPropertySheet_get_Height(This,Height)	\
    (This)->lpVtbl -> get_Height(This,Height)

#define IAgentCtlPropertySheet_get_Width(This,Width)	\
    (This)->lpVtbl -> get_Width(This,Width)

#define IAgentCtlPropertySheet_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlPropertySheet_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlPropertySheet_put_Page(This,Page)	\
    (This)->lpVtbl -> put_Page(This,Page)

#define IAgentCtlPropertySheet_get_Page(This,Page)	\
    (This)->lpVtbl -> get_Page(This,Page)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Left_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Left);


void __RPC_STUB IAgentCtlPropertySheet_get_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Top_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Top);


void __RPC_STUB IAgentCtlPropertySheet_get_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Height_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Height);


void __RPC_STUB IAgentCtlPropertySheet_get_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Width_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Width);


void __RPC_STUB IAgentCtlPropertySheet_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_put_Visible_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Visible);


void __RPC_STUB IAgentCtlPropertySheet_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Visible_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlPropertySheet_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_put_Page_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [in] */ BSTR Page);


void __RPC_STUB IAgentCtlPropertySheet_put_Page_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlPropertySheet_get_Page_Proxy( 
    IAgentCtlPropertySheet __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Page);


void __RPC_STUB IAgentCtlPropertySheet_get_Page_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlPropertySheet_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlCommandsWindow_INTERFACE_DEFINED__
#define __IAgentCtlCommandsWindow_INTERFACE_DEFINED__

/* interface IAgentCtlCommandsWindow */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlCommandsWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6D0ECB27-9968-11D0-AC6E-00C04FD97575")
    IAgentCtlCommandsWindow : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ short __RPC_FAR *Left) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ short __RPC_FAR *Top) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ short __RPC_FAR *Height) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ short __RPC_FAR *Width) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlCommandsWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlCommandsWindow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlCommandsWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Visible )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Visible )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Left )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Left);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Top )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Top);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Height )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Height);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            IAgentCtlCommandsWindow __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *Width);
        
        END_INTERFACE
    } IAgentCtlCommandsWindowVtbl;

    interface IAgentCtlCommandsWindow
    {
        CONST_VTBL struct IAgentCtlCommandsWindowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlCommandsWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlCommandsWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlCommandsWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlCommandsWindow_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlCommandsWindow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlCommandsWindow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlCommandsWindow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlCommandsWindow_get_Visible(This,Visible)	\
    (This)->lpVtbl -> get_Visible(This,Visible)

#define IAgentCtlCommandsWindow_put_Visible(This,Visible)	\
    (This)->lpVtbl -> put_Visible(This,Visible)

#define IAgentCtlCommandsWindow_get_Left(This,Left)	\
    (This)->lpVtbl -> get_Left(This,Left)

#define IAgentCtlCommandsWindow_get_Top(This,Top)	\
    (This)->lpVtbl -> get_Top(This,Top)

#define IAgentCtlCommandsWindow_get_Height(This,Height)	\
    (This)->lpVtbl -> get_Height(This,Height)

#define IAgentCtlCommandsWindow_get_Width(This,Width)	\
    (This)->lpVtbl -> get_Width(This,Width)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_get_Visible_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Visible);


void __RPC_STUB IAgentCtlCommandsWindow_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_put_Visible_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Visible);


void __RPC_STUB IAgentCtlCommandsWindow_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_get_Left_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Left);


void __RPC_STUB IAgentCtlCommandsWindow_get_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_get_Top_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Top);


void __RPC_STUB IAgentCtlCommandsWindow_get_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_get_Height_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Height);


void __RPC_STUB IAgentCtlCommandsWindow_get_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlCommandsWindow_get_Width_Proxy( 
    IAgentCtlCommandsWindow __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *Width);


void __RPC_STUB IAgentCtlCommandsWindow_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlCommandsWindow_INTERFACE_DEFINED__ */


#ifndef __IAgentCtl_INTERFACE_DEFINED__
#define __IAgentCtl_INTERFACE_DEFINED__

/* interface IAgentCtl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5BE8BD1-7DE6-11D0-91FE-00C04FD701A5")
    IAgentCtl : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Characters( 
            /* [retval][out] */ IAgentCtlCharacters __RPC_FAR *__RPC_FAR *Characters) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_AudioOutput( 
            /* [retval][out] */ IAgentCtlAudioObjectEx __RPC_FAR *__RPC_FAR *AudioOutput) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SpeechInput( 
            /* [retval][out] */ IAgentCtlSpeechInput __RPC_FAR *__RPC_FAR *SpeechInput) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PropertySheet( 
            /* [retval][out] */ IAgentCtlPropertySheet __RPC_FAR *__RPC_FAR *PropSheet) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CommandsWindow( 
            /* [retval][out] */ IAgentCtlCommandsWindow __RPC_FAR *__RPC_FAR *CommandsWindow) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Connected( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Connected) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Connected( 
            /* [in] */ VARIANT_BOOL Connected) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Suspended( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Suspended) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Characters )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCharacters __RPC_FAR *__RPC_FAR *Characters);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AudioOutput )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlAudioObjectEx __RPC_FAR *__RPC_FAR *AudioOutput);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SpeechInput )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlSpeechInput __RPC_FAR *__RPC_FAR *SpeechInput);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PropertySheet )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlPropertySheet __RPC_FAR *__RPC_FAR *PropSheet);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CommandsWindow )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCommandsWindow __RPC_FAR *__RPC_FAR *CommandsWindow);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Connected )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Connected);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Connected )( 
            IAgentCtl __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Connected);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Suspended )( 
            IAgentCtl __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Suspended);
        
        END_INTERFACE
    } IAgentCtlVtbl;

    interface IAgentCtl
    {
        CONST_VTBL struct IAgentCtlVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtl_get_Characters(This,Characters)	\
    (This)->lpVtbl -> get_Characters(This,Characters)

#define IAgentCtl_get_AudioOutput(This,AudioOutput)	\
    (This)->lpVtbl -> get_AudioOutput(This,AudioOutput)

#define IAgentCtl_get_SpeechInput(This,SpeechInput)	\
    (This)->lpVtbl -> get_SpeechInput(This,SpeechInput)

#define IAgentCtl_get_PropertySheet(This,PropSheet)	\
    (This)->lpVtbl -> get_PropertySheet(This,PropSheet)

#define IAgentCtl_get_CommandsWindow(This,CommandsWindow)	\
    (This)->lpVtbl -> get_CommandsWindow(This,CommandsWindow)

#define IAgentCtl_get_Connected(This,Connected)	\
    (This)->lpVtbl -> get_Connected(This,Connected)

#define IAgentCtl_put_Connected(This,Connected)	\
    (This)->lpVtbl -> put_Connected(This,Connected)

#define IAgentCtl_get_Suspended(This,Suspended)	\
    (This)->lpVtbl -> get_Suspended(This,Suspended)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_Characters_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlCharacters __RPC_FAR *__RPC_FAR *Characters);


void __RPC_STUB IAgentCtl_get_Characters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_AudioOutput_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlAudioObjectEx __RPC_FAR *__RPC_FAR *AudioOutput);


void __RPC_STUB IAgentCtl_get_AudioOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_SpeechInput_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlSpeechInput __RPC_FAR *__RPC_FAR *SpeechInput);


void __RPC_STUB IAgentCtl_get_SpeechInput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_PropertySheet_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlPropertySheet __RPC_FAR *__RPC_FAR *PropSheet);


void __RPC_STUB IAgentCtl_get_PropertySheet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_CommandsWindow_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ IAgentCtlCommandsWindow __RPC_FAR *__RPC_FAR *CommandsWindow);


void __RPC_STUB IAgentCtl_get_CommandsWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_Connected_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Connected);


void __RPC_STUB IAgentCtl_get_Connected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_put_Connected_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Connected);


void __RPC_STUB IAgentCtl_put_Connected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtl_get_Suspended_Proxy( 
    IAgentCtl __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Suspended);


void __RPC_STUB IAgentCtl_get_Suspended_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtl_INTERFACE_DEFINED__ */


#ifndef __IAgentCtlEx_INTERFACE_DEFINED__
#define __IAgentCtlEx_INTERFACE_DEFINED__

/* interface IAgentCtlEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCtlEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8563FF20-8ECC-11d1-B9B4-00C04FD97575")
    IAgentCtlEx : public IAgentCtl
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowDefaultCharacterProperties( 
            /* [optional][in] */ VARIANT x,
            /* [optional][in] */ VARIANT y) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_RaiseRequestErrors( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *RaiseErrors) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_RaiseRequestErrors( 
            /* [in] */ VARIANT_BOOL RaiseErrors) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCtlExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCtlEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCtlEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Characters )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCharacters __RPC_FAR *__RPC_FAR *Characters);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AudioOutput )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlAudioObjectEx __RPC_FAR *__RPC_FAR *AudioOutput);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SpeechInput )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlSpeechInput __RPC_FAR *__RPC_FAR *SpeechInput);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PropertySheet )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlPropertySheet __RPC_FAR *__RPC_FAR *PropSheet);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CommandsWindow )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ IAgentCtlCommandsWindow __RPC_FAR *__RPC_FAR *CommandsWindow);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Connected )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Connected);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Connected )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Connected);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Suspended )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Suspended);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowDefaultCharacterProperties )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [optional][in] */ VARIANT x,
            /* [optional][in] */ VARIANT y);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RaiseRequestErrors )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *RaiseErrors);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RaiseRequestErrors )( 
            IAgentCtlEx __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL RaiseErrors);
        
        END_INTERFACE
    } IAgentCtlExVtbl;

    interface IAgentCtlEx
    {
        CONST_VTBL struct IAgentCtlExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCtlEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCtlEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCtlEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCtlEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCtlEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCtlEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCtlEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCtlEx_get_Characters(This,Characters)	\
    (This)->lpVtbl -> get_Characters(This,Characters)

#define IAgentCtlEx_get_AudioOutput(This,AudioOutput)	\
    (This)->lpVtbl -> get_AudioOutput(This,AudioOutput)

#define IAgentCtlEx_get_SpeechInput(This,SpeechInput)	\
    (This)->lpVtbl -> get_SpeechInput(This,SpeechInput)

#define IAgentCtlEx_get_PropertySheet(This,PropSheet)	\
    (This)->lpVtbl -> get_PropertySheet(This,PropSheet)

#define IAgentCtlEx_get_CommandsWindow(This,CommandsWindow)	\
    (This)->lpVtbl -> get_CommandsWindow(This,CommandsWindow)

#define IAgentCtlEx_get_Connected(This,Connected)	\
    (This)->lpVtbl -> get_Connected(This,Connected)

#define IAgentCtlEx_put_Connected(This,Connected)	\
    (This)->lpVtbl -> put_Connected(This,Connected)

#define IAgentCtlEx_get_Suspended(This,Suspended)	\
    (This)->lpVtbl -> get_Suspended(This,Suspended)


#define IAgentCtlEx_ShowDefaultCharacterProperties(This,x,y)	\
    (This)->lpVtbl -> ShowDefaultCharacterProperties(This,x,y)

#define IAgentCtlEx_get_RaiseRequestErrors(This,RaiseErrors)	\
    (This)->lpVtbl -> get_RaiseRequestErrors(This,RaiseErrors)

#define IAgentCtlEx_put_RaiseRequestErrors(This,RaiseErrors)	\
    (This)->lpVtbl -> put_RaiseRequestErrors(This,RaiseErrors)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IAgentCtlEx_ShowDefaultCharacterProperties_Proxy( 
    IAgentCtlEx __RPC_FAR * This,
    /* [optional][in] */ VARIANT x,
    /* [optional][in] */ VARIANT y);


void __RPC_STUB IAgentCtlEx_ShowDefaultCharacterProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlEx_get_RaiseRequestErrors_Proxy( 
    IAgentCtlEx __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *RaiseErrors);


void __RPC_STUB IAgentCtlEx_get_RaiseRequestErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IAgentCtlEx_put_RaiseRequestErrors_Proxy( 
    IAgentCtlEx __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL RaiseErrors);


void __RPC_STUB IAgentCtlEx_put_RaiseRequestErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCtlEx_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_AgentControl_0227 */
/* [local] */ 

#define	CONTROL_MAJOR_VERSION	( 2 )

#define	CONTROL_MINOR_VERSION	( 0 )



extern RPC_IF_HANDLE __MIDL_itf_AgentControl_0227_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AgentControl_0227_v0_0_s_ifspec;


#ifndef __AgentObjects_LIBRARY_DEFINED__
#define __AgentObjects_LIBRARY_DEFINED__

/* library AgentObjects */
/* [helpstring][version][uuid] */ 





















EXTERN_C const IID LIBID_AgentObjects;

#ifndef ___AgentEvents_DISPINTERFACE_DEFINED__
#define ___AgentEvents_DISPINTERFACE_DEFINED__

/* dispinterface _AgentEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__AgentEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F5BE8BD4-7DE6-11D0-91FE-00C04FD701A5")
    _AgentEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _AgentEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _AgentEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _AgentEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _AgentEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _AgentEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _AgentEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _AgentEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _AgentEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _AgentEventsVtbl;

    interface _AgentEvents
    {
        CONST_VTBL struct _AgentEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _AgentEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _AgentEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _AgentEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _AgentEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _AgentEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _AgentEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _AgentEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___AgentEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Agent;

#ifdef __cplusplus

class DECLSPEC_UUID("D45FD31B-5C6E-11D1-9EC1-00C04FD7081F")
Agent;
#endif
#endif /* __AgentObjects_LIBRARY_DEFINED__ */

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

#endif // _MSC_VER < 1200
