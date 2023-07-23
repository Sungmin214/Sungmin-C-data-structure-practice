#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    return stack->top->data;
}

int main() {
    Stack stack;
    initStack(&stack);

    int value = 10;
    int i;
    int n,m;

    printf("10부터 10씩 몇 번 증가할 것인가? ");
    scanf("%d",&n);
    // 10부터 50까지 10씩 증가하여 스택에 push
    for (i = 0; i < n; i++) {
        push(&stack, value);
        value += 10;
    }

    printf("스택의 크기: %d\n", stack.size);

    // 스택에서 pop하여 데이터를 빼기 몇번 반복?

    printf("pop하여 데이터를 몇 번 뺄 것인가?");
    scanf("%d",&m);
    for (i = 0; i < 3; i++) {
        int popped = pop(&stack);
        if (popped != -1)
            printf("Popped: %d\n", popped);
    }

    printf("스택의 크기: %d\n", stack.size);

    return 0;
}
//연결리스트 스택 복습 집가서

