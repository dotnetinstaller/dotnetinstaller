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
	// language selection
	bool show_language_selector;
	std::wstring language_selector_title;
	std::wstring language_selector_ok;
	std::wstring language_selector_cancel;
	// error message when no matching os/lcid configuration was found
	std::wstring configuration_no_match_message;
public:
	Configurations();
	virtual ~Configurations();
	virtual void Load(TiXmlElement * node);
	// returns configurations that match current platform, lcid and processor architecture
	std::vector<ConfigurationPtr> GetSupportedConfigurations(DWORD oslcid) const;
	std::vector<std::wstring> GetLanguages() const;
	virtual std::wstring GetString() const;
};

typedef shared_any<Configurations *, close_delete> ConfigurationsPtr;
