
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 5.03.0279 */
/* at Fri Oct 01 16:58:17 1999
 */
/* Compiler settings for scardssp.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AXP64)
#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "scardssp.h"

#define TYPE_FORMAT_STRING_SIZE   1313                              
#define PROC_FORMAT_STRING_SIZE   3859                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   3            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Standard interface: __MIDL_itf_scardssp_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IByteBuffer, ver. 0.0,
   GUID={0xE126F8FE,0xA7AF,0x11D0,{0xB8,0x8A,0x00,0xC0,0x4F,0xD4,0x24,0xB9}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IByteBuffer_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IByteBuffer_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    108,
    144,
    198,
    240,
    288,
    336,
    366,
    414,
    450,
    492,
    540
    };

static const MIDL_SERVER_INFO IByteBuffer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IByteBuffer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IByteBuffer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IByteBuffer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(21) _IByteBufferProxyVtbl = 
{
    &IByteBuffer_ProxyInfo,
    &IID_IByteBuffer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IByteBuffer::get_Stream */ ,
    (void *)-1 /* IByteBuffer::put_Stream */ ,
    (void *)-1 /* IByteBuffer::Clone */ ,
    (void *)-1 /* IByteBuffer::Commit */ ,
    (void *)-1 /* IByteBuffer::CopyTo */ ,
    (void *)-1 /* IByteBuffer::Initialize */ ,
    (void *)-1 /* IByteBuffer::LockRegion */ ,
    (void *)-1 /* IByteBuffer::Read */ ,
    (void *)-1 /* IByteBuffer::Revert */ ,
    (void *)-1 /* IByteBuffer::Seek */ ,
    (void *)-1 /* IByteBuffer::SetSize */ ,
    (void *)-1 /* IByteBuffer::Stat */ ,
    (void *)-1 /* IByteBuffer::UnlockRegion */ ,
    (void *)-1 /* IByteBuffer::Write */
};


static const PRPC_STUB_FUNCTION IByteBuffer_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IByteBufferStubVtbl =
{
    &IID_IByteBuffer,
    &IByteBuffer_ServerInfo,
    21,
    &IByteBuffer_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0244, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCardTypeConv, ver. 0.0,
   GUID={0x53B6AA63,0x3F56,0x11D0,{0x91,0x6B,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCardTypeConv_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCardTypeConv_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    588,
    636,
    678,
    720,
    762,
    804,
    846,
    888,
    930,
    972
    };

static const MIDL_SERVER_INFO ISCardTypeConv_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCardTypeConv_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCardTypeConv_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCardTypeConv_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(17) _ISCardTypeConvProxyVtbl = 
{
    &ISCardTypeConv_ProxyInfo,
    &IID_ISCardTypeConv,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCardTypeConv::ConvertByteArrayToByteBuffer */ ,
    (void *)-1 /* ISCardTypeConv::ConvertByteBufferToByteArray */ ,
    (void *)-1 /* ISCardTypeConv::ConvertByteBufferToSafeArray */ ,
    (void *)-1 /* ISCardTypeConv::ConvertSafeArrayToByteBuffer */ ,
    (void *)-1 /* ISCardTypeConv::CreateByteArray */ ,
    (void *)-1 /* ISCardTypeConv::CreateByteBuffer */ ,
    (void *)-1 /* ISCardTypeConv::CreateSafeArray */ ,
    (void *)-1 /* ISCardTypeConv::FreeIStreamMemoryPtr */ ,
    (void *)-1 /* ISCardTypeConv::GetAtIStreamMemory */ ,
    (void *)-1 /* ISCardTypeConv::SizeOfIStream */
};


static const PRPC_STUB_FUNCTION ISCardTypeConv_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardTypeConvStubVtbl =
{
    &IID_ISCardTypeConv,
    &ISCardTypeConv_ServerInfo,
    17,
    &ISCardTypeConv_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0245, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCardCmd, ver. 0.0,
   GUID={0xD5778AE3,0x43DE,0x11D0,{0x91,0x71,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCardCmd_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCardCmd_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1014,
    1050,
    1086,
    1122,
    1158,
    1194,
    1230,
    1266,
    1302,
    1338,
    1374,
    1410,
    1446,
    1482,
    1518,
    1554,
    1590,
    1626,
    1662,
    1698,
    1734,
    1770,
    1806,
    1842,
    1878,
    1914,
    1950,
    1986,
    2022,
    2088,
    2118,
    2160,
    2196
    };

static const MIDL_SERVER_INFO ISCardCmd_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCardCmd_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCardCmd_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCardCmd_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(40) _ISCardCmdProxyVtbl = 
{
    &ISCardCmd_ProxyInfo,
    &IID_ISCardCmd,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCardCmd::get_Apdu */ ,
    (void *)-1 /* ISCardCmd::put_Apdu */ ,
    (void *)-1 /* ISCardCmd::get_ApduLength */ ,
    (void *)-1 /* ISCardCmd::get_ApduReply */ ,
    (void *)-1 /* ISCardCmd::put_ApduReply */ ,
    (void *)-1 /* ISCardCmd::get_ApduReplyLength */ ,
    (void *)-1 /* ISCardCmd::put_ApduReplyLength */ ,
    (void *)-1 /* ISCardCmd::get_ClassId */ ,
    (void *)-1 /* ISCardCmd::put_ClassId */ ,
    (void *)-1 /* ISCardCmd::get_Data */ ,
    (void *)-1 /* ISCardCmd::put_Data */ ,
    (void *)-1 /* ISCardCmd::get_InstructionId */ ,
    (void *)-1 /* ISCardCmd::put_InstructionId */ ,
    (void *)-1 /* ISCardCmd::get_LeField */ ,
    (void *)-1 /* ISCardCmd::get_P1 */ ,
    (void *)-1 /* ISCardCmd::put_P1 */ ,
    (void *)-1 /* ISCardCmd::get_P2 */ ,
    (void *)-1 /* ISCardCmd::put_P2 */ ,
    (void *)-1 /* ISCardCmd::get_P3 */ ,
    (void *)-1 /* ISCardCmd::get_ReplyStatus */ ,
    (void *)-1 /* ISCardCmd::put_ReplyStatus */ ,
    (void *)-1 /* ISCardCmd::get_ReplyStatusSW1 */ ,
    (void *)-1 /* ISCardCmd::get_ReplyStatusSW2 */ ,
    (void *)-1 /* ISCardCmd::get_Type */ ,
    (void *)-1 /* ISCardCmd::get_Nad */ ,
    (void *)-1 /* ISCardCmd::put_Nad */ ,
    (void *)-1 /* ISCardCmd::get_ReplyNad */ ,
    (void *)-1 /* ISCardCmd::put_ReplyNad */ ,
    (void *)-1 /* ISCardCmd::BuildCmd */ ,
    (void *)-1 /* ISCardCmd::Clear */ ,
    (void *)-1 /* ISCardCmd::Encapsulate */ ,
    (void *)-1 /* ISCardCmd::get_AlternateClassId */ ,
    (void *)-1 /* ISCardCmd::put_AlternateClassId */
};


static const PRPC_STUB_FUNCTION ISCardCmd_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardCmdStubVtbl =
{
    &IID_ISCardCmd,
    &ISCardCmd_ServerInfo,
    40,
    &ISCardCmd_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0246, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCardISO7816, ver. 0.0,
   GUID={0x53B6AA68,0x3F56,0x11D0,{0x91,0x6B,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCardISO7816_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCardISO7816_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    2232,
    2280,
    2334,
    2388,
    2430,
    2484,
    2538,
    2598,
    2646,
    2700,
    2754,
    2808,
    1446,
    2868,
    2922,
    2976,
    3024,
    3078
    };

static const MIDL_SERVER_INFO ISCardISO7816_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCardISO7816_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCardISO7816_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCardISO7816_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(25) _ISCardISO7816ProxyVtbl = 
{
    &ISCardISO7816_ProxyInfo,
    &IID_ISCardISO7816,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCardISO7816::AppendRecord */ ,
    (void *)-1 /* ISCardISO7816::EraseBinary */ ,
    (void *)-1 /* ISCardISO7816::ExternalAuthenticate */ ,
    (void *)-1 /* ISCardISO7816::GetChallenge */ ,
    (void *)-1 /* ISCardISO7816::GetData */ ,
    (void *)-1 /* ISCardISO7816::GetResponse */ ,
    (void *)-1 /* ISCardISO7816::InternalAuthenticate */ ,
    (void *)-1 /* ISCardISO7816::ManageChannel */ ,
    (void *)-1 /* ISCardISO7816::PutData */ ,
    (void *)-1 /* ISCardISO7816::ReadBinary */ ,
    (void *)-1 /* ISCardISO7816::ReadRecord */ ,
    (void *)-1 /* ISCardISO7816::SelectFile */ ,
    (void *)-1 /* ISCardISO7816::SetDefaultClassId */ ,
    (void *)-1 /* ISCardISO7816::UpdateBinary */ ,
    (void *)-1 /* ISCardISO7816::UpdateRecord */ ,
    (void *)-1 /* ISCardISO7816::Verify */ ,
    (void *)-1 /* ISCardISO7816::WriteBinary */ ,
    (void *)-1 /* ISCardISO7816::WriteRecord */
};


static const PRPC_STUB_FUNCTION ISCardISO7816_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardISO7816StubVtbl =
{
    &IID_ISCardISO7816,
    &ISCardISO7816_ServerInfo,
    25,
    &ISCardISO7816_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0247, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCard, ver. 0.0,
   GUID={0x1461AAC3,0x6810,0x11D0,{0x91,0x8F,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCard_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCard_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1014,
    3132,
    1086,
    3168,
    3204,
    3240,
    3276,
    3324,
    336,
    3360,
    3402,
    3438
    };

static const MIDL_SERVER_INFO ISCard_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCard_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCard_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCard_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(19) _ISCardProxyVtbl = 
{
    &ISCard_ProxyInfo,
    &IID_ISCard,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCard::get_Atr */ ,
    (void *)-1 /* ISCard::get_CardHandle */ ,
    (void *)-1 /* ISCard::get_Context */ ,
    (void *)-1 /* ISCard::get_Protocol */ ,
    (void *)-1 /* ISCard::get_Status */ ,
    (void *)-1 /* ISCard::AttachByHandle */ ,
    (void *)-1 /* ISCard::AttachByReader */ ,
    (void *)-1 /* ISCard::Detach */ ,
    (void *)-1 /* ISCard::LockSCard */ ,
    (void *)-1 /* ISCard::ReAttach */ ,
    (void *)-1 /* ISCard::Transaction */ ,
    (void *)-1 /* ISCard::UnlockSCard */
};


static const PRPC_STUB_FUNCTION ISCard_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardStubVtbl =
{
    &IID_ISCard,
    &ISCard_ServerInfo,
    19,
    &ISCard_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0248, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCardDatabase, ver. 0.0,
   GUID={0x1461AAC8,0x6810,0x11D0,{0x91,0x8F,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCardDatabase_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCardDatabase_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    3474,
    3516,
    3558,
    3612,
    3654
    };

static const MIDL_SERVER_INFO ISCardDatabase_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCardDatabase_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCardDatabase_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCardDatabase_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(12) _ISCardDatabaseProxyVtbl = 
{
    &ISCardDatabase_ProxyInfo,
    &IID_ISCardDatabase,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCardDatabase::GetProviderCardId */ ,
    (void *)-1 /* ISCardDatabase::ListCardInterfaces */ ,
    (void *)-1 /* ISCardDatabase::ListCards */ ,
    (void *)-1 /* ISCardDatabase::ListReaderGroups */ ,
    (void *)-1 /* ISCardDatabase::ListReaders */
};


static const PRPC_STUB_FUNCTION ISCardDatabase_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardDatabaseStubVtbl =
{
    &IID_ISCardDatabase,
    &ISCardDatabase_ServerInfo,
    12,
    &ISCardDatabase_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0249, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCardLocate, ver. 0.0,
   GUID={0x1461AACD,0x6810,0x11D0,{0x91,0x8F,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCardLocate_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCardLocate_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    3696,
    3750,
    3804
    };

static const MIDL_SERVER_INFO ISCardLocate_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCardLocate_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCardLocate_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCardLocate_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(10) _ISCardLocateProxyVtbl = 
{
    &ISCardLocate_ProxyInfo,
    &IID_ISCardLocate,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCardLocate::ConfigureCardGuidSearch */ ,
    (void *)-1 /* ISCardLocate::ConfigureCardNameSearch */ ,
    (void *)-1 /* ISCardLocate::FindCard */
};


static const PRPC_STUB_FUNCTION ISCardLocate_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardLocateStubVtbl =
{
    &IID_ISCardLocate,
    &ISCardLocate_ServerInfo,
    10,
    &ISCardLocate_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0250, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */

extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x5030117, /* MIDL Version 5.3.279 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            HGLOBAL_UserSize
            ,HGLOBAL_UserMarshal
            ,HGLOBAL_UserUnmarshal
            ,HGLOBAL_UserFree
            },
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            },
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 Professional or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_Stream */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  8 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppStream */

/* 24 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 26 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 28 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 32 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Stream */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 44 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStream */

/* 60 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 62 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 64 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 68 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 80 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 88 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppByteBuffer */

/* 96 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 98 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 100 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 104 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Commit */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 116 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 122 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 124 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter grfCommitFlags */

/* 132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 134 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 140 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyTo */

/* 144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 152 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 154 */	NdrFcShort( 0x18 ),	/* 24 */
/* 156 */	NdrFcShort( 0x18 ),	/* 24 */
/* 158 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 160 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppByteBuffer */

/* 168 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 170 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 172 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Parameter cb */

/* 174 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 176 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbRead */

/* 180 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
#ifndef _ALPHA_
/* 182 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbWritten */

/* 186 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
#ifndef _ALPHA_
/* 188 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 194 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 206 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 208 */	NdrFcShort( 0xd ),	/* 13 */
/* 210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 212 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 214 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lSize */

/* 222 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 224 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pData */

/* 228 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
#ifndef _ALPHA_
/* 230 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 232 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 236 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LockRegion */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 248 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 250 */	NdrFcShort( 0x18 ),	/* 24 */
/* 252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 254 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 256 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libOffset */

/* 264 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 266 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cb */

/* 270 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 272 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwLockType */

/* 276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 278 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 284 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Read */

/* 288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 296 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 298 */	NdrFcShort( 0x15 ),	/* 21 */
/* 300 */	NdrFcShort( 0x15 ),	/* 21 */
/* 302 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 304 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pByte */

/* 312 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
#ifndef _ALPHA_
/* 314 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 316 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter cb */

/* 318 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 320 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbRead */

/* 324 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
#ifndef _ALPHA_
/* 326 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 332 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LockSCard */


	/* Procedure Revert */

/* 336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 344 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x8 ),	/* 8 */
/* 350 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 352 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 362 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Seek */

/* 366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 374 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 376 */	NdrFcShort( 0x18 ),	/* 24 */
/* 378 */	NdrFcShort( 0x10 ),	/* 16 */
/* 380 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 382 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dLibMove */

/* 390 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 392 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwOrigin */

/* 396 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 398 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pLibnewPosition */

/* 402 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
#ifndef _ALPHA_
/* 404 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 410 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSize */

/* 414 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x11 ),	/* 17 */
#ifndef _ALPHA_
/* 422 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 426 */	NdrFcShort( 0x8 ),	/* 8 */
/* 428 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 430 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libNewSize */

/* 438 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 440 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 444 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 446 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stat */

/* 450 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x12 ),	/* 18 */
#ifndef _ALPHA_
/* 458 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 460 */	NdrFcShort( 0x24 ),	/* 36 */
/* 462 */	NdrFcShort( 0x24 ),	/* 36 */
/* 464 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 466 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pstatstg */

/* 474 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
#ifndef _ALPHA_
/* 476 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 478 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Parameter grfStatFlag */

/* 480 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 482 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 486 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 488 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnlockRegion */

/* 492 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0x13 ),	/* 19 */
#ifndef _ALPHA_
/* 500 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 502 */	NdrFcShort( 0x18 ),	/* 24 */
/* 504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 506 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 508 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libOffset */

/* 516 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 518 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cb */

/* 522 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 524 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwLockType */

/* 528 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 530 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 536 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Write */

/* 540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x14 ),	/* 20 */
#ifndef _ALPHA_
/* 548 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 550 */	NdrFcShort( 0x15 ),	/* 21 */
/* 552 */	NdrFcShort( 0x15 ),	/* 21 */
/* 554 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 556 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pByte */

/* 564 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
#ifndef _ALPHA_
/* 566 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 568 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter cb */

/* 570 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 572 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbWritten */

/* 576 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
#ifndef _ALPHA_
/* 578 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 584 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConvertByteArrayToByteBuffer */

/* 588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 596 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 598 */	NdrFcShort( 0xd ),	/* 13 */
/* 600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 602 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 604 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyArray */

/* 612 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
#ifndef _ALPHA_
/* 614 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 616 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter dwArraySize */

/* 618 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 620 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppbyBuffer */

/* 624 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 626 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 628 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 630 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 632 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConvertByteBufferToByteArray */

/* 636 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 638 */	NdrFcLong( 0x0 ),	/* 0 */
/* 642 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 644 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x8 ),	/* 8 */
/* 650 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 652 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 654 */	NdrFcShort( 0x3 ),	/* 3 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyBuffer */

/* 660 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 662 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 664 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppArray */

/* 666 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 668 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 670 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */

	/* Return value */

/* 672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 674 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConvertByteBufferToSafeArray */

/* 678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 686 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x8 ),	/* 8 */
/* 692 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 694 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 696 */	NdrFcShort( 0x12 ),	/* 18 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyBuffer */

/* 702 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 704 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 706 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppbyArray */

/* 708 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 710 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 712 */	NdrFcShort( 0x4a6 ),	/* Type Offset=1190 */

	/* Return value */

/* 714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 716 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConvertSafeArrayToByteBuffer */

/* 720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 728 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 734 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 736 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x12 ),	/* 18 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyArray */

/* 744 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 746 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 748 */	NdrFcShort( 0x4b8 ),	/* Type Offset=1208 */

	/* Parameter ppbyBuff */

/* 750 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 752 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 754 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 758 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateByteArray */

/* 762 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 764 */	NdrFcLong( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 770 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 774 */	NdrFcShort( 0x15 ),	/* 21 */
/* 776 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 778 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwAllocSize */

/* 786 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 788 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppbyArray */

/* 792 */	NdrFcShort( 0x2012 ),	/* Flags:  must free, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 794 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 796 */	NdrFcShort( 0x4c2 ),	/* Type Offset=1218 */

	/* Return value */

/* 798 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 800 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateByteBuffer */

/* 804 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 806 */	NdrFcLong( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 812 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 814 */	NdrFcShort( 0x8 ),	/* 8 */
/* 816 */	NdrFcShort( 0x8 ),	/* 8 */
/* 818 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 820 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwAllocSize */

/* 828 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 830 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppbyBuff */

/* 834 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 836 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 838 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 842 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateSafeArray */

/* 846 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 854 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 860 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 862 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 864 */	NdrFcShort( 0x12 ),	/* 18 */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nAllocSize */

/* 870 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 872 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppArray */

/* 876 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 878 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 880 */	NdrFcShort( 0x4a6 ),	/* Type Offset=1190 */

	/* Return value */

/* 882 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 884 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FreeIStreamMemoryPtr */

/* 888 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 890 */	NdrFcLong( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 896 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 898 */	NdrFcShort( 0x5 ),	/* 5 */
/* 900 */	NdrFcShort( 0x8 ),	/* 8 */
/* 902 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 904 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStrm */

/* 912 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 914 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 916 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter pMem */

/* 918 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
#ifndef _ALPHA_
/* 920 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 922 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 924 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 926 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAtIStreamMemory */

/* 930 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 932 */	NdrFcLong( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 938 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x8 ),	/* 8 */
/* 944 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 946 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 948 */	NdrFcShort( 0x3 ),	/* 3 */
/* 950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStrm */

/* 954 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 956 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 958 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter ppMem */

/* 960 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 962 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 964 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */

	/* Return value */

/* 966 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 968 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SizeOfIStream */

/* 972 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 974 */	NdrFcLong( 0x0 ),	/* 0 */
/* 978 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 980 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0x18 ),	/* 24 */
/* 986 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 988 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 994 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStrm */

/* 996 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 998 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1000 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter puliSize */

/* 1002 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1004 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1006 */	NdrFcShort( 0x2ce ),	/* Type Offset=718 */

	/* Return value */

/* 1008 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1010 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Atr */


	/* Procedure get_Apdu */

/* 1014 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1016 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1020 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 1022 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1026 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1028 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1030 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppAtr */


	/* Parameter ppApdu */

/* 1038 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 1040 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1042 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */

/* 1044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1046 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Apdu */

/* 1050 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 1058 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1064 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1066 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1072 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pApdu */

/* 1074 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 1076 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1078 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 1080 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1082 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Context */


	/* Procedure get_ApduLength */

/* 1086 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1088 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 1094 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1098 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1100 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1102 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1108 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pContext */


	/* Parameter plSize */

/* 1110 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1112 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1116 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1118 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ApduReply */

/* 1122 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 1130 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1134 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1136 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1138 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppReplyApdu */

/* 1146 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 1148 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1150 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 1152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1154 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ApduReply */

/* 1158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1164 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 1166 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1172 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1174 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pReplyApdu */

/* 1182 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 1184 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1186 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 1188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1190 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ApduReplyLength */

/* 1194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 1202 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1206 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1208 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1210 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter plSize */

/* 1218 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1220 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1226 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ApduReplyLength */

/* 1230 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 1238 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1244 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1246 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lSize */

/* 1254 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1256 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1262 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ClassId */

/* 1266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1272 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 1274 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1278 */	NdrFcShort( 0xd ),	/* 13 */
/* 1280 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1282 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyClass */

/* 1290 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1292 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1294 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1296 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1298 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ClassId */

/* 1302 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1308 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 1310 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1312 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1314 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1316 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1318 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1324 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byClass */

/* 1326 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1328 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1330 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1332 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1334 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Data */

/* 1338 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1340 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1344 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 1346 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1350 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1352 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1354 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1360 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppData */

/* 1362 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 1364 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1366 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 1368 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1370 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Data */

/* 1374 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1376 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1380 */	NdrFcShort( 0x11 ),	/* 17 */
#ifndef _ALPHA_
/* 1382 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1386 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1388 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1390 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1396 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pData */

/* 1398 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 1400 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1402 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 1404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1406 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_InstructionId */

/* 1410 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1416 */	NdrFcShort( 0x12 ),	/* 18 */
#ifndef _ALPHA_
/* 1418 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1422 */	NdrFcShort( 0xd ),	/* 13 */
/* 1424 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1426 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1432 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyIns */

/* 1434 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1436 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1438 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1440 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1442 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDefaultClassId */


	/* Procedure put_InstructionId */

/* 1446 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1448 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x13 ),	/* 19 */
#ifndef _ALPHA_
/* 1454 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1456 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1458 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1460 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1462 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1468 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byClass */


	/* Parameter byIns */

/* 1470 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1472 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1474 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1476 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1478 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LeField */

/* 1482 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1484 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x14 ),	/* 20 */
#ifndef _ALPHA_
/* 1490 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1494 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1496 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1498 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1504 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter plSize */

/* 1506 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1508 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1512 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1514 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_P1 */

/* 1518 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1520 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0x15 ),	/* 21 */
#ifndef _ALPHA_
/* 1526 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1530 */	NdrFcShort( 0xd ),	/* 13 */
/* 1532 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1534 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyP1 */

/* 1542 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1544 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1546 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1550 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_P1 */

/* 1554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1560 */	NdrFcShort( 0x16 ),	/* 22 */
#ifndef _ALPHA_
/* 1562 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1564 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1568 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1570 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 1578 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1580 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1582 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1586 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_P2 */

/* 1590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0x17 ),	/* 23 */
#ifndef _ALPHA_
/* 1598 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0xd ),	/* 13 */
/* 1604 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1606 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyP2 */

/* 1614 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1616 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1618 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1620 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1622 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_P2 */

/* 1626 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1632 */	NdrFcShort( 0x18 ),	/* 24 */
#ifndef _ALPHA_
/* 1634 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1636 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1640 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1642 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1648 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP2 */

/* 1650 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1652 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1654 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1658 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_P3 */

/* 1662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1668 */	NdrFcShort( 0x19 ),	/* 25 */
#ifndef _ALPHA_
/* 1670 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0xd ),	/* 13 */
/* 1676 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1678 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyP3 */

/* 1686 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1688 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1690 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1692 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1694 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ReplyStatus */

/* 1698 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1700 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x1a ),	/* 26 */
#ifndef _ALPHA_
/* 1706 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1710 */	NdrFcShort( 0xe ),	/* 14 */
/* 1712 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1714 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1720 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwStatus */

/* 1722 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1724 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1726 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1728 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1730 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ReplyStatus */

/* 1734 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1736 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1740 */	NdrFcShort( 0x1b ),	/* 27 */
#ifndef _ALPHA_
/* 1742 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1744 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1748 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1750 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1756 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wStatus */

/* 1758 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1760 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1762 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1764 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1766 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ReplyStatusSW1 */

/* 1770 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1776 */	NdrFcShort( 0x1c ),	/* 28 */
#ifndef _ALPHA_
/* 1778 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0xd ),	/* 13 */
/* 1784 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1786 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbySW1 */

/* 1794 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1796 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1798 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1800 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1802 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ReplyStatusSW2 */

/* 1806 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1812 */	NdrFcShort( 0x1d ),	/* 29 */
#ifndef _ALPHA_
/* 1814 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0xd ),	/* 13 */
/* 1820 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1822 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbySW2 */

/* 1830 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1832 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1834 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1836 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1838 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Type */

/* 1842 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1844 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1848 */	NdrFcShort( 0x1e ),	/* 30 */
#ifndef _ALPHA_
/* 1850 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0xe ),	/* 14 */
/* 1856 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1858 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1864 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 1866 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
#ifndef _ALPHA_
/* 1868 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1870 */	NdrFcShort( 0x4d6 ),	/* Type Offset=1238 */

	/* Return value */

/* 1872 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1874 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Nad */

/* 1878 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1884 */	NdrFcShort( 0x1f ),	/* 31 */
#ifndef _ALPHA_
/* 1886 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1890 */	NdrFcShort( 0xd ),	/* 13 */
/* 1892 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1894 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1900 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbNad */

/* 1902 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1904 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1906 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1908 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1910 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Nad */

/* 1914 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1916 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1920 */	NdrFcShort( 0x20 ),	/* 32 */
#ifndef _ALPHA_
/* 1922 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1924 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1926 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1928 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1930 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1936 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bNad */

/* 1938 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1940 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1942 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1946 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ReplyNad */

/* 1950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1956 */	NdrFcShort( 0x21 ),	/* 33 */
#ifndef _ALPHA_
/* 1958 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1962 */	NdrFcShort( 0xd ),	/* 13 */
/* 1964 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1966 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbNad */

/* 1974 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1976 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1978 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1980 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1982 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1984 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ReplyNad */

/* 1986 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1988 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1992 */	NdrFcShort( 0x22 ),	/* 34 */
#ifndef _ALPHA_
/* 1994 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1996 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1998 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2000 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2002 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2008 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bNad */

/* 2010 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2012 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2014 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 2016 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2018 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BuildCmd */

/* 2022 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2024 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2028 */	NdrFcShort( 0x23 ),	/* 35 */
#ifndef _ALPHA_
/* 2030 */	NdrFcShort( 0x20 ),	/* x86, MIPS, PPC Stack size/offset = 32 */
#else
			NdrFcShort( 0x40 ),	/* Alpha Stack size/offset = 64 */
#endif
/* 2032 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2036 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2038 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2044 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byClassId */

/* 2046 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2048 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2050 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byInsId */

/* 2052 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2054 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2056 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP1 */

/* 2058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2060 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2062 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2064 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2066 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2068 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pbyData */

/* 2070 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 2072 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2074 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter plLe */

/* 2076 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
#ifndef _ALPHA_
/* 2078 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2082 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2084 */	NdrFcShort( 0x1c ),	/* x86, MIPS, PPC Stack size/offset = 28 */
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 2086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clear */

/* 2088 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2090 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2094 */	NdrFcShort( 0x24 ),	/* 36 */
#ifndef _ALPHA_
/* 2096 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2100 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2102 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2104 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2110 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2114 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Encapsulate */

/* 2118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x25 ),	/* 37 */
#ifndef _ALPHA_
/* 2126 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2128 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2132 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2134 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pApdu */

/* 2142 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 2144 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2146 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ApduType */

/* 2148 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2150 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2152 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 2154 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2156 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_AlternateClassId */

/* 2160 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2162 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2166 */	NdrFcShort( 0x26 ),	/* 38 */
#ifndef _ALPHA_
/* 2168 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2172 */	NdrFcShort( 0xd ),	/* 13 */
/* 2174 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2176 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyClass */

/* 2184 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 2186 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2188 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 2190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2192 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_AlternateClassId */

/* 2196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2202 */	NdrFcShort( 0x27 ),	/* 39 */
#ifndef _ALPHA_
/* 2204 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2206 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2210 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2212 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byClass */

/* 2220 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2222 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2224 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 2226 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2228 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendRecord */

/* 2232 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2234 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 2240 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2242 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2244 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2246 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2248 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2254 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byRefCtrl */

/* 2256 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2258 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2260 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 2262 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 2264 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2266 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 2268 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2270 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2272 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2276 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EraseBinary */

/* 2280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2286 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 2288 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2290 */	NdrFcShort( 0xa ),	/* 10 */
/* 2292 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2294 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2296 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2304 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2306 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2308 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2312 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2314 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 2316 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 2318 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2320 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 2322 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2324 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2326 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2328 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2330 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExternalAuthenticate */

/* 2334 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2336 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2340 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 2342 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2344 */	NdrFcShort( 0xa ),	/* 10 */
/* 2346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2348 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2350 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2356 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byAlgorithmRef */

/* 2358 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2360 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2362 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter bySecretRef */

/* 2364 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2366 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2368 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pChallenge */

/* 2370 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 2372 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2374 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 2376 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2378 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2380 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2382 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2384 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2386 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetChallenge */

/* 2388 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2390 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2394 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 2396 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2400 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2402 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2404 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2410 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lBytesExpected */

/* 2412 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2414 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2418 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2420 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2422 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2424 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2426 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetData */

/* 2430 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2432 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2436 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 2438 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2440 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2442 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2444 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2446 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2452 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2456 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2458 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2462 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2464 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter lBytesToGet */

/* 2466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2468 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2472 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2474 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2476 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2480 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResponse */

/* 2484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2490 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 2492 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2494 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2498 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2500 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2510 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2512 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2514 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2516 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2518 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter lDataLength */

/* 2520 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2522 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2526 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2528 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2530 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2532 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2534 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InternalAuthenticate */

/* 2538 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2540 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2544 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 2546 */	NdrFcShort( 0x1c ),	/* x86, MIPS, PPC Stack size/offset = 28 */
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 2548 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2552 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2554 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2560 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byAlgorithmRef */

/* 2562 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2564 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2566 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter bySecretRef */

/* 2568 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2570 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2572 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pChallenge */

/* 2574 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 2576 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2578 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter lReplyBytes */

/* 2580 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2582 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2586 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2588 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2590 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2592 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2594 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ManageChannel */

/* 2598 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2604 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 2606 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2608 */	NdrFcShort( 0xa ),	/* 10 */
/* 2610 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2612 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2614 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2620 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byChannelState */

/* 2622 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2624 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2626 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byChannel */

/* 2628 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2630 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2632 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2634 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2636 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2638 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2642 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PutData */

/* 2646 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2652 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 2654 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2656 */	NdrFcShort( 0xa ),	/* 10 */
/* 2658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2660 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2662 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2668 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2670 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2672 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2674 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2676 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2678 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2680 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 2682 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 2684 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2686 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 2688 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2690 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2692 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2696 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadBinary */

/* 2700 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2706 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 2708 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2710 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2712 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2714 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2716 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2722 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2724 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2726 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2728 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2730 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2732 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2734 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter lBytesToRead */

/* 2736 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2738 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2742 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2744 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2746 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2748 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2750 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadRecord */

/* 2754 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2756 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2760 */	NdrFcShort( 0x11 ),	/* 17 */
#ifndef _ALPHA_
/* 2762 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2764 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2768 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2770 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2776 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byRecordId */

/* 2778 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2780 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2782 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byRefCtrl */

/* 2784 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2786 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2788 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter lBytesToRead */

/* 2790 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2792 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2796 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2798 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2800 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2802 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2804 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectFile */

/* 2808 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2810 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2814 */	NdrFcShort( 0x12 ),	/* 18 */
#ifndef _ALPHA_
/* 2816 */	NdrFcShort( 0x1c ),	/* x86, MIPS, PPC Stack size/offset = 28 */
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 2818 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2820 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2822 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2824 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2830 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2832 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2834 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2836 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2838 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2840 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2842 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 2844 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 2846 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2848 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter lBytesToRead */

/* 2850 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2852 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2854 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2856 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2858 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2860 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2862 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2864 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateBinary */

/* 2868 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2870 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2874 */	NdrFcShort( 0x14 ),	/* 20 */
#ifndef _ALPHA_
/* 2876 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2878 */	NdrFcShort( 0xa ),	/* 10 */
/* 2880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2882 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2884 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2890 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2892 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2894 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2896 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2898 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2900 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2902 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 2904 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 2906 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2908 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 2910 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2912 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2914 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2916 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2918 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateRecord */

/* 2922 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2928 */	NdrFcShort( 0x15 ),	/* 21 */
#ifndef _ALPHA_
/* 2930 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 2932 */	NdrFcShort( 0xa ),	/* 10 */
/* 2934 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2936 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2938 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2944 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byRecordId */

/* 2946 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2948 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 2950 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byRefCtrl */

/* 2952 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 2954 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 2956 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 2958 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 2960 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 2962 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 2964 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 2966 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 2968 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 2970 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2972 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Verify */

/* 2976 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2978 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2982 */	NdrFcShort( 0x16 ),	/* 22 */
#ifndef _ALPHA_
/* 2984 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 2986 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2988 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2990 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2992 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2998 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byRefCtrl */

/* 3000 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3002 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3004 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 3006 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 3008 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3010 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 3012 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 3014 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3016 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 3018 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3020 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3022 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteBinary */

/* 3024 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3026 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3030 */	NdrFcShort( 0x17 ),	/* 23 */
#ifndef _ALPHA_
/* 3032 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 3034 */	NdrFcShort( 0xa ),	/* 10 */
/* 3036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3038 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3040 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3046 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 3048 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3050 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3052 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 3054 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3056 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3058 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 3060 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 3062 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3064 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 3066 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 3068 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3070 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 3072 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3074 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 3076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteRecord */

/* 3078 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3080 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3084 */	NdrFcShort( 0x18 ),	/* 24 */
#ifndef _ALPHA_
/* 3086 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 3088 */	NdrFcShort( 0xa ),	/* 10 */
/* 3090 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3092 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3094 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byRecordId */

/* 3102 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3104 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3106 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byRefCtrl */

/* 3108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3110 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3112 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 3114 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 3116 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3118 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 3120 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 3122 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3124 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 3126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3128 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 3130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CardHandle */

/* 3132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3138 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 3140 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3144 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3146 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3148 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pHandle */

/* 3156 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 3158 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3164 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Protocol */

/* 3168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3174 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 3176 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3180 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3182 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3184 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3190 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pProtocol */

/* 3192 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 3194 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3196 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3200 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Status */

/* 3204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3210 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 3212 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3216 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3218 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3220 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStatus */

/* 3228 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 3230 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3232 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3236 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AttachByHandle */

/* 3240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3246 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 3248 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3254 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3256 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hCard */

/* 3264 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3266 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3272 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AttachByReader */

/* 3276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3282 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 3284 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 3286 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3290 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3292 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3296 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrReaderName */

/* 3300 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 3302 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3304 */	NdrFcShort( 0x4f8 ),	/* Type Offset=1272 */

	/* Parameter ShareMode */

/* 3306 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3308 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3310 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter PrefProtocol */

/* 3312 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3314 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3316 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3320 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Detach */

/* 3324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3330 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 3332 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3338 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3340 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Disposition */

/* 3348 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3350 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3352 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3356 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReAttach */

/* 3360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3366 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 3368 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3370 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3376 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3382 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ShareMode */

/* 3384 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3386 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3388 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter InitState */

/* 3390 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3392 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3394 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3398 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Transaction */

/* 3402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3408 */	NdrFcShort( 0x11 ),	/* 17 */
#ifndef _ALPHA_
/* 3410 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3416 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3418 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCmd */

/* 3426 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 3428 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3430 */	NdrFcShort( 0x4da ),	/* Type Offset=1242 */

	/* Return value */

/* 3432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3434 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnlockSCard */

/* 3438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3444 */	NdrFcShort( 0x12 ),	/* 18 */
#ifndef _ALPHA_
/* 3446 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3448 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3452 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3454 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Disposition */

/* 3462 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3464 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3466 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3470 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetProviderCardId */

/* 3474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3480 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 3482 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3486 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3488 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3490 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3494 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3496 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrCardName */

/* 3498 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 3500 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3502 */	NdrFcShort( 0x4f8 ),	/* Type Offset=1272 */

	/* Parameter ppguidProviderId */

/* 3504 */	NdrFcShort( 0x2012 ),	/* Flags:  must free, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 3506 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3508 */	NdrFcShort( 0x502 ),	/* Type Offset=1282 */

	/* Return value */

/* 3510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3512 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ListCardInterfaces */

/* 3516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3522 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 3524 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3530 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3532 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3534 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3536 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3538 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrCardName */

/* 3540 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 3542 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3544 */	NdrFcShort( 0x4f8 ),	/* Type Offset=1272 */

	/* Parameter ppInterfaceGuids */

/* 3546 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 3548 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3550 */	NdrFcShort( 0x4a6 ),	/* Type Offset=1190 */

	/* Return value */

/* 3552 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3554 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ListCards */

/* 3558 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3560 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3564 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 3566 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 3568 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3572 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3574 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3576 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3578 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3580 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAtr */

/* 3582 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 3584 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3586 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter pInterfaceGuids */

/* 3588 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 3590 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3592 */	NdrFcShort( 0x4b8 ),	/* Type Offset=1208 */

	/* Parameter localeId */

/* 3594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3596 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCardNames */

/* 3600 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 3602 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3604 */	NdrFcShort( 0x4a6 ),	/* Type Offset=1190 */

	/* Return value */

/* 3606 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3608 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 3610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ListReaderGroups */

/* 3612 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3618 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 3620 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3622 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3626 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3628 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3630 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter localeId */

/* 3636 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3638 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppReaderGroups */

/* 3642 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 3644 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3646 */	NdrFcShort( 0x4a6 ),	/* Type Offset=1190 */

	/* Return value */

/* 3648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3650 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ListReaders */

/* 3654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3660 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 3662 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3664 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3666 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3668 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3670 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3672 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3676 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter localeId */

/* 3678 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3680 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppReaders */

/* 3684 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 3686 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3688 */	NdrFcShort( 0x4a6 ),	/* Type Offset=1190 */

	/* Return value */

/* 3690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3692 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConfigureCardGuidSearch */

/* 3696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3702 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 3704 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 3706 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3710 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3712 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3716 */	NdrFcShort( 0x25 ),	/* 37 */
/* 3718 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCardGuids */

/* 3720 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 3722 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3724 */	NdrFcShort( 0x4b8 ),	/* Type Offset=1208 */

	/* Parameter pGroupNames */

/* 3726 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 3728 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3730 */	NdrFcShort( 0x4b8 ),	/* Type Offset=1208 */

	/* Parameter bstrTitle */

/* 3732 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 3734 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3736 */	NdrFcShort( 0x4f8 ),	/* Type Offset=1272 */

	/* Parameter lFlags */

/* 3738 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3740 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3744 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3746 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 3748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConfigureCardNameSearch */

/* 3750 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3752 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3756 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 3758 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 3760 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3764 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3766 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3770 */	NdrFcShort( 0x25 ),	/* 37 */
/* 3772 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCardNames */

/* 3774 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 3776 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3778 */	NdrFcShort( 0x4b8 ),	/* Type Offset=1208 */

	/* Parameter pGroupNames */

/* 3780 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 3782 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3784 */	NdrFcShort( 0x4b8 ),	/* Type Offset=1208 */

	/* Parameter bstrTitle */

/* 3786 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 3788 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3790 */	NdrFcShort( 0x4f8 ),	/* Type Offset=1272 */

	/* Parameter lFlags */

/* 3792 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3794 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3798 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3800 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 3802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindCard */

/* 3804 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3806 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3810 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 3812 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 3814 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3816 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3818 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 3820 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ShareMode */

/* 3828 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3830 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 3832 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter Protocols */

/* 3834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3836 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 3838 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter lFlags */

/* 3840 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 3842 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 3844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCardInfo */

/* 3846 */	NdrFcShort( 0x2012 ),	/* Flags:  must free, out, srv alloc size=8 */
#ifndef _ALPHA_
/* 3848 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 3850 */	NdrFcShort( 0x50a ),	/* Type Offset=1290 */

	/* Return value */

/* 3852 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 3854 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 3856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  8 */	NdrFcLong( 0xc ),	/* 12 */
/* 12 */	NdrFcShort( 0x0 ),	/* 0 */
/* 14 */	NdrFcShort( 0x0 ),	/* 0 */
/* 16 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 18 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 20 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 22 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 24 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 26 */	NdrFcShort( 0x2 ),	/* Offset= 2 (28) */
/* 28 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 30 */	NdrFcLong( 0xe126f8fe ),	/* -517539586 */
/* 34 */	NdrFcShort( 0xa7af ),	/* -22609 */
/* 36 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 38 */	0xb8,		/* 184 */
			0x8a,		/* 138 */
/* 40 */	0x0,		/* 0 */
			0xc0,		/* 192 */
/* 42 */	0x4f,		/* 79 */
			0xd4,		/* 212 */
/* 44 */	0x24,		/* 36 */
			0xb9,		/* 185 */
/* 46 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 48 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 50 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 52 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 54 */	
			0x11, 0x0,	/* FC_RP */
/* 56 */	NdrFcShort( 0x2 ),	/* Offset= 2 (58) */
/* 58 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 60 */	NdrFcShort( 0x14 ),	/* 20 */
/* 62 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 64 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 66 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 68 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 70 */	NdrFcShort( 0xffffffd6 ),	/* Offset= -42 (28) */
/* 72 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 74 */	NdrFcShort( 0x2 ),	/* Offset= 2 (76) */
/* 76 */	
			0x13, 0x0,	/* FC_OP */
/* 78 */	NdrFcShort( 0x50 ),	/* Offset= 80 (158) */
/* 80 */	
			0x13, 0x0,	/* FC_OP */
/* 82 */	NdrFcShort( 0x2 ),	/* Offset= 2 (84) */
/* 84 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 86 */	NdrFcShort( 0x8 ),	/* 8 */
/* 88 */	NdrFcShort( 0x3 ),	/* 3 */
/* 90 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 94 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 96 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 100 */	NdrFcShort( 0xa ),	/* Offset= 10 (110) */
/* 102 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 106 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 108 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (107) */
/* 110 */	
			0x13, 0x0,	/* FC_OP */
/* 112 */	NdrFcShort( 0xe ),	/* Offset= 14 (126) */
/* 114 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 116 */	NdrFcShort( 0x1 ),	/* 1 */
/* 118 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 120 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 122 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 124 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 126 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 130 */	NdrFcShort( 0xfffffff0 ),	/* Offset= -16 (114) */
/* 132 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 134 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 136 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x4 ),	/* 4 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0xffffffc0 ),	/* Offset= -64 (80) */
/* 146 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 148 */	NdrFcShort( 0x1 ),	/* 1 */
/* 150 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 152 */	NdrFcShort( 0x4 ),	/* 4 */
/* 154 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 156 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 158 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 160 */	NdrFcShort( 0xc ),	/* 12 */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0xa ),	/* Offset= 10 (174) */
/* 166 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 168 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (136) */
/* 170 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 172 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 174 */	
			0x13, 0x0,	/* FC_OP */
/* 176 */	NdrFcShort( 0xffffffe2 ),	/* Offset= -30 (146) */
/* 178 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 180 */	NdrFcShort( 0x3f2 ),	/* Offset= 1010 (1190) */
/* 182 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 184 */	NdrFcShort( 0x2 ),	/* Offset= 2 (186) */
/* 186 */	
			0x13, 0x0,	/* FC_OP */
/* 188 */	NdrFcShort( 0x3d8 ),	/* Offset= 984 (1172) */
/* 190 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 192 */	NdrFcShort( 0x18 ),	/* 24 */
/* 194 */	NdrFcShort( 0xa ),	/* 10 */
/* 196 */	NdrFcLong( 0x8 ),	/* 8 */
/* 200 */	NdrFcShort( 0x70 ),	/* Offset= 112 (312) */
/* 202 */	NdrFcLong( 0xd ),	/* 13 */
/* 206 */	NdrFcShort( 0xa6 ),	/* Offset= 166 (372) */
/* 208 */	NdrFcLong( 0x9 ),	/* 9 */
/* 212 */	NdrFcShort( 0xd8 ),	/* Offset= 216 (428) */
/* 214 */	NdrFcLong( 0xc ),	/* 12 */
/* 218 */	NdrFcShort( 0x2bc ),	/* Offset= 700 (918) */
/* 220 */	NdrFcLong( 0x24 ),	/* 36 */
/* 224 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (966) */
/* 226 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 230 */	NdrFcShort( 0x302 ),	/* Offset= 770 (1000) */
/* 232 */	NdrFcLong( 0x10 ),	/* 16 */
/* 236 */	NdrFcShort( 0x31c ),	/* Offset= 796 (1032) */
/* 238 */	NdrFcLong( 0x2 ),	/* 2 */
/* 242 */	NdrFcShort( 0x336 ),	/* Offset= 822 (1064) */
/* 244 */	NdrFcLong( 0x3 ),	/* 3 */
/* 248 */	NdrFcShort( 0x350 ),	/* Offset= 848 (1096) */
/* 250 */	NdrFcLong( 0x14 ),	/* 20 */
/* 254 */	NdrFcShort( 0x36a ),	/* Offset= 874 (1128) */
/* 256 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (255) */
/* 258 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 260 */	NdrFcShort( 0x2 ),	/* 2 */
/* 262 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 264 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 266 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 268 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 270 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 274 */	NdrFcShort( 0xfffffff0 ),	/* Offset= -16 (258) */
/* 276 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 278 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 280 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 282 */	NdrFcShort( 0x4 ),	/* 4 */
/* 284 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 290 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 292 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 294 */	NdrFcShort( 0x4 ),	/* 4 */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x1 ),	/* 1 */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 304 */	0x13, 0x0,	/* FC_OP */
/* 306 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (270) */
/* 308 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 310 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 312 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 314 */	NdrFcShort( 0x8 ),	/* 8 */
/* 316 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 318 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 320 */	NdrFcShort( 0x4 ),	/* 4 */
/* 322 */	NdrFcShort( 0x4 ),	/* 4 */
/* 324 */	0x11, 0x0,	/* FC_RP */
/* 326 */	NdrFcShort( 0xffffffd2 ),	/* Offset= -46 (280) */
/* 328 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 330 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 332 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 342 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 344 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 346 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 348 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 350 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 354 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 358 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 360 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 364 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 366 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 368 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (332) */
/* 370 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 372 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 374 */	NdrFcShort( 0x8 ),	/* 8 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0x6 ),	/* Offset= 6 (384) */
/* 380 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 382 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 384 */	
			0x11, 0x0,	/* FC_RP */
/* 386 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (350) */
/* 388 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 390 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 398 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 400 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 402 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 404 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 406 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 416 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 420 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 422 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 424 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (388) */
/* 426 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 428 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x6 ),	/* Offset= 6 (440) */
/* 436 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 438 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 440 */	
			0x11, 0x0,	/* FC_RP */
/* 442 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (406) */
/* 444 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 446 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 448 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 450 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 452 */	NdrFcShort( 0x2 ),	/* Offset= 2 (454) */
/* 454 */	NdrFcShort( 0x10 ),	/* 16 */
/* 456 */	NdrFcShort( 0x2b ),	/* 43 */
/* 458 */	NdrFcLong( 0x3 ),	/* 3 */
/* 462 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 464 */	NdrFcLong( 0x11 ),	/* 17 */
/* 468 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 470 */	NdrFcLong( 0x2 ),	/* 2 */
/* 474 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 476 */	NdrFcLong( 0x4 ),	/* 4 */
/* 480 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 482 */	NdrFcLong( 0x5 ),	/* 5 */
/* 486 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 488 */	NdrFcLong( 0xb ),	/* 11 */
/* 492 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 494 */	NdrFcLong( 0xa ),	/* 10 */
/* 498 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 500 */	NdrFcLong( 0x6 ),	/* 6 */
/* 504 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (718) */
/* 506 */	NdrFcLong( 0x7 ),	/* 7 */
/* 510 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 512 */	NdrFcLong( 0x8 ),	/* 8 */
/* 516 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (724) */
/* 518 */	NdrFcLong( 0xd ),	/* 13 */
/* 522 */	NdrFcShort( 0xffffff42 ),	/* Offset= -190 (332) */
/* 524 */	NdrFcLong( 0x9 ),	/* 9 */
/* 528 */	NdrFcShort( 0xffffff74 ),	/* Offset= -140 (388) */
/* 530 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 534 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (728) */
/* 536 */	NdrFcLong( 0x24 ),	/* 36 */
/* 540 */	NdrFcShort( 0xc4 ),	/* Offset= 196 (736) */
/* 542 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 546 */	NdrFcShort( 0xbe ),	/* Offset= 190 (736) */
/* 548 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 552 */	NdrFcShort( 0xee ),	/* Offset= 238 (790) */
/* 554 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 558 */	NdrFcShort( 0xec ),	/* Offset= 236 (794) */
/* 560 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 564 */	NdrFcShort( 0xea ),	/* Offset= 234 (798) */
/* 566 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 570 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (802) */
/* 572 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 576 */	NdrFcShort( 0xe6 ),	/* Offset= 230 (806) */
/* 578 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 582 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (794) */
/* 584 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 588 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (798) */
/* 590 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 594 */	NdrFcShort( 0xd8 ),	/* Offset= 216 (810) */
/* 596 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 600 */	NdrFcShort( 0xce ),	/* Offset= 206 (806) */
/* 602 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 606 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (814) */
/* 608 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 612 */	NdrFcShort( 0xce ),	/* Offset= 206 (818) */
/* 614 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 618 */	NdrFcShort( 0xcc ),	/* Offset= 204 (822) */
/* 620 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 624 */	NdrFcShort( 0xca ),	/* Offset= 202 (826) */
/* 626 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 630 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (838) */
/* 632 */	NdrFcLong( 0x10 ),	/* 16 */
/* 636 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 638 */	NdrFcLong( 0x12 ),	/* 18 */
/* 642 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 644 */	NdrFcLong( 0x13 ),	/* 19 */
/* 648 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 650 */	NdrFcLong( 0x16 ),	/* 22 */
/* 654 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 656 */	NdrFcLong( 0x17 ),	/* 23 */
/* 660 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 662 */	NdrFcLong( 0xe ),	/* 14 */
/* 666 */	NdrFcShort( 0xb4 ),	/* Offset= 180 (846) */
/* 668 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 672 */	NdrFcShort( 0xba ),	/* Offset= 186 (858) */
/* 674 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 678 */	NdrFcShort( 0xb8 ),	/* Offset= 184 (862) */
/* 680 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 684 */	NdrFcShort( 0x6e ),	/* Offset= 110 (794) */
/* 686 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 690 */	NdrFcShort( 0x6c ),	/* Offset= 108 (798) */
/* 692 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 696 */	NdrFcShort( 0x66 ),	/* Offset= 102 (798) */
/* 698 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 702 */	NdrFcShort( 0x60 ),	/* Offset= 96 (798) */
/* 704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x0 ),	/* Offset= 0 (708) */
/* 710 */	NdrFcLong( 0x1 ),	/* 1 */
/* 714 */	NdrFcShort( 0x0 ),	/* Offset= 0 (714) */
/* 716 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (715) */
/* 718 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 720 */	NdrFcShort( 0x8 ),	/* 8 */
/* 722 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 724 */	
			0x13, 0x0,	/* FC_OP */
/* 726 */	NdrFcShort( 0xfffffe38 ),	/* Offset= -456 (270) */
/* 728 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 730 */	NdrFcShort( 0x2 ),	/* Offset= 2 (732) */
/* 732 */	
			0x13, 0x0,	/* FC_OP */
/* 734 */	NdrFcShort( 0x1b6 ),	/* Offset= 438 (1172) */
/* 736 */	
			0x13, 0x0,	/* FC_OP */
/* 738 */	NdrFcShort( 0x20 ),	/* Offset= 32 (770) */
/* 740 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 742 */	NdrFcLong( 0x2f ),	/* 47 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 750 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 752 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 754 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 756 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 758 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 760 */	NdrFcShort( 0x1 ),	/* 1 */
/* 762 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 764 */	NdrFcShort( 0x4 ),	/* 4 */
/* 766 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 768 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 770 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 772 */	NdrFcShort( 0x10 ),	/* 16 */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0xa ),	/* Offset= 10 (786) */
/* 778 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 780 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 782 */	NdrFcShort( 0xffffffd6 ),	/* Offset= -42 (740) */
/* 784 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 786 */	
			0x13, 0x0,	/* FC_OP */
/* 788 */	NdrFcShort( 0xffffffe2 ),	/* Offset= -30 (758) */
/* 790 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 792 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 794 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 796 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 798 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 800 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 802 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 804 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 806 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 808 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 810 */	
			0x13, 0x0,	/* FC_OP */
/* 812 */	NdrFcShort( 0xffffffa2 ),	/* Offset= -94 (718) */
/* 814 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 816 */	NdrFcShort( 0xffffffa4 ),	/* Offset= -92 (724) */
/* 818 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 820 */	NdrFcShort( 0xfffffe18 ),	/* Offset= -488 (332) */
/* 822 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 824 */	NdrFcShort( 0xfffffe4c ),	/* Offset= -436 (388) */
/* 826 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 828 */	NdrFcShort( 0x2 ),	/* Offset= 2 (830) */
/* 830 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 832 */	NdrFcShort( 0x2 ),	/* Offset= 2 (834) */
/* 834 */	
			0x13, 0x0,	/* FC_OP */
/* 836 */	NdrFcShort( 0x150 ),	/* Offset= 336 (1172) */
/* 838 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 840 */	NdrFcShort( 0x2 ),	/* Offset= 2 (842) */
/* 842 */	
			0x13, 0x0,	/* FC_OP */
/* 844 */	NdrFcShort( 0x16 ),	/* Offset= 22 (866) */
/* 846 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 848 */	NdrFcShort( 0x10 ),	/* 16 */
/* 850 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 852 */	0x1,		/* FC_BYTE */
			0x38,		/* FC_ALIGNM4 */
/* 854 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 856 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 858 */	
			0x13, 0x0,	/* FC_OP */
/* 860 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (846) */
/* 862 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 864 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 866 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 868 */	NdrFcShort( 0x20 ),	/* 32 */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x0 ),	/* Offset= 0 (872) */
/* 874 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 876 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 878 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 880 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 882 */	NdrFcShort( 0xfffffe4a ),	/* Offset= -438 (444) */
/* 884 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 886 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 888 */	NdrFcShort( 0x4 ),	/* 4 */
/* 890 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 896 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 898 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 900 */	NdrFcShort( 0x4 ),	/* 4 */
/* 902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 904 */	NdrFcShort( 0x1 ),	/* 1 */
/* 906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	0x13, 0x0,	/* FC_OP */
/* 912 */	NdrFcShort( 0xffffffd2 ),	/* Offset= -46 (866) */
/* 914 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 916 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 918 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x6 ),	/* Offset= 6 (930) */
/* 926 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 928 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 930 */	
			0x11, 0x0,	/* FC_RP */
/* 932 */	NdrFcShort( 0xffffffd2 ),	/* Offset= -46 (886) */
/* 934 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 936 */	NdrFcShort( 0x4 ),	/* 4 */
/* 938 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 944 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 946 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 948 */	NdrFcShort( 0x4 ),	/* 4 */
/* 950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x1 ),	/* 1 */
/* 954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 958 */	0x13, 0x0,	/* FC_OP */
/* 960 */	NdrFcShort( 0xffffff42 ),	/* Offset= -190 (770) */
/* 962 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 964 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 966 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 968 */	NdrFcShort( 0x8 ),	/* 8 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x6 ),	/* Offset= 6 (978) */
/* 974 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 976 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 978 */	
			0x11, 0x0,	/* FC_RP */
/* 980 */	NdrFcShort( 0xffffffd2 ),	/* Offset= -46 (934) */
/* 982 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 984 */	NdrFcShort( 0x8 ),	/* 8 */
/* 986 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 988 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 990 */	NdrFcShort( 0x10 ),	/* 16 */
/* 992 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 994 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 996 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (982) */
			0x5b,		/* FC_END */
/* 1000 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1002 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0xa ),	/* Offset= 10 (1016) */
/* 1008 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1010 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1012 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (988) */
/* 1014 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1016 */	
			0x11, 0x0,	/* FC_RP */
/* 1018 */	NdrFcShort( 0xfffffd64 ),	/* Offset= -668 (350) */
/* 1020 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1022 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1024 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1028 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1030 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1032 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1036 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1038 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1040 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1042 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1044 */	0x13, 0x0,	/* FC_OP */
/* 1046 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (1020) */
/* 1048 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1050 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1052 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 1054 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1056 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1062 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 1064 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1066 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1068 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1070 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1072 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1074 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1076 */	0x13, 0x0,	/* FC_OP */
/* 1078 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (1052) */
/* 1080 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1082 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1084 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1086 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1088 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1094 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1096 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1100 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1102 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1104 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1106 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1108 */	0x13, 0x0,	/* FC_OP */
/* 1110 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (1084) */
/* 1112 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1114 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1116 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1120 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1126 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1128 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1132 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1134 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1136 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1138 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1140 */	0x13, 0x0,	/* FC_OP */
/* 1142 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (1116) */
/* 1144 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1146 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1148 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1152 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1154 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1156 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1160 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1162 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 1164 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1166 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1168 */	NdrFcShort( 0xffffffec ),	/* Offset= -20 (1148) */
/* 1170 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1172 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1174 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1176 */	NdrFcShort( 0xffffffec ),	/* Offset= -20 (1156) */
/* 1178 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1178) */
/* 1180 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1182 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 1184 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1186 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffc1b ),	/* Offset= -997 (190) */
			0x5b,		/* FC_END */
/* 1190 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1192 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1194 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1198 */	NdrFcShort( 0xfffffc08 ),	/* Offset= -1016 (182) */
/* 1200 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1202 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1204) */
/* 1204 */	
			0x12, 0x0,	/* FC_UP */
/* 1206 */	NdrFcShort( 0xffffffde ),	/* Offset= -34 (1172) */
/* 1208 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1210 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1212 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1216 */	NdrFcShort( 0xfffffff0 ),	/* Offset= -16 (1200) */
/* 1218 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1220 */	NdrFcShort( 0xfffffe9a ),	/* Offset= -358 (862) */
/* 1222 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1224 */	NdrFcShort( 0xfffffe06 ),	/* Offset= -506 (718) */
/* 1226 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1228 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1230 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1232 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1234 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1236 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1238 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1240 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 1242 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1244 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1246) */
/* 1246 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1248 */	NdrFcLong( 0xd5778ae3 ),	/* -713585949 */
/* 1252 */	NdrFcShort( 0x43de ),	/* 17374 */
/* 1254 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 1256 */	0x91,		/* 145 */
			0x71,		/* 113 */
/* 1258 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 1260 */	0x0,		/* 0 */
			0xc1,		/* 193 */
/* 1262 */	0x80,		/* 128 */
			0x68,		/* 104 */
/* 1264 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1266 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 1268 */	
			0x12, 0x0,	/* FC_UP */
/* 1270 */	NdrFcShort( 0xfffffc18 ),	/* Offset= -1000 (270) */
/* 1272 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1274 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1276 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1280 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (1268) */
/* 1282 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1284 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1286) */
/* 1286 */	
			0x13, 0x0,	/* FC_OP */
/* 1288 */	NdrFcShort( 0xfffffed4 ),	/* Offset= -300 (988) */
/* 1290 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1292 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1294) */
/* 1294 */	
			0x13, 0x0,	/* FC_OP */
/* 1296 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1298) */
/* 1298 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1300 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1302 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1304 */	0xe,		/* FC_ENUM32 */
			0xe,		/* FC_ENUM32 */
/* 1306 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1308 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1310 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */

			0x0
        }
    };

const CInterfaceProxyVtbl * _scardssp_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ISCardTypeConvProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISCardISO7816ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISCardProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISCardDatabaseProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISCardLocateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISCardCmdProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IByteBufferProxyVtbl,
    0
};

const CInterfaceStubVtbl * _scardssp_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ISCardTypeConvStubVtbl,
    ( CInterfaceStubVtbl *) &_ISCardISO7816StubVtbl,
    ( CInterfaceStubVtbl *) &_ISCardStubVtbl,
    ( CInterfaceStubVtbl *) &_ISCardDatabaseStubVtbl,
    ( CInterfaceStubVtbl *) &_ISCardLocateStubVtbl,
    ( CInterfaceStubVtbl *) &_ISCardCmdStubVtbl,
    ( CInterfaceStubVtbl *) &_IByteBufferStubVtbl,
    0
};

PCInterfaceName const _scardssp_InterfaceNamesList[] = 
{
    "ISCardTypeConv",
    "ISCardISO7816",
    "ISCard",
    "ISCardDatabase",
    "ISCardLocate",
    "ISCardCmd",
    "IByteBuffer",
    0
};

const IID *  _scardssp_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _scardssp_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _scardssp, pIID, n)

int __stdcall _scardssp_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _scardssp, 7, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _scardssp, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _scardssp, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _scardssp, 7, *pIndex )
    
}

const ExtendedProxyFileInfo scardssp_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _scardssp_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _scardssp_StubVtblList,
    (const PCInterfaceName * ) & _scardssp_InterfaceNamesList,
    (const IID ** ) & _scardssp_BaseIIDList,
    & _scardssp_IID_Lookup, 
    7,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};


#endif /* !defined(_M_IA64) && !defined(_M_AXP64)*/


#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 5.03.0279 */
/* at Fri Oct 01 16:58:17 1999
 */
/* Compiler settings for scardssp.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win64 (32b run,appending), ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if defined(_M_IA64) || defined(_M_AXP64)
#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "scardssp.h"

#define TYPE_FORMAT_STRING_SIZE   1273                              
#define PROC_FORMAT_STRING_SIZE   4079                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   3            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Standard interface: __MIDL_itf_scardssp_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IByteBuffer, ver. 0.0,
   GUID={0xE126F8FE,0xA7AF,0x11D0,{0xB8,0x8A,0x00,0xC0,0x4F,0xD4,0x24,0xB9}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IByteBuffer_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IByteBuffer_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    38,
    76,
    114,
    152,
    208,
    252,
    302,
    352,
    384,
    434,
    472,
    516,
    566
    };

static const MIDL_SERVER_INFO IByteBuffer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IByteBuffer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IByteBuffer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IByteBuffer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(21) _IByteBufferProxyVtbl = 
{
    &IByteBuffer_ProxyInfo,
    &IID_IByteBuffer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IByteBuffer::get_Stream */ ,
    (void *)-1 /* IByteBuffer::put_Stream */ ,
    (void *)-1 /* IByteBuffer::Clone */ ,
    (void *)-1 /* IByteBuffer::Commit */ ,
    (void *)-1 /* IByteBuffer::CopyTo */ ,
    (void *)-1 /* IByteBuffer::Initialize */ ,
    (void *)-1 /* IByteBuffer::LockRegion */ ,
    (void *)-1 /* IByteBuffer::Read */ ,
    (void *)-1 /* IByteBuffer::Revert */ ,
    (void *)-1 /* IByteBuffer::Seek */ ,
    (void *)-1 /* IByteBuffer::SetSize */ ,
    (void *)-1 /* IByteBuffer::Stat */ ,
    (void *)-1 /* IByteBuffer::UnlockRegion */ ,
    (void *)-1 /* IByteBuffer::Write */
};


static const PRPC_STUB_FUNCTION IByteBuffer_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IByteBufferStubVtbl =
{
    &IID_IByteBuffer,
    &IByteBuffer_ServerInfo,
    21,
    &IByteBuffer_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0244, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCardTypeConv, ver. 0.0,
   GUID={0x53B6AA63,0x3F56,0x11D0,{0x91,0x6B,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCardTypeConv_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCardTypeConv_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    616,
    666,
    710,
    754,
    798,
    842,
    886,
    930,
    974,
    1018
    };

static const MIDL_SERVER_INFO ISCardTypeConv_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCardTypeConv_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCardTypeConv_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCardTypeConv_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(17) _ISCardTypeConvProxyVtbl = 
{
    &ISCardTypeConv_ProxyInfo,
    &IID_ISCardTypeConv,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCardTypeConv::ConvertByteArrayToByteBuffer */ ,
    (void *)-1 /* ISCardTypeConv::ConvertByteBufferToByteArray */ ,
    (void *)-1 /* ISCardTypeConv::ConvertByteBufferToSafeArray */ ,
    (void *)-1 /* ISCardTypeConv::ConvertSafeArrayToByteBuffer */ ,
    (void *)-1 /* ISCardTypeConv::CreateByteArray */ ,
    (void *)-1 /* ISCardTypeConv::CreateByteBuffer */ ,
    (void *)-1 /* ISCardTypeConv::CreateSafeArray */ ,
    (void *)-1 /* ISCardTypeConv::FreeIStreamMemoryPtr */ ,
    (void *)-1 /* ISCardTypeConv::GetAtIStreamMemory */ ,
    (void *)-1 /* ISCardTypeConv::SizeOfIStream */
};


static const PRPC_STUB_FUNCTION ISCardTypeConv_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardTypeConvStubVtbl =
{
    &IID_ISCardTypeConv,
    &ISCardTypeConv_ServerInfo,
    17,
    &ISCardTypeConv_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0245, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCardCmd, ver. 0.0,
   GUID={0xD5778AE3,0x43DE,0x11D0,{0x91,0x71,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCardCmd_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCardCmd_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1062,
    1100,
    1138,
    1176,
    1214,
    1252,
    1290,
    1328,
    1366,
    1404,
    1442,
    1480,
    1518,
    1556,
    1594,
    1632,
    1670,
    1708,
    1746,
    1784,
    1822,
    1860,
    1898,
    1936,
    1974,
    2012,
    2050,
    2088,
    2126,
    2194,
    2226,
    2270,
    2308
    };

static const MIDL_SERVER_INFO ISCardCmd_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCardCmd_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCardCmd_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCardCmd_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(40) _ISCardCmdProxyVtbl = 
{
    &ISCardCmd_ProxyInfo,
    &IID_ISCardCmd,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCardCmd::get_Apdu */ ,
    (void *)-1 /* ISCardCmd::put_Apdu */ ,
    (void *)-1 /* ISCardCmd::get_ApduLength */ ,
    (void *)-1 /* ISCardCmd::get_ApduReply */ ,
    (void *)-1 /* ISCardCmd::put_ApduReply */ ,
    (void *)-1 /* ISCardCmd::get_ApduReplyLength */ ,
    (void *)-1 /* ISCardCmd::put_ApduReplyLength */ ,
    (void *)-1 /* ISCardCmd::get_ClassId */ ,
    (void *)-1 /* ISCardCmd::put_ClassId */ ,
    (void *)-1 /* ISCardCmd::get_Data */ ,
    (void *)-1 /* ISCardCmd::put_Data */ ,
    (void *)-1 /* ISCardCmd::get_InstructionId */ ,
    (void *)-1 /* ISCardCmd::put_InstructionId */ ,
    (void *)-1 /* ISCardCmd::get_LeField */ ,
    (void *)-1 /* ISCardCmd::get_P1 */ ,
    (void *)-1 /* ISCardCmd::put_P1 */ ,
    (void *)-1 /* ISCardCmd::get_P2 */ ,
    (void *)-1 /* ISCardCmd::put_P2 */ ,
    (void *)-1 /* ISCardCmd::get_P3 */ ,
    (void *)-1 /* ISCardCmd::get_ReplyStatus */ ,
    (void *)-1 /* ISCardCmd::put_ReplyStatus */ ,
    (void *)-1 /* ISCardCmd::get_ReplyStatusSW1 */ ,
    (void *)-1 /* ISCardCmd::get_ReplyStatusSW2 */ ,
    (void *)-1 /* ISCardCmd::get_Type */ ,
    (void *)-1 /* ISCardCmd::get_Nad */ ,
    (void *)-1 /* ISCardCmd::put_Nad */ ,
    (void *)-1 /* ISCardCmd::get_ReplyNad */ ,
    (void *)-1 /* ISCardCmd::put_ReplyNad */ ,
    (void *)-1 /* ISCardCmd::BuildCmd */ ,
    (void *)-1 /* ISCardCmd::Clear */ ,
    (void *)-1 /* ISCardCmd::Encapsulate */ ,
    (void *)-1 /* ISCardCmd::get_AlternateClassId */ ,
    (void *)-1 /* ISCardCmd::put_AlternateClassId */
};


static const PRPC_STUB_FUNCTION ISCardCmd_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardCmdStubVtbl =
{
    &IID_ISCardCmd,
    &ISCardCmd_ServerInfo,
    40,
    &ISCardCmd_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0246, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCardISO7816, ver. 0.0,
   GUID={0x53B6AA68,0x3F56,0x11D0,{0x91,0x6B,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCardISO7816_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCardISO7816_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    2346,
    2396,
    2452,
    2508,
    2552,
    2608,
    2664,
    2726,
    2776,
    2832,
    2888,
    2944,
    1518,
    3006,
    3062,
    3118,
    3168,
    3224
    };

static const MIDL_SERVER_INFO ISCardISO7816_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCardISO7816_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCardISO7816_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCardISO7816_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(25) _ISCardISO7816ProxyVtbl = 
{
    &ISCardISO7816_ProxyInfo,
    &IID_ISCardISO7816,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCardISO7816::AppendRecord */ ,
    (void *)-1 /* ISCardISO7816::EraseBinary */ ,
    (void *)-1 /* ISCardISO7816::ExternalAuthenticate */ ,
    (void *)-1 /* ISCardISO7816::GetChallenge */ ,
    (void *)-1 /* ISCardISO7816::GetData */ ,
    (void *)-1 /* ISCardISO7816::GetResponse */ ,
    (void *)-1 /* ISCardISO7816::InternalAuthenticate */ ,
    (void *)-1 /* ISCardISO7816::ManageChannel */ ,
    (void *)-1 /* ISCardISO7816::PutData */ ,
    (void *)-1 /* ISCardISO7816::ReadBinary */ ,
    (void *)-1 /* ISCardISO7816::ReadRecord */ ,
    (void *)-1 /* ISCardISO7816::SelectFile */ ,
    (void *)-1 /* ISCardISO7816::SetDefaultClassId */ ,
    (void *)-1 /* ISCardISO7816::UpdateBinary */ ,
    (void *)-1 /* ISCardISO7816::UpdateRecord */ ,
    (void *)-1 /* ISCardISO7816::Verify */ ,
    (void *)-1 /* ISCardISO7816::WriteBinary */ ,
    (void *)-1 /* ISCardISO7816::WriteRecord */
};


static const PRPC_STUB_FUNCTION ISCardISO7816_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardISO7816StubVtbl =
{
    &IID_ISCardISO7816,
    &ISCardISO7816_ServerInfo,
    25,
    &ISCardISO7816_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0247, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCard, ver. 0.0,
   GUID={0x1461AAC3,0x6810,0x11D0,{0x91,0x8F,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCard_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCard_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1062,
    3280,
    3318,
    3356,
    3394,
    3432,
    3470,
    3520,
    352,
    3558,
    3602,
    3640
    };

static const MIDL_SERVER_INFO ISCard_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCard_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCard_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCard_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(19) _ISCardProxyVtbl = 
{
    &ISCard_ProxyInfo,
    &IID_ISCard,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCard::get_Atr */ ,
    (void *)-1 /* ISCard::get_CardHandle */ ,
    (void *)-1 /* ISCard::get_Context */ ,
    (void *)-1 /* ISCard::get_Protocol */ ,
    (void *)-1 /* ISCard::get_Status */ ,
    (void *)-1 /* ISCard::AttachByHandle */ ,
    (void *)-1 /* ISCard::AttachByReader */ ,
    (void *)-1 /* ISCard::Detach */ ,
    (void *)-1 /* ISCard::LockSCard */ ,
    (void *)-1 /* ISCard::ReAttach */ ,
    (void *)-1 /* ISCard::Transaction */ ,
    (void *)-1 /* ISCard::UnlockSCard */
};


static const PRPC_STUB_FUNCTION ISCard_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardStubVtbl =
{
    &IID_ISCard,
    &ISCard_ServerInfo,
    19,
    &ISCard_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0248, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCardDatabase, ver. 0.0,
   GUID={0x1461AAC8,0x6810,0x11D0,{0x91,0x8F,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCardDatabase_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCardDatabase_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    3678,
    3722,
    3766,
    3822,
    3866
    };

static const MIDL_SERVER_INFO ISCardDatabase_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCardDatabase_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCardDatabase_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCardDatabase_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(12) _ISCardDatabaseProxyVtbl = 
{
    &ISCardDatabase_ProxyInfo,
    &IID_ISCardDatabase,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCardDatabase::GetProviderCardId */ ,
    (void *)-1 /* ISCardDatabase::ListCardInterfaces */ ,
    (void *)-1 /* ISCardDatabase::ListCards */ ,
    (void *)-1 /* ISCardDatabase::ListReaderGroups */ ,
    (void *)-1 /* ISCardDatabase::ListReaders */
};


static const PRPC_STUB_FUNCTION ISCardDatabase_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardDatabaseStubVtbl =
{
    &IID_ISCardDatabase,
    &ISCardDatabase_ServerInfo,
    12,
    &ISCardDatabase_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0249, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ISCardLocate, ver. 0.0,
   GUID={0x1461AACD,0x6810,0x11D0,{0x91,0x8F,0x00,0xAA,0x00,0xC1,0x80,0x68}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISCardLocate_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ISCardLocate_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    3910,
    3966,
    4022
    };

static const MIDL_SERVER_INFO ISCardLocate_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISCardLocate_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISCardLocate_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISCardLocate_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(10) _ISCardLocateProxyVtbl = 
{
    &ISCardLocate_ProxyInfo,
    &IID_ISCardLocate,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISCardLocate::ConfigureCardGuidSearch */ ,
    (void *)-1 /* ISCardLocate::ConfigureCardNameSearch */ ,
    (void *)-1 /* ISCardLocate::FindCard */
};


static const PRPC_STUB_FUNCTION ISCardLocate_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISCardLocateStubVtbl =
{
    &IID_ISCardLocate,
    &ISCardLocate_ServerInfo,
    10,
    &ISCardLocate_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_scardssp_0250, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */

extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x5030117, /* MIDL Version 5.3.279 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            HGLOBAL_UserSize
            ,HGLOBAL_UserMarshal
            ,HGLOBAL_UserUnmarshal
            ,HGLOBAL_UserFree
            },
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            },
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };


#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_Stream */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppStream */

/* 26 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 28 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 32 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Stream */

/* 38 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 40 */	NdrFcLong( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x8 ),	/* 8 */
/* 46 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x8 ),	/* 8 */
/* 52 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 54 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStream */

/* 64 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 66 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 68 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 70 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 72 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 76 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 78 */	NdrFcLong( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x9 ),	/* 9 */
/* 84 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x8 ),	/* 8 */
/* 90 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 92 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppByteBuffer */

/* 102 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 104 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 106 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Commit */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0xa ),	/* 10 */
/* 122 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 128 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 130 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter grfCommitFlags */

/* 140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 142 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 148 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyTo */

/* 152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0xb ),	/* 11 */
/* 160 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 162 */	NdrFcShort( 0x18 ),	/* 24 */
/* 164 */	NdrFcShort( 0x18 ),	/* 24 */
/* 166 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 168 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppByteBuffer */

/* 178 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 180 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 182 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Parameter cb */

/* 184 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 186 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbRead */

/* 190 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 192 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbWritten */

/* 196 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 198 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 204 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0xc ),	/* 12 */
/* 216 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 218 */	NdrFcShort( 0xd ),	/* 13 */
/* 220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 222 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 224 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lSize */

/* 234 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 236 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pData */

/* 240 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 242 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 244 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 248 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LockRegion */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0xd ),	/* 13 */
/* 260 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 262 */	NdrFcShort( 0x18 ),	/* 24 */
/* 264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 266 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 268 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libOffset */

/* 278 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 280 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cb */

/* 284 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 286 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwLockType */

/* 290 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 292 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 294 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 296 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 298 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Read */

/* 302 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0xe ),	/* 14 */
/* 310 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 312 */	NdrFcShort( 0x15 ),	/* 21 */
/* 314 */	NdrFcShort( 0x15 ),	/* 21 */
/* 316 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 318 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pByte */

/* 328 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 330 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 332 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter cb */

/* 334 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 336 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbRead */

/* 340 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 342 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 346 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 348 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LockSCard */


	/* Procedure Revert */

/* 352 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 354 */	NdrFcLong( 0x0 ),	/* 0 */
/* 358 */	NdrFcShort( 0xf ),	/* 15 */
/* 360 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 366 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 368 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 380 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Seek */

/* 384 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0x10 ),	/* 16 */
/* 392 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 394 */	NdrFcShort( 0x18 ),	/* 24 */
/* 396 */	NdrFcShort( 0x10 ),	/* 16 */
/* 398 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 400 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dLibMove */

/* 410 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 412 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwOrigin */

/* 416 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 418 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pLibnewPosition */

/* 422 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 424 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 428 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 430 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSize */

/* 434 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 436 */	NdrFcLong( 0x0 ),	/* 0 */
/* 440 */	NdrFcShort( 0x11 ),	/* 17 */
/* 442 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 444 */	NdrFcShort( 0x8 ),	/* 8 */
/* 446 */	NdrFcShort( 0x8 ),	/* 8 */
/* 448 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 450 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 458 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libNewSize */

/* 460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 462 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 466 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 468 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stat */

/* 472 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 474 */	NdrFcLong( 0x0 ),	/* 0 */
/* 478 */	NdrFcShort( 0x12 ),	/* 18 */
/* 480 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 482 */	NdrFcShort( 0x24 ),	/* 36 */
/* 484 */	NdrFcShort( 0x24 ),	/* 36 */
/* 486 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 488 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pstatstg */

/* 498 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 500 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 502 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Parameter grfStatFlag */

/* 504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 506 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 512 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnlockRegion */

/* 516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x13 ),	/* 19 */
/* 524 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 526 */	NdrFcShort( 0x18 ),	/* 24 */
/* 528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 530 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 532 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libOffset */

/* 542 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 544 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cb */

/* 548 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 550 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwLockType */

/* 554 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 556 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 562 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Write */

/* 566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x14 ),	/* 20 */
/* 574 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 576 */	NdrFcShort( 0x15 ),	/* 21 */
/* 578 */	NdrFcShort( 0x15 ),	/* 21 */
/* 580 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 582 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pByte */

/* 592 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 594 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 596 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter cb */

/* 598 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 600 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbWritten */

/* 604 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 606 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 610 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 612 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConvertByteArrayToByteBuffer */

/* 616 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 618 */	NdrFcLong( 0x0 ),	/* 0 */
/* 622 */	NdrFcShort( 0x7 ),	/* 7 */
/* 624 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 626 */	NdrFcShort( 0xd ),	/* 13 */
/* 628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 630 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 632 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyArray */

/* 642 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 644 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 646 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter dwArraySize */

/* 648 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 650 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppbyBuffer */

/* 654 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 656 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 658 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 660 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 662 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 664 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConvertByteBufferToByteArray */

/* 666 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 668 */	NdrFcLong( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 674 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0x8 ),	/* 8 */
/* 680 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 682 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 684 */	NdrFcShort( 0x3 ),	/* 3 */
/* 686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyBuffer */

/* 692 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 694 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 696 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppArray */

/* 698 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 700 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 702 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */

	/* Return value */

/* 704 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 706 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConvertByteBufferToSafeArray */

/* 710 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 712 */	NdrFcLong( 0x0 ),	/* 0 */
/* 716 */	NdrFcShort( 0x9 ),	/* 9 */
/* 718 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x8 ),	/* 8 */
/* 724 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 726 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 728 */	NdrFcShort( 0x12 ),	/* 18 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyBuffer */

/* 736 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 738 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 740 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppbyArray */

/* 742 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 744 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 746 */	NdrFcShort( 0x476 ),	/* Type Offset=1142 */

	/* Return value */

/* 748 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 750 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConvertSafeArrayToByteBuffer */

/* 754 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 756 */	NdrFcLong( 0x0 ),	/* 0 */
/* 760 */	NdrFcShort( 0xa ),	/* 10 */
/* 762 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 768 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 770 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0x12 ),	/* 18 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyArray */

/* 780 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 782 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 784 */	NdrFcShort( 0x488 ),	/* Type Offset=1160 */

	/* Parameter ppbyBuff */

/* 786 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 788 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 790 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 794 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateByteArray */

/* 798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0xb ),	/* 11 */
/* 806 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 808 */	NdrFcShort( 0x8 ),	/* 8 */
/* 810 */	NdrFcShort( 0x15 ),	/* 21 */
/* 812 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 814 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwAllocSize */

/* 824 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 826 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppbyArray */

/* 830 */	NdrFcShort( 0x2012 ),	/* Flags:  must free, out, srv alloc size=8 */
/* 832 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 834 */	NdrFcShort( 0x492 ),	/* Type Offset=1170 */

	/* Return value */

/* 836 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 838 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateByteBuffer */

/* 842 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 844 */	NdrFcLong( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0xc ),	/* 12 */
/* 850 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 856 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 858 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwAllocSize */

/* 868 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 870 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppbyBuff */

/* 874 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 876 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 878 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 882 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateSafeArray */

/* 886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0xd ),	/* 13 */
/* 894 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 900 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 902 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 904 */	NdrFcShort( 0x12 ),	/* 18 */
/* 906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nAllocSize */

/* 912 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 914 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppArray */

/* 918 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 920 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 922 */	NdrFcShort( 0x476 ),	/* Type Offset=1142 */

	/* Return value */

/* 924 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 926 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FreeIStreamMemoryPtr */

/* 930 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 932 */	NdrFcLong( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0xe ),	/* 14 */
/* 938 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 940 */	NdrFcShort( 0x5 ),	/* 5 */
/* 942 */	NdrFcShort( 0x8 ),	/* 8 */
/* 944 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 946 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStrm */

/* 956 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 958 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 960 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter pMem */

/* 962 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 964 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 966 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 968 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 970 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAtIStreamMemory */

/* 974 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 976 */	NdrFcLong( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0xf ),	/* 15 */
/* 982 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 986 */	NdrFcShort( 0x8 ),	/* 8 */
/* 988 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 990 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 992 */	NdrFcShort( 0x3 ),	/* 3 */
/* 994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStrm */

/* 1000 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1002 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1004 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter ppMem */

/* 1006 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1008 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1010 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */

	/* Return value */

/* 1012 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1014 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1016 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SizeOfIStream */

/* 1018 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1020 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1024 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1026 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1030 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1032 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1034 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStrm */

/* 1044 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1046 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1048 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter puliSize */

/* 1050 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1052 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1054 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Return value */

/* 1056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1058 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Atr */


	/* Procedure get_Apdu */

/* 1062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1070 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1076 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1078 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppAtr */


	/* Parameter ppApdu */

/* 1088 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1090 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1092 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */

/* 1094 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1096 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Apdu */

/* 1100 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1102 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1108 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1112 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1114 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1116 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pApdu */

/* 1126 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1128 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1130 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 1132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1134 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ApduLength */

/* 1138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1144 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1146 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1150 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1152 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1154 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter plSize */

/* 1164 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1166 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1172 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ApduReply */

/* 1176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1182 */	NdrFcShort( 0xa ),	/* 10 */
/* 1184 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1190 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1192 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppReplyApdu */

/* 1202 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1204 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1206 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 1208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1210 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ApduReply */

/* 1214 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1220 */	NdrFcShort( 0xb ),	/* 11 */
/* 1222 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1226 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1228 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1230 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pReplyApdu */

/* 1240 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1242 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1244 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 1246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1248 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ApduReplyLength */

/* 1252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1258 */	NdrFcShort( 0xc ),	/* 12 */
/* 1260 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1264 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1266 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1268 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter plSize */

/* 1278 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1280 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1286 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ApduReplyLength */

/* 1290 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0xd ),	/* 13 */
/* 1298 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1302 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1304 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1306 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1314 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lSize */

/* 1316 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1318 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1322 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1324 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ClassId */

/* 1328 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1334 */	NdrFcShort( 0xe ),	/* 14 */
/* 1336 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0xd ),	/* 13 */
/* 1342 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1344 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyClass */

/* 1354 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1356 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1358 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1362 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ClassId */

/* 1366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0xf ),	/* 15 */
/* 1374 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1376 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1380 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1382 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1390 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byClass */

/* 1392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1394 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1396 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1398 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1400 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Data */

/* 1404 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1410 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1412 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1416 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1418 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1420 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1428 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppData */

/* 1430 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1432 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1434 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 1436 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1438 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Data */

/* 1442 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1444 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1448 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1450 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1456 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1458 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pData */

/* 1468 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1470 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1472 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 1474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1476 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_InstructionId */

/* 1480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1486 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1488 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1492 */	NdrFcShort( 0xd ),	/* 13 */
/* 1494 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1496 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1504 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyIns */

/* 1506 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1508 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1510 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1512 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1514 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDefaultClassId */


	/* Procedure put_InstructionId */

/* 1518 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1520 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1526 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1528 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1532 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1534 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1542 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byClass */


	/* Parameter byIns */

/* 1544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1546 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1548 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1550 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1552 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LeField */

/* 1556 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1558 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1562 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1564 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1568 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1570 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1572 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1580 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter plSize */

/* 1582 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1584 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1588 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1590 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_P1 */

/* 1594 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1600 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1602 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1606 */	NdrFcShort( 0xd ),	/* 13 */
/* 1608 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1610 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyP1 */

/* 1620 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1622 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1624 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1626 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1628 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_P1 */

/* 1632 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1638 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1640 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1642 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1644 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1646 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1648 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1656 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 1658 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1660 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1662 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1664 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1666 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_P2 */

/* 1670 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1672 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1676 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1678 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1682 */	NdrFcShort( 0xd ),	/* 13 */
/* 1684 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1686 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1694 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyP2 */

/* 1696 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1698 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1700 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1702 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1704 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_P2 */

/* 1708 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1710 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1714 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1716 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1718 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1720 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1722 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1724 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1732 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP2 */

/* 1734 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1736 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1738 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1740 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1742 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_P3 */

/* 1746 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1748 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1754 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1758 */	NdrFcShort( 0xd ),	/* 13 */
/* 1760 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1762 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1770 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyP3 */

/* 1772 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1774 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1776 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1778 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1780 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1782 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ReplyStatus */

/* 1784 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1786 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1790 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1792 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1796 */	NdrFcShort( 0xe ),	/* 14 */
/* 1798 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1800 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1808 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwStatus */

/* 1810 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1812 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1814 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1816 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1818 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ReplyStatus */

/* 1822 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1824 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1828 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1830 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1832 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1834 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1836 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1838 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1846 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wStatus */

/* 1848 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1850 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1852 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1854 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1856 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ReplyStatusSW1 */

/* 1860 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1862 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1868 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0xd ),	/* 13 */
/* 1874 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1876 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1884 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbySW1 */

/* 1886 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1888 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1890 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1892 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1894 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1896 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ReplyStatusSW2 */

/* 1898 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1900 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1904 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1906 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1910 */	NdrFcShort( 0xd ),	/* 13 */
/* 1912 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1914 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbySW2 */

/* 1924 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1926 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1928 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1930 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1932 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Type */

/* 1936 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1938 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1942 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1944 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1948 */	NdrFcShort( 0xe ),	/* 14 */
/* 1950 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1952 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1960 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 1962 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 1964 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1966 */	NdrFcShort( 0x4a6 ),	/* Type Offset=1190 */

	/* Return value */

/* 1968 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1970 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Nad */

/* 1974 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1976 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1980 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1982 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1986 */	NdrFcShort( 0xd ),	/* 13 */
/* 1988 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1990 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1998 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbNad */

/* 2000 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2002 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2004 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 2006 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2008 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Nad */

/* 2012 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2018 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2020 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2022 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2026 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2028 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2036 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bNad */

/* 2038 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2040 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2042 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 2044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2046 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ReplyNad */

/* 2050 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2056 */	NdrFcShort( 0x21 ),	/* 33 */
/* 2058 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2062 */	NdrFcShort( 0xd ),	/* 13 */
/* 2064 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2066 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2074 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbNad */

/* 2076 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2078 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2080 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 2082 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2084 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ReplyNad */

/* 2088 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2090 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2094 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2096 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2098 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2100 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2102 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2104 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bNad */

/* 2114 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2116 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2118 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 2120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2122 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BuildCmd */

/* 2126 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2132 */	NdrFcShort( 0x23 ),	/* 35 */
/* 2134 */	NdrFcShort( 0x40 ),	/* ia64, axp64 Stack size/offset = 64 */
/* 2136 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2140 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2142 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byClassId */

/* 2152 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2154 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2156 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byInsId */

/* 2158 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2160 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2162 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP1 */

/* 2164 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2166 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2168 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2172 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2174 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pbyData */

/* 2176 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2178 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2180 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter plLe */

/* 2182 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2184 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 2186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2190 */	NdrFcShort( 0x38 ),	/* ia64, axp64 Stack size/offset = 56 */
/* 2192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clear */

/* 2194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2200 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2202 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2208 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2210 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2222 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Encapsulate */

/* 2226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2232 */	NdrFcShort( 0x25 ),	/* 37 */
/* 2234 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2236 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2240 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2242 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pApdu */

/* 2252 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2254 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2256 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ApduType */

/* 2258 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2260 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2262 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 2264 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2266 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_AlternateClassId */

/* 2270 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2272 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2276 */	NdrFcShort( 0x26 ),	/* 38 */
/* 2278 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2282 */	NdrFcShort( 0xd ),	/* 13 */
/* 2284 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2286 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2294 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbyClass */

/* 2296 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2298 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2300 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 2302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2304 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_AlternateClassId */

/* 2308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2314 */	NdrFcShort( 0x27 ),	/* 39 */
/* 2316 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2318 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2322 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2324 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2332 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byClass */

/* 2334 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2336 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2338 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 2340 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2342 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendRecord */

/* 2346 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2348 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2352 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2354 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2356 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2358 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2360 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2362 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2370 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byRefCtrl */

/* 2372 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2374 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2376 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 2378 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2380 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2382 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 2384 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2386 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2388 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 2390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2392 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EraseBinary */

/* 2396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2404 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 2406 */	NdrFcShort( 0xa ),	/* 10 */
/* 2408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2410 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2412 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2422 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2424 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2426 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2430 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2432 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 2434 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2436 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2438 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 2440 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2442 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2444 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 2446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2448 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExternalAuthenticate */

/* 2452 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2458 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2460 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 2462 */	NdrFcShort( 0xa ),	/* 10 */
/* 2464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2466 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2468 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2476 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byAlgorithmRef */

/* 2478 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2480 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2482 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter bySecretRef */

/* 2484 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2486 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2488 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pChallenge */

/* 2490 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2492 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2494 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 2496 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2498 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2500 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 2502 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2504 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetChallenge */

/* 2508 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2510 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2514 */	NdrFcShort( 0xa ),	/* 10 */
/* 2516 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2520 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2522 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2524 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2532 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lBytesExpected */

/* 2534 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2536 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2540 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2542 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2544 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 2546 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2548 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetData */

/* 2552 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2558 */	NdrFcShort( 0xb ),	/* 11 */
/* 2560 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 2562 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2566 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2568 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2578 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2580 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2582 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2584 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2586 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2588 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter lBytesToGet */

/* 2590 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2592 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2596 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2598 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2600 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 2602 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2604 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2606 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResponse */

/* 2608 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2614 */	NdrFcShort( 0xc ),	/* 12 */
/* 2616 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 2618 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2620 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2622 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2624 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2632 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2634 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2636 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2638 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2640 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2642 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2644 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter lDataLength */

/* 2646 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2648 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2652 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2654 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2656 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 2658 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2660 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InternalAuthenticate */

/* 2664 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2670 */	NdrFcShort( 0xd ),	/* 13 */
/* 2672 */	NdrFcShort( 0x38 ),	/* ia64, axp64 Stack size/offset = 56 */
/* 2674 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2676 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2678 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2680 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2688 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byAlgorithmRef */

/* 2690 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2692 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2694 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter bySecretRef */

/* 2696 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2698 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2700 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pChallenge */

/* 2702 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2704 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2706 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter lReplyBytes */

/* 2708 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2710 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2714 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2716 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2718 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 2720 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2722 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 2724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ManageChannel */

/* 2726 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2732 */	NdrFcShort( 0xe ),	/* 14 */
/* 2734 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2736 */	NdrFcShort( 0xa ),	/* 10 */
/* 2738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2740 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2742 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2750 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byChannelState */

/* 2752 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2754 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2756 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byChannel */

/* 2758 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2760 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2762 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2764 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2766 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2768 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 2770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2772 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PutData */

/* 2776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2782 */	NdrFcShort( 0xf ),	/* 15 */
/* 2784 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 2786 */	NdrFcShort( 0xa ),	/* 10 */
/* 2788 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2790 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2792 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2800 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2802 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2804 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2806 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2808 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2810 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2812 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 2814 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2816 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2818 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 2820 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2822 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2824 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 2826 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2828 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadBinary */

/* 2832 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2834 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2838 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2840 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 2842 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2846 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2848 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2858 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2860 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2862 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2864 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2866 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2868 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter lBytesToRead */

/* 2870 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2872 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2876 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2878 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2880 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 2882 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2884 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadRecord */

/* 2888 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2890 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2894 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2896 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 2898 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2900 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2902 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2904 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byRecordId */

/* 2914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2916 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2918 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byRefCtrl */

/* 2920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2922 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2924 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter lBytesToRead */

/* 2926 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2928 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2932 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2934 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2936 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 2938 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2940 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectFile */

/* 2944 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2946 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2950 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2952 */	NdrFcShort( 0x38 ),	/* ia64, axp64 Stack size/offset = 56 */
/* 2954 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2956 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2958 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2960 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2968 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 2970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2972 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2974 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 2976 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2978 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2980 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 2982 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2984 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2986 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter lBytesToRead */

/* 2988 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2990 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCmd */

/* 2994 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2996 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2998 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 3000 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3002 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 3004 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateBinary */

/* 3006 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3008 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3012 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3014 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 3016 */	NdrFcShort( 0xa ),	/* 10 */
/* 3018 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3020 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3022 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3030 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 3032 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3034 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3036 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 3038 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3040 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3042 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 3044 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3046 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3048 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 3050 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3052 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3054 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 3056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3058 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 3060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateRecord */

/* 3062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3068 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3070 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 3072 */	NdrFcShort( 0xa ),	/* 10 */
/* 3074 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3076 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3078 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3086 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byRecordId */

/* 3088 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3090 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3092 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byRefCtrl */

/* 3094 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3096 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3098 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 3100 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3102 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3104 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 3106 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3108 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3110 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 3112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3114 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 3116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Verify */

/* 3118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3124 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3126 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 3128 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3132 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3134 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byRefCtrl */

/* 3144 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3146 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3148 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 3150 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3152 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3154 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 3156 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3158 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3160 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 3162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3164 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteBinary */

/* 3168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3174 */	NdrFcShort( 0x17 ),	/* 23 */
/* 3176 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 3178 */	NdrFcShort( 0xa ),	/* 10 */
/* 3180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3182 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3184 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3192 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byP1 */

/* 3194 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3196 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3198 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byP2 */

/* 3200 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3202 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3204 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 3206 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3208 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3210 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 3212 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3214 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3216 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 3218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3220 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 3222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteRecord */

/* 3224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3230 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3232 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 3234 */	NdrFcShort( 0xa ),	/* 10 */
/* 3236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3238 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3240 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3248 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter byRecordId */

/* 3250 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3252 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3254 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter byRefCtrl */

/* 3256 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3258 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3260 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pData */

/* 3262 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3264 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3266 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter ppCmd */

/* 3268 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3270 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3272 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 3274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3276 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 3278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CardHandle */

/* 3280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3286 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3288 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3292 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3294 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3296 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pHandle */

/* 3306 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3308 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3310 */	0xb9,		/* FC_UINT3264 */
			0x0,		/* 0 */

	/* Return value */

/* 3312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3314 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Context */

/* 3318 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3324 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3326 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3330 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3332 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3334 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pContext */

/* 3344 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3346 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3348 */	0xb9,		/* FC_UINT3264 */
			0x0,		/* 0 */

	/* Return value */

/* 3350 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3352 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Protocol */

/* 3356 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3362 */	NdrFcShort( 0xa ),	/* 10 */
/* 3364 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3368 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3370 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3372 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3380 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pProtocol */

/* 3382 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3384 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3386 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3388 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3390 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Status */

/* 3394 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3396 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3400 */	NdrFcShort( 0xb ),	/* 11 */
/* 3402 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3406 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3408 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3410 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3418 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStatus */

/* 3420 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3422 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3424 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3426 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3428 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AttachByHandle */

/* 3432 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3434 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3438 */	NdrFcShort( 0xc ),	/* 12 */
/* 3440 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3442 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3444 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3446 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3448 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3456 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hCard */

/* 3458 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3460 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3462 */	0xb9,		/* FC_UINT3264 */
			0x0,		/* 0 */

	/* Return value */

/* 3464 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3466 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AttachByReader */

/* 3470 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3472 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3476 */	NdrFcShort( 0xd ),	/* 13 */
/* 3478 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 3480 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3482 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3484 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3486 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3490 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3494 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrReaderName */

/* 3496 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3498 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3500 */	NdrFcShort( 0x4cc ),	/* Type Offset=1228 */

	/* Parameter ShareMode */

/* 3502 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3504 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3506 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter PrefProtocol */

/* 3508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3510 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3512 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3514 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3516 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Detach */

/* 3520 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3522 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3526 */	NdrFcShort( 0xe ),	/* 14 */
/* 3528 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3532 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3534 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3536 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3544 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Disposition */

/* 3546 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3548 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3550 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3552 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3554 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReAttach */

/* 3558 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3560 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3564 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3566 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3568 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3572 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3574 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ShareMode */

/* 3584 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3586 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3588 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter InitState */

/* 3590 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3592 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3594 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3596 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3598 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Transaction */

/* 3602 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3604 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3608 */	NdrFcShort( 0x11 ),	/* 17 */
/* 3610 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3616 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3618 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3626 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCmd */

/* 3628 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3630 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3632 */	NdrFcShort( 0x4aa ),	/* Type Offset=1194 */

	/* Return value */

/* 3634 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3636 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnlockSCard */

/* 3640 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3642 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3646 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3648 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3652 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3654 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3656 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Disposition */

/* 3666 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3668 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3670 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3674 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetProviderCardId */

/* 3678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3684 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3686 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3690 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3692 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3694 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3698 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3702 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrCardName */

/* 3704 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3706 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3708 */	NdrFcShort( 0x4cc ),	/* Type Offset=1228 */

	/* Parameter ppguidProviderId */

/* 3710 */	NdrFcShort( 0x2012 ),	/* Flags:  must free, out, srv alloc size=8 */
/* 3712 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3714 */	NdrFcShort( 0x4d6 ),	/* Type Offset=1238 */

	/* Return value */

/* 3716 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3718 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ListCardInterfaces */

/* 3722 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3724 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3730 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3736 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3738 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3740 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3742 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3746 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrCardName */

/* 3748 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3750 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3752 */	NdrFcShort( 0x4cc ),	/* Type Offset=1228 */

	/* Parameter ppInterfaceGuids */

/* 3754 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3756 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3758 */	NdrFcShort( 0x476 ),	/* Type Offset=1142 */

	/* Return value */

/* 3760 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3762 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3764 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ListCards */

/* 3766 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3768 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3772 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3774 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 3776 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3778 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3780 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3782 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3784 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3786 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3790 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAtr */

/* 3792 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3794 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3796 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter pInterfaceGuids */

/* 3798 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3800 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3802 */	NdrFcShort( 0x488 ),	/* Type Offset=1160 */

	/* Parameter localeId */

/* 3804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3806 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCardNames */

/* 3810 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3812 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3814 */	NdrFcShort( 0x476 ),	/* Type Offset=1142 */

	/* Return value */

/* 3816 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3818 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 3820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ListReaderGroups */

/* 3822 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3824 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3828 */	NdrFcShort( 0xa ),	/* 10 */
/* 3830 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3834 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3836 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3838 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3840 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3846 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter localeId */

/* 3848 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3850 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppReaderGroups */

/* 3854 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3856 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3858 */	NdrFcShort( 0x476 ),	/* Type Offset=1142 */

	/* Return value */

/* 3860 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3862 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ListReaders */

/* 3866 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3868 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3872 */	NdrFcShort( 0xb ),	/* 11 */
/* 3874 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3876 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3878 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3880 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3882 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3884 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3890 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter localeId */

/* 3892 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3894 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3896 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppReaders */

/* 3898 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3900 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3902 */	NdrFcShort( 0x476 ),	/* Type Offset=1142 */

	/* Return value */

/* 3904 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3906 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConfigureCardGuidSearch */

/* 3910 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3912 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3916 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3918 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 3920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3922 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3924 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3926 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3930 */	NdrFcShort( 0x25 ),	/* 37 */
/* 3932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3934 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCardGuids */

/* 3936 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3938 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3940 */	NdrFcShort( 0x488 ),	/* Type Offset=1160 */

	/* Parameter pGroupNames */

/* 3942 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3944 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 3946 */	NdrFcShort( 0x488 ),	/* Type Offset=1160 */

	/* Parameter bstrTitle */

/* 3948 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3950 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 3952 */	NdrFcShort( 0x4cc ),	/* Type Offset=1228 */

	/* Parameter lFlags */

/* 3954 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3956 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 3958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3960 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3962 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 3964 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConfigureCardNameSearch */

/* 3966 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3968 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3974 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 3976 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3978 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3980 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3982 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3986 */	NdrFcShort( 0x25 ),	/* 37 */
/* 3988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3990 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCardNames */

/* 3992 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3994 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 3996 */	NdrFcShort( 0x488 ),	/* Type Offset=1160 */

	/* Parameter pGroupNames */

/* 3998 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4000 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 4002 */	NdrFcShort( 0x488 ),	/* Type Offset=1160 */

	/* Parameter bstrTitle */

/* 4004 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4006 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 4008 */	NdrFcShort( 0x4cc ),	/* Type Offset=1228 */

	/* Parameter lFlags */

/* 4010 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4012 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 4014 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4016 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4018 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 4020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindCard */

/* 4022 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4024 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4028 */	NdrFcShort( 0x9 ),	/* 9 */
/* 4030 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 4032 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4036 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 4038 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4046 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ShareMode */

/* 4048 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4050 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 4052 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter Protocols */

/* 4054 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4056 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 4058 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter lFlags */

/* 4060 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4062 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 4064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCardInfo */

/* 4066 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4068 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 4070 */	NdrFcShort( 0x4de ),	/* Type Offset=1246 */

	/* Return value */

/* 4072 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4074 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 4076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  8 */	NdrFcLong( 0xc ),	/* 12 */
/* 12 */	NdrFcShort( 0x0 ),	/* 0 */
/* 14 */	NdrFcShort( 0x0 ),	/* 0 */
/* 16 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 18 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 20 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 22 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 24 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 26 */	NdrFcShort( 0x2 ),	/* Offset= 2 (28) */
/* 28 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 30 */	NdrFcLong( 0xe126f8fe ),	/* -517539586 */
/* 34 */	NdrFcShort( 0xa7af ),	/* -22609 */
/* 36 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 38 */	0xb8,		/* 184 */
			0x8a,		/* 138 */
/* 40 */	0x0,		/* 0 */
			0xc0,		/* 192 */
/* 42 */	0x4f,		/* 79 */
			0xd4,		/* 212 */
/* 44 */	0x24,		/* 36 */
			0xb9,		/* 185 */
/* 46 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 48 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 50 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 52 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 54 */	
			0x11, 0x0,	/* FC_RP */
/* 56 */	NdrFcShort( 0x2 ),	/* Offset= 2 (58) */
/* 58 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 60 */	NdrFcShort( 0x14 ),	/* 20 */
/* 62 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 64 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 66 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 68 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 70 */	NdrFcShort( 0xffffffd6 ),	/* Offset= -42 (28) */
/* 72 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 74 */	NdrFcShort( 0x2 ),	/* Offset= 2 (76) */
/* 76 */	
			0x13, 0x0,	/* FC_OP */
/* 78 */	NdrFcShort( 0x50 ),	/* Offset= 80 (158) */
/* 80 */	
			0x13, 0x0,	/* FC_OP */
/* 82 */	NdrFcShort( 0x2 ),	/* Offset= 2 (84) */
/* 84 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 86 */	NdrFcShort( 0x8 ),	/* 8 */
/* 88 */	NdrFcShort( 0x3 ),	/* 3 */
/* 90 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 94 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 96 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 100 */	NdrFcShort( 0xa ),	/* Offset= 10 (110) */
/* 102 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 106 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 108 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (107) */
/* 110 */	
			0x13, 0x0,	/* FC_OP */
/* 112 */	NdrFcShort( 0xe ),	/* Offset= 14 (126) */
/* 114 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 116 */	NdrFcShort( 0x1 ),	/* 1 */
/* 118 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 120 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 122 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 124 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 126 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 130 */	NdrFcShort( 0xfffffff0 ),	/* Offset= -16 (114) */
/* 132 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 134 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 136 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0xffffffc0 ),	/* Offset= -64 (80) */
/* 146 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 148 */	NdrFcShort( 0x1 ),	/* 1 */
/* 150 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 154 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 156 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 158 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 160 */	NdrFcShort( 0x18 ),	/* 24 */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0xa ),	/* Offset= 10 (174) */
/* 166 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 168 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (136) */
/* 170 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 172 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 174 */	
			0x13, 0x0,	/* FC_OP */
/* 176 */	NdrFcShort( 0xffffffe2 ),	/* Offset= -30 (146) */
/* 178 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 180 */	NdrFcShort( 0x3c2 ),	/* Offset= 962 (1142) */
/* 182 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 184 */	NdrFcShort( 0x2 ),	/* Offset= 2 (186) */
/* 186 */	
			0x13, 0x0,	/* FC_OP */
/* 188 */	NdrFcShort( 0x3a8 ),	/* Offset= 936 (1124) */
/* 190 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x89,		/* 137 */
/* 192 */	NdrFcShort( 0x20 ),	/* 32 */
/* 194 */	NdrFcShort( 0xa ),	/* 10 */
/* 196 */	NdrFcLong( 0x8 ),	/* 8 */
/* 200 */	NdrFcShort( 0x66 ),	/* Offset= 102 (302) */
/* 202 */	NdrFcLong( 0xd ),	/* 13 */
/* 206 */	NdrFcShort( 0x98 ),	/* Offset= 152 (358) */
/* 208 */	NdrFcLong( 0x9 ),	/* 9 */
/* 212 */	NdrFcShort( 0xca ),	/* Offset= 202 (414) */
/* 214 */	NdrFcLong( 0xc ),	/* 12 */
/* 218 */	NdrFcShort( 0x2a6 ),	/* Offset= 678 (896) */
/* 220 */	NdrFcLong( 0x24 ),	/* 36 */
/* 224 */	NdrFcShort( 0x2c6 ),	/* Offset= 710 (934) */
/* 226 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 230 */	NdrFcShort( 0x2e2 ),	/* Offset= 738 (968) */
/* 232 */	NdrFcLong( 0x10 ),	/* 16 */
/* 236 */	NdrFcShort( 0x2fc ),	/* Offset= 764 (1000) */
/* 238 */	NdrFcLong( 0x2 ),	/* 2 */
/* 242 */	NdrFcShort( 0x312 ),	/* Offset= 786 (1028) */
/* 244 */	NdrFcLong( 0x3 ),	/* 3 */
/* 248 */	NdrFcShort( 0x328 ),	/* Offset= 808 (1056) */
/* 250 */	NdrFcLong( 0x14 ),	/* 20 */
/* 254 */	NdrFcShort( 0x33e ),	/* Offset= 830 (1084) */
/* 256 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (255) */
/* 258 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 260 */	NdrFcShort( 0x2 ),	/* 2 */
/* 262 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 264 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 266 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 268 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 270 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 274 */	NdrFcShort( 0xfffffff0 ),	/* Offset= -16 (258) */
/* 276 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 278 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 280 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 284 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 290 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 294 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 296 */	
			0x13, 0x0,	/* FC_OP */
/* 298 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (270) */
/* 300 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 302 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 304 */	NdrFcShort( 0x10 ),	/* 16 */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x6 ),	/* Offset= 6 (314) */
/* 310 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 312 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 314 */	
			0x11, 0x0,	/* FC_RP */
/* 316 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (280) */
/* 318 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 330 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 332 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 334 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 336 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 346 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 350 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 352 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 354 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (318) */
/* 356 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 358 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 360 */	NdrFcShort( 0x10 ),	/* 16 */
/* 362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 364 */	NdrFcShort( 0x6 ),	/* Offset= 6 (370) */
/* 366 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 368 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 370 */	
			0x11, 0x0,	/* FC_RP */
/* 372 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (336) */
/* 374 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 376 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 386 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 388 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 390 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 392 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 396 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 400 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 402 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 406 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 408 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 410 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (374) */
/* 412 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 414 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 416 */	NdrFcShort( 0x10 ),	/* 16 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x6 ),	/* Offset= 6 (426) */
/* 422 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 424 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 426 */	
			0x11, 0x0,	/* FC_RP */
/* 428 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (392) */
/* 430 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 432 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 434 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 436 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 438 */	NdrFcShort( 0x2 ),	/* Offset= 2 (440) */
/* 440 */	NdrFcShort( 0x10 ),	/* 16 */
/* 442 */	NdrFcShort( 0x2b ),	/* 43 */
/* 444 */	NdrFcLong( 0x3 ),	/* 3 */
/* 448 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 450 */	NdrFcLong( 0x11 ),	/* 17 */
/* 454 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 456 */	NdrFcLong( 0x2 ),	/* 2 */
/* 460 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 462 */	NdrFcLong( 0x4 ),	/* 4 */
/* 466 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 468 */	NdrFcLong( 0x5 ),	/* 5 */
/* 472 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 474 */	NdrFcLong( 0xb ),	/* 11 */
/* 478 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 480 */	NdrFcLong( 0xa ),	/* 10 */
/* 484 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 486 */	NdrFcLong( 0x6 ),	/* 6 */
/* 490 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (704) */
/* 492 */	NdrFcLong( 0x7 ),	/* 7 */
/* 496 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 498 */	NdrFcLong( 0x8 ),	/* 8 */
/* 502 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (710) */
/* 504 */	NdrFcLong( 0xd ),	/* 13 */
/* 508 */	NdrFcShort( 0xffffff42 ),	/* Offset= -190 (318) */
/* 510 */	NdrFcLong( 0x9 ),	/* 9 */
/* 514 */	NdrFcShort( 0xffffff74 ),	/* Offset= -140 (374) */
/* 516 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 520 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (714) */
/* 522 */	NdrFcLong( 0x24 ),	/* 36 */
/* 526 */	NdrFcShort( 0xc4 ),	/* Offset= 196 (722) */
/* 528 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 532 */	NdrFcShort( 0xbe ),	/* Offset= 190 (722) */
/* 534 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 538 */	NdrFcShort( 0xf0 ),	/* Offset= 240 (778) */
/* 540 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 544 */	NdrFcShort( 0xee ),	/* Offset= 238 (782) */
/* 546 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 550 */	NdrFcShort( 0xec ),	/* Offset= 236 (786) */
/* 552 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 556 */	NdrFcShort( 0xea ),	/* Offset= 234 (790) */
/* 558 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 562 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (794) */
/* 564 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 568 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (782) */
/* 570 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 574 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (786) */
/* 576 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 580 */	NdrFcShort( 0xda ),	/* Offset= 218 (798) */
/* 582 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 586 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (794) */
/* 588 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 592 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (802) */
/* 594 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 598 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (806) */
/* 600 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 604 */	NdrFcShort( 0xce ),	/* Offset= 206 (810) */
/* 606 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 610 */	NdrFcShort( 0xcc ),	/* Offset= 204 (814) */
/* 612 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 616 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (826) */
/* 618 */	NdrFcLong( 0x10 ),	/* 16 */
/* 622 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 624 */	NdrFcLong( 0x12 ),	/* 18 */
/* 628 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 630 */	NdrFcLong( 0x13 ),	/* 19 */
/* 634 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 636 */	NdrFcLong( 0x16 ),	/* 22 */
/* 640 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 642 */	NdrFcLong( 0x17 ),	/* 23 */
/* 646 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 648 */	NdrFcLong( 0xe ),	/* 14 */
/* 652 */	NdrFcShort( 0xb6 ),	/* Offset= 182 (834) */
/* 654 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 658 */	NdrFcShort( 0xbc ),	/* Offset= 188 (846) */
/* 660 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 664 */	NdrFcShort( 0xba ),	/* Offset= 186 (850) */
/* 666 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 670 */	NdrFcShort( 0x70 ),	/* Offset= 112 (782) */
/* 672 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 676 */	NdrFcShort( 0x6e ),	/* Offset= 110 (786) */
/* 678 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 682 */	NdrFcShort( 0x68 ),	/* Offset= 104 (786) */
/* 684 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 688 */	NdrFcShort( 0x62 ),	/* Offset= 98 (786) */
/* 690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x0 ),	/* Offset= 0 (694) */
/* 696 */	NdrFcLong( 0x1 ),	/* 1 */
/* 700 */	NdrFcShort( 0x0 ),	/* Offset= 0 (700) */
/* 702 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (701) */
/* 704 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 706 */	NdrFcShort( 0x8 ),	/* 8 */
/* 708 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 710 */	
			0x13, 0x0,	/* FC_OP */
/* 712 */	NdrFcShort( 0xfffffe46 ),	/* Offset= -442 (270) */
/* 714 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 716 */	NdrFcShort( 0x2 ),	/* Offset= 2 (718) */
/* 718 */	
			0x13, 0x0,	/* FC_OP */
/* 720 */	NdrFcShort( 0x194 ),	/* Offset= 404 (1124) */
/* 722 */	
			0x13, 0x0,	/* FC_OP */
/* 724 */	NdrFcShort( 0x20 ),	/* Offset= 32 (756) */
/* 726 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 728 */	NdrFcLong( 0x2f ),	/* 47 */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 738 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 740 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 742 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 744 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 746 */	NdrFcShort( 0x1 ),	/* 1 */
/* 748 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 750 */	NdrFcShort( 0x4 ),	/* 4 */
/* 752 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 754 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 756 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 758 */	NdrFcShort( 0x18 ),	/* 24 */
/* 760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0xc ),	/* Offset= 12 (774) */
/* 764 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 766 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 768 */	NdrFcShort( 0xffffffd6 ),	/* Offset= -42 (726) */
/* 770 */	0x39,		/* FC_ALIGNM8 */
			0x36,		/* FC_POINTER */
/* 772 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 774 */	
			0x13, 0x0,	/* FC_OP */
/* 776 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (744) */
/* 778 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 780 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 782 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 784 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 786 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 788 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 790 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 792 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 794 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 796 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 798 */	
			0x13, 0x0,	/* FC_OP */
/* 800 */	NdrFcShort( 0xffffffa0 ),	/* Offset= -96 (704) */
/* 802 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 804 */	NdrFcShort( 0xffffffa2 ),	/* Offset= -94 (710) */
/* 806 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 808 */	NdrFcShort( 0xfffffe16 ),	/* Offset= -490 (318) */
/* 810 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 812 */	NdrFcShort( 0xfffffe4a ),	/* Offset= -438 (374) */
/* 814 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 816 */	NdrFcShort( 0x2 ),	/* Offset= 2 (818) */
/* 818 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 820 */	NdrFcShort( 0x2 ),	/* Offset= 2 (822) */
/* 822 */	
			0x13, 0x0,	/* FC_OP */
/* 824 */	NdrFcShort( 0x12c ),	/* Offset= 300 (1124) */
/* 826 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 828 */	NdrFcShort( 0x2 ),	/* Offset= 2 (830) */
/* 830 */	
			0x13, 0x0,	/* FC_OP */
/* 832 */	NdrFcShort( 0x16 ),	/* Offset= 22 (854) */
/* 834 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 836 */	NdrFcShort( 0x10 ),	/* 16 */
/* 838 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 840 */	0x1,		/* FC_BYTE */
			0x38,		/* FC_ALIGNM4 */
/* 842 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 844 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 846 */	
			0x13, 0x0,	/* FC_OP */
/* 848 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (834) */
/* 850 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 852 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 854 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 856 */	NdrFcShort( 0x20 ),	/* 32 */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x0 ),	/* Offset= 0 (860) */
/* 862 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 864 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 866 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 868 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 870 */	NdrFcShort( 0xfffffe48 ),	/* Offset= -440 (430) */
/* 872 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 874 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 878 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 884 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 888 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 890 */	
			0x13, 0x0,	/* FC_OP */
/* 892 */	NdrFcShort( 0xffffffda ),	/* Offset= -38 (854) */
/* 894 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 896 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 898 */	NdrFcShort( 0x10 ),	/* 16 */
/* 900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 902 */	NdrFcShort( 0x6 ),	/* Offset= 6 (908) */
/* 904 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 906 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 908 */	
			0x11, 0x0,	/* FC_RP */
/* 910 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (874) */
/* 912 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 916 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 920 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 922 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 926 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 928 */	
			0x13, 0x0,	/* FC_OP */
/* 930 */	NdrFcShort( 0xffffff52 ),	/* Offset= -174 (756) */
/* 932 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 934 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 936 */	NdrFcShort( 0x10 ),	/* 16 */
/* 938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 940 */	NdrFcShort( 0x6 ),	/* Offset= 6 (946) */
/* 942 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 944 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 946 */	
			0x11, 0x0,	/* FC_RP */
/* 948 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (912) */
/* 950 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 954 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 956 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 958 */	NdrFcShort( 0x10 ),	/* 16 */
/* 960 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 962 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 964 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (950) */
			0x5b,		/* FC_END */
/* 968 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 970 */	NdrFcShort( 0x20 ),	/* 32 */
/* 972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 974 */	NdrFcShort( 0xa ),	/* Offset= 10 (984) */
/* 976 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 978 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 980 */	0x0,		/* 0 */
			NdrFcShort( 0xffffffe7 ),	/* Offset= -25 (956) */
			0x5b,		/* FC_END */
/* 984 */	
			0x11, 0x0,	/* FC_RP */
/* 986 */	NdrFcShort( 0xfffffd76 ),	/* Offset= -650 (336) */
/* 988 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 990 */	NdrFcShort( 0x1 ),	/* 1 */
/* 992 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 998 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1000 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1002 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1012) */
/* 1008 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 1010 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1012 */	
			0x13, 0x0,	/* FC_OP */
/* 1014 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (988) */
/* 1016 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 1018 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1020 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1024 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1026 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 1028 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1030 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1034 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1040) */
/* 1036 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 1038 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1040 */	
			0x13, 0x0,	/* FC_OP */
/* 1042 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (1016) */
/* 1044 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1046 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1048 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1052 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1054 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1056 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1058 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1068) */
/* 1064 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 1066 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1068 */	
			0x13, 0x0,	/* FC_OP */
/* 1070 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (1044) */
/* 1072 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1074 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1076 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1082 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1084 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1086 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1096) */
/* 1092 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 1094 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1096 */	
			0x13, 0x0,	/* FC_OP */
/* 1098 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (1072) */
/* 1100 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1102 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1104 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1106 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1108 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1112 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1114 */	NdrFcShort( 0xffc8 ),	/* -56 */
/* 1116 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1118 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1120 */	NdrFcShort( 0xffffffec ),	/* Offset= -20 (1100) */
/* 1122 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1124 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1126 */	NdrFcShort( 0x38 ),	/* 56 */
/* 1128 */	NdrFcShort( 0xffffffec ),	/* Offset= -20 (1108) */
/* 1130 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1130) */
/* 1132 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1134 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 1136 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1138 */	0x4,		/* 4 */
			NdrFcShort( 0xfffffc4b ),	/* Offset= -949 (190) */
			0x5b,		/* FC_END */
/* 1142 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1144 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1146 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1150 */	NdrFcShort( 0xfffffc38 ),	/* Offset= -968 (182) */
/* 1152 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1154 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1156) */
/* 1156 */	
			0x12, 0x0,	/* FC_UP */
/* 1158 */	NdrFcShort( 0xffffffde ),	/* Offset= -34 (1124) */
/* 1160 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1162 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1168 */	NdrFcShort( 0xfffffff0 ),	/* Offset= -16 (1152) */
/* 1170 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1172 */	NdrFcShort( 0xfffffebe ),	/* Offset= -322 (850) */
/* 1174 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1176 */	NdrFcShort( 0xfffffe28 ),	/* Offset= -472 (704) */
/* 1178 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1180 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1182 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1184 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1186 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1188 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1190 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1192 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 1194 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1196 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1198) */
/* 1198 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1200 */	NdrFcLong( 0xd5778ae3 ),	/* -713585949 */
/* 1204 */	NdrFcShort( 0x43de ),	/* 17374 */
/* 1206 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 1208 */	0x91,		/* 145 */
			0x71,		/* 113 */
/* 1210 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 1212 */	0x0,		/* 0 */
			0xc1,		/* 193 */
/* 1214 */	0x80,		/* 128 */
			0x68,		/* 104 */
/* 1216 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1218 */	0xb9,		/* FC_UINT3264 */
			0x5c,		/* FC_PAD */
/* 1220 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1222 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 1224 */	
			0x12, 0x0,	/* FC_UP */
/* 1226 */	NdrFcShort( 0xfffffc44 ),	/* Offset= -956 (270) */
/* 1228 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1230 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1232 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (1224) */
/* 1238 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1240 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1242) */
/* 1242 */	
			0x13, 0x0,	/* FC_OP */
/* 1244 */	NdrFcShort( 0xfffffee0 ),	/* Offset= -288 (956) */
/* 1246 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1248 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1250) */
/* 1250 */	
			0x13, 0x0,	/* FC_OP */
/* 1252 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1254) */
/* 1254 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1256 */	NdrFcShort( 0x38 ),	/* 56 */
/* 1258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1260 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1260) */
/* 1262 */	0xb9,		/* FC_UINT3264 */
			0xb9,		/* FC_UINT3264 */
/* 1264 */	0xe,		/* FC_ENUM32 */
			0xe,		/* FC_ENUM32 */
/* 1266 */	0x39,		/* FC_ALIGNM8 */
			0xb8,		/* FC_INT3264 */
/* 1268 */	0xb8,		/* FC_INT3264 */
			0xb8,		/* FC_INT3264 */
/* 1270 */	0xb8,		/* FC_INT3264 */
			0x5b,		/* FC_END */

			0x0
        }
    };

const CInterfaceProxyVtbl * _scardssp_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ISCardTypeConvProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISCardISO7816ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISCardProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISCardDatabaseProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISCardLocateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISCardCmdProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IByteBufferProxyVtbl,
    0
};

const CInterfaceStubVtbl * _scardssp_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ISCardTypeConvStubVtbl,
    ( CInterfaceStubVtbl *) &_ISCardISO7816StubVtbl,
    ( CInterfaceStubVtbl *) &_ISCardStubVtbl,
    ( CInterfaceStubVtbl *) &_ISCardDatabaseStubVtbl,
    ( CInterfaceStubVtbl *) &_ISCardLocateStubVtbl,
    ( CInterfaceStubVtbl *) &_ISCardCmdStubVtbl,
    ( CInterfaceStubVtbl *) &_IByteBufferStubVtbl,
    0
};

PCInterfaceName const _scardssp_InterfaceNamesList[] = 
{
    "ISCardTypeConv",
    "ISCardISO7816",
    "ISCard",
    "ISCardDatabase",
    "ISCardLocate",
    "ISCardCmd",
    "IByteBuffer",
    0
};

const IID *  _scardssp_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _scardssp_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _scardssp, pIID, n)

int __stdcall _scardssp_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _scardssp, 7, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _scardssp, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _scardssp, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _scardssp, 7, *pIndex )
    
}

const ExtendedProxyFileInfo scardssp_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _scardssp_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _scardssp_StubVtblList,
    (const PCInterfaceName * ) & _scardssp_InterfaceNamesList,
    (const IID ** ) & _scardssp_BaseIIDList,
    & _scardssp_IID_Lookup, 
    7,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};


#endif /* defined(_M_IA64) || defined(_M_AXP64)*/

