#include <iostream>
#include <vector>
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
	~Vertex() 
	{
		cout << "Object Destroyed!" << endl;
	}
};

ostream& operator<<(ostream& stream, Vertex& v)
{
	stream << v.X << ", " << v.Y << ", " << v.Z;
	return stream;
}

int main()
{
	shared_ptr<Vertex> vertex2;
	{
		shared_ptr<Vertex> vertex = make_shared<Vertex>(1,2,4);
		vertex2 = vertex;
	}
	cout << *vertex2 << endl;
	cin.get();
}