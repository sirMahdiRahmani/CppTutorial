#include "pch.h"

#define PROFILING 1

#if PROFILING

#define PROFILE_SCOPE(name) InstrumentationTimer timer ##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)

#else

#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)

#endif


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
	Instrumentor::Get().BeginSession("Main");
	BenchMark::RunBenchMark();
	Instrumentor::Get().EndSession();
}

