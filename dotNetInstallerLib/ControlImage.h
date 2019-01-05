#pragma once
#include "ControlText.h"

class ControlImage : public Control
{
public:
    ControlImage();
public:
	XmlAttribute resource_id;
	XmlAttribute image_file;
	bool center;
	void Load(tinyxml2::XMLElement * node);
	std::wstring GetString() const;
};

typedef shared_any<ControlImage *, close_delete> ControlImagePtr;
