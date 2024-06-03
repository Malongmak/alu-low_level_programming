#include <stdio.h>
/* function that returns the length of a string.*/
/**
 * _strlen - function that returns the length of a string.
 * @s: parameter that returns the length
 * main -Entry point
 * Return: Always 0 (success)
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
