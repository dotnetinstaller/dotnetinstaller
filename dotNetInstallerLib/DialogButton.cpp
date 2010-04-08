#include "StdAfx.h"
#include "DialogButton.h"

using namespace DialogButton;

DialogDefaultButton DialogButton::wstring2button(const std::wstring& button)
{
	if (button == L"cancel" || button.empty())
		return dialog_default_button_cancel;
	else if (button == L"install")
		return dialog_default_button_install;
	else if (button == L"skip")
		return dialog_default_button_skip;
	else 
	{
		THROW_EX(L"Invalid button: " << button);
	}
}
