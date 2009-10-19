#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ControlLabel.h"
#include "InstallerSession.h"
#include "InstallerLog.h"

ControlLabel::ControlLabel()
	: ControlText(control_type_label)
{

}

void ControlLabel::Load(TiXmlElement * node)
{
	ControlText::Load(node);
	LOG(L"Loaded " << GetString());
}

std::wstring ControlLabel::GetString() const
{
	std::wstringstream ss;
	ss << L"'label' control, " << ControlText::GetString();
	return ss.str();
}
