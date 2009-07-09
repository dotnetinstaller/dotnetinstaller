#include "StdAfx.h"
#include "ThreadComponent.h"

ThreadComponent::ThreadComponent()
	: m_exitcode(0)
	, m_pThread(NULL)
{

}

ThreadComponent::~ThreadComponent()
{
	if (m_pThread != NULL) 
	{
		delete m_pThread;
	}
}

bool ThreadComponent::IsExecuting() const
{
    if (m_pThread == NULL)
        return false;

    return (WAIT_TIMEOUT == WaitForSingleObject(m_pThread->m_hThread, 0));
}

UINT ThreadComponent::ExecuteThread(LPVOID pParam)
{
	ThreadComponent * pComponent = (ThreadComponent *) pParam;
	try
	{
		pComponent->m_exitcode = pComponent->ExecOnThread();
	}
	catch(std::exception& ex)
	{
		pComponent->m_error = DVLib::string2wstring(ex.what());
		pComponent->m_exitcode = -1;
	}
	catch(...)
	{
        pComponent->m_error = L"Failed to execute threaded component";
		pComponent->m_exitcode = -1;
	}
	
	return pComponent->m_exitcode;
}

void ThreadComponent::Exec()
{
    m_pThread = AfxBeginThread(ExecuteThread, this, 0, 0, CREATE_SUSPENDED);

	CHECK_WIN32_BOOL(m_pThread != NULL,
		L"AfxBeginThread");

	m_pThread->m_bAutoDelete = false;
    m_pThread->ResumeThread();

    CHECK_WIN32_BOOL(WAIT_FAILED != WaitForSingleObject(m_pThread->m_hThread, INFINITE),
		L"WaitForSingleObject");

	delete m_pThread;
	m_pThread = NULL;

	CHECK_BOOL(m_error.empty(), m_error);
	CHECK_BOOL(m_exitcode == 0, L"Unexpected error code " << m_exitcode);
}
