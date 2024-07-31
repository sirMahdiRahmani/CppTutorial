#include "pch.h"

int main() {
	std::variant<int, float, std::string> myVariant;

	myVariant = 42;
	std::cout << "Holds int: " << std::get<int>(myVariant) << std::endl;

	myVariant = 3.14f;
	std::cout << "Holds float: " << std::get<float>(myVariant) << std::endl;

	myVariant = "Hello";
	std::cout << "Holds string: " << std::get<std::string>(myVariant) << std::endl;

	// Using std::visit to handle the current value
	std::visit([](auto&& arg)
		{
			std::cout << "Current value: " << arg << std::endl;
		}, myVariant);

	return 0;
}