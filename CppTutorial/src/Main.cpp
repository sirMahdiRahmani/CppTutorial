#include "pch.h"

struct Vector2
{
	float x, y;
};



int main()
{
	std::vector<int*> SharedPtrs;
	SharedPtrs.reserve(1000000000);
	{
		std::cout << "Shared Pointers\n";
		
		Timer timer;
		for (int i = 0; i < 1000000000; i++)
		{
			SharedPtrs[i] = new int(i);
		}
	}
	std::cout << SharedPtrs[23000] << std::endl;
	/*for (int i = 0; i < SharedPtrs.size(); i++)
	{
		delete SharedPtrs[i];
	}*/
}
