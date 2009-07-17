#pragma once

#include "Component.h"

class Components : private std::vector<ComponentPtr>
{
private:
	std::map<std::wstring, ComponentPtr> components_map;
public:
	Components();
	// size of the components collection
	size_t size() const { return std::vector<ComponentPtr>::size(); }
	// add a component to the collection
	void add(const ComponentPtr& component);
	// returns whether the collection contains a component by this name
	bool contains(const std::wstring& description) const;
	// returns components that match current platform and processor architecture
	std::vector< ComponentPtr > GetSupportedComponents(DVLib::LcidType lcidtype) const;
	// reference
	const_reference operator[](size_type pos) const { return std::vector<ComponentPtr>::operator[](pos); }
};
