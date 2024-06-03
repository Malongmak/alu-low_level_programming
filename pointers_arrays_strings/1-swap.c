#include <stdio.h>
/* a function that swaps the values of two integers.*/
/**
 * swap_int - swaps the values of two integers
 * @a: parameter of int *a
 * @b: parameter of int *b
 * main -Entry pointer
 * Return: Always 0 (success)
 */

void swap_int(int *a, int *b)
{
	int y;

	y = *a;
	*a = *b;
	*b = y;
}
