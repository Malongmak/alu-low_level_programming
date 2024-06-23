#include "dog.h"
#include <stddef.h>
/*Write a function that initialize a variable of type struct dog*/
/**
 * init_dog - Our function
 *
 * @d: pointer d
 * @name: pointer name
 * @age: variable age
 * @owner: pointer owner
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		(*d).name = name;
		(*d).age = age;
		(*d).owner = owner;
	}
}
