#pragma once

typedef shared_any<CWinThread *, close_delete> ThreadPtr;

class ThreadComponent
{
public:
    ThreadComponent();
	virtual ~ThreadComponent();
public:
	bool IsExecuting(DWORD dwTimeout = 0) const;
	const std::wstring& GetError() const { return m_error; }
    void Exec();
	void BeginExec();
	void EndExec();
protected:
    ThreadPtr m_pThread;
    std::wstring m_error;
	int m_rc;
    virtual int ExecOnThread() = 0;
private:
    static UINT ExecuteThread(LPVOID pParam);
	int GetExitCode() const { return m_rc; }
	void WaitForCompletion();
};
