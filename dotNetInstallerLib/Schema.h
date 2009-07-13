#pragma once

class Schema
{
public:
	std::wstring version;
	std::wstring generator;
public:
	Schema();
	virtual void Load(TiXmlElement * node);
};

