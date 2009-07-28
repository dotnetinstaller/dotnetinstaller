#pragma once

#include "Configuration.h"
#include "DownloadDialog.h"

class ReferenceConfiguration : public Configuration
{
public:
	std::wstring filename;
	std::wstring lcid;
	DownloadDialogPtr downloaddialog;
public:
	ReferenceConfiguration();
	~ReferenceConfiguration();
	virtual void Load(TiXmlElement * node);
	void Exec();
};

