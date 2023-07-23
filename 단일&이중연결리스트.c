#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} node;

node *head = NULL;

//단일 연결리스트에 노드를 맨 앞에 추가하는 함수
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

//단일 연결리스트를 출력하는 함수
void display_node() {
    if (head == NULL) {
        printf("\n\n\t\t연결 리스트가 구성되지 않아 출력할 값이 없습니다;\n");
        return;
    }
    node* curNode = head;
    while (curNode != NULL) {
        printf("%d => ", curNode->value);
        curNode = curNode->next;
    }
}

//단일 연결리스트에 노드를 맨 뒤에 추가하는 함수
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

//단일 연결리스트의 모든 노드를 삭제하는 함수
void removeNode() {
    node* delNode;
    while (head != NULL) {
        delNode = head;
        head = head->next;
        free(delNode);
    }
}

//이중 연결리스트에 노드를 맨 앞에 추가하는 함수
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

//이중 연결리스트에 노드를 맨 뒤에 추가하는 함수
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
        printf("\n\n***이중 연결 리스트 ***\n\n");
        printf("1. 노드 삽입(맨 앞) - 단일 연결 리스트와 동일\n");
        printf("2. 노드 삽입(맨 뒤) - 단일 연결 리스트와 동일\n");
        printf("3. 노드 삽입(맨 앞) - 이중 연결 리스트\n");
        printf("4. 노드 삽입(맨 뒤) - 이중 연결 리스트\n");
        printf("10. 연결 리스트 출력 - 단일 연결 리스트와 동일\n");
        printf("0. 프로그램 종료 - 단일 연결 리스트와 동일\n");

        printf("\n메뉴 선택 : ");
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
