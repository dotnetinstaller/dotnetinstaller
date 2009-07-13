#pragma once

#include "FileAttribute.h"

typedef shared_any<FileAttribute *, close_delete> FileAttributePtr;
typedef std::map<std::wstring, FileAttributePtr> FileAttributeMap;

class FileAttributes : private FileAttributeMap
{
public:
	size_t size() const { return FileAttributeMap::size(); }
	FileAttributePtr& operator[](const std::wstring& name);
	FileAttributes();
	virtual ~FileAttributes();
	virtual void Load(TiXmlElement * node);
};

