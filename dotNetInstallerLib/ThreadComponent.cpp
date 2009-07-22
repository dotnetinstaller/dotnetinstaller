#include "StdAfx.h"
#include "ThreadComponent.h"
#include "InstallConfiguration.h"

ThreadComponent::ThreadComponent(component_type t)
	: Component(t)
	, m_pThread(NULL)
	, m_rc(0)
{

}

ThreadComponent::~ThreadComponent()
{
}

bool ThreadComponent::IsExecuting() const
{
    if (get(m_pThread) == NULL)
        return false;

    return (WAIT_TIMEOUT == WaitForSingleObject(m_pThread->m_hThread, 0));
}

UINT ThreadComponent::ExecuteThread(LPVOID pParam)
{
	ThreadComponent * pComponent = (ThreadComponent *) pParam;
	
	try
	{
		pComponent->m_rc = pComponent->ExecOnThread();
	}
	catch(std::exception& ex)
	{
		pComponent->m_error = DVLib::string2wstring(ex.what());
		pComponent->m_rc = -1;
	}

	return 0;
}

void ThreadComponent::Exec()
{
	BeginExec();
	EndExec();
}

void ThreadComponent::BeginExec()
{
    m_pThread = ThreadPtr(AfxBeginThread(ExecuteThread, this, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED));

	CHECK_WIN32_BOOL(get(m_pThread) != NULL,
		L"AfxBeginThread");

	m_pThread->m_bAutoDelete = false;
    m_pThread->ResumeThread();
}

void ThreadComponent::EndExec()
{
	if (! get(m_pThread))
		return;

	if (m_pThread->m_hThread != NULL)
	{
		CHECK_WIN32_BOOL(WAIT_FAILED != WaitForSingleObject(m_pThread->m_hThread, INFINITE),
			L"WaitForSingleObject");
	}

	reset(m_pThread);

	CHECK_BOOL(m_error.empty(), m_error);
	CHECK_BOOL(m_rc == 0, L"Component failed with error code: " << m_rc);
}
