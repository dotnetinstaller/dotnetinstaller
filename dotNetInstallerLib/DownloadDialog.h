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
	XmlAttribute caption;
	// component name
	XmlAttribute component_id;
	// help message
	XmlAttribute help_message;
	// progress messages
	XmlAttribute downloading_message;
	XmlAttribute copying_message;
	XmlAttribute connecting_message;
	XmlAttribute sendingrequest_message;
	// start button caption
	XmlAttribute start_caption;
	// cancel button caption
	XmlAttribute cancel_caption;
	// download components
	std::vector< DownloadFilePtr > downloadfiles;
	// auto-start download
	bool auto_start;
public:
	bool IsCopyRequired() const;
	bool IsDownloadRequired() const;
	bool IsRequired() const;
	DownloadDialog(const std::wstring& name = L"");
	void Load(tinyxml2::XMLElement * node);
	int ExecOnThread();
	std::wstring GetString(int indent = 0) const;
};

typedef shared_any<DownloadDialog *, close_delete> DownloadDialogPtr;
