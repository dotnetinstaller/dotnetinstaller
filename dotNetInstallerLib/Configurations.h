#pragma once

#include "Schema.h"
#include "Configuration.h"
#include "InstallUILevel.h"
#include "FileAttributes.h"

class Configurations : public std::vector< ConfigurationPtr >
{
public:
	DVLib::LcidType lcidtype;
	std::wstring fileversion;
	std::wstring productversion;
	InstallUILevel uilevel;
	Schema schema;
	FileAttributes fileattributes;
    // auto-enabled log
    bool log_enabled;
    std::wstring log_file;
public:
	Configurations();
	virtual ~Configurations();
	virtual void Load(TiXmlElement * node);
	// returns configurations that match current platform, lcid and processor architecture
	std::vector< ConfigurationPtr > GetSupportedConfigurations() const;
};

