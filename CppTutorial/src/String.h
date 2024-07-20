#pragma once
#include "pch.h"

#ifndef STRING_H
#define STRING_H

using namespace std;


class String 
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string);
	String(const String& other);


	char& operator[](unsigned int index);

	friend ostream& operator<<(ostream& stream, const String& string);

	~String();
};

#endif