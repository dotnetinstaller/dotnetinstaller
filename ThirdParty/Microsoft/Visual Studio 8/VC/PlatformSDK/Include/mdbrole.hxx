/*
 *	MDBEVENT.HXX
 *
 *	MDB Eventlogging APIs
 */
#ifndef	_MDBROLE_HXX_
#define _MDBROLE_HXX_
#include "fastcall.h"

#ifdef	MDBROLE_BUILD
#define	ROLDLLEXP	__declspec(dllexport)
#else
#define	ROLDLLEXP	__declspec(dllimport)
#endif

#if defined(_M_IX86)
#define ROLEAPI		__fastcall
#else
#define ROLEAPI
#endif

//
//	Returns 1 if specified SID is a role SID, 0 if not.
//
BOOL
ROLDLLEXP
ROLEAPI
FRoleSid(IN PSID psid);

HRESULT
ROLDLLEXP
ROLEAPI
HrParseRoleSid(IN PSID psid, IN long cbNameBuffer, OUT char rgchName[], OUT ULONG *pptagrole OPTIONAL, OUT BYTE *prolescope OPTIONAL);

HRESULT
ROLDLLEXP
ROLEAPI
HrConstructRoleSid(IN char * szRoleName, IN BYTE rolescope, IN ULONG ptagrole, OUT PSID *ppsid OPTIONAL);

void
ROLDLLEXP
ROLEAPI
FreeRoleSid(IN PSID psid);

//
//	Returns if the specified ACL is canonical or not.
//
BOOL
ROLDLLEXP
ROLEAPI
FCanonicalAcl(PACL pacl);
BOOL

ROLDLLEXP
ROLEAPI
FCanonicalAcl(PSECURITY_DESCRIPTOR pntsd);

#endif	//_MDBROLE_HXX_
