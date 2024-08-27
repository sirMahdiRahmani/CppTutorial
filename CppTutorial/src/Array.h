#pragma once
#include "pch.h"

template <typename T, size_t S>
class Array
{
public:
	int Size() { return S; }

	T& operator[] (int index) { return Data[index]; }

	const T& operator[] (int index) const { return Data[index]; }

	T* GetData() { return Data; }

	const T* GetData() const { return Data; }
private:
	T Data[S];
};
