

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for rtccore.idl:
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

#ifndef __rtccore_h__
#define __rtccore_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IRTCClient_FWD_DEFINED__
#define __IRTCClient_FWD_DEFINED__
typedef interface IRTCClient IRTCClient;
#endif 	/* __IRTCClient_FWD_DEFINED__ */


#ifndef __IRTCClient2_FWD_DEFINED__
#define __IRTCClient2_FWD_DEFINED__
typedef interface IRTCClient2 IRTCClient2;
#endif 	/* __IRTCClient2_FWD_DEFINED__ */


#ifndef __IRTCClientPresence_FWD_DEFINED__
#define __IRTCClientPresence_FWD_DEFINED__
typedef interface IRTCClientPresence IRTCClientPresence;
#endif 	/* __IRTCClientPresence_FWD_DEFINED__ */


#ifndef __IRTCClientPresence2_FWD_DEFINED__
#define __IRTCClientPresence2_FWD_DEFINED__
typedef interface IRTCClientPresence2 IRTCClientPresence2;
#endif 	/* __IRTCClientPresence2_FWD_DEFINED__ */


#ifndef __IRTCClientProvisioning_FWD_DEFINED__
#define __IRTCClientProvisioning_FWD_DEFINED__
typedef interface IRTCClientProvisioning IRTCClientProvisioning;
#endif 	/* __IRTCClientProvisioning_FWD_DEFINED__ */


#ifndef __IRTCClientProvisioning2_FWD_DEFINED__
#define __IRTCClientProvisioning2_FWD_DEFINED__
typedef interface IRTCClientProvisioning2 IRTCClientProvisioning2;
#endif 	/* __IRTCClientProvisioning2_FWD_DEFINED__ */


#ifndef __IRTCProfile_FWD_DEFINED__
#define __IRTCProfile_FWD_DEFINED__
typedef interface IRTCProfile IRTCProfile;
#endif 	/* __IRTCProfile_FWD_DEFINED__ */


#ifndef __IRTCProfile2_FWD_DEFINED__
#define __IRTCProfile2_FWD_DEFINED__
typedef interface IRTCProfile2 IRTCProfile2;
#endif 	/* __IRTCProfile2_FWD_DEFINED__ */


#ifndef __IRTCSession_FWD_DEFINED__
#define __IRTCSession_FWD_DEFINED__
typedef interface IRTCSession IRTCSession;
#endif 	/* __IRTCSession_FWD_DEFINED__ */


#ifndef __IRTCSession2_FWD_DEFINED__
#define __IRTCSession2_FWD_DEFINED__
typedef interface IRTCSession2 IRTCSession2;
#endif 	/* __IRTCSession2_FWD_DEFINED__ */


#ifndef __IRTCSessionCallControl_FWD_DEFINED__
#define __IRTCSessionCallControl_FWD_DEFINED__
typedef interface IRTCSessionCallControl IRTCSessionCallControl;
#endif 	/* __IRTCSessionCallControl_FWD_DEFINED__ */


#ifndef __IRTCParticipant_FWD_DEFINED__
#define __IRTCParticipant_FWD_DEFINED__
typedef interface IRTCParticipant IRTCParticipant;
#endif 	/* __IRTCParticipant_FWD_DEFINED__ */


#ifndef __IRTCRoamingEvent_FWD_DEFINED__
#define __IRTCRoamingEvent_FWD_DEFINED__
typedef interface IRTCRoamingEvent IRTCRoamingEvent;
#endif 	/* __IRTCRoamingEvent_FWD_DEFINED__ */


#ifndef __IRTCProfileEvent_FWD_DEFINED__
#define __IRTCProfileEvent_FWD_DEFINED__
typedef interface IRTCProfileEvent IRTCProfileEvent;
#endif 	/* __IRTCProfileEvent_FWD_DEFINED__ */


#ifndef __IRTCProfileEvent2_FWD_DEFINED__
#define __IRTCProfileEvent2_FWD_DEFINED__
typedef interface IRTCProfileEvent2 IRTCProfileEvent2;
#endif 	/* __IRTCProfileEvent2_FWD_DEFINED__ */


#ifndef __IRTCClientEvent_FWD_DEFINED__
#define __IRTCClientEvent_FWD_DEFINED__
typedef interface IRTCClientEvent IRTCClientEvent;
#endif 	/* __IRTCClientEvent_FWD_DEFINED__ */


#ifndef __IRTCRegistrationStateChangeEvent_FWD_DEFINED__
#define __IRTCRegistrationStateChangeEvent_FWD_DEFINED__
typedef interface IRTCRegistrationStateChangeEvent IRTCRegistrationStateChangeEvent;
#endif 	/* __IRTCRegistrationStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent_FWD_DEFINED__
#define __IRTCSessionStateChangeEvent_FWD_DEFINED__
typedef interface IRTCSessionStateChangeEvent IRTCSessionStateChangeEvent;
#endif 	/* __IRTCSessionStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent2_FWD_DEFINED__
#define __IRTCSessionStateChangeEvent2_FWD_DEFINED__
typedef interface IRTCSessionStateChangeEvent2 IRTCSessionStateChangeEvent2;
#endif 	/* __IRTCSessionStateChangeEvent2_FWD_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent_FWD_DEFINED__
#define __IRTCSessionOperationCompleteEvent_FWD_DEFINED__
typedef interface IRTCSessionOperationCompleteEvent IRTCSessionOperationCompleteEvent;
#endif 	/* __IRTCSessionOperationCompleteEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__
#define __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__
typedef interface IRTCSessionOperationCompleteEvent2 IRTCSessionOperationCompleteEvent2;
#endif 	/* __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__ */


#ifndef __IRTCParticipantStateChangeEvent_FWD_DEFINED__
#define __IRTCParticipantStateChangeEvent_FWD_DEFINED__
typedef interface IRTCParticipantStateChangeEvent IRTCParticipantStateChangeEvent;
#endif 	/* __IRTCParticipantStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCMediaEvent_FWD_DEFINED__
#define __IRTCMediaEvent_FWD_DEFINED__
typedef interface IRTCMediaEvent IRTCMediaEvent;
#endif 	/* __IRTCMediaEvent_FWD_DEFINED__ */


#ifndef __IRTCIntensityEvent_FWD_DEFINED__
#define __IRTCIntensityEvent_FWD_DEFINED__
typedef interface IRTCIntensityEvent IRTCIntensityEvent;
#endif 	/* __IRTCIntensityEvent_FWD_DEFINED__ */


#ifndef __IRTCMessagingEvent_FWD_DEFINED__
#define __IRTCMessagingEvent_FWD_DEFINED__
typedef interface IRTCMessagingEvent IRTCMessagingEvent;
#endif 	/* __IRTCMessagingEvent_FWD_DEFINED__ */


#ifndef __IRTCBuddyEvent_FWD_DEFINED__
#define __IRTCBuddyEvent_FWD_DEFINED__
typedef interface IRTCBuddyEvent IRTCBuddyEvent;
#endif 	/* __IRTCBuddyEvent_FWD_DEFINED__ */


#ifndef __IRTCBuddyEvent2_FWD_DEFINED__
#define __IRTCBuddyEvent2_FWD_DEFINED__
typedef interface IRTCBuddyEvent2 IRTCBuddyEvent2;
#endif 	/* __IRTCBuddyEvent2_FWD_DEFINED__ */


#ifndef __IRTCWatcherEvent_FWD_DEFINED__
#define __IRTCWatcherEvent_FWD_DEFINED__
typedef interface IRTCWatcherEvent IRTCWatcherEvent;
#endif 	/* __IRTCWatcherEvent_FWD_DEFINED__ */


#ifndef __IRTCWatcherEvent2_FWD_DEFINED__
#define __IRTCWatcherEvent2_FWD_DEFINED__
typedef interface IRTCWatcherEvent2 IRTCWatcherEvent2;
#endif 	/* __IRTCWatcherEvent2_FWD_DEFINED__ */


#ifndef __IRTCBuddyGroupEvent_FWD_DEFINED__
#define __IRTCBuddyGroupEvent_FWD_DEFINED__
typedef interface IRTCBuddyGroupEvent IRTCBuddyGroupEvent;
#endif 	/* __IRTCBuddyGroupEvent_FWD_DEFINED__ */


#ifndef __IRTCInfoEvent_FWD_DEFINED__
#define __IRTCInfoEvent_FWD_DEFINED__
typedef interface IRTCInfoEvent IRTCInfoEvent;
#endif 	/* __IRTCInfoEvent_FWD_DEFINED__ */


#ifndef __IRTCMediaRequestEvent_FWD_DEFINED__
#define __IRTCMediaRequestEvent_FWD_DEFINED__
typedef interface IRTCMediaRequestEvent IRTCMediaRequestEvent;
#endif 	/* __IRTCMediaRequestEvent_FWD_DEFINED__ */


#ifndef __IRTCReInviteEvent_FWD_DEFINED__
#define __IRTCReInviteEvent_FWD_DEFINED__
typedef interface IRTCReInviteEvent IRTCReInviteEvent;
#endif 	/* __IRTCReInviteEvent_FWD_DEFINED__ */


#ifndef __IRTCPresencePropertyEvent_FWD_DEFINED__
#define __IRTCPresencePropertyEvent_FWD_DEFINED__
typedef interface IRTCPresencePropertyEvent IRTCPresencePropertyEvent;
#endif 	/* __IRTCPresencePropertyEvent_FWD_DEFINED__ */


#ifndef __IRTCPresenceDataEvent_FWD_DEFINED__
#define __IRTCPresenceDataEvent_FWD_DEFINED__
typedef interface IRTCPresenceDataEvent IRTCPresenceDataEvent;
#endif 	/* __IRTCPresenceDataEvent_FWD_DEFINED__ */


#ifndef __IRTCPresenceStatusEvent_FWD_DEFINED__
#define __IRTCPresenceStatusEvent_FWD_DEFINED__
typedef interface IRTCPresenceStatusEvent IRTCPresenceStatusEvent;
#endif 	/* __IRTCPresenceStatusEvent_FWD_DEFINED__ */


#ifndef __IRTCCollection_FWD_DEFINED__
#define __IRTCCollection_FWD_DEFINED__
typedef interface IRTCCollection IRTCCollection;
#endif 	/* __IRTCCollection_FWD_DEFINED__ */


#ifndef __IRTCEnumParticipants_FWD_DEFINED__
#define __IRTCEnumParticipants_FWD_DEFINED__
typedef interface IRTCEnumParticipants IRTCEnumParticipants;
#endif 	/* __IRTCEnumParticipants_FWD_DEFINED__ */


#ifndef __IRTCEnumProfiles_FWD_DEFINED__
#define __IRTCEnumProfiles_FWD_DEFINED__
typedef interface IRTCEnumProfiles IRTCEnumProfiles;
#endif 	/* __IRTCEnumProfiles_FWD_DEFINED__ */


#ifndef __IRTCEnumBuddies_FWD_DEFINED__
#define __IRTCEnumBuddies_FWD_DEFINED__
typedef interface IRTCEnumBuddies IRTCEnumBuddies;
#endif 	/* __IRTCEnumBuddies_FWD_DEFINED__ */


#ifndef __IRTCEnumWatchers_FWD_DEFINED__
#define __IRTCEnumWatchers_FWD_DEFINED__
typedef interface IRTCEnumWatchers IRTCEnumWatchers;
#endif 	/* __IRTCEnumWatchers_FWD_DEFINED__ */


#ifndef __IRTCEnumGroups_FWD_DEFINED__
#define __IRTCEnumGroups_FWD_DEFINED__
typedef interface IRTCEnumGroups IRTCEnumGroups;
#endif 	/* __IRTCEnumGroups_FWD_DEFINED__ */


#ifndef __IRTCPresenceContact_FWD_DEFINED__
#define __IRTCPresenceContact_FWD_DEFINED__
typedef interface IRTCPresenceContact IRTCPresenceContact;
#endif 	/* __IRTCPresenceContact_FWD_DEFINED__ */


#ifndef __IRTCBuddy_FWD_DEFINED__
#define __IRTCBuddy_FWD_DEFINED__
typedef interface IRTCBuddy IRTCBuddy;
#endif 	/* __IRTCBuddy_FWD_DEFINED__ */


#ifndef __IRTCBuddy2_FWD_DEFINED__
#define __IRTCBuddy2_FWD_DEFINED__
typedef interface IRTCBuddy2 IRTCBuddy2;
#endif 	/* __IRTCBuddy2_FWD_DEFINED__ */


#ifndef __IRTCWatcher_FWD_DEFINED__
#define __IRTCWatcher_FWD_DEFINED__
typedef interface IRTCWatcher IRTCWatcher;
#endif 	/* __IRTCWatcher_FWD_DEFINED__ */


#ifndef __IRTCWatcher2_FWD_DEFINED__
#define __IRTCWatcher2_FWD_DEFINED__
typedef interface IRTCWatcher2 IRTCWatcher2;
#endif 	/* __IRTCWatcher2_FWD_DEFINED__ */


#ifndef __IRTCBuddyGroup_FWD_DEFINED__
#define __IRTCBuddyGroup_FWD_DEFINED__
typedef interface IRTCBuddyGroup IRTCBuddyGroup;
#endif 	/* __IRTCBuddyGroup_FWD_DEFINED__ */


#ifndef __IRTCEventNotification_FWD_DEFINED__
#define __IRTCEventNotification_FWD_DEFINED__
typedef interface IRTCEventNotification IRTCEventNotification;
#endif 	/* __IRTCEventNotification_FWD_DEFINED__ */


#ifndef __IRTCDispatchEventNotification_FWD_DEFINED__
#define __IRTCDispatchEventNotification_FWD_DEFINED__
typedef interface IRTCDispatchEventNotification IRTCDispatchEventNotification;
#endif 	/* __IRTCDispatchEventNotification_FWD_DEFINED__ */


#ifndef __IRTCPortManager_FWD_DEFINED__
#define __IRTCPortManager_FWD_DEFINED__
typedef interface IRTCPortManager IRTCPortManager;
#endif 	/* __IRTCPortManager_FWD_DEFINED__ */


#ifndef __IRTCSessionPortManagement_FWD_DEFINED__
#define __IRTCSessionPortManagement_FWD_DEFINED__
typedef interface IRTCSessionPortManagement IRTCSessionPortManagement;
#endif 	/* __IRTCSessionPortManagement_FWD_DEFINED__ */


#ifndef __IRTCClientPortManagement_FWD_DEFINED__
#define __IRTCClientPortManagement_FWD_DEFINED__
typedef interface IRTCClientPortManagement IRTCClientPortManagement;
#endif 	/* __IRTCClientPortManagement_FWD_DEFINED__ */


#ifndef __IRTCUserSearch_FWD_DEFINED__
#define __IRTCUserSearch_FWD_DEFINED__
typedef interface IRTCUserSearch IRTCUserSearch;
#endif 	/* __IRTCUserSearch_FWD_DEFINED__ */


#ifndef __IRTCUserSearchQuery_FWD_DEFINED__
#define __IRTCUserSearchQuery_FWD_DEFINED__
typedef interface IRTCUserSearchQuery IRTCUserSearchQuery;
#endif 	/* __IRTCUserSearchQuery_FWD_DEFINED__ */


#ifndef __IRTCUserSearchResult_FWD_DEFINED__
#define __IRTCUserSearchResult_FWD_DEFINED__
typedef interface IRTCUserSearchResult IRTCUserSearchResult;
#endif 	/* __IRTCUserSearchResult_FWD_DEFINED__ */


#ifndef __IRTCEnumUserSearchResults_FWD_DEFINED__
#define __IRTCEnumUserSearchResults_FWD_DEFINED__
typedef interface IRTCEnumUserSearchResults IRTCEnumUserSearchResults;
#endif 	/* __IRTCEnumUserSearchResults_FWD_DEFINED__ */


#ifndef __IRTCUserSearchResultsEvent_FWD_DEFINED__
#define __IRTCUserSearchResultsEvent_FWD_DEFINED__
typedef interface IRTCUserSearchResultsEvent IRTCUserSearchResultsEvent;
#endif 	/* __IRTCUserSearchResultsEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionReferStatusEvent_FWD_DEFINED__
#define __IRTCSessionReferStatusEvent_FWD_DEFINED__
typedef interface IRTCSessionReferStatusEvent IRTCSessionReferStatusEvent;
#endif 	/* __IRTCSessionReferStatusEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionReferredEvent_FWD_DEFINED__
#define __IRTCSessionReferredEvent_FWD_DEFINED__
typedef interface IRTCSessionReferredEvent IRTCSessionReferredEvent;
#endif 	/* __IRTCSessionReferredEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionDescriptionManager_FWD_DEFINED__
#define __IRTCSessionDescriptionManager_FWD_DEFINED__
typedef interface IRTCSessionDescriptionManager IRTCSessionDescriptionManager;
#endif 	/* __IRTCSessionDescriptionManager_FWD_DEFINED__ */


#ifndef __IRTCEnumPresenceDevices_FWD_DEFINED__
#define __IRTCEnumPresenceDevices_FWD_DEFINED__
typedef interface IRTCEnumPresenceDevices IRTCEnumPresenceDevices;
#endif 	/* __IRTCEnumPresenceDevices_FWD_DEFINED__ */


#ifndef __IRTCPresenceDevice_FWD_DEFINED__
#define __IRTCPresenceDevice_FWD_DEFINED__
typedef interface IRTCPresenceDevice IRTCPresenceDevice;
#endif 	/* __IRTCPresenceDevice_FWD_DEFINED__ */


#ifndef __IRTCProfile_FWD_DEFINED__
#define __IRTCProfile_FWD_DEFINED__
typedef interface IRTCProfile IRTCProfile;
#endif 	/* __IRTCProfile_FWD_DEFINED__ */


#ifndef __IRTCProfile2_FWD_DEFINED__
#define __IRTCProfile2_FWD_DEFINED__
typedef interface IRTCProfile2 IRTCProfile2;
#endif 	/* __IRTCProfile2_FWD_DEFINED__ */


#ifndef __IRTCEnumProfiles_FWD_DEFINED__
#define __IRTCEnumProfiles_FWD_DEFINED__
typedef interface IRTCEnumProfiles IRTCEnumProfiles;
#endif 	/* __IRTCEnumProfiles_FWD_DEFINED__ */


#ifndef __IRTCSession_FWD_DEFINED__
#define __IRTCSession_FWD_DEFINED__
typedef interface IRTCSession IRTCSession;
#endif 	/* __IRTCSession_FWD_DEFINED__ */


#ifndef __IRTCSession2_FWD_DEFINED__
#define __IRTCSession2_FWD_DEFINED__
typedef interface IRTCSession2 IRTCSession2;
#endif 	/* __IRTCSession2_FWD_DEFINED__ */


#ifndef __IRTCSessionCallControl_FWD_DEFINED__
#define __IRTCSessionCallControl_FWD_DEFINED__
typedef interface IRTCSessionCallControl IRTCSessionCallControl;
#endif 	/* __IRTCSessionCallControl_FWD_DEFINED__ */


#ifndef __IRTCParticipant_FWD_DEFINED__
#define __IRTCParticipant_FWD_DEFINED__
typedef interface IRTCParticipant IRTCParticipant;
#endif 	/* __IRTCParticipant_FWD_DEFINED__ */


#ifndef __IRTCEnumParticipants_FWD_DEFINED__
#define __IRTCEnumParticipants_FWD_DEFINED__
typedef interface IRTCEnumParticipants IRTCEnumParticipants;
#endif 	/* __IRTCEnumParticipants_FWD_DEFINED__ */


#ifndef __IRTCCollection_FWD_DEFINED__
#define __IRTCCollection_FWD_DEFINED__
typedef interface IRTCCollection IRTCCollection;
#endif 	/* __IRTCCollection_FWD_DEFINED__ */


#ifndef __IRTCPresenceContact_FWD_DEFINED__
#define __IRTCPresenceContact_FWD_DEFINED__
typedef interface IRTCPresenceContact IRTCPresenceContact;
#endif 	/* __IRTCPresenceContact_FWD_DEFINED__ */


#ifndef __IRTCBuddy_FWD_DEFINED__
#define __IRTCBuddy_FWD_DEFINED__
typedef interface IRTCBuddy IRTCBuddy;
#endif 	/* __IRTCBuddy_FWD_DEFINED__ */


#ifndef __IRTCBuddy2_FWD_DEFINED__
#define __IRTCBuddy2_FWD_DEFINED__
typedef interface IRTCBuddy2 IRTCBuddy2;
#endif 	/* __IRTCBuddy2_FWD_DEFINED__ */


#ifndef __IRTCEnumBuddies_FWD_DEFINED__
#define __IRTCEnumBuddies_FWD_DEFINED__
typedef interface IRTCEnumBuddies IRTCEnumBuddies;
#endif 	/* __IRTCEnumBuddies_FWD_DEFINED__ */


#ifndef __IRTCWatcher_FWD_DEFINED__
#define __IRTCWatcher_FWD_DEFINED__
typedef interface IRTCWatcher IRTCWatcher;
#endif 	/* __IRTCWatcher_FWD_DEFINED__ */


#ifndef __IRTCWatcher2_FWD_DEFINED__
#define __IRTCWatcher2_FWD_DEFINED__
typedef interface IRTCWatcher2 IRTCWatcher2;
#endif 	/* __IRTCWatcher2_FWD_DEFINED__ */


#ifndef __IRTCEnumWatchers_FWD_DEFINED__
#define __IRTCEnumWatchers_FWD_DEFINED__
typedef interface IRTCEnumWatchers IRTCEnumWatchers;
#endif 	/* __IRTCEnumWatchers_FWD_DEFINED__ */


#ifndef __IRTCBuddyGroup_FWD_DEFINED__
#define __IRTCBuddyGroup_FWD_DEFINED__
typedef interface IRTCBuddyGroup IRTCBuddyGroup;
#endif 	/* __IRTCBuddyGroup_FWD_DEFINED__ */


#ifndef __IRTCEnumGroups_FWD_DEFINED__
#define __IRTCEnumGroups_FWD_DEFINED__
typedef interface IRTCEnumGroups IRTCEnumGroups;
#endif 	/* __IRTCEnumGroups_FWD_DEFINED__ */


#ifndef __IRTCUserSearchQuery_FWD_DEFINED__
#define __IRTCUserSearchQuery_FWD_DEFINED__
typedef interface IRTCUserSearchQuery IRTCUserSearchQuery;
#endif 	/* __IRTCUserSearchQuery_FWD_DEFINED__ */


#ifndef __IRTCUserSearchResult_FWD_DEFINED__
#define __IRTCUserSearchResult_FWD_DEFINED__
typedef interface IRTCUserSearchResult IRTCUserSearchResult;
#endif 	/* __IRTCUserSearchResult_FWD_DEFINED__ */


#ifndef __IRTCEnumUserSearchResults_FWD_DEFINED__
#define __IRTCEnumUserSearchResults_FWD_DEFINED__
typedef interface IRTCEnumUserSearchResults IRTCEnumUserSearchResults;
#endif 	/* __IRTCEnumUserSearchResults_FWD_DEFINED__ */


#ifndef __IRTCEventNotification_FWD_DEFINED__
#define __IRTCEventNotification_FWD_DEFINED__
typedef interface IRTCEventNotification IRTCEventNotification;
#endif 	/* __IRTCEventNotification_FWD_DEFINED__ */


#ifndef __IRTCClientEvent_FWD_DEFINED__
#define __IRTCClientEvent_FWD_DEFINED__
typedef interface IRTCClientEvent IRTCClientEvent;
#endif 	/* __IRTCClientEvent_FWD_DEFINED__ */


#ifndef __IRTCRegistrationStateChangeEvent_FWD_DEFINED__
#define __IRTCRegistrationStateChangeEvent_FWD_DEFINED__
typedef interface IRTCRegistrationStateChangeEvent IRTCRegistrationStateChangeEvent;
#endif 	/* __IRTCRegistrationStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent_FWD_DEFINED__
#define __IRTCSessionStateChangeEvent_FWD_DEFINED__
typedef interface IRTCSessionStateChangeEvent IRTCSessionStateChangeEvent;
#endif 	/* __IRTCSessionStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent2_FWD_DEFINED__
#define __IRTCSessionStateChangeEvent2_FWD_DEFINED__
typedef interface IRTCSessionStateChangeEvent2 IRTCSessionStateChangeEvent2;
#endif 	/* __IRTCSessionStateChangeEvent2_FWD_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent_FWD_DEFINED__
#define __IRTCSessionOperationCompleteEvent_FWD_DEFINED__
typedef interface IRTCSessionOperationCompleteEvent IRTCSessionOperationCompleteEvent;
#endif 	/* __IRTCSessionOperationCompleteEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__
#define __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__
typedef interface IRTCSessionOperationCompleteEvent2 IRTCSessionOperationCompleteEvent2;
#endif 	/* __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__ */


#ifndef __IRTCParticipantStateChangeEvent_FWD_DEFINED__
#define __IRTCParticipantStateChangeEvent_FWD_DEFINED__
typedef interface IRTCParticipantStateChangeEvent IRTCParticipantStateChangeEvent;
#endif 	/* __IRTCParticipantStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCMediaEvent_FWD_DEFINED__
#define __IRTCMediaEvent_FWD_DEFINED__
typedef interface IRTCMediaEvent IRTCMediaEvent;
#endif 	/* __IRTCMediaEvent_FWD_DEFINED__ */


#ifndef __IRTCIntensityEvent_FWD_DEFINED__
#define __IRTCIntensityEvent_FWD_DEFINED__
typedef interface IRTCIntensityEvent IRTCIntensityEvent;
#endif 	/* __IRTCIntensityEvent_FWD_DEFINED__ */


#ifndef __IRTCMessagingEvent_FWD_DEFINED__
#define __IRTCMessagingEvent_FWD_DEFINED__
typedef interface IRTCMessagingEvent IRTCMessagingEvent;
#endif 	/* __IRTCMessagingEvent_FWD_DEFINED__ */


#ifndef __IRTCBuddyEvent_FWD_DEFINED__
#define __IRTCBuddyEvent_FWD_DEFINED__
typedef interface IRTCBuddyEvent IRTCBuddyEvent;
#endif 	/* __IRTCBuddyEvent_FWD_DEFINED__ */


#ifndef __IRTCBuddyEvent2_FWD_DEFINED__
#define __IRTCBuddyEvent2_FWD_DEFINED__
typedef interface IRTCBuddyEvent2 IRTCBuddyEvent2;
#endif 	/* __IRTCBuddyEvent2_FWD_DEFINED__ */


#ifndef __IRTCWatcherEvent_FWD_DEFINED__
#define __IRTCWatcherEvent_FWD_DEFINED__
typedef interface IRTCWatcherEvent IRTCWatcherEvent;
#endif 	/* __IRTCWatcherEvent_FWD_DEFINED__ */


#ifndef __IRTCPortManager_FWD_DEFINED__
#define __IRTCPortManager_FWD_DEFINED__
typedef interface IRTCPortManager IRTCPortManager;
#endif 	/* __IRTCPortManager_FWD_DEFINED__ */


#ifndef __IRTCSessionPortManagement_FWD_DEFINED__
#define __IRTCSessionPortManagement_FWD_DEFINED__
typedef interface IRTCSessionPortManagement IRTCSessionPortManagement;
#endif 	/* __IRTCSessionPortManagement_FWD_DEFINED__ */


#ifndef __IRTCClientPortManagement_FWD_DEFINED__
#define __IRTCClientPortManagement_FWD_DEFINED__
typedef interface IRTCClientPortManagement IRTCClientPortManagement;
#endif 	/* __IRTCClientPortManagement_FWD_DEFINED__ */


#ifndef __IRTCWatcherEvent2_FWD_DEFINED__
#define __IRTCWatcherEvent2_FWD_DEFINED__
typedef interface IRTCWatcherEvent2 IRTCWatcherEvent2;
#endif 	/* __IRTCWatcherEvent2_FWD_DEFINED__ */


#ifndef __IRTCBuddyGroupEvent_FWD_DEFINED__
#define __IRTCBuddyGroupEvent_FWD_DEFINED__
typedef interface IRTCBuddyGroupEvent IRTCBuddyGroupEvent;
#endif 	/* __IRTCBuddyGroupEvent_FWD_DEFINED__ */


#ifndef __IRTCProfileEvent_FWD_DEFINED__
#define __IRTCProfileEvent_FWD_DEFINED__
typedef interface IRTCProfileEvent IRTCProfileEvent;
#endif 	/* __IRTCProfileEvent_FWD_DEFINED__ */


#ifndef __IRTCProfileEvent2_FWD_DEFINED__
#define __IRTCProfileEvent2_FWD_DEFINED__
typedef interface IRTCProfileEvent2 IRTCProfileEvent2;
#endif 	/* __IRTCProfileEvent2_FWD_DEFINED__ */


#ifndef __IRTCUserSearchResultsEvent_FWD_DEFINED__
#define __IRTCUserSearchResultsEvent_FWD_DEFINED__
typedef interface IRTCUserSearchResultsEvent IRTCUserSearchResultsEvent;
#endif 	/* __IRTCUserSearchResultsEvent_FWD_DEFINED__ */


#ifndef __IRTCInfoEvent_FWD_DEFINED__
#define __IRTCInfoEvent_FWD_DEFINED__
typedef interface IRTCInfoEvent IRTCInfoEvent;
#endif 	/* __IRTCInfoEvent_FWD_DEFINED__ */


#ifndef __IRTCRoamingEvent_FWD_DEFINED__
#define __IRTCRoamingEvent_FWD_DEFINED__
typedef interface IRTCRoamingEvent IRTCRoamingEvent;
#endif 	/* __IRTCRoamingEvent_FWD_DEFINED__ */


#ifndef __IRTCMediaRequestEvent_FWD_DEFINED__
#define __IRTCMediaRequestEvent_FWD_DEFINED__
typedef interface IRTCMediaRequestEvent IRTCMediaRequestEvent;
#endif 	/* __IRTCMediaRequestEvent_FWD_DEFINED__ */


#ifndef __IRTCReInviteEvent_FWD_DEFINED__
#define __IRTCReInviteEvent_FWD_DEFINED__
typedef interface IRTCReInviteEvent IRTCReInviteEvent;
#endif 	/* __IRTCReInviteEvent_FWD_DEFINED__ */


#ifndef __IRTCPresencePropertyEvent_FWD_DEFINED__
#define __IRTCPresencePropertyEvent_FWD_DEFINED__
typedef interface IRTCPresencePropertyEvent IRTCPresencePropertyEvent;
#endif 	/* __IRTCPresencePropertyEvent_FWD_DEFINED__ */


#ifndef __IRTCPresenceDataEvent_FWD_DEFINED__
#define __IRTCPresenceDataEvent_FWD_DEFINED__
typedef interface IRTCPresenceDataEvent IRTCPresenceDataEvent;
#endif 	/* __IRTCPresenceDataEvent_FWD_DEFINED__ */


#ifndef __IRTCPresenceStatusEvent_FWD_DEFINED__
#define __IRTCPresenceStatusEvent_FWD_DEFINED__
typedef interface IRTCPresenceStatusEvent IRTCPresenceStatusEvent;
#endif 	/* __IRTCPresenceStatusEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionReferStatusEvent_FWD_DEFINED__
#define __IRTCSessionReferStatusEvent_FWD_DEFINED__
typedef interface IRTCSessionReferStatusEvent IRTCSessionReferStatusEvent;
#endif 	/* __IRTCSessionReferStatusEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionReferredEvent_FWD_DEFINED__
#define __IRTCSessionReferredEvent_FWD_DEFINED__
typedef interface IRTCSessionReferredEvent IRTCSessionReferredEvent;
#endif 	/* __IRTCSessionReferredEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionDescriptionManager_FWD_DEFINED__
#define __IRTCSessionDescriptionManager_FWD_DEFINED__
typedef interface IRTCSessionDescriptionManager IRTCSessionDescriptionManager;
#endif 	/* __IRTCSessionDescriptionManager_FWD_DEFINED__ */


#ifndef __IRTCEnumPresenceDevices_FWD_DEFINED__
#define __IRTCEnumPresenceDevices_FWD_DEFINED__
typedef interface IRTCEnumPresenceDevices IRTCEnumPresenceDevices;
#endif 	/* __IRTCEnumPresenceDevices_FWD_DEFINED__ */


#ifndef __IRTCPresenceDevice_FWD_DEFINED__
#define __IRTCPresenceDevice_FWD_DEFINED__
typedef interface IRTCPresenceDevice IRTCPresenceDevice;
#endif 	/* __IRTCPresenceDevice_FWD_DEFINED__ */


#ifndef __IRTCDispatchEventNotification_FWD_DEFINED__
#define __IRTCDispatchEventNotification_FWD_DEFINED__
typedef interface IRTCDispatchEventNotification IRTCDispatchEventNotification;
#endif 	/* __IRTCDispatchEventNotification_FWD_DEFINED__ */


#ifndef __RTCClient_FWD_DEFINED__
#define __RTCClient_FWD_DEFINED__

#ifdef __cplusplus
typedef class RTCClient RTCClient;
#else
typedef struct RTCClient RTCClient;
#endif /* __cplusplus */

#endif 	/* __RTCClient_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "control.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_rtccore_0000 */
/* [local] */ 

//  Copyright (c) Microsoft Corporation.  All rights reserved.
typedef 
enum RTC_AUDIO_DEVICE
    {	RTCAD_SPEAKER	= 0,
	RTCAD_MICROPHONE	= RTCAD_SPEAKER + 1
    } 	RTC_AUDIO_DEVICE;

typedef 
enum RTC_VIDEO_DEVICE
    {	RTCVD_RECEIVE	= 0,
	RTCVD_PREVIEW	= RTCVD_RECEIVE + 1
    } 	RTC_VIDEO_DEVICE;

typedef 
enum RTC_EVENT
    {	RTCE_CLIENT	= 0,
	RTCE_REGISTRATION_STATE_CHANGE	= RTCE_CLIENT + 1,
	RTCE_SESSION_STATE_CHANGE	= RTCE_REGISTRATION_STATE_CHANGE + 1,
	RTCE_SESSION_OPERATION_COMPLETE	= RTCE_SESSION_STATE_CHANGE + 1,
	RTCE_PARTICIPANT_STATE_CHANGE	= RTCE_SESSION_OPERATION_COMPLETE + 1,
	RTCE_MEDIA	= RTCE_PARTICIPANT_STATE_CHANGE + 1,
	RTCE_INTENSITY	= RTCE_MEDIA + 1,
	RTCE_MESSAGING	= RTCE_INTENSITY + 1,
	RTCE_BUDDY	= RTCE_MESSAGING + 1,
	RTCE_WATCHER	= RTCE_BUDDY + 1,
	RTCE_PROFILE	= RTCE_WATCHER + 1,
	RTCE_USERSEARCH	= RTCE_PROFILE + 1,
	RTCE_INFO	= RTCE_USERSEARCH + 1,
	RTCE_GROUP	= RTCE_INFO + 1,
	RTCE_MEDIA_REQUEST	= RTCE_GROUP + 1,
	RTCE_ROAMING	= RTCE_MEDIA_REQUEST + 1,
	RTCE_PRESENCE_PROPERTY	= RTCE_ROAMING + 1,
	RTCE_PRESENCE_DATA	= RTCE_PRESENCE_PROPERTY + 1,
	RTCE_PRESENCE_STATUS	= RTCE_PRESENCE_DATA + 1,
	RTCE_SESSION_REFER_STATUS	= RTCE_PRESENCE_STATUS + 1,
	RTCE_SESSION_REFERRED	= RTCE_SESSION_REFER_STATUS + 1,
	RTCE_REINVITE	= RTCE_SESSION_REFERRED + 1
    } 	RTC_EVENT;

typedef 
enum RTC_LISTEN_MODE
    {	RTCLM_NONE	= 0,
	RTCLM_DYNAMIC	= RTCLM_NONE + 1,
	RTCLM_BOTH	= RTCLM_DYNAMIC + 1
    } 	RTC_LISTEN_MODE;

typedef 
enum RTC_CLIENT_EVENT_TYPE
    {	RTCCET_VOLUME_CHANGE	= 0,
	RTCCET_DEVICE_CHANGE	= RTCCET_VOLUME_CHANGE + 1,
	RTCCET_NETWORK_QUALITY_CHANGE	= RTCCET_DEVICE_CHANGE + 1,
	RTCCET_ASYNC_CLEANUP_DONE	= RTCCET_NETWORK_QUALITY_CHANGE + 1
    } 	RTC_CLIENT_EVENT_TYPE;

typedef 
enum RTC_BUDDY_EVENT_TYPE
    {	RTCBET_BUDDY_ADD	= 0,
	RTCBET_BUDDY_REMOVE	= RTCBET_BUDDY_ADD + 1,
	RTCBET_BUDDY_UPDATE	= RTCBET_BUDDY_REMOVE + 1,
	RTCBET_BUDDY_STATE_CHANGE	= RTCBET_BUDDY_UPDATE + 1,
	RTCBET_BUDDY_ROAMED	= RTCBET_BUDDY_STATE_CHANGE + 1,
	RTCBET_BUDDY_SUBSCRIBED	= RTCBET_BUDDY_ROAMED + 1
    } 	RTC_BUDDY_EVENT_TYPE;

typedef 
enum RTC_WATCHER_EVENT_TYPE
    {	RTCWET_WATCHER_ADD	= 0,
	RTCWET_WATCHER_REMOVE	= RTCWET_WATCHER_ADD + 1,
	RTCWET_WATCHER_UPDATE	= RTCWET_WATCHER_REMOVE + 1,
	RTCWET_WATCHER_OFFERING	= RTCWET_WATCHER_UPDATE + 1,
	RTCWET_WATCHER_ROAMED	= RTCWET_WATCHER_OFFERING + 1
    } 	RTC_WATCHER_EVENT_TYPE;

typedef 
enum RTC_GROUP_EVENT_TYPE
    {	RTCGET_GROUP_ADD	= 0,
	RTCGET_GROUP_REMOVE	= RTCGET_GROUP_ADD + 1,
	RTCGET_GROUP_UPDATE	= RTCGET_GROUP_REMOVE + 1,
	RTCGET_GROUP_BUDDY_ADD	= RTCGET_GROUP_UPDATE + 1,
	RTCGET_GROUP_BUDDY_REMOVE	= RTCGET_GROUP_BUDDY_ADD + 1,
	RTCGET_GROUP_ROAMED	= RTCGET_GROUP_BUDDY_REMOVE + 1
    } 	RTC_GROUP_EVENT_TYPE;

typedef 
enum RTC_TERMINATE_REASON
    {	RTCTR_NORMAL	= 0,
	RTCTR_DND	= RTCTR_NORMAL + 1,
	RTCTR_BUSY	= RTCTR_DND + 1,
	RTCTR_REJECT	= RTCTR_BUSY + 1,
	RTCTR_TIMEOUT	= RTCTR_REJECT + 1,
	RTCTR_SHUTDOWN	= RTCTR_TIMEOUT + 1,
	RTCTR_INSUFFICIENT_SECURITY_LEVEL	= RTCTR_SHUTDOWN + 1,
	RTCTR_NOT_SUPPORTED	= RTCTR_INSUFFICIENT_SECURITY_LEVEL + 1
    } 	RTC_TERMINATE_REASON;

typedef 
enum RTC_REGISTRATION_STATE
    {	RTCRS_NOT_REGISTERED	= 0,
	RTCRS_REGISTERING	= RTCRS_NOT_REGISTERED + 1,
	RTCRS_REGISTERED	= RTCRS_REGISTERING + 1,
	RTCRS_REJECTED	= RTCRS_REGISTERED + 1,
	RTCRS_UNREGISTERING	= RTCRS_REJECTED + 1,
	RTCRS_ERROR	= RTCRS_UNREGISTERING + 1,
	RTCRS_LOGGED_OFF	= RTCRS_ERROR + 1,
	RTCRS_LOCAL_PA_LOGGED_OFF	= RTCRS_LOGGED_OFF + 1,
	RTCRS_REMOTE_PA_LOGGED_OFF	= RTCRS_LOCAL_PA_LOGGED_OFF + 1
    } 	RTC_REGISTRATION_STATE;

typedef 
enum RTC_SESSION_STATE
    {	RTCSS_IDLE	= 0,
	RTCSS_INCOMING	= RTCSS_IDLE + 1,
	RTCSS_ANSWERING	= RTCSS_INCOMING + 1,
	RTCSS_INPROGRESS	= RTCSS_ANSWERING + 1,
	RTCSS_CONNECTED	= RTCSS_INPROGRESS + 1,
	RTCSS_DISCONNECTED	= RTCSS_CONNECTED + 1,
	RTCSS_HOLD	= RTCSS_DISCONNECTED + 1,
	RTCSS_REFER	= RTCSS_HOLD + 1
    } 	RTC_SESSION_STATE;

typedef 
enum RTC_PARTICIPANT_STATE
    {	RTCPS_IDLE	= 0,
	RTCPS_PENDING	= RTCPS_IDLE + 1,
	RTCPS_INCOMING	= RTCPS_PENDING + 1,
	RTCPS_ANSWERING	= RTCPS_INCOMING + 1,
	RTCPS_INPROGRESS	= RTCPS_ANSWERING + 1,
	RTCPS_ALERTING	= RTCPS_INPROGRESS + 1,
	RTCPS_CONNECTED	= RTCPS_ALERTING + 1,
	RTCPS_DISCONNECTING	= RTCPS_CONNECTED + 1,
	RTCPS_DISCONNECTED	= RTCPS_DISCONNECTING + 1
    } 	RTC_PARTICIPANT_STATE;

typedef 
enum RTC_WATCHER_STATE
    {	RTCWS_UNKNOWN	= 0,
	RTCWS_OFFERING	= RTCWS_UNKNOWN + 1,
	RTCWS_ALLOWED	= RTCWS_OFFERING + 1,
	RTCWS_BLOCKED	= RTCWS_ALLOWED + 1,
	RTCWS_DENIED	= RTCWS_BLOCKED + 1,
	RTCWS_PROMPT	= RTCWS_DENIED + 1
    } 	RTC_WATCHER_STATE;

typedef 
enum RTC_ACE_SCOPE
    {	RTCAS_SCOPE_USER	= 0,
	RTCAS_SCOPE_DOMAIN	= RTCAS_SCOPE_USER + 1,
	RTCAS_SCOPE_ALL	= RTCAS_SCOPE_DOMAIN + 1
    } 	RTC_ACE_SCOPE;

typedef 
enum RTC_OFFER_WATCHER_MODE
    {	RTCOWM_OFFER_WATCHER_EVENT	= 0,
	RTCOWM_AUTOMATICALLY_ADD_WATCHER	= RTCOWM_OFFER_WATCHER_EVENT + 1
    } 	RTC_OFFER_WATCHER_MODE;

typedef 
enum RTC_WATCHER_MATCH_MODE
    {	RTCWMM_EXACT_MATCH	= 0,
	RTCWMM_BEST_ACE_MATCH	= RTCWMM_EXACT_MATCH + 1
    } 	RTC_WATCHER_MATCH_MODE;

typedef 
enum RTC_PRIVACY_MODE
    {	RTCPM_BLOCK_LIST_EXCLUDED	= 0,
	RTCPM_ALLOW_LIST_ONLY	= RTCPM_BLOCK_LIST_EXCLUDED + 1
    } 	RTC_PRIVACY_MODE;

typedef 
enum RTC_SESSION_TYPE
    {	RTCST_PC_TO_PC	= 0,
	RTCST_PC_TO_PHONE	= RTCST_PC_TO_PC + 1,
	RTCST_PHONE_TO_PHONE	= RTCST_PC_TO_PHONE + 1,
	RTCST_IM	= RTCST_PHONE_TO_PHONE + 1,
	RTCST_MULTIPARTY_IM	= RTCST_IM + 1,
	RTCST_APPLICATION	= RTCST_MULTIPARTY_IM + 1
    } 	RTC_SESSION_TYPE;

typedef 
enum RTC_PRESENCE_STATUS
    {	RTCXS_PRESENCE_OFFLINE	= 0,
	RTCXS_PRESENCE_ONLINE	= RTCXS_PRESENCE_OFFLINE + 1,
	RTCXS_PRESENCE_AWAY	= RTCXS_PRESENCE_ONLINE + 1,
	RTCXS_PRESENCE_IDLE	= RTCXS_PRESENCE_AWAY + 1,
	RTCXS_PRESENCE_BUSY	= RTCXS_PRESENCE_IDLE + 1,
	RTCXS_PRESENCE_BE_RIGHT_BACK	= RTCXS_PRESENCE_BUSY + 1,
	RTCXS_PRESENCE_ON_THE_PHONE	= RTCXS_PRESENCE_BE_RIGHT_BACK + 1,
	RTCXS_PRESENCE_OUT_TO_LUNCH	= RTCXS_PRESENCE_ON_THE_PHONE + 1
    } 	RTC_PRESENCE_STATUS;

typedef 
enum RTC_BUDDY_SUBSCRIPTION_TYPE
    {	RTCBT_SUBSCRIBED	= 0,
	RTCBT_ALWAYS_OFFLINE	= RTCBT_SUBSCRIBED + 1,
	RTCBT_ALWAYS_ONLINE	= RTCBT_ALWAYS_OFFLINE + 1,
	RTCBT_POLL	= RTCBT_ALWAYS_ONLINE + 1
    } 	RTC_BUDDY_SUBSCRIPTION_TYPE;

typedef 
enum RTC_MEDIA_EVENT_TYPE
    {	RTCMET_STOPPED	= 0,
	RTCMET_STARTED	= RTCMET_STOPPED + 1,
	RTCMET_FAILED	= RTCMET_STARTED + 1
    } 	RTC_MEDIA_EVENT_TYPE;

typedef 
enum RTC_MEDIA_EVENT_REASON
    {	RTCMER_NORMAL	= 0,
	RTCMER_HOLD	= RTCMER_NORMAL + 1,
	RTCMER_TIMEOUT	= RTCMER_HOLD + 1,
	RTCMER_BAD_DEVICE	= RTCMER_TIMEOUT + 1,
	RTCMER_NO_PORT	= RTCMER_BAD_DEVICE + 1,
	RTCMER_PORT_MAPPING_FAILED	= RTCMER_NO_PORT + 1,
	RTCMER_REMOTE_REQUEST	= RTCMER_PORT_MAPPING_FAILED + 1
    } 	RTC_MEDIA_EVENT_REASON;

typedef 
enum RTC_MESSAGING_EVENT_TYPE
    {	RTCMSET_MESSAGE	= 0,
	RTCMSET_STATUS	= RTCMSET_MESSAGE + 1
    } 	RTC_MESSAGING_EVENT_TYPE;

typedef 
enum RTC_MESSAGING_USER_STATUS
    {	RTCMUS_IDLE	= 0,
	RTCMUS_TYPING	= RTCMUS_IDLE + 1
    } 	RTC_MESSAGING_USER_STATUS;

typedef 
enum RTC_DTMF
    {	RTC_DTMF_0	= 0,
	RTC_DTMF_1	= RTC_DTMF_0 + 1,
	RTC_DTMF_2	= RTC_DTMF_1 + 1,
	RTC_DTMF_3	= RTC_DTMF_2 + 1,
	RTC_DTMF_4	= RTC_DTMF_3 + 1,
	RTC_DTMF_5	= RTC_DTMF_4 + 1,
	RTC_DTMF_6	= RTC_DTMF_5 + 1,
	RTC_DTMF_7	= RTC_DTMF_6 + 1,
	RTC_DTMF_8	= RTC_DTMF_7 + 1,
	RTC_DTMF_9	= RTC_DTMF_8 + 1,
	RTC_DTMF_STAR	= RTC_DTMF_9 + 1,
	RTC_DTMF_POUND	= RTC_DTMF_STAR + 1,
	RTC_DTMF_A	= RTC_DTMF_POUND + 1,
	RTC_DTMF_B	= RTC_DTMF_A + 1,
	RTC_DTMF_C	= RTC_DTMF_B + 1,
	RTC_DTMF_D	= RTC_DTMF_C + 1,
	RTC_DTMF_FLASH	= RTC_DTMF_D + 1
    } 	RTC_DTMF;

typedef 
enum RTC_PROVIDER_URI
    {	RTCPU_URIHOMEPAGE	= 0,
	RTCPU_URIHELPDESK	= RTCPU_URIHOMEPAGE + 1,
	RTCPU_URIPERSONALACCOUNT	= RTCPU_URIHELPDESK + 1,
	RTCPU_URIDISPLAYDURINGCALL	= RTCPU_URIPERSONALACCOUNT + 1,
	RTCPU_URIDISPLAYDURINGIDLE	= RTCPU_URIDISPLAYDURINGCALL + 1
    } 	RTC_PROVIDER_URI;

typedef 
enum RTC_RING_TYPE
    {	RTCRT_PHONE	= 0,
	RTCRT_MESSAGE	= RTCRT_PHONE + 1,
	RTCRT_RINGBACK	= RTCRT_MESSAGE + 1
    } 	RTC_RING_TYPE;

typedef 
enum RTC_T120_APPLET
    {	RTCTA_WHITEBOARD	= 0,
	RTCTA_APPSHARING	= RTCTA_WHITEBOARD + 1
    } 	RTC_T120_APPLET;

typedef 
enum RTC_PORT_TYPE
    {	RTCPT_AUDIO_RTP	= 0,
	RTCPT_AUDIO_RTCP	= RTCPT_AUDIO_RTP + 1,
	RTCPT_VIDEO_RTP	= RTCPT_AUDIO_RTCP + 1,
	RTCPT_VIDEO_RTCP	= RTCPT_VIDEO_RTP + 1,
	RTCPT_SIP	= RTCPT_VIDEO_RTCP + 1
    } 	RTC_PORT_TYPE;

typedef 
enum RTC_USER_SEARCH_COLUMN
    {	RTCUSC_URI	= 0,
	RTCUSC_DISPLAYNAME	= RTCUSC_URI + 1,
	RTCUSC_TITLE	= RTCUSC_DISPLAYNAME + 1,
	RTCUSC_OFFICE	= RTCUSC_TITLE + 1,
	RTCUSC_PHONE	= RTCUSC_OFFICE + 1,
	RTCUSC_COMPANY	= RTCUSC_PHONE + 1,
	RTCUSC_CITY	= RTCUSC_COMPANY + 1,
	RTCUSC_STATE	= RTCUSC_CITY + 1,
	RTCUSC_COUNTRY	= RTCUSC_STATE + 1,
	RTCUSC_EMAIL	= RTCUSC_COUNTRY + 1
    } 	RTC_USER_SEARCH_COLUMN;

typedef 
enum RTC_USER_SEARCH_PREFERENCE
    {	RTCUSP_MAX_MATCHES	= 0,
	RTCUSP_TIME_LIMIT	= RTCUSP_MAX_MATCHES + 1
    } 	RTC_USER_SEARCH_PREFERENCE;

typedef 
enum RTC_ROAMING_EVENT_TYPE
    {	RTCRET_BUDDY_ROAMING	= 0,
	RTCRET_WATCHER_ROAMING	= RTCRET_BUDDY_ROAMING + 1,
	RTCRET_PRESENCE_ROAMING	= RTCRET_WATCHER_ROAMING + 1,
	RTCRET_PROFILE_ROAMING	= RTCRET_PRESENCE_ROAMING + 1,
	RTCRET_WPENDING_ROAMING	= RTCRET_PROFILE_ROAMING + 1
    } 	RTC_ROAMING_EVENT_TYPE;

typedef 
enum RTC_PROFILE_EVENT_TYPE
    {	RTCPFET_PROFILE_GET	= 0,
	RTCPFET_PROFILE_UPDATE	= RTCPFET_PROFILE_GET + 1
    } 	RTC_PROFILE_EVENT_TYPE;

typedef 
enum RTC_ANSWER_MODE
    {	RTCAM_OFFER_SESSION_EVENT	= 0,
	RTCAM_AUTOMATICALLY_ACCEPT	= RTCAM_OFFER_SESSION_EVENT + 1,
	RTCAM_AUTOMATICALLY_REJECT	= RTCAM_AUTOMATICALLY_ACCEPT + 1,
	RTCAM_NOT_SUPPORTED	= RTCAM_AUTOMATICALLY_REJECT + 1
    } 	RTC_ANSWER_MODE;

typedef 
enum RTC_SESSION_REFER_STATUS
    {	RTCSRS_REFERRING	= 0,
	RTCSRS_ACCEPTED	= RTCSRS_REFERRING + 1,
	RTCSRS_ERROR	= RTCSRS_ACCEPTED + 1,
	RTCSRS_REJECTED	= RTCSRS_ERROR + 1,
	RTCSRS_DROPPED	= RTCSRS_REJECTED + 1,
	RTCSRS_DONE	= RTCSRS_DROPPED + 1
    } 	RTC_SESSION_REFER_STATUS;

typedef 
enum RTC_PRESENCE_PROPERTY
    {	RTCPP_PHONENUMBER	= 0,
	RTCPP_DISPLAYNAME	= RTCPP_PHONENUMBER + 1,
	RTCPP_EMAIL	= RTCPP_DISPLAYNAME + 1,
	RTCPP_DEVICE_NAME	= RTCPP_EMAIL + 1,
	RTCPP_MULTIPLE	= RTCPP_DEVICE_NAME + 1
    } 	RTC_PRESENCE_PROPERTY;

typedef 
enum RTC_SECURITY_TYPE
    {	RTCSECT_AUDIO_VIDEO_MEDIA_ENCRYPTION	= 0,
	RTCSECT_T120_MEDIA_ENCRYPTION	= RTCSECT_AUDIO_VIDEO_MEDIA_ENCRYPTION + 1
    } 	RTC_SECURITY_TYPE;

typedef 
enum RTC_SECURITY_LEVEL
    {	RTCSECL_UNSUPPORTED	= 1,
	RTCSECL_SUPPORTED	= RTCSECL_UNSUPPORTED + 1,
	RTCSECL_REQUIRED	= RTCSECL_SUPPORTED + 1
    } 	RTC_SECURITY_LEVEL;

typedef 
enum RTC_REINVITE_STATE
    {	RTCRIN_INCOMING	= 0,
	RTCRIN_SUCCEEDED	= RTCRIN_INCOMING + 1,
	RTCRIN_FAIL	= RTCRIN_SUCCEEDED + 1
    } 	RTC_REINVITE_STATE;

#define RTCCS_FORCE_PROFILE          0x00000001
#define RTCCS_FAIL_ON_REDIRECT       0x00000002
#define RTCMT_AUDIO_SEND     0x00000001
#define RTCMT_AUDIO_RECEIVE  0x00000002
#define RTCMT_VIDEO_SEND     0x00000004
#define RTCMT_VIDEO_RECEIVE  0x00000008
#define RTCMT_T120_SENDRECV  0x00000010
#define RTCMT_ALL_RTP   (       \
         RTCMT_AUDIO_SEND    |  \
         RTCMT_AUDIO_RECEIVE  | \
         RTCMT_VIDEO_SEND  |    \
         RTCMT_VIDEO_RECEIVE )    
#define RTCMT_ALL       (       \
         RTCMT_ALL_RTP    |     \
         RTCMT_T120_SENDRECV  )   
#define RTCSI_PC_TO_PC       0x00000001
#define RTCSI_PC_TO_PHONE    0x00000002
#define RTCSI_PHONE_TO_PHONE 0x00000004
#define RTCSI_IM             0x00000008
#define RTCSI_MULTIPARTY_IM  0x00000010
#define RTCSI_APPLICATION	0x00000020
#define RTCTR_UDP            0x00000001
#define RTCTR_TCP            0x00000002
#define RTCTR_TLS            0x00000004
#define RTCAU_BASIC                  0x00000001
#define RTCAU_DIGEST                 0x00000002
#define RTCAU_NTLM                   0x00000004
#define RTCAU_KERBEROS               0x00000008
#define RTCAU_USE_LOGON_CRED         0x00010000
#define RTCRF_REGISTER_INVITE_SESSIONS   0x00000001
#define RTCRF_REGISTER_MESSAGE_SESSIONS  0x00000002
#define RTCRF_REGISTER_PRESENCE          0x00000004
#define RTCRF_REGISTER_NOTIFY            0x00000008
#define RTCRF_REGISTER_ALL               0x0000000F
#define RTCRMF_BUDDY_ROAMING              0x00000001
#define RTCRMF_WATCHER_ROAMING            0x00000002
#define RTCRMF_PRESENCE_ROAMING           0x00000004
#define RTCRMF_PROFILE_ROAMING            0x00000008
#define RTCRMF_ALL_ROAMING                0x0000000F
#define RTCEF_CLIENT                     0x00000001
#define RTCEF_REGISTRATION_STATE_CHANGE  0x00000002
#define RTCEF_SESSION_STATE_CHANGE       0x00000004
#define RTCEF_SESSION_OPERATION_COMPLETE 0x00000008
#define RTCEF_PARTICIPANT_STATE_CHANGE   0x00000010
#define RTCEF_MEDIA                      0x00000020
#define RTCEF_INTENSITY                  0x00000040
#define RTCEF_MESSAGING                  0x00000080
#define RTCEF_BUDDY                      0x00000100
#define RTCEF_WATCHER                    0x00000200
#define RTCEF_PROFILE                    0x00000400
#define RTCEF_USERSEARCH                 0x00000800
#define RTCEF_INFO                       0x00001000
#define RTCEF_GROUP                      0x00002000
#define RTCEF_MEDIA_REQUEST              0x00004000
#define RTCEF_ROAMING                    0x00010000
#define RTCEF_PRESENCE_PROPERTY          0x00020000
#define RTCEF_BUDDY2                     0x00040000
#define RTCEF_WATCHER2                   0x00080000
#define RTCEF_SESSION_REFER_STATUS       0x00100000
#define RTCEF_SESSION_REFERRED           0x00200000
#define RTCEF_REINVITE                   0x00400000
#define RTCEF_PRESENCE_DATA              0x00800000
#define RTCEF_PRESENCE_STATUS            0x01000000
#define RTCEF_ALL                        0x01FFFFFF
#define RTCIF_DISABLE_MEDIA                          0x00000001
#define RTCIF_DISABLE_UPNP                           0x00000002
#define RTCIF_ENABLE_SERVER_CLASS                    0x00000004
#define RTCIF_DISABLE_STRICT_DNS                     0x00000008




































extern RPC_IF_HANDLE __MIDL_itf_rtccore_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_rtccore_0000_v0_0_s_ifspec;

#ifndef __IRTCClient_INTERFACE_DEFINED__
#define __IRTCClient_INTERFACE_DEFINED__

/* interface IRTCClient */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("07829e45-9a34-408e-a011-bddf13487cd1")
    IRTCClient : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Shutdown( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PrepareForShutdown( void) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_EventFilter( 
            /* [in] */ long lFilter) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EventFilter( 
            /* [retval][out] */ long *plFilter) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPreferredMediaTypes( 
            /* [in] */ long lMediaTypes,
            /* [in] */ VARIANT_BOOL fPersistent) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredMediaTypes( 
            /* [retval][out] */ long *plMediaTypes) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MediaCapabilities( 
            /* [retval][out] */ long *plMediaTypes) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateSession( 
            /* [in] */ RTC_SESSION_TYPE enType,
            /* [in] */ BSTR bstrLocalPhoneURI,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCSession **ppSession) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ListenForIncomingSessions( 
            /* [in] */ RTC_LISTEN_MODE enListen) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ListenForIncomingSessions( 
            /* [retval][out] */ RTC_LISTEN_MODE *penListen) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NetworkAddresses( 
            /* [in] */ VARIANT_BOOL fTCP,
            /* [in] */ VARIANT_BOOL fExternal,
            /* [retval][out] */ VARIANT *pvAddresses) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ long lVolume) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ long *plVolume) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AudioMuted( 
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ VARIANT_BOOL fMuted) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioMuted( 
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ VARIANT_BOOL *pfMuted) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IVideoWindow( 
            /* [in] */ RTC_VIDEO_DEVICE enDevice,
            /* [retval][out] */ IVideoWindow **ppIVideoWindow) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredAudioDevice( 
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ BSTR bstrDeviceName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredAudioDevice( 
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ BSTR *pbstrDeviceName) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredVolume( 
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ long lVolume) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredVolume( 
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ long *plVolume) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredAEC( 
            /* [in] */ VARIANT_BOOL bEnable) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredAEC( 
            /* [retval][out] */ VARIANT_BOOL *pbEnabled) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredVideoDevice( 
            /* [in] */ BSTR bstrDeviceName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredVideoDevice( 
            /* [retval][out] */ BSTR *pbstrDeviceName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveMedia( 
            /* [retval][out] */ long *plMediaType) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_MaxBitrate( 
            /* [in] */ long lMaxBitrate) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MaxBitrate( 
            /* [retval][out] */ long *plMaxBitrate) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_TemporalSpatialTradeOff( 
            /* [in] */ long lValue) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_TemporalSpatialTradeOff( 
            /* [retval][out] */ long *plValue) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NetworkQuality( 
            /* [retval][out] */ long *plNetworkQuality) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StartT120Applet( 
            /* [in] */ RTC_T120_APPLET enApplet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StopT120Applets( void) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsT120AppletRunning( 
            /* [in] */ RTC_T120_APPLET enApplet,
            /* [retval][out] */ VARIANT_BOOL *pfRunning) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LocalUserURI( 
            /* [retval][out] */ BSTR *pbstrUserURI) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_LocalUserURI( 
            /* [in] */ BSTR bstrUserURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LocalUserName( 
            /* [retval][out] */ BSTR *pbstrUserName) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_LocalUserName( 
            /* [in] */ BSTR bstrUserName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PlayRing( 
            /* [in] */ RTC_RING_TYPE enType,
            /* [in] */ VARIANT_BOOL bPlay) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendDTMF( 
            /* [in] */ RTC_DTMF enDTMF) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InvokeTuningWizard( 
            /* [in] */ OAHWND hwndParent) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsTuned( 
            /* [retval][out] */ VARIANT_BOOL *pfTuned) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCClient * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCClient * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IRTCClient * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Shutdown )( 
            IRTCClient * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PrepareForShutdown )( 
            IRTCClient * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EventFilter )( 
            IRTCClient * This,
            /* [in] */ long lFilter);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventFilter )( 
            IRTCClient * This,
            /* [retval][out] */ long *plFilter);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPreferredMediaTypes )( 
            IRTCClient * This,
            /* [in] */ long lMediaTypes,
            /* [in] */ VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredMediaTypes )( 
            IRTCClient * This,
            /* [retval][out] */ long *plMediaTypes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MediaCapabilities )( 
            IRTCClient * This,
            /* [retval][out] */ long *plMediaTypes);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateSession )( 
            IRTCClient * This,
            /* [in] */ RTC_SESSION_TYPE enType,
            /* [in] */ BSTR bstrLocalPhoneURI,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCSession **ppSession);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ListenForIncomingSessions )( 
            IRTCClient * This,
            /* [in] */ RTC_LISTEN_MODE enListen);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ListenForIncomingSessions )( 
            IRTCClient * This,
            /* [retval][out] */ RTC_LISTEN_MODE *penListen);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetworkAddresses )( 
            IRTCClient * This,
            /* [in] */ VARIANT_BOOL fTCP,
            /* [in] */ VARIANT_BOOL fExternal,
            /* [retval][out] */ VARIANT *pvAddresses);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            IRTCClient * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ long lVolume);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            IRTCClient * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ long *plVolume);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AudioMuted )( 
            IRTCClient * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ VARIANT_BOOL fMuted);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioMuted )( 
            IRTCClient * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ VARIANT_BOOL *pfMuted);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IVideoWindow )( 
            IRTCClient * This,
            /* [in] */ RTC_VIDEO_DEVICE enDevice,
            /* [retval][out] */ IVideoWindow **ppIVideoWindow);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredAudioDevice )( 
            IRTCClient * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ BSTR bstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredAudioDevice )( 
            IRTCClient * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ BSTR *pbstrDeviceName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredVolume )( 
            IRTCClient * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ long lVolume);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredVolume )( 
            IRTCClient * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ long *plVolume);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredAEC )( 
            IRTCClient * This,
            /* [in] */ VARIANT_BOOL bEnable);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredAEC )( 
            IRTCClient * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnabled);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredVideoDevice )( 
            IRTCClient * This,
            /* [in] */ BSTR bstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredVideoDevice )( 
            IRTCClient * This,
            /* [retval][out] */ BSTR *pbstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveMedia )( 
            IRTCClient * This,
            /* [retval][out] */ long *plMediaType);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxBitrate )( 
            IRTCClient * This,
            /* [in] */ long lMaxBitrate);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxBitrate )( 
            IRTCClient * This,
            /* [retval][out] */ long *plMaxBitrate);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TemporalSpatialTradeOff )( 
            IRTCClient * This,
            /* [in] */ long lValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TemporalSpatialTradeOff )( 
            IRTCClient * This,
            /* [retval][out] */ long *plValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetworkQuality )( 
            IRTCClient * This,
            /* [retval][out] */ long *plNetworkQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartT120Applet )( 
            IRTCClient * This,
            /* [in] */ RTC_T120_APPLET enApplet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StopT120Applets )( 
            IRTCClient * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsT120AppletRunning )( 
            IRTCClient * This,
            /* [in] */ RTC_T120_APPLET enApplet,
            /* [retval][out] */ VARIANT_BOOL *pfRunning);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalUserURI )( 
            IRTCClient * This,
            /* [retval][out] */ BSTR *pbstrUserURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalUserURI )( 
            IRTCClient * This,
            /* [in] */ BSTR bstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalUserName )( 
            IRTCClient * This,
            /* [retval][out] */ BSTR *pbstrUserName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalUserName )( 
            IRTCClient * This,
            /* [in] */ BSTR bstrUserName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PlayRing )( 
            IRTCClient * This,
            /* [in] */ RTC_RING_TYPE enType,
            /* [in] */ VARIANT_BOOL bPlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendDTMF )( 
            IRTCClient * This,
            /* [in] */ RTC_DTMF enDTMF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InvokeTuningWizard )( 
            IRTCClient * This,
            /* [in] */ OAHWND hwndParent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsTuned )( 
            IRTCClient * This,
            /* [retval][out] */ VARIANT_BOOL *pfTuned);
        
        END_INTERFACE
    } IRTCClientVtbl;

    interface IRTCClient
    {
        CONST_VTBL struct IRTCClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClient_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCClient_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCClient_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCClient_Initialize(This)	\
    (This)->lpVtbl -> Initialize(This)

#define IRTCClient_Shutdown(This)	\
    (This)->lpVtbl -> Shutdown(This)

#define IRTCClient_PrepareForShutdown(This)	\
    (This)->lpVtbl -> PrepareForShutdown(This)

#define IRTCClient_put_EventFilter(This,lFilter)	\
    (This)->lpVtbl -> put_EventFilter(This,lFilter)

#define IRTCClient_get_EventFilter(This,plFilter)	\
    (This)->lpVtbl -> get_EventFilter(This,plFilter)

#define IRTCClient_SetPreferredMediaTypes(This,lMediaTypes,fPersistent)	\
    (This)->lpVtbl -> SetPreferredMediaTypes(This,lMediaTypes,fPersistent)

#define IRTCClient_get_PreferredMediaTypes(This,plMediaTypes)	\
    (This)->lpVtbl -> get_PreferredMediaTypes(This,plMediaTypes)

#define IRTCClient_get_MediaCapabilities(This,plMediaTypes)	\
    (This)->lpVtbl -> get_MediaCapabilities(This,plMediaTypes)

#define IRTCClient_CreateSession(This,enType,bstrLocalPhoneURI,pProfile,lFlags,ppSession)	\
    (This)->lpVtbl -> CreateSession(This,enType,bstrLocalPhoneURI,pProfile,lFlags,ppSession)

#define IRTCClient_put_ListenForIncomingSessions(This,enListen)	\
    (This)->lpVtbl -> put_ListenForIncomingSessions(This,enListen)

#define IRTCClient_get_ListenForIncomingSessions(This,penListen)	\
    (This)->lpVtbl -> get_ListenForIncomingSessions(This,penListen)

#define IRTCClient_get_NetworkAddresses(This,fTCP,fExternal,pvAddresses)	\
    (This)->lpVtbl -> get_NetworkAddresses(This,fTCP,fExternal,pvAddresses)

#define IRTCClient_put_Volume(This,enDevice,lVolume)	\
    (This)->lpVtbl -> put_Volume(This,enDevice,lVolume)

#define IRTCClient_get_Volume(This,enDevice,plVolume)	\
    (This)->lpVtbl -> get_Volume(This,enDevice,plVolume)

#define IRTCClient_put_AudioMuted(This,enDevice,fMuted)	\
    (This)->lpVtbl -> put_AudioMuted(This,enDevice,fMuted)

#define IRTCClient_get_AudioMuted(This,enDevice,pfMuted)	\
    (This)->lpVtbl -> get_AudioMuted(This,enDevice,pfMuted)

#define IRTCClient_get_IVideoWindow(This,enDevice,ppIVideoWindow)	\
    (This)->lpVtbl -> get_IVideoWindow(This,enDevice,ppIVideoWindow)

#define IRTCClient_put_PreferredAudioDevice(This,enDevice,bstrDeviceName)	\
    (This)->lpVtbl -> put_PreferredAudioDevice(This,enDevice,bstrDeviceName)

#define IRTCClient_get_PreferredAudioDevice(This,enDevice,pbstrDeviceName)	\
    (This)->lpVtbl -> get_PreferredAudioDevice(This,enDevice,pbstrDeviceName)

#define IRTCClient_put_PreferredVolume(This,enDevice,lVolume)	\
    (This)->lpVtbl -> put_PreferredVolume(This,enDevice,lVolume)

#define IRTCClient_get_PreferredVolume(This,enDevice,plVolume)	\
    (This)->lpVtbl -> get_PreferredVolume(This,enDevice,plVolume)

#define IRTCClient_put_PreferredAEC(This,bEnable)	\
    (This)->lpVtbl -> put_PreferredAEC(This,bEnable)

#define IRTCClient_get_PreferredAEC(This,pbEnabled)	\
    (This)->lpVtbl -> get_PreferredAEC(This,pbEnabled)

#define IRTCClient_put_PreferredVideoDevice(This,bstrDeviceName)	\
    (This)->lpVtbl -> put_PreferredVideoDevice(This,bstrDeviceName)

#define IRTCClient_get_PreferredVideoDevice(This,pbstrDeviceName)	\
    (This)->lpVtbl -> get_PreferredVideoDevice(This,pbstrDeviceName)

#define IRTCClient_get_ActiveMedia(This,plMediaType)	\
    (This)->lpVtbl -> get_ActiveMedia(This,plMediaType)

#define IRTCClient_put_MaxBitrate(This,lMaxBitrate)	\
    (This)->lpVtbl -> put_MaxBitrate(This,lMaxBitrate)

#define IRTCClient_get_MaxBitrate(This,plMaxBitrate)	\
    (This)->lpVtbl -> get_MaxBitrate(This,plMaxBitrate)

#define IRTCClient_put_TemporalSpatialTradeOff(This,lValue)	\
    (This)->lpVtbl -> put_TemporalSpatialTradeOff(This,lValue)

#define IRTCClient_get_TemporalSpatialTradeOff(This,plValue)	\
    (This)->lpVtbl -> get_TemporalSpatialTradeOff(This,plValue)

#define IRTCClient_get_NetworkQuality(This,plNetworkQuality)	\
    (This)->lpVtbl -> get_NetworkQuality(This,plNetworkQuality)

#define IRTCClient_StartT120Applet(This,enApplet)	\
    (This)->lpVtbl -> StartT120Applet(This,enApplet)

#define IRTCClient_StopT120Applets(This)	\
    (This)->lpVtbl -> StopT120Applets(This)

#define IRTCClient_get_IsT120AppletRunning(This,enApplet,pfRunning)	\
    (This)->lpVtbl -> get_IsT120AppletRunning(This,enApplet,pfRunning)

#define IRTCClient_get_LocalUserURI(This,pbstrUserURI)	\
    (This)->lpVtbl -> get_LocalUserURI(This,pbstrUserURI)

#define IRTCClient_put_LocalUserURI(This,bstrUserURI)	\
    (This)->lpVtbl -> put_LocalUserURI(This,bstrUserURI)

#define IRTCClient_get_LocalUserName(This,pbstrUserName)	\
    (This)->lpVtbl -> get_LocalUserName(This,pbstrUserName)

#define IRTCClient_put_LocalUserName(This,bstrUserName)	\
    (This)->lpVtbl -> put_LocalUserName(This,bstrUserName)

#define IRTCClient_PlayRing(This,enType,bPlay)	\
    (This)->lpVtbl -> PlayRing(This,enType,bPlay)

#define IRTCClient_SendDTMF(This,enDTMF)	\
    (This)->lpVtbl -> SendDTMF(This,enDTMF)

#define IRTCClient_InvokeTuningWizard(This,hwndParent)	\
    (This)->lpVtbl -> InvokeTuningWizard(This,hwndParent)

#define IRTCClient_get_IsTuned(This,pfTuned)	\
    (This)->lpVtbl -> get_IsTuned(This,pfTuned)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient_Initialize_Proxy( 
    IRTCClient * This);


void __RPC_STUB IRTCClient_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient_Shutdown_Proxy( 
    IRTCClient * This);


void __RPC_STUB IRTCClient_Shutdown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient_PrepareForShutdown_Proxy( 
    IRTCClient * This);


void __RPC_STUB IRTCClient_PrepareForShutdown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_EventFilter_Proxy( 
    IRTCClient * This,
    /* [in] */ long lFilter);


void __RPC_STUB IRTCClient_put_EventFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_EventFilter_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ long *plFilter);


void __RPC_STUB IRTCClient_get_EventFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient_SetPreferredMediaTypes_Proxy( 
    IRTCClient * This,
    /* [in] */ long lMediaTypes,
    /* [in] */ VARIANT_BOOL fPersistent);


void __RPC_STUB IRTCClient_SetPreferredMediaTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_PreferredMediaTypes_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ long *plMediaTypes);


void __RPC_STUB IRTCClient_get_PreferredMediaTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_MediaCapabilities_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ long *plMediaTypes);


void __RPC_STUB IRTCClient_get_MediaCapabilities_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient_CreateSession_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_SESSION_TYPE enType,
    /* [in] */ BSTR bstrLocalPhoneURI,
    /* [in] */ IRTCProfile *pProfile,
    /* [in] */ long lFlags,
    /* [retval][out] */ IRTCSession **ppSession);


void __RPC_STUB IRTCClient_CreateSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_ListenForIncomingSessions_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_LISTEN_MODE enListen);


void __RPC_STUB IRTCClient_put_ListenForIncomingSessions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_ListenForIncomingSessions_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ RTC_LISTEN_MODE *penListen);


void __RPC_STUB IRTCClient_get_ListenForIncomingSessions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_NetworkAddresses_Proxy( 
    IRTCClient * This,
    /* [in] */ VARIANT_BOOL fTCP,
    /* [in] */ VARIANT_BOOL fExternal,
    /* [retval][out] */ VARIANT *pvAddresses);


void __RPC_STUB IRTCClient_get_NetworkAddresses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_Volume_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_AUDIO_DEVICE enDevice,
    /* [in] */ long lVolume);


void __RPC_STUB IRTCClient_put_Volume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_Volume_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_AUDIO_DEVICE enDevice,
    /* [retval][out] */ long *plVolume);


void __RPC_STUB IRTCClient_get_Volume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_AudioMuted_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_AUDIO_DEVICE enDevice,
    /* [in] */ VARIANT_BOOL fMuted);


void __RPC_STUB IRTCClient_put_AudioMuted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_AudioMuted_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_AUDIO_DEVICE enDevice,
    /* [retval][out] */ VARIANT_BOOL *pfMuted);


void __RPC_STUB IRTCClient_get_AudioMuted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_IVideoWindow_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_VIDEO_DEVICE enDevice,
    /* [retval][out] */ IVideoWindow **ppIVideoWindow);


void __RPC_STUB IRTCClient_get_IVideoWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_PreferredAudioDevice_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_AUDIO_DEVICE enDevice,
    /* [in] */ BSTR bstrDeviceName);


void __RPC_STUB IRTCClient_put_PreferredAudioDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_PreferredAudioDevice_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_AUDIO_DEVICE enDevice,
    /* [retval][out] */ BSTR *pbstrDeviceName);


void __RPC_STUB IRTCClient_get_PreferredAudioDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_PreferredVolume_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_AUDIO_DEVICE enDevice,
    /* [in] */ long lVolume);


void __RPC_STUB IRTCClient_put_PreferredVolume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_PreferredVolume_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_AUDIO_DEVICE enDevice,
    /* [retval][out] */ long *plVolume);


void __RPC_STUB IRTCClient_get_PreferredVolume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_PreferredAEC_Proxy( 
    IRTCClient * This,
    /* [in] */ VARIANT_BOOL bEnable);


void __RPC_STUB IRTCClient_put_PreferredAEC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_PreferredAEC_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ VARIANT_BOOL *pbEnabled);


void __RPC_STUB IRTCClient_get_PreferredAEC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_PreferredVideoDevice_Proxy( 
    IRTCClient * This,
    /* [in] */ BSTR bstrDeviceName);


void __RPC_STUB IRTCClient_put_PreferredVideoDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_PreferredVideoDevice_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ BSTR *pbstrDeviceName);


void __RPC_STUB IRTCClient_get_PreferredVideoDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_ActiveMedia_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ long *plMediaType);


void __RPC_STUB IRTCClient_get_ActiveMedia_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_MaxBitrate_Proxy( 
    IRTCClient * This,
    /* [in] */ long lMaxBitrate);


void __RPC_STUB IRTCClient_put_MaxBitrate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_MaxBitrate_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ long *plMaxBitrate);


void __RPC_STUB IRTCClient_get_MaxBitrate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_TemporalSpatialTradeOff_Proxy( 
    IRTCClient * This,
    /* [in] */ long lValue);


void __RPC_STUB IRTCClient_put_TemporalSpatialTradeOff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_TemporalSpatialTradeOff_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ long *plValue);


void __RPC_STUB IRTCClient_get_TemporalSpatialTradeOff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_NetworkQuality_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ long *plNetworkQuality);


void __RPC_STUB IRTCClient_get_NetworkQuality_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient_StartT120Applet_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_T120_APPLET enApplet);


void __RPC_STUB IRTCClient_StartT120Applet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient_StopT120Applets_Proxy( 
    IRTCClient * This);


void __RPC_STUB IRTCClient_StopT120Applets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_IsT120AppletRunning_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_T120_APPLET enApplet,
    /* [retval][out] */ VARIANT_BOOL *pfRunning);


void __RPC_STUB IRTCClient_get_IsT120AppletRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_LocalUserURI_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ BSTR *pbstrUserURI);


void __RPC_STUB IRTCClient_get_LocalUserURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_LocalUserURI_Proxy( 
    IRTCClient * This,
    /* [in] */ BSTR bstrUserURI);


void __RPC_STUB IRTCClient_put_LocalUserURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_LocalUserName_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ BSTR *pbstrUserName);


void __RPC_STUB IRTCClient_get_LocalUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient_put_LocalUserName_Proxy( 
    IRTCClient * This,
    /* [in] */ BSTR bstrUserName);


void __RPC_STUB IRTCClient_put_LocalUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient_PlayRing_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_RING_TYPE enType,
    /* [in] */ VARIANT_BOOL bPlay);


void __RPC_STUB IRTCClient_PlayRing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient_SendDTMF_Proxy( 
    IRTCClient * This,
    /* [in] */ RTC_DTMF enDTMF);


void __RPC_STUB IRTCClient_SendDTMF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient_InvokeTuningWizard_Proxy( 
    IRTCClient * This,
    /* [in] */ OAHWND hwndParent);


void __RPC_STUB IRTCClient_InvokeTuningWizard_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient_get_IsTuned_Proxy( 
    IRTCClient * This,
    /* [retval][out] */ VARIANT_BOOL *pfTuned);


void __RPC_STUB IRTCClient_get_IsTuned_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCClient_INTERFACE_DEFINED__ */


#ifndef __IRTCClient2_INTERFACE_DEFINED__
#define __IRTCClient2_INTERFACE_DEFINED__

/* interface IRTCClient2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClient2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0C91D71D-1064-42da-BFA5-572BEB8EEA84")
    IRTCClient2 : public IRTCClient
    {
    public:
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AnswerMode( 
            /* [in] */ RTC_SESSION_TYPE enType,
            /* [in] */ RTC_ANSWER_MODE enMode) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AnswerMode( 
            /* [in] */ RTC_SESSION_TYPE enType,
            /* [retval][out] */ RTC_ANSWER_MODE *penMode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InvokeTuningWizardEx( 
            /* [in] */ OAHWND hwndParent,
            /* [in] */ VARIANT_BOOL fAllowAudio,
            /* [in] */ VARIANT_BOOL fAllowVideo) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ long *plVersion) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ClientName( 
            /* [in] */ BSTR bstrClientName) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ClientCurVer( 
            /* [in] */ BSTR bstrClientCurVer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InitializeEx( 
            /* [in] */ long lFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateSessionWithDescription( 
            /* [in] */ BSTR bstrContentType,
            /* [in] */ BSTR bstrSessionDescription,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCSession2 **ppSession2) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSessionDescriptionManager( 
            /* [in] */ IRTCSessionDescriptionManager *pSessionDescriptionManager) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredSecurityLevel( 
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [in] */ RTC_SECURITY_LEVEL enSecurityLevel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredSecurityLevel( 
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AllowedPorts( 
            /* [in] */ long lTransport,
            /* [in] */ RTC_LISTEN_MODE enListenMode) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AllowedPorts( 
            /* [in] */ long lTransport,
            /* [retval][out] */ RTC_LISTEN_MODE *penListenMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCClient2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCClient2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCClient2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCClient2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IRTCClient2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Shutdown )( 
            IRTCClient2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PrepareForShutdown )( 
            IRTCClient2 * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EventFilter )( 
            IRTCClient2 * This,
            /* [in] */ long lFilter);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventFilter )( 
            IRTCClient2 * This,
            /* [retval][out] */ long *plFilter);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPreferredMediaTypes )( 
            IRTCClient2 * This,
            /* [in] */ long lMediaTypes,
            /* [in] */ VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredMediaTypes )( 
            IRTCClient2 * This,
            /* [retval][out] */ long *plMediaTypes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MediaCapabilities )( 
            IRTCClient2 * This,
            /* [retval][out] */ long *plMediaTypes);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateSession )( 
            IRTCClient2 * This,
            /* [in] */ RTC_SESSION_TYPE enType,
            /* [in] */ BSTR bstrLocalPhoneURI,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCSession **ppSession);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ListenForIncomingSessions )( 
            IRTCClient2 * This,
            /* [in] */ RTC_LISTEN_MODE enListen);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ListenForIncomingSessions )( 
            IRTCClient2 * This,
            /* [retval][out] */ RTC_LISTEN_MODE *penListen);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetworkAddresses )( 
            IRTCClient2 * This,
            /* [in] */ VARIANT_BOOL fTCP,
            /* [in] */ VARIANT_BOOL fExternal,
            /* [retval][out] */ VARIANT *pvAddresses);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            IRTCClient2 * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ long lVolume);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            IRTCClient2 * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ long *plVolume);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AudioMuted )( 
            IRTCClient2 * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ VARIANT_BOOL fMuted);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioMuted )( 
            IRTCClient2 * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ VARIANT_BOOL *pfMuted);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IVideoWindow )( 
            IRTCClient2 * This,
            /* [in] */ RTC_VIDEO_DEVICE enDevice,
            /* [retval][out] */ IVideoWindow **ppIVideoWindow);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredAudioDevice )( 
            IRTCClient2 * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ BSTR bstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredAudioDevice )( 
            IRTCClient2 * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ BSTR *pbstrDeviceName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredVolume )( 
            IRTCClient2 * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [in] */ long lVolume);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredVolume )( 
            IRTCClient2 * This,
            /* [in] */ RTC_AUDIO_DEVICE enDevice,
            /* [retval][out] */ long *plVolume);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredAEC )( 
            IRTCClient2 * This,
            /* [in] */ VARIANT_BOOL bEnable);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredAEC )( 
            IRTCClient2 * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnabled);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredVideoDevice )( 
            IRTCClient2 * This,
            /* [in] */ BSTR bstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredVideoDevice )( 
            IRTCClient2 * This,
            /* [retval][out] */ BSTR *pbstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveMedia )( 
            IRTCClient2 * This,
            /* [retval][out] */ long *plMediaType);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxBitrate )( 
            IRTCClient2 * This,
            /* [in] */ long lMaxBitrate);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxBitrate )( 
            IRTCClient2 * This,
            /* [retval][out] */ long *plMaxBitrate);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TemporalSpatialTradeOff )( 
            IRTCClient2 * This,
            /* [in] */ long lValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TemporalSpatialTradeOff )( 
            IRTCClient2 * This,
            /* [retval][out] */ long *plValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetworkQuality )( 
            IRTCClient2 * This,
            /* [retval][out] */ long *plNetworkQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartT120Applet )( 
            IRTCClient2 * This,
            /* [in] */ RTC_T120_APPLET enApplet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StopT120Applets )( 
            IRTCClient2 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsT120AppletRunning )( 
            IRTCClient2 * This,
            /* [in] */ RTC_T120_APPLET enApplet,
            /* [retval][out] */ VARIANT_BOOL *pfRunning);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalUserURI )( 
            IRTCClient2 * This,
            /* [retval][out] */ BSTR *pbstrUserURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalUserURI )( 
            IRTCClient2 * This,
            /* [in] */ BSTR bstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalUserName )( 
            IRTCClient2 * This,
            /* [retval][out] */ BSTR *pbstrUserName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalUserName )( 
            IRTCClient2 * This,
            /* [in] */ BSTR bstrUserName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PlayRing )( 
            IRTCClient2 * This,
            /* [in] */ RTC_RING_TYPE enType,
            /* [in] */ VARIANT_BOOL bPlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendDTMF )( 
            IRTCClient2 * This,
            /* [in] */ RTC_DTMF enDTMF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InvokeTuningWizard )( 
            IRTCClient2 * This,
            /* [in] */ OAHWND hwndParent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsTuned )( 
            IRTCClient2 * This,
            /* [retval][out] */ VARIANT_BOOL *pfTuned);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AnswerMode )( 
            IRTCClient2 * This,
            /* [in] */ RTC_SESSION_TYPE enType,
            /* [in] */ RTC_ANSWER_MODE enMode);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AnswerMode )( 
            IRTCClient2 * This,
            /* [in] */ RTC_SESSION_TYPE enType,
            /* [retval][out] */ RTC_ANSWER_MODE *penMode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InvokeTuningWizardEx )( 
            IRTCClient2 * This,
            /* [in] */ OAHWND hwndParent,
            /* [in] */ VARIANT_BOOL fAllowAudio,
            /* [in] */ VARIANT_BOOL fAllowVideo);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            IRTCClient2 * This,
            /* [retval][out] */ long *plVersion);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClientName )( 
            IRTCClient2 * This,
            /* [in] */ BSTR bstrClientName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClientCurVer )( 
            IRTCClient2 * This,
            /* [in] */ BSTR bstrClientCurVer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InitializeEx )( 
            IRTCClient2 * This,
            /* [in] */ long lFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateSessionWithDescription )( 
            IRTCClient2 * This,
            /* [in] */ BSTR bstrContentType,
            /* [in] */ BSTR bstrSessionDescription,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCSession2 **ppSession2);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSessionDescriptionManager )( 
            IRTCClient2 * This,
            /* [in] */ IRTCSessionDescriptionManager *pSessionDescriptionManager);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredSecurityLevel )( 
            IRTCClient2 * This,
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [in] */ RTC_SECURITY_LEVEL enSecurityLevel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredSecurityLevel )( 
            IRTCClient2 * This,
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowedPorts )( 
            IRTCClient2 * This,
            /* [in] */ long lTransport,
            /* [in] */ RTC_LISTEN_MODE enListenMode);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowedPorts )( 
            IRTCClient2 * This,
            /* [in] */ long lTransport,
            /* [retval][out] */ RTC_LISTEN_MODE *penListenMode);
        
        END_INTERFACE
    } IRTCClient2Vtbl;

    interface IRTCClient2
    {
        CONST_VTBL struct IRTCClient2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClient2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCClient2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCClient2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCClient2_Initialize(This)	\
    (This)->lpVtbl -> Initialize(This)

#define IRTCClient2_Shutdown(This)	\
    (This)->lpVtbl -> Shutdown(This)

#define IRTCClient2_PrepareForShutdown(This)	\
    (This)->lpVtbl -> PrepareForShutdown(This)

#define IRTCClient2_put_EventFilter(This,lFilter)	\
    (This)->lpVtbl -> put_EventFilter(This,lFilter)

#define IRTCClient2_get_EventFilter(This,plFilter)	\
    (This)->lpVtbl -> get_EventFilter(This,plFilter)

#define IRTCClient2_SetPreferredMediaTypes(This,lMediaTypes,fPersistent)	\
    (This)->lpVtbl -> SetPreferredMediaTypes(This,lMediaTypes,fPersistent)

#define IRTCClient2_get_PreferredMediaTypes(This,plMediaTypes)	\
    (This)->lpVtbl -> get_PreferredMediaTypes(This,plMediaTypes)

#define IRTCClient2_get_MediaCapabilities(This,plMediaTypes)	\
    (This)->lpVtbl -> get_MediaCapabilities(This,plMediaTypes)

#define IRTCClient2_CreateSession(This,enType,bstrLocalPhoneURI,pProfile,lFlags,ppSession)	\
    (This)->lpVtbl -> CreateSession(This,enType,bstrLocalPhoneURI,pProfile,lFlags,ppSession)

#define IRTCClient2_put_ListenForIncomingSessions(This,enListen)	\
    (This)->lpVtbl -> put_ListenForIncomingSessions(This,enListen)

#define IRTCClient2_get_ListenForIncomingSessions(This,penListen)	\
    (This)->lpVtbl -> get_ListenForIncomingSessions(This,penListen)

#define IRTCClient2_get_NetworkAddresses(This,fTCP,fExternal,pvAddresses)	\
    (This)->lpVtbl -> get_NetworkAddresses(This,fTCP,fExternal,pvAddresses)

#define IRTCClient2_put_Volume(This,enDevice,lVolume)	\
    (This)->lpVtbl -> put_Volume(This,enDevice,lVolume)

#define IRTCClient2_get_Volume(This,enDevice,plVolume)	\
    (This)->lpVtbl -> get_Volume(This,enDevice,plVolume)

#define IRTCClient2_put_AudioMuted(This,enDevice,fMuted)	\
    (This)->lpVtbl -> put_AudioMuted(This,enDevice,fMuted)

#define IRTCClient2_get_AudioMuted(This,enDevice,pfMuted)	\
    (This)->lpVtbl -> get_AudioMuted(This,enDevice,pfMuted)

#define IRTCClient2_get_IVideoWindow(This,enDevice,ppIVideoWindow)	\
    (This)->lpVtbl -> get_IVideoWindow(This,enDevice,ppIVideoWindow)

#define IRTCClient2_put_PreferredAudioDevice(This,enDevice,bstrDeviceName)	\
    (This)->lpVtbl -> put_PreferredAudioDevice(This,enDevice,bstrDeviceName)

#define IRTCClient2_get_PreferredAudioDevice(This,enDevice,pbstrDeviceName)	\
    (This)->lpVtbl -> get_PreferredAudioDevice(This,enDevice,pbstrDeviceName)

#define IRTCClient2_put_PreferredVolume(This,enDevice,lVolume)	\
    (This)->lpVtbl -> put_PreferredVolume(This,enDevice,lVolume)

#define IRTCClient2_get_PreferredVolume(This,enDevice,plVolume)	\
    (This)->lpVtbl -> get_PreferredVolume(This,enDevice,plVolume)

#define IRTCClient2_put_PreferredAEC(This,bEnable)	\
    (This)->lpVtbl -> put_PreferredAEC(This,bEnable)

#define IRTCClient2_get_PreferredAEC(This,pbEnabled)	\
    (This)->lpVtbl -> get_PreferredAEC(This,pbEnabled)

#define IRTCClient2_put_PreferredVideoDevice(This,bstrDeviceName)	\
    (This)->lpVtbl -> put_PreferredVideoDevice(This,bstrDeviceName)

#define IRTCClient2_get_PreferredVideoDevice(This,pbstrDeviceName)	\
    (This)->lpVtbl -> get_PreferredVideoDevice(This,pbstrDeviceName)

#define IRTCClient2_get_ActiveMedia(This,plMediaType)	\
    (This)->lpVtbl -> get_ActiveMedia(This,plMediaType)

#define IRTCClient2_put_MaxBitrate(This,lMaxBitrate)	\
    (This)->lpVtbl -> put_MaxBitrate(This,lMaxBitrate)

#define IRTCClient2_get_MaxBitrate(This,plMaxBitrate)	\
    (This)->lpVtbl -> get_MaxBitrate(This,plMaxBitrate)

#define IRTCClient2_put_TemporalSpatialTradeOff(This,lValue)	\
    (This)->lpVtbl -> put_TemporalSpatialTradeOff(This,lValue)

#define IRTCClient2_get_TemporalSpatialTradeOff(This,plValue)	\
    (This)->lpVtbl -> get_TemporalSpatialTradeOff(This,plValue)

#define IRTCClient2_get_NetworkQuality(This,plNetworkQuality)	\
    (This)->lpVtbl -> get_NetworkQuality(This,plNetworkQuality)

#define IRTCClient2_StartT120Applet(This,enApplet)	\
    (This)->lpVtbl -> StartT120Applet(This,enApplet)

#define IRTCClient2_StopT120Applets(This)	\
    (This)->lpVtbl -> StopT120Applets(This)

#define IRTCClient2_get_IsT120AppletRunning(This,enApplet,pfRunning)	\
    (This)->lpVtbl -> get_IsT120AppletRunning(This,enApplet,pfRunning)

#define IRTCClient2_get_LocalUserURI(This,pbstrUserURI)	\
    (This)->lpVtbl -> get_LocalUserURI(This,pbstrUserURI)

#define IRTCClient2_put_LocalUserURI(This,bstrUserURI)	\
    (This)->lpVtbl -> put_LocalUserURI(This,bstrUserURI)

#define IRTCClient2_get_LocalUserName(This,pbstrUserName)	\
    (This)->lpVtbl -> get_LocalUserName(This,pbstrUserName)

#define IRTCClient2_put_LocalUserName(This,bstrUserName)	\
    (This)->lpVtbl -> put_LocalUserName(This,bstrUserName)

#define IRTCClient2_PlayRing(This,enType,bPlay)	\
    (This)->lpVtbl -> PlayRing(This,enType,bPlay)

#define IRTCClient2_SendDTMF(This,enDTMF)	\
    (This)->lpVtbl -> SendDTMF(This,enDTMF)

#define IRTCClient2_InvokeTuningWizard(This,hwndParent)	\
    (This)->lpVtbl -> InvokeTuningWizard(This,hwndParent)

#define IRTCClient2_get_IsTuned(This,pfTuned)	\
    (This)->lpVtbl -> get_IsTuned(This,pfTuned)


#define IRTCClient2_put_AnswerMode(This,enType,enMode)	\
    (This)->lpVtbl -> put_AnswerMode(This,enType,enMode)

#define IRTCClient2_get_AnswerMode(This,enType,penMode)	\
    (This)->lpVtbl -> get_AnswerMode(This,enType,penMode)

#define IRTCClient2_InvokeTuningWizardEx(This,hwndParent,fAllowAudio,fAllowVideo)	\
    (This)->lpVtbl -> InvokeTuningWizardEx(This,hwndParent,fAllowAudio,fAllowVideo)

#define IRTCClient2_get_Version(This,plVersion)	\
    (This)->lpVtbl -> get_Version(This,plVersion)

#define IRTCClient2_put_ClientName(This,bstrClientName)	\
    (This)->lpVtbl -> put_ClientName(This,bstrClientName)

#define IRTCClient2_put_ClientCurVer(This,bstrClientCurVer)	\
    (This)->lpVtbl -> put_ClientCurVer(This,bstrClientCurVer)

#define IRTCClient2_InitializeEx(This,lFlags)	\
    (This)->lpVtbl -> InitializeEx(This,lFlags)

#define IRTCClient2_CreateSessionWithDescription(This,bstrContentType,bstrSessionDescription,pProfile,lFlags,ppSession2)	\
    (This)->lpVtbl -> CreateSessionWithDescription(This,bstrContentType,bstrSessionDescription,pProfile,lFlags,ppSession2)

#define IRTCClient2_SetSessionDescriptionManager(This,pSessionDescriptionManager)	\
    (This)->lpVtbl -> SetSessionDescriptionManager(This,pSessionDescriptionManager)

#define IRTCClient2_put_PreferredSecurityLevel(This,enSecurityType,enSecurityLevel)	\
    (This)->lpVtbl -> put_PreferredSecurityLevel(This,enSecurityType,enSecurityLevel)

#define IRTCClient2_get_PreferredSecurityLevel(This,enSecurityType,penSecurityLevel)	\
    (This)->lpVtbl -> get_PreferredSecurityLevel(This,enSecurityType,penSecurityLevel)

#define IRTCClient2_put_AllowedPorts(This,lTransport,enListenMode)	\
    (This)->lpVtbl -> put_AllowedPorts(This,lTransport,enListenMode)

#define IRTCClient2_get_AllowedPorts(This,lTransport,penListenMode)	\
    (This)->lpVtbl -> get_AllowedPorts(This,lTransport,penListenMode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient2_put_AnswerMode_Proxy( 
    IRTCClient2 * This,
    /* [in] */ RTC_SESSION_TYPE enType,
    /* [in] */ RTC_ANSWER_MODE enMode);


void __RPC_STUB IRTCClient2_put_AnswerMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient2_get_AnswerMode_Proxy( 
    IRTCClient2 * This,
    /* [in] */ RTC_SESSION_TYPE enType,
    /* [retval][out] */ RTC_ANSWER_MODE *penMode);


void __RPC_STUB IRTCClient2_get_AnswerMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient2_InvokeTuningWizardEx_Proxy( 
    IRTCClient2 * This,
    /* [in] */ OAHWND hwndParent,
    /* [in] */ VARIANT_BOOL fAllowAudio,
    /* [in] */ VARIANT_BOOL fAllowVideo);


void __RPC_STUB IRTCClient2_InvokeTuningWizardEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient2_get_Version_Proxy( 
    IRTCClient2 * This,
    /* [retval][out] */ long *plVersion);


void __RPC_STUB IRTCClient2_get_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient2_put_ClientName_Proxy( 
    IRTCClient2 * This,
    /* [in] */ BSTR bstrClientName);


void __RPC_STUB IRTCClient2_put_ClientName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient2_put_ClientCurVer_Proxy( 
    IRTCClient2 * This,
    /* [in] */ BSTR bstrClientCurVer);


void __RPC_STUB IRTCClient2_put_ClientCurVer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient2_InitializeEx_Proxy( 
    IRTCClient2 * This,
    /* [in] */ long lFlags);


void __RPC_STUB IRTCClient2_InitializeEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient2_CreateSessionWithDescription_Proxy( 
    IRTCClient2 * This,
    /* [in] */ BSTR bstrContentType,
    /* [in] */ BSTR bstrSessionDescription,
    /* [in] */ IRTCProfile *pProfile,
    /* [in] */ long lFlags,
    /* [retval][out] */ IRTCSession2 **ppSession2);


void __RPC_STUB IRTCClient2_CreateSessionWithDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClient2_SetSessionDescriptionManager_Proxy( 
    IRTCClient2 * This,
    /* [in] */ IRTCSessionDescriptionManager *pSessionDescriptionManager);


void __RPC_STUB IRTCClient2_SetSessionDescriptionManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient2_put_PreferredSecurityLevel_Proxy( 
    IRTCClient2 * This,
    /* [in] */ RTC_SECURITY_TYPE enSecurityType,
    /* [in] */ RTC_SECURITY_LEVEL enSecurityLevel);


void __RPC_STUB IRTCClient2_put_PreferredSecurityLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient2_get_PreferredSecurityLevel_Proxy( 
    IRTCClient2 * This,
    /* [in] */ RTC_SECURITY_TYPE enSecurityType,
    /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel);


void __RPC_STUB IRTCClient2_get_PreferredSecurityLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClient2_put_AllowedPorts_Proxy( 
    IRTCClient2 * This,
    /* [in] */ long lTransport,
    /* [in] */ RTC_LISTEN_MODE enListenMode);


void __RPC_STUB IRTCClient2_put_AllowedPorts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClient2_get_AllowedPorts_Proxy( 
    IRTCClient2 * This,
    /* [in] */ long lTransport,
    /* [retval][out] */ RTC_LISTEN_MODE *penListenMode);


void __RPC_STUB IRTCClient2_get_AllowedPorts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCClient2_INTERFACE_DEFINED__ */


#ifndef __IRTCClientPresence_INTERFACE_DEFINED__
#define __IRTCClientPresence_INTERFACE_DEFINED__

/* interface IRTCClientPresence */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientPresence;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11c3cbcc-0744-42d1-968a-51aa1bb274c6")
    IRTCClientPresence : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnablePresence( 
            /* [in] */ VARIANT_BOOL fUseStorage,
            /* [in] */ VARIANT varStorage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Export( 
            /* [in] */ VARIANT varStorage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Import( 
            /* [in] */ VARIANT varStorage,
            /* [in] */ VARIANT_BOOL fReplaceAll) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateBuddies( 
            /* [retval][out] */ IRTCEnumBuddies **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Buddies( 
            /* [retval][out] */ IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Buddy( 
            /* [in] */ BSTR bstrPresentityURI,
            /* [retval][out] */ IRTCBuddy **ppBuddy) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddBuddy( 
            /* [in] */ BSTR bstrPresentityURI,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrData,
            /* [in] */ VARIANT_BOOL fPersistent,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCBuddy **ppBuddy) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveBuddy( 
            /* [in] */ IRTCBuddy *pBuddy) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateWatchers( 
            /* [retval][out] */ IRTCEnumWatchers **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Watchers( 
            /* [retval][out] */ IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Watcher( 
            /* [in] */ BSTR bstrPresentityURI,
            /* [retval][out] */ IRTCWatcher **ppWatcher) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddWatcher( 
            /* [in] */ BSTR bstrPresentityURI,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrData,
            /* [in] */ VARIANT_BOOL fBlocked,
            /* [in] */ VARIANT_BOOL fPersistent,
            /* [retval][out] */ IRTCWatcher **ppWatcher) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveWatcher( 
            /* [in] */ IRTCWatcher *pWatcher) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetLocalPresenceInfo( 
            /* [in] */ RTC_PRESENCE_STATUS enStatus,
            /* [in] */ BSTR bstrNotes) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_OfferWatcherMode( 
            /* [retval][out] */ RTC_OFFER_WATCHER_MODE *penMode) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_OfferWatcherMode( 
            /* [in] */ RTC_OFFER_WATCHER_MODE enMode) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PrivacyMode( 
            /* [retval][out] */ RTC_PRIVACY_MODE *penMode) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PrivacyMode( 
            /* [in] */ RTC_PRIVACY_MODE enMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCClientPresenceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCClientPresence * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCClientPresence * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCClientPresence * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnablePresence )( 
            IRTCClientPresence * This,
            /* [in] */ VARIANT_BOOL fUseStorage,
            /* [in] */ VARIANT varStorage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Export )( 
            IRTCClientPresence * This,
            /* [in] */ VARIANT varStorage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            IRTCClientPresence * This,
            /* [in] */ VARIANT varStorage,
            /* [in] */ VARIANT_BOOL fReplaceAll);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateBuddies )( 
            IRTCClientPresence * This,
            /* [retval][out] */ IRTCEnumBuddies **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddies )( 
            IRTCClientPresence * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddy )( 
            IRTCClientPresence * This,
            /* [in] */ BSTR bstrPresentityURI,
            /* [retval][out] */ IRTCBuddy **ppBuddy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddBuddy )( 
            IRTCClientPresence * This,
            /* [in] */ BSTR bstrPresentityURI,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrData,
            /* [in] */ VARIANT_BOOL fPersistent,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCBuddy **ppBuddy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveBuddy )( 
            IRTCClientPresence * This,
            /* [in] */ IRTCBuddy *pBuddy);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateWatchers )( 
            IRTCClientPresence * This,
            /* [retval][out] */ IRTCEnumWatchers **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watchers )( 
            IRTCClientPresence * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watcher )( 
            IRTCClientPresence * This,
            /* [in] */ BSTR bstrPresentityURI,
            /* [retval][out] */ IRTCWatcher **ppWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddWatcher )( 
            IRTCClientPresence * This,
            /* [in] */ BSTR bstrPresentityURI,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrData,
            /* [in] */ VARIANT_BOOL fBlocked,
            /* [in] */ VARIANT_BOOL fPersistent,
            /* [retval][out] */ IRTCWatcher **ppWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveWatcher )( 
            IRTCClientPresence * This,
            /* [in] */ IRTCWatcher *pWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetLocalPresenceInfo )( 
            IRTCClientPresence * This,
            /* [in] */ RTC_PRESENCE_STATUS enStatus,
            /* [in] */ BSTR bstrNotes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OfferWatcherMode )( 
            IRTCClientPresence * This,
            /* [retval][out] */ RTC_OFFER_WATCHER_MODE *penMode);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OfferWatcherMode )( 
            IRTCClientPresence * This,
            /* [in] */ RTC_OFFER_WATCHER_MODE enMode);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PrivacyMode )( 
            IRTCClientPresence * This,
            /* [retval][out] */ RTC_PRIVACY_MODE *penMode);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PrivacyMode )( 
            IRTCClientPresence * This,
            /* [in] */ RTC_PRIVACY_MODE enMode);
        
        END_INTERFACE
    } IRTCClientPresenceVtbl;

    interface IRTCClientPresence
    {
        CONST_VTBL struct IRTCClientPresenceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientPresence_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCClientPresence_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCClientPresence_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCClientPresence_EnablePresence(This,fUseStorage,varStorage)	\
    (This)->lpVtbl -> EnablePresence(This,fUseStorage,varStorage)

#define IRTCClientPresence_Export(This,varStorage)	\
    (This)->lpVtbl -> Export(This,varStorage)

#define IRTCClientPresence_Import(This,varStorage,fReplaceAll)	\
    (This)->lpVtbl -> Import(This,varStorage,fReplaceAll)

#define IRTCClientPresence_EnumerateBuddies(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateBuddies(This,ppEnum)

#define IRTCClientPresence_get_Buddies(This,ppCollection)	\
    (This)->lpVtbl -> get_Buddies(This,ppCollection)

#define IRTCClientPresence_get_Buddy(This,bstrPresentityURI,ppBuddy)	\
    (This)->lpVtbl -> get_Buddy(This,bstrPresentityURI,ppBuddy)

#define IRTCClientPresence_AddBuddy(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,pProfile,lFlags,ppBuddy)	\
    (This)->lpVtbl -> AddBuddy(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,pProfile,lFlags,ppBuddy)

#define IRTCClientPresence_RemoveBuddy(This,pBuddy)	\
    (This)->lpVtbl -> RemoveBuddy(This,pBuddy)

#define IRTCClientPresence_EnumerateWatchers(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateWatchers(This,ppEnum)

#define IRTCClientPresence_get_Watchers(This,ppCollection)	\
    (This)->lpVtbl -> get_Watchers(This,ppCollection)

#define IRTCClientPresence_get_Watcher(This,bstrPresentityURI,ppWatcher)	\
    (This)->lpVtbl -> get_Watcher(This,bstrPresentityURI,ppWatcher)

#define IRTCClientPresence_AddWatcher(This,bstrPresentityURI,bstrUserName,bstrData,fBlocked,fPersistent,ppWatcher)	\
    (This)->lpVtbl -> AddWatcher(This,bstrPresentityURI,bstrUserName,bstrData,fBlocked,fPersistent,ppWatcher)

#define IRTCClientPresence_RemoveWatcher(This,pWatcher)	\
    (This)->lpVtbl -> RemoveWatcher(This,pWatcher)

#define IRTCClientPresence_SetLocalPresenceInfo(This,enStatus,bstrNotes)	\
    (This)->lpVtbl -> SetLocalPresenceInfo(This,enStatus,bstrNotes)

#define IRTCClientPresence_get_OfferWatcherMode(This,penMode)	\
    (This)->lpVtbl -> get_OfferWatcherMode(This,penMode)

#define IRTCClientPresence_put_OfferWatcherMode(This,enMode)	\
    (This)->lpVtbl -> put_OfferWatcherMode(This,enMode)

#define IRTCClientPresence_get_PrivacyMode(This,penMode)	\
    (This)->lpVtbl -> get_PrivacyMode(This,penMode)

#define IRTCClientPresence_put_PrivacyMode(This,enMode)	\
    (This)->lpVtbl -> put_PrivacyMode(This,enMode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_EnablePresence_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ VARIANT_BOOL fUseStorage,
    /* [in] */ VARIANT varStorage);


void __RPC_STUB IRTCClientPresence_EnablePresence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_Export_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ VARIANT varStorage);


void __RPC_STUB IRTCClientPresence_Export_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_Import_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ VARIANT varStorage,
    /* [in] */ VARIANT_BOOL fReplaceAll);


void __RPC_STUB IRTCClientPresence_Import_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_EnumerateBuddies_Proxy( 
    IRTCClientPresence * This,
    /* [retval][out] */ IRTCEnumBuddies **ppEnum);


void __RPC_STUB IRTCClientPresence_EnumerateBuddies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_get_Buddies_Proxy( 
    IRTCClientPresence * This,
    /* [retval][out] */ IRTCCollection **ppCollection);


void __RPC_STUB IRTCClientPresence_get_Buddies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_get_Buddy_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ BSTR bstrPresentityURI,
    /* [retval][out] */ IRTCBuddy **ppBuddy);


void __RPC_STUB IRTCClientPresence_get_Buddy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_AddBuddy_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ BSTR bstrPresentityURI,
    /* [in] */ BSTR bstrUserName,
    /* [in] */ BSTR bstrData,
    /* [in] */ VARIANT_BOOL fPersistent,
    /* [in] */ IRTCProfile *pProfile,
    /* [in] */ long lFlags,
    /* [retval][out] */ IRTCBuddy **ppBuddy);


void __RPC_STUB IRTCClientPresence_AddBuddy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_RemoveBuddy_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ IRTCBuddy *pBuddy);


void __RPC_STUB IRTCClientPresence_RemoveBuddy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_EnumerateWatchers_Proxy( 
    IRTCClientPresence * This,
    /* [retval][out] */ IRTCEnumWatchers **ppEnum);


void __RPC_STUB IRTCClientPresence_EnumerateWatchers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_get_Watchers_Proxy( 
    IRTCClientPresence * This,
    /* [retval][out] */ IRTCCollection **ppCollection);


void __RPC_STUB IRTCClientPresence_get_Watchers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_get_Watcher_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ BSTR bstrPresentityURI,
    /* [retval][out] */ IRTCWatcher **ppWatcher);


void __RPC_STUB IRTCClientPresence_get_Watcher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_AddWatcher_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ BSTR bstrPresentityURI,
    /* [in] */ BSTR bstrUserName,
    /* [in] */ BSTR bstrData,
    /* [in] */ VARIANT_BOOL fBlocked,
    /* [in] */ VARIANT_BOOL fPersistent,
    /* [retval][out] */ IRTCWatcher **ppWatcher);


void __RPC_STUB IRTCClientPresence_AddWatcher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_RemoveWatcher_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ IRTCWatcher *pWatcher);


void __RPC_STUB IRTCClientPresence_RemoveWatcher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_SetLocalPresenceInfo_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ RTC_PRESENCE_STATUS enStatus,
    /* [in] */ BSTR bstrNotes);


void __RPC_STUB IRTCClientPresence_SetLocalPresenceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_get_OfferWatcherMode_Proxy( 
    IRTCClientPresence * This,
    /* [retval][out] */ RTC_OFFER_WATCHER_MODE *penMode);


void __RPC_STUB IRTCClientPresence_get_OfferWatcherMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_put_OfferWatcherMode_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ RTC_OFFER_WATCHER_MODE enMode);


void __RPC_STUB IRTCClientPresence_put_OfferWatcherMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_get_PrivacyMode_Proxy( 
    IRTCClientPresence * This,
    /* [retval][out] */ RTC_PRIVACY_MODE *penMode);


void __RPC_STUB IRTCClientPresence_get_PrivacyMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence_put_PrivacyMode_Proxy( 
    IRTCClientPresence * This,
    /* [in] */ RTC_PRIVACY_MODE enMode);


void __RPC_STUB IRTCClientPresence_put_PrivacyMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCClientPresence_INTERFACE_DEFINED__ */


#ifndef __IRTCClientPresence2_INTERFACE_DEFINED__
#define __IRTCClientPresence2_INTERFACE_DEFINED__

/* interface IRTCClientPresence2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientPresence2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD1809E8-62F7-4783-909A-29C9D2CB1D34")
    IRTCClientPresence2 : public IRTCClientPresence
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnablePresenceEx( 
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ VARIANT varStorage,
            /* [in] */ long lFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DisablePresence( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddGroup( 
            /* [in] */ BSTR bstrGroupName,
            /* [in] */ BSTR bstrData,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCBuddyGroup **ppGroup) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveGroup( 
            /* [in] */ IRTCBuddyGroup *pGroup) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateGroups( 
            /* [retval][out] */ IRTCEnumGroups **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Groups( 
            /* [retval][out] */ IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Group( 
            /* [in] */ BSTR bstrGroupName,
            /* [retval][out] */ IRTCBuddyGroup **ppGroup) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddWatcherEx( 
            /* [in] */ BSTR bstrPresentityURI,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrData,
            /* [in] */ RTC_WATCHER_STATE enState,
            /* [in] */ VARIANT_BOOL fPersistent,
            /* [in] */ RTC_ACE_SCOPE enScope,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCWatcher2 **ppWatcher) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_WatcherEx( 
            /* [in] */ RTC_WATCHER_MATCH_MODE enMode,
            /* [in] */ BSTR bstrPresentityURI,
            /* [retval][out] */ IRTCWatcher2 **ppWatcher) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PresenceProperty( 
            /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
            /* [in] */ BSTR bstrProperty) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PresenceProperty( 
            /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
            /* [retval][out] */ BSTR *pbstrProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPresenceData( 
            /* [in] */ BSTR bstrNamespace,
            /* [in] */ BSTR bstrData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPresenceData( 
            /* [out] */ BSTR *pbstrNamespace,
            /* [out] */ BSTR *pbstrData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLocalPresenceInfo( 
            /* [out] */ RTC_PRESENCE_STATUS *penStatus,
            /* [out] */ BSTR *pbstrNotes) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddBuddyEx( 
            /* [in] */ BSTR bstrPresentityURI,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrData,
            /* [in] */ VARIANT_BOOL fPersistent,
            /* [in] */ RTC_BUDDY_SUBSCRIPTION_TYPE enSubscriptionType,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCBuddy2 **ppBuddy) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCClientPresence2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCClientPresence2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCClientPresence2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCClientPresence2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnablePresence )( 
            IRTCClientPresence2 * This,
            /* [in] */ VARIANT_BOOL fUseStorage,
            /* [in] */ VARIANT varStorage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Export )( 
            IRTCClientPresence2 * This,
            /* [in] */ VARIANT varStorage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            IRTCClientPresence2 * This,
            /* [in] */ VARIANT varStorage,
            /* [in] */ VARIANT_BOOL fReplaceAll);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateBuddies )( 
            IRTCClientPresence2 * This,
            /* [retval][out] */ IRTCEnumBuddies **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddies )( 
            IRTCClientPresence2 * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddy )( 
            IRTCClientPresence2 * This,
            /* [in] */ BSTR bstrPresentityURI,
            /* [retval][out] */ IRTCBuddy **ppBuddy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddBuddy )( 
            IRTCClientPresence2 * This,
            /* [in] */ BSTR bstrPresentityURI,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrData,
            /* [in] */ VARIANT_BOOL fPersistent,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCBuddy **ppBuddy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveBuddy )( 
            IRTCClientPresence2 * This,
            /* [in] */ IRTCBuddy *pBuddy);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateWatchers )( 
            IRTCClientPresence2 * This,
            /* [retval][out] */ IRTCEnumWatchers **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watchers )( 
            IRTCClientPresence2 * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watcher )( 
            IRTCClientPresence2 * This,
            /* [in] */ BSTR bstrPresentityURI,
            /* [retval][out] */ IRTCWatcher **ppWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddWatcher )( 
            IRTCClientPresence2 * This,
            /* [in] */ BSTR bstrPresentityURI,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrData,
            /* [in] */ VARIANT_BOOL fBlocked,
            /* [in] */ VARIANT_BOOL fPersistent,
            /* [retval][out] */ IRTCWatcher **ppWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveWatcher )( 
            IRTCClientPresence2 * This,
            /* [in] */ IRTCWatcher *pWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetLocalPresenceInfo )( 
            IRTCClientPresence2 * This,
            /* [in] */ RTC_PRESENCE_STATUS enStatus,
            /* [in] */ BSTR bstrNotes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OfferWatcherMode )( 
            IRTCClientPresence2 * This,
            /* [retval][out] */ RTC_OFFER_WATCHER_MODE *penMode);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OfferWatcherMode )( 
            IRTCClientPresence2 * This,
            /* [in] */ RTC_OFFER_WATCHER_MODE enMode);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PrivacyMode )( 
            IRTCClientPresence2 * This,
            /* [retval][out] */ RTC_PRIVACY_MODE *penMode);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PrivacyMode )( 
            IRTCClientPresence2 * This,
            /* [in] */ RTC_PRIVACY_MODE enMode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnablePresenceEx )( 
            IRTCClientPresence2 * This,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ VARIANT varStorage,
            /* [in] */ long lFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DisablePresence )( 
            IRTCClientPresence2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddGroup )( 
            IRTCClientPresence2 * This,
            /* [in] */ BSTR bstrGroupName,
            /* [in] */ BSTR bstrData,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCBuddyGroup **ppGroup);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveGroup )( 
            IRTCClientPresence2 * This,
            /* [in] */ IRTCBuddyGroup *pGroup);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateGroups )( 
            IRTCClientPresence2 * This,
            /* [retval][out] */ IRTCEnumGroups **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Groups )( 
            IRTCClientPresence2 * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Group )( 
            IRTCClientPresence2 * This,
            /* [in] */ BSTR bstrGroupName,
            /* [retval][out] */ IRTCBuddyGroup **ppGroup);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddWatcherEx )( 
            IRTCClientPresence2 * This,
            /* [in] */ BSTR bstrPresentityURI,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrData,
            /* [in] */ RTC_WATCHER_STATE enState,
            /* [in] */ VARIANT_BOOL fPersistent,
            /* [in] */ RTC_ACE_SCOPE enScope,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCWatcher2 **ppWatcher);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WatcherEx )( 
            IRTCClientPresence2 * This,
            /* [in] */ RTC_WATCHER_MATCH_MODE enMode,
            /* [in] */ BSTR bstrPresentityURI,
            /* [retval][out] */ IRTCWatcher2 **ppWatcher);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresenceProperty )( 
            IRTCClientPresence2 * This,
            /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
            /* [in] */ BSTR bstrProperty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresenceProperty )( 
            IRTCClientPresence2 * This,
            /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
            /* [retval][out] */ BSTR *pbstrProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPresenceData )( 
            IRTCClientPresence2 * This,
            /* [in] */ BSTR bstrNamespace,
            /* [in] */ BSTR bstrData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPresenceData )( 
            IRTCClientPresence2 * This,
            /* [out] */ BSTR *pbstrNamespace,
            /* [out] */ BSTR *pbstrData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLocalPresenceInfo )( 
            IRTCClientPresence2 * This,
            /* [out] */ RTC_PRESENCE_STATUS *penStatus,
            /* [out] */ BSTR *pbstrNotes);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddBuddyEx )( 
            IRTCClientPresence2 * This,
            /* [in] */ BSTR bstrPresentityURI,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrData,
            /* [in] */ VARIANT_BOOL fPersistent,
            /* [in] */ RTC_BUDDY_SUBSCRIPTION_TYPE enSubscriptionType,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags,
            /* [retval][out] */ IRTCBuddy2 **ppBuddy);
        
        END_INTERFACE
    } IRTCClientPresence2Vtbl;

    interface IRTCClientPresence2
    {
        CONST_VTBL struct IRTCClientPresence2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientPresence2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCClientPresence2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCClientPresence2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCClientPresence2_EnablePresence(This,fUseStorage,varStorage)	\
    (This)->lpVtbl -> EnablePresence(This,fUseStorage,varStorage)

#define IRTCClientPresence2_Export(This,varStorage)	\
    (This)->lpVtbl -> Export(This,varStorage)

#define IRTCClientPresence2_Import(This,varStorage,fReplaceAll)	\
    (This)->lpVtbl -> Import(This,varStorage,fReplaceAll)

#define IRTCClientPresence2_EnumerateBuddies(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateBuddies(This,ppEnum)

#define IRTCClientPresence2_get_Buddies(This,ppCollection)	\
    (This)->lpVtbl -> get_Buddies(This,ppCollection)

#define IRTCClientPresence2_get_Buddy(This,bstrPresentityURI,ppBuddy)	\
    (This)->lpVtbl -> get_Buddy(This,bstrPresentityURI,ppBuddy)

#define IRTCClientPresence2_AddBuddy(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,pProfile,lFlags,ppBuddy)	\
    (This)->lpVtbl -> AddBuddy(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,pProfile,lFlags,ppBuddy)

#define IRTCClientPresence2_RemoveBuddy(This,pBuddy)	\
    (This)->lpVtbl -> RemoveBuddy(This,pBuddy)

#define IRTCClientPresence2_EnumerateWatchers(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateWatchers(This,ppEnum)

#define IRTCClientPresence2_get_Watchers(This,ppCollection)	\
    (This)->lpVtbl -> get_Watchers(This,ppCollection)

#define IRTCClientPresence2_get_Watcher(This,bstrPresentityURI,ppWatcher)	\
    (This)->lpVtbl -> get_Watcher(This,bstrPresentityURI,ppWatcher)

#define IRTCClientPresence2_AddWatcher(This,bstrPresentityURI,bstrUserName,bstrData,fBlocked,fPersistent,ppWatcher)	\
    (This)->lpVtbl -> AddWatcher(This,bstrPresentityURI,bstrUserName,bstrData,fBlocked,fPersistent,ppWatcher)

#define IRTCClientPresence2_RemoveWatcher(This,pWatcher)	\
    (This)->lpVtbl -> RemoveWatcher(This,pWatcher)

#define IRTCClientPresence2_SetLocalPresenceInfo(This,enStatus,bstrNotes)	\
    (This)->lpVtbl -> SetLocalPresenceInfo(This,enStatus,bstrNotes)

#define IRTCClientPresence2_get_OfferWatcherMode(This,penMode)	\
    (This)->lpVtbl -> get_OfferWatcherMode(This,penMode)

#define IRTCClientPresence2_put_OfferWatcherMode(This,enMode)	\
    (This)->lpVtbl -> put_OfferWatcherMode(This,enMode)

#define IRTCClientPresence2_get_PrivacyMode(This,penMode)	\
    (This)->lpVtbl -> get_PrivacyMode(This,penMode)

#define IRTCClientPresence2_put_PrivacyMode(This,enMode)	\
    (This)->lpVtbl -> put_PrivacyMode(This,enMode)


#define IRTCClientPresence2_EnablePresenceEx(This,pProfile,varStorage,lFlags)	\
    (This)->lpVtbl -> EnablePresenceEx(This,pProfile,varStorage,lFlags)

#define IRTCClientPresence2_DisablePresence(This)	\
    (This)->lpVtbl -> DisablePresence(This)

#define IRTCClientPresence2_AddGroup(This,bstrGroupName,bstrData,pProfile,lFlags,ppGroup)	\
    (This)->lpVtbl -> AddGroup(This,bstrGroupName,bstrData,pProfile,lFlags,ppGroup)

#define IRTCClientPresence2_RemoveGroup(This,pGroup)	\
    (This)->lpVtbl -> RemoveGroup(This,pGroup)

#define IRTCClientPresence2_EnumerateGroups(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateGroups(This,ppEnum)

#define IRTCClientPresence2_get_Groups(This,ppCollection)	\
    (This)->lpVtbl -> get_Groups(This,ppCollection)

#define IRTCClientPresence2_get_Group(This,bstrGroupName,ppGroup)	\
    (This)->lpVtbl -> get_Group(This,bstrGroupName,ppGroup)

#define IRTCClientPresence2_AddWatcherEx(This,bstrPresentityURI,bstrUserName,bstrData,enState,fPersistent,enScope,pProfile,lFlags,ppWatcher)	\
    (This)->lpVtbl -> AddWatcherEx(This,bstrPresentityURI,bstrUserName,bstrData,enState,fPersistent,enScope,pProfile,lFlags,ppWatcher)

#define IRTCClientPresence2_get_WatcherEx(This,enMode,bstrPresentityURI,ppWatcher)	\
    (This)->lpVtbl -> get_WatcherEx(This,enMode,bstrPresentityURI,ppWatcher)

#define IRTCClientPresence2_put_PresenceProperty(This,enProperty,bstrProperty)	\
    (This)->lpVtbl -> put_PresenceProperty(This,enProperty,bstrProperty)

#define IRTCClientPresence2_get_PresenceProperty(This,enProperty,pbstrProperty)	\
    (This)->lpVtbl -> get_PresenceProperty(This,enProperty,pbstrProperty)

#define IRTCClientPresence2_SetPresenceData(This,bstrNamespace,bstrData)	\
    (This)->lpVtbl -> SetPresenceData(This,bstrNamespace,bstrData)

#define IRTCClientPresence2_GetPresenceData(This,pbstrNamespace,pbstrData)	\
    (This)->lpVtbl -> GetPresenceData(This,pbstrNamespace,pbstrData)

#define IRTCClientPresence2_GetLocalPresenceInfo(This,penStatus,pbstrNotes)	\
    (This)->lpVtbl -> GetLocalPresenceInfo(This,penStatus,pbstrNotes)

#define IRTCClientPresence2_AddBuddyEx(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,enSubscriptionType,pProfile,lFlags,ppBuddy)	\
    (This)->lpVtbl -> AddBuddyEx(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,enSubscriptionType,pProfile,lFlags,ppBuddy)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_EnablePresenceEx_Proxy( 
    IRTCClientPresence2 * This,
    /* [in] */ IRTCProfile *pProfile,
    /* [in] */ VARIANT varStorage,
    /* [in] */ long lFlags);


void __RPC_STUB IRTCClientPresence2_EnablePresenceEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_DisablePresence_Proxy( 
    IRTCClientPresence2 * This);


void __RPC_STUB IRTCClientPresence2_DisablePresence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_AddGroup_Proxy( 
    IRTCClientPresence2 * This,
    /* [in] */ BSTR bstrGroupName,
    /* [in] */ BSTR bstrData,
    /* [in] */ IRTCProfile *pProfile,
    /* [in] */ long lFlags,
    /* [retval][out] */ IRTCBuddyGroup **ppGroup);


void __RPC_STUB IRTCClientPresence2_AddGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_RemoveGroup_Proxy( 
    IRTCClientPresence2 * This,
    /* [in] */ IRTCBuddyGroup *pGroup);


void __RPC_STUB IRTCClientPresence2_RemoveGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_EnumerateGroups_Proxy( 
    IRTCClientPresence2 * This,
    /* [retval][out] */ IRTCEnumGroups **ppEnum);


void __RPC_STUB IRTCClientPresence2_EnumerateGroups_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_get_Groups_Proxy( 
    IRTCClientPresence2 * This,
    /* [retval][out] */ IRTCCollection **ppCollection);


void __RPC_STUB IRTCClientPresence2_get_Groups_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_get_Group_Proxy( 
    IRTCClientPresence2 * This,
    /* [in] */ BSTR bstrGroupName,
    /* [retval][out] */ IRTCBuddyGroup **ppGroup);


void __RPC_STUB IRTCClientPresence2_get_Group_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_AddWatcherEx_Proxy( 
    IRTCClientPresence2 * This,
    /* [in] */ BSTR bstrPresentityURI,
    /* [in] */ BSTR bstrUserName,
    /* [in] */ BSTR bstrData,
    /* [in] */ RTC_WATCHER_STATE enState,
    /* [in] */ VARIANT_BOOL fPersistent,
    /* [in] */ RTC_ACE_SCOPE enScope,
    /* [in] */ IRTCProfile *pProfile,
    /* [in] */ long lFlags,
    /* [retval][out] */ IRTCWatcher2 **ppWatcher);


void __RPC_STUB IRTCClientPresence2_AddWatcherEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_get_WatcherEx_Proxy( 
    IRTCClientPresence2 * This,
    /* [in] */ RTC_WATCHER_MATCH_MODE enMode,
    /* [in] */ BSTR bstrPresentityURI,
    /* [retval][out] */ IRTCWatcher2 **ppWatcher);


void __RPC_STUB IRTCClientPresence2_get_WatcherEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_put_PresenceProperty_Proxy( 
    IRTCClientPresence2 * This,
    /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
    /* [in] */ BSTR bstrProperty);


void __RPC_STUB IRTCClientPresence2_put_PresenceProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_get_PresenceProperty_Proxy( 
    IRTCClientPresence2 * This,
    /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
    /* [retval][out] */ BSTR *pbstrProperty);


void __RPC_STUB IRTCClientPresence2_get_PresenceProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_SetPresenceData_Proxy( 
    IRTCClientPresence2 * This,
    /* [in] */ BSTR bstrNamespace,
    /* [in] */ BSTR bstrData);


void __RPC_STUB IRTCClientPresence2_SetPresenceData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_GetPresenceData_Proxy( 
    IRTCClientPresence2 * This,
    /* [out] */ BSTR *pbstrNamespace,
    /* [out] */ BSTR *pbstrData);


void __RPC_STUB IRTCClientPresence2_GetPresenceData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_GetLocalPresenceInfo_Proxy( 
    IRTCClientPresence2 * This,
    /* [out] */ RTC_PRESENCE_STATUS *penStatus,
    /* [out] */ BSTR *pbstrNotes);


void __RPC_STUB IRTCClientPresence2_GetLocalPresenceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPresence2_AddBuddyEx_Proxy( 
    IRTCClientPresence2 * This,
    /* [in] */ BSTR bstrPresentityURI,
    /* [in] */ BSTR bstrUserName,
    /* [in] */ BSTR bstrData,
    /* [in] */ VARIANT_BOOL fPersistent,
    /* [in] */ RTC_BUDDY_SUBSCRIPTION_TYPE enSubscriptionType,
    /* [in] */ IRTCProfile *pProfile,
    /* [in] */ long lFlags,
    /* [retval][out] */ IRTCBuddy2 **ppBuddy);


void __RPC_STUB IRTCClientPresence2_AddBuddyEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCClientPresence2_INTERFACE_DEFINED__ */


#ifndef __IRTCClientProvisioning_INTERFACE_DEFINED__
#define __IRTCClientProvisioning_INTERFACE_DEFINED__

/* interface IRTCClientProvisioning */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientProvisioning;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B9F5CF06-65B9-4a80-A0E6-73CAE3EF3822")
    IRTCClientProvisioning : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateProfile( 
            /* [in] */ BSTR bstrProfileXML,
            /* [retval][out] */ IRTCProfile **ppProfile) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnableProfile( 
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lRegisterFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DisableProfile( 
            /* [in] */ IRTCProfile *pProfile) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateProfiles( 
            /* [retval][out] */ IRTCEnumProfiles **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Profiles( 
            /* [retval][out] */ IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProfile( 
            /* [in] */ BSTR bstrUserAccount,
            /* [in] */ BSTR bstrUserPassword,
            /* [in] */ BSTR bstrUserURI,
            /* [in] */ BSTR bstrServer,
            /* [in] */ long lTransport,
            /* [in] */ LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SessionCapabilities( 
            /* [retval][out] */ long *plSupportedSessions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCClientProvisioningVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCClientProvisioning * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCClientProvisioning * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCClientProvisioning * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateProfile )( 
            IRTCClientProvisioning * This,
            /* [in] */ BSTR bstrProfileXML,
            /* [retval][out] */ IRTCProfile **ppProfile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnableProfile )( 
            IRTCClientProvisioning * This,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lRegisterFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DisableProfile )( 
            IRTCClientProvisioning * This,
            /* [in] */ IRTCProfile *pProfile);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateProfiles )( 
            IRTCClientProvisioning * This,
            /* [retval][out] */ IRTCEnumProfiles **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profiles )( 
            IRTCClientProvisioning * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProfile )( 
            IRTCClientProvisioning * This,
            /* [in] */ BSTR bstrUserAccount,
            /* [in] */ BSTR bstrUserPassword,
            /* [in] */ BSTR bstrUserURI,
            /* [in] */ BSTR bstrServer,
            /* [in] */ long lTransport,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SessionCapabilities )( 
            IRTCClientProvisioning * This,
            /* [retval][out] */ long *plSupportedSessions);
        
        END_INTERFACE
    } IRTCClientProvisioningVtbl;

    interface IRTCClientProvisioning
    {
        CONST_VTBL struct IRTCClientProvisioningVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientProvisioning_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCClientProvisioning_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCClientProvisioning_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCClientProvisioning_CreateProfile(This,bstrProfileXML,ppProfile)	\
    (This)->lpVtbl -> CreateProfile(This,bstrProfileXML,ppProfile)

#define IRTCClientProvisioning_EnableProfile(This,pProfile,lRegisterFlags)	\
    (This)->lpVtbl -> EnableProfile(This,pProfile,lRegisterFlags)

#define IRTCClientProvisioning_DisableProfile(This,pProfile)	\
    (This)->lpVtbl -> DisableProfile(This,pProfile)

#define IRTCClientProvisioning_EnumerateProfiles(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateProfiles(This,ppEnum)

#define IRTCClientProvisioning_get_Profiles(This,ppCollection)	\
    (This)->lpVtbl -> get_Profiles(This,ppCollection)

#define IRTCClientProvisioning_GetProfile(This,bstrUserAccount,bstrUserPassword,bstrUserURI,bstrServer,lTransport,lCookie)	\
    (This)->lpVtbl -> GetProfile(This,bstrUserAccount,bstrUserPassword,bstrUserURI,bstrServer,lTransport,lCookie)

#define IRTCClientProvisioning_get_SessionCapabilities(This,plSupportedSessions)	\
    (This)->lpVtbl -> get_SessionCapabilities(This,plSupportedSessions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientProvisioning_CreateProfile_Proxy( 
    IRTCClientProvisioning * This,
    /* [in] */ BSTR bstrProfileXML,
    /* [retval][out] */ IRTCProfile **ppProfile);


void __RPC_STUB IRTCClientProvisioning_CreateProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientProvisioning_EnableProfile_Proxy( 
    IRTCClientProvisioning * This,
    /* [in] */ IRTCProfile *pProfile,
    /* [in] */ long lRegisterFlags);


void __RPC_STUB IRTCClientProvisioning_EnableProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientProvisioning_DisableProfile_Proxy( 
    IRTCClientProvisioning * This,
    /* [in] */ IRTCProfile *pProfile);


void __RPC_STUB IRTCClientProvisioning_DisableProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE IRTCClientProvisioning_EnumerateProfiles_Proxy( 
    IRTCClientProvisioning * This,
    /* [retval][out] */ IRTCEnumProfiles **ppEnum);


void __RPC_STUB IRTCClientProvisioning_EnumerateProfiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientProvisioning_get_Profiles_Proxy( 
    IRTCClientProvisioning * This,
    /* [retval][out] */ IRTCCollection **ppCollection);


void __RPC_STUB IRTCClientProvisioning_get_Profiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientProvisioning_GetProfile_Proxy( 
    IRTCClientProvisioning * This,
    /* [in] */ BSTR bstrUserAccount,
    /* [in] */ BSTR bstrUserPassword,
    /* [in] */ BSTR bstrUserURI,
    /* [in] */ BSTR bstrServer,
    /* [in] */ long lTransport,
    /* [in] */ LONG_PTR lCookie);


void __RPC_STUB IRTCClientProvisioning_GetProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientProvisioning_get_SessionCapabilities_Proxy( 
    IRTCClientProvisioning * This,
    /* [retval][out] */ long *plSupportedSessions);


void __RPC_STUB IRTCClientProvisioning_get_SessionCapabilities_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCClientProvisioning_INTERFACE_DEFINED__ */


#ifndef __IRTCClientProvisioning2_INTERFACE_DEFINED__
#define __IRTCClientProvisioning2_INTERFACE_DEFINED__

/* interface IRTCClientProvisioning2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientProvisioning2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A70909B5-F40E-4587-BB75-E6BC0845023E")
    IRTCClientProvisioning2 : public IRTCClientProvisioning
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnableProfileEx( 
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lRegisterFlags,
            /* [in] */ long lRoamingFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCClientProvisioning2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCClientProvisioning2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCClientProvisioning2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCClientProvisioning2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateProfile )( 
            IRTCClientProvisioning2 * This,
            /* [in] */ BSTR bstrProfileXML,
            /* [retval][out] */ IRTCProfile **ppProfile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnableProfile )( 
            IRTCClientProvisioning2 * This,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lRegisterFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DisableProfile )( 
            IRTCClientProvisioning2 * This,
            /* [in] */ IRTCProfile *pProfile);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateProfiles )( 
            IRTCClientProvisioning2 * This,
            /* [retval][out] */ IRTCEnumProfiles **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profiles )( 
            IRTCClientProvisioning2 * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProfile )( 
            IRTCClientProvisioning2 * This,
            /* [in] */ BSTR bstrUserAccount,
            /* [in] */ BSTR bstrUserPassword,
            /* [in] */ BSTR bstrUserURI,
            /* [in] */ BSTR bstrServer,
            /* [in] */ long lTransport,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SessionCapabilities )( 
            IRTCClientProvisioning2 * This,
            /* [retval][out] */ long *plSupportedSessions);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnableProfileEx )( 
            IRTCClientProvisioning2 * This,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lRegisterFlags,
            /* [in] */ long lRoamingFlags);
        
        END_INTERFACE
    } IRTCClientProvisioning2Vtbl;

    interface IRTCClientProvisioning2
    {
        CONST_VTBL struct IRTCClientProvisioning2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientProvisioning2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCClientProvisioning2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCClientProvisioning2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCClientProvisioning2_CreateProfile(This,bstrProfileXML,ppProfile)	\
    (This)->lpVtbl -> CreateProfile(This,bstrProfileXML,ppProfile)

#define IRTCClientProvisioning2_EnableProfile(This,pProfile,lRegisterFlags)	\
    (This)->lpVtbl -> EnableProfile(This,pProfile,lRegisterFlags)

#define IRTCClientProvisioning2_DisableProfile(This,pProfile)	\
    (This)->lpVtbl -> DisableProfile(This,pProfile)

#define IRTCClientProvisioning2_EnumerateProfiles(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateProfiles(This,ppEnum)

#define IRTCClientProvisioning2_get_Profiles(This,ppCollection)	\
    (This)->lpVtbl -> get_Profiles(This,ppCollection)

#define IRTCClientProvisioning2_GetProfile(This,bstrUserAccount,bstrUserPassword,bstrUserURI,bstrServer,lTransport,lCookie)	\
    (This)->lpVtbl -> GetProfile(This,bstrUserAccount,bstrUserPassword,bstrUserURI,bstrServer,lTransport,lCookie)

#define IRTCClientProvisioning2_get_SessionCapabilities(This,plSupportedSessions)	\
    (This)->lpVtbl -> get_SessionCapabilities(This,plSupportedSessions)


#define IRTCClientProvisioning2_EnableProfileEx(This,pProfile,lRegisterFlags,lRoamingFlags)	\
    (This)->lpVtbl -> EnableProfileEx(This,pProfile,lRegisterFlags,lRoamingFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientProvisioning2_EnableProfileEx_Proxy( 
    IRTCClientProvisioning2 * This,
    /* [in] */ IRTCProfile *pProfile,
    /* [in] */ long lRegisterFlags,
    /* [in] */ long lRoamingFlags);


void __RPC_STUB IRTCClientProvisioning2_EnableProfileEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCClientProvisioning2_INTERFACE_DEFINED__ */


#ifndef __IRTCProfile_INTERFACE_DEFINED__
#define __IRTCProfile_INTERFACE_DEFINED__

/* interface IRTCProfile */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCProfile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d07eca9e-4062-4dd4-9e7d-722a49ba7303")
    IRTCProfile : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [retval][out] */ BSTR *pbstrKey) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_XML( 
            /* [retval][out] */ BSTR *pbstrXML) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProviderName( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProviderURI( 
            /* [in] */ RTC_PROVIDER_URI enURI,
            /* [retval][out] */ BSTR *pbstrURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProviderData( 
            /* [retval][out] */ BSTR *pbstrData) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientName( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientBanner( 
            /* [retval][out] */ VARIANT_BOOL *pfBanner) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientMinVer( 
            /* [retval][out] */ BSTR *pbstrMinVer) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientCurVer( 
            /* [retval][out] */ BSTR *pbstrCurVer) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientUpdateURI( 
            /* [retval][out] */ BSTR *pbstrUpdateURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientData( 
            /* [retval][out] */ BSTR *pbstrData) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UserURI( 
            /* [retval][out] */ BSTR *pbstrUserURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UserName( 
            /* [retval][out] */ BSTR *pbstrUserName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UserAccount( 
            /* [retval][out] */ BSTR *pbstrUserAccount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCredentials( 
            /* [in] */ BSTR bstrUserURI,
            /* [in] */ BSTR bstrUserAccount,
            /* [in] */ BSTR bstrPassword) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SessionCapabilities( 
            /* [retval][out] */ long *plSupportedSessions) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ RTC_REGISTRATION_STATE *penState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCProfileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCProfile * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCProfile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCProfile * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrKey);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XML )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrXML);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderName )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderURI )( 
            IRTCProfile * This,
            /* [in] */ RTC_PROVIDER_URI enURI,
            /* [retval][out] */ BSTR *pbstrURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderData )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientName )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientBanner )( 
            IRTCProfile * This,
            /* [retval][out] */ VARIANT_BOOL *pfBanner);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientMinVer )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrMinVer);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientCurVer )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrCurVer);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientUpdateURI )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrUpdateURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientData )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserURI )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserName )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrUserName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserAccount )( 
            IRTCProfile * This,
            /* [retval][out] */ BSTR *pbstrUserAccount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCredentials )( 
            IRTCProfile * This,
            /* [in] */ BSTR bstrUserURI,
            /* [in] */ BSTR bstrUserAccount,
            /* [in] */ BSTR bstrPassword);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SessionCapabilities )( 
            IRTCProfile * This,
            /* [retval][out] */ long *plSupportedSessions);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCProfile * This,
            /* [retval][out] */ RTC_REGISTRATION_STATE *penState);
        
        END_INTERFACE
    } IRTCProfileVtbl;

    interface IRTCProfile
    {
        CONST_VTBL struct IRTCProfileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCProfile_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCProfile_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCProfile_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCProfile_get_Key(This,pbstrKey)	\
    (This)->lpVtbl -> get_Key(This,pbstrKey)

#define IRTCProfile_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IRTCProfile_get_XML(This,pbstrXML)	\
    (This)->lpVtbl -> get_XML(This,pbstrXML)

#define IRTCProfile_get_ProviderName(This,pbstrName)	\
    (This)->lpVtbl -> get_ProviderName(This,pbstrName)

#define IRTCProfile_get_ProviderURI(This,enURI,pbstrURI)	\
    (This)->lpVtbl -> get_ProviderURI(This,enURI,pbstrURI)

#define IRTCProfile_get_ProviderData(This,pbstrData)	\
    (This)->lpVtbl -> get_ProviderData(This,pbstrData)

#define IRTCProfile_get_ClientName(This,pbstrName)	\
    (This)->lpVtbl -> get_ClientName(This,pbstrName)

#define IRTCProfile_get_ClientBanner(This,pfBanner)	\
    (This)->lpVtbl -> get_ClientBanner(This,pfBanner)

#define IRTCProfile_get_ClientMinVer(This,pbstrMinVer)	\
    (This)->lpVtbl -> get_ClientMinVer(This,pbstrMinVer)

#define IRTCProfile_get_ClientCurVer(This,pbstrCurVer)	\
    (This)->lpVtbl -> get_ClientCurVer(This,pbstrCurVer)

#define IRTCProfile_get_ClientUpdateURI(This,pbstrUpdateURI)	\
    (This)->lpVtbl -> get_ClientUpdateURI(This,pbstrUpdateURI)

#define IRTCProfile_get_ClientData(This,pbstrData)	\
    (This)->lpVtbl -> get_ClientData(This,pbstrData)

#define IRTCProfile_get_UserURI(This,pbstrUserURI)	\
    (This)->lpVtbl -> get_UserURI(This,pbstrUserURI)

#define IRTCProfile_get_UserName(This,pbstrUserName)	\
    (This)->lpVtbl -> get_UserName(This,pbstrUserName)

#define IRTCProfile_get_UserAccount(This,pbstrUserAccount)	\
    (This)->lpVtbl -> get_UserAccount(This,pbstrUserAccount)

#define IRTCProfile_SetCredentials(This,bstrUserURI,bstrUserAccount,bstrPassword)	\
    (This)->lpVtbl -> SetCredentials(This,bstrUserURI,bstrUserAccount,bstrPassword)

#define IRTCProfile_get_SessionCapabilities(This,plSupportedSessions)	\
    (This)->lpVtbl -> get_SessionCapabilities(This,plSupportedSessions)

#define IRTCProfile_get_State(This,penState)	\
    (This)->lpVtbl -> get_State(This,penState)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_Key_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrKey);


void __RPC_STUB IRTCProfile_get_Key_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_Name_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IRTCProfile_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_XML_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrXML);


void __RPC_STUB IRTCProfile_get_XML_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_ProviderName_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IRTCProfile_get_ProviderName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_ProviderURI_Proxy( 
    IRTCProfile * This,
    /* [in] */ RTC_PROVIDER_URI enURI,
    /* [retval][out] */ BSTR *pbstrURI);


void __RPC_STUB IRTCProfile_get_ProviderURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_ProviderData_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrData);


void __RPC_STUB IRTCProfile_get_ProviderData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_ClientName_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IRTCProfile_get_ClientName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_ClientBanner_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ VARIANT_BOOL *pfBanner);


void __RPC_STUB IRTCProfile_get_ClientBanner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_ClientMinVer_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrMinVer);


void __RPC_STUB IRTCProfile_get_ClientMinVer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_ClientCurVer_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrCurVer);


void __RPC_STUB IRTCProfile_get_ClientCurVer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_ClientUpdateURI_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrUpdateURI);


void __RPC_STUB IRTCProfile_get_ClientUpdateURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_ClientData_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrData);


void __RPC_STUB IRTCProfile_get_ClientData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_UserURI_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrUserURI);


void __RPC_STUB IRTCProfile_get_UserURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_UserName_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrUserName);


void __RPC_STUB IRTCProfile_get_UserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_UserAccount_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ BSTR *pbstrUserAccount);


void __RPC_STUB IRTCProfile_get_UserAccount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCProfile_SetCredentials_Proxy( 
    IRTCProfile * This,
    /* [in] */ BSTR bstrUserURI,
    /* [in] */ BSTR bstrUserAccount,
    /* [in] */ BSTR bstrPassword);


void __RPC_STUB IRTCProfile_SetCredentials_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_SessionCapabilities_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ long *plSupportedSessions);


void __RPC_STUB IRTCProfile_get_SessionCapabilities_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile_get_State_Proxy( 
    IRTCProfile * This,
    /* [retval][out] */ RTC_REGISTRATION_STATE *penState);


void __RPC_STUB IRTCProfile_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCProfile_INTERFACE_DEFINED__ */


#ifndef __IRTCProfile2_INTERFACE_DEFINED__
#define __IRTCProfile2_INTERFACE_DEFINED__

/* interface IRTCProfile2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCProfile2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4B81F84E-BDC7-4184-9154-3CB2DD7917FB")
    IRTCProfile2 : public IRTCProfile
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Realm( 
            /* [retval][out] */ BSTR *pbstrRealm) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Realm( 
            /* [in] */ BSTR bstrRealm) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AllowedAuth( 
            /* [retval][out] */ long *plAllowedAuth) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AllowedAuth( 
            /* [in] */ long lAllowedAuth) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCProfile2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCProfile2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCProfile2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCProfile2 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrKey);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XML )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrXML);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderName )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderURI )( 
            IRTCProfile2 * This,
            /* [in] */ RTC_PROVIDER_URI enURI,
            /* [retval][out] */ BSTR *pbstrURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderData )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientName )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientBanner )( 
            IRTCProfile2 * This,
            /* [retval][out] */ VARIANT_BOOL *pfBanner);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientMinVer )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrMinVer);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientCurVer )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrCurVer);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientUpdateURI )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrUpdateURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientData )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserURI )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserName )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrUserName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserAccount )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrUserAccount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCredentials )( 
            IRTCProfile2 * This,
            /* [in] */ BSTR bstrUserURI,
            /* [in] */ BSTR bstrUserAccount,
            /* [in] */ BSTR bstrPassword);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SessionCapabilities )( 
            IRTCProfile2 * This,
            /* [retval][out] */ long *plSupportedSessions);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCProfile2 * This,
            /* [retval][out] */ RTC_REGISTRATION_STATE *penState);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Realm )( 
            IRTCProfile2 * This,
            /* [retval][out] */ BSTR *pbstrRealm);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Realm )( 
            IRTCProfile2 * This,
            /* [in] */ BSTR bstrRealm);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowedAuth )( 
            IRTCProfile2 * This,
            /* [retval][out] */ long *plAllowedAuth);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowedAuth )( 
            IRTCProfile2 * This,
            /* [in] */ long lAllowedAuth);
        
        END_INTERFACE
    } IRTCProfile2Vtbl;

    interface IRTCProfile2
    {
        CONST_VTBL struct IRTCProfile2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCProfile2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCProfile2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCProfile2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCProfile2_get_Key(This,pbstrKey)	\
    (This)->lpVtbl -> get_Key(This,pbstrKey)

#define IRTCProfile2_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IRTCProfile2_get_XML(This,pbstrXML)	\
    (This)->lpVtbl -> get_XML(This,pbstrXML)

#define IRTCProfile2_get_ProviderName(This,pbstrName)	\
    (This)->lpVtbl -> get_ProviderName(This,pbstrName)

#define IRTCProfile2_get_ProviderURI(This,enURI,pbstrURI)	\
    (This)->lpVtbl -> get_ProviderURI(This,enURI,pbstrURI)

#define IRTCProfile2_get_ProviderData(This,pbstrData)	\
    (This)->lpVtbl -> get_ProviderData(This,pbstrData)

#define IRTCProfile2_get_ClientName(This,pbstrName)	\
    (This)->lpVtbl -> get_ClientName(This,pbstrName)

#define IRTCProfile2_get_ClientBanner(This,pfBanner)	\
    (This)->lpVtbl -> get_ClientBanner(This,pfBanner)

#define IRTCProfile2_get_ClientMinVer(This,pbstrMinVer)	\
    (This)->lpVtbl -> get_ClientMinVer(This,pbstrMinVer)

#define IRTCProfile2_get_ClientCurVer(This,pbstrCurVer)	\
    (This)->lpVtbl -> get_ClientCurVer(This,pbstrCurVer)

#define IRTCProfile2_get_ClientUpdateURI(This,pbstrUpdateURI)	\
    (This)->lpVtbl -> get_ClientUpdateURI(This,pbstrUpdateURI)

#define IRTCProfile2_get_ClientData(This,pbstrData)	\
    (This)->lpVtbl -> get_ClientData(This,pbstrData)

#define IRTCProfile2_get_UserURI(This,pbstrUserURI)	\
    (This)->lpVtbl -> get_UserURI(This,pbstrUserURI)

#define IRTCProfile2_get_UserName(This,pbstrUserName)	\
    (This)->lpVtbl -> get_UserName(This,pbstrUserName)

#define IRTCProfile2_get_UserAccount(This,pbstrUserAccount)	\
    (This)->lpVtbl -> get_UserAccount(This,pbstrUserAccount)

#define IRTCProfile2_SetCredentials(This,bstrUserURI,bstrUserAccount,bstrPassword)	\
    (This)->lpVtbl -> SetCredentials(This,bstrUserURI,bstrUserAccount,bstrPassword)

#define IRTCProfile2_get_SessionCapabilities(This,plSupportedSessions)	\
    (This)->lpVtbl -> get_SessionCapabilities(This,plSupportedSessions)

#define IRTCProfile2_get_State(This,penState)	\
    (This)->lpVtbl -> get_State(This,penState)


#define IRTCProfile2_get_Realm(This,pbstrRealm)	\
    (This)->lpVtbl -> get_Realm(This,pbstrRealm)

#define IRTCProfile2_put_Realm(This,bstrRealm)	\
    (This)->lpVtbl -> put_Realm(This,bstrRealm)

#define IRTCProfile2_get_AllowedAuth(This,plAllowedAuth)	\
    (This)->lpVtbl -> get_AllowedAuth(This,plAllowedAuth)

#define IRTCProfile2_put_AllowedAuth(This,lAllowedAuth)	\
    (This)->lpVtbl -> put_AllowedAuth(This,lAllowedAuth)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile2_get_Realm_Proxy( 
    IRTCProfile2 * This,
    /* [retval][out] */ BSTR *pbstrRealm);


void __RPC_STUB IRTCProfile2_get_Realm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCProfile2_put_Realm_Proxy( 
    IRTCProfile2 * This,
    /* [in] */ BSTR bstrRealm);


void __RPC_STUB IRTCProfile2_put_Realm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfile2_get_AllowedAuth_Proxy( 
    IRTCProfile2 * This,
    /* [retval][out] */ long *plAllowedAuth);


void __RPC_STUB IRTCProfile2_get_AllowedAuth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCProfile2_put_AllowedAuth_Proxy( 
    IRTCProfile2 * This,
    /* [in] */ long lAllowedAuth);


void __RPC_STUB IRTCProfile2_put_AllowedAuth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCProfile2_INTERFACE_DEFINED__ */


#ifndef __IRTCSession_INTERFACE_DEFINED__
#define __IRTCSession_INTERFACE_DEFINED__

/* interface IRTCSession */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("387c8086-99be-42fb-9973-7c0fc0ca9fa8")
    IRTCSession : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Client( 
            /* [retval][out] */ IRTCClient **ppClient) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ RTC_SESSION_STATE *penState) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ RTC_SESSION_TYPE *penType) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [retval][out] */ IRTCProfile **ppProfile) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Participants( 
            /* [retval][out] */ IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Answer( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Terminate( 
            /* [in] */ RTC_TERMINATE_REASON enReason) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Redirect( 
            /* [in] */ RTC_SESSION_TYPE enType,
            /* [in] */ BSTR bstrLocalPhoneURI,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddParticipant( 
            /* [in] */ BSTR bstrAddress,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IRTCParticipant **ppParticipant) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveParticipant( 
            /* [in] */ IRTCParticipant *pParticipant) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateParticipants( 
            /* [retval][out] */ IRTCEnumParticipants **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CanAddParticipants( 
            /* [retval][out] */ VARIANT_BOOL *pfCanAdd) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RedirectedUserURI( 
            /* [retval][out] */ BSTR *pbstrUserURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RedirectedUserName( 
            /* [retval][out] */ BSTR *pbstrUserName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE NextRedirectedUser( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendMessage( 
            /* [in] */ BSTR bstrMessageHeader,
            /* [in] */ BSTR bstrMessage,
            /* [in] */ LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendMessageStatus( 
            /* [in] */ RTC_MESSAGING_USER_STATUS enUserStatus,
            /* [in] */ LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddStream( 
            /* [in] */ long lMediaType,
            /* [in] */ LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveStream( 
            /* [in] */ long lMediaType,
            /* [in] */ LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_EncryptionKey( 
            /* [in] */ long lMediaType,
            /* [in] */ BSTR EncryptionKey) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCSession * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCSession * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCSession * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Client )( 
            IRTCSession * This,
            /* [retval][out] */ IRTCClient **ppClient);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCSession * This,
            /* [retval][out] */ RTC_SESSION_STATE *penState);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IRTCSession * This,
            /* [retval][out] */ RTC_SESSION_TYPE *penType);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            IRTCSession * This,
            /* [retval][out] */ IRTCProfile **ppProfile);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participants )( 
            IRTCSession * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Answer )( 
            IRTCSession * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            IRTCSession * This,
            /* [in] */ RTC_TERMINATE_REASON enReason);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Redirect )( 
            IRTCSession * This,
            /* [in] */ RTC_SESSION_TYPE enType,
            /* [in] */ BSTR bstrLocalPhoneURI,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddParticipant )( 
            IRTCSession * This,
            /* [in] */ BSTR bstrAddress,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IRTCParticipant **ppParticipant);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveParticipant )( 
            IRTCSession * This,
            /* [in] */ IRTCParticipant *pParticipant);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateParticipants )( 
            IRTCSession * This,
            /* [retval][out] */ IRTCEnumParticipants **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanAddParticipants )( 
            IRTCSession * This,
            /* [retval][out] */ VARIANT_BOOL *pfCanAdd);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RedirectedUserURI )( 
            IRTCSession * This,
            /* [retval][out] */ BSTR *pbstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RedirectedUserName )( 
            IRTCSession * This,
            /* [retval][out] */ BSTR *pbstrUserName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *NextRedirectedUser )( 
            IRTCSession * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendMessage )( 
            IRTCSession * This,
            /* [in] */ BSTR bstrMessageHeader,
            /* [in] */ BSTR bstrMessage,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendMessageStatus )( 
            IRTCSession * This,
            /* [in] */ RTC_MESSAGING_USER_STATUS enUserStatus,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddStream )( 
            IRTCSession * This,
            /* [in] */ long lMediaType,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveStream )( 
            IRTCSession * This,
            /* [in] */ long lMediaType,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncryptionKey )( 
            IRTCSession * This,
            /* [in] */ long lMediaType,
            /* [in] */ BSTR EncryptionKey);
        
        END_INTERFACE
    } IRTCSessionVtbl;

    interface IRTCSession
    {
        CONST_VTBL struct IRTCSessionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCSession_get_Client(This,ppClient)	\
    (This)->lpVtbl -> get_Client(This,ppClient)

#define IRTCSession_get_State(This,penState)	\
    (This)->lpVtbl -> get_State(This,penState)

#define IRTCSession_get_Type(This,penType)	\
    (This)->lpVtbl -> get_Type(This,penType)

#define IRTCSession_get_Profile(This,ppProfile)	\
    (This)->lpVtbl -> get_Profile(This,ppProfile)

#define IRTCSession_get_Participants(This,ppCollection)	\
    (This)->lpVtbl -> get_Participants(This,ppCollection)

#define IRTCSession_Answer(This)	\
    (This)->lpVtbl -> Answer(This)

#define IRTCSession_Terminate(This,enReason)	\
    (This)->lpVtbl -> Terminate(This,enReason)

#define IRTCSession_Redirect(This,enType,bstrLocalPhoneURI,pProfile,lFlags)	\
    (This)->lpVtbl -> Redirect(This,enType,bstrLocalPhoneURI,pProfile,lFlags)

#define IRTCSession_AddParticipant(This,bstrAddress,bstrName,ppParticipant)	\
    (This)->lpVtbl -> AddParticipant(This,bstrAddress,bstrName,ppParticipant)

#define IRTCSession_RemoveParticipant(This,pParticipant)	\
    (This)->lpVtbl -> RemoveParticipant(This,pParticipant)

#define IRTCSession_EnumerateParticipants(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateParticipants(This,ppEnum)

#define IRTCSession_get_CanAddParticipants(This,pfCanAdd)	\
    (This)->lpVtbl -> get_CanAddParticipants(This,pfCanAdd)

#define IRTCSession_get_RedirectedUserURI(This,pbstrUserURI)	\
    (This)->lpVtbl -> get_RedirectedUserURI(This,pbstrUserURI)

#define IRTCSession_get_RedirectedUserName(This,pbstrUserName)	\
    (This)->lpVtbl -> get_RedirectedUserName(This,pbstrUserName)

#define IRTCSession_NextRedirectedUser(This)	\
    (This)->lpVtbl -> NextRedirectedUser(This)

#define IRTCSession_SendMessage(This,bstrMessageHeader,bstrMessage,lCookie)	\
    (This)->lpVtbl -> SendMessage(This,bstrMessageHeader,bstrMessage,lCookie)

#define IRTCSession_SendMessageStatus(This,enUserStatus,lCookie)	\
    (This)->lpVtbl -> SendMessageStatus(This,enUserStatus,lCookie)

#define IRTCSession_AddStream(This,lMediaType,lCookie)	\
    (This)->lpVtbl -> AddStream(This,lMediaType,lCookie)

#define IRTCSession_RemoveStream(This,lMediaType,lCookie)	\
    (This)->lpVtbl -> RemoveStream(This,lMediaType,lCookie)

#define IRTCSession_put_EncryptionKey(This,lMediaType,EncryptionKey)	\
    (This)->lpVtbl -> put_EncryptionKey(This,lMediaType,EncryptionKey)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSession_get_Client_Proxy( 
    IRTCSession * This,
    /* [retval][out] */ IRTCClient **ppClient);


void __RPC_STUB IRTCSession_get_Client_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSession_get_State_Proxy( 
    IRTCSession * This,
    /* [retval][out] */ RTC_SESSION_STATE *penState);


void __RPC_STUB IRTCSession_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSession_get_Type_Proxy( 
    IRTCSession * This,
    /* [retval][out] */ RTC_SESSION_TYPE *penType);


void __RPC_STUB IRTCSession_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSession_get_Profile_Proxy( 
    IRTCSession * This,
    /* [retval][out] */ IRTCProfile **ppProfile);


void __RPC_STUB IRTCSession_get_Profile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSession_get_Participants_Proxy( 
    IRTCSession * This,
    /* [retval][out] */ IRTCCollection **ppCollection);


void __RPC_STUB IRTCSession_get_Participants_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession_Answer_Proxy( 
    IRTCSession * This);


void __RPC_STUB IRTCSession_Answer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession_Terminate_Proxy( 
    IRTCSession * This,
    /* [in] */ RTC_TERMINATE_REASON enReason);


void __RPC_STUB IRTCSession_Terminate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession_Redirect_Proxy( 
    IRTCSession * This,
    /* [in] */ RTC_SESSION_TYPE enType,
    /* [in] */ BSTR bstrLocalPhoneURI,
    /* [in] */ IRTCProfile *pProfile,
    /* [in] */ long lFlags);


void __RPC_STUB IRTCSession_Redirect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession_AddParticipant_Proxy( 
    IRTCSession * This,
    /* [in] */ BSTR bstrAddress,
    /* [in] */ BSTR bstrName,
    /* [retval][out] */ IRTCParticipant **ppParticipant);


void __RPC_STUB IRTCSession_AddParticipant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession_RemoveParticipant_Proxy( 
    IRTCSession * This,
    /* [in] */ IRTCParticipant *pParticipant);


void __RPC_STUB IRTCSession_RemoveParticipant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE IRTCSession_EnumerateParticipants_Proxy( 
    IRTCSession * This,
    /* [retval][out] */ IRTCEnumParticipants **ppEnum);


void __RPC_STUB IRTCSession_EnumerateParticipants_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSession_get_CanAddParticipants_Proxy( 
    IRTCSession * This,
    /* [retval][out] */ VARIANT_BOOL *pfCanAdd);


void __RPC_STUB IRTCSession_get_CanAddParticipants_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSession_get_RedirectedUserURI_Proxy( 
    IRTCSession * This,
    /* [retval][out] */ BSTR *pbstrUserURI);


void __RPC_STUB IRTCSession_get_RedirectedUserURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSession_get_RedirectedUserName_Proxy( 
    IRTCSession * This,
    /* [retval][out] */ BSTR *pbstrUserName);


void __RPC_STUB IRTCSession_get_RedirectedUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession_NextRedirectedUser_Proxy( 
    IRTCSession * This);


void __RPC_STUB IRTCSession_NextRedirectedUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession_SendMessage_Proxy( 
    IRTCSession * This,
    /* [in] */ BSTR bstrMessageHeader,
    /* [in] */ BSTR bstrMessage,
    /* [in] */ LONG_PTR lCookie);


void __RPC_STUB IRTCSession_SendMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession_SendMessageStatus_Proxy( 
    IRTCSession * This,
    /* [in] */ RTC_MESSAGING_USER_STATUS enUserStatus,
    /* [in] */ LONG_PTR lCookie);


void __RPC_STUB IRTCSession_SendMessageStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession_AddStream_Proxy( 
    IRTCSession * This,
    /* [in] */ long lMediaType,
    /* [in] */ LONG_PTR lCookie);


void __RPC_STUB IRTCSession_AddStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession_RemoveStream_Proxy( 
    IRTCSession * This,
    /* [in] */ long lMediaType,
    /* [in] */ LONG_PTR lCookie);


void __RPC_STUB IRTCSession_RemoveStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCSession_put_EncryptionKey_Proxy( 
    IRTCSession * This,
    /* [in] */ long lMediaType,
    /* [in] */ BSTR EncryptionKey);


void __RPC_STUB IRTCSession_put_EncryptionKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCSession_INTERFACE_DEFINED__ */


#ifndef __IRTCSession2_INTERFACE_DEFINED__
#define __IRTCSession2_INTERFACE_DEFINED__

/* interface IRTCSession2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCSession2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17D7CDFC-B007-484c-99D2-86A8A820991D")
    IRTCSession2 : public IRTCSession
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendInfo( 
            /* [in] */ BSTR bstrInfoHeader,
            /* [in] */ BSTR bstrInfo,
            /* [in] */ LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredSecurityLevel( 
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [in] */ RTC_SECURITY_LEVEL enSecurityLevel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredSecurityLevel( 
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsSecurityEnabled( 
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [retval][out] */ VARIANT_BOOL *pfSecurityEnabled) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AnswerWithSessionDescription( 
            /* [in] */ BSTR bstrContentType,
            /* [in] */ BSTR bstrSessionDescription) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReInviteWithSessionDescription( 
            /* [in] */ BSTR bstrContentType,
            /* [in] */ BSTR bstrSessionDescription,
            /* [in] */ LONG_PTR lCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCSession2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCSession2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCSession2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCSession2 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Client )( 
            IRTCSession2 * This,
            /* [retval][out] */ IRTCClient **ppClient);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCSession2 * This,
            /* [retval][out] */ RTC_SESSION_STATE *penState);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IRTCSession2 * This,
            /* [retval][out] */ RTC_SESSION_TYPE *penType);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            IRTCSession2 * This,
            /* [retval][out] */ IRTCProfile **ppProfile);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participants )( 
            IRTCSession2 * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Answer )( 
            IRTCSession2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            IRTCSession2 * This,
            /* [in] */ RTC_TERMINATE_REASON enReason);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Redirect )( 
            IRTCSession2 * This,
            /* [in] */ RTC_SESSION_TYPE enType,
            /* [in] */ BSTR bstrLocalPhoneURI,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ long lFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddParticipant )( 
            IRTCSession2 * This,
            /* [in] */ BSTR bstrAddress,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IRTCParticipant **ppParticipant);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveParticipant )( 
            IRTCSession2 * This,
            /* [in] */ IRTCParticipant *pParticipant);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateParticipants )( 
            IRTCSession2 * This,
            /* [retval][out] */ IRTCEnumParticipants **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanAddParticipants )( 
            IRTCSession2 * This,
            /* [retval][out] */ VARIANT_BOOL *pfCanAdd);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RedirectedUserURI )( 
            IRTCSession2 * This,
            /* [retval][out] */ BSTR *pbstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RedirectedUserName )( 
            IRTCSession2 * This,
            /* [retval][out] */ BSTR *pbstrUserName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *NextRedirectedUser )( 
            IRTCSession2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendMessage )( 
            IRTCSession2 * This,
            /* [in] */ BSTR bstrMessageHeader,
            /* [in] */ BSTR bstrMessage,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendMessageStatus )( 
            IRTCSession2 * This,
            /* [in] */ RTC_MESSAGING_USER_STATUS enUserStatus,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddStream )( 
            IRTCSession2 * This,
            /* [in] */ long lMediaType,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveStream )( 
            IRTCSession2 * This,
            /* [in] */ long lMediaType,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncryptionKey )( 
            IRTCSession2 * This,
            /* [in] */ long lMediaType,
            /* [in] */ BSTR EncryptionKey);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendInfo )( 
            IRTCSession2 * This,
            /* [in] */ BSTR bstrInfoHeader,
            /* [in] */ BSTR bstrInfo,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredSecurityLevel )( 
            IRTCSession2 * This,
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [in] */ RTC_SECURITY_LEVEL enSecurityLevel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredSecurityLevel )( 
            IRTCSession2 * This,
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsSecurityEnabled )( 
            IRTCSession2 * This,
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [retval][out] */ VARIANT_BOOL *pfSecurityEnabled);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AnswerWithSessionDescription )( 
            IRTCSession2 * This,
            /* [in] */ BSTR bstrContentType,
            /* [in] */ BSTR bstrSessionDescription);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReInviteWithSessionDescription )( 
            IRTCSession2 * This,
            /* [in] */ BSTR bstrContentType,
            /* [in] */ BSTR bstrSessionDescription,
            /* [in] */ LONG_PTR lCookie);
        
        END_INTERFACE
    } IRTCSession2Vtbl;

    interface IRTCSession2
    {
        CONST_VTBL struct IRTCSession2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSession2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCSession2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCSession2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCSession2_get_Client(This,ppClient)	\
    (This)->lpVtbl -> get_Client(This,ppClient)

#define IRTCSession2_get_State(This,penState)	\
    (This)->lpVtbl -> get_State(This,penState)

#define IRTCSession2_get_Type(This,penType)	\
    (This)->lpVtbl -> get_Type(This,penType)

#define IRTCSession2_get_Profile(This,ppProfile)	\
    (This)->lpVtbl -> get_Profile(This,ppProfile)

#define IRTCSession2_get_Participants(This,ppCollection)	\
    (This)->lpVtbl -> get_Participants(This,ppCollection)

#define IRTCSession2_Answer(This)	\
    (This)->lpVtbl -> Answer(This)

#define IRTCSession2_Terminate(This,enReason)	\
    (This)->lpVtbl -> Terminate(This,enReason)

#define IRTCSession2_Redirect(This,enType,bstrLocalPhoneURI,pProfile,lFlags)	\
    (This)->lpVtbl -> Redirect(This,enType,bstrLocalPhoneURI,pProfile,lFlags)

#define IRTCSession2_AddParticipant(This,bstrAddress,bstrName,ppParticipant)	\
    (This)->lpVtbl -> AddParticipant(This,bstrAddress,bstrName,ppParticipant)

#define IRTCSession2_RemoveParticipant(This,pParticipant)	\
    (This)->lpVtbl -> RemoveParticipant(This,pParticipant)

#define IRTCSession2_EnumerateParticipants(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateParticipants(This,ppEnum)

#define IRTCSession2_get_CanAddParticipants(This,pfCanAdd)	\
    (This)->lpVtbl -> get_CanAddParticipants(This,pfCanAdd)

#define IRTCSession2_get_RedirectedUserURI(This,pbstrUserURI)	\
    (This)->lpVtbl -> get_RedirectedUserURI(This,pbstrUserURI)

#define IRTCSession2_get_RedirectedUserName(This,pbstrUserName)	\
    (This)->lpVtbl -> get_RedirectedUserName(This,pbstrUserName)

#define IRTCSession2_NextRedirectedUser(This)	\
    (This)->lpVtbl -> NextRedirectedUser(This)

#define IRTCSession2_SendMessage(This,bstrMessageHeader,bstrMessage,lCookie)	\
    (This)->lpVtbl -> SendMessage(This,bstrMessageHeader,bstrMessage,lCookie)

#define IRTCSession2_SendMessageStatus(This,enUserStatus,lCookie)	\
    (This)->lpVtbl -> SendMessageStatus(This,enUserStatus,lCookie)

#define IRTCSession2_AddStream(This,lMediaType,lCookie)	\
    (This)->lpVtbl -> AddStream(This,lMediaType,lCookie)

#define IRTCSession2_RemoveStream(This,lMediaType,lCookie)	\
    (This)->lpVtbl -> RemoveStream(This,lMediaType,lCookie)

#define IRTCSession2_put_EncryptionKey(This,lMediaType,EncryptionKey)	\
    (This)->lpVtbl -> put_EncryptionKey(This,lMediaType,EncryptionKey)


#define IRTCSession2_SendInfo(This,bstrInfoHeader,bstrInfo,lCookie)	\
    (This)->lpVtbl -> SendInfo(This,bstrInfoHeader,bstrInfo,lCookie)

#define IRTCSession2_put_PreferredSecurityLevel(This,enSecurityType,enSecurityLevel)	\
    (This)->lpVtbl -> put_PreferredSecurityLevel(This,enSecurityType,enSecurityLevel)

#define IRTCSession2_get_PreferredSecurityLevel(This,enSecurityType,penSecurityLevel)	\
    (This)->lpVtbl -> get_PreferredSecurityLevel(This,enSecurityType,penSecurityLevel)

#define IRTCSession2_IsSecurityEnabled(This,enSecurityType,pfSecurityEnabled)	\
    (This)->lpVtbl -> IsSecurityEnabled(This,enSecurityType,pfSecurityEnabled)

#define IRTCSession2_AnswerWithSessionDescription(This,bstrContentType,bstrSessionDescription)	\
    (This)->lpVtbl -> AnswerWithSessionDescription(This,bstrContentType,bstrSessionDescription)

#define IRTCSession2_ReInviteWithSessionDescription(This,bstrContentType,bstrSessionDescription,lCookie)	\
    (This)->lpVtbl -> ReInviteWithSessionDescription(This,bstrContentType,bstrSessionDescription,lCookie)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession2_SendInfo_Proxy( 
    IRTCSession2 * This,
    /* [in] */ BSTR bstrInfoHeader,
    /* [in] */ BSTR bstrInfo,
    /* [in] */ LONG_PTR lCookie);


void __RPC_STUB IRTCSession2_SendInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCSession2_put_PreferredSecurityLevel_Proxy( 
    IRTCSession2 * This,
    /* [in] */ RTC_SECURITY_TYPE enSecurityType,
    /* [in] */ RTC_SECURITY_LEVEL enSecurityLevel);


void __RPC_STUB IRTCSession2_put_PreferredSecurityLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSession2_get_PreferredSecurityLevel_Proxy( 
    IRTCSession2 * This,
    /* [in] */ RTC_SECURITY_TYPE enSecurityType,
    /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel);


void __RPC_STUB IRTCSession2_get_PreferredSecurityLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession2_IsSecurityEnabled_Proxy( 
    IRTCSession2 * This,
    /* [in] */ RTC_SECURITY_TYPE enSecurityType,
    /* [retval][out] */ VARIANT_BOOL *pfSecurityEnabled);


void __RPC_STUB IRTCSession2_IsSecurityEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession2_AnswerWithSessionDescription_Proxy( 
    IRTCSession2 * This,
    /* [in] */ BSTR bstrContentType,
    /* [in] */ BSTR bstrSessionDescription);


void __RPC_STUB IRTCSession2_AnswerWithSessionDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSession2_ReInviteWithSessionDescription_Proxy( 
    IRTCSession2 * This,
    /* [in] */ BSTR bstrContentType,
    /* [in] */ BSTR bstrSessionDescription,
    /* [in] */ LONG_PTR lCookie);


void __RPC_STUB IRTCSession2_ReInviteWithSessionDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCSession2_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionCallControl_INTERFACE_DEFINED__
#define __IRTCSessionCallControl_INTERFACE_DEFINED__

/* interface IRTCSessionCallControl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionCallControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E9A50D94-190B-4F82-9530-3B8EBF60758A")
    IRTCSessionCallControl : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Hold( 
            /* [in] */ LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UnHold( 
            /* [in] */ LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Forward( 
            /* [in] */ BSTR bstrForwardToURI) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Refer( 
            /* [in] */ BSTR bstrReferToURI,
            /* [in] */ BSTR bstrReferCookie) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ReferredByURI( 
            /* [in] */ BSTR bstrReferredByURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ReferredByURI( 
            /* [retval][out] */ BSTR *pbstrReferredByURI) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ReferCookie( 
            /* [in] */ BSTR bstrReferCookie) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ReferCookie( 
            /* [retval][out] */ BSTR *pbstrReferCookie) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsReferred( 
            /* [retval][out] */ VARIANT_BOOL *pfIsReferred) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCSessionCallControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCSessionCallControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCSessionCallControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCSessionCallControl * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Hold )( 
            IRTCSessionCallControl * This,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnHold )( 
            IRTCSessionCallControl * This,
            /* [in] */ LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Forward )( 
            IRTCSessionCallControl * This,
            /* [in] */ BSTR bstrForwardToURI);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Refer )( 
            IRTCSessionCallControl * This,
            /* [in] */ BSTR bstrReferToURI,
            /* [in] */ BSTR bstrReferCookie);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReferredByURI )( 
            IRTCSessionCallControl * This,
            /* [in] */ BSTR bstrReferredByURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferredByURI )( 
            IRTCSessionCallControl * This,
            /* [retval][out] */ BSTR *pbstrReferredByURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReferCookie )( 
            IRTCSessionCallControl * This,
            /* [in] */ BSTR bstrReferCookie);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferCookie )( 
            IRTCSessionCallControl * This,
            /* [retval][out] */ BSTR *pbstrReferCookie);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReferred )( 
            IRTCSessionCallControl * This,
            /* [retval][out] */ VARIANT_BOOL *pfIsReferred);
        
        END_INTERFACE
    } IRTCSessionCallControlVtbl;

    interface IRTCSessionCallControl
    {
        CONST_VTBL struct IRTCSessionCallControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionCallControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCSessionCallControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCSessionCallControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCSessionCallControl_Hold(This,lCookie)	\
    (This)->lpVtbl -> Hold(This,lCookie)

#define IRTCSessionCallControl_UnHold(This,lCookie)	\
    (This)->lpVtbl -> UnHold(This,lCookie)

#define IRTCSessionCallControl_Forward(This,bstrForwardToURI)	\
    (This)->lpVtbl -> Forward(This,bstrForwardToURI)

#define IRTCSessionCallControl_Refer(This,bstrReferToURI,bstrReferCookie)	\
    (This)->lpVtbl -> Refer(This,bstrReferToURI,bstrReferCookie)

#define IRTCSessionCallControl_put_ReferredByURI(This,bstrReferredByURI)	\
    (This)->lpVtbl -> put_ReferredByURI(This,bstrReferredByURI)

#define IRTCSessionCallControl_get_ReferredByURI(This,pbstrReferredByURI)	\
    (This)->lpVtbl -> get_ReferredByURI(This,pbstrReferredByURI)

#define IRTCSessionCallControl_put_ReferCookie(This,bstrReferCookie)	\
    (This)->lpVtbl -> put_ReferCookie(This,bstrReferCookie)

#define IRTCSessionCallControl_get_ReferCookie(This,pbstrReferCookie)	\
    (This)->lpVtbl -> get_ReferCookie(This,pbstrReferCookie)

#define IRTCSessionCallControl_get_IsReferred(This,pfIsReferred)	\
    (This)->lpVtbl -> get_IsReferred(This,pfIsReferred)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSessionCallControl_Hold_Proxy( 
    IRTCSessionCallControl * This,
    /* [in] */ LONG_PTR lCookie);


void __RPC_STUB IRTCSessionCallControl_Hold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSessionCallControl_UnHold_Proxy( 
    IRTCSessionCallControl * This,
    /* [in] */ LONG_PTR lCookie);


void __RPC_STUB IRTCSessionCallControl_UnHold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSessionCallControl_Forward_Proxy( 
    IRTCSessionCallControl * This,
    /* [in] */ BSTR bstrForwardToURI);


void __RPC_STUB IRTCSessionCallControl_Forward_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCSessionCallControl_Refer_Proxy( 
    IRTCSessionCallControl * This,
    /* [in] */ BSTR bstrReferToURI,
    /* [in] */ BSTR bstrReferCookie);


void __RPC_STUB IRTCSessionCallControl_Refer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCSessionCallControl_put_ReferredByURI_Proxy( 
    IRTCSessionCallControl * This,
    /* [in] */ BSTR bstrReferredByURI);


void __RPC_STUB IRTCSessionCallControl_put_ReferredByURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionCallControl_get_ReferredByURI_Proxy( 
    IRTCSessionCallControl * This,
    /* [retval][out] */ BSTR *pbstrReferredByURI);


void __RPC_STUB IRTCSessionCallControl_get_ReferredByURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCSessionCallControl_put_ReferCookie_Proxy( 
    IRTCSessionCallControl * This,
    /* [in] */ BSTR bstrReferCookie);


void __RPC_STUB IRTCSessionCallControl_put_ReferCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionCallControl_get_ReferCookie_Proxy( 
    IRTCSessionCallControl * This,
    /* [retval][out] */ BSTR *pbstrReferCookie);


void __RPC_STUB IRTCSessionCallControl_get_ReferCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionCallControl_get_IsReferred_Proxy( 
    IRTCSessionCallControl * This,
    /* [retval][out] */ VARIANT_BOOL *pfIsReferred);


void __RPC_STUB IRTCSessionCallControl_get_IsReferred_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCSessionCallControl_INTERFACE_DEFINED__ */


#ifndef __IRTCParticipant_INTERFACE_DEFINED__
#define __IRTCParticipant_INTERFACE_DEFINED__

/* interface IRTCParticipant */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCParticipant;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ae86add5-26b1-4414-af1d-b94cd938d739")
    IRTCParticipant : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UserURI( 
            /* [retval][out] */ BSTR *pbstrUserURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Removable( 
            /* [retval][out] */ VARIANT_BOOL *pfRemovable) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ RTC_PARTICIPANT_STATE *penState) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [retval][out] */ IRTCSession **ppSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCParticipantVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCParticipant * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCParticipant * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCParticipant * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserURI )( 
            IRTCParticipant * This,
            /* [retval][out] */ BSTR *pbstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IRTCParticipant * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Removable )( 
            IRTCParticipant * This,
            /* [retval][out] */ VARIANT_BOOL *pfRemovable);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCParticipant * This,
            /* [retval][out] */ RTC_PARTICIPANT_STATE *penState);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            IRTCParticipant * This,
            /* [retval][out] */ IRTCSession **ppSession);
        
        END_INTERFACE
    } IRTCParticipantVtbl;

    interface IRTCParticipant
    {
        CONST_VTBL struct IRTCParticipantVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCParticipant_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCParticipant_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCParticipant_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCParticipant_get_UserURI(This,pbstrUserURI)	\
    (This)->lpVtbl -> get_UserURI(This,pbstrUserURI)

#define IRTCParticipant_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IRTCParticipant_get_Removable(This,pfRemovable)	\
    (This)->lpVtbl -> get_Removable(This,pfRemovable)

#define IRTCParticipant_get_State(This,penState)	\
    (This)->lpVtbl -> get_State(This,penState)

#define IRTCParticipant_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCParticipant_get_UserURI_Proxy( 
    IRTCParticipant * This,
    /* [retval][out] */ BSTR *pbstrUserURI);


void __RPC_STUB IRTCParticipant_get_UserURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCParticipant_get_Name_Proxy( 
    IRTCParticipant * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IRTCParticipant_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCParticipant_get_Removable_Proxy( 
    IRTCParticipant * This,
    /* [retval][out] */ VARIANT_BOOL *pfRemovable);


void __RPC_STUB IRTCParticipant_get_Removable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCParticipant_get_State_Proxy( 
    IRTCParticipant * This,
    /* [retval][out] */ RTC_PARTICIPANT_STATE *penState);


void __RPC_STUB IRTCParticipant_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCParticipant_get_Session_Proxy( 
    IRTCParticipant * This,
    /* [retval][out] */ IRTCSession **ppSession);


void __RPC_STUB IRTCParticipant_get_Session_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCParticipant_INTERFACE_DEFINED__ */


#ifndef __IRTCRoamingEvent_INTERFACE_DEFINED__
#define __IRTCRoamingEvent_INTERFACE_DEFINED__

/* interface IRTCRoamingEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCRoamingEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("79960a6b-0cb1-4dc8-a805-7318e99902e8")
    IRTCRoamingEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [retval][out] */ RTC_ROAMING_EVENT_TYPE *pEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [retval][out] */ IRTCProfile2 **ppProfile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [retval][out] */ BSTR *pbstrStatusText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCRoamingEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCRoamingEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCRoamingEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCRoamingEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCRoamingEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCRoamingEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCRoamingEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCRoamingEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            IRTCRoamingEvent * This,
            /* [retval][out] */ RTC_ROAMING_EVENT_TYPE *pEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            IRTCRoamingEvent * This,
            /* [retval][out] */ IRTCProfile2 **ppProfile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCRoamingEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            IRTCRoamingEvent * This,
            /* [retval][out] */ BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCRoamingEventVtbl;

    interface IRTCRoamingEvent
    {
        CONST_VTBL struct IRTCRoamingEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCRoamingEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCRoamingEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCRoamingEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCRoamingEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCRoamingEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCRoamingEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCRoamingEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCRoamingEvent_get_EventType(This,pEventType)	\
    (This)->lpVtbl -> get_EventType(This,pEventType)

#define IRTCRoamingEvent_get_Profile(This,ppProfile)	\
    (This)->lpVtbl -> get_Profile(This,ppProfile)

#define IRTCRoamingEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCRoamingEvent_get_StatusText(This,pbstrStatusText)	\
    (This)->lpVtbl -> get_StatusText(This,pbstrStatusText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCRoamingEvent_get_EventType_Proxy( 
    IRTCRoamingEvent * This,
    /* [retval][out] */ RTC_ROAMING_EVENT_TYPE *pEventType);


void __RPC_STUB IRTCRoamingEvent_get_EventType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCRoamingEvent_get_Profile_Proxy( 
    IRTCRoamingEvent * This,
    /* [retval][out] */ IRTCProfile2 **ppProfile);


void __RPC_STUB IRTCRoamingEvent_get_Profile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCRoamingEvent_get_StatusCode_Proxy( 
    IRTCRoamingEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCRoamingEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCRoamingEvent_get_StatusText_Proxy( 
    IRTCRoamingEvent * This,
    /* [retval][out] */ BSTR *pbstrStatusText);


void __RPC_STUB IRTCRoamingEvent_get_StatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCRoamingEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCProfileEvent_INTERFACE_DEFINED__
#define __IRTCProfileEvent_INTERFACE_DEFINED__

/* interface IRTCProfileEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCProfileEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D6D5AB3B-770E-43e8-800A-79B062395FCA")
    IRTCProfileEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [retval][out] */ IRTCProfile **ppProfile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cookie( 
            /* [retval][out] */ LONG_PTR *plCookie) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCProfileEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCProfileEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCProfileEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCProfileEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCProfileEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCProfileEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCProfileEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCProfileEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            IRTCProfileEvent * This,
            /* [retval][out] */ IRTCProfile **ppProfile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cookie )( 
            IRTCProfileEvent * This,
            /* [retval][out] */ LONG_PTR *plCookie);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCProfileEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        END_INTERFACE
    } IRTCProfileEventVtbl;

    interface IRTCProfileEvent
    {
        CONST_VTBL struct IRTCProfileEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCProfileEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCProfileEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCProfileEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCProfileEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCProfileEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCProfileEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCProfileEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCProfileEvent_get_Profile(This,ppProfile)	\
    (This)->lpVtbl -> get_Profile(This,ppProfile)

#define IRTCProfileEvent_get_Cookie(This,plCookie)	\
    (This)->lpVtbl -> get_Cookie(This,plCookie)

#define IRTCProfileEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfileEvent_get_Profile_Proxy( 
    IRTCProfileEvent * This,
    /* [retval][out] */ IRTCProfile **ppProfile);


void __RPC_STUB IRTCProfileEvent_get_Profile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfileEvent_get_Cookie_Proxy( 
    IRTCProfileEvent * This,
    /* [retval][out] */ LONG_PTR *plCookie);


void __RPC_STUB IRTCProfileEvent_get_Cookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfileEvent_get_StatusCode_Proxy( 
    IRTCProfileEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCProfileEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCProfileEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCProfileEvent2_INTERFACE_DEFINED__
#define __IRTCProfileEvent2_INTERFACE_DEFINED__

/* interface IRTCProfileEvent2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCProfileEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("62E56EDC-03FA-4121-94FB-23493FD0AE64")
    IRTCProfileEvent2 : public IRTCProfileEvent
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [retval][out] */ RTC_PROFILE_EVENT_TYPE *pEventType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCProfileEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCProfileEvent2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCProfileEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCProfileEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCProfileEvent2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCProfileEvent2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCProfileEvent2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCProfileEvent2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            IRTCProfileEvent2 * This,
            /* [retval][out] */ IRTCProfile **ppProfile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cookie )( 
            IRTCProfileEvent2 * This,
            /* [retval][out] */ LONG_PTR *plCookie);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCProfileEvent2 * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            IRTCProfileEvent2 * This,
            /* [retval][out] */ RTC_PROFILE_EVENT_TYPE *pEventType);
        
        END_INTERFACE
    } IRTCProfileEvent2Vtbl;

    interface IRTCProfileEvent2
    {
        CONST_VTBL struct IRTCProfileEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCProfileEvent2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCProfileEvent2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCProfileEvent2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCProfileEvent2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCProfileEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCProfileEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCProfileEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCProfileEvent2_get_Profile(This,ppProfile)	\
    (This)->lpVtbl -> get_Profile(This,ppProfile)

#define IRTCProfileEvent2_get_Cookie(This,plCookie)	\
    (This)->lpVtbl -> get_Cookie(This,plCookie)

#define IRTCProfileEvent2_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)


#define IRTCProfileEvent2_get_EventType(This,pEventType)	\
    (This)->lpVtbl -> get_EventType(This,pEventType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCProfileEvent2_get_EventType_Proxy( 
    IRTCProfileEvent2 * This,
    /* [retval][out] */ RTC_PROFILE_EVENT_TYPE *pEventType);


void __RPC_STUB IRTCProfileEvent2_get_EventType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCProfileEvent2_INTERFACE_DEFINED__ */


#ifndef __IRTCClientEvent_INTERFACE_DEFINED__
#define __IRTCClientEvent_INTERFACE_DEFINED__

/* interface IRTCClientEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2b493b7a-3cba-4170-9c8b-76a9dacdd644")
    IRTCClientEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [retval][out] */ RTC_CLIENT_EVENT_TYPE *penEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Client( 
            /* [retval][out] */ IRTCClient **ppClient) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCClientEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCClientEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCClientEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCClientEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCClientEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCClientEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCClientEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCClientEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            IRTCClientEvent * This,
            /* [retval][out] */ RTC_CLIENT_EVENT_TYPE *penEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Client )( 
            IRTCClientEvent * This,
            /* [retval][out] */ IRTCClient **ppClient);
        
        END_INTERFACE
    } IRTCClientEventVtbl;

    interface IRTCClientEvent
    {
        CONST_VTBL struct IRTCClientEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCClientEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCClientEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCClientEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCClientEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCClientEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCClientEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCClientEvent_get_EventType(This,penEventType)	\
    (This)->lpVtbl -> get_EventType(This,penEventType)

#define IRTCClientEvent_get_Client(This,ppClient)	\
    (This)->lpVtbl -> get_Client(This,ppClient)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientEvent_get_EventType_Proxy( 
    IRTCClientEvent * This,
    /* [retval][out] */ RTC_CLIENT_EVENT_TYPE *penEventType);


void __RPC_STUB IRTCClientEvent_get_EventType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCClientEvent_get_Client_Proxy( 
    IRTCClientEvent * This,
    /* [retval][out] */ IRTCClient **ppClient);


void __RPC_STUB IRTCClientEvent_get_Client_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCClientEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCRegistrationStateChangeEvent_INTERFACE_DEFINED__
#define __IRTCRegistrationStateChangeEvent_INTERFACE_DEFINED__

/* interface IRTCRegistrationStateChangeEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCRegistrationStateChangeEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("62d0991b-50ab-4f02-b948-ca94f26f8f95")
    IRTCRegistrationStateChangeEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [retval][out] */ IRTCProfile **ppProfile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ RTC_REGISTRATION_STATE *penState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [retval][out] */ BSTR *pbstrStatusText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCRegistrationStateChangeEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCRegistrationStateChangeEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCRegistrationStateChangeEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCRegistrationStateChangeEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCRegistrationStateChangeEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCRegistrationStateChangeEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCRegistrationStateChangeEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCRegistrationStateChangeEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            IRTCRegistrationStateChangeEvent * This,
            /* [retval][out] */ IRTCProfile **ppProfile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCRegistrationStateChangeEvent * This,
            /* [retval][out] */ RTC_REGISTRATION_STATE *penState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCRegistrationStateChangeEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            IRTCRegistrationStateChangeEvent * This,
            /* [retval][out] */ BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCRegistrationStateChangeEventVtbl;

    interface IRTCRegistrationStateChangeEvent
    {
        CONST_VTBL struct IRTCRegistrationStateChangeEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCRegistrationStateChangeEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCRegistrationStateChangeEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCRegistrationStateChangeEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCRegistrationStateChangeEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCRegistrationStateChangeEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCRegistrationStateChangeEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCRegistrationStateChangeEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCRegistrationStateChangeEvent_get_Profile(This,ppProfile)	\
    (This)->lpVtbl -> get_Profile(This,ppProfile)

#define IRTCRegistrationStateChangeEvent_get_State(This,penState)	\
    (This)->lpVtbl -> get_State(This,penState)

#define IRTCRegistrationStateChangeEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCRegistrationStateChangeEvent_get_StatusText(This,pbstrStatusText)	\
    (This)->lpVtbl -> get_StatusText(This,pbstrStatusText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCRegistrationStateChangeEvent_get_Profile_Proxy( 
    IRTCRegistrationStateChangeEvent * This,
    /* [retval][out] */ IRTCProfile **ppProfile);


void __RPC_STUB IRTCRegistrationStateChangeEvent_get_Profile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCRegistrationStateChangeEvent_get_State_Proxy( 
    IRTCRegistrationStateChangeEvent * This,
    /* [retval][out] */ RTC_REGISTRATION_STATE *penState);


void __RPC_STUB IRTCRegistrationStateChangeEvent_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCRegistrationStateChangeEvent_get_StatusCode_Proxy( 
    IRTCRegistrationStateChangeEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCRegistrationStateChangeEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCRegistrationStateChangeEvent_get_StatusText_Proxy( 
    IRTCRegistrationStateChangeEvent * This,
    /* [retval][out] */ BSTR *pbstrStatusText);


void __RPC_STUB IRTCRegistrationStateChangeEvent_get_StatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCRegistrationStateChangeEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent_INTERFACE_DEFINED__
#define __IRTCSessionStateChangeEvent_INTERFACE_DEFINED__

/* interface IRTCSessionStateChangeEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionStateChangeEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b5bad703-5952-48b3-9321-7f4500521506")
    IRTCSessionStateChangeEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [retval][out] */ IRTCSession **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ RTC_SESSION_STATE *penState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [retval][out] */ BSTR *pbstrStatusText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCSessionStateChangeEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCSessionStateChangeEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCSessionStateChangeEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCSessionStateChangeEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCSessionStateChangeEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCSessionStateChangeEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCSessionStateChangeEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionStateChangeEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            IRTCSessionStateChangeEvent * This,
            /* [retval][out] */ IRTCSession **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCSessionStateChangeEvent * This,
            /* [retval][out] */ RTC_SESSION_STATE *penState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCSessionStateChangeEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            IRTCSessionStateChangeEvent * This,
            /* [retval][out] */ BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCSessionStateChangeEventVtbl;

    interface IRTCSessionStateChangeEvent
    {
        CONST_VTBL struct IRTCSessionStateChangeEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionStateChangeEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCSessionStateChangeEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCSessionStateChangeEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCSessionStateChangeEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCSessionStateChangeEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCSessionStateChangeEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCSessionStateChangeEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCSessionStateChangeEvent_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)

#define IRTCSessionStateChangeEvent_get_State(This,penState)	\
    (This)->lpVtbl -> get_State(This,penState)

#define IRTCSessionStateChangeEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCSessionStateChangeEvent_get_StatusText(This,pbstrStatusText)	\
    (This)->lpVtbl -> get_StatusText(This,pbstrStatusText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionStateChangeEvent_get_Session_Proxy( 
    IRTCSessionStateChangeEvent * This,
    /* [retval][out] */ IRTCSession **ppSession);


void __RPC_STUB IRTCSessionStateChangeEvent_get_Session_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionStateChangeEvent_get_State_Proxy( 
    IRTCSessionStateChangeEvent * This,
    /* [retval][out] */ RTC_SESSION_STATE *penState);


void __RPC_STUB IRTCSessionStateChangeEvent_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionStateChangeEvent_get_StatusCode_Proxy( 
    IRTCSessionStateChangeEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCSessionStateChangeEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionStateChangeEvent_get_StatusText_Proxy( 
    IRTCSessionStateChangeEvent * This,
    /* [retval][out] */ BSTR *pbstrStatusText);


void __RPC_STUB IRTCSessionStateChangeEvent_get_StatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCSessionStateChangeEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent2_INTERFACE_DEFINED__
#define __IRTCSessionStateChangeEvent2_INTERFACE_DEFINED__

/* interface IRTCSessionStateChangeEvent2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionStateChangeEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F933171-6F95-4880-80D9-2EC8D495D261")
    IRTCSessionStateChangeEvent2 : public IRTCSessionStateChangeEvent
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MediaTypes( 
            /* [retval][out] */ long *pMediaTypes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemotePreferredSecurityLevel( 
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsForked( 
            /* [retval][out] */ VARIANT_BOOL *pfIsForked) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRemoteSessionDescription( 
            /* [out] */ BSTR *pbstrContentType,
            /* [out] */ BSTR *pbstrSessionDescription) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCSessionStateChangeEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCSessionStateChangeEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCSessionStateChangeEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [retval][out] */ IRTCSession **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [retval][out] */ RTC_SESSION_STATE *penState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [retval][out] */ BSTR *pbstrStatusText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MediaTypes )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [retval][out] */ long *pMediaTypes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemotePreferredSecurityLevel )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsForked )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [retval][out] */ VARIANT_BOOL *pfIsForked);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRemoteSessionDescription )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [out] */ BSTR *pbstrContentType,
            /* [out] */ BSTR *pbstrSessionDescription);
        
        END_INTERFACE
    } IRTCSessionStateChangeEvent2Vtbl;

    interface IRTCSessionStateChangeEvent2
    {
        CONST_VTBL struct IRTCSessionStateChangeEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionStateChangeEvent2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCSessionStateChangeEvent2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCSessionStateChangeEvent2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCSessionStateChangeEvent2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCSessionStateChangeEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCSessionStateChangeEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCSessionStateChangeEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCSessionStateChangeEvent2_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)

#define IRTCSessionStateChangeEvent2_get_State(This,penState)	\
    (This)->lpVtbl -> get_State(This,penState)

#define IRTCSessionStateChangeEvent2_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCSessionStateChangeEvent2_get_StatusText(This,pbstrStatusText)	\
    (This)->lpVtbl -> get_StatusText(This,pbstrStatusText)


#define IRTCSessionStateChangeEvent2_get_MediaTypes(This,pMediaTypes)	\
    (This)->lpVtbl -> get_MediaTypes(This,pMediaTypes)

#define IRTCSessionStateChangeEvent2_get_RemotePreferredSecurityLevel(This,enSecurityType,penSecurityLevel)	\
    (This)->lpVtbl -> get_RemotePreferredSecurityLevel(This,enSecurityType,penSecurityLevel)

#define IRTCSessionStateChangeEvent2_get_IsForked(This,pfIsForked)	\
    (This)->lpVtbl -> get_IsForked(This,pfIsForked)

#define IRTCSessionStateChangeEvent2_GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription)	\
    (This)->lpVtbl -> GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionStateChangeEvent2_get_MediaTypes_Proxy( 
    IRTCSessionStateChangeEvent2 * This,
    /* [retval][out] */ long *pMediaTypes);


void __RPC_STUB IRTCSessionStateChangeEvent2_get_MediaTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionStateChangeEvent2_get_RemotePreferredSecurityLevel_Proxy( 
    IRTCSessionStateChangeEvent2 * This,
    /* [in] */ RTC_SECURITY_TYPE enSecurityType,
    /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel);


void __RPC_STUB IRTCSessionStateChangeEvent2_get_RemotePreferredSecurityLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionStateChangeEvent2_get_IsForked_Proxy( 
    IRTCSessionStateChangeEvent2 * This,
    /* [retval][out] */ VARIANT_BOOL *pfIsForked);


void __RPC_STUB IRTCSessionStateChangeEvent2_get_IsForked_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCSessionStateChangeEvent2_GetRemoteSessionDescription_Proxy( 
    IRTCSessionStateChangeEvent2 * This,
    /* [out] */ BSTR *pbstrContentType,
    /* [out] */ BSTR *pbstrSessionDescription);


void __RPC_STUB IRTCSessionStateChangeEvent2_GetRemoteSessionDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCSessionStateChangeEvent2_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent_INTERFACE_DEFINED__
#define __IRTCSessionOperationCompleteEvent_INTERFACE_DEFINED__

/* interface IRTCSessionOperationCompleteEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionOperationCompleteEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a6bff4c0-f7c8-4d3c-9a41-3550f78a95b0")
    IRTCSessionOperationCompleteEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [retval][out] */ IRTCSession **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cookie( 
            /* [retval][out] */ LONG_PTR *plCookie) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [retval][out] */ BSTR *pbstrStatusText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCSessionOperationCompleteEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCSessionOperationCompleteEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCSessionOperationCompleteEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCSessionOperationCompleteEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCSessionOperationCompleteEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCSessionOperationCompleteEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCSessionOperationCompleteEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionOperationCompleteEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            IRTCSessionOperationCompleteEvent * This,
            /* [retval][out] */ IRTCSession **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cookie )( 
            IRTCSessionOperationCompleteEvent * This,
            /* [retval][out] */ LONG_PTR *plCookie);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCSessionOperationCompleteEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            IRTCSessionOperationCompleteEvent * This,
            /* [retval][out] */ BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCSessionOperationCompleteEventVtbl;

    interface IRTCSessionOperationCompleteEvent
    {
        CONST_VTBL struct IRTCSessionOperationCompleteEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionOperationCompleteEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCSessionOperationCompleteEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCSessionOperationCompleteEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCSessionOperationCompleteEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCSessionOperationCompleteEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCSessionOperationCompleteEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCSessionOperationCompleteEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCSessionOperationCompleteEvent_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)

#define IRTCSessionOperationCompleteEvent_get_Cookie(This,plCookie)	\
    (This)->lpVtbl -> get_Cookie(This,plCookie)

#define IRTCSessionOperationCompleteEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCSessionOperationCompleteEvent_get_StatusText(This,pbstrStatusText)	\
    (This)->lpVtbl -> get_StatusText(This,pbstrStatusText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionOperationCompleteEvent_get_Session_Proxy( 
    IRTCSessionOperationCompleteEvent * This,
    /* [retval][out] */ IRTCSession **ppSession);


void __RPC_STUB IRTCSessionOperationCompleteEvent_get_Session_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionOperationCompleteEvent_get_Cookie_Proxy( 
    IRTCSessionOperationCompleteEvent * This,
    /* [retval][out] */ LONG_PTR *plCookie);


void __RPC_STUB IRTCSessionOperationCompleteEvent_get_Cookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionOperationCompleteEvent_get_StatusCode_Proxy( 
    IRTCSessionOperationCompleteEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCSessionOperationCompleteEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionOperationCompleteEvent_get_StatusText_Proxy( 
    IRTCSessionOperationCompleteEvent * This,
    /* [retval][out] */ BSTR *pbstrStatusText);


void __RPC_STUB IRTCSessionOperationCompleteEvent_get_StatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCSessionOperationCompleteEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent2_INTERFACE_DEFINED__
#define __IRTCSessionOperationCompleteEvent2_INTERFACE_DEFINED__

/* interface IRTCSessionOperationCompleteEvent2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionOperationCompleteEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f6fc2a9b-d5bc-4241-b436-1b8460c13832")
    IRTCSessionOperationCompleteEvent2 : public IRTCSessionOperationCompleteEvent
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Participant( 
            /* [retval][out] */ IRTCParticipant **ppParticipant) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRemoteSessionDescription( 
            /* [out] */ BSTR *pbstrContentType,
            /* [out] */ BSTR *pbstrSessionDescription) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCSessionOperationCompleteEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCSessionOperationCompleteEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCSessionOperationCompleteEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [retval][out] */ IRTCSession **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cookie )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [retval][out] */ LONG_PTR *plCookie);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [retval][out] */ BSTR *pbstrStatusText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participant )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [retval][out] */ IRTCParticipant **ppParticipant);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRemoteSessionDescription )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [out] */ BSTR *pbstrContentType,
            /* [out] */ BSTR *pbstrSessionDescription);
        
        END_INTERFACE
    } IRTCSessionOperationCompleteEvent2Vtbl;

    interface IRTCSessionOperationCompleteEvent2
    {
        CONST_VTBL struct IRTCSessionOperationCompleteEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionOperationCompleteEvent2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCSessionOperationCompleteEvent2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCSessionOperationCompleteEvent2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCSessionOperationCompleteEvent2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCSessionOperationCompleteEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCSessionOperationCompleteEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCSessionOperationCompleteEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCSessionOperationCompleteEvent2_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)

#define IRTCSessionOperationCompleteEvent2_get_Cookie(This,plCookie)	\
    (This)->lpVtbl -> get_Cookie(This,plCookie)

#define IRTCSessionOperationCompleteEvent2_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCSessionOperationCompleteEvent2_get_StatusText(This,pbstrStatusText)	\
    (This)->lpVtbl -> get_StatusText(This,pbstrStatusText)


#define IRTCSessionOperationCompleteEvent2_get_Participant(This,ppParticipant)	\
    (This)->lpVtbl -> get_Participant(This,ppParticipant)

#define IRTCSessionOperationCompleteEvent2_GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription)	\
    (This)->lpVtbl -> GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionOperationCompleteEvent2_get_Participant_Proxy( 
    IRTCSessionOperationCompleteEvent2 * This,
    /* [retval][out] */ IRTCParticipant **ppParticipant);


void __RPC_STUB IRTCSessionOperationCompleteEvent2_get_Participant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCSessionOperationCompleteEvent2_GetRemoteSessionDescription_Proxy( 
    IRTCSessionOperationCompleteEvent2 * This,
    /* [out] */ BSTR *pbstrContentType,
    /* [out] */ BSTR *pbstrSessionDescription);


void __RPC_STUB IRTCSessionOperationCompleteEvent2_GetRemoteSessionDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCSessionOperationCompleteEvent2_INTERFACE_DEFINED__ */


#ifndef __IRTCParticipantStateChangeEvent_INTERFACE_DEFINED__
#define __IRTCParticipantStateChangeEvent_INTERFACE_DEFINED__

/* interface IRTCParticipantStateChangeEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCParticipantStateChangeEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("09bcb597-f0fa-48f9-b420-468cea7fde04")
    IRTCParticipantStateChangeEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Participant( 
            /* [retval][out] */ IRTCParticipant **ppParticipant) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ RTC_PARTICIPANT_STATE *penState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCParticipantStateChangeEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCParticipantStateChangeEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCParticipantStateChangeEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCParticipantStateChangeEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCParticipantStateChangeEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCParticipantStateChangeEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCParticipantStateChangeEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCParticipantStateChangeEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participant )( 
            IRTCParticipantStateChangeEvent * This,
            /* [retval][out] */ IRTCParticipant **ppParticipant);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCParticipantStateChangeEvent * This,
            /* [retval][out] */ RTC_PARTICIPANT_STATE *penState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCParticipantStateChangeEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        END_INTERFACE
    } IRTCParticipantStateChangeEventVtbl;

    interface IRTCParticipantStateChangeEvent
    {
        CONST_VTBL struct IRTCParticipantStateChangeEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCParticipantStateChangeEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCParticipantStateChangeEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCParticipantStateChangeEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCParticipantStateChangeEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCParticipantStateChangeEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCParticipantStateChangeEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCParticipantStateChangeEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCParticipantStateChangeEvent_get_Participant(This,ppParticipant)	\
    (This)->lpVtbl -> get_Participant(This,ppParticipant)

#define IRTCParticipantStateChangeEvent_get_State(This,penState)	\
    (This)->lpVtbl -> get_State(This,penState)

#define IRTCParticipantStateChangeEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCParticipantStateChangeEvent_get_Participant_Proxy( 
    IRTCParticipantStateChangeEvent * This,
    /* [retval][out] */ IRTCParticipant **ppParticipant);


void __RPC_STUB IRTCParticipantStateChangeEvent_get_Participant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCParticipantStateChangeEvent_get_State_Proxy( 
    IRTCParticipantStateChangeEvent * This,
    /* [retval][out] */ RTC_PARTICIPANT_STATE *penState);


void __RPC_STUB IRTCParticipantStateChangeEvent_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCParticipantStateChangeEvent_get_StatusCode_Proxy( 
    IRTCParticipantStateChangeEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCParticipantStateChangeEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCParticipantStateChangeEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCMediaEvent_INTERFACE_DEFINED__
#define __IRTCMediaEvent_INTERFACE_DEFINED__

/* interface IRTCMediaEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCMediaEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("099944fb-bcda-453e-8c41-e13da2adf7f3")
    IRTCMediaEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MediaType( 
            /* [retval][out] */ long *pMediaType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [retval][out] */ RTC_MEDIA_EVENT_TYPE *penEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventReason( 
            /* [retval][out] */ RTC_MEDIA_EVENT_REASON *penEventReason) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCMediaEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCMediaEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCMediaEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCMediaEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCMediaEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCMediaEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCMediaEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCMediaEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MediaType )( 
            IRTCMediaEvent * This,
            /* [retval][out] */ long *pMediaType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            IRTCMediaEvent * This,
            /* [retval][out] */ RTC_MEDIA_EVENT_TYPE *penEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventReason )( 
            IRTCMediaEvent * This,
            /* [retval][out] */ RTC_MEDIA_EVENT_REASON *penEventReason);
        
        END_INTERFACE
    } IRTCMediaEventVtbl;

    interface IRTCMediaEvent
    {
        CONST_VTBL struct IRTCMediaEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCMediaEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCMediaEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCMediaEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCMediaEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCMediaEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCMediaEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCMediaEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCMediaEvent_get_MediaType(This,pMediaType)	\
    (This)->lpVtbl -> get_MediaType(This,pMediaType)

#define IRTCMediaEvent_get_EventType(This,penEventType)	\
    (This)->lpVtbl -> get_EventType(This,penEventType)

#define IRTCMediaEvent_get_EventReason(This,penEventReason)	\
    (This)->lpVtbl -> get_EventReason(This,penEventReason)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMediaEvent_get_MediaType_Proxy( 
    IRTCMediaEvent * This,
    /* [retval][out] */ long *pMediaType);


void __RPC_STUB IRTCMediaEvent_get_MediaType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMediaEvent_get_EventType_Proxy( 
    IRTCMediaEvent * This,
    /* [retval][out] */ RTC_MEDIA_EVENT_TYPE *penEventType);


void __RPC_STUB IRTCMediaEvent_get_EventType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMediaEvent_get_EventReason_Proxy( 
    IRTCMediaEvent * This,
    /* [retval][out] */ RTC_MEDIA_EVENT_REASON *penEventReason);


void __RPC_STUB IRTCMediaEvent_get_EventReason_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCMediaEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCIntensityEvent_INTERFACE_DEFINED__
#define __IRTCIntensityEvent_INTERFACE_DEFINED__

/* interface IRTCIntensityEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCIntensityEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4c23bf51-390c-4992-a41d-41eec05b2a4b")
    IRTCIntensityEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Level( 
            /* [retval][out] */ long *plLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Min( 
            /* [retval][out] */ long *plMin) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Max( 
            /* [retval][out] */ long *plMax) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Direction( 
            /* [retval][out] */ RTC_AUDIO_DEVICE *penDirection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCIntensityEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCIntensityEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCIntensityEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCIntensityEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCIntensityEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCIntensityEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCIntensityEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCIntensityEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Level )( 
            IRTCIntensityEvent * This,
            /* [retval][out] */ long *plLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Min )( 
            IRTCIntensityEvent * This,
            /* [retval][out] */ long *plMin);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Max )( 
            IRTCIntensityEvent * This,
            /* [retval][out] */ long *plMax);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Direction )( 
            IRTCIntensityEvent * This,
            /* [retval][out] */ RTC_AUDIO_DEVICE *penDirection);
        
        END_INTERFACE
    } IRTCIntensityEventVtbl;

    interface IRTCIntensityEvent
    {
        CONST_VTBL struct IRTCIntensityEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCIntensityEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCIntensityEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCIntensityEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCIntensityEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCIntensityEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCIntensityEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCIntensityEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCIntensityEvent_get_Level(This,plLevel)	\
    (This)->lpVtbl -> get_Level(This,plLevel)

#define IRTCIntensityEvent_get_Min(This,plMin)	\
    (This)->lpVtbl -> get_Min(This,plMin)

#define IRTCIntensityEvent_get_Max(This,plMax)	\
    (This)->lpVtbl -> get_Max(This,plMax)

#define IRTCIntensityEvent_get_Direction(This,penDirection)	\
    (This)->lpVtbl -> get_Direction(This,penDirection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCIntensityEvent_get_Level_Proxy( 
    IRTCIntensityEvent * This,
    /* [retval][out] */ long *plLevel);


void __RPC_STUB IRTCIntensityEvent_get_Level_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCIntensityEvent_get_Min_Proxy( 
    IRTCIntensityEvent * This,
    /* [retval][out] */ long *plMin);


void __RPC_STUB IRTCIntensityEvent_get_Min_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCIntensityEvent_get_Max_Proxy( 
    IRTCIntensityEvent * This,
    /* [retval][out] */ long *plMax);


void __RPC_STUB IRTCIntensityEvent_get_Max_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCIntensityEvent_get_Direction_Proxy( 
    IRTCIntensityEvent * This,
    /* [retval][out] */ RTC_AUDIO_DEVICE *penDirection);


void __RPC_STUB IRTCIntensityEvent_get_Direction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCIntensityEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCMessagingEvent_INTERFACE_DEFINED__
#define __IRTCMessagingEvent_INTERFACE_DEFINED__

/* interface IRTCMessagingEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCMessagingEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d3609541-1b29-4de5-a4ad-5aebaf319512")
    IRTCMessagingEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [retval][out] */ IRTCSession **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Participant( 
            /* [retval][out] */ IRTCParticipant **ppParticipant) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [retval][out] */ RTC_MESSAGING_EVENT_TYPE *penEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Message( 
            /* [retval][out] */ BSTR *pbstrMessage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MessageHeader( 
            /* [retval][out] */ BSTR *pbstrMessageHeader) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserStatus( 
            /* [retval][out] */ RTC_MESSAGING_USER_STATUS *penUserStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCMessagingEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCMessagingEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCMessagingEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCMessagingEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCMessagingEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCMessagingEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCMessagingEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCMessagingEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            IRTCMessagingEvent * This,
            /* [retval][out] */ IRTCSession **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participant )( 
            IRTCMessagingEvent * This,
            /* [retval][out] */ IRTCParticipant **ppParticipant);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            IRTCMessagingEvent * This,
            /* [retval][out] */ RTC_MESSAGING_EVENT_TYPE *penEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Message )( 
            IRTCMessagingEvent * This,
            /* [retval][out] */ BSTR *pbstrMessage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MessageHeader )( 
            IRTCMessagingEvent * This,
            /* [retval][out] */ BSTR *pbstrMessageHeader);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserStatus )( 
            IRTCMessagingEvent * This,
            /* [retval][out] */ RTC_MESSAGING_USER_STATUS *penUserStatus);
        
        END_INTERFACE
    } IRTCMessagingEventVtbl;

    interface IRTCMessagingEvent
    {
        CONST_VTBL struct IRTCMessagingEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCMessagingEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCMessagingEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCMessagingEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCMessagingEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCMessagingEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCMessagingEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCMessagingEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCMessagingEvent_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)

#define IRTCMessagingEvent_get_Participant(This,ppParticipant)	\
    (This)->lpVtbl -> get_Participant(This,ppParticipant)

#define IRTCMessagingEvent_get_EventType(This,penEventType)	\
    (This)->lpVtbl -> get_EventType(This,penEventType)

#define IRTCMessagingEvent_get_Message(This,pbstrMessage)	\
    (This)->lpVtbl -> get_Message(This,pbstrMessage)

#define IRTCMessagingEvent_get_MessageHeader(This,pbstrMessageHeader)	\
    (This)->lpVtbl -> get_MessageHeader(This,pbstrMessageHeader)

#define IRTCMessagingEvent_get_UserStatus(This,penUserStatus)	\
    (This)->lpVtbl -> get_UserStatus(This,penUserStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMessagingEvent_get_Session_Proxy( 
    IRTCMessagingEvent * This,
    /* [retval][out] */ IRTCSession **ppSession);


void __RPC_STUB IRTCMessagingEvent_get_Session_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMessagingEvent_get_Participant_Proxy( 
    IRTCMessagingEvent * This,
    /* [retval][out] */ IRTCParticipant **ppParticipant);


void __RPC_STUB IRTCMessagingEvent_get_Participant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMessagingEvent_get_EventType_Proxy( 
    IRTCMessagingEvent * This,
    /* [retval][out] */ RTC_MESSAGING_EVENT_TYPE *penEventType);


void __RPC_STUB IRTCMessagingEvent_get_EventType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMessagingEvent_get_Message_Proxy( 
    IRTCMessagingEvent * This,
    /* [retval][out] */ BSTR *pbstrMessage);


void __RPC_STUB IRTCMessagingEvent_get_Message_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMessagingEvent_get_MessageHeader_Proxy( 
    IRTCMessagingEvent * This,
    /* [retval][out] */ BSTR *pbstrMessageHeader);


void __RPC_STUB IRTCMessagingEvent_get_MessageHeader_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMessagingEvent_get_UserStatus_Proxy( 
    IRTCMessagingEvent * This,
    /* [retval][out] */ RTC_MESSAGING_USER_STATUS *penUserStatus);


void __RPC_STUB IRTCMessagingEvent_get_UserStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCMessagingEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddyEvent_INTERFACE_DEFINED__
#define __IRTCBuddyEvent_INTERFACE_DEFINED__

/* interface IRTCBuddyEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddyEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f36d755d-17e6-404e-954f-0fc07574c78d")
    IRTCBuddyEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Buddy( 
            /* [retval][out] */ IRTCBuddy **ppBuddy) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCBuddyEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCBuddyEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCBuddyEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCBuddyEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCBuddyEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCBuddyEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCBuddyEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCBuddyEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddy )( 
            IRTCBuddyEvent * This,
            /* [retval][out] */ IRTCBuddy **ppBuddy);
        
        END_INTERFACE
    } IRTCBuddyEventVtbl;

    interface IRTCBuddyEvent
    {
        CONST_VTBL struct IRTCBuddyEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddyEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCBuddyEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCBuddyEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCBuddyEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCBuddyEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCBuddyEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCBuddyEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCBuddyEvent_get_Buddy(This,ppBuddy)	\
    (This)->lpVtbl -> get_Buddy(This,ppBuddy)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyEvent_get_Buddy_Proxy( 
    IRTCBuddyEvent * This,
    /* [retval][out] */ IRTCBuddy **ppBuddy);


void __RPC_STUB IRTCBuddyEvent_get_Buddy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCBuddyEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddyEvent2_INTERFACE_DEFINED__
#define __IRTCBuddyEvent2_INTERFACE_DEFINED__

/* interface IRTCBuddyEvent2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddyEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("484A7F1E-73F0-4990-BFC2-60BC3978A720")
    IRTCBuddyEvent2 : public IRTCBuddyEvent
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [retval][out] */ RTC_BUDDY_EVENT_TYPE *pEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [retval][out] */ BSTR *pbstrStatusText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCBuddyEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCBuddyEvent2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCBuddyEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCBuddyEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCBuddyEvent2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCBuddyEvent2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCBuddyEvent2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCBuddyEvent2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddy )( 
            IRTCBuddyEvent2 * This,
            /* [retval][out] */ IRTCBuddy **ppBuddy);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            IRTCBuddyEvent2 * This,
            /* [retval][out] */ RTC_BUDDY_EVENT_TYPE *pEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCBuddyEvent2 * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            IRTCBuddyEvent2 * This,
            /* [retval][out] */ BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCBuddyEvent2Vtbl;

    interface IRTCBuddyEvent2
    {
        CONST_VTBL struct IRTCBuddyEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddyEvent2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCBuddyEvent2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCBuddyEvent2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCBuddyEvent2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCBuddyEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCBuddyEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCBuddyEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCBuddyEvent2_get_Buddy(This,ppBuddy)	\
    (This)->lpVtbl -> get_Buddy(This,ppBuddy)


#define IRTCBuddyEvent2_get_EventType(This,pEventType)	\
    (This)->lpVtbl -> get_EventType(This,pEventType)

#define IRTCBuddyEvent2_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCBuddyEvent2_get_StatusText(This,pbstrStatusText)	\
    (This)->lpVtbl -> get_StatusText(This,pbstrStatusText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyEvent2_get_EventType_Proxy( 
    IRTCBuddyEvent2 * This,
    /* [retval][out] */ RTC_BUDDY_EVENT_TYPE *pEventType);


void __RPC_STUB IRTCBuddyEvent2_get_EventType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyEvent2_get_StatusCode_Proxy( 
    IRTCBuddyEvent2 * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCBuddyEvent2_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyEvent2_get_StatusText_Proxy( 
    IRTCBuddyEvent2 * This,
    /* [retval][out] */ BSTR *pbstrStatusText);


void __RPC_STUB IRTCBuddyEvent2_get_StatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCBuddyEvent2_INTERFACE_DEFINED__ */


#ifndef __IRTCWatcherEvent_INTERFACE_DEFINED__
#define __IRTCWatcherEvent_INTERFACE_DEFINED__

/* interface IRTCWatcherEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCWatcherEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f30d7261-587a-424f-822c-312788f43548")
    IRTCWatcherEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Watcher( 
            /* [retval][out] */ IRTCWatcher **ppWatcher) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCWatcherEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCWatcherEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCWatcherEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCWatcherEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCWatcherEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCWatcherEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCWatcherEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCWatcherEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watcher )( 
            IRTCWatcherEvent * This,
            /* [retval][out] */ IRTCWatcher **ppWatcher);
        
        END_INTERFACE
    } IRTCWatcherEventVtbl;

    interface IRTCWatcherEvent
    {
        CONST_VTBL struct IRTCWatcherEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCWatcherEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCWatcherEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCWatcherEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCWatcherEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCWatcherEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCWatcherEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCWatcherEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCWatcherEvent_get_Watcher(This,ppWatcher)	\
    (This)->lpVtbl -> get_Watcher(This,ppWatcher)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCWatcherEvent_get_Watcher_Proxy( 
    IRTCWatcherEvent * This,
    /* [retval][out] */ IRTCWatcher **ppWatcher);


void __RPC_STUB IRTCWatcherEvent_get_Watcher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCWatcherEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCWatcherEvent2_INTERFACE_DEFINED__
#define __IRTCWatcherEvent2_INTERFACE_DEFINED__

/* interface IRTCWatcherEvent2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCWatcherEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E52891E8-188C-49AF-B005-98ED13F83F9C")
    IRTCWatcherEvent2 : public IRTCWatcherEvent
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [retval][out] */ RTC_WATCHER_EVENT_TYPE *pEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCWatcherEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCWatcherEvent2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCWatcherEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCWatcherEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCWatcherEvent2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCWatcherEvent2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCWatcherEvent2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCWatcherEvent2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watcher )( 
            IRTCWatcherEvent2 * This,
            /* [retval][out] */ IRTCWatcher **ppWatcher);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            IRTCWatcherEvent2 * This,
            /* [retval][out] */ RTC_WATCHER_EVENT_TYPE *pEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCWatcherEvent2 * This,
            /* [retval][out] */ long *plStatusCode);
        
        END_INTERFACE
    } IRTCWatcherEvent2Vtbl;

    interface IRTCWatcherEvent2
    {
        CONST_VTBL struct IRTCWatcherEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCWatcherEvent2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCWatcherEvent2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCWatcherEvent2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCWatcherEvent2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCWatcherEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCWatcherEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCWatcherEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCWatcherEvent2_get_Watcher(This,ppWatcher)	\
    (This)->lpVtbl -> get_Watcher(This,ppWatcher)


#define IRTCWatcherEvent2_get_EventType(This,pEventType)	\
    (This)->lpVtbl -> get_EventType(This,pEventType)

#define IRTCWatcherEvent2_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCWatcherEvent2_get_EventType_Proxy( 
    IRTCWatcherEvent2 * This,
    /* [retval][out] */ RTC_WATCHER_EVENT_TYPE *pEventType);


void __RPC_STUB IRTCWatcherEvent2_get_EventType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCWatcherEvent2_get_StatusCode_Proxy( 
    IRTCWatcherEvent2 * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCWatcherEvent2_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCWatcherEvent2_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddyGroupEvent_INTERFACE_DEFINED__
#define __IRTCBuddyGroupEvent_INTERFACE_DEFINED__

/* interface IRTCBuddyGroupEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddyGroupEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3A79E1D1-B736-4414-96F8-BBC7F08863E4")
    IRTCBuddyGroupEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [retval][out] */ RTC_GROUP_EVENT_TYPE *pEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Group( 
            /* [retval][out] */ IRTCBuddyGroup **ppGroup) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Buddy( 
            /* [retval][out] */ IRTCBuddy2 **ppBuddy) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCBuddyGroupEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCBuddyGroupEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCBuddyGroupEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCBuddyGroupEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCBuddyGroupEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCBuddyGroupEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCBuddyGroupEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCBuddyGroupEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            IRTCBuddyGroupEvent * This,
            /* [retval][out] */ RTC_GROUP_EVENT_TYPE *pEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Group )( 
            IRTCBuddyGroupEvent * This,
            /* [retval][out] */ IRTCBuddyGroup **ppGroup);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddy )( 
            IRTCBuddyGroupEvent * This,
            /* [retval][out] */ IRTCBuddy2 **ppBuddy);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCBuddyGroupEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        END_INTERFACE
    } IRTCBuddyGroupEventVtbl;

    interface IRTCBuddyGroupEvent
    {
        CONST_VTBL struct IRTCBuddyGroupEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddyGroupEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCBuddyGroupEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCBuddyGroupEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCBuddyGroupEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCBuddyGroupEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCBuddyGroupEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCBuddyGroupEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCBuddyGroupEvent_get_EventType(This,pEventType)	\
    (This)->lpVtbl -> get_EventType(This,pEventType)

#define IRTCBuddyGroupEvent_get_Group(This,ppGroup)	\
    (This)->lpVtbl -> get_Group(This,ppGroup)

#define IRTCBuddyGroupEvent_get_Buddy(This,ppBuddy)	\
    (This)->lpVtbl -> get_Buddy(This,ppBuddy)

#define IRTCBuddyGroupEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroupEvent_get_EventType_Proxy( 
    IRTCBuddyGroupEvent * This,
    /* [retval][out] */ RTC_GROUP_EVENT_TYPE *pEventType);


void __RPC_STUB IRTCBuddyGroupEvent_get_EventType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroupEvent_get_Group_Proxy( 
    IRTCBuddyGroupEvent * This,
    /* [retval][out] */ IRTCBuddyGroup **ppGroup);


void __RPC_STUB IRTCBuddyGroupEvent_get_Group_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroupEvent_get_Buddy_Proxy( 
    IRTCBuddyGroupEvent * This,
    /* [retval][out] */ IRTCBuddy2 **ppBuddy);


void __RPC_STUB IRTCBuddyGroupEvent_get_Buddy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroupEvent_get_StatusCode_Proxy( 
    IRTCBuddyGroupEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCBuddyGroupEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCBuddyGroupEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCInfoEvent_INTERFACE_DEFINED__
#define __IRTCInfoEvent_INTERFACE_DEFINED__

/* interface IRTCInfoEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCInfoEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4E1D68AE-1912-4f49-B2C3-594FADFD425F")
    IRTCInfoEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [retval][out] */ IRTCSession2 **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Participant( 
            /* [retval][out] */ IRTCParticipant **ppParticipant) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Info( 
            /* [retval][out] */ BSTR *pbstrInfo) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfoHeader( 
            /* [retval][out] */ BSTR *pbstrInfoHeader) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCInfoEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCInfoEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCInfoEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCInfoEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCInfoEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCInfoEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCInfoEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCInfoEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            IRTCInfoEvent * This,
            /* [retval][out] */ IRTCSession2 **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participant )( 
            IRTCInfoEvent * This,
            /* [retval][out] */ IRTCParticipant **ppParticipant);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Info )( 
            IRTCInfoEvent * This,
            /* [retval][out] */ BSTR *pbstrInfo);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InfoHeader )( 
            IRTCInfoEvent * This,
            /* [retval][out] */ BSTR *pbstrInfoHeader);
        
        END_INTERFACE
    } IRTCInfoEventVtbl;

    interface IRTCInfoEvent
    {
        CONST_VTBL struct IRTCInfoEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCInfoEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCInfoEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCInfoEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCInfoEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCInfoEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCInfoEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCInfoEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCInfoEvent_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)

#define IRTCInfoEvent_get_Participant(This,ppParticipant)	\
    (This)->lpVtbl -> get_Participant(This,ppParticipant)

#define IRTCInfoEvent_get_Info(This,pbstrInfo)	\
    (This)->lpVtbl -> get_Info(This,pbstrInfo)

#define IRTCInfoEvent_get_InfoHeader(This,pbstrInfoHeader)	\
    (This)->lpVtbl -> get_InfoHeader(This,pbstrInfoHeader)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCInfoEvent_get_Session_Proxy( 
    IRTCInfoEvent * This,
    /* [retval][out] */ IRTCSession2 **ppSession);


void __RPC_STUB IRTCInfoEvent_get_Session_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCInfoEvent_get_Participant_Proxy( 
    IRTCInfoEvent * This,
    /* [retval][out] */ IRTCParticipant **ppParticipant);


void __RPC_STUB IRTCInfoEvent_get_Participant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCInfoEvent_get_Info_Proxy( 
    IRTCInfoEvent * This,
    /* [retval][out] */ BSTR *pbstrInfo);


void __RPC_STUB IRTCInfoEvent_get_Info_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCInfoEvent_get_InfoHeader_Proxy( 
    IRTCInfoEvent * This,
    /* [retval][out] */ BSTR *pbstrInfoHeader);


void __RPC_STUB IRTCInfoEvent_get_InfoHeader_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCInfoEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCMediaRequestEvent_INTERFACE_DEFINED__
#define __IRTCMediaRequestEvent_INTERFACE_DEFINED__

/* interface IRTCMediaRequestEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCMediaRequestEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52572D15-148C-4d97-A36C-2DA55C289D63")
    IRTCMediaRequestEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [retval][out] */ IRTCSession2 **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProposedMedia( 
            /* [retval][out] */ long *plMediaTypes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentMedia( 
            /* [retval][out] */ long *plMediaTypes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Accept( 
            /* [in] */ long lMediaTypes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemotePreferredSecurityLevel( 
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reject( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ RTC_REINVITE_STATE *pState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCMediaRequestEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCMediaRequestEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCMediaRequestEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCMediaRequestEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCMediaRequestEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCMediaRequestEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCMediaRequestEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCMediaRequestEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            IRTCMediaRequestEvent * This,
            /* [retval][out] */ IRTCSession2 **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProposedMedia )( 
            IRTCMediaRequestEvent * This,
            /* [retval][out] */ long *plMediaTypes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentMedia )( 
            IRTCMediaRequestEvent * This,
            /* [retval][out] */ long *plMediaTypes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Accept )( 
            IRTCMediaRequestEvent * This,
            /* [in] */ long lMediaTypes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemotePreferredSecurityLevel )( 
            IRTCMediaRequestEvent * This,
            /* [in] */ RTC_SECURITY_TYPE enSecurityType,
            /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reject )( 
            IRTCMediaRequestEvent * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCMediaRequestEvent * This,
            /* [retval][out] */ RTC_REINVITE_STATE *pState);
        
        END_INTERFACE
    } IRTCMediaRequestEventVtbl;

    interface IRTCMediaRequestEvent
    {
        CONST_VTBL struct IRTCMediaRequestEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCMediaRequestEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCMediaRequestEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCMediaRequestEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCMediaRequestEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCMediaRequestEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCMediaRequestEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCMediaRequestEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCMediaRequestEvent_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)

#define IRTCMediaRequestEvent_get_ProposedMedia(This,plMediaTypes)	\
    (This)->lpVtbl -> get_ProposedMedia(This,plMediaTypes)

#define IRTCMediaRequestEvent_get_CurrentMedia(This,plMediaTypes)	\
    (This)->lpVtbl -> get_CurrentMedia(This,plMediaTypes)

#define IRTCMediaRequestEvent_Accept(This,lMediaTypes)	\
    (This)->lpVtbl -> Accept(This,lMediaTypes)

#define IRTCMediaRequestEvent_get_RemotePreferredSecurityLevel(This,enSecurityType,penSecurityLevel)	\
    (This)->lpVtbl -> get_RemotePreferredSecurityLevel(This,enSecurityType,penSecurityLevel)

#define IRTCMediaRequestEvent_Reject(This)	\
    (This)->lpVtbl -> Reject(This)

#define IRTCMediaRequestEvent_get_State(This,pState)	\
    (This)->lpVtbl -> get_State(This,pState)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMediaRequestEvent_get_Session_Proxy( 
    IRTCMediaRequestEvent * This,
    /* [retval][out] */ IRTCSession2 **ppSession);


void __RPC_STUB IRTCMediaRequestEvent_get_Session_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMediaRequestEvent_get_ProposedMedia_Proxy( 
    IRTCMediaRequestEvent * This,
    /* [retval][out] */ long *plMediaTypes);


void __RPC_STUB IRTCMediaRequestEvent_get_ProposedMedia_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMediaRequestEvent_get_CurrentMedia_Proxy( 
    IRTCMediaRequestEvent * This,
    /* [retval][out] */ long *plMediaTypes);


void __RPC_STUB IRTCMediaRequestEvent_get_CurrentMedia_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCMediaRequestEvent_Accept_Proxy( 
    IRTCMediaRequestEvent * This,
    /* [in] */ long lMediaTypes);


void __RPC_STUB IRTCMediaRequestEvent_Accept_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMediaRequestEvent_get_RemotePreferredSecurityLevel_Proxy( 
    IRTCMediaRequestEvent * This,
    /* [in] */ RTC_SECURITY_TYPE enSecurityType,
    /* [retval][out] */ RTC_SECURITY_LEVEL *penSecurityLevel);


void __RPC_STUB IRTCMediaRequestEvent_get_RemotePreferredSecurityLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCMediaRequestEvent_Reject_Proxy( 
    IRTCMediaRequestEvent * This);


void __RPC_STUB IRTCMediaRequestEvent_Reject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCMediaRequestEvent_get_State_Proxy( 
    IRTCMediaRequestEvent * This,
    /* [retval][out] */ RTC_REINVITE_STATE *pState);


void __RPC_STUB IRTCMediaRequestEvent_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCMediaRequestEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCReInviteEvent_INTERFACE_DEFINED__
#define __IRTCReInviteEvent_INTERFACE_DEFINED__

/* interface IRTCReInviteEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCReInviteEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11558D84-204C-43e7-99B0-2034E9417F7D")
    IRTCReInviteEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [retval][out] */ IRTCSession2 **ppSession2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Accept( 
            /* [in] */ BSTR bstrContentType,
            /* [in] */ BSTR bstrSessionDescription) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reject( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ RTC_REINVITE_STATE *pState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRemoteSessionDescription( 
            /* [out] */ BSTR *pbstrContentType,
            /* [out] */ BSTR *pbstrSessionDescription) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCReInviteEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCReInviteEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCReInviteEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCReInviteEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCReInviteEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCReInviteEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCReInviteEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCReInviteEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            IRTCReInviteEvent * This,
            /* [retval][out] */ IRTCSession2 **ppSession2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Accept )( 
            IRTCReInviteEvent * This,
            /* [in] */ BSTR bstrContentType,
            /* [in] */ BSTR bstrSessionDescription);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reject )( 
            IRTCReInviteEvent * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCReInviteEvent * This,
            /* [retval][out] */ RTC_REINVITE_STATE *pState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRemoteSessionDescription )( 
            IRTCReInviteEvent * This,
            /* [out] */ BSTR *pbstrContentType,
            /* [out] */ BSTR *pbstrSessionDescription);
        
        END_INTERFACE
    } IRTCReInviteEventVtbl;

    interface IRTCReInviteEvent
    {
        CONST_VTBL struct IRTCReInviteEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCReInviteEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCReInviteEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCReInviteEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCReInviteEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCReInviteEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCReInviteEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCReInviteEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCReInviteEvent_get_Session(This,ppSession2)	\
    (This)->lpVtbl -> get_Session(This,ppSession2)

#define IRTCReInviteEvent_Accept(This,bstrContentType,bstrSessionDescription)	\
    (This)->lpVtbl -> Accept(This,bstrContentType,bstrSessionDescription)

#define IRTCReInviteEvent_Reject(This)	\
    (This)->lpVtbl -> Reject(This)

#define IRTCReInviteEvent_get_State(This,pState)	\
    (This)->lpVtbl -> get_State(This,pState)

#define IRTCReInviteEvent_GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription)	\
    (This)->lpVtbl -> GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCReInviteEvent_get_Session_Proxy( 
    IRTCReInviteEvent * This,
    /* [retval][out] */ IRTCSession2 **ppSession2);


void __RPC_STUB IRTCReInviteEvent_get_Session_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCReInviteEvent_Accept_Proxy( 
    IRTCReInviteEvent * This,
    /* [in] */ BSTR bstrContentType,
    /* [in] */ BSTR bstrSessionDescription);


void __RPC_STUB IRTCReInviteEvent_Accept_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCReInviteEvent_Reject_Proxy( 
    IRTCReInviteEvent * This);


void __RPC_STUB IRTCReInviteEvent_Reject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCReInviteEvent_get_State_Proxy( 
    IRTCReInviteEvent * This,
    /* [retval][out] */ RTC_REINVITE_STATE *pState);


void __RPC_STUB IRTCReInviteEvent_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCReInviteEvent_GetRemoteSessionDescription_Proxy( 
    IRTCReInviteEvent * This,
    /* [out] */ BSTR *pbstrContentType,
    /* [out] */ BSTR *pbstrSessionDescription);


void __RPC_STUB IRTCReInviteEvent_GetRemoteSessionDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCReInviteEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCPresencePropertyEvent_INTERFACE_DEFINED__
#define __IRTCPresencePropertyEvent_INTERFACE_DEFINED__

/* interface IRTCPresencePropertyEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCPresencePropertyEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F777F570-A820-49d5-86BD-E099493F1518")
    IRTCPresencePropertyEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [retval][out] */ BSTR *pbstrStatusText) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PresenceProperty( 
            /* [retval][out] */ RTC_PRESENCE_PROPERTY *penPresProp) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ BSTR *pbstrValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCPresencePropertyEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCPresencePropertyEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCPresencePropertyEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCPresencePropertyEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCPresencePropertyEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCPresencePropertyEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCPresencePropertyEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCPresencePropertyEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCPresencePropertyEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            IRTCPresencePropertyEvent * This,
            /* [retval][out] */ BSTR *pbstrStatusText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresenceProperty )( 
            IRTCPresencePropertyEvent * This,
            /* [retval][out] */ RTC_PRESENCE_PROPERTY *penPresProp);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IRTCPresencePropertyEvent * This,
            /* [retval][out] */ BSTR *pbstrValue);
        
        END_INTERFACE
    } IRTCPresencePropertyEventVtbl;

    interface IRTCPresencePropertyEvent
    {
        CONST_VTBL struct IRTCPresencePropertyEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPresencePropertyEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCPresencePropertyEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCPresencePropertyEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCPresencePropertyEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCPresencePropertyEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCPresencePropertyEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCPresencePropertyEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCPresencePropertyEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCPresencePropertyEvent_get_StatusText(This,pbstrStatusText)	\
    (This)->lpVtbl -> get_StatusText(This,pbstrStatusText)

#define IRTCPresencePropertyEvent_get_PresenceProperty(This,penPresProp)	\
    (This)->lpVtbl -> get_PresenceProperty(This,penPresProp)

#define IRTCPresencePropertyEvent_get_Value(This,pbstrValue)	\
    (This)->lpVtbl -> get_Value(This,pbstrValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresencePropertyEvent_get_StatusCode_Proxy( 
    IRTCPresencePropertyEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCPresencePropertyEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresencePropertyEvent_get_StatusText_Proxy( 
    IRTCPresencePropertyEvent * This,
    /* [retval][out] */ BSTR *pbstrStatusText);


void __RPC_STUB IRTCPresencePropertyEvent_get_StatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresencePropertyEvent_get_PresenceProperty_Proxy( 
    IRTCPresencePropertyEvent * This,
    /* [retval][out] */ RTC_PRESENCE_PROPERTY *penPresProp);


void __RPC_STUB IRTCPresencePropertyEvent_get_PresenceProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresencePropertyEvent_get_Value_Proxy( 
    IRTCPresencePropertyEvent * This,
    /* [retval][out] */ BSTR *pbstrValue);


void __RPC_STUB IRTCPresencePropertyEvent_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCPresencePropertyEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCPresenceDataEvent_INTERFACE_DEFINED__
#define __IRTCPresenceDataEvent_INTERFACE_DEFINED__

/* interface IRTCPresenceDataEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCPresenceDataEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38F0E78C-8B87-4c04-A82D-AEDD83C909BB")
    IRTCPresenceDataEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [retval][out] */ BSTR *pbstrStatusText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPresenceData( 
            /* [out] */ BSTR *pbstrNamespace,
            /* [out] */ BSTR *pbstrData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCPresenceDataEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCPresenceDataEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCPresenceDataEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCPresenceDataEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCPresenceDataEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCPresenceDataEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCPresenceDataEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCPresenceDataEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCPresenceDataEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            IRTCPresenceDataEvent * This,
            /* [retval][out] */ BSTR *pbstrStatusText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPresenceData )( 
            IRTCPresenceDataEvent * This,
            /* [out] */ BSTR *pbstrNamespace,
            /* [out] */ BSTR *pbstrData);
        
        END_INTERFACE
    } IRTCPresenceDataEventVtbl;

    interface IRTCPresenceDataEvent
    {
        CONST_VTBL struct IRTCPresenceDataEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPresenceDataEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCPresenceDataEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCPresenceDataEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCPresenceDataEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCPresenceDataEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCPresenceDataEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCPresenceDataEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCPresenceDataEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCPresenceDataEvent_get_StatusText(This,pbstrStatusText)	\
    (This)->lpVtbl -> get_StatusText(This,pbstrStatusText)

#define IRTCPresenceDataEvent_GetPresenceData(This,pbstrNamespace,pbstrData)	\
    (This)->lpVtbl -> GetPresenceData(This,pbstrNamespace,pbstrData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresenceDataEvent_get_StatusCode_Proxy( 
    IRTCPresenceDataEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCPresenceDataEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresenceDataEvent_get_StatusText_Proxy( 
    IRTCPresenceDataEvent * This,
    /* [retval][out] */ BSTR *pbstrStatusText);


void __RPC_STUB IRTCPresenceDataEvent_get_StatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCPresenceDataEvent_GetPresenceData_Proxy( 
    IRTCPresenceDataEvent * This,
    /* [out] */ BSTR *pbstrNamespace,
    /* [out] */ BSTR *pbstrData);


void __RPC_STUB IRTCPresenceDataEvent_GetPresenceData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCPresenceDataEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCPresenceStatusEvent_INTERFACE_DEFINED__
#define __IRTCPresenceStatusEvent_INTERFACE_DEFINED__

/* interface IRTCPresenceStatusEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCPresenceStatusEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("78673F32-4A0F-462c-89AA-EE7706707678")
    IRTCPresenceStatusEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [retval][out] */ BSTR *pbstrStatusText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLocalPresenceInfo( 
            /* [out] */ RTC_PRESENCE_STATUS *penStatus,
            /* [out] */ BSTR *pbstrNotes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCPresenceStatusEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCPresenceStatusEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCPresenceStatusEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCPresenceStatusEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCPresenceStatusEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCPresenceStatusEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCPresenceStatusEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCPresenceStatusEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCPresenceStatusEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            IRTCPresenceStatusEvent * This,
            /* [retval][out] */ BSTR *pbstrStatusText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLocalPresenceInfo )( 
            IRTCPresenceStatusEvent * This,
            /* [out] */ RTC_PRESENCE_STATUS *penStatus,
            /* [out] */ BSTR *pbstrNotes);
        
        END_INTERFACE
    } IRTCPresenceStatusEventVtbl;

    interface IRTCPresenceStatusEvent
    {
        CONST_VTBL struct IRTCPresenceStatusEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPresenceStatusEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCPresenceStatusEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCPresenceStatusEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCPresenceStatusEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCPresenceStatusEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCPresenceStatusEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCPresenceStatusEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCPresenceStatusEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCPresenceStatusEvent_get_StatusText(This,pbstrStatusText)	\
    (This)->lpVtbl -> get_StatusText(This,pbstrStatusText)

#define IRTCPresenceStatusEvent_GetLocalPresenceInfo(This,penStatus,pbstrNotes)	\
    (This)->lpVtbl -> GetLocalPresenceInfo(This,penStatus,pbstrNotes)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresenceStatusEvent_get_StatusCode_Proxy( 
    IRTCPresenceStatusEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCPresenceStatusEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresenceStatusEvent_get_StatusText_Proxy( 
    IRTCPresenceStatusEvent * This,
    /* [retval][out] */ BSTR *pbstrStatusText);


void __RPC_STUB IRTCPresenceStatusEvent_get_StatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCPresenceStatusEvent_GetLocalPresenceInfo_Proxy( 
    IRTCPresenceStatusEvent * This,
    /* [out] */ RTC_PRESENCE_STATUS *penStatus,
    /* [out] */ BSTR *pbstrNotes);


void __RPC_STUB IRTCPresenceStatusEvent_GetLocalPresenceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCPresenceStatusEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCCollection_INTERFACE_DEFINED__
#define __IRTCCollection_INTERFACE_DEFINED__

/* interface IRTCCollection */
/* [dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC7C8096-B918-4044-94F1-E4FBA0361D5C")
    IRTCCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *lCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ VARIANT *pVariant) = 0;
        
        virtual /* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppNewEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IRTCCollection * This,
            /* [retval][out] */ long *lCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IRTCCollection * This,
            /* [in] */ long Index,
            /* [retval][out] */ VARIANT *pVariant);
        
        /* [helpstring][id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IRTCCollection * This,
            /* [retval][out] */ IUnknown **ppNewEnum);
        
        END_INTERFACE
    } IRTCCollectionVtbl;

    interface IRTCCollection
    {
        CONST_VTBL struct IRTCCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCCollection_get_Count(This,lCount)	\
    (This)->lpVtbl -> get_Count(This,lCount)

#define IRTCCollection_get_Item(This,Index,pVariant)	\
    (This)->lpVtbl -> get_Item(This,Index,pVariant)

#define IRTCCollection_get__NewEnum(This,ppNewEnum)	\
    (This)->lpVtbl -> get__NewEnum(This,ppNewEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCCollection_get_Count_Proxy( 
    IRTCCollection * This,
    /* [retval][out] */ long *lCount);


void __RPC_STUB IRTCCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCCollection_get_Item_Proxy( 
    IRTCCollection * This,
    /* [in] */ long Index,
    /* [retval][out] */ VARIANT *pVariant);


void __RPC_STUB IRTCCollection_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE IRTCCollection_get__NewEnum_Proxy( 
    IRTCCollection * This,
    /* [retval][out] */ IUnknown **ppNewEnum);


void __RPC_STUB IRTCCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCCollection_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumParticipants_INTERFACE_DEFINED__
#define __IRTCEnumParticipants_INTERFACE_DEFINED__

/* interface IRTCEnumParticipants */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumParticipants;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fcd56f29-4a4f-41b2-ba5c-f5bccc060bf6")
    IRTCEnumParticipants : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCParticipant **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ IRTCEnumParticipants **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCEnumParticipantsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCEnumParticipants * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCEnumParticipants * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCEnumParticipants * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IRTCEnumParticipants * This,
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCParticipant **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IRTCEnumParticipants * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IRTCEnumParticipants * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IRTCEnumParticipants * This,
            /* [retval][out] */ IRTCEnumParticipants **ppEnum);
        
        END_INTERFACE
    } IRTCEnumParticipantsVtbl;

    interface IRTCEnumParticipants
    {
        CONST_VTBL struct IRTCEnumParticipantsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumParticipants_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCEnumParticipants_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCEnumParticipants_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCEnumParticipants_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

#define IRTCEnumParticipants_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IRTCEnumParticipants_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IRTCEnumParticipants_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRTCEnumParticipants_Next_Proxy( 
    IRTCEnumParticipants * This,
    /* [in] */ ULONG celt,
    /* [size_is][out] */ IRTCParticipant **ppElements,
    /* [full][out][in] */ ULONG *pceltFetched);


void __RPC_STUB IRTCEnumParticipants_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumParticipants_Reset_Proxy( 
    IRTCEnumParticipants * This);


void __RPC_STUB IRTCEnumParticipants_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumParticipants_Skip_Proxy( 
    IRTCEnumParticipants * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IRTCEnumParticipants_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumParticipants_Clone_Proxy( 
    IRTCEnumParticipants * This,
    /* [retval][out] */ IRTCEnumParticipants **ppEnum);


void __RPC_STUB IRTCEnumParticipants_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCEnumParticipants_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumProfiles_INTERFACE_DEFINED__
#define __IRTCEnumProfiles_INTERFACE_DEFINED__

/* interface IRTCEnumProfiles */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumProfiles;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29b7c41c-ed82-4bca-84ad-39d5101b58e3")
    IRTCEnumProfiles : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCProfile **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ IRTCEnumProfiles **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCEnumProfilesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCEnumProfiles * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCEnumProfiles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCEnumProfiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IRTCEnumProfiles * This,
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCProfile **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IRTCEnumProfiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IRTCEnumProfiles * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IRTCEnumProfiles * This,
            /* [retval][out] */ IRTCEnumProfiles **ppEnum);
        
        END_INTERFACE
    } IRTCEnumProfilesVtbl;

    interface IRTCEnumProfiles
    {
        CONST_VTBL struct IRTCEnumProfilesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumProfiles_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCEnumProfiles_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCEnumProfiles_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCEnumProfiles_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

#define IRTCEnumProfiles_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IRTCEnumProfiles_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IRTCEnumProfiles_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRTCEnumProfiles_Next_Proxy( 
    IRTCEnumProfiles * This,
    /* [in] */ ULONG celt,
    /* [size_is][out] */ IRTCProfile **ppElements,
    /* [full][out][in] */ ULONG *pceltFetched);


void __RPC_STUB IRTCEnumProfiles_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumProfiles_Reset_Proxy( 
    IRTCEnumProfiles * This);


void __RPC_STUB IRTCEnumProfiles_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumProfiles_Skip_Proxy( 
    IRTCEnumProfiles * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IRTCEnumProfiles_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumProfiles_Clone_Proxy( 
    IRTCEnumProfiles * This,
    /* [retval][out] */ IRTCEnumProfiles **ppEnum);


void __RPC_STUB IRTCEnumProfiles_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCEnumProfiles_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumBuddies_INTERFACE_DEFINED__
#define __IRTCEnumBuddies_INTERFACE_DEFINED__

/* interface IRTCEnumBuddies */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumBuddies;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f7296917-5569-4b3b-b3af-98d1144b2b87")
    IRTCEnumBuddies : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCBuddy **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ IRTCEnumBuddies **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCEnumBuddiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCEnumBuddies * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCEnumBuddies * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCEnumBuddies * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IRTCEnumBuddies * This,
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCBuddy **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IRTCEnumBuddies * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IRTCEnumBuddies * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IRTCEnumBuddies * This,
            /* [retval][out] */ IRTCEnumBuddies **ppEnum);
        
        END_INTERFACE
    } IRTCEnumBuddiesVtbl;

    interface IRTCEnumBuddies
    {
        CONST_VTBL struct IRTCEnumBuddiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumBuddies_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCEnumBuddies_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCEnumBuddies_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCEnumBuddies_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

#define IRTCEnumBuddies_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IRTCEnumBuddies_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IRTCEnumBuddies_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRTCEnumBuddies_Next_Proxy( 
    IRTCEnumBuddies * This,
    /* [in] */ ULONG celt,
    /* [size_is][out] */ IRTCBuddy **ppElements,
    /* [full][out][in] */ ULONG *pceltFetched);


void __RPC_STUB IRTCEnumBuddies_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumBuddies_Reset_Proxy( 
    IRTCEnumBuddies * This);


void __RPC_STUB IRTCEnumBuddies_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumBuddies_Skip_Proxy( 
    IRTCEnumBuddies * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IRTCEnumBuddies_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumBuddies_Clone_Proxy( 
    IRTCEnumBuddies * This,
    /* [retval][out] */ IRTCEnumBuddies **ppEnum);


void __RPC_STUB IRTCEnumBuddies_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCEnumBuddies_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumWatchers_INTERFACE_DEFINED__
#define __IRTCEnumWatchers_INTERFACE_DEFINED__

/* interface IRTCEnumWatchers */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumWatchers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a87d55d7-db74-4ed1-9ca4-77a0e41b413e")
    IRTCEnumWatchers : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCWatcher **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ IRTCEnumWatchers **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCEnumWatchersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCEnumWatchers * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCEnumWatchers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCEnumWatchers * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IRTCEnumWatchers * This,
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCWatcher **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IRTCEnumWatchers * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IRTCEnumWatchers * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IRTCEnumWatchers * This,
            /* [retval][out] */ IRTCEnumWatchers **ppEnum);
        
        END_INTERFACE
    } IRTCEnumWatchersVtbl;

    interface IRTCEnumWatchers
    {
        CONST_VTBL struct IRTCEnumWatchersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumWatchers_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCEnumWatchers_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCEnumWatchers_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCEnumWatchers_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

#define IRTCEnumWatchers_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IRTCEnumWatchers_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IRTCEnumWatchers_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRTCEnumWatchers_Next_Proxy( 
    IRTCEnumWatchers * This,
    /* [in] */ ULONG celt,
    /* [size_is][out] */ IRTCWatcher **ppElements,
    /* [full][out][in] */ ULONG *pceltFetched);


void __RPC_STUB IRTCEnumWatchers_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumWatchers_Reset_Proxy( 
    IRTCEnumWatchers * This);


void __RPC_STUB IRTCEnumWatchers_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumWatchers_Skip_Proxy( 
    IRTCEnumWatchers * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IRTCEnumWatchers_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumWatchers_Clone_Proxy( 
    IRTCEnumWatchers * This,
    /* [retval][out] */ IRTCEnumWatchers **ppEnum);


void __RPC_STUB IRTCEnumWatchers_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCEnumWatchers_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumGroups_INTERFACE_DEFINED__
#define __IRTCEnumGroups_INTERFACE_DEFINED__

/* interface IRTCEnumGroups */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumGroups;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("742378D6-A141-4415-8F27-35D99076CF5D")
    IRTCEnumGroups : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCBuddyGroup **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ IRTCEnumGroups **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCEnumGroupsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCEnumGroups * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCEnumGroups * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCEnumGroups * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IRTCEnumGroups * This,
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCBuddyGroup **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IRTCEnumGroups * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IRTCEnumGroups * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IRTCEnumGroups * This,
            /* [retval][out] */ IRTCEnumGroups **ppEnum);
        
        END_INTERFACE
    } IRTCEnumGroupsVtbl;

    interface IRTCEnumGroups
    {
        CONST_VTBL struct IRTCEnumGroupsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumGroups_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCEnumGroups_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCEnumGroups_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCEnumGroups_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

#define IRTCEnumGroups_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IRTCEnumGroups_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IRTCEnumGroups_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRTCEnumGroups_Next_Proxy( 
    IRTCEnumGroups * This,
    /* [in] */ ULONG celt,
    /* [size_is][out] */ IRTCBuddyGroup **ppElements,
    /* [full][out][in] */ ULONG *pceltFetched);


void __RPC_STUB IRTCEnumGroups_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumGroups_Reset_Proxy( 
    IRTCEnumGroups * This);


void __RPC_STUB IRTCEnumGroups_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumGroups_Skip_Proxy( 
    IRTCEnumGroups * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IRTCEnumGroups_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumGroups_Clone_Proxy( 
    IRTCEnumGroups * This,
    /* [retval][out] */ IRTCEnumGroups **ppEnum);


void __RPC_STUB IRTCEnumGroups_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCEnumGroups_INTERFACE_DEFINED__ */


#ifndef __IRTCPresenceContact_INTERFACE_DEFINED__
#define __IRTCPresenceContact_INTERFACE_DEFINED__

/* interface IRTCPresenceContact */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCPresenceContact;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8b22f92c-cd90-42db-a733-212205c3e3df")
    IRTCPresenceContact : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PresentityURI( 
            /* [retval][out] */ BSTR *pbstrPresentityURI) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PresentityURI( 
            /* [in] */ BSTR bstrPresentityURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Data( 
            /* [retval][out] */ BSTR *pbstrData) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Data( 
            /* [in] */ BSTR bstrData) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Persistent( 
            /* [retval][out] */ VARIANT_BOOL *pfPersistent) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Persistent( 
            /* [in] */ VARIANT_BOOL fPersistent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCPresenceContactVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCPresenceContact * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCPresenceContact * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCPresenceContact * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresentityURI )( 
            IRTCPresenceContact * This,
            /* [retval][out] */ BSTR *pbstrPresentityURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresentityURI )( 
            IRTCPresenceContact * This,
            /* [in] */ BSTR bstrPresentityURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IRTCPresenceContact * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IRTCPresenceContact * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            IRTCPresenceContact * This,
            /* [retval][out] */ BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            IRTCPresenceContact * This,
            /* [in] */ BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Persistent )( 
            IRTCPresenceContact * This,
            /* [retval][out] */ VARIANT_BOOL *pfPersistent);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Persistent )( 
            IRTCPresenceContact * This,
            /* [in] */ VARIANT_BOOL fPersistent);
        
        END_INTERFACE
    } IRTCPresenceContactVtbl;

    interface IRTCPresenceContact
    {
        CONST_VTBL struct IRTCPresenceContactVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPresenceContact_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCPresenceContact_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCPresenceContact_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCPresenceContact_get_PresentityURI(This,pbstrPresentityURI)	\
    (This)->lpVtbl -> get_PresentityURI(This,pbstrPresentityURI)

#define IRTCPresenceContact_put_PresentityURI(This,bstrPresentityURI)	\
    (This)->lpVtbl -> put_PresentityURI(This,bstrPresentityURI)

#define IRTCPresenceContact_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IRTCPresenceContact_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IRTCPresenceContact_get_Data(This,pbstrData)	\
    (This)->lpVtbl -> get_Data(This,pbstrData)

#define IRTCPresenceContact_put_Data(This,bstrData)	\
    (This)->lpVtbl -> put_Data(This,bstrData)

#define IRTCPresenceContact_get_Persistent(This,pfPersistent)	\
    (This)->lpVtbl -> get_Persistent(This,pfPersistent)

#define IRTCPresenceContact_put_Persistent(This,fPersistent)	\
    (This)->lpVtbl -> put_Persistent(This,fPersistent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresenceContact_get_PresentityURI_Proxy( 
    IRTCPresenceContact * This,
    /* [retval][out] */ BSTR *pbstrPresentityURI);


void __RPC_STUB IRTCPresenceContact_get_PresentityURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCPresenceContact_put_PresentityURI_Proxy( 
    IRTCPresenceContact * This,
    /* [in] */ BSTR bstrPresentityURI);


void __RPC_STUB IRTCPresenceContact_put_PresentityURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresenceContact_get_Name_Proxy( 
    IRTCPresenceContact * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IRTCPresenceContact_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCPresenceContact_put_Name_Proxy( 
    IRTCPresenceContact * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IRTCPresenceContact_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresenceContact_get_Data_Proxy( 
    IRTCPresenceContact * This,
    /* [retval][out] */ BSTR *pbstrData);


void __RPC_STUB IRTCPresenceContact_get_Data_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCPresenceContact_put_Data_Proxy( 
    IRTCPresenceContact * This,
    /* [in] */ BSTR bstrData);


void __RPC_STUB IRTCPresenceContact_put_Data_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresenceContact_get_Persistent_Proxy( 
    IRTCPresenceContact * This,
    /* [retval][out] */ VARIANT_BOOL *pfPersistent);


void __RPC_STUB IRTCPresenceContact_get_Persistent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCPresenceContact_put_Persistent_Proxy( 
    IRTCPresenceContact * This,
    /* [in] */ VARIANT_BOOL fPersistent);


void __RPC_STUB IRTCPresenceContact_put_Persistent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCPresenceContact_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddy_INTERFACE_DEFINED__
#define __IRTCBuddy_INTERFACE_DEFINED__

/* interface IRTCBuddy */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fcb136c8-7b90-4e0c-befe-56edf0ba6f1c")
    IRTCBuddy : public IRTCPresenceContact
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ RTC_PRESENCE_STATUS *penStatus) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Notes( 
            /* [retval][out] */ BSTR *pbstrNotes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCBuddyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCBuddy * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCBuddy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCBuddy * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresentityURI )( 
            IRTCBuddy * This,
            /* [retval][out] */ BSTR *pbstrPresentityURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresentityURI )( 
            IRTCBuddy * This,
            /* [in] */ BSTR bstrPresentityURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IRTCBuddy * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IRTCBuddy * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            IRTCBuddy * This,
            /* [retval][out] */ BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            IRTCBuddy * This,
            /* [in] */ BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Persistent )( 
            IRTCBuddy * This,
            /* [retval][out] */ VARIANT_BOOL *pfPersistent);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Persistent )( 
            IRTCBuddy * This,
            /* [in] */ VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IRTCBuddy * This,
            /* [retval][out] */ RTC_PRESENCE_STATUS *penStatus);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Notes )( 
            IRTCBuddy * This,
            /* [retval][out] */ BSTR *pbstrNotes);
        
        END_INTERFACE
    } IRTCBuddyVtbl;

    interface IRTCBuddy
    {
        CONST_VTBL struct IRTCBuddyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCBuddy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCBuddy_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCBuddy_get_PresentityURI(This,pbstrPresentityURI)	\
    (This)->lpVtbl -> get_PresentityURI(This,pbstrPresentityURI)

#define IRTCBuddy_put_PresentityURI(This,bstrPresentityURI)	\
    (This)->lpVtbl -> put_PresentityURI(This,bstrPresentityURI)

#define IRTCBuddy_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IRTCBuddy_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IRTCBuddy_get_Data(This,pbstrData)	\
    (This)->lpVtbl -> get_Data(This,pbstrData)

#define IRTCBuddy_put_Data(This,bstrData)	\
    (This)->lpVtbl -> put_Data(This,bstrData)

#define IRTCBuddy_get_Persistent(This,pfPersistent)	\
    (This)->lpVtbl -> get_Persistent(This,pfPersistent)

#define IRTCBuddy_put_Persistent(This,fPersistent)	\
    (This)->lpVtbl -> put_Persistent(This,fPersistent)


#define IRTCBuddy_get_Status(This,penStatus)	\
    (This)->lpVtbl -> get_Status(This,penStatus)

#define IRTCBuddy_get_Notes(This,pbstrNotes)	\
    (This)->lpVtbl -> get_Notes(This,pbstrNotes)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddy_get_Status_Proxy( 
    IRTCBuddy * This,
    /* [retval][out] */ RTC_PRESENCE_STATUS *penStatus);


void __RPC_STUB IRTCBuddy_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddy_get_Notes_Proxy( 
    IRTCBuddy * This,
    /* [retval][out] */ BSTR *pbstrNotes);


void __RPC_STUB IRTCBuddy_get_Notes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCBuddy_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddy2_INTERFACE_DEFINED__
#define __IRTCBuddy2_INTERFACE_DEFINED__

/* interface IRTCBuddy2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddy2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("102F9588-23E7-40e3-954D-CD7A1D5C0361")
    IRTCBuddy2 : public IRTCBuddy
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [retval][out] */ IRTCProfile2 **ppProfile) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateGroups( 
            /* [retval][out] */ IRTCEnumGroups **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Groups( 
            /* [retval][out] */ IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PresenceProperty( 
            /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
            /* [retval][out] */ BSTR *pbstrProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnumeratePresenceDevices( 
            /* [retval][out] */ IRTCEnumPresenceDevices **ppEnumDevices) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PresenceDevices( 
            /* [retval][out] */ IRTCCollection **ppDevicesCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriptionType( 
            /* [retval][out] */ RTC_BUDDY_SUBSCRIPTION_TYPE *penSubscriptionType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCBuddy2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCBuddy2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCBuddy2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCBuddy2 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresentityURI )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ BSTR *pbstrPresentityURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresentityURI )( 
            IRTCBuddy2 * This,
            /* [in] */ BSTR bstrPresentityURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IRTCBuddy2 * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            IRTCBuddy2 * This,
            /* [in] */ BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Persistent )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ VARIANT_BOOL *pfPersistent);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Persistent )( 
            IRTCBuddy2 * This,
            /* [in] */ VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ RTC_PRESENCE_STATUS *penStatus);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Notes )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ BSTR *pbstrNotes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ IRTCProfile2 **ppProfile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IRTCBuddy2 * This);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateGroups )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ IRTCEnumGroups **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Groups )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresenceProperty )( 
            IRTCBuddy2 * This,
            /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
            /* [retval][out] */ BSTR *pbstrProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumeratePresenceDevices )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ IRTCEnumPresenceDevices **ppEnumDevices);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresenceDevices )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ IRTCCollection **ppDevicesCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubscriptionType )( 
            IRTCBuddy2 * This,
            /* [retval][out] */ RTC_BUDDY_SUBSCRIPTION_TYPE *penSubscriptionType);
        
        END_INTERFACE
    } IRTCBuddy2Vtbl;

    interface IRTCBuddy2
    {
        CONST_VTBL struct IRTCBuddy2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddy2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCBuddy2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCBuddy2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCBuddy2_get_PresentityURI(This,pbstrPresentityURI)	\
    (This)->lpVtbl -> get_PresentityURI(This,pbstrPresentityURI)

#define IRTCBuddy2_put_PresentityURI(This,bstrPresentityURI)	\
    (This)->lpVtbl -> put_PresentityURI(This,bstrPresentityURI)

#define IRTCBuddy2_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IRTCBuddy2_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IRTCBuddy2_get_Data(This,pbstrData)	\
    (This)->lpVtbl -> get_Data(This,pbstrData)

#define IRTCBuddy2_put_Data(This,bstrData)	\
    (This)->lpVtbl -> put_Data(This,bstrData)

#define IRTCBuddy2_get_Persistent(This,pfPersistent)	\
    (This)->lpVtbl -> get_Persistent(This,pfPersistent)

#define IRTCBuddy2_put_Persistent(This,fPersistent)	\
    (This)->lpVtbl -> put_Persistent(This,fPersistent)


#define IRTCBuddy2_get_Status(This,penStatus)	\
    (This)->lpVtbl -> get_Status(This,penStatus)

#define IRTCBuddy2_get_Notes(This,pbstrNotes)	\
    (This)->lpVtbl -> get_Notes(This,pbstrNotes)


#define IRTCBuddy2_get_Profile(This,ppProfile)	\
    (This)->lpVtbl -> get_Profile(This,ppProfile)

#define IRTCBuddy2_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)

#define IRTCBuddy2_EnumerateGroups(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateGroups(This,ppEnum)

#define IRTCBuddy2_get_Groups(This,ppCollection)	\
    (This)->lpVtbl -> get_Groups(This,ppCollection)

#define IRTCBuddy2_get_PresenceProperty(This,enProperty,pbstrProperty)	\
    (This)->lpVtbl -> get_PresenceProperty(This,enProperty,pbstrProperty)

#define IRTCBuddy2_EnumeratePresenceDevices(This,ppEnumDevices)	\
    (This)->lpVtbl -> EnumeratePresenceDevices(This,ppEnumDevices)

#define IRTCBuddy2_get_PresenceDevices(This,ppDevicesCollection)	\
    (This)->lpVtbl -> get_PresenceDevices(This,ppDevicesCollection)

#define IRTCBuddy2_get_SubscriptionType(This,penSubscriptionType)	\
    (This)->lpVtbl -> get_SubscriptionType(This,penSubscriptionType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddy2_get_Profile_Proxy( 
    IRTCBuddy2 * This,
    /* [retval][out] */ IRTCProfile2 **ppProfile);


void __RPC_STUB IRTCBuddy2_get_Profile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCBuddy2_Refresh_Proxy( 
    IRTCBuddy2 * This);


void __RPC_STUB IRTCBuddy2_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE IRTCBuddy2_EnumerateGroups_Proxy( 
    IRTCBuddy2 * This,
    /* [retval][out] */ IRTCEnumGroups **ppEnum);


void __RPC_STUB IRTCBuddy2_EnumerateGroups_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddy2_get_Groups_Proxy( 
    IRTCBuddy2 * This,
    /* [retval][out] */ IRTCCollection **ppCollection);


void __RPC_STUB IRTCBuddy2_get_Groups_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddy2_get_PresenceProperty_Proxy( 
    IRTCBuddy2 * This,
    /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
    /* [retval][out] */ BSTR *pbstrProperty);


void __RPC_STUB IRTCBuddy2_get_PresenceProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCBuddy2_EnumeratePresenceDevices_Proxy( 
    IRTCBuddy2 * This,
    /* [retval][out] */ IRTCEnumPresenceDevices **ppEnumDevices);


void __RPC_STUB IRTCBuddy2_EnumeratePresenceDevices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddy2_get_PresenceDevices_Proxy( 
    IRTCBuddy2 * This,
    /* [retval][out] */ IRTCCollection **ppDevicesCollection);


void __RPC_STUB IRTCBuddy2_get_PresenceDevices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddy2_get_SubscriptionType_Proxy( 
    IRTCBuddy2 * This,
    /* [retval][out] */ RTC_BUDDY_SUBSCRIPTION_TYPE *penSubscriptionType);


void __RPC_STUB IRTCBuddy2_get_SubscriptionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCBuddy2_INTERFACE_DEFINED__ */


#ifndef __IRTCWatcher_INTERFACE_DEFINED__
#define __IRTCWatcher_INTERFACE_DEFINED__

/* interface IRTCWatcher */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCWatcher;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c7cedad8-346b-4d1b-ac02-a2088df9be4f")
    IRTCWatcher : public IRTCPresenceContact
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ RTC_WATCHER_STATE *penState) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_State( 
            /* [in] */ RTC_WATCHER_STATE enState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCWatcherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCWatcher * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCWatcher * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCWatcher * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresentityURI )( 
            IRTCWatcher * This,
            /* [retval][out] */ BSTR *pbstrPresentityURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresentityURI )( 
            IRTCWatcher * This,
            /* [in] */ BSTR bstrPresentityURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IRTCWatcher * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IRTCWatcher * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            IRTCWatcher * This,
            /* [retval][out] */ BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            IRTCWatcher * This,
            /* [in] */ BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Persistent )( 
            IRTCWatcher * This,
            /* [retval][out] */ VARIANT_BOOL *pfPersistent);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Persistent )( 
            IRTCWatcher * This,
            /* [in] */ VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCWatcher * This,
            /* [retval][out] */ RTC_WATCHER_STATE *penState);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_State )( 
            IRTCWatcher * This,
            /* [in] */ RTC_WATCHER_STATE enState);
        
        END_INTERFACE
    } IRTCWatcherVtbl;

    interface IRTCWatcher
    {
        CONST_VTBL struct IRTCWatcherVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCWatcher_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCWatcher_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCWatcher_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCWatcher_get_PresentityURI(This,pbstrPresentityURI)	\
    (This)->lpVtbl -> get_PresentityURI(This,pbstrPresentityURI)

#define IRTCWatcher_put_PresentityURI(This,bstrPresentityURI)	\
    (This)->lpVtbl -> put_PresentityURI(This,bstrPresentityURI)

#define IRTCWatcher_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IRTCWatcher_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IRTCWatcher_get_Data(This,pbstrData)	\
    (This)->lpVtbl -> get_Data(This,pbstrData)

#define IRTCWatcher_put_Data(This,bstrData)	\
    (This)->lpVtbl -> put_Data(This,bstrData)

#define IRTCWatcher_get_Persistent(This,pfPersistent)	\
    (This)->lpVtbl -> get_Persistent(This,pfPersistent)

#define IRTCWatcher_put_Persistent(This,fPersistent)	\
    (This)->lpVtbl -> put_Persistent(This,fPersistent)


#define IRTCWatcher_get_State(This,penState)	\
    (This)->lpVtbl -> get_State(This,penState)

#define IRTCWatcher_put_State(This,enState)	\
    (This)->lpVtbl -> put_State(This,enState)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCWatcher_get_State_Proxy( 
    IRTCWatcher * This,
    /* [retval][out] */ RTC_WATCHER_STATE *penState);


void __RPC_STUB IRTCWatcher_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCWatcher_put_State_Proxy( 
    IRTCWatcher * This,
    /* [in] */ RTC_WATCHER_STATE enState);


void __RPC_STUB IRTCWatcher_put_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCWatcher_INTERFACE_DEFINED__ */


#ifndef __IRTCWatcher2_INTERFACE_DEFINED__
#define __IRTCWatcher2_INTERFACE_DEFINED__

/* interface IRTCWatcher2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCWatcher2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D4D9967F-D011-4b1d-91E3-ABA78F96393D")
    IRTCWatcher2 : public IRTCWatcher
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [retval][out] */ IRTCProfile2 **ppProfile) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Scope( 
            /* [retval][out] */ RTC_ACE_SCOPE *penScope) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCWatcher2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCWatcher2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCWatcher2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCWatcher2 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresentityURI )( 
            IRTCWatcher2 * This,
            /* [retval][out] */ BSTR *pbstrPresentityURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresentityURI )( 
            IRTCWatcher2 * This,
            /* [in] */ BSTR bstrPresentityURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IRTCWatcher2 * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IRTCWatcher2 * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            IRTCWatcher2 * This,
            /* [retval][out] */ BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            IRTCWatcher2 * This,
            /* [in] */ BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Persistent )( 
            IRTCWatcher2 * This,
            /* [retval][out] */ VARIANT_BOOL *pfPersistent);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Persistent )( 
            IRTCWatcher2 * This,
            /* [in] */ VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IRTCWatcher2 * This,
            /* [retval][out] */ RTC_WATCHER_STATE *penState);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_State )( 
            IRTCWatcher2 * This,
            /* [in] */ RTC_WATCHER_STATE enState);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            IRTCWatcher2 * This,
            /* [retval][out] */ IRTCProfile2 **ppProfile);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Scope )( 
            IRTCWatcher2 * This,
            /* [retval][out] */ RTC_ACE_SCOPE *penScope);
        
        END_INTERFACE
    } IRTCWatcher2Vtbl;

    interface IRTCWatcher2
    {
        CONST_VTBL struct IRTCWatcher2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCWatcher2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCWatcher2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCWatcher2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCWatcher2_get_PresentityURI(This,pbstrPresentityURI)	\
    (This)->lpVtbl -> get_PresentityURI(This,pbstrPresentityURI)

#define IRTCWatcher2_put_PresentityURI(This,bstrPresentityURI)	\
    (This)->lpVtbl -> put_PresentityURI(This,bstrPresentityURI)

#define IRTCWatcher2_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IRTCWatcher2_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IRTCWatcher2_get_Data(This,pbstrData)	\
    (This)->lpVtbl -> get_Data(This,pbstrData)

#define IRTCWatcher2_put_Data(This,bstrData)	\
    (This)->lpVtbl -> put_Data(This,bstrData)

#define IRTCWatcher2_get_Persistent(This,pfPersistent)	\
    (This)->lpVtbl -> get_Persistent(This,pfPersistent)

#define IRTCWatcher2_put_Persistent(This,fPersistent)	\
    (This)->lpVtbl -> put_Persistent(This,fPersistent)


#define IRTCWatcher2_get_State(This,penState)	\
    (This)->lpVtbl -> get_State(This,penState)

#define IRTCWatcher2_put_State(This,enState)	\
    (This)->lpVtbl -> put_State(This,enState)


#define IRTCWatcher2_get_Profile(This,ppProfile)	\
    (This)->lpVtbl -> get_Profile(This,ppProfile)

#define IRTCWatcher2_get_Scope(This,penScope)	\
    (This)->lpVtbl -> get_Scope(This,penScope)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCWatcher2_get_Profile_Proxy( 
    IRTCWatcher2 * This,
    /* [retval][out] */ IRTCProfile2 **ppProfile);


void __RPC_STUB IRTCWatcher2_get_Profile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCWatcher2_get_Scope_Proxy( 
    IRTCWatcher2 * This,
    /* [retval][out] */ RTC_ACE_SCOPE *penScope);


void __RPC_STUB IRTCWatcher2_get_Scope_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCWatcher2_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddyGroup_INTERFACE_DEFINED__
#define __IRTCBuddyGroup_INTERFACE_DEFINED__

/* interface IRTCBuddyGroup */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddyGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60361E68-9164-4389-A4C6-D0B3925BDA5E")
    IRTCBuddyGroup : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrGroupName) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrGroupName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddBuddy( 
            /* [in] */ IRTCBuddy *pBuddy) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveBuddy( 
            /* [in] */ IRTCBuddy *pBuddy) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateBuddies( 
            /* [retval][out] */ IRTCEnumBuddies **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Buddies( 
            /* [retval][out] */ IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Data( 
            /* [retval][out] */ BSTR *pbstrData) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Data( 
            /* [in] */ BSTR bstrData) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [retval][out] */ IRTCProfile2 **ppProfile) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCBuddyGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCBuddyGroup * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCBuddyGroup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCBuddyGroup * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IRTCBuddyGroup * This,
            /* [retval][out] */ BSTR *pbstrGroupName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IRTCBuddyGroup * This,
            /* [in] */ BSTR bstrGroupName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddBuddy )( 
            IRTCBuddyGroup * This,
            /* [in] */ IRTCBuddy *pBuddy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveBuddy )( 
            IRTCBuddyGroup * This,
            /* [in] */ IRTCBuddy *pBuddy);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateBuddies )( 
            IRTCBuddyGroup * This,
            /* [retval][out] */ IRTCEnumBuddies **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddies )( 
            IRTCBuddyGroup * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            IRTCBuddyGroup * This,
            /* [retval][out] */ BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            IRTCBuddyGroup * This,
            /* [in] */ BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            IRTCBuddyGroup * This,
            /* [retval][out] */ IRTCProfile2 **ppProfile);
        
        END_INTERFACE
    } IRTCBuddyGroupVtbl;

    interface IRTCBuddyGroup
    {
        CONST_VTBL struct IRTCBuddyGroupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddyGroup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCBuddyGroup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCBuddyGroup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCBuddyGroup_get_Name(This,pbstrGroupName)	\
    (This)->lpVtbl -> get_Name(This,pbstrGroupName)

#define IRTCBuddyGroup_put_Name(This,bstrGroupName)	\
    (This)->lpVtbl -> put_Name(This,bstrGroupName)

#define IRTCBuddyGroup_AddBuddy(This,pBuddy)	\
    (This)->lpVtbl -> AddBuddy(This,pBuddy)

#define IRTCBuddyGroup_RemoveBuddy(This,pBuddy)	\
    (This)->lpVtbl -> RemoveBuddy(This,pBuddy)

#define IRTCBuddyGroup_EnumerateBuddies(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateBuddies(This,ppEnum)

#define IRTCBuddyGroup_get_Buddies(This,ppCollection)	\
    (This)->lpVtbl -> get_Buddies(This,ppCollection)

#define IRTCBuddyGroup_get_Data(This,pbstrData)	\
    (This)->lpVtbl -> get_Data(This,pbstrData)

#define IRTCBuddyGroup_put_Data(This,bstrData)	\
    (This)->lpVtbl -> put_Data(This,bstrData)

#define IRTCBuddyGroup_get_Profile(This,ppProfile)	\
    (This)->lpVtbl -> get_Profile(This,ppProfile)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroup_get_Name_Proxy( 
    IRTCBuddyGroup * This,
    /* [retval][out] */ BSTR *pbstrGroupName);


void __RPC_STUB IRTCBuddyGroup_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroup_put_Name_Proxy( 
    IRTCBuddyGroup * This,
    /* [in] */ BSTR bstrGroupName);


void __RPC_STUB IRTCBuddyGroup_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroup_AddBuddy_Proxy( 
    IRTCBuddyGroup * This,
    /* [in] */ IRTCBuddy *pBuddy);


void __RPC_STUB IRTCBuddyGroup_AddBuddy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroup_RemoveBuddy_Proxy( 
    IRTCBuddyGroup * This,
    /* [in] */ IRTCBuddy *pBuddy);


void __RPC_STUB IRTCBuddyGroup_RemoveBuddy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroup_EnumerateBuddies_Proxy( 
    IRTCBuddyGroup * This,
    /* [retval][out] */ IRTCEnumBuddies **ppEnum);


void __RPC_STUB IRTCBuddyGroup_EnumerateBuddies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroup_get_Buddies_Proxy( 
    IRTCBuddyGroup * This,
    /* [retval][out] */ IRTCCollection **ppCollection);


void __RPC_STUB IRTCBuddyGroup_get_Buddies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroup_get_Data_Proxy( 
    IRTCBuddyGroup * This,
    /* [retval][out] */ BSTR *pbstrData);


void __RPC_STUB IRTCBuddyGroup_get_Data_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroup_put_Data_Proxy( 
    IRTCBuddyGroup * This,
    /* [in] */ BSTR bstrData);


void __RPC_STUB IRTCBuddyGroup_put_Data_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCBuddyGroup_get_Profile_Proxy( 
    IRTCBuddyGroup * This,
    /* [retval][out] */ IRTCProfile2 **ppProfile);


void __RPC_STUB IRTCBuddyGroup_get_Profile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCBuddyGroup_INTERFACE_DEFINED__ */


#ifndef __IRTCEventNotification_INTERFACE_DEFINED__
#define __IRTCEventNotification_INTERFACE_DEFINED__

/* interface IRTCEventNotification */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCEventNotification;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("13fa24c7-5748-4b21-91f5-7397609ce747")
    IRTCEventNotification : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Event( 
            /* [in] */ RTC_EVENT RTCEvent,
            /* [in] */ IDispatch *pEvent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCEventNotificationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCEventNotification * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCEventNotification * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCEventNotification * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Event )( 
            IRTCEventNotification * This,
            /* [in] */ RTC_EVENT RTCEvent,
            /* [in] */ IDispatch *pEvent);
        
        END_INTERFACE
    } IRTCEventNotificationVtbl;

    interface IRTCEventNotification
    {
        CONST_VTBL struct IRTCEventNotificationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEventNotification_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCEventNotification_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCEventNotification_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCEventNotification_Event(This,RTCEvent,pEvent)	\
    (This)->lpVtbl -> Event(This,RTCEvent,pEvent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCEventNotification_Event_Proxy( 
    IRTCEventNotification * This,
    /* [in] */ RTC_EVENT RTCEvent,
    /* [in] */ IDispatch *pEvent);


void __RPC_STUB IRTCEventNotification_Event_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCEventNotification_INTERFACE_DEFINED__ */


#ifndef __IRTCPortManager_INTERFACE_DEFINED__
#define __IRTCPortManager_INTERFACE_DEFINED__

/* interface IRTCPortManager */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCPortManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA77C14B-6208-43ca-8DDF-5B60A0A69FAC")
    IRTCPortManager : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMapping( 
            /* [in] */ BSTR bstrRemoteAddress,
            /* [in] */ RTC_PORT_TYPE enPortType,
            /* [out][in] */ BSTR *pbstrInternalLocalAddress,
            /* [out][in] */ long *plInternalLocalPort,
            /* [out][in] */ BSTR *pbstrExternalLocalAddress,
            /* [out][in] */ long *plExternalLocalPort) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateRemoteAddress( 
            /* [in] */ BSTR bstrRemoteAddress,
            /* [in] */ BSTR bstrInternalLocalAddress,
            /* [in] */ long lInternalLocalPort,
            /* [in] */ BSTR bstrExternalLocalAddress,
            /* [in] */ long lExternalLocalPort) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReleaseMapping( 
            /* [in] */ BSTR bstrInternalLocalAddress,
            /* [in] */ long lInternalLocalPort,
            /* [in] */ BSTR bstrExternalLocalAddress,
            /* [in] */ long lExternalLocalAddress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCPortManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCPortManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCPortManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCPortManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMapping )( 
            IRTCPortManager * This,
            /* [in] */ BSTR bstrRemoteAddress,
            /* [in] */ RTC_PORT_TYPE enPortType,
            /* [out][in] */ BSTR *pbstrInternalLocalAddress,
            /* [out][in] */ long *plInternalLocalPort,
            /* [out][in] */ BSTR *pbstrExternalLocalAddress,
            /* [out][in] */ long *plExternalLocalPort);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateRemoteAddress )( 
            IRTCPortManager * This,
            /* [in] */ BSTR bstrRemoteAddress,
            /* [in] */ BSTR bstrInternalLocalAddress,
            /* [in] */ long lInternalLocalPort,
            /* [in] */ BSTR bstrExternalLocalAddress,
            /* [in] */ long lExternalLocalPort);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseMapping )( 
            IRTCPortManager * This,
            /* [in] */ BSTR bstrInternalLocalAddress,
            /* [in] */ long lInternalLocalPort,
            /* [in] */ BSTR bstrExternalLocalAddress,
            /* [in] */ long lExternalLocalAddress);
        
        END_INTERFACE
    } IRTCPortManagerVtbl;

    interface IRTCPortManager
    {
        CONST_VTBL struct IRTCPortManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPortManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCPortManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCPortManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCPortManager_GetMapping(This,bstrRemoteAddress,enPortType,pbstrInternalLocalAddress,plInternalLocalPort,pbstrExternalLocalAddress,plExternalLocalPort)	\
    (This)->lpVtbl -> GetMapping(This,bstrRemoteAddress,enPortType,pbstrInternalLocalAddress,plInternalLocalPort,pbstrExternalLocalAddress,plExternalLocalPort)

#define IRTCPortManager_UpdateRemoteAddress(This,bstrRemoteAddress,bstrInternalLocalAddress,lInternalLocalPort,bstrExternalLocalAddress,lExternalLocalPort)	\
    (This)->lpVtbl -> UpdateRemoteAddress(This,bstrRemoteAddress,bstrInternalLocalAddress,lInternalLocalPort,bstrExternalLocalAddress,lExternalLocalPort)

#define IRTCPortManager_ReleaseMapping(This,bstrInternalLocalAddress,lInternalLocalPort,bstrExternalLocalAddress,lExternalLocalAddress)	\
    (This)->lpVtbl -> ReleaseMapping(This,bstrInternalLocalAddress,lInternalLocalPort,bstrExternalLocalAddress,lExternalLocalAddress)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCPortManager_GetMapping_Proxy( 
    IRTCPortManager * This,
    /* [in] */ BSTR bstrRemoteAddress,
    /* [in] */ RTC_PORT_TYPE enPortType,
    /* [out][in] */ BSTR *pbstrInternalLocalAddress,
    /* [out][in] */ long *plInternalLocalPort,
    /* [out][in] */ BSTR *pbstrExternalLocalAddress,
    /* [out][in] */ long *plExternalLocalPort);


void __RPC_STUB IRTCPortManager_GetMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCPortManager_UpdateRemoteAddress_Proxy( 
    IRTCPortManager * This,
    /* [in] */ BSTR bstrRemoteAddress,
    /* [in] */ BSTR bstrInternalLocalAddress,
    /* [in] */ long lInternalLocalPort,
    /* [in] */ BSTR bstrExternalLocalAddress,
    /* [in] */ long lExternalLocalPort);


void __RPC_STUB IRTCPortManager_UpdateRemoteAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCPortManager_ReleaseMapping_Proxy( 
    IRTCPortManager * This,
    /* [in] */ BSTR bstrInternalLocalAddress,
    /* [in] */ long lInternalLocalPort,
    /* [in] */ BSTR bstrExternalLocalAddress,
    /* [in] */ long lExternalLocalAddress);


void __RPC_STUB IRTCPortManager_ReleaseMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCPortManager_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionPortManagement_INTERFACE_DEFINED__
#define __IRTCSessionPortManagement_INTERFACE_DEFINED__

/* interface IRTCSessionPortManagement */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionPortManagement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a072f1d6-0286-4e1f-85f2-17a2948456ec")
    IRTCSessionPortManagement : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPortManager( 
            /* [in] */ IRTCPortManager *pPortManager) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCSessionPortManagementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCSessionPortManagement * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCSessionPortManagement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCSessionPortManagement * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPortManager )( 
            IRTCSessionPortManagement * This,
            /* [in] */ IRTCPortManager *pPortManager);
        
        END_INTERFACE
    } IRTCSessionPortManagementVtbl;

    interface IRTCSessionPortManagement
    {
        CONST_VTBL struct IRTCSessionPortManagementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionPortManagement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCSessionPortManagement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCSessionPortManagement_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCSessionPortManagement_SetPortManager(This,pPortManager)	\
    (This)->lpVtbl -> SetPortManager(This,pPortManager)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRTCSessionPortManagement_SetPortManager_Proxy( 
    IRTCSessionPortManagement * This,
    /* [in] */ IRTCPortManager *pPortManager);


void __RPC_STUB IRTCSessionPortManagement_SetPortManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCSessionPortManagement_INTERFACE_DEFINED__ */


#ifndef __IRTCClientPortManagement_INTERFACE_DEFINED__
#define __IRTCClientPortManagement_INTERFACE_DEFINED__

/* interface IRTCClientPortManagement */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientPortManagement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d5df3f03-4bde-4417-aefe-71177bdaea66")
    IRTCClientPortManagement : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartListenAddressAndPort( 
            /* [in] */ BSTR bstrInternalLocalAddress,
            /* [in] */ long lInternalLocalPort) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopListenAddressAndPort( 
            /* [in] */ BSTR bstrInternalLocalAddress,
            /* [in] */ long lInternalLocalPort) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPortRange( 
            /* [in] */ RTC_PORT_TYPE enPortType,
            /* [out] */ long *plMinValue,
            /* [out] */ long *plMaxValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCClientPortManagementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCClientPortManagement * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCClientPortManagement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCClientPortManagement * This);
        
        HRESULT ( STDMETHODCALLTYPE *StartListenAddressAndPort )( 
            IRTCClientPortManagement * This,
            /* [in] */ BSTR bstrInternalLocalAddress,
            /* [in] */ long lInternalLocalPort);
        
        HRESULT ( STDMETHODCALLTYPE *StopListenAddressAndPort )( 
            IRTCClientPortManagement * This,
            /* [in] */ BSTR bstrInternalLocalAddress,
            /* [in] */ long lInternalLocalPort);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPortRange )( 
            IRTCClientPortManagement * This,
            /* [in] */ RTC_PORT_TYPE enPortType,
            /* [out] */ long *plMinValue,
            /* [out] */ long *plMaxValue);
        
        END_INTERFACE
    } IRTCClientPortManagementVtbl;

    interface IRTCClientPortManagement
    {
        CONST_VTBL struct IRTCClientPortManagementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientPortManagement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCClientPortManagement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCClientPortManagement_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCClientPortManagement_StartListenAddressAndPort(This,bstrInternalLocalAddress,lInternalLocalPort)	\
    (This)->lpVtbl -> StartListenAddressAndPort(This,bstrInternalLocalAddress,lInternalLocalPort)

#define IRTCClientPortManagement_StopListenAddressAndPort(This,bstrInternalLocalAddress,lInternalLocalPort)	\
    (This)->lpVtbl -> StopListenAddressAndPort(This,bstrInternalLocalAddress,lInternalLocalPort)

#define IRTCClientPortManagement_GetPortRange(This,enPortType,plMinValue,plMaxValue)	\
    (This)->lpVtbl -> GetPortRange(This,enPortType,plMinValue,plMaxValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRTCClientPortManagement_StartListenAddressAndPort_Proxy( 
    IRTCClientPortManagement * This,
    /* [in] */ BSTR bstrInternalLocalAddress,
    /* [in] */ long lInternalLocalPort);


void __RPC_STUB IRTCClientPortManagement_StartListenAddressAndPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCClientPortManagement_StopListenAddressAndPort_Proxy( 
    IRTCClientPortManagement * This,
    /* [in] */ BSTR bstrInternalLocalAddress,
    /* [in] */ long lInternalLocalPort);


void __RPC_STUB IRTCClientPortManagement_StopListenAddressAndPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCClientPortManagement_GetPortRange_Proxy( 
    IRTCClientPortManagement * This,
    /* [in] */ RTC_PORT_TYPE enPortType,
    /* [out] */ long *plMinValue,
    /* [out] */ long *plMaxValue);


void __RPC_STUB IRTCClientPortManagement_GetPortRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCClientPortManagement_INTERFACE_DEFINED__ */


#ifndef __IRTCUserSearch_INTERFACE_DEFINED__
#define __IRTCUserSearch_INTERFACE_DEFINED__

/* interface IRTCUserSearch */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCUserSearch;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B619882B-860C-4db4-BE1B-693B6505BBE5")
    IRTCUserSearch : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateQuery( 
            /* [retval][out] */ IRTCUserSearchQuery **ppQuery) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ExecuteSearch( 
            /* [in] */ IRTCUserSearchQuery *pQuery,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ LONG_PTR lCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCUserSearchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCUserSearch * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCUserSearch * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCUserSearch * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateQuery )( 
            IRTCUserSearch * This,
            /* [retval][out] */ IRTCUserSearchQuery **ppQuery);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ExecuteSearch )( 
            IRTCUserSearch * This,
            /* [in] */ IRTCUserSearchQuery *pQuery,
            /* [in] */ IRTCProfile *pProfile,
            /* [in] */ LONG_PTR lCookie);
        
        END_INTERFACE
    } IRTCUserSearchVtbl;

    interface IRTCUserSearch
    {
        CONST_VTBL struct IRTCUserSearchVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCUserSearch_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCUserSearch_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCUserSearch_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCUserSearch_CreateQuery(This,ppQuery)	\
    (This)->lpVtbl -> CreateQuery(This,ppQuery)

#define IRTCUserSearch_ExecuteSearch(This,pQuery,pProfile,lCookie)	\
    (This)->lpVtbl -> ExecuteSearch(This,pQuery,pProfile,lCookie)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCUserSearch_CreateQuery_Proxy( 
    IRTCUserSearch * This,
    /* [retval][out] */ IRTCUserSearchQuery **ppQuery);


void __RPC_STUB IRTCUserSearch_CreateQuery_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCUserSearch_ExecuteSearch_Proxy( 
    IRTCUserSearch * This,
    /* [in] */ IRTCUserSearchQuery *pQuery,
    /* [in] */ IRTCProfile *pProfile,
    /* [in] */ LONG_PTR lCookie);


void __RPC_STUB IRTCUserSearch_ExecuteSearch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCUserSearch_INTERFACE_DEFINED__ */


#ifndef __IRTCUserSearchQuery_INTERFACE_DEFINED__
#define __IRTCUserSearchQuery_INTERFACE_DEFINED__

/* interface IRTCUserSearchQuery */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCUserSearchQuery;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("288300F5-D23A-4365-9A73-9985C98C2881")
    IRTCUserSearchQuery : public IUnknown
    {
    public:
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SearchTerm( 
            /* [in] */ BSTR bstrName,
            /* [in] */ BSTR bstrValue) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SearchTerm( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ BSTR *pbstrValue) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SearchTerms( 
            /* [retval][out] */ BSTR *pbstrNames) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SearchPreference( 
            /* [in] */ RTC_USER_SEARCH_PREFERENCE enPreference,
            /* [in] */ long lValue) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SearchPreference( 
            /* [in] */ RTC_USER_SEARCH_PREFERENCE enPreference,
            /* [retval][out] */ long *plValue) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SearchDomain( 
            /* [in] */ BSTR bstrDomain) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SearchDomain( 
            /* [retval][out] */ BSTR *pbstrDomain) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCUserSearchQueryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCUserSearchQuery * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCUserSearchQuery * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCUserSearchQuery * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SearchTerm )( 
            IRTCUserSearchQuery * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ BSTR bstrValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchTerm )( 
            IRTCUserSearchQuery * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ BSTR *pbstrValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchTerms )( 
            IRTCUserSearchQuery * This,
            /* [retval][out] */ BSTR *pbstrNames);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SearchPreference )( 
            IRTCUserSearchQuery * This,
            /* [in] */ RTC_USER_SEARCH_PREFERENCE enPreference,
            /* [in] */ long lValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchPreference )( 
            IRTCUserSearchQuery * This,
            /* [in] */ RTC_USER_SEARCH_PREFERENCE enPreference,
            /* [retval][out] */ long *plValue);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SearchDomain )( 
            IRTCUserSearchQuery * This,
            /* [in] */ BSTR bstrDomain);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchDomain )( 
            IRTCUserSearchQuery * This,
            /* [retval][out] */ BSTR *pbstrDomain);
        
        END_INTERFACE
    } IRTCUserSearchQueryVtbl;

    interface IRTCUserSearchQuery
    {
        CONST_VTBL struct IRTCUserSearchQueryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCUserSearchQuery_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCUserSearchQuery_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCUserSearchQuery_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCUserSearchQuery_put_SearchTerm(This,bstrName,bstrValue)	\
    (This)->lpVtbl -> put_SearchTerm(This,bstrName,bstrValue)

#define IRTCUserSearchQuery_get_SearchTerm(This,bstrName,pbstrValue)	\
    (This)->lpVtbl -> get_SearchTerm(This,bstrName,pbstrValue)

#define IRTCUserSearchQuery_get_SearchTerms(This,pbstrNames)	\
    (This)->lpVtbl -> get_SearchTerms(This,pbstrNames)

#define IRTCUserSearchQuery_put_SearchPreference(This,enPreference,lValue)	\
    (This)->lpVtbl -> put_SearchPreference(This,enPreference,lValue)

#define IRTCUserSearchQuery_get_SearchPreference(This,enPreference,plValue)	\
    (This)->lpVtbl -> get_SearchPreference(This,enPreference,plValue)

#define IRTCUserSearchQuery_put_SearchDomain(This,bstrDomain)	\
    (This)->lpVtbl -> put_SearchDomain(This,bstrDomain)

#define IRTCUserSearchQuery_get_SearchDomain(This,pbstrDomain)	\
    (This)->lpVtbl -> get_SearchDomain(This,pbstrDomain)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchQuery_put_SearchTerm_Proxy( 
    IRTCUserSearchQuery * This,
    /* [in] */ BSTR bstrName,
    /* [in] */ BSTR bstrValue);


void __RPC_STUB IRTCUserSearchQuery_put_SearchTerm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchQuery_get_SearchTerm_Proxy( 
    IRTCUserSearchQuery * This,
    /* [in] */ BSTR bstrName,
    /* [retval][out] */ BSTR *pbstrValue);


void __RPC_STUB IRTCUserSearchQuery_get_SearchTerm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchQuery_get_SearchTerms_Proxy( 
    IRTCUserSearchQuery * This,
    /* [retval][out] */ BSTR *pbstrNames);


void __RPC_STUB IRTCUserSearchQuery_get_SearchTerms_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchQuery_put_SearchPreference_Proxy( 
    IRTCUserSearchQuery * This,
    /* [in] */ RTC_USER_SEARCH_PREFERENCE enPreference,
    /* [in] */ long lValue);


void __RPC_STUB IRTCUserSearchQuery_put_SearchPreference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchQuery_get_SearchPreference_Proxy( 
    IRTCUserSearchQuery * This,
    /* [in] */ RTC_USER_SEARCH_PREFERENCE enPreference,
    /* [retval][out] */ long *plValue);


void __RPC_STUB IRTCUserSearchQuery_get_SearchPreference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchQuery_put_SearchDomain_Proxy( 
    IRTCUserSearchQuery * This,
    /* [in] */ BSTR bstrDomain);


void __RPC_STUB IRTCUserSearchQuery_put_SearchDomain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchQuery_get_SearchDomain_Proxy( 
    IRTCUserSearchQuery * This,
    /* [retval][out] */ BSTR *pbstrDomain);


void __RPC_STUB IRTCUserSearchQuery_get_SearchDomain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCUserSearchQuery_INTERFACE_DEFINED__ */


#ifndef __IRTCUserSearchResult_INTERFACE_DEFINED__
#define __IRTCUserSearchResult_INTERFACE_DEFINED__

/* interface IRTCUserSearchResult */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCUserSearchResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("851278B2-9592-480f-8DB5-2DE86B26B54D")
    IRTCUserSearchResult : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [in] */ RTC_USER_SEARCH_COLUMN enColumn,
            /* [retval][out] */ BSTR *pbstrValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCUserSearchResultVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCUserSearchResult * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCUserSearchResult * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCUserSearchResult * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IRTCUserSearchResult * This,
            /* [in] */ RTC_USER_SEARCH_COLUMN enColumn,
            /* [retval][out] */ BSTR *pbstrValue);
        
        END_INTERFACE
    } IRTCUserSearchResultVtbl;

    interface IRTCUserSearchResult
    {
        CONST_VTBL struct IRTCUserSearchResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCUserSearchResult_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCUserSearchResult_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCUserSearchResult_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCUserSearchResult_get_Value(This,enColumn,pbstrValue)	\
    (This)->lpVtbl -> get_Value(This,enColumn,pbstrValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchResult_get_Value_Proxy( 
    IRTCUserSearchResult * This,
    /* [in] */ RTC_USER_SEARCH_COLUMN enColumn,
    /* [retval][out] */ BSTR *pbstrValue);


void __RPC_STUB IRTCUserSearchResult_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCUserSearchResult_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumUserSearchResults_INTERFACE_DEFINED__
#define __IRTCEnumUserSearchResults_INTERFACE_DEFINED__

/* interface IRTCEnumUserSearchResults */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumUserSearchResults;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("83D4D877-AA5D-4a5b-8D0E-002A8067E0E8")
    IRTCEnumUserSearchResults : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCUserSearchResult **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ IRTCEnumUserSearchResults **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCEnumUserSearchResultsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCEnumUserSearchResults * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCEnumUserSearchResults * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCEnumUserSearchResults * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IRTCEnumUserSearchResults * This,
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCUserSearchResult **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IRTCEnumUserSearchResults * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IRTCEnumUserSearchResults * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IRTCEnumUserSearchResults * This,
            /* [retval][out] */ IRTCEnumUserSearchResults **ppEnum);
        
        END_INTERFACE
    } IRTCEnumUserSearchResultsVtbl;

    interface IRTCEnumUserSearchResults
    {
        CONST_VTBL struct IRTCEnumUserSearchResultsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumUserSearchResults_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCEnumUserSearchResults_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCEnumUserSearchResults_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCEnumUserSearchResults_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

#define IRTCEnumUserSearchResults_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IRTCEnumUserSearchResults_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IRTCEnumUserSearchResults_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRTCEnumUserSearchResults_Next_Proxy( 
    IRTCEnumUserSearchResults * This,
    /* [in] */ ULONG celt,
    /* [size_is][out] */ IRTCUserSearchResult **ppElements,
    /* [full][out][in] */ ULONG *pceltFetched);


void __RPC_STUB IRTCEnumUserSearchResults_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumUserSearchResults_Reset_Proxy( 
    IRTCEnumUserSearchResults * This);


void __RPC_STUB IRTCEnumUserSearchResults_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumUserSearchResults_Skip_Proxy( 
    IRTCEnumUserSearchResults * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IRTCEnumUserSearchResults_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumUserSearchResults_Clone_Proxy( 
    IRTCEnumUserSearchResults * This,
    /* [retval][out] */ IRTCEnumUserSearchResults **ppEnum);


void __RPC_STUB IRTCEnumUserSearchResults_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCEnumUserSearchResults_INTERFACE_DEFINED__ */


#ifndef __IRTCUserSearchResultsEvent_INTERFACE_DEFINED__
#define __IRTCUserSearchResultsEvent_INTERFACE_DEFINED__

/* interface IRTCUserSearchResultsEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCUserSearchResultsEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D8C8C3CD-7FAC-4088-81C5-C24CBC0938E3")
    IRTCUserSearchResultsEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateResults( 
            /* [retval][out] */ IRTCEnumUserSearchResults **ppEnum) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Results( 
            /* [retval][out] */ IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [retval][out] */ IRTCProfile2 **ppProfile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Query( 
            /* [retval][out] */ IRTCUserSearchQuery **ppQuery) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cookie( 
            /* [retval][out] */ LONG_PTR *plCookie) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MoreAvailable( 
            /* [retval][out] */ VARIANT_BOOL *pfMoreAvailable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCUserSearchResultsEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCUserSearchResultsEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCUserSearchResultsEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCUserSearchResultsEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCUserSearchResultsEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCUserSearchResultsEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCUserSearchResultsEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCUserSearchResultsEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateResults )( 
            IRTCUserSearchResultsEvent * This,
            /* [retval][out] */ IRTCEnumUserSearchResults **ppEnum);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Results )( 
            IRTCUserSearchResultsEvent * This,
            /* [retval][out] */ IRTCCollection **ppCollection);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            IRTCUserSearchResultsEvent * This,
            /* [retval][out] */ IRTCProfile2 **ppProfile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Query )( 
            IRTCUserSearchResultsEvent * This,
            /* [retval][out] */ IRTCUserSearchQuery **ppQuery);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cookie )( 
            IRTCUserSearchResultsEvent * This,
            /* [retval][out] */ LONG_PTR *plCookie);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCUserSearchResultsEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MoreAvailable )( 
            IRTCUserSearchResultsEvent * This,
            /* [retval][out] */ VARIANT_BOOL *pfMoreAvailable);
        
        END_INTERFACE
    } IRTCUserSearchResultsEventVtbl;

    interface IRTCUserSearchResultsEvent
    {
        CONST_VTBL struct IRTCUserSearchResultsEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCUserSearchResultsEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCUserSearchResultsEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCUserSearchResultsEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCUserSearchResultsEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCUserSearchResultsEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCUserSearchResultsEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCUserSearchResultsEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCUserSearchResultsEvent_EnumerateResults(This,ppEnum)	\
    (This)->lpVtbl -> EnumerateResults(This,ppEnum)

#define IRTCUserSearchResultsEvent_get_Results(This,ppCollection)	\
    (This)->lpVtbl -> get_Results(This,ppCollection)

#define IRTCUserSearchResultsEvent_get_Profile(This,ppProfile)	\
    (This)->lpVtbl -> get_Profile(This,ppProfile)

#define IRTCUserSearchResultsEvent_get_Query(This,ppQuery)	\
    (This)->lpVtbl -> get_Query(This,ppQuery)

#define IRTCUserSearchResultsEvent_get_Cookie(This,plCookie)	\
    (This)->lpVtbl -> get_Cookie(This,plCookie)

#define IRTCUserSearchResultsEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCUserSearchResultsEvent_get_MoreAvailable(This,pfMoreAvailable)	\
    (This)->lpVtbl -> get_MoreAvailable(This,pfMoreAvailable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][hidden] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchResultsEvent_EnumerateResults_Proxy( 
    IRTCUserSearchResultsEvent * This,
    /* [retval][out] */ IRTCEnumUserSearchResults **ppEnum);


void __RPC_STUB IRTCUserSearchResultsEvent_EnumerateResults_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchResultsEvent_get_Results_Proxy( 
    IRTCUserSearchResultsEvent * This,
    /* [retval][out] */ IRTCCollection **ppCollection);


void __RPC_STUB IRTCUserSearchResultsEvent_get_Results_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchResultsEvent_get_Profile_Proxy( 
    IRTCUserSearchResultsEvent * This,
    /* [retval][out] */ IRTCProfile2 **ppProfile);


void __RPC_STUB IRTCUserSearchResultsEvent_get_Profile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchResultsEvent_get_Query_Proxy( 
    IRTCUserSearchResultsEvent * This,
    /* [retval][out] */ IRTCUserSearchQuery **ppQuery);


void __RPC_STUB IRTCUserSearchResultsEvent_get_Query_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchResultsEvent_get_Cookie_Proxy( 
    IRTCUserSearchResultsEvent * This,
    /* [retval][out] */ LONG_PTR *plCookie);


void __RPC_STUB IRTCUserSearchResultsEvent_get_Cookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchResultsEvent_get_StatusCode_Proxy( 
    IRTCUserSearchResultsEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCUserSearchResultsEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCUserSearchResultsEvent_get_MoreAvailable_Proxy( 
    IRTCUserSearchResultsEvent * This,
    /* [retval][out] */ VARIANT_BOOL *pfMoreAvailable);


void __RPC_STUB IRTCUserSearchResultsEvent_get_MoreAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCUserSearchResultsEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionReferStatusEvent_INTERFACE_DEFINED__
#define __IRTCSessionReferStatusEvent_INTERFACE_DEFINED__

/* interface IRTCSessionReferStatusEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionReferStatusEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3D8FC2CD-5D76-44AB-BB68-2A80353B34A2")
    IRTCSessionReferStatusEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [retval][out] */ IRTCSession2 **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReferStatus( 
            /* [retval][out] */ RTC_SESSION_REFER_STATUS *penReferStatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [retval][out] */ BSTR *pbstrStatusText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCSessionReferStatusEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCSessionReferStatusEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCSessionReferStatusEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCSessionReferStatusEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCSessionReferStatusEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCSessionReferStatusEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCSessionReferStatusEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionReferStatusEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            IRTCSessionReferStatusEvent * This,
            /* [retval][out] */ IRTCSession2 **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferStatus )( 
            IRTCSessionReferStatusEvent * This,
            /* [retval][out] */ RTC_SESSION_REFER_STATUS *penReferStatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IRTCSessionReferStatusEvent * This,
            /* [retval][out] */ long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            IRTCSessionReferStatusEvent * This,
            /* [retval][out] */ BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCSessionReferStatusEventVtbl;

    interface IRTCSessionReferStatusEvent
    {
        CONST_VTBL struct IRTCSessionReferStatusEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionReferStatusEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCSessionReferStatusEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCSessionReferStatusEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCSessionReferStatusEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCSessionReferStatusEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCSessionReferStatusEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCSessionReferStatusEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCSessionReferStatusEvent_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)

#define IRTCSessionReferStatusEvent_get_ReferStatus(This,penReferStatus)	\
    (This)->lpVtbl -> get_ReferStatus(This,penReferStatus)

#define IRTCSessionReferStatusEvent_get_StatusCode(This,plStatusCode)	\
    (This)->lpVtbl -> get_StatusCode(This,plStatusCode)

#define IRTCSessionReferStatusEvent_get_StatusText(This,pbstrStatusText)	\
    (This)->lpVtbl -> get_StatusText(This,pbstrStatusText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionReferStatusEvent_get_Session_Proxy( 
    IRTCSessionReferStatusEvent * This,
    /* [retval][out] */ IRTCSession2 **ppSession);


void __RPC_STUB IRTCSessionReferStatusEvent_get_Session_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionReferStatusEvent_get_ReferStatus_Proxy( 
    IRTCSessionReferStatusEvent * This,
    /* [retval][out] */ RTC_SESSION_REFER_STATUS *penReferStatus);


void __RPC_STUB IRTCSessionReferStatusEvent_get_ReferStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionReferStatusEvent_get_StatusCode_Proxy( 
    IRTCSessionReferStatusEvent * This,
    /* [retval][out] */ long *plStatusCode);


void __RPC_STUB IRTCSessionReferStatusEvent_get_StatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionReferStatusEvent_get_StatusText_Proxy( 
    IRTCSessionReferStatusEvent * This,
    /* [retval][out] */ BSTR *pbstrStatusText);


void __RPC_STUB IRTCSessionReferStatusEvent_get_StatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCSessionReferStatusEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionReferredEvent_INTERFACE_DEFINED__
#define __IRTCSessionReferredEvent_INTERFACE_DEFINED__

/* interface IRTCSessionReferredEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionReferredEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("176A6828-4FCC-4F28-A862-04597A6CF1C4")
    IRTCSessionReferredEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [retval][out] */ IRTCSession2 **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReferredByURI( 
            /* [retval][out] */ BSTR *pbstrReferredByURI) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReferToURI( 
            /* [retval][out] */ BSTR *pbstrReferoURI) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReferCookie( 
            /* [retval][out] */ BSTR *pbstrReferCookie) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Accept( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reject( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetReferredSessionState( 
            /* [in] */ RTC_SESSION_STATE enState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCSessionReferredEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCSessionReferredEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCSessionReferredEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCSessionReferredEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCSessionReferredEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCSessionReferredEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCSessionReferredEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionReferredEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            IRTCSessionReferredEvent * This,
            /* [retval][out] */ IRTCSession2 **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferredByURI )( 
            IRTCSessionReferredEvent * This,
            /* [retval][out] */ BSTR *pbstrReferredByURI);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferToURI )( 
            IRTCSessionReferredEvent * This,
            /* [retval][out] */ BSTR *pbstrReferoURI);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferCookie )( 
            IRTCSessionReferredEvent * This,
            /* [retval][out] */ BSTR *pbstrReferCookie);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Accept )( 
            IRTCSessionReferredEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reject )( 
            IRTCSessionReferredEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetReferredSessionState )( 
            IRTCSessionReferredEvent * This,
            /* [in] */ RTC_SESSION_STATE enState);
        
        END_INTERFACE
    } IRTCSessionReferredEventVtbl;

    interface IRTCSessionReferredEvent
    {
        CONST_VTBL struct IRTCSessionReferredEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionReferredEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCSessionReferredEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCSessionReferredEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCSessionReferredEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCSessionReferredEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCSessionReferredEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCSessionReferredEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRTCSessionReferredEvent_get_Session(This,ppSession)	\
    (This)->lpVtbl -> get_Session(This,ppSession)

#define IRTCSessionReferredEvent_get_ReferredByURI(This,pbstrReferredByURI)	\
    (This)->lpVtbl -> get_ReferredByURI(This,pbstrReferredByURI)

#define IRTCSessionReferredEvent_get_ReferToURI(This,pbstrReferoURI)	\
    (This)->lpVtbl -> get_ReferToURI(This,pbstrReferoURI)

#define IRTCSessionReferredEvent_get_ReferCookie(This,pbstrReferCookie)	\
    (This)->lpVtbl -> get_ReferCookie(This,pbstrReferCookie)

#define IRTCSessionReferredEvent_Accept(This)	\
    (This)->lpVtbl -> Accept(This)

#define IRTCSessionReferredEvent_Reject(This)	\
    (This)->lpVtbl -> Reject(This)

#define IRTCSessionReferredEvent_SetReferredSessionState(This,enState)	\
    (This)->lpVtbl -> SetReferredSessionState(This,enState)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionReferredEvent_get_Session_Proxy( 
    IRTCSessionReferredEvent * This,
    /* [retval][out] */ IRTCSession2 **ppSession);


void __RPC_STUB IRTCSessionReferredEvent_get_Session_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionReferredEvent_get_ReferredByURI_Proxy( 
    IRTCSessionReferredEvent * This,
    /* [retval][out] */ BSTR *pbstrReferredByURI);


void __RPC_STUB IRTCSessionReferredEvent_get_ReferredByURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionReferredEvent_get_ReferToURI_Proxy( 
    IRTCSessionReferredEvent * This,
    /* [retval][out] */ BSTR *pbstrReferoURI);


void __RPC_STUB IRTCSessionReferredEvent_get_ReferToURI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRTCSessionReferredEvent_get_ReferCookie_Proxy( 
    IRTCSessionReferredEvent * This,
    /* [retval][out] */ BSTR *pbstrReferCookie);


void __RPC_STUB IRTCSessionReferredEvent_get_ReferCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCSessionReferredEvent_Accept_Proxy( 
    IRTCSessionReferredEvent * This);


void __RPC_STUB IRTCSessionReferredEvent_Accept_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCSessionReferredEvent_Reject_Proxy( 
    IRTCSessionReferredEvent * This);


void __RPC_STUB IRTCSessionReferredEvent_Reject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCSessionReferredEvent_SetReferredSessionState_Proxy( 
    IRTCSessionReferredEvent * This,
    /* [in] */ RTC_SESSION_STATE enState);


void __RPC_STUB IRTCSessionReferredEvent_SetReferredSessionState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCSessionReferredEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionDescriptionManager_INTERFACE_DEFINED__
#define __IRTCSessionDescriptionManager_INTERFACE_DEFINED__

/* interface IRTCSessionDescriptionManager */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionDescriptionManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA7F518E-D336-4070-93A6-865395C843F9")
    IRTCSessionDescriptionManager : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EvaluateSessionDescription( 
            /* [in] */ BSTR bstrContentType,
            /* [in] */ BSTR bstrSessionDescription,
            /* [out][in] */ VARIANT_BOOL *pfApplicationSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCSessionDescriptionManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCSessionDescriptionManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCSessionDescriptionManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCSessionDescriptionManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EvaluateSessionDescription )( 
            IRTCSessionDescriptionManager * This,
            /* [in] */ BSTR bstrContentType,
            /* [in] */ BSTR bstrSessionDescription,
            /* [out][in] */ VARIANT_BOOL *pfApplicationSession);
        
        END_INTERFACE
    } IRTCSessionDescriptionManagerVtbl;

    interface IRTCSessionDescriptionManager
    {
        CONST_VTBL struct IRTCSessionDescriptionManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionDescriptionManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCSessionDescriptionManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCSessionDescriptionManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCSessionDescriptionManager_EvaluateSessionDescription(This,bstrContentType,bstrSessionDescription,pfApplicationSession)	\
    (This)->lpVtbl -> EvaluateSessionDescription(This,bstrContentType,bstrSessionDescription,pfApplicationSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRTCSessionDescriptionManager_EvaluateSessionDescription_Proxy( 
    IRTCSessionDescriptionManager * This,
    /* [in] */ BSTR bstrContentType,
    /* [in] */ BSTR bstrSessionDescription,
    /* [out][in] */ VARIANT_BOOL *pfApplicationSession);


void __RPC_STUB IRTCSessionDescriptionManager_EvaluateSessionDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCSessionDescriptionManager_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumPresenceDevices_INTERFACE_DEFINED__
#define __IRTCEnumPresenceDevices_INTERFACE_DEFINED__

/* interface IRTCEnumPresenceDevices */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumPresenceDevices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("708C2AB7-8BF8-42f8-8C7D-635197AD5539")
    IRTCEnumPresenceDevices : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCPresenceDevice **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ IRTCEnumPresenceDevices **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCEnumPresenceDevicesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCEnumPresenceDevices * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCEnumPresenceDevices * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCEnumPresenceDevices * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IRTCEnumPresenceDevices * This,
            /* [in] */ ULONG celt,
            /* [size_is][out] */ IRTCPresenceDevice **ppElements,
            /* [full][out][in] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IRTCEnumPresenceDevices * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IRTCEnumPresenceDevices * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IRTCEnumPresenceDevices * This,
            /* [retval][out] */ IRTCEnumPresenceDevices **ppEnum);
        
        END_INTERFACE
    } IRTCEnumPresenceDevicesVtbl;

    interface IRTCEnumPresenceDevices
    {
        CONST_VTBL struct IRTCEnumPresenceDevicesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumPresenceDevices_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCEnumPresenceDevices_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCEnumPresenceDevices_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCEnumPresenceDevices_Next(This,celt,ppElements,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched)

#define IRTCEnumPresenceDevices_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IRTCEnumPresenceDevices_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IRTCEnumPresenceDevices_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRTCEnumPresenceDevices_Next_Proxy( 
    IRTCEnumPresenceDevices * This,
    /* [in] */ ULONG celt,
    /* [size_is][out] */ IRTCPresenceDevice **ppElements,
    /* [full][out][in] */ ULONG *pceltFetched);


void __RPC_STUB IRTCEnumPresenceDevices_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumPresenceDevices_Reset_Proxy( 
    IRTCEnumPresenceDevices * This);


void __RPC_STUB IRTCEnumPresenceDevices_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumPresenceDevices_Skip_Proxy( 
    IRTCEnumPresenceDevices * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IRTCEnumPresenceDevices_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRTCEnumPresenceDevices_Clone_Proxy( 
    IRTCEnumPresenceDevices * This,
    /* [retval][out] */ IRTCEnumPresenceDevices **ppEnum);


void __RPC_STUB IRTCEnumPresenceDevices_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCEnumPresenceDevices_INTERFACE_DEFINED__ */


#ifndef __IRTCPresenceDevice_INTERFACE_DEFINED__
#define __IRTCPresenceDevice_INTERFACE_DEFINED__

/* interface IRTCPresenceDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCPresenceDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BC6A90DD-AD9A-48da-9B0C-2515E38521AD")
    IRTCPresenceDevice : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ RTC_PRESENCE_STATUS *penStatus) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Notes( 
            /* [retval][out] */ BSTR *pbstrNotes) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PresenceProperty( 
            /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
            /* [retval][out] */ BSTR *pbstrProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPresenceData( 
            /* [out] */ BSTR *pbstrNamespace,
            /* [out] */ BSTR *pbstrData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTCPresenceDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCPresenceDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCPresenceDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCPresenceDevice * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IRTCPresenceDevice * This,
            /* [retval][out] */ RTC_PRESENCE_STATUS *penStatus);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Notes )( 
            IRTCPresenceDevice * This,
            /* [retval][out] */ BSTR *pbstrNotes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresenceProperty )( 
            IRTCPresenceDevice * This,
            /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
            /* [retval][out] */ BSTR *pbstrProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPresenceData )( 
            IRTCPresenceDevice * This,
            /* [out] */ BSTR *pbstrNamespace,
            /* [out] */ BSTR *pbstrData);
        
        END_INTERFACE
    } IRTCPresenceDeviceVtbl;

    interface IRTCPresenceDevice
    {
        CONST_VTBL struct IRTCPresenceDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPresenceDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCPresenceDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCPresenceDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCPresenceDevice_get_Status(This,penStatus)	\
    (This)->lpVtbl -> get_Status(This,penStatus)

#define IRTCPresenceDevice_get_Notes(This,pbstrNotes)	\
    (This)->lpVtbl -> get_Notes(This,pbstrNotes)

#define IRTCPresenceDevice_get_PresenceProperty(This,enProperty,pbstrProperty)	\
    (This)->lpVtbl -> get_PresenceProperty(This,enProperty,pbstrProperty)

#define IRTCPresenceDevice_GetPresenceData(This,pbstrNamespace,pbstrData)	\
    (This)->lpVtbl -> GetPresenceData(This,pbstrNamespace,pbstrData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresenceDevice_get_Status_Proxy( 
    IRTCPresenceDevice * This,
    /* [retval][out] */ RTC_PRESENCE_STATUS *penStatus);


void __RPC_STUB IRTCPresenceDevice_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresenceDevice_get_Notes_Proxy( 
    IRTCPresenceDevice * This,
    /* [retval][out] */ BSTR *pbstrNotes);


void __RPC_STUB IRTCPresenceDevice_get_Notes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRTCPresenceDevice_get_PresenceProperty_Proxy( 
    IRTCPresenceDevice * This,
    /* [in] */ RTC_PRESENCE_PROPERTY enProperty,
    /* [retval][out] */ BSTR *pbstrProperty);


void __RPC_STUB IRTCPresenceDevice_get_PresenceProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTCPresenceDevice_GetPresenceData_Proxy( 
    IRTCPresenceDevice * This,
    /* [out] */ BSTR *pbstrNamespace,
    /* [out] */ BSTR *pbstrData);


void __RPC_STUB IRTCPresenceDevice_GetPresenceData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTCPresenceDevice_INTERFACE_DEFINED__ */



#ifndef __RTCCORELib_LIBRARY_DEFINED__
#define __RTCCORELib_LIBRARY_DEFINED__

/* library RTCCORELib */
/* [helpstring][version][uuid] */ 

























































EXTERN_C const IID LIBID_RTCCORELib;

#ifndef __IRTCDispatchEventNotification_DISPINTERFACE_DEFINED__
#define __IRTCDispatchEventNotification_DISPINTERFACE_DEFINED__

/* dispinterface IRTCDispatchEventNotification */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_IRTCDispatchEventNotification;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("176ddfbe-fec0-4d55-bc87-84cff1ef7f91")
    IRTCDispatchEventNotification : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IRTCDispatchEventNotificationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRTCDispatchEventNotification * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRTCDispatchEventNotification * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRTCDispatchEventNotification * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRTCDispatchEventNotification * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRTCDispatchEventNotification * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRTCDispatchEventNotification * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCDispatchEventNotification * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IRTCDispatchEventNotificationVtbl;

    interface IRTCDispatchEventNotification
    {
        CONST_VTBL struct IRTCDispatchEventNotificationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCDispatchEventNotification_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTCDispatchEventNotification_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTCDispatchEventNotification_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTCDispatchEventNotification_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRTCDispatchEventNotification_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRTCDispatchEventNotification_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRTCDispatchEventNotification_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IRTCDispatchEventNotification_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_RTCClient;

#ifdef __cplusplus

class DECLSPEC_UUID("7a42ea29-a2b7-40c4-b091-f6f024aa89be")
RTCClient;
#endif
#endif /* __RTCCORELib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


