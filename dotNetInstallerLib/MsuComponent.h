#pragma once
#include "ProcessComponent.h"

class MsuComponent : public ProcessComponent
{
public:
    MsuComponent();
public:
	XmlAttribute package;
	XmlAttribute cmdparameters;
    XmlAttribute cmdparameters_silent;
	XmlAttribute cmdparameters_basic;
	void Exec();
	void Load(TiXmlElement * node);
	void Wait(DWORD tt = 1000);
};

typedef shared_any<MsuComponent *, close_delete> MsuComponentPtr;
