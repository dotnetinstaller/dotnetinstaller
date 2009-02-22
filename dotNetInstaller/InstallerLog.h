#pragma once

class InstallerLog
{
public:
	InstallerLog(void);
	~InstallerLog(void);

	void EnableLog(LPCTSTR filename = NULL)
	{
		m_EnableLog = true;
        m_LogFileName = filename; 
	}

	void DisableLog()
	{
		m_EnableLog = false;
	}

	bool IsEnableLog()
	{
		return m_EnableLog;
	}

	void Write(LPCTSTR message);
	void Write(LPCTSTR message, LPCTSTR appendMessage);

private:
	bool m_EnableLog;
    CString m_LogFileName;
    HANDLE m_hFile;
};

extern InstallerLog ApplicationLog;

