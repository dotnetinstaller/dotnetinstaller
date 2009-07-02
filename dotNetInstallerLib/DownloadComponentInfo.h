#pragma once

struct DownloadComponentInfo
{
	//URL del file da scaricare
	CString SourceURL;

	//Optional local location for the file.
	CString SourcePath;

	//Directory di destinazione (senza il nome del file)
	CString DestinationPath;

	//File di destinazione (se vuoto il nome del file viene reperito dal campo SourceURL)
	CString DestinationFileName;

	////Indica se scaricare sempre il componente anche se si trova già nella directory di destinazione
	//bool ForceDownload;

	//Nome visivo del componente
	CString ComponentName;

    // enable bypassing download if the file already exists locally
	bool AlwaysDownload;
};

typedef CArray<DownloadComponentInfo> DownloadComponentInfoVector;
