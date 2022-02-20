//˳���Ĳ���ɾ��
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
    if(i < 1||i > MaxSize)      //�ж�i��ֵ����Ч��Χ
        return false;
    if(L->length >= MaxSize)    //��ǰ�洢�ռ����������ܷ���
        return false;
    for(int j = L->length;j >= i;j--)
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;
    L->length++;
    
    return true;
}

bool ListDelete(SqList *L,int i,int *e){
    if(i < 1||i > MaxSize)      //�ж�i��ֵ����Ч��Χ
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
        if(j = 0){
            printf("lose!!!\n");
        }
    }
    int e = -1;
    if (ListDelete(&L,3,&e))
        printf("��ɾ����3��Ԫ�أ�ɾ��Ԫ��ֵΪ%d\n",e);
    else
        printf("λ�򲻺Ϸ���ɾ��ʧ�ܣ�\n");
        
    for(int i = 0;i < L.length; i++)
        printf("data[%d] = %d\n",i,L.data[i]);
    printf("length = %d\n",L.length);

    system("pause");
    return 0;
}