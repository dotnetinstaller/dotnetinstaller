#pragma once

class InstallerLog
{
public:
	InstallerLog();
	void DisableLog() { m_enabled = false; }
	bool IsEnabled() const { return m_enabled; }
    void EnableLog() { m_enabled = true; }
	void SetEnabled(bool enabled) { m_enabled = enabled; }
	const std::wstring& GetLogFile() const { return m_logfile; }
	void SetLogFile(const std::wstring& filename);
	void Write(const std::wstring& message);
	static shared_any<InstallerLog *, close_delete> Instance;
private:
	bool m_enabled;
	std::wstring m_logfile;
    auto_hfile m_hFile;
};

#define LOG( message ) \
{ \
	std::wstringstream ss_message; ss_message << message; \
	InstallerLog::Instance->Write(ss_message.str()); \
}

#define TRYLOG( message ) \
{ \
	try \
	{ \
		std::wstringstream ss_message; ss_message << message; \
		InstallerLog::Instance->Write(ss_message.str()); \
	} \
	catch(std::exception&) \
	{ \
	} \
}
