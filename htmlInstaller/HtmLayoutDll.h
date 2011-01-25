#pragma once

class HtmLayoutDll
{
private:
	HMODULE m_h;
	std::wstring m_dir;
	std::wstring m_path;
	void Load();
	void Extract();
	void Unload();
public:
	static shared_any<HtmLayoutDll *, close_delete> Instance;
	HtmLayoutDll(void);
	~HtmLayoutDll(void);
};
