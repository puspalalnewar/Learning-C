#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *crateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insertions functions

void insertAtBeg(struct Node **head, int data)
{
    struct Node *newNode = crateNode(data);
    struct Node *temp = *head;
    newNode->next = *head;
    *head = newNode;
}

void printLinkedlist(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = crateNode(data);
    struct Node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(struct Node **head, int data, int position)
{
    struct Node *newNode = crateNode(data);
    struct Node* temp = *head;

    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Position Out Of Bound\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

}

// Deletion functions
void deleteFirst(struct Node** head){
    struct Node* temp = *head;
    *head = (*head) ->next;
    free(temp);
}

// Delete from last
void deleteLast(struct Node** head){
    struct Node* temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(temp->next);
}

// Delete from position
void deletePosition(struct Node** head, int position){
    struct Node* temp = *head;
    for(int i = 1; temp != NULL && i < position-1; i++){
        temp = temp ->next;
    }

    if(position == 1){
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node* nodeToDel = temp->next;
    temp->next = nodeToDel->next;
    free(nodeToDel);
}

int main()
{
    struct Node *head = NULL;

    insertAtBeg(&head, 5);
    insertAtBeg(&head, 4);
    insertAtBeg(&head, 3);
    insertAtBeg(&head, 2);
    insertAtBeg(&head, 1);
    insertAtBeg(&head, 0);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtPosition(&head, -1, 1);
    insertAtPosition(&head, -1, 2);
    deleteFirst(&head);
    deleteFirst(&head);
    deleteLast(&head);
    deletePosition(&head, 1);
    deletePosition(&head, 2);
    
    // Print List
    printLinkedlist(head);
    return 0;
}