#include "stdafx.h"
#include "DniMessageBox.h"

void CALLBACK CloseMessageBox(HWND /*p_hwnd*/, UINT /*p_uiMsg*/, UINT /*p_idEvent*/, DWORD /*p_dwTime*/)
{
	HWND hwnd = FindWindow(NULL, AfxGetApp()->m_pszAppName);
	if (hwnd != NULL)
	{
		EndDialog(hwnd, 0xFFFFFF);
	}
}

int DniMessageBox::Show(const std::wstring& p_lpszText, UINT p_nType /*=MB_OK*/, UINT p_nDefaultResult /*=MB_OK*/, UINT p_nIDHelp /*=0*/, UINT p_nTime)
{
	int result = p_nDefaultResult;
	switch(CurrentInstallUILevel.GetUILevel())
	{
	// basic UI, dialogs appear and disappear
	case InstallUILevelBasic:
		{
			UINT_PTR timer = SetTimer(NULL, 0, p_nTime, (TIMERPROC) CloseMessageBox);
			CHECK_BOOL(timer != NULL, L"Error setting message box timer");
			result = AfxMessageBox(p_lpszText.c_str(), p_nType, p_nIDHelp);
			if (result == 0xFFFFFF) result = p_nDefaultResult;
			KillTimer(NULL, timer);
		}
		break;

	// silent, no UI
	case InstallUILevelSilent:
		result = p_nDefaultResult;
		break;

	// full UI
	case InstallUILevelFull:
	default:
		result = AfxMessageBox(p_lpszText.c_str(), p_nType, p_nIDHelp);
		break;
	}

	return result;
}
