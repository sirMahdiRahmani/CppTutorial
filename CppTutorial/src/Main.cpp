#include "pch.h"

struct Vector2
{
	float x, y;
};

int main()
{
	{
		std::cout << "Shared Pointers\n";
		std::array<std::shared_ptr<Vector2>, 1000> SharedPtrs;
		Timer timer;
		for (int i = 0; i < SharedPtrs.size(); i++)
		{
			SharedPtrs[i] = std::make_shared<Vector2>();
		}
	}

	{
		std::cout << "Shared Pointers with New\n";
		std::array<std::shared_ptr<Vector2>, 1000> SharedPtrs2;
		
		Timer timer; // start to measure from here
		for (int i = 0; i < SharedPtrs2.size(); i++)
		{
			SharedPtrs2[i] = std::shared_ptr<Vector2>(new Vector2());
		} // destruct the timer and calc the taken time
	}

	{
		std::cout << "Unique Pointers\n";

		std::array<std::unique_ptr<Vector2>, 1000> UniquePtrs;
		Timer timer;
		for (int i = 0; i < UniquePtrs.size(); i++)
		{
			UniquePtrs[i] = std::make_unique<Vector2>();
		}
	}
}
