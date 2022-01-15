#include "StdAfx.h"
#include "Configuration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"
#include "XmlAttribute.h"

Configuration::Configuration(configuration_type t)
: type(t),
os_filter_min(DVLib::winNone),
os_filter_max(DVLib::winNone),
supports_install(false),
supports_uninstall(false)
{

}

Configuration::~Configuration()
{

}

void Configuration::Load(tinyxml2::XMLElement * node)
{
    CHECK_BOOL(node != NULL,
        L"Expected 'configuration' node");

    CHECK_BOOL(0 == strcmp(node->Value(), "configuration"),
        L"Expected 'configuration' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

    // locale
    lcid_filter = node->Attribute("lcid_filter");
    // language
    language_id = node->Attribute("language_id");
    language = node->Attribute("language");
    // os filters
    os_filter = node->Attribute("os_filter");
    os_filter_min = DVLib::oscode2os(XmlAttribute(node->Attribute("os_filter_min")).GetValue());
    os_filter_max = DVLib::oscode2os(XmlAttribute(node->Attribute("os_filter_max")).GetValue());
    os_type_filter = node->Attribute("os_type_filter");
    // processor architecture filter
    processor_architecture_filter = XmlAttribute(node->Attribute("processor_architecture_filter"));
    // install modes
    supports_install = XmlAttribute(node->Attribute("supports_install")).GetBoolValue(true);
    supports_uninstall = XmlAttribute(node->Attribute("supports_uninstall")).GetBoolValue(true);
}

bool Configuration::IsSupported(LCID lcid) const
{
    return DVLib::IsOperatingSystemLCIDValue(lcid, lcid_filter) &&
        DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), processor_architecture_filter) &&
        DVLib::IsInOperatingSystemInRange(DVLib::GetOperatingSystemVersion(), os_filter, os_filter_min, os_filter_max) &&
        DVLib::IsOperatingSystemProductType(DVLib::GetOperatingSystemProductType(), os_type_filter);
}

std::wstring Configuration::GetLanguageString() const
{
    std::wstring result = language;
    if (result.empty()) result = language_id.GetValue();
    if (result.empty()) result = lcid_filter.GetValue();
    // \todo: get the string representation of the current language
    if (result.empty()) result = DVLib::towstring(DVLib::GetOperatingSystemLCID(DVLib::LcidUser));
    return result;
}

std::wstring Configuration::GetString(int /* indent */) const
{
    std::wstringstream ss;
    ss << L", lang=" << GetLanguageString();
    if (! processor_architecture_filter.empty()) 
        ss << L", pa=" << processor_architecture_filter;
    if (! os_filter.empty())
        ss << L", os=" << os_filter;
    if (os_filter_min != DVLib::winNone)
        ss << L", os_filter_min=" << DVLib::os2wstring(os_filter_min);
    if (os_filter_max != DVLib::winNone)
        ss << L", os_filter_max=" << DVLib::os2wstring(os_filter_max);
    if (!os_type_filter.empty())
        ss << L", os_type=" << os_type_filter;
    return ss.str();
}