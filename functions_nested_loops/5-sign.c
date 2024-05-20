#include "main.h"
/*Write a function that prints the sign of a number.*/
/**
 * print_sign - A Function that prints the sign of numbers
 *
 * @n: the parameter n of the function
 * Return: returns 1 if number greater than zero
 * 0 if number is equal to zero
 * -1 if number is less than zero
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	} else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	_putchar('-');
	return (-1);
}
