#include "pch.h"
#include "Timer.h"

Timer::Timer()
{
	Timer::startPoint = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
	Timer::endPoint = std::chrono::high_resolution_clock::now();

	auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startPoint).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();

	auto duration = end - start;
	double ms = duration * 0.001;
	double s = duration * 0.000001;
	std::cout << s << " Seconds | " << ms << " Miliseconds | " << duration << " Microseconds" << std::endl;
}
