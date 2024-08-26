#include "pch.h"


class String
{
public:
	String() = default;

	String(const char* string) // Create Constructor
	{
		printf("Created\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String& other) // Copy Constructor
	{
		printf("Copied\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept // Move Constructor (rvalue)
	{
		printf("Moved\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	~String()
	{
		printf("Destroyed\n");
		delete[] m_Data;
	}

	void Print()
	{
		for (int i = 0; i < m_Size; i++)
		{
			printf("%c", m_Data[i]);
		}
		printf("\n");
	}

	String& operator=(String&& other) noexcept // defining = operator for Moving Assignment
	{
		printf("Moved\n");

		if (this != &other) // check if the asset and what we want to copy is equal or not (have same memory address)
		{
			// if not same, delete current data and replace with new moved object
			delete[] m_Data;
			m_Size = other.m_Size;
			m_Data = other.m_Data;

			other.m_Size = 0;
			other.m_Data = nullptr;
		}
		// if there are same just return this
		return *this;
	}

private:
	int m_Size;
	char* m_Data;
};

int main()
{
	String name = "Mahdi";
	String movedName;
	
	movedName = std::move(name); // use the std::move to make the name value temporary and use = operator

	movedName.Print();
	std::cin.get();
}
