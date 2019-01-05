#pragma once
#include <tinyxml2.h>

class EmbedFolder
{
public:
	XmlAttribute sourcefolderpath;
	XmlAttribute targetfolderpath;
public:
	EmbedFolder();
	virtual void Load(tinyxml2::XMLElement * node);
};

typedef shared_any<EmbedFolder *, close_delete> EmbedFolderPtr;