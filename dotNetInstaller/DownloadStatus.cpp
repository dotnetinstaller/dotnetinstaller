#include "StdAfx.h"
#include "DownloadStatus.h"

DownloadStatusPtr DownloadStatus::CreateProgress(const std::wstring& status, ULONG progress_current, ULONG progress_max)
{
	DownloadStatusPtr param(new DownloadStatus());
	param->type = StatusType_Downloading;
	param->progress_current = progress_current;
	param->progress_max = progress_max;
	param->status = status;
	return param;
}

DownloadStatusPtr DownloadStatus::CreateComplete()
{
	DownloadStatusPtr param(new DownloadStatus());
	param->type = StatusType_Completed;
	return param;
}

DownloadStatusPtr DownloadStatus::CreateError(const std::wstring& error)
{
	DownloadStatusPtr param(new DownloadStatus());
	param->type = StatusType_Error;
	param->error = error;
	return param;
}

DownloadStatusPtr DownloadStatus::CreateCanceled()
{
	DownloadStatusPtr param(new DownloadStatus());
	param->type = StatusType_Canceled;
	return param;
}
