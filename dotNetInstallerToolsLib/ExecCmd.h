#pragma once

namespace DVLib
{
	// ==========================================================================
	// ExecCmd()
	//
	// Purpose:
	//  Executes command-line
	// Inputs:
	//  LPCTSTR pszCmd: command to run
	// Notes: This routine does a CreateProcess on the input cmd-line
	// Outputs:True is succedeed othrwise false
	// ==========================================================================
	inline bool ExecCmd( LPCTSTR pszCmd, PROCESS_INFORMATION * process_info)
	{
		BOOL  bReturnVal   = false ;
		STARTUPINFO  si ;

		ZeroMemory(&si, sizeof(si)) ;
		si.cb = sizeof(si) ;

		// if environment variables are in the string for ExecCmd then replace these variables first.
		// Using ShellExecuteEx API function with setting the flag SEE_MASK_DOENVSUBST does not working in this case
		// because environment variables can also be placed in the parameters for the new process.
		CString expandedCmd = pszCmd;
		CString search;
		CString environment;
		CString replace;
		int startPos = 0;
		int endPos = 0;
		
		while (1)
		{
			// search first %
			startPos = expandedCmd.Find(TEXT("%"), 0);
			if (startPos != -1)
			{
				// search second %
				endPos = expandedCmd.Find(TEXT("%"), startPos + 1);
			}
			else
			{
				// break if not found
				break;
			}
			// second % found and minimum one character between the two % chars?
			if (endPos != -1 && endPos - startPos > 1)
			{
				environment = expandedCmd.Mid(startPos + 1, endPos - startPos - 1);
				search = expandedCmd.Mid(startPos, endPos - startPos + 1);
				replace.GetEnvironmentVariable(environment);
				expandedCmd.Replace(search, replace);
			}
			else
			{
				// break if it not so
				break;
			}
		}
		
		bReturnVal = CreateProcess(NULL, 
								expandedCmd.GetBuffer(expandedCmd.GetLength()), 
								NULL, 
								NULL, 
								FALSE, 
								0, 
								NULL, 
								NULL, 
								&si, 
								process_info) ;

		expandedCmd.ReleaseBuffer();

		if (bReturnVal)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	// ==========================================================================
	// ExecCmd()
	//
	// Purpose:
	//  Executes command-line
	// Inputs:
	//  LPCTSTR pszCmd: command to run
	// p_ExitCodes :  exit code from the command
	// Notes: This routine does a CreateProcess on the input cmd-line
	//        and waits for the launched process to exit.
	// Check ERROR_SUCCESS_REBOOT_REQUIRED a reboot is required.
	// Outputs:True is succedeed othrwise false
	// ==========================================================================
	inline bool ExecCmdAndWait( LPCTSTR pszCmd , DWORD * p_ExitCodes)
	{
		BOOL  bReturnVal   = false ;
		STARTUPINFO  si ;
		DWORD  dwExitCode ;
		SECURITY_ATTRIBUTES saProcess, saThread ;
		PROCESS_INFORMATION process_info ;

		ZeroMemory(&si, sizeof(si)) ;
		si.cb = sizeof(si) ;

		saProcess.nLength = sizeof(saProcess) ;
		saProcess.lpSecurityDescriptor = NULL ;
		saProcess.bInheritHandle = TRUE ;

		saThread.nLength = sizeof(saThread) ;
		saThread.lpSecurityDescriptor = NULL ;
		saThread.bInheritHandle = FALSE ;

		bReturnVal = CreateProcess(NULL, 
								(LPTSTR)pszCmd, 
								&saProcess, 
								&saThread, 
								FALSE, 
								DETACHED_PROCESS, 
								NULL, 
								NULL, 
								&si, 
								&process_info) ;

		if (bReturnVal)
		{
			CloseHandle( process_info.hThread ) ;
			WaitForSingleObject( process_info.hProcess, INFINITE ) ;
			GetExitCodeProcess( process_info.hProcess, &dwExitCode ) ;
			CloseHandle( process_info.hProcess ) ;

			*p_ExitCodes = dwExitCode;
		}
		else
		{
			return false;
		}

		return true;
	}
}