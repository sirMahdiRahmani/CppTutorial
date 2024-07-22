#include "pch.h"

std::tuple<std::string, int> GetNameAge()
{
	return { "Arthur", 38 };
}

int main()
{
	auto [name, age] = GetNameAge();
	std::cout << name << " is " << age << " years Old\n";
}
