// Debug:
// clang -g -O0 ../src/*.c -o main -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer

// Release:
// clang -Ofast ../src/*.c -o main -Wall -Wextra

#include "../include/container.h"

int main() {

	Container* c = container_new(10, "int");

	if (c == NULL) {

		return 1;
	}
	
	for (size_t i = 0; i < c->size; ++i) {

		printf("%d\n", c->int_data[i]);
	}

	printf("%s\n", c->data_type);

	container_delete(&c);

	return 0;
}

