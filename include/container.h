#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* const LIB_NAME = "Container";

typedef struct Container_struct {

  size_t size;
  const char* data_type;

  int* int_data;
  float* float_data;

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

		container->int_data = calloc(size, sizeof(container->int_data));
		if (container->int_data == NULL) {

			fprintf(stderr, "%s error: container_new: Failed to allocate data of type integer\n", LIB_NAME);
			return NULL;
		}
	}
	else if (strcmp(data_type, "float") == 0) {

		container->float_data = calloc(size, sizeof(container->float_data));
		if (container->float_data == NULL) {

			fprintf(stderr, "%s error: container_new: Failed to allocate data of type float\n", LIB_NAME);
			return NULL;
		}
	}
	else {

		fprintf(stderr, "%s error: container_new: Data type not supported\n", LIB_NAME);
		return NULL;
	}

	return container;
}

void container_delete(Container** container) {

	if (*container == NULL) {

		fprintf(stderr, "%s error: container_delete: Container is already non-existent\n", LIB_NAME);
		return;
	}

	if (strcmp((*container)->data_type, "int") == 0) {

		if ((*container)->int_data != NULL) {

			free((*container)->int_data);
			(*container)->int_data = NULL;
		}
		else {

			fprintf(stderr, "%s error: container_delete: Data is already empty\n", LIB_NAME);
		}
	}
	else if (strcmp((*container)->data_type, "float") == 0) {

		if ((*container)->float_data != NULL) {

			free((*container)->float_data);
			(*container)->float_data = NULL;
		}
		else {

			fprintf(stderr, "%s error: container_delete: Data is already empty\n", LIB_NAME);
		}
	}

	free(*container);
	*container = NULL;
}

