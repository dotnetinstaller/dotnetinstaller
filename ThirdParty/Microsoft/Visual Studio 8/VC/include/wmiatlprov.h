// This is a part of the Active Template Library.
// Copyright (C) 1996-2000 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __ATLWMIPROV_H__
#define __ATLWMIPROV_H__

#pragma once

#ifndef __cplusplus
    #error requires C++ compilation (use a .cpp suffix)
#endif

#ifndef __wbemprov_h__
    #include <wbemprov.h>
#endif

#ifndef __wmiutils_h__
    #include <wmiutils.h>
#endif

namespace ATL
{

class ATL_NO_VTABLE IWbemInstProviderImpl : public IWbemServices,
                                            public IWbemProviderInit
    
{
public:

    //IWbemServices  

    HRESULT STDMETHODCALLTYPE OpenNamespace( 
        /* [in] */ const BSTR Namespace,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemServices __RPC_FAR *__RPC_FAR *ppWorkingNamespace,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppResult) {return WBEM_E_NOT_SUPPORTED;};
    
/*?*/HRESULT STDMETHODCALLTYPE CancelAsyncCall( 
        /* [in] */ IWbemObjectSink __RPC_FAR *pSink) {return WBEM_E_NOT_SUPPORTED;};
        
/*?*/HRESULT STDMETHODCALLTYPE QueryObjectSink( 
        /* [in] */ long lFlags,
        /* [out] */ IWbemObjectSink __RPC_FAR *__RPC_FAR *ppResponseHandler) {return WBEM_E_NOT_SUPPORTED;};
    
    HRESULT STDMETHODCALLTYPE GetObject( 
        /* [in] */ const BSTR ObjectPath,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemClassObject __RPC_FAR *__RPC_FAR *ppObject,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult) {return WBEM_E_NOT_SUPPORTED;};
    
    
    HRESULT STDMETHODCALLTYPE PutClass( 
        /* [in] */ IWbemClassObject __RPC_FAR *pObject,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult) {return WBEM_E_NOT_SUPPORTED;};
    
    HRESULT STDMETHODCALLTYPE PutClassAsync( 
        /* [in] */ IWbemClassObject __RPC_FAR *pObject,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler) {return WBEM_E_NOT_SUPPORTED;};
    
    HRESULT STDMETHODCALLTYPE DeleteClass( 
        /* [in] */ const BSTR Class,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult) {return WBEM_E_NOT_SUPPORTED;};
    
    HRESULT STDMETHODCALLTYPE DeleteClassAsync( 
        /* [in] */ const BSTR Class,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler) {return WBEM_E_NOT_SUPPORTED;};
    
    HRESULT STDMETHODCALLTYPE CreateClassEnum( 
        /* [in] */ const BSTR Superclass,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [out] */ IEnumWbemClassObject __RPC_FAR *__RPC_FAR *ppEnum) {return WBEM_E_NOT_SUPPORTED;};
    
    HRESULT STDMETHODCALLTYPE CreateClassEnumAsync( 
        /* [in] */ const BSTR Superclass,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler) {return WBEM_E_NOT_SUPPORTED;};
    
    HRESULT STDMETHODCALLTYPE PutInstance( 
        /* [in] */ IWbemClassObject __RPC_FAR *pInst,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult) {return WBEM_E_NOT_SUPPORTED;};
    
    
    HRESULT STDMETHODCALLTYPE DeleteInstance( 
        /* [in] */ const BSTR ObjectPath,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult) {return WBEM_E_NOT_SUPPORTED;};
    
    
    HRESULT STDMETHODCALLTYPE CreateInstanceEnum( 
        /* [in] */ const BSTR Class,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [out] */ IEnumWbemClassObject __RPC_FAR *__RPC_FAR *ppEnum) {return WBEM_E_NOT_SUPPORTED;};
    
    
    HRESULT STDMETHODCALLTYPE ExecQuery( 
        /* [in] */ const BSTR QueryLanguage,
        /* [in] */ const BSTR Query,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [out] */ IEnumWbemClassObject __RPC_FAR *__RPC_FAR *ppEnum) {return WBEM_E_NOT_SUPPORTED;};
    
    HRESULT STDMETHODCALLTYPE ExecNotificationQuery( 
        /* [in] */ const BSTR QueryLanguage,
        /* [in] */ const BSTR Query,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [out] */ IEnumWbemClassObject __RPC_FAR *__RPC_FAR *ppEnum) {return WBEM_E_NOT_SUPPORTED;};
    
    HRESULT STDMETHODCALLTYPE ExecNotificationQueryAsync( 
        /* [in] */ const BSTR QueryLanguage,
        /* [in] */ const BSTR Query,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler) {return WBEM_E_NOT_SUPPORTED;};
    
    HRESULT STDMETHODCALLTYPE ExecMethod( 
        /* [in] */ const BSTR strObjectPath,
        /* [in] */ const BSTR strMethodName,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemClassObject __RPC_FAR *pInParams,
        /* [unique][in][out] */ IWbemClassObject __RPC_FAR *__RPC_FAR *ppOutParams,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult) {return WBEM_E_NOT_SUPPORTED;};
    
    HRESULT STDMETHODCALLTYPE ExecMethodAsync( 
        /* [in] */ const BSTR strObjectPath,
        /* [in] */ const BSTR strMethodName,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemClassObject __RPC_FAR *pInParams,
        /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler) {return WBEM_E_NOT_SUPPORTED;};

};


class CProviderHelper
{   
private:
    CComPtr<IWbemClassObject> m_pErrorObject;
    HRESULT m_hr; // store the construction status here

public:
    //Construction:
    CProviderHelper(IWbemServices * pNamespace, IWbemContext *pCtx)
    {
        m_hr = WBEM_E_FAILED; // assume the worst to start
        m_pErrorObject == NULL;
        if (NULL == pNamespace)
        {
            m_hr = WBEM_E_INVALID_PARAMETER; 
            ATLASSERT (0);
            return;
        }
        BSTR bstrString = SysAllocString(L"__ExtendedStatus");
        if (NULL == bstrString)
        {
            m_hr = WBEM_E_OUT_OF_MEMORY;
            return;
        }
        m_hr = pNamespace->GetObject(bstrString, 
                                     0, 
                                     pCtx, 
                                     &m_pErrorObject, 
                                     NULL);
        SysFreeString(bstrString);
        return;
    }

    virtual ~CProviderHelper()
    {
    }   

    HRESULT STDMETHODCALLTYPE ConstructErrorObject (
                                                    /*in*/const ULONG ulStatusCode,
                                                    /*in*/const BSTR bstrDescription,
                                                    /*in*/const BSTR bstrOperation,
                                                    /*in*/const BSTR bstrParameter,
                                                    /*in*/const BSTR bstrProviderName,
                                                    /*out*/IWbemClassObject ** ppErrorObject)
    {

        static const LPWSTR lpwstrDescription = L"Description";
        static const LPWSTR lpwstrOperation = L"Operation";
        static const LPWSTR lpwstrStatusCode = L"StatusCode";
        static const LPWSTR lpwstrParameterInfo = L"ParameterInfo";
        static const LPWSTR lpwstrProviderName = L"ProviderName";

        if (FAILED (m_hr))
        {
            // constructor failed
            ATLASSERT (0);
            return m_hr;
        }

        if (NULL == ppErrorObject)
        {
            ATLASSERT (0);
            return WBEM_E_INVALID_PARAMETER;
        }

        HRESULT hr = m_pErrorObject->SpawnInstance(0, ppErrorObject);
        if(FAILED(hr))
        {
            return hr;
        }

        VARIANT var;
        VariantInit(&var);
        var.vt = VT_I4;
        var.lVal = ulStatusCode;

        hr = (*ppErrorObject)->Put(lpwstrStatusCode, 0, &var, 0);
        if (FAILED(hr))
        {
            return hr;
        }

        var.vt = VT_BSTR;

        if (bstrDescription != NULL)
        {               
            var.bstrVal = bstrDescription;
            hr = (*ppErrorObject)->Put(lpwstrDescription, 0, &var, 0);
            if (FAILED(hr))
            {
                return hr;
            }
        }
        
        if (bstrOperation != NULL)
        {
            var.bstrVal = bstrOperation;
            hr = (*ppErrorObject)->Put(lpwstrOperation, 0, &var, 0);
            if (FAILED(hr))
            {
                return hr;
            }
        }

        if (bstrParameter != NULL)
        {
            var.bstrVal = bstrParameter;
            hr = (*ppErrorObject)->Put(lpwstrParameterInfo, 0, &var, 0);
            if (FAILED(hr))
            {
                return hr;
            }
        }

        if (bstrProviderName != NULL)
        {
            var.bstrVal = bstrProviderName;
            hr = (*ppErrorObject)->Put(lpwstrProviderName, 0, &var, 0);
            if (FAILED(hr))
            {
                return hr;
            }
        }
            
        return hr;
    }
};

class CIntrinsicEventProviderHelper : public CProviderHelper
{
private:
    CComPtr<IWbemClassObject> m_pCreationEventClass;
    CComPtr<IWbemClassObject> m_pDeletionEventClass;
    CComPtr<IWbemClassObject> m_pModificationEventClass;
    HRESULT m_hr;

public:

    //Construction
    CIntrinsicEventProviderHelper( IWbemServices * pNamespace, IWbemContext * pCtx)
                : CProviderHelper ( pNamespace, pCtx)
    {
        m_hr = WBEM_E_FAILED; // assume the worst

        if (NULL == pNamespace || NULL == pCtx)
        {
            m_hr = WBEM_E_INVALID_PARAMETER;
            ATLASSERT (0);
            return;
        }

        m_pCreationEventClass = NULL;
        m_pModificationEventClass = NULL; 
        m_pDeletionEventClass = NULL;

        BSTR bstrString = SysAllocString(L"__InstanceCreationEvent");
        if (NULL == bstrString)
        {
            m_hr = WBEM_E_OUT_OF_MEMORY;
            return;
        }

        m_hr = pNamespace->GetObject(bstrString, 
                                     0, 
                                     pCtx, 
                                     &m_pCreationEventClass, 
                                     NULL);
        SysFreeString(bstrString);
        bstrString=NULL;
        if (FAILED(m_hr)) 
        {
            return;
        }

        bstrString = SysAllocString(L"__InstanceModificationEvent");
        if (NULL == bstrString)
        {
            m_hr = WBEM_E_OUT_OF_MEMORY;
            return;
        }
        m_hr = pNamespace->GetObject(bstrString, 
                                     0, 
                                     pCtx, //passing IWbemContext pointer to prevent deadlocks
                                     &m_pModificationEventClass, 
                                     NULL);
        SysFreeString(bstrString);
        bstrString=NULL;
        if (FAILED(m_hr)) 
        {
            return;
        }
        
        bstrString = SysAllocString(L"__InstanceDeletionEvent");
        if (NULL == bstrString)
        {
            m_hr = WBEM_E_OUT_OF_MEMORY;
            return;
        }
        m_hr = pNamespace->GetObject(bstrString, 
                                     0, 
                                     pCtx, //passing IWbemContext pointer to prevent deadlocks
                                     &m_pDeletionEventClass, 
                                     NULL);
        SysFreeString(bstrString);
        bstrString=NULL;           
        if (FAILED(m_hr)) 
        {
            return;
        }

        return;
    }

    virtual ~CIntrinsicEventProviderHelper()
    {
    }

    HRESULT STDMETHODCALLTYPE FireCreationEvent(
                                                /*in*/IWbemClassObject * pNewInstance,
                                                /*in*/IWbemObjectSink * pSink )
    {
        if (FAILED(m_hr))
        {
            // construction failed
            ATLASSERT (0);      
            return m_hr;
        }

        if (pNewInstance == NULL || pSink == NULL)
        {
            ATLASSERT (0);      
            return WBEM_E_INVALID_PARAMETER;
        }
        
        CComPtr<IWbemClassObject> pEvtInstance;
        HRESULT hr = m_pCreationEventClass->SpawnInstance(0, &pEvtInstance);
        if(FAILED(hr))
        {
            return hr;
        }
        
        VARIANT var;
        VariantInit(&var);
        var.vt = VT_UNKNOWN; 
        CComQIPtr<IUnknown, &IID_IUnknown>pTemp(pNewInstance);
        var.punkVal = pTemp;
        hr = pEvtInstance->Put(L"TargetInstance", 0, &var, 0);
        if(FAILED(hr))
        {
            return hr;
        }

        IWbemClassObject *_pEvtInstance = (IWbemClassObject*)pEvtInstance;
        return pSink->Indicate(1, &_pEvtInstance);
    }


    HRESULT STDMETHODCALLTYPE FireDeletionEvent(
                                    /*in*/IWbemClassObject * pInstanceToDelete,
                                    /*in*/IWbemObjectSink * pSink )
    {
        if (FAILED (m_hr))
        {
            // construction failed
            ATLASSERT (0);      
            return m_hr;
        }

        if (pInstanceToDelete == NULL || pSink == NULL)
        {
            ATLASSERT (0);      
            return WBEM_E_INVALID_PARAMETER;
        }

        CComPtr<IWbemClassObject> pEvtInstance;
        HRESULT hr = m_pDeletionEventClass->SpawnInstance(0, &pEvtInstance);
        if(FAILED(hr))
        {
            return hr;
        }

        VARIANT var;
        VariantInit(&var);
        var.vt = VT_UNKNOWN; 
        CComQIPtr<IUnknown, &IID_IUnknown>pTemp(pInstanceToDelete);
        var.punkVal = pTemp;
        hr = pEvtInstance->Put(L"TargetInstance", 0, &var, 0);
        if(FAILED(hr))
        {
            return hr;
        }

        IWbemClassObject *_pEvtInstance = (IWbemClassObject*)pEvtInstance;
        return pSink->Indicate(1, &_pEvtInstance);
    }


    HRESULT STDMETHODCALLTYPE FireModificationEvent(
                                                    /*in*/IWbemClassObject * pOldInstance,
                                                    /*in*/IWbemClassObject * pNewInstance,
                                                    /*in*/IWbemObjectSink * pSink )
    {
        if (FAILED (m_hr))
        {
            // construction failed
            ATLASSERT (0);      
            return m_hr;
        }

        if (pOldInstance == NULL || pNewInstance == NULL || pSink == NULL)
        {
            ATLASSERT (0);      
            return WBEM_E_INVALID_PARAMETER;
        }
                
        CComPtr<IWbemClassObject> pEvtInstance;
        HRESULT hr = m_pModificationEventClass->SpawnInstance(0, &pEvtInstance);
        if(FAILED(hr))
        {
            return hr;
        }

        VARIANT var;
        VariantInit(&var);
        var.vt = VT_UNKNOWN; 
        CComQIPtr<IUnknown, &IID_IUnknown>pTempNew(pNewInstance);
        var.punkVal = pTempNew;
        hr = pEvtInstance->Put(L"TargetInstance", 0, &var, 0);
        if (FAILED(hr)) 
        {       
            return hr;
        }
        
        CComQIPtr<IUnknown, &IID_IUnknown>pTempOld(pOldInstance);
        var.punkVal = pTempOld;
        hr = pEvtInstance->Put(L"PreviousInstance", 0, &var, 0);
        if (FAILED(hr)) 
        {       
            return hr;
        }
        
        IWbemClassObject *_pEvtInstance = (IWbemClassObject*)pEvtInstance;
        return pSink->Indicate(1, &_pEvtInstance);
    }

};

class CInstanceProviderHelper : public CProviderHelper
{

public:

    CInstanceProviderHelper (IWbemServices * pNamespace, IWbemContext *pCtx)
                : CProviderHelper ( pNamespace, pCtx)
    {
    }

    virtual ~CInstanceProviderHelper()
    {
    }
    
    HRESULT STDMETHODCALLTYPE CheckInstancePath (
                                /*[in]*/ IClassFactory * pParserFactory,    //pointer to path parser class factory
                                /*[in]*/ const BSTR ObjectPath, //object path string
                                /*[in]*/ const BSTR ClassName,  //name of WMI class whose instances are provided
                                /*[in]*/ ULONGLONG ullTest)          //flags from WMI_PATH_STATUS_FLAG (defined in wmiutils.h)
    {   

        if (pParserFactory == NULL)
        {
            ATLASSERT (0);      
            return WBEM_E_INVALID_PARAMETER;
        }
        
        //Create path parser object
        CComPtr<IWbemPath>pPath;
        HRESULT hr = pParserFactory->CreateInstance(NULL,
                                            IID_IWbemPath,
                                            (void **) &pPath);
        if (FAILED(hr))
        {
            return WBEM_E_INVALID_PARAMETER;
        }

        hr = pPath->SetText(WBEMPATH_CREATE_ACCEPT_ALL,
                                    ObjectPath);
        if(FAILED(hr))
        {
            return hr;
        }

        //check that the class requested is the class provided
        unsigned int nPathLen = SysStringLen(ObjectPath);  // assume this is a real BSTR not just WCHAR*
        if (nPathLen >= (unsigned long)(-1)) return HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW);
        
        unsigned long ulBufLen = (unsigned long)(nPathLen + 1);
        WCHAR * wClass = new WCHAR[ulBufLen];
        if (NULL == wClass)
        {
            return WBEM_E_OUT_OF_MEMORY;
        }
        hr = pPath->GetClassName(&ulBufLen, wClass);
        if(FAILED(hr))
        {
            delete[] wClass;
            return hr;
        }
        DWORD lcid = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT);
        if (CSTR_EQUAL != CompareStringW(lcid, NORM_IGNORECASE, ClassName, -1, wClass, -1))
        {
            delete[] wClass;
            return WBEM_E_NOT_FOUND;
        }
        
        delete[] wClass;
        
        //check that the path reflects the object type
        unsigned __int64 ullPathInfo;
        hr = pPath->GetInfo(0L, &ullPathInfo);
        if(FAILED(hr))
        {
            return hr;
        }

        if (!(ullPathInfo & ullTest))
        {
            return WBEM_E_INVALID_OBJECT_PATH;
        }   
        
        return WBEM_S_NO_ERROR;     
    }

};


//IWbemPullClassProviderImpl class 

template <class T>
class ATL_NO_VTABLE IWbemPullClassProviderImpl : public IWbemServices,
                                                 public IWbemProviderInit
{
public:


    //IWbemServices  

    virtual HRESULT STDMETHODCALLTYPE OpenNamespace( 
        /* [in] */ const BSTR strNamespace,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemServices __RPC_FAR *__RPC_FAR *ppWorkingNamespace,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppResult){return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE CancelAsyncCall( 
        /* [in] */ IWbemObjectSink __RPC_FAR *pSink){return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE QueryObjectSink( 
        /* [in] */ long lFlags,
        /* [out] */ IWbemObjectSink __RPC_FAR *__RPC_FAR *ppResponseHandler) {return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE GetObject( 
        /* [in] */ const BSTR strObjectPath,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemClassObject __RPC_FAR *__RPC_FAR *ppObject,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult) {return WBEM_E_NOT_SUPPORTED;};
    
    
    virtual HRESULT STDMETHODCALLTYPE PutClass( 
        /* [in] */ IWbemClassObject __RPC_FAR *pObject,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult){return WBEM_E_NOT_SUPPORTED;};
    
    
    virtual HRESULT STDMETHODCALLTYPE DeleteClass( 
        /* [in] */ const BSTR strClass,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult){return WBEM_E_NOT_SUPPORTED;};
    
    
    virtual HRESULT STDMETHODCALLTYPE CreateClassEnum( 
        /* [in] */ const BSTR strSuperclass,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [out] */ IEnumWbemClassObject __RPC_FAR *__RPC_FAR *ppEnum) {return WBEM_E_NOT_SUPPORTED;};
    
    
    virtual HRESULT STDMETHODCALLTYPE PutInstance( 
        /* [in] */ IWbemClassObject __RPC_FAR *pInst,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult){return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE PutInstanceAsync( 
        /* [in] */ IWbemClassObject __RPC_FAR *pInst,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler) {return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE DeleteInstance( 
        /* [in] */ const BSTR strObjectPath,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult){return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE DeleteInstanceAsync( 
        /* [in] */ const BSTR strObjectPath,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler){return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE CreateInstanceEnum( 
        /* [in] */ const BSTR strClass,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [out] */ IEnumWbemClassObject __RPC_FAR *__RPC_FAR *ppEnum) {return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE CreateInstanceEnumAsync( 
        /* [in] */ const BSTR strClass,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler) {return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE ExecQuery( 
        /* [in] */ const BSTR strQueryLanguage,
        /* [in] */ const BSTR strQuery,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [out] */ IEnumWbemClassObject __RPC_FAR *__RPC_FAR *ppEnum) {return WBEM_E_NOT_SUPPORTED;};
    
    
    virtual HRESULT STDMETHODCALLTYPE ExecNotificationQuery( 
        /* [in] */ const BSTR strQueryLanguage,
        /* [in] */ const BSTR strQuery,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [out] */ IEnumWbemClassObject __RPC_FAR *__RPC_FAR *ppEnum) {return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE ExecNotificationQueryAsync( 
        /* [in] */ const BSTR strQueryLanguage,
        /* [in] */ const BSTR strQuery,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler) {return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE ExecMethod( 
        /* [in] */ const BSTR strObjectPath,
        /* [in] */ const BSTR strMethodName,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemClassObject __RPC_FAR *pInParams,
        /* [unique][in][out] */ IWbemClassObject __RPC_FAR *__RPC_FAR *ppOutParams,
        /* [unique][in][out] */ IWbemCallResult __RPC_FAR *__RPC_FAR *ppCallResult) {return WBEM_E_NOT_SUPPORTED;};
    
    virtual HRESULT STDMETHODCALLTYPE ExecMethodAsync( 
        /* [in] */ const BSTR strObjectPath,
        /* [in] */ const BSTR strMethodName,
        /* [in] */ long lFlags,
        /* [in] */ IWbemContext __RPC_FAR *pCtx,
        /* [in] */ IWbemClassObject __RPC_FAR *pInParams,
        /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler) {return WBEM_E_NOT_SUPPORTED;};
    

};

class CImpersonateClientHelper
{
    private:
        BOOL m_bImpersonate;    
    public:
        CImpersonateClientHelper()
        { 
            m_bImpersonate = FALSE;
        }

        ~CImpersonateClientHelper()
        {
            if(m_bImpersonate)
                CoRevertToSelf();
        }

        HRESULT ImpersonateClient()
        {
            HRESULT hr = S_OK;
            if(SUCCEEDED(hr = CoImpersonateClient()))
            {
                m_bImpersonate = TRUE;
            }
            return hr;
        }

        HRESULT GetCurrentImpersonationLevel ( DWORD & a_Level )
        {
            DWORD t_ImpersonationLevel = RPC_C_IMP_LEVEL_ANONYMOUS ;
            HANDLE t_ThreadToken = NULL ;
            
            HRESULT t_Result = S_OK ;
            if(SUCCEEDED(t_Result = CoImpersonateClient()))
            {
                BOOL t_Status = OpenThreadToken (GetCurrentThread() ,TOKEN_QUERY,TRUE,&t_ThreadToken);
                if ( t_Status )
                {
                    SECURITY_IMPERSONATION_LEVEL t_Level = SecurityAnonymous ;
                    DWORD t_Returned = 0 ;
         
                    t_Status = GetTokenInformation (t_ThreadToken ,TokenImpersonationLevel ,&t_Level ,sizeof(SECURITY_IMPERSONATION_LEVEL),&t_Returned);
                    CloseHandle ( t_ThreadToken ) ;

                    if ( t_Status == FALSE )
                    {
                        t_Result = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,GetLastError());
                    }
                    else
                    {
                        switch ( t_Level )
                        {
                            case SecurityAnonymous:
                            {
                                t_ImpersonationLevel = RPC_C_IMP_LEVEL_ANONYMOUS ;
                            }
                            break ;

                            case SecurityIdentification:
                            {
                                t_ImpersonationLevel = RPC_C_IMP_LEVEL_IDENTIFY ;
                            }
                            break ;

                            case SecurityImpersonation:
                            {
                                t_ImpersonationLevel = RPC_C_IMP_LEVEL_IMPERSONATE ;
                            }
                            break ;

                            case SecurityDelegation:
                            {
                                t_ImpersonationLevel = RPC_C_IMP_LEVEL_DELEGATE ;
                            }
                            break ;

                            default:
                            {
                                t_Result = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,E_UNEXPECTED);
                            }
                            break ;
                        }
                    }
                }
                else
                {
                    t_Result = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,GetLastError());
                }

                CoRevertToSelf();
            }

            a_Level = t_ImpersonationLevel ;
            return t_Result ; 
        }

    };
}       //namespace ATL

#endif  //__ATLWMIPROV_H__
