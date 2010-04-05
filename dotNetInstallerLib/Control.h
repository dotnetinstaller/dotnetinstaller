#pragma once
#include "WidgetPosition.h"
#include "InstalledCheck.h"
#include "InstalledCheckOperator.h"

enum control_type
{
	control_type_undefined = 0, 
	control_type_label, // label
	control_type_edit, // edit
	control_type_checkbox, // checkbox
	control_type_browse, // browse
	control_type_license, // license
	control_type_hyperlink, // hyperlink
};

enum control_check
{
	control_check_enabled = 0, // enabled
	control_check_display, // display
	control_check_both, // both display and enabled
};

class Control
{
public:
    Control(control_type t);
    virtual ~Control();
public:
	// display
	bool display_install;
	bool display_uninstall;
	// value
	bool has_value_disabled;
	// installed checks that define whether this control is enabled
	std::vector<InstalledCheckPtr> installedchecks;
	// control type
	control_type type;
	// control check type
	control_check check;
	// control position
	WidgetPosition position;
	// enabled
	bool IsEnabled() const;
	// visible
	bool IsVisible() const;
	// load a control from an xml node
	virtual void Load(TiXmlElement * node);
	// string representation of the control
	virtual std::wstring GetString() const;
	// convert a string into a check type
	static control_check wstring2controlcheck(const std::wstring& value);
private:
	bool enabled;
};

typedef shared_any<Control *, close_delete> ControlPtr;
