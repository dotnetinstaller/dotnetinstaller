#pragma once

#include "Configuration.h"
#include "DownloadGroupConfiguration.h"

class ReferenceConfiguration : public Configuration
{
public:
	std::wstring filename;
	std::wstring lcid;
	DownloadGroupConfigurationPtr downloadconfiguration;
public:
	ReferenceConfiguration();
	~ReferenceConfiguration();
	virtual void Load(TiXmlElement * node);
	void Exec();
};

