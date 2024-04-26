#include <iostream>
#include "Log.h"

using namespace std;

int main()
{
	int a = 8;
	int b = 5;

	int* ptr = &a;
	*ptr = 2;

	ptr = &b;
	*ptr = 45;

	cout << a << endl;
	cout << b << endl;
}