#pragma once

#include "ResponseFile.h"

class ResponseFileText : public ResponseFile
{
public:
	ResponseFileText(const std::wstring& s, const std::wstring& t);
	void Exec();
};
