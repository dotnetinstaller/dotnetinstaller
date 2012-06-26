/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1993-1999, Microsoft Corporation

Module Name:

    aclapi.h

Abstract:

    Public
    Structure/constant definitions and typedefines for the Win32 Access
    Control APIs

--*/
#ifndef __ACCESS_CONTROL_API__
#define __ACCESS_CONTROL_API__

#include <windows.h>
#include <accctrl.h>

#ifdef __cplusplus
extern "C" {
#endif

//
// Progress Function:
// Caller of tree operation implements this Progress function, then
// passes its function pointer to tree operation.
// Tree operation invokes Progress function to provide progress and error
// information to the caller during the potentially long execution
// of the tree operation.  Tree operation provides the name of the object
// last processed and the error status of the operation on that object.
// Tree operation also passes the current InvokeSetting value.
// Caller may change the InvokeSetting value, for example, from "Always"
// to "Only On Error."
//

typedef VOID (*FN_PROGRESS) (
    IN LPWSTR                   pObjectName,    // name of object just processed
    IN DWORD                    Status,         // status of operation on object
    IN OUT PPROG_INVOKE_SETTING pInvokeSetting, // Never, always,
    IN PVOID                    Args,           // Caller specific data
    IN BOOL                     SecuritySet     // Whether security was set
    );


WINADVAPI
DWORD
WINAPI
SetEntriesInAclA(
    __in ULONG               cCountOfExplicitEntries,
    __in_ecount_opt(cCountOfExplicitEntries)  PEXPLICIT_ACCESS_A  pListOfExplicitEntries,
    __in_opt  PACL           OldAcl,
    __out PACL              * NewAcl
    );
WINADVAPI
DWORD
WINAPI
SetEntriesInAclW(
    __in ULONG               cCountOfExplicitEntries,
    __in_ecount_opt(cCountOfExplicitEntries)  PEXPLICIT_ACCESS_W  pListOfExplicitEntries,
    __in_opt  PACL           OldAcl,
    __out PACL              * NewAcl
    );
#ifdef UNICODE
#define SetEntriesInAcl  SetEntriesInAclW
#else
#define SetEntriesInAcl  SetEntriesInAclA
#endif // !UNICODE


WINADVAPI
DWORD
WINAPI
GetExplicitEntriesFromAclA(
    __in PACL                  pacl,
    __out PULONG                pcCountOfExplicitEntries,
    __out_ecount(*pcCountOfExplicitEntries) PEXPLICIT_ACCESS_A  * pListOfExplicitEntries
    );
WINADVAPI
DWORD
WINAPI
GetExplicitEntriesFromAclW(
    __in PACL                  pacl,
    __out PULONG                pcCountOfExplicitEntries,
    __out_ecount(*pcCountOfExplicitEntries) PEXPLICIT_ACCESS_W  * pListOfExplicitEntries
    );
#ifdef UNICODE
#define GetExplicitEntriesFromAcl  GetExplicitEntriesFromAclW
#else
#define GetExplicitEntriesFromAcl  GetExplicitEntriesFromAclA
#endif // !UNICODE


WINADVAPI
DWORD
WINAPI
GetEffectiveRightsFromAclA(
    __in  PACL          pacl,
    __in  PTRUSTEE_A    pTrustee,
    __out PACCESS_MASK  pAccessRights
    );
WINADVAPI
DWORD
WINAPI
GetEffectiveRightsFromAclW(
    __in  PACL          pacl,
    __in  PTRUSTEE_W    pTrustee,
    __out PACCESS_MASK  pAccessRights
    );
#ifdef UNICODE
#define GetEffectiveRightsFromAcl  GetEffectiveRightsFromAclW
#else
#define GetEffectiveRightsFromAcl  GetEffectiveRightsFromAclA
#endif // !UNICODE


WINADVAPI
DWORD
WINAPI
GetAuditedPermissionsFromAclA(
    __in  PACL          pacl,
    __in  PTRUSTEE_A    pTrustee,
    __out PACCESS_MASK  pSuccessfulAuditedRights,
    __out PACCESS_MASK  pFailedAuditRights
    );
WINADVAPI
DWORD
WINAPI
GetAuditedPermissionsFromAclW(
    __in  PACL          pacl,
    __in  PTRUSTEE_W    pTrustee,
    __out PACCESS_MASK  pSuccessfulAuditedRights,
    __out PACCESS_MASK  pFailedAuditRights
    );
#ifdef UNICODE
#define GetAuditedPermissionsFromAcl  GetAuditedPermissionsFromAclW
#else
#define GetAuditedPermissionsFromAcl  GetAuditedPermissionsFromAclA
#endif // !UNICODE

WINADVAPI
DWORD
WINAPI
GetNamedSecurityInfoA(
    __in  LPSTR                pObjectName,
    __in  SE_OBJECT_TYPE         ObjectType,
    __in  SECURITY_INFORMATION   SecurityInfo,
    __out_opt PSID             * ppsidOwner,
    __out_opt PSID             * ppsidGroup,
    __out_opt PACL             * ppDacl,
    __out_opt PACL             * ppSacl,
    __out PSECURITY_DESCRIPTOR * ppSecurityDescriptor
    );
WINADVAPI
DWORD
WINAPI
GetNamedSecurityInfoW(
    __in  LPWSTR                pObjectName,
    __in  SE_OBJECT_TYPE         ObjectType,
    __in  SECURITY_INFORMATION   SecurityInfo,
    __out_opt PSID             * ppsidOwner,
    __out_opt PSID             * ppsidGroup,
    __out_opt PACL             * ppDacl,
    __out_opt PACL             * ppSacl,
    __out PSECURITY_DESCRIPTOR * ppSecurityDescriptor
    );
#ifdef UNICODE
#define GetNamedSecurityInfo  GetNamedSecurityInfoW
#else
#define GetNamedSecurityInfo  GetNamedSecurityInfoA
#endif // !UNICODE

WINADVAPI
DWORD
WINAPI
GetSecurityInfo(
    __in  HANDLE                 handle,
    __in  SE_OBJECT_TYPE         ObjectType,
    __in  SECURITY_INFORMATION   SecurityInfo,
    __deref_out_opt PSID                 * ppsidOwner,
    __deref_out_opt PSID                 * ppsidGroup,
    __deref_out_opt PACL                 * ppDacl,
    __deref_out_opt PACL                 * ppSacl,
    __deref_out PSECURITY_DESCRIPTOR * ppSecurityDescriptor
    );

WINADVAPI
DWORD
WINAPI
SetNamedSecurityInfoA(
    __in LPSTR               pObjectName,
    __in SE_OBJECT_TYPE        ObjectType,
    __in SECURITY_INFORMATION  SecurityInfo,
    __in_opt PSID              psidOwner,
    __in_opt PSID              psidGroup,
    __in_opt PACL              pDacl,
    __in_opt PACL              pSacl
    );
WINADVAPI
DWORD
WINAPI
SetNamedSecurityInfoW(
    __in LPWSTR               pObjectName,
    __in SE_OBJECT_TYPE        ObjectType,
    __in SECURITY_INFORMATION  SecurityInfo,
    __in_opt PSID              psidOwner,
    __in_opt PSID              psidGroup,
    __in_opt PACL              pDacl,
    __in_opt PACL              pSacl
    );
#ifdef UNICODE
#define SetNamedSecurityInfo  SetNamedSecurityInfoW
#else
#define SetNamedSecurityInfo  SetNamedSecurityInfoA
#endif // !UNICODE

WINADVAPI
DWORD
WINAPI
SetSecurityInfo(
    __in HANDLE                handle,
    __in SE_OBJECT_TYPE        ObjectType,
    __in SECURITY_INFORMATION  SecurityInfo,
    __in PSID                  psidOwner,
    __in PSID                  psidGroup,
    __in PACL                  pDacl,
    __in PACL                  pSacl
    );


WINADVAPI
DWORD
WINAPI
GetInheritanceSourceA(
    __in LPSTR                  pObjectName,
    __in SE_OBJECT_TYPE           ObjectType,
    __in SECURITY_INFORMATION     SecurityInfo,
    __in BOOL                     Container,
    __in_ecount_opt(GuidCount) GUID	** pObjectClassGuids,
    __in DWORD                    GuidCount,
    __in PACL                     pAcl,
    __in_opt PFN_OBJECT_MGR_FUNCTS    pfnArray,
    __in PGENERIC_MAPPING         pGenericMapping,
    __out PINHERITED_FROMA         pInheritArray
    );
WINADVAPI
DWORD
WINAPI
GetInheritanceSourceW(
    __in LPWSTR                  pObjectName,
    __in SE_OBJECT_TYPE           ObjectType,
    __in SECURITY_INFORMATION     SecurityInfo,
    __in BOOL                     Container,
    __in_ecount_opt(GuidCount) GUID	** pObjectClassGuids,
    __in DWORD                    GuidCount,
    __in PACL                     pAcl,
    __in_opt PFN_OBJECT_MGR_FUNCTS    pfnArray,
    __in PGENERIC_MAPPING         pGenericMapping,
    __out PINHERITED_FROMW         pInheritArray
    );
#ifdef UNICODE
#define GetInheritanceSource  GetInheritanceSourceW
#else
#define GetInheritanceSource  GetInheritanceSourceA
#endif // !UNICODE

WINADVAPI
DWORD
WINAPI
FreeInheritedFromArray(
    __in_ecount(AceCnt) PINHERITED_FROMW pInheritArray,
    __in USHORT AceCnt,
    __in_opt PFN_OBJECT_MGR_FUNCTS   pfnArray OPTIONAL
    );

WINADVAPI
DWORD
WINAPI
TreeResetNamedSecurityInfoA(
    __in LPSTR              pObjectName,
    __in SE_OBJECT_TYPE       ObjectType,
    __in SECURITY_INFORMATION SecurityInfo,
    __in_opt PSID             pOwner,
    __in_opt PSID             pGroup,
    __in_opt PACL             pDacl,
    __in_opt PACL             pSacl,
    __in BOOL                 KeepExplicit,
    __in_opt FN_PROGRESS      fnProgress,
    __in PROG_INVOKE_SETTING  ProgressInvokeSetting,
    __in_opt PVOID            Args
    );
WINADVAPI
DWORD
WINAPI
TreeResetNamedSecurityInfoW(
    __in LPWSTR              pObjectName,
    __in SE_OBJECT_TYPE       ObjectType,
    __in SECURITY_INFORMATION SecurityInfo,
    __in_opt PSID             pOwner,
    __in_opt PSID             pGroup,
    __in_opt PACL             pDacl,
    __in_opt PACL             pSacl,
    __in BOOL                 KeepExplicit,
    __in_opt FN_PROGRESS      fnProgress,
    __in PROG_INVOKE_SETTING  ProgressInvokeSetting,
    __in_opt PVOID            Args
    );
#ifdef UNICODE
#define TreeResetNamedSecurityInfo  TreeResetNamedSecurityInfoW
#else
#define TreeResetNamedSecurityInfo  TreeResetNamedSecurityInfoA
#endif // !UNICODE

//----------------------------------------------------------------------------
// The following API are provided for trusted servers to use to
// implement access control on their own objects.
//----------------------------------------------------------------------------

WINADVAPI
DWORD
WINAPI
BuildSecurityDescriptorA(
    __in_opt PTRUSTEE_A              pOwner,
    __in_opt PTRUSTEE_A              pGroup,
    __in ULONG                   cCountOfAccessEntries,
    __in_ecount_opt(cCountOfAccessEntries) PEXPLICIT_ACCESS_A      pListOfAccessEntries,
    __in ULONG                   cCountOfAuditEntries,
    __in_ecount_opt(cCountOfAuditEntries) PEXPLICIT_ACCESS_A      pListOfAuditEntries,
    __in_opt PSECURITY_DESCRIPTOR    pOldSD,
    __out PULONG                  pSizeNewSD,
    __deref_out_bcount(*pSizeNewSD) PSECURITY_DESCRIPTOR  * pNewSD
    );
WINADVAPI
DWORD
WINAPI
BuildSecurityDescriptorW(
    __in_opt PTRUSTEE_W              pOwner,
    __in_opt PTRUSTEE_W              pGroup,
    __in ULONG                   cCountOfAccessEntries,
    __in_ecount_opt(cCountOfAccessEntries) PEXPLICIT_ACCESS_W      pListOfAccessEntries,
    __in ULONG                   cCountOfAuditEntries,
    __in_ecount_opt(cCountOfAuditEntries) PEXPLICIT_ACCESS_W      pListOfAuditEntries,
    __in_opt PSECURITY_DESCRIPTOR    pOldSD,
    __out PULONG                  pSizeNewSD,
    __deref_out_bcount(*pSizeNewSD) PSECURITY_DESCRIPTOR  * pNewSD
    );
#ifdef UNICODE
#define BuildSecurityDescriptor  BuildSecurityDescriptorW
#else
#define BuildSecurityDescriptor  BuildSecurityDescriptorA
#endif // !UNICODE

WINADVAPI
DWORD
WINAPI
LookupSecurityDescriptorPartsA(
    __out_opt PTRUSTEE_A         * ppOwner,
    __out_opt PTRUSTEE_A         * ppGroup,
    __out_opt PULONG               pcCountOfAccessEntries,
    __deref_out_ecount_opt(*pcCountOfAccessEntries) PEXPLICIT_ACCESS_A * ppListOfAccessEntries,
    __out_opt PULONG               pcCountOfAuditEntries,
    __deref_out_ecount_opt(*pcCountOfAuditEntries) PEXPLICIT_ACCESS_A * ppListOfAuditEntries,
    __in  PSECURITY_DESCRIPTOR pSD
    );
WINADVAPI
DWORD
WINAPI
LookupSecurityDescriptorPartsW(
    __out_opt PTRUSTEE_W         * ppOwner,
    __out_opt PTRUSTEE_W         * ppGroup,
    __out_opt PULONG               pcCountOfAccessEntries,
    __deref_out_ecount_opt(*pcCountOfAccessEntries) PEXPLICIT_ACCESS_W * ppListOfAccessEntries,
    __out_opt PULONG               pcCountOfAuditEntries,
    __deref_out_ecount_opt(*pcCountOfAuditEntries) PEXPLICIT_ACCESS_W * ppListOfAuditEntries,
    __in  PSECURITY_DESCRIPTOR pSD
    );
#ifdef UNICODE
#define LookupSecurityDescriptorParts  LookupSecurityDescriptorPartsW
#else
#define LookupSecurityDescriptorParts  LookupSecurityDescriptorPartsA
#endif // !UNICODE


//----------------------------------------------------------------------------
// The following helper API are provided for building
// access control structures.
//----------------------------------------------------------------------------

WINADVAPI
VOID
WINAPI
BuildExplicitAccessWithNameA(
    __inout    PEXPLICIT_ACCESS_A  pExplicitAccess,
    __in_opt   LPSTR             pTrusteeName,
    __in       DWORD               AccessPermissions,
    __in       ACCESS_MODE         AccessMode,
    __in       DWORD               Inheritance
    );
WINADVAPI
VOID
WINAPI
BuildExplicitAccessWithNameW(
    __inout    PEXPLICIT_ACCESS_W  pExplicitAccess,
    __in_opt   LPWSTR             pTrusteeName,
    __in       DWORD               AccessPermissions,
    __in       ACCESS_MODE         AccessMode,
    __in       DWORD               Inheritance
    );
#ifdef UNICODE
#define BuildExplicitAccessWithName  BuildExplicitAccessWithNameW
#else
#define BuildExplicitAccessWithName  BuildExplicitAccessWithNameA
#endif // !UNICODE

WINADVAPI
VOID
WINAPI
BuildImpersonateExplicitAccessWithNameA(
    __inout PEXPLICIT_ACCESS_A  pExplicitAccess,
    __in_opt LPSTR             pTrusteeName,
    __in_opt PTRUSTEE_A          pTrustee,
    __in    DWORD               AccessPermissions,
    __in    ACCESS_MODE         AccessMode,
    __in    DWORD               Inheritance
    );
WINADVAPI
VOID
WINAPI
BuildImpersonateExplicitAccessWithNameW(
    __inout PEXPLICIT_ACCESS_W  pExplicitAccess,
    __in_opt LPWSTR             pTrusteeName,
    __in_opt PTRUSTEE_W          pTrustee,
    __in    DWORD               AccessPermissions,
    __in    ACCESS_MODE         AccessMode,
    __in    DWORD               Inheritance
    );
#ifdef UNICODE
#define BuildImpersonateExplicitAccessWithName  BuildImpersonateExplicitAccessWithNameW
#else
#define BuildImpersonateExplicitAccessWithName  BuildImpersonateExplicitAccessWithNameA
#endif // !UNICODE

WINADVAPI
VOID
WINAPI
BuildTrusteeWithNameA(
    __inout	PTRUSTEE_A  pTrustee,
    __in_opt LPSTR     pName
    );
WINADVAPI
VOID
WINAPI
BuildTrusteeWithNameW(
    __inout	PTRUSTEE_W  pTrustee,
    __in_opt LPWSTR     pName
    );
#ifdef UNICODE
#define BuildTrusteeWithName  BuildTrusteeWithNameW
#else
#define BuildTrusteeWithName  BuildTrusteeWithNameA
#endif // !UNICODE

WINADVAPI
VOID
WINAPI
BuildImpersonateTrusteeA(
    __inout PTRUSTEE_A  pTrustee,
    __in_opt PTRUSTEE_A  pImpersonateTrustee
    );
WINADVAPI
VOID
WINAPI
BuildImpersonateTrusteeW(
    __inout PTRUSTEE_W  pTrustee,
    __in_opt PTRUSTEE_W  pImpersonateTrustee
    );
#ifdef UNICODE
#define BuildImpersonateTrustee  BuildImpersonateTrusteeW
#else
#define BuildImpersonateTrustee  BuildImpersonateTrusteeA
#endif // !UNICODE

WINADVAPI
VOID
WINAPI
BuildTrusteeWithSidA(
    __inout PTRUSTEE_A  pTrustee,
    __in_opt PSID        pSid
    );
WINADVAPI
VOID
WINAPI
BuildTrusteeWithSidW(
    __inout PTRUSTEE_W  pTrustee,
    __in_opt PSID        pSid
    );
#ifdef UNICODE
#define BuildTrusteeWithSid  BuildTrusteeWithSidW
#else
#define BuildTrusteeWithSid  BuildTrusteeWithSidA
#endif // !UNICODE

WINADVAPI
VOID
WINAPI
BuildTrusteeWithObjectsAndSidA(
    __inout PTRUSTEE_A         pTrustee,
    __in_opt POBJECTS_AND_SID   pObjSid,
    __in_opt GUID             * pObjectGuid,
    __in_opt GUID             * pInheritedObjectGuid,
    __in_opt PSID               pSid
    );
WINADVAPI
VOID
WINAPI
BuildTrusteeWithObjectsAndSidW(
    __inout PTRUSTEE_W         pTrustee,
    __in_opt POBJECTS_AND_SID   pObjSid,
    __in_opt GUID             * pObjectGuid,
    __in_opt GUID             * pInheritedObjectGuid,
    __in_opt PSID               pSid
    );
#ifdef UNICODE
#define BuildTrusteeWithObjectsAndSid  BuildTrusteeWithObjectsAndSidW
#else
#define BuildTrusteeWithObjectsAndSid  BuildTrusteeWithObjectsAndSidA
#endif // !UNICODE

WINADVAPI
VOID
WINAPI
BuildTrusteeWithObjectsAndNameA(
    __inout PTRUSTEE_A          pTrustee,
    __in_opt POBJECTS_AND_NAME_A pObjName,
    __in_opt SE_OBJECT_TYPE      ObjectType,
    __in_opt LPSTR             ObjectTypeName,
    __in_opt LPSTR             InheritedObjectTypeName,
    __in_opt LPSTR             Name
    );
WINADVAPI
VOID
WINAPI
BuildTrusteeWithObjectsAndNameW(
    __inout PTRUSTEE_W          pTrustee,
    __in_opt POBJECTS_AND_NAME_W pObjName,
    __in_opt SE_OBJECT_TYPE      ObjectType,
    __in_opt LPWSTR             ObjectTypeName,
    __in_opt LPWSTR             InheritedObjectTypeName,
    __in_opt LPWSTR             Name
    );
#ifdef UNICODE
#define BuildTrusteeWithObjectsAndName  BuildTrusteeWithObjectsAndNameW
#else
#define BuildTrusteeWithObjectsAndName  BuildTrusteeWithObjectsAndNameA
#endif // !UNICODE

WINADVAPI
LPSTR
WINAPI
GetTrusteeNameA(
    __in PTRUSTEE_A  pTrustee
    );
WINADVAPI
LPWSTR
WINAPI
GetTrusteeNameW(
    __in PTRUSTEE_W  pTrustee
    );
#ifdef UNICODE
#define GetTrusteeName  GetTrusteeNameW
#else
#define GetTrusteeName  GetTrusteeNameA
#endif // !UNICODE

WINADVAPI
TRUSTEE_TYPE
WINAPI
GetTrusteeTypeA(
    __in_opt PTRUSTEE_A  pTrustee
    );
WINADVAPI
TRUSTEE_TYPE
WINAPI
GetTrusteeTypeW(
    __in_opt PTRUSTEE_W  pTrustee
    );
#ifdef UNICODE
#define GetTrusteeType  GetTrusteeTypeW
#else
#define GetTrusteeType  GetTrusteeTypeA
#endif // !UNICODE

WINADVAPI
TRUSTEE_FORM
WINAPI
GetTrusteeFormA(
    __in PTRUSTEE_A  pTrustee
    );
WINADVAPI
TRUSTEE_FORM
WINAPI
GetTrusteeFormW(
    __in PTRUSTEE_W  pTrustee
    );
#ifdef UNICODE
#define GetTrusteeForm  GetTrusteeFormW
#else
#define GetTrusteeForm  GetTrusteeFormA
#endif // !UNICODE

WINADVAPI
MULTIPLE_TRUSTEE_OPERATION
WINAPI
GetMultipleTrusteeOperationA(
    __in_opt PTRUSTEE_A  pTrustee
    );
WINADVAPI
MULTIPLE_TRUSTEE_OPERATION
WINAPI
GetMultipleTrusteeOperationW(
    __in_opt PTRUSTEE_W  pTrustee
    );
#ifdef UNICODE
#define GetMultipleTrusteeOperation  GetMultipleTrusteeOperationW
#else
#define GetMultipleTrusteeOperation  GetMultipleTrusteeOperationA
#endif // !UNICODE

WINADVAPI
PTRUSTEE_A
WINAPI
GetMultipleTrusteeA(
    __in_opt PTRUSTEE_A  pTrustee
    );
WINADVAPI
PTRUSTEE_W
WINAPI
GetMultipleTrusteeW(
    __in_opt PTRUSTEE_W  pTrustee
    );
#ifdef UNICODE
#define GetMultipleTrustee  GetMultipleTrusteeW
#else
#define GetMultipleTrustee  GetMultipleTrusteeA
#endif // !UNICODE

//
// Temporary requirement for the technology preview, no longer required
//
#define AccProvInit(err)

#ifdef __cplusplus
}
#endif


#endif // __ACCESS_CONTROL_API__

