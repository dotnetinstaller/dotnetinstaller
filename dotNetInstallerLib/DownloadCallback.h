#pragma once

class IDownloadCallback
{
public:
	virtual void DownloadingFile(const std::wstring& filename) = 0;
	virtual void CopyingFile(const std::wstring& filename) = 0;
	virtual void Connecting(const std::wstring& host) = 0;
	virtual void SendingRequest(const std::wstring& host) = 0;
	virtual void Status(ULONG progress_current, ULONG progress_max, const std::wstring& description) = 0;
	virtual void DownloadComplete() = 0;
	virtual void DownloadError(const std::wstring& message) = 0;
	virtual bool IsDownloadCancelled() const = 0;
};
