#pragma once

#include "FileAttributes.h"
#include "Configurations.h"

class ConfigFile : public Configurations
{
private:
	std::wstring m_filename;
    TiXmlDocument m_XmlDocument;
public:
	ConfigFile();
	void LoadFile(const std::wstring& filename);
	void LoadResource(HINSTANCE h, const std::wstring& res_name, const std::wstring& res_type = L"CUSTOM");
	const std::wstring& GetFilename() const { return m_filename; }
};
