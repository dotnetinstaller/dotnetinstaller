#pragma once

class DownloadComponentInfo
{
public:
	// download url
	std::wstring sourceurl;
	// optional local location for the file
	std::wstring sourcepath;
	// destination path
	std::wstring destinationpath;
	// destination filename
	std::wstring destinationfilename;
	// component name
	std::wstring componentname;
    // enable bypassing download if the file already exists locally
	bool alwaysdownload;
public:
	DownloadComponentInfo();
	void Load(TiXmlElement * node);
};

typedef shared_any<DownloadComponentInfo *, close_delete> DownloadComponentInfoPtr;
