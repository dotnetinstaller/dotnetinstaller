#pragma once
#include "Component.h"

class ThreadComponent : public Component
{
public:
    ThreadComponent();
	~ThreadComponent();
public:
    bool IsExecuting() const;
	DWORD GetExitCode() const { return m_exitcode; }
	const std::wstring& GetError() const { return m_error; }
    void Exec();
protected:
    virtual UINT ExecOnThread() = 0;
private:
    CWinThread * m_pThread;
    std::wstring m_error;
	DWORD m_exitcode;
    static UINT ExecuteThread(LPVOID pParam);
};
