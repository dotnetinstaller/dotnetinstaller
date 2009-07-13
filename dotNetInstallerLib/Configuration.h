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
	std::wstring lcid;
	configuration_type type;
public:
	Configuration(configuration_type t);
	virtual void Load(TiXmlElement * node);
	// returns true if this configuration is supported on this operating system/lcid
	virtual bool IsSupported(DVLib::LcidType lcidtype) const;
};

typedef shared_any<Configuration *, close_delete> ConfigurationPtr;
