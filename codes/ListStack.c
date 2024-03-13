#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DataType;
typedef struct Node {
    DataType data;
    struct Node *next;
} Node;

void Push(Node *top, DataType x) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = x;
    p->next = top;
    top = p;
}

bool IsEmpty(Node *top) {
    return top == NULL;
}

bool Pop(Node *top, DataType *ptr) {
    if (IsEmpty(top)) return false;
    Node *p = top;
    *ptr = top->data;
    top = top->next;
    free(p);
    return true;
}

bool GetTop(Node *top, DataType *ptr) {
    if (IsEmpty(top)) return false;
    *ptr = top->data;
    return true;
}

void DestroyStack(Node *top) {
    DataType x;
    while (!IsEmpty(top)) {
        Pop(top, &x);
    }
}