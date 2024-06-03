#include <stdio.h>
/* function that prints a string, followed by a new line*/
/**
 * _puts - prints a string
 * @str: parameter that prints a string
 * main -Entry point
 * Return: Always 0 (success)
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
		_putchar('\n');
}
