#include "StdAfx.h"
#include "XmlAttribute.h"
#include "InstallerSession.h"

XmlAttribute::XmlAttribute()
{
}

XmlAttribute::XmlAttribute(const std::string& s)
{
	operator=(s);
}

std::wstring XmlAttribute::GetValue() const
{
	return InstallerSession::Instance->ExpandVariables(value);
}

XmlAttribute::XmlAttribute(const XmlAttribute& rhs)
{
	operator=(rhs);
}

XmlAttribute::XmlAttribute(const std::wstring& s)
{
	operator=(s);
}

XmlAttribute::XmlAttribute(const char * psz)
{
	operator=(psz);
}

XmlAttribute::XmlAttribute(const wchar_t * psz)
{
	operator=(psz);
}

XmlAttribute& XmlAttribute::operator=(const XmlAttribute& rhs)
{
	value = rhs.value;
	return * this;
}

XmlAttribute& XmlAttribute::operator=(const char * rhs)
{
	value = DVLib::UTF8string2wstring(rhs);
	return * this;
}

XmlAttribute& XmlAttribute::operator=(const wchar_t * rhs)
{
	value = rhs;
	return * this;
}

XmlAttribute& XmlAttribute::operator=(const std::string& s)
{
	value = DVLib::UTF8string2wstring(s);
	return * this;
}

XmlAttribute& XmlAttribute::operator=(const std::wstring& s)
{
	value = s;
	return * this;
}

std::wostream& operator<<(std::wostream& os, const XmlAttribute& attr)
{
	os << attr.GetValue();
	return os;
}
