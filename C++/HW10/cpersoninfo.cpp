
#include "cpersoninfo.h"

template <class T>
CPersonInfo<T>::CPersonInfo()
{
	m_weight = 0;
	m_height = 0;
	m_age = new int;
	*m_age = 0;
	m_fullName = " ";
}

template <class T>
CPersonInfo<T>::CPersonInfo(const CPersonInfo& other)
{
	m_weight = other.GetWeight();
	m_height = other.GetHeight();
	m_age = new int;
	*m_age = other.GetAge();
	m_fullName = other.GetName();
}

template <class T>
CPersonInfo<T>::CPersonInfo(T weight, T height, int age, string fullName)
{
	m_weight = weight;
	m_height = height;
	m_age = new int;
	*m_age = age;
	m_fullName = fullName;
}

template <class T>
CPersonInfo<T>::~CPersonInfo()
{
	*m_age = 0;
	delete m_age;
}

template <class T>
int CPersonInfo<T>::GetAge() const
{
	return *m_age;
}

template <class T>
T CPersonInfo<T>::GetHeight() const
{
	return m_height;
}

template <class T>
T CPersonInfo<T>::GetWeight() const
{
	return m_weight;
}

template <class T>
string CPersonInfo<T>::GetName() const
{
	return m_fullName;
}

template <class T>
int CPersonInfo<T>::GetNameLength() const
{
	int count = 0;
	for (int i = 0; i < m_fullName.length(); i++)
	{

		if (m_fullName[i] != ' ')
		{
			count++;
		}
	}

	return count;
}

template <class T>
void CPersonInfo<T>::SetWeight(T weight)
{
	m_weight = weight;
}

template <class T>
void CPersonInfo<T>::SetHeight(T height)
{
	m_height = height;
}

template <class T>
void CPersonInfo<T>::SetAge(int age)
{
	*m_age = age;
}

template <class T>
void CPersonInfo<T>::SetName(string name)
{
	m_fullName = name;
}



