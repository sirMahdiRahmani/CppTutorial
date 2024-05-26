#include <iostream>
#include <array>
#include <string>

using namespace std;

class Entity
{
public:
	static const int sizeNumbers = 6;
	int numbers[sizeNumbers];
	int size = sizeNumbers;
	const char* Name;

	Entity(const char* name) : Name(name)
	{
		for (int i = 0; i < sizeNumbers; i++)
		{
			numbers[i] = 0;
		}
	}

	void GetName()
	{
		cout << Name << endl;
	}


};


int main()
{
	const Entity* entityPtr;
	{
		Entity* entity = new Entity("Mahdi");
		entityPtr = entity;
		entity->GetName();
		delete entity;
	}

	cin.get();
}