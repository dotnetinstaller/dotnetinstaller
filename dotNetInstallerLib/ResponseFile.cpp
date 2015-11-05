#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ResponseFile.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"
#include "ResponseFileText.h"
#include "ResponseFileIni.h"

ResponseFile::ResponseFile(const std::wstring& s, const std::wstring& t)
: source(s)
, target(t)
{

}

ResponseFileFormat ResponseFile::string2responsefileformat(const std::wstring& format) 
{
    if (format == L"none")
        return ResponseFileFormatNone;
    if (format == L"text")
        return ResponseFileFormatText;
    else if (format == L"ini")
        return ResponseFileFormatIni;
    else
    {
        THROW_EX(L"Invalid response file format: " << format);
    }
}
