#pragma once

#include "XmlAttribute.h"

class FileAttribute
{
public:
	XmlAttribute name;
	XmlAttribute value;
public:
	FileAttribute();
	virtual void Load(TiXmlElement * node);
};

