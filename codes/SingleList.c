#include "stdio.h"
#include "stdlib.h"

typedef int DataType;

typedef struct Node {
    DataType data;
    struct Node *next;
} Node;

int InsertElem(Node *L, int i, DataType *ptr) {
    int j;
    Node *p, *s;
    p = L;
    j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) {
        return 0;
    }
    s = (Node *) malloc(sizeof(Node));
    s->data = *ptr;
    s->next = p->next;
    p->next = s;
    return 1;
}

int DelElem(Node *L, int i, DataType *ptr) {
    int j;
    Node *p, *q;
    q = NULL;
    p = L;
    j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1) {
        return 0;
    }
    q = p->next;
    p->next = q->next;
    *ptr = q->data;
    free(q);
    return 1;
}

Node *CreateList(DataType a[], int n) {
    Node *p = NULL;
    Node *L = (Node *) malloc(sizeof(Node));
    L->next = NULL;
    for (int i = 0; i < n; i++) {
        p = (Node *) malloc(sizeof(Node));
        p->data = a[i];
        p->next = L->next;
        L->next = p;
    }
    return L;
}

Node *RearCreate(DataType a[], int n) {
    Node *p = NULL;
    Node *rear = NULL;
    Node *L = (Node *) malloc(sizeof(Node));
    rear = L;
    for (int i = 0; i < n; i++) {
        p = (Node *) malloc(sizeof(Node));
        p->data = a[i];
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
    return L;
}

int main(){
    return 0;
}

