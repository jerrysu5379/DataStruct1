#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DataType;
typedef struct Node {
    DataType data;
    struct Node *next;
} Node;
typedef struct {
    Node *front;
    Node *rear;
} LinkQueue;

bool IsEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(LinkQueue Q, DataType e) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        return false;
    }
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return true;
}

bool DeQueue(LinkQueue Q, DataType *ptr) {
    if (IsEmpty(Q)){
        return false;
    }
    Node *p = Q.front->next;
    *ptr = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}

void DestroyQueue(LinkQueue Q) {
    while (Q.front != NULL) {
        Node *p = Q.front;
        Q.front = Q.front->next;
        free(p);
    }
}