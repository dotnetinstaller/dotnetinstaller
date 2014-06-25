#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class FindWindow
		{
		public:
			HWND static FindWindowFromProcessId( DWORD dwProcessId );
			HWND static FindWindowFromProcess( HANDLE hProcess );
		};
	}
}