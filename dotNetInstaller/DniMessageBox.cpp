#include "stdafx.h"
#include "DniMessageBox.h"

// support for silent installs
int DniMessageBox(LPCTSTR p_lpszText, UINT p_nType /*=MB_OK*/, UINT p_nDefaultResult /*=MB_OK*/, UINT p_nIDHelp /*=0*/)
{
	// Determine whether to display a message to the end user or just return the default value
	if(CurrentInstallUILevel.IsSilent())
	{
		return p_nDefaultResult;
	}
	else
	{
		return AfxMessageBox(p_lpszText, p_nType, p_nIDHelp);
	}
}


void CALLBACK CloseMessageBox(HWND p_hwnd, UINT p_uiMsg, UINT p_idEvent, DWORD p_dwTime)
{
	HWND hwnd = FindWindow(NULL, AfxGetAppName());
	if (hwnd != NULL)
	{
		EndDialog(hwnd, IDOK);
	}
}


int DniTimedMessageBox(bool p_bTimed, LPCTSTR p_lpszText, UINT p_nType /*=MB_OK*/, UINT p_nDefaultResult /*=MB_OK*/, UINT p_nIDHelp /*=0*/)
{
	int result;
	UINT_PTR idTimer;

	if(p_bTimed)
	{
		DWORD milli = 3500; // timeout
		idTimer = SetTimer(NULL, 0, milli, (TIMERPROC)CloseMessageBox);

		// Display the message box
		result = AfxMessageBox(p_lpszText, p_nType, p_nIDHelp);

		// Cancel the timer & delete the timer queue
		KillTimer(NULL, idTimer);
	}
	else
	{
		result = AfxMessageBox(p_lpszText, p_nType, p_nIDHelp);
	}

	return result;
}

int DniSilentMessageBox(LPCTSTR p_lpszText, UINT p_nType /*=MB_OK*/, UINT p_nDefaultResult /*=MB_OK*/, UINT p_nIDHelp /*=0*/)
{
	return DniTimedMessageBox(CurrentInstallUILevel.IsSilent(), p_lpszText, p_nType, p_nDefaultResult, p_nIDHelp);
}
