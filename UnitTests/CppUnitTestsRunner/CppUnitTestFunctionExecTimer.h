#pragma once

//! A simple TIMER class useful for tracking a call execution time.
class CppUnitTestFunctionExecTimer
{
private:
	double duration;
	clock_t start;
	clock_t finish;
public:
    CppUnitTestFunctionExecTimer();    
	~CppUnitTestFunctionExecTimer();
	void StartTimer( void );
	void StopTimer( void );
	double GetDuration( void ) const;
	double TimeElaspedInSeconds() const;
	std::string ToString( void ) const;
};
