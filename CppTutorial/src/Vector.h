#pragma once
#include "pch.h"

template<typename T>
class Vector
{
public:

	Vector()
	{
		ReAlloc(2);
	}

	~Vector()
	{
		Clear();
		::operator delete(m_Data, m_Capacity * sizeof(T));
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		if (m_Size >= m_Capacity)
		{
			ReAlloc(m_Capacity + m_Capacity / 2);
		}
		new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
		return m_Data[m_Size++];
	}

	void PushBack(const T& data)
	{
		if (m_Size >= m_Capacity)
		{
			ReAlloc(m_Capacity + m_Capacity / 2);
		}
		m_Data[m_Size] = data;
		m_Size++;
	}

	void PushBack(T&& data)
	{
		if (m_Size >= m_Capacity)
		{
			ReAlloc(m_Capacity + m_Capacity / 2);
		}
		m_Data[m_Size] = std::move(data);
		m_Size++;
	}

	void PopBack()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T();
		}
	}

	void Clear()
	{
		for (size_t i = 0; i < m_Size; i++)
		{
			m_Data[i].~T();
		}
		m_Size = 0;
	}

	const T& operator[](size_t index) const
	{
		return m_Data[index];
	}

	T& operator[](size_t index)
	{
		return m_Data[index];
	}

	size_t Size() const { return m_Size; }

private:
	void ReAlloc(size_t newCapacity)
	{
		T* NewBlock = (T*)::operator new (newCapacity * sizeof(T));

		if (newCapacity < m_Size)
		{
			m_Size = newCapacity;
		}

		for (size_t i = 0; i < m_Size; i++)
		{
			NewBlock[i] = std::move(m_Data[i]);
		}

		for (size_t i = 0; i < m_Size; i++)
		{
			m_Data[i].~T();
		}

		::operator delete(m_Data, m_Capacity * sizeof(T));
		m_Data = NewBlock;
		m_Capacity = newCapacity;
	}

private:
	size_t m_Size = 0;
	size_t m_Capacity = 0;
	T* m_Data = nullptr;
};
