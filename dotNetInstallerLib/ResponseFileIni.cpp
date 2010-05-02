#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ResponseFile.h"
#include "ResponseFileIni.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

ResponseFileIni::ResponseFileIni(const std::wstring& s, const std::wstring& t)
	: ResponseFile(s, t)
{

}

void ResponseFileIni::Exec()
{
	std::vector<char> data = DVLib::FileReadToEnd(source);
	std::string data_s(data.begin(), data.end());
	std::vector<std::string> lines = DVLib::split(data_s, "\r\n");
	for(size_t i = 0; i < lines.size(); i++)
	{
		std::vector<std::string> parts = DVLib::split(lines[i], "=", 2);
		if (parts.size() == 2) 
		{
			lines[i] = parts[0] + "=" + DVLib::wstring2string(InstallerSession::Instance->ExpandVariables(
				DVLib::string2wstring(parts[1])));
		}
	}
	
	std::string data_out = DVLib::join(lines, "\r\n");
	std::vector<char> data_out_c(data_out.begin(), data_out.end());
	DVLib::FileWrite(target, data_out_c);
}