#pragma once

class FileAttribute
{
public:
	std::wstring name;
	std::wstring value;
public:
	FileAttribute();
	virtual void Load(TiXmlElement * node);
};

