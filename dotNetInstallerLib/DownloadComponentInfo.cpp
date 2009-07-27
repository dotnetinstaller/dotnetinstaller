#include "StdAfx.h"
#include "XmlAttribute.h"
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

	componentname = XML_ATTRIBUTE(node->Attribute("componentname"));
	sourceurl = XML_ATTRIBUTE(node->Attribute("sourceurl"));
	sourcepath = XML_ATTRIBUTE(node->Attribute("sourcepath"));
	destinationpath = XML_ATTRIBUTE(node->Attribute("destinationpath"));
	destinationfilename = XML_ATTRIBUTE(node->Attribute("destinationfilename"));
	alwaysdownload = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("alwaysdownload")), true);		

	LOG(L"Loaded 'download' dialog component '" << componentname 
		<< L"', source=" << (sourceurl.length() ? sourceurl : sourcepath));

	if (sourceurl.empty() && sourcepath.empty())
	{
		THROW_EX(L"Error in 'download' dialog component '" << componentname << L"', missing source url or path");
	}
}

bool DownloadComponentInfo::IsDownloadRequired() const
{
	if (sourceurl.empty())
		return false;

	if (! alwaysdownload)
	{
		// destination file has already been donwloaded
		if (DVLib::FileExists(GetDestinationFileName()))
			return false;
		// file exists in a local path
		if (IsCopyRequired())
			return false;
	}

	return true;
}

bool DownloadComponentInfo::IsCopyRequired() const
{
	// no source path, nothing to copy
	if (sourcepath.empty())
		return false;

	// download every time
	if (alwaysdownload)
		return false;

	// destination file has already been downloaded/copied
	if (DVLib::FileExists(GetDestinationFileName()))
		return false;

	// source path file exists, copy it
	if (DVLib::FileExists(sourcepath))
		return true;

	// source path file doesn't exist
	return false;
}

std::wstring DownloadComponentInfo::GetDestinationFileName() const
{
	return destinationfilename.empty()
		? DVLib::DirectoryCombine(destinationpath, DVLib::GetFileNameW(sourceurl))
		: DVLib::DirectoryCombine(destinationpath, destinationfilename);
}

