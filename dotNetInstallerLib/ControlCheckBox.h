#pragma once
#include "ControlText.h"
#include <tinyxml2.h>

class ControlCheckBox : public ControlText
{
public:
    ControlCheckBox();
public:
	// checked
	bool checked;
	// id
	XmlAttribute id;
	// values
	XmlAttribute checked_value;
	XmlAttribute unchecked_value;
	void Load(tinyxml2::XMLElement * node);
	std::wstring GetString() const;
};

typedef shared_any<ControlCheckBox *, close_delete> ControlCheckBoxPtr;
