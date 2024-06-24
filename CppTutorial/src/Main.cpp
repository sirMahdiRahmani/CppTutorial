#include <iostream>

struct Values
{
	float ValueX, ValueY;
};

float X, Y;

static Values ReturnValues()
{
	X = 1;
	Y = 5;

	return { X, Y };
}


int main()
{
	Values values = ReturnValues();
	std::cout << values.ValueX << std::endl;
}
