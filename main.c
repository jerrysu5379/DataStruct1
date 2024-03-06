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

void Init() {
    first = (Node *) malloc(sizeof(Node));
    first->next = NULL;
}

void Insert(Node *first, int i, DataType x) {
    Node *p = first;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i - 1) {
        printf("插入位置不合法\n");
        return;
    }
    Node *s = (Node *) malloc(sizeof(Node));
    s->data = x;
    s->next = p->next;
    p->next = s;
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

int Get(Node *first, int i, DataType *ptr) {
    Node *p = first->next;
    int j = 1;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) {
        return 0;
    }
    *ptr = p->data;
    return 1;
}

int Locate(Node *first, DataType x) {
    Node *p = first->next;
    int j = 1;
    while (p != NULL && p->data != x){
        p = p->next;
        j++;
    }
    if (p == NULL){
        return 0;
    }
    return j;
}