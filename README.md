# Learning Data Structure(DS) with C-Programming language
# Single or One-dimensional Array
an array is a collection of elements of the same type stored in contiguous memory locations. A single array refers to a one-dimensional array, which is the simplest form of an array. It can hold multiple values but can be accessed by indexing through a single index.
<br/>
<h3>Declaring and Initializing a Single-Dimensional Array</h3>
    
```c
// Declaration of an array with a size of 5
int arr[5];

// Initialization (either at the time of declaration or separately)
int arr[5] = {10, 20, 30, 40, 50}; // Array initialized with values
```
<h3>Iterating Over an Array</h3>

```c
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
```
<h3>Key Points</h3>
<p>
1.Fixed size: Once the size of an array is defined, it cannot be changed.
<br/>
2.Indexing starts at 0: The first element is accessed with index 0, the second with 1, and so on.
<br/>
3.Type consistency: All elements in the array must be of the same type (e.g., all integers, all floats).
</p>


# Two-Dimensional Array (2D Array)
<p>A 2D array (two-dimensional array) is a collection of elements arranged in rows and columns, forming a matrix-like structure. It is essentially an array of arrays, where each element of the main array is another array. In a 2D array, elements are accessed using two indices: one for the row and one for the column.</p>
<h3>Key Points:</h3>

<p>
1.Dimensions: A 2D array has two dimensions: rows and columns.<br/>
Indexing: The first index refers to the row, and the second index refers to the column. Indexing starts from 0.<br/>
2.Data Type: All elements in a 2D array must be of the same data type (e.g., all integers, all floats).<br/>
3.Memory Layout: In C, 2D arrays are stored in row-major order, meaning elements of the same row are stored in contiguous memory locations.
</p>
<h3>Initializing a Two-Dimensional Array</h3>

```c
int arr[3][4] = {
    {1, 2, 3, 4}, 
    {5, 6, 7, 8}, 
    {9, 10, 11, 12}
};
```
<h3>Looping Through Multi-Dimensional Arrays</h3>

```c
#include <stdio.h>

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    for (int i = 0; i < 3; i++) {  // Loop through rows
        for (int j = 0; j < 4; j++) {  // Loop through columns
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```
