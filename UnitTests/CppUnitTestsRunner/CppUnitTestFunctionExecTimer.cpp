#include "StdAfx.h"

CppUnitTestFunctionExecTimer::CppUnitTestFunctionExecTimer()
: duration(0),
  start(0),
  finish(0)
{	
};    

CppUnitTestFunctionExecTimer::~CppUnitTestFunctionExecTimer()
{	
};

void CppUnitTestFunctionExecTimer::StartTimer()
{ 
	start = clock();
}

void CppUnitTestFunctionExecTimer::StopTimer() 
{ 
	finish = clock();
	duration = (static_cast<double>(finish - start)) / CLOCKS_PER_SEC;
}

double CppUnitTestFunctionExecTimer::GetDuration() const
{
	return duration;
}

double CppUnitTestFunctionExecTimer::TimeElaspedInSeconds() const
{
	return (static_cast<double>(clock() - start) / CLOCKS_PER_SEC);
}

std::string CppUnitTestFunctionExecTimer::ToString(void) const
{
	std::stringstream result;
    result << duration;
    return result.str();
}