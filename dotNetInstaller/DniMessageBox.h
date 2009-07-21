#pragma once

namespace DniMessageBox
{
	// a message box that depends on the current UI level
	int Show(
		const std::wstring& p_lpszText, 
		UINT p_nType = MB_OK, 
		UINT p_nDefaultResult = MB_OK, 
		UINT p_nIDHelp = 0,
		UINT p_nTimer = 3000);
};
