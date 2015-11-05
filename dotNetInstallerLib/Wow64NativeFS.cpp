#include "StdAfx.h"
#include "Wow64NativeFS.h"

Wow64NativeFS::Wow64NativeFS()
: wow64_fs_redirection_old(NULL)
, disabled(false)
{
    disabled = DVLib::Wow64DisableWow64FsRedirection(& wow64_fs_redirection_old);
}

Wow64NativeFS::~Wow64NativeFS()
{
    DVLib::Wow64RevertWow64FsRedirection(wow64_fs_redirection_old);
    wow64_fs_redirection_old = NULL;
    disabled = false;
}

bool Wow64NativeFS::IsDisabled()
{
    return disabled;
}