#include "StdAfx.h"
#include "Wow64NativeFS.h"


Wow64NativeFS::Wow64NativeFS(void)
{
	wow64_fs_redirection_old = NULL;
	CHECK_WIN32_BOOL(DVLib::Wow64DisableWow64FsRedirection(&wow64_fs_redirection_old),
		L"DVLib::Wow64DisableWow64FsRedirection");
}

Wow64NativeFS::~Wow64NativeFS(void)
{
	DVLib::Wow64RevertWow64FsRedirection(wow64_fs_redirection_old);
}

