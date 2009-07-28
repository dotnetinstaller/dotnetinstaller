#pragma once

class IDownloadCallback
{
public:
	virtual void Connecting() = 0;
	virtual void SendingRequest() = 0;
	virtual void Status(ULONG progress_current, ULONG progress_max, const std::wstring& description) = 0;
	virtual void DownloadComplete() = 0;
	virtual void DownloadError(const std::wstring& message) = 0;
	virtual bool IsDownloadCancelled() const = 0;
	virtual void DownloadCancel() = 0;
};
