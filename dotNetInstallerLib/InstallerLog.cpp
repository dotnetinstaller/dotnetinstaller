#include "StdAfx.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

shared_any<InstallerLog *, close_delete> InstallerLog::Instance;

InstallerLog::InstallerLog(void)
: m_enabled(false)
{

}

void InstallerLog::Write(const std::wstring& message)
{
    if (! IsEnabled() || message.empty())
        return;

    if (get(m_hFile) == INVALID_HANDLE_VALUE)
    {
        if (m_logfile.empty())
        {
            m_logfile = DVLib::DirectoryCombine(DVLib::GetTemporaryDirectoryW(), L"dotNetInstallerLog.txt").c_str();
        }

        std::wstring path = DVLib::GetFileDirectoryW(m_logfile);
        if (path.length()) DVLib::DirectoryCreate(path);

        reset(m_hFile, ::CreateFile(m_logfile.c_str(), GENERIC_WRITE, FILE_SHARE_READ, 
            NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

        if (!m_hFile)
        {
            // if a sharing violation occurred, get the process which has locked the file
            DWORD error = GetLastError();
            if (error == ERROR_SHARING_VIOLATION)
            {
                auto_handle hFileMapping;
                reset(hFileMapping, ::CreateFileMapping(get(m_hFile), NULL, PAGE_READONLY, 0, 1, NULL));

                CHECK_WIN32_BOOL(hFileMapping,
                    L"Failed to create file mapping \"" << m_logfile << L"\"");

                BY_HANDLE_FILE_INFORMATION fileInfo;
                CHECK_WIN32_BOOL(::GetFileInformationByHandle(get(m_hFile), &fileInfo),
                    L"Failed to retrieve file information \"" << m_logfile << L"\"");

                auto_handle hProcess;
                reset(hProcess, ::OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, fileInfo.dwVolumeSerialNumber));
                CHECK_WIN32_BOOL(hProcess,
                    L"Failed to retrieve process information \"" << m_logfile << L"\"");

                DWORD processId = ::GetProcessId(get(hProcess));

                // query WMI for process information
                std::wstring wmiQuery = L"SELECT Name FROM Win32_Process WHERE ProcessId = " + std::to_wstring(processId);
                std::wstring processName = DVLib::WmiUtil::Get(wmiQuery, L"Name");

                CHECK_WIN32_BOOL(m_hFile,
                    L"Error creating or opening \"" << m_logfile << L"\": The file is being used by \"" << processName << "\" (PID: " << processId << ").");
            }
        }

        CHECK_WIN32_BOOL(m_hFile,
            L"Error creating or opening \"" << m_logfile << L"\"");

        SetFilePointer(get(m_hFile), 0, 0, FILE_END);
    }

    DWORD l_BytesWritten = 0;

    std::stringstream message_s;
    message_s << DVLib::FormatCurrentDateTimeA() << "\t" << DVLib::wstring2string(message) << "\r\n";

    CHECK_WIN32_BOOL(WriteFile(get(m_hFile), message_s.str().c_str(), message_s.str().size(),  & l_BytesWritten, NULL),
        L"Error writing to \"" << m_logfile << L"\"");
}

void InstallerLog::SetLogFile(const std::wstring& filename)
{ 
    m_logfile = InstallerSession::Instance->ExpandVariables(filename); 
}

void InstallerLog::CloseLog()
{ 
    reset(m_hFile);
}
