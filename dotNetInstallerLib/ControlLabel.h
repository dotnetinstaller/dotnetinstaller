#pragma once
#include "ControlText.h"

class ControlLabel : public ControlText
{
public:
    ControlLabel();
public:
	void Load(tinyxml2::XMLElement * node);
	std::wstring GetString() const;
};

typedef shared_any<ControlLabel *, close_delete> ControlLabelPtr;
