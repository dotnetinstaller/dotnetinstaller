#pragma once

class Component;

#include "WidgetPosition.h"

enum configuration_type
{
	configuration_unknown = 0,
	configuration_install,
	configuration_reference
};

class Configuration
{
public:
	// configuration lcid filter
	std::wstring lcid_filter;
	// configuration language
	std::wstring language;
	std::wstring language_id;
	// filter for minimum operating system version
	std::wstring os_filter_greater;
	// filter for maximum operating system version
	std::wstring os_filter_smaller;
	// filter for processor architecture
	std::wstring processor_architecture_filter;
	// configuration type
	configuration_type type;
	// install mode
	bool supports_install;
	bool supports_uninstall;
public:
	Configuration(configuration_type t);
	virtual void Load(TiXmlElement * node);
	// returns true if this configuration is supported on this operating system/lcid
	virtual bool IsSupported(LCID lcid) const;
	virtual std::wstring GetLanguageString() const;
	virtual std::wstring GetString(int indent = 0) const;
};

typedef shared_any<Configuration *, close_delete> ConfigurationPtr;
