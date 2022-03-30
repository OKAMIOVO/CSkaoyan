//顺序表
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int length;
}SqList;

void InitList(SqList *L){
    for(int i = 0;i < MaxSize; i++)
        L->data[i] = 0;
    L->length = 0;
}

int main(){
    SqList L;
    SqList *L1 = &L;
    InitList(L1);

    for(int i = 0;i < MaxSize; i++)
        printf("data[%d] = %d\n",i,L.data[i]);
    
    system("pause");
    return 0;
}