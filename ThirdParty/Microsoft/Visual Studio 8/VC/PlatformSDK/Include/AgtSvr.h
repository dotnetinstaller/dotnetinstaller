/**************************************************************************
*                                                                         *
* AgtSvr.h - Microsoft Agent Server                                       *
*                                                                         *
* Copyright (c) 1996-1999, Microsoft Corp. All rights reserved.           *
*                                                                         *
**************************************************************************/

#if _MSC_VER < 1200

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Mon Aug 31 17:00:38 1998
 */
/* Compiler settings for AgentServer.idl:
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

#ifndef __AgtSvrV5_h__
#define __AgtSvrV5_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAgentUserInput_FWD_DEFINED__
#define __IAgentUserInput_FWD_DEFINED__
typedef interface IAgentUserInput IAgentUserInput;
#endif 	/* __IAgentUserInput_FWD_DEFINED__ */


#ifndef __IAgentCommand_FWD_DEFINED__
#define __IAgentCommand_FWD_DEFINED__
typedef interface IAgentCommand IAgentCommand;
#endif 	/* __IAgentCommand_FWD_DEFINED__ */


#ifndef __IAgentCommandEx_FWD_DEFINED__
#define __IAgentCommandEx_FWD_DEFINED__
typedef interface IAgentCommandEx IAgentCommandEx;
#endif 	/* __IAgentCommandEx_FWD_DEFINED__ */


#ifndef __IAgentCommands_FWD_DEFINED__
#define __IAgentCommands_FWD_DEFINED__
typedef interface IAgentCommands IAgentCommands;
#endif 	/* __IAgentCommands_FWD_DEFINED__ */


#ifndef __IAgentCommandsEx_FWD_DEFINED__
#define __IAgentCommandsEx_FWD_DEFINED__
typedef interface IAgentCommandsEx IAgentCommandsEx;
#endif 	/* __IAgentCommandsEx_FWD_DEFINED__ */


#ifndef __IAgentCommandWindow_FWD_DEFINED__
#define __IAgentCommandWindow_FWD_DEFINED__
typedef interface IAgentCommandWindow IAgentCommandWindow;
#endif 	/* __IAgentCommandWindow_FWD_DEFINED__ */


#ifndef __IAgentSpeechInputProperties_FWD_DEFINED__
#define __IAgentSpeechInputProperties_FWD_DEFINED__
typedef interface IAgentSpeechInputProperties IAgentSpeechInputProperties;
#endif 	/* __IAgentSpeechInputProperties_FWD_DEFINED__ */


#ifndef __IAgentAudioOutputProperties_FWD_DEFINED__
#define __IAgentAudioOutputProperties_FWD_DEFINED__
typedef interface IAgentAudioOutputProperties IAgentAudioOutputProperties;
#endif 	/* __IAgentAudioOutputProperties_FWD_DEFINED__ */


#ifndef __IAgentAudioOutputPropertiesEx_FWD_DEFINED__
#define __IAgentAudioOutputPropertiesEx_FWD_DEFINED__
typedef interface IAgentAudioOutputPropertiesEx IAgentAudioOutputPropertiesEx;
#endif 	/* __IAgentAudioOutputPropertiesEx_FWD_DEFINED__ */


#ifndef __IAgentPropertySheet_FWD_DEFINED__
#define __IAgentPropertySheet_FWD_DEFINED__
typedef interface IAgentPropertySheet IAgentPropertySheet;
#endif 	/* __IAgentPropertySheet_FWD_DEFINED__ */


#ifndef __IAgentBalloon_FWD_DEFINED__
#define __IAgentBalloon_FWD_DEFINED__
typedef interface IAgentBalloon IAgentBalloon;
#endif 	/* __IAgentBalloon_FWD_DEFINED__ */


#ifndef __IAgentBalloonEx_FWD_DEFINED__
#define __IAgentBalloonEx_FWD_DEFINED__
typedef interface IAgentBalloonEx IAgentBalloonEx;
#endif 	/* __IAgentBalloonEx_FWD_DEFINED__ */


#ifndef __IAgentCharacter_FWD_DEFINED__
#define __IAgentCharacter_FWD_DEFINED__
typedef interface IAgentCharacter IAgentCharacter;
#endif 	/* __IAgentCharacter_FWD_DEFINED__ */


#ifndef __IAgentCharacterEx_FWD_DEFINED__
#define __IAgentCharacterEx_FWD_DEFINED__
typedef interface IAgentCharacterEx IAgentCharacterEx;
#endif 	/* __IAgentCharacterEx_FWD_DEFINED__ */


#ifndef __IAgent_FWD_DEFINED__
#define __IAgent_FWD_DEFINED__
typedef interface IAgent IAgent;
#endif 	/* __IAgent_FWD_DEFINED__ */


#ifndef __IAgentEx_FWD_DEFINED__
#define __IAgentEx_FWD_DEFINED__
typedef interface IAgentEx IAgentEx;
#endif 	/* __IAgentEx_FWD_DEFINED__ */


#ifndef __IAgentNotifySink_FWD_DEFINED__
#define __IAgentNotifySink_FWD_DEFINED__
typedef interface IAgentNotifySink IAgentNotifySink;
#endif 	/* __IAgentNotifySink_FWD_DEFINED__ */


#ifndef __IAgentNotifySinkEx_FWD_DEFINED__
#define __IAgentNotifySinkEx_FWD_DEFINED__
typedef interface IAgentNotifySinkEx IAgentNotifySinkEx;
#endif 	/* __IAgentNotifySinkEx_FWD_DEFINED__ */


#ifndef __IAgentPrivateNotifySink_FWD_DEFINED__
#define __IAgentPrivateNotifySink_FWD_DEFINED__
typedef interface IAgentPrivateNotifySink IAgentPrivateNotifySink;
#endif 	/* __IAgentPrivateNotifySink_FWD_DEFINED__ */


#ifndef __IAgentCustomMarshalMaker_FWD_DEFINED__
#define __IAgentCustomMarshalMaker_FWD_DEFINED__
typedef interface IAgentCustomMarshalMaker IAgentCustomMarshalMaker;
#endif 	/* __IAgentCustomMarshalMaker_FWD_DEFINED__ */


#ifndef __IAgentClientStatus_FWD_DEFINED__
#define __IAgentClientStatus_FWD_DEFINED__
typedef interface IAgentClientStatus IAgentClientStatus;
#endif 	/* __IAgentClientStatus_FWD_DEFINED__ */


#ifndef __AgentServer_FWD_DEFINED__
#define __AgentServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class AgentServer AgentServer;
#else
typedef struct AgentServer AgentServer;
#endif /* __cplusplus */

#endif 	/* __AgentServer_FWD_DEFINED__ */


#ifndef __IAgentUserInput_FWD_DEFINED__
#define __IAgentUserInput_FWD_DEFINED__
typedef interface IAgentUserInput IAgentUserInput;
#endif 	/* __IAgentUserInput_FWD_DEFINED__ */


#ifndef __IAgentCommand_FWD_DEFINED__
#define __IAgentCommand_FWD_DEFINED__
typedef interface IAgentCommand IAgentCommand;
#endif 	/* __IAgentCommand_FWD_DEFINED__ */


#ifndef __IAgentCommandEx_FWD_DEFINED__
#define __IAgentCommandEx_FWD_DEFINED__
typedef interface IAgentCommandEx IAgentCommandEx;
#endif 	/* __IAgentCommandEx_FWD_DEFINED__ */


#ifndef __IAgentCommands_FWD_DEFINED__
#define __IAgentCommands_FWD_DEFINED__
typedef interface IAgentCommands IAgentCommands;
#endif 	/* __IAgentCommands_FWD_DEFINED__ */


#ifndef __IAgentCommandsEx_FWD_DEFINED__
#define __IAgentCommandsEx_FWD_DEFINED__
typedef interface IAgentCommandsEx IAgentCommandsEx;
#endif 	/* __IAgentCommandsEx_FWD_DEFINED__ */


#ifndef __IAgentSpeechInputProperties_FWD_DEFINED__
#define __IAgentSpeechInputProperties_FWD_DEFINED__
typedef interface IAgentSpeechInputProperties IAgentSpeechInputProperties;
#endif 	/* __IAgentSpeechInputProperties_FWD_DEFINED__ */


#ifndef __IAgentAudioOutputProperties_FWD_DEFINED__
#define __IAgentAudioOutputProperties_FWD_DEFINED__
typedef interface IAgentAudioOutputProperties IAgentAudioOutputProperties;
#endif 	/* __IAgentAudioOutputProperties_FWD_DEFINED__ */


#ifndef __IAgentAudioOutputPropertiesEx_FWD_DEFINED__
#define __IAgentAudioOutputPropertiesEx_FWD_DEFINED__
typedef interface IAgentAudioOutputPropertiesEx IAgentAudioOutputPropertiesEx;
#endif 	/* __IAgentAudioOutputPropertiesEx_FWD_DEFINED__ */


#ifndef __IAgentPropertySheet_FWD_DEFINED__
#define __IAgentPropertySheet_FWD_DEFINED__
typedef interface IAgentPropertySheet IAgentPropertySheet;
#endif 	/* __IAgentPropertySheet_FWD_DEFINED__ */


#ifndef __IAgentBalloon_FWD_DEFINED__
#define __IAgentBalloon_FWD_DEFINED__
typedef interface IAgentBalloon IAgentBalloon;
#endif 	/* __IAgentBalloon_FWD_DEFINED__ */


#ifndef __IAgentBalloonEx_FWD_DEFINED__
#define __IAgentBalloonEx_FWD_DEFINED__
typedef interface IAgentBalloonEx IAgentBalloonEx;
#endif 	/* __IAgentBalloonEx_FWD_DEFINED__ */


#ifndef __IAgentCharacter_FWD_DEFINED__
#define __IAgentCharacter_FWD_DEFINED__
typedef interface IAgentCharacter IAgentCharacter;
#endif 	/* __IAgentCharacter_FWD_DEFINED__ */


#ifndef __IAgentCharacterEx_FWD_DEFINED__
#define __IAgentCharacterEx_FWD_DEFINED__
typedef interface IAgentCharacterEx IAgentCharacterEx;
#endif 	/* __IAgentCharacterEx_FWD_DEFINED__ */


#ifndef __IAgent_FWD_DEFINED__
#define __IAgent_FWD_DEFINED__
typedef interface IAgent IAgent;
#endif 	/* __IAgent_FWD_DEFINED__ */


#ifndef __IAgentEx_FWD_DEFINED__
#define __IAgentEx_FWD_DEFINED__
typedef interface IAgentEx IAgentEx;
#endif 	/* __IAgentEx_FWD_DEFINED__ */


#ifndef __IAgentNotifySink_FWD_DEFINED__
#define __IAgentNotifySink_FWD_DEFINED__
typedef interface IAgentNotifySink IAgentNotifySink;
#endif 	/* __IAgentNotifySink_FWD_DEFINED__ */


#ifndef __IAgentNotifySinkEx_FWD_DEFINED__
#define __IAgentNotifySinkEx_FWD_DEFINED__
typedef interface IAgentNotifySinkEx IAgentNotifySinkEx;
#endif 	/* __IAgentNotifySinkEx_FWD_DEFINED__ */


#ifndef __IAgentCommandWindow_FWD_DEFINED__
#define __IAgentCommandWindow_FWD_DEFINED__
typedef interface IAgentCommandWindow IAgentCommandWindow;
#endif 	/* __IAgentCommandWindow_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_AgentServer_0000
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define	NeverMoved	( 0 )

#define	UserMoved	( 1 )

#define	ProgramMoved	( 2 )

#define	OtherProgramMoved	( 3 )

#define	SystemMoved	( 4 )

#define	NeverShown	( 0 )

#define	UserHid	( 1 )

#define	UserShowed	( 2 )

#define	ProgramHid	( 3 )

#define	ProgramShowed	( 4 )

#define	OtherProgramHid	( 5 )

#define	OtherProgramShowed	( 6 )

#define	UserHidViaCharacterMenu	( 7 )

#define	UserHidViaTaskbarIcon	( UserHid )

#define	CSHELPCAUSE_COMMAND	( 1 )

#define	CSHELPCAUSE_OTHERPROGRAM	( 2 )

#define	CSHELPCAUSE_OPENCOMMANDSWINDOW	( 3 )

#define	CSHELPCAUSE_CLOSECOMMANDSWINDOW	( 4 )

#define	CSHELPCAUSE_SHOWCHARACTER	( 5 )

#define	CSHELPCAUSE_HIDECHARACTER	( 6 )

#define	CSHELPCAUSE_CHARACTER	( 7 )

#define	ACTIVATE_NOTTOPMOST	( 0 )

#define	ACTIVATE_TOPMOST	( 1 )

#define	ACTIVATE_NOTACTIVE	( 0 )

#define	ACTIVATE_ACTIVE	( 1 )

#define	ACTIVATE_INPUTACTIVE	( 2 )

#define	PREPARE_ANIMATION	( 0 )

#define	PREPARE_STATE	( 1 )

#define	PREPARE_WAVE	( 2 )

#define	STOP_TYPE_PLAY	( 0x1 )

#define	STOP_TYPE_MOVE	( 0x2 )

#define	STOP_TYPE_SPEAK	( 0x4 )

#define	STOP_TYPE_PREPARE	( 0x8 )

#define	STOP_TYPE_NONQUEUEDPREPARE	( 0x10 )

#define	STOP_TYPE_VISIBLE	( 0x20 )

#define	STOP_TYPE_ALL	( 0xffffffff )

#define	BALLOON_STYLE_BALLOON_ON	( 0x1 )

#define	BALLOON_STYLE_SIZETOTEXT	( 0x2 )

#define	BALLOON_STYLE_AUTOHIDE	( 0x4 )

#define	BALLOON_STYLE_AUTOPACE	( 0x8 )

#define	AUDIO_STATUS_AVAILABLE	( 0 )

#define	AUDIO_STATUS_NOAUDIO	( 1 )

#define	AUDIO_STATUS_CANTOPENAUDIO	( 2 )

#define	AUDIO_STATUS_USERSPEAKING	( 3 )

#define	AUDIO_STATUS_CHARACTERSPEAKING	( 4 )

#define	AUDIO_STATUS_SROVERRIDEABLE	( 5 )

#define	AUDIO_STATUS_ERROR	( 6 )

#define	LISTEN_STATUS_CANLISTEN	( 0 )

#define	LISTEN_STATUS_NOAUDIO	( 1 )

#define	LISTEN_STATUS_NOTACTIVE	( 2 )

#define	LISTEN_STATUS_CANTOPENAUDIO	( 3 )

#define	LISTEN_STATUS_COULDNTINITIALIZESPEECH	( 4 )

#define	LISTEN_STATUS_SPEECHDISABLED	( 5 )

#define	LISTEN_STATUS_ERROR	( 6 )

#define	MK_ICON	( 0x1000 )

#define	LSCOMPLETE_CAUSE_PROGRAMDISABLED	( 1 )

#define	LSCOMPLETE_CAUSE_PROGRAMTIMEDOUT	( 2 )

#define	LSCOMPLETE_CAUSE_USERTIMEDOUT	( 3 )

#define	LSCOMPLETE_CAUSE_USERRELEASEDKEY	( 4 )

#define	LSCOMPLETE_CAUSE_USERUTTERANCEENDED	( 5 )

#define	LSCOMPLETE_CAUSE_CLIENTDEACTIVATED	( 6 )

#define	LSCOMPLETE_CAUSE_DEFAULTCHARCHANGE	( 7 )

#define	LSCOMPLETE_CAUSE_USERDISABLED	( 8 )



extern RPC_IF_HANDLE __MIDL_itf_AgentServer_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AgentServer_0000_v0_0_s_ifspec;

#ifndef __IAgentUserInput_INTERFACE_DEFINED__
#define __IAgentUserInput_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentUserInput
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentUserInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("A7B93C80-7B81-11D0-AC5F-00C04FD97575")
    IAgentUserInput : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ long __RPC_FAR *pdwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemID( 
            /* [in] */ long dwItemIndex,
            /* [out] */ long __RPC_FAR *pdwCommandID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemConfidence( 
            /* [in] */ long dwItemIndex,
            /* [out] */ long __RPC_FAR *plConfidence) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemText( 
            /* [in] */ long dwItemIndex,
            /* [out] */ BSTR __RPC_FAR *pbszText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllItemData( 
            /* [out] */ VARIANT __RPC_FAR *pdwItemIndices,
            /* [out] */ VARIANT __RPC_FAR *plConfidences,
            /* [out] */ VARIANT __RPC_FAR *pbszText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentUserInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentUserInput __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentUserInput __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentUserInput __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IAgentUserInput __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemID )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ long dwItemIndex,
            /* [out] */ long __RPC_FAR *pdwCommandID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemConfidence )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ long dwItemIndex,
            /* [out] */ long __RPC_FAR *plConfidence);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemText )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ long dwItemIndex,
            /* [out] */ BSTR __RPC_FAR *pbszText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllItemData )( 
            IAgentUserInput __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *pdwItemIndices,
            /* [out] */ VARIANT __RPC_FAR *plConfidences,
            /* [out] */ VARIANT __RPC_FAR *pbszText);
        
        END_INTERFACE
    } IAgentUserInputVtbl;

    interface IAgentUserInput
    {
        CONST_VTBL struct IAgentUserInputVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentUserInput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentUserInput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentUserInput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentUserInput_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentUserInput_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentUserInput_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentUserInput_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentUserInput_GetCount(This,pdwCount)	\
    (This)->lpVtbl -> GetCount(This,pdwCount)

#define IAgentUserInput_GetItemID(This,dwItemIndex,pdwCommandID)	\
    (This)->lpVtbl -> GetItemID(This,dwItemIndex,pdwCommandID)

#define IAgentUserInput_GetItemConfidence(This,dwItemIndex,plConfidence)	\
    (This)->lpVtbl -> GetItemConfidence(This,dwItemIndex,plConfidence)

#define IAgentUserInput_GetItemText(This,dwItemIndex,pbszText)	\
    (This)->lpVtbl -> GetItemText(This,dwItemIndex,pbszText)

#define IAgentUserInput_GetAllItemData(This,pdwItemIndices,plConfidences,pbszText)	\
    (This)->lpVtbl -> GetAllItemData(This,pdwItemIndices,plConfidences,pbszText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentUserInput_GetCount_Proxy( 
    IAgentUserInput __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwCount);


void __RPC_STUB IAgentUserInput_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentUserInput_GetItemID_Proxy( 
    IAgentUserInput __RPC_FAR * This,
    /* [in] */ long dwItemIndex,
    /* [out] */ long __RPC_FAR *pdwCommandID);


void __RPC_STUB IAgentUserInput_GetItemID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentUserInput_GetItemConfidence_Proxy( 
    IAgentUserInput __RPC_FAR * This,
    /* [in] */ long dwItemIndex,
    /* [out] */ long __RPC_FAR *plConfidence);


void __RPC_STUB IAgentUserInput_GetItemConfidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentUserInput_GetItemText_Proxy( 
    IAgentUserInput __RPC_FAR * This,
    /* [in] */ long dwItemIndex,
    /* [out] */ BSTR __RPC_FAR *pbszText);


void __RPC_STUB IAgentUserInput_GetItemText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentUserInput_GetAllItemData_Proxy( 
    IAgentUserInput __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *pdwItemIndices,
    /* [out] */ VARIANT __RPC_FAR *plConfidences,
    /* [out] */ VARIANT __RPC_FAR *pbszText);


void __RPC_STUB IAgentUserInput_GetAllItemData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentUserInput_INTERFACE_DEFINED__ */


#ifndef __IAgentCommand_INTERFACE_DEFINED__
#define __IAgentCommand_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCommand
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCommand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("A7B93C83-7B81-11D0-AC5F-00C04FD97575")
    IAgentCommand : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetCaption( 
            /* [in] */ BSTR bszCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCaption( 
            /* [out] */ BSTR __RPC_FAR *pbszCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoice( 
            /* [in] */ BSTR bszVoice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoice( 
            /* [out] */ BSTR __RPC_FAR *pbszVoice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnabled( 
            /* [in] */ long bEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnabled( 
            /* [out] */ long __RPC_FAR *pbEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVisible( 
            /* [in] */ long bVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConfidenceThreshold( 
            /* [in] */ long lThreshold) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConfidenceThreshold( 
            /* [out] */ long __RPC_FAR *plThreshold) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConfidenceText( 
            /* [in] */ BSTR bszTipText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConfidenceText( 
            /* [out] */ BSTR __RPC_FAR *pbszTipText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetID( 
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCommandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCommand __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCommand __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ BSTR bszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaption )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoice )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ BSTR bszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoice )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ long bEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConfidenceThreshold )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ long lThreshold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConfidenceThreshold )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plThreshold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConfidenceText )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ BSTR bszTipText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConfidenceText )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszTipText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwID);
        
        END_INTERFACE
    } IAgentCommandVtbl;

    interface IAgentCommand
    {
        CONST_VTBL struct IAgentCommandVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCommand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCommand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCommand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCommand_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCommand_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCommand_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCommand_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCommand_SetCaption(This,bszCaption)	\
    (This)->lpVtbl -> SetCaption(This,bszCaption)

#define IAgentCommand_GetCaption(This,pbszCaption)	\
    (This)->lpVtbl -> GetCaption(This,pbszCaption)

#define IAgentCommand_SetVoice(This,bszVoice)	\
    (This)->lpVtbl -> SetVoice(This,bszVoice)

#define IAgentCommand_GetVoice(This,pbszVoice)	\
    (This)->lpVtbl -> GetVoice(This,pbszVoice)

#define IAgentCommand_SetEnabled(This,bEnabled)	\
    (This)->lpVtbl -> SetEnabled(This,bEnabled)

#define IAgentCommand_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentCommand_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentCommand_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCommand_SetConfidenceThreshold(This,lThreshold)	\
    (This)->lpVtbl -> SetConfidenceThreshold(This,lThreshold)

#define IAgentCommand_GetConfidenceThreshold(This,plThreshold)	\
    (This)->lpVtbl -> GetConfidenceThreshold(This,plThreshold)

#define IAgentCommand_SetConfidenceText(This,bszTipText)	\
    (This)->lpVtbl -> SetConfidenceText(This,bszTipText)

#define IAgentCommand_GetConfidenceText(This,pbszTipText)	\
    (This)->lpVtbl -> GetConfidenceText(This,pbszTipText)

#define IAgentCommand_GetID(This,pdwID)	\
    (This)->lpVtbl -> GetID(This,pdwID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCommand_SetCaption_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ BSTR bszCaption);


void __RPC_STUB IAgentCommand_SetCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetCaption_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszCaption);


void __RPC_STUB IAgentCommand_GetCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_SetVoice_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ BSTR bszVoice);


void __RPC_STUB IAgentCommand_SetVoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetVoice_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszVoice);


void __RPC_STUB IAgentCommand_GetVoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_SetEnabled_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ long bEnabled);


void __RPC_STUB IAgentCommand_SetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetEnabled_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbEnabled);


void __RPC_STUB IAgentCommand_GetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_SetVisible_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentCommand_SetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetVisible_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentCommand_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_SetConfidenceThreshold_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ long lThreshold);


void __RPC_STUB IAgentCommand_SetConfidenceThreshold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetConfidenceThreshold_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plThreshold);


void __RPC_STUB IAgentCommand_GetConfidenceThreshold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_SetConfidenceText_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ BSTR bszTipText);


void __RPC_STUB IAgentCommand_SetConfidenceText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetConfidenceText_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszTipText);


void __RPC_STUB IAgentCommand_GetConfidenceText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetID_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommand_GetID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCommand_INTERFACE_DEFINED__ */


#ifndef __IAgentCommandEx_INTERFACE_DEFINED__
#define __IAgentCommandEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCommandEx
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCommandEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("B0913412-3B44-11d1-ACBA-00C04FD97575")
    IAgentCommandEx : public IAgentCommand
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetHelpContextID( 
            /* [in] */ long ulID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpContextID( 
            /* [out] */ long __RPC_FAR *pulID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoiceCaption( 
            /* [in] */ BSTR bszVoiceCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoiceCaption( 
            /* [out] */ BSTR __RPC_FAR *pbszVoiceCaption) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCommandExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCommandEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCommandEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaption )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoice )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ BSTR bszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoice )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ long bEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConfidenceThreshold )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ long lThreshold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConfidenceThreshold )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plThreshold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConfidenceText )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ BSTR bszTipText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConfidenceText )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszTipText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpContextID )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ long ulID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpContextID )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pulID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoiceCaption )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ BSTR bszVoiceCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoiceCaption )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszVoiceCaption);
        
        END_INTERFACE
    } IAgentCommandExVtbl;

    interface IAgentCommandEx
    {
        CONST_VTBL struct IAgentCommandExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCommandEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCommandEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCommandEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCommandEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCommandEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCommandEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCommandEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCommandEx_SetCaption(This,bszCaption)	\
    (This)->lpVtbl -> SetCaption(This,bszCaption)

#define IAgentCommandEx_GetCaption(This,pbszCaption)	\
    (This)->lpVtbl -> GetCaption(This,pbszCaption)

#define IAgentCommandEx_SetVoice(This,bszVoice)	\
    (This)->lpVtbl -> SetVoice(This,bszVoice)

#define IAgentCommandEx_GetVoice(This,pbszVoice)	\
    (This)->lpVtbl -> GetVoice(This,pbszVoice)

#define IAgentCommandEx_SetEnabled(This,bEnabled)	\
    (This)->lpVtbl -> SetEnabled(This,bEnabled)

#define IAgentCommandEx_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentCommandEx_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentCommandEx_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCommandEx_SetConfidenceThreshold(This,lThreshold)	\
    (This)->lpVtbl -> SetConfidenceThreshold(This,lThreshold)

#define IAgentCommandEx_GetConfidenceThreshold(This,plThreshold)	\
    (This)->lpVtbl -> GetConfidenceThreshold(This,plThreshold)

#define IAgentCommandEx_SetConfidenceText(This,bszTipText)	\
    (This)->lpVtbl -> SetConfidenceText(This,bszTipText)

#define IAgentCommandEx_GetConfidenceText(This,pbszTipText)	\
    (This)->lpVtbl -> GetConfidenceText(This,pbszTipText)

#define IAgentCommandEx_GetID(This,pdwID)	\
    (This)->lpVtbl -> GetID(This,pdwID)


#define IAgentCommandEx_SetHelpContextID(This,ulID)	\
    (This)->lpVtbl -> SetHelpContextID(This,ulID)

#define IAgentCommandEx_GetHelpContextID(This,pulID)	\
    (This)->lpVtbl -> GetHelpContextID(This,pulID)

#define IAgentCommandEx_SetVoiceCaption(This,bszVoiceCaption)	\
    (This)->lpVtbl -> SetVoiceCaption(This,bszVoiceCaption)

#define IAgentCommandEx_GetVoiceCaption(This,pbszVoiceCaption)	\
    (This)->lpVtbl -> GetVoiceCaption(This,pbszVoiceCaption)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCommandEx_SetHelpContextID_Proxy( 
    IAgentCommandEx __RPC_FAR * This,
    /* [in] */ long ulID);


void __RPC_STUB IAgentCommandEx_SetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandEx_GetHelpContextID_Proxy( 
    IAgentCommandEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pulID);


void __RPC_STUB IAgentCommandEx_GetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandEx_SetVoiceCaption_Proxy( 
    IAgentCommandEx __RPC_FAR * This,
    /* [in] */ BSTR bszVoiceCaption);


void __RPC_STUB IAgentCommandEx_SetVoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandEx_GetVoiceCaption_Proxy( 
    IAgentCommandEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszVoiceCaption);


void __RPC_STUB IAgentCommandEx_GetVoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCommandEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCommands_INTERFACE_DEFINED__
#define __IAgentCommands_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCommands
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCommands;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("A7B93C85-7B81-11D0-AC5F-00C04FD97575")
    IAgentCommands : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCommand( 
            /* [in] */ long dwCommandID,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkCommand) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ long __RPC_FAR *pdwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCaption( 
            /* [in] */ BSTR bszCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCaption( 
            /* [out] */ BSTR __RPC_FAR *pbszCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoice( 
            /* [in] */ BSTR bszVoice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoice( 
            /* [out] */ BSTR __RPC_FAR *pbszVoice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVisible( 
            /* [in] */ long bVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long dwRefID,
            /* [in] */ long bBefore,
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ long dwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCommandsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCommands __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCommands __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCommands __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommand )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ long dwCommandID,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkCommand);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IAgentCommands __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ BSTR bszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaption )( 
            IAgentCommands __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoice )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ BSTR bszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoice )( 
            IAgentCommands __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCommands __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long dwRefID,
            /* [in] */ long bBefore,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ long dwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll )( 
            IAgentCommands __RPC_FAR * This);
        
        END_INTERFACE
    } IAgentCommandsVtbl;

    interface IAgentCommands
    {
        CONST_VTBL struct IAgentCommandsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCommands_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCommands_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCommands_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCommands_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCommands_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCommands_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCommands_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCommands_GetCommand(This,dwCommandID,ppunkCommand)	\
    (This)->lpVtbl -> GetCommand(This,dwCommandID,ppunkCommand)

#define IAgentCommands_GetCount(This,pdwCount)	\
    (This)->lpVtbl -> GetCount(This,pdwCount)

#define IAgentCommands_SetCaption(This,bszCaption)	\
    (This)->lpVtbl -> SetCaption(This,bszCaption)

#define IAgentCommands_GetCaption(This,pbszCaption)	\
    (This)->lpVtbl -> GetCaption(This,pbszCaption)

#define IAgentCommands_SetVoice(This,bszVoice)	\
    (This)->lpVtbl -> SetVoice(This,bszVoice)

#define IAgentCommands_GetVoice(This,pbszVoice)	\
    (This)->lpVtbl -> GetVoice(This,pbszVoice)

#define IAgentCommands_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentCommands_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCommands_Add(This,bszCaption,bszVoice,bEnabled,bVisible,pdwID)	\
    (This)->lpVtbl -> Add(This,bszCaption,bszVoice,bEnabled,bVisible,pdwID)

#define IAgentCommands_Insert(This,bszCaption,bszVoice,bEnabled,bVisible,dwRefID,bBefore,pdwID)	\
    (This)->lpVtbl -> Insert(This,bszCaption,bszVoice,bEnabled,bVisible,dwRefID,bBefore,pdwID)

#define IAgentCommands_Remove(This,dwID)	\
    (This)->lpVtbl -> Remove(This,dwID)

#define IAgentCommands_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCommands_GetCommand_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ long dwCommandID,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkCommand);


void __RPC_STUB IAgentCommands_GetCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_GetCount_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwCount);


void __RPC_STUB IAgentCommands_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_SetCaption_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ BSTR bszCaption);


void __RPC_STUB IAgentCommands_SetCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_GetCaption_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszCaption);


void __RPC_STUB IAgentCommands_GetCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_SetVoice_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ BSTR bszVoice);


void __RPC_STUB IAgentCommands_SetVoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_GetVoice_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszVoice);


void __RPC_STUB IAgentCommands_GetVoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_SetVisible_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentCommands_SetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_GetVisible_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentCommands_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_Add_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ BSTR bszCaption,
    /* [in] */ BSTR bszVoice,
    /* [in] */ long bEnabled,
    /* [in] */ long bVisible,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommands_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_Insert_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ BSTR bszCaption,
    /* [in] */ BSTR bszVoice,
    /* [in] */ long bEnabled,
    /* [in] */ long bVisible,
    /* [in] */ long dwRefID,
    /* [in] */ long bBefore,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommands_Insert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_Remove_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ long dwID);


void __RPC_STUB IAgentCommands_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_RemoveAll_Proxy( 
    IAgentCommands __RPC_FAR * This);


void __RPC_STUB IAgentCommands_RemoveAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCommands_INTERFACE_DEFINED__ */


#ifndef __IAgentCommandsEx_INTERFACE_DEFINED__
#define __IAgentCommandsEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCommandsEx
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCommandsEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("6BA90C00-3910-11d1-ACB3-00C04FD97575")
    IAgentCommandsEx : public IAgentCommands
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCommandEx( 
            /* [in] */ long dwCommandID,
            /* [out] */ IAgentCommandEx __RPC_FAR *__RPC_FAR *ppCommandEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultID( 
            /* [in] */ long dwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultID( 
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHelpContextID( 
            /* [in] */ long ulHelpID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpContextID( 
            /* [out] */ long __RPC_FAR *pulHelpID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFontName( 
            /* [in] */ BSTR bszFontName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontName( 
            /* [out] */ BSTR __RPC_FAR *pbszFontName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFontSize( 
            /* [in] */ long lFontSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontSize( 
            /* [out] */ long __RPC_FAR *lFontSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoiceCaption( 
            /* [in] */ BSTR bszVoiceCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoiceCaption( 
            /* [out] */ BSTR __RPC_FAR *bszVoiceCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddEx( 
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ BSTR bszVoiceCaption,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long ulHelpId,
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertEx( 
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ BSTR bszVoiceCaption,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long ulHelpId,
            /* [in] */ long dwRefID,
            /* [in] */ long bBefore,
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGlobalVoiceCommandsEnabled( 
            /* [in] */ long bEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGlobalVoiceCommandsEnabled( 
            /* [out] */ long __RPC_FAR *pbEnabled) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCommandsExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCommandsEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCommandsEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommand )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long dwCommandID,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkCommand);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaption )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoice )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoice )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long dwRefID,
            /* [in] */ long bBefore,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long dwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll )( 
            IAgentCommandsEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommandEx )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long dwCommandID,
            /* [out] */ IAgentCommandEx __RPC_FAR *__RPC_FAR *ppCommandEx);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultID )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long dwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultID )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpContextID )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long ulHelpID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpContextID )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pulHelpID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontName )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontName )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontSize )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long lFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontSize )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *lFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoiceCaption )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszVoiceCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoiceCaption )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *bszVoiceCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddEx )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ BSTR bszVoiceCaption,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long ulHelpId,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertEx )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ BSTR bszVoiceCaption,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long ulHelpId,
            /* [in] */ long dwRefID,
            /* [in] */ long bBefore,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGlobalVoiceCommandsEnabled )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long bEnable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGlobalVoiceCommandsEnabled )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        END_INTERFACE
    } IAgentCommandsExVtbl;

    interface IAgentCommandsEx
    {
        CONST_VTBL struct IAgentCommandsExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCommandsEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCommandsEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCommandsEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCommandsEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCommandsEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCommandsEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCommandsEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCommandsEx_GetCommand(This,dwCommandID,ppunkCommand)	\
    (This)->lpVtbl -> GetCommand(This,dwCommandID,ppunkCommand)

#define IAgentCommandsEx_GetCount(This,pdwCount)	\
    (This)->lpVtbl -> GetCount(This,pdwCount)

#define IAgentCommandsEx_SetCaption(This,bszCaption)	\
    (This)->lpVtbl -> SetCaption(This,bszCaption)

#define IAgentCommandsEx_GetCaption(This,pbszCaption)	\
    (This)->lpVtbl -> GetCaption(This,pbszCaption)

#define IAgentCommandsEx_SetVoice(This,bszVoice)	\
    (This)->lpVtbl -> SetVoice(This,bszVoice)

#define IAgentCommandsEx_GetVoice(This,pbszVoice)	\
    (This)->lpVtbl -> GetVoice(This,pbszVoice)

#define IAgentCommandsEx_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentCommandsEx_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCommandsEx_Add(This,bszCaption,bszVoice,bEnabled,bVisible,pdwID)	\
    (This)->lpVtbl -> Add(This,bszCaption,bszVoice,bEnabled,bVisible,pdwID)

#define IAgentCommandsEx_Insert(This,bszCaption,bszVoice,bEnabled,bVisible,dwRefID,bBefore,pdwID)	\
    (This)->lpVtbl -> Insert(This,bszCaption,bszVoice,bEnabled,bVisible,dwRefID,bBefore,pdwID)

#define IAgentCommandsEx_Remove(This,dwID)	\
    (This)->lpVtbl -> Remove(This,dwID)

#define IAgentCommandsEx_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)


#define IAgentCommandsEx_GetCommandEx(This,dwCommandID,ppCommandEx)	\
    (This)->lpVtbl -> GetCommandEx(This,dwCommandID,ppCommandEx)

#define IAgentCommandsEx_SetDefaultID(This,dwID)	\
    (This)->lpVtbl -> SetDefaultID(This,dwID)

#define IAgentCommandsEx_GetDefaultID(This,pdwID)	\
    (This)->lpVtbl -> GetDefaultID(This,pdwID)

#define IAgentCommandsEx_SetHelpContextID(This,ulHelpID)	\
    (This)->lpVtbl -> SetHelpContextID(This,ulHelpID)

#define IAgentCommandsEx_GetHelpContextID(This,pulHelpID)	\
    (This)->lpVtbl -> GetHelpContextID(This,pulHelpID)

#define IAgentCommandsEx_SetFontName(This,bszFontName)	\
    (This)->lpVtbl -> SetFontName(This,bszFontName)

#define IAgentCommandsEx_GetFontName(This,pbszFontName)	\
    (This)->lpVtbl -> GetFontName(This,pbszFontName)

#define IAgentCommandsEx_SetFontSize(This,lFontSize)	\
    (This)->lpVtbl -> SetFontSize(This,lFontSize)

#define IAgentCommandsEx_GetFontSize(This,lFontSize)	\
    (This)->lpVtbl -> GetFontSize(This,lFontSize)

#define IAgentCommandsEx_SetVoiceCaption(This,bszVoiceCaption)	\
    (This)->lpVtbl -> SetVoiceCaption(This,bszVoiceCaption)

#define IAgentCommandsEx_GetVoiceCaption(This,bszVoiceCaption)	\
    (This)->lpVtbl -> GetVoiceCaption(This,bszVoiceCaption)

#define IAgentCommandsEx_AddEx(This,bszCaption,bszVoice,bszVoiceCaption,bEnabled,bVisible,ulHelpId,pdwID)	\
    (This)->lpVtbl -> AddEx(This,bszCaption,bszVoice,bszVoiceCaption,bEnabled,bVisible,ulHelpId,pdwID)

#define IAgentCommandsEx_InsertEx(This,bszCaption,bszVoice,bszVoiceCaption,bEnabled,bVisible,ulHelpId,dwRefID,bBefore,pdwID)	\
    (This)->lpVtbl -> InsertEx(This,bszCaption,bszVoice,bszVoiceCaption,bEnabled,bVisible,ulHelpId,dwRefID,bBefore,pdwID)

#define IAgentCommandsEx_SetGlobalVoiceCommandsEnabled(This,bEnable)	\
    (This)->lpVtbl -> SetGlobalVoiceCommandsEnabled(This,bEnable)

#define IAgentCommandsEx_GetGlobalVoiceCommandsEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetGlobalVoiceCommandsEnabled(This,pbEnabled)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetCommandEx_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ long dwCommandID,
    /* [out] */ IAgentCommandEx __RPC_FAR *__RPC_FAR *ppCommandEx);


void __RPC_STUB IAgentCommandsEx_GetCommandEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetDefaultID_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ long dwID);


void __RPC_STUB IAgentCommandsEx_SetDefaultID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetDefaultID_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommandsEx_GetDefaultID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetHelpContextID_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ long ulHelpID);


void __RPC_STUB IAgentCommandsEx_SetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetHelpContextID_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pulHelpID);


void __RPC_STUB IAgentCommandsEx_GetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetFontName_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR bszFontName);


void __RPC_STUB IAgentCommandsEx_SetFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetFontName_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszFontName);


void __RPC_STUB IAgentCommandsEx_GetFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetFontSize_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ long lFontSize);


void __RPC_STUB IAgentCommandsEx_SetFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetFontSize_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *lFontSize);


void __RPC_STUB IAgentCommandsEx_GetFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetVoiceCaption_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR bszVoiceCaption);


void __RPC_STUB IAgentCommandsEx_SetVoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetVoiceCaption_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *bszVoiceCaption);


void __RPC_STUB IAgentCommandsEx_GetVoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_AddEx_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR bszCaption,
    /* [in] */ BSTR bszVoice,
    /* [in] */ BSTR bszVoiceCaption,
    /* [in] */ long bEnabled,
    /* [in] */ long bVisible,
    /* [in] */ long ulHelpId,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommandsEx_AddEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_InsertEx_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR bszCaption,
    /* [in] */ BSTR bszVoice,
    /* [in] */ BSTR bszVoiceCaption,
    /* [in] */ long bEnabled,
    /* [in] */ long bVisible,
    /* [in] */ long ulHelpId,
    /* [in] */ long dwRefID,
    /* [in] */ long bBefore,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommandsEx_InsertEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetGlobalVoiceCommandsEnabled_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ long bEnable);


void __RPC_STUB IAgentCommandsEx_SetGlobalVoiceCommandsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetGlobalVoiceCommandsEnabled_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbEnabled);


void __RPC_STUB IAgentCommandsEx_GetGlobalVoiceCommandsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCommandsEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCommandWindow_INTERFACE_DEFINED__
#define __IAgentCommandWindow_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCommandWindow
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCommandWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("6D0ECB23-9968-11D0-AC6E-00C04FD97575")
    IAgentCommandWindow : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetVisible( 
            /* [in] */ long bVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPosition( 
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCommandWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCommandWindow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCommandWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPosition )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight);
        
        END_INTERFACE
    } IAgentCommandWindowVtbl;

    interface IAgentCommandWindow
    {
        CONST_VTBL struct IAgentCommandWindowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCommandWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCommandWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCommandWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCommandWindow_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCommandWindow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCommandWindow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCommandWindow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCommandWindow_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentCommandWindow_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCommandWindow_GetPosition(This,plLeft,plTop)	\
    (This)->lpVtbl -> GetPosition(This,plLeft,plTop)

#define IAgentCommandWindow_GetSize(This,plWidth,plHeight)	\
    (This)->lpVtbl -> GetSize(This,plWidth,plHeight)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCommandWindow_SetVisible_Proxy( 
    IAgentCommandWindow __RPC_FAR * This,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentCommandWindow_SetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandWindow_GetVisible_Proxy( 
    IAgentCommandWindow __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentCommandWindow_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandWindow_GetPosition_Proxy( 
    IAgentCommandWindow __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plLeft,
    /* [out] */ long __RPC_FAR *plTop);


void __RPC_STUB IAgentCommandWindow_GetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandWindow_GetSize_Proxy( 
    IAgentCommandWindow __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plWidth,
    /* [out] */ long __RPC_FAR *plHeight);


void __RPC_STUB IAgentCommandWindow_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCommandWindow_INTERFACE_DEFINED__ */


#ifndef __IAgentSpeechInputProperties_INTERFACE_DEFINED__
#define __IAgentSpeechInputProperties_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentSpeechInputProperties
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentSpeechInputProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("A7B93C87-7B81-11D0-AC5F-00C04FD97575")
    IAgentSpeechInputProperties : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInstalled( 
            /* [out] */ long __RPC_FAR *pbInstalled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnabled( 
            /* [out] */ long __RPC_FAR *pbEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHotKey( 
            /* [out] */ BSTR __RPC_FAR *pbszHotCharKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLCID( 
            /* [out] */ LCID __RPC_FAR *plcidCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEngine( 
            /* [out] */ BSTR __RPC_FAR *pbszEngine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEngine( 
            /* [in] */ BSTR bszEngine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetListeningTip( 
            /* [out] */ long __RPC_FAR *pbListeningTip) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentSpeechInputPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentSpeechInputProperties __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentSpeechInputProperties __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInstalled )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbInstalled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHotKey )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszHotCharKey);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLCID )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ LCID __RPC_FAR *plcidCurrent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEngine )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszEngine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEngine )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [in] */ BSTR bszEngine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetListeningTip )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbListeningTip);
        
        END_INTERFACE
    } IAgentSpeechInputPropertiesVtbl;

    interface IAgentSpeechInputProperties
    {
        CONST_VTBL struct IAgentSpeechInputPropertiesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentSpeechInputProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentSpeechInputProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentSpeechInputProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentSpeechInputProperties_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentSpeechInputProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentSpeechInputProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentSpeechInputProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentSpeechInputProperties_GetInstalled(This,pbInstalled)	\
    (This)->lpVtbl -> GetInstalled(This,pbInstalled)

#define IAgentSpeechInputProperties_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentSpeechInputProperties_GetHotKey(This,pbszHotCharKey)	\
    (This)->lpVtbl -> GetHotKey(This,pbszHotCharKey)

#define IAgentSpeechInputProperties_GetLCID(This,plcidCurrent)	\
    (This)->lpVtbl -> GetLCID(This,plcidCurrent)

#define IAgentSpeechInputProperties_GetEngine(This,pbszEngine)	\
    (This)->lpVtbl -> GetEngine(This,pbszEngine)

#define IAgentSpeechInputProperties_SetEngine(This,bszEngine)	\
    (This)->lpVtbl -> SetEngine(This,bszEngine)

#define IAgentSpeechInputProperties_GetListeningTip(This,pbListeningTip)	\
    (This)->lpVtbl -> GetListeningTip(This,pbListeningTip)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetInstalled_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbInstalled);


void __RPC_STUB IAgentSpeechInputProperties_GetInstalled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetEnabled_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbEnabled);


void __RPC_STUB IAgentSpeechInputProperties_GetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetHotKey_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszHotCharKey);


void __RPC_STUB IAgentSpeechInputProperties_GetHotKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetLCID_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ LCID __RPC_FAR *plcidCurrent);


void __RPC_STUB IAgentSpeechInputProperties_GetLCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetEngine_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszEngine);


void __RPC_STUB IAgentSpeechInputProperties_GetEngine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_SetEngine_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [in] */ BSTR bszEngine);


void __RPC_STUB IAgentSpeechInputProperties_SetEngine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetListeningTip_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbListeningTip);


void __RPC_STUB IAgentSpeechInputProperties_GetListeningTip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentSpeechInputProperties_INTERFACE_DEFINED__ */


#ifndef __IAgentAudioOutputProperties_INTERFACE_DEFINED__
#define __IAgentAudioOutputProperties_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentAudioOutputProperties
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentAudioOutputProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("A7B93C89-7B81-11D0-AC5F-00C04FD97575")
    IAgentAudioOutputProperties : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEnabled( 
            /* [out] */ long __RPC_FAR *pbEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUsingSoundEffects( 
            /* [out] */ long __RPC_FAR *pbUsingSoundEffects) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentAudioOutputPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentAudioOutputProperties __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentAudioOutputProperties __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUsingSoundEffects )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbUsingSoundEffects);
        
        END_INTERFACE
    } IAgentAudioOutputPropertiesVtbl;

    interface IAgentAudioOutputProperties
    {
        CONST_VTBL struct IAgentAudioOutputPropertiesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentAudioOutputProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentAudioOutputProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentAudioOutputProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentAudioOutputProperties_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentAudioOutputProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentAudioOutputProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentAudioOutputProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentAudioOutputProperties_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentAudioOutputProperties_GetUsingSoundEffects(This,pbUsingSoundEffects)	\
    (This)->lpVtbl -> GetUsingSoundEffects(This,pbUsingSoundEffects)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentAudioOutputProperties_GetEnabled_Proxy( 
    IAgentAudioOutputProperties __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbEnabled);


void __RPC_STUB IAgentAudioOutputProperties_GetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentAudioOutputProperties_GetUsingSoundEffects_Proxy( 
    IAgentAudioOutputProperties __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbUsingSoundEffects);


void __RPC_STUB IAgentAudioOutputProperties_GetUsingSoundEffects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentAudioOutputProperties_INTERFACE_DEFINED__ */


#ifndef __IAgentAudioOutputPropertiesEx_INTERFACE_DEFINED__
#define __IAgentAudioOutputPropertiesEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentAudioOutputPropertiesEx
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentAudioOutputPropertiesEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("A7B93CA0-7B81-11D0-AC5F-00C04FD97575")
    IAgentAudioOutputPropertiesEx : public IAgentAudioOutputProperties
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ long __RPC_FAR *plStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentAudioOutputPropertiesExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUsingSoundEffects )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbUsingSoundEffects);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStatus )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plStatus);
        
        END_INTERFACE
    } IAgentAudioOutputPropertiesExVtbl;

    interface IAgentAudioOutputPropertiesEx
    {
        CONST_VTBL struct IAgentAudioOutputPropertiesExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentAudioOutputPropertiesEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentAudioOutputPropertiesEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentAudioOutputPropertiesEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentAudioOutputPropertiesEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentAudioOutputPropertiesEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentAudioOutputPropertiesEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentAudioOutputPropertiesEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentAudioOutputPropertiesEx_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentAudioOutputPropertiesEx_GetUsingSoundEffects(This,pbUsingSoundEffects)	\
    (This)->lpVtbl -> GetUsingSoundEffects(This,pbUsingSoundEffects)


#define IAgentAudioOutputPropertiesEx_GetStatus(This,plStatus)	\
    (This)->lpVtbl -> GetStatus(This,plStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentAudioOutputPropertiesEx_GetStatus_Proxy( 
    IAgentAudioOutputPropertiesEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plStatus);


void __RPC_STUB IAgentAudioOutputPropertiesEx_GetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentAudioOutputPropertiesEx_INTERFACE_DEFINED__ */


#ifndef __IAgentPropertySheet_INTERFACE_DEFINED__
#define __IAgentPropertySheet_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentPropertySheet
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentPropertySheet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("A7B93C8B-7B81-11D0-AC5F-00C04FD97575")
    IAgentPropertySheet : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVisible( 
            /* [in] */ long bVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPosition( 
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPage( 
            /* [out] */ BSTR __RPC_FAR *pbszPage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPage( 
            /* [in] */ BSTR bszPage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentPropertySheetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentPropertySheet __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentPropertySheet __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPosition )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPage )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszPage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPage )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ BSTR bszPage);
        
        END_INTERFACE
    } IAgentPropertySheetVtbl;

    interface IAgentPropertySheet
    {
        CONST_VTBL struct IAgentPropertySheetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentPropertySheet_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentPropertySheet_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentPropertySheet_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentPropertySheet_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentPropertySheet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentPropertySheet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentPropertySheet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentPropertySheet_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentPropertySheet_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentPropertySheet_GetPosition(This,plLeft,plTop)	\
    (This)->lpVtbl -> GetPosition(This,plLeft,plTop)

#define IAgentPropertySheet_GetSize(This,plWidth,plHeight)	\
    (This)->lpVtbl -> GetSize(This,plWidth,plHeight)

#define IAgentPropertySheet_GetPage(This,pbszPage)	\
    (This)->lpVtbl -> GetPage(This,pbszPage)

#define IAgentPropertySheet_SetPage(This,bszPage)	\
    (This)->lpVtbl -> SetPage(This,bszPage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentPropertySheet_GetVisible_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentPropertySheet_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPropertySheet_SetVisible_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentPropertySheet_SetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPropertySheet_GetPosition_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plLeft,
    /* [out] */ long __RPC_FAR *plTop);


void __RPC_STUB IAgentPropertySheet_GetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPropertySheet_GetSize_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plWidth,
    /* [out] */ long __RPC_FAR *plHeight);


void __RPC_STUB IAgentPropertySheet_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPropertySheet_GetPage_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszPage);


void __RPC_STUB IAgentPropertySheet_GetPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPropertySheet_SetPage_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [in] */ BSTR bszPage);


void __RPC_STUB IAgentPropertySheet_SetPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentPropertySheet_INTERFACE_DEFINED__ */


#ifndef __IAgentBalloon_INTERFACE_DEFINED__
#define __IAgentBalloon_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentBalloon
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentBalloon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("A7B93C8D-7B81-11D0-AC5F-00C04FD97575")
    IAgentBalloon : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEnabled( 
            /* [out] */ long __RPC_FAR *pbEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumLines( 
            /* [out] */ long __RPC_FAR *plLines) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumCharsPerLine( 
            /* [out] */ long __RPC_FAR *plCharsPerLine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontName( 
            /* [out] */ BSTR __RPC_FAR *pbszFontName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontSize( 
            /* [out] */ long __RPC_FAR *plFontSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontBold( 
            /* [out] */ long __RPC_FAR *pbFontBold) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontItalic( 
            /* [out] */ long __RPC_FAR *pbFontItalic) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontStrikethru( 
            /* [out] */ long __RPC_FAR *pbFontStrikethru) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontUnderline( 
            /* [out] */ long __RPC_FAR *pbFontUnderline) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetForeColor( 
            /* [out] */ long __RPC_FAR *plFGColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBackColor( 
            /* [out] */ long __RPC_FAR *plBGColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBorderColor( 
            /* [out] */ long __RPC_FAR *plBorderColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVisible( 
            /* [in] */ long bVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFontName( 
            /* [in] */ BSTR bszFontName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFontSize( 
            /* [in] */ long lFontSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFontCharSet( 
            /* [in] */ short sFontCharSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontCharSet( 
            /* [out] */ short __RPC_FAR *psFontCharSet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentBalloonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentBalloon __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentBalloon __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumLines )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLines);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumCharsPerLine )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plCharsPerLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontName )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontSize )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontBold )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontBold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontItalic )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontItalic);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontStrikethru )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontStrikethru);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontUnderline )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontUnderline);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetForeColor )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plFGColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBackColor )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plBGColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBorderColor )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plBorderColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontName )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ BSTR bszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontSize )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ long lFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontCharSet )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ short sFontCharSet);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontCharSet )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *psFontCharSet);
        
        END_INTERFACE
    } IAgentBalloonVtbl;

    interface IAgentBalloon
    {
        CONST_VTBL struct IAgentBalloonVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentBalloon_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentBalloon_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentBalloon_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentBalloon_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentBalloon_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentBalloon_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentBalloon_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentBalloon_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentBalloon_GetNumLines(This,plLines)	\
    (This)->lpVtbl -> GetNumLines(This,plLines)

#define IAgentBalloon_GetNumCharsPerLine(This,plCharsPerLine)	\
    (This)->lpVtbl -> GetNumCharsPerLine(This,plCharsPerLine)

#define IAgentBalloon_GetFontName(This,pbszFontName)	\
    (This)->lpVtbl -> GetFontName(This,pbszFontName)

#define IAgentBalloon_GetFontSize(This,plFontSize)	\
    (This)->lpVtbl -> GetFontSize(This,plFontSize)

#define IAgentBalloon_GetFontBold(This,pbFontBold)	\
    (This)->lpVtbl -> GetFontBold(This,pbFontBold)

#define IAgentBalloon_GetFontItalic(This,pbFontItalic)	\
    (This)->lpVtbl -> GetFontItalic(This,pbFontItalic)

#define IAgentBalloon_GetFontStrikethru(This,pbFontStrikethru)	\
    (This)->lpVtbl -> GetFontStrikethru(This,pbFontStrikethru)

#define IAgentBalloon_GetFontUnderline(This,pbFontUnderline)	\
    (This)->lpVtbl -> GetFontUnderline(This,pbFontUnderline)

#define IAgentBalloon_GetForeColor(This,plFGColor)	\
    (This)->lpVtbl -> GetForeColor(This,plFGColor)

#define IAgentBalloon_GetBackColor(This,plBGColor)	\
    (This)->lpVtbl -> GetBackColor(This,plBGColor)

#define IAgentBalloon_GetBorderColor(This,plBorderColor)	\
    (This)->lpVtbl -> GetBorderColor(This,plBorderColor)

#define IAgentBalloon_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentBalloon_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentBalloon_SetFontName(This,bszFontName)	\
    (This)->lpVtbl -> SetFontName(This,bszFontName)

#define IAgentBalloon_SetFontSize(This,lFontSize)	\
    (This)->lpVtbl -> SetFontSize(This,lFontSize)

#define IAgentBalloon_SetFontCharSet(This,sFontCharSet)	\
    (This)->lpVtbl -> SetFontCharSet(This,sFontCharSet)

#define IAgentBalloon_GetFontCharSet(This,psFontCharSet)	\
    (This)->lpVtbl -> GetFontCharSet(This,psFontCharSet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentBalloon_GetEnabled_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbEnabled);


void __RPC_STUB IAgentBalloon_GetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetNumLines_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plLines);


void __RPC_STUB IAgentBalloon_GetNumLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetNumCharsPerLine_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plCharsPerLine);


void __RPC_STUB IAgentBalloon_GetNumCharsPerLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontName_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszFontName);


void __RPC_STUB IAgentBalloon_GetFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontSize_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plFontSize);


void __RPC_STUB IAgentBalloon_GetFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontBold_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbFontBold);


void __RPC_STUB IAgentBalloon_GetFontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontItalic_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbFontItalic);


void __RPC_STUB IAgentBalloon_GetFontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontStrikethru_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbFontStrikethru);


void __RPC_STUB IAgentBalloon_GetFontStrikethru_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontUnderline_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbFontUnderline);


void __RPC_STUB IAgentBalloon_GetFontUnderline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetForeColor_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plFGColor);


void __RPC_STUB IAgentBalloon_GetForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetBackColor_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plBGColor);


void __RPC_STUB IAgentBalloon_GetBackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetBorderColor_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plBorderColor);


void __RPC_STUB IAgentBalloon_GetBorderColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_SetVisible_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentBalloon_SetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetVisible_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentBalloon_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_SetFontName_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [in] */ BSTR bszFontName);


void __RPC_STUB IAgentBalloon_SetFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_SetFontSize_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [in] */ long lFontSize);


void __RPC_STUB IAgentBalloon_SetFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_SetFontCharSet_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [in] */ short sFontCharSet);


void __RPC_STUB IAgentBalloon_SetFontCharSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontCharSet_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *psFontCharSet);


void __RPC_STUB IAgentBalloon_GetFontCharSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentBalloon_INTERFACE_DEFINED__ */


#ifndef __IAgentBalloonEx_INTERFACE_DEFINED__
#define __IAgentBalloonEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentBalloonEx
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentBalloonEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("D7A6D440-8872-11d1-9EC6-00C04FD7081F")
    IAgentBalloonEx : public IAgentBalloon
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetStyle( 
            /* [in] */ long lStyle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStyle( 
            /* [out] */ long __RPC_FAR *plStyle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNumLines( 
            /* [in] */ long lLines) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNumCharsPerLine( 
            /* [in] */ long lCharsPerLine) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentBalloonExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentBalloonEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentBalloonEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumLines )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLines);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumCharsPerLine )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plCharsPerLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontName )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontSize )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontBold )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontBold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontItalic )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontItalic);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontStrikethru )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontStrikethru);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontUnderline )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontUnderline);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetForeColor )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plFGColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBackColor )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plBGColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBorderColor )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plBorderColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontName )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ BSTR bszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontSize )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ long lFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontCharSet )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ short sFontCharSet);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontCharSet )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *psFontCharSet);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStyle )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ long lStyle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStyle )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plStyle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetNumLines )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ long lLines);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetNumCharsPerLine )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ long lCharsPerLine);
        
        END_INTERFACE
    } IAgentBalloonExVtbl;

    interface IAgentBalloonEx
    {
        CONST_VTBL struct IAgentBalloonExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentBalloonEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentBalloonEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentBalloonEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentBalloonEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentBalloonEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentBalloonEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentBalloonEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentBalloonEx_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentBalloonEx_GetNumLines(This,plLines)	\
    (This)->lpVtbl -> GetNumLines(This,plLines)

#define IAgentBalloonEx_GetNumCharsPerLine(This,plCharsPerLine)	\
    (This)->lpVtbl -> GetNumCharsPerLine(This,plCharsPerLine)

#define IAgentBalloonEx_GetFontName(This,pbszFontName)	\
    (This)->lpVtbl -> GetFontName(This,pbszFontName)

#define IAgentBalloonEx_GetFontSize(This,plFontSize)	\
    (This)->lpVtbl -> GetFontSize(This,plFontSize)

#define IAgentBalloonEx_GetFontBold(This,pbFontBold)	\
    (This)->lpVtbl -> GetFontBold(This,pbFontBold)

#define IAgentBalloonEx_GetFontItalic(This,pbFontItalic)	\
    (This)->lpVtbl -> GetFontItalic(This,pbFontItalic)

#define IAgentBalloonEx_GetFontStrikethru(This,pbFontStrikethru)	\
    (This)->lpVtbl -> GetFontStrikethru(This,pbFontStrikethru)

#define IAgentBalloonEx_GetFontUnderline(This,pbFontUnderline)	\
    (This)->lpVtbl -> GetFontUnderline(This,pbFontUnderline)

#define IAgentBalloonEx_GetForeColor(This,plFGColor)	\
    (This)->lpVtbl -> GetForeColor(This,plFGColor)

#define IAgentBalloonEx_GetBackColor(This,plBGColor)	\
    (This)->lpVtbl -> GetBackColor(This,plBGColor)

#define IAgentBalloonEx_GetBorderColor(This,plBorderColor)	\
    (This)->lpVtbl -> GetBorderColor(This,plBorderColor)

#define IAgentBalloonEx_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentBalloonEx_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentBalloonEx_SetFontName(This,bszFontName)	\
    (This)->lpVtbl -> SetFontName(This,bszFontName)

#define IAgentBalloonEx_SetFontSize(This,lFontSize)	\
    (This)->lpVtbl -> SetFontSize(This,lFontSize)

#define IAgentBalloonEx_SetFontCharSet(This,sFontCharSet)	\
    (This)->lpVtbl -> SetFontCharSet(This,sFontCharSet)

#define IAgentBalloonEx_GetFontCharSet(This,psFontCharSet)	\
    (This)->lpVtbl -> GetFontCharSet(This,psFontCharSet)


#define IAgentBalloonEx_SetStyle(This,lStyle)	\
    (This)->lpVtbl -> SetStyle(This,lStyle)

#define IAgentBalloonEx_GetStyle(This,plStyle)	\
    (This)->lpVtbl -> GetStyle(This,plStyle)

#define IAgentBalloonEx_SetNumLines(This,lLines)	\
    (This)->lpVtbl -> SetNumLines(This,lLines)

#define IAgentBalloonEx_SetNumCharsPerLine(This,lCharsPerLine)	\
    (This)->lpVtbl -> SetNumCharsPerLine(This,lCharsPerLine)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentBalloonEx_SetStyle_Proxy( 
    IAgentBalloonEx __RPC_FAR * This,
    /* [in] */ long lStyle);


void __RPC_STUB IAgentBalloonEx_SetStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloonEx_GetStyle_Proxy( 
    IAgentBalloonEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plStyle);


void __RPC_STUB IAgentBalloonEx_GetStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloonEx_SetNumLines_Proxy( 
    IAgentBalloonEx __RPC_FAR * This,
    /* [in] */ long lLines);


void __RPC_STUB IAgentBalloonEx_SetNumLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloonEx_SetNumCharsPerLine_Proxy( 
    IAgentBalloonEx __RPC_FAR * This,
    /* [in] */ long lCharsPerLine);


void __RPC_STUB IAgentBalloonEx_SetNumCharsPerLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentBalloonEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCharacter_INTERFACE_DEFINED__
#define __IAgentCharacter_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCharacter
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCharacter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("A7B93C8F-7B81-11D0-AC5F-00C04FD97575")
    IAgentCharacter : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPosition( 
            /* [in] */ long lLeft,
            /* [in] */ long lTop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPosition( 
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSize( 
            /* [in] */ long lWidth,
            /* [in] */ long lHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR __RPC_FAR *pbszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ BSTR __RPC_FAR *pbszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTTSSpeed( 
            /* [out] */ long __RPC_FAR *pdwSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTTSPitch( 
            /* [out] */ short __RPC_FAR *pwPitch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Activate( 
            /* [in] */ short sState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIdleOn( 
            /* [in] */ long bOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdleOn( 
            /* [out] */ long __RPC_FAR *pbOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Prepare( 
            /* [in] */ long dwType,
            /* [in] */ BSTR bszName,
            /* [in] */ long bQueue,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Play( 
            /* [in] */ BSTR bszAnimation,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( 
            /* [in] */ long dwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopAll( 
            /* [in] */ long lTypes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Wait( 
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Interrupt( 
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Show( 
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Hide( 
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Speak( 
            /* [in] */ BSTR bszText,
            /* [in] */ BSTR bszUrl,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveTo( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ long lSpeed,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GestureAt( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMoveCause( 
            /* [out] */ long __RPC_FAR *pdwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisibilityCause( 
            /* [out] */ long __RPC_FAR *pdwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HasOtherClients( 
            /* [out] */ long __RPC_FAR *plNumOtherClients) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSoundEffectsOn( 
            /* [in] */ long bOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSoundEffectsOn( 
            /* [out] */ long __RPC_FAR *pbOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ BSTR bszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [in] */ BSTR bszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtraData( 
            /* [out] */ BSTR __RPC_FAR *pbszExtraData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCharacterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCharacter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCharacter __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPosition )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long lLeft,
            /* [in] */ long lTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPosition )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSize )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDescription )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszDescription);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTTSSpeed )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwSpeed);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTTSPitch )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *pwPitch);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Activate )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ short sState);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIdleOn )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIdleOn )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Prepare )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long dwType,
            /* [in] */ BSTR bszName,
            /* [in] */ long bQueue,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ BSTR bszAnimation,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long dwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopAll )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long lTypes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Wait )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Interrupt )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Show )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hide )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Speak )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ BSTR bszText,
            /* [in] */ BSTR bszUrl,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ long lSpeed,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GestureAt )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMoveCause )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisibilityCause )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HasOtherClients )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plNumOtherClients);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSoundEffectsOn )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSoundEffectsOn )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ BSTR bszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDescription )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ BSTR bszDescription);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExtraData )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszExtraData);
        
        END_INTERFACE
    } IAgentCharacterVtbl;

    interface IAgentCharacter
    {
        CONST_VTBL struct IAgentCharacterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCharacter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCharacter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCharacter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCharacter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCharacter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCharacter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCharacter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCharacter_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCharacter_SetPosition(This,lLeft,lTop)	\
    (This)->lpVtbl -> SetPosition(This,lLeft,lTop)

#define IAgentCharacter_GetPosition(This,plLeft,plTop)	\
    (This)->lpVtbl -> GetPosition(This,plLeft,plTop)

#define IAgentCharacter_SetSize(This,lWidth,lHeight)	\
    (This)->lpVtbl -> SetSize(This,lWidth,lHeight)

#define IAgentCharacter_GetSize(This,plWidth,plHeight)	\
    (This)->lpVtbl -> GetSize(This,plWidth,plHeight)

#define IAgentCharacter_GetName(This,pbszName)	\
    (This)->lpVtbl -> GetName(This,pbszName)

#define IAgentCharacter_GetDescription(This,pbszDescription)	\
    (This)->lpVtbl -> GetDescription(This,pbszDescription)

#define IAgentCharacter_GetTTSSpeed(This,pdwSpeed)	\
    (This)->lpVtbl -> GetTTSSpeed(This,pdwSpeed)

#define IAgentCharacter_GetTTSPitch(This,pwPitch)	\
    (This)->lpVtbl -> GetTTSPitch(This,pwPitch)

#define IAgentCharacter_Activate(This,sState)	\
    (This)->lpVtbl -> Activate(This,sState)

#define IAgentCharacter_SetIdleOn(This,bOn)	\
    (This)->lpVtbl -> SetIdleOn(This,bOn)

#define IAgentCharacter_GetIdleOn(This,pbOn)	\
    (This)->lpVtbl -> GetIdleOn(This,pbOn)

#define IAgentCharacter_Prepare(This,dwType,bszName,bQueue,pdwReqID)	\
    (This)->lpVtbl -> Prepare(This,dwType,bszName,bQueue,pdwReqID)

#define IAgentCharacter_Play(This,bszAnimation,pdwReqID)	\
    (This)->lpVtbl -> Play(This,bszAnimation,pdwReqID)

#define IAgentCharacter_Stop(This,dwReqID)	\
    (This)->lpVtbl -> Stop(This,dwReqID)

#define IAgentCharacter_StopAll(This,lTypes)	\
    (This)->lpVtbl -> StopAll(This,lTypes)

#define IAgentCharacter_Wait(This,dwReqID,pdwReqID)	\
    (This)->lpVtbl -> Wait(This,dwReqID,pdwReqID)

#define IAgentCharacter_Interrupt(This,dwReqID,pdwReqID)	\
    (This)->lpVtbl -> Interrupt(This,dwReqID,pdwReqID)

#define IAgentCharacter_Show(This,bFast,pdwReqID)	\
    (This)->lpVtbl -> Show(This,bFast,pdwReqID)

#define IAgentCharacter_Hide(This,bFast,pdwReqID)	\
    (This)->lpVtbl -> Hide(This,bFast,pdwReqID)

#define IAgentCharacter_Speak(This,bszText,bszUrl,pdwReqID)	\
    (This)->lpVtbl -> Speak(This,bszText,bszUrl,pdwReqID)

#define IAgentCharacter_MoveTo(This,x,y,lSpeed,pdwReqID)	\
    (This)->lpVtbl -> MoveTo(This,x,y,lSpeed,pdwReqID)

#define IAgentCharacter_GestureAt(This,x,y,pdwReqID)	\
    (This)->lpVtbl -> GestureAt(This,x,y,pdwReqID)

#define IAgentCharacter_GetMoveCause(This,pdwCause)	\
    (This)->lpVtbl -> GetMoveCause(This,pdwCause)

#define IAgentCharacter_GetVisibilityCause(This,pdwCause)	\
    (This)->lpVtbl -> GetVisibilityCause(This,pdwCause)

#define IAgentCharacter_HasOtherClients(This,plNumOtherClients)	\
    (This)->lpVtbl -> HasOtherClients(This,plNumOtherClients)

#define IAgentCharacter_SetSoundEffectsOn(This,bOn)	\
    (This)->lpVtbl -> SetSoundEffectsOn(This,bOn)

#define IAgentCharacter_GetSoundEffectsOn(This,pbOn)	\
    (This)->lpVtbl -> GetSoundEffectsOn(This,pbOn)

#define IAgentCharacter_SetName(This,bszName)	\
    (This)->lpVtbl -> SetName(This,bszName)

#define IAgentCharacter_SetDescription(This,bszDescription)	\
    (This)->lpVtbl -> SetDescription(This,bszDescription)

#define IAgentCharacter_GetExtraData(This,pbszExtraData)	\
    (This)->lpVtbl -> GetExtraData(This,pbszExtraData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCharacter_GetVisible_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentCharacter_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetPosition_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long lLeft,
    /* [in] */ long lTop);


void __RPC_STUB IAgentCharacter_SetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetPosition_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plLeft,
    /* [out] */ long __RPC_FAR *plTop);


void __RPC_STUB IAgentCharacter_GetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetSize_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long lWidth,
    /* [in] */ long lHeight);


void __RPC_STUB IAgentCharacter_SetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetSize_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plWidth,
    /* [out] */ long __RPC_FAR *plHeight);


void __RPC_STUB IAgentCharacter_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetName_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszName);


void __RPC_STUB IAgentCharacter_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetDescription_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszDescription);


void __RPC_STUB IAgentCharacter_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetTTSSpeed_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwSpeed);


void __RPC_STUB IAgentCharacter_GetTTSSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetTTSPitch_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *pwPitch);


void __RPC_STUB IAgentCharacter_GetTTSPitch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Activate_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ short sState);


void __RPC_STUB IAgentCharacter_Activate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetIdleOn_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long bOn);


void __RPC_STUB IAgentCharacter_SetIdleOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetIdleOn_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbOn);


void __RPC_STUB IAgentCharacter_GetIdleOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Prepare_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long dwType,
    /* [in] */ BSTR bszName,
    /* [in] */ long bQueue,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Prepare_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Play_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ BSTR bszAnimation,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Play_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Stop_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long dwReqID);


void __RPC_STUB IAgentCharacter_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_StopAll_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long lTypes);


void __RPC_STUB IAgentCharacter_StopAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Wait_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long dwReqID,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Wait_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Interrupt_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long dwReqID,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Interrupt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Show_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long bFast,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Show_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Hide_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long bFast,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Hide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Speak_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ BSTR bszText,
    /* [in] */ BSTR bszUrl,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Speak_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_MoveTo_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [in] */ long lSpeed,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_MoveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GestureAt_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_GestureAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetMoveCause_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwCause);


void __RPC_STUB IAgentCharacter_GetMoveCause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetVisibilityCause_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwCause);


void __RPC_STUB IAgentCharacter_GetVisibilityCause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_HasOtherClients_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plNumOtherClients);


void __RPC_STUB IAgentCharacter_HasOtherClients_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetSoundEffectsOn_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long bOn);


void __RPC_STUB IAgentCharacter_SetSoundEffectsOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetSoundEffectsOn_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbOn);


void __RPC_STUB IAgentCharacter_GetSoundEffectsOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetName_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ BSTR bszName);


void __RPC_STUB IAgentCharacter_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetDescription_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ BSTR bszDescription);


void __RPC_STUB IAgentCharacter_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetExtraData_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszExtraData);


void __RPC_STUB IAgentCharacter_GetExtraData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCharacter_INTERFACE_DEFINED__ */


#ifndef __IAgentCharacterEx_INTERFACE_DEFINED__
#define __IAgentCharacterEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCharacterEx
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentCharacterEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("98BBE491-2EED-11d1-ACAC-00C04FD97575")
    IAgentCharacterEx : public IAgentCharacter
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShowPopupMenu( 
            /* [in] */ short x,
            /* [in] */ short y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAutoPopupMenu( 
            /* [in] */ long bAutoPopupMenu) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAutoPopupMenu( 
            /* [out] */ long __RPC_FAR *pbAutoPopupMenu) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpFileName( 
            /* [out] */ BSTR __RPC_FAR *pbszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHelpFileName( 
            /* [in] */ BSTR bszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHelpModeOn( 
            /* [in] */ long bHelpModeOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpModeOn( 
            /* [out] */ long __RPC_FAR *pbHelpModeOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHelpContextID( 
            /* [in] */ long ulID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpContextID( 
            /* [out] */ long __RPC_FAR *pulID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActive( 
            /* [out] */ short __RPC_FAR *psState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Listen( 
            /* [in] */ long bListen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLanguageID( 
            /* [in] */ long langid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLanguageID( 
            /* [out] */ long __RPC_FAR *plangid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTTSModeID( 
            /* [out] */ BSTR __RPC_FAR *pbszModeID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTTSModeID( 
            /* [in] */ BSTR bszModeID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSRModeID( 
            /* [out] */ BSTR __RPC_FAR *pbszModeID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSRModeID( 
            /* [in] */ BSTR bszModeID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGUID( 
            /* [out] */ BSTR __RPC_FAR *pbszID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOriginalSize( 
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Think( 
            /* [in] */ BSTR bszText,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [out] */ short __RPC_FAR *psMajor,
            /* [out] */ short __RPC_FAR *psMinor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAnimationNames( 
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *punkEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSRStatus( 
            /* [out] */ long __RPC_FAR *plStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCharacterExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCharacterEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCharacterEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPosition )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long lLeft,
            /* [in] */ long lTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPosition )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSize )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDescription )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszDescription);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTTSSpeed )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwSpeed);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTTSPitch )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *pwPitch);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Activate )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ short sState);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIdleOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIdleOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Prepare )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long dwType,
            /* [in] */ BSTR bszName,
            /* [in] */ long bQueue,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszAnimation,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long dwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopAll )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long lTypes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Wait )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Interrupt )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Show )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hide )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Speak )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszText,
            /* [in] */ BSTR bszUrl,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ long lSpeed,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GestureAt )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMoveCause )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisibilityCause )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HasOtherClients )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plNumOtherClients);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSoundEffectsOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSoundEffectsOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDescription )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszDescription);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExtraData )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszExtraData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowPopupMenu )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoPopupMenu )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bAutoPopupMenu);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoPopupMenu )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbAutoPopupMenu);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpFileName )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpFileName )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpModeOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bHelpModeOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpModeOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbHelpModeOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpContextID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long ulID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpContextID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pulID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetActive )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *psState);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Listen )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bListen);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLanguageID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long langid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLanguageID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plangid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTTSModeID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszModeID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTTSModeID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszModeID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSRModeID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszModeID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSRModeID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszModeID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGUID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOriginalSize )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Think )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszText,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVersion )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *psMajor,
            /* [out] */ short __RPC_FAR *psMinor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnimationNames )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *punkEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSRStatus )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plStatus);
        
        END_INTERFACE
    } IAgentCharacterExVtbl;

    interface IAgentCharacterEx
    {
        CONST_VTBL struct IAgentCharacterExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCharacterEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCharacterEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCharacterEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCharacterEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCharacterEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCharacterEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCharacterEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCharacterEx_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCharacterEx_SetPosition(This,lLeft,lTop)	\
    (This)->lpVtbl -> SetPosition(This,lLeft,lTop)

#define IAgentCharacterEx_GetPosition(This,plLeft,plTop)	\
    (This)->lpVtbl -> GetPosition(This,plLeft,plTop)

#define IAgentCharacterEx_SetSize(This,lWidth,lHeight)	\
    (This)->lpVtbl -> SetSize(This,lWidth,lHeight)

#define IAgentCharacterEx_GetSize(This,plWidth,plHeight)	\
    (This)->lpVtbl -> GetSize(This,plWidth,plHeight)

#define IAgentCharacterEx_GetName(This,pbszName)	\
    (This)->lpVtbl -> GetName(This,pbszName)

#define IAgentCharacterEx_GetDescription(This,pbszDescription)	\
    (This)->lpVtbl -> GetDescription(This,pbszDescription)

#define IAgentCharacterEx_GetTTSSpeed(This,pdwSpeed)	\
    (This)->lpVtbl -> GetTTSSpeed(This,pdwSpeed)

#define IAgentCharacterEx_GetTTSPitch(This,pwPitch)	\
    (This)->lpVtbl -> GetTTSPitch(This,pwPitch)

#define IAgentCharacterEx_Activate(This,sState)	\
    (This)->lpVtbl -> Activate(This,sState)

#define IAgentCharacterEx_SetIdleOn(This,bOn)	\
    (This)->lpVtbl -> SetIdleOn(This,bOn)

#define IAgentCharacterEx_GetIdleOn(This,pbOn)	\
    (This)->lpVtbl -> GetIdleOn(This,pbOn)

#define IAgentCharacterEx_Prepare(This,dwType,bszName,bQueue,pdwReqID)	\
    (This)->lpVtbl -> Prepare(This,dwType,bszName,bQueue,pdwReqID)

#define IAgentCharacterEx_Play(This,bszAnimation,pdwReqID)	\
    (This)->lpVtbl -> Play(This,bszAnimation,pdwReqID)

#define IAgentCharacterEx_Stop(This,dwReqID)	\
    (This)->lpVtbl -> Stop(This,dwReqID)

#define IAgentCharacterEx_StopAll(This,lTypes)	\
    (This)->lpVtbl -> StopAll(This,lTypes)

#define IAgentCharacterEx_Wait(This,dwReqID,pdwReqID)	\
    (This)->lpVtbl -> Wait(This,dwReqID,pdwReqID)

#define IAgentCharacterEx_Interrupt(This,dwReqID,pdwReqID)	\
    (This)->lpVtbl -> Interrupt(This,dwReqID,pdwReqID)

#define IAgentCharacterEx_Show(This,bFast,pdwReqID)	\
    (This)->lpVtbl -> Show(This,bFast,pdwReqID)

#define IAgentCharacterEx_Hide(This,bFast,pdwReqID)	\
    (This)->lpVtbl -> Hide(This,bFast,pdwReqID)

#define IAgentCharacterEx_Speak(This,bszText,bszUrl,pdwReqID)	\
    (This)->lpVtbl -> Speak(This,bszText,bszUrl,pdwReqID)

#define IAgentCharacterEx_MoveTo(This,x,y,lSpeed,pdwReqID)	\
    (This)->lpVtbl -> MoveTo(This,x,y,lSpeed,pdwReqID)

#define IAgentCharacterEx_GestureAt(This,x,y,pdwReqID)	\
    (This)->lpVtbl -> GestureAt(This,x,y,pdwReqID)

#define IAgentCharacterEx_GetMoveCause(This,pdwCause)	\
    (This)->lpVtbl -> GetMoveCause(This,pdwCause)

#define IAgentCharacterEx_GetVisibilityCause(This,pdwCause)	\
    (This)->lpVtbl -> GetVisibilityCause(This,pdwCause)

#define IAgentCharacterEx_HasOtherClients(This,plNumOtherClients)	\
    (This)->lpVtbl -> HasOtherClients(This,plNumOtherClients)

#define IAgentCharacterEx_SetSoundEffectsOn(This,bOn)	\
    (This)->lpVtbl -> SetSoundEffectsOn(This,bOn)

#define IAgentCharacterEx_GetSoundEffectsOn(This,pbOn)	\
    (This)->lpVtbl -> GetSoundEffectsOn(This,pbOn)

#define IAgentCharacterEx_SetName(This,bszName)	\
    (This)->lpVtbl -> SetName(This,bszName)

#define IAgentCharacterEx_SetDescription(This,bszDescription)	\
    (This)->lpVtbl -> SetDescription(This,bszDescription)

#define IAgentCharacterEx_GetExtraData(This,pbszExtraData)	\
    (This)->lpVtbl -> GetExtraData(This,pbszExtraData)


#define IAgentCharacterEx_ShowPopupMenu(This,x,y)	\
    (This)->lpVtbl -> ShowPopupMenu(This,x,y)

#define IAgentCharacterEx_SetAutoPopupMenu(This,bAutoPopupMenu)	\
    (This)->lpVtbl -> SetAutoPopupMenu(This,bAutoPopupMenu)

#define IAgentCharacterEx_GetAutoPopupMenu(This,pbAutoPopupMenu)	\
    (This)->lpVtbl -> GetAutoPopupMenu(This,pbAutoPopupMenu)

#define IAgentCharacterEx_GetHelpFileName(This,pbszName)	\
    (This)->lpVtbl -> GetHelpFileName(This,pbszName)

#define IAgentCharacterEx_SetHelpFileName(This,bszName)	\
    (This)->lpVtbl -> SetHelpFileName(This,bszName)

#define IAgentCharacterEx_SetHelpModeOn(This,bHelpModeOn)	\
    (This)->lpVtbl -> SetHelpModeOn(This,bHelpModeOn)

#define IAgentCharacterEx_GetHelpModeOn(This,pbHelpModeOn)	\
    (This)->lpVtbl -> GetHelpModeOn(This,pbHelpModeOn)

#define IAgentCharacterEx_SetHelpContextID(This,ulID)	\
    (This)->lpVtbl -> SetHelpContextID(This,ulID)

#define IAgentCharacterEx_GetHelpContextID(This,pulID)	\
    (This)->lpVtbl -> GetHelpContextID(This,pulID)

#define IAgentCharacterEx_GetActive(This,psState)	\
    (This)->lpVtbl -> GetActive(This,psState)

#define IAgentCharacterEx_Listen(This,bListen)	\
    (This)->lpVtbl -> Listen(This,bListen)

#define IAgentCharacterEx_SetLanguageID(This,langid)	\
    (This)->lpVtbl -> SetLanguageID(This,langid)

#define IAgentCharacterEx_GetLanguageID(This,plangid)	\
    (This)->lpVtbl -> GetLanguageID(This,plangid)

#define IAgentCharacterEx_GetTTSModeID(This,pbszModeID)	\
    (This)->lpVtbl -> GetTTSModeID(This,pbszModeID)

#define IAgentCharacterEx_SetTTSModeID(This,bszModeID)	\
    (This)->lpVtbl -> SetTTSModeID(This,bszModeID)

#define IAgentCharacterEx_GetSRModeID(This,pbszModeID)	\
    (This)->lpVtbl -> GetSRModeID(This,pbszModeID)

#define IAgentCharacterEx_SetSRModeID(This,bszModeID)	\
    (This)->lpVtbl -> SetSRModeID(This,bszModeID)

#define IAgentCharacterEx_GetGUID(This,pbszID)	\
    (This)->lpVtbl -> GetGUID(This,pbszID)

#define IAgentCharacterEx_GetOriginalSize(This,plWidth,plHeight)	\
    (This)->lpVtbl -> GetOriginalSize(This,plWidth,plHeight)

#define IAgentCharacterEx_Think(This,bszText,pdwReqID)	\
    (This)->lpVtbl -> Think(This,bszText,pdwReqID)

#define IAgentCharacterEx_GetVersion(This,psMajor,psMinor)	\
    (This)->lpVtbl -> GetVersion(This,psMajor,psMinor)

#define IAgentCharacterEx_GetAnimationNames(This,punkEnum)	\
    (This)->lpVtbl -> GetAnimationNames(This,punkEnum)

#define IAgentCharacterEx_GetSRStatus(This,plStatus)	\
    (This)->lpVtbl -> GetSRStatus(This,plStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCharacterEx_ShowPopupMenu_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y);


void __RPC_STUB IAgentCharacterEx_ShowPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetAutoPopupMenu_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ long bAutoPopupMenu);


void __RPC_STUB IAgentCharacterEx_SetAutoPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetAutoPopupMenu_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbAutoPopupMenu);


void __RPC_STUB IAgentCharacterEx_GetAutoPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetHelpFileName_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszName);


void __RPC_STUB IAgentCharacterEx_GetHelpFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetHelpFileName_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR bszName);


void __RPC_STUB IAgentCharacterEx_SetHelpFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetHelpModeOn_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ long bHelpModeOn);


void __RPC_STUB IAgentCharacterEx_SetHelpModeOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetHelpModeOn_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbHelpModeOn);


void __RPC_STUB IAgentCharacterEx_GetHelpModeOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetHelpContextID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ long ulID);


void __RPC_STUB IAgentCharacterEx_SetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetHelpContextID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pulID);


void __RPC_STUB IAgentCharacterEx_GetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetActive_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *psState);


void __RPC_STUB IAgentCharacterEx_GetActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_Listen_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ long bListen);


void __RPC_STUB IAgentCharacterEx_Listen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetLanguageID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ long langid);


void __RPC_STUB IAgentCharacterEx_SetLanguageID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetLanguageID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plangid);


void __RPC_STUB IAgentCharacterEx_GetLanguageID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetTTSModeID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszModeID);


void __RPC_STUB IAgentCharacterEx_GetTTSModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetTTSModeID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR bszModeID);


void __RPC_STUB IAgentCharacterEx_SetTTSModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetSRModeID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszModeID);


void __RPC_STUB IAgentCharacterEx_GetSRModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetSRModeID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR bszModeID);


void __RPC_STUB IAgentCharacterEx_SetSRModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetGUID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszID);


void __RPC_STUB IAgentCharacterEx_GetGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetOriginalSize_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plWidth,
    /* [out] */ long __RPC_FAR *plHeight);


void __RPC_STUB IAgentCharacterEx_GetOriginalSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_Think_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR bszText,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacterEx_Think_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetVersion_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *psMajor,
    /* [out] */ short __RPC_FAR *psMinor);


void __RPC_STUB IAgentCharacterEx_GetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetAnimationNames_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *punkEnum);


void __RPC_STUB IAgentCharacterEx_GetAnimationNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetSRStatus_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plStatus);


void __RPC_STUB IAgentCharacterEx_GetSRStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCharacterEx_INTERFACE_DEFINED__ */


#ifndef __IAgent_INTERFACE_DEFINED__
#define __IAgent_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgent
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("A7B93C91-7B81-11D0-AC5F-00C04FD97575")
    IAgent : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ VARIANT vLoadKey,
            /* [out] */ long __RPC_FAR *pdwCharID,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unload( 
            /* [in] */ long dwCharID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Register( 
            /* [in] */ IUnknown __RPC_FAR *punkNotifySink,
            /* [out] */ long __RPC_FAR *pdwSinkID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unregister( 
            /* [in] */ long dwSinkID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCharacter( 
            /* [in] */ long dwCharID,
            /* [out] */ IDispatch __RPC_FAR *__RPC_FAR *ppunkCharacter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSuspended( 
            /* [out] */ long __RPC_FAR *pbSuspended) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IAgent __RPC_FAR * This,
            /* [in] */ VARIANT vLoadKey,
            /* [out] */ long __RPC_FAR *pdwCharID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unload )( 
            IAgent __RPC_FAR * This,
            /* [in] */ long dwCharID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Register )( 
            IAgent __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *punkNotifySink,
            /* [out] */ long __RPC_FAR *pdwSinkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unregister )( 
            IAgent __RPC_FAR * This,
            /* [in] */ long dwSinkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCharacter )( 
            IAgent __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [out] */ IDispatch __RPC_FAR *__RPC_FAR *ppunkCharacter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSuspended )( 
            IAgent __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbSuspended);
        
        END_INTERFACE
    } IAgentVtbl;

    interface IAgent
    {
        CONST_VTBL struct IAgentVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgent_Load(This,vLoadKey,pdwCharID,pdwReqID)	\
    (This)->lpVtbl -> Load(This,vLoadKey,pdwCharID,pdwReqID)

#define IAgent_Unload(This,dwCharID)	\
    (This)->lpVtbl -> Unload(This,dwCharID)

#define IAgent_Register(This,punkNotifySink,pdwSinkID)	\
    (This)->lpVtbl -> Register(This,punkNotifySink,pdwSinkID)

#define IAgent_Unregister(This,dwSinkID)	\
    (This)->lpVtbl -> Unregister(This,dwSinkID)

#define IAgent_GetCharacter(This,dwCharID,ppunkCharacter)	\
    (This)->lpVtbl -> GetCharacter(This,dwCharID,ppunkCharacter)

#define IAgent_GetSuspended(This,pbSuspended)	\
    (This)->lpVtbl -> GetSuspended(This,pbSuspended)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgent_Load_Proxy( 
    IAgent __RPC_FAR * This,
    /* [in] */ VARIANT vLoadKey,
    /* [out] */ long __RPC_FAR *pdwCharID,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgent_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgent_Unload_Proxy( 
    IAgent __RPC_FAR * This,
    /* [in] */ long dwCharID);


void __RPC_STUB IAgent_Unload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgent_Register_Proxy( 
    IAgent __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *punkNotifySink,
    /* [out] */ long __RPC_FAR *pdwSinkID);


void __RPC_STUB IAgent_Register_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgent_Unregister_Proxy( 
    IAgent __RPC_FAR * This,
    /* [in] */ long dwSinkID);


void __RPC_STUB IAgent_Unregister_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgent_GetCharacter_Proxy( 
    IAgent __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [out] */ IDispatch __RPC_FAR *__RPC_FAR *ppunkCharacter);


void __RPC_STUB IAgent_GetCharacter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgent_GetSuspended_Proxy( 
    IAgent __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbSuspended);


void __RPC_STUB IAgent_GetSuspended_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgent_INTERFACE_DEFINED__ */


#ifndef __IAgentEx_INTERFACE_DEFINED__
#define __IAgentEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentEx
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("48D12BA0-5B77-11d1-9EC1-00C04FD7081F")
    IAgentEx : public IAgent
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCharacterEx( 
            /* [in] */ long dwCharID,
            /* [out] */ IAgentCharacterEx __RPC_FAR *__RPC_FAR *ppCharacterEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [out] */ short __RPC_FAR *psMajor,
            /* [out] */ short __RPC_FAR *psMinor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowDefaultCharacterProperties( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ long bUseDefaultPosition) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ VARIANT vLoadKey,
            /* [out] */ long __RPC_FAR *pdwCharID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unload )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ long dwCharID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Register )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *punkNotifySink,
            /* [out] */ long __RPC_FAR *pdwSinkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unregister )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ long dwSinkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCharacter )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [out] */ IDispatch __RPC_FAR *__RPC_FAR *ppunkCharacter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSuspended )( 
            IAgentEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbSuspended);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCharacterEx )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [out] */ IAgentCharacterEx __RPC_FAR *__RPC_FAR *ppCharacterEx);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVersion )( 
            IAgentEx __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *psMajor,
            /* [out] */ short __RPC_FAR *psMinor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowDefaultCharacterProperties )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ long bUseDefaultPosition);
        
        END_INTERFACE
    } IAgentExVtbl;

    interface IAgentEx
    {
        CONST_VTBL struct IAgentExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentEx_Load(This,vLoadKey,pdwCharID,pdwReqID)	\
    (This)->lpVtbl -> Load(This,vLoadKey,pdwCharID,pdwReqID)

#define IAgentEx_Unload(This,dwCharID)	\
    (This)->lpVtbl -> Unload(This,dwCharID)

#define IAgentEx_Register(This,punkNotifySink,pdwSinkID)	\
    (This)->lpVtbl -> Register(This,punkNotifySink,pdwSinkID)

#define IAgentEx_Unregister(This,dwSinkID)	\
    (This)->lpVtbl -> Unregister(This,dwSinkID)

#define IAgentEx_GetCharacter(This,dwCharID,ppunkCharacter)	\
    (This)->lpVtbl -> GetCharacter(This,dwCharID,ppunkCharacter)

#define IAgentEx_GetSuspended(This,pbSuspended)	\
    (This)->lpVtbl -> GetSuspended(This,pbSuspended)


#define IAgentEx_GetCharacterEx(This,dwCharID,ppCharacterEx)	\
    (This)->lpVtbl -> GetCharacterEx(This,dwCharID,ppCharacterEx)

#define IAgentEx_GetVersion(This,psMajor,psMinor)	\
    (This)->lpVtbl -> GetVersion(This,psMajor,psMinor)

#define IAgentEx_ShowDefaultCharacterProperties(This,x,y,bUseDefaultPosition)	\
    (This)->lpVtbl -> ShowDefaultCharacterProperties(This,x,y,bUseDefaultPosition)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentEx_GetCharacterEx_Proxy( 
    IAgentEx __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [out] */ IAgentCharacterEx __RPC_FAR *__RPC_FAR *ppCharacterEx);


void __RPC_STUB IAgentEx_GetCharacterEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentEx_GetVersion_Proxy( 
    IAgentEx __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *psMajor,
    /* [out] */ short __RPC_FAR *psMinor);


void __RPC_STUB IAgentEx_GetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentEx_ShowDefaultCharacterProperties_Proxy( 
    IAgentEx __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [in] */ long bUseDefaultPosition);


void __RPC_STUB IAgentEx_ShowDefaultCharacterProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentEx_INTERFACE_DEFINED__ */


#ifndef __IAgentNotifySink_INTERFACE_DEFINED__
#define __IAgentNotifySink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentNotifySink
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentNotifySink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("00D18159-8466-11D0-AC63-00C04FD97575")
    IAgentNotifySink : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Command( 
            /* [in] */ long dwCommandID,
            /* [in] */ IUnknown __RPC_FAR *punkUserInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivateInputState( 
            /* [in] */ long dwCharID,
            /* [in] */ long bActivated) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Restart( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Shutdown( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VisibleState( 
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible,
            /* [in] */ long dwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Click( 
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DblClick( 
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DragStart( 
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DragComplete( 
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestStart( 
            /* [in] */ long dwRequestID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestComplete( 
            /* [in] */ long dwRequestID,
            /* [in] */ long hrStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BookMark( 
            /* [in] */ long dwBookMarkID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Idle( 
            /* [in] */ long dwCharID,
            /* [in] */ long bStart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ long dwCharID,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ long dwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Size( 
            /* [in] */ long dwCharID,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BalloonVisibleState( 
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentNotifySinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentNotifySink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentNotifySink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Command )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCommandID,
            /* [in] */ IUnknown __RPC_FAR *punkUserInput);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateInputState )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bActivated);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Restart )( 
            IAgentNotifySink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Shutdown )( 
            IAgentNotifySink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *VisibleState )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Click )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DblClick )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DragStart )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DragComplete )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestStart )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwRequestID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestComplete )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwRequestID,
            /* [in] */ long hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BookMark )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwBookMarkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Idle )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bStart);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Move )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Size )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BalloonVisibleState )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible);
        
        END_INTERFACE
    } IAgentNotifySinkVtbl;

    interface IAgentNotifySink
    {
        CONST_VTBL struct IAgentNotifySinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentNotifySink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentNotifySink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentNotifySink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentNotifySink_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentNotifySink_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentNotifySink_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentNotifySink_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentNotifySink_Command(This,dwCommandID,punkUserInput)	\
    (This)->lpVtbl -> Command(This,dwCommandID,punkUserInput)

#define IAgentNotifySink_ActivateInputState(This,dwCharID,bActivated)	\
    (This)->lpVtbl -> ActivateInputState(This,dwCharID,bActivated)

#define IAgentNotifySink_Restart(This)	\
    (This)->lpVtbl -> Restart(This)

#define IAgentNotifySink_Shutdown(This)	\
    (This)->lpVtbl -> Shutdown(This)

#define IAgentNotifySink_VisibleState(This,dwCharID,bVisible,dwCause)	\
    (This)->lpVtbl -> VisibleState(This,dwCharID,bVisible,dwCause)

#define IAgentNotifySink_Click(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> Click(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySink_DblClick(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DblClick(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySink_DragStart(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DragStart(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySink_DragComplete(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DragComplete(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySink_RequestStart(This,dwRequestID)	\
    (This)->lpVtbl -> RequestStart(This,dwRequestID)

#define IAgentNotifySink_RequestComplete(This,dwRequestID,hrStatus)	\
    (This)->lpVtbl -> RequestComplete(This,dwRequestID,hrStatus)

#define IAgentNotifySink_BookMark(This,dwBookMarkID)	\
    (This)->lpVtbl -> BookMark(This,dwBookMarkID)

#define IAgentNotifySink_Idle(This,dwCharID,bStart)	\
    (This)->lpVtbl -> Idle(This,dwCharID,bStart)

#define IAgentNotifySink_Move(This,dwCharID,x,y,dwCause)	\
    (This)->lpVtbl -> Move(This,dwCharID,x,y,dwCause)

#define IAgentNotifySink_Size(This,dwCharID,lWidth,lHeight)	\
    (This)->lpVtbl -> Size(This,dwCharID,lWidth,lHeight)

#define IAgentNotifySink_BalloonVisibleState(This,dwCharID,bVisible)	\
    (This)->lpVtbl -> BalloonVisibleState(This,dwCharID,bVisible)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentNotifySink_Command_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCommandID,
    /* [in] */ IUnknown __RPC_FAR *punkUserInput);


void __RPC_STUB IAgentNotifySink_Command_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_ActivateInputState_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long bActivated);


void __RPC_STUB IAgentNotifySink_ActivateInputState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Restart_Proxy( 
    IAgentNotifySink __RPC_FAR * This);


void __RPC_STUB IAgentNotifySink_Restart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Shutdown_Proxy( 
    IAgentNotifySink __RPC_FAR * This);


void __RPC_STUB IAgentNotifySink_Shutdown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_VisibleState_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long bVisible,
    /* [in] */ long dwCause);


void __RPC_STUB IAgentNotifySink_VisibleState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Click_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ short fwKeys,
    /* [in] */ long x,
    /* [in] */ long y);


void __RPC_STUB IAgentNotifySink_Click_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_DblClick_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ short fwKeys,
    /* [in] */ long x,
    /* [in] */ long y);


void __RPC_STUB IAgentNotifySink_DblClick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_DragStart_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ short fwKeys,
    /* [in] */ long x,
    /* [in] */ long y);


void __RPC_STUB IAgentNotifySink_DragStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_DragComplete_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ short fwKeys,
    /* [in] */ long x,
    /* [in] */ long y);


void __RPC_STUB IAgentNotifySink_DragComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_RequestStart_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwRequestID);


void __RPC_STUB IAgentNotifySink_RequestStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_RequestComplete_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwRequestID,
    /* [in] */ long hrStatus);


void __RPC_STUB IAgentNotifySink_RequestComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_BookMark_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwBookMarkID);


void __RPC_STUB IAgentNotifySink_BookMark_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Idle_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long bStart);


void __RPC_STUB IAgentNotifySink_Idle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Move_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long x,
    /* [in] */ long y,
    /* [in] */ long dwCause);


void __RPC_STUB IAgentNotifySink_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Size_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long lWidth,
    /* [in] */ long lHeight);


void __RPC_STUB IAgentNotifySink_Size_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_BalloonVisibleState_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentNotifySink_BalloonVisibleState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentNotifySink_INTERFACE_DEFINED__ */


#ifndef __IAgentNotifySinkEx_INTERFACE_DEFINED__
#define __IAgentNotifySinkEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentNotifySinkEx
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAgentNotifySinkEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("08C75162-3C9C-11d1-91FE-00C04FD701A5")
    IAgentNotifySinkEx : public IAgentNotifySink
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE HelpComplete( 
            /* [in] */ long dwCharID,
            /* [in] */ long dwCommandID,
            /* [in] */ long dwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ListeningState( 
            /* [in] */ long dwCharID,
            /* [in] */ long bListening,
            /* [in] */ long dwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DefaultCharacterChange( 
            /* [in] */ BSTR bszGUID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AgentPropertyChange( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActiveClientChange( 
            /* [in] */ long dwCharID,
            /* [in] */ long lStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentNotifySinkExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentNotifySinkEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentNotifySinkEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Command )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCommandID,
            /* [in] */ IUnknown __RPC_FAR *punkUserInput);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateInputState )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bActivated);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Restart )( 
            IAgentNotifySinkEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Shutdown )( 
            IAgentNotifySinkEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *VisibleState )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Click )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DblClick )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DragStart )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DragComplete )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestStart )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwRequestID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestComplete )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwRequestID,
            /* [in] */ long hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BookMark )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwBookMarkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Idle )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bStart);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Move )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Size )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BalloonVisibleState )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HelpComplete )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long dwCommandID,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ListeningState )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bListening,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DefaultCharacterChange )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ BSTR bszGUID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AgentPropertyChange )( 
            IAgentNotifySinkEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActiveClientChange )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long lStatus);
        
        END_INTERFACE
    } IAgentNotifySinkExVtbl;

    interface IAgentNotifySinkEx
    {
        CONST_VTBL struct IAgentNotifySinkExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentNotifySinkEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentNotifySinkEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentNotifySinkEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentNotifySinkEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentNotifySinkEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentNotifySinkEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentNotifySinkEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentNotifySinkEx_Command(This,dwCommandID,punkUserInput)	\
    (This)->lpVtbl -> Command(This,dwCommandID,punkUserInput)

#define IAgentNotifySinkEx_ActivateInputState(This,dwCharID,bActivated)	\
    (This)->lpVtbl -> ActivateInputState(This,dwCharID,bActivated)

#define IAgentNotifySinkEx_Restart(This)	\
    (This)->lpVtbl -> Restart(This)

#define IAgentNotifySinkEx_Shutdown(This)	\
    (This)->lpVtbl -> Shutdown(This)

#define IAgentNotifySinkEx_VisibleState(This,dwCharID,bVisible,dwCause)	\
    (This)->lpVtbl -> VisibleState(This,dwCharID,bVisible,dwCause)

#define IAgentNotifySinkEx_Click(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> Click(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySinkEx_DblClick(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DblClick(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySinkEx_DragStart(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DragStart(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySinkEx_DragComplete(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DragComplete(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySinkEx_RequestStart(This,dwRequestID)	\
    (This)->lpVtbl -> RequestStart(This,dwRequestID)

#define IAgentNotifySinkEx_RequestComplete(This,dwRequestID,hrStatus)	\
    (This)->lpVtbl -> RequestComplete(This,dwRequestID,hrStatus)

#define IAgentNotifySinkEx_BookMark(This,dwBookMarkID)	\
    (This)->lpVtbl -> BookMark(This,dwBookMarkID)

#define IAgentNotifySinkEx_Idle(This,dwCharID,bStart)	\
    (This)->lpVtbl -> Idle(This,dwCharID,bStart)

#define IAgentNotifySinkEx_Move(This,dwCharID,x,y,dwCause)	\
    (This)->lpVtbl -> Move(This,dwCharID,x,y,dwCause)

#define IAgentNotifySinkEx_Size(This,dwCharID,lWidth,lHeight)	\
    (This)->lpVtbl -> Size(This,dwCharID,lWidth,lHeight)

#define IAgentNotifySinkEx_BalloonVisibleState(This,dwCharID,bVisible)	\
    (This)->lpVtbl -> BalloonVisibleState(This,dwCharID,bVisible)


#define IAgentNotifySinkEx_HelpComplete(This,dwCharID,dwCommandID,dwCause)	\
    (This)->lpVtbl -> HelpComplete(This,dwCharID,dwCommandID,dwCause)

#define IAgentNotifySinkEx_ListeningState(This,dwCharID,bListening,dwCause)	\
    (This)->lpVtbl -> ListeningState(This,dwCharID,bListening,dwCause)

#define IAgentNotifySinkEx_DefaultCharacterChange(This,bszGUID)	\
    (This)->lpVtbl -> DefaultCharacterChange(This,bszGUID)

#define IAgentNotifySinkEx_AgentPropertyChange(This)	\
    (This)->lpVtbl -> AgentPropertyChange(This)

#define IAgentNotifySinkEx_ActiveClientChange(This,dwCharID,lStatus)	\
    (This)->lpVtbl -> ActiveClientChange(This,dwCharID,lStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentNotifySinkEx_HelpComplete_Proxy( 
    IAgentNotifySinkEx __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long dwCommandID,
    /* [in] */ long dwCause);


void __RPC_STUB IAgentNotifySinkEx_HelpComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySinkEx_ListeningState_Proxy( 
    IAgentNotifySinkEx __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long bListening,
    /* [in] */ long dwCause);


void __RPC_STUB IAgentNotifySinkEx_ListeningState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySinkEx_DefaultCharacterChange_Proxy( 
    IAgentNotifySinkEx __RPC_FAR * This,
    /* [in] */ BSTR bszGUID);


void __RPC_STUB IAgentNotifySinkEx_DefaultCharacterChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySinkEx_AgentPropertyChange_Proxy( 
    IAgentNotifySinkEx __RPC_FAR * This);


void __RPC_STUB IAgentNotifySinkEx_AgentPropertyChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySinkEx_ActiveClientChange_Proxy( 
    IAgentNotifySinkEx __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long lStatus);


void __RPC_STUB IAgentNotifySinkEx_ActiveClientChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentNotifySinkEx_INTERFACE_DEFINED__ */


#ifndef __IAgentPrivateNotifySink_INTERFACE_DEFINED__
#define __IAgentPrivateNotifySink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentPrivateNotifySink
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][uuid][local][object] */ 



EXTERN_C const IID IID_IAgentPrivateNotifySink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("B741B760-8EA6-11d0-AC6A-00C04FD97575")
    IAgentPrivateNotifySink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ReleaseAll( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseOne( 
            void __RPC_FAR *pnNotify) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClientID( 
            DWORD __RPC_FAR *pdwClientID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentPrivateNotifySinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentPrivateNotifySink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentPrivateNotifySink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentPrivateNotifySink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseAll )( 
            IAgentPrivateNotifySink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseOne )( 
            IAgentPrivateNotifySink __RPC_FAR * This,
            void __RPC_FAR *pnNotify);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClientID )( 
            IAgentPrivateNotifySink __RPC_FAR * This,
            DWORD __RPC_FAR *pdwClientID);
        
        END_INTERFACE
    } IAgentPrivateNotifySinkVtbl;

    interface IAgentPrivateNotifySink
    {
        CONST_VTBL struct IAgentPrivateNotifySinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentPrivateNotifySink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentPrivateNotifySink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentPrivateNotifySink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentPrivateNotifySink_ReleaseAll(This)	\
    (This)->lpVtbl -> ReleaseAll(This)

#define IAgentPrivateNotifySink_ReleaseOne(This,pnNotify)	\
    (This)->lpVtbl -> ReleaseOne(This,pnNotify)

#define IAgentPrivateNotifySink_GetClientID(This,pdwClientID)	\
    (This)->lpVtbl -> GetClientID(This,pdwClientID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentPrivateNotifySink_ReleaseAll_Proxy( 
    IAgentPrivateNotifySink __RPC_FAR * This);


void __RPC_STUB IAgentPrivateNotifySink_ReleaseAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPrivateNotifySink_ReleaseOne_Proxy( 
    IAgentPrivateNotifySink __RPC_FAR * This,
    void __RPC_FAR *pnNotify);


void __RPC_STUB IAgentPrivateNotifySink_ReleaseOne_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPrivateNotifySink_GetClientID_Proxy( 
    IAgentPrivateNotifySink __RPC_FAR * This,
    DWORD __RPC_FAR *pdwClientID);


void __RPC_STUB IAgentPrivateNotifySink_GetClientID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentPrivateNotifySink_INTERFACE_DEFINED__ */


#ifndef __IAgentCustomMarshalMaker_INTERFACE_DEFINED__
#define __IAgentCustomMarshalMaker_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentCustomMarshalMaker
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][uuid][hidden][local][object] */ 



EXTERN_C const IID IID_IAgentCustomMarshalMaker;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("408D7542-C8FC-11d1-AA83-00C04FA34D72")
    IAgentCustomMarshalMaker : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ IUnknown __RPC_FAR *pSink,
            /* [in] */ REFIID riidSink,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *pMarshaledSink) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCustomMarshalMakerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCustomMarshalMaker __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCustomMarshalMaker __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCustomMarshalMaker __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create )( 
            IAgentCustomMarshalMaker __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pSink,
            /* [in] */ REFIID riidSink,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *pMarshaledSink);
        
        END_INTERFACE
    } IAgentCustomMarshalMakerVtbl;

    interface IAgentCustomMarshalMaker
    {
        CONST_VTBL struct IAgentCustomMarshalMakerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCustomMarshalMaker_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCustomMarshalMaker_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCustomMarshalMaker_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCustomMarshalMaker_Create(This,pSink,riidSink,pMarshaledSink)	\
    (This)->lpVtbl -> Create(This,pSink,riidSink,pMarshaledSink)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCustomMarshalMaker_Create_Proxy( 
    IAgentCustomMarshalMaker __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pSink,
    /* [in] */ REFIID riidSink,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *pMarshaledSink);


void __RPC_STUB IAgentCustomMarshalMaker_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCustomMarshalMaker_INTERFACE_DEFINED__ */


#ifndef __IAgentClientStatus_INTERFACE_DEFINED__
#define __IAgentClientStatus_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAgentClientStatus
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][uuid][local][object] */ 



EXTERN_C const IID IID_IAgentClientStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("C5649F70-7AED-11d1-B9A8-00C04FD97575")
    IAgentClientStatus : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Ping( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentClientStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentClientStatus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentClientStatus __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentClientStatus __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Ping )( 
            IAgentClientStatus __RPC_FAR * This);
        
        END_INTERFACE
    } IAgentClientStatusVtbl;

    interface IAgentClientStatus
    {
        CONST_VTBL struct IAgentClientStatusVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentClientStatus_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentClientStatus_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentClientStatus_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentClientStatus_Ping(This)	\
    (This)->lpVtbl -> Ping(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentClientStatus_Ping_Proxy( 
    IAgentClientStatus __RPC_FAR * This);


void __RPC_STUB IAgentClientStatus_Ping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentClientStatus_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_AgentServer_0156
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define	AGENT_VERSION_MAJOR	( 2 )

#define	AGENT_VERSION_MINOR	( 0 )



extern RPC_IF_HANDLE __MIDL_itf_AgentServer_0156_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AgentServer_0156_v0_0_s_ifspec;


#ifndef __AgentServerObjects_LIBRARY_DEFINED__
#define __AgentServerObjects_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: AgentServerObjects
 * at Mon Aug 31 17:00:38 1998
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 





















EXTERN_C const IID LIBID_AgentServerObjects;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_AgentServer;

class DECLSPEC_UUID("D45FD2FC-5C6E-11D1-9EC1-00C04FD7081F")
AgentServer;
#endif
#endif /* __AgentServerObjects_LIBRARY_DEFINED__ */

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
/* at Tue Sep 15 16:56:07 1998
 */
/* Compiler settings for AgentServer.idl:
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

#ifndef __AgentServer_h__
#define __AgentServer_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAgentUserInput_FWD_DEFINED__
#define __IAgentUserInput_FWD_DEFINED__
typedef interface IAgentUserInput IAgentUserInput;
#endif 	/* __IAgentUserInput_FWD_DEFINED__ */


#ifndef __IAgentCommand_FWD_DEFINED__
#define __IAgentCommand_FWD_DEFINED__
typedef interface IAgentCommand IAgentCommand;
#endif 	/* __IAgentCommand_FWD_DEFINED__ */


#ifndef __IAgentCommandEx_FWD_DEFINED__
#define __IAgentCommandEx_FWD_DEFINED__
typedef interface IAgentCommandEx IAgentCommandEx;
#endif 	/* __IAgentCommandEx_FWD_DEFINED__ */


#ifndef __IAgentCommands_FWD_DEFINED__
#define __IAgentCommands_FWD_DEFINED__
typedef interface IAgentCommands IAgentCommands;
#endif 	/* __IAgentCommands_FWD_DEFINED__ */


#ifndef __IAgentCommandsEx_FWD_DEFINED__
#define __IAgentCommandsEx_FWD_DEFINED__
typedef interface IAgentCommandsEx IAgentCommandsEx;
#endif 	/* __IAgentCommandsEx_FWD_DEFINED__ */


#ifndef __IAgentCommandWindow_FWD_DEFINED__
#define __IAgentCommandWindow_FWD_DEFINED__
typedef interface IAgentCommandWindow IAgentCommandWindow;
#endif 	/* __IAgentCommandWindow_FWD_DEFINED__ */


#ifndef __IAgentSpeechInputProperties_FWD_DEFINED__
#define __IAgentSpeechInputProperties_FWD_DEFINED__
typedef interface IAgentSpeechInputProperties IAgentSpeechInputProperties;
#endif 	/* __IAgentSpeechInputProperties_FWD_DEFINED__ */


#ifndef __IAgentAudioOutputProperties_FWD_DEFINED__
#define __IAgentAudioOutputProperties_FWD_DEFINED__
typedef interface IAgentAudioOutputProperties IAgentAudioOutputProperties;
#endif 	/* __IAgentAudioOutputProperties_FWD_DEFINED__ */


#ifndef __IAgentAudioOutputPropertiesEx_FWD_DEFINED__
#define __IAgentAudioOutputPropertiesEx_FWD_DEFINED__
typedef interface IAgentAudioOutputPropertiesEx IAgentAudioOutputPropertiesEx;
#endif 	/* __IAgentAudioOutputPropertiesEx_FWD_DEFINED__ */


#ifndef __IAgentPropertySheet_FWD_DEFINED__
#define __IAgentPropertySheet_FWD_DEFINED__
typedef interface IAgentPropertySheet IAgentPropertySheet;
#endif 	/* __IAgentPropertySheet_FWD_DEFINED__ */


#ifndef __IAgentBalloon_FWD_DEFINED__
#define __IAgentBalloon_FWD_DEFINED__
typedef interface IAgentBalloon IAgentBalloon;
#endif 	/* __IAgentBalloon_FWD_DEFINED__ */


#ifndef __IAgentBalloonEx_FWD_DEFINED__
#define __IAgentBalloonEx_FWD_DEFINED__
typedef interface IAgentBalloonEx IAgentBalloonEx;
#endif 	/* __IAgentBalloonEx_FWD_DEFINED__ */


#ifndef __IAgentCharacter_FWD_DEFINED__
#define __IAgentCharacter_FWD_DEFINED__
typedef interface IAgentCharacter IAgentCharacter;
#endif 	/* __IAgentCharacter_FWD_DEFINED__ */


#ifndef __IAgentCharacterEx_FWD_DEFINED__
#define __IAgentCharacterEx_FWD_DEFINED__
typedef interface IAgentCharacterEx IAgentCharacterEx;
#endif 	/* __IAgentCharacterEx_FWD_DEFINED__ */


#ifndef __IAgent_FWD_DEFINED__
#define __IAgent_FWD_DEFINED__
typedef interface IAgent IAgent;
#endif 	/* __IAgent_FWD_DEFINED__ */


#ifndef __IAgentEx_FWD_DEFINED__
#define __IAgentEx_FWD_DEFINED__
typedef interface IAgentEx IAgentEx;
#endif 	/* __IAgentEx_FWD_DEFINED__ */


#ifndef __IAgentNotifySink_FWD_DEFINED__
#define __IAgentNotifySink_FWD_DEFINED__
typedef interface IAgentNotifySink IAgentNotifySink;
#endif 	/* __IAgentNotifySink_FWD_DEFINED__ */


#ifndef __IAgentNotifySinkEx_FWD_DEFINED__
#define __IAgentNotifySinkEx_FWD_DEFINED__
typedef interface IAgentNotifySinkEx IAgentNotifySinkEx;
#endif 	/* __IAgentNotifySinkEx_FWD_DEFINED__ */


#ifndef __IAgentPrivateNotifySink_FWD_DEFINED__
#define __IAgentPrivateNotifySink_FWD_DEFINED__
typedef interface IAgentPrivateNotifySink IAgentPrivateNotifySink;
#endif 	/* __IAgentPrivateNotifySink_FWD_DEFINED__ */


#ifndef __IAgentCustomMarshalMaker_FWD_DEFINED__
#define __IAgentCustomMarshalMaker_FWD_DEFINED__
typedef interface IAgentCustomMarshalMaker IAgentCustomMarshalMaker;
#endif 	/* __IAgentCustomMarshalMaker_FWD_DEFINED__ */


#ifndef __IAgentClientStatus_FWD_DEFINED__
#define __IAgentClientStatus_FWD_DEFINED__
typedef interface IAgentClientStatus IAgentClientStatus;
#endif 	/* __IAgentClientStatus_FWD_DEFINED__ */


#ifndef __AgentServer_FWD_DEFINED__
#define __AgentServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class AgentServer AgentServer;
#else
typedef struct AgentServer AgentServer;
#endif /* __cplusplus */

#endif 	/* __AgentServer_FWD_DEFINED__ */


#ifndef __IAgentUserInput_FWD_DEFINED__
#define __IAgentUserInput_FWD_DEFINED__
typedef interface IAgentUserInput IAgentUserInput;
#endif 	/* __IAgentUserInput_FWD_DEFINED__ */


#ifndef __IAgentCommand_FWD_DEFINED__
#define __IAgentCommand_FWD_DEFINED__
typedef interface IAgentCommand IAgentCommand;
#endif 	/* __IAgentCommand_FWD_DEFINED__ */


#ifndef __IAgentCommandEx_FWD_DEFINED__
#define __IAgentCommandEx_FWD_DEFINED__
typedef interface IAgentCommandEx IAgentCommandEx;
#endif 	/* __IAgentCommandEx_FWD_DEFINED__ */


#ifndef __IAgentCommands_FWD_DEFINED__
#define __IAgentCommands_FWD_DEFINED__
typedef interface IAgentCommands IAgentCommands;
#endif 	/* __IAgentCommands_FWD_DEFINED__ */


#ifndef __IAgentCommandsEx_FWD_DEFINED__
#define __IAgentCommandsEx_FWD_DEFINED__
typedef interface IAgentCommandsEx IAgentCommandsEx;
#endif 	/* __IAgentCommandsEx_FWD_DEFINED__ */


#ifndef __IAgentSpeechInputProperties_FWD_DEFINED__
#define __IAgentSpeechInputProperties_FWD_DEFINED__
typedef interface IAgentSpeechInputProperties IAgentSpeechInputProperties;
#endif 	/* __IAgentSpeechInputProperties_FWD_DEFINED__ */


#ifndef __IAgentAudioOutputProperties_FWD_DEFINED__
#define __IAgentAudioOutputProperties_FWD_DEFINED__
typedef interface IAgentAudioOutputProperties IAgentAudioOutputProperties;
#endif 	/* __IAgentAudioOutputProperties_FWD_DEFINED__ */


#ifndef __IAgentAudioOutputPropertiesEx_FWD_DEFINED__
#define __IAgentAudioOutputPropertiesEx_FWD_DEFINED__
typedef interface IAgentAudioOutputPropertiesEx IAgentAudioOutputPropertiesEx;
#endif 	/* __IAgentAudioOutputPropertiesEx_FWD_DEFINED__ */


#ifndef __IAgentPropertySheet_FWD_DEFINED__
#define __IAgentPropertySheet_FWD_DEFINED__
typedef interface IAgentPropertySheet IAgentPropertySheet;
#endif 	/* __IAgentPropertySheet_FWD_DEFINED__ */


#ifndef __IAgentBalloon_FWD_DEFINED__
#define __IAgentBalloon_FWD_DEFINED__
typedef interface IAgentBalloon IAgentBalloon;
#endif 	/* __IAgentBalloon_FWD_DEFINED__ */


#ifndef __IAgentBalloonEx_FWD_DEFINED__
#define __IAgentBalloonEx_FWD_DEFINED__
typedef interface IAgentBalloonEx IAgentBalloonEx;
#endif 	/* __IAgentBalloonEx_FWD_DEFINED__ */


#ifndef __IAgentCharacter_FWD_DEFINED__
#define __IAgentCharacter_FWD_DEFINED__
typedef interface IAgentCharacter IAgentCharacter;
#endif 	/* __IAgentCharacter_FWD_DEFINED__ */


#ifndef __IAgentCharacterEx_FWD_DEFINED__
#define __IAgentCharacterEx_FWD_DEFINED__
typedef interface IAgentCharacterEx IAgentCharacterEx;
#endif 	/* __IAgentCharacterEx_FWD_DEFINED__ */


#ifndef __IAgent_FWD_DEFINED__
#define __IAgent_FWD_DEFINED__
typedef interface IAgent IAgent;
#endif 	/* __IAgent_FWD_DEFINED__ */


#ifndef __IAgentEx_FWD_DEFINED__
#define __IAgentEx_FWD_DEFINED__
typedef interface IAgentEx IAgentEx;
#endif 	/* __IAgentEx_FWD_DEFINED__ */


#ifndef __IAgentNotifySink_FWD_DEFINED__
#define __IAgentNotifySink_FWD_DEFINED__
typedef interface IAgentNotifySink IAgentNotifySink;
#endif 	/* __IAgentNotifySink_FWD_DEFINED__ */


#ifndef __IAgentNotifySinkEx_FWD_DEFINED__
#define __IAgentNotifySinkEx_FWD_DEFINED__
typedef interface IAgentNotifySinkEx IAgentNotifySinkEx;
#endif 	/* __IAgentNotifySinkEx_FWD_DEFINED__ */


#ifndef __IAgentCommandWindow_FWD_DEFINED__
#define __IAgentCommandWindow_FWD_DEFINED__
typedef interface IAgentCommandWindow IAgentCommandWindow;
#endif 	/* __IAgentCommandWindow_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_AgentServer_0000 */
/* [local] */ 

#define	NeverMoved	( 0 )

#define	UserMoved	( 1 )

#define	ProgramMoved	( 2 )

#define	OtherProgramMoved	( 3 )

#define	SystemMoved	( 4 )

#define	NeverShown	( 0 )

#define	UserHid	( 1 )

#define	UserShowed	( 2 )

#define	ProgramHid	( 3 )

#define	ProgramShowed	( 4 )

#define	OtherProgramHid	( 5 )

#define	OtherProgramShowed	( 6 )

#define	UserHidViaCharacterMenu	( 7 )

#define	UserHidViaTaskbarIcon	( UserHid )

#define	CSHELPCAUSE_COMMAND	( 1 )

#define	CSHELPCAUSE_OTHERPROGRAM	( 2 )

#define	CSHELPCAUSE_OPENCOMMANDSWINDOW	( 3 )

#define	CSHELPCAUSE_CLOSECOMMANDSWINDOW	( 4 )

#define	CSHELPCAUSE_SHOWCHARACTER	( 5 )

#define	CSHELPCAUSE_HIDECHARACTER	( 6 )

#define	CSHELPCAUSE_CHARACTER	( 7 )

#define	ACTIVATE_NOTTOPMOST	( 0 )

#define	ACTIVATE_TOPMOST	( 1 )

#define	ACTIVATE_NOTACTIVE	( 0 )

#define	ACTIVATE_ACTIVE	( 1 )

#define	ACTIVATE_INPUTACTIVE	( 2 )

#define	PREPARE_ANIMATION	( 0 )

#define	PREPARE_STATE	( 1 )

#define	PREPARE_WAVE	( 2 )

#define	STOP_TYPE_PLAY	( 0x1 )

#define	STOP_TYPE_MOVE	( 0x2 )

#define	STOP_TYPE_SPEAK	( 0x4 )

#define	STOP_TYPE_PREPARE	( 0x8 )

#define	STOP_TYPE_NONQUEUEDPREPARE	( 0x10 )

#define	STOP_TYPE_VISIBLE	( 0x20 )

#define	STOP_TYPE_ALL	( 0xffffffff )

#define	BALLOON_STYLE_BALLOON_ON	( 0x1 )

#define	BALLOON_STYLE_SIZETOTEXT	( 0x2 )

#define	BALLOON_STYLE_AUTOHIDE	( 0x4 )

#define	BALLOON_STYLE_AUTOPACE	( 0x8 )

#define	AUDIO_STATUS_AVAILABLE	( 0 )

#define	AUDIO_STATUS_NOAUDIO	( 1 )

#define	AUDIO_STATUS_CANTOPENAUDIO	( 2 )

#define	AUDIO_STATUS_USERSPEAKING	( 3 )

#define	AUDIO_STATUS_CHARACTERSPEAKING	( 4 )

#define	AUDIO_STATUS_SROVERRIDEABLE	( 5 )

#define	AUDIO_STATUS_ERROR	( 6 )

#define	LISTEN_STATUS_CANLISTEN	( 0 )

#define	LISTEN_STATUS_NOAUDIO	( 1 )

#define	LISTEN_STATUS_NOTACTIVE	( 2 )

#define	LISTEN_STATUS_CANTOPENAUDIO	( 3 )

#define	LISTEN_STATUS_COULDNTINITIALIZESPEECH	( 4 )

#define	LISTEN_STATUS_SPEECHDISABLED	( 5 )

#define	LISTEN_STATUS_ERROR	( 6 )

#define	MK_ICON	( 0x1000 )

#define	LSCOMPLETE_CAUSE_PROGRAMDISABLED	( 1 )

#define	LSCOMPLETE_CAUSE_PROGRAMTIMEDOUT	( 2 )

#define	LSCOMPLETE_CAUSE_USERTIMEDOUT	( 3 )

#define	LSCOMPLETE_CAUSE_USERRELEASEDKEY	( 4 )

#define	LSCOMPLETE_CAUSE_USERUTTERANCEENDED	( 5 )

#define	LSCOMPLETE_CAUSE_CLIENTDEACTIVATED	( 6 )

#define	LSCOMPLETE_CAUSE_DEFAULTCHARCHANGE	( 7 )

#define	LSCOMPLETE_CAUSE_USERDISABLED	( 8 )



extern RPC_IF_HANDLE __MIDL_itf_AgentServer_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AgentServer_0000_v0_0_s_ifspec;

#ifndef __IAgentUserInput_INTERFACE_DEFINED__
#define __IAgentUserInput_INTERFACE_DEFINED__

/* interface IAgentUserInput */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentUserInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7B93C80-7B81-11D0-AC5F-00C04FD97575")
    IAgentUserInput : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ long __RPC_FAR *pdwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemID( 
            /* [in] */ long dwItemIndex,
            /* [out] */ long __RPC_FAR *pdwCommandID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemConfidence( 
            /* [in] */ long dwItemIndex,
            /* [out] */ long __RPC_FAR *plConfidence) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemText( 
            /* [in] */ long dwItemIndex,
            /* [out] */ BSTR __RPC_FAR *pbszText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllItemData( 
            /* [out] */ VARIANT __RPC_FAR *pdwItemIndices,
            /* [out] */ VARIANT __RPC_FAR *plConfidences,
            /* [out] */ VARIANT __RPC_FAR *pbszText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentUserInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentUserInput __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentUserInput __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentUserInput __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IAgentUserInput __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemID )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ long dwItemIndex,
            /* [out] */ long __RPC_FAR *pdwCommandID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemConfidence )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ long dwItemIndex,
            /* [out] */ long __RPC_FAR *plConfidence);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemText )( 
            IAgentUserInput __RPC_FAR * This,
            /* [in] */ long dwItemIndex,
            /* [out] */ BSTR __RPC_FAR *pbszText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllItemData )( 
            IAgentUserInput __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *pdwItemIndices,
            /* [out] */ VARIANT __RPC_FAR *plConfidences,
            /* [out] */ VARIANT __RPC_FAR *pbszText);
        
        END_INTERFACE
    } IAgentUserInputVtbl;

    interface IAgentUserInput
    {
        CONST_VTBL struct IAgentUserInputVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentUserInput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentUserInput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentUserInput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentUserInput_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentUserInput_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentUserInput_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentUserInput_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentUserInput_GetCount(This,pdwCount)	\
    (This)->lpVtbl -> GetCount(This,pdwCount)

#define IAgentUserInput_GetItemID(This,dwItemIndex,pdwCommandID)	\
    (This)->lpVtbl -> GetItemID(This,dwItemIndex,pdwCommandID)

#define IAgentUserInput_GetItemConfidence(This,dwItemIndex,plConfidence)	\
    (This)->lpVtbl -> GetItemConfidence(This,dwItemIndex,plConfidence)

#define IAgentUserInput_GetItemText(This,dwItemIndex,pbszText)	\
    (This)->lpVtbl -> GetItemText(This,dwItemIndex,pbszText)

#define IAgentUserInput_GetAllItemData(This,pdwItemIndices,plConfidences,pbszText)	\
    (This)->lpVtbl -> GetAllItemData(This,pdwItemIndices,plConfidences,pbszText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentUserInput_GetCount_Proxy( 
    IAgentUserInput __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwCount);


void __RPC_STUB IAgentUserInput_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentUserInput_GetItemID_Proxy( 
    IAgentUserInput __RPC_FAR * This,
    /* [in] */ long dwItemIndex,
    /* [out] */ long __RPC_FAR *pdwCommandID);


void __RPC_STUB IAgentUserInput_GetItemID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentUserInput_GetItemConfidence_Proxy( 
    IAgentUserInput __RPC_FAR * This,
    /* [in] */ long dwItemIndex,
    /* [out] */ long __RPC_FAR *plConfidence);


void __RPC_STUB IAgentUserInput_GetItemConfidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentUserInput_GetItemText_Proxy( 
    IAgentUserInput __RPC_FAR * This,
    /* [in] */ long dwItemIndex,
    /* [out] */ BSTR __RPC_FAR *pbszText);


void __RPC_STUB IAgentUserInput_GetItemText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentUserInput_GetAllItemData_Proxy( 
    IAgentUserInput __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *pdwItemIndices,
    /* [out] */ VARIANT __RPC_FAR *plConfidences,
    /* [out] */ VARIANT __RPC_FAR *pbszText);


void __RPC_STUB IAgentUserInput_GetAllItemData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentUserInput_INTERFACE_DEFINED__ */


#ifndef __IAgentCommand_INTERFACE_DEFINED__
#define __IAgentCommand_INTERFACE_DEFINED__

/* interface IAgentCommand */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCommand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7B93C83-7B81-11D0-AC5F-00C04FD97575")
    IAgentCommand : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetCaption( 
            /* [in] */ BSTR bszCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCaption( 
            /* [out] */ BSTR __RPC_FAR *pbszCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoice( 
            /* [in] */ BSTR bszVoice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoice( 
            /* [out] */ BSTR __RPC_FAR *pbszVoice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnabled( 
            /* [in] */ long bEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnabled( 
            /* [out] */ long __RPC_FAR *pbEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVisible( 
            /* [in] */ long bVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConfidenceThreshold( 
            /* [in] */ long lThreshold) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConfidenceThreshold( 
            /* [out] */ long __RPC_FAR *plThreshold) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConfidenceText( 
            /* [in] */ BSTR bszTipText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConfidenceText( 
            /* [out] */ BSTR __RPC_FAR *pbszTipText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetID( 
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCommandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCommand __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCommand __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ BSTR bszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaption )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoice )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ BSTR bszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoice )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ long bEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConfidenceThreshold )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ long lThreshold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConfidenceThreshold )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plThreshold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConfidenceText )( 
            IAgentCommand __RPC_FAR * This,
            /* [in] */ BSTR bszTipText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConfidenceText )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszTipText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IAgentCommand __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwID);
        
        END_INTERFACE
    } IAgentCommandVtbl;

    interface IAgentCommand
    {
        CONST_VTBL struct IAgentCommandVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCommand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCommand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCommand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCommand_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCommand_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCommand_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCommand_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCommand_SetCaption(This,bszCaption)	\
    (This)->lpVtbl -> SetCaption(This,bszCaption)

#define IAgentCommand_GetCaption(This,pbszCaption)	\
    (This)->lpVtbl -> GetCaption(This,pbszCaption)

#define IAgentCommand_SetVoice(This,bszVoice)	\
    (This)->lpVtbl -> SetVoice(This,bszVoice)

#define IAgentCommand_GetVoice(This,pbszVoice)	\
    (This)->lpVtbl -> GetVoice(This,pbszVoice)

#define IAgentCommand_SetEnabled(This,bEnabled)	\
    (This)->lpVtbl -> SetEnabled(This,bEnabled)

#define IAgentCommand_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentCommand_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentCommand_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCommand_SetConfidenceThreshold(This,lThreshold)	\
    (This)->lpVtbl -> SetConfidenceThreshold(This,lThreshold)

#define IAgentCommand_GetConfidenceThreshold(This,plThreshold)	\
    (This)->lpVtbl -> GetConfidenceThreshold(This,plThreshold)

#define IAgentCommand_SetConfidenceText(This,bszTipText)	\
    (This)->lpVtbl -> SetConfidenceText(This,bszTipText)

#define IAgentCommand_GetConfidenceText(This,pbszTipText)	\
    (This)->lpVtbl -> GetConfidenceText(This,pbszTipText)

#define IAgentCommand_GetID(This,pdwID)	\
    (This)->lpVtbl -> GetID(This,pdwID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCommand_SetCaption_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ BSTR bszCaption);


void __RPC_STUB IAgentCommand_SetCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetCaption_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszCaption);


void __RPC_STUB IAgentCommand_GetCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_SetVoice_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ BSTR bszVoice);


void __RPC_STUB IAgentCommand_SetVoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetVoice_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszVoice);


void __RPC_STUB IAgentCommand_GetVoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_SetEnabled_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ long bEnabled);


void __RPC_STUB IAgentCommand_SetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetEnabled_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbEnabled);


void __RPC_STUB IAgentCommand_GetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_SetVisible_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentCommand_SetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetVisible_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentCommand_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_SetConfidenceThreshold_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ long lThreshold);


void __RPC_STUB IAgentCommand_SetConfidenceThreshold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetConfidenceThreshold_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plThreshold);


void __RPC_STUB IAgentCommand_GetConfidenceThreshold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_SetConfidenceText_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [in] */ BSTR bszTipText);


void __RPC_STUB IAgentCommand_SetConfidenceText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetConfidenceText_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszTipText);


void __RPC_STUB IAgentCommand_GetConfidenceText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommand_GetID_Proxy( 
    IAgentCommand __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommand_GetID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCommand_INTERFACE_DEFINED__ */


#ifndef __IAgentCommandEx_INTERFACE_DEFINED__
#define __IAgentCommandEx_INTERFACE_DEFINED__

/* interface IAgentCommandEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCommandEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B0913412-3B44-11d1-ACBA-00C04FD97575")
    IAgentCommandEx : public IAgentCommand
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetHelpContextID( 
            /* [in] */ long ulID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpContextID( 
            /* [out] */ long __RPC_FAR *pulID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoiceCaption( 
            /* [in] */ BSTR bszVoiceCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoiceCaption( 
            /* [out] */ BSTR __RPC_FAR *pbszVoiceCaption) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCommandExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCommandEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCommandEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaption )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoice )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ BSTR bszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoice )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ long bEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConfidenceThreshold )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ long lThreshold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConfidenceThreshold )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plThreshold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConfidenceText )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ BSTR bszTipText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConfidenceText )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszTipText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpContextID )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ long ulID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpContextID )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pulID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoiceCaption )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [in] */ BSTR bszVoiceCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoiceCaption )( 
            IAgentCommandEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszVoiceCaption);
        
        END_INTERFACE
    } IAgentCommandExVtbl;

    interface IAgentCommandEx
    {
        CONST_VTBL struct IAgentCommandExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCommandEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCommandEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCommandEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCommandEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCommandEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCommandEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCommandEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCommandEx_SetCaption(This,bszCaption)	\
    (This)->lpVtbl -> SetCaption(This,bszCaption)

#define IAgentCommandEx_GetCaption(This,pbszCaption)	\
    (This)->lpVtbl -> GetCaption(This,pbszCaption)

#define IAgentCommandEx_SetVoice(This,bszVoice)	\
    (This)->lpVtbl -> SetVoice(This,bszVoice)

#define IAgentCommandEx_GetVoice(This,pbszVoice)	\
    (This)->lpVtbl -> GetVoice(This,pbszVoice)

#define IAgentCommandEx_SetEnabled(This,bEnabled)	\
    (This)->lpVtbl -> SetEnabled(This,bEnabled)

#define IAgentCommandEx_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentCommandEx_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentCommandEx_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCommandEx_SetConfidenceThreshold(This,lThreshold)	\
    (This)->lpVtbl -> SetConfidenceThreshold(This,lThreshold)

#define IAgentCommandEx_GetConfidenceThreshold(This,plThreshold)	\
    (This)->lpVtbl -> GetConfidenceThreshold(This,plThreshold)

#define IAgentCommandEx_SetConfidenceText(This,bszTipText)	\
    (This)->lpVtbl -> SetConfidenceText(This,bszTipText)

#define IAgentCommandEx_GetConfidenceText(This,pbszTipText)	\
    (This)->lpVtbl -> GetConfidenceText(This,pbszTipText)

#define IAgentCommandEx_GetID(This,pdwID)	\
    (This)->lpVtbl -> GetID(This,pdwID)


#define IAgentCommandEx_SetHelpContextID(This,ulID)	\
    (This)->lpVtbl -> SetHelpContextID(This,ulID)

#define IAgentCommandEx_GetHelpContextID(This,pulID)	\
    (This)->lpVtbl -> GetHelpContextID(This,pulID)

#define IAgentCommandEx_SetVoiceCaption(This,bszVoiceCaption)	\
    (This)->lpVtbl -> SetVoiceCaption(This,bszVoiceCaption)

#define IAgentCommandEx_GetVoiceCaption(This,pbszVoiceCaption)	\
    (This)->lpVtbl -> GetVoiceCaption(This,pbszVoiceCaption)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCommandEx_SetHelpContextID_Proxy( 
    IAgentCommandEx __RPC_FAR * This,
    /* [in] */ long ulID);


void __RPC_STUB IAgentCommandEx_SetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandEx_GetHelpContextID_Proxy( 
    IAgentCommandEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pulID);


void __RPC_STUB IAgentCommandEx_GetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandEx_SetVoiceCaption_Proxy( 
    IAgentCommandEx __RPC_FAR * This,
    /* [in] */ BSTR bszVoiceCaption);


void __RPC_STUB IAgentCommandEx_SetVoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandEx_GetVoiceCaption_Proxy( 
    IAgentCommandEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszVoiceCaption);


void __RPC_STUB IAgentCommandEx_GetVoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCommandEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCommands_INTERFACE_DEFINED__
#define __IAgentCommands_INTERFACE_DEFINED__

/* interface IAgentCommands */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCommands;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7B93C85-7B81-11D0-AC5F-00C04FD97575")
    IAgentCommands : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCommand( 
            /* [in] */ long dwCommandID,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkCommand) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ long __RPC_FAR *pdwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCaption( 
            /* [in] */ BSTR bszCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCaption( 
            /* [out] */ BSTR __RPC_FAR *pbszCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoice( 
            /* [in] */ BSTR bszVoice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoice( 
            /* [out] */ BSTR __RPC_FAR *pbszVoice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVisible( 
            /* [in] */ long bVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long dwRefID,
            /* [in] */ long bBefore,
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ long dwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCommandsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCommands __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCommands __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCommands __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommand )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ long dwCommandID,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkCommand);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IAgentCommands __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ BSTR bszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaption )( 
            IAgentCommands __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoice )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ BSTR bszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoice )( 
            IAgentCommands __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCommands __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long dwRefID,
            /* [in] */ long bBefore,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IAgentCommands __RPC_FAR * This,
            /* [in] */ long dwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll )( 
            IAgentCommands __RPC_FAR * This);
        
        END_INTERFACE
    } IAgentCommandsVtbl;

    interface IAgentCommands
    {
        CONST_VTBL struct IAgentCommandsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCommands_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCommands_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCommands_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCommands_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCommands_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCommands_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCommands_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCommands_GetCommand(This,dwCommandID,ppunkCommand)	\
    (This)->lpVtbl -> GetCommand(This,dwCommandID,ppunkCommand)

#define IAgentCommands_GetCount(This,pdwCount)	\
    (This)->lpVtbl -> GetCount(This,pdwCount)

#define IAgentCommands_SetCaption(This,bszCaption)	\
    (This)->lpVtbl -> SetCaption(This,bszCaption)

#define IAgentCommands_GetCaption(This,pbszCaption)	\
    (This)->lpVtbl -> GetCaption(This,pbszCaption)

#define IAgentCommands_SetVoice(This,bszVoice)	\
    (This)->lpVtbl -> SetVoice(This,bszVoice)

#define IAgentCommands_GetVoice(This,pbszVoice)	\
    (This)->lpVtbl -> GetVoice(This,pbszVoice)

#define IAgentCommands_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentCommands_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCommands_Add(This,bszCaption,bszVoice,bEnabled,bVisible,pdwID)	\
    (This)->lpVtbl -> Add(This,bszCaption,bszVoice,bEnabled,bVisible,pdwID)

#define IAgentCommands_Insert(This,bszCaption,bszVoice,bEnabled,bVisible,dwRefID,bBefore,pdwID)	\
    (This)->lpVtbl -> Insert(This,bszCaption,bszVoice,bEnabled,bVisible,dwRefID,bBefore,pdwID)

#define IAgentCommands_Remove(This,dwID)	\
    (This)->lpVtbl -> Remove(This,dwID)

#define IAgentCommands_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCommands_GetCommand_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ long dwCommandID,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkCommand);


void __RPC_STUB IAgentCommands_GetCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_GetCount_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwCount);


void __RPC_STUB IAgentCommands_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_SetCaption_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ BSTR bszCaption);


void __RPC_STUB IAgentCommands_SetCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_GetCaption_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszCaption);


void __RPC_STUB IAgentCommands_GetCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_SetVoice_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ BSTR bszVoice);


void __RPC_STUB IAgentCommands_SetVoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_GetVoice_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszVoice);


void __RPC_STUB IAgentCommands_GetVoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_SetVisible_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentCommands_SetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_GetVisible_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentCommands_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_Add_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ BSTR bszCaption,
    /* [in] */ BSTR bszVoice,
    /* [in] */ long bEnabled,
    /* [in] */ long bVisible,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommands_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_Insert_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ BSTR bszCaption,
    /* [in] */ BSTR bszVoice,
    /* [in] */ long bEnabled,
    /* [in] */ long bVisible,
    /* [in] */ long dwRefID,
    /* [in] */ long bBefore,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommands_Insert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_Remove_Proxy( 
    IAgentCommands __RPC_FAR * This,
    /* [in] */ long dwID);


void __RPC_STUB IAgentCommands_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommands_RemoveAll_Proxy( 
    IAgentCommands __RPC_FAR * This);


void __RPC_STUB IAgentCommands_RemoveAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCommands_INTERFACE_DEFINED__ */


#ifndef __IAgentCommandsEx_INTERFACE_DEFINED__
#define __IAgentCommandsEx_INTERFACE_DEFINED__

/* interface IAgentCommandsEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCommandsEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6BA90C00-3910-11d1-ACB3-00C04FD97575")
    IAgentCommandsEx : public IAgentCommands
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCommandEx( 
            /* [in] */ long dwCommandID,
            /* [out] */ IAgentCommandEx __RPC_FAR *__RPC_FAR *ppCommandEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultID( 
            /* [in] */ long dwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultID( 
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHelpContextID( 
            /* [in] */ long ulHelpID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpContextID( 
            /* [out] */ long __RPC_FAR *pulHelpID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFontName( 
            /* [in] */ BSTR bszFontName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontName( 
            /* [out] */ BSTR __RPC_FAR *pbszFontName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFontSize( 
            /* [in] */ long lFontSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontSize( 
            /* [out] */ long __RPC_FAR *lFontSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoiceCaption( 
            /* [in] */ BSTR bszVoiceCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoiceCaption( 
            /* [out] */ BSTR __RPC_FAR *bszVoiceCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddEx( 
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ BSTR bszVoiceCaption,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long ulHelpId,
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertEx( 
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ BSTR bszVoiceCaption,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long ulHelpId,
            /* [in] */ long dwRefID,
            /* [in] */ long bBefore,
            /* [out] */ long __RPC_FAR *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGlobalVoiceCommandsEnabled( 
            /* [in] */ long bEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGlobalVoiceCommandsEnabled( 
            /* [out] */ long __RPC_FAR *pbEnabled) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCommandsExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCommandsEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCommandsEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommand )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long dwCommandID,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkCommand);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaption )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoice )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoice )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszVoice);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long dwRefID,
            /* [in] */ long bBefore,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long dwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll )( 
            IAgentCommandsEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommandEx )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long dwCommandID,
            /* [out] */ IAgentCommandEx __RPC_FAR *__RPC_FAR *ppCommandEx);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultID )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long dwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultID )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpContextID )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long ulHelpID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpContextID )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pulHelpID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontName )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontName )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontSize )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long lFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontSize )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *lFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVoiceCaption )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszVoiceCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVoiceCaption )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *bszVoiceCaption);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddEx )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ BSTR bszVoiceCaption,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long ulHelpId,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertEx )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ BSTR bszCaption,
            /* [in] */ BSTR bszVoice,
            /* [in] */ BSTR bszVoiceCaption,
            /* [in] */ long bEnabled,
            /* [in] */ long bVisible,
            /* [in] */ long ulHelpId,
            /* [in] */ long dwRefID,
            /* [in] */ long bBefore,
            /* [out] */ long __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGlobalVoiceCommandsEnabled )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [in] */ long bEnable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGlobalVoiceCommandsEnabled )( 
            IAgentCommandsEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        END_INTERFACE
    } IAgentCommandsExVtbl;

    interface IAgentCommandsEx
    {
        CONST_VTBL struct IAgentCommandsExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCommandsEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCommandsEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCommandsEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCommandsEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCommandsEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCommandsEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCommandsEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCommandsEx_GetCommand(This,dwCommandID,ppunkCommand)	\
    (This)->lpVtbl -> GetCommand(This,dwCommandID,ppunkCommand)

#define IAgentCommandsEx_GetCount(This,pdwCount)	\
    (This)->lpVtbl -> GetCount(This,pdwCount)

#define IAgentCommandsEx_SetCaption(This,bszCaption)	\
    (This)->lpVtbl -> SetCaption(This,bszCaption)

#define IAgentCommandsEx_GetCaption(This,pbszCaption)	\
    (This)->lpVtbl -> GetCaption(This,pbszCaption)

#define IAgentCommandsEx_SetVoice(This,bszVoice)	\
    (This)->lpVtbl -> SetVoice(This,bszVoice)

#define IAgentCommandsEx_GetVoice(This,pbszVoice)	\
    (This)->lpVtbl -> GetVoice(This,pbszVoice)

#define IAgentCommandsEx_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentCommandsEx_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCommandsEx_Add(This,bszCaption,bszVoice,bEnabled,bVisible,pdwID)	\
    (This)->lpVtbl -> Add(This,bszCaption,bszVoice,bEnabled,bVisible,pdwID)

#define IAgentCommandsEx_Insert(This,bszCaption,bszVoice,bEnabled,bVisible,dwRefID,bBefore,pdwID)	\
    (This)->lpVtbl -> Insert(This,bszCaption,bszVoice,bEnabled,bVisible,dwRefID,bBefore,pdwID)

#define IAgentCommandsEx_Remove(This,dwID)	\
    (This)->lpVtbl -> Remove(This,dwID)

#define IAgentCommandsEx_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)


#define IAgentCommandsEx_GetCommandEx(This,dwCommandID,ppCommandEx)	\
    (This)->lpVtbl -> GetCommandEx(This,dwCommandID,ppCommandEx)

#define IAgentCommandsEx_SetDefaultID(This,dwID)	\
    (This)->lpVtbl -> SetDefaultID(This,dwID)

#define IAgentCommandsEx_GetDefaultID(This,pdwID)	\
    (This)->lpVtbl -> GetDefaultID(This,pdwID)

#define IAgentCommandsEx_SetHelpContextID(This,ulHelpID)	\
    (This)->lpVtbl -> SetHelpContextID(This,ulHelpID)

#define IAgentCommandsEx_GetHelpContextID(This,pulHelpID)	\
    (This)->lpVtbl -> GetHelpContextID(This,pulHelpID)

#define IAgentCommandsEx_SetFontName(This,bszFontName)	\
    (This)->lpVtbl -> SetFontName(This,bszFontName)

#define IAgentCommandsEx_GetFontName(This,pbszFontName)	\
    (This)->lpVtbl -> GetFontName(This,pbszFontName)

#define IAgentCommandsEx_SetFontSize(This,lFontSize)	\
    (This)->lpVtbl -> SetFontSize(This,lFontSize)

#define IAgentCommandsEx_GetFontSize(This,lFontSize)	\
    (This)->lpVtbl -> GetFontSize(This,lFontSize)

#define IAgentCommandsEx_SetVoiceCaption(This,bszVoiceCaption)	\
    (This)->lpVtbl -> SetVoiceCaption(This,bszVoiceCaption)

#define IAgentCommandsEx_GetVoiceCaption(This,bszVoiceCaption)	\
    (This)->lpVtbl -> GetVoiceCaption(This,bszVoiceCaption)

#define IAgentCommandsEx_AddEx(This,bszCaption,bszVoice,bszVoiceCaption,bEnabled,bVisible,ulHelpId,pdwID)	\
    (This)->lpVtbl -> AddEx(This,bszCaption,bszVoice,bszVoiceCaption,bEnabled,bVisible,ulHelpId,pdwID)

#define IAgentCommandsEx_InsertEx(This,bszCaption,bszVoice,bszVoiceCaption,bEnabled,bVisible,ulHelpId,dwRefID,bBefore,pdwID)	\
    (This)->lpVtbl -> InsertEx(This,bszCaption,bszVoice,bszVoiceCaption,bEnabled,bVisible,ulHelpId,dwRefID,bBefore,pdwID)

#define IAgentCommandsEx_SetGlobalVoiceCommandsEnabled(This,bEnable)	\
    (This)->lpVtbl -> SetGlobalVoiceCommandsEnabled(This,bEnable)

#define IAgentCommandsEx_GetGlobalVoiceCommandsEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetGlobalVoiceCommandsEnabled(This,pbEnabled)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetCommandEx_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ long dwCommandID,
    /* [out] */ IAgentCommandEx __RPC_FAR *__RPC_FAR *ppCommandEx);


void __RPC_STUB IAgentCommandsEx_GetCommandEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetDefaultID_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ long dwID);


void __RPC_STUB IAgentCommandsEx_SetDefaultID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetDefaultID_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommandsEx_GetDefaultID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetHelpContextID_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ long ulHelpID);


void __RPC_STUB IAgentCommandsEx_SetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetHelpContextID_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pulHelpID);


void __RPC_STUB IAgentCommandsEx_GetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetFontName_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR bszFontName);


void __RPC_STUB IAgentCommandsEx_SetFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetFontName_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszFontName);


void __RPC_STUB IAgentCommandsEx_GetFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetFontSize_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ long lFontSize);


void __RPC_STUB IAgentCommandsEx_SetFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetFontSize_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *lFontSize);


void __RPC_STUB IAgentCommandsEx_GetFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetVoiceCaption_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR bszVoiceCaption);


void __RPC_STUB IAgentCommandsEx_SetVoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetVoiceCaption_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *bszVoiceCaption);


void __RPC_STUB IAgentCommandsEx_GetVoiceCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_AddEx_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR bszCaption,
    /* [in] */ BSTR bszVoice,
    /* [in] */ BSTR bszVoiceCaption,
    /* [in] */ long bEnabled,
    /* [in] */ long bVisible,
    /* [in] */ long ulHelpId,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommandsEx_AddEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_InsertEx_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ BSTR bszCaption,
    /* [in] */ BSTR bszVoice,
    /* [in] */ BSTR bszVoiceCaption,
    /* [in] */ long bEnabled,
    /* [in] */ long bVisible,
    /* [in] */ long ulHelpId,
    /* [in] */ long dwRefID,
    /* [in] */ long bBefore,
    /* [out] */ long __RPC_FAR *pdwID);


void __RPC_STUB IAgentCommandsEx_InsertEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_SetGlobalVoiceCommandsEnabled_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [in] */ long bEnable);


void __RPC_STUB IAgentCommandsEx_SetGlobalVoiceCommandsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandsEx_GetGlobalVoiceCommandsEnabled_Proxy( 
    IAgentCommandsEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbEnabled);


void __RPC_STUB IAgentCommandsEx_GetGlobalVoiceCommandsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCommandsEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCommandWindow_INTERFACE_DEFINED__
#define __IAgentCommandWindow_INTERFACE_DEFINED__

/* interface IAgentCommandWindow */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCommandWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6D0ECB23-9968-11D0-AC6E-00C04FD97575")
    IAgentCommandWindow : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetVisible( 
            /* [in] */ long bVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPosition( 
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCommandWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCommandWindow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCommandWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPosition )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IAgentCommandWindow __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight);
        
        END_INTERFACE
    } IAgentCommandWindowVtbl;

    interface IAgentCommandWindow
    {
        CONST_VTBL struct IAgentCommandWindowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCommandWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCommandWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCommandWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCommandWindow_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCommandWindow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCommandWindow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCommandWindow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCommandWindow_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentCommandWindow_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCommandWindow_GetPosition(This,plLeft,plTop)	\
    (This)->lpVtbl -> GetPosition(This,plLeft,plTop)

#define IAgentCommandWindow_GetSize(This,plWidth,plHeight)	\
    (This)->lpVtbl -> GetSize(This,plWidth,plHeight)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCommandWindow_SetVisible_Proxy( 
    IAgentCommandWindow __RPC_FAR * This,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentCommandWindow_SetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandWindow_GetVisible_Proxy( 
    IAgentCommandWindow __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentCommandWindow_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandWindow_GetPosition_Proxy( 
    IAgentCommandWindow __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plLeft,
    /* [out] */ long __RPC_FAR *plTop);


void __RPC_STUB IAgentCommandWindow_GetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCommandWindow_GetSize_Proxy( 
    IAgentCommandWindow __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plWidth,
    /* [out] */ long __RPC_FAR *plHeight);


void __RPC_STUB IAgentCommandWindow_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCommandWindow_INTERFACE_DEFINED__ */


#ifndef __IAgentSpeechInputProperties_INTERFACE_DEFINED__
#define __IAgentSpeechInputProperties_INTERFACE_DEFINED__

/* interface IAgentSpeechInputProperties */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentSpeechInputProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7B93C87-7B81-11D0-AC5F-00C04FD97575")
    IAgentSpeechInputProperties : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInstalled( 
            /* [out] */ long __RPC_FAR *pbInstalled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnabled( 
            /* [out] */ long __RPC_FAR *pbEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHotKey( 
            /* [out] */ BSTR __RPC_FAR *pbszHotCharKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLCID( 
            /* [out] */ LCID __RPC_FAR *plcidCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEngine( 
            /* [out] */ BSTR __RPC_FAR *pbszEngine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEngine( 
            /* [in] */ BSTR bszEngine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetListeningTip( 
            /* [out] */ long __RPC_FAR *pbListeningTip) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentSpeechInputPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentSpeechInputProperties __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentSpeechInputProperties __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInstalled )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbInstalled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHotKey )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszHotCharKey);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLCID )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ LCID __RPC_FAR *plcidCurrent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEngine )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszEngine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEngine )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [in] */ BSTR bszEngine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetListeningTip )( 
            IAgentSpeechInputProperties __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbListeningTip);
        
        END_INTERFACE
    } IAgentSpeechInputPropertiesVtbl;

    interface IAgentSpeechInputProperties
    {
        CONST_VTBL struct IAgentSpeechInputPropertiesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentSpeechInputProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentSpeechInputProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentSpeechInputProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentSpeechInputProperties_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentSpeechInputProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentSpeechInputProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentSpeechInputProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentSpeechInputProperties_GetInstalled(This,pbInstalled)	\
    (This)->lpVtbl -> GetInstalled(This,pbInstalled)

#define IAgentSpeechInputProperties_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentSpeechInputProperties_GetHotKey(This,pbszHotCharKey)	\
    (This)->lpVtbl -> GetHotKey(This,pbszHotCharKey)

#define IAgentSpeechInputProperties_GetLCID(This,plcidCurrent)	\
    (This)->lpVtbl -> GetLCID(This,plcidCurrent)

#define IAgentSpeechInputProperties_GetEngine(This,pbszEngine)	\
    (This)->lpVtbl -> GetEngine(This,pbszEngine)

#define IAgentSpeechInputProperties_SetEngine(This,bszEngine)	\
    (This)->lpVtbl -> SetEngine(This,bszEngine)

#define IAgentSpeechInputProperties_GetListeningTip(This,pbListeningTip)	\
    (This)->lpVtbl -> GetListeningTip(This,pbListeningTip)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetInstalled_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbInstalled);


void __RPC_STUB IAgentSpeechInputProperties_GetInstalled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetEnabled_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbEnabled);


void __RPC_STUB IAgentSpeechInputProperties_GetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetHotKey_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszHotCharKey);


void __RPC_STUB IAgentSpeechInputProperties_GetHotKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetLCID_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ LCID __RPC_FAR *plcidCurrent);


void __RPC_STUB IAgentSpeechInputProperties_GetLCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetEngine_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszEngine);


void __RPC_STUB IAgentSpeechInputProperties_GetEngine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_SetEngine_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [in] */ BSTR bszEngine);


void __RPC_STUB IAgentSpeechInputProperties_SetEngine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentSpeechInputProperties_GetListeningTip_Proxy( 
    IAgentSpeechInputProperties __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbListeningTip);


void __RPC_STUB IAgentSpeechInputProperties_GetListeningTip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentSpeechInputProperties_INTERFACE_DEFINED__ */


#ifndef __IAgentAudioOutputProperties_INTERFACE_DEFINED__
#define __IAgentAudioOutputProperties_INTERFACE_DEFINED__

/* interface IAgentAudioOutputProperties */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentAudioOutputProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7B93C89-7B81-11D0-AC5F-00C04FD97575")
    IAgentAudioOutputProperties : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEnabled( 
            /* [out] */ long __RPC_FAR *pbEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUsingSoundEffects( 
            /* [out] */ long __RPC_FAR *pbUsingSoundEffects) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentAudioOutputPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentAudioOutputProperties __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentAudioOutputProperties __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUsingSoundEffects )( 
            IAgentAudioOutputProperties __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbUsingSoundEffects);
        
        END_INTERFACE
    } IAgentAudioOutputPropertiesVtbl;

    interface IAgentAudioOutputProperties
    {
        CONST_VTBL struct IAgentAudioOutputPropertiesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentAudioOutputProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentAudioOutputProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentAudioOutputProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentAudioOutputProperties_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentAudioOutputProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentAudioOutputProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentAudioOutputProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentAudioOutputProperties_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentAudioOutputProperties_GetUsingSoundEffects(This,pbUsingSoundEffects)	\
    (This)->lpVtbl -> GetUsingSoundEffects(This,pbUsingSoundEffects)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentAudioOutputProperties_GetEnabled_Proxy( 
    IAgentAudioOutputProperties __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbEnabled);


void __RPC_STUB IAgentAudioOutputProperties_GetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentAudioOutputProperties_GetUsingSoundEffects_Proxy( 
    IAgentAudioOutputProperties __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbUsingSoundEffects);


void __RPC_STUB IAgentAudioOutputProperties_GetUsingSoundEffects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentAudioOutputProperties_INTERFACE_DEFINED__ */


#ifndef __IAgentAudioOutputPropertiesEx_INTERFACE_DEFINED__
#define __IAgentAudioOutputPropertiesEx_INTERFACE_DEFINED__

/* interface IAgentAudioOutputPropertiesEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentAudioOutputPropertiesEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7B93CA0-7B81-11D0-AC5F-00C04FD97575")
    IAgentAudioOutputPropertiesEx : public IAgentAudioOutputProperties
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ long __RPC_FAR *plStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentAudioOutputPropertiesExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUsingSoundEffects )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbUsingSoundEffects);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStatus )( 
            IAgentAudioOutputPropertiesEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plStatus);
        
        END_INTERFACE
    } IAgentAudioOutputPropertiesExVtbl;

    interface IAgentAudioOutputPropertiesEx
    {
        CONST_VTBL struct IAgentAudioOutputPropertiesExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentAudioOutputPropertiesEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentAudioOutputPropertiesEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentAudioOutputPropertiesEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentAudioOutputPropertiesEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentAudioOutputPropertiesEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentAudioOutputPropertiesEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentAudioOutputPropertiesEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentAudioOutputPropertiesEx_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentAudioOutputPropertiesEx_GetUsingSoundEffects(This,pbUsingSoundEffects)	\
    (This)->lpVtbl -> GetUsingSoundEffects(This,pbUsingSoundEffects)


#define IAgentAudioOutputPropertiesEx_GetStatus(This,plStatus)	\
    (This)->lpVtbl -> GetStatus(This,plStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentAudioOutputPropertiesEx_GetStatus_Proxy( 
    IAgentAudioOutputPropertiesEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plStatus);


void __RPC_STUB IAgentAudioOutputPropertiesEx_GetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentAudioOutputPropertiesEx_INTERFACE_DEFINED__ */


#ifndef __IAgentPropertySheet_INTERFACE_DEFINED__
#define __IAgentPropertySheet_INTERFACE_DEFINED__

/* interface IAgentPropertySheet */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentPropertySheet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7B93C8B-7B81-11D0-AC5F-00C04FD97575")
    IAgentPropertySheet : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVisible( 
            /* [in] */ long bVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPosition( 
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPage( 
            /* [out] */ BSTR __RPC_FAR *pbszPage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPage( 
            /* [in] */ BSTR bszPage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentPropertySheetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentPropertySheet __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentPropertySheet __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPosition )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPage )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszPage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPage )( 
            IAgentPropertySheet __RPC_FAR * This,
            /* [in] */ BSTR bszPage);
        
        END_INTERFACE
    } IAgentPropertySheetVtbl;

    interface IAgentPropertySheet
    {
        CONST_VTBL struct IAgentPropertySheetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentPropertySheet_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentPropertySheet_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentPropertySheet_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentPropertySheet_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentPropertySheet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentPropertySheet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentPropertySheet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentPropertySheet_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentPropertySheet_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentPropertySheet_GetPosition(This,plLeft,plTop)	\
    (This)->lpVtbl -> GetPosition(This,plLeft,plTop)

#define IAgentPropertySheet_GetSize(This,plWidth,plHeight)	\
    (This)->lpVtbl -> GetSize(This,plWidth,plHeight)

#define IAgentPropertySheet_GetPage(This,pbszPage)	\
    (This)->lpVtbl -> GetPage(This,pbszPage)

#define IAgentPropertySheet_SetPage(This,bszPage)	\
    (This)->lpVtbl -> SetPage(This,bszPage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentPropertySheet_GetVisible_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentPropertySheet_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPropertySheet_SetVisible_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentPropertySheet_SetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPropertySheet_GetPosition_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plLeft,
    /* [out] */ long __RPC_FAR *plTop);


void __RPC_STUB IAgentPropertySheet_GetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPropertySheet_GetSize_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plWidth,
    /* [out] */ long __RPC_FAR *plHeight);


void __RPC_STUB IAgentPropertySheet_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPropertySheet_GetPage_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszPage);


void __RPC_STUB IAgentPropertySheet_GetPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPropertySheet_SetPage_Proxy( 
    IAgentPropertySheet __RPC_FAR * This,
    /* [in] */ BSTR bszPage);


void __RPC_STUB IAgentPropertySheet_SetPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentPropertySheet_INTERFACE_DEFINED__ */


#ifndef __IAgentBalloon_INTERFACE_DEFINED__
#define __IAgentBalloon_INTERFACE_DEFINED__

/* interface IAgentBalloon */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentBalloon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7B93C8D-7B81-11D0-AC5F-00C04FD97575")
    IAgentBalloon : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEnabled( 
            /* [out] */ long __RPC_FAR *pbEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumLines( 
            /* [out] */ long __RPC_FAR *plLines) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumCharsPerLine( 
            /* [out] */ long __RPC_FAR *plCharsPerLine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontName( 
            /* [out] */ BSTR __RPC_FAR *pbszFontName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontSize( 
            /* [out] */ long __RPC_FAR *plFontSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontBold( 
            /* [out] */ long __RPC_FAR *pbFontBold) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontItalic( 
            /* [out] */ long __RPC_FAR *pbFontItalic) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontStrikethru( 
            /* [out] */ long __RPC_FAR *pbFontStrikethru) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontUnderline( 
            /* [out] */ long __RPC_FAR *pbFontUnderline) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetForeColor( 
            /* [out] */ long __RPC_FAR *plFGColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBackColor( 
            /* [out] */ long __RPC_FAR *plBGColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBorderColor( 
            /* [out] */ long __RPC_FAR *plBorderColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVisible( 
            /* [in] */ long bVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFontName( 
            /* [in] */ BSTR bszFontName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFontSize( 
            /* [in] */ long lFontSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFontCharSet( 
            /* [in] */ short sFontCharSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontCharSet( 
            /* [out] */ short __RPC_FAR *psFontCharSet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentBalloonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentBalloon __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentBalloon __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumLines )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLines);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumCharsPerLine )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plCharsPerLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontName )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontSize )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontBold )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontBold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontItalic )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontItalic);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontStrikethru )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontStrikethru);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontUnderline )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontUnderline);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetForeColor )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plFGColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBackColor )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plBGColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBorderColor )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plBorderColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontName )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ BSTR bszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontSize )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ long lFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontCharSet )( 
            IAgentBalloon __RPC_FAR * This,
            /* [in] */ short sFontCharSet);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontCharSet )( 
            IAgentBalloon __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *psFontCharSet);
        
        END_INTERFACE
    } IAgentBalloonVtbl;

    interface IAgentBalloon
    {
        CONST_VTBL struct IAgentBalloonVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentBalloon_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentBalloon_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentBalloon_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentBalloon_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentBalloon_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentBalloon_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentBalloon_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentBalloon_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentBalloon_GetNumLines(This,plLines)	\
    (This)->lpVtbl -> GetNumLines(This,plLines)

#define IAgentBalloon_GetNumCharsPerLine(This,plCharsPerLine)	\
    (This)->lpVtbl -> GetNumCharsPerLine(This,plCharsPerLine)

#define IAgentBalloon_GetFontName(This,pbszFontName)	\
    (This)->lpVtbl -> GetFontName(This,pbszFontName)

#define IAgentBalloon_GetFontSize(This,plFontSize)	\
    (This)->lpVtbl -> GetFontSize(This,plFontSize)

#define IAgentBalloon_GetFontBold(This,pbFontBold)	\
    (This)->lpVtbl -> GetFontBold(This,pbFontBold)

#define IAgentBalloon_GetFontItalic(This,pbFontItalic)	\
    (This)->lpVtbl -> GetFontItalic(This,pbFontItalic)

#define IAgentBalloon_GetFontStrikethru(This,pbFontStrikethru)	\
    (This)->lpVtbl -> GetFontStrikethru(This,pbFontStrikethru)

#define IAgentBalloon_GetFontUnderline(This,pbFontUnderline)	\
    (This)->lpVtbl -> GetFontUnderline(This,pbFontUnderline)

#define IAgentBalloon_GetForeColor(This,plFGColor)	\
    (This)->lpVtbl -> GetForeColor(This,plFGColor)

#define IAgentBalloon_GetBackColor(This,plBGColor)	\
    (This)->lpVtbl -> GetBackColor(This,plBGColor)

#define IAgentBalloon_GetBorderColor(This,plBorderColor)	\
    (This)->lpVtbl -> GetBorderColor(This,plBorderColor)

#define IAgentBalloon_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentBalloon_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentBalloon_SetFontName(This,bszFontName)	\
    (This)->lpVtbl -> SetFontName(This,bszFontName)

#define IAgentBalloon_SetFontSize(This,lFontSize)	\
    (This)->lpVtbl -> SetFontSize(This,lFontSize)

#define IAgentBalloon_SetFontCharSet(This,sFontCharSet)	\
    (This)->lpVtbl -> SetFontCharSet(This,sFontCharSet)

#define IAgentBalloon_GetFontCharSet(This,psFontCharSet)	\
    (This)->lpVtbl -> GetFontCharSet(This,psFontCharSet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentBalloon_GetEnabled_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbEnabled);


void __RPC_STUB IAgentBalloon_GetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetNumLines_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plLines);


void __RPC_STUB IAgentBalloon_GetNumLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetNumCharsPerLine_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plCharsPerLine);


void __RPC_STUB IAgentBalloon_GetNumCharsPerLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontName_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszFontName);


void __RPC_STUB IAgentBalloon_GetFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontSize_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plFontSize);


void __RPC_STUB IAgentBalloon_GetFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontBold_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbFontBold);


void __RPC_STUB IAgentBalloon_GetFontBold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontItalic_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbFontItalic);


void __RPC_STUB IAgentBalloon_GetFontItalic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontStrikethru_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbFontStrikethru);


void __RPC_STUB IAgentBalloon_GetFontStrikethru_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontUnderline_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbFontUnderline);


void __RPC_STUB IAgentBalloon_GetFontUnderline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetForeColor_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plFGColor);


void __RPC_STUB IAgentBalloon_GetForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetBackColor_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plBGColor);


void __RPC_STUB IAgentBalloon_GetBackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetBorderColor_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plBorderColor);


void __RPC_STUB IAgentBalloon_GetBorderColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_SetVisible_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentBalloon_SetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetVisible_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentBalloon_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_SetFontName_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [in] */ BSTR bszFontName);


void __RPC_STUB IAgentBalloon_SetFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_SetFontSize_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [in] */ long lFontSize);


void __RPC_STUB IAgentBalloon_SetFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_SetFontCharSet_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [in] */ short sFontCharSet);


void __RPC_STUB IAgentBalloon_SetFontCharSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloon_GetFontCharSet_Proxy( 
    IAgentBalloon __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *psFontCharSet);


void __RPC_STUB IAgentBalloon_GetFontCharSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentBalloon_INTERFACE_DEFINED__ */


#ifndef __IAgentBalloonEx_INTERFACE_DEFINED__
#define __IAgentBalloonEx_INTERFACE_DEFINED__

/* interface IAgentBalloonEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentBalloonEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D7A6D440-8872-11d1-9EC6-00C04FD7081F")
    IAgentBalloonEx : public IAgentBalloon
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetStyle( 
            /* [in] */ long lStyle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStyle( 
            /* [out] */ long __RPC_FAR *plStyle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNumLines( 
            /* [in] */ long lLines) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNumCharsPerLine( 
            /* [in] */ long lCharsPerLine) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentBalloonExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentBalloonEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentBalloonEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbEnabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumLines )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLines);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumCharsPerLine )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plCharsPerLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontName )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontSize )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontBold )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontBold);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontItalic )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontItalic);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontStrikethru )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontStrikethru);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontUnderline )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbFontUnderline);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetForeColor )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plFGColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBackColor )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plBGColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBorderColor )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plBorderColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontName )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ BSTR bszFontName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontSize )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ long lFontSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFontCharSet )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ short sFontCharSet);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontCharSet )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *psFontCharSet);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStyle )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ long lStyle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStyle )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plStyle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetNumLines )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ long lLines);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetNumCharsPerLine )( 
            IAgentBalloonEx __RPC_FAR * This,
            /* [in] */ long lCharsPerLine);
        
        END_INTERFACE
    } IAgentBalloonExVtbl;

    interface IAgentBalloonEx
    {
        CONST_VTBL struct IAgentBalloonExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentBalloonEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentBalloonEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentBalloonEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentBalloonEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentBalloonEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentBalloonEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentBalloonEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentBalloonEx_GetEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pbEnabled)

#define IAgentBalloonEx_GetNumLines(This,plLines)	\
    (This)->lpVtbl -> GetNumLines(This,plLines)

#define IAgentBalloonEx_GetNumCharsPerLine(This,plCharsPerLine)	\
    (This)->lpVtbl -> GetNumCharsPerLine(This,plCharsPerLine)

#define IAgentBalloonEx_GetFontName(This,pbszFontName)	\
    (This)->lpVtbl -> GetFontName(This,pbszFontName)

#define IAgentBalloonEx_GetFontSize(This,plFontSize)	\
    (This)->lpVtbl -> GetFontSize(This,plFontSize)

#define IAgentBalloonEx_GetFontBold(This,pbFontBold)	\
    (This)->lpVtbl -> GetFontBold(This,pbFontBold)

#define IAgentBalloonEx_GetFontItalic(This,pbFontItalic)	\
    (This)->lpVtbl -> GetFontItalic(This,pbFontItalic)

#define IAgentBalloonEx_GetFontStrikethru(This,pbFontStrikethru)	\
    (This)->lpVtbl -> GetFontStrikethru(This,pbFontStrikethru)

#define IAgentBalloonEx_GetFontUnderline(This,pbFontUnderline)	\
    (This)->lpVtbl -> GetFontUnderline(This,pbFontUnderline)

#define IAgentBalloonEx_GetForeColor(This,plFGColor)	\
    (This)->lpVtbl -> GetForeColor(This,plFGColor)

#define IAgentBalloonEx_GetBackColor(This,plBGColor)	\
    (This)->lpVtbl -> GetBackColor(This,plBGColor)

#define IAgentBalloonEx_GetBorderColor(This,plBorderColor)	\
    (This)->lpVtbl -> GetBorderColor(This,plBorderColor)

#define IAgentBalloonEx_SetVisible(This,bVisible)	\
    (This)->lpVtbl -> SetVisible(This,bVisible)

#define IAgentBalloonEx_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentBalloonEx_SetFontName(This,bszFontName)	\
    (This)->lpVtbl -> SetFontName(This,bszFontName)

#define IAgentBalloonEx_SetFontSize(This,lFontSize)	\
    (This)->lpVtbl -> SetFontSize(This,lFontSize)

#define IAgentBalloonEx_SetFontCharSet(This,sFontCharSet)	\
    (This)->lpVtbl -> SetFontCharSet(This,sFontCharSet)

#define IAgentBalloonEx_GetFontCharSet(This,psFontCharSet)	\
    (This)->lpVtbl -> GetFontCharSet(This,psFontCharSet)


#define IAgentBalloonEx_SetStyle(This,lStyle)	\
    (This)->lpVtbl -> SetStyle(This,lStyle)

#define IAgentBalloonEx_GetStyle(This,plStyle)	\
    (This)->lpVtbl -> GetStyle(This,plStyle)

#define IAgentBalloonEx_SetNumLines(This,lLines)	\
    (This)->lpVtbl -> SetNumLines(This,lLines)

#define IAgentBalloonEx_SetNumCharsPerLine(This,lCharsPerLine)	\
    (This)->lpVtbl -> SetNumCharsPerLine(This,lCharsPerLine)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentBalloonEx_SetStyle_Proxy( 
    IAgentBalloonEx __RPC_FAR * This,
    /* [in] */ long lStyle);


void __RPC_STUB IAgentBalloonEx_SetStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloonEx_GetStyle_Proxy( 
    IAgentBalloonEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plStyle);


void __RPC_STUB IAgentBalloonEx_GetStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloonEx_SetNumLines_Proxy( 
    IAgentBalloonEx __RPC_FAR * This,
    /* [in] */ long lLines);


void __RPC_STUB IAgentBalloonEx_SetNumLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentBalloonEx_SetNumCharsPerLine_Proxy( 
    IAgentBalloonEx __RPC_FAR * This,
    /* [in] */ long lCharsPerLine);


void __RPC_STUB IAgentBalloonEx_SetNumCharsPerLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentBalloonEx_INTERFACE_DEFINED__ */


#ifndef __IAgentCharacter_INTERFACE_DEFINED__
#define __IAgentCharacter_INTERFACE_DEFINED__

/* interface IAgentCharacter */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCharacter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7B93C8F-7B81-11D0-AC5F-00C04FD97575")
    IAgentCharacter : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ long __RPC_FAR *pbVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPosition( 
            /* [in] */ long lLeft,
            /* [in] */ long lTop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPosition( 
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSize( 
            /* [in] */ long lWidth,
            /* [in] */ long lHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR __RPC_FAR *pbszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ BSTR __RPC_FAR *pbszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTTSSpeed( 
            /* [out] */ long __RPC_FAR *pdwSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTTSPitch( 
            /* [out] */ short __RPC_FAR *pwPitch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Activate( 
            /* [in] */ short sState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIdleOn( 
            /* [in] */ long bOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdleOn( 
            /* [out] */ long __RPC_FAR *pbOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Prepare( 
            /* [in] */ long dwType,
            /* [in] */ BSTR bszName,
            /* [in] */ long bQueue,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Play( 
            /* [in] */ BSTR bszAnimation,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( 
            /* [in] */ long dwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopAll( 
            /* [in] */ long lTypes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Wait( 
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Interrupt( 
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Show( 
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Hide( 
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Speak( 
            /* [in] */ BSTR bszText,
            /* [in] */ BSTR bszUrl,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveTo( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ long lSpeed,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GestureAt( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMoveCause( 
            /* [out] */ long __RPC_FAR *pdwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisibilityCause( 
            /* [out] */ long __RPC_FAR *pdwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HasOtherClients( 
            /* [out] */ long __RPC_FAR *plNumOtherClients) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSoundEffectsOn( 
            /* [in] */ long bOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSoundEffectsOn( 
            /* [out] */ long __RPC_FAR *pbOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ BSTR bszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [in] */ BSTR bszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtraData( 
            /* [out] */ BSTR __RPC_FAR *pbszExtraData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCharacterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCharacter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCharacter __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPosition )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long lLeft,
            /* [in] */ long lTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPosition )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSize )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDescription )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszDescription);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTTSSpeed )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwSpeed);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTTSPitch )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *pwPitch);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Activate )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ short sState);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIdleOn )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIdleOn )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Prepare )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long dwType,
            /* [in] */ BSTR bszName,
            /* [in] */ long bQueue,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ BSTR bszAnimation,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long dwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopAll )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long lTypes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Wait )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Interrupt )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Show )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hide )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Speak )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ BSTR bszText,
            /* [in] */ BSTR bszUrl,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ long lSpeed,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GestureAt )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMoveCause )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisibilityCause )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HasOtherClients )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plNumOtherClients);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSoundEffectsOn )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ long bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSoundEffectsOn )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ BSTR bszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDescription )( 
            IAgentCharacter __RPC_FAR * This,
            /* [in] */ BSTR bszDescription);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExtraData )( 
            IAgentCharacter __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszExtraData);
        
        END_INTERFACE
    } IAgentCharacterVtbl;

    interface IAgentCharacter
    {
        CONST_VTBL struct IAgentCharacterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCharacter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCharacter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCharacter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCharacter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCharacter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCharacter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCharacter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCharacter_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCharacter_SetPosition(This,lLeft,lTop)	\
    (This)->lpVtbl -> SetPosition(This,lLeft,lTop)

#define IAgentCharacter_GetPosition(This,plLeft,plTop)	\
    (This)->lpVtbl -> GetPosition(This,plLeft,plTop)

#define IAgentCharacter_SetSize(This,lWidth,lHeight)	\
    (This)->lpVtbl -> SetSize(This,lWidth,lHeight)

#define IAgentCharacter_GetSize(This,plWidth,plHeight)	\
    (This)->lpVtbl -> GetSize(This,plWidth,plHeight)

#define IAgentCharacter_GetName(This,pbszName)	\
    (This)->lpVtbl -> GetName(This,pbszName)

#define IAgentCharacter_GetDescription(This,pbszDescription)	\
    (This)->lpVtbl -> GetDescription(This,pbszDescription)

#define IAgentCharacter_GetTTSSpeed(This,pdwSpeed)	\
    (This)->lpVtbl -> GetTTSSpeed(This,pdwSpeed)

#define IAgentCharacter_GetTTSPitch(This,pwPitch)	\
    (This)->lpVtbl -> GetTTSPitch(This,pwPitch)

#define IAgentCharacter_Activate(This,sState)	\
    (This)->lpVtbl -> Activate(This,sState)

#define IAgentCharacter_SetIdleOn(This,bOn)	\
    (This)->lpVtbl -> SetIdleOn(This,bOn)

#define IAgentCharacter_GetIdleOn(This,pbOn)	\
    (This)->lpVtbl -> GetIdleOn(This,pbOn)

#define IAgentCharacter_Prepare(This,dwType,bszName,bQueue,pdwReqID)	\
    (This)->lpVtbl -> Prepare(This,dwType,bszName,bQueue,pdwReqID)

#define IAgentCharacter_Play(This,bszAnimation,pdwReqID)	\
    (This)->lpVtbl -> Play(This,bszAnimation,pdwReqID)

#define IAgentCharacter_Stop(This,dwReqID)	\
    (This)->lpVtbl -> Stop(This,dwReqID)

#define IAgentCharacter_StopAll(This,lTypes)	\
    (This)->lpVtbl -> StopAll(This,lTypes)

#define IAgentCharacter_Wait(This,dwReqID,pdwReqID)	\
    (This)->lpVtbl -> Wait(This,dwReqID,pdwReqID)

#define IAgentCharacter_Interrupt(This,dwReqID,pdwReqID)	\
    (This)->lpVtbl -> Interrupt(This,dwReqID,pdwReqID)

#define IAgentCharacter_Show(This,bFast,pdwReqID)	\
    (This)->lpVtbl -> Show(This,bFast,pdwReqID)

#define IAgentCharacter_Hide(This,bFast,pdwReqID)	\
    (This)->lpVtbl -> Hide(This,bFast,pdwReqID)

#define IAgentCharacter_Speak(This,bszText,bszUrl,pdwReqID)	\
    (This)->lpVtbl -> Speak(This,bszText,bszUrl,pdwReqID)

#define IAgentCharacter_MoveTo(This,x,y,lSpeed,pdwReqID)	\
    (This)->lpVtbl -> MoveTo(This,x,y,lSpeed,pdwReqID)

#define IAgentCharacter_GestureAt(This,x,y,pdwReqID)	\
    (This)->lpVtbl -> GestureAt(This,x,y,pdwReqID)

#define IAgentCharacter_GetMoveCause(This,pdwCause)	\
    (This)->lpVtbl -> GetMoveCause(This,pdwCause)

#define IAgentCharacter_GetVisibilityCause(This,pdwCause)	\
    (This)->lpVtbl -> GetVisibilityCause(This,pdwCause)

#define IAgentCharacter_HasOtherClients(This,plNumOtherClients)	\
    (This)->lpVtbl -> HasOtherClients(This,plNumOtherClients)

#define IAgentCharacter_SetSoundEffectsOn(This,bOn)	\
    (This)->lpVtbl -> SetSoundEffectsOn(This,bOn)

#define IAgentCharacter_GetSoundEffectsOn(This,pbOn)	\
    (This)->lpVtbl -> GetSoundEffectsOn(This,pbOn)

#define IAgentCharacter_SetName(This,bszName)	\
    (This)->lpVtbl -> SetName(This,bszName)

#define IAgentCharacter_SetDescription(This,bszDescription)	\
    (This)->lpVtbl -> SetDescription(This,bszDescription)

#define IAgentCharacter_GetExtraData(This,pbszExtraData)	\
    (This)->lpVtbl -> GetExtraData(This,pbszExtraData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCharacter_GetVisible_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbVisible);


void __RPC_STUB IAgentCharacter_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetPosition_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long lLeft,
    /* [in] */ long lTop);


void __RPC_STUB IAgentCharacter_SetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetPosition_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plLeft,
    /* [out] */ long __RPC_FAR *plTop);


void __RPC_STUB IAgentCharacter_GetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetSize_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long lWidth,
    /* [in] */ long lHeight);


void __RPC_STUB IAgentCharacter_SetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetSize_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plWidth,
    /* [out] */ long __RPC_FAR *plHeight);


void __RPC_STUB IAgentCharacter_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetName_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszName);


void __RPC_STUB IAgentCharacter_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetDescription_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszDescription);


void __RPC_STUB IAgentCharacter_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetTTSSpeed_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwSpeed);


void __RPC_STUB IAgentCharacter_GetTTSSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetTTSPitch_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *pwPitch);


void __RPC_STUB IAgentCharacter_GetTTSPitch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Activate_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ short sState);


void __RPC_STUB IAgentCharacter_Activate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetIdleOn_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long bOn);


void __RPC_STUB IAgentCharacter_SetIdleOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetIdleOn_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbOn);


void __RPC_STUB IAgentCharacter_GetIdleOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Prepare_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long dwType,
    /* [in] */ BSTR bszName,
    /* [in] */ long bQueue,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Prepare_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Play_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ BSTR bszAnimation,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Play_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Stop_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long dwReqID);


void __RPC_STUB IAgentCharacter_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_StopAll_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long lTypes);


void __RPC_STUB IAgentCharacter_StopAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Wait_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long dwReqID,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Wait_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Interrupt_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long dwReqID,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Interrupt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Show_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long bFast,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Show_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Hide_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long bFast,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Hide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_Speak_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ BSTR bszText,
    /* [in] */ BSTR bszUrl,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_Speak_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_MoveTo_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [in] */ long lSpeed,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_MoveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GestureAt_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacter_GestureAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetMoveCause_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwCause);


void __RPC_STUB IAgentCharacter_GetMoveCause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetVisibilityCause_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pdwCause);


void __RPC_STUB IAgentCharacter_GetVisibilityCause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_HasOtherClients_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plNumOtherClients);


void __RPC_STUB IAgentCharacter_HasOtherClients_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetSoundEffectsOn_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ long bOn);


void __RPC_STUB IAgentCharacter_SetSoundEffectsOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetSoundEffectsOn_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbOn);


void __RPC_STUB IAgentCharacter_GetSoundEffectsOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetName_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ BSTR bszName);


void __RPC_STUB IAgentCharacter_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_SetDescription_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [in] */ BSTR bszDescription);


void __RPC_STUB IAgentCharacter_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacter_GetExtraData_Proxy( 
    IAgentCharacter __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszExtraData);


void __RPC_STUB IAgentCharacter_GetExtraData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCharacter_INTERFACE_DEFINED__ */


#ifndef __IAgentCharacterEx_INTERFACE_DEFINED__
#define __IAgentCharacterEx_INTERFACE_DEFINED__

/* interface IAgentCharacterEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentCharacterEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("98BBE491-2EED-11d1-ACAC-00C04FD97575")
    IAgentCharacterEx : public IAgentCharacter
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShowPopupMenu( 
            /* [in] */ short x,
            /* [in] */ short y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAutoPopupMenu( 
            /* [in] */ long bAutoPopupMenu) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAutoPopupMenu( 
            /* [out] */ long __RPC_FAR *pbAutoPopupMenu) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpFileName( 
            /* [out] */ BSTR __RPC_FAR *pbszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHelpFileName( 
            /* [in] */ BSTR bszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHelpModeOn( 
            /* [in] */ long bHelpModeOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpModeOn( 
            /* [out] */ long __RPC_FAR *pbHelpModeOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHelpContextID( 
            /* [in] */ long ulID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpContextID( 
            /* [out] */ long __RPC_FAR *pulID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActive( 
            /* [out] */ short __RPC_FAR *psState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Listen( 
            /* [in] */ long bListen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLanguageID( 
            /* [in] */ long langid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLanguageID( 
            /* [out] */ long __RPC_FAR *plangid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTTSModeID( 
            /* [out] */ BSTR __RPC_FAR *pbszModeID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTTSModeID( 
            /* [in] */ BSTR bszModeID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSRModeID( 
            /* [out] */ BSTR __RPC_FAR *pbszModeID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSRModeID( 
            /* [in] */ BSTR bszModeID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGUID( 
            /* [out] */ BSTR __RPC_FAR *pbszID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOriginalSize( 
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Think( 
            /* [in] */ BSTR bszText,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [out] */ short __RPC_FAR *psMajor,
            /* [out] */ short __RPC_FAR *psMinor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAnimationNames( 
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *punkEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSRStatus( 
            /* [out] */ long __RPC_FAR *plStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCharacterExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCharacterEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCharacterEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPosition )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long lLeft,
            /* [in] */ long lTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPosition )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLeft,
            /* [out] */ long __RPC_FAR *plTop);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSize )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDescription )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszDescription);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTTSSpeed )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwSpeed);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTTSPitch )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *pwPitch);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Activate )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ short sState);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIdleOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIdleOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Prepare )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long dwType,
            /* [in] */ BSTR bszName,
            /* [in] */ long bQueue,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszAnimation,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long dwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopAll )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long lTypes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Wait )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Interrupt )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long dwReqID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Show )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hide )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bFast,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Speak )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszText,
            /* [in] */ BSTR bszUrl,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ long lSpeed,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GestureAt )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMoveCause )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisibilityCause )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pdwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HasOtherClients )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plNumOtherClients);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSoundEffectsOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSoundEffectsOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDescription )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszDescription);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExtraData )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszExtraData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowPopupMenu )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoPopupMenu )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bAutoPopupMenu);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoPopupMenu )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbAutoPopupMenu);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpFileName )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpFileName )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpModeOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bHelpModeOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpModeOn )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbHelpModeOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHelpContextID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long ulID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpContextID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pulID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetActive )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *psState);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Listen )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long bListen);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLanguageID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ long langid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLanguageID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plangid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTTSModeID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszModeID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTTSModeID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszModeID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSRModeID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszModeID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSRModeID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszModeID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGUID )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbszID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOriginalSize )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plWidth,
            /* [out] */ long __RPC_FAR *plHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Think )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [in] */ BSTR bszText,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVersion )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *psMajor,
            /* [out] */ short __RPC_FAR *psMinor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnimationNames )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *punkEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSRStatus )( 
            IAgentCharacterEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plStatus);
        
        END_INTERFACE
    } IAgentCharacterExVtbl;

    interface IAgentCharacterEx
    {
        CONST_VTBL struct IAgentCharacterExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCharacterEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCharacterEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCharacterEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCharacterEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentCharacterEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentCharacterEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentCharacterEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentCharacterEx_GetVisible(This,pbVisible)	\
    (This)->lpVtbl -> GetVisible(This,pbVisible)

#define IAgentCharacterEx_SetPosition(This,lLeft,lTop)	\
    (This)->lpVtbl -> SetPosition(This,lLeft,lTop)

#define IAgentCharacterEx_GetPosition(This,plLeft,plTop)	\
    (This)->lpVtbl -> GetPosition(This,plLeft,plTop)

#define IAgentCharacterEx_SetSize(This,lWidth,lHeight)	\
    (This)->lpVtbl -> SetSize(This,lWidth,lHeight)

#define IAgentCharacterEx_GetSize(This,plWidth,plHeight)	\
    (This)->lpVtbl -> GetSize(This,plWidth,plHeight)

#define IAgentCharacterEx_GetName(This,pbszName)	\
    (This)->lpVtbl -> GetName(This,pbszName)

#define IAgentCharacterEx_GetDescription(This,pbszDescription)	\
    (This)->lpVtbl -> GetDescription(This,pbszDescription)

#define IAgentCharacterEx_GetTTSSpeed(This,pdwSpeed)	\
    (This)->lpVtbl -> GetTTSSpeed(This,pdwSpeed)

#define IAgentCharacterEx_GetTTSPitch(This,pwPitch)	\
    (This)->lpVtbl -> GetTTSPitch(This,pwPitch)

#define IAgentCharacterEx_Activate(This,sState)	\
    (This)->lpVtbl -> Activate(This,sState)

#define IAgentCharacterEx_SetIdleOn(This,bOn)	\
    (This)->lpVtbl -> SetIdleOn(This,bOn)

#define IAgentCharacterEx_GetIdleOn(This,pbOn)	\
    (This)->lpVtbl -> GetIdleOn(This,pbOn)

#define IAgentCharacterEx_Prepare(This,dwType,bszName,bQueue,pdwReqID)	\
    (This)->lpVtbl -> Prepare(This,dwType,bszName,bQueue,pdwReqID)

#define IAgentCharacterEx_Play(This,bszAnimation,pdwReqID)	\
    (This)->lpVtbl -> Play(This,bszAnimation,pdwReqID)

#define IAgentCharacterEx_Stop(This,dwReqID)	\
    (This)->lpVtbl -> Stop(This,dwReqID)

#define IAgentCharacterEx_StopAll(This,lTypes)	\
    (This)->lpVtbl -> StopAll(This,lTypes)

#define IAgentCharacterEx_Wait(This,dwReqID,pdwReqID)	\
    (This)->lpVtbl -> Wait(This,dwReqID,pdwReqID)

#define IAgentCharacterEx_Interrupt(This,dwReqID,pdwReqID)	\
    (This)->lpVtbl -> Interrupt(This,dwReqID,pdwReqID)

#define IAgentCharacterEx_Show(This,bFast,pdwReqID)	\
    (This)->lpVtbl -> Show(This,bFast,pdwReqID)

#define IAgentCharacterEx_Hide(This,bFast,pdwReqID)	\
    (This)->lpVtbl -> Hide(This,bFast,pdwReqID)

#define IAgentCharacterEx_Speak(This,bszText,bszUrl,pdwReqID)	\
    (This)->lpVtbl -> Speak(This,bszText,bszUrl,pdwReqID)

#define IAgentCharacterEx_MoveTo(This,x,y,lSpeed,pdwReqID)	\
    (This)->lpVtbl -> MoveTo(This,x,y,lSpeed,pdwReqID)

#define IAgentCharacterEx_GestureAt(This,x,y,pdwReqID)	\
    (This)->lpVtbl -> GestureAt(This,x,y,pdwReqID)

#define IAgentCharacterEx_GetMoveCause(This,pdwCause)	\
    (This)->lpVtbl -> GetMoveCause(This,pdwCause)

#define IAgentCharacterEx_GetVisibilityCause(This,pdwCause)	\
    (This)->lpVtbl -> GetVisibilityCause(This,pdwCause)

#define IAgentCharacterEx_HasOtherClients(This,plNumOtherClients)	\
    (This)->lpVtbl -> HasOtherClients(This,plNumOtherClients)

#define IAgentCharacterEx_SetSoundEffectsOn(This,bOn)	\
    (This)->lpVtbl -> SetSoundEffectsOn(This,bOn)

#define IAgentCharacterEx_GetSoundEffectsOn(This,pbOn)	\
    (This)->lpVtbl -> GetSoundEffectsOn(This,pbOn)

#define IAgentCharacterEx_SetName(This,bszName)	\
    (This)->lpVtbl -> SetName(This,bszName)

#define IAgentCharacterEx_SetDescription(This,bszDescription)	\
    (This)->lpVtbl -> SetDescription(This,bszDescription)

#define IAgentCharacterEx_GetExtraData(This,pbszExtraData)	\
    (This)->lpVtbl -> GetExtraData(This,pbszExtraData)


#define IAgentCharacterEx_ShowPopupMenu(This,x,y)	\
    (This)->lpVtbl -> ShowPopupMenu(This,x,y)

#define IAgentCharacterEx_SetAutoPopupMenu(This,bAutoPopupMenu)	\
    (This)->lpVtbl -> SetAutoPopupMenu(This,bAutoPopupMenu)

#define IAgentCharacterEx_GetAutoPopupMenu(This,pbAutoPopupMenu)	\
    (This)->lpVtbl -> GetAutoPopupMenu(This,pbAutoPopupMenu)

#define IAgentCharacterEx_GetHelpFileName(This,pbszName)	\
    (This)->lpVtbl -> GetHelpFileName(This,pbszName)

#define IAgentCharacterEx_SetHelpFileName(This,bszName)	\
    (This)->lpVtbl -> SetHelpFileName(This,bszName)

#define IAgentCharacterEx_SetHelpModeOn(This,bHelpModeOn)	\
    (This)->lpVtbl -> SetHelpModeOn(This,bHelpModeOn)

#define IAgentCharacterEx_GetHelpModeOn(This,pbHelpModeOn)	\
    (This)->lpVtbl -> GetHelpModeOn(This,pbHelpModeOn)

#define IAgentCharacterEx_SetHelpContextID(This,ulID)	\
    (This)->lpVtbl -> SetHelpContextID(This,ulID)

#define IAgentCharacterEx_GetHelpContextID(This,pulID)	\
    (This)->lpVtbl -> GetHelpContextID(This,pulID)

#define IAgentCharacterEx_GetActive(This,psState)	\
    (This)->lpVtbl -> GetActive(This,psState)

#define IAgentCharacterEx_Listen(This,bListen)	\
    (This)->lpVtbl -> Listen(This,bListen)

#define IAgentCharacterEx_SetLanguageID(This,langid)	\
    (This)->lpVtbl -> SetLanguageID(This,langid)

#define IAgentCharacterEx_GetLanguageID(This,plangid)	\
    (This)->lpVtbl -> GetLanguageID(This,plangid)

#define IAgentCharacterEx_GetTTSModeID(This,pbszModeID)	\
    (This)->lpVtbl -> GetTTSModeID(This,pbszModeID)

#define IAgentCharacterEx_SetTTSModeID(This,bszModeID)	\
    (This)->lpVtbl -> SetTTSModeID(This,bszModeID)

#define IAgentCharacterEx_GetSRModeID(This,pbszModeID)	\
    (This)->lpVtbl -> GetSRModeID(This,pbszModeID)

#define IAgentCharacterEx_SetSRModeID(This,bszModeID)	\
    (This)->lpVtbl -> SetSRModeID(This,bszModeID)

#define IAgentCharacterEx_GetGUID(This,pbszID)	\
    (This)->lpVtbl -> GetGUID(This,pbszID)

#define IAgentCharacterEx_GetOriginalSize(This,plWidth,plHeight)	\
    (This)->lpVtbl -> GetOriginalSize(This,plWidth,plHeight)

#define IAgentCharacterEx_Think(This,bszText,pdwReqID)	\
    (This)->lpVtbl -> Think(This,bszText,pdwReqID)

#define IAgentCharacterEx_GetVersion(This,psMajor,psMinor)	\
    (This)->lpVtbl -> GetVersion(This,psMajor,psMinor)

#define IAgentCharacterEx_GetAnimationNames(This,punkEnum)	\
    (This)->lpVtbl -> GetAnimationNames(This,punkEnum)

#define IAgentCharacterEx_GetSRStatus(This,plStatus)	\
    (This)->lpVtbl -> GetSRStatus(This,plStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCharacterEx_ShowPopupMenu_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y);


void __RPC_STUB IAgentCharacterEx_ShowPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetAutoPopupMenu_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ long bAutoPopupMenu);


void __RPC_STUB IAgentCharacterEx_SetAutoPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetAutoPopupMenu_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbAutoPopupMenu);


void __RPC_STUB IAgentCharacterEx_GetAutoPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetHelpFileName_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszName);


void __RPC_STUB IAgentCharacterEx_GetHelpFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetHelpFileName_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR bszName);


void __RPC_STUB IAgentCharacterEx_SetHelpFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetHelpModeOn_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ long bHelpModeOn);


void __RPC_STUB IAgentCharacterEx_SetHelpModeOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetHelpModeOn_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbHelpModeOn);


void __RPC_STUB IAgentCharacterEx_GetHelpModeOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetHelpContextID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ long ulID);


void __RPC_STUB IAgentCharacterEx_SetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetHelpContextID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pulID);


void __RPC_STUB IAgentCharacterEx_GetHelpContextID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetActive_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *psState);


void __RPC_STUB IAgentCharacterEx_GetActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_Listen_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ long bListen);


void __RPC_STUB IAgentCharacterEx_Listen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetLanguageID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ long langid);


void __RPC_STUB IAgentCharacterEx_SetLanguageID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetLanguageID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plangid);


void __RPC_STUB IAgentCharacterEx_GetLanguageID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetTTSModeID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszModeID);


void __RPC_STUB IAgentCharacterEx_GetTTSModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetTTSModeID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR bszModeID);


void __RPC_STUB IAgentCharacterEx_SetTTSModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetSRModeID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszModeID);


void __RPC_STUB IAgentCharacterEx_GetSRModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_SetSRModeID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR bszModeID);


void __RPC_STUB IAgentCharacterEx_SetSRModeID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetGUID_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbszID);


void __RPC_STUB IAgentCharacterEx_GetGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetOriginalSize_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plWidth,
    /* [out] */ long __RPC_FAR *plHeight);


void __RPC_STUB IAgentCharacterEx_GetOriginalSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_Think_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [in] */ BSTR bszText,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgentCharacterEx_Think_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetVersion_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *psMajor,
    /* [out] */ short __RPC_FAR *psMinor);


void __RPC_STUB IAgentCharacterEx_GetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetAnimationNames_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *punkEnum);


void __RPC_STUB IAgentCharacterEx_GetAnimationNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentCharacterEx_GetSRStatus_Proxy( 
    IAgentCharacterEx __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plStatus);


void __RPC_STUB IAgentCharacterEx_GetSRStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCharacterEx_INTERFACE_DEFINED__ */


#ifndef __IAgent_INTERFACE_DEFINED__
#define __IAgent_INTERFACE_DEFINED__

/* interface IAgent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7B93C91-7B81-11D0-AC5F-00C04FD97575")
    IAgent : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ VARIANT vLoadKey,
            /* [out] */ long __RPC_FAR *pdwCharID,
            /* [out] */ long __RPC_FAR *pdwReqID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unload( 
            /* [in] */ long dwCharID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Register( 
            /* [in] */ IUnknown __RPC_FAR *punkNotifySink,
            /* [out] */ long __RPC_FAR *pdwSinkID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unregister( 
            /* [in] */ long dwSinkID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCharacter( 
            /* [in] */ long dwCharID,
            /* [out] */ IDispatch __RPC_FAR *__RPC_FAR *ppunkCharacter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSuspended( 
            /* [out] */ long __RPC_FAR *pbSuspended) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IAgent __RPC_FAR * This,
            /* [in] */ VARIANT vLoadKey,
            /* [out] */ long __RPC_FAR *pdwCharID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unload )( 
            IAgent __RPC_FAR * This,
            /* [in] */ long dwCharID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Register )( 
            IAgent __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *punkNotifySink,
            /* [out] */ long __RPC_FAR *pdwSinkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unregister )( 
            IAgent __RPC_FAR * This,
            /* [in] */ long dwSinkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCharacter )( 
            IAgent __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [out] */ IDispatch __RPC_FAR *__RPC_FAR *ppunkCharacter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSuspended )( 
            IAgent __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbSuspended);
        
        END_INTERFACE
    } IAgentVtbl;

    interface IAgent
    {
        CONST_VTBL struct IAgentVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgent_Load(This,vLoadKey,pdwCharID,pdwReqID)	\
    (This)->lpVtbl -> Load(This,vLoadKey,pdwCharID,pdwReqID)

#define IAgent_Unload(This,dwCharID)	\
    (This)->lpVtbl -> Unload(This,dwCharID)

#define IAgent_Register(This,punkNotifySink,pdwSinkID)	\
    (This)->lpVtbl -> Register(This,punkNotifySink,pdwSinkID)

#define IAgent_Unregister(This,dwSinkID)	\
    (This)->lpVtbl -> Unregister(This,dwSinkID)

#define IAgent_GetCharacter(This,dwCharID,ppunkCharacter)	\
    (This)->lpVtbl -> GetCharacter(This,dwCharID,ppunkCharacter)

#define IAgent_GetSuspended(This,pbSuspended)	\
    (This)->lpVtbl -> GetSuspended(This,pbSuspended)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgent_Load_Proxy( 
    IAgent __RPC_FAR * This,
    /* [in] */ VARIANT vLoadKey,
    /* [out] */ long __RPC_FAR *pdwCharID,
    /* [out] */ long __RPC_FAR *pdwReqID);


void __RPC_STUB IAgent_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgent_Unload_Proxy( 
    IAgent __RPC_FAR * This,
    /* [in] */ long dwCharID);


void __RPC_STUB IAgent_Unload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgent_Register_Proxy( 
    IAgent __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *punkNotifySink,
    /* [out] */ long __RPC_FAR *pdwSinkID);


void __RPC_STUB IAgent_Register_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgent_Unregister_Proxy( 
    IAgent __RPC_FAR * This,
    /* [in] */ long dwSinkID);


void __RPC_STUB IAgent_Unregister_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgent_GetCharacter_Proxy( 
    IAgent __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [out] */ IDispatch __RPC_FAR *__RPC_FAR *ppunkCharacter);


void __RPC_STUB IAgent_GetCharacter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgent_GetSuspended_Proxy( 
    IAgent __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pbSuspended);


void __RPC_STUB IAgent_GetSuspended_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgent_INTERFACE_DEFINED__ */


#ifndef __IAgentEx_INTERFACE_DEFINED__
#define __IAgentEx_INTERFACE_DEFINED__

/* interface IAgentEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("48D12BA0-5B77-11d1-9EC1-00C04FD7081F")
    IAgentEx : public IAgent
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCharacterEx( 
            /* [in] */ long dwCharID,
            /* [out] */ IAgentCharacterEx __RPC_FAR *__RPC_FAR *ppCharacterEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [out] */ short __RPC_FAR *psMajor,
            /* [out] */ short __RPC_FAR *psMinor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowDefaultCharacterProperties( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ long bUseDefaultPosition) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ VARIANT vLoadKey,
            /* [out] */ long __RPC_FAR *pdwCharID,
            /* [out] */ long __RPC_FAR *pdwReqID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unload )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ long dwCharID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Register )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *punkNotifySink,
            /* [out] */ long __RPC_FAR *pdwSinkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unregister )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ long dwSinkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCharacter )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [out] */ IDispatch __RPC_FAR *__RPC_FAR *ppunkCharacter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSuspended )( 
            IAgentEx __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pbSuspended);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCharacterEx )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [out] */ IAgentCharacterEx __RPC_FAR *__RPC_FAR *ppCharacterEx);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVersion )( 
            IAgentEx __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *psMajor,
            /* [out] */ short __RPC_FAR *psMinor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowDefaultCharacterProperties )( 
            IAgentEx __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ long bUseDefaultPosition);
        
        END_INTERFACE
    } IAgentExVtbl;

    interface IAgentEx
    {
        CONST_VTBL struct IAgentExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentEx_Load(This,vLoadKey,pdwCharID,pdwReqID)	\
    (This)->lpVtbl -> Load(This,vLoadKey,pdwCharID,pdwReqID)

#define IAgentEx_Unload(This,dwCharID)	\
    (This)->lpVtbl -> Unload(This,dwCharID)

#define IAgentEx_Register(This,punkNotifySink,pdwSinkID)	\
    (This)->lpVtbl -> Register(This,punkNotifySink,pdwSinkID)

#define IAgentEx_Unregister(This,dwSinkID)	\
    (This)->lpVtbl -> Unregister(This,dwSinkID)

#define IAgentEx_GetCharacter(This,dwCharID,ppunkCharacter)	\
    (This)->lpVtbl -> GetCharacter(This,dwCharID,ppunkCharacter)

#define IAgentEx_GetSuspended(This,pbSuspended)	\
    (This)->lpVtbl -> GetSuspended(This,pbSuspended)


#define IAgentEx_GetCharacterEx(This,dwCharID,ppCharacterEx)	\
    (This)->lpVtbl -> GetCharacterEx(This,dwCharID,ppCharacterEx)

#define IAgentEx_GetVersion(This,psMajor,psMinor)	\
    (This)->lpVtbl -> GetVersion(This,psMajor,psMinor)

#define IAgentEx_ShowDefaultCharacterProperties(This,x,y,bUseDefaultPosition)	\
    (This)->lpVtbl -> ShowDefaultCharacterProperties(This,x,y,bUseDefaultPosition)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentEx_GetCharacterEx_Proxy( 
    IAgentEx __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [out] */ IAgentCharacterEx __RPC_FAR *__RPC_FAR *ppCharacterEx);


void __RPC_STUB IAgentEx_GetCharacterEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentEx_GetVersion_Proxy( 
    IAgentEx __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *psMajor,
    /* [out] */ short __RPC_FAR *psMinor);


void __RPC_STUB IAgentEx_GetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentEx_ShowDefaultCharacterProperties_Proxy( 
    IAgentEx __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [in] */ long bUseDefaultPosition);


void __RPC_STUB IAgentEx_ShowDefaultCharacterProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentEx_INTERFACE_DEFINED__ */


#ifndef __IAgentNotifySink_INTERFACE_DEFINED__
#define __IAgentNotifySink_INTERFACE_DEFINED__

/* interface IAgentNotifySink */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentNotifySink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00D18159-8466-11D0-AC63-00C04FD97575")
    IAgentNotifySink : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Command( 
            /* [in] */ long dwCommandID,
            /* [in] */ IUnknown __RPC_FAR *punkUserInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivateInputState( 
            /* [in] */ long dwCharID,
            /* [in] */ long bActivated) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Restart( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Shutdown( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VisibleState( 
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible,
            /* [in] */ long dwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Click( 
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DblClick( 
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DragStart( 
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DragComplete( 
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestStart( 
            /* [in] */ long dwRequestID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestComplete( 
            /* [in] */ long dwRequestID,
            /* [in] */ long hrStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BookMark( 
            /* [in] */ long dwBookMarkID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Idle( 
            /* [in] */ long dwCharID,
            /* [in] */ long bStart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ long dwCharID,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ long dwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Size( 
            /* [in] */ long dwCharID,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BalloonVisibleState( 
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentNotifySinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentNotifySink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentNotifySink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Command )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCommandID,
            /* [in] */ IUnknown __RPC_FAR *punkUserInput);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateInputState )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bActivated);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Restart )( 
            IAgentNotifySink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Shutdown )( 
            IAgentNotifySink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *VisibleState )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Click )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DblClick )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DragStart )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DragComplete )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestStart )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwRequestID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestComplete )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwRequestID,
            /* [in] */ long hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BookMark )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwBookMarkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Idle )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bStart);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Move )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Size )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BalloonVisibleState )( 
            IAgentNotifySink __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible);
        
        END_INTERFACE
    } IAgentNotifySinkVtbl;

    interface IAgentNotifySink
    {
        CONST_VTBL struct IAgentNotifySinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentNotifySink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentNotifySink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentNotifySink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentNotifySink_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentNotifySink_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentNotifySink_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentNotifySink_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentNotifySink_Command(This,dwCommandID,punkUserInput)	\
    (This)->lpVtbl -> Command(This,dwCommandID,punkUserInput)

#define IAgentNotifySink_ActivateInputState(This,dwCharID,bActivated)	\
    (This)->lpVtbl -> ActivateInputState(This,dwCharID,bActivated)

#define IAgentNotifySink_Restart(This)	\
    (This)->lpVtbl -> Restart(This)

#define IAgentNotifySink_Shutdown(This)	\
    (This)->lpVtbl -> Shutdown(This)

#define IAgentNotifySink_VisibleState(This,dwCharID,bVisible,dwCause)	\
    (This)->lpVtbl -> VisibleState(This,dwCharID,bVisible,dwCause)

#define IAgentNotifySink_Click(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> Click(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySink_DblClick(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DblClick(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySink_DragStart(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DragStart(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySink_DragComplete(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DragComplete(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySink_RequestStart(This,dwRequestID)	\
    (This)->lpVtbl -> RequestStart(This,dwRequestID)

#define IAgentNotifySink_RequestComplete(This,dwRequestID,hrStatus)	\
    (This)->lpVtbl -> RequestComplete(This,dwRequestID,hrStatus)

#define IAgentNotifySink_BookMark(This,dwBookMarkID)	\
    (This)->lpVtbl -> BookMark(This,dwBookMarkID)

#define IAgentNotifySink_Idle(This,dwCharID,bStart)	\
    (This)->lpVtbl -> Idle(This,dwCharID,bStart)

#define IAgentNotifySink_Move(This,dwCharID,x,y,dwCause)	\
    (This)->lpVtbl -> Move(This,dwCharID,x,y,dwCause)

#define IAgentNotifySink_Size(This,dwCharID,lWidth,lHeight)	\
    (This)->lpVtbl -> Size(This,dwCharID,lWidth,lHeight)

#define IAgentNotifySink_BalloonVisibleState(This,dwCharID,bVisible)	\
    (This)->lpVtbl -> BalloonVisibleState(This,dwCharID,bVisible)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentNotifySink_Command_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCommandID,
    /* [in] */ IUnknown __RPC_FAR *punkUserInput);


void __RPC_STUB IAgentNotifySink_Command_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_ActivateInputState_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long bActivated);


void __RPC_STUB IAgentNotifySink_ActivateInputState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Restart_Proxy( 
    IAgentNotifySink __RPC_FAR * This);


void __RPC_STUB IAgentNotifySink_Restart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Shutdown_Proxy( 
    IAgentNotifySink __RPC_FAR * This);


void __RPC_STUB IAgentNotifySink_Shutdown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_VisibleState_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long bVisible,
    /* [in] */ long dwCause);


void __RPC_STUB IAgentNotifySink_VisibleState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Click_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ short fwKeys,
    /* [in] */ long x,
    /* [in] */ long y);


void __RPC_STUB IAgentNotifySink_Click_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_DblClick_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ short fwKeys,
    /* [in] */ long x,
    /* [in] */ long y);


void __RPC_STUB IAgentNotifySink_DblClick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_DragStart_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ short fwKeys,
    /* [in] */ long x,
    /* [in] */ long y);


void __RPC_STUB IAgentNotifySink_DragStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_DragComplete_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ short fwKeys,
    /* [in] */ long x,
    /* [in] */ long y);


void __RPC_STUB IAgentNotifySink_DragComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_RequestStart_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwRequestID);


void __RPC_STUB IAgentNotifySink_RequestStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_RequestComplete_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwRequestID,
    /* [in] */ long hrStatus);


void __RPC_STUB IAgentNotifySink_RequestComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_BookMark_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwBookMarkID);


void __RPC_STUB IAgentNotifySink_BookMark_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Idle_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long bStart);


void __RPC_STUB IAgentNotifySink_Idle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Move_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long x,
    /* [in] */ long y,
    /* [in] */ long dwCause);


void __RPC_STUB IAgentNotifySink_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_Size_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long lWidth,
    /* [in] */ long lHeight);


void __RPC_STUB IAgentNotifySink_Size_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySink_BalloonVisibleState_Proxy( 
    IAgentNotifySink __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long bVisible);


void __RPC_STUB IAgentNotifySink_BalloonVisibleState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentNotifySink_INTERFACE_DEFINED__ */


#ifndef __IAgentNotifySinkEx_INTERFACE_DEFINED__
#define __IAgentNotifySinkEx_INTERFACE_DEFINED__

/* interface IAgentNotifySinkEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgentNotifySinkEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08C75162-3C9C-11d1-91FE-00C04FD701A5")
    IAgentNotifySinkEx : public IAgentNotifySink
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE HelpComplete( 
            /* [in] */ long dwCharID,
            /* [in] */ long dwCommandID,
            /* [in] */ long dwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ListeningState( 
            /* [in] */ long dwCharID,
            /* [in] */ long bListening,
            /* [in] */ long dwCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DefaultCharacterChange( 
            /* [in] */ BSTR bszGUID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AgentPropertyChange( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActiveClientChange( 
            /* [in] */ long dwCharID,
            /* [in] */ long lStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentNotifySinkExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentNotifySinkEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentNotifySinkEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Command )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCommandID,
            /* [in] */ IUnknown __RPC_FAR *punkUserInput);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateInputState )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bActivated);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Restart )( 
            IAgentNotifySinkEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Shutdown )( 
            IAgentNotifySinkEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *VisibleState )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Click )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DblClick )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DragStart )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DragComplete )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ short fwKeys,
            /* [in] */ long x,
            /* [in] */ long y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestStart )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwRequestID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestComplete )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwRequestID,
            /* [in] */ long hrStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BookMark )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwBookMarkID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Idle )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bStart);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Move )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Size )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BalloonVisibleState )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bVisible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HelpComplete )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long dwCommandID,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ListeningState )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long bListening,
            /* [in] */ long dwCause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DefaultCharacterChange )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ BSTR bszGUID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AgentPropertyChange )( 
            IAgentNotifySinkEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActiveClientChange )( 
            IAgentNotifySinkEx __RPC_FAR * This,
            /* [in] */ long dwCharID,
            /* [in] */ long lStatus);
        
        END_INTERFACE
    } IAgentNotifySinkExVtbl;

    interface IAgentNotifySinkEx
    {
        CONST_VTBL struct IAgentNotifySinkExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentNotifySinkEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentNotifySinkEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentNotifySinkEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentNotifySinkEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAgentNotifySinkEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAgentNotifySinkEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAgentNotifySinkEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAgentNotifySinkEx_Command(This,dwCommandID,punkUserInput)	\
    (This)->lpVtbl -> Command(This,dwCommandID,punkUserInput)

#define IAgentNotifySinkEx_ActivateInputState(This,dwCharID,bActivated)	\
    (This)->lpVtbl -> ActivateInputState(This,dwCharID,bActivated)

#define IAgentNotifySinkEx_Restart(This)	\
    (This)->lpVtbl -> Restart(This)

#define IAgentNotifySinkEx_Shutdown(This)	\
    (This)->lpVtbl -> Shutdown(This)

#define IAgentNotifySinkEx_VisibleState(This,dwCharID,bVisible,dwCause)	\
    (This)->lpVtbl -> VisibleState(This,dwCharID,bVisible,dwCause)

#define IAgentNotifySinkEx_Click(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> Click(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySinkEx_DblClick(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DblClick(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySinkEx_DragStart(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DragStart(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySinkEx_DragComplete(This,dwCharID,fwKeys,x,y)	\
    (This)->lpVtbl -> DragComplete(This,dwCharID,fwKeys,x,y)

#define IAgentNotifySinkEx_RequestStart(This,dwRequestID)	\
    (This)->lpVtbl -> RequestStart(This,dwRequestID)

#define IAgentNotifySinkEx_RequestComplete(This,dwRequestID,hrStatus)	\
    (This)->lpVtbl -> RequestComplete(This,dwRequestID,hrStatus)

#define IAgentNotifySinkEx_BookMark(This,dwBookMarkID)	\
    (This)->lpVtbl -> BookMark(This,dwBookMarkID)

#define IAgentNotifySinkEx_Idle(This,dwCharID,bStart)	\
    (This)->lpVtbl -> Idle(This,dwCharID,bStart)

#define IAgentNotifySinkEx_Move(This,dwCharID,x,y,dwCause)	\
    (This)->lpVtbl -> Move(This,dwCharID,x,y,dwCause)

#define IAgentNotifySinkEx_Size(This,dwCharID,lWidth,lHeight)	\
    (This)->lpVtbl -> Size(This,dwCharID,lWidth,lHeight)

#define IAgentNotifySinkEx_BalloonVisibleState(This,dwCharID,bVisible)	\
    (This)->lpVtbl -> BalloonVisibleState(This,dwCharID,bVisible)


#define IAgentNotifySinkEx_HelpComplete(This,dwCharID,dwCommandID,dwCause)	\
    (This)->lpVtbl -> HelpComplete(This,dwCharID,dwCommandID,dwCause)

#define IAgentNotifySinkEx_ListeningState(This,dwCharID,bListening,dwCause)	\
    (This)->lpVtbl -> ListeningState(This,dwCharID,bListening,dwCause)

#define IAgentNotifySinkEx_DefaultCharacterChange(This,bszGUID)	\
    (This)->lpVtbl -> DefaultCharacterChange(This,bszGUID)

#define IAgentNotifySinkEx_AgentPropertyChange(This)	\
    (This)->lpVtbl -> AgentPropertyChange(This)

#define IAgentNotifySinkEx_ActiveClientChange(This,dwCharID,lStatus)	\
    (This)->lpVtbl -> ActiveClientChange(This,dwCharID,lStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentNotifySinkEx_HelpComplete_Proxy( 
    IAgentNotifySinkEx __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long dwCommandID,
    /* [in] */ long dwCause);


void __RPC_STUB IAgentNotifySinkEx_HelpComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySinkEx_ListeningState_Proxy( 
    IAgentNotifySinkEx __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long bListening,
    /* [in] */ long dwCause);


void __RPC_STUB IAgentNotifySinkEx_ListeningState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySinkEx_DefaultCharacterChange_Proxy( 
    IAgentNotifySinkEx __RPC_FAR * This,
    /* [in] */ BSTR bszGUID);


void __RPC_STUB IAgentNotifySinkEx_DefaultCharacterChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySinkEx_AgentPropertyChange_Proxy( 
    IAgentNotifySinkEx __RPC_FAR * This);


void __RPC_STUB IAgentNotifySinkEx_AgentPropertyChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentNotifySinkEx_ActiveClientChange_Proxy( 
    IAgentNotifySinkEx __RPC_FAR * This,
    /* [in] */ long dwCharID,
    /* [in] */ long lStatus);


void __RPC_STUB IAgentNotifySinkEx_ActiveClientChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentNotifySinkEx_INTERFACE_DEFINED__ */


#ifndef __IAgentPrivateNotifySink_INTERFACE_DEFINED__
#define __IAgentPrivateNotifySink_INTERFACE_DEFINED__

/* interface IAgentPrivateNotifySink */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IAgentPrivateNotifySink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B741B760-8EA6-11d0-AC6A-00C04FD97575")
    IAgentPrivateNotifySink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ReleaseAll( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseOne( 
            void __RPC_FAR *pnNotify) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClientID( 
            DWORD __RPC_FAR *pdwClientID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentPrivateNotifySinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentPrivateNotifySink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentPrivateNotifySink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentPrivateNotifySink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseAll )( 
            IAgentPrivateNotifySink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseOne )( 
            IAgentPrivateNotifySink __RPC_FAR * This,
            void __RPC_FAR *pnNotify);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClientID )( 
            IAgentPrivateNotifySink __RPC_FAR * This,
            DWORD __RPC_FAR *pdwClientID);
        
        END_INTERFACE
    } IAgentPrivateNotifySinkVtbl;

    interface IAgentPrivateNotifySink
    {
        CONST_VTBL struct IAgentPrivateNotifySinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentPrivateNotifySink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentPrivateNotifySink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentPrivateNotifySink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentPrivateNotifySink_ReleaseAll(This)	\
    (This)->lpVtbl -> ReleaseAll(This)

#define IAgentPrivateNotifySink_ReleaseOne(This,pnNotify)	\
    (This)->lpVtbl -> ReleaseOne(This,pnNotify)

#define IAgentPrivateNotifySink_GetClientID(This,pdwClientID)	\
    (This)->lpVtbl -> GetClientID(This,pdwClientID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentPrivateNotifySink_ReleaseAll_Proxy( 
    IAgentPrivateNotifySink __RPC_FAR * This);


void __RPC_STUB IAgentPrivateNotifySink_ReleaseAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPrivateNotifySink_ReleaseOne_Proxy( 
    IAgentPrivateNotifySink __RPC_FAR * This,
    void __RPC_FAR *pnNotify);


void __RPC_STUB IAgentPrivateNotifySink_ReleaseOne_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAgentPrivateNotifySink_GetClientID_Proxy( 
    IAgentPrivateNotifySink __RPC_FAR * This,
    DWORD __RPC_FAR *pdwClientID);


void __RPC_STUB IAgentPrivateNotifySink_GetClientID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentPrivateNotifySink_INTERFACE_DEFINED__ */


#ifndef __IAgentCustomMarshalMaker_INTERFACE_DEFINED__
#define __IAgentCustomMarshalMaker_INTERFACE_DEFINED__

/* interface IAgentCustomMarshalMaker */
/* [unique][helpstring][uuid][hidden][local][object] */ 


EXTERN_C const IID IID_IAgentCustomMarshalMaker;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("408D7542-C8FC-11d1-AA83-00C04FA34D72")
    IAgentCustomMarshalMaker : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ IUnknown __RPC_FAR *pSink,
            /* [in] */ REFIID riidSink,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *pMarshaledSink) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentCustomMarshalMakerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentCustomMarshalMaker __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentCustomMarshalMaker __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentCustomMarshalMaker __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create )( 
            IAgentCustomMarshalMaker __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pSink,
            /* [in] */ REFIID riidSink,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *pMarshaledSink);
        
        END_INTERFACE
    } IAgentCustomMarshalMakerVtbl;

    interface IAgentCustomMarshalMaker
    {
        CONST_VTBL struct IAgentCustomMarshalMakerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentCustomMarshalMaker_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentCustomMarshalMaker_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentCustomMarshalMaker_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentCustomMarshalMaker_Create(This,pSink,riidSink,pMarshaledSink)	\
    (This)->lpVtbl -> Create(This,pSink,riidSink,pMarshaledSink)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentCustomMarshalMaker_Create_Proxy( 
    IAgentCustomMarshalMaker __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pSink,
    /* [in] */ REFIID riidSink,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *pMarshaledSink);


void __RPC_STUB IAgentCustomMarshalMaker_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentCustomMarshalMaker_INTERFACE_DEFINED__ */


#ifndef __IAgentClientStatus_INTERFACE_DEFINED__
#define __IAgentClientStatus_INTERFACE_DEFINED__

/* interface IAgentClientStatus */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IAgentClientStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C5649F70-7AED-11d1-B9A8-00C04FD97575")
    IAgentClientStatus : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Ping( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAgentClientStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAgentClientStatus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAgentClientStatus __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAgentClientStatus __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Ping )( 
            IAgentClientStatus __RPC_FAR * This);
        
        END_INTERFACE
    } IAgentClientStatusVtbl;

    interface IAgentClientStatus
    {
        CONST_VTBL struct IAgentClientStatusVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgentClientStatus_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAgentClientStatus_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAgentClientStatus_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAgentClientStatus_Ping(This)	\
    (This)->lpVtbl -> Ping(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAgentClientStatus_Ping_Proxy( 
    IAgentClientStatus __RPC_FAR * This);


void __RPC_STUB IAgentClientStatus_Ping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAgentClientStatus_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_AgentServer_0229 */
/* [local] */ 

#define	AGENT_VERSION_MAJOR	( 2 )

#define	AGENT_VERSION_MINOR	( 0 )



extern RPC_IF_HANDLE __MIDL_itf_AgentServer_0229_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AgentServer_0229_v0_0_s_ifspec;


#ifndef __AgentServerObjects_LIBRARY_DEFINED__
#define __AgentServerObjects_LIBRARY_DEFINED__

/* library AgentServerObjects */
/* [helpstring][version][uuid] */ 




















EXTERN_C const IID LIBID_AgentServerObjects;

EXTERN_C const CLSID CLSID_AgentServer;

#ifdef __cplusplus

class DECLSPEC_UUID("D45FD2FC-5C6E-11D1-9EC1-00C04FD7081F")
AgentServer;
#endif
#endif /* __AgentServerObjects_LIBRARY_DEFINED__ */

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
