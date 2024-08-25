#include "pch.h"


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
