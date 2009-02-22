#include "StdAfx.h"
#include ".\installerlog.h"
#include "path.h"
#include <string>
#include "StringUtil.h"

InstallerLog ApplicationLog;

InstallerLog::InstallerLog(void):
				m_EnableLog(false)
{
}

InstallerLog::~InstallerLog(void)
{
}

void InstallerLog::Write(LPCTSTR message)
{
	if (IsEnableLog() == false || message == NULL)
		return;
		
	CString tempFile = DVLib::PathCombineCustom(DVLib::GetTempPathCustom(), TEXT("dotNetInstallerLog.txt") );

	HANDLE l_hFile = CreateFile(tempFile, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (l_hFile == INVALID_HANDLE_VALUE)
		return;

	SetFilePointer(l_hFile, 0, 0, FILE_END);

	DWORD l_BytesWritten = 0;

	std::string strMessage = DVLib::Tstring2string(message);
	strMessage.append("\r\n");

	if (WriteFile(l_hFile, strMessage.data(), (DWORD)strMessage.length(), &l_BytesWritten, NULL) == FALSE)
		return;

	CloseHandle(l_hFile);
}

void InstallerLog::Write(LPCTSTR message, LPCTSTR appendMessage)
{
	stlstring tmp = message;
	tmp.append(appendMessage);
	Write(tmp.data());
}