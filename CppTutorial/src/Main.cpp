#include "pch.h"

namespace BenchMark
{
	void Function1()
	{
		PROFILE_FUNCTION();

		for (int i = 0; i < 10000; i++)
		{
			std::cout << "Hello\n";
		}
	}
	void Function2()
	{
		PROFILE_FUNCTION();

		for (int i = 0; i < 10000; i++)
		{
			std::cout << "Hello\n";
		}
	}

	void RunBenchMark()
	{
		PROFILE_FUNCTION();
		std::cout << "Run Bench\n";
		Function1();
		Function2();
	}
}


int main()
{
	Instrumentor::Get().BeginSession("Main"); // Start Instumentor to create file and start time

	BenchMark::RunBenchMark();
	
	Instrumentor::Get().EndSession(); // Stop Instumentor to Ending file and stop time
}

