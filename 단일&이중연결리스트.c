#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} node;

node *head = NULL;

//���� ���Ḯ��Ʈ�� ��带 �� �տ� �߰��ϴ� �Լ�
void insert_node_front() {
    node* newNode = (node*)malloc(sizeof(node));
    scanf("%d", &newNode->value);
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

//���� ���Ḯ��Ʈ�� ����ϴ� �Լ�
void display_node() {
    if (head == NULL) {
        printf("\n\n\t\t���� ����Ʈ�� �������� �ʾ� ����� ���� �����ϴ�;\n");
        return;
    }
    node* curNode = head;
    while (curNode != NULL) {
        printf("%d => ", curNode->value);
        curNode = curNode->next;
    }
}

//���� ���Ḯ��Ʈ�� ��带 �� �ڿ� �߰��ϴ� �Լ�
void insert_node_rear() {
    node* newNode = (node*)malloc(sizeof(node));
    scanf("%d", &newNode->value);
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    node* curNode = head;
    while (curNode->next != NULL) {
        curNode = curNode->next;
    }
    curNode->next = newNode;
    newNode->prev = curNode;
}

//���� ���Ḯ��Ʈ�� ��� ��带 �����ϴ� �Լ�
void removeNode() {
    node* delNode;
    while (head != NULL) {
        delNode = head;
        head = head->next;
        free(delNode);
    }
}

//���� ���Ḯ��Ʈ�� ��带 �� �տ� �߰��ϴ� �Լ�
void insert_node_front_double() {
    node* newNode = (node*)malloc(sizeof(node));
    scanf("%d", &newNode->value);
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

//���� ���Ḯ��Ʈ�� ��带 �� �ڿ� �߰��ϴ� �Լ�
void insert_node_rear_double() {
    node* newNode = (node*)malloc(sizeof(node));
    scanf("%d", &newNode->value);
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    node* curNode = head;
    while (curNode->next != NULL) {
        curNode = curNode->next;
    }
    curNode->next = newNode;
    newNode->prev = curNode;
}

int main() {
    int choice;
    while (1) {
        system("cls");
        printf("\n\n***���� ���� ����Ʈ ***\n\n");
        printf("1. ��� ����(�� ��) - ���� ���� ����Ʈ�� ����\n");
        printf("2. ��� ����(�� ��) - ���� ���� ����Ʈ�� ����\n");
        printf("3. ��� ����(�� ��) - ���� ���� ����Ʈ\n");
        printf("4. ��� ����(�� ��) - ���� ���� ����Ʈ\n");
        printf("10. ���� ����Ʈ ��� - ���� ���� ����Ʈ�� ����\n");
        printf("0. ���α׷� ���� - ���� ���� ����Ʈ�� ����\n");

        printf("\n�޴� ���� : ");
        scanf("%d", &choice);

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                insert_node_front();
                break;
            case 2:
                insert_node_rear();
                break;
            case 3:
                insert_node_front_double();
                break;
            case 4:
                insert_node_rear_double();
                break;
            case 10:
                display_node();
                break;
            case 0:
                removeNode();
                exit(0);
        }

        printf("\n\n\t\t");
        system("pause");
    }
    return 0;
}
