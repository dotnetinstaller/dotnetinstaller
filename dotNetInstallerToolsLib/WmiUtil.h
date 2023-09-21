#pragma once

#include <Wbemidl.h>

namespace DVLib
{
	class WmiUtil
	{
	public:
		static bool Any(const std::wstring& query);
		static std::wstring Get(const std::wstring& query, const std::wstring& propertyName);
	private:
		static ULONG FirstOrNull(const std::wstring& query, IWbemClassObject*& pclsObj);
	};
}