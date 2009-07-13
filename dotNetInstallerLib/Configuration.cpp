#include "StdAfx.h"
#include "Configuration.h"
#include "InstallerTypes.h"
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

	lcid = node->AttributeW("lcid");
}

bool Configuration::IsSupported(DVLib::LcidType lcidtype) const
{
	return DVLib::IsOperatingSystemLCID(lcidtype, lcid);
}