#include "StdAfx.h"
#include "Schema.h"
#include "InstallerLog.h"

Schema::Schema()
	: generator(L"dotNetInstaller InstallerEditor")
	, version(L"1")
{

}

void Schema::Load(TiXmlElement * node)
{
	CHECK_BOOL(node != NULL,
		L"Expected 'schema' node");

	CHECK_BOOL(0 == strcmp(node->Value(), "schema"),
		L"Expected 'schema' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

	version = DVLib::UTF8string2wstring(node->Attribute("version"));
	generator = DVLib::UTF8string2wstring(node->Attribute("generator"));

	LOG(L"Loaded schema: version=" << version << L", generator=" << generator);
}
