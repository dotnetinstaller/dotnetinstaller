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
	lcid = DVLib::UTF8string2wstring(node->Attribute("lcid"));
	// os filters
	os_filter_greater = DVLib::UTF8string2wstring(node->Attribute("os_filter_greater"));
	os_filter_smaller = DVLib::UTF8string2wstring(node->Attribute("os_filter_smaller"));
	// processor architecture filter
	processor_architecture_filter = DVLib::UTF8string2wstring(node->Attribute("processor_architecture_filter"));
}

bool Configuration::IsSupported(DVLib::LcidType lcidtype) const
{
	return DVLib::IsOperatingSystemLCID(lcidtype, lcid) &&
		DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), processor_architecture_filter) &&
		DVLib::IsInOperatingSystemInRange(DVLib::GetOperatingSystemVersion(), os_filter_greater, os_filter_smaller);
}