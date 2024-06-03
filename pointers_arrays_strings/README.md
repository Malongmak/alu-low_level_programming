ALU Low-Level Programming: Pointers, Arrays, and Strings
Welcome to the repository for low-level programming exercises focusing on pointers, arrays, and strings. This README provides an overview of each task, including code examples and explanations.

Table of Contents
98 Battery St.
Don't Swap Horses in Crossing a Stream
This Report, by Its Very Length, Defends Itself Against the Risk of Being Read
I Do Not Fear Computers. I Fear the Lack of Them
I Can Only Go One Way. I've Not Got a Reverse Gear
Half the Lies They Tell About Me Aren't True
Winning is Only Half of It. Having Fun is the Other Half
Arrays Are Not Pointers
strcpy
98 Battery St.
Task
Write a function that takes a pointer to an int as a parameter and updates the value it points to 98.

Prototype
c
Copy code
void reset_to_98(int *n);
Example
c
Copy code
#include "main.h"
#include <stdio.h>

int main(void)
{
    int n;

    n = 402;
    printf("n=%d\n", n);
    reset_to_98(&n);
    printf("n=%d\n", n);
    return (0);
}
Compilation and Output
bash
Copy code
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-reset_to_98.c -o 0-98
./0-98
Output:

makefile
Copy code
n=402
n=98
Don't Swap Horses in Crossing a Stream
Task
Write a function that swaps the values of two integers.

Prototype
c
Copy code
void swap_int(int *a, int *b);
Example
c
Copy code
#include "main.h"
#include <stdio.h>

int main(void)
{
    int a;
    int b;

    a = 98;
    b = 42;
    printf("a=%d, b=%d\n", a, b);
    swap_int(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    return (0);
}
Compilation and Output
bash
Copy code
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-swap.c -o 1-swap
./1-swap
Output:

css
Copy code
a=98, b=42
a=42, b=98
This Report, by Its Very Length, Defends Itself Against the Risk of Being Read
Task
Write a function that returns the length of a string.

Prototype
c
Copy code
int _strlen(char *s);
Example
c
Copy code
#include "main.h"
#include <stdio.h>

int main(void)
{
    char *str;
    int len;

    str = "My first strlen!";
    len = _strlen(str);
    printf("%d\n", len);
    return (0);
}
Compilation and Output
bash
Copy code
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-strlen.c -o 2-strlen
./2-strlen
Output:

Copy code
16
I Do Not Fear Computers. I Fear the Lack of Them
Task
Write a function that prints a string, followed by a new line, to stdout.

Prototype
c
Copy code
void _puts(char *str);
Example
c
Copy code
#include "main.h"

int main(void)
{
    char *str;

    str = "I do not fear computers. I fear the lack of them - Isaac Asimov";
    _puts(str);
    return (0);
}
Compilation and Output
bash
Copy code
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 3-main.c 3-puts.c -o 3-puts
./3-puts
