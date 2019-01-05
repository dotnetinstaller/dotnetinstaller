#pragma once

#include "XmlAttribute.h"
#include <tinyxml2.h>

class FileAttribute
{
public:
	XmlAttribute name;
	XmlAttribute value;
public:
	FileAttribute();
	virtual void Load(tinyxml2::XMLElement * node);
};

