#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode-> next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeg(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode -> next = *head;
    *head = newNode;
}

// Insert At the ending the list
void insertAtEnd(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    while(temp ->next != NULL){
        temp = temp -> next;
    }
    
    temp -> next = newNode;

}

void insertAnyPoint(struct Node** head, int data, int position){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if(position == 1){
        newNode -> next = *head;
        *head = newNode;
        return;
    }

    for(int i = 1; temp!= NULL && i < position-1; i++){
        temp = temp -> next;
    }

    if(temp == NULL){
        printf("Positon Out Of Bound\n");
        return;
    }

    newNode -> next = temp->next;
    temp -> next = newNode;

}

void printList(struct Node* head){
    struct Node* temp = head;

    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL");
}

int main(){

    struct Node* head = NULL;
    
    insertAtBeg(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 21);
    insertAtEnd(&head, 22);
    insertAnyPoint(&head, 0, 1);
    insertAnyPoint(&head, 15, 3);
    
    printList(head);

    return 0;
}