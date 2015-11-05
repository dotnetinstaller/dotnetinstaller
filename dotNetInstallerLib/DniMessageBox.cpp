#include "stdafx.h"
#include "DniMessageBox.h"
#include "InstallUILevel.h"

HWND g_hMessageBox = NULL;
HHOOK g_hHook = NULL;

UINT MessageBoxCloseThreadProc(LPVOID msTilAutoClose)
{
	Sleep((DWORD) msTilAutoClose);
	if (IsWindow(g_hMessageBox))
	{
		EndDialog(g_hMessageBox, 0xFFFFFF);
		g_hMessageBox = NULL;
	}
	return 0;
}

LRESULT CALLBACK CBTProc(int nCode, WPARAM wParam, LPARAM /* lParam */)
{
	if (HCBT_CREATEWND == nCode)
	{
		// the first window to be created is the message box itself.
		g_hMessageBox = reinterpret_cast<HWND>(wParam);
		CHECK_WIN32_BOOL(::UnhookWindowsHookEx(g_hHook),
			L"Error in UnhookWindowsHookEx");
		g_hHook = NULL;
		ASSERT(IsWindow(g_hMessageBox));
		CHECK_WIN32_BOOL(NULL != AfxBeginThread(MessageBoxCloseThreadProc, (LPVOID) 2500),
			L"Error starting timeout thread");
	}

	return 0;
}

int DniMessageBox::Show(const std::wstring& p_lpszText, UINT p_nType /*=MB_OK*/, UINT p_nDefaultResult /*=MB_OK*/, UINT p_nIDHelp /*=0*/)
{
	int result = p_nDefaultResult;
	switch(InstallUILevelSetting::Instance->GetUILevel())
	{
	// basic UI, dialogs appear and disappear
	case InstallUILevelBasic:
		{
			g_hHook = SetWindowsHookEx(WH_CBT, CBTProc, NULL, GetCurrentThreadId());
			CHECK_WIN32_BOOL(NULL != g_hHook, L"Error setting CBT hook");
			result = AfxMessageBox(p_lpszText.c_str(), p_nType, p_nIDHelp);
			CHECK_BOOL(0 != result, L"Not enough memory to display the message box.");
			if (result == 0xFFFFFF) result = p_nDefaultResult;
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
