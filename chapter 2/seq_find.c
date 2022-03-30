//顺序表的查找
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0
#define InitSize 10
typedef struct{
    int *data;
    int MaxSize;
    int length;
}SqList;

SqList* InitList(SqList *L){
    L->data = (int *)malloc(InitSize*sizeof(int));
    L->length = 0;
    L->MaxSize = InitSize;
    return L;
}

bool ListInsert(SqList *L,int i,int e){
    if(i < 1||i > InitSize)      //判断i的值的有效范围
        return false;
    if(L->length >= InitSize)    //当前存储空间已满，不能放入
        return false;
    for(int j = L->length;j >= i;j--)
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;
    L->length++;
    
    return true;
}

int GetElem(SqList *L,int i){   //按位查找
    return L->data[i-1];
}

int LocateElem(SqList *L,int e){
    // for(int i = 0;i < L->length; i++)
    //     printf("data[%d] = %d\n",i,L->data[i]);
    // printf("length = %d\n",L->length);
    for(int i = 0;i<L->length;i++)
        if(L->data[i] == e)
            return i+1;
        return 0;

}

int main(){
    SqList *L;
    L = InitList(L);
    bool j;
    for(int i = 1;i<InitSize;i++){
        j = ListInsert(L,i,i);
        if(j = 0){
            printf("lose!!!\n");
        }
    }
    int e = GetElem(L,3);
    printf("locate = %d\n",e);

    int t = LocateElem(L,3);
    printf("location = %d\n",t);

    //system("pause");
    return 0;

}