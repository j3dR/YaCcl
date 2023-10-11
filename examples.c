#include "yaccl.h"

int main() {

	// Creating a new container with fixed size ----------------------------------------------------------------------------------

	Container* container = container_new(10, INT);  // creates a container of size 10 with an int data type
	                                                // the data memory is filled with zeros
													// returns NULL when an error occures

	container_delete(&container);  // delete the container when it's no longer needed

	// Clearing all the data -----------------------------------------------------------------------------------------------------

	Container* container = container_new(15, FLOAT);

	container_clear(&container);  // frees the data memory leaving container of size 0
	                              // the data type stays the same as specified earlier

	container_delete(&container);  // delete the container when it's no longer needed
								   // the container struct itself is still in the memory, thus have to be freed

	// Creating a new container by appending new element(s) -----------------------------------------------------------------------

	Container* container = NULL;  // have to be NULL or 0, otherwise the value is practically random
	container_append(&container, (char)'a');  // creates a new container of size 1
									   		  // and with a data type the same as that of the value to be appended
											  // in this case it's char

	// Also can be done after clearing all the data:

	container_clear(&container);
	container_append(&container, (char)'b');

	container_delete(&container);  // delete the container when it's no longer needed

	// Assigning a new value at a given index -------------------------------------------------------------------------------------

	Container* container = container_new(5, LONG);

	container_assign(&container, 153l, 2);  // assigns long int of value 153 at index 2

	container_delete(&container);  // delete the container when it's no longer needed

	// Removing an element at a given index ---------------------------------------------------------------------------------------

	Container* container = container_new(20, DOUBLE);

	container_remove(&container, 9);  // removes one element at index 9

	container_delete(&container);  // delete the container when it's no longer needed

	// Getting the value at a given index -----------------------------------------------------------------------------------------

	Container* container = NULL;

	for (int i = 0; i < 15; ++i) {
		container_append(&container, i);
	}

	printf("%d\n", container_geti(container, 10));  // should print 10

	// In this case there is no universal function, all data types have corresponding getters:

	// CHAR
	container_getc(container, 0);

	// SHORT
	container_gets(container, 0);

	// INT
	container_geti(container, 0);
	
	// LONG
	container_getl(container, 0);

	// FLOAT
	container_getf(container, 0);

	// DOUBLE
	container_getd(container, 0);

	container_delete(&container);  // delete the container when it's no longer needed

	// Getting the size of a container --------------------------------------------------------------------------------------------

	Container* container = container_new(25, SHORT);

	printf("%lu\n", container->size);  // should print 25

	container_delete(&container);  // delete the container when it's no longer needed

	// Getting the data type of a container ---------------------------------------------------------------------------------------

	Container* container = container_new(10, CHAR);

	printf("%d\n", container->data_type);  // should print 0 due to CHAR being the first state in enum ContainerDataType

	// More elegant example mapping enum states to the corresponding string:

	switch (container->data_type) {
		case CHAR:
			puts("char");
			break;
		case SHORT:
			puts("short");
			break;
		case INT:
			puts("int");
			break;
		case LONG:
			puts("long");
			break;
		case FLOAT:
			puts("float");
			break;
		case DOUBLE:
			puts("double");
			break;
	}

	container_delete(&container);  // delete the container when it's no longer needed

	return 0;
}

