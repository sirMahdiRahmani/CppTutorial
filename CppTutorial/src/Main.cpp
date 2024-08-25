#include "pch.h"

struct AllocationMetrics // struct for allocation metrics with a method to calculate
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;

	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics; // create static instance of Allocation Metrics

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

void PrintMemoryUsage() // Create a Function to call for getting memory usage
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " Bytes\n";
}


int main()
{
	{
		PrintMemoryUsage();
		std::unique_ptr<std::string> nameUnq = std::make_unique<std::string>("Mahdi");
		PrintMemoryUsage();
	}
	PrintMemoryUsage();
	std::string name = "Mahdi";
	PrintMemoryUsage();
}
