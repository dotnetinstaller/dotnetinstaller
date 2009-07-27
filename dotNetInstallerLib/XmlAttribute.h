#pragma once

#define XML_ATTRIBUTE(value) \
	InstallerSession::Instance->ExpandVariables(DVLib::UTF8string2wstring(value))