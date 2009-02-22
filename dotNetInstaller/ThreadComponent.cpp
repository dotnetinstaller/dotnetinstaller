#include "StdAfx.h"
#include "ThreadComponent.h"

thread_component::thread_component()
{
}

DWORD thread_component::GetExitCode()
{
    return m_ExitCode;
}

bool thread_component::IsExecuting()
{
    if (m_pThread == NULL)
        return false;

    return (WAIT_TIMEOUT == WaitForSingleObject(m_pThread->m_hThread, 0));
}

UINT thread_component::ExecuteThread(LPVOID pParam)
{
	thread_component * pComponent = (thread_component *) pParam;
	try
	{
		pComponent->m_ExitCode = pComponent->ExecOnThread();
	}
	catch(std::exception& ex)
	{
        pComponent->m_Error = ex.what();
		pComponent->m_ExitCode = -1;
	}
	catch(...)
	{
        pComponent->m_Error = TEXT("Failed to execute threaded Component");
		pComponent->m_ExitCode = -1;
	}
	return pComponent->m_ExitCode;
}

void thread_component::Init(CDialog * pDialog)
{
	m_ExitCode = 0;
    Component::Init(pDialog);
    m_pThread = AfxBeginThread(ExecuteThread, this, 0, 0, CREATE_SUSPENDED);
    m_pThread->ResumeThread();
}

bool thread_component::Exec()
{
    if (m_pThread != NULL)
    {
        if (WAIT_FAILED == WaitForSingleObject(m_pThread->m_hThread, INFINITE))
		{
			throw std::exception("WaitForSingleObject failed");
		}

        if (m_Error.GetLength())
        {
            throw std::exception(DVLib::Tstring2string((LPCWSTR) m_Error).c_str());
        }
    }

    return m_ExitCode == 0 ? true : false;
}

