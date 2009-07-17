#pragma once
#include "Component.h"

class OpenFileComponent : public Component
{
public:
    OpenFileComponent();
public:
	std::wstring file; //file to open. Can be a web link or a standard file
	void Exec();
	DWORD GetExitCode() const;
	bool IsExecuting() const;
	void Load(TiXmlElement * node);
};

typedef shared_any<OpenFileComponent *, close_delete> OpenFileComponentPtr;
