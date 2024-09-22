#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the Stack
void stackInit(struct Stack* stack){
    stack ->top = -1;
}

int isFull(struct Stack* stack){
    return stack->top == MAX-1;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

void push(struct Stack* stack, int val){
    if(isFull(stack)){
        printf("Stack is full\n");
        return;
    }
    stack->arr[++stack->top] = val;
    printf("Pushed %d to the stack\n", val);
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return -1;
    }

    int poppedVal = stack->arr[stack->top--];
    printf("Popped %d from stack\n", poppedVal);
    return poppedVal;
}

int peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main(){
    

    struct Stack* myStack;
    stackInit(myStack);
    
    push(myStack, 1);
    push(myStack, 2);
    push(myStack, 3);
    push(myStack, 4);
    printf("Peeked %d from stack\n", peek(myStack));

    peek(myStack);
    pop(myStack);
    pop(myStack);


    return 0;
}