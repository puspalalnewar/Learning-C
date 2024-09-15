#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// Creating Node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert At the beginning
void insertAtBeginning(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head){
    struct Node* temp = head;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main(){
    // struct Node* head= NULL;
    struct Node* head = createNode(5);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    printList(head);
    

    return 0;
}