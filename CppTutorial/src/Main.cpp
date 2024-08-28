#include "pch.h"


struct Vector3
{
	float x = 0.0f, y = 0.0f, z = 0.0f;

	Vector3() {}
	Vector3(float scalar)
		: x(scalar), y(scalar), z(scalar) {}
	Vector3(float X, float Y, float Z)
		: x(X), y(Y), z(Z) {}

	Vector3(const Vector3& other)
		: x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Copy Vector3 ----------\n";
	}

	Vector3(Vector3&& other)
		: x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Move Vector3 ----------\n";
	}
	~Vector3()
	{
		std::cout << "Destroy Vector3 ----------\n";
	}

	Vector3& operator=(const Vector3& other)
	{
		std::cout << "Copied\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	Vector3& operator=(Vector3&& other)
	{
		std::cout << "Moved\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
};

int main()
{
	{
		Vector<Vector3> vector;
		vector.EmplaceBack(1.2f);
		vector.PushBack(Vector3(2.0f, 3.4f, 7.0f));
		vector.PushBack(Vector3());

		PrintVector(vector);
		PrintMemoryUsage();
		vector.Clear();
	}
	PrintMemoryUsage();
}
