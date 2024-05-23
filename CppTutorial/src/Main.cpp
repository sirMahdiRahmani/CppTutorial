#include <iostream>

using namespace std;


class Actor
{
public:
	int X;
	int Y;
	int Z;

	virtual void Move(int x, int y, int z)
	{
		X += x;
		Y += y;
		Z += z;
	}
};

class Vehicle : public Actor
{
	int Speed;
	void Move(int x, int y, int z) override
	{
		X += x * Speed;
		Y += y * Speed;
		Z += z * Speed;
	}
};

int main()
{
}