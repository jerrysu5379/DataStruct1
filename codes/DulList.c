#include "stdio.h"
#include "stdlib.h"

int main(){
    return 0;
}

typedef int DataType;

typedef struct DulNode {
    DataType data;
    struct DulNode *prior, *next;
} Node;

int InitList(Node **L) {
    *L = (Node *)malloc(sizeof(Node));
    if (*L == NULL) {
        return 0;
    }
    (*L)->prior = *L;
    (*L)->next = *L;
    return 1;
}

int ListInsert(Node *L, int i, DataType e) {
    Node *p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (j != i - 1) {
        return 0;
    }
    Node *s = (Node *)malloc(sizeof(Node));
    if (s == NULL) {
        return 0;
    }
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return 1;
}

int ListDelete(Node *L, int i, DataType *e) {
    Node *p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (j != i - 1) {
        return 0;
    }
    Node *q = p->next;
    *e = q->data;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return 1;
}