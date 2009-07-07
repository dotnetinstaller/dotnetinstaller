#pragma once

struct DownloadComponentInfo
{
	// download url
	std::wstring source_url;
	// optional local location for the file
	std::wstring source_path;
	// destination path
	std::wstring destination_path;
	// destination filename
	std::wstring destination_filename;
	// component name
	std::wstring component_name;
    // enable bypassing download if the file already exists locally
	bool always_download;
};
