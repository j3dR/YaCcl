/*
Debug:
clang -g -O0 ../src/main.c -o main -Wall -Wextra

Release:
clang -Ofast ../src/main.c -o main -Wall -Wextra
*/

#include <stdio.h>
#include "../include/container.h"

int main() {

	Container c;
	c.size = 10;
	printf("%d\n", c.size);

	return 0;
}

