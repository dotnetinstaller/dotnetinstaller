#include "StdAfx.h"
#include "ComponentsStatus.h"

ComponentsStatus::ComponentsStatus()
	: m_all_required(true)
	, m_all_optional(true)
{

}

ComponentsStatus::ComponentsStatus(const ComponentsStatus& rhs)
{
	operator=(rhs);
}

ComponentsStatus& ComponentsStatus::operator=(const ComponentsStatus& s)
{
	m_all_required = s.all_required();
	m_all_optional = s.all_optional();
	return * this;
}

void ComponentsStatus::add_required(bool value)
{
	m_all_required &= value;
}

void ComponentsStatus::add_optional(bool value)
{
	m_all_optional &= value;
}
