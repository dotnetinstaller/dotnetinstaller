#include "StdAfx.h"
#include "ControlValue.h"

ControlValue::ControlValue()
{

}

ControlValue::~ControlValue()
{

}

ControlValueBrowse::ControlValueBrowse()
{

}

std::wstring ControlValueBrowse::GetValue() const
{
	return std::wstring((LPCTSTR) CBrowseCtrl::GetPathName());
}

ControlValueEdit::ControlValueEdit()
{

}

std::wstring ControlValueEdit::GetValue() const 
{
	CString value;
	CEdit::GetWindowTextW(value);
	return std::wstring((LPCTSTR) value);
}

ControlValueCheckBox::ControlValueCheckBox(const std::wstring& checked, const std::wstring& unchecked)
	: checked_value(checked)
	, unchecked_value(unchecked)
{

}

std::wstring ControlValueCheckBox::GetValue() const 
{
	return CButton::GetCheck() ? checked_value : unchecked_value;
}

ControlValueLicense::ControlValueLicense(const std::wstring& msg)
	: accept_message(msg)
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
