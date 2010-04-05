#pragma once

#include "ResponseFile.h"

class ResponseFileIni : public ResponseFile
{
public:
	ResponseFileIni(const std::wstring& s, const std::wstring& t);
	void Exec();
};
