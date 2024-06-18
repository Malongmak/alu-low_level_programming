#include "main.h"
/* function that returns a pointer to a newly allocated space i*/
/*n memory, which contains a copy of the string given as a parameter.*/
/**
 * _strdup - the function
 * @str: first parameter
 * Return: returns pointer of type char
 */
char *_strdup(char *str)
{
	unsigned int l;
	unsigned int k;
	char *ptr;

	if (str == NULL)
	{
		return (NULL);
	}
	l = strlen(str) + 1;
	ptr = (char *)malloc(l);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (k = 0; k < l; k++)
	{
		ptr[k] = str[k];
	}
	return (ptr);
}
