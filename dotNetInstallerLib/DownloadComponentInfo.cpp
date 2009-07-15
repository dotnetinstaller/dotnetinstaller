#include "StdAfx.h"
#include "DownloadComponentInfo.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

DownloadComponentInfo::DownloadComponentInfo()
{

}

void DownloadComponentInfo::Load(TiXmlElement * node)
{
	CHECK_BOOL(node != NULL,
		L"Expected 'download' node");

	CHECK_BOOL(0 == strcmp(node->Value(), "download"),
		L"Expected 'download' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

	componentname = node->AttributeW("componentname");			
	sourceurl = InstallerSession::MakePath(node->AttributeW("sourceurl"));
	sourcepath = InstallerSession::MakePath(node->AttributeW("sourcepath"));
	destinationpath = InstallerSession::MakePath(node->AttributeW("destinationpath"));
	destinationfilename = InstallerSession::MakePath(node->AttributeW("destinationfilename"));
	alwaysdownload = DVLib::wstring2bool(node->AttributeW("alwaysdownload"), true);		

	LOG(L"Loaded 'download' dialog component '" << componentname 
		<< L"', source=" << (sourceurl.length() ? sourceurl : sourcepath));
}