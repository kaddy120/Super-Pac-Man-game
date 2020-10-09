#include "Clock.h"

Clock::Clock()
{
	StartTime = std::chrono::steady_clock::now();
}
void Clock::Reset()
{
	StartTime = std::chrono::steady_clock::now();
}

float Clock::TimeLapse()
{
	Now = std::chrono::steady_clock::now();
	std::chrono::duration<float> elapsed_seconds = Now - StartTime;
	return elapsed_seconds.count();
}