#include "StdAfx.h"
#include "Configuration.h"
#include "InstallerLog.h"

Configuration::Configuration(configuration_type t)
	: type(t)
{

}

void Configuration::Load(TiXmlElement * node)
{
	CHECK_BOOL(node != NULL,
		L"Expected 'configuration' node");

	CHECK_BOOL(0 == strcmp(node->Value(), "configuration"),
		L"Expected 'configuration' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

	// locale
	lcid = node->AttributeW("lcid");
	// os filters
	os_filter_greater = node->AttributeW("os_filter_greater");
	os_filter_smaller = node->AttributeW("os_filter_smaller");
	// processor architecture filter
	processor_architecture_filter = node->AttributeW("processor_architecture_filter");
}

bool Configuration::IsSupported(DVLib::LcidType lcidtype) const
{
	return DVLib::IsOperatingSystemLCID(lcidtype, lcid) &&
		DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), processor_architecture_filter) &&
		DVLib::IsInOperatingSystemInRange(DVLib::GetOperatingSystemVersion(), os_filter_greater, os_filter_smaller);
}