#pragma once

class ComponentsStatus
{
private:
	bool m_all_required;
	bool m_all_optional;
	bool m_all_checked;
public:
	bool all_required() const { return m_all_required; }
	bool all_optional() const { return m_all_optional; }
	bool all_checked() const { return m_all_checked; }
	bool all() const { return all_required() && all_optional(); }
	void add_required(bool value);
	void add_optional(bool value);
	void add_checked(bool value);
	ComponentsStatus();
	ComponentsStatus(const ComponentsStatus&);
	ComponentsStatus& operator=(const ComponentsStatus&);
};
