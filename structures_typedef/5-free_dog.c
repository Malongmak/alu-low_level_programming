#include "dog.h"
#include <stdlib.h>
/*Write a function that frees dogs.*/
/**
 * free_dog - Our freeing function for dynamic memory
 * @d: a structure pointer
 * Return: void
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->owner);
		free(d->name);
		free(d);
	}
}
