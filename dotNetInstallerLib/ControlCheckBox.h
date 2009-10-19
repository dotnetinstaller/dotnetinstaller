#pragma once
#include "ControlText.h"

class ControlCheckBox : public ControlText
{
public:
    ControlCheckBox();
public:
	// checked
	bool checked;
	// id
	std::wstring id;
	// values
	std::wstring checked_value;
	std::wstring unchecked_value;
	void Load(TiXmlElement * node);
	std::wstring GetString() const;
};

typedef shared_any<ControlCheckBox *, close_delete> ControlCheckBoxPtr;
