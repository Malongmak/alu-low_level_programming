#include "main.h"
/*a function that prints n elements of*/
/*an array of integers, followed by a new line.*/
/**
 * print_array - prints n element
 *@a: parameter int *a
 * @n: parameter int n
 *main -Entry point
 *Return: void
 */
void print_array(int *a, int n)
{
	int j;

	for (j = 0; j < n; j++)
	{
	printf("%d", a[j]);
	if (j != (n - 1))
	{
	printf(", ");
	}
	}
	printf("\n");
}

