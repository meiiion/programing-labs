#include "Sort.h"


// private:

int Sort::get_size(std::ifstream& fin)
{
	fin.seekg(std::ios_base::beg);
	int size = 0;
	int tmp = 0;
	while (fin.peek() != '\n' && fin.peek() != EOF) {
		fin >> tmp;
		fin.get();
		size++;
	}
	return size;
}

void Sort::swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// public:

Sort::Sort(std::ifstream &fin) {
	array = new int[this->size = get_size(fin)];
}

void Sort::FRead(std::ifstream& fin) {
	fin.clear();
	fin.seekg(0);
	for (int i = 0; i < size; i++)
	{
		fin >> array[i];
		fin.get();
	}
}

void Sort::Print() {
	for (int i = 0; i < size; i++)
		std::cout << " <" << array[i] << "> ";
	std::cout << std::endl;
}

void Sort::Bubble() {
	for (int i = 0; i < size - 1; i++) 
		for (int j = 0; j < size - i - 1; j++)
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
}

void Sort::Selection() {
	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] > array[min_idx])
				min_idx = j;
		swap(&array[min_idx], &array[i]);
	}
}

Sort::~Sort()
{
	delete[] array;
}
