#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define StackSize 100
typedef int DataType;
typedef struct {
    DataType data[StackSize];
    int top;
} SeqStack;

bool Push(SeqStack S, DataType x) {
    if (S.top == StackSize - 1) {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SeqStack S, DataType *ptr) {
    if (S.top == -1) {
        return false;
    }
    *ptr = S.data[S.top--];
    return true;
}

DataType GetTop(SeqStack S) {
    if (S.top == -1) {
        return -1;
    }[]
    return S.data[S.top];
}

bool StackEmpty(SeqStack S) {
    return S.top == -1;
}

int main() {
    return 0;
}