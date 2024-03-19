#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100
typedef int DataType;
typedef struct {
    DataType data[MaxSize];
    int front, rear;
} SeqQueue;

void InitQueue(SeqQueue Q) {
    Q.front = Q.rear = -1;
}

bool IsEmpty(SeqQueue Q) {
    return Q.front == Q.rear;
}

bool IsFull(SeqQueue Q) {
    return (Q.rear + 1) % MaxSize == Q.front;
}

bool EnQueue(SeqQueue Q, DataType x) {
    if (IsFull(Q)){
        return false;
    }
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.data[Q.rear] = x;
    return true;
}

bool DeQueue(SeqQueue Q, DataType *ptr) {
    if (IsEmpty(Q)) {
        return false;
    }
    Q.front = (Q.front + 1) % MaxSize;
    *ptr = Q.data[Q.front];
    return true;
}

DataType GetHead(SeqQueue Q) {
    if (IsEmpty(Q)) {
        return -1;
    }
    return Q.data[(Q.front + 1) % MaxSize];
}

int main(){
    return 0;
}