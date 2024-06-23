# Programming in C - Structures and typedef

## Overview
This project involves working with structures and typedef in C. By the end of this project, you should be able to understand and explain the use of structures and typedef in C programming. You will also be able to define, initialize, and manipulate structures, as well as create and free dynamic instances of structures.

## Learning Objectives
- Understand what structures are and when, why, and how to use them
- Learn how to use typedef to create new data type names
- Implement and manipulate structures in C
- Ensure code adheres to specified style and guidelines

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- Compilation on Ubuntu 20.04 LTS using gcc with flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files must end with a new line
- A `README.md` file at the root of the project folder is mandatory
- Code should follow the Betty style (checked using `betty-style.pl` and `betty-doc.pl`)
- No global variables allowed
- No more than 5 functions per file
- Only allowed C standard library functions: `printf`, `malloc`, `free`, `exit`
- Header files must be include guarded

## Resources
- `0x0d. Structures.pdf`
- `struct (C programming language)`
- `Documentation: structures`
- `0x0d. Typedef and structures.pdf`
- `typedef`
- Programming in C by Stephen Kochan - Chapter 8, Working with Structures p163-189
- The Lost Art of C Structure Packing (Advanced - not mandatory)

## Tasks

### Task 0: Poppy
Define a new type `struct dog` with the following elements:
- `name`, type: `char *`
- `age`, type: `float`
- `owner`, type: `char *`

File: `dog.h`

### Task 1: A dog is the only thing on earth that loves you more than you love yourself
Write a function to initialize a variable of type `struct dog`.

Prototype: `void init_dog(struct dog *d, char *name, float age, char *owner);`

File: `1-init_dog.c`

### Task 2: A dog will teach you unconditional love. If you can have that in your life, things won't be too bad
Write a function that prints a `struct dog`.

Prototype: `void print_dog(struct dog *d);`

- If an element of `d` is `NULL`, print `(nil)` instead of this element.
- If `d` is `NULL` print nothing.

File: `2-print_dog.c`

### Task 3: Outside of a dog, a book is a man's best friend. Inside of a dog it's too dark to read
Define a new type `dog_t` as a new name for the type `struct dog`.

File: `dog.h`

### Task 4: A door is what a dog is perpetually on the wrong side of
Write a function that creates a new dog.

Prototype: `dog_t *new_dog(char *name, float age, char *owner);`

- You have to store a copy of `name` and `owner`
- Return `NULL` if the function fails

File: `4-new_dog.c`

### Task 5: How many legs does a dog have if you call his tail a leg? Four. Saying that a tail is a leg doesn't make it a leg
Write a function that frees dogs.

Prototype: `void free_dog(dog_t *d);`

File: `5-free_dog.c`

## Compilation and Testing
To compile the code for testing, use the following commands:

```sh
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c -o a
./a
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-init_dog.c -o b
./b
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-print_dog.c -o c
./c
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c -o d
./d
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-new_dog.c -o e
./e
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-free_dog.c 4-new_dog.c -o f
valgrind ./f
```

Ensure that your code adheres to the project requirements and the Betty style guidelines. Push your changes to the GitHub repository to track your progress and receive feedback.
