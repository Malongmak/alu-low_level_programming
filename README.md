# Low-Level Programming: Hello World

Welcome to the **Hello World** section of the Low-Level Programming repository! This module introduces fundamental programming concepts in C, laying the groundwork for more advanced topics. Whether you're a beginner or refreshing your skills, this guide will help you understand the basics and get started with C programming.
![Alt text](./image.jpg)


## Table of Contents

1. [Introduction](#introduction)
2. [Setup and Installation](#setup-and-installation)
3. [Project Structure](#project-structure)
4. [Tasks](#tasks)
    - [0. Preprocessor](#0-preprocessor)
    - [1. Compiler](#1-compiler)
    - [2. Assembler](#2-assembler)
    - [3. Name](#3-name)
    - [4. Hello, puts](#4-hello-puts)
    - [5. Hello, printf](#5-hello-printf)
    - [6. Size](#6-size)
    - [7. Intel](#7-intel)
    - [8. UNIX is basically a simple operating system, but you have to be a genius to understand the simplicity](#8-unix-is-basically-a-simple-operating-system-but-you-have-to-be-a-genius-to-understand-the-simplicity)
5. [Compilation and Execution](#compilation-and-execution)
6. [Contribution](#contribution)
7. [License](#license)

## Introduction

This module covers the following essential topics in C programming:
- Preprocessing
- Compilation
- Assembly
- Linking

You'll learn how to write, compile, and run simple C programs. By the end of this module, you will be comfortable with basic C syntax and compilation processes.

## Setup and Installation

Before you begin, ensure you have the following installed on your system:
- GCC (GNU Compiler Collection)
- Make (Build automation tool)

### Installation

#### Ubuntu
```bash
sudo apt update
sudo apt install build-essential
```

#### macOS
```bash
xcode-select --install
```

#### Windows
Download and install [MinGW](http://www.mingw.org/).

## Project Structure

```plaintext
hello_world/
├── 0-preprocessor
├── 1-compiler
├── 2-assembler
├── 3-name
├── 4-puts.c
├── 5-printf.c
├── 6-size.c
├── 100-intel
└── 101-quote.c
```

## Tasks

### 0. Preprocessor

#### Description
Write a script that runs a C file through the preprocessor and saves the result into another file.

#### Usage
```bash
gcc -E <source_file> -o <output_file>
```

### 1. Compiler

#### Description
Write a script that compiles a C file but does not link.

#### Usage
```bash
gcc -S <source_file>
```

### 2. Assembler

#### Description
Write a script that generates the assembly code of a C code and saves it in an output file.

#### Usage
```bash
gcc -S <source_file> -o <output_file>
```

### 3. Name

#### Description
Write a script that compiles a C file and creates an executable named `cisfun`.

#### Usage
```bash
gcc <source_file> -o cisfun
```

### 4. Hello, puts

#### Description
Write a C program that prints exactly `"Programming is like building a multilingual puzzle"`, followed by a new line, using the `puts` function.

#### File
```c
#include <stdio.h>

int main(void)
{
    puts("\"Programming is like building a multilingual puzzle");
    return (0);
}
```

### 5. Hello, printf

#### Description
Write a C program that prints exactly `with proper grammar, but the outcome is a piece of art,`, followed by a new line, using the `printf` function.

#### File
```c
#include <stdio.h>

int main(void)
{
    printf("with proper grammar, but the outcome is a piece of art,\n");
    return (0);
}
```

### 6. Size

#### Description
Write a C program that prints the size of various types on the computer it is compiled and run on.

#### File
```c
#include <stdio.h>

int main(void)
{
    printf("Size of a char: %zu byte(s)\n", sizeof(char));
    printf("Size of an int: %zu byte(s)\n", sizeof(int));
    printf("Size of a long int: %zu byte(s)\n", sizeof(long int));
    printf("Size of a long long int: %zu byte(s)\n", sizeof(long long int));
    printf("Size of a float: %zu byte(s)\n", sizeof(float));
    return (0);
}
```

### 7. Intel

#### Description
Write a script that generates the assembly code (Intel syntax) of a C code and saves it in an output file.

#### Usage
```bash
gcc -S -masm=intel <source_file> -o <output_file>
```

### 8. UNIX is basically a simple operating system, but you have to be a genius to understand the simplicity

#### Description
Write a C program that prints exactly `and that piece of art is useful" - Dora Korpar, 2015-10-19`, followed by a new line, to the standard error.

#### File
```c
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
    return (1);
}
```

## Compilation and Execution

To compile and run any of the provided C programs, use the following commands:

### Compilation
```bash
gcc <filename.c> -o <output_name>
```

### Execution
```bash
./<output_name>
```

## Contribution

We welcome contributions! If you find any issues or have improvements, feel free to open an issue or submit a pull request.

### How to Contribute

1. Fork the repository
2. Create a new branch (`git checkout -b feature-branch`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature-branch`)
5. Create a new Pull Request

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

**Happy coding!.**
