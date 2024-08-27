#include "pch.h"

int main()
{
	myArray<int, 6> array;
	int count = 0;
	for (int i = 0; i < array.Size(); i++)
	{
		array[i] = count++;
		std::cout << array[i] << std::endl;
	}
}
