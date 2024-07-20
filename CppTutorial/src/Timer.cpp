#include "pch.h"
#include "Timer.h"

Timer::Timer()
{
	Timer::start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
	Timer::end = std::chrono::high_resolution_clock::now();
	Timer::duration = end - start;
	std::cout << "Execution time: " << Timer::duration.count() << " seconds." << std::endl;
}
