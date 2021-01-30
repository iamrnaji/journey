#pragma once
#include <iostream>
using namespace std;


#ifndef CPERSON_HEADER
#define CPERSON_HEADER

class CPerson
{
public:
	CPerson();
	CPerson(const char* name, int age);
	CPerson(const CPerson& object);
	~CPerson();

	int GetAge() const;
	const char* GetName() const;
	void SetAge(int age);
	void SetName(const char* name);
	void DisplayData();
	void GetData();
	bool operator==(const CPerson& rhs);
	bool operator>(const CPerson& rhs);

private:
	char *m_name;
	int m_age;
};

istream& operator>>(istream& inStream, CPerson& object);
ostream& operator<<(ostream& outStream, const CPerson& object);

#endif
