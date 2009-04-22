#pragma once

#include "DownloadComponentInfo.h"

class IDownloadCallback
{
public:
	virtual void Status(ULONG p_CurrentProgress, ULONG p_MaxProgress, LPCTSTR p_Description) = 0;
	virtual void DownloadComplete() = 0;
	virtual void DownloadError(LPCTSTR p_Message) = 0;
	virtual bool WantToStop() = 0;
	virtual void CanceledByTheUser() = 0;
	virtual DownloadComponentInfoVector * GetComponents() = 0;
};
