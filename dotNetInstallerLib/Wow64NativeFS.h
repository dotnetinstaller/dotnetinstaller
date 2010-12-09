#pragma once

class Wow64NativeFS
{
private:
	void *wow64_fs_redirection_old;

public:
	Wow64NativeFS(void);
	~Wow64NativeFS(void);
};

typedef shared_any<Wow64NativeFS *, close_delete> Wow64NativeFSPtr;
