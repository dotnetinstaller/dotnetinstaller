#pragma once

#include "Configuration.h"
#include "DownloadDialog.h"

class ReferenceConfiguration : public Configuration
{
public:
	std::wstring filename;
	DownloadDialogPtr downloaddialog;
public:
	ReferenceConfiguration();
	~ReferenceConfiguration();
	virtual void Load(TiXmlElement * node);
	void Exec();
	std::wstring GetString(int indent = 0) const;
};

