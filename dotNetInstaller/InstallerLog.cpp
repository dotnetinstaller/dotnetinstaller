#include "StdAfx.h"
#include ".\installerlog.h"
#include "Path.h"
#include "File.h"
#include <string>
#include "StringUtil.h"

InstallerLog ApplicationLog;

InstallerLog::InstallerLog(void)
    : m_EnableLog(false)
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

void InstallerLog::Write(LPCTSTR message)
{
	if (IsEnableLog() == false || message == NULL)
		return;

    if (m_hFile == INVALID_HANDLE_VALUE)
    {
        if (m_LogFileName.GetLength() == 0)
        {
            m_LogFileName = DVLib::PathCombineCustom(DVLib::GetTempPathCustom(), TEXT("dotNetInstallerLog.txt"));
        }

	    m_hFile = CreateFile(m_LogFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	    if (m_hFile == INVALID_HANDLE_VALUE)
            throw (LPCTSTR) (TEXT("Error creating log file: ") + m_LogFileName);

	    SetFilePointer(m_hFile, 0, 0, FILE_END);
    }

	DWORD l_BytesWritten = 0;

	std::string strMessage = DVLib::Tstring2string(message);
	strMessage.append("\r\n");

	if (WriteFile(m_hFile, strMessage.data(), (DWORD)strMessage.length(), &l_BytesWritten, NULL) == FALSE)
		return;
}

void InstallerLog::Write(LPCTSTR message, LPCTSTR appendMessage)
{
	stlstring tmp = message;
	tmp.append(appendMessage);
	Write(tmp.data());
}