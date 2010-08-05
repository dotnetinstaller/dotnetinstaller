

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Jul 05 19:04:02 2010
 */
/* Compiler settings for .\AxHTMLayout.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


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

MIDL_DEFINE_GUID(IID, IID_IElement,0xF144258B,0x4129,0x42E1,0x9A,0x07,0x9F,0x04,0x84,0x5C,0x62,0x90);


MIDL_DEFINE_GUID(IID, IID_IEngine,0xF4032083,0x0553,0x4AC1,0xB0,0x8A,0x6A,0x85,0x4D,0xFD,0x11,0x53);


MIDL_DEFINE_GUID(IID, LIBID_HTMLayout,0x22A83438,0x4B36,0x4CEC,0x9A,0xF7,0xC0,0x00,0x16,0x74,0xE2,0xA8);


MIDL_DEFINE_GUID(IID, DIID__IEngineEvents,0xA9CCCA1B,0x4E1B,0x4AE0,0x80,0x04,0xDD,0x81,0x84,0xBA,0x8F,0xDA);


MIDL_DEFINE_GUID(CLSID, CLSID_Engine,0x58BD87DF,0x8687,0x4CEC,0x97,0x10,0xA4,0xCE,0xEE,0x7D,0x0F,0x7D);


MIDL_DEFINE_GUID(IID, DIID__IElementEvents,0xA6F09FE1,0xEB03,0x4679,0xB9,0x72,0x2C,0x4E,0xF9,0x59,0x67,0x51);


MIDL_DEFINE_GUID(CLSID, CLSID_Element,0xDE1EBB05,0xE806,0x4434,0xA7,0xC3,0x49,0x4D,0x28,0xCF,0xFE,0x24);


MIDL_DEFINE_GUID(IID, IID_IElements,0xF8745FCD,0x98FE,0x4B6F,0x96,0xCA,0xF0,0xB9,0x69,0xBB,0xFD,0x31);


MIDL_DEFINE_GUID(CLSID, CLSID_Elements,0xBB9B507A,0x1F92,0x4C43,0xA2,0xED,0xA0,0xB0,0x57,0x02,0x00,0xBC);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



