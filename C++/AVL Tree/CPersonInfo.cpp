#include <iostream>
#include <string>
#include <iomanip>
#include "CPersonInfo.h"

using namespace std;


CPersonInfo::CPersonInfo()
{
	m_fname = "";
	m_lname = "";
	m_checking = 0;
	m_savings = 0;
	m_age = 0;
}

CPersonInfo::CPersonInfo(const std::string& fname, const std::string& lname, int age, double checking, double savings)
{
	m_fname = fname;
	m_lname = lname;
	m_age = age;
	m_checking = checking;
	m_savings = savings;
}

void CPersonInfo::SetFirstName(const std::string& fname)
{
	m_fname = fname;
}

void CPersonInfo::SetLastName(const std::string& lname)
{
	m_lname = lname;
}

void CPersonInfo::SetAge(int age)
{
	m_age = age;
}

void CPersonInfo::SetChecking(double checking)
{
	m_checking = checking;
}

void CPersonInfo::SetSavings(double savings)
{
	m_savings = savings;
}

std::string CPersonInfo::GetFirstName() const
{
	return m_fname;
}

std::string CPersonInfo::GetLastName() const
{
	return m_lname;
}

int CPersonInfo::GetAge() const
{
	return m_age;
}

double CPersonInfo::GetChecking() const
{
	return m_checking;
}

double CPersonInfo::GetSavings() const
{
	return m_savings;
}

bool CPersonInfo::operator==(const CPersonInfo& rhs)
{
	if (m_fname == rhs.GetFirstName() && m_lname == rhs.GetLastName() && m_age == rhs.GetAge() && m_checking == rhs.GetChecking() && m_savings == rhs.GetSavings())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CPersonInfo::operator<(const CPersonInfo& rhs)
{
	if (m_age < rhs.GetAge())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CPersonInfo::operator>(const CPersonInfo& rhs)
{
	if (m_age > rhs.GetAge())
	{
		return true;
	}
	else
	{
		return false;
	}
}

istream& operator>>(std::istream& ins, CPersonInfo& person)
{
	std::string fname;
	std::string lname;
	int age;
	double checking;
	double savings;
	ins >> fname >> lname >> age >> checking >> savings;
	person.SetFirstName(fname);
	person.SetLastName(lname);
	person.SetAge(age);
	person.SetChecking(checking);
	person.SetSavings(savings);
	return ins;
}

ostream& operator<<(std::ostream& outs, const CPersonInfo& person)
{
	outs << setw(12) << left << person.GetFirstName() << setw(12) << left << person.GetLastName() << setw(12) << left << person.GetAge() << setw(12) << left << "$" << setw(12) << left << person.GetChecking() << setw(12) << left << "$" << setw(12) << left << person.GetSavings() << endl;
	return outs;
}
