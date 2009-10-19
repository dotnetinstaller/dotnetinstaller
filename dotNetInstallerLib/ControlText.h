#pragma once
#include "Control.h"

class ControlText : public Control
{
public:
    ControlText(control_type type);
public:
	// control text
	std::wstring text;
	// font face name
	std::wstring font_name;
	// font point size
	int font_size;
	void Load(TiXmlElement * node);
	std::wstring GetString() const;
};

typedef shared_any<ControlText *, close_delete> ControlTextPtr;
