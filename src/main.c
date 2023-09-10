#include "../include/yaccl.h"

int main() {
	Container* container = NULL;
	container_append(&container, 4.567);
	switch (container->data_type) {
		case CHAR:
			puts("Type: char");
			break;
		case SHORT:
			puts("Type: short");
			break;
		case INT:
			puts("Type: int");
			break;
		case LONG:
			puts("Type: long");
			break;
		case FLOAT:
			puts("Type: float");
			break;
		case DOUBLE:
			puts("Type: double");
			break;
	}
	printf("Size: %lu\n", container->size);
	printf("c[0] = %f\n\n", container_getd(container, 0));

	for (int i = 0; i < 10; ++i) {
		container_append(&container, 2.345);
	}

	for (size_t i = 0; i < container->size; ++i) {
		printf("%f\n", container_getd(container, i));
	}
	printf("Size: %lu\n\n", container->size);

	container_remove(&container, 9);

	for (size_t i = 0; i < container->size; ++i) {
		printf("%f\n", container_getd(container, i));
	}
	printf("Size: %lu\n\n", container->size);

	container_assign(&container, 7.123, 0);

	for (size_t i = 0; i < container->size; ++i) {
		printf("%f\n", container_getd(container, i));
	}
	printf("Size: %lu\n\n", container->size);

	container_delete(&container);
	return 0;

	/*
	Container* container = container_new(10, INT);

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

