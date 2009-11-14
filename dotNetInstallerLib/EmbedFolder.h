#pragma once

class EmbedFolder
{
public:
	std::wstring sourcefolderpath;
	std::wstring targetfolderpath;
public:
	EmbedFolder();
	virtual void Load(TiXmlElement * node);
};

typedef shared_any<EmbedFolder *, close_delete> EmbedFolderPtr;