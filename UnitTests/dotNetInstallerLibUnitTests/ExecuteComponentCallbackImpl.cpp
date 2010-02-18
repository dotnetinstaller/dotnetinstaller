#include "StdAfx.h"
#include "ExecuteComponentCallbackImpl.h"

using namespace DVLib::UnitTests;

ExecuteComponentCallbackImpl::ExecuteComponentCallbackImpl()
	: begins(0)
	, waits(0)
	, successes(0)
	, errors(0)
{
}

bool ExecuteComponentCallbackImpl::OnComponentExecBegin(const ComponentPtr& component)
{
	::InterlockedIncrement(& begins);
	std::wcout << std::endl << L"Executing '" << component->id << L"' (" << component->GetDisplayName() << L")";
	return true;
}

bool ExecuteComponentCallbackImpl::OnComponentExecWait(const ComponentPtr& component)
{
	::InterlockedIncrement(& waits);
	std::wcout << std::endl << L"Waiting for '" << component->id << L"' (" << component->GetDisplayName() << L")";
	return true;
}

bool ExecuteComponentCallbackImpl::OnComponentExecSuccess(const ComponentPtr& component)
{
	::InterlockedIncrement(& successes);
	std::wcout << std::endl << L"Successfully executed '" << component->id << L"' (" << component->GetDisplayName() << L")";
	return true;
}

bool ExecuteComponentCallbackImpl::OnComponentExecError(const ComponentPtr& component, std::exception& ex)
{
	::InterlockedIncrement(& errors);
	std::wcout << std::endl << L"Error executing '" << component->id << L"' (" << component->GetDisplayName() << L"):"
		<< DVLib::string2wstring(ex.what());
	return true;
}

