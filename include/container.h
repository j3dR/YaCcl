#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* const LIB_NAME = "Container";

typedef struct Container_struct {

  size_t size;
  const char* data_type;

  int* data_int;
  float* data_float;

} Container;

Container* container_new(size_t size, const char* data_type) {

	Container* container = malloc(size);
	if (container == NULL) {

		fprintf(stderr, "%s error: container_new: Failed to allocate memory for the container struct", LIB_NAME);
		return NULL;
	}

	container->size = size;
	container->data_type = data_type;

	if (strcmp(data_type, "int") == 0) {

		container->data_int = calloc(size, sizeof(container->data_int));
		if (container->data_int == NULL) {

			fprintf(stderr, "%s error: container_new: Failed to allocate data of type integer", LIB_NAME);
			return NULL;
		}
	}
	else if (strcmp(data_type, "float") == 0) {

		container->data_float = calloc(size, sizeof(container->data_float));
		if (container->data_float == NULL) {

			fprintf(stderr, "%s error: container_new: Failed to allocate data of type float", LIB_NAME);
			return NULL;
		}
	}
	else {

		fprintf(stderr, "%s error: container_new: Data type not supported", LIB_NAME);
		return NULL;
	}

	return container;
}

