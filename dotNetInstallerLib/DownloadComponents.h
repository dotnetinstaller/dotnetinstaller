#pragma once
#include "DownloadComponent.h"
#include "ThreadComponent.h"

class DownloadComponents : public std::vector<DownloadComponentPtr>, public ThreadComponent
{
private:
	IDownloadCallback * callback;
protected:
	int ExecOnThread();
public:
	bool IsCopyRequired() const;
	bool IsDownloadRequired() const;
	DownloadComponents();
	void Load(IDownloadCallback * callback, const std::vector<DownloadComponentInfoPtr>& component_info);
};
