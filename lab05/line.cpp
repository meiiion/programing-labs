#include "line.h"
#include <iostream>
#include <string>
#define BUFFER_LIMIT 150
using namespace std;

char* getarray() {
	int c = 0;
	size_t size = 0;
	size_t buffer = 32;
	char* line = (char*)(malloc(buffer));
	if (line == NULL) return nullptr;
	while ((c = getchar()) != '\n' && buffer <= BUFFER_LIMIT)
	{
		(size)++;
		if (size <= buffer) line[size - 1] = c;
		else
		{
			char* ptr = (char*)realloc(line, buffer += 8);
			if (ptr == nullptr)
			{
				free(line);
				return nullptr;
			}
			line = ptr;
			line[size - 1] = c;
		}
	}
	if (size < buffer) line[size] = '\0';
	else
	{
		char* ptr = (char*)realloc(line, buffer += 1);
		if (ptr == nullptr)
		{
			free(line);
			return nullptr;
		}
		line = ptr;
		line[size] = '\0';
	}
	line[size] = '\0';
	return line;
}

char* getarray(size_t* size) {
	int c = 0;
	*size = 0;
	size_t buffer = 32;
	char* line = (char*)(malloc(buffer));
	if (line == NULL) return nullptr;
	while ((c = getchar()) != '\n' && buffer <= BUFFER_LIMIT)
	{
		(*size)++;
		if (*size <= buffer) line[*size - 1] = c;
		else
		{
			char* ptr = (char*)realloc(line, buffer += 8);
			if (ptr == nullptr)
			{
				free(line);
				return nullptr;
			}
			line = ptr;
			line[*size - 1] = c;
		}
	}
	if (*size < buffer) line[*size] = '\0';
	else
	{
		char* ptr = (char*)realloc(line, buffer += 1);
		if (ptr == nullptr)
		{
			free(line);
			return nullptr;
		}
		line = ptr;
		line[*size] = '\0';
	}
	line[*size] = '\0';
	return line;
}

void printwords(char *firstword, char *secondword, size_t *x, size_t *y)
{
	for (size_t i = 0; firstword[i] != '\0'; i++)
	{
		for (size_t j = 0; secondword[j] != '\0'; j++)
		{
			//if ((i == *y) && (j == *x)) putchar(firstword[i]);
			if (i == *y) putchar(firstword[j]); else
				if (j == *x) putchar(secondword[i]); else
					putchar(' ');
		}
		putchar('\n');
	}
}
