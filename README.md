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
# Sparse Matrix Array Representation
<p>The array representation of a sparse matrix is often used to store only non-zero elements efficiently, saving space and reducing unnecessary computations. A common way to represent a sparse matrix is through triplet form or COO (Coordinate) format, where you store only the non-zero values and their coordinates (row and column indices).</p>

<h2>Triplet Representation (COO Format):</h2>
<p>In this method, the sparse matrix is represented as a list of 3 elements (row, column, value) for each non-zero entry.</p>
<h4>Example</h4>
<p>
Consider a sparse matrix:<br/>
<table border="1">
<tr>
<td>0</td>
<td>0</td>
<td>3</td>
</tr>
<tr>
<td>0</td>
<td>4</td>
<td>0</td>
</tr>
<tr>
<td>5</td>
<td>0</td>
<td>0</td>
</tr>
</table>
<br/>
<p>The array representation in triplet form would be:</p><br/>
<table border="1">
<tr>
<th>Row</th>
<td>0</td>
<td>1</td>
<td>2</td>
</tr>
<tr>
<th>Col</th>
<td>2</td>
<td>1</td>
<td>0</td>
</tr>
<tr>
<th>Value</th>
<td>3</td>
<td>4</td>
<td>5</td>
</tr>
</table>
</p>
<p>&bull;The first column is the row index of the non-zero value.<br/>
&bull;The second column is the column index of the non-zero value.<br/>
&bull;The third column is the non-zero value itself.</p>

<h2>C Code for Triplet Representation of a Sparse Matrix</h2>

```c
#include<stdio.h> 
 int main() 
{ 
    // Assume 4x5 sparse matrix 
    int sparseMatrix[4][5] = 
    { 
        {0 , 0 , 3 , 0 , 4 }, 
        {0 , 0 , 5 , 7 , 0 }, 
        {0 , 0 , 0 , 0 , 0 }, 
        {0 , 2 , 6 , 0 , 0 } 
    }; 
  
    int size = 0; 
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 5; j++) 
            if (sparseMatrix[i][j] != 0) 
                size++; 
     int compactMatrix[3][size]; 
     // Making of new matrix 
    int k = 0; 
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 5; j++) 
            if (sparseMatrix[i][j] != 0) 
            { 
                compactMatrix[0][k] = i; 
                compactMatrix[1][k] = j; 
                compactMatrix[2][k] = sparseMatrix[i][j]; 
                k++; 
            } 
     for (int i=0; i<3; i++) 
    { 
        for (int j=0; j<size; j++) 
            printf("%d ", compactMatrix[i][j]); 
         printf("\n"); 
    } 
    return 0; 
}
```

# Linked List in C

A **Linked List** is a dynamic data structure that consists of a sequence of nodes. Each node stores data and a reference (or pointer) to the next node in the sequence.

## Node Structure

In C, the structure for a node in a singly linked list is defined as:

```c
struct Node {
    int data;
    struct Node* next;
};

// Create Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
```

## Types of Linked Lists:

<ol>
<li>Singly Linked List: Each node points to the next node and the last node points to null.</li>
<li>Doubly Linked List: Each node points to both the next and previous nodes.</li>
<li>Circular Linked List: The last node points back to the first node, forming a circle.</li>
</ol>

## Operations

### Insertion

<h3>Insert at the Beginning</h3>

```c
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*head);
    (*head) = newNode;
}
```
<h3>Insert at the End</h3>

```c

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};
// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

```
<h3>Insert at any specific location</h3>

```c
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};
// Insert any specific location
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    // If inserting at the head (position 1)
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse to the node before the desired position
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If the position is out of range
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    // Insert the new node at the position
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    
    printf("After inserting at the beginning:\n");
    printList(head); // Linked List: 1 -> 2 -> 3 -> NULL

    // Insert nodes at the end
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("After inserting at the end:\n");
    printList(head); // Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    return 0;
}

```

