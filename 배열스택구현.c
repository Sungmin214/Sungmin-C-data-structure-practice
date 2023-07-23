#include <stdio.h>
#define MAX_SIZE 100

typedef struct Stack {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE -1;
}

void push(Stack* stack, int data) {
    if(isFull(stack)) {
        printf("스택이 가득 찼습니다 \n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack* stack) {
    if(isEmpty(stack)) {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n",peek(&stack));

    while(!isEmpty(&stack)) {
        printf("Popped: %d\n",pop(&stack));
    }

    return 0;
}