#include "pch.h"


class Random
{
public:
	static Random& Get()
	{
		static Random s_Instance;
		return s_Instance;
	}

	float Float()
	{
		return RandomNumber;
	}
private:
	float RandomNumber = 0.4f;
	Random() {};
};

int main()
{
	Instrumentor::Get().BeginSession("Main"); // Start Instumentor to create file and start time
	Random& random = Random::Get();
	std::cout << random.Float();
	Instrumentor::Get().EndSession();         // Stop Instumentor to Ending file and stop time
}
