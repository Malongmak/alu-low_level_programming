#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Prints a name using a pointer to function
 * @name: The name string to print
 * @f: Pointer to a function that takes a char * argument
 *     and returns void
 *
 * Description: This function takes a name string and a pointer
 *              to a function. If `name` and `f` are not NULL,
 *              it calls the function `f` with the `name` as
 *              an argument.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

