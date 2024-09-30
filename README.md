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

<h2>Linked List Deletion using C</h2>

<p>Here is an example of how to delete a node from a singly linked list in C:</p>

```c
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    
    // If the list has only one node
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    
    // Traverse to the second last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    // Free the last node
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node from a specific position
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;

    // If deleting the head node
    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    // Traverse to the node before the position
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    
    // If the position is beyond the list length
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    
    // Node to be deleted
    struct Node* nodeToDelete = temp->next;
    
    // Change the next pointer of the previous node
    temp->next = nodeToDelete->next;
    
    free(nodeToDelete);
}

int main() {
    // Creating a simple linked list: 10 -> 20 -> 30 -> 40 -> NULL
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    
    printf("Original List:\n");
    printList(head);
    
    // Deleting from the beginning
    deleteFromBeginning(&head);
    printf("After deleting from the beginning:\n");
    printList(head);
    
    // Deleting from the end
    deleteFromEnd(&head);
    printf("After deleting from the end:\n");
    printList(head);
    
    // Deleting from position 2
    deleteFromPosition(&head, 2);
    printf("After deleting from position 2:\n");
    printList(head);
    
    return 0;
}

```


<h2>Doubly Linked List in C</h2>

<p>A <strong>doubly linked list</strong> is a type of linked list in which each node contains a data part and two pointers. One pointer points to the previous node, and the other points to the next node in the sequence. This allows traversal of the list in both directions.</p>

<pre><code>

#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

// Define the structure of a node in a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode-&gt;data = data;
    newNode-&gt;prev = NULL;
    newNode-&gt;next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode-&gt;next = *head;
    (*head)-&gt;prev = newNode;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp-&gt;next != NULL) {
        temp = temp-&gt;next;
    }
    temp-&gt;next = newNode;
    newNode-&gt;prev = temp;
}

// Function to display the list forward
void displayForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp-&gt;data);
        temp = temp-&gt;next;
    }
    printf("\n");
}

// Function to display the list backward
void displayBackward(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) return;

    // Move to the last node
    while (temp-&gt;next != NULL) {
        temp = temp-&gt;next;
    }

    // Print in reverse
    while (temp != NULL) {
        printf("%d ", temp-&gt;data);
        temp = temp-&gt;prev;
    }
    printf("\n");
}

// Main function to demonstrate the doubly linked list
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);

    printf("List displayed forward: ");
    displayForward(head);

    printf("List displayed backward: ");
    displayBackward(head);

    return 0;
}

</code></pre>

<p>Explanation:</p>
<ul>
    <li><strong>struct Node</strong>: Defines the structure of a doubly linked list node with <code>data</code>, <code>prev</code> (pointer to the previous node), and <code>next</code> (pointer to the next node).</li>
    <li><strong>createNode</strong>: Allocates memory for a new node and initializes it with the given data.</li>
    <li><strong>insertAtBeginning</strong>: Inserts a node at the start of the list.</li>
    <li><strong>insertAtEnd</strong>: Inserts a node at the end of the list.</li>
    <li><strong>displayForward</strong>: Prints the list starting from the head and traversing forward.</li>
    <li><strong>displayBackward</strong>: Prints the list from the last node to the head (traversing backward).</li>
</ul>

<p><strong>Sample Output:</strong></p>
<pre><code>
List displayed forward: 5 10 20 30 
List displayed backward: 30 20 10 5
</code></pre>


<h1>Basic Stack Implementation using Arrays in C</h1>

<p>A stack is a linear data structure that follows the Last In First Out (LIFO) principle, meaning the last element added is the first one to be removed.</p>

<h3>Key Operations of Stack:</h3>
<ul>
  <li><strong>Push:</strong> Add an element to the top of the stack.</li>
  <li><strong>Pop:</strong> Remove and return the top element of the stack.</li>
  <li><strong>Peek (Top):</strong> Retrieve the top element without removing it.</li>
  <li><strong>isEmpty:</strong> Check if the stack is empty.</li>
  <li><strong>isFull:</strong> Check if the stack is full.</li>
</ul>

<h3>Example: Stack Implementation using Array</h3>

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the stack

// Stack structure
struct Stack {
    int arr[MAX];  // Array to hold the elements
    int top;       // Variable to track the top of the stack
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;  // Initialize top to -1 to represent an empty stack
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an element to the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d to the stack\n", value);
}

// Function to remove an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    int poppedValue = stack->arr[stack->top--];
    printf("Popped %d from the stack\n", poppedValue);
    return poppedValue;
}

// Function to return the top element of the stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No top element\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Main function to demonstrate stack operations
int main() {
    struct Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element is: %d\n", peek(&myStack));

    pop(&myStack);
    pop(&myStack);

    printf("Top element is: %d\n", peek(&myStack));

    return 0;
}

```

## Stack Implementation using Linked List in C

In this approach, a stack is implemented dynamically using linked lists, where each element (node) contains a pointer to the next element.

### Key Operations of Stack:
1. **Push**: Add a new node at the top of the stack.
2. **Pop**: Remove the node from the top of the stack.
3. **Peek (Top)**: Retrieve the value of the top node without removing it.
4. **isEmpty**: Check if the stack is empty.

### Example: Stack Implementation using Linked List

```c
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = *top;  // Link new node with current top
    *top = newNode;        // Update top to new node
    printf("Pushed %d to the stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;  // Move top to the next node
    free(temp);           // Free the popped node
    printf("Popped %d from the stack\n", poppedValue);
    return poppedValue;
}

// Function to return the top element without removing it
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty! No top element\n");
        return -1;
    }
    return top->data;
}

// Main function to demonstrate stack operations
int main() {
    struct Node* top = NULL;  // Initialize an empty stack

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("Top element is: %d\n", peek(top));

    pop(&top);
    pop(&top);

    printf("Top element is: %d\n", peek(top));

    return 0;
}

```

# Queue 
## Implementation using Arrays in C


### Queue Operations in C:
- **Enqueue:** Adds an element to the rear of the queue.
- **Dequeue:** Removes an element from the front of the queue.
- **Front:** The front pointer that keeps track of the first element in the queue.
- **Rear:** The rear pointer that keeps track of where to insert the next element.

<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221213113312/Queue-Data-Structures.png" />

### C Code:

```c
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1)
            front = 0;  // Initialize front to 0 if inserting the first element
        rear++;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Dequeue operation
void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        front++;
        if (front > rear) {  // Reset the queue if it becomes empty
            front = rear = -1;
        }
    }
}

// Display the queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}

```



