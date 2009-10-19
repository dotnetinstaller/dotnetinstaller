#pragma once

#include "Control.h"

class Controls : private std::vector<ControlPtr>
{
public:
	Controls();
	Controls(const Controls& rhs);
	Controls& operator=(const Controls& rhs);
	// size of the controls collection
	size_t size() const { return std::vector<ControlPtr>::size(); }
	// add a control to the collection
	void add(const ControlPtr& control);
	// reference
	const_reference operator[](size_type pos) const { return std::vector<ControlPtr>::operator[](pos); }
	virtual std::wstring GetString(int indent = 0) const;
};
