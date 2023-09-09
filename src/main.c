#include "../include/container.h"

int main() {
	Container* c = NULL;
	container_append(&c, 54);
	printf("Type: %s\n", c->data_type);
	printf("Size: %lu\n", c->size);
	printf("c[0] = %d\n\n", container_geti(c, 0));

	for (int i = 0; i < 10; ++i) {
		container_append(&c, i);
	}

	for (size_t i = 0; i < c->size; ++i) {
		printf("%d\n", container_geti(c, i));
	}
	printf("Size: %lu\n\n", c->size);

	container_remove(&c, 9);

	for (size_t i = 0; i < c->size; ++i) {
		printf("%d\n", container_geti(c, i));
	}
	printf("Size: %lu\n\n", c->size);

	container_delete(&c);
	return 0;

	/*
	Container* container = container_new(10, "int");

	if (container == NULL) {
		return 1;
	}

	// Assign values
	for (size_t i = 0; i < container->size; ++i) {
		container_assign(&container, (int)i, i);
	}

	container_assign(&container, 2137, 5);
	
	// Read values
	for (size_t i = 0; i < container->size; ++i) {
		printf("%d\n", container_geti(container, i));
	}

	printf("%s\n", container->data_type);

	puts("");

	container_append(&container, 69);

	// Read values
	for (size_t i = 0; i < container->size; ++i) {
		printf("%d\n", container_geti(container, i));
	}

	container_delete(&container);

	return 0;
	*/
}

