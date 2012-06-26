
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

#if !defined(_M_IA64) && !defined(_M_AXP64)

#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IExchangeServer,0x25150F47,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);


MIDL_DEFINE_GUID(IID, IID_IStorageGroup,0x25150F46,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);


MIDL_DEFINE_GUID(IID, IID_IPublicStoreDB,0x25150F44,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);


MIDL_DEFINE_GUID(IID, IID_IMailboxStoreDB,0x25150F45,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);


MIDL_DEFINE_GUID(IID, IID_IFolderTree,0x25150F43,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);


MIDL_DEFINE_GUID(IID, IID_IDataSource2,0x25150F48,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AXP64)*/


#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 5.03.0279 */
/* at Wed Dec 13 23:45:32 2000
 */
/* Compiler settings for P:\admin\src\libs\emolib\EMOSTORE.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win64 (32b run,appending), ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if defined(_M_IA64) || defined(_M_AXP64)

#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IExchangeServer,0x25150F47,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);


MIDL_DEFINE_GUID(IID, IID_IStorageGroup,0x25150F46,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);


MIDL_DEFINE_GUID(IID, IID_IPublicStoreDB,0x25150F44,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);


MIDL_DEFINE_GUID(IID, IID_IMailboxStoreDB,0x25150F45,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);


MIDL_DEFINE_GUID(IID, IID_IFolderTree,0x25150F43,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);


MIDL_DEFINE_GUID(IID, IID_IDataSource2,0x25150F48,0x5734,0x11d2,0xA5,0x93,0x00,0xC0,0x4F,0x99,0x0D,0x8A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AXP64)*/

