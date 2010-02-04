#pragma once

class EmbedFile
{
public:
	XmlAttribute sourcefilepath;
	XmlAttribute targetfilepath;
public:
	EmbedFile();
	virtual void Load(TiXmlElement * node);
};

typedef shared_any<EmbedFile *, close_delete> EmbedFilePtr;