#include <iostream>
#include "Digits.h"
using std::cout;
using std::cin;
#define default_option Menu::set_d1

enum class Menu {
	exit, set_d1, set_d2, print_vars, sum
};

void PrintMenu() {
	cout <<
		"\n [#]  Выберете нужную опцию  [#]\n (" << (int)Menu::set_d1 <<
		") Установить D1\n (" << (int)Menu::set_d2 <<
		") Установить D2\n (" << (int)Menu::print_vars <<
		") Вывести на экран числа\n (" << (int)Menu::sum <<
		") Вывести результат суммы чисел \n (" << (int)Menu::exit <<
		") Выход\n"
		" >>> ";
}

int main() {
	setlocale(LC_ALL, "Russian");
	Menu menu = default_option; // init by default value
	Digits *d1 = new Digits(), *d2 = new Digits(), *d3 = new Digits();

	while (menu != Menu::exit) {
		PrintMenu();
		int op = 1;
		cin >> op;
		if ((unsigned int)op > 4)
			menu = default_option;
		else
			menu = (Menu)op;
		double tmp = 0;

		switch (menu) {
		case Menu::set_d1:
			cout << "\n [#]  Введите D1  [#]\n A = ";
			tmp = 0;
			cin >> tmp;
			d1->set_a(tmp);
			cout << " B = ";
			cin >> tmp;
			d1->set_b(tmp);
			break;

		case Menu::set_d2:
			cout << "\n [#]  Введите D2  [#]\n A = ";
			tmp = 0;
			cin >> tmp;
			d2->set_a(tmp);
			cout << " B = ";
			cin >> tmp;
			d2->set_b(tmp);
			break;

		case Menu::sum:
			*d3 = *d1 + *d2;
			cout << "\n [#]  Числа  [#]"
				"\n Сумма D1, D2: A = " << d3->get_a() << " B = " << d3->get_b() << std::endl;
			break;

		case Menu::print_vars:
			cout << "\n [#]  Числа  [#]"
				"\n D1: A = " << d1->get_a() << " B = " << d1->get_b() <<
				"\n D2: A = " << d2->get_a() << " B = " << d2->get_b() << std::endl;
			break;
		}
	}
	delete d1, d2, d3;
	return 0;
}
