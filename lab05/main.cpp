#include <iostream>
#include <string>
#include "line.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	size_t first_size = 0, second_size = 0;
	printf("Введите первое слово: ");
	char *firstword = getarray(&first_size);
	printf("Введите второе слово: ");
	char *secondword = getarray(&second_size);
	printf("Все возможные комбинации кроссворда:\n\n");
	for (size_t i = 0, counter = 1; i<first_size; i++)
	{
		for (size_t j = 0; j<second_size; j++)
		{
			if (firstword[i] == secondword[j])
			{
				printf("%d)\n", counter++);
				printwords(firstword, secondword, &i, &j);
				putchar('\n');
			}
		}
	}
	free(firstword);
	free(secondword);
	return 0;
}
