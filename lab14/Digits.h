#pragma once
#include <math.h>
class Digits
{
private:
	double a, b;
	double min(double a, double b);
public:
	Digits();
	Digits(double a, double b);
	virtual ~Digits();
	Digits operator+(Digits d2);
	double get_a();
	double get_b();
	void set_a(double a);
	void set_b(double b);
};

