#pragma once

#include "HtmlWindow.h"

class InstallerWindow : public HtmlWindow
{
private:
	int m_recorded_error;
	bool m_reboot;
	bool m_additional_config;
	DVLib::LcidType m_lcidtype;
	ConfigurationPtr m_configuration;
	htmlayout::dom::element components;
public:
	bool RunInstallConfiguration(DVLib::LcidType lcidtype, const ConfigurationPtr& configuration, bool additional_config);
	bool RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration);
	void Create(int x, int y, int width, int height, const wchar_t * caption = 0);
	bool LoadComponentsList();
	void DoModal();
public:
	InstallerWindow();
};
