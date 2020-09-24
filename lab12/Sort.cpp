#include "chisla.h"
#include <stdlib.h>

Сhisla::Сhisla() {
	x = 0;
	y = 0;
}

Сhisla::Сhisla(int x, int y) {
	this->x = x;
	this->y = y;
}

Сhisla::~Сhisla()
{
}

int Сhisla::get_x() {
	return x;
}

int Сhisla::get_y() {
	return y;
}

void Сhisla::set_x(int x) {
	this->x = x;
}

void Сhisla::set_y(int y) {
	this->y = y;
}

int Сhisla::mul() {
	return x * y;
}

int Сhisla::neg() {
	if (x >= 0 && y >= 0) {
		return 0;
	} else if (x < 0 && y < 0) {
		return abs(x - y) + 1;
	}
	else if (x < 0 && y >= 0) {
		return abs(x);
	}
	else if (y < 0 && x >= 0) {
		return abs(y);
	}
}
