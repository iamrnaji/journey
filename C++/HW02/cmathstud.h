#pragma once
#include "cquadratic.h"
class CMathStud
{
public:
	CMathStud(int first, int second);
	CMathStud(int first, int second, int third);
	~CMathStud();

	double getMyValue(double value);

private:
	CQuadratic QE;
};
