#include "StdAfx.h"
#include "ControlValue.h"

ControlValue::ControlValue(const Control& control)
{
	enabled = (control.IsEnabled() || control.has_value_disabled);
	visible = control.IsVisible();
}

ControlValue::~ControlValue()
{

}

ControlValueBrowse::ControlValueBrowse(const ControlBrowse& control)
	: ControlValue(control)
{

}

std::wstring ControlValueBrowse::GetValue() const
{
	std::wstring value = (LPCTSTR) CBrowseCtrl::GetPathName();
	value = DVLib::trimright(value, L" \t\n\r\\/");
	if (value.length() == 2 && value[1] == L':') value += L"\\";
	return value;
}

ControlValueEdit::ControlValueEdit(const ControlEdit& control)
	: ControlValue(control)
{

}

std::wstring ControlValueEdit::GetValue() const 
{
	CString value;
	CEdit::GetWindowTextW(value);
	return std::wstring((LPCTSTR) value);
}

ControlValueCheckBox::ControlValueCheckBox(const ControlCheckBox& checkbox)
	: ControlValue(checkbox)
	, checked_value(checkbox.checked_value)
	, unchecked_value(checkbox.unchecked_value)
{

}

std::wstring ControlValueCheckBox::GetValue() const 
{
	return CButton::GetCheck() ? checked_value : unchecked_value;
}

ControlValueLicense::ControlValueLicense(const ControlLicense& license)
	: ControlValue(license)
	, accept_message(license.accept_message)
{

}

std::wstring ControlValueLicense::GetValue() const
{
	if (! InstallUILevelSetting::Instance->IsSilent())
	{
		if (! CButton::GetCheck())
		{
			THROW_EX(accept_message);
		}
	}
	return CButton::GetCheck() ? L"1" : L"0";
}
