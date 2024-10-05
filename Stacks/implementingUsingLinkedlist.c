#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* isEmpty(struct Node* top){
    if(top == NULL){
        printf("Stack is empty");
    }
}

void push(struct Node** top, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d to the stack\n", value);
}

int pop(struct Node** top){
    if(*top == NULL){
        printf("Linkedlist is empty");
        return -1;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    printf("Popped %d from stack\n", temp->data);
    return temp->data;
}

int main(){
    struct Node* top = NULL;
    push(&top, 2);
    push(&top, 5);
    return 0;
}