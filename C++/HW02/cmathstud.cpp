#include <iostream>
#include "cmathstud.h"
using namespace std;

CMathStud::CMathStud(int first, int second)
	: QE(first, second, 0)
{
	cout << "CMathStud Constructor!!!\n";
}

CMathStud::CMathStud(int first, int second, int third)
	: QE(first, second, third)
{
	cout << "CMathStud Constructor!!!\n";
}

CMathStud::~CMathStud()
{
	cout << "CMathStud destructor!!!\n";
}

double CMathStud::getMyValue(double value)
{
	return QE.Evaluate(value);
}
