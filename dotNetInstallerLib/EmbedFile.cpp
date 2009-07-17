#include "StdAfx.h"
#include "EmbedFile.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

EmbedFile::EmbedFile()
{

}

void EmbedFile::Load(TiXmlElement * node)
{
	CHECK_BOOL(node != NULL,
		L"Expected 'embedfile' node");

	CHECK_BOOL(0 == strcmp(node->Value(), "embedfile"),
		L"Expected 'embedfile' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

	sourcefilepath = InstallerSession::MakePath(DVLib::UTF8string2wstring(node->Attribute("sourcefilepath")));
	targetfilepath = InstallerSession::MakePath(DVLib::UTF8string2wstring(node->Attribute("targetfilepath")));

	LOG(L"Read 'embedfile', source=" << sourcefilepath
		<< L", target=" << targetfilepath);
}