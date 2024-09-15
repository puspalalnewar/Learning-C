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

void insertBeg(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode ->next = *head;
    *head = newNode;
}

void insertEnd(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp->next = newNode;
}

void insertAnyPos(struct Node** head, int data, int position){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (position == 1){
        newNode ->next = *head;
        *head = newNode;
        return;
    }
    
    
    for(int i = 1; i<position-1 && temp != NULL; i++){
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp ->next;
    temp ->next = newNode;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    
}

int main(){
    struct Node *head = NULL;
    insertBeg(&head, 5);
    insertBeg(&head, 1);
    insertEnd(&head, 74);
    insertAnyPos(&head, 20, 3);
    printList(head);
    return 0;
}