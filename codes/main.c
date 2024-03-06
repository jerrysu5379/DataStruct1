#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
#define MaxSize 100
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i;
        }
    }
    return 0;
}

int InsertElem(SqList L,  int i, ElemType e){
    int j;
    if (L.length >= MaxSize) {
        return 0;
    }
    if (i < 1 || i > L.length + 1) {
        return 0;
    }
    for (j = L.length - 1; j >= i - 1; j--) {
        L.data[j + 1] = L.data[j];
    }
    L.data[i - 1] = e;
    L.length++;
    return 1;
}

int DelElem(SqList L, int i, ElemType *e) {
    int j;
    if (L.length == 0){
        return 0;
    }
    if (i < 1 || i > L.length){
        return 0;
    }
    *e = L.data[i - 1];
    for (j = i; j < L.length; j++){
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return 1;
}