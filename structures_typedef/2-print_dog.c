#include "dog.h"
#include <stddef.h>
#include <stdio.h>
/*Write a function that prints a struct dog*/
/**
 * print_dog - Our function
 * @d: a pointer of structure data type
 *
 * Return: returns void
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", (d->name) ? d->name : "(nil)");
		printf("Age: %f\n", (d->age) ? d->age : 0);
		printf("Owner: %s\n", (d->owner) ? d->owner : "(nil)");
	}
}
