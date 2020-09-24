/*
 *  Лабораторная работа #2
 *  Учаев Григорий, СББ-901-О-01, 2 пг.
 *	Вариант 19
 */

#include <iostream>
#include "chisla.h"
using std::cout;
using std::cin;
#define default_option Menu::print_vars

enum class Menu {
	exit, set_x, set_y, print_vars, mul, neg
};

void PrintMenu() {
	cout <<
		"\n [#]  Выберете нужную опцию  [#]\n ("<< (int)Menu::set_x <<
		") Установить X\n (" << (int)Menu::set_y <<
		") Установить Y\n (" << (int)Menu::print_vars <<
		") Вывести на экран числа\n (" << (int)Menu::mul <<
		") Вывести результат произведения чисел \n (" << (int)Menu::neg <<
		") Вывести количество отрицательный чисел\n (" << (int)Menu::exit <<
		") Выход\n"
		" >>> ";
}

int main() {
	setlocale(LC_ALL, "Russian");
	Menu menu = default_option; // init by default value
	Сhisla* chisla = new Сhisla();

	while (menu != Menu::exit) {
		PrintMenu();
		int op = 1;
		cin >> op;
		if ((unsigned int)op > 7)
			menu = default_option;
		else
			menu = (Menu)op;
		int number = 0;

		switch (menu) {
		case Menu::set_x:
			cout << "\n [#]  Введите число X  [#]\n >>> ";
			cin >> number;
			chisla->set_x(number);
			break;
		case Menu::set_y:
			cout << "\n [#]  Введите число Y  [#]\n >>> ";
			cin >> number;
			chisla->set_y(number);
			break;
		case Menu::mul:
			cout << "\n [#]  Числа  [#]"
				"\n Прозиведение чисел x, y = " << chisla->mul() << std::endl;
			break;
		case Menu::print_vars:
			cout << "\n [#]  Числа  [#]"
				"\n X = " << chisla->get_x() <<
				"\n Y = " << chisla->get_y() << std::endl;
			break;
		case Menu::neg:
			cout << "\n [#]  Числа  [#]"
				"\n Кол-вл отрицательных чисел между x, y = " << chisla->neg() << std::endl;
			break;

		}
	}
	delete chisla;
	return 0;
}
