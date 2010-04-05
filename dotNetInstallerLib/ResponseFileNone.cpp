#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ResponseFile.h"
#include "ResponseFileNone.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

ResponseFileNone::ResponseFileNone(const std::wstring& s, const std::wstring& t)
	: ResponseFile(s, t)
{

}

void ResponseFileNone::Exec()
{
	DVLib::FileCopy(source, target);
}