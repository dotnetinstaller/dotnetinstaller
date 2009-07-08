#pragma once
#include "Component.h"

class thread_component : public Component
{
public:
    thread_component();
	~thread_component();
public:
    CWinThread * m_pThread;
	DWORD m_exitcode;
    std::wstring m_error;
public:
    bool IsExecuting() const;
    virtual UINT ExecOnThread() = 0;
    DWORD GetExitCode() const;
    void Exec();
private:
    static UINT ExecuteThread(LPVOID pParam);
};
