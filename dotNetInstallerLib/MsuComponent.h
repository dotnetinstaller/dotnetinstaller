#pragma once
#include "ProcessComponent.h"

class MsuComponent : public ProcessComponent
{
public:
    MsuComponent();
public:
	std::wstring package;
	std::wstring cmdparameters;
    std::wstring cmdparameters_silent;
	std::wstring cmdparameters_basic;
	void Exec();
	void Load(TiXmlElement * node);
};

typedef shared_any<MsuComponent *, close_delete> MsuComponentPtr;
