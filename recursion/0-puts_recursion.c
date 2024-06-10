#include "main.h"
/*Write a function that prints a string, followed by a new line.*/
/**
 * _puts_recursion - Our string printing function
 *
 * @s: Our first parameter
 * Return: returns void or nothing
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		putchar('\n');
	}
	else
	{
		putchar(*s);
		_puts_recursion(++s);
	}
}
