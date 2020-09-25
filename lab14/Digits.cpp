#include "Digits.h"

double Digits::min(double a, double b)
{
	if (a == b) 
		return a;
	else 
		if (a < b) 
			return a;
	else 
		if (a > b) 
			return b;
}

Digits::Digits(): a(0), b(0)
{
}

Digits::Digits(double a, double b): a(a), b(b)
{
}

Digits::~Digits()
{
}

Digits Digits::operator+(Digits d2)
{
	return Digits(min(this->a, d2.a), pow(this->b,d2.b));
}

double Digits::get_a()
{
	return a;
}

double Digits::get_b()
{
	return b;
}

void Digits::set_a(double a)
{
	this->a = a;
}

void Digits::set_b(double b)
{
	this->b = b;
}
