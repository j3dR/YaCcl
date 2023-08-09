/*
Debug:
clang -g -O0 ../src/main.c -o main -Wall -Wextra

Release:
clang -Ofast ../src/main.c -o main -Wall -Wextra
*/

#include "../include/container.h"

int main() {

	Container* c = container_new(10, "int");
	
	for (size_t i = 0; i < c->size; ++i) {

		printf("%d\n", c->data_int[i]);
	}

	free(c);

	return 0;
}

