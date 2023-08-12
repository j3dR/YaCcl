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

// ------------------------------------------------------------------------- Setters ---------------------------------------------------------------------------------

#define container_assign(container, value, index) _Generic(value,                                              \
														   int: container_assigni(container, value, index),    \
														   float: container_assignf(container, value, index))  \

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

