#pragma once
#include <tinyxml2.h>

class Schema
{
public:
	std::wstring version;
	std::wstring generator;
public:
	Schema();
	virtual void Load(tinyxml2::XMLElement * node);
};

