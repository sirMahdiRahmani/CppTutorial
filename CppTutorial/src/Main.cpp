#include "pch.h"

class Vector
{
public:

	Vector()
	{
		std::cout << "New size of Vector: " << sizeof(VectorData) / sizeof(int) << std::endl;

	}

	void Add(int data)
	{
		if (size <= sizeof(VectorData) / sizeof(int))
		{
			size++;

			VectorTemp = new int[size];

			for (int i = 0; i < sizeof(VectorData) / sizeof(int); i++)
			{
				VectorTemp[i] = VectorData[i];
			}
			VectorTemp[size + 1] = data;
			delete[] VectorData;
			VectorData = new int[size];
			VectorData = VectorTemp;
			delete[] VectorTemp;
		}
	}

	void Reserve(int AddedSize)
	{
		size += AddedSize;

		VectorTemp = new int[size];
		for (int i = 0; i < sizeof(VectorData) / sizeof(int) - 1; i++)
		{
			VectorTemp[i] = VectorData[i];
		}
		delete[] VectorData;
		VectorData = new int[size];
		VectorData = VectorTemp;
		delete[] VectorTemp;

		std::cout << "New size of Vector: " << sizeof(VectorData) / sizeof(int) << std::endl;
	}

private:
	int size = 1;
	int* VectorData = new int[1];
	int* VectorTemp = new int[1];
};


int main()
{
	std::vector<int> ListOfInt;

	ListOfInt.push_back(1);

	ListOfInt.push_back(1);

	std::string* name = new std::string("Mahdi");

	ListOfInt.push_back(2);

}
