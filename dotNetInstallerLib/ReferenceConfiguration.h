#pragma once

#include "Configuration.h"
#include "DownloadDialog.h"

class ReferenceConfiguration : public Configuration
{
public:
	XmlAttribute filename;
	DownloadDialogPtr downloaddialog;
public:
	ReferenceConfiguration();
	~ReferenceConfiguration();
	virtual void Load(tinyxml2::XMLElement * node);
	void Exec();
	std::wstring GetString(int indent = 0) const;
};

