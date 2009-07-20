#pragma once
#include "Component.h"

class ThreadComponent : public Component
{
public:
    ThreadComponent(component_type t);
	~ThreadComponent();
public:
    bool IsExecuting() const;
	DWORD GetExitCode() const { return m_exitcode; }
	const std::wstring& GetError() const { return m_error; }
    void Exec();
	void BeginExec();
	void EndExec();
protected:
    virtual UINT ExecOnThread() = 0;
private:
    auto_any<CWinThread *, close_delete> m_pThread;
    std::wstring m_error;
	DWORD m_exitcode;
    static UINT ExecuteThread(LPVOID pParam);
};
