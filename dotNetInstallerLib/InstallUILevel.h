#pragma once

// UI level for installation

enum InstallUILevel
{
	InstallUILevelNotSet = 0, // not set
	InstallUILevelFull, // full UI mode
	InstallUILevelBasic, // basic UI mode
    InstallUILevelSilent // silent UI mode
};

class InstallUILevelSetting
{
public:
	InstallUILevelSetting();
	void SetConfigLevel(InstallUILevel value);
	void SetRuntimeLevel(InstallUILevel value);
	InstallUILevel GetConfigLevel() const { return m_ConfigLevel; }
	InstallUILevel GetRuntimeLevel() const { return m_RuntimeLevel; }
	bool IsSilent() const; // true if running in any of the silent modes (basic or silent)
	bool IsAnyUI() const; // true if any UI level
	InstallUILevel GetUILevel(InstallUILevel defaultValue = InstallUILevelFull) const; // current combined UI level
	static std::wstring ToString(InstallUILevel value); // UI level as a string
	static InstallUILevel ToUILevel(const std::wstring& level, InstallUILevel defaultValue = InstallUILevelNotSet);
	static shared_any<InstallUILevelSetting *, close_delete> Instance;
	// swap commands per UI level
	std::wstring GetCommand(const std::wstring& full, const std::wstring& basic, const std::wstring& silent) const;
private:
	InstallUILevel m_ConfigLevel;
	InstallUILevel m_RuntimeLevel;
};

class InstallUILevelState
{
private:
	InstallUILevel m_ConfigLevel;
	InstallUILevel m_RuntimeLevel;
public:
	InstallUILevelState();
	virtual ~InstallUILevelState();
};

