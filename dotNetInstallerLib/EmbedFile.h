#pragma once

class InstallConfiguration;

class EmbedFile
{
public:
	std::wstring sourcefilepath;
	std::wstring targetfilepath;
public:
	EmbedFile();
	virtual void Load(TiXmlElement * node);
};

typedef shared_any<EmbedFile *, close_delete> EmbedFilePtr;