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

void printLinkedList(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    
}

int main(){
    // int i = 0; 
    // while(i != '\n'){
    //     createNode()
    // }
    
    // for(int i = 0; i<10; i++){
    //     printf("Enter Your Data : ");
    //     int data = scanf("%d", &data);
    //     // struct Node* head = createNode(data);
    //     insertAtBeg(&head, data);
    //     printf("If You Want To Add Press 1.If You Don't Press 0 ");
    //     int response = scanf("%d", &response);
    //     if(response == 0){
    //         break;
    //     }
    // }
    // struct Node* head = createNode();
    // insertAtBeg(&head, 5);
    // insertAtBeg(&head, 2);
    // insertAtBeg(&head, 5);
    struct Node* head = createNode(5);
    struct Node* second = createNode(4);

    head->next = second;
    second ->next = NULL;
    
    printLinkedList(head);
    return 0;
}