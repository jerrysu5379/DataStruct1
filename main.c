#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}

typedef int DataType;

typedef struct Node {
    DataType data;
    struct Node *next;
} Node;
Node *first;

void init() {
    first = (Node *) malloc(sizeof(Node));
    first->next = NULL;
}

void insert(DataType x) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = x;
    p->next = first->next;
    first->next = p;
}

void PrintList(Node *first){
    Node *p = first->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Length(Node *first){
    Node *p = first->next;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void Delete(DataType x) {
    Node *p = first->next;
    Node *pre = first;
    while (p != NULL) {
        if (p->data == x) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}