#include "StdAfx.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

shared_any<InstallerLog *, close_delete> InstallerLog::Instance;

InstallerLog::InstallerLog(void)
    : m_enabled(false)
    , m_hFile(INVALID_HANDLE_VALUE)
{

}

InstallerLog::~InstallerLog(void)
{
    if (m_hFile != NULL)
    {
        ::CloseHandle(m_hFile);
    }
}

void InstallerLog::Write(const std::wstring& message)
{
	if (! IsEnabled() || message.empty())
		return;

    if (m_hFile == INVALID_HANDLE_VALUE)
    {
        if (m_logfile.empty()) 
        {
			m_logfile = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), L"dotNetInstallerLog.txt").c_str();
        }

		std::wstring path = DVLib::GetFileDirectoryW(m_logfile);
		if (path.length()) DVLib::DirectoryCreate(path);

		m_hFile = ::CreateFile(m_logfile.c_str(), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		CHECK_WIN32_BOOL(m_hFile != INVALID_HANDLE_VALUE,
			L"Error creating or opening \"" << m_logfile << L"\"");

	    SetFilePointer(m_hFile, 0, 0, FILE_END);
    }

	DWORD l_BytesWritten = 0;

	std::stringstream message_s;
	message_s << DVLib::FormatCurrentDateTimeA() << "\t" << DVLib::wstring2string(message) << "\r\n";

	CHECK_WIN32_BOOL(WriteFile(m_hFile, message_s.str().c_str(), message_s.str().size(),  & l_BytesWritten, NULL),
		L"Error writing to \"" << m_logfile << L"\"");
}

void InstallerLog::SetLogFile(const std::wstring& filename)
{ 
	m_logfile = InstallerSession::Instance->MakePath(filename); 
}
