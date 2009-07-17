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

std::vector< ComponentPtr > Components::GetSupportedComponents(DVLib::LcidType lcidtype) const
{
	std::vector<ComponentPtr> result;
	for each (const ComponentPtr& component in * this)
	{
		bool supported = component->IsSupported(lcidtype);
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
