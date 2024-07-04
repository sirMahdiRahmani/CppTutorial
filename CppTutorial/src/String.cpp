#include <iostream>
#include "String.h"

using namespace std;

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string) + 1;
		m_Buffer = new char[m_Size];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	String(const String& other) : m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size);
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend ostream& operator<<(ostream& stream, const String& string);

	~String()
	{
		delete[] m_Buffer;
	}
};

ostream& operator<<(ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}