#pragma once

class InstallerLog
{
public:
	InstallerLog(void);
	~InstallerLog(void);

	void DisableLog()
	{
		m_EnableLog = false;
	}

	bool IsEnableLog() const
	{
		return m_EnableLog;
	}

    void EnableLog()
    {
        m_EnableLog = true;
    }

    const CString& GetLogFile() const 
    { 
        return m_LogFile; 
    }

    void SetLogFile(LPCTSTR filename)
    {
        m_LogFile = filename;
    }

	void Write(LPCTSTR message);
	void Write(LPCTSTR message, LPCTSTR appendMessage);

private:
	bool m_EnableLog;
    CString m_LogFile;
    HANDLE m_hFile;
};

extern InstallerLog ApplicationLog;

