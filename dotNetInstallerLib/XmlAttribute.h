#pragma once

class XmlAttribute
{
private:
	std::wstring value;
public:
	std::wstring GetValue() const;
	bool GetBoolValue(bool defaultvalue) const { return DVLib::wstring2bool(GetValue(), defaultvalue); }
	long GetLongValue() const { return DVLib::wstring2long(GetValue()); }
	XmlAttribute();
	XmlAttribute(const std::wstring& s);
	XmlAttribute(const std::string& s);
	XmlAttribute(const char * psz);
	XmlAttribute(const wchar_t * psz);
	XmlAttribute(const XmlAttribute&);
	XmlAttribute& operator=(const XmlAttribute&);
	XmlAttribute& operator=(const std::wstring&);
	XmlAttribute& operator=(const std::string&);
	XmlAttribute& operator=(const char *);
	XmlAttribute& operator=(const wchar_t *);
	bool empty() const { return value.empty(); }
	bool operator==(const std::wstring& rhs) const { return GetValue() == rhs; }
	bool operator==(const wchar_t * rhs) const { return GetValue() == rhs; }
	bool operator!=(const std::wstring& rhs) const { return GetValue() != rhs; }
	operator std::wstring() const { return GetValue(); }
};

std::wostream& operator<<(std::wostream& os, const XmlAttribute& attr);
