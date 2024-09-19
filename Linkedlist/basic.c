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

// Insert at the end of the node
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

// Print List
void printLinkedList(struct Node* head){
    if(head == NULL){
        printf("LinkedList Is Empty");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    
}

// Function to delete a node from the beginning
void deleteFromBeg(struct Node** head){
    if(*head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head) -> next;
    free(temp);

}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head){
    if(*head == NULL){
        printf("LinkedList is empty.\n");
        return;
    }
    struct Node* temp = *head;
    // Only one node
    if(temp->next == NULL){
        *head == NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    
}

// Function to delete from any position
void deleteFromPosition(struct Node** head, int position){
    if(*head == NULL){
        printf("LinkedList is empty.\n");
        return;
    }
    struct Node* temp = *head;
    // Only one node
    if(position == 1){
        *head = temp -> next;
        free(temp);
        return;
    }
    for(int i = 1; temp != NULL && i < position-1; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp -> next == NULL){
        printf("Position Out Of bound\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    
}



int main(){
    struct Node *head = NULL;

    insertAtBeg(&head, 1);
    insertAtEnd(&head, 10);
    insertAtPosition(&head, 0, 1);
    deleteFromBeg(&head);
    deleteFromEnd(&head);
    deleteFromPosition(&head, 1);
    printLinkedList(head);

    return 0;
}