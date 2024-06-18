#include "main.h"
/*a function that concatenates two strings.*/
/**
 * str_concat - the function
 * @s1: first paramter
 * @s2: second parameter
 * Return: pointer of type character
 */
char *str_concat(char *s1, char *s2)
{
	char *ptr;
	unsigned int total_len, len_s1, len_s2, a, b;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1);
		*s1 = '\0';
	}
	if (s2 == NULL)
	{
		s2 = (char *)malloc(1);
		*s2 = '\0';
	}
	len_s1 = strlen(s1);
	len_s2 = strlen(s2) + 1;
	total_len = len_s1 + len_s2;
	ptr = (char *)malloc(total_len);
	a = 0;
	b = 0;
	if (ptr == NULL)
		return (NULL);
	while (a < len_s1)
	{
		ptr[a] = s1[a];
		a++;
	}
	while (a < total_len && b < len_s2)
	{
		ptr[a] = s2[b];
		a++;
		b++;
	}
	return (ptr);
}
