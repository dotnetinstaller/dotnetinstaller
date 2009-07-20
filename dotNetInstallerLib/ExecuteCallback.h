#pragma once

class IExecuteCallback
{
public:
	// component execution begins
	virtual bool OnComponentExecBegin(const ComponentPtr&) = 0;
	// component execution is in progress
	virtual bool OnComponentExecWait(const ComponentPtr&) = 0;
	// component execution succeeded, return true to continue execution
	virtual bool OnComponentExecSuccess(const ComponentPtr& component) = 0;
	// component execution failed, return true to continue execution
	virtual bool OnComponentExecError(const ComponentPtr& component, std::exception& ex) = 0;
};
