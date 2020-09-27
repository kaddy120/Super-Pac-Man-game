#pragma once
#include <chrono>

class Clock
{
public:
	Clock();
	void Reset();
	float TimeLapse();

private:
	std::chrono::steady_clock::time_point StartTime;
	std::chrono::steady_clock::time_point Now;
};

