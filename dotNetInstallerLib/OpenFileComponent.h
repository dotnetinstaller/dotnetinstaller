#pragma once
#include "Component.h"

class OpenFileComponent : public Component
{
private:
	int m_rc;
public:
    OpenFileComponent();
public:
	std::wstring file; //file to open. Can be a web link or a standard file
	void Exec();
	bool IsExecuting() const;
	void Load(TiXmlElement * node);
	int GetExitCode() const;
};

typedef shared_any<OpenFileComponent *, close_delete> OpenFileComponentPtr;
