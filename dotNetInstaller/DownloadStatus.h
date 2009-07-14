#pragma once

enum StatusType
{
	StatusType_Error,
	StatusType_Downloading,
	StatusType_Completed,
	StatusType_Canceled
};

struct DownloadStatus;
typedef auto_any<DownloadStatus *, close_delete> DownloadStatusPtr;

struct DownloadStatus
{
	// status properties
	StatusType type;
	ULONG progress_current;
	ULONG progress_max;
	std::wstring status;
	std::wstring error;
	// status constructors
	static DownloadStatusPtr CreateProgress(const std::wstring&, ULONG, ULONG);
	static DownloadStatusPtr CreateComplete();
	static DownloadStatusPtr CreateError(const std::wstring&);
	static DownloadStatusPtr CreateCanceled();
};

