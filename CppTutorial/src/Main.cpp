#include "pch.h"

void Function() 
{
	InstrumentationTimer timer("F");

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

