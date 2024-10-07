#include <stdio.h>
#include<stdlib.h>

// Created Node
struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeg(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    }
    newNode->next = *head;
    *head = newNode;
}

void printLL(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
}


int main(){
    
    struct Node* head = NULL;
    insertAtBeg(&head, 5);
    insertAtBeg(&head, 4);
    insertAtBeg(&head, 3);
    insertAtBeg(&head, 2);
    insertAtBeg(&head, 1);
    printLL(head);

    return 0;
}