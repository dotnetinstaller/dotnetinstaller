#pragma once
#include "ControlText.h"

class ControlEdit : public ControlText
{
public:
    ControlEdit();
public:
	// id
	XmlAttribute id;
	void Load(tinyxml2::XMLElement * node);
	std::wstring GetString() const;
};

typedef shared_any<ControlEdit *, close_delete> ControlEditPtr;
