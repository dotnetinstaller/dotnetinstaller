#pragma once
#include <tinyxml2.h>

class EmbedFile
{
public:
	XmlAttribute sourcefilepath;
	XmlAttribute targetfilepath;
public:
	EmbedFile();
	virtual void Load(tinyxml2::XMLElement * node);
};

typedef shared_any<EmbedFile *, close_delete> EmbedFilePtr;