#pragma once

#include "DownloadCallback.h"
#include "ThreadComponent.h"
#include "DownloadFile.h"

class DownloadDialog : public ThreadComponent
{
public:
	// download callback
	IDownloadCallback * callback;
	// download window caption
	std::wstring caption;
	// help message
	std::wstring help_message;
	// progress messages
	std::wstring downloading_message;
	std::wstring connecting_message;
	std::wstring sendingrequest_message;
	// start button caption
	std::wstring start_caption;
	// cancel button caption
	std::wstring cancel_caption;
	// download components
	std::vector< DownloadFilePtr > downloadfiles;
	// auto-start download
	bool auto_start;
public:
	bool IsCopyRequired() const;
	bool IsDownloadRequired() const;
	DownloadDialog();
	void Load(TiXmlElement * node);
	int ExecOnThread();
};

typedef shared_any<DownloadDialog *, close_delete> DownloadDialogPtr;
