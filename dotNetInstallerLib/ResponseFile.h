#pragma once

enum ResponseFileFormat {
	ResponseFileFormatNone,
	ResponseFileFormatText,
	ResponseFileFormatIni
};

class ResponseFile
{
protected:
	std::wstring source;
	std::wstring target;
public:
	static ResponseFileFormat string2responsefileformat(const std::wstring& format);
	ResponseFile(const std::wstring& s, const std::wstring& t);
	virtual void Exec() = 0;
};

typedef shared_any<ResponseFile *, close_delete> ResponseFilePtr;
