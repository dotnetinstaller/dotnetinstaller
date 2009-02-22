#pragma once

// Matthew Sheets - 2007-08-10: Support silent installs

int DniMessageBox(LPCTSTR p_lpszText, UINT p_nType = MB_OK, UINT p_nDefaultResult = MB_OK, UINT p_nIDHelp = 0);

int DniTimedMessageBox(bool p_bTimed, LPCTSTR p_lpszText, UINT p_nType = MB_OK, UINT p_nDefaultResult = MB_OK, UINT p_nIDHelp = 0);

int DniSilentMessageBox(LPCTSTR p_lpszText, UINT p_nType = MB_OK, UINT p_nDefaultResult = MB_OK, UINT p_nIDHelp = 0);


/*
int AFXAPI DniMessageBox(
   UINT nIDPrompt,
   UINT nType = MB_OK,
   UINT nIDHelp = (UINT) -1,
   UINT nDefaultResult = MD_OK
);
*/
