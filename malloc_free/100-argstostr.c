#include "main.h"

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: the argument count
 * @av: the argument vector
 *
 * Return: a pointer to the concatenated string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
    int i, j, k = 0, total_length = 0;
    char *result;

    if (ac == 0 || av == NULL)
        return (NULL);

    /* Calculate total length needed for the concatenated string */
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
            total_length++;
        total_length++;  /* for the newline character */
    }
    total_length++;  /* for the null terminator */

    /* Allocate memory for the result string */
    result = malloc(total_length * sizeof(char));
    if (result == NULL)
        return (NULL);

    /* Copy each argument into the result string followed by newline */
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
            result[k++] = av[i][j];
        result[k++] = '\n';
    }
    result[k] = '\0';  /* Null-terminate the result string */

    return (result);
}

