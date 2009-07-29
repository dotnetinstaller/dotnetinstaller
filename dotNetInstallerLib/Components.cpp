#include "StdAfx.h"
#include "Components.h"
#include "InstallerLog.h"

Components::Components()
{
}

void Components::add(const ComponentPtr& component)
{
    components_map.insert(std::make_pair(component->description, component));
    push_back(component);
}

bool Components::contains(const std::wstring& description) const
{
	return components_map.find(description) != components_map.end();
}

Components::Components(const Components& rhs)
{
	operator=(rhs);
}

Components& Components::operator=(const Components& rhs)
{
	components_map = rhs.components_map;
	std::vector<ComponentPtr>::operator=(rhs);
	return * this;
}

Components Components::GetSupportedComponents(DWORD oslcid) const
{
	Components result;
	for each (const ComponentPtr& component in * this)
	{
		bool supported = component->IsSupported(oslcid);
		if (supported)
		{
			result.push_back(component);
		}

		LOG(L"-- " << component->description << L" (os_filter_lcid=" << component->os_filter_lcid
			<< L", os_filter_greater=" << component->os_filter_greater
			<< L", os_filter_smaller=" << component->os_filter_smaller
			<< L", processor_architecture_filter=" << component->processor_architecture_filter
			<< L"): " << (supported ? L"LOADED" : L"SKIPPED"));
	}

	LOG(L"--- Loaded " << result.size() << L" supported component(s)");
	return result;
}

int Components::Exec(IExecuteCallback * callback)
{
	int rc = 0;
	for each(const ComponentPtr& component in * this)
	{
		if (! component->selected)
		{
			LOG(L"--- Component '" << component->description << L"': SKIPPED");
			continue;
		}

		try
		{
			LOG(L"--- Component '" << component->description << L"': EXECUTING");
			
			if (callback && ! callback->OnComponentExecBegin(component))
				break;

			component->Exec();
			
			if (callback && ! callback->OnComponentExecWait(component))
				break;

			component->Wait();

			LOG(L"*** Component '" << component->description << L"': SUCCESS");

			if (callback && ! callback->OnComponentExecSuccess(component))
				break;
		}
		catch(std::exception& ex)
		{
			if (rc == 0) rc = component->GetExitCode();
			if (rc == 0) rc = -1;

			LOG(L"*** Component '" << component->description << L"' ERROR: " << DVLib::string2wstring(ex.what()));
			
			if (callback && ! callback->OnComponentExecError(component, ex))
				break;
		}
	}

	return rc;
}
