#include "main.h"
/*Write a function that checks for alphabetic character.*/
/**
 * _isalpha - checks for alphabetic character
 *
 * @c: here is the parameter for the function
 * Return: 1 if c is a letter, lowercase or uppercase 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
