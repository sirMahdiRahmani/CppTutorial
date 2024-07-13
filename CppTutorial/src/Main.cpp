#include <iostream>
#include "Timer.h"

int main()
{
	Timer timer;
	int* Array = new int[5]; // defining single dimensional array of five pointer to integers

	int** Array2D = new int*[5]; // defining 2 dimensional array of five pointer to pointer to integer

	for (int i = 0; i < 5; i++)
	{
		Array2D[i] = new int[5]; // initialize the pointer to the array of five pointer to integers
		for (int j = 0; j < 5; j++) 
		{
			Array2D[i][j] = 2;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		delete[] Array2D[i];
	}
	delete[] Array2D;
}
