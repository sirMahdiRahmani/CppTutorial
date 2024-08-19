#include "pch.h"

#define PROFILING 1

#if PROFILING

#define PROFILE_SCOPE(name) InstrumentationTimer timer ##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)

#else

#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)

#endif

void Function() 
{
	PROFILE_FUNCTION();

	for (int i = 0; i < 100; i++) 
	{
		std::cout << "Hello\n";
	}
}

int main() 
{	
	Instrumentor::Get().BeginSession("Main");
	Function();
	Instrumentor::Get().EndSession();

	

}

