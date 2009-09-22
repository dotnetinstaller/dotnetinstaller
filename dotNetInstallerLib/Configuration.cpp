#include "StdAfx.h"
#include "Configuration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"
#include "XmlAttribute.h"

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
	lcid_filter = DVLib::UTF8string2wstring(node->Attribute("lcid_filter"));
	// language
	language_id = XML_ATTRIBUTE(node->Attribute("language_id"));
	language = XML_ATTRIBUTE(node->Attribute("language"));
	// os filters
	os_filter_greater = DVLib::UTF8string2wstring(node->Attribute("os_filter_greater"));
	os_filter_smaller = DVLib::UTF8string2wstring(node->Attribute("os_filter_smaller"));
	// processor architecture filter
	processor_architecture_filter = DVLib::UTF8string2wstring(node->Attribute("processor_architecture_filter"));
}

bool Configuration::IsSupported(DWORD oslcid) const
{
	return DVLib::IsOperatingSystemLCID(oslcid, lcid_filter) &&
		DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), processor_architecture_filter) &&
		DVLib::IsInOperatingSystemInRange(DVLib::GetOperatingSystemVersion(), os_filter_greater, os_filter_smaller);
}

std::wstring Configuration::GetLanguageString() const
{
	std::wstring result = language;
	if (result.empty()) result = language_id;
	if (result.empty()) result = lcid_filter;
	// \todo: get the string representation of the current language
	if (result.empty()) result = DVLib::towstring(DVLib::GetOperatingSystemLCID(DVLib::LcidUser));
	return result;
}

std::wstring Configuration::GetString(int indent) const
{
	std::wstringstream ss;
	ss << L", lang=" << GetLanguageString();
	if (! processor_architecture_filter.empty()) 
		ss << L", pa=" << processor_architecture_filter;
	if (! os_filter_greater.empty() || ! os_filter_smaller.empty())
		ss << L", os=" << os_filter_greater << L"/" << os_filter_smaller;
	return ss.str();
}