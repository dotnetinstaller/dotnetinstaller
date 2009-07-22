#pragma once
#include "Component.h"

typedef shared_any<CWinThread *, close_delete> ThreadPtr;

class ThreadComponent : public Component
{
public:
    ThreadComponent(component_type t);
	~ThreadComponent();
public:
    bool IsExecuting() const;
	const std::wstring& GetError() const { return m_error; }
    void Exec();
	void BeginExec();
	void EndExec();
protected:
    virtual int ExecOnThread() = 0;
private:
    ThreadPtr m_pThread;
    std::wstring m_error;
	int m_rc;
    static UINT ExecuteThread(LPVOID pParam);
	int GetExitCode() const { return m_rc; }
};
