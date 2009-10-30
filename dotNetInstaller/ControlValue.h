#pragma once
#include "BrowseCtrl.h"

class ControlValue
{
public:
	virtual std::wstring GetValue() const = 0;
	ControlValue();
	virtual ~ControlValue();
};

class ControlValueBrowse : public CBrowseCtrl, public ControlValue
{
public:
	ControlValueBrowse();
	std::wstring GetValue() const;
};

class ControlValueEdit : public CEdit, public ControlValue
{
public:
	ControlValueEdit();
	std::wstring GetValue() const;
};

class ControlValueCheckBox : public CButton, public ControlValue
{
private:
	std::wstring checked_value;
	std::wstring unchecked_value;
public:
	ControlValueCheckBox(const std::wstring& checked, const std::wstring& unchecked);
	std::wstring GetValue() const;
};

class ControlValueLicense : public CButton, public ControlValue
{
private:
	std::wstring accept_message;
public:
	ControlValueLicense(const std::wstring& msg);
	std::wstring GetValue() const;
};
