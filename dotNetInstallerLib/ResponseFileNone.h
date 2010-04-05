#pragma once

#include "ResponseFile.h"

class ResponseFileNone : public ResponseFile
{
public:
	ResponseFileNone(const std::wstring& s, const std::wstring& t);
	void Exec();
};
