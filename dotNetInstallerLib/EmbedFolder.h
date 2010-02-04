#pragma once

class EmbedFolder
{
public:
	XmlAttribute sourcefolderpath;
	XmlAttribute targetfolderpath;
public:
	EmbedFolder();
	virtual void Load(TiXmlElement * node);
};

typedef shared_any<EmbedFolder *, close_delete> EmbedFolderPtr;