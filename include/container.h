#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* const LIB_NAME = "Container";

typedef struct Container_struct {
	size_t size;
  	const char* data_type;

	void* data;
} Container;

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
		fprintf(stderr, "%s error: container_new: Data type not supported\n", LIB_NAME);
		return NULL;
	}

	if (container->data == NULL) {
		fprintf(stderr, "%s error: container_new: Failed to allocate data\n", LIB_NAME);
		return NULL;
	}

	return container;
}

void container_delete(Container** container) {
	if (*container == NULL) {
		fprintf(stderr, "%s error: container_delete: Container is already non-existent\n", LIB_NAME);
		return;
	}

	if ((*container)->data != NULL) {
		free((*container)->data);
		(*container)->data = NULL;
	}
	else {
		fprintf(stderr, "%s error: container_delete: Data is already empty\n", LIB_NAME);
	}
	
	free(*container);
	*container = NULL;
}

