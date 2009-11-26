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
	// component name
	std::wstring component_name;
	// help message
	std::wstring help_message;
	// progress messages
	std::wstring downloading_message;
	std::wstring copying_message;
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
	bool IsRequired() const;
	DownloadDialog(const std::wstring& name = L"");
	void Load(TiXmlElement * node);
	int ExecOnThread();
	std::wstring GetString(int indent = 0) const;
};

typedef shared_any<DownloadDialog *, close_delete> DownloadDialogPtr;
