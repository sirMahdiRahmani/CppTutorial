#include "pch.h"

int main()
{
	int size;
	int* index = new int;
	std::cin >> size;

	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> *index;
		array[i] = int(*index);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		std::cout << array[i] << " ";
	}
	delete[] array;

}
