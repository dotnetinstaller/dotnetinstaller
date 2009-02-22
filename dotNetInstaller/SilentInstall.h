#pragma once

// Matthew Sheets - 2007-09-20: Support silent installs

class SilentInstall
{
public:
	SilentInstall(void);
	~SilentInstall(void);

	void EnableSilentInstall()
	{
		m_EnableSilentInstall = true;
	}

	void DisableSilentInstall()
	{
		m_EnableSilentInstall = false;
	}

	// Force a non-silent install, overriding the config file value
	void OverrideSilentInstall()
	{
		m_OverrideSilentInstall = true;
	}

	// Cancel the forcing of a non-silent install
	void OverrideSilentInstallCancel()
	{
		m_OverrideSilentInstall = false;
	}

	bool IsSilent()
	{
		return (m_EnableSilentInstall && (!m_OverrideSilentInstall));
	}

private:
	bool m_EnableSilentInstall;
	bool m_OverrideSilentInstall;
};

extern SilentInstall QuietInstall;
