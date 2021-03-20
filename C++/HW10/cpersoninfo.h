#pragma once

#include <iostream>
using namespace std;

template <class T>
class CPersonInfo
{
public:
	CPersonInfo();
	CPersonInfo(const CPersonInfo& other);
	CPersonInfo(T weight, T height, int age, string fullName);
	~CPersonInfo();

	T GetWeight() const;
	T GetHeight() const;
	int GetAge() const;
	string GetName() const;
	
	int GetNameLength() const;
	void SetWeight(T weight);
	void SetHeight(T height);
	void SetAge(int age);
	void SetName(string fullName);
	
private:
	T m_weight;
	T m_height;
	int* m_age;
	string m_fullName;
};

#include "cpersoninfo.cpp"
