# Learning Data Structure(DS) with C-Programming language
# Arrays
an array is a collection of elements of the same type stored in contiguous memory locations. Here’s a basic overview of how arrays work in C:
<h3>Declaration of array</h3>

```c
int main(){
    int numbers[5] = {1, 2, 3, 4, 5};
    int numbers[5] = {1, 2}; // Equivalent to {1, 2, 0, 0, 0};
    return 0;
}
```
# Using Loop

```c
#include<stdio.h>
int main() {
    int numbers[5] = {1, 2, 3, 4, 5};

    // Print all elements of the array
    for (int i = 0; i < 5; i++) {
        printf("Element at index %d: %d\n", i, numbers[i]);
    }

    // Modify an element
    numbers[2] = 10;
    printf("Modified element at index 2: %d\n", numbers[2]);

    return 0;
}
```
<h2>LinkedList Declaration</h2>
