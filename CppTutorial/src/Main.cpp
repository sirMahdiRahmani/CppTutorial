#include "pch.h"

template <typename T, size_t S>
class Array
{
public:
	int Size()
	{
		return S;
	}

	T& operator[] (unsigned int index)
	{
		return Data[index];
	}
private:
	T Data[S];
};


int main()
{
	Array<int, 5> myArray;
	int count = 0;
	for (int i = 0; i < myArray.Size(); i++)
	{
		myArray[i] = count++;
		std::cout << myArray[i] << std::endl;
	}
}
