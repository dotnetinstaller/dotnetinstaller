#include "StdAfx.h"
#include "XmlAttribute.h"
#include "EmbedFile.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

EmbedFile::EmbedFile()
{

}

void EmbedFile::Load(tinyxml2::XMLElement * node)
{
    CHECK_BOOL(node != NULL,
        L"Expected 'embedfile' node");

    CHECK_BOOL(0 == strcmp(node->Value(), "embedfile"),
        L"Expected 'embedfile' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

    sourcefilepath = node->Attribute("sourcefilepath");
    targetfilepath = node->Attribute("targetfilepath");

    LOG(L"Read 'embedfile', source=" << sourcefilepath
        << L", target=" << targetfilepath);
}
