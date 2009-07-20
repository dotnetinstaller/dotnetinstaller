#include "StdAfx.h"
#include "ThreadComponent.h"
#include "InstallConfiguration.h"

ThreadComponent::ThreadComponent(component_type t)
	: Component(t)
	, m_exitcode(0)
	, m_pThread(NULL)
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
	BeginExec();
	EndExec();
}

void ThreadComponent::BeginExec()
{
    m_pThread = auto_any<CWinThread *, close_delete>(AfxBeginThread(ExecuteThread, this, 0, 0, CREATE_SUSPENDED));

	CHECK_WIN32_BOOL(get(m_pThread) != NULL,
		L"AfxBeginThread");

	m_pThread->m_bAutoDelete = false;
    m_pThread->ResumeThread();
}

void ThreadComponent::EndExec()
{
    CHECK_WIN32_BOOL(WAIT_FAILED != WaitForSingleObject(m_pThread->m_hThread, INFINITE),
		L"WaitForSingleObject");

	reset(m_pThread);

	CHECK_BOOL(m_error.empty(), m_error);
	CHECK_BOOL(m_exitcode == 0, L"Unexpected error code " << m_exitcode);
}
