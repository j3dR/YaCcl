// Debug:
// clang -g -O0 ../src/*.c -o main -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer

// Release:
// clang -Ofast ../src/*.c -o main -Wall -Wextra

#include "../include/container.h"

int main() {
	Container* container = container_new(10, "int");

	if (container == NULL) {
		return 1;
	}

	// Assign values
	for (size_t i = 0; i < container->size; ++i) {
		container_assign(&container, (int[]){69}, i);
	}
	
	// Read values
	for (size_t i = 0; i < container->size; ++i) {
		printf("%d\n", ((int*)container->data)[i]);
	}

	printf("%s\n", container->data_type);

	container_delete(&container);

	return 0;
}

