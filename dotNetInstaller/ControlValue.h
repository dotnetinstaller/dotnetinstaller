#pragma once
#include "BrowseCtrl.h"

class ControlValue
{
private:
	bool enabled;
	bool visible;
public:
	bool IsEnabled() const { return enabled; }
	bool IsVisible() const { return visible; }
	virtual std::wstring GetValue() const = 0;
	ControlValue(const Control& parent);
	virtual ~ControlValue();
};

class ControlValueBrowse : public CBrowseCtrl, public ControlValue
{
public:
	ControlValueBrowse(const ControlBrowse& parent);
	std::wstring GetValue() const;
};

class ControlValueEdit : public CEdit, public ControlValue
{
public:
	ControlValueEdit(const ControlEdit& parent);
	std::wstring GetValue() const;
};

class ControlValueCheckBox : public CButton, public ControlValue
{
private:
	std::wstring checked_value;
	std::wstring unchecked_value;
public:
	ControlValueCheckBox(const ControlCheckBox& parent);
	std::wstring GetValue() const;
};

class ControlValueLicense : public CButton, public ControlValue
{
private:
	std::wstring accept_message;
public:
	ControlValueLicense(const ControlLicense& parent);
	std::wstring GetValue() const;
};
