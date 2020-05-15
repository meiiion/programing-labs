//Not Finished!!!!!!!!!

#include <iostream>
#include <string>
#define BUFFER_LIMIT 150
using namespace std;



size_t strlen(char* line) {
	size_t count = 0;
	while (line[count]) count++;
	return count;
}

char* getarray(size_t *size) {
	int c = 0;
	*size = 0;
	size_t buffer = 32;
	char *line = (char *)(malloc(buffer));
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
	line[*size] = '\0';
	return line;
}

int main() {
	size_t size = 0;
	char* p = getarray(&size);
	printf(p);
	
	
	return 0;
}
