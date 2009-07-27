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
	// returns true if a download is required (local file doesn't exist, etc.)
	bool IsDownloadRequired() const;
	// returns true if a local copy from source path is required (or possible)
	bool IsCopyRequired() const;
	std::wstring GetDestinationFileName() const;
	DownloadComponentInfo();
	void Load(TiXmlElement * node);
};

typedef shared_any<DownloadComponentInfo *, close_delete> DownloadComponentInfoPtr;
