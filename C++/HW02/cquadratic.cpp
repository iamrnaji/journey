

#include <iostream>
#include "cquadratic.h"
using namespace std;

CQuadratic::CQuadratic(int first, int second, int third)
{
	cout << "CQuadratic constructor!!!\n";
	c1 = first;
	c2 = second;
	c3 = third;
}

CQuadratic::~CQuadratic()
{
	cout << "CQuadratic destructor!!!\n";
}

double CQuadratic::Evaluate(double value)
{
	return (c1 * (value * value) + (c2 * value) + c3);
}
