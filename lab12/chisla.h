#pragma once
#include <iostream>
#include <fstream>

class Sort
{
private:
	int *array = nullptr;
	int size = 0;
	int get_size(std::ifstream& fin);
	void swap(int* xp, int* yp);
public:
	Sort(std::ifstream &fin);
	void FRead(std::ifstream &fin);
	void Print();
	void Bubble();
	void Selection();
	virtual ~Sort();
};
