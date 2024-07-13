#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>


int main()
{
	std::vector<int> vector = { 4,2,1,3,5 };

	std::sort(vector.begin(), vector.end(), [](int a, int b) { return a > b; });

	for (int value : vector)
	{
		std::cout << value << std::endl;
	}
}
