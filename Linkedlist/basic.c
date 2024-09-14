#include<stdio.h>
#include <stdlib.h>
// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // printf("Enter Data: ");
    // scanf("%d", &newNode->data);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeg(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data){
    // struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // newNode ->data = data;
    // newNode -> next = NULL;
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while (temp -> next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert any specific position
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

void printLinkedList(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    
}

// Insert the node at the end of the node
// void insertAtEnd(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//         return;
//     }
    
//     struct Node* temp = *head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
// }

int main(){
    struct Node *hi = NULL;
    // printf("%d ->",hi->data);
    // printf("NULL");
    insertAtBeg(&hi, 1);
    insertAtEnd(&hi, 10);
    printLinkedList(hi);
    return 0;
}