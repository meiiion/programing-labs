#include <iostream>
#include <fstream>
#include "Sort.h"


int main() {
	std::ifstream fin;
	fin.open("C:\\data.txt");
	if (!fin.is_open()) {
		std::cout << "File isn't open\n";
		return 0;
	}
	Sort *sort = new Sort(fin);
	sort->FRead(fin);
	sort->Print();
	sort->Bubble();
	sort->Print();
	sort->FRead(fin);
	sort->Print();
	sort->Selection();
	sort->Print();
	return 0;
}
