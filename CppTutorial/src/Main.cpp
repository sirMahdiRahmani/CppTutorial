#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
using namespace std;



struct Vertex
{
	float X, Y, Z;

	Vertex(float x, float y, float z)
		: X(x), Y(y), Z(z) {}

	Vertex(const Vertex& vert)
		: X(vert.X), Y(vert.Y), Z(vert.Z)
	{
		static int counter = 0;
		cout << "Coopied!" << endl;
		counter++;
		cout << counter << endl;
	}
};

ostream& operator<<(ostream& stream, Vertex& v)
{
	stream << v.X << ", " << v.Y << ", " << v.Z;
	return stream;
}

int main()
{
	
	int a = glfwInit();
	cout << a << endl;
	cin.get();
}