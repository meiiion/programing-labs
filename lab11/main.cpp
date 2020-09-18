/*
 *  Лабораторная работа #1
 *  Учаев Григорий, СББ-901-О-01, 2 пг.
 *  Вариант 19
 */
#include <iostream>
#include "Deque.h"
#define default_option Menu::pushBack

enum class Menu {
	exit, pushBack, popFront, pushFront, popBack, isEmpty, printQueue, Clear
};

void PrintMenu() {
	printf(
		"\n [#]  Выберете нужную опцию  [#]\n"
		" (%d) Добавить элемент в  конец  очереди\n"
		" (%d) Извлечь  элемент из начала очереди\n"
		" (%d) Добавить элемент в  начало очереди\n"
		" (%d) Извлечь  элемент из конца  очереди\n"
		" (%d) Проверка на  отсутствие  элементов\n"
		" (%d) Вывести  элементы  на  экран\n"
		" (%d) Очистить очередь\n"
		" (%d) Выход\n"
		" >>> ", 
		Menu::pushBack, Menu::popFront, Menu::pushFront, Menu::popBack, Menu::isEmpty, Menu::printQueue, Menu::Clear, Menu::exit

	);
}

void PrintElements(Deque& d) {
	printf(" ");
	for (int i = 0; i < d.count - 1; i++) {
		printf("<%d>, ", d.queue[i]);
	}
	printf("<%d>.\n", d.queue[d.count - 1]);
}

int main() {
	setlocale(LC_ALL, "Russian");
	Menu menu = default_option; // init by default value
	Deque deque = Deque(50);
	
	while (menu != Menu::exit) {
		PrintMenu();
		scanf_s("%d", &menu);
		if ((unsigned int)menu > 7) 
			menu = default_option;
		int number = 0;

		switch(menu){
		case Menu::pushBack:
			printf("\n [#]  Введите число  [#]\n >>> ");
			scanf_s("%d", &number);
			deque.PushBack(number);
			break;
		case Menu::popFront:
			if (!deque.IsEmpty()) {
			number = deque.PopFront();
			printf("\n [#]  Число <%d> извлечено из начала очереди  [#] \n", number);
			} else {
				printf("\n [#]  Очередь пуста  [#] \n");
			}
			break;
		case Menu::pushFront:
			printf("\n [#]  Введите число  [#]\n >>> ");
			scanf_s("%d", &number);
			deque.PushFront(number);
			break;
		case Menu::popBack:
			if (!deque.IsEmpty()) {
				number = deque.PopBack();
				printf("\n [#]  Число <%d> извлечено из конца очереди  [#] \n", number);
			} else {
				printf("\n [#]  Очередь пуста  [#] \n");
			}
			break;
		case Menu::isEmpty:
			if (deque.IsEmpty())
				printf("\n [#]  Очередь пуста  [#] \n");
			else
				printf("\n [#]  Очередь не пуста  [#] \n");
			break;
		case Menu::printQueue:
			if (!deque.IsEmpty()) {
				printf("\n [#]  Элементы очереди  [#] \n");
				PrintElements(deque);
			}
			else {
				printf("\n [#]  Очередь пуста  [#] \n");
			}
			break;
		case Menu::Clear:
			if (!deque.IsEmpty()) {
				deque.Clear();
				printf("\n\n [#]  Очередь очищена  [#]\n");
			} else {
				printf("\n [#]  Очередь пуста  [#] \n");
			}
			break;
		}
		
	}
	return 0;
}
