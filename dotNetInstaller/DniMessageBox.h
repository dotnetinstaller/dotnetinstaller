#pragma once

// support silent installs

int DniMessageBox(const std::wstring& p_lpszText, UINT p_nType = MB_OK, UINT p_nDefaultResult = MB_OK, UINT p_nIDHelp = 0);

int DniTimedMessageBox(bool p_bTimed, const std::wstring& p_lpszText, UINT p_nType = MB_OK, UINT p_nDefaultResult = MB_OK, UINT p_nIDHelp = 0);

int DniSilentMessageBox(const std::wstring& p_lpszText, UINT p_nType = MB_OK, UINT p_nDefaultResult = MB_OK, UINT p_nIDHelp = 0);
