#pragma once

namespace DVLib
{
	namespace UnitTests 
	{
		class DownloadComponentCallbackImpl : public IDownloadCallback
		{
		private:
			long m_error;
			long m_complete;
			bool m_cancelled;
		public:
			DownloadComponentCallbackImpl();
			void Status(ULONG progress_current, ULONG progress_max, const std::wstring& description);
			void DownloadComplete();
			void DownloadError(const std::wstring& message);
			bool IsDownloadCancelled() const { return m_cancelled; }
			void DownloadCancel() { m_cancelled = true; }
			void Connecting();
			void SendingRequest();
			long GetCompleteCount() const { return m_complete; }
			long GetErrorCount() const { return m_error; }
		};
	}
}