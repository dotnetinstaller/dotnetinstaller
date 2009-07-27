#include "StdAfx.h"
#include "ConfigFilesImpl.h"

using namespace DVLib::UnitTests;

ConfigFilesImpl::ConfigFilesImpl(const std::wstring& configfile)
	: m_configfile(configfile)
	, m_loaded(false)
	, m_runs(0)
	, m_downloads(0)
{
}

bool ConfigFilesImpl::OnLoad()
{
	std::wcout << std::endl << L"ConfigFilesImpl::OnLoad(" << m_configfile << L") ...";
	if (! m_configfile.empty())
	{
		config.LoadFile(m_configfile);
		m_loaded = true;
		return true;
	}
	else
	{
		// nothing loaded
		return false;
	}
}

bool ConfigFilesImpl::OnVersionError(const std::wstring& version, const std::wstring& filename)
{
	std::wcout << std::endl << L"ConfigFilesImpl::OnVersionError: version '" << version << L"' mismatch in '" << filename << L"'";
	return true; // ignore mismatch
}

bool ConfigFilesImpl::OnDownload(const ConfigurationPtr& config)
{
	std::wcout << std::endl << L"ConfigFilesImpl::OnDownload(" << config->type << L") ...";
	InterlockedIncrement(& m_downloads);
	return false; // nothing downloaded
}

bool ConfigFilesImpl::OnRunConfiguration(const ConfigurationPtr& config)
{
	std::wcout << std::endl << L"ConfigFilesImpl::OnRunConfiguration(" << config->type << L") ...";
	InterlockedIncrement(& m_runs);
	return true;
}

