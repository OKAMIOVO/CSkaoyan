//顺序表的插入删除
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0
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

bool ListInsert(SqList *L,int i,int e){
    if(i < 1||i > MaxSize)      //判断i的值的有效范围
        return false;
    if(L->length >= MaxSize)    //当前存储空间已满，不能放入
        return false;
    for(int j = L->length;j >= i;j--)
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;
    L->length++;
    
    return true;
}

bool ListDelete(SqList *L,int i,int *e){
    if(i < 1||i > MaxSize)      //判断i的值的有效范围
        return false;
    *e = L->data[i-1];
    for(int j = i;j<L->length;j++)
        L->data[j-1] = L->data[j];
    L->length--;
    return true;
}

int main(){
    SqList L;
    InitList(&L);
    bool j;
    for(int i = 1;i<MaxSize;i++){
        j = ListInsert(&L,i,i);
        if(j == 0){
            printf("lose!!!\n");
        }
    }
    int e = -1;
    if (ListDelete(&L,3,&e))
        printf("已删除第3个元素，删除元素值为%d\n",e);
    else
        printf("位序不合法，删除失败!\n");
        
    for(int i = 0;i < L.length; i++)
        printf("data[%d] = %d\n",i,L.data[i]);
    printf("length = %d\n",L.length);

    system("pause");
    return 0;
}