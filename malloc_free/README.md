# Dynamic Memory Allocation in C (`malloc` and `free`)

## Overview

This document provides a detailed explanation and usage guide for dynamic memory allocation functions `malloc` and `free` in the C programming language. Understanding these functions is essential for managing memory in C programs, enabling efficient use of system resources and avoiding memory leaks.
[![Watch the video](https://img.youtube.com/vi/7RNesIP9Ot0/maxresdefault.jpg)](https://youtu.be/7RNesIP9Ot0)
## Table of Contents

- [Introduction](#introduction)
- [malloc Function](#malloc-function)
  - [Syntax](#syntax)
  - [Example](#example)
- [free Function](#free-function)
  - [Syntax](#syntax-1)
  - [Example](#example-1)
- [Important Points](#important-points)
- [Complete Example](#complete-example)
- [Best Practices](#best-practices)
- [References](#references)

## Introduction

Dynamic memory allocation allows a program to request memory from the heap at runtime. This is useful when the amount of memory required cannot be determined at compile time. The C standard library provides `malloc` and `free` for allocating and deallocating memory dynamically.

## malloc Function

The `malloc` (memory allocation) function allocates a specified number of bytes and returns a pointer to the allocated memory. The memory is uninitialized.

### Syntax

```c
void* malloc(size_t size);
```

- `size_t size`: Number of bytes to allocate.

### Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n = 5;

    printf("Allocating memory for %d integers.\n", n);

    // Allocate memory for n integers
    ptr = (int*)malloc(n * sizeof(int));

    // Check if the memory has been allocated
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize and display the allocated memory
    for (int i = 0; i < n; i++) {
        ptr[i] = i + 1;
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(ptr);

    return 0;
}
```

## free Function

The `free` function deallocates the memory previously allocated by `malloc`, `calloc`, or `realloc`. It does not change the value of the pointer; the pointer still points to the same memory location, but dereferencing it after `free` is undefined behavior.

### Syntax

```c
void free(void* ptr);
```

- `void* ptr`: Pointer to the memory to be deallocated.

### Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n = 5;

    printf("Allocating memory for %d integers.\n", n);

    // Allocate memory for n integers
    ptr = (int*)malloc(n * sizeof(int));

    // Check if the memory has been allocated
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize and display the allocated memory
    for (int i = 0; i < n; i++) {
        ptr[i] = i + 1;
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(ptr);

    return 0;
}
```

## Important Points

1. **Always Check for `NULL`**: Always check if `malloc` returned `NULL`, which indicates that the memory allocation failed.
2. **Free Allocated Memory**: Always use `free` to deallocate memory that is no longer needed to avoid memory leaks.
3. **Pointer after `free`**: After calling `free`, the pointer is still valid (not `NULL`), but dereferencing it is undefined behavior. It is a good practice to set the pointer to `NULL` after freeing it.

## Complete Example

Here is a complete example of allocating and deallocating memory in C:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int n = 10;

    printf("Allocating memory for %d integers.\n", n);

    // Allocate memory for n integers
    array = (int*)malloc(n * sizeof(int));

    // Check if the memory has been allocated successfully
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the allocated memory and print the values
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    // Optionally, set the pointer to NULL to avoid using the freed memory
    array = NULL;

    return 0;
}
```

## Best Practices

- **Check Return Value**: Always check the return value of `malloc` to ensure that memory allocation was successful.
- **Free Memory**: Always `free` allocated memory when it is no longer needed.
- **Set Pointer to NULL**: After freeing memory, set the pointer to `NULL` to avoid accidental dereferencing.
- **Avoid Memory Leaks**: Make sure every `malloc` call has a corresponding `free` call to prevent memory leaks.

## References

- [ISO/IEC 9899:2018 - Information technology — Programming languages — C](https://www.iso.org/standard/74528.html)
- [C Standard Library: malloc](https://en.cppreference.com/w/c/memory/malloc)
- [C Standard Library: free](https://en.cppreference.com/w/c/memory/free)

This document provides a fundamental understanding of dynamic memory allocation using `malloc` and `free` in C. For fur
