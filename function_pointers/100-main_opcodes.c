#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints its own opcodes.
 * @argc: The number of arguments.
 * @argv: An array of arguments.
 *
 * Description: This function prints the opcodes of its own main function.
 *              It takes one argument, the number of bytes to print. If the
 *              number of arguments is incorrect or if the number of bytes is
 *              negative, it prints an error message and exits with a status
 *              of 1 or 2 respectively.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char *argv[])
{
    int bytes, i;
    char *arr;

    if (argc != 2)
    {
        printf("Error\n");
        exit(1);
    }

    bytes = atoi(argv[1]);

    if (bytes < 0)
    {
        printf("Error\n");
        exit(2);
    }

    arr = (char *)main;

    for (i = 0; i < bytes; i++)
    {
        if (i == bytes - 1)
        {
            printf("%02hhx\n", arr[i]);
            break;
        }
        printf("%02hhx ", arr[i]);
    }
    return (0);
}

