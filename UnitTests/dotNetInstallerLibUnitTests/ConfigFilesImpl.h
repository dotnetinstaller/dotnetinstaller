#pragma once

namespace DVLib
{
	namespace UnitTests
	{
		class ConfigFilesImpl : public ConfigFiles
		{
		private:
			std::wstring m_configfile;
			bool m_loaded;
			long m_runs;
			long m_downloads;
			LanguageSelection m_langselection;
		public:
			bool IsLoaded() const { return m_loaded; }
			ConfigFilesImpl(const std::wstring& configfile = L"");
			bool OnLoad();
			bool OnVersionError(const std::wstring& version, const std::wstring& filename);
			bool OnDownload(const ConfigurationPtr& config);
			bool OnRunConfiguration(const ConfigurationPtr& configuration);
			int GetRuns() const { return m_runs; }
			int GetDownloads() const { return m_downloads; }
			void SetLanguageSelectionCancelled() { m_langselection = LanguageSelection_Cancel; }
			LanguageSelection OnSelectLanguage() { return m_langselection; }
		};
	}
}


