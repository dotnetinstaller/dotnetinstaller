#pragma once
#include "Component.h"

class thread_component : public Component
{
public:
    thread_component();
public:
    CWinThread * m_pThread;
	DWORD m_ExitCode;
    CString m_Error;
public:
    bool IsExecuting();
    virtual UINT ExecOnThread() = 0;
    DWORD GetExitCode();
    void Init(CDialog * pDialog);
    bool Exec();
private:
    static UINT ExecuteThread(LPVOID pParam);
};
