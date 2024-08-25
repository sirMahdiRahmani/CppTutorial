#pragma once

#include "pch.h"

struct AllocationMetrics // struct for allocation metrics with a method to calculate
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;

	uint32_t CurrentUsage();
};

static AllocationMetrics s_AllocationMetrics; // create static instance of Allocation Metrics

void* operator new(size_t size);

void operator delete (void* memory, size_t size);

void PrintMemoryUsage();
