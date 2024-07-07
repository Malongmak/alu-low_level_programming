#include "function_pointers.h"
/*Write a function that searches for an integer.*/
/**
 * int_index - function
 * @array: first parameter
 * @size: second parameter
 * @cmp: third parameter
 * Return: -1 if no elem matches, 0 if nothing works
 * -1 if size = 0, return the index of first match
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int j = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (j < size)
			{
				if (cmp(array[j]))
					return (j);
				j++;
			}
		}
	}
	return (-1);
}
