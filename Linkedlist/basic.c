#include<stdio.h>
#include <stdlib.h>
// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

void printLinkedList(struct Node* ptr){
    struct Node* temp = ptr;
    while (temp != NULL)
    {
        printf("Element : %d\n", temp->data);
        temp = temp->next;
    }
    
}
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}



int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;
    second->data = 12;
    second -> next = third;
    third->data = 45;
    third -> next = NULL;

    printLinkedList(second);
    
    return 0;
}