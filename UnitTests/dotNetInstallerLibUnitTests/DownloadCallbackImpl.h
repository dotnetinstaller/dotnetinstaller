#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class DownloadCallbackImpl : public IDownloadCallback
		{
		private:
			long m_error;
			long m_complete;
			bool m_cancelled;
			bool m_downloading;
			bool m_copying;
		public:
			DownloadCallbackImpl();
			void Status(ULONG progress_current, ULONG progress_max, const std::wstring& description);
			void DownloadComplete();
			void DownloadError(const std::wstring& message);
			bool IsDownloadCancelled() const { return m_cancelled; }
			void DownloadCancel() { m_cancelled = true; }
			void Connecting();
			void SendingRequest();
			void CopyingFile();
			void DownloadingFile();
			long GetCompleteCount() const { return m_complete; }
			long GetErrorCount() const { return m_error; }
			bool IsDownloading() const { return m_downloading; }
			bool IsCopying() const { return m_copying; }
		};
	}
}