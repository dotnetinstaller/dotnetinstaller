#pragma once

class Wow64NativeFS
{
private:
	LPVOID wow64_fs_redirection_old;
	bool disabled;
public:
	bool IsDisabled();
	Wow64NativeFS();
	~Wow64NativeFS();
};

typedef shared_any<Wow64NativeFS *, close_delete> Wow64NativeFSPtr;
