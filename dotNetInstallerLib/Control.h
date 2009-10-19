#pragma once
#include "WidgetPosition.h"

enum control_type
{
	control_type_undefined = 0, 
	control_type_label, // label
	control_type_edit, // edit
	control_type_checkbox, // checkbox
	control_type_browse, // browse
};

class Control
{
public:
    Control(control_type t);
    virtual ~Control();
public:
	// control type
	control_type type;
	// control position
	WidgetPosition position;
	// enabled
	bool enabled;
	// load a control from an xml node
	virtual void Load(TiXmlElement * node);
	// string representation of the control
	virtual std::wstring GetString() const;
};

typedef shared_any<Control *, close_delete> ControlPtr;
