#include "AllocationMetrics.h"
#include "pch.h"

uint32_t AllocationMetrics::CurrentUsage()
{
	return TotalAllocated - TotalFreed;
}

void* operator new(size_t size)
{
	s_AllocationMetrics.TotalAllocated += size; // add value to allocation Metrics Total Allocated
	std::cout << "Allocating " << size << " Bytes of Memory" << std::endl;
	return malloc(size);
}

void operator delete (void* memory, size_t size)
{
	s_AllocationMetrics.TotalFreed += size; // add value to allocation Metrics Total Freed
	std::cout << "Freeing " << size << " Bytes of Memory" << std::endl;
	return free(memory);
}

void operator delete[] (void* memory, size_t size)
{
	s_AllocationMetrics.TotalFreed += size; // add value to allocation Metrics Total Freed
	std::cout << "Freeing " << size << " Bytes of Memory" << std::endl;
	return free(memory);
}

void PrintMemoryUsage() // Create a Function to call for getting memory usage
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " Bytes\n";
}
