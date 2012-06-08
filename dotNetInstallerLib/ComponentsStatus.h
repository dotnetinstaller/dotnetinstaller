#pragma once

class ComponentsStatus
{
private:
	bool m_all_required;
	bool m_all_optional;
public:
	bool all_required() const { return m_all_required; }
	bool all_optional() const { return m_all_optional; }
	bool all() const { return all_required() && all_optional(); }
	void add_required(bool value);
	void add_optional(bool value);
	ComponentsStatus();
	ComponentsStatus(const ComponentsStatus&);
	ComponentsStatus& operator=(const ComponentsStatus&);
};
