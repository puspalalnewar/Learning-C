#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert At Beginning of LinkedList
void insertAtBeg(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Delete from beginning
void deleteBeg(struct Node** head){
    if(*head == NULL){
        printf("LinkedList is Empty!!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Print LinkedList
void printLL(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

// Delete from End
void delFromEnd(struct Node** head){
    struct Node* temp = *head;
    if(temp == NULL){
        printf("LL is Empty!!");
        return;
    }
    if(temp->next == NULL){
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    
}

int main(){
    struct Node* head = NULL;
    insertAtBeg(&head, 5);
    insertAtBeg(&head, 4);
    insertAtBeg(&head, 3);
    insertAtBeg(&head, 2);
    insertAtBeg(&head, 1);
    // deleteBeg(&head);
    // deleteBeg(&head);
    // deleteBeg(&head);
    // deleteBeg(&head);
    // deleteBeg(&head);
    // deleteBeg(&head);
    delFromEnd(&head);
    printLL(head);
    return 0;
}