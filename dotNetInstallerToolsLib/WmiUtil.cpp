#include "stdafx.h"
#include "WmiUtil.h"
#include "ComInitializer.h"
#include "StringUtil.h"
#include "ErrorUtil.h"
#include "ExceptionMacros.h"
#include <comdef.h>
#include <Wbemidl.h>
#pragma comment(lib, "wbemuuid.lib")

bool DVLib::WmiUtil::Any(const std::wstring& query)
{
    CComPtr<IWbemClassObject> pclsObj = nullptr;
    ULONG uReturn = FirstOrNull(query, pclsObj.p);

    return (uReturn > 0);
}

std::wstring DVLib::WmiUtil::Get(const std::wstring& query, const std::wstring& propertyName)
{
    CComPtr<IWbemClassObject> pclsObj = nullptr;
    ULONG uReturn = FirstOrNull(query, pclsObj.p);
    if (uReturn == 0)
    {
        // no entries found
        return L"";
    }

    _variant_t vtProp;

    // get the value of the specified property
    CHECK_HR(pclsObj->Get(propertyName.c_str(), 0, &vtProp, 0, 0),
        L"Error getting value for property '" << propertyName << L"'");

    return vtProp.bstrVal;
}

ULONG DVLib::WmiUtil::FirstOrNull(const std::wstring& query, IWbemClassObject*& pclsObj)
{
    // initialize COM
    ComInitializer comInitializer;

    // create an instance of the COM object
    CComPtr<IWbemLocator> pLocator = nullptr;

    CHECK_HR(::CoCreateInstance(
        CLSID_WbemLocator,          // Class identifier
        0,                        // IUnknown
        CLSCTX_INPROC_SERVER,   // Context
        IID_IWbemLocator,             // Interface identifier
        (LPVOID*)&pLocator),           // Pointer to created interface
        L"Failed to create IWbemLocator object.");

    // connect to the WMI namespace
    CComPtr<IWbemServices> pServices = nullptr;

    CHECK_HR(pLocator->ConnectServer(
        _bstr_t(L"ROOT\\CIMV2"),  // WMI namespace
        NULL,                                    // User name
        NULL,                                    // Password
        0,                                       // Locale
        NULL,                                    // Security flags
        0,                                       // Authority
        0,                                       // Context
        &pServices),                             // IWbemServices proxy
        L"Failed to connect to WMI namespace.");

    // set security levels on the proxy
    CHECK_HR(::CoSetProxyBlanket(
        pServices,             // IWbemServices proxy
        RPC_C_AUTHN_WINNT,           // Authentication service
        RPC_C_AUTHZ_NONE,            // Authorization service
        NULL,                        // Server principal name
        RPC_C_AUTHN_LEVEL_CALL,      // Authentication level
        RPC_C_IMP_LEVEL_IMPERSONATE, // Impersonation level
        NULL,                        // Authentication info
        EOAC_NONE),                  // Additional capabilities
        L"Failed to set proxy blanket.");

    // execute the query
    CComPtr<IEnumWbemClassObject> pEnumerator = nullptr;

    CHECK_HR(pServices->ExecQuery(
        bstr_t("WQL"),                                  // Query language
        bstr_t(query.c_str()),                                // Query
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, // Flags
        NULL,                                                        // Context
        &pEnumerator),                                               // Enumerator
        L"Failed to execute the WMI query.");
    if (pEnumerator == nullptr)
    {
        throw std::exception("Failed to enumerate WMI query results.");
    }

    // get the first object, if any
    ULONG uReturn = 0;

    CHECK_HR(pEnumerator->Next(
        WBEM_INFINITE, // Timeout
        1,              // Count of objects to return
        &pclsObj,     // Objects
        &uReturn),   // Count of returned objects
        L"Failed to get the WMI class object.");

    return uReturn;
}