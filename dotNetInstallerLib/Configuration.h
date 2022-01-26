#pragma once

class Component;

#include "WidgetPosition.h"
#include "XmlAttribute.h"
#include <tinyxml2.h>

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
	XmlAttribute lcid_filter;
	// configuration language
	XmlAttribute language;
	XmlAttribute language_id;
	// filter for operating system version
	XmlAttribute os_filter;
	// operating system filter range
	DVLib::OperatingSystem os_filter_min;
	DVLib::OperatingSystem os_filter_max;
	// operating system product type filter
	XmlAttribute os_type_filter;
	// filter for processor architecture
	XmlAttribute processor_architecture_filter;
	// configuration type
	configuration_type type;
	// install mode
	bool supports_install;
	bool supports_uninstall;
public:
	Configuration(configuration_type t);
	virtual ~Configuration();
	virtual void Load(tinyxml2::XMLElement * node);
	// returns true if this configuration is supported on this operating system/lcid
	virtual bool IsSupported(LCID lcid) const;
	virtual std::wstring GetLanguageString() const;
	virtual std::wstring GetString(int indent = 0) const;
};

typedef shared_any<Configuration *, close_delete> ConfigurationPtr;
