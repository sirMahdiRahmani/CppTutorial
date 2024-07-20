#include "pch.h"

class Entity
{
	virtual void PrintName() {}
};

class Player : public Entity
{};

class Enemy : public Entity
{};

int main()
{
	Entity* player = new Player();
	Entity* enemy = new Enemy();

	Player* p0 = dynamic_cast<Player*>(player); // it will return actuall player pointer and store it.
	Player* p1 = dynamic_cast<Player*>(enemy); // it will return nullptr and is not valid.

	std::cin.get();
}
