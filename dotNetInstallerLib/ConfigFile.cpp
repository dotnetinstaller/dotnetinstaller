#include "stdafx.h"
#include "ConfigFile.h"
#include <Version/Version.h>
#include "InstallerLog.h"

ConfigFile::ConfigFile()
{

}

void ConfigFile::LoadFile(const std::wstring& filename)
{
	LOG(L"Loading configuration file: " << filename);
	std::vector<char> xml = DVLib::FileReadToEnd(filename);
	LOG(L"Parsing: " << DVLib::FormatBytesW(xml.size()));
	if (xml.size() == 0) THROW_EX(L"Error loading file: " << filename << L", file is empty");
	m_XmlDocument.Parse(& * xml.begin());
	CHECK_BOOL(! m_XmlDocument.Error(),
		L"Error loading configuration: " << DVLib::string2wstring(m_XmlDocument.ErrorDesc()));
	Load(m_XmlDocument.FirstChildElement());
}

void ConfigFile::LoadResource(HMODULE h, const std::wstring& res_name, const std::wstring& res_type)
{
	std::vector<char> data = DVLib::LoadResourceData<char>(h, res_name, res_type);
	m_XmlDocument.Parse(& * data.begin());
	CHECK_BOOL(! m_XmlDocument.Error(),
		L"Error parsing '" << res_name << L" resource: " << DVLib::string2wstring(m_XmlDocument.ErrorDesc()));
	LOG(L"Loaded configuration from embedded resource '" << res_name << L"'");
	Load(m_XmlDocument.FirstChildElement());
}
