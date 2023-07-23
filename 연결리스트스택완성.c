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
        printf("������ ����ֽ��ϴ�.\n");
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
        printf("������ ����ֽ��ϴ�.\n");
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

    printf("10���� 10�� �� �� ������ ���ΰ�? ");
    scanf("%d",&n);
    // 10���� 50���� 10�� �����Ͽ� ���ÿ� push
    for (i = 0; i < n; i++) {
        push(&stack, value);
        value += 10;
    }

    printf("������ ũ��: %d\n", stack.size);

    // ���ÿ��� pop�Ͽ� �����͸� ���� ��� �ݺ�?

    printf("pop�Ͽ� �����͸� �� �� �� ���ΰ�?");
    scanf("%d",&m);
    for (i = 0; i < 3; i++) {
        int popped = pop(&stack);
        if (popped != -1)
            printf("Popped: %d\n", popped);
    }

    printf("������ ũ��: %d\n", stack.size);

    return 0;
}
//���Ḯ��Ʈ ���� ���� ������

