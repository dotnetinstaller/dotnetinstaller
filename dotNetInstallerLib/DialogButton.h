#pragma once

namespace DialogButton 
{
	enum DialogDefaultButton 
	{
		dialog_default_button_cancel,
		dialog_default_button_install,
		dialog_default_button_skip
	};

	DialogDefaultButton wstring2button(const std::wstring&);
}


