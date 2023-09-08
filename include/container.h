#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* const LIB_NAME = "container.h";  // library name

// Template
typedef struct Container_struct {
	size_t size;
  	const char* data_type;

	void* data;
} Container;

// Constructor
Container* container_new(size_t size, const char* data_type) {
	Container* container = malloc(sizeof(Container));
	if (container == NULL) {
		fprintf(stderr, "%s error: container_new: Failed to allocate memory for the container struct\n", LIB_NAME);
		return NULL;
	}

	container->size = size;
	container->data_type = data_type;

	if (strcmp(data_type, "int") == 0) {
		container->data = calloc(size, sizeof(int));	
	}
	else if (strcmp(data_type, "float") == 0) {
		container->data = calloc(size, sizeof(float));
	}
	else {
		free(container);
		fprintf(stderr, "%s error: container_new: Data type not supported\n", LIB_NAME);
		puts("                                  Supported data types: int, float");
		return NULL;
	}

	if (container->data == NULL) {
		free(container);
		fprintf(stderr, "%s error: container_new: Failed to allocate data\n", LIB_NAME);
		return NULL;
	}

	return container;
}

// Destructor
void container_delete(Container** container) {
	if (*container == NULL) {
		fprintf(stderr, "%s error: container_delete: Container is already non-existent\n", LIB_NAME);
		return;
	}

	if ((*container)->data != NULL) {
		free((*container)->data);
		(*container)->data = NULL;
	}
	
	free(*container);
	*container = NULL;
}

// Clear all data
void container_clear(Container** container) {
	if (*container == NULL) {
		fprintf(stderr, "%s error: container_clear: Container is non-existent\n", LIB_NAME);
		return;
	}

	if ((*container)->data == NULL) {
		fprintf(stderr, "%s error: container_clear: Data is already empty\n", LIB_NAME);
		return;
	}

	free((*container)->data);
	(*container)->data = NULL;

	(*container)->size = 0;
}

// Assign functions ---------------------------------------------------------------------------------------------------------

#define container_assign(container_reference, value, size_t_index) _Generic(value,                                              \
														   int: container_assigni(container_reference, value, size_t_index),    \
														   float: container_assignf(container_reference, value, size_t_index))  \

// Assign int
void container_assigni(Container** container, int value, size_t index) {
	if (*container == NULL) {
		fprintf(stderr, "%s error: container_assign: Container is non-existent\n", LIB_NAME);
		return;
	}

	if ((*container)->data == NULL) {
		fprintf(stderr, "%s error: container_assign: Data is empty\n", LIB_NAME);
		return;
	}

	if (strcmp((*container)->data_type, "int") != 0) {
		fprintf(stderr, "%s error: container_assign: Incorrect value data type\n", LIB_NAME);
		return;
	}

	if (index > (*container)->size - 1) {
		fprintf(stderr, "%s error: container_assign: Incorrect index\n", LIB_NAME);
		return;
	}

	((int*)(*container)->data)[index] = value;
}

// Assign float
void container_assignf(Container** container, float value, size_t index) {
	if (*container == NULL) {
		fprintf(stderr, "%s error: container_assign: Container is non-existent\n", LIB_NAME);
		return;
	}

	if ((*container)->data == NULL) {
		fprintf(stderr, "%s error: container_assign: Data is empty\n", LIB_NAME);
		return;
	}

	if (strcmp((*container)->data_type, "float") != 0) {
		fprintf(stderr, "%s error: container_assign: Incorrect value data type\n", LIB_NAME);
		return;
	}

	if (index > (*container)->size - 1) {
		fprintf(stderr, "%s error: container_assign: Incorrect index\n", LIB_NAME);
		return;
	}

	((float*)(*container)->data)[index] = value;
}

// Getters ------------------------------------------------------------------------------------------------------------------

int container_geti(Container* container, size_t index) {
	if (container == NULL) {
		fprintf(stderr, "%s error: container_geti: Container is non-existent\n", LIB_NAME);
		return 0;
	}

	if (container->data == NULL) {
		fprintf(stderr, "%s error: container_geti: Data is empty\n", LIB_NAME);
		return 0;
	}

	if (index > container->size - 1) {
		fprintf(stderr, "%s error: container_geti: Incorrect index\n", LIB_NAME);
		return 0;
	}

	return ((int*)container->data)[index];
}

float container_getf(Container* container, size_t index) {
	if (container == NULL) {
		fprintf(stderr, "%s error: container_getf: Container is non-existent\n", LIB_NAME);
		return 0.0f;
	}

	if (container->data == NULL) {
		fprintf(stderr, "%s error: container_getf: Data is empty\n", LIB_NAME);
		return 0.0f;
	}

	if (index > container->size - 1) {
		fprintf(stderr, "%s error: container_getf: Incorrect index\n", LIB_NAME);
		return 0.0f;
	}

	return ((float*)container->data)[index];
}

// Append functions ---------------------------------------------------------------------------------------------------------

#define container_append(container_reference, value) _Generic(value,                                       \
													int: container_appendi(container_reference, value),    \
													float: container_appendf(container_reference, value))  \

void container_appendi(Container** container, int value) {
	if (*container == NULL) {
		*container = container_new(1, "int");
		if (*container == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to initialize empty container\n", LIB_NAME);
			return;
		}

		((int*)(*container)->data)[0] = value;
	}
	else if ((*container)->data == NULL) {
		(*container)->size = 1;

		(*container)->data = malloc(sizeof(int));
		if ((*container)->data == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to allocate data\n", LIB_NAME);
			return;
		}

		((int*)(*container)->data)[0] = value;
	}
	else {
		(*container)->data = realloc((*container)->data, ++(*container)->size * sizeof(int));
		if ((*container)->data == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to reallocate memory\n", LIB_NAME);
			return;
		}

		((int*)(*container)->data)[(*container)->size - 1] = value;
	}
}

void container_appendf(Container** container, float value) {
	if (*container == NULL) {
		*container = container_new(1, "float");
		if (*container == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to initialize empty container\n", LIB_NAME);
			return;
		}

		((float*)(*container)->data)[0] = value;
	}
	else if ((*container)->data == NULL) {
		(*container)->size = 1;

		(*container)->data = malloc(sizeof(float));
		if ((*container)->data == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to allocate data\n", LIB_NAME);
			return;
		}

		((float*)(*container)->data)[0] = value;
	}
	else {
		(*container)->data = realloc((*container)->data, ++(*container)->size * sizeof(float));
		if ((*container)->data == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to reallocate memory\n", LIB_NAME);
			return;
		}

		((float*)(*container)->data)[(*container)->size - 1] = value;
	}
}

