#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ResponseFile.h"
#include "ResponseFileText.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

ResponseFileText::ResponseFileText(const std::wstring& s, const std::wstring& t)
	: ResponseFile(s, t)
{

}

void ResponseFileText::Exec()
{
	std::vector<char> data = DVLib::FileReadToEnd(source);
	std::string data_s(data.begin(), data.end());
	std::string data_out = DVLib::wstring2string(InstallerSession::Instance->ExpandVariables(DVLib::string2wstring(data_s)));
	std::vector<char> data_out_c(data_out.begin(), data_out.end());
	DVLib::FileWrite(target, data_out_c);
}