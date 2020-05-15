// NOT FINISHED

#include <iostream>
#include <string>
#include "line.h"
#define BUFFER_LIMIT 150
using namespace std;

int main() {
	size_t size = 0;
	char* p = getarray(&size);
	printf("%s, %d", p, size);
	
	return 0;
}
