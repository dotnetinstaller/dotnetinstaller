#pragma once

// install sequence
enum InstallSequence
{
	SequenceInstall = 0, // not set/install
	SequenceUninstall, // uninstall
};

namespace InstallSequenceUtil
{
	// convert to string
	std::wstring towstring(InstallSequence sequence);
}

class InstallSequenceState
{
private:
	InstallSequence m_sequence;
public:
	InstallSequenceState();
	InstallSequenceState(InstallSequence sequence);
	virtual ~InstallSequenceState();
};

