// Copyright (C) 2023 j3dR
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* const LIB_NAME = "yaccl.h";  // library name

enum ContainerDataType {
	CHAR,
	SHORT,
	INT,
	LONG,
	FLOAT,
	DOUBLE
};

// Template
typedef struct ContainerStruct {
	size_t size;
  	enum ContainerDataType data_type;

	void* data;
} Container;

// Constructor
Container* container_new(size_t size, enum ContainerDataType data_type) {
	Container* container = malloc(sizeof(Container));
	if (container == NULL) {
		fprintf(stderr, "%s error: container_new: Failed to allocate memory for the container struct\n", LIB_NAME);
		return NULL;
	}

	container->size = size;
	container->data_type = data_type;

	switch (data_type) {
		case CHAR:
			container->data = calloc(size, sizeof(char));
			break;
		case SHORT:
			container->data = calloc(size, sizeof(short));
			break;
		case INT:
			container->data = calloc(size, sizeof(int));
			break;
		case LONG:
			container->data = calloc(size, sizeof(long));
			break;
		case FLOAT:
			container->data = calloc(size, sizeof(float));
			break;
		case DOUBLE:
			container->data = calloc(size, sizeof(double));
			break;
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

// Clear all the data
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

// Remove an element at a given index
void container_remove(Container** container, size_t index) {
	if (*container == NULL) {
		fprintf(stderr, "%s error: container_remove: Container is non-existent\n", LIB_NAME);
		return;
	}

	if ((*container)->data == NULL) {
		fprintf(stderr, "%s error: container_remove: Data is empty\n", LIB_NAME);
		return;
	}

	if (index > (*container)->size - 1) {
		fprintf(stderr, "%s error: container_remove: Incorrect index\n", LIB_NAME);
		return;
	}

	size_t data_size;
	switch ((*container)->data_type) {
		case CHAR:
			data_size = sizeof(char);

			if (index == (size_t)0) {
				for (size_t i = 0; i < (*container)->size - 1; ++i) {
					((char*)(*container)->data)[i] = ((char*)(*container)->data)[i + 1];
				}
			}
			else if (index < (*container)->size - 1) {
				for (size_t i = index; i < (*container)->size - 1; ++i) {
					((char*)(*container)->data)[i] = ((char*)(*container)->data)[i + 1];
				}
			}
			break;
		case SHORT:
			data_size = sizeof(short);

			if (index == (size_t)0) {
				for (size_t i = 0; i < (*container)->size - 1; ++i) {
					((short*)(*container)->data)[i] = ((short*)(*container)->data)[i + 1];
				}
			}
			else if (index < (*container)->size - 1) {
				for (size_t i = index; i < (*container)->size - 1; ++i) {
					((short*)(*container)->data)[i] = ((short*)(*container)->data)[i + 1];
				}
			}
			break;
		case INT:
			data_size = sizeof(int);

			if (index == (size_t)0) {
				for (size_t i = 0; i < (*container)->size - 1; ++i) {
					((int*)(*container)->data)[i] = ((int*)(*container)->data)[i + 1];
				}
			}
			else if (index < (*container)->size - 1) {
				for (size_t i = index; i < (*container)->size - 1; ++i) {
					((int*)(*container)->data)[i] = ((int*)(*container)->data)[i + 1];
				}
			}
			break;
		case LONG:
			data_size = sizeof(long);

			if (index == (size_t)0) {
				for (size_t i = 0; i < (*container)->size - 1; ++i) {
					((long*)(*container)->data)[i] = ((long*)(*container)->data)[i + 1];
				}
			}
			else if (index < (*container)->size - 1) {
				for (size_t i = index; i < (*container)->size - 1; ++i) {
					((long*)(*container)->data)[i] = ((long*)(*container)->data)[i + 1];
				}
			}
			break;
		case FLOAT:
			data_size = sizeof(float);

			if (index == (size_t)0) {
				for (size_t i = 0; i < (*container)->size - 1; ++i) {
					((float*)(*container)->data)[i] = ((float*)(*container)->data)[i + 1];
				}
			}
			else if (index < (*container)->size - 1) {
				for (size_t i = index; i < (*container)->size - 1; ++i) {
					((float*)(*container)->data)[i] = ((float*)(*container)->data)[i + 1];
				}
			}
			break;
		case DOUBLE:
			data_size = sizeof(double);

			if (index == (size_t)0) {
				for (size_t i = 0; i < (*container)->size - 1; ++i) {
					((double*)(*container)->data)[i] = ((double*)(*container)->data)[i + 1];
				}
			}
			else if (index < (*container)->size - 1) {
				for (size_t i = index; i < (*container)->size - 1; ++i) {
					((double*)(*container)->data)[i] = ((double*)(*container)->data)[i + 1];
				}
			}
			break;
	}

	void* temp = realloc((*container)->data, ((*container)->size - 1) * data_size);
	if (temp == NULL) {
		fprintf(stderr, "%s error: container_remove: Failed to reallocate memory\n", LIB_NAME);
		return;
	}

	(*container)->data = temp;
	
	if (--(*container)->size == 0) {
		free((*container)->data);
		(*container)->data = NULL;
	}
}

// Assign functions --------------------------------------------------------------------------------------------------------------

#define container_assign(container_reference, value, size_t_index) _Generic(value,                                           \
														char: container_assignc(container_reference, value, size_t_index),   \
														short: container_assigns(container_reference, value, size_t_index),  \
														int: container_assigni(container_reference, value, size_t_index),    \
														long: container_assignl(container_reference, value, size_t_index),   \
														float: container_assignf(container_reference, value, size_t_index),  \
														double: container_assignd(container_reference, value, size_t_index)) \

// Assign char
void container_assignc(Container** container, char value, size_t index) {
	if (*container == NULL) {
		fprintf(stderr, "%s error: container_assign: Container is non-existent\n", LIB_NAME);
		return;
	}

	if ((*container)->data == NULL) {
		fprintf(stderr, "%s error: container_assign: Data is empty\n", LIB_NAME);
		return;
	}

	if ((*container)->data_type != CHAR) {
		fprintf(stderr, "%s error: container_assign: Incorrect value data type\n", LIB_NAME);
		return;
	}

	if (index > (*container)->size - 1) {
		fprintf(stderr, "%s error: container_assign: Incorrect index\n", LIB_NAME);
		return;
	}

	((char*)(*container)->data)[index] = value;
}

// Assign short
void container_assigns(Container** container, short value, size_t index) {
	if (*container == NULL) {
		fprintf(stderr, "%s error: container_assign: Container is non-existent\n", LIB_NAME);
		return;
	}

	if ((*container)->data == NULL) {
		fprintf(stderr, "%s error: container_assign: Data is empty\n", LIB_NAME);
		return;
	}

	if ((*container)->data_type != SHORT) {
		fprintf(stderr, "%s error: container_assign: Incorrect value data type\n", LIB_NAME);
		return;
	}

	if (index > (*container)->size - 1) {
		fprintf(stderr, "%s error: container_assign: Incorrect index\n", LIB_NAME);
		return;
	}

	((short*)(*container)->data)[index] = value;
}

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

	if ((*container)->data_type != INT) {
		fprintf(stderr, "%s error: container_assign: Incorrect value data type\n", LIB_NAME);
		return;
	}

	if (index > (*container)->size - 1) {
		fprintf(stderr, "%s error: container_assign: Incorrect index\n", LIB_NAME);
		return;
	}

	((int*)(*container)->data)[index] = value;
}

// Assign long
void container_assignl(Container** container, long value, size_t index) {
	if (*container == NULL) {
		fprintf(stderr, "%s error: container_assign: Container is non-existent\n", LIB_NAME);
		return;
	}

	if ((*container)->data == NULL) {
		fprintf(stderr, "%s error: container_assign: Data is empty\n", LIB_NAME);
		return;
	}

	if ((*container)->data_type != LONG) {
		fprintf(stderr, "%s error: container_assign: Incorrect value data type\n", LIB_NAME);
		return;
	}

	if (index > (*container)->size - 1) {
		fprintf(stderr, "%s error: container_assign: Incorrect index\n", LIB_NAME);
		return;
	}

	((long*)(*container)->data)[index] = value;
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

	if ((*container)->data_type != FLOAT) {
		fprintf(stderr, "%s error: container_assign: Incorrect value data type\n", LIB_NAME);
		return;
	}

	if (index > (*container)->size - 1) {
		fprintf(stderr, "%s error: container_assign: Incorrect index\n", LIB_NAME);
		return;
	}

	((float*)(*container)->data)[index] = value;
}

// Assign double
void container_assignd(Container** container, double value, size_t index) {
	if (*container == NULL) {
		fprintf(stderr, "%s error: container_assign: Container is non-existent\n", LIB_NAME);
		return;
	}

	if ((*container)->data == NULL) {
		fprintf(stderr, "%s error: container_assign: Data is empty\n", LIB_NAME);
		return;
	}

	if ((*container)->data_type != DOUBLE) {
		fprintf(stderr, "%s error: container_assign: Incorrect value data type\n", LIB_NAME);
		return;
	}

	if (index > (*container)->size - 1) {
		fprintf(stderr, "%s error: container_assign: Incorrect index\n", LIB_NAME);
		return;
	}

	((double*)(*container)->data)[index] = value;
}

// Getters -----------------------------------------------------------------------------------------------------------------------

char container_getc(Container* container, size_t index) {
	if (container == NULL) {
		fprintf(stderr, "%s error: container_getc: Container is non-existent\n", LIB_NAME);
		return 1;
	}

	if (container->data == NULL) {
		fprintf(stderr, "%s error: container_getc: Data is empty\n", LIB_NAME);
		return 2;
	}

	if (index > container->size - 1) {
		fprintf(stderr, "%s error: container_getc: Incorrect index\n", LIB_NAME);
		return 3;
	}

	return ((char*)container->data)[index];
}

short container_gets(Container* container, size_t index) {
	if (container == NULL) {
		fprintf(stderr, "%s error: container_gets: Container is non-existent\n", LIB_NAME);
		return 1;
	}

	if (container->data == NULL) {
		fprintf(stderr, "%s error: container_gets: Data is empty\n", LIB_NAME);
		return 2;
	}

	if (index > container->size - 1) {
		fprintf(stderr, "%s error: container_gets: Incorrect index\n", LIB_NAME);
		return 3;
	}

	return ((short*)container->data)[index];
}

int container_geti(Container* container, size_t index) {
	if (container == NULL) {
		fprintf(stderr, "%s error: container_geti: Container is non-existent\n", LIB_NAME);
		return 1;
	}

	if (container->data == NULL) {
		fprintf(stderr, "%s error: container_geti: Data is empty\n", LIB_NAME);
		return 2;
	}

	if (index > container->size - 1) {
		fprintf(stderr, "%s error: container_geti: Incorrect index\n", LIB_NAME);
		return 3;
	}

	return ((int*)container->data)[index];
}

long container_getl(Container* container, size_t index) {
	if (container == NULL) {
		fprintf(stderr, "%s error: container_getl: Container is non-existent\n", LIB_NAME);
		return 1;
	}

	if (container->data == NULL) {
		fprintf(stderr, "%s error: container_getl: Data is empty\n", LIB_NAME);
		return 2;
	}

	if (index > container->size - 1) {
		fprintf(stderr, "%s error: container_getl: Incorrect index\n", LIB_NAME);
		return 3;
	}

	return ((long*)container->data)[index];
}

float container_getf(Container* container, size_t index) {
	if (container == NULL) {
		fprintf(stderr, "%s error: container_getf: Container is non-existent\n", LIB_NAME);
		return 1;
	}

	if (container->data == NULL) {
		fprintf(stderr, "%s error: container_getf: Data is empty\n", LIB_NAME);
		return 2;
	}

	if (index > container->size - 1) {
		fprintf(stderr, "%s error: container_getf: Incorrect index\n", LIB_NAME);
		return 3;
	}

	return ((float*)container->data)[index];
}

double container_getd(Container* container, size_t index) {
	if (container == NULL) {
		fprintf(stderr, "%s error: container_getd: Container is non-existent\n", LIB_NAME);
		return 1;
	}

	if (container->data == NULL) {
		fprintf(stderr, "%s error: container_getd: Data is empty\n", LIB_NAME);
		return 2;
	}

	if (index > container->size - 1) {
		fprintf(stderr, "%s error: container_getd: Incorrect index\n", LIB_NAME);
		return 3;
	}

	return ((double*)container->data)[index];
}

// Append functions --------------------------------------------------------------------------------------------------------------

#define container_append(container_reference, value) _Generic(value,                                           \
												    	char: container_appendc(container_reference, value),   \
														short: container_appends(container_reference, value),  \
														int: container_appendi(container_reference, value),    \
														long: container_appendl(container_reference, value),   \
														float: container_appendf(container_reference, value),  \
														double: container_appendd(container_reference, value)) \

// Append char
void container_appendc(Container** container, char value) {
	if (*container == NULL) {
		*container = container_new(1, CHAR);
		if (*container == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to initialize empty container\n", LIB_NAME);
			return;
		}

		((char*)(*container)->data)[0] = value;
	}
	else if ((*container)->data == NULL) {
		(*container)->size = 1;

		(*container)->data = malloc(sizeof(char));
		if ((*container)->data == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to allocate data\n", LIB_NAME);
			return;
		}

		((char*)(*container)->data)[0] = value;
	}
	else {
		void* temp = realloc((*container)->data, ((*container)->size + 1) * sizeof(char));
		if (temp == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to reallocate memory\n", LIB_NAME);
			return;
		}

		(*container)->data = temp;

		((char*)(*container)->data)[(*container)->size++] = value;
	}
}

// Append short
void container_appends(Container** container, short value) {
	if (*container == NULL) {
		*container = container_new(1, SHORT);
		if (*container == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to initialize empty container\n", LIB_NAME);
			return;
		}

		((short*)(*container)->data)[0] = value;
	}
	else if ((*container)->data == NULL) {
		(*container)->size = 1;

		(*container)->data = malloc(sizeof(short));
		if ((*container)->data == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to allocate data\n", LIB_NAME);
			return;
		}

		((short*)(*container)->data)[0] = value;
	}
	else {
		void* temp = realloc((*container)->data, ((*container)->size + 1) * sizeof(short));
		if (temp == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to reallocate memory\n", LIB_NAME);
			return;
		}

		(*container)->data = temp;

		((short*)(*container)->data)[(*container)->size++] = value;
	}
}

// Append int
void container_appendi(Container** container, int value) {
	if (*container == NULL) {
		*container = container_new(1, INT);
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
		void* temp = realloc((*container)->data, ((*container)->size + 1) * sizeof(int));
		if (temp == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to reallocate memory\n", LIB_NAME);
			return;
		}

		(*container)->data = temp;

		((int*)(*container)->data)[(*container)->size++] = value;
	}
}

// Append long
void container_appendl(Container** container, long value) {
	if (*container == NULL) {
		*container = container_new(1, LONG);
		if (*container == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to initialize empty container\n", LIB_NAME);
			return;
		}

		((long*)(*container)->data)[0] = value;
	}
	else if ((*container)->data == NULL) {
		(*container)->size = 1;

		(*container)->data = malloc(sizeof(long));
		if ((*container)->data == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to allocate data\n", LIB_NAME);
			return;
		}

		((long*)(*container)->data)[0] = value;
	}
	else {
		void* temp = realloc((*container)->data, ((*container)->size + 1) * sizeof(long));
		if (temp == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to reallocate memory\n", LIB_NAME);
			return;
		}

		(*container)->data = temp;

		((long*)(*container)->data)[(*container)->size++] = value;
	}
}

// Append float
void container_appendf(Container** container, float value) {
	if (*container == NULL) {
		*container = container_new(1, FLOAT);
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
		void* temp = realloc((*container)->data, ((*container)->size + 1) * sizeof(float));
		if (temp == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to reallocate memory\n", LIB_NAME);
			return;
		}

		(*container)->data = temp;

		((float*)(*container)->data)[(*container)->size++] = value;
	}
}

// Append double
void container_appendd(Container** container, double value) {
	if (*container == NULL) {
		*container = container_new(1, DOUBLE);
		if (*container == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to initialize empty container\n", LIB_NAME);
			return;
		}

		((double*)(*container)->data)[0] = value;
	}
	else if ((*container)->data == NULL) {
		(*container)->size = 1;

		(*container)->data = malloc(sizeof(double));
		if ((*container)->data == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to allocate data\n", LIB_NAME);
			return;
		}

		((double*)(*container)->data)[0] = value;
	}
	else {
		void* temp = realloc((*container)->data, ((*container)->size + 1) * sizeof(double));
		if (temp == NULL) {
			fprintf(stderr, "%s error: container_append: Failed to reallocate memory\n", LIB_NAME);
			return;
		}

		(*container)->data = temp;

		((double*)(*container)->data)[(*container)->size++] = value;
	}
}
