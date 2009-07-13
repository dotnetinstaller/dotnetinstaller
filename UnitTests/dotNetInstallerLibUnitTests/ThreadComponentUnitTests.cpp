#include "StdAfx.h"
#include "ThreadComponentUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ThreadComponentUnitTests);

using namespace DVLib::UnitTests;

class ThreadComponentImpl : public ThreadComponent
{
private:
	int m_exitcode;
public:
	ThreadComponentImpl(int exitcode);
	UINT ExecOnThread() { return m_exitcode; }
};

ThreadComponentImpl::ThreadComponentImpl(int exitcode) 
	: ThreadComponent(undefined), 
	m_exitcode(exitcode) 
{ 

}

void ThreadComponentUnitTests::testExec()
{
	ThreadComponentImpl component(0);
	component.Exec();
	CPPUNIT_ASSERT(0 == component.GetExitCode());
}

void ThreadComponentUnitTests::testExecWithError()
{
	ThreadComponentImpl component(123);
	try
	{
		component.Exec();
		throw "expected exception";
	}
	catch(std::exception&)
	{
	}
	CPPUNIT_ASSERT(123 == component.GetExitCode());
}