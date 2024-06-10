Introduction
Recursion is a powerful programming technique in which a function calls itself in order to solve a problem. It is widely used for tasks that can be divided into smaller, repetitive tasks. In C programming, recursion can be a simple yet efficient way to approach problems such as factorial calculation, Fibonacci series, and tree traversals.

Table of Contents
What is Recursion?
Base Case and Recursive Case
Benefits and Drawbacks
Examples
Factorial
Fibonacci Series
Binary Search
Tower of Hanoi
Common Mistakes
Best Practices
Further Reading
What is Recursion?
Recursion occurs when a function calls itself to solve a smaller instance of the same problem. A recursive function typically has two parts:

Base Case: The condition under which the function stops calling itself.
Recursive Case: The part of the function that includes the recursive call.
Base Case and Recursive Case
Understanding the base case and recursive case is crucial to writing a recursive function.

Base Case
The base case is the simplest, smallest instance of the problem, which can be solved directly. Without a base case, a recursive function would call itself indefinitely, leading to infinite recursion and eventually a stack overflow.

Recursive Case
The recursive case is where the function calls itself with a smaller or simpler input, working towards the base case. Each recursive call should bring the function closer to the base case.

Benefits and Drawbacks
Benefits
Simplicity: Recursive solutions can be more straightforward and easier to understand than iterative ones.
Problem Decomposition: Naturally suited for problems that can be divided into similar subproblems.
Drawbacks
Memory Usage: Recursive functions can consume more memory due to the call stack.
Performance: May be slower than iterative solutions for large inputs due to overhead of multiple function calls.
Risk of Infinite Recursion: Improperly defined base cases can lead to infinite recursion.
Examples
Factorial
The factorial of a number 
𝑛
n (denoted as 
𝑛
!
n!) is the product of all positive integers less than or equal to 
𝑛
n.

c
Copy code
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1; // Base case
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

int main() {
    int number = 5;
    printf("Factorial of %d is %d\n", number, factorial(number));
    return 0;
}
Fibonacci Series
The Fibonacci series is a sequence where each number is the sum of the two preceding ones.

c
Copy code
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base case
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

int main() {
    int number = 10;
    for (int i = 0; i < number; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
Binary Search
Binary search is an efficient algorithm for finding an item from a sorted list of items.

c
Copy code
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // Base case: not found
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid; // Base case: found
    } else if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target); // Recursive case
    } else {
        return binarySearch(arr, mid + 1, high, target); // Recursive case
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, size - 1, target);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
Tower of Hanoi
The Tower of Hanoi is a classic problem involving moving disks between rods according to specific rules.

c
Copy code
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, and C are names of rods
    return 0;
}
Common Mistakes
Missing Base Case: Forgetting to define a base case can lead to infinite recursion.
Incorrect Base Case: An improperly defined base case can cause incorrect results or infinite loops.
Stack Overflow: Deep recursion can lead to stack overflow due to excessive function calls.
Best Practices
Define Clear Base Case: Ensure the base case is well-defined and reachable.
Test with Small Inputs: Start with small inputs to understand the behavior of the recursive function.
Consider Iteration for Deep Recursion: For very deep recursion, consider iterative solutions or tail recursion optimization.
Use Memoization: For problems like Fibonacci where the same results are repeatedly calculated, use memoization to store and reuse results.
Further Reading
Recursion on Wikipedia
GeeksforGeeks - Recursion
C Programming - Tutorial Point
By understanding and properly utilizing recursion in C, you can solve complex problems with elegant and concise code. Happy coding!
