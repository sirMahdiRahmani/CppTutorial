#include "pch.h"

class Base
{
public:
	Base()
	{
		std::cout << "Base Constructor\n";
	}

	virtual ~Base()
	{
		std::cout << "Base Destructor\n";
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Derived Constructor\n";
	}

	void PrintHello()
	{
		std::cout << "Hello" << std::endl;
	}

	~Derived()
	{
		std::cout << "Derived Destructor\n";
	}
};

int main()
{
	double numD = 6.56;
	int numI = (int)numD;
	std::cout << numD << " ," << numI << std::endl;
	// Static Casting

	Base* base = new Derived();
	Derived* derived = (Derived*)base;
	// Reinterpret Casting (Type Punnning)

	const int& num = 54;
	int* number = (int*)(&num);
	*number = 89;
	std::cout << num << std::endl;
	// Const Casting

	std::cin.get();
}
