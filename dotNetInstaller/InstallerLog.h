#pragma once

class InstallerLog
{
public:
	InstallerLog(void);
	~InstallerLog(void);

	void EnableLog()
	{
		m_EnableLog = true;
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
};

extern InstallerLog ApplicationLog;

