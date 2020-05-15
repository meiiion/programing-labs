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
