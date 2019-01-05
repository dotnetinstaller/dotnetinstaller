#pragma once
#include "Control.h"

class ControlText : public Control
{
public:
    ControlText(control_type type);
public:
	// control text
	XmlAttribute text;
	// font face name
	XmlAttribute font_name;
	// font point size
	int font_size;
	void Load(tinyxml2::XMLElement * node);
	std::wstring GetString() const;
};

typedef shared_any<ControlText *, close_delete> ControlTextPtr;
