#pragma once
class CQuadratic
{
public:
	CQuadratic(int first, int second, int third);
	~CQuadratic();

	double Evaluate(double value);


private:
	int c1;
	int c2;
	int c3;
};
