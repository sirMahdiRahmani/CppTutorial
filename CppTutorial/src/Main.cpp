#include "pch.h"

static uint32_t s_AllocCount = 0;

void* operator new(size_t size)
{
	s_AllocCount++;
	std::cout << "Allocating " << size << " Bytes\n";
	return malloc(size);
}

#define STRING_VIEW 1

#if STRING_VIEW
void printName(std::string_view name) 
{
	std::cout << name << std::endl;
}
#else
void printName(const std::string& name) 
{
	std::cout << name << std::endl;
}
#endif


int main() 
{	
	std::string fullName = "Jurgen Klopp";

#if STRING_VIEW
	std::string_view firstName(fullName.c_str(), 6);
	std::string_view lastName(fullName.c_str() + 7, 5);
#else
	std::string firstName = fullName.substr(0, 6);
	std::string lastName = fullName.substr(7, 5);
#endif

	printName(firstName);
	printName(lastName);

	std::cout << "Allocating " << s_AllocCount;
}
