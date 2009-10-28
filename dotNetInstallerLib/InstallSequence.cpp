#include "StdAfx.h"
#include "InstallSequence.h"
#include "InstallerSession.h"

InstallSequenceState::InstallSequenceState()
	: m_sequence(InstallerSession::Instance->sequence)
{

}

InstallSequenceState::InstallSequenceState(InstallSequence sequence)
	: m_sequence(InstallerSession::Instance->sequence)
{
	InstallerSession::Instance->sequence = sequence;
}

InstallSequenceState::~InstallSequenceState()
{
	InstallerSession::Instance->sequence = m_sequence;
}

std::wstring InstallSequenceUtil::towstring(InstallSequence sequence)
{
	switch(sequence)
	{
	case SequenceInstall:
		return L"install";
	case SequenceUninstall:
		return L"uninstall";
	default:
		THROW_EX(L"Unsupported install sequence: " << InstallerSession::Instance->sequence << L".");
	}
}