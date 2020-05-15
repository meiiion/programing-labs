//v0.1

#include <iostream>
using namespace std;

void PrintNum(char *nums, size_t size) {
	char numbers[10][5][3] = {
	{
		{'#','#','#'},
		{'#',' ','#'},
		{'#',' ','#'},
		{'#',' ','#'},
		{'#','#','#'}
	},
	{
		{' ','#',' '},
		{'#','#',' '},
		{' ','#',' '},
		{' ','#',' '},
		{'#','#','#'}
	},
	{
		{'#','#','#'},
		{' ',' ','#'},
		{'#','#','#'},
		{'#',' ',' '},
		{'#','#','#'}
	},
	{
		{'#','#','#'},
		{' ',' ','#'},
		{'#','#','#'},
		{' ',' ','#'},
		{'#','#','#'}
	},
	{
		{'#',' ','#'},
		{'#',' ','#'},
		{'#','#','#'},
		{' ',' ','#'},
		{' ',' ','#'}
	},
	{
		{'#','#','#'},
		{'#',' ',' '},
		{'#','#','#'},
		{' ',' ','#'},
		{'#','#','#'}
	},
	{
		{'#','#','#'},
		{'#',' ',' '},
		{'#','#','#'},
		{'#',' ','#'},
		{'#','#','#'}
	},
	{
		{'#','#','#'},
		{' ',' ','#'},
		{' ','#',' '},
		{' ','#',' '},
		{' ','#',' '}
	},
	{
		{'#','#','#'},
		{'#',' ','#'},
		{'#','#','#'},
		{'#',' ','#'},
		{'#','#','#'}
	},
	{
		{'#','#','#'},
		{'#',' ','#'},
		{'#','#','#'},
		{' ',' ','#'},
		{'#','#','#'}
	},
	};
	for (size_t i = 0; i < 5; i++) {
		for (size_t t = size; t > 0; t--) {
			for (size_t j = 0; j < 3; j++) putchar(numbers[nums[t-1]][i][j]);
			putchar(' ');
		}
		putchar('\n');
	}
}

void ToArray(char *array, unsigned long int num, size_t size) {
	int i = 0;
	while (num) {
		array[i++] = num % 10;
		num /= 10;
	}
}

int main() {
    int number = 0, tmp = 0;
	cin >> number;
	tmp = number;
	size_t count = 1;
	while (tmp /= 10) count++;
	char* numArrayPtr = new char[count];
	ToArray(numArrayPtr, number, count);
	PrintNum(numArrayPtr, count);
	delete[] numArrayPtr;
	return 0;
}
