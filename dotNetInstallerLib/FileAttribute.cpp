#include "StdAfx.h"
#include "FileAttribute.h"
#include "InstallerLog.h"

FileAttribute::FileAttribute()
{

}

void FileAttribute::Load(TiXmlElement * node)
{
	CHECK_BOOL(node != NULL,
		L"Expected 'fileattribute' node");

	CHECK_BOOL(0 == strcmp(node->Value(), "fileattribute"),
		L"Expected 'fileattribute' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

	name = DVLib::UTF8string2wstring(node->Attribute("name"));
	value = DVLib::UTF8string2wstring(node->Attribute("value"));

	LOG(L"Read file attribute: name=" << name 
		<< L", value=" << value);
}